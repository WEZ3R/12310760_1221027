
#ifndef _PIXEL_H
#define _PIXEL_H

struct Pixel {

 private:
    unsigned char r, g, b;

 public:

    Pixel();//constructeur pixel par défaut sans parametres.
    Pixel(unsigned char nr, unsigned char ng, unsigned char nb);//constructeur pixel avec parametres.

};

#endif