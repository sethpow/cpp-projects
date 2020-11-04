#include "Particle.h"
#include <math.h>
#include <stdlib.h>

namespace particlefire {

	Particle::Particle(): m_x(0), m_y(0) {
		init();
	}

	void Particle::init() {
		m_x = 0;
		m_y = 0;
		m_direction = (2 * 3.14159265359 * rand()) / RAND_MAX;
		m_speed = (0.05 * rand()) / RAND_MAX;
		m_speed *= m_speed;
	}

	Particle::~Particle() {

	}

	// update position of particles
	void Particle::update() {
		// add particle curling
		m_direction += m_direction * .0005;

		double xspeed = m_speed * cos(m_direction);
		double yspeed = m_speed * sin(m_direction);

		m_x += xspeed;
		m_y += yspeed;

		if (m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1) {
			init();
		}

		if (rand() < RAND_MAX / 100) {
			init();
		}
	}

}