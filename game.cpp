#include "game.h"

void GAME::init()
{
//    cout << "��J���a�� �m�W HP MP AP DP:";
//    cin >> user.name >> user.hp >> user.mp >> user.ap >> user.dp;
//    cout << "��J�ĤH�� �m�W HP MP AP DP:";
//    cin >> enemy.name >> enemy.hp >> enemy.mp >> enemy.ap >> enemy.dp;
    user=PLAYER("�����L", 100, 100, 80, 70);
    enemy=PLAYER("�p��", 100, 100, 85, 60);
    user_box=BOX(3, 2, 36, 4, YELLOW, BLUE, user.name, "���a");
    enemy_box=BOX(43, 2, 36, 4, BLACK, LIGHTGRAY, enemy.name, "�q��");
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
    char choice=user_box.popinput(20, 20, "1)���� 2)�]�k 3)�^�_HP 4)�D�� ��L)���G", "�A�n������H");
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
    return ENEMY_ATTACK;    //�u�|�������³J
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
        enemy_box.popmsg(0, 0, user.name+" ���`�A�A��F�A�C�������I");
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
        user_box.popmsg(0, 0, enemy.name+" ���`�A�AĹ�F�A�C�������I");
        status=GAME_OVER;
        break;
    default:
        break;
    }
}
