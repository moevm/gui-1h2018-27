#include "stdafx.h"
#include <cmath>
#include <string>


using namespace std;
double degree(string string, int& counter, double x, int& brct);
double value_at_a_point(string string, int& counter, double x, int& brct);
double multiplication(string string, int& counter, double x, int& brct);


bool is_number(char a){
	if ((a >= '0') || (a <= '9')){
		return true;
	}
	else{
		return false;
	}
}

double value_at_a_point(string string, int& counter, double x, int& brct){
	double res = 0;

	while (counter < string.length()){ // !!!

		if ((string[counter] >= '0') && (string[counter] <= '9')){
			bool pointchecker = false;
			int subcounter = counter; // счетчик для считывания числа
			while (((string[counter] >= '0') && (string[counter] <= '9')) || (string[counter] == '.')){ // !!!!

				if ((string[counter] == '.') && pointchecker){
					//error
				}
				if (string[counter] == '.') pointchecker = true;
				counter++;
			}
			res = stod(string.substr(subcounter, counter+1)); // парсим число в дабл !!!
		}	

		if (string[counter] == '+'){
			++counter;
			if (is_number(string[counter]) || string[counter] == 'x' || string[counter] == '(')  res = res + value_at_a_point(string, counter, x, brct);
			else {
				//error
			}
		}

		if (string[counter] == '-'){
			++counter;
			if (is_number(string[counter]) || string[counter] == 'x' || string[counter] == '(')  res = res - value_at_a_point(string, counter, x, brct);
			else {
				//error
			}
		}

		if (string[counter] == '*'){
			++counter;
			if (is_number(string[counter]) || string[counter] == 'x' || string[counter] == '(') res = res * multiplication(string, counter, x, brct);
			else {
				//error
			}
		}

		if (string[counter] == '/'){
			++counter;
			if (is_number(string[counter]) || string[counter] == 'x' || string[counter] == '(') res = res / multiplication(string, counter, x, brct);
			else {
				//error
			}
		}

		if (string[counter] == '^'){
			++counter;
			if (is_number(string[counter]) || string[counter] == 'x' || string[counter] == '(')  res = pow(res, degree(string, counter, x, brct));
			else {
				//error
			}
		}

		if (string[counter] == '('){

			counter++; // возможно потом добавить счетчик  скобок
			++brct;
		}

		if (string[counter] == ')'){
			++counter;
			--brct;
			return res;
		}

		if (string[counter] == 's'){
			++counter;
			if (string[counter] == 'q'){
				if ((string[counter + 1] == 'r') && (string[counter + 2] == 't') && (string[counter + 3]) == '('){
					counter = counter + 3;
					res = sqrt(value_at_a_point(string, counter, x, brct));
				}
				else{
					//error
				}
			}
			if (string[counter] == 'i'){
				if ((string[counter + 1] == 'n') && (string[counter + 2] == '(')){
					counter = counter + 2;
					res = sin(value_at_a_point(string, counter, x, brct));
				}
				else{
					//error
				}
			}
		
		}

		if (string[counter] == 'c'){
			if ((string[counter + 1] == 'o') && (string[counter + 2] == 's') && (string[counter + 3] == '(')){
				counter = counter + 3;
				res = cos(value_at_a_point(string, counter, x, brct));
			}
			else{
				//error
			}
		}

		if (string[counter] == 't'){
			if ((string[counter + 1] == 'a') && (string[counter + 2] == 'n') && (string[counter + 3] == '(')){
				counter = counter + 3;
				res = tan(value_at_a_point(string, counter, x, brct));
			}
			else{
				//error
			}
		}

		if (string[counter] == 'l'){
			if ((string[counter + 1] == 'o') && (string[counter + 2] == 'g') && (string[counter + 3] == '(')){
				counter = counter + 3;
				res = log(value_at_a_point(string, counter, x, brct));
			}
			else{
				//error
			}
		}

		if (string[counter] == 'e'){
			if ((string[counter + 1] == 'x') && (string[counter + 2] == 'p') && (string[counter + 3] == '(')){
				counter = counter + 3;
				res = exp(value_at_a_point(string, counter, x, brct));
			}
			else{
				//error
			}
		}

		if (string[counter] == 'a'){
			++counter;
			if (string[counter] == 's'){
				if ((string[counter + 1] == 'i') && (string[counter + 2] == 'n') && (string[counter + 3] == '(')){
					counter = counter + 3;
					res = asin(value_at_a_point(string, counter, x, brct));
				}
				else{
					//error
				}
			}
			if (string[counter] == 'c'){
				if ((string[counter + 1] == 'o') && (string[counter + 2] == 's') && (string[counter + 3] == '(')){
					counter = counter + 3;
					res = acos(value_at_a_point(string, counter, x, brct));
				}
				else{
					//error
				}
			}
			if (string[counter] == 't'){
				if ((string[counter + 1] == 'a') && (string[counter + 2] == 'n') && (string[counter + 3] == '(')){
					counter = counter + 3;
					res = atan(value_at_a_point(string, counter, x, brct));
				}
				else{
					//error
				}
			}
			if (string[counter] == 'b'){
				if ((string[counter + 1] == 's') && (string[counter + 2] == '(')){
					counter = counter + 2;
					res = abs(value_at_a_point(string, counter, x, brct));
				}
				else{
					//error
				}
			}
		}

		if (string[counter] == 'x'){
			res = x;
			counter++;
		}
	}
	return res;
}

