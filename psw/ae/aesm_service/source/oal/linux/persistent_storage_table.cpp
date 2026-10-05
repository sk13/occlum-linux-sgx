/*
 * Copyright (C) 2011-2021 Intel Corporation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 *   * Neither the name of Intel Corporation nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include "se_version.h"
#include "persistent_storage_info.h"
#include "util.h"

//The ordering of the array must be same as the enumerartion aesm_data_id_t
static const persistent_storage_info_t psinfos[]={
	{FT_ENCLAVE_NAME, AESM_LOCATION_EXE_FOLDER, AESM_FILE_ACCESS_PATH_ONLY, "libsgx_pce.signed.so." PCE_VERSION}, //PCE_ENCLAVE_FID
    {FT_PERSISTENT_STORAGE, AESM_LOCATION_DATA, AESM_FILE_ACCESS_ALL, "aesm_network_setting.blob"},//NETWORK_SETTING_FID
#ifdef DBG_LOG
    {FT_PERSISTENT_STORAGE, AESM_LOCATION_DATA, AESM_FILE_ACCESS_ALL, "internal_log.txt"}, //AESM_DBG_LOG_FID
    {FT_PERSISTENT_STORAGE, AESM_LOCATION_DATA, AESM_FILE_ACCESS_ALL, "internal_log_cfg.xml"}, //AESM_DBG_LOG_CFG_FID
#endif
#ifdef _PROFILE_
    {FT_PERSISTENT_STORAGE, AESM_LOCATION_DATA, AESM_FILE_ACCESS_ALL, "perf_time.csv"}, //AESM_PERF_DATA_FID
#endif
};

se_static_assert(sizeof(psinfos)/sizeof(persistent_storage_info_t) == NUMBER_OF_FIDS);

const persistent_storage_info_t* get_persistent_storage_info(aesm_data_id_t id)
{
    if(id<0||id>=NUMBER_OF_FIDS)
        return NULL;
    return &psinfos[id];
}

