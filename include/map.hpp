#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
#include<fstream>
#include <vector>
#include "texture.hpp"

class Map
{
    private:
        std::vector<std::string> map;
        LTexture grass;
        LTexture wall;

    public:
        bool loadMap();
        void showMap();
        Map();
        ~Map();
};

#endif // MAP_H_INCLUDED