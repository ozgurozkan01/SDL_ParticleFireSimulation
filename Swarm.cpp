#include "Swarm.h"

Swarm::Swarm()
{
    particles = new Particle[NPARTICLES];
}

Swarm::~Swarm()
{
    delete [] particles;
}
