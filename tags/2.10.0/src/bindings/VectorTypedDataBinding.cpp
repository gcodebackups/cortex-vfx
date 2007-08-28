//////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2007, Image Engine Design Inc. All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are
//  met:
//
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//
//     * Neither the name of Image Engine Design nor the names of any
//       other contributors to this software may be used to endorse or
//       promote products derived from this software without specific prior
//       written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
//  IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
//  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
//  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
//  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
//  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
//  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
//  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
//  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
//  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
//  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//////////////////////////////////////////////////////////////////////////

// System includes

// External includes
#include <boost/python.hpp>
#include <boost/python/make_constructor.hpp>
#include <boost/python/suite/indexing/container_utils.hpp>
#include <boost/numeric/conversion/cast.hpp>
#include <boost/python/implicit.hpp>

#include <OpenEXR/ImathBox.h>
#include <OpenEXR/ImathQuat.h>
#include <OpenEXR/ImathVec.h>

#include "IECore/VectorTypedData.h"
#include "IECore/bindings/ImathMatrixVectorBinding.h"
#include "IECore/bindings/ImathVecVectorBinding.h"
#include "IECore/bindings/ImathColorVectorBinding.h"
#include "IECore/bindings/ImathBoxVectorBinding.h"
#include "IECore/bindings/ImathQuatVectorBinding.h"
#include "IECore/bindings/IntrusivePtrPatch.h"
#include "IECore/bindings/VectorTypedDataBinding.inl"
#include "IECore/bindings/RunTimeTypedBinding.h"

using namespace std;
using std::string;
using namespace boost;
using namespace boost::python;
using namespace Imath;

namespace IECore {

IE_COREPYTHON_DEFINEVECTORDATASTRSPECIALISATION( half )
IE_COREPYTHON_DEFINEVECTORDATASTRSPECIALISATION( float )
IE_COREPYTHON_DEFINEVECTORDATASTRSPECIALISATION( double )
IE_COREPYTHON_DEFINEVECTORDATASTRSPECIALISATION( int )
IE_COREPYTHON_DEFINEVECTORDATASTRSPECIALISATION( unsigned int )
IE_COREPYTHON_DEFINEVECTORDATASTRSPECIALISATION( char )
IE_COREPYTHON_DEFINEVECTORDATASTRSPECIALISATION( unsigned char )
IE_COREPYTHON_DEFINEVECTORDATASTRSPECIALISATION( std::string )

void bindAllVectorTypedData()
{
	// basic types
	BIND_FULL_OPERATED_VECTOR_TYPEDDATA( 
		half,
		"HalfVectorData",
		"half")
		
	BIND_FULL_OPERATED_VECTOR_TYPEDDATA( 
		float,
		"FloatVectorData",
		"float")
		
	BIND_FULL_OPERATED_VECTOR_TYPEDDATA( 
		double,
		"DoubleVectorData",
		"double")
		
	BIND_FULL_OPERATED_VECTOR_TYPEDDATA(
		int,
		"IntVectorData",
		"int")
		
	BIND_FULL_OPERATED_VECTOR_TYPEDDATA(
		unsigned int,
		"UIntVectorData",
		"unsigned int")
		
	BIND_FULL_OPERATED_VECTOR_TYPEDDATA(
		char,
		"CharVectorData",
		"char")
		
	BIND_FULL_OPERATED_VECTOR_TYPEDDATA(
		unsigned char,
		"UCharVectorData",
		"unsigned char")
		
	BIND_VECTOR_TYPEDDATA (
		std::string,
		"StringVectorData",
		"string")
	
	// Imath types
	bindImathMatrixVectorTypedData();
	bindImathVecVectorTypedData();
	bindImathColorVectorTypedData();
	bindImathBoxVectorTypedData();
	bindImathQuatVectorTypedData();
}


} // namespace IECore
