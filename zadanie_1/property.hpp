#pragma once

namespace prop
{
    template<typename T>
    class val
    {
    public:
        virtual ~val() {}
        // Property by-value getter
        virtual const T& operator()() const { return this->value; }
        // Property by-pointer getter
        virtual T* operator->() { return &(this->value); }
    protected:
        T value;
    };

    template<typename T>
    class var : public val<T>
    {
    public:
        // Property setter
        virtual T& operator=(const T& v) { return this->value = v; }
    };
}
