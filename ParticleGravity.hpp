#ifndef PARTICLE_GRAVITY_HPP
#define PARTICLE_GRAVITY_HPP

#include <SFML/Graphics.hpp>
#include <cmath>

class GravitySource {
  
   sf::Vector2f pos; float st; sf::CircleShape cs; //pos := positon, st := strength, cs := circle shape

public:
    GravitySource(float pos_x = rand() % 800, float pos_y = rand() % 1000, float st = rand() % 5000);
  
    void rr(sf::RenderWindow& w); sf::Vector2f get_pos();float get_st();
  
};

class Particle {
    sf::Vector2f pos;
    sf::Vector2f v;
    sf::CircleShape cs;

public:
    Particle(float pos_x = rand() % 160, float pos_y = rand() % 100, float v_x = (((rand() & 100) * 0.02) - 1), float v_y = (((rand() & 100) * 0.02) - 1), sf::Color c = sf::Color(rand() % 255, rand() % 255, rand() % 255));
  
    void rr(sf::RenderWindow& w); void physicsmov(GravitySource& cs);
  
};

#endif
