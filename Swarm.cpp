#include "Swarm.h"

Swarm::Swarm()
{
    particles = new Particle[NPARTICLES];
}

Swarm::~Swarm()
{
    delete [] particles;
}

void Swarm::update()
{
    for (int i = 0; i < Swarm::NPARTICLES; ++i)
    {
        particles[i].update();
    }
}
