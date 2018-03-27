#include "stdafx.h"
#include <cmath>
#include <string>
#include <iostream>

using namespace std;
double degree(string string, int& counter, double x, int& brct, bool& error);
double value_at_a_point(string string, int& counter, double x, int& brct,bool& error);
double multiplication(string string, int& counter, double x, int& brct, bool& error);


bool is_number(char a){
	if ((a == '0') || (a == '1') || (a == '2') || (a == '3') || (a == '4') || (a == '5') || (a == '6') || (a == '7') || (a == '8') || (a == '9')){
		return true;
	}
	else{
		return false;
	}
}

bool correctcont(char a){
	if (is_number(a) || a == 'x' || a == '(' || a == 's' || a == 'c' || a == 't' || a == 'a' || a == 'l' || a == 'e') return true;
	else return false;
}

double value_at_a_point(string string, int& counter, double x, int& brct, bool& error){
	double res = 0;

	while (counter < string.length()){ // !!!

		if ((string[counter] >= '0') && (string[counter] <= '9')){
			bool pointchecker = false;
			int subcounter = counter; // счетчик для считывания числа
			while (((string[counter] >= '0') && (string[counter] <= '9')) || (string[counter] == '.')){ // !!!!

				if ((string[counter] == '.') && pointchecker){
					error = true;
					return 0;
				}
				if (string[counter] == '.') pointchecker = true;
				counter++;
			}
			res = stod(string.substr(subcounter, counter+1)); // парсим число в дабл !!!
		}	

		if (string[counter] == '+'){
			++counter;
			if (correctcont(string[counter]))  res = res + value_at_a_point(string, counter, x, brct, error);
			else {
				error = true;
				return 0;
			}
		}

		if (string[counter] == '-'){
			++counter;
			if (correctcont(string[counter]))  res = res - value_at_a_point(string, counter, x, brct, error);
			else {
				error = true;
				return 0;
			}
		}

		if (string[counter] == '*'){
			++counter;
			if (correctcont(string[counter])) { res = res * multiplication(string, counter, x, brct, error); }
			else {
				error = true;
				return 0;
			}
		}

		if (string[counter] == '/'){
			++counter;
			if (correctcont(string[counter])) res = res / multiplication(string, counter, x, brct, error);
			else {
				error = true;
				return 0;
			}
		}

		if (string[counter] == '^'){
			++counter;
			if (correctcont(string[counter]))  res = pow(res, degree(string, counter, x, brct, error));
			else {
				error = true;
				return 0;
			}
		}

		if (string[counter] == '('){
			counter++; // возможно потом добавить счетчик  скобок
			++brct;
		}

		if (string[counter] == ')'){
			if (brct <= 0) {
				error = true;
				return 0;
			}
			++counter;
			if (counter == string.length()){
				--brct;
				return res;
			}
			else{
				if (string[counter] == '+' || string[counter] == '-' || string[counter] == '*' || string[counter] == '/' || string[counter] == '^'){
					--brct;
					return res;
				}
				else{
					error = true;
					return 0;
				}
			}
		}

		if (string[counter] == 's'){
			++counter;
			if (string[counter] == 'q'){
				if ((string[counter + 1] == 'r') && (string[counter + 2] == 't') && (string[counter + 3]) == '('){
					counter = counter + 3;
					res = sqrt(value_at_a_point(string, counter, x, brct, error));
				}
				else{
					error = true;
					return 0;
				}
			}
			if (string[counter] == 'i'){
				if ((string[counter + 1] == 'n') && (string[counter + 2] == '(')){
					counter = counter + 2;
					res = sin(value_at_a_point(string, counter, x, brct, error));
				}
				else{
					error = true;
					return 0;
				}
			}
		
		}

		if (string[counter] == 'c'){
			if ((string[counter + 1] == 'o') && (string[counter + 2] == 's') && (string[counter + 3] == '(')){
				counter = counter + 3;
				res = cos(value_at_a_point(string, counter, x, brct, error));
			}
			else{
				error = true; return 0;
			}
		}

		if (string[counter] == 't'){
			if ((string[counter + 1] == 'a') && (string[counter + 2] == 'n') && (string[counter + 3] == '(')){
				counter = counter + 3;
				res = tan(value_at_a_point(string, counter, x, brct, error));
			}
			else{
				error = true; return 0;
			}
		}

		if (string[counter] == 'l'){
			if ((string[counter + 1] == 'o') && (string[counter + 2] == 'g') && (string[counter + 3] == '(')){
				counter = counter + 3;
				res = log(value_at_a_point(string, counter, x, brct, error));
			}
			else{
				error = true; return 0;
			}
		}

		if (string[counter] == 'e'){
			if ((string[counter + 1] == 'x') && (string[counter + 2] == 'p') && (string[counter + 3] == '(')){
				counter = counter + 3;
				res = exp(value_at_a_point(string, counter, x, brct, error));
			}
			else{
				error = true; return 0;
			}
		}
		
		if (string[counter] == 'a'){
			++counter;
			if (string[counter] == 's'){
				if ((string[counter + 1] == 'i') && (string[counter + 2] == 'n') && (string[counter + 3] == '(')){
					counter = counter + 3;
					res = asin(value_at_a_point(string, counter, x, brct, error));
				}
				else{
					error = true; return 0;
				}
			}
			if (string[counter] == 'c'){
				if ((string[counter + 1] == 'o') && (string[counter + 2] == 's') && (string[counter + 3] == '(')){
					counter = counter + 3;
					res = acos(value_at_a_point(string, counter, x, brct, error));
				}
				else{
					error = true; return 0;
				}
			}
			if (string[counter] == 't'){
				if ((string[counter + 1] == 'a') && (string[counter + 2] == 'n') && (string[counter + 3] == '(')){
					counter = counter + 3;
					res = atan(value_at_a_point(string, counter, x, brct, error));
				}
				else{
					error = true; return 0;
				}
			}
			if (string[counter] == 'b'){
				if ((string[counter + 1] == 's') && (string[counter + 2] == '(')){
					counter = counter + 2;
					res = abs(value_at_a_point(string, counter, x, brct, error));
				}
				else{
					error = true; return 0;
				}
			}
		}
		if (string[counter] == 'x'){
			res = x;
			counter++;
		}

		if (string[counter] == '.'){
			error = true;
			return 0;
		}
	}
	return res;
}

