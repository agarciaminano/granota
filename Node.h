#include "Vehicle.h"
class Node
{
public:
	Node();
	~Node();
	Vehicle& getValor();
	Node* getNext();
	void setValor(Vehicle valor);
	void setNext(Node* next);
private:
	Vehicle m_valor;
	Node* m_next;
};
