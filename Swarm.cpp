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
    // SDL_GetTicks returns running time but we need deltaTime to make independent of computer speed.
    // Getting deltaTime what we should do in these circumstances, to subtract previous time from current time.
    int deltaTime = elapsed - lastTime;

    for (int i = 0; i < Swarm::NPARTICLES; ++i)
    {
        particles[i].update(deltaTime);
    }

    lastTime = elapsed;
}
