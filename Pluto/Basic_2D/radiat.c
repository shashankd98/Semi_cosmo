/* ///////////////////////////////////////////////////////////////////// */
/*! 
  \file  
  \brief Compute right hand side for Tabulated cooling

  \authors A. Mignone (mignone@ph.unito.it)\n
           M. Sormani\n

 \b References

  \date   Apr 09, 2019
*/
/* ///////////////////////////////////////////////////////////////////// */
#include "pluto.h"

extern double gCooling_x1, gCooling_x2, gCooling_x3;

double LamCool(double);
double WiersmaCool(double);

/* ***************************************************************** */
void Radiat (double *v, double *rhs)
/*!
 *   Provide r.h.s. for tabulated cooling.
 * 
 ******************************************************************* */
{
  int    klo, khi, kmid;
  static int ntab;
  double  mu, T, Tmid, scrh, dT, prs;
  static double *L_tab, *T_tab, E_cost;
  double nH = UNIT_DENSITY/CONST_amu*H_MASS_FRAC/CONST_AH*v[RHO];
  double ne = nH*(1.0 + 0.5*CONST_AZ*FRAC_Z);
  
/* -------------------------------------------
        Read tabulated cooling function
   ------------------------------------------- */
  g_minCoolingTemp=2.e4;
  
  E_cost = UNIT_LENGTH/UNIT_DENSITY/pow(UNIT_VELOCITY, 3.0);
/* ---------------------------------------------
            Get pressure and temperature 
   --------------------------------------------- */

  prs = v[RHOE]*(g_gamma-1.0);
  if (prs < 0.0) {
    prs     = g_smallPressure;
    v[RHOE] = prs/(g_gamma - 1.0);
  }

  mu  = MeanMolecularWeight(v);
  T   = prs/v[RHO]*KELVIN*mu;

  if (T != T){
    printf ("! Radiat(): Nan found: rho = %12.6e, prs = %12.6e\n",v[RHO], prs);
    QUIT_PLUTO(1);
  }
/*
  if (T < g_minCoolingTemp) { 
    rhs[RHOE] = 0.0;
    return;
  }
*/
/* ----------------------------------------------
        Table lookup by binary search  
   ---------------------------------------------- */
  if (T<2.e4) T=2.e4;
  else if (T>1.e9) T=1.e9;

  scrh=WiersmaCool(T);
  
  rhs[RHOE] = -ne*nH*scrh*E_cost;
  
  //printf("%g \n",rhs[RHOE]);
/* ----------------------------------------------
    Temperature cutoff
   ---------------------------------------------- */

  rhs[RHOE] *= 1.0 - 1.0/cosh( pow( T/g_minCoolingTemp, 12.0));

}
