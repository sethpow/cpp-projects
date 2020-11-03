#include "Swarm.h"
// manage a collection of particles

namespace particlefire {

	Swarm::Swarm() {
		m_particles = new Particle[NPARTICLES];
	}

	Swarm::~Swarm() {
		delete[] m_particles;
	}

}