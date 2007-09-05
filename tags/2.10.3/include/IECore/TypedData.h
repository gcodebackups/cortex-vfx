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

#ifndef IE_CORE_TYPEDDATA_H
#define IE_CORE_TYPEDDATA_H

#include "IECore/Data.h"

namespace IECore
{

/// A templated class which can be used to wrap useful data
/// types and containers. The copyFrom() function is implemented
/// so as to perform a lazy copy on write type behaviour - this
/// makes the creation of read only copies of significant amounts
/// of data relatively cheap. Note that as this class derives from
/// Object, a proper instantiation requires a fair bit of specialisation
/// of the methods reimplemented from Object. For this reason the
/// template implementation is hidden from the public interface, and
/// you can therefore only use only the typedefs in SimpleTypedData.h,
/// VectorTypedData.h and CompoundData.h rather than being able
/// to instantiate the template for arbitrary data types.
template <class T> 
class TypedData : public Data
{
	public:
	
		typedef boost::intrusive_ptr<TypedData> Ptr;
		typedef boost::intrusive_ptr<const TypedData> ConstPtr;
		
		typedef T ValueType;
	
		/// Default constructor.
		TypedData();
		/// Constructor based on the stored data type.
		TypedData(const T &data);
		
		//! @name RunTimeTyped interface
		////////////////////////////////////////////////////////////
		//@{
		virtual TypeId typeId() const;
		virtual std::string typeName() const;
		virtual bool isInstanceOf( TypeId typeId ) const;
		virtual bool isInstanceOf( const std::string &typeName ) const;
		static TypeId staticTypeId();
		static std::string staticTypeName();
		static bool inheritsFrom( TypeId typeId );
		static bool inheritsFrom( const std::string &typeName );
		//@}
		
		//! @name Object interface
		////////////////////////////////////////////////////////////
		//@{
		boost::intrusive_ptr<TypedData<T> > copy() const;
		bool isEqualTo( ConstObjectPtr other ) const;
		//@}
		
		/// Equivalent to writable() = data
		void operator = (const T &data);
		/// Equivalent to writable() = typedData.readable()
		void operator = (const TypedData<T> &typedData);

		/// get read-only access to the internal data structure.
		const T &readable() const;
		/// get read-write access to the internal data structure.
		T &writable();
		
		
		
	protected:
	
		/// protected destructor. Use intrusive_ptrs for this object.
		virtual ~TypedData();
		
		static TypeDescription<TypedData<T> > m_typeDescription;
		
		virtual void copyFrom( ConstObjectPtr other, CopyContext *context );
		virtual void save( SaveContext *context ) const;
		virtual void load( LoadContextPtr context );
		/// If the memory usage is anything other than sizeof(T) for
		/// a given T then you must provide an accurate specialisation
		/// for this function.
		virtual void memoryUsage( Object::MemoryAccumulator &accumulator ) const;
		
		class DataHolder : public RefCounted
		{
			public:
				DataHolder() : data() {}
				DataHolder(const T &initData) : data(initData) {}
			public:
				T data;
		};
		typedef boost::intrusive_ptr<DataHolder> DataHolderPtr;
		DataHolderPtr m_data;
};

} // namespace IECore

#endif // IE_CORE_TYPEDDATA_H
