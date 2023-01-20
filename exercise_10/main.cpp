#include <iostream>
#include <deque>
#include <cstdio>

#include "util/ansi_text.hpp"

static char const* colors[] = {
    ANSI::magenta,
    ANSI::red,
    ANSI::yellow,
    ANSI::green,
    ANSI::cyan,
    ANSI::blue,
    ANSI::b_black,
    ANSI::b_white
};

static char const* ANSI__clear = "\033[2J";

static char const* block = "oooooooooooooooooooooooooooooooooooooooooooooooooooo";
static char const* margin = "...................................................";

class hanoi
{
private:
    // column sticks
    std::deque<int> __p[3]{};
    // number of blocks on board
    int __size;
    // picked block or 0
    int __picked{};
public:
    hanoi(int _size): __size(_size)
    {
        // fill first column
        for (int s = 1; s <= _size; ++s)
        {
            __p[0].push_front(s);
        }
    }

    void make_move(int _i)
    {
        if (0 > _i || _i > 2) { return; } // not a column in board
        if (__picked != 0) // place down
        {
            if (!__p[_i].empty() && __p[_i].back() < __picked) { return; } // top block is larger than currently picked
            __p[_i].push_back(__picked);
            __picked = 0;
        }
        else // pick up
        {
            if (__p[_i].empty()) { return; } // column empty - nothing to pick up
            __picked = __p[_i].back();
            __p[_i].pop_back();
        }
    }

    void render()
    {
        // clear the screen - move to top-left position
        printf("%s\n", ANSI__clear);

        // if block is picked, print it in first row
        if (__picked > 0) { printf(" %s %.*s %s", colors[__picked - 1], __picked * 2 + 1, block, ANSI::reset); }

        printf("\n");

        for (int i = 0; i < __size; ++i)
        {
            printf(" ");

            // render columns side-by-side
            for (int j = 0; j < 3; ++j)
            {
                // render next block
                try
                {
                    int p = __p[j].at(__size - 1 - i);
                    printf(
                        "%s" "%.*s" "%s" "%.*s" "%s" "%.*s " "%s",
                        ANSI::black,
                        (int)(__size - p), margin,
                        colors[p - 1],
                        (int)(p * 2 + 1), block,
                        ANSI::black,
                        (int)(__size - p), margin,
                        ANSI::reset
                    );
                }
                // or empty space
                catch (std::out_of_range const&)
                {
                    printf(
                        "%s" "%.*s " "%s",
                        ANSI::black,
                        (int)(__size * 2 + 1), margin,
                        ANSI::reset
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
