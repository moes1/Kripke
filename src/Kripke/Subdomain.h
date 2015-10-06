#ifndef KRIPKE_SUBDOMAIN_H__
#define KRIPKE_SUBDOMAIN_H__

#include <vector>
#include <Kripke/Layout.h>

#include <Kripke/cu_utils.h>

// Foreward Decl
struct Directions;
struct SubTVec;
struct Input_Variables;
class Kernel;

/**
 * Provides sweep index sets for a given octant.
 * This generalizes the sweep pattern, and allows for experimenting with
 * a tiled approach to on-node sweeps.
 */
struct Grid_Sweep_Block {
  int start_i, start_j, start_k; // starting index
  int end_i, end_j, end_k; // termination conditon (one past)
  int inc_i, inc_j, inc_k; // increment
//LG
  int Nhyperplanes;
  int *ii_jj_kk_z_idx;
  int *offset;
  int *d_ii_jj_kk_z_idx;
  int *d_offset;
};



/**
 * Contains parameters and variables that describe a single Group Set and
 * Direction Set.
 */
struct Subdomain {
  Subdomain();
  ~Subdomain();

  void setup(int sdom_id, Input_Variables *input_vars, int gs, int ds, int zs,
    std::vector<Directions> &direction_list, Kernel *kernel, Layout *layout);

  void setVars(SubTVec *ell_ptr, SubTVec *ell_plus_ptr,
    SubTVec *phi_ptr, SubTVec *phi_out_ptr);

  void randomizeData(void);
  void copy(Subdomain const &b);
  bool compare(Subdomain const &b, double tol, bool verbose);
  void computeSweepIndexSet(void);
  void computeLLPlus(int legendre_order);

  int idx_group_set;
  int idx_dir_set;
  int idx_zone_set;

  int num_groups;       // Number of groups in this set
  int num_directions;   // Number of directions in this set
  int num_zones;        // Number of zones in this set

  int zeros[3];                     // origin of local mesh
  int nzones[3];                    // Number of zones in each dimension
  std::vector<double> deltas[3];    // Spatial grid deltas in each dimension (including ghost zones)
//LG
#ifdef KRIPKE_USE_CUDA
  double *d_delta_x, *d_delta_y, *d_delta_z; // Spatial grid deltas in each dimension, stored as 1D array on GPU
  double *two_inv_d_delta_x, *two_inv_d_delta_y, *two_inv_d_delta_z;
#endif

  int group0;           // Starting global group id
  int direction0;       // Starting global direction id

  Grid_Sweep_Block sweep_block;

  // Neighbors
  Neighbor upwind[3];   // Upwind dependencies in x,y,z
  Neighbor downwind[3]; // Downwind neighbors in x,y,z

  // Sweep boundary data
  SubTVec *plane_data[3];

  // Variables
  SubTVec *psi;         // Solution
  SubTVec *rhs;         // RHS, source term
  SubTVec *sigt;        // Zonal per-group cross-section


  // Pointers into directions and directionset data from Grid_Data
  Directions *directions;
//LG
  SubTVec *ell;
  SubTVec *ell_plus;
  SubTVec *phi;
  SubTVec *phi_out;

//LG
#ifdef KRIPKE_USE_CUDA
  Directions *d_directions; // direction data on GPU
  double *d_sigt;       // ZOnal per-group cross-sectio, stored on GPU
  double *d_rhs;        // RHS, on GPU
  double *d_ell_plus;
  double *d_ell;
  double *d_phi_out;
  double *d_phi;

  #ifdef KRIPKE_USE_CUBLAS
    double **d_rhs_ptrs,
           **d_ell_plus_ptrs,
           **d_phi_out_ptrs;
  #endif

#endif

  // Materials on the mesh, used for scattering lookup
  std::vector<int> mixed_to_zones;     // mapping from mixed slot to zones
  std::vector<int> mixed_material;  // material number for each mixed slot
  std::vector<double> mixed_fraction;  // volume fraction each mixed slot
//LG  replace  with std::vector later on
  int *mixed_offset;  // volume fraction each mixed slot


//LG
#ifdef KRIPKE_USE_CUDA
  int *d_mixed_to_zones;
  int *d_mixed_material;
  double *d_mixed_fraction;
  int *d_mixed_offset;
#endif


};

#endif
