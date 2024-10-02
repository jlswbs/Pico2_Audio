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
#include "HvControlBinop.h"
#include "HvSignalTabread.h"
#include "HvSignalRPole.h"
#include "HvTable.h"
#include "HvControlCast.h"
#include "HvSignalDel1.h"
#include "HvSignalPhasor.h"
#include "HvControlSlice.h"
#include "HvControlVar.h"
#include "HvMath.h"
#include "HvControlUnop.h"
#include "HvSignalVar.h"
#include "HvControlSystem.h"
#include "HvControlDelay.h"
#include "HvSignalSamphold.h"
#include "HvControlRandom.h"

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
  static void hTable_lvJbLiGL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_VBjESlg5_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_YaIkuKVV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_PDSrBreC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_WK1LRdV0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_MX5DLi8q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_NU8roKf2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_MxdTsktK_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_BEJmarMh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_hExdgjag_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_6kG00Hzz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_GdX0firh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6YAYIL1p_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_faVCYyc0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_CuahfNpZ_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_IZBuS5Kf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_kNbQUtWM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_WiNXG8Q4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_oZsi7xCi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ug2U7Naw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_zfV4Yl6k_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_pPkrVwXr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_8WwP8MZX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_waE3m75T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_0dkCVsIr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_cuySbm0H_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_odVcnI2w_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_YkAP3oUi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_pZFEcXuc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_FShT9K55_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_sGRDLRcw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_uFfOvOSb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_gQkUTANm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_0IQsOwuZ_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_MV3BFikQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_D2YxX1ra_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_dfwL5bVo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_Zk4iZOTZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_hPM2L4C5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_twzLPtiy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gdzFEccd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xgbUa11P_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_RWvARcPF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_WtrOixC9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_eoTeUCkC_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_wcXbxj8V_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_qTkABywD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_Vw1XQNFj_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_sbV92jll_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_E3gE71Xh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_uLnoWaDo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_sb2HAKYm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_mZwPyW2N_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_1sUARX9e_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_cIwx2B7F_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_OlJ7f6UV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_6lcNjJoK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_ipNHKD7b_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_g8JThVX8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_n4Sn2zkG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_to0uH418_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Ae9dzJc7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_SEZykTuc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_m2VT0X0B_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_5qP9X8jK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_bWfcA5I9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_hh8Pz5Gn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_63XhKRCB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_chZqhCc2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bXoGWi0h_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_zBo1b8lb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_plOchsw4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_EnpLZ8kp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_xYO1EKyB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_2oleM7A7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ZMEek87I_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BUHgxqrL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_OARDUQkq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_IV0XQoEP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_14G1QKfN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_gKD6Fwgj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_7D2GXMJ1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0XIYLLpI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_SGHUALRU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_L3geQkql_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_QSkwNlvr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Fwhqcvup_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_HaFVcqqH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_U6DCEYH7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_YGC2Z8De_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ZzBL8our_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_FUifdNJl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Z26trWiG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_q33weLCt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_CEwzv5dT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_CFWadtW7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_j11l8kFZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bs7AAOK4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vYsiadxz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_zCXyI1vE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_vX7XVJDM_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_nr4id9Wf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_PQWdJCcK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_rUutPVrn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_jj9itnUJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VKyfx96y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_yJ7GgO2h_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_WoHRvnPO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_Ol2AgiGD_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_xDO5wPDq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_HW5lEsMu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_8qSV018s_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_xkPnU8Xx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ZK44swLH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_KT8ksvDe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Kn7b3n1D_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3R6FZwjg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6vwESt0s_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Tx2xkCv1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_F09TEjqi_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_ZDpKFGn0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_cOAPmYfh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_5Tchwy3f_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_zDHrTlO0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_trX1ynUL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_haFlXsHu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_pLrAy02f_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_k6FZTyub_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_WZX5zwpM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_qZ7Mg9jw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_pdY144oz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Bq2Ko4ST_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_lDElroan_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_cS62Lsrb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2O34A7rA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_iPDvRkfT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1LbxG2C7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_CKKt3Axx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KCX0V5zy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_PamuUXHw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_RigS9nG9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_FLZkeIhC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vRIjZJuj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_yhjJYd5V_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cZksxt5C_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_nhUuPiOh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_UtBKOuHD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_QWc1RyI6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_XcmpDI8S_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_4phI5lPW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_vWOpaQEF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1GeXzg4N_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_vgIoIsUX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_TGipII8k_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_nHxlVZLP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ln6IaUHD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_X4GIGhCD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_QHSZojX2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Tlw7bOn8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_VWVAkJyn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_pBfRswet_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_bkEQhq1P_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_cCOFNU5o_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ujjKfFsq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_A6EOz2MX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_oSR12xZO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_8AXE2xed_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_sdqd0jNH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_uNAE7spE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_VUoZ7QBV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_688RcFKu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_frCvKzSn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Ys734ZHK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_m5TNIf9J_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ofIQAJ6V_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_nu8dZGkE_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_EcQdOxSB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_nO7DHNH5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_rvXqYZGM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_C0RjP20E_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_EUQ3ezXH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_XdvoNVIK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_EGVu9oSr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3wf95yFy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_h2PMVSYP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_qX8huQk5_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_t3Rud7Dp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_ikQMXYqq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_vyt9MsA0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_WeBnhHFW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_pdVQEPJ0_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_TkisLvpK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_HaBDkk6h_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_Bw9kf9uO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_QBPtDShY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_cygrhSvI_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_MKRngERP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_S8Tgv1EJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_9YCMRWL7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_KYQrbbAF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_PylUBsv7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ZwN5teSY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_maXCof0a_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_awdV9gJ0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_4nODoDr7_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_C753b4b4;
  SignalPhasor sPhasor_QUCVXl5s;
  SignalTabread sTabread_dcQFDX0O;
  SignalRPole sRPole_UPtwyIgg;
  SignalPhasor sPhasor_M587ym8p;
  SignalDel1 sDel1_wfZtSdd0;
  SignalSamphold sSamphold_FPQwX9nO;
  SignalDel1 sDel1_ry3DWd1S;
  SignalSamphold sSamphold_PmqKZGcL;
  SignalPhasor sPhasor_PLet9XGU;
  SignalPhasor sPhasor_FMZxZoYt;
  SignalTabread sTabread_8LzTb8Il;
  SignalPhasor sPhasor_sNHjiXuu;
  SignalPhasor sPhasor_CjRV26IM;
  SignalPhasor sPhasor_IVa3auyZ;
  SignalTabread sTabread_liNiT6Dt;
  SignalRPole sRPole_5cgsYbKQ;
  SignalTabread sTabread_71OqpAPm;
  SignalPhasor sPhasor_IzIVOOY7;
  HvTable hTable_lvJbLiGL;
  ControlBinop cBinop_YaIkuKVV;
  ControlRandom cRandom_WK1LRdV0;
  ControlSlice cSlice_MX5DLi8q;
  SignalVari sVari_UzLx6anC;
  ControlVar cVar_BEJmarMh;
  ControlSlice cSlice_GdX0firh;
  ControlBinop cBinop_6YAYIL1p;
  SignalVarf sVarf_fpaBEcU4;
  HvTable hTable_faVCYyc0;
  ControlVar cVar_IZBuS5Kf;
  ControlSlice cSlice_oZsi7xCi;
  ControlBinop cBinop_ug2U7Naw;
  SignalVarf sVarf_jFULZl59;
  ControlVar cVar_zfV4Yl6k;
  ControlBinop cBinop_pPkrVwXr;
  ControlVar cVar_8WwP8MZX;
  ControlVar cVar_waE3m75T;
  ControlVar cVar_0dkCVsIr;
  ControlVar cVar_odVcnI2w;
  ControlSlice cSlice_FShT9K55;
  ControlBinop cBinop_sGRDLRcw;
  SignalVarf sVarf_Dh5FMze2;
  ControlDelay cDelay_MV3BFikQ;
  ControlVar cVar_hPM2L4C5;
  ControlBinop cBinop_gdzFEccd;
  ControlBinop cBinop_xgbUa11P;
  ControlBinop cBinop_RWvARcPF;
  ControlVar cVar_WtrOixC9;
  ControlSlice cSlice_sbV92jll;
  ControlSlice cSlice_E3gE71Xh;
  ControlVar cVar_uLnoWaDo;
  ControlVar cVar_sb2HAKYm;
  ControlVar cVar_cIwx2B7F;
  ControlVar cVar_OlJ7f6UV;
  ControlVar cVar_6lcNjJoK;
  ControlSlice cSlice_ipNHKD7b;
  ControlSlice cSlice_g8JThVX8;
  ControlBinop cBinop_n4Sn2zkG;
  ControlBinop cBinop_to0uH418;
  ControlBinop cBinop_Ae9dzJc7;
  ControlBinop cBinop_SEZykTuc;
  ControlBinop cBinop_m2VT0X0B;
  ControlBinop cBinop_hh8Pz5Gn;
  ControlBinop cBinop_63XhKRCB;
  ControlBinop cBinop_chZqhCc2;
  ControlBinop cBinop_bXoGWi0h;
  ControlBinop cBinop_BUHgxqrL;
  ControlBinop cBinop_0XIYLLpI;
  ControlVar cVar_HaFVcqqH;
  ControlVar cVar_U6DCEYH7;
  ControlVar cVar_YGC2Z8De;
  ControlBinop cBinop_Z26trWiG;
  ControlBinop cBinop_q33weLCt;
  SignalVarf sVarf_WhHaMB6w;
  ControlBinop cBinop_CFWadtW7;
  ControlBinop cBinop_j11l8kFZ;
  ControlBinop cBinop_bs7AAOK4;
  SignalVarf sVarf_ig3w0C6R;
  ControlBinop cBinop_vYsiadxz;
  ControlVar cVar_nr4id9Wf;
  ControlSlice cSlice_jj9itnUJ;
  ControlBinop cBinop_VKyfx96y;
  SignalVarf sVarf_zQb0SQUu;
  ControlDelay cDelay_xDO5wPDq;
  ControlVar cVar_ZK44swLH;
  ControlBinop cBinop_Kn7b3n1D;
  ControlBinop cBinop_3R6FZwjg;
  ControlBinop cBinop_6vwESt0s;
  ControlVar cVar_Tx2xkCv1;
  ControlSlice cSlice_zDHrTlO0;
  ControlSlice cSlice_trX1ynUL;
  ControlVar cVar_haFlXsHu;
  ControlVar cVar_pLrAy02f;
  ControlVar cVar_qZ7Mg9jw;
  ControlVar cVar_pdY144oz;
  ControlVar cVar_Bq2Ko4ST;
  ControlSlice cSlice_lDElroan;
  ControlSlice cSlice_cS62Lsrb;
  ControlBinop cBinop_2O34A7rA;
  ControlBinop cBinop_iPDvRkfT;
  ControlBinop cBinop_1LbxG2C7;
  ControlBinop cBinop_CKKt3Axx;
  ControlBinop cBinop_KCX0V5zy;
  ControlBinop cBinop_FLZkeIhC;
  ControlBinop cBinop_vRIjZJuj;
  ControlBinop cBinop_yhjJYd5V;
  ControlBinop cBinop_cZksxt5C;
  ControlBinop cBinop_1GeXzg4N;
  ControlBinop cBinop_QHSZojX2;
  ControlVar cVar_cCOFNU5o;
  ControlVar cVar_ujjKfFsq;
  ControlVar cVar_A6EOz2MX;
  ControlBinop cBinop_sdqd0jNH;
  ControlBinop cBinop_uNAE7spE;
  SignalVarf sVarf_fODK2IQY;
  ControlBinop cBinop_688RcFKu;
  ControlBinop cBinop_frCvKzSn;
  ControlBinop cBinop_Ys734ZHK;
  SignalVarf sVarf_X643wL3c;
  ControlBinop cBinop_m5TNIf9J;
  SignalVarf sVarf_pO2tFV3G;
  SignalVarf sVarf_KPeCqkss;
  ControlDelay cDelay_EcQdOxSB;
  ControlVar cVar_EUQ3ezXH;
  ControlBinop cBinop_EGVu9oSr;
  ControlBinop cBinop_3wf95yFy;
  ControlBinop cBinop_h2PMVSYP;
  ControlBinop cBinop_t3Rud7Dp;
  ControlRandom cRandom_vyt9MsA0;
  ControlSlice cSlice_WeBnhHFW;
  ControlBinop cBinop_TkisLvpK;
  ControlRandom cRandom_Bw9kf9uO;
  ControlSlice cSlice_QBPtDShY;
  ControlBinop cBinop_MKRngERP;
  ControlRandom cRandom_9YCMRWL7;
  ControlSlice cSlice_KYQrbbAF;
  ControlBinop cBinop_PylUBsv7;
  ControlBinop cBinop_ZwN5teSY;
  ControlBinop cBinop_maXCof0a;
  ControlBinop cBinop_awdV9gJ0;
  SignalVarf sVarf_FWYh9Vrk;
  SignalVarf sVarf_KDIYTzno;
  SignalVarf sVarf_kFJd40nN;
  SignalVarf sVarf_Gv263fd5;
};

#endif // _HEAVY_CONTEXT_PROG_HPP_
