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
/**
 * @file OrbElem.cpp
 * OrbElem data encapsulated in engineering terms
 */

#include "OrbElem.hpp"
#include "StringUtils.hpp"
#include "CGCS2000Ellipsoid.hpp"
#include "EllipsoidModel.hpp"
#include "GPSEllipsoid.hpp"
#include "YDSTime.hpp"
#include "CivilTime.hpp"
#include "TimeSystem.hpp"
#include "TimeString.hpp"
#include "MathBase.hpp"


namespace gpstk
{
   using namespace std;
   using namespace gpstk;
   OrbElem::OrbElem()
         : Cuc(0.0), Cus(0.0), Crc(0.0), Crs(0.0), Cic(0.0), Cis(0.0), M0(0.0),
           dn(0.0), dndot(0.0), ecc(0.0), A(0.0), Adot(0.0), OMEGA0(0.0),
           i0(0.0), w(0.0), OMEGAdot(0.0), idot(0.0), af0(0.0), af1(0.0),
           af2(0.0), ctToc(CommonTime::BEGINNING_OF_TIME)
   {
      ctToc.setTimeSystem(TimeSystem::GPS);
      beginValid.setTimeSystem(TimeSystem::GPS);
      endValid.setTimeSystem(TimeSystem::GPS);
   } 

   bool OrbElem::isValid(const CommonTime& ct) const
   {
      if (!dataLoaded())
      {
         InvalidRequest exc("Required data not stored.");
         GPSTK_THROW(exc);
      }
      if (ct >= beginValid && ct <= endValid) return(true);
      return(false);
   }


   bool OrbElem::isSameData(const OrbElem* right) const
   {
      if (!OrbElemBase::isSameData(right))   return false;
      if (Cuc            != right->Cuc)      return false;
      if (Cus            != right->Cus)      return false;
      if (Crc            != right->Crc)      return false;
      if (Crs            != right->Crs)      return false;
      if (Cic            != right->Cic)      return false;
      if (Cis            != right->Cis)      return false;
      if (M0             != right->M0)       return false;
      if (dn             != right->dn)       return false;
      if (dndot          != right->dndot)    return false;
      if (ecc            != right->ecc)      return false;
      if (A              != right->A)        return false;
      if (Adot           != right->Adot)     return false;
      if (OMEGA0         != right->OMEGA0)   return false;
      if (i0             != right->i0)       return false;
      if (w              != right->w)        return false;
      if (OMEGAdot       != right->OMEGAdot) return false;
      if (idot           != right->idot)     return false;
      if (ctToc          != right->ctToc)    return false;
      if (af0            != right->af0)      return false;
      if (af1            != right->af1)      return false;
      if (af2            != right->af2)      return false;
      return true;
   }

   std::list<std::string> OrbElem::compare(const OrbElem* right) const
   {
      std::list<std::string> retList = OrbElemBase::compare(right);
      if (Cuc            != right->Cuc)      retList.push_back("Cuc");
      if (Cus            != right->Cus)      retList.push_back("Cus");
      if (Crc            != right->Crc)      retList.push_back("Crc");
      if (Crs            != right->Crs)      retList.push_back("Crs");
      if (Cic            != right->Cic)      retList.push_back("Cic");
      if (Cis            != right->Cis)      retList.push_back("Cis");
      if (M0             != right->M0)       retList.push_back("M0");
      if (dn             != right->dn)       retList.push_back("dn");
      if (dndot          != right->dndot)    retList.push_back("dndot");
      if (ecc            != right->ecc)      retList.push_back("ecc");
      if (A              != right->A)        retList.push_back("A");
      if (Adot           != right->Adot)     retList.push_back("Adot");
      if (OMEGA0         != right->OMEGA0)   retList.push_back("OMEGA0");
      if (i0             != right->i0)       retList.push_back("i0");
      if (w              != right->w)        retList.push_back("w");
      if (OMEGAdot       != right->OMEGAdot) retList.push_back("OMEGAdot");
      if (idot           != right->idot)     retList.push_back("idot");
      if (ctToc          != right->ctToc)    retList.push_back("ctToc");
      if (af0            != right->af0)      retList.push_back("af0");
      if (af1            != right->af1)      retList.push_back("af1");
      if (af2            != right->af2)      retList.push_back("af2");
      return retList;
   }

   double OrbElem::svClockBias(const CommonTime& t) const
   {
      if (!dataLoaded())
      {
         InvalidRequest exc("Required data not stored.");
         GPSTK_THROW(exc);
      }
      double dtc,elaptc;
      elaptc = t - ctToc;
      dtc = af0 + elaptc * ( af1 + elaptc * af2 );
      return dtc;
   }

