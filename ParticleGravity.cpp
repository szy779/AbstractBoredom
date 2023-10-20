#include "ParticleGravity.hpp"

GravitySource::GravitySource(float pos_x, float pos_y, float st) {
    pos.x = pos_x;
    pos.y = pos_y;
    this->st = st;

    cs.setPosition(pos); cs.setFillColor(sf::Color::Magenta); cs.setRadius(st * 0.002);
    
}

void GravitySource::rr(sf::RenderWindow& w) {
    w.draw(cs);
}

sf::Vector2f GravitySource::get_pos() {
    return pos;
}

float GravitySource::get_st() {
    return st;
}

Particle::Particle(float pos_x, float pos_y, float v_x, float v_y, sf::Color c) {
  
    pos.x = pos_x;
    pos.y = pos_y;

    v.x = v_x;
    v.y = v_y;

    cs.setPosition(pos); cs.setRadius(3); cs.setFillColor(c);
    
}

void Particle::rr(sf::RenderWindow& w) {
    cs.setPosition(pos);
    w.draw(cs);
}

void Particle::physicsmov(GravitySource& cs) {
    float d_x = cs.get_pos().x - pos.x; float d_y = cs.get_pos().y - pos.y;

    float d = sqrt(d_x * d_x + d_y * d_y);

    float invd = 1.f / d; //inverse of the distance

    float nx /*normalised x*/  = invd * d_x; float ny = invd * d_y;

    float isd = invd * invd;

    float ax = nx * cs.get_st() * isd;  /*calculating the acceleration of the particle */ float ay = ny * cs.get_st() * isd;

    v.x = v.x + ax;
    v.y = v.y + ay;

    pos.x = pos.x + v.x;
    pos.y = pos.y + v.y;
}
