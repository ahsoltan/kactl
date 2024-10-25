/**
 * Author: Adam Soltan
 * Description: Arithmetic on rational numbers. Consider using python or doubles.
 */
#pragma once

template<class T>
struct Frac {
  typedef Frac F;
  T p, q;
  Frac(T x = 0) : Frac(x, 1) {}
  Frac(T x, T y) : p(x), q(y) {
    T g = __gcd(p, q); p /= g, q /= g;
    if (q < 0) p *= -1, q *= -1;
  }
  friend F abs(F f) { return F(abs(f.p), f.q); }
  F operator-() const { return F(-p, q); }
  friend F operator+(F a, F b){
    return F(a.p * b.q + b.p * a.q, a.q * b.q); }
  friend F operator-(F a, F b) {
    return F(a.p * b.q - b.p * a.q, a.q * b.q); }
  friend F operator*(F a, F b) { return F(a.p*b.p, a.q*b.q); }
  friend F operator/(F a, F b) { return F(a.p*b.q, a.q*b.p); }
  friend F& operator+=(F& a, F b) { return a = a + b; }
  friend F& operator-=(F& a, F b) { return a = a - b; }
  friend F& operator*=(F& a, F b) { return a = a * b; }
  friend F& operator/=(F& a, F b) { return a = a / b; }
  auto operator<=>(const F& f) const {
    return p * f.q - f.p * q <=> 0; }
  bool operator==(const F& f) const {
    return p == f.p && q == f.q; }
};
