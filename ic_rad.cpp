#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

//all in cgs
const double pi=3.1415926;
const double c=2.997e10; //speed of light 2.997e10 cm s-1
const double pc=3.0856e18; //1pc=3.26ly=3.0856e18cm
const double h=6.626e-27; //planck constant 6.626e-27 erg s-1
const double h_bar=1.054e-27;//h_bar=h/2pi
const double eV=1.602e-12; //1 eV = 1.602e-12 erg
const double Me=9.1e-28; //mass of electron in units of g
const double e_charge=4.8e-10; // charge of an electron in units of e.s.u
const double Ee_min=1.0e9*eV;//Ee_min=1 GeV min energy of the electron distribution
const double Ee_max= 5.11e14*eV;//Ee_max=511 TeV following Naima default configuration
const double K_bzm = 1.38e-16;//Boltzman constant in units of erg K^-1

const double dist = 1.5e3*pc; //distance to earth

double G3(double x) //Eqs 20, 24, 25 26 27 of Khangulyan et al (2014)
{
    double alpha3 = 0.606;
    double beta3 = 1.481;
    double a3 = 0.443;
    double b3 = 0.54;
    double c3 = 0.319;
    double pi26=pi*pi/6.0;
    double tmp1 = (1.0+c3*x)/(1.0+pi26*c3*x);
    double G30 = pi26*tmp1*exp(-x);
    double tmp2 = 1.0 + b3*pow(x,beta3);
    double g3 = 1.0/(1.0+a3*pow(x,alpha3)/tmp2);
    return G30*g3;
}

double G4(double x) //Eqs 20, 24, 25 26 27 of Khangulyan et al (2014)
{
    double alpha4 = 0.461;
    double beta4 = 1.457;
    double a4 = 0.726;
    double b4 = 0.382;
    double c4 = 6.62;
    double pi26=pi*pi/6.0;
    double tmp1 = (1.0+c4*x)/(1.0+pi26*c4*x);
    double G40 = pi26*tmp1*exp(-x);
    double tmp2 = 1.0 + b4*pow(x,beta4);
    double g4 = 1.0/(1.0+a4*pow(x,alpha4)/tmp2);
    return G40*g4;
}

int main()
{

    return 0;
}
