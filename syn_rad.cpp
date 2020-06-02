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

const double dist = 1.5e3*pc; //distance to earth
const double B_field = 1.0e-4; // magnetic field in units of G
const double alpha = 2.1; //spectra index
const double beta = 1.0; //spectra index for E cut off
const double amplitude=1.0e36/eV;//normlization factor which is 1.0e36 ev^-1 and change to erg^-1
//which is atcually cal by total electron energy = We i.e. integrate E*(dN/dE) dE in E range to get total energy
//here 1.0e36 ev^-1 is a test value
const double E0 = 1.0e12*eV;//E0 is 1 TeV
const double Ecutoff=1.3e13*eV;//Ecutoff is 13 TeV

double G(double x) //Aharonian et al.2010 Eq.D7
{
    double x_cb = pow(x,1.0/3.0); //cubic root of x
    double part1 = 1.808*x_cb/sqrt(1.0 + 3.4*x_cb*x_cb);
    double part2 = 1.0 + 2.21*x_cb*x_cb + 0.347*x_cb*x_cb*x_cb*x_cb;
    double part3 = 1.0 + 1.353*x_cb*x_cb + 0.217*x_cb*x_cb*x_cb*x_cb;
    return part1*(part2/part3)*exp(-x);
}

double Esyn_c(double Ee) //the character Energy of synch photon
{
    double part1 = 3.0*B_field*Ee*Ee*h_bar*e_charge;
    double part2 = 2.0*Me*Me*Me*c*c*c*c*c;
    return part1/part2;
}


void test_syn()
{
    const int n = 200;
    double dlnE = (log(Ee_max)-log(Ee_min))/(double)(n-1);
    double Ee_arr[n];
    double Egamma_min = 0.1*eV;
    double Egamma_max = 1.0e7*eV;
    double dlnEg = (log(Egamma_max)-log(Egamma_min))/(double)(n-1);
    double E_gamma[n];
    //double E_gamma = 1.0*eV; //1.0 eV change to erg
    ofstream ofs;
    ofs.open("syn_sed.txt", ios::out);
    for(int i=0;i<n;i++)
    {
        Ee_arr[i]=exp(log(Ee_min)+i*dlnE);
    }
    for(int i=0;i<n;i++)
    {
        E_gamma[i]=exp(log(Egamma_min)+i*dlnEg);
    }
//    for(int i=0;i<n;i++)
//    {
//        cout<< i << '\t' << Ee_arr[i] << endl;
//    }
    for(int j=0; j<n; j++)
    {
    double sum=0.;
    for(int i=0; i<n-1;i++)
    {
        double up_part1=sqrt(3.0)*e_charge*e_charge*e_charge*B_field;
        double down_part1=h*Me*c*c*E_gamma[j];
        double Ec1= Esyn_c(Ee_arr[i]);
        double G1 = G(E_gamma[j]/Ec1);
        double f1=up_part1/down_part1*G1*amplitude*pow(Ee_arr[i]/E0,-alpha)*exp(-Ee_arr[i]/Ecutoff);

        double up_part2=sqrt(3.0)*e_charge*e_charge*e_charge*B_field;
        double down_part2=h*Me*c*c*E_gamma[j];
        double Ec2= Esyn_c(Ee_arr[i+1]);
        double G2 = G(E_gamma[j]/Ec2);
        double f2=up_part2/down_part2*G2*amplitude*pow(Ee_arr[i+1]/E0,-alpha)*exp(-Ee_arr[i+1]/Ecutoff);
        sum+=0.5*(f1+f2)*(Ee_arr[i+1]-Ee_arr[i]);
    }
    double flux = sum/(4.0*pi*dist*dist);
    ofs << E_gamma[j]/eV << '\t' << E_gamma[j]*E_gamma[j]*flux << endl;//E^2dN/dE in units of erg s^-1 cm^-2
    }
    ofs.close();
}

//void test_G()
//{
//    const int n = 200;
//    double x_min = 1.0e-4;
//    double x_max = 10.0;
//    double dlnx = (log(x_max)-log(x_min))/(double)(n-1);
//    double x_arr[n];
//    for(int i=0;i<n;i++)
//    {
//        x_arr[i]=exp(log(x_min)+i*dlnx);
//    }
////    for(int i=0;i<n;i++)
////    {
////        cout << i << '\t' << x_arr[i] << endl;
////    }
//    ofstream ofs;
//    ofs.open("syn_g.txt", ios::out);


//    for(int i=0;i<n;i++)
//    {
//        ofs << x_arr[i] << '\t' << G(x_arr[i]) << endl;
//    }
//    ofs.close();
//}

int main()
{

    //test_G();
    test_syn();
    return 0;
}




