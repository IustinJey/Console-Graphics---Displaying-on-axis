#ifndef PATRAT_HPP
#define PATRAT_HPP

#include "vector2.hpp"

class Patrat {
public:
    // constructor
    Patrat(double latura_ = 0, Vector2 centru_ = { 0, 0 });

    // destructor
    ~Patrat() = default;

    // getteri
    double getLatura();
    Vector2 getCentru() const;

    // setteri
    void setLatura(double latura_);
    void setCentru(const Vector2& centru);

    // arie si perimetru
    double arie() const;
    double perimetru() const;

    // operatori
    friend std::ostream& operator<<(std::ostream& os, const Patrat& p);
    friend std::istream& operator>>(std::istream& is, Patrat& p);

private:
    double latura;
    Vector2 centru;
};

#endif // PATRAT_HPP