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
const double Ee_max=5.11e14*eV;//Ee_max=511 TeV following Naima default configuration
const double K_bzm = 1.38e-16;//Boltzman constant in units of erg K^-1
const double r0 = e_charge*e_charge/(Me*c*c);//electron classical redius
const double E_elec = 0.511e6*eV;//electron rest energy


const double dist = 1.5e3*pc; //distance to earth
const double amplitude=1.0e36/eV;//normlization factor which is 1.0e36 ev^-1 and change to erg^-1
//which is atcually cal by total electron energy = We i.e. integrate E*(dN/dE) dE in E range to get total energy
//here 1.0e36 ev^-1 is a test value
const double alpha = 2.1; //spectra index
const double beta = 1.0; //spectra index for E cut off
const double E0 = 1.0e12*eV;//E0 is 1 TeV
const double Ecutoff=1.3e13*eV;//Ecutoff is 13 TeV
//here the IC radiation just consider isotropic photon field
//for mono-directional photon field see also Khangulyan et al 2014
const double sigma_sb = 5.67e-5;//stefan boltzman constant in units of ers/s/cm^2/K^4

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


//void test_G3G4()
//{
//    const int n = 200;
//    double x_min = 1.0e-3;
//    double x_max = 100.0;
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
//    ofs.open("ic_g3g4.txt", ios::out);


//    for(int i=0;i<n;i++)
//    {
//        ofs << x_arr[i] << '\t' << G3(x_arr[i])*exp(x_arr[i]) << '\t' << G4(x_arr[i])*exp(x_arr[i]) << endl;
//    }
//    ofs.close();
//}


// IC cross-section for isotropic interaction with a blackbody photon
//spectrum following Eq. 14 of Khangulyan, Aharonian, and Kelner 2014,
//soft_photon_temperature is in units of K 
//and K_bzm*T is thermal energy

//the energies of both photons and electrons, as well as the photon gas temperature, are expressed
//in units of mec2 //but here all is in erg
double soft_photon_temperature = 30.0;//CMB is 2.72 K
//FIR is 30 K energy_density is 0.5 eV/cm^3
//NIR is 3000k energy_density is 1.0 eV/cm^3
double energy_density = 0.5*eV; //change in erg/cm^3
double Temperature = soft_photon_temperature * K_bzm;//in erg
double ar = 4.0*sigma_sb/c;//sigma_sb is in units of ers/s/cm^2/K^4
double uf = energy_density/(ar*pow(soft_photon_temperature,4.0));//for CMB uf is 1.0 for FIR NIR uf is calculated by energy_density/(ar*T^4)

double dNdwdt(double Egamma,double Ee)
{

    double z = Egamma/Ee; //Ee should also in erg
    double t = 4.0*(Ee/E_elec)*(Temperature/E_elec);//in Khangulyan2014 t=4ET while E and T are in units of mec2
    double x = z/(1.0-z)/t;
    double tmp1 = 0.5*z*z/(1.0-z);
    double cross_section = tmp1*G3(x)+G4(x);
    //double constants = 2.0*r0*r0*Me*Me*Me*c*c*c*c/(pi*h_bar*h_bar*h_bar);
    double constants= 2.6318735743809104e16;
    //double k=1.0;//not considered here but may contain in Amplitude like in Syn_rad.cpp as
    // k is a dilution factor which << 1 i.e. reducing the amplitude of spectrum or k=1.0 for isotropic ?
    double tmp2 = Temperature*Temperature/(Ee*Ee);
    double dndwdt = cross_section * constants * tmp2;
    if(Egamma<Ee && Ee>E_elec) //Egamma should not > Ee and Ee should > E_elec
    {
        return dndwdt;
    }
    else
    {
        return 0.0;
    }

}

void test_ic()
{
    const int n = 200;
    double dlnE = (log(Ee_max)-log(Ee_min))/(double)(n-1);
    double Ee_arr[n];
    //double Egamma = 1.0e12*eV;//10^4 eV in units of erg for test
    double E_gamma[n];
    double Egamma_min = 1.0e3*eV;
    double Egamma_max = 1.0e14*eV;
    double dlnEg = (log(Egamma_max)-log(Egamma_min))/(double)(n-1);
    ofstream ofs;
    ofs.open("ic_sed.txt", ios::out);
    for(int i=0;i<n;i++)
    {
        E_gamma[i]=exp(log(Egamma_min)+i*dlnEg);
    }
    for(int i=0;i<n;i++)
    {
        Ee_arr[i]=exp(log(Ee_min)+i*dlnE);
    }
    for(int j=0; j<n; j++)
    {
    double sum=0.;
    for(int i=0; i<n-1;i++)
    {
        double tmp1 = dNdwdt(E_gamma[j],Ee_arr[i]);
        double f1=tmp1*amplitude*pow(Ee_arr[i]/E0,-alpha)*exp(-Ee_arr[i]/Ecutoff);

        double tmp2 = dNdwdt(E_gamma[j],Ee_arr[i+1]);
        double f2=tmp2*amplitude*pow(Ee_arr[i+1]/E0,-alpha)*exp(-Ee_arr[i+1]/Ecutoff);
        sum+=0.5*(f1+f2)*(Ee_arr[i+1]-Ee_arr[i]);
    }
    double flux = sum/(4.0*pi*dist*dist);
    ofs << E_gamma[j]/eV << '\t' << uf*1.2216e6*E_gamma[j]*E_gamma[j]*flux << endl;//E^2dN/dE in units of erg s^-1 cm^-2
    //1.2216e6 is due to dndwdt as the dw is in units of mec2
    //so here we should multiply 1/mec2(in erg) which is 1.2216e6
    }
    ofs.close();
    //cout << uf << endl;
}

int main()
{
    //test_G3G4();
    test_ic();
    return 0;
}
































