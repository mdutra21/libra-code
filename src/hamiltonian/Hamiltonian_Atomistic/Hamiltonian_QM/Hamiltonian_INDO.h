/*********************************************************************************
* Copyright (C) 2015 Alexey V. Akimov
*
* This file is distributed under the terms of the GNU General Public License
* as published by the Free Software Foundation, either version 2 of
* the License, or (at your option) any later version.
* See the file LICENSE in the root directory of this distribution
* or <http://www.gnu.org/licenses/>.
*
*********************************************************************************/

#ifndef HAMILTONIAN_INDO_H
#define HAMILTONIAN_INDO_H

#include "../../../calculators/libcalculators.h"
using namespace libcalculators;

#include "../../../qchem/libqchem.h"
using namespace libqchem;
using namespace libqchem::libqobjects;

#include "../../../chemobjects/libchemobjects.h"
using namespace libchemobjects;
using namespace libchemobjects::libchemsys;

#include "Control_Parameters/libcontrol_parameters.h"
using namespace libhamiltonian::libhamiltonian_atomistic::libhamiltonian_qm::libcontrol_parameters;

#include "Model_Parameters/libmodel_parameters.h"
using namespace libhamiltonian::libhamiltonian_atomistic::libhamiltonian_qm::libmodel_parameters;

#include "Electronic_Structure.h"


namespace libhamiltonian{
namespace libhamiltonian_atomistic{
namespace libhamiltonian_qm{



// Hamiltonian_INDO.cpp
vector<int> compute_sorb_indices
( int sz, vector<AO>& basis_ao, vector< vector<int> >& atom_to_ao_map, vector<int>& ao_to_atom_map
);

void compute_indo_core_parameters
( System& syst, vector<AO>& basis_ao, Model_Parameters& modprms,
  vector< vector<int> >& atom_to_ao_map, vector<int>& ao_to_atom_map,
  vector<int>& sorb_indx,
  int opt, int a, int b, double& eri, double& V_AB
);

void compute_indo_core_parameters_derivs
( System& syst, vector<AO>& basis_ao, Model_Parameters& modprms,
  vector< vector<int> >& atom_to_ao_map, vector<int>& ao_to_atom_map,
  vector<int>& sorb_indx,
  int opt, int a, int b, int c, VECTOR& deri, VECTOR& dV_AB
);

void indo_core_parameters
( System& syst, vector<AO>& basis_ao, Model_Parameters& modprms,
  vector< vector<int> >& atom_to_ao_map, vector<int>& ao_to_atom_map,
  int opt, int DF
);




void Hamiltonian_core_indo
( System& syst, vector<AO>& basis_ao, 
  Control_Parameters& prms, Model_Parameters& modprms,
  vector< vector<int> >& atom_to_ao_map, vector<int>& ao_to_atom_map,
  MATRIX* Hao, MATRIX* Sao, int DF
);

void Hamiltonian_core_indo
( System& syst, vector<AO>& basis_ao, 
  Control_Parameters& prms, Model_Parameters& modprms,
  vector< vector<int> >& atom_to_ao_map, vector<int>& ao_to_atom_map,
  MATRIX& Hao, MATRIX& Sao, int DF
);

void Hamiltonian_core_deriv_indo
( System& syst, vector<AO>& basis_ao, 
  Control_Parameters& prms, Model_Parameters& modprms,
  vector< vector<int> >& atom_to_ao_map, vector<int>& ao_to_atom_map,
  MATRIX* Hao, MATRIX* Sao, int DF,
  int c,
  MATRIX* dHao_dx, MATRIX* dHao_dy, MATRIX* dHao_dz, 
  MATRIX* dSao_dx, MATRIX* dSao_dy, MATRIX* dSao_dz
);

void Hamiltonian_core_deriv_indo
( System& syst, vector<AO>& basis_ao, 
  Control_Parameters& prms, Model_Parameters& modprms,
  vector< vector<int> >& atom_to_ao_map, vector<int>& ao_to_atom_map,
  MATRIX& Hao, MATRIX& Sao, int DF,
  int c,
  MATRIX& dHao_dx, MATRIX& dHao_dy, MATRIX& dHao_dz, 
  MATRIX& dSao_dx, MATRIX& dSao_dy, MATRIX& dSao_dz
);



void get_integrals(int i,int j,vector<AO>& basis_ao, double eri_aa, double G1, double F2, double& ii_jj,double& ij_ij);



void Hamiltonian_Fock_indo(Electronic_Structure* el, System& syst, vector<AO>& basis_ao,
                           Control_Parameters& prms,Model_Parameters& modprms,
                           vector< vector<int> >& atom_to_ao_map, vector<int>& ao_to_atom_map
                          );

void Hamiltonian_Fock_indo(Electronic_Structure& el, System& syst, vector<AO>& basis_ao,
                           Control_Parameters& prms,Model_Parameters& modprms,
                           vector< vector<int> >& atom_to_ao_map, vector<int>& ao_to_atom_map
                          );

void Hamiltonian_Fock_derivs_indo
( Electronic_Structure* el, System& syst, vector<AO>& basis_ao,
  Control_Parameters& prms, Model_Parameters& modprms,
  vector< vector<int> >& atom_to_ao_map, vector<int>& ao_to_atom_map,
  int c, 
  MATRIX* dHao_dx, MATRIX* dHao_dy, MATRIX* dHao_dz,
  MATRIX* dFao_alp_dx, MATRIX* dFao_alp_dy, MATRIX* dFao_alp_dz,
  MATRIX* dFao_bet_dx, MATRIX* dFao_bet_dy, MATRIX* dFao_bet_dz
);

void Hamiltonian_Fock_derivs_indo
( Electronic_Structure& el, System& syst, vector<AO>& basis_ao,
  Control_Parameters& prms, Model_Parameters& modprms,
  vector< vector<int> >& atom_to_ao_map, vector<int>& ao_to_atom_map,
  int c, 
  MATRIX& dHao_dx,     MATRIX& dHao_dy,     MATRIX& dHao_dz,
  MATRIX& dFao_alp_dx, MATRIX& dFao_alp_dy, MATRIX& dFao_alp_dz,
  MATRIX& dFao_bet_dx, MATRIX& dFao_bet_dy, MATRIX& dFao_bet_dz
);






/*
void indo_core_parameters(vector<int>&, vector<int>&, vector<AO>&, Nuclear&, vector<double>&, vector<double>&, Memory*, int);

void Hamiltonian_core_indo(Control_Parameters&, Model_Parameters&, Nuclear&,
                           vector<int>&, vector<int>&, vector<AO>&, vector<vector<int> >&, 
                           MATRIX*, MATRIX*, Memory*, vector<double>&, vector<double>&);


void get_integrals(int, int, vector<AO>&, double, double, double, double&, double&);

void Hamiltonian_Fock_indo(Control_Parameters&, Model_Parameters&, Nuclear&,
                           vector<int>&, vector<int>&, vector<AO>&, vector<vector<int> >&,
                           Electronic*, Memory*, vector<double>&, vector<double>&);
*/




}// namespace libhamiltonian_qm
}// namespace libhamiltonian_atomistic
}// namespace libhamiltonian


#endif // HAMILTONIAN_INDO_H
