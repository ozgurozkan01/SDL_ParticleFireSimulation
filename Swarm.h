//
// Created by ozgur on 7/29/2023.
//

#ifndef SDL_PARTICLEFIRESIMULATION_SWARM_H
#define SDL_PARTICLEFIRESIMULATION_SWARM_H


#include "Particle.h"

class Swarm {
public:
    const static int NPARTICLES = 20000; // const values must initialize where it is defined.
private:

    Particle *particles;

public:

    Swarm();
    ~Swarm();

    const Particle * const getParticles() { return particles;}
};


#endif //SDL_PARTICLEFIRESIMULATION_SWARM_H
