#include "Pixel.h"
#include <math.h>
#include <iostream>

using namespace std;

    /**
     * @brief Constructeur par défaut de la classe Pixel.
     */
Pixel::Pixel(){
    r=0;
    g=0;
    b=0;
}

    /**
     * @brief Constructeur de la classe Pixel avec des valeurs initiales spécifiées.
     * @param nr Valeur de rouge initiale.
     * @param ng Valeur de vert initiale.
     * @param nb Valeur de bleu initiale.
     */
Pixel::Pixel(unsigned char nr, unsigned char ng, unsigned char nb): r(nr), g(ng), b(nb){}

 
