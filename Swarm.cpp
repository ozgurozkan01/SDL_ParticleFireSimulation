//
// Created by ozgur on 7/29/2023.
//

#include "Swarm.h"

Swarm::Swarm()
{
    particles = new Particle[NPARTICLES];
}

Swarm::~Swarm()
{
    delete [] particles;
}