   double OrbElem::svClockBiasM(const CommonTime& t) const
   {
      if (!dataLoaded())
      {
         InvalidRequest exc("Required data not stored.");
         GPSTK_THROW(exc);
      }
      double ret = svClockBias(t);
      ret = ret*C_MPS;
      return (ret);
   }

   double OrbElem::svClockDrift(const CommonTime& t) const
   {
      if (!dataLoaded())
      {
         InvalidRequest exc("Required data not stored.");
         GPSTK_THROW(exc);
      }
      double drift,elaptc;
      elaptc = t - ctToc;
      drift = af1 + elaptc * af2;
      return drift;
   }

      // Implements equations of motion as defined in IS-GPS-200.
      // This code has its origins in 1980's FORTRAN code that has
      // been ported to C, then C++, then became part of the toolkit.
      // The original code was based on IS-GPS-200 Table 20-IV.
      // In July 2013, the code was modified to conform to Table 30-II
      // which includes additional time-dependent terms (A(dot) 
      // and delta n(dot)) that are in CNAV but not in LNAV.  These
      // changes should be backward compatible with LNAV as long as the 
      // Adot and dndot variables are appropriately set to 0.0 by the 
      // LNAV loaders. 
   Xvt OrbElem::svXvt(const CommonTime& t) const
   {
      if (!dataLoaded())
      {
         InvalidRequest exc("Required data not stored.");
         GPSTK_THROW(exc);
      }
      Xvt sv;

      GPSWeekSecond gpsws = (ctToe);
      double ToeSOW = gpsws.sow;
      double ea;              // eccentric anomaly //
      double delea;           // delta eccentric anomaly during iteration */
      double elapte;          // elapsed time since Toe
         //double elaptc;          // elapsed time since Toc
      double q,sinea,cosea;
      double GSTA,GCTA;
      double amm;
      double meana;           // mean anomaly
      double F,G;             // temporary real variables
      double alat,talat,c2al,s2al,du,dr,di,U,R,truea,AINC;
      double ANLON,cosu,sinu,xip,yip,can,san,cinc,sinc;
      double xef,yef,zef,dek,dlk,div,domk,duv,drv;
      double dxp,dyp,vxef,vyef,vzef;

         // Several GNSSs use this algorithm.  In some cases the physical
         // constants need to be different.
      EllipsoidModel *ell;
      if (satID.system==SatelliteSystem::BeiDou)
         ell = new CGCS2000Ellipsoid();
      else
         ell = new GPSEllipsoid();

         // Compute time since ephemeris & clock epochs
      elapte = t - ctToe;
      double sqrtgm = SQRT(ell->gm());

         // Compute A at time of interest
      double Ak = A + Adot * elapte;

      double twoPI = 2.0e0 * PI;
      double lecc;               // eccentricity
      double tdrinc;            // dt inclination

      lecc = ecc;
      tdrinc = idot;

         // Compute mean motion
      double dnA = dn + 0.5 * dndot * elapte;
      double Ahalf = SQRT(A); 
      amm  = (sqrtgm / (A*Ahalf)) + dnA;  // NOT Ak because this equation
                                          // specifies A0, not Ak.  

         // In-plane angles
         //     meana - Mean anomaly
         //     ea    - Eccentric anomaly
         //     truea - True anomaly

      meana = M0 + elapte * amm;
      meana = fmod(meana, twoPI);

      ea = meana + lecc * ::sin(meana);

      int loop_cnt = 1;
      do  {
         F = meana - ( ea - lecc * ::sin(ea));
         G = 1.0 - lecc * ::cos(ea);
         delea = F/G;
         ea = ea + delea;
         loop_cnt++;
      } while ( (fabs(delea) > 1.0e-11 ) && (loop_cnt <= 20) );

         // Compute clock corrections
      sv.relcorr = svRelativity(t);
      sv.clkbias = svClockBias(t);
      sv.clkdrift = svClockDrift(t);
         // This appear to be only a string for naming
      sv.frame = ReferenceFrame::WGS84;

         // Compute true anomaly
      q     = SQRT( 1.0e0 - lecc*lecc);
      sinea = ::sin(ea);
      cosea = ::cos(ea);
      G     = 1.0e0 - lecc * cosea;

         //  G*SIN(TA) AND G*COS(TA)
      GSTA  = q * sinea;
      GCTA  = cosea - lecc;

         //  True anomaly
      truea = atan2 ( GSTA, GCTA );

         // Argument of lat and correction terms (2nd harmonic)
      alat  = truea + w;
      talat = 2.0e0 * alat;
      c2al  = ::cos( talat );
      s2al  = ::sin( talat );

      du  = c2al * Cuc +  s2al * Cus;
      dr  = c2al * Crc +  s2al * Crs;
      di  = c2al * Cic +  s2al * Cis;

         // U = updated argument of lat, R = radius, AINC = inclination
      U    = alat + du;
      R    = Ak*G  + dr;
      AINC = i0 + tdrinc * elapte  +  di;

         //  Longitude of ascending node (ANLON)
      ANLON = OMEGA0 + (OMEGAdot - ell->angVelocity()) *
         elapte - ell->angVelocity() * ToeSOW;

         // In plane location
      cosu = ::cos( U );
      sinu = ::sin( U );

      xip  = R * cosu;
      yip  = R * sinu;

         //  Angles for rotation to earth fixed
      can  = ::cos( ANLON );
      san  = ::sin( ANLON );
      cinc = ::cos( AINC  );
      sinc = ::sin( AINC  );

         // Earth fixed - meters
      xef  =  xip*can  -  yip*cinc*san;
      yef  =  xip*san  +  yip*cinc*can;
      zef  =              yip*sinc;

      sv.x[0] = xef;
      sv.x[1] = yef;
      sv.x[2] = zef;

         // Compute velocity of rotation coordinates
      dek = amm / G;
      dlk = amm * q / (G*G);
      div = tdrinc - 2.0e0 * dlk *
         ( Cic  * s2al - Cis * c2al );
      domk = OMEGAdot - ell->angVelocity();
      duv = dlk*(1.e0+ 2.e0 * (Cus*c2al - Cuc*s2al) );
      drv = Ak * lecc * dek * sinea - 2.e0 * dlk *
         ( Crc * s2al - Crs * c2al ) + Adot * G;

      dxp = drv*cosu - R*sinu*duv;
      dyp = drv*sinu + R*cosu*duv;

         // Calculate velocities
      vxef = dxp*can - xip*san*domk - dyp*cinc*san
         + yip*( sinc*san*div - cinc*can*domk);
      vyef = dxp*san + xip*can*domk + dyp*cinc*can
         - yip*( sinc*can*div + cinc*san*domk);
      vzef = dyp*sinc + yip*cinc*div;

         // Move results into output variables
      sv.v[0] = vxef;
      sv.v[1] = vyef;
      sv.v[2] = vzef;
      sv.health = isHealthy() ? Xvt::Healthy : Xvt::Unhealthy;
      delete ell;

      return sv;
   }