double multiplication(string string, int& counter, double x, int& brct, bool& error){
	double res = 0;
	bool pointchecker = false;
	bool mmarker = false;
	int subcounter = counter; // указатель на конеч числа

	while (counter < string.length()){

		if ((string[counter] >= '0') && (string[counter] <= '9')){
			bool pointchecker = false;
			int subcounter = counter; // счетчик для считывания числа
			if (mmarker) subcounter--; // - 
			while (((string[counter] >= '0') && (string[counter] <= '9')) || (string[counter] == '.')){ // !!!!

				if ((string[counter] == '.') && pointchecker){
					error = true; return 0;
				}
				if (string[counter] == '.') pointchecker = true;
				counter++;
			}
			res = stod(string.substr(subcounter, counter+1)); // парсим число в дабл !!!
		}

		if (string[counter] == '+'){
			if (brct != 0){
				++counter;
				if (correctcont(string[counter])) res = res + value_at_a_point(string, counter, x, brct, error);
				else {
					error = true; return 0;
				}
			}
			else return res;			
		}
			
		if (string[counter] == '-'){
			if (brct != 0){
				++counter;
				if (correctcont(string[counter])) res = res - value_at_a_point(string, counter, x, brct, error);
				else {
					error = true; return 0;
				}
			}
			else return res;
		}

		if (string[counter] == '*'){
			++counter;
			if (correctcont(string[counter])) res = res * multiplication(string, counter, x, brct, error);
			else {
				error = true; return 0;
			}
		}

		if (string[counter] == '/'){
			++counter;
			if (correctcont(string[counter])) res = res / multiplication(string, counter, x, brct, error);
			else {
				error = true; return 0;
			}
		}

		if (string[counter] == '^'){
			++counter;
			if (correctcont(string[counter])) res = pow(res, degree(string, counter, x, brct, error));
			else {
				error = true; return 0;
			}
		}

		if (string[counter] == '('){
			++counter; // возможно потом добавить счетчик  скобок
			++brct;
			if ((string[counter] == '-') && is_number(string[counter + 1])){
				mmarker = true;
			}
		}		

		if (string[counter] == ')'){
			if (brct <= 0) {
				error = true;
				return 0;
			}
			++counter;
			if (counter == string.length()){
				--brct;
				return res;
			}
			else{
				if (string[counter] == '+' || string[counter] == '-' || string[counter] == '*' || string[counter] == '/' || string[counter] == '^'){
					--brct;
					return res;
				}
				else{
					error = true;
					return 0;
				}
			}
		}

		if (string[counter] == 's'){
			++counter;
			if (string[counter] == 'q'){
				if ((string[counter + 1] == 'r') && (string[counter + 2] == 't') && (string[counter + 3]) == '('){
					counter = counter + 3;
					res = sqrt(value_at_a_point(string, counter, x, brct, error));
				}
				else{
					error = true; return 0;
				}
			}
			if (string[counter] == 'i'){
				if ((string[counter + 1] == 'n') && (string[counter + 2] == '(')){
					counter = counter + 2;
					res = sin(value_at_a_point(string, counter, x, brct, error));
				}
				else{
					error = true; return 0;
				}
			}
		}

		if (string[counter] == 'c'){
			if ((string[counter + 1] == 'o') && (string[counter + 2] == 's') && (string[counter + 3] == '(')){
				counter = counter + 3;
				res = cos(value_at_a_point(string, counter, x, brct, error));
			}
			else{
				error = true; return 0;
			}
		}
		
		if (string[counter] == 't'){
			if ((string[counter + 1] == 'a') && (string[counter + 2] == 'n') && (string[counter + 3] == '(')){
				counter = counter + 3;
				res = tan(value_at_a_point(string, counter, x, brct, error));
			}
			else{
				error = true; return 0;
			}
		}

		if (string[counter] == 'l'){
			if ((string[counter + 1] == 'o') && (string[counter + 2] == 'g') && (string[counter + 3] == '(')){
				counter = counter + 3;
				res = log(value_at_a_point(string, counter, x, brct, error));
			}
			else{
				error = true; return 0;
			}
		}

		if (string[counter] == 'e'){
			if ((string[counter + 1] == 'x') && (string[counter + 2] == 'p') && (string[counter + 3] == '(')){
				counter = counter + 3;
				res = exp(value_at_a_point(string, counter, x, brct, error));
			}
			else{
				error = true; return 0;
			}
		}

		if (string[counter] == 'a'){
			++counter;
			if (string[counter] == 's'){
				if ((string[counter + 1] == 'i') && (string[counter + 2] == 'n') && (string[counter + 3] == '(')){
					counter = counter + 3;
					res = asin(value_at_a_point(string, counter, x, brct, error));
				}
				else{
					error = true; return 0;
				}
			}

			if (string[counter] == 'c'){
				if ((string[counter + 1] == 'o') && (string[counter + 2] == 's') && (string[counter + 3] == '(')){
					counter = counter + 3;
					res = acos(value_at_a_point(string, counter, x, brct, error));
				}
				else{
					error = true; return 0;
				}
			}

			if (string[counter] == 't'){
				if ((string[counter + 1] == 'a') && (string[counter + 2] == 'n') && (string[counter + 3] == '(')){
					counter = counter + 3;
					res = atan(value_at_a_point(string, counter, x, brct, error));
				}
				else{
					error = true; return 0;
				}
			}

			if (string[counter] == 'b'){
				if ((string[counter + 1] == 's') && (string[counter + 2] == '(')){
					counter = counter + 2;
					res = abs(value_at_a_point(string, counter, x, brct, error));
				}
				else{
					error = true; return 0;
				}
			}
		}

		if (string[counter] == 'x'){
			res = x;
			counter++;
		}
		if (string[counter] == '.'){
			error = true;
			return 0;
		}
	}
	return res;
}

