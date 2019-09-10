#include "pch.h"
#include <stdio.h>
#include <fstream>
#include <string>
#include "D:\Gamagora\Synthese\TP_1\TP_1\Vector.h"
#include "D:\Gamagora\Synthese\TP_1\TP_1\image_ppm.h"

using namespace winrt;
using namespace Windows::Foundation;
using namespace std;


int main()
{
	//creation du fichier txt
	string const nomFichier("trajectoirevitesse55kg.txt");
	ofstream fichier(nomFichier.c_str());
	fichier << "x\t" << "y\t" << "z\t" << endl;

	//variables
	
	double g = 9.8;
	const int nb_ticks = 60;
	double masse_objet = 85;
	double vitesseVent = -2;
	double constanteAir = (masse_objet*g)/(50*50);
	Vec3<int> z{ 0,0,1 };
	Vec3<double> vitesse{ 40,0,0 };
	Vec3<double> positions[nb_ticks];
	Vec3<double> P0{ 0,0,4000 };

	Vec3<double> acceleration{ -g * z.x,-g * z.y ,-g * z.z };
	
	Vec3<double> position = P0;
	

	for (int t = 0; t < nb_ticks; t++) {

		
		double normeVitesse = norm(vitesse);

		Vec3<double> forcefrotement{ (-vitesse.x * constanteAir * normeVitesse)/masse_objet,
									 (-vitesse.y * constanteAir * normeVitesse)/masse_objet,
									 (-vitesse.z * constanteAir * normeVitesse)/masse_objet };

		Vec3<double> newAcceleration{ acceleration.x + -g * z.x + forcefrotement.x,
									  acceleration.y + -g * z.y + forcefrotement.y,
									  acceleration.z + -g * z.z + forcefrotement.z };

		vitesse = newAcceleration + vitesse;
		
		
		//calcul de la trajectoire d'un objet avec vitesse et frotement
		Vec3<double> nouvellePos{ vitesse.x + position.x + (vitesseVent),
								  vitesse.y + position.y,
								  vitesse.z + position.z };

		positions[t] = nouvellePos;
		position = nouvellePos;

		//ecriture dans le fichier
		cout << vitesse.x <<"\t";
		cout << vitesse.z << endl;
	
		fichier << nouvellePos.x <<"\t"<< nouvellePos.y <<"\t"<< nouvellePos.z << endl;
	}
	return 1;
}