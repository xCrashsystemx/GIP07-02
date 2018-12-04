#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Person
{
	string vorname;
	string nachname;
	string geburstag;
};
Person extrahiere_person(string einlesen);