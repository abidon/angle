//
// iterator.hxx
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

#ifndef _angle_iterator_h
#define _angle_iterator_h

namespace angle {
	template <typename _type>
	struct Iterator
	{
		virtual _type&
		operator*() const = 0;

		virtual _type*
		operator->() const = 0;

		virtual Iterator&
		operator++() = 0;

		virtual Iterator&
		operator--() = 0;

		virtual
		operator bool() const = 0;

		virtual
		operator _type*() const = 0;
	};
}

#endif
