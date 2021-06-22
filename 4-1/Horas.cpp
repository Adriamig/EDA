#include "Horas.h"

istream& operator>>(istream& in, Horas& set)
{
	char c;

	in >> set.hora >> c >> set.min >> c >> set.sec;

	return in;
}

ostream& operator<<(ostream& out, Horas& set)
{
    if (set.hora < 10) out << "0";
    out << set.hora << ":";

    if (set.min < 10) out << "0";
    out << set.min << ":";

    if (set.sec < 10) out << "0";
    out << set.sec;

    return out;
}

bool Horas::horaValida()
{
    return (hora < 24 && min < 60 && sec < 60);
}

bool Horas::operator<=(const Horas& h2)
{
    return (hora < h2.hora ||
        (hora == h2.hora && (min < h2.min || (min == h2.min && sec <= h2.sec))));
}
