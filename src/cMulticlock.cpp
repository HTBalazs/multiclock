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

#include "cMulticlock.h"

using namespace ProLog;

void cMulticlock::start() {
	clock.push_back(Clock{});
	idx = 0;
	started = true;
	timer.tic();
}
void cMulticlock::tic(int const& i) {
	if(!started) {
		pLogger::warning_msg("Multiclock is not started yet.\n");
		return;
	}
	if(i==idx) { return; }
	if(clock.size()<=i) {
		clock.resize(i+1, Clock{});
	}
	this->finish();
	idx = i;
	timer.tic();
}
void cMulticlock::pause() {
	if(started) {
		this->finish();
	}
}
void cMulticlock::resume() {
	if(started) {
		timer.tic();
	}
}
void cMulticlock::finish() {
	timer.tac();
	clock[idx] += timer.get_difference();
}
void cMulticlock::report() const {
	pLogger::log<GRN>(" Multiclock summary:\n");
	pLogger::log<GRN>("  Clock   |   Duration[%%]\n");
	double total = 0;
	for(auto const& n : clock) {
		total += n.count();
	}
	for(int i=0; i<clock.size();i++) {
		pLogger::log<GRN>("     %i    |      %g\n", i, clock[i]/total*100.0f);
	}
}