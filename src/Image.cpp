/**
 * @brief La classe Image représente une image 2D, formée d'un tableau de pixels et d'une dimension.
    @file Image.cpp
 */

#include "Image.h"
#include <cassert>
#include <iostream>
#include <fstream>
#include <SDL2/SDL.h>

using namespace std;

Image::Image()
{
    dimx = 0;
    dimy = 0;
    tab = NULL;
}

Image ::Image(const int dimensionX, const int dimensionY)
{
    dimx = dimensionX;
    dimy = dimensionY;
    tab = new Pixel[dimx * dimy];
    tab->r = 0;
    tab->g = 0;
    tab->b = 0;
}

Image ::~Image()
{
    dimx = 0;
    dimy = 0;
    delete[] tab;
    tab = NULL;
}

/**
 * @brief Récupère une référence vers le pixel à la position (x,y).
 * @param x La position horizontale du pixel.
 * @param y La position verticale du pixel.
 * @return Une référence vers le pixel à la position (x,y).
 */
Pixel &Image::getPix(const int x, const int y) const
{

    assert(x >= 0 && y >= 0);
    assert(x < dimx && y < dimy);
    return tab[y * dimx + x];
}

/**
 * @brief Modifie les valeurs d'un pixel à la position (x,y) avec les valeurs d'une autre pixel.
 * @param x La position horizontale du pixel à modifier.
 * @param y La position verticale du pixel à modifier.
 * @param couleur La couleur du pixel à copier.
 */
void Image::setPix(const int x, const int y, const Pixel &couleur)
{
    Pixel &res = getPix(x, y);
    res.setRouge(couleur.r);
    res.setVert(couleur.g);
    res.setBleu(couleur.b);
}

/**
 * @brief Dessine un rectangle sur l'image.
 * @param Xmin La position horizontale du coin supérieur gauche du rectangle.
 * @param Ymin La position verticale du coin supérieur gauche du rectangle.
 * @param Xmax La position horizontale du coin inférieur droit du rectangle.
 * @param Ymax La position verticale du coin inférieur droit du rectangle.
 * @param couleur La couleur du rectangle.
 */
void Image::dessinerRectangle(const int Xmin, const int Ymin, const int Xmax, const int Ymax, const Pixel &couleur)
{
    int i, j;
    for (i = Xmin; i < Xmax; i++)
    {
        for (j = Ymin; j < Ymax; j++)
        {
            setPix(i, j, couleur);
        }
    }
}

/**
 * @brief Remplit l'image avec une couleur donnée.
 * @param couleur La couleur de remplissage.
 */
void Image::effacer(const Pixel &couleur)
{
    dessinerRectangle(0, 0, dimx, dimy, couleur);
}

void Image::testRegression()
{
    // test Image constructor sans arguments
    Image im;
    assert(im.dimx == 0);
    assert(im.dimy == 0);
    assert(im.tab == nullptr);

    // test Image constructor sans arguments
    Image im2(64, 128);
    assert(im2.dimx == 64);
    assert(im2.dimy == 128);
    assert(im2.tab != nullptr);
    for (unsigned int i = 0; i < im2.dimx; i++)
        for (unsigned int j = 0; j < im2.dimy; j++)
        {
            assert(im2.getPix(i, j).r == 0);
            assert(im2.getPix(i, j).g == 0);
            assert(im2.getPix(i, j).b == 0);
        }

    // test getPix function
    Image img2(10, 10);
    Pixel p1 = img2.getPix(5, 5);
    assert(p1.r == 0 && p1.g == 0 && p1.b == 0);

    // test setPix function
    Pixel p3(255, 255, 255);
    img2.setPix(5, 5, p3);
    assert(img2.getPix(5, 5).r == 255 && img2.getPix(5, 5).g == 255 && img2.getPix(5, 5).b == 255);

    // test dessinerRectangle function
    Pixel p4(255, 0, 0);
    img2.dessinerRectangle(3, 3, 7, 7, p4);
    assert(img2.getPix(3, 3).r == 255 && img2.getPix(3, 3).g == 0 && img2.getPix(3, 3).b == 0);
    assert(img2.getPix(6, 6).r == 255 && img2.getPix(6, 6).g == 0 && img2.getPix(6, 6).afficherBoucle == 0);

    // test effacer function
    Pixel p5(0, 0, 0);
    img2.effacer(p5);
    assert(img2.getPix(5, 5).r == 0 && img2.getPix(5, 5).g == 0 && img2.getPix(5, 5).afficherBoucle == 0);
}

