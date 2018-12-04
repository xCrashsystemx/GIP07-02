#include <iostream>
#include <fstream>
#include <string>
#include "person.h"
#include "trimm.h"
using namespace std;
//Hilfsmethoden
string b(string s) {
	string tmp = "";
	tmp += "<b>";
	tmp += s;
	tmp += "</b>";
	return tmp;
}

string br(string s) {
	string tmp = "";
	tmp += "<br>";
	tmp += s;
	tmp += "</br>";
	return tmp;
}
int main() {
	//Auslesen
	ifstream daten;
	daten.open("personen.txt");
	string kurztext = "", langtext = "";
	while (!daten.eof()) {
		string einlesen = "";
		getline(daten, einlesen);
		Person person = extrahiere_person(einlesen);
		//Kurztext ausgeben lassen...
		kurztext += br(b(person.nachname) + ", " + person.vorname) + "\n";
		//Langtext ausgeben lassen...
		langtext += br(b(person.vorname + " " + person.nachname) + ", " + person.geburstag) + "\n";

	}
	daten.close();


	//Schreiben
	ifstream read;
	read.open("webseite.html.sec");
	ofstream write;
	write.open("webseite.html");
	while (!read.eof()) {
		string einlesen = "";
		getline(read, einlesen);
		einlesen = ersetze(einlesen, '%', kurztext);
		einlesen = ersetze(einlesen, '$', langtext);
		write << einlesen + "\n";
	}
	read.close();
	write.close();

	cout << "Test";



	system("PAUSE");
	return 0;
}