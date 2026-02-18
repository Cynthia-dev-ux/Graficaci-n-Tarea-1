#include <SFML/Graphics.hpp>
#include "Celula.h"
#include <vector>
#include <typeinfo>
#include <iostream>
#include <chrono>
#include <thread>

void calculaEstadosFuturos(const std::vector<Celula*>& celulas);

int main()
{
	// Se crea la ventana de la aplicación
	sf::RenderWindow window( sf::VideoMode( { 504, 504 } ), "Juego de la vida" );

	// Ciclo en el que se crean los objetos
	float pos_x = 0.f;
	float pos_y = 0.f;

	// Lista que almacena las celulas
	std::vector<Celula*> celulas;

	// Se crean las celulas y se guardan apuntadores de las mismas
	for (int i = 0; i<5; i++){
		for (int j = 0; j<5;j++)
		{
			Celula* celula = new Celula(pos_x,pos_y);
			pos_x += 101.f;
			celulas.push_back(celula);
		}
		pos_x = 0.f;
		pos_y += 101.f;
	}

	// El color de fondo a usar
	sf::Color color(203,224,233);

	// GAME LOOP
	while ( window.isOpen() )
	{       sf::Event event;
            while (window.pollEvent(event))	
				{
            if (event.type == sf::Event::Closed)
			{				
			window.close();
				}
			//Se revisa cuando se da un click
			else if (event.type == sf::Event::MouseButtonPressed)
				// Se obtiene la coordenada del click
			{
				int mouse_x = event.mouseButton.x;
                int mouse_y = event.mouseButton.y;

				//Se obtienen los indices correspondientes del arreglo de cuadrados
				int coord_x = mouse_x/101;
				int coord_y = mouse_y/101;

				// Se convierte el indice a una dimension
				int index = (coord_y*5+coord_x);

				celulas.at(index)->cambiaEstado();
			}
				
			//Se revisa cuando se presiona la tecla ENter para comenzar la simulación
			else if (event.type == sf::Event::KeyPressed)
			{
            if (event.key.code == sf::Keyboard::Enter)				
			 {
					// número de iteraciones a realizar 
					int iteraciones = 25;
					int contador = 0;

					while(contador++ <iteraciones)
					{
						
						// Se verifica si todas las celulas estan muertas para temrinar la simulación.
						bool muertos = false;
						for (Celula* celula: celulas)
						{
							if (celula->isViva())
								muertos = true;
						}
						if (!muertos)
							break;
			
						// Comienza la simulación
						std::cout<<"Iteración : "<<contador<<std::endl;
						calculaEstadosFuturos(celulas); // Se calculan los nuevos estados
						// Se actualizan los estados de la celula
						for (Celula* celula: celulas)
						{
							if (celula->isViva() != celula->getEstadoFuturo())
							{
								celula->cambiaEstado();
								celula->setEstadoFuturo(false);
							}
						}
						// Se redibujan las celulas
						window.clear(color);
						for (Celula* celula : celulas)
						{
							window.draw(celula->getCuadrado());
						}
						window.display();
						// Se duerme el hilo medio segundo
						std::this_thread::sleep_for(std::chrono::milliseconds(500));
					}
				}
			}
		}

		

		window.clear(color);
		for (Celula* celula : celulas)
		{
			window.draw(celula->getCuadrado());
		}
		window.display();
	}
}



/**
 * @brief función que asigna los estados futuros a las células. 
 * Esta función debe verificar el número de vecinos vivos por cada celula y actaulizar su estado futuro
 * de acuerdo a las reglas del juego de la vida
 */
void calculaEstadosFuturos(const std::vector<Celula*>& celulas)
{
	//TODO

for(int i = 0; i < 25; i++){

	int vecinosVivos = 0;

    // Arriba
	if (i > 4) {
            if (celulas[i - 5]->isViva()) {
                vecinosVivos++;
            }
        } 
	// Arriba izquierda
    if (i > 5 && i % 5 != 0) {
            if (celulas[i - 6]->isViva()) {
                vecinosVivos++;
            }
        }
		
	//Arriba derecha
	if (i > 3 && i % 5 != 4) {
            if (celulas[i - 4]->isViva()) {
                vecinosVivos++;
            }
        }

	//Izquierda
	   if (i > 0 && i % 5 != 0) {
            if (celulas[i - 1]->isViva()) {
                vecinosVivos++;
            }
        }
	//Derecha
	        if (i < 24 && i % 5 != 4) {
            if (celulas[i + 1]->isViva()) {
                vecinosVivos++;
            }
        }
    //Abajo
	 if (i < 19) {
            if (celulas[i + 5]->isViva()) {
                vecinosVivos++;
            }
        }
	// Abajo izquierda
	        if (i < 20 && i % 5 != 0) {
            if (celulas[i + 4]->isViva()) {
                vecinosVivos++;
            }
        }
    //Abajo derecha

	  if (i < 18 && i % 5 != 4) {
            if (celulas[i + 6]->isViva()) {
                vecinosVivos++;
            }
	  }
	//Ver si está viva o muerta o nace siguiendo los reglas

    if(celulas[i] -> isViva() == true){
		if (vecinosVivos == 2 || vecinosVivos == 3) {
			celulas[i] -> setEstadoFuturo(true);
		} else {
			celulas[i] -> setEstadoFuturo(false);
		}
	}else {
		if (vecinosVivos == 3){
			celulas[i] -> setEstadoFuturo(true);
		}else{
			celulas[i]-> setEstadoFuturo(false);
		}
	}
	


		}
}

