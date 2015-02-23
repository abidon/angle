//
// types.h
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

#ifndef _types_h
#define _types_h

#ifdef __cplusplus
	struct null_pointer_t {
		operator void*() const { return (void*) 0; };
		template<typename T> operator T*() const { return (T*) 0; };
	};
	extern null_pointer_t nullptr;
#else
	#define nullptr ((void*)0)
#endif

#endif
