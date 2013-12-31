#include "game.h"

int main()
{
    GAME rpg;
    rpg.init();
    string name;
    cout << "請輸入您的暱稱...";
    cin >> name ;

    while(!rpg.over())
    {
        rpg.do_action();
    }
    return 0;
}
