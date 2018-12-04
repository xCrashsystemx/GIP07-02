#include "trimm.h"
void trimm(string eingabezeile, char trimsymbol, string &result,string &rest) {
	for (int i = 0; i < eingabezeile.length(); i++) {
		if (result.length() > 1) {
			break;
		}
		else if (eingabezeile.at(i) == trimsymbol) {
			for (int j = 0; j < i; j++) {
				result += eingabezeile.at(j);
			}
			for (int k = i + 1; k < eingabezeile.length(); k++) {
				rest += eingabezeile.at(k);
			}
		}
	}

}

string clear(string eingabe) {
	int head = 0, tail = 0;
	string result = "";
	for (int j = eingabe.length() - 1; j >= 0; j--) {
		if (eingabe.at(j) == ' ') {
			tail = j + 1;
			break;
		}
		else {
			tail = 0;
		}
	}
	for (int i = tail; i < eingabe.length(); i++) {
		if (eingabe.at(i) == ' ') {
			head = i;
			break;
		}
		else {
			head = eingabe.length();
		}
	}



	for (tail; tail < head; tail++) {
		result += eingabe.at(tail);
	}
	return result;
}

string ersetze(string eingabe, char ersetzsymbol, string ersatztext) {
	string result = "";
	for (int i = 0; i < eingabe.length(); i++){
		if (eingabe.at(i) == ersetzsymbol) {
			for (int j = 0; j < ersatztext.length(); j++) {
				result += ersatztext.at(j);
			}
		}
		else {
			result += eingabe.at(i);
		}
	}
	return result;
}