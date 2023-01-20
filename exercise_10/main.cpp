#include <iostream>
#include <deque>

#include <cstdio>

static char const* colors[] = {
    "\u001b[35m", //m
    "\u001b[31m", //r
    "\u001b[33m", //y
    "\u001b[32m", //g
    "\u001b[36m", //c
    "\u001b[34m", //b
    "\u001b[90m", //g
    "\u001b[97m"  //w
};

static char const* clear = "\033[2J";

static char const* reset = "\u001b[0m";

static char const* block = "oooooooooooooooooooooooooooooooooooooooooooooooooooo";
// char const* margin = "                                                    ";
static char const* margin = "...................................................";

static const char* black = "\u001b[30m";

class hanoi
{
private:
    std::deque<int> __p[3]{};
    int __size;
    int __picked{};
public:
    hanoi(int _size): __size(_size)
    {
        for (int s = 1; s <= _size; ++s)
        {
            __p[0].push_front(s);
        }
    }

    void make_move(int _i)
    {
        if (0 > _i || _i > 2) { return; }
        if (__picked != 0)
        {
            if (!__p[_i].empty() && __p[_i].back() < __picked) { return; }
            __p[_i].push_back(__picked);
            __picked = 0;
        }
        else
        {
            if (__p[_i].empty()) { return; }
            __picked = __p[_i].back();
            __p[_i].pop_back();
        }
    }

    void render()
    {
        printf("%s\n", clear);

        if (__picked > 0) { printf(" %s %.*s %s", colors[__picked - 1], __picked * 2 + 1, block, reset); }

        printf("\n");

        for (int i = 0; i < __size; ++i)
        {
            printf(" ");

            for (int j = 0; j < 3; ++j)
            {
                try
                {
                    int p = __p[j].at(__size - 1 - i);
                    printf(
                        "%s" "%.*s" "%s" "%.*s" "%s" "%.*s " "%s",
                        black,
                        (int)(__size - p), margin,
                        colors[p - 1],
                        (int)(p * 2 + 1), block,
                        black,
                        (int)(__size - p), margin,
                        reset
                        );
                }
                catch (std::out_of_range const&)
                {
                    printf(
                        "%s" "%.*s " "%s",
                        black,
                        (int)(__size * 2 + 1), margin,
                        reset
                    );
                    continue;
                }
            }
            printf("\n");
        }
    }
};

int main(int argc, char const* argv[])
{
    int siz;
    if (argc != 2)
    {
        siz = 3;
    }
    else
    {
        siz = std::stoi(std::string(argv[1]));

        if (siz < 3) { siz = 3; }
        if (siz > 8) { siz = 8; }
    }


    hanoi board(siz);

    int mv;
    
    while (true)
    {
        board.render();
        
        mv = getchar();

        switch (mv)
        {
        case 'p': { return 0;}
        case 'a': {
            board.make_move(0);
            break;
        }
        case 's': {
            board.make_move(1);
            break;
        }
        case 'd': {
            board.make_move(2);
            break;
        }
        default: break;
        }
    }
}
