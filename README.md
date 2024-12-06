# Deflated Continuation of various Navier-Stokes problems.
# Supported by the Russian Science Foundation (RSF) [23-21-00107](https://rscf.ru/en/project/23-21-00107/)

This is the project for deflated continuation and building skeleton of a disconnected bifurcation diagram for a large scale nonlinear system. It is aimed to be used with a generally supplied nonlinear function $F(x, \lambda)=0$, Jacobians $F_x$ and $F_\lambda$ and, optionally, preconditioners to the nonliear system. In this particular case it targets discrete systems obtained from the Navier-Stokes equations.
##### Makefile is used to assemble targets. Configuration files for your system must be correctly provided. See make_configs/ folder for more details. Run target("ker") to build kernels for your GPUs.
Examples of the nonlinear operators include:
- Simple circular test case (targets: circle\_ker, circle\_bd).
- 1D/2D Kuramoto-Sivashinksi system on periodic domain (targets: Kuramoto\_Sivashinskiy\_2D\_ker, KS\_bd).
- 2D Kolmogorov flow problem for Navier-Stokes equations (targets: Kolmogorov\_2D\_ker, KF2D\_bd).
- 3D Kolmogorov flow problem for Navier-Stokes equations (targets: Kolmogorov\_3D\_ker, KF3D\_bd).
- 3D Kolmogorov flow problem for Navier-Stokes equations with defation of SO(2) group (targets: deflation\_translation\_Kolmogorov\_3D).
- 3D ABC flow problem for Navier-Stokes equations (targets: abc\_flow\_ker, abc\_bd).
- overscreening breakdown problem (targets: ob\_ker, ob\_ker\_var\_prec, test\_ob, ob\_json).

## The application of this software or its parts is discribed in the following papers. 
### Supported by the RSF grant 23-21-00107:
- (https://doi.org/10.1007/978-3-031-38864-4_11)
- (https://doi.org/10.3390/math11183875)
- (https://doi.org/10.3390/math11204336)
- (https://doi.org/10.3390/math12213389)
- (https://doi.org/10.14357/20790279240401)
### Supported by the RSF grant 23-21-00095:
- (https://doi.org/10.1016/j.jcis.2024.08.040)

