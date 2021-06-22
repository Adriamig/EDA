#pragma once
#include <iostream>

using namespace std;

class Horas
{
private:
	int hora;
	int min;
	int sec;

public:
	Horas() : hora(0), min(0), sec(0) {};
	Horas(int h, int m, int s) : hora(h), min(m), sec(s) {};
	Horas(const Horas& ho) {
		hora = ho.hora;
		min = ho.min;
		sec = ho.sec;
	}

	bool horaValida();

	bool operator<=(const Horas& h2);

	friend istream& operator>>(istream& sIn, Horas& set);
	friend ostream& operator<<(ostream& sOut, Horas& set);

};

