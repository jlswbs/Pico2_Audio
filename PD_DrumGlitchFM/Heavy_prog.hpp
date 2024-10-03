/**
 * Copyright (c) 2024 Enzien Audio, Ltd.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions, and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the phrase "powered by heavy",
 *    the heavy logo, and a hyperlink to https://enzienaudio.com, all in a visible
 *    form.
 * 
 *   2.1 If the Application is distributed in a store system (for example,
 *       the Apple "App Store" or "Google Play"), the phrase "powered by heavy"
 *       shall be included in the app description or the copyright text as well as
 *       the in the app itself. The heavy logo will shall be visible in the app
 *       itself as well.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#ifndef _HEAVY_CONTEXT_PROG_HPP_
#define _HEAVY_CONTEXT_PROG_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvControlRandom.h"
#include "HvMath.h"
#include "HvSignalPhasor.h"
#include "HvSignalTabwrite.h"
#include "HvSignalDel1.h"
#include "HvControlCast.h"
#include "HvControlUnop.h"
#include "HvSignalRPole.h"
#include "HvControlIf.h"
#include "HvSignalLine.h"
#include "HvControlVar.h"
#include "HvControlSlice.h"
#include "HvControlSystem.h"
#include "HvControlDelay.h"
#include "HvControlBinop.h"
#include "HvTable.h"
#include "HvSignalSamphold.h"
#include "HvSignalTabread.h"
#include "HvSignalVar.h"

class Heavy_prog : public HeavyContext {

 public:
  Heavy_prog(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_prog();

  const char *getName() override { return "prog"; }
  int getNumInputChannels() override { return 0; }
  int getNumOutputChannels() override { return 2; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;

  // static sendMessage functions
  static void hTable_RPybrwyL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_PUzx5J4j_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_Z2ETUH2l_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_zUFw6YIe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_NxmAdL4j_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_7PWKjbuI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_9Hi8Lehd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_A4TrlUct_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_DIdRVfnd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_lE2tvkIQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_0jqJDRfH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_A8fDG0AD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YCWHuW0E_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_YzALYAHs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_f44YIuir_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_Y3cbda9K_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_6z2fPESs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_WPyuVZZF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_hZVHbfpP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_FZQbGmrj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_0ZuVoSqE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_NTcDpuIf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_nOEyHi70_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_XHNXr2pF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_rYtio41B_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_S5xfh6CL_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_3riWEw75_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_6BrnfrRu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_k2XoZ2w8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_LY2ZymZR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_t1YLww9E_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_VK7B9Wl5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_JENHcmIR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_U58fPOPy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_RJ6MgK3l_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_91sfLIvG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_RLkz05Bo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_RBHPkfW8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_KNrbREf3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_SztCNhM2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_VEnwZih7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_qTUbHXbW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_z1PsCsLt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_M6pfpqYc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_9YIRdBQ1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_dC1efwJt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DQ2RDtrD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Wg5YprUu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_1gL6Rlxv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zUL7lbCF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_8aRKPNJU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_ntndhPz8_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_T857R1xP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_gNJ1Wlke_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ZgVEWp6e_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_IDE2DtRJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_J0dqboxp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_qS9ofKEV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ajAU4xS3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_3MIfEG3H_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_QX6IspvZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_96jvUkca_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Uqq5fzS1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ewM44c36_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_9SyzrrDf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Ip4jN9Uc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_GNlI5elM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vrc1CUtI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ZXSZc9XK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_sYmLvgi1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_vcTAt9hK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_UPVoeEHn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_S0cikNAI_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_SfawAqxR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_QxlAcxqw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Ux59tf7V_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_N7WSYgsY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_SnOBO9j0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ewANWjOr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_jh1QNYEv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5k9FiQEC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8ZDjxtSd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_jr8Ca8hg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zOCOO7KW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_3ZwSbsEc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rbMoadIv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_BVJv4vSA_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_HybCuGtQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_UBTcnyli_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_P01Uzsem_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_ImyOuUGp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zm1B70yt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ekwuzCWF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_QUd8stx2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_aU2bIAy5_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_fdH6qdv2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_6iDo3esw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_QCsfuRNg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_pdcPZmqi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_D0cEkarV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_CTqYKW19_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_GcoERMzi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ciY4sDNo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_spsDT5OI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_wg5qY8bA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_B806sm5j_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_68hyqiX6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ViKC17ZH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_6wBjFsQe_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_5g6P4c1V_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_fpHUHaLt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_FTe6QJjj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_i0hiHACv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_heXrX7qJ_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_tMYt1iLh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_8WBEbD2e_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_89VQm834_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_iLmaKfZz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_ESOTVdZz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_hRYjz46H_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BHTNqq02_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VXAgrh9K_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_7FynoUqJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_sDDcAT5A_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DleDTZjq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_v5UVwLG4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_KsJ9mrUA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zpcS123e_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BjZy6IJu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9ZXAVl2w_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Gm1kQSP4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_aTWh4Jxk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_606VL5LI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_w5sGTnhf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_RXePku6N_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_82E6O9Qx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_zcHzbyTc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zxCa1cjO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_0p76Drca_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_VsCO4u1f_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Me6Da1JP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Z6oyN6sZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_s5aEJK1M_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_upcoXnDC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_DNL0Uqoj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_B36a8uZN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_d2dEagC9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_a7v4HRuW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_2la0ru3u_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_sV6zJ1op_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_PsxYpv36_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_6jEL6YOb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_PULZ8onL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_g3dlt2cL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6r1VMRFZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_MyYarodY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_uVVkLxiV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WzRRpJ9N_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_JGaTbcrf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_C42bQUdF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_8yPlSrws_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_fFrDgHfs_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_DShILYSK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_de473Hh0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_r6Wt5DFl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_eWDxf5oR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ssaxiUQO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_e5auMNvv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_j7jyn2R2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_Qi6p3h9V_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_bpm8RBsk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_YRTv2RPa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_8813EPV5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_dzYM5zHI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_LAtSLMje_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_JpAUte9n_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_uYrpCHO7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rHEiEK7K_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qc5I9DdI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_IcjehQRy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_Cd5emoYZ_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_AR3P6B1S_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_EI9HqyFN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_FEBKi0xq_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_VfvZNKCa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_Kq4bUuIT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_XZT9R5SK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_seT2eV2v_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_w2hin7dg_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_TLQIdLE1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_wl1nnByO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_NoVIsnBC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_nnHIaXVT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_4T7qwEJz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_D9x4KREN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_i0MXIn5d_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_sxFmoikJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_nWcScPzL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BQzaXrHs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KYktjVsA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_qqzuoaMi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_70lT2zuT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0E8gdAW7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_RqvbQYqf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ZmOiM4Wf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_apbEW0CM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_mvdz8zCg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_SlawRg8H_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_PMiUtajo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_SMwFp36D_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_O9IuZjeJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_FBJULFho_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_armmSPWm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_eJMbC5M9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_NsK5SY90_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_wRuDHKm3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_5L21tn6N_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_d5itjuX6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6fjzYiQw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_WG52xhO0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_PKOf85TP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_oF4NkZRC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_VVbNi4Pc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_H4piAIN2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_YCOhlR5C_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_6k5ze4ta_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_caU1RzYj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_GScugVGS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ZusCWYHG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_L50m1Mow_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_bJxM0Zq5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_eW21dpQX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_grTuOQs2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ny98PFUf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_faGqVW0B_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_FlFT4gzu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_HgTx5jVE_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_5WdJoRC5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_wsrtc66w_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_JxG8mkEi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_UUTRu7aX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_8QI7YkcU_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_DYwMHVci_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_rDJdRrbX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_iS6JIoz8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_2v6vDrzi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_zQRB2P9v_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WxJyEOf4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_9SqdVFxV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_2QelaX80_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_MIcD3Kku_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_dz9ksWt7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_hktaKlWF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_NqokPbQb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_a4uSFIya_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_V3H9Cqo1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_qbxjeyM5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_Z1f3RJYd_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_BMJ0wvEM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_AKSubafE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_YX9oAOCs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_1uOOPjn1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_hvy9d5nq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Jcpl7OoL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kwa6daRT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_PZFcrWBo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HBaxAvdu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_wXWWX23S_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_03Z4l1cW_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_XrhaeER5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_4dW4NfKv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_mBWkjrnn_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_TGax4pJi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_KxCPzJVV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_XCaUsISU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ycxLVGkb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_v97Jw2Yg_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_GOQ5vOCM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_KfMyo88r_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_0XXKNvAV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ORIxzAtG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_bDzVhOnQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_2au1wLlK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KuapHPix_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zkmtqCjL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_K21HBUVF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9QWjhwdC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_L46t4IMZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_us4sJybV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_9VYaB8vG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qw3gceKR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_M9mTMyVw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9faFPxs1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_r9CgljTz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_TOgTWy2Q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Ju9yqpox_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_qfRDuYJ7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_MW8aldS2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_UoDYYhgJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_VPR9D8uU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_38Pl3nMq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_KwzqhoKI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_eCMEh9Wx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_xnwFIMbC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_1kDccx21_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_AtY3pVdv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ipAz7kjd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_UR4cqD1Z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_nUbw5jhD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_QLvRla8d_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_4YIrYFgP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_LgUyw1tZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ce0ZlvB6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_O06H60Og_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_E7RmBtPd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_ANJncfR0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_TO0V0KMU_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_RdbfgFrv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_ToPW3UQS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_dEsYqyXn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1eWf44U3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_kJBUe96a_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_uJsqLaQL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_qCVhPtz1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_JlRcNtP0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kPA0dLJD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rbRPtNdU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_yE62pBdh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_kMtSqZR2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_NIpxk2Q9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_wqFhdin6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_UL3nE32M_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ojRXyRKc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Cuv3H57T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_MdYX8rOX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qJXLDTsp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_U9k74GC0_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalLine sLine_Wn4xGTap;
  SignalTabhead sTabhead_3Jg1d84C;
  SignalTabread sTabread_llG7Hkm1;
  SignalTabread sTabread_gMlwLtdZ;
  SignalPhasor sPhasor_i6IXorOW;
  SignalDel1 sDel1_Mgx5RUVM;
  SignalSamphold sSamphold_DHHG7BtT;
  SignalPhasor sPhasor_g3ELGpII;
  SignalTabread sTabread_zZkLsy0S;
  SignalRPole sRPole_3zvzGcbH;
  SignalDel1 sDel1_WTX9mCyY;
  SignalSamphold sSamphold_3SoJdobP;
  SignalPhasor sPhasor_rQRUfaH6;
  SignalPhasor sPhasor_9tkoB20b;
  SignalLine sLine_XP150LC0;
  SignalTabread sTabread_q0Nv109U;
  SignalLine sLine_PAANS8fd;
  SignalTabwrite sTabwrite_1LpRqB1M;
  SignalPhasor sPhasor_dgHVr5b1;
  SignalTabread sTabread_2BpHVnS5;
  SignalRPole sRPole_aHCsP9fw;
  SignalTabread sTabread_FRPPLcoI;
  HvTable hTable_RPybrwyL;
  ControlBinop cBinop_Z2ETUH2l;
  ControlRandom cRandom_NxmAdL4j;
  ControlSlice cSlice_7PWKjbuI;
  SignalVari sVari_ebEiUZe1;
  ControlVar cVar_DIdRVfnd;
  ControlSlice cSlice_A8fDG0AD;
  ControlBinop cBinop_YCWHuW0E;
  SignalVarf sVarf_0rouOuEK;
  HvTable hTable_YzALYAHs;
  ControlVar cVar_Y3cbda9K;
  ControlSlice cSlice_hZVHbfpP;
  ControlBinop cBinop_FZQbGmrj;
  SignalVarf sVarf_EOxSq7SM;
  ControlVar cVar_0ZuVoSqE;
  ControlBinop cBinop_NTcDpuIf;
  ControlVar cVar_nOEyHi70;
  ControlVar cVar_XHNXr2pF;
  ControlVar cVar_rYtio41B;
  ControlBinop cBinop_3riWEw75;
  ControlRandom cRandom_k2XoZ2w8;
  ControlSlice cSlice_LY2ZymZR;
  ControlBinop cBinop_zUL7lbCF;
  SignalVarf sVarf_saQvZ3iN;
  ControlBinop cBinop_vrc1CUtI;
  SignalVarf sVarf_hupngRmY;
  ControlDelay cDelay_SfawAqxR;
  ControlVar cVar_SnOBO9j0;
  ControlBinop cBinop_jh1QNYEv;
  ControlBinop cBinop_5k9FiQEC;
  ControlBinop cBinop_8ZDjxtSd;
  ControlVar cVar_jr8Ca8hg;
  ControlBinop cBinop_zOCOO7KW;
  ControlVar cVar_3ZwSbsEc;
  ControlBinop cBinop_rbMoadIv;
  ControlVar cVar_HybCuGtQ;
  ControlSlice cSlice_ImyOuUGp;
  ControlBinop cBinop_zm1B70yt;
  SignalVarf sVarf_AmiAXVq4;
  ControlDelay cDelay_fdH6qdv2;
  ControlVar cVar_D0cEkarV;
  ControlBinop cBinop_GcoERMzi;
  ControlBinop cBinop_ciY4sDNo;
  ControlBinop cBinop_spsDT5OI;
  ControlVar cVar_wg5qY8bA;
  ControlSlice cSlice_5g6P4c1V;
  ControlSlice cSlice_fpHUHaLt;
  ControlVar cVar_FTe6QJjj;
  ControlVar cVar_i0hiHACv;
  ControlVar cVar_8WBEbD2e;
  ControlVar cVar_89VQm834;
  ControlVar cVar_iLmaKfZz;
  ControlSlice cSlice_ESOTVdZz;
  ControlSlice cSlice_hRYjz46H;
  ControlBinop cBinop_BHTNqq02;
  ControlBinop cBinop_VXAgrh9K;
  ControlBinop cBinop_7FynoUqJ;
  ControlBinop cBinop_sDDcAT5A;
  ControlBinop cBinop_DleDTZjq;
  ControlBinop cBinop_zpcS123e;
  ControlBinop cBinop_BjZy6IJu;
  ControlBinop cBinop_9ZXAVl2w;
  ControlBinop cBinop_Gm1kQSP4;
  ControlBinop cBinop_zxCa1cjO;
  ControlBinop cBinop_upcoXnDC;
  ControlVar cVar_2la0ru3u;
  ControlVar cVar_sV6zJ1op;
  ControlVar cVar_PsxYpv36;
  ControlBinop cBinop_g3dlt2cL;
  ControlBinop cBinop_6r1VMRFZ;
  SignalVarf sVarf_771Hl0qJ;
  ControlBinop cBinop_uVVkLxiV;
  ControlBinop cBinop_WzRRpJ9N;
  ControlBinop cBinop_JGaTbcrf;
  SignalVarf sVarf_D9uWrCeC;
  ControlBinop cBinop_C42bQUdF;
  ControlVar cVar_DShILYSK;
  ControlSlice cSlice_eWDxf5oR;
  ControlBinop cBinop_ssaxiUQO;
  SignalVarf sVarf_F0N8VNNn;
  ControlDelay cDelay_bpm8RBsk;
  ControlVar cVar_LAtSLMje;
  ControlBinop cBinop_uYrpCHO7;
  ControlBinop cBinop_rHEiEK7K;
  ControlBinop cBinop_qc5I9DdI;
  ControlVar cVar_IcjehQRy;
  ControlSlice cSlice_VfvZNKCa;
  ControlSlice cSlice_Kq4bUuIT;
  ControlVar cVar_XZT9R5SK;
  ControlVar cVar_seT2eV2v;
  ControlVar cVar_wl1nnByO;
  ControlVar cVar_NoVIsnBC;
  ControlVar cVar_nnHIaXVT;
  ControlSlice cSlice_4T7qwEJz;
  ControlSlice cSlice_D9x4KREN;
  ControlBinop cBinop_i0MXIn5d;
  ControlBinop cBinop_sxFmoikJ;
  ControlBinop cBinop_nWcScPzL;
  ControlBinop cBinop_BQzaXrHs;
  ControlBinop cBinop_KYktjVsA;
  ControlBinop cBinop_0E8gdAW7;
  ControlBinop cBinop_RqvbQYqf;
  ControlBinop cBinop_ZmOiM4Wf;
  ControlBinop cBinop_apbEW0CM;
  ControlBinop cBinop_armmSPWm;
  ControlBinop cBinop_6fjzYiQw;
  ControlVar cVar_H4piAIN2;
  ControlVar cVar_YCOhlR5C;
  ControlVar cVar_6k5ze4ta;
  ControlBinop cBinop_ZusCWYHG;
  ControlBinop cBinop_L50m1Mow;
  SignalVarf sVarf_YPz7pNXi;
  ControlBinop cBinop_eW21dpQX;
  ControlBinop cBinop_grTuOQs2;
  ControlBinop cBinop_ny98PFUf;
  SignalVarf sVarf_zVe07gie;
  ControlBinop cBinop_faGqVW0B;
  ControlBinop cBinop_5WdJoRC5;
  ControlRandom cRandom_JxG8mkEi;
  ControlSlice cSlice_UUTRu7aX;
  ControlBinop cBinop_DYwMHVci;
  ControlRandom cRandom_iS6JIoz8;
  ControlSlice cSlice_2v6vDrzi;
  ControlIf cIf_zQRB2P9v;
  ControlBinop cBinop_WxJyEOf4;
  ControlVar cVar_MIcD3Kku;
  ControlBinop cBinop_hktaKlWF;
  ControlBinop cBinop_a4uSFIya;
  SignalVarf sVarf_Jjf6gCEl;
  SignalVarf sVarf_Aov3NyUl;
  SignalVarf sVarf_t7y0Bxki;
  ControlDelay cDelay_BMJ0wvEM;
  ControlVar cVar_hvy9d5nq;
  ControlBinop cBinop_kwa6daRT;
  ControlBinop cBinop_PZFcrWBo;
  ControlBinop cBinop_HBaxAvdu;
  ControlVar cVar_wXWWX23S;
  ControlSlice cSlice_TGax4pJi;
  ControlSlice cSlice_KxCPzJVV;
  ControlVar cVar_XCaUsISU;
  ControlVar cVar_ycxLVGkb;
  ControlVar cVar_KfMyo88r;
  ControlVar cVar_0XXKNvAV;
  ControlVar cVar_ORIxzAtG;
  ControlSlice cSlice_bDzVhOnQ;
  ControlSlice cSlice_2au1wLlK;
  ControlBinop cBinop_KuapHPix;
  ControlBinop cBinop_zkmtqCjL;
  ControlBinop cBinop_K21HBUVF;
  ControlBinop cBinop_9QWjhwdC;
  ControlBinop cBinop_L46t4IMZ;
  ControlBinop cBinop_qw3gceKR;
  ControlBinop cBinop_M9mTMyVw;
  ControlBinop cBinop_9faFPxs1;
  ControlBinop cBinop_r9CgljTz;
  ControlBinop cBinop_38Pl3nMq;
  ControlBinop cBinop_ipAz7kjd;
  ControlVar cVar_LgUyw1tZ;
  ControlDelay cDelay_E7RmBtPd;
  ControlDelay cDelay_ANJncfR0;
  ControlBinop cBinop_RdbfgFrv;
  HvTable hTable_ToPW3UQS;
  ControlBinop cBinop_1eWf44U3;
  ControlBinop cBinop_kPA0dLJD;
  ControlBinop cBinop_rbRPtNdU;
  ControlBinop cBinop_UL3nE32M;
  ControlBinop cBinop_Cuv3H57T;
  ControlBinop cBinop_qJXLDTsp;
  SignalVarf sVarf_XvZVkes5;
  SignalVarf sVarf_NW0SJJDr;
  SignalVarf sVarf_mmmh0Fsa;
  SignalVarf sVarf_6mRg3hUI;
};

#endif // _HEAVY_CONTEXT_PROG_HPP_
