#pragma once
#ifndef SWARM_H_
#define SWARM_H_
#include "Particle.h"

namespace particlefire {
class Swarm {
public:
	const static int NPARTICLES = 5000;

private:
	Particle* m_particles;

public:
	Swarm();
	~Swarm();
	// const pointer pointing to a const Particle
	const Particle* const getParticles() { return m_particles; };

};
}

#endif // !SWARM_H_