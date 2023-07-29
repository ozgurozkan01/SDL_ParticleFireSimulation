#include "Particle.h"
#include <stdlib.h>

Particle::Particle()
{
    xCord = (1.0 * rand()) / RAND_MAX; // number which rand function returns / max number which rand function can return
    yCord = (1.0 * rand()) / RAND_MAX; // between 0-1;
}

Particle::~Particle()
{

}
