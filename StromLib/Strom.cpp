#include "stdafx.h"
#include "targetver.h"
#include <iostream>
#include "Strom.h"
using namespace std;

void Strom::zrusStrom(Uzol * list)
{
	if (list != nullptr)
	{
		zrusStrom(list->getVlavo());
		zrusStrom(list->getVpravo());
		delete list;
	}
}

void Strom::vloz(int data, Uzol * list)
{
	if (data < list->getData())
	{
		if (list->getVlavo())
		{
			vloz(data, list->getVlavo());
		}
		else
		{
			list->setVlavo(new Uzol);
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
			list->setVpravo(new Uzol);
			list->getVpravo()->setData(data);
			//list->getVpravo()->setVlavo(nullptr);
			//list->getVpravo()->setVpravo(nullptr);
		}
	}
}

Uzol * Strom::najdi(int data, Uzol * list) {
	if (list != nullptr) {
		if (data == list->getData()) {
			return list;
		}
		if (data < list->getData()) {
			return najdi(data, list->getVlavo());
		} else {
			return najdi(data, list->getVpravo());
		}
	}
	return nullptr;
}

void Strom::vypis(Uzol * list)
{
	if (list)
	{
		vypis(list->getVlavo());
		cout << list->getData() << endl;
		vypis(list->getVpravo());
		//cout << list->getData() << endl;

	}
}

void Strom::zrusStrom()
{
	zrusStrom(koren);
}

void Strom::vloz(int data)
{
	if (koren)
	{
		vloz(data, koren);
	}
	else
	{
		koren = new Uzol;
		koren->setData(data);
		koren->setVlavo(nullptr);
		koren->setVpravo(nullptr);
	}
}

Uzol * Strom::najdi(int data)
{
	return najdi(data, koren);
}

void Strom::vypis()
{
	vypis(koren);
}
