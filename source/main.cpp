#include <Game.hpp>
#include <Defs.hpp>
int main(int argc, char *argv[])
{
    srand(time(0));
    Game(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
    return 0;
}