double multiplication(string string, int& counter, double x, int& brct){
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
					//error
				}
				if (string[counter] == '.') pointchecker = true;
				counter++;
			}
			res = stod(string.substr(subcounter, counter+1)); // парсим число в дабл !!!
		}

		if (string[counter] == '+'){
			if (brct != 0){
				++counter;
				if (is_number(string[counter]) || string[counter] == 'x' || string[counter] == '(') res = res + value_at_a_point(string, counter, x, brct);
				else {
					//error
				}
			}
			else return res;			
		}
			
		if (string[counter] == '-'){
			if (brct != 0){
				++counter;
				if (is_number(string[counter]) || string[counter] == 'x' || string[counter] == '(') res = res - value_at_a_point(string, counter, x, brct);
				else {
					//error
				}
			}
			else return res;
		}

		if (string[counter] == '*'){
			++counter;
			if (is_number(string[counter]) || string[counter] == 'x' || string[counter] == '(') res = res * multiplication(string, counter, x, brct);
			else {
				//error
			}
		}

		if (string[counter] == '/'){
			++counter;
			if (is_number(string[counter]) || string[counter] == 'x' || string[counter] == '(') res = res / multiplication(string, counter, x, brct);
			else {
				//error
			}
		}

		if (string[counter] == '^'){
			++counter;
			if (is_number(string[counter]) || string[counter] == 'x' || string[counter] == '(') res = pow(res, degree(string, counter, x, brct));
			else {
				//error
			}
		}

		if (string[counter] == '('){
			++counter; // возможно потом добавить счетчик  скобок
			++brct;
			if ((string[counter] == '-') && is_number(string[counter + 1])){
				mmarker = true;
			}
		}		

		if (string[counter] == '('){
			++counter;
			--brct;
			return res;
			}	

		if (string[counter] == 's'){
			++counter;
			if (string[counter] == 'q'){
				if ((string[counter + 1] == 'r') && (string[counter + 2] == 't') && (string[counter + 3]) == '('){
					counter = counter + 3;
					res = sqrt(value_at_a_point(string, counter, x, brct));
				}
				else{
					//error
				}
			}
			if (string[counter] == 'i'){
				if ((string[counter + 1] == 'n') && (string[counter + 2] == '(')){
					counter = counter + 2;
					res = sin(value_at_a_point(string, counter, x, brct));
				}
				else{
					//error
				}
			}
		}

		if (string[counter] == 'c'){
			if ((string[counter + 1] == 'o') && (string[counter + 2] == 's') && (string[counter + 3] == '(')){
				counter = counter + 3;
				res = cos(value_at_a_point(string, counter, x, brct));
			}
			else{
				//error
			}
		}

		if (string[counter] == 't'){
			if ((string[counter + 1] == 'a') && (string[counter + 2] == 'n') && (string[counter + 3] == '(')){
				counter = counter + 3;
				res = tan(value_at_a_point(string, counter, x, brct));
			}
			else{
				//error
			}
		}

		if (string[counter] == 'l'){
			if ((string[counter + 1] == 'o') && (string[counter + 2] == 'g') && (string[counter + 3] == '(')){
				counter = counter + 3;
				res = log(value_at_a_point(string, counter, x, brct));
			}
			else{
				//error
			}
		}

		if (string[counter] == 'e'){
			if ((string[counter + 1] == 'x') && (string[counter + 2] == 'p') && (string[counter + 3] == '(')){
				counter = counter + 3;
				res = exp(value_at_a_point(string, counter, x, brct));
			}
			else{
				//error
			}
		}

		if (string[counter] == 'a'){
			++counter;
			if (string[counter] == 's'){
				if ((string[counter + 1] == 'i') && (string[counter + 2] == 'n') && (string[counter + 3] == '(')){
					counter = counter + 3;
					res = asin(value_at_a_point(string, counter, x, brct));
				}
				else{
					//error
				}
			}

			if (string[counter] == 'c'){
				if ((string[counter + 1] == 'o') && (string[counter + 2] == 's') && (string[counter + 3] == '(')){
					counter = counter + 3;
					res = acos(value_at_a_point(string, counter, x, brct));
				}
				else{
					//error
				}
			}

			if (string[counter] == 't'){
				if ((string[counter + 1] == 'a') && (string[counter + 2] == 'n') && (string[counter + 3] == '(')){
					counter = counter + 3;
					res = atan(value_at_a_point(string, counter, x, brct));
				}
				else{
					//error
				}
			}

			if (string[counter] == 'b'){
				if ((string[counter + 1] == 's') && (string[counter + 2] == '(')){
					counter = counter + 2;
					res = abs(value_at_a_point(string, counter, x, brct));
				}
				else{
					//error
				}
			}
		}

		if (string[counter] == 'x'){
			res = x;
			counter++;
		}
	}
	return res;
}

