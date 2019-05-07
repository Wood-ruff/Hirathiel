#include "MobListObject.hpp"

MobListObject::MobListObject():GenericListObject()
{
	this->id = 1;
}

MobListObject::MobListObject(long id, GenericListObject* next, GenericListObject* prev) :GenericListObject((next),(prev)) {

	this->id = id;
}

MobListObject::~MobListObject(){
}


bool MobListObject::insert(MobListObject* next) {

	if (this->next == nullptr || next == nullptr){
		return false;
	}
	next->setNext(this->next);
	next->setPrev(this);

	this->next->setPrev(dynamic_cast<GenericListObject*>(next));
	this->next = dynamic_cast<GenericListObject*>(next);

	return true;
}

void MobListObject::remove(){
	if (prev != nullptr){
		prev->setNext(this->next);
	}
	if (next != nullptr){
		next->setPrev(this->prev);
	}
}