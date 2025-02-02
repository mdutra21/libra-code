/*********************************************************************************
* Copyright (C) 2015-2019 Alexey V. Akimov
*
* This file is distributed under the terms of the GNU General Public License
* as published by the Free Software Foundation, either version 2 of
* the License, or (at your option) any later version.
* See the file LICENSE in the root directory of this distribution
* or <http://www.gnu.org/licenses/>.
*
*********************************************************************************/
/**
  \file dyn_hop_proposal.h
  \brief The header for dyn_hop_proposal.cpp
    
*/

#ifndef DYN_HOP_PROPOSAL_H
#define DYN_HOP_PROPOSAL_H

// External dependencies
#include "../math_linalg/liblinalg.h"
#include "../hamiltonian/libhamiltonian.h"
#include "../io/libio.h"
#include "dyn_control_params.h"


/// liblibra namespace
namespace liblibra{

using namespace libio;
using namespace libhamiltonian;
namespace bp = boost::python;

/// libdyn namespace
namespace libdyn{

MATRIX hopping_probabilities_fssh(dyn_control_params& prms, CMATRIX& Coeff, CMATRIX& Hvib);
MATRIX hopping_probabilities_gfsh(dyn_control_params& prms, CMATRIX& Coeff, CMATRIX& Hvib);
MATRIX hopping_probabilities_mssh(dyn_control_params& prms, CMATRIX& Coeff, CMATRIX& Hvib);

vector<MATRIX> hop_proposal_probabilities(dyn_control_params& prms,
       MATRIX& q, MATRIX& p, MATRIX& invM, CMATRIX& C, vector<CMATRIX>& projectors,
       nHamiltonian& ham, vector<MATRIX>& prev_ham_dia);

int hop(vector<double>& prob, double ksi);
int hop(int initstate, MATRIX& g, double ksi);
vector<int> propose_hops(vector<MATRIX>& g, vector<int>& act_states, Random& rnd);




}// namespace libdyn
}// liblibra

#endif // DYN_HOP_PROPOSAL_H

