#pragma once
template <class T>
class Uzol
{
	T data;
	Uzol *vlavo = nullptr;
	Uzol *vpravo = nullptr;
public:
	Uzol() {};
	~Uzol() {};

	T getData() const { return data; }
	Uzol *getVlavo() const { return vlavo; }
	Uzol *getVpravo() const { return vpravo; }

	void setData(T pdata) { data = pdata; }
	void setVlavo(Uzol *uzol) { vlavo = uzol; }
	void setVpravo(Uzol *uzol) { vpravo = uzol; }
};
