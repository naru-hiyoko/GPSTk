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

#ifndef GPSTK_SP3_SATID_HPP
#define GPSTK_SP3_SATID_HPP

#include <iostream>
#include <sstream>
#include <iomanip>

#include "Exception.hpp"
#include "SatID.hpp"

/**
 * @file SP3SatID.hpp
 * gpstk::SP3SatID - navigation system-independent representation of a satellite
 * as defined by the SP3 specification.
 */

namespace gpstk
{
      /// @todo determine if this really belongs with the SP3 files

      /// @ingroup FileHandling
      //@{

   class SP3SatID : public SatID
   {
   public:

         /// empty constructor, creates an invalid object
      SP3SatID() = default;

         /// explicit constructor, no defaults, SP3 systems only
      SP3SatID(int p, SatelliteSystem s) throw();

         /** constructor from string
          * @throw Exception
          */
      SP3SatID(const std::string& str)
      {
         try { fromString(str); }
         catch(Exception& e) { GPSTK_RETHROW(e); }
      }

         /// cast SatID to SP3SatID
      SP3SatID(const SatID& sat) throw()
            : SatID(sat)
      { validate(); }

         /// set the fill character used in output
         /// return the current fill character
      char setfill(char c) throw()
      { char csave=fillchar; fillchar=c; return csave; }

         /// get the fill character used in output
      char getfill() throw()
      { return fillchar; }

         // operator=, copy constructor and destructor built by compiler

         /// operator == for SP3SatID
      bool operator==(const SP3SatID& right) const
      {
         return ((system == right.system) && (id == right.id));
      }

         /// operator != for SP3SatID
      bool operator!=(const SP3SatID& right) const
      {
         return !(operator==(right));
      }

         /// operator < (less than) for SP3SatID : order by system, then number
      bool operator<(const SP3SatID& right) const
      {
         if(system==right.system)
            return (id < right.id);
         return (system < right.system);
      }

         /// operator > (greater than) for SP3SatID
      bool operator>(const SP3SatID& right) const
      {
         return (!operator<(right) && !operator==(right));
      }

         /// operator >= (greater than or equal) for SP3SatID
      bool operator>=(const SP3SatID& right) const
      {
         return (!operator<(right));
      }

         /// operator <= (less than or equal) for SP3SatID
      bool operator<=(const SP3SatID& right) const
      {
         return (!operator>(right));
      }

         /// return a character based on the system
         /// return the single-character system descriptor
         /// @note return only SP3 types, for non-SP3 systems return '?'
      char systemChar() const throw();

      std::string systemString() const throw();

         /** read from string
          * @note GPS is default system (no or unknown system char)
          * @throw Exception
          */
      void fromString(const std::string s);

         /// convert to string
      std::string toString() const throw();

   private:
         /// If an unsupported system is used, set to unknown and PRN -1.
      void validate();

      static char fillchar;  ///< fill character used during stream output

   }; // class SP3SatID

      /// stream output for SP3SatID
   inline std::ostream& operator<<(std::ostream& s, const SP3SatID& sat)
   {
      s << sat.toString();
      return s;
   }

      //@}

} // namespace gpstk

#endif
