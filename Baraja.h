#ifndef BARAJA_HPP
#define BARAJA_HPP

class Baraja {
private:
    int cartas[4][13];

public:
    Baraja();
    void inicializar();
    int repartirCarta();
};

#endif // BARAJA_HPP