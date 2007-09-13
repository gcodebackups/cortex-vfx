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

#ifndef IE_CORE_BOXTRAITS_H
#define IE_CORE_BOXTRAITS_H

#include <boost/static_assert.hpp>

#include "OpenEXR/ImathBox.h"

namespace IECore
{

/// The VectorTraits struct provides a means of using different box
/// classes within templated code. 
template<typename T>
struct BoxTraits
{
	BOOST_STATIC_ASSERT(sizeof(T)==0);	
};

template<>
struct BoxTraits<Imath::Box3s>
{
	typedef Imath::V3s BaseType;
};

template<>
struct BoxTraits<Imath::Box3i>
{
	typedef Imath::V3i BaseType;
};

template<>
struct BoxTraits<Imath::Box3f>
{
	typedef Imath::V3f BaseType;	
};

template<>
struct BoxTraits<Imath::Box3d>
{
	typedef Imath::V3d BaseType;	
};

template<>
struct BoxTraits<Imath::Box2s>
{
	typedef Imath::V2s BaseType;
};

template<>
struct BoxTraits<Imath::Box2i>
{
	typedef Imath::V2i BaseType;
};

template<>
struct BoxTraits<Imath::Box2f>
{
	typedef Imath::V2f BaseType;	
};

template<>
struct BoxTraits<Imath::Box2d>
{
	typedef Imath::V2d BaseType;	
};

} // namespace IECore

#endif // IE_CORE_BOXTRAITS_H
