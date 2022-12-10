#include "euc_vector.hpp"

#include "util/ansi_text.hpp"

euc_vector move_to_origin(point const& origin, euc_vector const& _v)
{
    long x_mv = _v.start().__x - origin.__x;
    long y_mv = _v.start().__y - origin.__y;

    return euc_vector{
        point {
            _v.start().__x - x_mv,
            _v.start().__y - y_mv
        },
        point {
            _v.end().__x - x_mv,
            _v.end().__y - y_mv
        },
    };
}

size_t euc_vector::__created_vectors{ 0 };

euc_vector::euc_vector(point _start, point _end): __start(_start), __end(_end)
{
    this->__created_vectors++;
}

euc_vector::~euc_vector()
{
    std::cout
        << ANSI::b_magenta << "Exercise done"
        << ANSI::reset << util::nl;
}

euc_vector operator+ (euc_vector const& _v1, euc_vector const& _v2)
{
    euc_vector _v2_prim{
        move_to_origin(_v1.end(), _v2)
    };
    return euc_vector{
        _v1.start(),
        _v2_prim.end()
    };
}

euc_vector operator- (euc_vector const& _v1, euc_vector const& _v2)
{
    euc_vector _v2_prim{
        move_to_origin(_v1.start(), _v2)
    };
    return euc_vector{
        _v2_prim.end(),
        _v1.end()
    };
}

euc_vector operator* (euc_vector const& _v, long const& _s)
{
    euc_vector _v2_prim{
        move_to_origin(point{0,0}, _v)
    };
    _v2_prim.end().__x *= _s;
    _v2_prim.end().__y *= _s;
    return euc_vector{
        move_to_origin(_v.start(), _v2_prim)
    };
}

std::ostream& operator<< (std::ostream& _s, euc_vector const& _v)
{
    return _s
        << ANSI::b_black << "euc_vector: {" << util::nl << "  start: { x:"
        << ANSI::reset << _v.start().__x
        << ANSI::b_black << ", y:"
        << ANSI::reset << _v.start().__y
        << ANSI::b_black << " },"
        << ANSI::reset << util::nl
        << ANSI::b_black << "  end: { x:"
        << ANSI::reset << _v.end().__x
        << ANSI::b_black << ", y:"
        << ANSI::reset << _v.end().__y
        << ANSI::b_black << " }" << util::nl << "}"
        << ANSI::reset << util::nl;
}

size_t euc_vector::created_vectors() { return euc_vector::__created_vectors; }

point& euc_vector::start() { return this->__start; }
point& euc_vector::end() { return this->__end; }

point const& euc_vector::start() const { return this->__start; }
point const& euc_vector::end() const { return this->__end; }
