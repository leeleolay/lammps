/* -*- c++ -*- ----------------------------------------------------------
   LAMMPS - Large-scale Atomic/Molecular Massively Parallel Simulator
   https://www.lammps.org/ Sandia National Laboratories
   LAMMPS development team: developers@lammps.org

   Copyright (2003) Sandia Corporation.  Under the terms of Contract
   DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
   certain rights in this software.  This software is distributed under
   the GNU General Public License.

   See the README file in the top-level LAMMPS directory.
------------------------------------------------------------------------- */

#ifdef PAIR_CLASS
// clang-format off
PairStyle(dpd/ext,PairDPDExt);
// clang-format on
#else

#ifndef LMP_PAIR_DPD_EXT_H
#define LMP_PAIR_DPD_EXT_H

#include "pair.h"

namespace LAMMPS_NS {

class PairDPDExt : public Pair {
 public:
  PairDPDExt(class LAMMPS *);
  ~PairDPDExt() override;
  void compute(int, int) override;
  void settings(int, char **) override;
  void coeff(int, char **) override;
  void init_style() override;
  double init_one(int, int) override;
  void write_restart(FILE *) override;
  void read_restart(FILE *) override;
  void write_restart_settings(FILE *) override;
  void read_restart_settings(FILE *) override;
  void write_data(FILE *) override;
  void write_data_all(FILE *) override;
  double single(int, int, int, int, double, double, double, double &) override;

 protected:
  double cut_global, temperature;
  int seed;
  double **cut;
  double **a0, **gamma, **gammaT;
  double **sigma, **sigmaT;
  double **ws, **wsT;
  class RanMars *random;
  virtual void allocate();
};

}    // namespace LAMMPS_NS

#endif
#endif