double degree(string string, int& counter, double x, int& brct, bool& error){
	double res = 0;
	bool pointchecker = false;
	bool mmarker = false;
	int subcounter = counter; // указатель на конеч числа

	while (counter < string.length()){

		if ((string[counter] >= '0') && (string[counter] <= '9')){
			bool pointchecker = false;
			int subcounter = counter; // счетчик для считывания числа
			if (mmarker) subcounter--; // - 
			while (((string[counter] >= '0') && (string[counter] <= '9')) || (string[counter] == '.')){ // !!!!

				if ((string[counter] == '.') && pointchecker){
					error = true; return 0;
				}
				if (string[counter] == '.') pointchecker = true;
				counter++;
			}
			res = stod(string.substr(subcounter, counter + 1)); // парсим число в дабл !!!
		}

		if (string[counter] == '+'){
			if (brct != 0){
				++counter;
				if (correctcont(string[counter])) res = res + value_at_a_point(string, counter, x, brct, error);
				else {
					error = true; return 0;
				}
			}
			else return res;
		}

		if (string[counter] == '-'){
			if (brct != 0){
				++counter;
				if (correctcont(string[counter])) res = res - value_at_a_point(string, counter, x, brct, error);
				else {
					error = true; return 0;
				}
			}
			else return res;
		}

		if (string[counter] == '*'){
			if (brct != 0){
				++counter;
				if (correctcont(string[counter])) res = res * multiplication(string, counter, x, brct, error);
				else {
					error = true; return 0;
				}
			}
			else return res;
		}

		if (string[counter] == '/'){
			if (brct != 0){
				++counter;
				if (correctcont(string[counter])) res = res / multiplication(string, counter, x, brct, error);
				else {
					error = true; return 0;
				}
			}
			else return res;
		}
		if (string[counter] == '^'){
			++counter;
			if (correctcont(string[counter])) res = pow(res, degree(string, counter, x, brct, error));
			else {
				error = true; return 0;
			}
		}

		if (string[counter] == '('){
			++counter; // возможно потом добавить счетчик  скобок
			++brct;
			if ((string[counter] == '-') && is_number(string[counter + 1])){
				mmarker = true;
			}
		}

		if (string[counter] == ')'){
			if (brct <= 0) {
				error = true;
				return 0;
			}
			++counter;
			if (counter == string.length()){
				--brct;
				return res;
			}
			else{
				if (string[counter] == '+' || string[counter] == '-' || string[counter] == '*' || string[counter] == '/' || string[counter] == '^'){
					--brct;
					return res;
				}
				else{
					error = true;
					return 0;
				}
			}
		}

		if (string[counter] == 's'){
			++counter;

			if (string[counter] == 'q'){
				if ((string[counter + 1] == 'r') && (string[counter + 2] == 't') && (string[counter + 3]) == '('){
					counter = counter + 3;
					res = sqrt(value_at_a_point(string, counter, x, brct, error));
				}
				else{
					error = true; return 0;
				}
			}

			if (string[counter] == 'i'){
				if ((string[counter + 1] == 'n') && (string[counter + 2] == '(')){
					counter = counter + 2;
					res = sin(value_at_a_point(string, counter, x, brct, error));
				}
				else{
					error = true; return 0;
				}
			}
		}

		if (string[counter] == 'c'){
			if ((string[counter + 1] == 'o') && (string[counter + 2] == 's') && (string[counter + 3] == '(')){
				counter = counter + 3;
				res = cos(value_at_a_point(string, counter, x, brct, error));
			}
			else{
				error = true; return 0;
			}
		}

		if (string[counter] == 't'){
			if ((string[counter + 1] == 'a') && (string[counter + 2] == 'n') && (string[counter + 3] == '(')){
				counter = counter + 3;
				res = tan(value_at_a_point(string, counter, x, brct, error));
			}
			else{
				error = true; return 0;
			}
		}

		if (string[counter] == 'l'){
			if ((string[counter + 1] == 'o') && (string[counter + 2] == 'g') && (string[counter + 3] == '(')){
				counter = counter + 3;
				res = log(value_at_a_point(string, counter, x, brct, error));
			}
			else{
				error = true; return 0;
			}
		}

		if (string[counter] == 'e'){
			if ((string[counter + 1] == 'x') && (string[counter + 2] == 'p') && (string[counter + 3] == '(')){
				counter = counter + 3;
				res = exp(value_at_a_point(string, counter, x, brct, error));
			}
			else{
				error = true; return 0;
			}
		}

		if (string[counter] == 'a'){
			++counter;

			if (string[counter] == 's'){
				if ((string[counter + 1] == 'i') && (string[counter + 2] == 'n') && (string[counter + 3] == '(')){
					counter = counter + 3;
					res = asin(value_at_a_point(string, counter, x, brct, error));
				}
				else{
					error = true; return 0;
				}
			}

			if (string[counter] == 'c'){
				if ((string[counter + 1] == 'o') && (string[counter + 2] == 's') && (string[counter + 3] == '(')){
					counter = counter + 3;
					res = acos(value_at_a_point(string, counter, x, brct, error));
				}
				else{
					error = true; return 0;
				}
			}

			if (string[counter] == 't'){
				if ((string[counter + 1] == 'a') && (string[counter + 2] == 'n') && (string[counter + 3] == '(')){
					counter = counter + 3;
					res = atan(value_at_a_point(string, counter, x, brct, error));
				}
				else{
					error = true; return 0;
				}
			}

			if (string[counter] == 'b'){
				if ((string[counter + 1] == 's') && (string[counter + 2] == '(')){
					counter = counter + 2;
					res = abs(value_at_a_point(string, counter, x, brct, error));
				}
				else{
					error = true; return 0;
				}
			}
		}

		if (string[counter] == 'x'){
			res = x;
			counter++;
		}
		if (string[counter] == '.'){
			error = true;
			return 0;
		}
	}
	return res;
}