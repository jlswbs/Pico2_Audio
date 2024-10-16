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
#include "HvControlSystem.h"
#include "HvSignalTabwrite.h"
#include "HvSignalVar.h"
#include "HvMath.h"
#include "HvControlBinop.h"
#include "HvTable.h"
#include "HvControlCast.h"
#include "HvSignalDel1.h"
#include "HvControlTabhead.h"
#include "HvSignalPhasor.h"
#include "HvSignalLine.h"
#include "HvSignalSamphold.h"
#include "HvControlRandom.h"
#include "HvControlDelay.h"
#include "HvSignalTabread.h"
#include "HvControlPack.h"
#include "HvControlUnop.h"
#include "HvSignalRPole.h"
#include "HvControlVar.h"
#include "HvControlSlice.h"

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
  static void cVar_TcKUj30G_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WiZW4OYe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_FadPedbA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BwI2AylW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Qa184Kzx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_2VRdLiXP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_JgrCCxjJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_YbUz0K0D_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xSu7umeE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_aWEYdcGv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Ov5jTnX2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_DaEHskIx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_xKTG4b8r_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Q6QsP5fL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_mmTNXwyr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_sHhmAOms_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_8XPLzcyE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ozmYMGS0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_wky49RhV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_pzSuDuz2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_mTlvyzan_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_UPzeqLV0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2hj6zS4A_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_JBoQLkEY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zkWt4FNY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_S4XDu9bP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_sKqzznBf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_4vJIJAKT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_jdSouoj8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_93XFykoi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_gxUNVYOj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_7DVFbTKU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_9fyfFmCM_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_LClbQWWQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_KBwn0ja1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_w2gC4Agj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_UgLt0n4i_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_o8Uy5856_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_5CObGk4F_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_aYFgAqQT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Bqm09PZn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_xccTDSa7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_CUDDwf7z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DmUfKpWc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_BcA5yXuG_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_ltHnAmPG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_wiHoJZpT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_59RtojPm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_tBGzJKho_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_jOJCSspO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_78MUjA7T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_7RKwXmg0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4zgWOiZ6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_tib0cz7l_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_5yD3JQHI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_fexLnSs5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_p4vIO7Cf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8fmKsl44_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_rrgwGpAw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_44IZTRF8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_iQ2Xs0gJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_LrNWiyca_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_l1FY6qq0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_oplyMOKK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_myjGrgk1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_to2kp7Mb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VNcx7zmJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_UbAzjfgn_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_C3oegIzI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_gtgOQMvs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_YClxjlcz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_2ZjpHkd8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_elp4L5I4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_I7J0J8aL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_VXo965aN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_MaPwvB0I_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_sHOud2ay_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_WLgP1UVv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Sbywmybf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_2buxfsdF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_49wBorWn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_QE4yxXX6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_dG4hGNFW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_DrBiaXkc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_pGkmOG8Z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Ipt0Jz4T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_vyX4nNaD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_fl66CZmW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_d8ZQBjB8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KxROLSwj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BXpA184e_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_QiCxZlbg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_dB64oBNt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_sdZaXGyp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_sDsQvuNN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_AU8eSOSq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_0jl5Nu06_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_ikjQ8FJc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_UxDsWIhS_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_lfFQLyXY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_8CDDo8vp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_9xAI2Bjh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qP4kSTVH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_uMS66mmd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_o7ijTQug_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_wZOO7K6v_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_4Sg9Fng1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_020Wz5Sm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_osXMQtEe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_3jEiMhUz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_q0s4cemx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_oSCbnwnT_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_rByCdJzz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_cDOXciKF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_UZYt1pQJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_CsIWEGeK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Yq5Vrx6I_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_hyIAzKaD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_swKNnwQb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_mgvIt4gi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_pSY8jYGW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_MCitW5Us_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_7lQkzMoc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_FQjj2yPb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Nk7JLYI4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_37rIKfVi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_aK2gc4RO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_F6UNaMy5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_98u8yxNY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_yZZMSOs2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ft1N54oi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_i1FZEE13_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Y6H0t1sq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_VK0dFYEB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_ua4F6x6a_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_QyNDCaxw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_JOhnBbrr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_QmVMMAY2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_I0N2UvYb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_sGYHYvpG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabhead_LS1XrLXO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_NJi5l5dD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_y0h1cP54_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_4QQjVg3L_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_gjbQa1Q3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_sLfY13QE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void sTabread_NfforoI9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_N8bEUnv9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cuASbAoG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Sor5BSgg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_QqRUunRo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_slLvmBNz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_8ZBZ9Q0X_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_jRJm1zCA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Mq5SBFJm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_IqNhsnzt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HSzu7Og0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_h9ltkHNo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_le6qK3je_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_LkLcyVvI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_hCj1n9Lz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_h8NfLZuG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_Idg2ua2A_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_h8L4w9s6_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_FJYbV6dD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_qMBY2bex_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_xI3iZEEn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5lD8rpja_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_13WIjfHJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_IZJZgG5b_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_fp40Vlrq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_jf275kRt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_CJiTvmrq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_pybew1HX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_vE5spGp9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_UmSKQClr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zP6MvgJJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_hOItgQtS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2EZKxV3l_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_fOrIaJNl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ERb8Rkap_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0ez8Y2bQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_b358FKKU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_hHvQqGXT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_9KTsvS35_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_iQw9GMpp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_uqfNEFII_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_UmGgh2VJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_IbI3GxJg_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_3PAPFc9g_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_6FP2TvCd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_CnyPbM6y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_lqwZmexZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_lT9usbm5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_g62lVL3g_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_wf9hpLeB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_rUcerbzT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_qQyWnYwq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vAG3qNbo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_jCkVzVxF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WEaklsdk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_q4SZmBe1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_yj3TNbBU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_R6NkXVwQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_UYuBrQew_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9bL31tRc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ntoRrfBS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BDb16Kqi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_7kjH41YQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vk4RVHIT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rsfM1l3R_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_dAPp3pDT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_kvv0NHR9_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalLine sLine_g5KyF95G;
  SignalPhasor sPhasor_FbRz30fz;
  SignalPhasor sPhasor_NaXa0xTr;
  SignalPhasor sPhasor_QpWoFRfb;
  SignalLine sLine_9wpmFxu6;
  SignalPhasor sPhasor_ABLqzCyU;
  SignalDel1 sDel1_me8FL4nE;
  SignalSamphold sSamphold_JQxob8ps;
  SignalPhasor sPhasor_pDglqP1H;
  SignalRPole sRPole_g6Ry6sxa;
  SignalLine sLine_t8Usze2t;
  SignalTabhead sTabhead_5S7UDsKN;
  SignalTabread sTabread_m5JMSnQm;
  SignalTabread sTabread_BpfX092f;
  SignalLine sLine_BrnRlOS3;
  SignalLine sLine_LKRb39xS;
  SignalTabhead sTabhead_TTcVIYFz;
  SignalTabread sTabread_hGd9Cjsw;
  SignalTabread sTabread_kliJexTI;
  SignalLine sLine_LlJVTA5d;
  SignalTabwrite sTabwrite_C0DOrCc8;
  SignalTabwrite sTabwrite_03e0ZJQL;
  SignalLine sLine_dmsNWyxh;
  SignalPhasor sPhasor_0mndNZqE;
  SignalLine sLine_2WoiwUMu;
  SignalTabread sTabread_NfforoI9;
  SignalPhasor sPhasor_cMstxnuW;
  SignalLine sLine_53rY9gEc;
  SignalRPole sRPole_stWFVLbV;
  SignalTabwrite sTabwrite_vwkI9rv0;
  SignalRPole sRPole_JwNwtTjl;
  ControlVar cVar_TcKUj30G;
  ControlBinop cBinop_WiZW4OYe;
  ControlBinop cBinop_FadPedbA;
  ControlBinop cBinop_BwI2AylW;
  ControlBinop cBinop_Qa184Kzx;
  ControlVar cVar_JgrCCxjJ;
  ControlPack cPack_YbUz0K0D;
  SignalVarf sVarf_LFX7k2Va;
  ControlBinop cBinop_xSu7umeE;
  SignalVarf sVarf_gETB6QGm;
  SignalVarf sVarf_DBLG0iM8;
  SignalVarf sVarf_WrpXZ7zp;
  ControlVar cVar_mmTNXwyr;
  ControlBinop cBinop_2hj6zS4A;
  ControlBinop cBinop_JBoQLkEY;
  ControlBinop cBinop_zkWt4FNY;
  ControlPack cPack_sKqzznBf;
  ControlSlice cSlice_4vJIJAKT;
  ControlSlice cSlice_jdSouoj8;
  ControlSlice cSlice_93XFykoi;
  ControlSlice cSlice_gxUNVYOj;
  ControlSlice cSlice_7DVFbTKU;
  SignalVarf sVarf_RxSjtlWv;
  ControlBinop cBinop_aYFgAqQT;
  ControlBinop cBinop_Bqm09PZn;
  SignalVarf sVarf_o78tQ3Qq;
  SignalVarf sVarf_0gYnCE0f;
  ControlBinop cBinop_ltHnAmPG;
  ControlRandom cRandom_59RtojPm;
  ControlSlice cSlice_tBGzJKho;
  ControlVar cVar_jOJCSspO;
  ControlBinop cBinop_4zgWOiZ6;
  ControlBinop cBinop_tib0cz7l;
  SignalVarf sVarf_z0snXtHr;
  ControlBinop cBinop_fexLnSs5;
  ControlBinop cBinop_p4vIO7Cf;
  ControlBinop cBinop_8fmKsl44;
  SignalVarf sVarf_HwskvUJx;
  ControlVar cVar_rrgwGpAw;
  ControlBinop cBinop_LrNWiyca;
  ControlBinop cBinop_l1FY6qq0;
  SignalVarf sVarf_7g0OilzL;
  ControlBinop cBinop_myjGrgk1;
  ControlBinop cBinop_to2kp7Mb;
  ControlBinop cBinop_VNcx7zmJ;
  SignalVarf sVarf_gTIvVE1i;
  ControlBinop cBinop_C3oegIzI;
  ControlRandom cRandom_YClxjlcz;
  ControlSlice cSlice_2ZjpHkd8;
  ControlPack cPack_elp4L5I4;
  ControlPack cPack_I7J0J8aL;
  ControlVar cVar_sHOud2ay;
  ControlBinop cBinop_Sbywmybf;
  ControlBinop cBinop_49wBorWn;
  SignalVarf sVarf_EBECv8VG;
  SignalVarf sVarf_ipJHjSul;
  SignalVarf sVarf_HYt3yWAS;
  ControlVar cVar_DrBiaXkc;
  ControlBinop cBinop_Ipt0Jz4T;
  ControlBinop cBinop_fl66CZmW;
  SignalVarf sVarf_GX9iSPxG;
  SignalVarf sVarf_nYszIQ4f;
  SignalVarf sVarf_ZhDKGkYS;
  ControlBinop cBinop_d8ZQBjB8;
  ControlBinop cBinop_KxROLSwj;
  ControlBinop cBinop_BXpA184e;
  ControlBinop cBinop_QiCxZlbg;
  ControlBinop cBinop_dB64oBNt;
  ControlBinop cBinop_sdZaXGyp;
  ControlDelay cDelay_0jl5Nu06;
  ControlDelay cDelay_ikjQ8FJc;
  ControlBinop cBinop_lfFQLyXY;
  HvTable hTable_8CDDo8vp;
  ControlBinop cBinop_qP4kSTVH;
  ControlDelay cDelay_3jEiMhUz;
  ControlDelay cDelay_q0s4cemx;
  ControlBinop cBinop_rByCdJzz;
  HvTable hTable_cDOXciKF;
  ControlBinop cBinop_CsIWEGeK;
  ControlBinop cBinop_Nk7JLYI4;
  ControlBinop cBinop_37rIKfVi;
  ControlBinop cBinop_yZZMSOs2;
  ControlBinop cBinop_ft1N54oi;
  ControlBinop cBinop_i1FZEE13;
  ControlBinop cBinop_Y6H0t1sq;
  ControlBinop cBinop_QyNDCaxw;
  ControlRandom cRandom_QmVMMAY2;
  ControlSlice cSlice_I0N2UvYb;
  SignalVari sVari_ModgsPP6;
  ControlTabhead cTabhead_LS1XrLXO;
  ControlVar cVar_4QQjVg3L;
  ControlDelay cDelay_gjbQa1Q3;
  ControlDelay cDelay_sLfY13QE;
  ControlBinop cBinop_N8bEUnv9;
  ControlBinop cBinop_cuASbAoG;
  ControlBinop cBinop_Sor5BSgg;
  ControlBinop cBinop_Mq5SBFJm;
  ControlBinop cBinop_HSzu7Og0;
  ControlBinop cBinop_h9ltkHNo;
  ControlDelay cDelay_h8NfLZuG;
  ControlDelay cDelay_Idg2ua2A;
  ControlBinop cBinop_FJYbV6dD;
  HvTable hTable_qMBY2bex;
  ControlBinop cBinop_5lD8rpja;
  ControlVar cVar_CJiTvmrq;
  ControlBinop cBinop_UmSKQClr;
  ControlBinop cBinop_zP6MvgJJ;
  SignalVarf sVarf_g4qf68OI;
  ControlBinop cBinop_2EZKxV3l;
  ControlBinop cBinop_fOrIaJNl;
  ControlBinop cBinop_ERb8Rkap;
  SignalVarf sVarf_6O56S4Xl;
  ControlBinop cBinop_0ez8Y2bQ;
  ControlBinop cBinop_iQw9GMpp;
  ControlBinop cBinop_UmGgh2VJ;
  ControlBinop cBinop_3PAPFc9g;
  ControlRandom cRandom_CnyPbM6y;
  ControlSlice cSlice_lqwZmexZ;
  SignalVari sVari_bA8gj8sb;
  ControlVar cVar_g62lVL3g;
  ControlDelay cDelay_wf9hpLeB;
  ControlBinop cBinop_vAG3qNbo;
  ControlBinop cBinop_jCkVzVxF;
  ControlBinop cBinop_WEaklsdk;
  ControlBinop cBinop_yj3TNbBU;
  ControlBinop cBinop_R6NkXVwQ;
  ControlBinop cBinop_9bL31tRc;
  ControlBinop cBinop_ntoRrfBS;
  ControlBinop cBinop_BDb16Kqi;
  ControlBinop cBinop_7kjH41YQ;
  ControlBinop cBinop_vk4RVHIT;
  ControlBinop cBinop_rsfM1l3R;
  ControlBinop cBinop_dAPp3pDT;
  SignalVarf sVarf_sYhN3LQe;
};

#endif // _HEAVY_CONTEXT_PROG_HPP_
