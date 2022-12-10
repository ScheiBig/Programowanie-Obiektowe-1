#pragma once

#include <cstdlib>
#include <iostream>

struct point
{
    long __x;
    long __y;
};

class euc_vector
{
private:
    point __start;
    point __end;

    static size_t __created_vectors;
public:
    euc_vector(point _start, point _end);
    ~euc_vector();

    friend euc_vector operator+ (euc_vector const& _v1, euc_vector const& _v2);
    friend euc_vector operator- (euc_vector const& _v1, euc_vector const& _v2);
    friend euc_vector operator* (euc_vector const& _v, long const& _s);

    friend std::ostream& operator<< (std::ostream& _s, euc_vector const& _v);

    static size_t created_vectors();
    point& start();
    point& end();
    point const& start() const;
    point const& end() const;
};
