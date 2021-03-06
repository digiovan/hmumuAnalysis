//==========================================================================
// This file has been automatically generated for C++ Standalone
// MadGraph 5 v. 1.5.7, 2013-01-15
// By the MadGraph Development Team
// Please visit us at https://launchpad.net/madgraph5
//==========================================================================

#ifndef HelAmps_HEF_MEKD_spin1pA_H
#define HelAmps_HEF_MEKD_spin1pA_H

#include <cmath> 
#include <complex> 

using namespace std; 

namespace MG5_HEF_MEKD_spin1pA
{
double Sgn(double e, double f); 

void oxxxxx(double p[4], double fmass, int nhel, int nsf, std::complex<double>
    fo[6]);

void vxxxxx(double p[4], double vmass, int nhel, int nsv, std::complex<double>
    v[6]);

void sxxxxx(double p[4], int nss, std::complex<double> sc[3]); 

void ixxxxx(double p[4], double fmass, int nhel, int nsf, std::complex<double>
    fi[6]);

void FFV2_3(complex<double> F1[], complex<double> F2[], complex<double> COUP,
    double M3, double W3, complex<double> V3[]);

void VVV2_0(complex<double> V1[], complex<double> V2[], complex<double> V3[],
    complex<double> COUP, complex<double> & vertex);

void FFV2_2(complex<double> F1[], complex<double> V3[], complex<double> COUP,
    double M2, double W2, complex<double> F2[]);

void FFV7_3(complex<double> F1[], complex<double> F2[], complex<double> COUP,
    double M3, double W3, complex<double> V3[]);

void VVV2_1(complex<double> V2[], complex<double> V3[], complex<double> COUP,
    double M1, double W1, complex<double> V1[]);

void FFV5_3(complex<double> F1[], complex<double> F2[], complex<double> COUP,
    double M3, double W3, complex<double> V3[]);
void FFV5_7_3(complex<double> F1[], complex<double> F2[], complex<double>
    COUP1, complex<double> COUP2, double M3, double W3, complex<double> V3[]);

void FFV3_3(complex<double> F1[], complex<double> F2[], complex<double> COUP,
    double M3, double W3, complex<double> V3[]);

void FFV5_0(complex<double> F1[], complex<double> F2[], complex<double> V3[],
    complex<double> COUP, complex<double> & vertex);
void FFV5_7_0(complex<double> F1[], complex<double> F2[], complex<double> V3[],
    complex<double> COUP1, complex<double> COUP2, complex<double> & vertex);

void FFV1_3(complex<double> F1[], complex<double> F2[], complex<double> COUP,
    double M3, double W3, complex<double> V3[]);
void FFV1_2_3_4_3(complex<double> F1[], complex<double> F2[], complex<double>
    COUP1, complex<double> COUP2, complex<double> COUP3, complex<double> COUP4,
    double M3, double W3, complex<double> V3[]);

void VVV1_0(complex<double> V1[], complex<double> V2[], complex<double> V3[],
    complex<double> COUP, complex<double> & vertex);
void VVV1_2_0(complex<double> V1[], complex<double> V2[], complex<double> V3[],
    complex<double> COUP1, complex<double> COUP2, complex<double> & vertex);

void FFV2_1(complex<double> F2[], complex<double> V3[], complex<double> COUP,
    double M1, double W1, complex<double> F1[]);

void VVV1_1(complex<double> V2[], complex<double> V3[], complex<double> COUP,
    double M1, double W1, complex<double> V1[]);
void VVV1_2_1(complex<double> V2[], complex<double> V3[], complex<double>
    COUP1, complex<double> COUP2, double M1, double W1, complex<double> V1[]);

void FFV4_3(complex<double> F1[], complex<double> F2[], complex<double> COUP,
    double M3, double W3, complex<double> V3[]);

void FFV7_0(complex<double> F1[], complex<double> F2[], complex<double> V3[],
    complex<double> COUP, complex<double> & vertex);

}  // end namespace MG5_HEF_MEK

#endif  // HelAmps_HEF_MEKD_H
