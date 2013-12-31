#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <string>
#include <sstream>

using namespace std;

class PLAYER
{
private:
    int hp;
    int mp;
    int ap;
    int dp;
    int sp;
    int exp;
    int level;
    string msg;
public:
    PLAYER(string _name="unknow", int _hp=100, int _mp=20, int _ap=34, int _dp=22)
        :name(_name), hp(_hp), mp(_mp), ap(_ap), dp(_dp), sp(_sp), exp(_exp), level(_level) {}

    void attack(PLAYER &);
    void magic(PLAYER &);
    void more_hp();
    bool is_live()
    {
        return hp>0;
    }
    friend class BOX;
    friend class GAME;
};

#endif // PLAYER_H_INCLUDED