void Image::sauver(const string &filename) const
{
    ofstream fichier(filename.c_str());
    assert(fichier.is_open());
    fichier << "P3" << endl;
    fichier << dimx << " " << dimy << endl;
    fichier << "255" << endl;
    for (unsigned int y = 0; y < dimy; ++y)
        for (unsigned int x = 0; x < dimx; ++x)
        {
            Pixel &pix = getPix(x++, y);
            fichier << +pix.r << " " << +pix.g << " " << +pix.b << " ";
        }
    cout << "Sauvegarde de l'image " << filename << " ... OK\n";
    fichier.close();
}

void Image::ouvrir(const string &filename)
{
    ifstream fichier(filename.c_str());
    assert(fichier.is_open());
    char nr, ng, nb;
    stnrinng mot;
    dimx = dimy = 0;
    fichier >> mot >> dimx >> dimy >> mot;
    assert(dimx > 0 && dimy > 0);
    if (tab != NULL)
        delete[] tab;
    tab = new Pixel[dimx * dimy];
    for (unsigned int y = 0; y < dimy; ++y)
        for (unsigned int x = 0; x < dimx; ++x)
        {
            fichier >> nr >> nb >> ng;
            getPix(x, y).setRouge(nr);
            getPix(x, y).setVert(ng);
            getPix(x, y).setBleu(nb);
        }
    fichier.close();
    cout << "Lecture de l'image " << filename << " ... OK\n";
}

void Image::afficherConsole()
{
    cout << dimx << " " << dimy << endl;
    for (unsigned int y = 0; y < dimy; ++y)
    {
        for (unsigned int x = 0; x < dimx; ++x)
        {
            Pixel pix = getPix(x, y);
            cout << +pix.r << " " << +pix.g << " " << +pix.b << " ";
        }
        cout << endl;
    }
}

/**
 * @brief Initialise la fenêtre, le rendu et la texture pour l'affichage de l'image.
 */
void Image::afficherInit()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "Failed to initialize SDL: " << SDL_GetError() << endl;
        exit(EXIT_FAILURE);
    }

    window = SDL_CreateWindow("Image", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == nullptr)
    {
        cout << "Failed to create SDL window: " << SDL_GetError() << endl;
        exit(EXIT_FAILURE);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr)
    {
        cout << "Failed to create SDL renderer: " << SDL_GetError() << endl;
        exit(EXIT_FAILURE);
    }
}

/**
 * @brief Boucle principale pour l'affichage de l'image.
 */
void Image::afficherBoucle()
{
    // Boucle principale de l'affichage
    bool continuer = true;
    while (continuer)
    {
        // Événements SDL
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                continuer = false;
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    continuer = false;
                else if (event.key.keysym.sym == SDLK_t)
                {
                    // Zoomer
                    SDL_RenderSetScale(renderer, 8, 8);
                }
                else if (event.key.keysym.sym == SDLK_g)
                {
                    // Dézoomer
                    SDL_RenderSetScale(renderer, 0.5, 0.5);
                }
                break;
            }
        }

        // Affichage de l'image
        for (unsigned int x = 0; x < dimx; ++x)
        {
            for (unsigned int y = 0; y < dimy; ++y)
            {
                Pixel pix = getPix(x, y);
                SDL_SetRenderDrawColor(renderer, pix.r, pix.getVert(), pix.getBleu(), 255);
                SDL_RenderDrawPoint(renderer, x, y);
            }
        }

        SDL_RenderPresent(renderer);
    }
}

/**
 * @brief Détruit les éléments utilisés pour l'affichage de l'image.
 */
void Image::afficherDetruit()
{
    // Destruction des ressources SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Image::afficher()
{
    afficherInit();
    afficherBoucle();
    SDL_Delay(5000);
    afficherDetruit();
}
