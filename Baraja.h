#ifndef BARAJA_HPP
#define BARAJA_HPP

#include <string>

class Baraja {
private:
    int baraja[4][13];
    std::string ultimoPalo;

public:
    Baraja();
    void inicializar();
    int repartirCarta();
    std::string getPalo() const;
};

#endif // BARAJA_HPP