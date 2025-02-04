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
 * @file Rinex3NavStream.hpp
 * File stream for Rinex 3 navigation file data
 */

#ifndef RINEX3NAVSTREAM_HPP
#define RINEX3NAVSTREAM_HPP

#include "FFTextStream.hpp"
#include "Rinex3NavHeader.hpp"

namespace gpstk
{
      /// @ingroup FileHandling
      //@{

      /**
       * This class performs file i/o on a RINEX 3 NAV file.
       *
       * \sa rinex_nav_test.cpp and rinex_nav_read_write.cpp for examples.
       * \sa gpstk::Rinex3NavHeader and gpstk::Rinex3NavData classes.
       */

   class Rinex3NavStream : public FFTextStream
   {
   public:
         /// Default constructor
      Rinex3NavStream();
      
         /** Constructor 
          * Opens a file named \a fn using ios::openmode \a mode.
          */
      Rinex3NavStream(const char* fn, std::ios::openmode mode=std::ios::in);
      
         /// Destructor
      virtual ~Rinex3NavStream();
      
         /// overrides open to reset the header
      virtual void open(const char* fn, std::ios::openmode mode);

         /// RINEX NAV header for this file.
      Rinex3NavHeader header;
     
         /// Flag showing whether or not the header has been read.
      bool headerRead;

   private:
         /// initialize internal data structures
      void init();
   };

      //@}

}

#endif
