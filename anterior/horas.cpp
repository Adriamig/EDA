#include "horas.h"

using namespace std;

horas::horas(int h, int m, int s) {
	hora = h;
	min = m;
	seg = s;
}

int horas::getHora()const {
	return hora;
}

int horas::getMin()const {
	return min;
}

int horas::getSeg()const {
	return seg;
}

bool horas::horaCorrecta()const {
	return(hora < 24 && min < 60 && seg < 60);
}

bool horas::operator<(const horas& h)const {
	return (hora < h.getHora() ||
		(hora == h.getHora() && (min < h.getMin() || (min == h.getMin() && seg < h.getSeg()))));
}
