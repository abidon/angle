//
// list.hxx
//
// Angle - A C++ template library for Circle
// Copyright (C) 2014 Bidon Aurelien <bidon.aurelien@gmail.com>
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef _angle_list_h
#define _angle_list_h

#include <types.h>
#include <angle/iterator.hxx>

/*
 * Future improvements: clear, removeIf, (cached) size
 */

namespace angle {
	template <typename _type>
	class List
	{
		struct Node
		{
			_type data;
			Node* next;
			Node* prev;
			
			Node(const _type& data, Node* next, Node* prev);
			
			Node&
			operator=(const Node&) = delete;
		};
		
		template <typename _itype>
		class ListIterator : public Iterator<_itype>
		{
			friend class List<_type>;
			List<_type> const* _container;
			List<_type>::Node* _cursor;
			
			ListIterator(const List<_type>* list);
			
		public:
			virtual _itype&
			operator*() const;

			virtual _itype*
			operator->() const;

			virtual ListIterator&
			operator++();

			virtual ListIterator&
			operator--();

			virtual
			operator bool() const;
			
			virtual
			operator _itype*() const;
		};
		
		Node* _head;
		Node* _tail;
		
		void
		_insertAfter(Node* cur, const _type& val);
		
		void
		_insertBefore(Node* cur, const _type& val);
		
		void
		_remove(Node* cur);
	public:
		List(void);
		List(const List& copy); // todo
		List& operator=(const List& copy) = delete;

		_type&
		back(void);

		const _type&
		back(void) const;
		
		ListIterator<const _type>
		constIterator(void) const;
		
		bool
		empty(void) const;

		_type&
		front(void);

		const _type&
		front(void) const;
		
		void
		insertAfter(const _type& val, const ListIterator<_type>& iter);
		
		void
		insertBefore(const _type& val, const ListIterator<_type>& iter);
		
		ListIterator<_type>
		iterator(void);
		
		List<_type>&
		popBack(void);
		
		List<_type>&
		popFront(void);
		
		List<_type>&
		pushBack(const _type& v);
		
		List<_type>&
		pushFront(const _type& v);
		
		void
		remove(ListIterator<_type> iter);
	};
}

#include "impl/list.hpp"

#endif