double degree(string string, int& counter, double x, int& brct){
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
					//error
				}
				if (string[counter] == '.') pointchecker = true;
				counter++;
			}
			res = stod(string.substr(subcounter, counter + 1)); // парсим число в дабл !!!
		}

		if (string[counter] == '+'){
			if (brct != 0){
				++counter;
				if (is_number(string[counter]) || string[counter] == 'x' || string[counter] == '(') res = res + value_at_a_point(string, counter, x, brct);
				else {
					//error
				}
			}
			else return res;
		}

		if (string[counter] == '-'){
			if (brct != 0){
				++counter;
				if (is_number(string[counter]) || string[counter] == 'x' || string[counter] == '(') res = res - value_at_a_point(string, counter, x, brct);
				else {
					//error
				}
			}
			else return res;
		}

		if (string[counter] == '*'){
			if (brct != 0){
				++counter;
				if (is_number(string[counter]) || string[counter] == 'x' || string[counter] == '(') res = res * multiplication(string, counter, x, brct);
				else {
					//error
				}
			}
			else return res;
		}

		if (string[counter] == '/'){
			if (brct != 0){
				++counter;
				if (is_number(string[counter]) || string[counter] == 'x' || string[counter] == '(') res = res / multiplication(string, counter, x, brct);
				else {
					//error
				}
			}
			else return res;
		}
		if (string[counter] == '^'){
			++counter;
			if (is_number(string[counter]) || string[counter] == 'x' || string[counter] == '(') res = pow(res, degree(string, counter, x, brct));
			else {
				//error
			}
		}

		if (string[counter] == '('){
			++counter; // возможно потом добавить счетчик  скобок
			++brct;
			if ((string[counter] == '-') && is_number(string[counter + 1])){
				mmarker = true;
			}
		}

		if (string[counter] == '('){
			++counter;
			--brct;
			return res;
		}

		if (string[counter] == 's'){
			++counter;

			if (string[counter] == 'q'){
				if ((string[counter + 1] == 'r') && (string[counter + 2] == 't') && (string[counter + 3]) == '('){
					counter = counter + 3;
					res = sqrt(value_at_a_point(string, counter, x, brct));
				}
				else{
					//error
				}
			}

			if (string[counter] == 'i'){
				if ((string[counter + 1] == 'n') && (string[counter + 2] == '(')){
					counter = counter + 2;
					res = sin(value_at_a_point(string, counter, x, brct));
				}
				else{
					//error
				}
			}
		}

		if (string[counter] == 'c'){
			if ((string[counter + 1] == 'o') && (string[counter + 2] == 's') && (string[counter + 3] == '(')){
				counter = counter + 3;
				res = cos(value_at_a_point(string, counter, x, brct));
			}
			else{
				//error
			}
		}

		if (string[counter] == 't'){
			if ((string[counter + 1] == 'a') && (string[counter + 2] == 'n') && (string[counter + 3] == '(')){
				counter = counter + 3;
				res = tan(value_at_a_point(string, counter, x, brct));
			}
			else{
				//error
			}
		}

		if (string[counter] == 'l'){
			if ((string[counter + 1] == 'o') && (string[counter + 2] == 'g') && (string[counter + 3] == '(')){
				counter = counter + 3;
				res = log(value_at_a_point(string, counter, x, brct));
			}
			else{
				//error
			}
		}

		if (string[counter] == 'e'){
			if ((string[counter + 1] == 'x') && (string[counter + 2] == 'p') && (string[counter + 3] == '(')){
				counter = counter + 3;
				res = exp(value_at_a_point(string, counter, x, brct));
			}
			else{
				//error
			}
		}

		if (string[counter] == 'a'){
			++counter;

			if (string[counter] == 's'){
				if ((string[counter + 1] == 'i') && (string[counter + 2] == 'n') && (string[counter + 3] == '(')){
					counter = counter + 3;
					res = asin(value_at_a_point(string, counter, x, brct));
				}
				else{
					//error
				}
			}

			if (string[counter] == 'c'){
				if ((string[counter + 1] == 'o') && (string[counter + 2] == 's') && (string[counter + 3] == '(')){
					counter = counter + 3;
					res = acos(value_at_a_point(string, counter, x, brct));
				}
				else{
					//error
				}
			}

			if (string[counter] == 't'){
				if ((string[counter + 1] == 'a') && (string[counter + 2] == 'n') && (string[counter + 3] == '(')){
					counter = counter + 3;
					res = atan(value_at_a_point(string, counter, x, brct));
				}
				else{
					//error
				}
			}

			if (string[counter] == 'b'){
				if ((string[counter + 1] == 's') && (string[counter + 2] == '(')){
					counter = counter + 2;
					res = abs(value_at_a_point(string, counter, x, brct));
				}
				else{
					//error
				}
			}
		}

		if (string[counter] == 'x'){
			res = x;
			counter++;
		}
	}
	return res;
}