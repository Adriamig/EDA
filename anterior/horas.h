#pragma once

class horas
{
private:
	int hora;
	int min;
	int seg;

public:
	horas() : hora(0), min(0), seg(0) {};
	horas(int h, int m, int s);
	int getHora()const;
	int getMin()const;
	int getSeg()const;
	bool horaCorrecta()const;
	bool operator<(const horas& h)const;
};

