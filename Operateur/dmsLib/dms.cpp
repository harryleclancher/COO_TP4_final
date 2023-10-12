#include "pch.h"
#include "dms.h"


using namespace std;

dms::dms() {
	degre = new int(0);
	minutes = new int(0);
	secondes = new int(0);
}

dms::dms(int my_degre, int my_minutes, int my_secondes) { // On part du principe que les valeur donné son cohérente
	degre = new int(my_degre);
	minutes = new int(my_minutes);
	secondes = new int(my_secondes);
}

dms::dms(const float my_degre) {
	degre = new int();
	minutes = new int();
	secondes = new int();
	*degre = (int)my_degre;
	float floatMinutes = (my_degre - (float)((int)my_degre)) * 100;
	*minutes = (int)(floatMinutes);
	*secondes = (int)((floatMinutes - (float)((int)floatMinutes)) * 100);
}

dms::~dms() {
	delete degre;
	delete minutes;
	delete secondes;
}

dms::dms(const dms& my_dms) {
	degre = new int(*(my_dms.degre));
	minutes = new int(*(my_dms.minutes));
	secondes = new int(*(my_dms.secondes));
}

dms& dms::operator=(const dms& my_dms) {
	if (this == &my_dms) {
		return *this;
	}

	delete degre;
	delete minutes;
	delete secondes;

	degre = new int(*(my_dms.degre));
	minutes = new int(*(my_dms.minutes));
	secondes = new int(*(my_dms.secondes));

	return *this;
}



dms dms::operator + (const dms& my_dms) const {
	dms res;
	int test_secondes = *secondes + *(my_dms.getSecondes());
	int test_minutes = *minutes + *(my_dms.getMinutes());
	int test_degre = *degre + *(my_dms.getDegre());

	if (test_secondes >= 60) {
		test_minutes += 1;
		test_secondes %= 60;
	}

	if (test_minutes >= 60) {
		test_degre += 1;
		test_minutes %= 60;
	}

	res.setDegre(test_degre);
	res.setMinutes(test_minutes);
	res.setSecondes(test_secondes);

	return res;
}

dms dms::operator - (const dms& my_dms) const {
	dms res;

	int test_degre = *degre - *(my_dms.getDegre());

	if (test_degre < 0) {
		res.setDegre(0);
		res.setMinutes(0);
		res.setSecondes(0);
	}
	else {
		int test_minutes = *minutes - *(my_dms.getMinutes());

		if (test_minutes < 0) {
			test_degre -= 1;
			test_minutes += 60;
		}

		int test_secondes = *secondes - *(my_dms.getSecondes());

		if (test_secondes < 0) {
			test_minutes -= 1;
			test_secondes += 60;
		}

		res.setDegre(test_degre);
		res.setMinutes(test_minutes);
		res.setSecondes(test_secondes);
	}

	return res;
}

dms dms::operator * (const unsigned int nb) const {
	dms res;
	int result_seconds = *secondes * nb;
	int minutes_ajout = result_seconds / 60;
	result_seconds %= 60;
	int result_minutes = (*minutes * nb) + minutes_ajout; 

	int carry_ajout = result_minutes / 60;
	result_minutes %= 60;
	int result_degrees = (*degre * nb) + carry_ajout;
	res.setDegre(result_degrees);
	res.setMinutes(result_minutes);
	res.setSecondes(result_seconds);

	return res;
}


float dms::operator ^ (const dms& my_dms) const{
	float res = (float)*(my_dms.getDegre()) + (float)*(my_dms.getMinutes()) * 100.0 / 60.0 + (float)*(my_dms.getSecondes()) * 1000 / 60;
	return res;
}

bool dms::operator <= (const dms& my_dms) const {
	if (getDegre() == my_dms.getDegre()) {
		if (getMinutes() == my_dms.getMinutes()) {
			return getSecondes() <= my_dms.getSecondes();
		}
		else {
			return getMinutes() <= my_dms.getMinutes();
		}
	}
	else {
		return getDegre() <= my_dms.getDegre();
	}

}


bool dms::operator >= (const dms& my_dms) const {
	if (*(getDegre()) == *(my_dms.getDegre())) {
		if (*(getMinutes()) == *my_dms.getMinutes()) {
			return *getSecondes() >= *my_dms.getSecondes();
		}
		else {
			return *getMinutes() >= *my_dms.getMinutes();
		}
	}
	else {
		return *getDegre() >= *my_dms.getDegre();
	}

}

bool dms::operator < (const dms& my_dms) const {
	if (getDegre() == my_dms.getDegre()) {
		if (getMinutes() == my_dms.getMinutes()) {
			return getSecondes() < my_dms.getSecondes();
		}
		else {
			return getMinutes() < my_dms.getMinutes();
		}
	}
	else {
		return getDegre() < my_dms.getDegre();
	}

}


bool dms::operator > (const dms& my_dms) const {
	if (*(getDegre()) == *(my_dms.getDegre())) {
		if (*(getMinutes()) == *my_dms.getMinutes()) {
			return *getSecondes() > *my_dms.getSecondes();
		}
		else {
			return *getMinutes() > *my_dms.getMinutes();
		}
	}
	else {
		return *getDegre() > *my_dms.getDegre();
	}

}

bool dms::operator == (const dms& my_dms) const {
	return *getDegre() == *my_dms.getDegre() && *getMinutes() == *my_dms.getMinutes() && *getSecondes() == *my_dms.getSecondes();
}

bool dms::operator != (const dms& my_dms) const {
	return *getDegre() != *my_dms.getDegre() || *getMinutes() != *my_dms.getMinutes() || *getSecondes() != *my_dms.getSecondes();
}

void dms::affiche() {
	cout << "degre : " << *getDegre() << " | minutes : " << *getMinutes() << " | secondes : " << *getSecondes() << std::endl;
}