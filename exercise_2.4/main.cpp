

#include "klass.hpp"

int main()
{
    klass k1;
    klass k2{ 'a' };
    klass k3{ 2 };
    klass k4{ 3.45 };

    klass k5;
    k5.character() = 'b';
    k5.integer() = 6;
    k5.floating_point() = 7.89;

    [[maybe_unused]] klass k6{ k5 };
    // /* Also implicitly called when: */
    // [[maybe_unused]] klass k6 = k5;

    return 0;
}
