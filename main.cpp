#include "game.h"

int main()
{
    GAME rpg;
    rpg.init();
    string name;
    cout << "�п�J�z���ʺ�...";
    cin >> name ;

    while(!rpg.over())
    {
        rpg.do_action();
    }
    return 0;
}
