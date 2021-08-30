#ifndef __MYCOMPLEX__
#define __MYCOMPLEX__

class complex;
complex& __doapl(complex* ths, const complex& r);
complex& __doami(complex* ths, const complex& r);
complex& __doaml(complex* ths, const complex& r);

class complex {
public:
    complex(double r = 0, double i = 0): re(r), im(i) {};
    complex& operator+=(const complex&);
    complex& operator-=(const complex&);
    complex& operator*=(const complex&);
    complex& operator/=(const complex&);
private:
    double re, im;

};

#endif
