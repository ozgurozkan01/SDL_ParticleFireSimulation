#include "Particle.h"
#include <stdlib.h>

Particle::Particle()
{
    xCord = (2.0 * rand() / RAND_MAX) - 1; // number which rand function returns / max number which rand function can return
    yCord = (2.0 * rand() / RAND_MAX) - 1; // between 0-1;
}

Particle::~Particle()
{

}
