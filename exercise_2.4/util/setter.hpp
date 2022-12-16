#pragma once

namespace util
{
    template<typename T>
    class setter
    {
    private:
        T& __value;
        T const& (*__validator)(T const&);
        static T const& default_validator(T const& _value) { return _value; }
    public:
        setter(T& _value): __value(_value), __validator(default_validator) {}
        setter(T& _value, T const& (*_validator)(T const&)): __value(_value), __validator(_validator) {}

        T& operator=(T const& _value) { return this->__value = __validator(_value); }
    };
}
