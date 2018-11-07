/*********************************************************************************
* Copyright (C) 2018 Alexey V. Akimov
*
* This file is distributed under the terms of the GNU General Public License
* as published by the Free Software Foundation, either version 2 of
* the License, or (at your option) any later version.
* See the file LICENSE in the root directory of this distribution
* or <http://www.gnu.org/licenses/>.
*
*********************************************************************************/

#include "SpecialFunctions.h"
#include "../math_meigen/mEigen.h"


//================== Functions ==========================

/// liblibra namespace
namespace liblibra{

/// libspecialfunctions namespace
namespace libspecialfunctions{


MATRIX mean(MATRIX& X){
/** 
  Compute the mean of the data in X:

  mean_i = <X_i> = (1/nsampl) sum_k { X_ik }

  X (ndof x nsampl)
  where ndof - the number of degrees of freedom 
        nsampl - the number of samples on ndof-dimensional data

*/

  int ndof = X.n_rows;
  int sz = X.n_cols;

  MATRIX res(ndof, 1);
  
  for(int i=0;i<ndof;i++){
    for(int t=0;t<sz;t++){
      res.M[i] += X.get(i,t);
    }
    res.M[i] /= double(sz);
  }

  return res;
}

CMATRIX mean(CMATRIX& X){
/** 
  Compute the mean of the data in X:

  mean_i = <X_i> = (1/nsampl) sum_k { X_ik }

  X (ndof x nsampl)
  where ndof - the number of degrees of freedom 
        nsampl - the number of samples on ndof-dimensional data

*/

  int ndof = X.n_rows;
  int sz = X.n_cols;

  CMATRIX res(ndof, 1);
  
  for(int i=0;i<ndof;i++){
    for(int t=0;t<sz;t++){
      res.M[i] += X.get(i,t);
    }
    res.M[i] /= double(sz);
  }

  return res;
}


MATRIX deviation(MATRIX& X){
/**
  Returns the deviation of each component from its mean value
*/

  int ndof = X.n_rows;  
  int sz = X.n_cols;

  MATRIX res(ndof, sz);
  MATRIX E(ndof, sz); // Expectation value

  E = mean(X);
  
  for(int i=0;i<ndof;i++){
    for(int t=0;t<sz;t++){
      res.set(i,t,  X.get(i,t) - E.get(i));
    }
  }

  return res;
}

CMATRIX deviation(CMATRIX& X){
/**
  Returns the deviation of each component from its mean value
*/

  int ndof = X.n_rows;  
  int sz = X.n_cols;

  CMATRIX res(ndof, sz);
  CMATRIX E(ndof, sz); // Expectation value

  E = mean(X);
  
  for(int i=0;i<ndof;i++){
    for(int t=0;t<sz;t++){
      res.set(i,t,  X.get(i,t) - E.get(i));
    }
  }

  return res;
}


MATRIX covariance(MATRIX& X){
/** 
  Compute a covariance of the data in X:

  cov_ij = <X_i * X_j> = (1/nsampl) sum_k { (X_ik-E[X_i]) * (X_jk-E[X_j]) }

  X (ndof x nsampl)
  where ndof - the number of degrees of freedom 
        nsampl - the number of samples on ndof-dimensional data

*/


  int ndof = X.n_rows;
  int sz = X.n_cols;

//  MATRIX dX(ndof, sz);
  MATRIX res(ndof, ndof);

//  dX = deviation(X);

  for(int i=0;i<ndof;i++){
    for(int j=0;j<ndof;j++){

      double tmp = 0.0;
      for(int t=0;t<sz;t++){  tmp += X.get(i,t) * X.get(j,t);  }

      res.set(i,j, tmp/double(sz) );

    }
  }

  return res;
}

CMATRIX covariance(CMATRIX& X){
/** 
  Compute a covariance of the data in X:

  cov_ij = <X_i * X_j> = (1/nsampl) sum_k { (X_ik-E[X_i]) * conj(X_jk-E[X_j]) }

  According to: https://en.wikipedia.org/wiki/Complex_random_variable

  X (ndof x nsampl)
  where ndof - the number of degrees of freedom 
        nsampl - the number of samples on ndof-dimensional data

*/


  int ndof = X.n_rows;
  int sz = X.n_cols;

//  CMATRIX dX(ndof, sz);
  CMATRIX res(ndof, ndof);

//  dX = deviation(X);

  for(int i=0;i<ndof;i++){
    for(int j=0;j<ndof;j++){

      complex<double> tmp(0.0, 0.0);
      for(int t=0;t<sz;t++){  tmp += X.get(i,t) * std::conj(X.get(j,t));  }

      res.set(i,j, tmp/double(sz) );

    }
  }

  return res;
}





}// namespace libspecialfunctions
}// namespace liblibra



