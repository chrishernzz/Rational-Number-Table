#pragma once
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//precondition: going to make a class header that is called Rational
//postcondition: going to do getters, setters, class inside public, functions, and overloading operators
class Rational{
private:
	int numerator, denominator; 
	//getting the greatest common dominator
	int gcd(int a, int b) {
		if (a == 0) {
			return b;
		}
		else if (b == 0) {
			return a;
		}
		else if (a ==  b) {
			return a;
		}
		else if(a> b) {
			return gcd(a-b,b);
		}
		else {
			return gcd(a, b - a);
		}
	}
	//function will check if denominator is negative, then the negative sign is moved to the numerator
	void normalize() {
		if (denominator < 0) {
			denominator *= -1;
			numerator *= -1;
		}
		if (numerator != 0) {
			int temp = gcd(abs(numerator), abs(denominator));
			numerator /= temp;
			denominator /= temp;
		}
	}
public:
	class ZeroDenominator {
	private:
		string rational;
	public:
		//defualt constructor
		ZeroDenominator() {}
		//constructor one argument(parameter)
		ZeroDenominator(Rational r) {
			rational = r.toString();
		}
		string toString() {
			return rational;
		}
	};
	//defualt constructor 
	Rational() {
		numerator = 0;
		denominator = 1;
	}
	//function that returns a string expression of the numerator/denominator
	string toString() {
		return to_string(numerator) + "/" + to_string(denominator);
	}
	//constructor
	Rational(int newNumerator, int newDenominator) {
		numerator = newNumerator;
		denominator = newDenominator;
		//if the denominator is zero, throw
		if (denominator == 0) {
			throw ZeroDenominator(*this);
		}
		normalize();
	}

	//getters(mutators)
	int getNumerator() const {
		return numerator;
	}
	int getDenominator() const {
		return denominator;
	}

	//setters(mutators)
	void setNumerator(int newNumerator) {
		numerator = newNumerator;
	}
	void setDenominator(int newDenominator) {
		denominator = newDenominator;
		if (denominator == 0) {
			throw ZeroDenominator(*this);
		}
		normalize();
	}

	//overloading ==, <,
	friend bool operator==(const Rational& obj, const Rational& obj2) {
		return (obj.numerator * obj2.denominator) == (obj2.numerator * obj.denominator);
	}
	friend bool operator<(const Rational& obj, const Rational& obj2) {
		return (obj.numerator * obj2.denominator) < (obj2.numerator * obj.denominator);
	}
	friend ostream& operator<<(ostream& out, Rational obj) {
		out <<obj.toString();
		return out;
	}
};

