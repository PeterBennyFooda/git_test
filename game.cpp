#include "game.h"

void GAME::init()
{
//    cout << "輸入玩家的 姓名 HP MP AP DP:";
//    cin >> user.name >> user.hp >> user.mp >> user.ap >> user.dp;
//    cout << "輸入敵人的 姓名 HP MP AP DP:";
//    cin >> enemy.name >> enemy.hp >> enemy.mp >> enemy.ap >> enemy.dp;
    user=PLAYER("蝙蝠俠", 100, 100, 80, 70);
    enemy=PLAYER("小醜", 100, 100, 85, 60);
    user_box=BOX(3, 2, 36, 4, YELLOW, BLUE, user.name, "玩家");
    enemy_box=BOX(43, 2, 36, 4, BLACK, LIGHTGRAY, enemy.name, "電腦");
    player_box(user_box, user);
    player_box(enemy_box, enemy);
    status=USER_INPUT;
}

void GAME::player_box(const BOX &b, const PLAYER &p)const
{
    b.textbox("");
    b.xyout(1, 1, "HP: ");
    b.xyout(5, 1, string(p.hp/5, ' '), BLUE, RED);
    b.xyout(1, 2, "MP: ");
    b.xyout(5, 2, string(p.mp/5, ' '), BLUE, GREEN);
}

GAMESTATUS GAME::input()
{
    char choice=user_box.popinput(20, 20, "1)攻擊 2)魔法 3)回復HP 4)道具 其他)放棄：", "你要做什麼？");
    switch(choice)
    {
        case '1': return USER_ATTACK;
        case '2': return USER_MAGIC;
        case '3': return USER_MOREHP;
        case '4': return USER_ITEM;
        default: return ENEMY_INPUT;
    }
}

GAMESTATUS GAME::enemy_ai()
{
    return ENEMY_ATTACK;    //只會攻擊的笨蛋
}

void GAME::do_action()
{
    switch(status)
    {
    case USER_INPUT:
        status=input();
        break;
    case USER_ATTACK:
        user.attack(enemy);
        player_box(enemy_box, enemy);
        user_box.popmsg(0, 0, user.msg);
        if(enemy.hp>0) status=ENEMY_INPUT;
        else status=ENEMY_DEATH;
        break;
    case USER_MAGIC:
        user.magic(enemy);
        player_box(enemy_box, enemy);
        user_box.popmsg(0, 0, user.msg);
        if(enemy.hp>0) status=ENEMY_INPUT;
        else status=ENEMY_DEATH;
        break;
    case USER_MOREHP:
        user.more_hp();
        player_box(user_box, user);
        user_box.popmsg(0, 0, user.msg);
        status=ENEMY_INPUT;
        break;
    case USER_DEATH:
        enemy_box.popmsg(0, 0, user.name+" 死亡，你輸了，遊戲結束！");
        status=GAME_OVER;
        break;
    case ENEMY_INPUT:
        status=enemy_ai();
        break;
    case ENEMY_ATTACK:
        enemy.attack(user);
        player_box(user_box, user);
        enemy_box.popmsg(0, 0, enemy.msg);
        if(user.hp>0) status=USER_INPUT;
        else status=USER_DEATH;
        break;
    case ENEMY_MAGIC:
        enemy.magic(user);
        player_box(user_box, user);
        enemy_box.popmsg(0, 0, enemy.msg);
        if(user.hp>0) status=USER_INPUT;
        else status=USER_DEATH;
        break;
    case ENEMY_MOREHP:
        enemy.more_hp();
        player_box(enemy_box, enemy);
        enemy_box.popmsg(0, 0, enemy.msg);
        status=USER_INPUT;
        break;
    case ENEMY_DEATH:
        user_box.popmsg(0, 0, enemy.name+" 死亡，你贏了，遊戲結束！");
        status=GAME_OVER;
        break;
    default:
        break;
    }
}
