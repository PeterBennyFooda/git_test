#include "box.h"

void BOX::get_background()
{
    if(buffer!=NULL) delete [] buffer;
    buffer=new char_info[width*height];
    gettext(left, top, left+width-1, top+height-1, buffer);
}

void BOX::put_background()
{
    if(buffer!=NULL)
    {
        puttext(left, top, left+width-1, top+height-1, buffer);
        delete [] buffer;
    }
}

void BOX::draw_box() const
{
    cout << setxy(left,         top) << "¢z";
    cout << setxy(left+width-2, top) << "¢{";
    cout << setxy(left,         top+height-1) << "¢|";
    cout << setxy(left+width-2, top+height-1) << "¢}";
    for(int x=left+2; x<left+width-2; x+=2)
    {
        cout << setxy(x, top) << "¢w";
        cout << setxy(x, top+height-1) << "¢w";
    }
    for(int y=top+1; y<top+height-1; ++y)
    {
        cout << setxy(left,         y) << "¢x" << string(width-4, ' ') << "¢x";
    }
    cout << setxy(left+4, top) << title;
    cout << setxy(left+width-2-footer.size(), top+height-1) << footer;
}

void BOX::xyout(int x, int y, const string &s) const
{
    textcolor(color);
    textbackground(bgcolor);
    cout << setxy(left+1+x, top+y) << s;
}

void BOX::xyout(int x, int y, const string &s, COLORS b, COLORS bc) const
{
    textcolor(b);
    textbackground(bc);
    cout << setxy(left+1+x, top+y) << s;
    textcolor(color);
    textbackground(bgcolor);
}

void BOX::textbox(const string &msg) const
{
    textcolor(color);
    textbackground(bgcolor);
    highvideo();
    draw_box();
    cout << setxy(left+2, top+1) << msg;
    normvideo();
}

void BOX::popmsg(int x, int y, const string &msg, const string &st, const string &sf) const
{
    int w=(msg.size()%2==0)?msg.size()+4:msg.size()+5;
    int h=3;
    if(x==0) x=(80-w)/2; if(x%2==0) ++x;
    if(y==0) y=(25-3)/2;
    BOX pbox(x, y, w, h, color, bgcolor, st, sf);
    pbox.get_background();
    pbox.textbox(msg);
    getch();
    pbox.put_background();
}

char BOX::popinput(int x, int y, const string &msg, const string &st, const string &sf)
{
    int w=(msg.size()%2==0)?msg.size()+6:msg.size()+7;
    int h=3;
    if(x==0) x=(80-w)/2; if(x%2==0) ++x;
    if(y==0) y=(25-3)/2;
    BOX pbox(x, y, w, h, color, bgcolor, st, sf);
    pbox.get_background();
    pbox.textbox(msg);
    char ch=getche();
    pbox.put_background();
    return ch;
}
