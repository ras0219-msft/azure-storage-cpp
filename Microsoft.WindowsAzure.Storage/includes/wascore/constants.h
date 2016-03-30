// -----------------------------------------------------------------------------------------
// <copyright file="constants.h" company="Microsoft">
//    Copyright 2013 Microsoft Corporation
//
//    Licensed under the Apache License, Version 2.0 (the "License");
//    you may not use this file except in compliance with the License.
//    You may obtain a copy of the License at
//      http://www.apache.org/licenses/LICENSE-2.0
//
//    Unless required by applicable law or agreed to in writing, software
//    distributed under the License is distributed on an "AS IS" BASIS,
//    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//    See the License for the specific language governing permissions and
//    limitations under the License.
// </copyright>
// -----------------------------------------------------------------------------------------

#pragma once

#include "cpprest/asyncrt_utils.h"

#include "wascore/basic_types.h"

namespace azure { namespace storage { namespace protocol {

    // size constants
    const size_t max_block_size = 4 * 1024 * 1024;
    const size_t default_buffer_size = 64 * 1024;
    const utility::size64_t default_single_blob_upload_threshold = 32 * 1024 * 1024;

    // duration constants
    const std::chrono::seconds default_retry_interval(3);
    // The following value must be less than 2147482, which is the highest 
    // that Casablanca 2.2.0 on Linux can accept, which is derived from 
    // the maximum value for a signed long on g++, divided by 1000.
    // Choosing to set it to 24 days to align with .NET.
    const std::chrono::seconds default_maximum_execution_time(24 * 24 * 60 * 60);
    // For the following value, "0" means "don't send a timeout to the service"
    const std::chrono::seconds default_server_timeout(0);

    // lease break period and duration constants
    const std::chrono::seconds minimum_lease_break_period(0);
    const std::chrono::seconds maximum_lease_break_period(60);
    const std::chrono::seconds minimum_fixed_lease_duration(15);
    const std::chrono::seconds maximum_fixed_lease_duration(60);

#define DAT(a,b) extern WASTORAGE_API const utility::string_t a;
#include "constants.dat"
#undef DAT

}}} // namespace azure::storage::protocol
