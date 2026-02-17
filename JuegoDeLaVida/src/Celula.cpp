#include "Celula.h"

sf::RectangleShape& Celula::getCuadrado()
{
    return m_cuadrado;
}

void Celula::cambiaEstado()
{
    //TODO
    estado = !estado;
}

bool Celula::isViva()
{
    //TODO
    return estado;
}

void Celula::setEstadoFuturo(bool estado)
{
    //TODO
    estadoFuturo = estado;
}

bool Celula::getEstadoFuturo()
{
    //TODO
    return estadoFuturo;
}