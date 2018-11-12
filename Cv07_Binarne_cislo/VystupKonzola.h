#pragma once
#include "IVystup.h"
class VystupKonzola :
	public IVystup
{
public:
	// Inherited via IVystup
	virtual void Vypis(const char * text) override;
};

