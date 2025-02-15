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

/* ----------------------------------------------------------------------
   Contributing author: Shern Tee (UQ)
------------------------------------------------------------------------- */

#ifdef FIX_CLASS

// clang-format off
FixStyle(electrode/conq/intel, FixElectrodeConqIntel)
// clang-format on

#else

#ifndef LMP_FIX_ELECTRODE_CONQ_INTEL_H
#define LMP_FIX_ELECTRODE_CONQ_INTEL_H

#include "electrode_accel_intel.h"
#include "fix_electrode_conq.h"

namespace LAMMPS_NS {

class FixElectrodeConqIntel : public FixElectrodeConq {
 public:
  FixElectrodeConqIntel(class LAMMPS *lmp, int narg, char **arg) : FixElectrodeConq(lmp, narg, arg)
  {
    intelflag = true;
    accel_interface = std::unique_ptr<ElectrodeAccelInterface>(new ElectrodeAccelIntel(lmp));
  }
};

}    // namespace LAMMPS_NS

#endif
#endif
