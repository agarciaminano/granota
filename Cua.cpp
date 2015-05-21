#include "Cua.h"

Cua::Cua()
{
	m_primer = NULL;
	m_ultim = NULL;
}
bool Cua::esBuida() const
{
	return m_primer == NULL;
}

Vehicle& Cua::getPrimer() const
{
	return m_primer->getValor();
}
Vehicle& Cua::getUltim() const
{
	return m_ultim->getValor();
}

Cua::~Cua()
{
	
}
Vehicle Cua::treu() 
{ 
	Node* aux; 
	Vehicle valor; 
	aux = m_primer; 
	if (m_primer == m_ultim)
		m_ultim = NULL;
	valor = aux->getValor();
	m_primer = aux->getNext();
	delete aux; 
	return valor; 
}

bool Cua::afegeix(Vehicle valor)
{
	Node* aux;
	bool correcte = false;

	if ((aux = new Node) != NULL)
	{
		correcte = true;
		aux->setValor(valor);
		aux->setNext(NULL);
		if (esBuida())
			m_primer = aux;
		else
			m_ultim->setNext(aux);
		m_ultim = aux;
	}
	return correcte;
}

Iterador Cua::getInici() const
{
	return Iterador(m_primer);
}