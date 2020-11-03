#pragma once
#ifndef SWARM_H_
#define SWARM_H_
#include "Particle.h"

namespace particlefire {
class Swarm {
public:
	// number of particles
	const static int NPARTICLES = 2500;

private:
	Particle* m_pParticles;

public:
	Swarm();
	virtual ~Swarm();
	void update();
	// const pointer pointing to a const Particle
	const Particle* const getParticles() { return m_pParticles; };

};
}

#endif // !SWARM_H_