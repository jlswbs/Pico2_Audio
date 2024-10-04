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
#include "HvSignalLine.h"
#include "HvControlBinop.h"
#include "HvControlDelay.h"
#include "HvSignalTabread.h"
#include "HvControlRandom.h"
#include "HvMath.h"
#include "HvControlSystem.h"
#include "HvControlPack.h"
#include "HvSignalVar.h"
#include "HvTable.h"
#include "HvControlCast.h"
#include "HvSignalPhasor.h"
#include "HvControlSlice.h"
#include "HvControlUnop.h"
#include "HvControlIf.h"
#include "HvControlVar.h"
#include "HvSignalTabwrite.h"

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
  static void cVar_Y1n269E8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_7jKV1DcY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_n4OeWMZO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_RzAe9niw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_GvYcLbDR_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_j9vrMWXL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_ZwUZRMuh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_rsb6Sc05_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_Vd93ILrK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_Hg7Sc7Wt_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_yn1A5HIv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_13b8X1TM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_RxnkBmy1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_Rds8anBq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_Aia28Ah1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_DWgU0SN0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_mKeYlGfs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_orf0b9WY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_lAgzzqqE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_DXV5o3Lw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_q4jPZyJg_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_KIN4iSl2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_GkD3Djq8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_7u2sprAa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_bw1DUQFR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_wrReOrEr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Kgzo63Yn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_J0fRPZsk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Qudds8mF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_e6AtFHpj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DnzrqGb6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_LBCQQpoI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_uegVsTVn_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_2fqSuDTk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_Y9Je5yU7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_PF1y9EAN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_4Vs4DX50_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_hws0HNaI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_FI9VPFCw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_1UxaNi2U_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_vYMSVemh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_exuJqNjf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_5fJ9GSFc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_QOF0LBeN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_pkMmsCoH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HeQFsWEI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_eWC2jmIW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_EyV9N51M_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_VAio10WH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_ZlhsQHL1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4EIeDRRu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_JoPObvLj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ct00Jg58_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_exDoqCbG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_T1ZlJ3At_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_mYhdyjgj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_qD6RoSbW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_bPowcWSp_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_JxmEVTuW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_6F5kI6MG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_7HAz54hx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BflTAlie_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_SCwvXm5M_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_78BbIpCQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DMVCyhNF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_BQo9NhFb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ia6YC8Jt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_yIindWiC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_ArreQD0W_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_6q0Llt3F_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_XjQVbnko_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_183SSlVe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_ON1C7Wxf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_BB8C7X4W_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rNXeVdmT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_0VXmgNv1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_LAZreMkj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_WKjGK62J_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_TSCYMnZp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_49X0iU7n_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_lH9QgYy0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1juND2oo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Gh7ckbsH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_RLET3RFB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xrXQz5yD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_TiMpz1Ub_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DEtYihhg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rxtJXBN6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qNOLMzk5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_GGPjPvVW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_AIDUneLW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ABrCU5CY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Db2Guhet_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_xbUGXQhL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_4wAQtwl4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_54z8w8f3_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_m4q0OXkw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Fk5TDtqd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_m3Tepfzy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_iBLJilpk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Nk22g96w_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_4osxvHNA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vGKtmPJX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_LGhSOOiK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_x078sjED_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_Co50Qpyj_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_MyvNL4Nc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_UAmX9KbE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Twl3VW0P_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_GlLKrIeU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_tK4j9RFP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_YRmoYkID_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_w0bB3D6F_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_RkfL6NrC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_FFyPN5Cq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_vo86KxmI_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_ZY1y8qM2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_8gkbSuoN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_o0u06kJD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_gm9tCWMR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_X3FGyhs7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_QEwXDSVp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_Kj2FISwG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_M6b7OaW3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_mURdKEkU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_pTWztxdf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_AWEYY5t3_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_ep7CdGvs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_wgRiuBxC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_0Bvp4Nle_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Yrr6PPQW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_5YVYa2gX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Di25bNcZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_iMxBluSy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vyoYI2NB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_7Q1nLlIl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_EtVjEf9Q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_GoNouLQE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_uAKB7XzC_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_YcfqfjLu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_MGHXlcOk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_zwopfjU4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_FebRG7uN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_wrpV92oY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_cXWVgS37_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_YhMKh4UR_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_WVrquOKn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_RhDH9CF8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_W46Jjo54_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_vQR4bZLt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_mT2nO8Wg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_wECCakCv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_gHacxFY5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_eJhD5JCZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_cPL9IK8E_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VHPB3uOZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_DKqIt3Es_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ioS5qTT3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_DszfnXEe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_tePGELr5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_QWJLLiyu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_9Iyyl35H_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_A2JVdw1p_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_G8D9T6Ad_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6WycUXP9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_sLkO61Vb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Waedi30r_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_bA2mDOWp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1VuTebzA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_PGwMDcs5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5DkVdlhw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BgqLThw9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_uxEmp4hE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_0vc25TxV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_cOJWuMGJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_2Fvn1bJL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_K4tGZ13H_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_uf0h2qCm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_ulliU4ZT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_kn2SeFMS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_uA2pEUS1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_5ZkFD5nM_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_fxhe9sgf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_zU9avkjl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_CouypCls_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_g28ckT0T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_deXN5hiI_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_Ohvljzq8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_GULlJezm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_lbU2mAHa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_M9t4ohNc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_oMTJ8C9S_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_W8UG5TGD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_UArr5yty_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_rV8zmuKf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_ugW9QQRP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_CDtvJVMP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_0Zl62TGD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_9N6QLjMN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_cka7OGrC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_UFr8jYil_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_seiBuLp4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_iPW4RJSS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_DQG300gv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_vhm2UQoS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_kTnp4MmB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_BwvNs83z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_P3a6xalk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Voz1pUci_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Jfvr80ch_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_KnAFTeWx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_iWKboJeo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_a9tSVIsa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ZXqaOm3l_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_y6hvOO66_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_mxc36ebf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_FJRJ7nnZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Zqjsft7I_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qRLoc2CK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Vze8jFrw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_YHYx9sZ8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_VKGYcUH2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_AiHJgBpy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_GeJZF1sp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_cojxLUEE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ag7tEh6h_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_l0Di9L2U_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5lPwLpxO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_yf8EHEhZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_mkTbKFYA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_mMbU0YiB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_QL7GvIQn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_WY9GETro_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_UC4NigbB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_uyUqSx9K_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_BYMlgNA9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_uBlVa8OC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_5BxPnaIF_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_jr1uXGVr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_rqI3VxP2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_PU6CK5SJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_2tKhvxzp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_bFyRg4iL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_1QoyFhU9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_oQliWnk1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_sOg1oYsN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_cXDKFJgB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_OlYB2iRp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_zlALpkqk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_yhnOJlo1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_DSBfWGJn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_IPXSWABL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_f5aZ276n_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_uhr8kppM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_AAmD5bTL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ORJUlePY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_2i56cyVv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_CD79Nslw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_2w2uJUjt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9VCU9m0q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_aagBk7y9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Ld0p5gTT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_6XGO9Nf0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_swBg2dY9_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_2nzknvo2;
  SignalLine sLine_eBKI5gSb;
  SignalPhasor sPhasor_EyAvJncG;
  SignalLine sLine_RcL7jbNB;
  SignalPhasor sPhasor_fb30VM52;
  SignalPhasor sPhasor_PLyU98zV;
  SignalLine sLine_8xZuxxIq;
  SignalPhasor sPhasor_dY9bksQT;
  SignalPhasor sPhasor_Kp6pfADo;
  SignalPhasor sPhasor_favMWr5T;
  SignalLine sLine_puXWWNP2;
  SignalPhasor sPhasor_M6e5wPsf;
  SignalPhasor sPhasor_TjmuA1zl;
  SignalLine sLine_e4c5MxLI;
  SignalPhasor sPhasor_z1D2svmR;
  SignalLine sLine_Tc5ROhQw;
  SignalTabhead sTabhead_897iqLJ6;
  SignalTabread sTabread_mwLz3Xyo;
  SignalTabread sTabread_ucEGJi5m;
  SignalLine sLine_HRPJ36te;
  SignalLine sLine_Dycv4cv8;
  SignalTabhead sTabhead_Rk99td38;
  SignalTabread sTabread_UIcQpSw0;
  SignalTabread sTabread_Pg7dfuvx;
  SignalLine sLine_dPHrdpuN;
  SignalTabwrite sTabwrite_Lb8z0cI8;
  SignalTabwrite sTabwrite_NO16AwuL;
  SignalLine sLine_yvFasSQA;
  ControlVar cVar_Y1n269E8;
  ControlVar cVar_7jKV1DcY;
  ControlBinop cBinop_n4OeWMZO;
  ControlVar cVar_RzAe9niw;
  ControlBinop cBinop_j9vrMWXL;
  ControlRandom cRandom_rsb6Sc05;
  ControlSlice cSlice_Vd93ILrK;
  ControlBinop cBinop_yn1A5HIv;
  ControlRandom cRandom_RxnkBmy1;
  ControlSlice cSlice_Rds8anBq;
  ControlPack cPack_Aia28Ah1;
  ControlSlice cSlice_DWgU0SN0;
  ControlSlice cSlice_mKeYlGfs;
  ControlSlice cSlice_orf0b9WY;
  ControlSlice cSlice_lAgzzqqE;
  ControlSlice cSlice_DXV5o3Lw;
  SignalVarf sVarf_bdlqFuuL;
  ControlBinop cBinop_J0fRPZsk;
  ControlBinop cBinop_Qudds8mF;
  SignalVarf sVarf_XnBj1JPX;
  SignalVarf sVarf_cKLWdxD7;
  ControlBinop cBinop_2fqSuDTk;
  ControlRandom cRandom_PF1y9EAN;
  ControlSlice cSlice_4Vs4DX50;
  ControlPack cPack_hws0HNaI;
  ControlPack cPack_FI9VPFCw;
  ControlVar cVar_exuJqNjf;
  ControlBinop cBinop_QOF0LBeN;
  ControlBinop cBinop_HeQFsWEI;
  SignalVarf sVarf_Xs647X4K;
  SignalVarf sVarf_rr0SdXhn;
  SignalVarf sVarf_LtEyJLQp;
  ControlVar cVar_VAio10WH;
  ControlBinop cBinop_4EIeDRRu;
  ControlBinop cBinop_ct00Jg58;
  SignalVarf sVarf_KY9Vg7zj;
  SignalVarf sVarf_EM5phRoD;
  SignalVarf sVarf_OsHJd4xu;
  ControlDelay cDelay_mYhdyjgj;
  ControlDelay cDelay_qD6RoSbW;
  ControlBinop cBinop_JxmEVTuW;
  HvTable hTable_6F5kI6MG;
  ControlBinop cBinop_BflTAlie;
  ControlDelay cDelay_ArreQD0W;
  ControlDelay cDelay_6q0Llt3F;
  ControlBinop cBinop_183SSlVe;
  HvTable hTable_ON1C7Wxf;
  ControlBinop cBinop_rNXeVdmT;
  ControlBinop cBinop_49X0iU7n;
  ControlBinop cBinop_lH9QgYy0;
  ControlBinop cBinop_1juND2oo;
  ControlBinop cBinop_Gh7ckbsH;
  ControlBinop cBinop_RLET3RFB;
  ControlBinop cBinop_xrXQz5yD;
  ControlBinop cBinop_rxtJXBN6;
  ControlBinop cBinop_qNOLMzk5;
  ControlVar cVar_4wAQtwl4;
  ControlDelay cDelay_m4q0OXkw;
  ControlVar cVar_Nk22g96w;
  ControlBinop cBinop_vGKtmPJX;
  ControlBinop cBinop_LGhSOOiK;
  ControlBinop cBinop_x078sjED;
  ControlDelay cDelay_MyvNL4Nc;
  ControlVar cVar_tK4j9RFP;
  ControlBinop cBinop_w0bB3D6F;
  ControlBinop cBinop_RkfL6NrC;
  ControlBinop cBinop_FFyPN5Cq;
  ControlBinop cBinop_ZY1y8qM2;
  ControlRandom cRandom_o0u06kJD;
  ControlSlice cSlice_gm9tCWMR;
  ControlPack cPack_X3FGyhs7;
  ControlSlice cSlice_QEwXDSVp;
  ControlSlice cSlice_Kj2FISwG;
  ControlSlice cSlice_M6b7OaW3;
  ControlSlice cSlice_mURdKEkU;
  ControlSlice cSlice_pTWztxdf;
  SignalVarf sVarf_fmoXBxZo;
  ControlBinop cBinop_iMxBluSy;
  ControlBinop cBinop_vyoYI2NB;
  SignalVarf sVarf_31kGsukl;
  SignalVarf sVarf_qJCyIbYI;
  ControlBinop cBinop_YcfqfjLu;
  ControlRandom cRandom_zwopfjU4;
  ControlSlice cSlice_FebRG7uN;
  ControlVar cVar_wrpV92oY;
  ControlVar cVar_cXWVgS37;
  ControlVar cVar_vQR4bZLt;
  ControlVar cVar_mT2nO8Wg;
  ControlVar cVar_wECCakCv;
  ControlVar cVar_gHacxFY5;
  ControlBinop cBinop_VHPB3uOZ;
  SignalVarf sVarf_2SoprVX7;
  ControlBinop cBinop_G8D9T6Ad;
  ControlBinop cBinop_6WycUXP9;
  ControlBinop cBinop_sLkO61Vb;
  ControlBinop cBinop_Waedi30r;
  SignalVarf sVarf_u8NiChKT;
  ControlBinop cBinop_1VuTebzA;
  ControlBinop cBinop_PGwMDcs5;
  ControlBinop cBinop_5DkVdlhw;
  ControlBinop cBinop_BgqLThw9;
  ControlVar cVar_uxEmp4hE;
  ControlVar cVar_0vc25TxV;
  ControlVar cVar_cOJWuMGJ;
  ControlPack cPack_2Fvn1bJL;
  ControlVar cVar_K4tGZ13H;
  ControlVar cVar_uf0h2qCm;
  ControlSlice cSlice_ulliU4ZT;
  ControlSlice cSlice_kn2SeFMS;
  ControlSlice cSlice_uA2pEUS1;
  ControlSlice cSlice_fxhe9sgf;
  ControlDelay cDelay_zU9avkjl;
  ControlDelay cDelay_CouypCls;
  ControlIf cIf_g28ckT0T;
  ControlSlice cSlice_Ohvljzq8;
  ControlPack cPack_ugW9QQRP;
  SignalVarf sVarf_tDKBcNvk;
  ControlVar cVar_Jfvr80ch;
  ControlVar cVar_KnAFTeWx;
  ControlBinop cBinop_iWKboJeo;
  ControlBinop cBinop_a9tSVIsa;
  ControlBinop cBinop_ZXqaOm3l;
  ControlBinop cBinop_y6hvOO66;
  SignalVarf sVarf_ny9v4c4x;
  ControlBinop cBinop_FJRJ7nnZ;
  ControlBinop cBinop_Zqjsft7I;
  ControlBinop cBinop_qRLoc2CK;
  ControlBinop cBinop_Vze8jFrw;
  ControlVar cVar_YHYx9sZ8;
  ControlVar cVar_VKGYcUH2;
  ControlPack cPack_AiHJgBpy;
  ControlVar cVar_GeJZF1sp;
  ControlVar cVar_cojxLUEE;
  ControlVar cVar_ag7tEh6h;
  ControlVar cVar_l0Di9L2U;
  ControlBinop cBinop_5lPwLpxO;
  ControlBinop cBinop_yf8EHEhZ;
  ControlSlice cSlice_mkTbKFYA;
  ControlSlice cSlice_mMbU0YiB;
  ControlSlice cSlice_QL7GvIQn;
  ControlSlice cSlice_UC4NigbB;
  ControlDelay cDelay_uyUqSx9K;
  ControlDelay cDelay_BYMlgNA9;
  ControlIf cIf_uBlVa8OC;
  ControlSlice cSlice_jr1uXGVr;
  ControlPack cPack_cXDKFJgB;
  SignalVarf sVarf_w0qEdyrk;
  SignalVarf sVarf_jsKAGKyf;
  SignalVarf sVarf_8uvF5VEO;
  ControlBinop cBinop_9VCU9m0q;
  ControlBinop cBinop_aagBk7y9;
  ControlBinop cBinop_Ld0p5gTT;
};

#endif // _HEAVY_CONTEXT_PROG_HPP_
