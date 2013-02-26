/*
    SymbolicC++ : An object oriented computer algebra system written in C++

    Copyright (C) 2008 Yorick Hardy and Willi-Hans Steeb

    This library is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#ifndef _POLYNOMIAL
#define _POLYNOMIAL

#include <cassert>
#include <iostream>
#include <list>
#include <string>
#include <utility>

#include "qtrIdentity.h"

using namespace std;

template <class T> class qtrPolynomial
{
 public:
   static int Karatsuba, Newton;

   qtrPolynomial() {}
   qtrPolynomial(const T&);
   qtrPolynomial(string x);
   qtrPolynomial(const qtrPolynomial<T> &p)
    : variable(p.variable), terms(p.terms) {}

   qtrPolynomial<T>& operator=(const T&);
   qtrPolynomial<T>& operator=(const qtrPolynomial<T>&);

   qtrPolynomial<T> operator+() const;
   qtrPolynomial<T> operator-() const;

   qtrPolynomial<T> operator+(const qtrPolynomial<T>&) const;
   qtrPolynomial<T> operator-(const qtrPolynomial<T>&) const;
   qtrPolynomial<T> operator*(const qtrPolynomial<T>&) const;
   qtrPolynomial<T> operator/(const qtrPolynomial<T>&) const;
   qtrPolynomial<T> operator%(const qtrPolynomial<T>&) const;

   qtrPolynomial<T> operator^(unsigned int) const;

   qtrPolynomial<T> operator+(const T&) const;
   qtrPolynomial<T> operator-(const T&) const;
   qtrPolynomial<T> operator*(const T&) const;
   qtrPolynomial<T> operator/(const T&) const;
   qtrPolynomial<T> operator%(const T&) const;

   qtrPolynomial<T>& operator+=(const qtrPolynomial<T>&);
   qtrPolynomial<T>& operator-=(const qtrPolynomial<T>&);
   qtrPolynomial<T>& operator*=(const qtrPolynomial<T>&);
   qtrPolynomial<T>& operator/=(const qtrPolynomial<T>&);
   qtrPolynomial<T>& operator%=(const qtrPolynomial<T>&);

   qtrPolynomial<T>& operator+=(const T&);
   qtrPolynomial<T>& operator-=(const T&);
   qtrPolynomial<T>& operator*=(const T&);
   qtrPolynomial<T>& operator/=(const T&);
   qtrPolynomial<T>& operator%=(const T&);

   qtrPolynomial<T> karatsuba(const qtrPolynomial<T>&, const qtrPolynomial<T>&,int) const;
   qtrPolynomial<T> newton(const qtrPolynomial<T>&, const qtrPolynomial<T>&) const;
   qtrPolynomial<T> gcd(const qtrPolynomial<T>&, const qtrPolynomial<T>&) const;
   qtrPolynomial<T> Diff(const string &) const;
   qtrPolynomial<T> Int(const string &) const;
   qtrPolynomial<T> reverse() const;
   list<qtrPolynomial<T> > squarefree() const;

   int operator==(const qtrPolynomial<T>&) const;
   int operator!=(const qtrPolynomial<T>&) const;

   int operator==(const T&) const;
   int operator!=(const T&) const;

   T operator()(const T&) const;
   ostream &output1(ostream &) const;
   ostream &output2(ostream &) const;
   int constant() const;

protected:
   void remove_zeros(void);

protected:
   list<pair<T,int> > terms;

public:
   string variable;
};

// multiply using Karatsuba algorithm
template <class T> int qtrPolynomial<T>::Karatsuba = 1;
// inversion by Newton iteration for division
template <class T> int qtrPolynomial<T>::Newton = 1;

// additional functions that are not members of the class
template <class T>
qtrPolynomial<T> operator+(const T&,const qtrPolynomial<T>&);
template <class T>
qtrPolynomial<T> operator-(const T&,const qtrPolynomial<T>&);
template <class T>
qtrPolynomial<T> operator*(const T&,const qtrPolynomial<T>&);
template <class T>
qtrPolynomial<T> operator/(const T&,const qtrPolynomial<T>&);
template <class T>
qtrPolynomial<T> operator%(const T&,const qtrPolynomial<T>&);
template <class T>
int operator==(T,const qtrPolynomial<T>&);
template <class T>
int operator!=(T,const qtrPolynomial<T>&);


// implementation

template <class T>
qtrPolynomial<T>::qtrPolynomial(const T &c) : variable("")
{ if(c!=zero(T())) terms.push_back(pair<T,int>(c,0)); }

template <class T>
qtrPolynomial<T>::qtrPolynomial(string x): variable(x)
{ terms.push_back(pair<T,int>(one(T()),1)); }

template <class T>
qtrPolynomial<T>& qtrPolynomial<T>::operator=(const T &c)
{ return *this = qtrPolynomial<T>(c); }

template <class T>
qtrPolynomial<T>& qtrPolynomial<T>::operator=(const qtrPolynomial<T> &p)
{
 if(this == &p) return *this;
 variable = p.variable;
 terms = p.terms;
 return *this;
}

template <class T>
qtrPolynomial<T> qtrPolynomial<T>::operator+() const
{ return *this; }

template <class T>
qtrPolynomial<T> qtrPolynomial<T>::operator-() const
{
 qtrPolynomial<T> p2(*this);
 typename list<pair<T,int> >::iterator i = p2.terms.begin();
 for(;i!=p2.terms.end();i++) i->first = -(i->first);
 return p2;
}

template <class T>
qtrPolynomial<T> 
qtrPolynomial<T>::operator+(const qtrPolynomial<T> &p) const
{
 qtrPolynomial<T> p2;
 typename list<pair<T,int> >::const_iterator i = terms.begin();
 typename list<pair<T,int> >::const_iterator j = p.terms.begin();
 
 if(constant()) p2.variable = p.variable;
 else if(p.constant()) p2.variable = variable;
 else assert((p2.variable = variable) == p.variable);

 while(i!=terms.end() && j!=p.terms.end())
 {
  if(i->second < j->second)      p2.terms.push_back(*(j++));
  else if(i->second > j->second) p2.terms.push_back(*(i++));
  else  // i->second == j->second
  {
   p2.terms.push_back(pair<T,int>(i->first + j->first,i->second));
   i++; j++;
  }
 }

 while(i != terms.end())   p2.terms.push_back(*(i++));
 while(j != p.terms.end()) p2.terms.push_back(*(j++));

 p2.remove_zeros();
 return p2;
}

template <class T>
qtrPolynomial<T> 
qtrPolynomial<T>::operator-(const qtrPolynomial<T> &p) const
{ return (*this) + (-p); }

template <class T>
qtrPolynomial<T> 
qtrPolynomial<T>::operator*(const qtrPolynomial<T> &p) const
{
 qtrPolynomial<T> p2;
 typename list<pair<T,int> >::const_iterator i, j;
 
 if(constant()) p2.variable = p.variable;
 else if(p.constant()) p2.variable = variable;
 else assert((p2.variable=variable) == p.variable);

 if(!Karatsuba) // conventional multiplication
 for(i=terms.begin();i!=terms.end();i++)
 {
  qtrPolynomial<T> t;
  t.variable = p2.variable;
  for(j=p.terms.begin();j!=p.terms.end();j++)
   t.terms.push_back(pair<T,int>(i->first*j->first,i->second+j->second));

  p2 += t;
 }
 else // Karatsuba multiplication
 {
  int degree = 1;
  int degree1 = (terms.empty()) ? 0 : terms.front().second;
  int degree2 = (p.terms.empty()) ? 0 : p.terms.front().second;
  while(degree <= degree1 || degree <= degree2) degree *= 2;
  qtrPolynomial<T> k = karatsuba(*this,p,degree);
  k.variable = p2.variable;
  return k;
 }
 return p2;
}

template <class T>
qtrPolynomial<T> 
qtrPolynomial<T>::operator/(const qtrPolynomial<T> &p) const
{
 qtrPolynomial<T> p2, p3(*this);
 typename list<pair<T,int> >::const_iterator i;
 typename list<pair<T,int> >::iterator j;
 
 if(constant()) p2.variable = p.variable;
 else if(p.constant()) p2.variable = variable;
 else assert((p2.variable=variable) == p.variable);

 assert(p != zero(T()));

 if(!Newton)  // long division
 while(p3.terms.size() > 0 &&
       p3.terms.front().second >= p.terms.front().second)
 {
  qtrPolynomial<T> t;
  t.variable = p2.variable;
  t.terms.push_back(
    pair<T,int>(p3.terms.front().first/p.terms.front().first,
                p3.terms.front().second-p.terms.front().second));
  p2 += t;
  p3 -= t * p;
 }
 else       // Newton iteration
  return newton(*this,p);

 return p2;
}

template <class T>
qtrPolynomial<T> 
qtrPolynomial<T>::operator%(const qtrPolynomial<T> &p) const
{ return *this - p * (*this/p); }

template <class T>
qtrPolynomial<T> qtrPolynomial<T>::operator^(unsigned int n) const
{
 qtrPolynomial<T> result(one(T())), factor(*this);
 while(n>0)
 {
  if(n%2 == 1) result *= factor;
  factor *= factor;
  n /= 2;
 }
 return result;
}

template <class T>
qtrPolynomial<T> qtrPolynomial<T>::operator+(const T &c) const
{ return (*this) + qtrPolynomial<T>(c); }

template <class T>
qtrPolynomial<T> qtrPolynomial<T>::operator-(const T &c) const
{ return (*this) - qtrPolynomial<T>(c); }

template <class T>
qtrPolynomial<T> qtrPolynomial<T>::operator*(const T &c) const
{ return (*this) * qtrPolynomial<T>(c); }

template <class T>
qtrPolynomial<T> qtrPolynomial<T>::operator/(const T &c) const
{ return (*this) / qtrPolynomial<T>(c); }

template <class T>
qtrPolynomial<T> qtrPolynomial<T>::operator%(const T &c) const
{ return (*this) / qtrPolynomial<T>(c); }

template <class T>
qtrPolynomial<T>& qtrPolynomial<T>::operator+=(const qtrPolynomial<T> &p)
{ return *this = *this + p; }

template <class T>
qtrPolynomial<T>& qtrPolynomial<T>::operator-=(const qtrPolynomial<T> &p)
{ return *this = *this - p; }

template <class T>
qtrPolynomial<T>& qtrPolynomial<T>::operator*=(const qtrPolynomial<T> &p)
{ return *this = *this * p; }

template <class T>
qtrPolynomial<T>& qtrPolynomial<T>::operator/=(const qtrPolynomial<T> &p)
{ return *this = *this / p; }

template <class T>
qtrPolynomial<T>& qtrPolynomial<T>::operator%=(const qtrPolynomial<T> &p)
{ return *this = *this % p; }

template <class T>
qtrPolynomial<T> &qtrPolynomial<T>::operator+=(const T &c)
{ return *this += qtrPolynomial<T>(c); }

template <class T>
qtrPolynomial<T> &qtrPolynomial<T>::operator-=(const T &c)
{ return *this -= qtrPolynomial<T>(c); }

template <class T>
qtrPolynomial<T> &qtrPolynomial<T>::operator*=(const T &c)
{ return *this *= qtrPolynomial<T>(c); }

template <class T>
qtrPolynomial<T> &qtrPolynomial<T>::operator/=(const T &c)
{ return *this /= qtrPolynomial<T>(c); }

template <class T>
qtrPolynomial<T> &qtrPolynomial<T>::operator%=(const T &c)
{ return *this %= qtrPolynomial<T>(c); }

template <class T>
T Diff(const T &t,const string &x)
{ return zero(T()); }

// partial template specialization for polynomials
template <class T>
qtrPolynomial<T> Diff(const qtrPolynomial<T>&p,const string &x)
{ return p.Diff(x); }

template <class T>
qtrPolynomial<T> qtrPolynomial<T>::karatsuba(const qtrPolynomial<T> &p1,
                                       const qtrPolynomial<T> &p2,int n) const
{
 typename list<pair<T,int> >::const_iterator i;
 typename list<pair<T,int> >::iterator j;
 int n2 = n/2;
 qtrPolynomial<T> f0;
 qtrPolynomial<T> f1;
 qtrPolynomial<T> g0;
 qtrPolynomial<T> g1;
 
 if(n == 1)
 {
  qtrPolynomial<T> p;
  if(p1.terms.empty() || p2.terms.empty()) return p;
  T t1 = p1.terms.front().first;
  T t2 = p2.terms.front().first;
  if(t1*t2 == zero(T())) return p;
  p.terms.push_back(make_pair(t1*t2,0));
  return p;
 }

 for(i=p1.terms.begin();i!=p1.terms.end() && i->second>=n2;i++)
  f1.terms.push_back(make_pair(i->first, i->second - n2));
 f0.terms.insert(f0.terms.end(),i,p1.terms.end());

 for(i=p2.terms.begin();i!=p2.terms.end() && i->second>=n2;i++)
  g1.terms.push_back(make_pair(i->first, i->second - n2));
 g0.terms.insert(g0.terms.end(),i,p2.terms.end());

 qtrPolynomial<T> r1 = karatsuba(f1,g1,n2);
 qtrPolynomial<T> r2 = karatsuba(f0,g0,n2);
 qtrPolynomial<T> r3 = karatsuba(f0+f1,g0+g1,n2);
 qtrPolynomial<T> r4 = r3 - r1 - r2;

 // multiply by x^(n/2)
 for(j=r4.terms.begin();j!=r4.terms.end();j++) j->second += n2;
 // multiply by x^n
 for(j=r1.terms.begin();j!=r1.terms.end();j++) j->second += n;

 return r1 + r4 + r2;
}

template <class T>
qtrPolynomial<T> qtrPolynomial<T>::newton(const qtrPolynomial<T> &p1,
                                    const qtrPolynomial<T> &p2) const
{
 T two = one(T()) + one(T());
 qtrPolynomial<T> g = one(T());
 qtrPolynomial<T> f = p2.reverse();

 g.variable = f.variable;

 int n = (p1.terms.empty()) ? 0 : p1.terms.front().second;
 int m = (p2.terms.empty()) ? 0 : p2.terms.front().second;
 int i, j, r;

 if(n<m) return qtrPolynomial<T>(zero(T()));

 T lc = (p2.terms.empty()) ? one(T()) : p2.terms.front().first;
 T lci = one(T()) / lc;
 f *= lci;

 n = n - m + 1;
 r = 0; j = 1;
 while(j < n) { r++; j *= 2; }

 for(i=1,j=2;i<=r;i++,j*=2) 
 {
  g *= (two - f*g);
  while(!g.terms.empty() && g.terms.front().second >= j)
   g.terms.pop_front();
 }
 g.variable = p2.variable;

 qtrPolynomial<T> result =  p1.reverse()*g*lci;
 while(!result.terms.empty() && result.terms.front().second >= n)
  result.terms.pop_front();

 if(p1.constant()) result.variable = p2.variable;
 else              result.variable = p1.variable;
 return result.reverse();
}

template <class T>
qtrPolynomial<T> qtrPolynomial<T>::gcd(const qtrPolynomial<T> &a,
                                 const qtrPolynomial<T> &b) const
{
 qtrPolynomial<T> c(a);
 qtrPolynomial<T> d(b);

 if(c.terms.empty()) return qtrPolynomial<T>(one(T()));
 if(d.terms.empty()) return qtrPolynomial<T>(one(T()));

 c /= c.terms.front().first; d /= d.terms.front().first;
 while(d != qtrPolynomial<T>(zero(T())))
 {
  qtrPolynomial<T> r = c % d;
  c = d; d = r;
 }
 return c / c.terms.front().first;
}

template <class T>
qtrPolynomial<T> qtrPolynomial<T>::Diff(const string &x) const
{
 qtrPolynomial<T> p2;
 typename list<pair<T,int> >::const_iterator i = terms.begin();

 // if(variable != x) return qtrPolynomial<T>(zero(T()));
 if(variable != x)
 {
  p2.variable = variable;
  for(;i!=terms.end();i++)
    p2.terms.push_back(pair<T,int>(::Diff(i->first,x),i->second));
  p2.remove_zeros();
  return p2;
 }
 p2.variable = variable;
 for(;i!=terms.end();i++)
  if(i->second > 0)
   p2.terms.push_back(pair<T,int>(i->first*T(i->second),i->second-1));

 return p2;
}

template <class T>
T Int(const T &t,const string &x)
{
 cerr << "Tried to integrate a datatype with respect to " << x
      << " when it is not supported." << endl;
 return t;
}

// partial template specialization for polynomials
template <class T>
qtrPolynomial<T> Int(const qtrPolynomial<T> &p,const string &x)
{ return p.Int(x); }

template <class T>
qtrPolynomial<T> qtrPolynomial<T>::Int(const string &x) const
{
 qtrPolynomial<T> p2;
 typename list<pair<T,int> >::const_iterator i = terms.begin();

 if(variable != x)
 {
  p2.variable = variable;
  for(;i!=terms.end();i++)
   p2.terms.push_back(pair<T,int>(::Int(i->first,x),i->second));
 }

 p2.variable = variable;
 for(;i!=terms.end();i++)
  p2.terms.push_back(pair<T,int>(i->first/T(i->second+1),i->second+1));

 return p2;
}

template <class T>
qtrPolynomial<T> qtrPolynomial<T>::reverse() const
{
 int degree = terms.front().second;
 typename list<pair<T,int> >::const_reverse_iterator i;
 qtrPolynomial<T> p(variable);

 p.terms.clear();
 for(i=terms.rbegin();i!=terms.rend();i++)
  p.terms.push_back(make_pair(i->first,degree - i->second));

 return p;
}

template <class T>
list<qtrPolynomial<T> > qtrPolynomial<T>::squarefree() const
{
 list<qtrPolynomial<T> > l;
 T lc = (terms.empty()) ? one(T()) : terms.front().first;
 qtrPolynomial<T> a = *this/lc;
 qtrPolynomial<T> c = gcd(a,Diff(variable));
 qtrPolynomial<T> w = a/c;
 while(c != qtrPolynomial<T>(one(T())))
 {
  qtrPolynomial<T> y = gcd(w,c);
  qtrPolynomial<T> z = w/y;
  l.push_back(z);
  w = y; c /= y;
 }
 l.push_back(w);
 l.push_front(qtrPolynomial<T>(lc));
 return l;
}

template <class T>
int qtrPolynomial<T>::operator==(const qtrPolynomial<T> &p) const
{ return ((*this-p).terms.size() == 0); }

template <class T>
int qtrPolynomial<T>::operator!=(const qtrPolynomial<T> &p) const
{ return !(*this == p); }

template <class T>
int qtrPolynomial<T>::operator==(const T &c) const
{ return *this == qtrPolynomial<T>(c); }

template <class T>
int qtrPolynomial<T>::operator!=(const T &c) const
{ return !(*this == c); }

template <class T>
T qtrPolynomial<T>::operator()(const T &c) const
{
 T factor = one(T()), result = zero(T());
 typename list<pair<T,int> >::const_reverse_iterator i = terms.rbegin();

 for(int j=0;i!=terms.rend();i++) 
 {
  for(int k=j;k<i->second;k++) factor *= c;
  j = i->second;
  result += i->first * factor;
 }

 return result;
}

template <class T>
ostream &qtrPolynomial<T>::output1(ostream &o) const
{
 typename list<pair<T,int> >::const_iterator i = terms.begin();

 if(i == terms.end()) return o << zero(T());
 o << ((i->first >= zero(T())) ? "" : "-");
 while(i != terms.end())
 {
  if(i->first != one(T()) || i->second == zero(T()))
   o << ((i->first >= zero(T())) ? i->first : -(i->first));
  if(i->second > zero(T())) o << variable;
  if(i->second > one(T())) o << "^" << i->second;
  if(++i != terms.end()) o << ((i->first >= zero(T())) ? "+" : "-");
 }
 return o;
}

template <class T>
ostream &qtrPolynomial<T>::output2(ostream &o) const
{
 typename list<pair<T,int> >::const_iterator i = terms.begin();

 if(i == terms.end()) return o << zero(T());
 while(i != terms.end())
 {
  if(i->first != one(T()) || i->second == 0)
   o << "(" << i->first << ")";
  if(i->second > 0) o << variable;
  if(i->second > 1) o << "^" << i->second;
  if(++i != terms.end()) o << "+";
 }
 return o;
}

template <class T>
ostream &operator<<(ostream &o,const qtrPolynomial<T> &p)
{ return p.output1(o); }

// partial template specialization for polynomial coefficients
template <class T>
ostream &operator<<(ostream &o,const qtrPolynomial<qtrPolynomial<T> > &p)
{ return p.output2(o); }

template <class T>
int qtrPolynomial<T>::constant(void) const
{
 return terms.size() == 0 ||
               (terms.size() == 1 && terms.front().second == 0);
}

template <class T>
void qtrPolynomial<T>::remove_zeros(void)
{
 typename list<pair<T,int> >::iterator i, j;

 for(i=j=terms.begin();i!=terms.end();)
 {
  j++;
  if(i->first == zero(T())) terms.erase(i);
  i=j;
 }
}

// additional functions that are not members of the class
template <class T>
qtrPolynomial<T> operator+(const T &c,const qtrPolynomial<T> &p)
{ return qtrPolynomial<T>(c) + p; }

template <class T>
qtrPolynomial<T> operator-(const T &c,const qtrPolynomial<T> &p)
{ return qtrPolynomial<T>(c) - p; }

template <class T>
qtrPolynomial<T> operator*(const T &c,const qtrPolynomial<T> &p)
{ return qtrPolynomial<T>(c) * p; }

template <class T>
qtrPolynomial<T> operator/(const T &c,const qtrPolynomial<T> &p)
{ return qtrPolynomial<T>(c) / p; }

template <class T>
qtrPolynomial<T> operator%(const T &c,const qtrPolynomial<T> &p)
{ return qtrPolynomial<T>(c) % p; }

template <class T>
int operator==(const T &c,const qtrPolynomial<T> &p) { return p == c; }

template <class T>
int operator!=(const T &c,const qtrPolynomial<T> &p) { return p != c; }

template <class T>
qtrPolynomial<T> zero(qtrPolynomial<T>) { return qtrPolynomial<T>(zero(T())); }

template <class T>
qtrPolynomial<T> one(qtrPolynomial<T>) { return qtrPolynomial<T>(one(T())); }

#endif
