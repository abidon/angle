//
// impl/list.hpp
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

#ifndef _angle_list_impl_h
#define _angle_list_impl_h

#ifndef _angle_list_h
#	error angle/impl/list.hpp should not be included manually
#endif

#ifdef __EXCEPTIONS
#	include <angle/exception.h>
#else
#	include <assert.h>
#endif

/*=================
  angle::List<type>
  ===============*/
template <typename _type>
angle::List<_type>::List(void) :
_head(nullptr),
_tail(nullptr)
{ }

template <typename _type>
void
angle::List<_type>::_insertAfter(Node* cur, const _type& val)
{
	Node* newNode = new Node(val, cur->next, cur);
	if (cur->next == nullptr) _tail = newNode;
	else cur->next->prev = newNode;
	cur->next = newNode;
}

template <typename _type>
void
angle::List<_type>::_insertBefore(Node* cur, const _type& val)
{
	Node* newNode = new Node(val, cur, cur->prev);
	if (cur->prev == nullptr) _head = newNode;
	else cur->prev->next = newNode;
	cur->prev = newNode;
}

template <typename _type>	
void
angle::List<_type>::_remove(Node* cur)
{
	if (cur->prev == nullptr) _head = cur->next;
	else cur->prev->next = cur->next;
	
	if (cur->next == nullptr) _tail = cur->prev;
	else cur->next->prev = cur->prev;
	
	delete cur;
}

template <typename _type>
_type&
angle::List<_type>::back(void)
{
#ifdef __EXCEPTIONS
	if (empty()) throw OutOfRangeException();
#else
	assert(empty() == false);
#endif
	return _tail->data;
}

template <typename _type>
const _type&
angle::List<_type>::back(void) const
{
#ifdef __EXCEPTIONS
	if (empty()) throw OutOfRangeException();
#else
	assert(empty() == false);
#endif
	return _tail->data;
}

template <typename _type>
angle::List<_type>::ListIterator<const _type>
angle::List<_type>::constIterator(void) const
{
	return ListIterator<const _type>(this);
}

template <typename _type>
bool
angle::List<_type>::empty(void) const
{
	return _head == nullptr;
}

template <typename _type>
_type&
angle::List<_type>::front(void)
{
#ifdef __EXCEPTIONS
	if (empty()) throw OutOfRangeException();
#else
	assert(empty() == false);
#endif
	return _head->data;
}

template <typename _type>
const _type&
angle::List<_type>::front(void) const
{
#ifdef __EXCEPTIONS
	if (empty()) throw OutOfRangeException();
#else
	assert(empty() == false);
#endif
	return _head->data;
}

template <typename _type>
void
angle::List<_type>::insertAfter(const _type& val, const ListIterator<_type>& iter)
{
#ifdef __EXCEPTIONS
	if (empty()) throw OutOfRangeException();
	if (iter._container != this) throw OutOfRangeException();
	if (iter._cursor == nullptr) throw OutOfRangeException();
#else
	assert(empty() == false);
	assert(iter._container == this);
	assert(iter._cursor != nullptr);
#endif
	
	_insertAfter(iter._cursor, val);
}

template <typename _type>
void
angle::List<_type>::insertBefore(const _type& val, const ListIterator<_type>& iter)
{
#ifdef __EXCEPTIONS
	if (empty()) throw OutOfRangeException();
	if (iter._container != this) throw OutOfRangeException();
	if (iter._cursor == nullptr) throw OutOfRangeException();
#else
	assert(empty() == false);
	assert(iter._container == this);
	assert(iter._cursor != nullptr);
#endif
	
	_insertBefore(iter._cursor, val);
}

template <typename _type>
angle::List<_type>::ListIterator<_type>
angle::List<_type>::iterator(void)
{
	return ListIterator<_type>(this);
}

template <typename _type>
angle::List<_type>&
angle::List<_type>::popBack(void)
{
#ifdef __EXCEPTIONS
	if (empty()) throw OutOfRangeException();
#else
	assert(empty() == false);
#endif
	_remove(_tail);
	return *this;
}

template <typename _type>
angle::List<_type>&
angle::List<_type>::popFront(void)
{
#ifdef __EXCEPTIONS
	if (empty()) throw OutOfRangeException();
#else
	assert(empty() == false);
#endif
	_remove(_head);
	return *this;
}

template <typename _type>
angle::List<_type>&
angle::List<_type>::pushBack(const _type& v)
{
	if (_tail == nullptr)
		pushFront(v);
	else _insertAfter(_tail, v);
	return *this;
}

template <typename _type>
angle::List<_type>&
angle::List<_type>::pushFront(const _type& v)
{
	if (_head == nullptr) _head = _tail = new Node(v, nullptr, nullptr);
	else _insertBefore(_head, v);
	return *this;
}

template <typename _type>
void
angle::List<_type>::remove(ListIterator<_type> iter)
{
#ifdef __EXCEPTIONS
	if (empty()) throw OutOfRangeException();
	if (iter._container != this) throw OutOfRangeException();
	if (iter._cursor == nullptr) throw OutOfRangeException();
#else
	assert(empty() == false);
	assert(iter._container == this);
	assert(iter._cursor != nullptr);
#endif
	_remove(iter._cursor);
}

/*==================================
  angle::List<type>::Iterator<itype>
  ================================*/
template <typename _type>
template <typename _itype>
angle::List<_type>::ListIterator<_itype>::ListIterator(const List<_type>* list) :
_container(list),
_cursor(list->_head)
{ }

template <typename _type>
template <typename _itype>
_itype&
angle::List<_type>::ListIterator<_itype>::operator*() const
{
	return _cursor->data;
}

template <typename _type>
template <typename _itype>
_itype*
angle::List<_type>::ListIterator<_itype>::operator->() const
{
	return &_cursor->data;
}

template <typename _type>
template <typename _itype>
angle::List<_type>::ListIterator<_itype>&
angle::List<_type>::ListIterator<_itype>::operator++()
{
	_cursor = _cursor->next;
	return *this;
}

template <typename _type>
template <typename _itype>
angle::List<_type>::ListIterator<_itype>&
angle::List<_type>::ListIterator<_itype>::operator--()
{
	_cursor = _cursor->prev;
	return *this;
}

template <typename _type>
template <typename _itype>
angle::List<_type>::ListIterator<_itype>::operator bool() const
{
	return _cursor != nullptr;
}

template <typename _type>
template <typename _itype>
angle::List<_type>::ListIterator<_itype>::operator _itype*() const
{
	return &_cursor->data;
}

/*=======================
  angle::List<type>::Node
  =====================*/
template <typename _type>
angle::List<_type>::Node::Node(const _type& data, Node* next, Node* prev) :
data(data),
next(next),
prev(prev)
{ }

#endif