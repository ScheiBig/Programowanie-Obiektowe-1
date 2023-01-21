#pragma once

class solid
{
    virtual double area() =0;
    virtual double volume() =0;
    virtual double diagonal() =0;
};

struct sphere: public solid
{
    double _r;
    double area() override;
    double volume() override;
    double diagonal() override;
};

struct cuboid: public solid
{
    double _a;
    double _b;
    double _c;
    double area() override;
    double volume() override;
    double diagonal() override;
};

struct pyramid: public solid
{
    double _a;
    double _b;
    double _h;
    double area() override;
    double volume() override;
    double diagonal() override;
};
