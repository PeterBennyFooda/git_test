#include "player.h"

//�����t�@�Ӫ��a
void PLAYER::attack(PLAYER &p)
{
    ostringstream oss;
    int hit=ap-p.dp;    //���ħ���=�ڪ������Oap-���a p �����m�Odp
    if(hit>0)
    {
        p.hp-=hit;
        if(p.hp<0) p.hp=0;
        oss << name << " �@����� " << p.name << " " << hit << " �I";
    }
    else
    {
        oss << name << "�@������L��";
    }
    msg=oss.str();
}

//�ϥΪk�N�����t�@�Ӫ��a�A���� MP
void PLAYER::magic(PLAYER &p)
{
    ostringstream oss;
    if(mp>=10)  //�ϥΪk�N���Ӫ��a MP 10�I
    {
        mp-=10;
        int hit=ap*1.5-p.dp;    //�k�N�� 1.5 �������O
        if(hit>0)
        {
            p.hp-=hit;
            if(p.hp<0) p.hp=0;
            oss << name << " �]�k���� " << p.name << " " << hit << " �I";
        }
        else
        {
            oss << name << "�]�k�����L��";
        }
    }
    else
    {
        oss << name << " �]�k���� " << p.name << "�A�i�O MP ����";
    }
    msg=oss.str();
}

//�^�_ HP �k�N�A���� MP 20�I
void PLAYER::more_hp()
{
    ostringstream oss;
    if(mp>=20)
    {
        mp-=20;
        hp*=1.5;    //HP�^�_����Ӫ�1.5��
        if(hp>100)
        {
            hp=100; //����W�L�W�� 100
        }
        oss << name << " �� HP �^�_�� " << hp << endl;
    }
    else
    {
        oss << name << " �� MP �����A�L�k�^�_ HP" << endl;
    }
    msg=oss.str();
}
