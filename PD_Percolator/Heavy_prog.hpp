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
#include "HvSignalPhasor.h"
#include "HvControlTabhead.h"
#include "HvControlSlice.h"
#include "HvSignalBiquad.h"
#include "HvControlRandom.h"
#include "HvSignalTabwrite.h"
#include "HvControlPack.h"
#include "HvControlVar.h"
#include "HvMath.h"
#include "HvSignalLine.h"
#include "HvSignalTabread.h"
#include "HvTable.h"
#include "HvSignalDel1.h"
#include "HvControlCast.h"
#include "HvControlUnop.h"
#include "HvControlDelay.h"
#include "HvSignalVar.h"
#include "HvControlSystem.h"
#include "HvControlBinop.h"
#include "HvSignalRPole.h"

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
  static void cBinop_AuJw2oek_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_019JhJyD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3P5Y59Ys_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_NvNZfntG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_1x6Zn2CS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_5xQo5FrO_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_JMeov7LZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_QU3JNlYh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_W51xktNs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_Q8uSaD8A_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Kqcg1tsA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabhead_P3uNalpp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_lZk3h5U7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_j9PjxO4V_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_wHkXSSjw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_4l4zmC3Q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_sF3Wu5XU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void sTabread_YursPVP1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_NSm8z2uJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KLL4hGQm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Lyvjzkht_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_1BhTkVWj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_VljxZcGX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_wasloP4a_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_o6175oon_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cqjWYeXD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_YnBH7GpI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Jztpd3N3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_LVqOJBaO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Wy3PeJ6T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_4f0uI6ns_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_FDwRtfSh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_YtboBCav_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_cX3CSIKX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_1xC22qgw_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_1QSrfW0l_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_yoANTlmv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_AJMYLtbH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gLUsWXVu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_NLJQ1Lio_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_J7sSopu2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_CqjvXgZ4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_OPQEqCc7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Zmfn4Thx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_eHgT5O95_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_JL1wIO74_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_LAEf7zJx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WEf61pOO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_RUmvZ4f1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rS6dJH0M_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_yiWFOsJ7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xpYxlibK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_wXThpdCs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_QchiwOHm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_EiG8OnQ3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_w50XZCAe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6gFJRQG3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_jiny781H_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6ibDgD3I_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_dWRi7L0D_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_bpLLwQyM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_y3Ks91TE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_gIjEhzY7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_CegCF8J2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_emS35dtd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_fbQOenbt_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_T7RRm1fY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_0ILI2K5M_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_VyKDZwhs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_GFEPE95E_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_nQHsCv2n_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_XfYYg44l_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4uTycqq8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9R846fy2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_FX4w6qLN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_jz5WN6jW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_g52FD0VO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_QFYgMNCc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_PDhm312h_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Pr0CrA1c_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_z40M2AR7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_MY5GRjVV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_nSTkqnMf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Y4YcGSKI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_V4pnRL0v_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rymVOIZ3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_vnmkYrNY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_KIN4LNn7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_TQJPoo9N_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_vIQR1j7L_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xS3kda3e_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_a66NgyI8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ghKOtnMG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5Qhb5lUM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_AcV6tNNL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_q4mM0Fbe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_exKNTHDG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_FKvDrMOY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_y9UYdecU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_0LVM2v8v_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_pssOYrr4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_V4Dlnmhz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_72ZSIW28_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_cd3N1RCF_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_lSF8FeBd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_Jn8DpTrG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_oIAg5bPS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OKRRmx9P_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_1lRMwbYO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_9ELzJnoA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_7wbgHzXw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_c9dqEjfz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_f8IrrG2y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_x1u7QXAu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_RRCmZ1F3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_jwPqNSyk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_NRN3M224_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_9rklVAi3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_Ub9gekAh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_H2bY8pKI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_fAzwkZqD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_6T0pVlJd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_KiS4bBTD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_CTRJ99x9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_MvMHIZQF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_JmNh316W_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_6qXRa3GI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_zOkwRjrj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_MucfsoHt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_PtHSq25V_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DWirRziK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Vy8vPkGJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_S3Tw5nnT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_AjEssTCL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_6F6hBUiI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_jAFYF26y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_u0qecKUB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_8T9Lp2kN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_AOO0hYlz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_fwIbhgAr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_nUOnGJNS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_54LRdGIn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1WcJ3jEx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_klXewiY2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8DOJj3Lp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_vxGZ7BuT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_XOxNKtDY_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_iTtamC6t_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_UAzaF7Uy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_RXwNOozZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_YXtVZYvx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_g0Qqd213_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_GcCX8z8g_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_5y4aWLWu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_miUzOvcs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kCQjZqLL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_AJ9JvHXJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Rc5U6NxU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Ftlo3WTM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_K6meOsRA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_H7b7PKik_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Ald8luI4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_7W6B2vGI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3NNmYuvJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_HsAygfYm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_dkjYmqxd_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_SBRuZJEy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_EdQFlfMH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_NElCpblh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_Et7AGMDl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_AZ4FGC4L_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabhead_OvZQC9Gi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_UOAWuRxQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_LHn7k8pR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_gzCG7ylf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_WB5yLmHx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_m4Nlcez9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void sTabread_U4T6nfp9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_p55R9fuk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_v7Zom7fu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bzBbaaTf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_ALEoGy5V_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_7jYTRYvN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_IVMNMAos_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_pe2hTTjl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_39iW8Ohz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_bcwJXDVx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_w03jQXFs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_NXypHPyy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ACwZCcHW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_p3NVSK5A_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_61kI3JCY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_3bAGStkX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_w5Z9lhD8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_beZhBLWJ_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_kgOTILqL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_4a2NYJ2e_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_oM5S2aJ4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Ee7X4Adm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_juaqczjS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_UKqyQlVy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_k3TEi4QI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_erI7a1p7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_yP0Y8xnG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_3OeJ37Ow_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_4EY8vWob_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_jP0sx8mx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_SGy33OKE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Lv5ZIZHm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_RmFQZlGQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1SGRLXVJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_D3m8XO5s_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_JvvkkyKh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Thwd10OR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_pKR0Z6dt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_3FdSR5ZC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ZpdDIYyx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_kFFkS7Aa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_jiGus1Cj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_vm1sBByU_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_INidkFlv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_SzCrB0iD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_A8QSVJi0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_QlD9hx3A_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_XNuSbcpg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DtSvgxmg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_dlbwRmYT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_aJyQk1Y4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_UG8M8hdq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_0Ian9Nos_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_l7Dlf2Du_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gLrBnO67_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_fpJtpY2y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HiVfoxfX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_lXbSOxUM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_JLCkEeAY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6vrHt5zh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ftl0VpAb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MHsX9Z6b_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bJoM7oGl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_P269yGmL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WgLGUhIl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_XwZuxGJC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_oppWUIjB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_thMbhhEQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_sKRKJ2pi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_s6ePdRTd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Xrvx2lAK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_pyMly1PH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_zHcbFOUd_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_Nj3mz8b1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_qoM9SypF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_fBR6K1gy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_L9VIqt17_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ahs0IZec_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_u4enbaNe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_zp0jocVa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_vrEYoHRO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_a64tdNbs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BPZX3tRz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_CyzYapUA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zum3vKax_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_7hGzaeqN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_QFsGctM8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_EmNIHsAY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Iqh9vfTj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_dVAMeAQm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KrI7DIkM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KxrlVmFn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_dPQvq6XS_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_p5Tgl76A;
  SignalLine sLine_lE765kvS;
  SignalPhasor sPhasor_zJriyjmR;
  SignalLine sLine_h7mjnjXM;
  SignalTabread sTabread_LfyWcIfJ;
  SignalPhasor sPhasor_3kM10C70;
  SignalPhasor sPhasor_pEc1mTv2;
  SignalLine sLine_Z4ZJAREW;
  SignalPhasor sPhasor_2bugMkWS;
  SignalTabread sTabread_U4T6nfp9;
  SignalPhasor sPhasor_6k4QUyC9;
  SignalLine sLine_UzsHDhYq;
  SignalRPole sRPole_YqSwF43r;
  SignalTabwrite sTabwrite_Y6fiqUTx;
  SignalBiquad_k sBiquad_k_zEAHz4hb;
  SignalLine sLine_xTWoxp5n;
  SignalTabhead sTabhead_CaWg4r82;
  SignalTabread sTabread_27UM8P4d;
  SignalTabread sTabread_HdxpFTTk;
  SignalLine sLine_i9H0kCAo;
  SignalLine sLine_mybgC5bn;
  SignalTabhead sTabhead_TvPkfyi4;
  SignalTabread sTabread_d1q6e24C;
  SignalTabread sTabread_JpDIdtKs;
  SignalLine sLine_yikKq08A;
  SignalTabwrite sTabwrite_Qs5PzVhA;
  SignalTabwrite sTabwrite_TbVvJ6kn;
  SignalPhasor sPhasor_JjcpztXJ;
  SignalTabread sTabread_YursPVP1;
  SignalPhasor sPhasor_3aKv930E;
  SignalLine sLine_vzCVj8E3;
  SignalRPole sRPole_zzpzvYdp;
  SignalTabwrite sTabwrite_YS7RaK5T;
  ControlBinop cBinop_AuJw2oek;
  ControlBinop cBinop_019JhJyD;
  ControlBinop cBinop_3P5Y59Ys;
  ControlBinop cBinop_NvNZfntG;
  ControlBinop cBinop_JMeov7LZ;
  ControlRandom cRandom_W51xktNs;
  ControlSlice cSlice_Q8uSaD8A;
  SignalVari sVari_mdF9j3v0;
  ControlTabhead cTabhead_P3uNalpp;
  ControlVar cVar_wHkXSSjw;
  ControlDelay cDelay_4l4zmC3Q;
  ControlDelay cDelay_sF3Wu5XU;
  ControlBinop cBinop_NSm8z2uJ;
  ControlBinop cBinop_KLL4hGQm;
  ControlBinop cBinop_Lyvjzkht;
  ControlBinop cBinop_cqjWYeXD;
  ControlBinop cBinop_Jztpd3N3;
  ControlBinop cBinop_LVqOJBaO;
  ControlDelay cDelay_YtboBCav;
  ControlDelay cDelay_cX3CSIKX;
  ControlBinop cBinop_1QSrfW0l;
  HvTable hTable_yoANTlmv;
  ControlBinop cBinop_gLUsWXVu;
  ControlVar cVar_Zmfn4Thx;
  ControlBinop cBinop_LAEf7zJx;
  ControlBinop cBinop_WEf61pOO;
  SignalVarf sVarf_C2qccrfG;
  ControlBinop cBinop_rS6dJH0M;
  ControlBinop cBinop_yiWFOsJ7;
  ControlBinop cBinop_xpYxlibK;
  SignalVarf sVarf_SLBa4PGw;
  ControlBinop cBinop_wXThpdCs;
  ControlBinop cBinop_6gFJRQG3;
  ControlBinop cBinop_6ibDgD3I;
  ControlPack cPack_dWRi7L0D;
  ControlSlice cSlice_bpLLwQyM;
  ControlSlice cSlice_y3Ks91TE;
  ControlSlice cSlice_gIjEhzY7;
  ControlSlice cSlice_CegCF8J2;
  ControlSlice cSlice_emS35dtd;
  SignalVarf sVarf_g6rj8uKb;
  ControlBinop cBinop_4uTycqq8;
  ControlBinop cBinop_9R846fy2;
  SignalVarf sVarf_vqoP0jaB;
  SignalVarf sVarf_AFgoUlSM;
  ControlPack cPack_QFYgMNCc;
  ControlPack cPack_PDhm312h;
  ControlVar cVar_MY5GRjVV;
  ControlBinop cBinop_Y4YcGSKI;
  ControlBinop cBinop_rymVOIZ3;
  SignalVarf sVarf_PPxAvq4z;
  SignalVarf sVarf_J3cCL6hE;
  SignalVarf sVarf_D86feJP3;
  ControlVar cVar_TQJPoo9N;
  ControlBinop cBinop_xS3kda3e;
  ControlBinop cBinop_ghKOtnMG;
  SignalVarf sVarf_NZR5JOXk;
  SignalVarf sVarf_apijj2Kq;
  SignalVarf sVarf_9nTIKcxH;
  ControlBinop cBinop_5Qhb5lUM;
  ControlBinop cBinop_AcV6tNNL;
  ControlBinop cBinop_q4mM0Fbe;
  ControlBinop cBinop_exKNTHDG;
  ControlBinop cBinop_FKvDrMOY;
  ControlBinop cBinop_y9UYdecU;
  ControlDelay cDelay_V4Dlnmhz;
  ControlDelay cDelay_72ZSIW28;
  ControlBinop cBinop_lSF8FeBd;
  HvTable hTable_Jn8DpTrG;
  ControlBinop cBinop_OKRRmx9P;
  ControlDelay cDelay_RRCmZ1F3;
  ControlDelay cDelay_jwPqNSyk;
  ControlBinop cBinop_9rklVAi3;
  HvTable hTable_Ub9gekAh;
  ControlBinop cBinop_fAzwkZqD;
  ControlBinop cBinop_PtHSq25V;
  ControlBinop cBinop_DWirRziK;
  ControlVar cVar_6F6hBUiI;
  ControlBinop cBinop_1WcJ3jEx;
  ControlBinop cBinop_klXewiY2;
  ControlBinop cBinop_8DOJj3Lp;
  ControlBinop cBinop_iTtamC6t;
  ControlRandom cRandom_RXwNOozZ;
  ControlSlice cSlice_YXtVZYvx;
  ControlVar cVar_g0Qqd213;
  ControlDelay cDelay_GcCX8z8g;
  ControlBinop cBinop_kCQjZqLL;
  ControlBinop cBinop_AJ9JvHXJ;
  ControlBinop cBinop_Rc5U6NxU;
  ControlBinop cBinop_K6meOsRA;
  ControlBinop cBinop_H7b7PKik;
  ControlBinop cBinop_Ald8luI4;
  ControlBinop cBinop_7W6B2vGI;
  ControlBinop cBinop_3NNmYuvJ;
  ControlBinop cBinop_SBRuZJEy;
  ControlRandom cRandom_NElCpblh;
  ControlSlice cSlice_Et7AGMDl;
  SignalVari sVari_w70QM8dB;
  ControlTabhead cTabhead_OvZQC9Gi;
  ControlVar cVar_gzCG7ylf;
  ControlDelay cDelay_WB5yLmHx;
  ControlDelay cDelay_m4Nlcez9;
  ControlBinop cBinop_p55R9fuk;
  ControlBinop cBinop_v7Zom7fu;
  ControlBinop cBinop_bzBbaaTf;
  ControlBinop cBinop_39iW8Ohz;
  ControlBinop cBinop_w03jQXFs;
  ControlBinop cBinop_NXypHPyy;
  ControlDelay cDelay_3bAGStkX;
  ControlDelay cDelay_w5Z9lhD8;
  ControlBinop cBinop_kgOTILqL;
  HvTable hTable_4a2NYJ2e;
  ControlBinop cBinop_Ee7X4Adm;
  ControlVar cVar_yP0Y8xnG;
  ControlBinop cBinop_jP0sx8mx;
  ControlBinop cBinop_SGy33OKE;
  SignalVarf sVarf_isWowbsF;
  ControlBinop cBinop_RmFQZlGQ;
  ControlBinop cBinop_1SGRLXVJ;
  ControlBinop cBinop_D3m8XO5s;
  SignalVarf sVarf_NdOw1akm;
  ControlBinop cBinop_JvvkkyKh;
  ControlBinop cBinop_ZpdDIYyx;
  ControlBinop cBinop_jiGus1Cj;
  ControlBinop cBinop_INidkFlv;
  ControlRandom cRandom_A8QSVJi0;
  ControlSlice cSlice_QlD9hx3A;
  SignalVari sVari_xUTVezR4;
  ControlVar cVar_aJyQk1Y4;
  ControlVar cVar_UG8M8hdq;
  ControlBinop cBinop_l7Dlf2Du;
  ControlBinop cBinop_gLrBnO67;
  ControlBinop cBinop_fpJtpY2y;
  ControlBinop cBinop_HiVfoxfX;
  ControlBinop cBinop_lXbSOxUM;
  ControlBinop cBinop_JLCkEeAY;
  ControlBinop cBinop_6vrHt5zh;
  ControlBinop cBinop_MHsX9Z6b;
  ControlBinop cBinop_bJoM7oGl;
  ControlBinop cBinop_P269yGmL;
  ControlBinop cBinop_WgLGUhIl;
  ControlBinop cBinop_XwZuxGJC;
  ControlBinop cBinop_oppWUIjB;
  ControlBinop cBinop_thMbhhEQ;
  ControlBinop cBinop_sKRKJ2pi;
  ControlBinop cBinop_s6ePdRTd;
  ControlBinop cBinop_Xrvx2lAK;
  HvTable hTable_pyMly1PH;
  ControlVar cVar_Nj3mz8b1;
  ControlSlice cSlice_L9VIqt17;
  ControlBinop cBinop_ahs0IZec;
  SignalVarf sVarf_BdD58aQC;
  ControlVar cVar_u4enbaNe;
  ControlDelay cDelay_zp0jocVa;
  ControlBinop cBinop_BPZX3tRz;
  ControlBinop cBinop_CyzYapUA;
  ControlBinop cBinop_zum3vKax;
  ControlBinop cBinop_QFsGctM8;
  ControlBinop cBinop_dVAMeAQm;
  ControlBinop cBinop_KrI7DIkM;
  ControlBinop cBinop_KxrlVmFn;
};

#endif // _HEAVY_CONTEXT_PROG_HPP_
