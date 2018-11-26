#pragma once
class Uzol
{
	int data = 0;
	Uzol *vlavo = nullptr;
	Uzol *vpravo = nullptr;
public:
	Uzol() {};
	~Uzol() {};
	int getData() const { return data; }
	Uzol *getVlavo() const { return vlavo; }
	Uzol *getVpravo() const { return vpravo; }

	void setData(int pdata) { data = pdata; }
	void setVlavo(Uzol *uzol) { vlavo = uzol; }
	void setVpravo(Uzol *uzol) { vpravo = uzol; }
};
