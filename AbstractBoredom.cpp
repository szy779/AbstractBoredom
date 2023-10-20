#include <SFML/Graphics.hpp>
#include "ParticleGravity.hpp"

 int main(){

    sf::RenderWindow w(sf::VideoMode(1600, 1000), "Abstract Boredom");
    w.setFramerateLimit(60);

    int const numg = 4; int const nump = 10000;

    GravitySource source[numg];   Particle particle[nump];


    
    while(w.isOpen()){

      sf::Event event;
      while(w.pollEvent(event)){

	if(event.type == sf::Event::Closed) w.close();


	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) w.close();
	    	
      }


      w.clear();

      for(int k = 0; k< nump; k++){

	for(int kk =0; kk<numg; kk++){

	  particle[k].physicsmov(source[kk]);
	  
	}

	particle[k].rr(w);
	
      }

      for(int kk =0; kk< numg; kk++){

	source[kk].rr(w);
	
      }
      w.display();
    }
    
    return 0;
    
  }
