/*
 * d4
 * Copyright (C) 2020  Univ. Artois & CNRS
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once
#include <boost/program_options.hpp>
#include <vector>

#include "src/problem/ProblemManager.hpp"
#include "src/problem/ProblemTypes.hpp"

namespace d4 {
namespace po = boost::program_options;
struct LastBreathPreproc {
  std::vector<double> countConflict;
  bool panic;

  inline void fitSizeCountConflict(unsigned size) {
    countConflict.resize(size);
  }
};

class PreprocManager {
public:
  static PreprocManager *makePreprocManager(po::variables_map &vm,
                                            std::ostream &out);

  virtual ~PreprocManager() {}
  virtual ProblemManager *run(ProblemManager *pin,
                              LastBreathPreproc &lastBreath) = 0;
};
} // namespace d4
