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
#include "HvControlIf.h"
#include "HvControlDelay.h"
#include "HvMath.h"
#include "HvControlSystem.h"
#include "HvSignalRPole.h"
#include "HvTable.h"
#include "HvControlCast.h"
#include "HvControlTabhead.h"
#include "HvSignalBiquad.h"
#include "HvControlUnop.h"
#include "HvControlVar.h"
#include "HvSignalPhasor.h"
#include "HvControlRandom.h"
#include "HvControlBinop.h"
#include "HvControlSlice.h"
#include "HvSignalDel1.h"
#include "HvSignalTabwrite.h"
#include "HvSignalVar.h"
#include "HvSignalTabread.h"
#include "HvSignalLine.h"
#include "HvControlPack.h"

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
  static void cPack_Umtc8m7B_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_uCeeaDCi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_w1DFK18j_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_oSYt3JsO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_31dcTInX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_91SpY1hJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_ELzPgKTV_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_hVBStpxO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_hodciYNl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ZHAAwlf5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_4auEkFM8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_oYrNPXvt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ZIwCdk8G_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ZqyBf6eY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_IsxbPcyJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_sx8qwf0O_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_XVK1tZAN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_MpxQi47r_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_kjGhRJJQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_nRgWFnx9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_mVXjzZ72_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_hnJsdOUx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_mDnAClNK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_L0p4HWhm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zOykHCQO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_jHzd5IJd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1LAl7JTY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_09VqSU6z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_diuSIZE3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_FgfgFVLb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_vkFXRbo3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8ffIoxHZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_UYabfOg4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_7J17VLNK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_u0krAgoW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_CMQ4kMGL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KU90j0Rg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kuEBFWGG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_F8RbaFmz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_njsSib3M_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ejXEBBBw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_2t0UYWKH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_Qlgbf4DD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_V7Bg8okb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_qhpuBP8e_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_vgfLWJbo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_6NnYa1gW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DPwXgPCK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_uJf073Y9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_8LLsYA8S_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_DgzGT3a4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_A3YjrHnR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_cob5pa1D_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_oELgZ5Zh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_GX96SX14_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_9VjlLQij_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_R43F9e3h_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_e4ayJNUW_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_DBG7axuZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_RSCHpM7S_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ChNnpggJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_PPsWWxJq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_cvfMTLRu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_gOotHBDf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_4wpScoxW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_5hNFIN3q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_GGldd6DJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Eo9VchYv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_HbdXdJD0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_mEQDhxJr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_eYRuPsor_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_lcgrgkuG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_H7PydLiK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_qMPh04nq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_MSfFIUlq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_94qkq5ls_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_PMQCDa8N_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_du1eT0p1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_LkCQHWat_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_wAx7EdtM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_LCIJSZ2s_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_o2mjTCxS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_t1pmA560_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cCKr9iv9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_P0pMkGD1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8dqg9Uqz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_VoYbQ9ku_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_XOAWATeM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_ua2tuugZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_AlzKO5pl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_swgUzl0Y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_v1OJ2aA7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cprXhtMI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_mpuXSgqe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_3bSAk3TT_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_gtVahQSs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_JayWHoVl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_d2vMPun7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_JgWUY116_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_azFy7afF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_b5UVEUg7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_6XAj1obJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_4GGFHtgZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_2y5Acj4k_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xH22j4jf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ZeeCFWMH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_62AhM6ST_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_JdLl49NG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_mz7pjecg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_84bIARAc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_sv7yxcwp_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_1RTa6quG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Gp2LsnFj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_kNPEigZF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_Sq1Qf40Z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_VNoPOyUy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_DqSSfPyp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_2dZfXi8m_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Pw7JTjRm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_v3CbBV4l_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Xzpixm7T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_QLDNW2o9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_KTql2ELd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zDcWK4ru_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8gMXtXuc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_m1Dy7wNN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_T3Gq0gpM_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_1SRYQLQt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_pWpPmdFM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bvl8BMSv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9eFNOunO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_lGJwIJzh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BdOh3K18_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_8naDOI7D_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_ysje4zNi_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_mnLlxfy1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_hVo5coaF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_s5cmr2Ek_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_kV4sV5ka_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_WHfHHgek_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_5MBzcvtQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_j748SDwM_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_KTDqii1X_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_r1VO5Pkv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_87zNzrt4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_Hg1a7fFy_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_645btzoT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_5emCu49O_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_zklMGZct_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_5KS463DQ_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_SePx1fj6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_O6mRuvKU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_xNB9tKot_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_7ptmNGvr_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_XjKTPns3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_s9kMtrMe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_OsYVqOHq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_6Y9yFf5x_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_5foSaRYK_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_FdP7iLVd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_ny3pn3pV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_xPKFqMcA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YzekwAUv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zaiVktH6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_iNtdz03s_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_wmoqHOuq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HwFy0KPN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_X5DcXdYc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_TcJty9BS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_dkVoqyot_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_dkZF1oSo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_bGSixa7i_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Fl6cjQEs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_3dtNxbVW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ne8xx7Yw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_MNgF6rAo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_7StI8iUO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_TnYyXjO5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_gb5MEIpU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_aVPfItfk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_95HrKg8L_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_e7gENvKp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_csSP8RcE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_jbPuCfrm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_zXcQLUck_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_jon8KqY7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_62s2ujjD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_9Tl4h2ZF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_kuEL7J5t_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_UKAV8QTO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rc8ON79I_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_4cKceb5h_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_K9qBW0Td_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_uCffvnCz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_aDoNfOEA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_hgbksNPt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_rAXDtk8T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_jirvkrIp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_gD42ZJy2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_3s6ycpXZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_jtIvsVdW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_QQCkJjjJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_9ZufqMej_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Go9t6spH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_00zQnxAJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_OGTiuuXW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_QIlpUMW2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_epFMRQoE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_thscegvE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_CcSDTgnv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cIA3UCBJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xU377ePm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_brVgDE9u_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_cA4hkEOR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_BQ9OGn9B_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_CHSrKiRd_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_HQ5esm88_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_szqyQOCg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_nXGqg6IN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_dPA6TQrA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_yoA4VWMP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KkAMjfh9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_fhLUHh1Y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_XtNeo2Zz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cRzooumg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_WgRLEnqJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_5GtPAsOr_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_FH6iAazo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_wcouy16g_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_osUzjoTe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_SkboIH0P_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_AfwFZUb0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabhead_vqx2fA6g_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_WvpZXHxt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_nXVFIdgA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Om9nZlGl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_sF8K9GQj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_7LFX19wJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void sTabread_uo0OBiAM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5quD9JBM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VaEV5ETO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_iCIyBeks_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_NSafD5RR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_8onuErGj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_SoDemoGr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_nTAE9uEG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6QchZZ9M_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Gc8UyXb3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VVhBqeoR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_LbQHhmwT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_5VTJeFgz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_UA6PDbFk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_0QOImq1e_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_lyEZyJes_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_zfBgdnGz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_xwPDQcwI_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_8XnBnSw2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_ElWEIygO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_8kDoudiM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1TJSxn6s_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_fVfvgxMG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_y0JShZhm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_We9OfAAn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_sgbsmaCW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_gQExx4bt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_2Idglbhe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_tgDSGHrS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_QI4QGwvv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_m2Z3Pv5v_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DYX5cTdX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MGGRFOV3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VQlWhYI3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_aq8esNR7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_z6jclXAG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ay14IWDK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_QbKAt358_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_3jQSFkDW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0395xywt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_y5vYhM9h_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qV8bzt0K_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_Kv384DrO_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_BGrpPBhl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_4Yyt42ZN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_z1t4y7oc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_gihxncnf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_LA9nXji7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DOjncu7U_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_eGqiCKSc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0qZFPKxj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ZCZKt9nV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_TrgFOYMl_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_EZzKi6vB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_sYlmt2lL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_Nzzi5PNv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_O0yWS5Hw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_t0Hy1j2A_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabhead_Tfk7hPio_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_WG2LLPWl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_GXHeedgA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_yEiVzCbD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_7HFkmvG1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_iXhgRk57_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void sTabread_5xuekenN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bgT7QROq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_lIMrAFyM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_nqFlC583_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_g9wG2PhI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_owHjnmH9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_R929Yr10_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_5d0MMeuL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_t79ifcPJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_EW08l3VT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_iECOj6aU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gqfz90qD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_a78lxG6u_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ZEvov2mY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_jUQbaQnt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_4ypJVFxp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_Hz4h58R4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_OPWXc48k_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_i01xm9sV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_dYarlN3y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_kHu00dgL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_M1MuiGXK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_3LZh1jRx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_46pfl2pL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DAedXgUX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ncZu83Ma_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_0suCiwdB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_SV9fd9Av_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_JH0X3H64_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_EiJcEoec_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_12qLszJa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_PzT25nIs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_I4lVJ3GX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Ft6HLwCS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ReDlJGp0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_v9zuj9br_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_J8tjw3nw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_pPNbIiOv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_m842SMLk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9AmGk4jY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_x74VS8R7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_H2vaRBZ7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_CNlEAQyg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_aTQm4aKw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_nvaH7Sje_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_yuigtzsA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_p4WHyUqU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_aNJPAWBI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_E3XE285u_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_SLG3ACCH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_41Qyy9r3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_dTaESuTg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_UI85S5KJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_J8FK5EWO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_4mEzioo1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5jt9q7nJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_q6fyIJtQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9Q7KQ2bK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_FenE2xJN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_mYZGuWaf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Fs1vYBFq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_HIzXgDOS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qSRO9ipS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_AgzC0Rux_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_tFgEVlrZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VyfDPWlS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3mKJSCew_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_NJHVjnPb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_cdwLBKQ1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_K2z89Su4_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalTabread sTabread_uo0OBiAM;
  SignalPhasor sPhasor_HDkGQCpp;
  SignalLine sLine_G7OMnlKW;
  SignalRPole sRPole_ymGctuwH;
  SignalTabwrite sTabwrite_8BaqlGsf;
  SignalPhasor sPhasor_gldyenqC;
  SignalLine sLine_FkLrNy0y;
  SignalPhasor sPhasor_ubydacGm;
  SignalLine sLine_XkmIvcAe;
  SignalRPole sRPole_94gjxaDI;
  SignalPhasor sPhasor_tsuMVecm;
  SignalRPole sRPole_EV713p3j;
  SignalLine sLine_lvO83xh3;
  SignalLine sLine_wjVHc5oo;
  SignalBiquad sBiquad_s_54xTfrk2;
  SignalBiquad sBiquad_s_Afz4mgme;
  SignalPhasor sPhasor_NbBTov1k;
  SignalPhasor sPhasor_PIjhwkLE;
  SignalLine sLine_tc4YMTy8;
  SignalPhasor sPhasor_BWCUjx9q;
  SignalLine sLine_dOa8UFWq;
  SignalTabhead sTabhead_FRYqmwTo;
  SignalTabread sTabread_Ox1ck9vq;
  SignalTabread sTabread_zJsYPHiK;
  SignalLine sLine_DocSZ9mM;
  SignalLine sLine_Jbj7q6P5;
  SignalTabhead sTabhead_4zAMiQln;
  SignalTabread sTabread_VgyvTCOg;
  SignalTabread sTabread_kgkBdsw2;
  SignalLine sLine_nV1G1Hp5;
  SignalTabwrite sTabwrite_t8PP8ETu;
  SignalTabwrite sTabwrite_JLley0Oi;
  SignalTabread sTabread_5xuekenN;
  SignalPhasor sPhasor_pRKaKxDF;
  SignalLine sLine_D18u364V;
  SignalRPole sRPole_YHgQ23dg;
  SignalTabwrite sTabwrite_2Ue0SpcF;
  SignalPhasor sPhasor_n4zIwrke;
  ControlPack cPack_Umtc8m7B;
  ControlSlice cSlice_uCeeaDCi;
  ControlSlice cSlice_w1DFK18j;
  ControlSlice cSlice_oSYt3JsO;
  ControlSlice cSlice_31dcTInX;
  ControlSlice cSlice_91SpY1hJ;
  SignalVarf sVarf_iehjSlKL;
  ControlBinop cBinop_ZqyBf6eY;
  ControlBinop cBinop_IsxbPcyJ;
  SignalVarf sVarf_KgMG07PG;
  SignalVarf sVarf_YWMRTbAs;
  ControlPack cPack_kjGhRJJQ;
  ControlPack cPack_nRgWFnx9;
  ControlVar cVar_mDnAClNK;
  ControlBinop cBinop_zOykHCQO;
  ControlBinop cBinop_1LAl7JTY;
  SignalVarf sVarf_toF4PZT7;
  SignalVarf sVarf_ovUceuj6;
  SignalVarf sVarf_o5sdhfxt;
  ControlVar cVar_FgfgFVLb;
  ControlBinop cBinop_8ffIoxHZ;
  ControlBinop cBinop_7J17VLNK;
  SignalVarf sVarf_TzyroLZG;
  SignalVarf sVarf_aCEWg1ui;
  SignalVarf sVarf_A1pCm424;
  ControlBinop cBinop_u0krAgoW;
  ControlBinop cBinop_CMQ4kMGL;
  ControlBinop cBinop_KU90j0Rg;
  ControlBinop cBinop_kuEBFWGG;
  ControlBinop cBinop_F8RbaFmz;
  ControlBinop cBinop_njsSib3M;
  ControlDelay cDelay_Qlgbf4DD;
  ControlDelay cDelay_V7Bg8okb;
  ControlBinop cBinop_vgfLWJbo;
  HvTable hTable_6NnYa1gW;
  ControlBinop cBinop_uJf073Y9;
  ControlDelay cDelay_9VjlLQij;
  ControlDelay cDelay_R43F9e3h;
  ControlBinop cBinop_DBG7axuZ;
  HvTable hTable_RSCHpM7S;
  ControlBinop cBinop_PPsWWxJq;
  ControlBinop cBinop_eYRuPsor;
  ControlBinop cBinop_lcgrgkuG;
  ControlVar cVar_94qkq5ls;
  ControlBinop cBinop_cCKr9iv9;
  ControlBinop cBinop_P0pMkGD1;
  ControlBinop cBinop_8dqg9Uqz;
  ControlSlice cSlice_XOAWATeM;
  ControlSlice cSlice_ua2tuugZ;
  ControlBinop cBinop_AlzKO5pl;
  ControlBinop cBinop_swgUzl0Y;
  ControlBinop cBinop_v1OJ2aA7;
  ControlBinop cBinop_cprXhtMI;
  ControlDelay cDelay_gtVahQSs;
  ControlPack cPack_JgWUY116;
  ControlSlice cSlice_azFy7afF;
  ControlSlice cSlice_b5UVEUg7;
  ControlVar cVar_6XAj1obJ;
  ControlBinop cBinop_xH22j4jf;
  ControlBinop cBinop_ZeeCFWMH;
  SignalVarf sVarf_wqIhnCAI;
  ControlBinop cBinop_JdLl49NG;
  ControlBinop cBinop_mz7pjecg;
  ControlBinop cBinop_84bIARAc;
  SignalVarf sVarf_X8XdXNUC;
  ControlDelay cDelay_1RTa6quG;
  ControlPack cPack_Sq1Qf40Z;
  ControlSlice cSlice_VNoPOyUy;
  ControlSlice cSlice_DqSSfPyp;
  ControlVar cVar_2dZfXi8m;
  ControlBinop cBinop_Xzpixm7T;
  ControlBinop cBinop_QLDNW2o9;
  SignalVarf sVarf_bP1JzMf8;
  ControlBinop cBinop_zDcWK4ru;
  ControlBinop cBinop_8gMXtXuc;
  ControlBinop cBinop_m1Dy7wNN;
  SignalVarf sVarf_YVmmOr0h;
  ControlSlice cSlice_1SRYQLQt;
  ControlSlice cSlice_pWpPmdFM;
  ControlBinop cBinop_bvl8BMSv;
  ControlBinop cBinop_9eFNOunO;
  ControlBinop cBinop_lGJwIJzh;
  ControlBinop cBinop_BdOh3K18;
  SignalVarf sVarf_pQlbcK5L;
  SignalVarf sVarf_2riROFOT;
  ControlDelay cDelay_5MBzcvtQ;
  SignalVarf sVarf_3SJcfwyu;
  ControlDelay cDelay_KTDqii1X;
  ControlDelay cDelay_645btzoT;
  ControlDelay cDelay_SePx1fj6;
  ControlDelay cDelay_XjKTPns3;
  ControlDelay cDelay_6Y9yFf5x;
  ControlIf cIf_ny3pn3pV;
  ControlBinop cBinop_YzekwAUv;
  ControlBinop cBinop_zaiVktH6;
  ControlBinop cBinop_HwFy0KPN;
  ControlBinop cBinop_X5DcXdYc;
  ControlBinop cBinop_dkVoqyot;
  ControlPack cPack_dkZF1oSo;
  ControlPack cPack_bGSixa7i;
  ControlBinop cBinop_Fl6cjQEs;
  ControlBinop cBinop_ne8xx7Yw;
  ControlBinop cBinop_aVPfItfk;
  ControlBinop cBinop_e7gENvKp;
  ControlBinop cBinop_rc8ON79I;
  ControlBinop cBinop_K9qBW0Td;
  SignalVarf sVarf_xnzOEWvE;
  ControlBinop cBinop_QIlpUMW2;
  ControlBinop cBinop_epFMRQoE;
  ControlBinop cBinop_CcSDTgnv;
  ControlBinop cBinop_cIA3UCBJ;
  ControlBinop cBinop_xU377ePm;
  SignalVarf sVarf_Q5UqM26M;
  SignalVarf sVarf_ZdnDhfhT;
  SignalVarf sVarf_Cf5Th4BF;
  ControlVar cVar_BQ9OGn9B;
  ControlBinop cBinop_HQ5esm88;
  ControlRandom cRandom_nXGqg6IN;
  ControlSlice cSlice_dPA6TQrA;
  ControlVar cVar_yoA4VWMP;
  ControlBinop cBinop_KkAMjfh9;
  ControlBinop cBinop_fhLUHh1Y;
  ControlBinop cBinop_XtNeo2Zz;
  ControlBinop cBinop_cRzooumg;
  ControlBinop cBinop_FH6iAazo;
  ControlRandom cRandom_osUzjoTe;
  ControlSlice cSlice_SkboIH0P;
  SignalVari sVari_7vOtQ12w;
  ControlTabhead cTabhead_vqx2fA6g;
  ControlVar cVar_Om9nZlGl;
  ControlDelay cDelay_sF8K9GQj;
  ControlDelay cDelay_7LFX19wJ;
  ControlBinop cBinop_5quD9JBM;
  ControlBinop cBinop_VaEV5ETO;
  ControlBinop cBinop_iCIyBeks;
  ControlBinop cBinop_6QchZZ9M;
  ControlBinop cBinop_VVhBqeoR;
  ControlBinop cBinop_LbQHhmwT;
  ControlDelay cDelay_lyEZyJes;
  ControlDelay cDelay_zfBgdnGz;
  ControlBinop cBinop_8XnBnSw2;
  HvTable hTable_ElWEIygO;
  ControlBinop cBinop_1TJSxn6s;
  ControlVar cVar_gQExx4bt;
  ControlBinop cBinop_QI4QGwvv;
  ControlBinop cBinop_m2Z3Pv5v;
  SignalVarf sVarf_9tQZsJvq;
  ControlBinop cBinop_MGGRFOV3;
  ControlBinop cBinop_VQlWhYI3;
  ControlBinop cBinop_aq8esNR7;
  SignalVarf sVarf_JqlbM8WQ;
  ControlBinop cBinop_z6jclXAG;
  ControlBinop cBinop_0395xywt;
  ControlBinop cBinop_qV8bzt0K;
  ControlBinop cBinop_BGrpPBhl;
  ControlRandom cRandom_z1t4y7oc;
  ControlSlice cSlice_gihxncnf;
  ControlBinop cBinop_LA9nXji7;
  ControlBinop cBinop_DOjncu7U;
  ControlBinop cBinop_eGqiCKSc;
  ControlBinop cBinop_0qZFPKxj;
  ControlBinop cBinop_EZzKi6vB;
  ControlRandom cRandom_Nzzi5PNv;
  ControlSlice cSlice_O0yWS5Hw;
  SignalVari sVari_S7fm1ihi;
  ControlTabhead cTabhead_Tfk7hPio;
  ControlVar cVar_yEiVzCbD;
  ControlDelay cDelay_7HFkmvG1;
  ControlDelay cDelay_iXhgRk57;
  ControlBinop cBinop_bgT7QROq;
  ControlBinop cBinop_lIMrAFyM;
  ControlBinop cBinop_nqFlC583;
  ControlBinop cBinop_t79ifcPJ;
  ControlBinop cBinop_iECOj6aU;
  ControlBinop cBinop_gqfz90qD;
  ControlDelay cDelay_4ypJVFxp;
  ControlDelay cDelay_Hz4h58R4;
  ControlBinop cBinop_i01xm9sV;
  HvTable hTable_dYarlN3y;
  ControlBinop cBinop_M1MuiGXK;
  ControlVar cVar_0suCiwdB;
  ControlBinop cBinop_EiJcEoec;
  ControlBinop cBinop_12qLszJa;
  SignalVarf sVarf_aT4V8xSI;
  ControlBinop cBinop_I4lVJ3GX;
  ControlBinop cBinop_Ft6HLwCS;
  ControlBinop cBinop_ReDlJGp0;
  SignalVarf sVarf_13SyNhJe;
  ControlBinop cBinop_v9zuj9br;
  ControlBinop cBinop_9AmGk4jY;
  ControlBinop cBinop_H2vaRBZ7;
  ControlVar cVar_CNlEAQyg;
  ControlDelay cDelay_aTQm4aKw;
  ControlBinop cBinop_p4WHyUqU;
  ControlBinop cBinop_aNJPAWBI;
  ControlBinop cBinop_E3XE285u;
  ControlBinop cBinop_41Qyy9r3;
  ControlVar cVar_dTaESuTg;
  ControlDelay cDelay_UI85S5KJ;
  ControlBinop cBinop_5jt9q7nJ;
  ControlBinop cBinop_q6fyIJtQ;
  ControlBinop cBinop_9Q7KQ2bK;
  ControlBinop cBinop_mYZGuWaf;
  ControlBinop cBinop_qSRO9ipS;
  ControlBinop cBinop_AgzC0Rux;
  ControlBinop cBinop_tFgEVlrZ;
  ControlBinop cBinop_VyfDPWlS;
  ControlBinop cBinop_3mKJSCew;
  ControlBinop cBinop_NJHVjnPb;
  SignalVarf sVarf_pBpPjVUC;
  SignalVarf sVarf_8NVlX85H;
};

#endif // _HEAVY_CONTEXT_PROG_HPP_
