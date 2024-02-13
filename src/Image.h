#ifndef _IMAGE_H
#define _IMAGE_H

#include "Pixel.h"

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

class Image
{

private:
    Pixel *tab;
    unsigned int dimx, dimy;

    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *surface;
    SDL_Texture *texture;

    void afficherInit();
    void afficherBoucle();
    void afficherDetruit();

public:
    Image();
    Image(const int dimensionX, const int dimensionY);
    ~Image();

    Pixel &getPix(const int x, const int y) const;
    void setPix(const int x, const int y, const Pixel &couleur);
    void dessinerRectangle(const int Xmin, const int Ymin, const int Xmax, const int Ymax, const Pixel &couleur);
    void effacer(const Pixel &couleur);
    void testRegression();
    void sauver(const string &filename) const;
    void ouvrir(const string &filename);
    void afficherConsole();
    void afficher();
};

#endif