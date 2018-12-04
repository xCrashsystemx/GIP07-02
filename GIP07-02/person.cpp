#include "person.h";
#include "trimm.h";
Person extrahiere_person(string eingabezeile){
	Person p;
	string rest = "";
	
	trimm(eingabezeile, ',',p.nachname, rest);
	trimm(rest, ',', p.vorname,p.geburstag);
	p.nachname = clear(p.nachname);
	p.vorname = clear(p.vorname);
	p.geburstag = clear(p.geburstag);

	return p;
}