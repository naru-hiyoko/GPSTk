//==============================================================================
//
//  This file is part of GPSTk, the GPS Toolkit.
//
//  The GPSTk is free software; you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as published
//  by the Free Software Foundation; either version 3.0 of the License, or
//  any later version.
//
//  The GPSTk is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with GPSTk; if not, write to the Free Software Foundation,
//  Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
//  
//  This software was developed by Applied Research Laboratories at the
//  University of Texas at Austin.
//  Copyright 2004-2020, The Board of Regents of The University of Texas System
//
//==============================================================================

//==============================================================================
//
//  This software was developed by Applied Research Laboratories at the
//  University of Texas at Austin, under contract to an agency or agencies
//  within the U.S. Department of Defense. The U.S. Government retains all
//  rights to use, duplicate, distribute, disclose, or release this software.
//
//  Pursuant to DoD Directive 523024 
//
//  DISTRIBUTION STATEMENT A: This software has been approved for public 
//                            release, distribution is unlimited.
//
//==============================================================================

      //-----------------------------------------------------------------------
      // Code to implement Table 8.1 of IERS Conventions 1996 series for
      // Zonal Tide terms for UT1R, length of the day and omega(Earth).
      // Units for UT1R, length of the day and omega(Earth) are:
      //        seconds,    seconds        and radians/sec.
      // (Generated by perl script Table81.pl)
      double arg;
      UT1mUT1R = dlodR = domegaR = 0.0;
   
      // line 1 of Table 8.1, period = 5.64 days
      arg = l+2*f+2*d+2*o;
      UT1mUT1R -= 0.02e-4 * ::sin(arg);
      dlodR += 0.3e-5 * ::cos(arg);
      domegaR -= 0.2e-14 * ::cos(arg);
      // line 2 of Table 8.1, period = 6.85 days
      arg = 2*l+2*f+o;
      UT1mUT1R -= 0.04e-4 * ::sin(arg);
      dlodR += 0.4e-5 * ::cos(arg);
      domegaR -= 0.3e-14 * ::cos(arg);
      // line 3 of Table 8.1, period = 6.86 days
      arg = 2*l+2*f+2*o;
      UT1mUT1R -= 0.10e-4 * ::sin(arg);
      dlodR += 0.9e-5 * ::cos(arg);
      domegaR -= 0.8e-14 * ::cos(arg);
      // line 4 of Table 8.1, period = 7.09 days
      arg = 2*f+2*d+o;
      UT1mUT1R -= 0.05e-4 * ::sin(arg);
      dlodR += 0.4e-5 * ::cos(arg);
      domegaR -= 0.4e-14 * ::cos(arg);
      // line 5 of Table 8.1, period = 7.10 days
      arg = 2*f+2*d+2*o;
      UT1mUT1R -= 0.12e-4 * ::sin(arg);
      dlodR += 1.1e-5 * ::cos(arg);
      domegaR -= 0.9e-14 * ::cos(arg);
      // line 6 of Table 8.1, period = 9.11 days
      arg = l+2*f;
      UT1mUT1R -= 0.04e-4 * ::sin(arg);
      dlodR += 0.3e-5 * ::cos(arg);
      domegaR -= 0.2e-14 * ::cos(arg);
      // line 7 of Table 8.1, period = 9.12 days
      arg = l+2*f+o;
      UT1mUT1R -= 0.41e-4 * ::sin(arg);
      dlodR += 2.8e-5 * ::cos(arg);
      domegaR -= 2.4e-14 * ::cos(arg);
      // line 8 of Table 8.1, period = 9.13 days
      arg = l+2*f+2*o;
      UT1mUT1R -= 0.99e-4 * ::sin(arg);
      dlodR += 6.8e-5 * ::cos(arg);
      domegaR -= 5.8e-14 * ::cos(arg);
      // line 9 of Table 8.1, period = 9.18 days
      arg = 3*l;
      UT1mUT1R -= 0.02e-4 * ::sin(arg);
      dlodR += 0.1e-5 * ::cos(arg);
      domegaR -= 0.1e-14 * ::cos(arg);
      // line 10 of Table 8.1, period = 9.54 days
      arg = -l+2*f+2*d+o;
      UT1mUT1R -= 0.08e-4 * ::sin(arg);
      dlodR += 0.5e-5 * ::cos(arg);
      domegaR -= 0.5e-14 * ::cos(arg);
      // line 11 of Table 8.1, period = 9.56 days
      arg = -l+2*f+2*d+2*o;
      UT1mUT1R -= 0.20e-4 * ::sin(arg);
      dlodR += 1.3e-5 * ::cos(arg);
      domegaR -= 1.1e-14 * ::cos(arg);
      // line 12 of Table 8.1, period = 9.61 days
      arg = l+2*d;
      UT1mUT1R -= 0.08e-4 * ::sin(arg);
      dlodR += 0.5e-5 * ::cos(arg);
      domegaR -= 0.4e-14 * ::cos(arg);
      // line 13 of Table 8.1, period = 12.81 days
      arg = 2*l+2*f-2*d+2*o;
      UT1mUT1R += 0.02e-4 * ::sin(arg);
      dlodR -= 0.1e-5 * ::cos(arg);
      domegaR += 0.1e-14 * ::cos(arg);
      // line 14 of Table 8.1, period = 13.17 days
      arg = lp+2*f+2*o;
      UT1mUT1R += 0.03e-4 * ::sin(arg);
      dlodR -= 0.1e-5 * ::cos(arg);
      domegaR += 0.1e-14 * ::cos(arg);
      // line 15 of Table 8.1, period = 13.61 days
      arg = 2*f;
      UT1mUT1R -= 0.30e-4 * ::sin(arg);
      dlodR += 1.4e-5 * ::cos(arg);
      domegaR -= 1.2e-14 * ::cos(arg);
      // line 16 of Table 8.1, period = 13.63 days
      arg = 2*f+o;
      UT1mUT1R -= 3.21e-4 * ::sin(arg);
      dlodR += 14.8e-5 * ::cos(arg);
      domegaR -= 12.5e-14 * ::cos(arg);
      // line 17 of Table 8.1, period = 13.66 days
      arg = 2*f+2*o;
      UT1mUT1R -= 7.76e-4 * ::sin(arg);
      dlodR += 35.7e-5 * ::cos(arg);
      domegaR -= 30.1e-14 * ::cos(arg);
      // line 18 of Table 8.1, period = 13.75 days
      arg = 2*l-o;
      UT1mUT1R += 0.02e-4 * ::sin(arg);
      dlodR -= 0.1e-5 * ::cos(arg);
      domegaR += 0.1e-14 * ::cos(arg);
      // line 19 of Table 8.1, period = 13.78 days
      arg = 2*l;
      UT1mUT1R -= 0.34e-4 * ::sin(arg);
      dlodR += 1.5e-5 * ::cos(arg);
      domegaR -= 1.3e-14 * ::cos(arg);
      // line 20 of Table 8.1, period = 13.81 days
      arg = 2*l+o;
      UT1mUT1R += 0.02e-4 * ::sin(arg);
      dlodR -= 0.1e-5 * ::cos(arg);
      domegaR += 0.1e-14 * ::cos(arg);
      // line 21 of Table 8.1, period = 14.19 days
      arg = -lp+2*f+2*o;
      UT1mUT1R -= 0.02e-4 * ::sin(arg);
      dlodR += 0.1e-5 * ::cos(arg);
      domegaR -= 0.1e-14 * ::cos(arg);
      // line 22 of Table 8.1, period = 14.73 days
      arg = 2*d-o;
      UT1mUT1R += 0.05e-4 * ::sin(arg);
      dlodR -= 0.2e-5 * ::cos(arg);
      domegaR += 0.2e-14 * ::cos(arg);
      // line 23 of Table 8.1, period = 14.77 days
      arg = 2*d;
      UT1mUT1R -= 0.73e-4 * ::sin(arg);
      dlodR += 3.1e-5 * ::cos(arg);
      domegaR -= 2.6e-14 * ::cos(arg);
      // line 24 of Table 8.1, period = 14.80 days
      arg = 2*d+o;
      UT1mUT1R -= 0.05e-4 * ::sin(arg);
      dlodR += 0.2e-5 * ::cos(arg);
      domegaR -= 0.2e-14 * ::cos(arg);
      // line 25 of Table 8.1, period = 15.39 days
      arg = -lp+2*d;
      UT1mUT1R -= 0.05e-4 * ::sin(arg);
      dlodR += 0.2e-5 * ::cos(arg);
      domegaR -= 0.2e-14 * ::cos(arg);
      // line 26 of Table 8.1, period = 23.86 days
      arg = l+2*f-2*d+o;
      UT1mUT1R += 0.05e-4 * ::sin(arg);
      dlodR -= 0.1e-5 * ::cos(arg);
      domegaR += 0.1e-14 * ::cos(arg);
      // line 27 of Table 8.1, period = 23.94 days
      arg = l+2*f-2*d+2*o;
      UT1mUT1R += 0.10e-4 * ::sin(arg);
      dlodR -= 0.3e-5 * ::cos(arg);
      domegaR += 0.2e-14 * ::cos(arg);
      // line 28 of Table 8.1, period = 25.62 days
      arg = l+lp;
      UT1mUT1R += 0.04e-4 * ::sin(arg);
      dlodR -= 0.1e-5 * ::cos(arg);
      domegaR += 0.1e-14 * ::cos(arg);
      // line 29 of Table 8.1, period = 26.88 days
      arg = -l+2*f;
      UT1mUT1R += 0.05e-4 * ::sin(arg);
      dlodR -= 0.1e-5 * ::cos(arg);
      domegaR += 0.1e-14 * ::cos(arg);
      // line 30 of Table 8.1, period = 26.98 days
      arg = -l+2*f+o;
      UT1mUT1R += 0.18e-4 * ::sin(arg);
      dlodR -= 0.4e-5 * ::cos(arg);
      domegaR += 0.3e-14 * ::cos(arg);
      // line 31 of Table 8.1, period = 27.09 days
      arg = -l+2*f+2*o;
      UT1mUT1R += 0.44e-4 * ::sin(arg);
      dlodR -= 1.0e-5 * ::cos(arg);
      domegaR += 0.9e-14 * ::cos(arg);
      // line 32 of Table 8.1, period = 27.44 days
      arg = l-o;
      UT1mUT1R += 0.53e-4 * ::sin(arg);
      dlodR -= 1.2e-5 * ::cos(arg);
      domegaR += 1.0e-14 * ::cos(arg);
      // line 33 of Table 8.1, period = 27.56 days
      arg = l;
      UT1mUT1R -= 8.26e-4 * ::sin(arg);
      dlodR += 18.8e-5 * ::cos(arg);
      domegaR -= 15.9e-14 * ::cos(arg);
      // line 34 of Table 8.1, period = 27.67 days
      arg = l+o;
      UT1mUT1R += 0.54e-4 * ::sin(arg);
      dlodR -= 1.2e-5 * ::cos(arg);
      domegaR += 1.0e-14 * ::cos(arg);
      // line 35 of Table 8.1, period = 29.53 days
      arg = d;
      UT1mUT1R += 0.05e-4 * ::sin(arg);
      dlodR -= 0.1e-5 * ::cos(arg);
      domegaR += 0.1e-14 * ::cos(arg);
      // line 36 of Table 8.1, period = 29.80 days
      arg = l-lp;
      UT1mUT1R -= 0.06e-4 * ::sin(arg);
      dlodR += 0.1e-5 * ::cos(arg);
      domegaR -= 0.1e-14 * ::cos(arg);
      // line 37 of Table 8.1, period = 31.66 days
      arg = -l+2*d-o;
      UT1mUT1R += 0.12e-4 * ::sin(arg);
      dlodR -= 0.2e-5 * ::cos(arg);
      domegaR += 0.2e-14 * ::cos(arg);
      // line 38 of Table 8.1, period = 31.81 days
      arg = -l+2*d;
      UT1mUT1R -= 1.82e-4 * ::sin(arg);
      dlodR += 3.6e-5 * ::cos(arg);
      domegaR -= 3.0e-14 * ::cos(arg);
      // line 39 of Table 8.1, period = 31.96 days
      arg = -l+2*d+o;
      UT1mUT1R += 0.13e-4 * ::sin(arg);
      dlodR -= 0.3e-5 * ::cos(arg);
      domegaR += 0.2e-14 * ::cos(arg);
      // line 40 of Table 8.1, period = 32.61 days
      arg = l-2*f+2*d-o;
      UT1mUT1R += 0.02e-4 * ::sin(arg);
      // line 41 of Table 8.1, period = 34.85 days
      arg = -l-lp+2*d;
      UT1mUT1R -= 0.09e-4 * ::sin(arg);
      dlodR += 0.2e-5 * ::cos(arg);
      domegaR -= 0.1e-14 * ::cos(arg);
   
      //End Code implementing Table 8.1 IERS Conventions 1996 UT1R tide series.

