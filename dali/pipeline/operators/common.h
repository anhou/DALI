// Copyright (c) 2017-2018, NVIDIA CORPORATION. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef DALI_PIPELINE_OPERATORS_COMMON_H_
#define DALI_PIPELINE_OPERATORS_COMMON_H_

#include <vector>

#include "dali/pipeline/operators/op_spec.h"

namespace dali {
template <typename T>
inline void GetSingleOrDoubleArg(const OpSpec &spec, vector<T> *arg, const char *argName,
                          bool doubleArg = true) {
  try {
      *arg = spec.GetRepeatedArgument<T>(argName);
  } catch (std::runtime_error e) {
      try {
        *arg = {spec.GetArgument<T>(argName)};
      } catch (std::runtime_error e) {
          DALI_FAIL("Invalid type of argument \"" + argName + "\"");
      }
  }

  if (doubleArg && arg->size() == 1)
    arg->push_back(arg->back());
}

}  // namespace dali
#endif  // DALI_PIPELINE_OPERATORS_COMMON_H_
