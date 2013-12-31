#ifndef BOX_H_INCLUDED
#define BOX_H_INCLUDED

#include <string>
#include <vector>
#include "constream"

using namespace std;
using namespace conio;

class BOX
{
private:
    int left;
    int top;
    int width;
    int height;
    COLORS color;
    COLORS bgcolor;
    string title;
    string footer;
    char_info *buffer;
    void get_background();
    void put_background();
public:
    BOX(int l=1, int t=1, int w=80, int h=24, COLORS c=YELLOW, COLORS bc=BLUE, string st="", string sf="")
        :left(l), top(t), width(w), height(h), color(c), bgcolor(bc), title(st), footer(sf), buffer(NULL) {}
    void set_title(const string &t){title=t;}
    void set_footer(const string &f){footer=f;}
    void draw_box() const;
    void xyout(int, int, const string &) const;
    void xyout(int, int, const string &, COLORS, COLORS) const;
    void textbox(const string &) const;
    void popmsg(int, int, const string &, const string &st="訊息", const string &sf="按任意鍵繼續") const;
    char popinput(int, int, const string &, const string &st="輸入", const string &sf="△");
};

#endif // BOX_H_INCLUDED
