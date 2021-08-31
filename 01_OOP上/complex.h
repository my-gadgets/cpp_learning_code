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
    double real() const { return re; }
    double imag() const { return im; }
private:
    double re, im;

    friend complex& __doapl(complex *, const complex&);
    friend complex& __doami(complex *, const complex&);
    friend complex& __doaml(complex *, const complex&);
};



inline
complex& complex::operator+=(const complex& r) {
    return __doapl(this, r);
}

inline
complex& complex::operator-=(const complex& r) {
    return __doami(this, r);
}

inline
complex& complex::operator*=(const complex& r) {
    return __doaml(this, r);
}

inline
double real(const complex& x) {
    return x.real();
}

inline
double imag(const complex& x) {
    return x.imag();
}

inline
complex operator+(const complex& x, const complex& y) {
    return complex(real(x) + real(y), imag(x) + imag(y));
}

inline
complex operator+(const complex& x, double y) {
    return complex(real(x), imag(x) + y);
}

inline
complex operator+(double x, const complex& y) {
    return complex(x + real(y), imag(y));
}

inline
complex operator-(const complex& x, const complex& y) {
    return complex(real(x) - real(y), imag(x) - imag(y));
}

inline
complex operator-(const complex& x, double y) {
    return complex(real(x), imag(x) - y);
}

inline
complex operator-(double x, const complex& y) {
    return complex(x - real(y), imag(y));
}

inline
complex operator*(const complex& x, const complex& y) {
    return complex(real(x) * real(y) - imag(x) * imag(y),
                   real(x) * imag(y) + imag(x) * real(y));
}


inline
complex operator*(const complex& x, double y) {
    return complex(real(x) * y, imag(x) * y);
}

inline
complex operator*(double x, const complex& y) {
    return complex(x * real(y), x * imag(y));
}

complex operator/(const complex& x, double y) {
    return complex(real(x) / y, imag(x) / y);
}

inline
complex operator+(const complex& x) {
    return x;
}

inline
complex operator-(const complex& x) {
    return complex(-real(x), -imag(x));
}

inline
bool operator==(const complex& x, const complex& y) {
    return real(x) == real(y) && imag(x) == imag(y);
}

inline
bool operator==(const complex& x, double y) {
    return real(x) == y && imag(x) == 0;
}

inline
bool operator==(double x, const complex& y) {
    return x == real(y) && imag(y) == 0;
}

inline
bool operator!=(const complex& x, const complex& y) {
    return real(x) != real(y) || imag(x) != imag(y);
}

inline
bool operator!=(const complex& x, double y) {
    return real(x) != y || imag(x) != 0;
}

inline
bool operator!=(double x, const complex& y) {
    return x != real(y) || imag(y) != 0;
}








inline
complex& __doapl(complex* ths, const complex& r) {
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

#endif
