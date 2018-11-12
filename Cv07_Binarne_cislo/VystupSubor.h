#pragma once
#include "IVystup.h"
#include <cstdio>

class VystupSubor :
	public IVystup
{
private:
	FILE *f = nullptr;
public:
	VystupSubor(const char *menoSuboru);
	~VystupSubor();
	// Inherited via IVystup
	virtual void Vypis(const char * text) override;
};

