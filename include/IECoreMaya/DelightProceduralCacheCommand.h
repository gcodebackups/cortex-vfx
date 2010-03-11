//////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2009, Image Engine Design Inc. All rights reserved.
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

#ifndef IECOREMAYA_DELIGHTPROCEDURALCACHECOMMAND_H
#define IECOREMAYA_DELIGHTPROCEDURALCACHECOMMAND_H

#include <string>
#include <map>

#include "maya/MPxCommand.h"

#include "IECore/ParameterisedProcedural.h"
#include "IECore/CompoundObject.h"

namespace IECoreMaya
{

/// This command provides support for outputting ProceduralHolders into
/// the rib stream generated by 3dfm, the 3delight rib generation plugin
/// for maya.
class DelightProceduralCacheCommand : public MPxCommand
{
	public :
	
		DelightProceduralCacheCommand();
		virtual ~DelightProceduralCacheCommand();
		
		static void *creator();
		static MSyntax newSyntax();
		
		MStatus doIt( const MArgList & args );
		
	private :
		
		struct CachedProcedural
		{
			std::string className;
			int classVersion;
			Imath::Box3f bound; // the union of the procedural bound across all sample times
			IECore::ParameterisedProceduralPtr procedural;
			IECore::ObjectPtr values;
		};		
		typedef std::map<std::string, CachedProcedural> ProceduralMap;
		static ProceduralMap g_procedurals;
		
};

} // namespace IECoreMaya

#endif // IECOREMAYA_DELIGHTPROCEDURALCACHECOMMAND_H
