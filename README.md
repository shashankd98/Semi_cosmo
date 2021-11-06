This work studies the cosmological evolution of baryonic gas in an idealized isolated halo. 

Authors: Shashank Dattathri (shashank.dattathri@gmail.com) and Prateek Sharma (prateek@iisc.ac.in). 

Some of the codes used to generate the figures from the paper are uploaded here. The full data will be shared on reasonable request to the authors. 

Description of codes:
/Codes/DK14_density_potential.py : creates the density-potential pair for a DK14 density profile. 
/Codes/mass_accretion_histories.py : creates the mass accretion history profiles for the dark matter halos. 
/Codes/plane.py : plots the fundamental plane

PLUTO files:
/PLUTO/Non_rad : Non-radiative run for M_0 = 10^{14} M_\odot
/PLUTO/Cooling_flow : Cooling flow run for M_0 = 10^{14} M_\odot
/PLUTO/AGN_feedback : AGN feedback run for M_0=10^{14} M_\odot, \epsilon = 10^{-4}

Data analysis (pyPLUTO) files: 
/Analysis/coolcores.py : plots the time-averaged density and standard deviation for the AGN feedback run. 
/Analysis/evolution.py : calculates the baryon fraction
/Analysis/snapshots.py : plots snapshots for the 2D runs
/Analysis/visualize.py : plots relavent quantitites (density, pressure, velocity, temperature, t_cool/t_ff, Mdot) for 1D runs
/Analysis/visualize2d.py : plots relavent quantitites (density, pressure, velocity, temperature, t_cool/t_ff, Mdot) for 2D runs
