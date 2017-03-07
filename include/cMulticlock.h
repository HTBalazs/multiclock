/*
    Copyright 2017 Balazs Toth
    This file is part of Multiclock.

    Multiclock is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Multiclock is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with Multiclock.  If not, see <http://www.gnu.org/licenses/>.

    For more information please visit: https://bitbucket.org/Multiclock/
*/

#include <iostream>
#include <vector>
#include <numeric>
#include "prolog/pLogger.h"

class cMulticlock {
	using Clock = std::chrono::duration<double>;
	std::vector<Clock> clock;
	int idx = 0;
	pTimer timer;
	bool started = false;
public:
	cMulticlock() {}
	void tic(int const& i);
	void start();
	void finish();
	void report() const;	
};