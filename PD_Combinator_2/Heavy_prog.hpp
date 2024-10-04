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
#include "HvSignalTabread.h"
#include "HvControlRandom.h"
#include "HvControlIf.h"
#include "HvControlSlice.h"
#include "HvSignalSamphold.h"
#include "HvControlPack.h"
#include "HvSignalVar.h"
#include "HvTable.h"
#include "HvControlCast.h"
#include "HvSignalTabwrite.h"
#include "HvMath.h"
#include "HvControlBinop.h"
#include "HvSignalPhasor.h"
#include "HvControlDelay.h"
#include "HvSignalRPole.h"
#include "HvSignalLine.h"
#include "HvControlSystem.h"
#include "HvControlVar.h"
#include "HvSignalDel1.h"
#include "HvControlUnop.h"

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
  static void cVar_W8j6gANJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_rTUHUIMl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8ZLhFHfI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_wxuOCmOO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_ivHa8HMy_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_NrbziHn1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_is4A4rCS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_7lcCkl59_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_eB7QXUHP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_A4rjOfuM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_G2xEIGxz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_CWmYWInk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_rxU4oAhG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_oIdO5Y1r_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_1BLFFInO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_jGggqWEV_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_7fX6IAZj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_KrcZyIhU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_0nvrGLLS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_49hEj0nq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_418HkmhO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DQxJcYTR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_wYzxqDRq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ih44YR3v_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_NrLSGoyx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_tgokL91T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Dxrso7ah_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_wdmaXtfD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_oJGSsNrS_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_3v6GfgXX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_avplGojE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_YlUigL53_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_EPIjW80u_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_gbQfcyAx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_okIpauTa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_yGQmhAUQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_fh2yWSHm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_CdtdvnZZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_wGwzRg11_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_SN3HcuRY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_5sXhimTc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_YWJ6GYwB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_y8boNSEw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_S6nIRUTa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_eWYAbQim_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_1OLBWRoH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_K6kJknxn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_qthYvSxh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_2zmfCaTE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_u1psvoS3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_1KJD707S_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_noSiBcjX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_AUKnAoyi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_bDKyf99O_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ZX6e4YKU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_jeh2kG9F_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_tgjvlkil_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_8FilOoYy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_hErxSlMQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_HmbKGmB3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_TJEqEWdP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_AxbCM1YZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_7BP832xf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_RjPx4TJE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_jHchOYOK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_wYhgGbc9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VpnPBS1I_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_TQYKwxlk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_nDfjEbp5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_JsuCNCri_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_C59JIOWH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_0sWSdSc4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_41HS0QRV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_RXlcJnYm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_NoVWSYbR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_ryCBDPlV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_LW7Vmdb2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_KGnpojq6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_oyiD1N6F_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_dkQhA6Tv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_TdLWqMrb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_oEfDmSFs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_G8QvOWT3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HzYwWLK8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_iqeuYFAD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YxYYt6sk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8tr8xaJ9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gnaHYos3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5qQ6pQMb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_eMNQkMGS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VJbO38i3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OFWHTa32_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_qf0XwH9p_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_H14ZMIf2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_481VmPEH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_upIOsx9V_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_nplNJKpn_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_aRuz6xuF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_UBsTbrIQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_5j2BiW00_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0Y43JFbX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_TMHIXyXL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_2JLGcnj2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_BYELWbPH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_KvqamoJj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_3uKYPcPz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_lwkhaFHX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_ujVbuQGX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_fIRsBMxH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_rHTr4hF9_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_IwUMM7Ta_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_ShYD98Wr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ejnbeKLK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Uf4sPWt3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_jv09E43O_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_KRahda0m_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_yKkoRwqk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_LC9NdvTM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_LWDlQTap_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_X2nkUyOV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_HmXi95qg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_tQe8ojDL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_FJI5r2Mt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ICissggF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ShkaDX72_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_hN4ezQIN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_snoB7RpS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_3m8eWnpA_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_Z43Yy3z3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_uhfSEOJ7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_P3JZlb9J_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_6ojTtIS5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Ci5yaceL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_uwg8WLsO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cJIH0466_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_NjEMYDrE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MjzwVz53_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_Fela7A4P_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_tUE9Vrvh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_aw4kWpNC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_X7ZZMgde_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_YAajXtAC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5QBgsSwu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_sd0PCCPy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ZkhmpYAA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_fFuoIuVL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_X1bevG0c_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_GscrLBmC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DqMJ6QQs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VXcc5LoE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_dOM3lYnW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_mNrVCgI7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_K9G40gze_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ROfQQtRN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_HxWJjsrA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Cgn3DMlv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_mxssSgvc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_8CBjIrDJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_cBX6Pkex_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_AS7ppurV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_fVhk0WM3_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_IzEcvL1P_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_ENsxRd88_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_riDt1OxU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_Hh8tJ2mL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_iFJyhGd0_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_L0nuVbEa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_wlaYOeGP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_3NbIFw3K_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_DOl6QpC4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_orGuVV6s_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_9r8xC5TF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_eitDqaRx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_FWqQ2BhS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_3yzU9g5T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ww87yDZ6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_63RFJIMJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_9LHovrwg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_1N39z5ec_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_bYCY9inA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_JBXaT1wn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_f5Ucll1k_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_WwFIQrLt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ZHBPwXxr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_33XCdujB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_q8XERXLC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_q6r1dqk9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_u8DyI0Ua_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_O8RhuduG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9ipRZZ9i_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_JTjlRUCU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6g5v7mJZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_d5YUlhye_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_X7LF0Dyq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9ghPSPVh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8whutfFA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2jGNQNe1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_q4qHLIKj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_y3Bnfkl1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_CFbqqqRw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_DHJPWAOL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Jvpiho6N_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_qCrSdh3V_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_r53NBIYP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_H4lIUZRk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MojyC66V_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_EiN4FkTm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_9tOt6x61_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_ATcY1Td7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_SNdBDiR9_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_jq09hdfN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_A7eJFRBj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_PznM48Jl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_RbYDYIbW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_KisYa0eX_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_x3QGeGUl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_vPF3jgPM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Zva4iDlX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_p9Ou7eUq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_iDsTIokd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_pEe3cUpm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_UQBit3Ow_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Sr30jzln_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_rcQhsGdP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_MxFcjBBV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_iLfqxJez_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_NxOHyMcF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_A9f8PmPA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_K6ZyhK07_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_WVJxo91V_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_HxOMnV7f_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_0ndpx8dr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_SoXwo7YS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_dsNeX709_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_9iGCnCQP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_jjIogc5O_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_CwpCYNsH_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_04RN7EFO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_xD9VY3dV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_v1yoq5U6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_ZQlXBqPn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_ewCaq7Qy_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_slNZ0mAd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_Lh3d1fBV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_YPRHUkkH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_M7rAMhW3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_l0oCMhFc_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_Shbk4Leg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_kOWcIDz9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_7tj1Zfu5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ooMGtvvF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Sjl3IabK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_smxDCpVT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_JUtWU4XH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_nWyJ44jd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_7H9UG31T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_PF5Mcfpt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_EsuFEUXQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_cP5kraob_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_DEJ2utTd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_tRaeAaJW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ObiDlhQ5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_NAIJeotF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Jre201LV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_UFqOczpK_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_bm75oD2q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_sLLaYteF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_asg4tMMY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_SQfSVFH7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_40CKhTId_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_mirnxlBe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0ECfXXAT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Nx2JqE5g_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_MlD2gUGZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_CqtpddWc_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalLine sLine_nJfYMCMC;
  SignalPhasor sPhasor_hkABiTEE;
  SignalLine sLine_EWkWwWZ6;
  SignalPhasor sPhasor_8iIOs0GG;
  SignalLine sLine_Z6DVMeGp;
  SignalPhasor sPhasor_PVOBCXNN;
  SignalPhasor sPhasor_w6bugCxu;
  SignalLine sLine_Weo8l11X;
  SignalPhasor sPhasor_PAJLFf79;
  SignalDel1 sDel1_VTn5l1EK;
  SignalSamphold sSamphold_qYYwPwwj;
  SignalRPole sRPole_yF2T3zAp;
  SignalPhasor sPhasor_3KrGvG5f;
  SignalPhasor sPhasor_ai1Xzu2L;
  SignalLine sLine_UCZnggPO;
  SignalPhasor sPhasor_s3v42jCl;
  SignalPhasor sPhasor_G47Aclun;
  SignalPhasor sPhasor_vsYdDqND;
  SignalLine sLine_a5AmQPKu;
  SignalLine sLine_hAAHSc6j;
  SignalTabhead sTabhead_GMBUDSG3;
  SignalTabread sTabread_Ax5TchwI;
  SignalTabread sTabread_3GJ7jomA;
  SignalLine sLine_Bnj82DFC;
  SignalLine sLine_YVTMNqNi;
  SignalTabhead sTabhead_XW47bxAE;
  SignalTabread sTabread_3RAqMdWy;
  SignalTabread sTabread_4e2jX6dl;
  SignalLine sLine_nw3wEL0j;
  SignalTabwrite sTabwrite_bqH2eNDv;
  SignalTabwrite sTabwrite_PBlvOfaq;
  ControlVar cVar_W8j6gANJ;
  ControlVar cVar_rTUHUIMl;
  ControlBinop cBinop_8ZLhFHfI;
  ControlVar cVar_wxuOCmOO;
  ControlBinop cBinop_NrbziHn1;
  ControlRandom cRandom_7lcCkl59;
  ControlSlice cSlice_eB7QXUHP;
  ControlPack cPack_A4rjOfuM;
  ControlSlice cSlice_G2xEIGxz;
  ControlSlice cSlice_CWmYWInk;
  ControlSlice cSlice_rxU4oAhG;
  ControlSlice cSlice_oIdO5Y1r;
  ControlSlice cSlice_1BLFFInO;
  SignalVarf sVarf_q7wy3ygM;
  ControlBinop cBinop_wYzxqDRq;
  ControlBinop cBinop_ih44YR3v;
  SignalVarf sVarf_VjdvtlNC;
  SignalVarf sVarf_lNWAKkKx;
  ControlVar cVar_wdmaXtfD;
  ControlDelay cDelay_3v6GfgXX;
  ControlVar cVar_gbQfcyAx;
  ControlBinop cBinop_yGQmhAUQ;
  ControlBinop cBinop_fh2yWSHm;
  ControlBinop cBinop_CdtdvnZZ;
  ControlPack cPack_wGwzRg11;
  ControlSlice cSlice_SN3HcuRY;
  ControlSlice cSlice_5sXhimTc;
  ControlSlice cSlice_YWJ6GYwB;
  ControlSlice cSlice_y8boNSEw;
  ControlSlice cSlice_S6nIRUTa;
  SignalVarf sVarf_ZD1qa7Ff;
  ControlBinop cBinop_noSiBcjX;
  ControlBinop cBinop_AUKnAoyi;
  SignalVarf sVarf_e9Q3n8OA;
  SignalVarf sVarf_EgyP79ak;
  ControlVar cVar_tgjvlkil;
  ControlVar cVar_8FilOoYy;
  ControlVar cVar_hErxSlMQ;
  ControlVar cVar_HmbKGmB3;
  ControlVar cVar_TJEqEWdP;
  ControlBinop cBinop_RjPx4TJE;
  ControlBinop cBinop_jHchOYOK;
  SignalVarf sVarf_GD7gFKDc;
  ControlBinop cBinop_VpnPBS1I;
  ControlBinop cBinop_TQYKwxlk;
  ControlBinop cBinop_nDfjEbp5;
  SignalVarf sVarf_6p0GlcSf;
  ControlVar cVar_JsuCNCri;
  ControlPack cPack_C59JIOWH;
  ControlPack cPack_0sWSdSc4;
  ControlVar cVar_NoVWSYbR;
  ControlBinop cBinop_LW7Vmdb2;
  ControlBinop cBinop_oyiD1N6F;
  SignalVarf sVarf_f9H4Z7tY;
  SignalVarf sVarf_zVq9rX1c;
  SignalVarf sVarf_tEVox5qL;
  ControlVar cVar_oEfDmSFs;
  ControlBinop cBinop_HzYwWLK8;
  ControlBinop cBinop_YxYYt6sk;
  SignalVarf sVarf_1yUpDfUL;
  SignalVarf sVarf_cXycfIxT;
  SignalVarf sVarf_Pxc22I1a;
  ControlBinop cBinop_8tr8xaJ9;
  ControlBinop cBinop_gnaHYos3;
  ControlBinop cBinop_5qQ6pQMb;
  ControlBinop cBinop_eMNQkMGS;
  ControlBinop cBinop_VJbO38i3;
  ControlBinop cBinop_OFWHTa32;
  ControlDelay cDelay_481VmPEH;
  ControlDelay cDelay_upIOsx9V;
  ControlBinop cBinop_aRuz6xuF;
  HvTable hTable_UBsTbrIQ;
  ControlBinop cBinop_0Y43JFbX;
  ControlDelay cDelay_ujVbuQGX;
  ControlDelay cDelay_fIRsBMxH;
  ControlBinop cBinop_IwUMM7Ta;
  HvTable hTable_ShYD98Wr;
  ControlBinop cBinop_Uf4sPWt3;
  ControlBinop cBinop_FJI5r2Mt;
  ControlBinop cBinop_ICissggF;
  ControlDelay cDelay_Z43Yy3z3;
  ControlVar cVar_Ci5yaceL;
  ControlBinop cBinop_cJIH0466;
  ControlBinop cBinop_NjEMYDrE;
  ControlBinop cBinop_MjzwVz53;
  ControlBinop cBinop_tUE9Vrvh;
  ControlRandom cRandom_X7ZZMgde;
  ControlSlice cSlice_YAajXtAC;
  ControlBinop cBinop_5QBgsSwu;
  ControlBinop cBinop_sd0PCCPy;
  ControlBinop cBinop_ZkhmpYAA;
  ControlBinop cBinop_fFuoIuVL;
  SignalVarf sVarf_MRkzqZnL;
  ControlBinop cBinop_GscrLBmC;
  ControlBinop cBinop_DqMJ6QQs;
  ControlBinop cBinop_VXcc5LoE;
  ControlBinop cBinop_dOM3lYnW;
  ControlVar cVar_mNrVCgI7;
  ControlVar cVar_K9G40gze;
  ControlVar cVar_ROfQQtRN;
  ControlPack cPack_HxWJjsrA;
  ControlVar cVar_Cgn3DMlv;
  ControlVar cVar_mxssSgvc;
  ControlSlice cSlice_8CBjIrDJ;
  ControlSlice cSlice_cBX6Pkex;
  ControlSlice cSlice_AS7ppurV;
  ControlSlice cSlice_IzEcvL1P;
  ControlDelay cDelay_ENsxRd88;
  ControlDelay cDelay_riDt1OxU;
  ControlIf cIf_Hh8tJ2mL;
  ControlSlice cSlice_L0nuVbEa;
  ControlPack cPack_3yzU9g5T;
  SignalVarf sVarf_tFSl5x6N;
  ControlBinop cBinop_O8RhuduG;
  ControlBinop cBinop_9ipRZZ9i;
  ControlBinop cBinop_JTjlRUCU;
  ControlBinop cBinop_6g5v7mJZ;
  SignalVarf sVarf_61avkbsr;
  ControlBinop cBinop_X7LF0Dyq;
  ControlBinop cBinop_9ghPSPVh;
  ControlBinop cBinop_8whutfFA;
  ControlBinop cBinop_2jGNQNe1;
  ControlVar cVar_q4qHLIKj;
  ControlVar cVar_y3Bnfkl1;
  ControlPack cPack_CFbqqqRw;
  ControlVar cVar_DHJPWAOL;
  ControlVar cVar_Jvpiho6N;
  ControlVar cVar_qCrSdh3V;
  ControlVar cVar_r53NBIYP;
  ControlBinop cBinop_H4lIUZRk;
  ControlBinop cBinop_MojyC66V;
  ControlSlice cSlice_EiN4FkTm;
  ControlSlice cSlice_9tOt6x61;
  ControlSlice cSlice_ATcY1Td7;
  ControlSlice cSlice_jq09hdfN;
  ControlDelay cDelay_A7eJFRBj;
  ControlDelay cDelay_PznM48Jl;
  ControlIf cIf_RbYDYIbW;
  ControlSlice cSlice_x3QGeGUl;
  ControlPack cPack_rcQhsGdP;
  SignalVarf sVarf_H84vJuZl;
  SignalVarf sVarf_xiFM6HIu;
  SignalVarf sVarf_UF8WBoeW;
  ControlBinop cBinop_04RN7EFO;
  ControlRandom cRandom_v1yoq5U6;
  ControlSlice cSlice_ZQlXBqPn;
  ControlBinop cBinop_slNZ0mAd;
  ControlRandom cRandom_YPRHUkkH;
  ControlSlice cSlice_M7rAMhW3;
  ControlVar cVar_ooMGtvvF;
  ControlVar cVar_Sjl3IabK;
  ControlVar cVar_smxDCpVT;
  ControlVar cVar_JUtWU4XH;
  ControlBinop cBinop_PF5Mcfpt;
  SignalVarf sVarf_3Rrf6rlY;
  ControlBinop cBinop_bm75oD2q;
  ControlRandom cRandom_asg4tMMY;
  ControlSlice cSlice_SQfSVFH7;
  ControlBinop cBinop_40CKhTId;
  ControlBinop cBinop_mirnxlBe;
  ControlBinop cBinop_0ECfXXAT;
  ControlBinop cBinop_Nx2JqE5g;
};

#endif // _HEAVY_CONTEXT_PROG_HPP_
