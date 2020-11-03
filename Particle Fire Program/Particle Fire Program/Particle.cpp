#include "Particle.h"
#include <stdlib.h>

namespace particlefire {

	Particle::Particle() {
		// random # between 0 and const max
		m_x = ((2.0 * rand()) / RAND_MAX) - 1;
		m_y = ((2.0 * rand()) / RAND_MAX) - 1;

	}

	Particle::~Particle() {

	}

}