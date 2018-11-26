#pragma once
#include "Uzol.h"
#include <iostream>

using namespace std;

template <class T>
class Strom
{
	Uzol<T> *koren;
	void zrusStrom(Uzol<T> *list) {
		if (list != nullptr)
		{
			zrusStrom(list->getVlavo());
			zrusStrom(list->getVpravo());
			delete list;
		}
	};
	void vloz(T data, Uzol<T> *list) {
		if (data < list->getData())
		{
			if (list->getVlavo())
			{
				vloz(data, list->getVlavo());
			}
			else
			{
				list->setVlavo(new Uzol<T>);
				list->getVlavo()->setData(data);
				//list->getVlavo()->setVlavo(nullptr);
				//list->getVlavo()->setVpravo(nullptr);
			}
		}
		else
		{
			if (list->getVpravo())
			{
				vloz(data, list->getVpravo());
			}
			else
			{
				list->setVpravo(new Uzol<T>);
				list->getVpravo()->setData(data);
				//list->getVpravo()->setVlavo(nullptr);
				//list->getVpravo()->setVpravo(nullptr);
			}
		}
	};
	Uzol<T> *najdi(T data, Uzol<T> *list) {
		if (list != nullptr) {
			if (data == list->getData()) {
				return list;
			}
			if (data < list->getData()) {
				return najdi(data, list->getVlavo());
			}
			else {
				return najdi(data, list->getVpravo());
			}
		}
		return nullptr;
	};
	void vypis(Uzol<T> *list) {
		if (list)
		{
			vypis(list->getVlavo());
			cout << list->getData() << endl;
			vypis(list->getVpravo());
			//cout << list->getData() << endl;

		}
	};
public:
	Strom() : koren(nullptr) {}
	~Strom() { zrusStrom(); }
	void zrusStrom() { zrusStrom(koren); };
	void vloz(T data) {
		if (koren)
		{
			vloz(data, koren);
		}
		else
		{
			koren = new Uzol<T>;
			koren->setData(data);
			koren->setVlavo(nullptr);
			koren->setVpravo(nullptr);
		}
	}
	Uzol<T> *najdi(T data) { return najdi(data, koren); };
	void vypis() { vypis(koren); };
};

