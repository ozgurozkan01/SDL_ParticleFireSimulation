#ifndef SDL_PARTICLEFIRESIMULATION_PARTICLE_H
#define SDL_PARTICLEFIRESIMULATION_PARTICLE_H


class Particle {

private:
    double xCord;
    double yCord;

public:

    Particle();
    ~Particle();

    [[nodiscard]] double getX() const { return xCord; };
    [[nodiscard]] double getY() const { return yCord; };
};


#endif //SDL_PARTICLEFIRESIMULATION_PARTICLE_H
