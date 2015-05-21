#include "Node.h"
Node::Node() {

}

Node::~Node() {

}

void Node::setNext(Node* next) {
	m_next = next;
}

void Node::setValor(Vehicle valor){
	m_valor = valor;
}

Vehicle& Node::getValor()
{
	return m_valor;
}
Node* Node::getNext()
{
	return m_next;
}