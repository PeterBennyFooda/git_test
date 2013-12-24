#include "player.h"

//攻擊另一個玩家
void PLAYER::attack(PLAYER &p)
{
    ostringstream oss;
    int hit=ap-p.dp;    //有效攻擊=我的攻擊力ap-玩家 p 的防禦力dp
    if(hit>0)
    {
        p.hp-=hit;
        if(p.hp<0) p.hp=0;
        oss << name << " 一般攻擊 " << p.name << " " << hit << " 點";
    }
    else
    {
        oss << name << "一般攻擊無效";
    }
    msg=oss.str();
}

//使用法術攻擊另一個玩家，消耗 MP
void PLAYER::magic(PLAYER &p)
{
    ostringstream oss;
    if(mp>=10)  //使用法術消耗玩家 MP 10點
    {
        mp-=10;
        int hit=ap*1.5-p.dp;    //法術有 1.5 倍攻擊力
        if(hit>0)
        {
            p.hp-=hit;
            if(p.hp<0) p.hp=0;
            oss << name << " 魔法攻擊 " << p.name << " " << hit << " 點";
        }
        else
        {
            oss << name << "魔法攻擊無效";
        }
    }
    else
    {
        oss << name << " 魔法攻擊 " << p.name << "，可是 MP 不足";
    }
    msg=oss.str();
}

//回復 HP 法術，消耗 MP 20點
void PLAYER::more_hp()
{
    ostringstream oss;
    if(mp>=20)
    {
        mp-=20;
        hp*=1.5;    //HP回復為原來的1.5倍
        if(hp>100)
        {
            hp=100; //不能超過上限 100
        }
        oss << name << " 的 HP 回復為 " << hp << endl;
    }
    else
    {
        oss << name << " 的 MP 不足，無法回復 HP" << endl;
    }
    msg=oss.str();
}