   double OrbElem::svRelativity(const CommonTime& t) const
   {
      if (!dataLoaded())
      {
         InvalidRequest exc("Required data not stored.");
         GPSTK_THROW(exc);
      }

         // Several GNSSs use this algorithm.  In some cases the physical
         // constants need to be different.
      EllipsoidModel *ell;
      if (satID.system==SatelliteSystem::BeiDou)
         ell = new CGCS2000Ellipsoid();
      else
         ell = new GPSEllipsoid();

      double twoPI  = 2.0e0 * PI;
      double sqrtgm = SQRT(ell->gm());
      delete ell;
      double elapte = t - ctToe;

         // Compute A at time of interest
      double Ak = A + Adot * elapte;   
      
      double dnA = dn + 0.5 * dndot * elapte;
      double Ahalf = SQRT(A);
      double amm    = (sqrtgm / (A*Ahalf)) + dnA;// NOT Ak because this equation
                                                 // specifies A0, not Ak.  
      double meana,F,G,delea;

      meana = M0 + elapte * amm;
      meana = fmod(meana, twoPI);
      double ea = meana + ecc * ::sin(meana);

      int loop_cnt = 1;
      do {
         F     = meana - ( ea - ecc * ::sin(ea));
         G     = 1.0 - ecc * ::cos(ea);
         delea = F/G;
         ea    = ea + delea;
         loop_cnt++;
      } while ( (ABS(delea) > 1.0e-11 ) && (loop_cnt <= 20) );
      
         // Use Ak as we are interested in semi-major axis at this moment.
      double dtr = REL_CONST * ecc * SQRT(Ak) * ::sin(ea); 
      return dtr;
   }

   void OrbElem::shortcut(ostream & os, const long HOW )
   {
      short DOW, hour, min, sec;
      long SOD, SOW;
      short SOH;

      SOW = static_cast<long>( HOW );
      DOW = static_cast<short>( SOW / SEC_PER_DAY );
      SOD = SOW - static_cast<long>( DOW * SEC_PER_DAY );
      hour = static_cast<short>( SOD/3600 );

      SOH = static_cast<short>( SOD - (hour*3600) );
      min = SOH/60;

      sec = SOH - min * 60;
      switch (DOW)
      {
         case 0: os << "Sun-0"; break;
         case 1: os << "Mon-1"; break;
         case 2: os << "Tue-2"; break;
         case 3: os << "Wed-3"; break;
         case 4: os << "Thu-4"; break;
         case 5: os << "Fri-5"; break;
         case 6: os << "Sat-6"; break;
         default: break;
      }

      os << ":" << setfill('0')
         << setw(2) << hour
         << ":" << setw(2) << min
         << ":" << setw(2) << sec
         << setfill(' ');
   }


