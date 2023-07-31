#include "Swarm.h"

Swarm::Swarm() : lastTime(0)
{
    particles = new Particle[NPARTICLES];
}

Swarm::~Swarm()
{
    delete [] particles;
}

void Swarm::update(int elapsed)
{
    int deltaTime = elapsed - lastTime;
    for (int i = 0; i < Swarm::NPARTICLES; ++i)
    {
        particles[i].update(deltaTime);
    }

    lastTime = elapsed;
}
