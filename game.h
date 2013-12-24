#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "player.h"
#include "box.h"

enum GAMESTATUS
{
    GAME_INIT, GAME_OVER,
    USER_INPUT, USER_ATTACK, USER_MAGIC, USER_ITEM, USER_MOREHP, USER_DEATH,
    ENEMY_INPUT, ENEMY_ATTACK, ENEMY_MAGIC, ENEMY_MOREHP, ENEMY_DEATH
};

class GAME
{
private:
    PLAYER user;
    PLAYER enemy;
    GAMESTATUS status;
    BOX user_box;
    BOX enemy_box;
public:
    GAME():status(GAME_INIT){}
    void init();
    bool over() const {return status==GAME_OVER;}
    void player_box(const BOX &, const PLAYER &) const;
    GAMESTATUS input();
    GAMESTATUS enemy_ai();
    void do_action();
};

#endif // GAME_H_INCLUDED
