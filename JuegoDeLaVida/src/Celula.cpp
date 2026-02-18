#include "Celula.h"

sf::RectangleShape& Celula::getCuadrado()
{
    return m_cuadrado;
}

void Celula::cambiaEstado()
{
    //TODO
    m_estado = !m_estado;
    if(m_estado)
       m_cuadrado.setFillColor(sf::Color::White);
    else
       m_cuadrado.setFillColor(sf::Color::Black);
}

bool Celula::isViva()
{
    //TODO
    return m_estado;
}

void Celula::setEstadoFuturo(bool estado)
{
    //TODO
    m_estadoFuturo = estado;
}

bool Celula::getEstadoFuturo()
{
    //TODO
    return m_estadoFuturo;
}