   void OrbElem::timeDisplay( ostream & os, const CommonTime& t )
   {
      os.setf(ios::dec, ios::basefield);
         // Convert to CommonTime struct from GPS wk,SOW to M/D/Y, H:M:S.
      GPSWeekSecond dummyTime;
      dummyTime = GPSWeekSecond(t);
      os << setw(4) << dummyTime.week << "(";
      os << setw(4) << (dummyTime.week & 0x03FF) << ")  ";
      os << setw(6) << setfill(' ') << dummyTime.sow << "   ";

      switch (dummyTime.getDayOfWeek())
      {
         case 0: os << "Sun-0"; break;
         case 1: os << "Mon-1"; break;
         case 2: os << "Tue-2"; break;
         case 3: os << "Wed-3"; break;
         case 4: os << "Thu-4"; break;
         case 5: os << "Fri-5"; break;
         case 6: os << "Sat-6"; break;
         default: break;
      }
      os << printTime(t,"   %3j   %5.0s   %02m/%02d/%04Y   %02H:%02M:%02S");
   }

   void OrbElem::dumpBody(ostream& s) const
   {
      if (!dataLoaded())
      {
         InvalidRequest exc("Required data not stored.");
         GPSTK_THROW(exc);
      }
      const ios::fmtflags oldFlags = s.flags();
      size_t precision = 8; 

      s.setf(ios::fixed, ios::floatfield);
      s.setf(ios::right, ios::adjustfield);
      s.setf(ios::uppercase);
      s.precision(0);
      s.fill(' ');

      s << endl;
      s << "           TIMES OF INTEREST"
        << endl << endl;
      s << "              Week(10bt)     SOW     DOW   UTD     SOD"
        << "   MM/DD/YYYY   HH:MM:SS\n";
      s << "Begin Valid:  ";
      timeDisplay(s, beginValid);
      s << endl;
      s << "Clock Epoch:  ";
      timeDisplay(s, ctToc);
      s << endl;
      s << "Eph Epoch:    ";
      timeDisplay(s, ctToe);
      s << endl;
      s << "End Valid:    ";
      timeDisplay(s, endValid);

      s.setf(ios::scientific, ios::floatfield);
      s.precision(precision);
      s.fill(' ');
      unsigned fw = precision + 8;

      s << endl
        << endl
        << "           CLOCK PARAMETERS"
        << endl
        << endl
        << "Bias T0:     " << setw(fw) << af0 << " sec" << endl
        << "Drift:       " << setw(fw) << af1 << " sec/sec" << endl
        << "Drift rate:  " << setw(fw) << af2 << " sec/(sec**2)" << endl;

      s << endl
        << "           ORBIT PARAMETERS"
        << endl
        << endl
        << "Semi-major axis:       " << setw(fw) <<  A     << " m       "
        << setw(fw) << Adot  << "   m/sec" << endl
        << "Motion correction:     " << setw(fw) <<  dn    << " rad/sec "
        << setw(fw) << dndot << " rad/(sec**2)" << endl
        << "Eccentricity:          " << setw(fw) << ecc << endl
        << "Arg of perigee:        " << setw(fw) << w << " rad" << endl
        << "Mean anomaly at epoch: " << setw(fw) << M0 << " rad" << endl
        << "Right ascension:       " << setw(fw) << OMEGA0 << " rad     "
        << setw(fw) << OMEGAdot << " rad/sec" << endl
        << "Inclination:           " << setw(fw) << i0     << " rad     "
        << setw(fw) << idot << " rad/sec" << endl;

      s << endl
        << "           HARMONIC CORRECTIONS"
        << endl
        << endl
        << "Radial        Sine: " << setw(fw) << Crs << " m    Cosine: "
        << setw(fw) << Crc << " m" << endl
        << "Inclination   Sine: " << setw(fw) << Cis << " rad  Cosine: "
        << setw(fw) << Cic << " rad" << endl
        << "In-track      Sine: " << setw(fw) << Cus << " rad  Cosine: "
        << setw(fw) << Cuc << " rad" << endl;

      s.flags(oldFlags);
   } // end of dumpBody()

   void OrbElem::dumpHeader(ostream& s) const
   {
      s << "****************************************************************"
        << "************" << endl
        << "Broadcast Ephemeris (Engineering Units) - " << getNameLong();
      s << endl;

      s << endl;
      s << "PRN : " << setw(2) << satID.id << " / "
        << "SVN : " << setw(2);
      std::string svn;
      if (getSVN(satID, ctToe, svn))
      {
         s << svn;
      }
      s << "  " << endl
        << endl;
   }

   void OrbElem::dumpFooter(ostream& s) const
   {}

   void OrbElem::dump(ostream& s) const
   {
      dumpHeader(s);
      dumpBody(s);
      dumpFooter(s);
   }

} // namespace
