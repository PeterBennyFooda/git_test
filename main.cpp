#include "game.h"

int main()
{
    GAME rpg;
    rpg.init();
    while(!rpg.over())
    {
        rpg.do_action();
    }
    return 0;
}
