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
#include "HvControlSlice.h"
#include "HvControlIf.h"
#include "HvControlDelay.h"
#include "HvControlVar.h"
#include "HvSignalSamphold.h"
#include "HvSignalTabwrite.h"
#include "HvControlSystem.h"
#include "HvTable.h"
#include "HvSignalRPole.h"
#include "HvControlUnop.h"
#include "HvSignalVar.h"
#include "HvControlRandom.h"
#include "HvSignalDel1.h"
#include "HvMath.h"
#include "HvControlCast.h"
#include "HvSignalTabread.h"
#include "HvSignalPhasor.h"

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
  static void hTable_fKiIW0XV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_W5qFgpPD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_4ongLnOn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_p2decAiI_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_uvmMCIas_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_i6F7MFJA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Vi4fKRwz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_eiNyx99P_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_I9CVDef2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_MeygDXML_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_NC9tNiym_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2xMGOfew_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qSq4Vmi3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_WEy3xGNP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_TL1nwg3Q_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_TOubOCp3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_MYXbbBvb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_HRWWF04F_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_hUbOYUHq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_QDxawHWO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_oOVCaLoC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_mIbAaZpQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_c4JNtdil_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_2w9ra88w_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_KCagZz8h_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_DMashu6b_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_g1oBuaWW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_P7UmFQd1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_lz1PakQY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_phkKPPzm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0Wmh33jm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Z3mPzPSQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2WRNriIo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ayPCML5M_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_7wxCzoJu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_n5aPDQWt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_AgpNgzXN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_RaXHOxpJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_mHD5FLI6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_7SVOhoOp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_HAFBjVno_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_5DvjtkpD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_6DDOwB87_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_SwlwpLbm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_dYWXJvQ5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_29hTB5Ef_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_QAqDMHdI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_y0tKb7kL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_4NocfFwI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_yfVqulBB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ygDOwYpf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_nB2tHsTa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_X7urbrYc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_VR3jeTiJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Cfv9KH9N_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_gCuJTnUs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_WuiWeiQo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_kQqkKJ6L_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_OrS7w7FT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_mYsaHcsK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Qxdxy8vo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_A28rroyb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_LDyRzAsJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rCPcPjBi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_L0VAYQ81_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xlsZnBT2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kCbyGQsP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MjB3M5wD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_G7jkabk9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_DE8wOGC4_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_qYKTHJeR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_QuOi4jk7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_eQd5HbUb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_DYPwW2I3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VYj9Sddo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_5V9oECde_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_HvHftByA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_M49DjQLY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_9wOy5tNw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_mjfOT5eW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_9USi1bGD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Ns4rBK2t_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BQqTF06H_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_3oxZQgeF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_9RC54elg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vjocZIW7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_PF0OAQt9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_I9v4H6Mn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_wlQnxYhn_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_x5F4QmLH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_caOcHcPl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_gaXEVxs7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_ZEmCQWtu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_mnNlLW9x_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_isref72q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_dO6Qjnir_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VVNSElUg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_7UqGEDVj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_0IRinph8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_HpzuTRZ4_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_Hj4LCaRB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_wUK0hKsX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_t4VfIqT7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_d6cqH8V1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gn3S0iS1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_Vnxkz4t7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_x0o8w8hN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_goErZMj2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_Y1A9BPIP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_lsuVWx6j_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_UQ2OT6D9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_TsTtvE6C_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_DadAOeN2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_bSaxZ4xJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_lzAy9WdL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_I5Vo4jOJ_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_nalTcgbi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_qg2wmv29_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_PZteXITA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_cZHLhYfH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Pnvsjd3F_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_HcvX76bN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_nzrlgXE0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_IgyJq2HS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_FbdY9upx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_9KmW9XOo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_dcv0iF2n_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_PKC3YDhv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_pHrju9HB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_jvHHoV5u_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_e7Y1gWvl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_rBMqoXp8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_HYw6cFWG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_bh183G6m_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_yDanFwb0_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_qMqLP7xe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_NkC5Mctd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_V722g2EZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_AgHolfkJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_oyQ4AzOD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_04AfUg1V_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_hvIzhBUc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_tq0zgSUh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_tcfWKqLn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kEoG1jMg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_XlvOTXZ1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_q8H2cgS7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ESbvYltz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zsuWQ9p2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gqDyb95s_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KdMF2jrK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_FaVnmiq8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_6uBxdqzc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_aM1D38hJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ZzT0dVU7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_B8bZES3T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_5r6uLnDy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_iaPHHYBC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_sZI1S4B0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_gEe8SpGA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_SbdT5QHB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_zbM7j0ES_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_TIXT0Dii_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_PchfzXck_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_LpV0F9xa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_kbFs8RZc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ga9E3Xwz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_M9ZYOuVE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_zB9CueAS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_8Dctnd1v_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Z67CjfuJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_JJJcK8md_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KoPnBVtS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_RS5vAzAe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_yvA42JMM_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_8HLASfv0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_BXX5Hyz1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_WnHkkmYv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_pTb9dXdh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_dusj7UPM_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_MxE8gEbE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_ilO3Qh8Q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_AhnlKLqM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_Kbpxxm81_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_17bmFlEr_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_NIfgpfJd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_QGc5JNSO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_2cnvQtND_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_XsItKfKg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_GzwpqvBM_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_KeU0adYk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_P3xKJjrv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_2gGzKYJ1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_m6lm5q1p_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_esnWj0bb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_SwbMFJHR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_EzHDjlMr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_KISAv7UZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_6osVXNUF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_aEI58Epe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KrnkSY8K_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_co191QgJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_zlDcFU66_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_jE2gHkE6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_wzOsf9IV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_K6ANqsMT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_oIk4tdHr_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_lhfHBjD6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_JHrGclky_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8Y2zMWuT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_KElujq3v_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_gRgLfr6C_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Qxuf9t9Q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_JpS84zFi_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_eCBO7kPs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_5sptwqFs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_bOzTi1Za_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_iIOfKNOT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_QZQ1mHLn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_hLY1bVz8_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_I8CJRgRl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_chLAsyt1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_XLBvEwXq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_u05Jr74a_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_i0g2MsJC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_QTlETYk6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_7k61r2G5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_Q4zLlDzI_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_xmvA15ai_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_xnp1YfOi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_VvZ68Un7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_6HUHgbLE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_K9ZuWQ79_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ifcaMAgv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Um2yiOZF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_7pwOOwo6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_vChBdXUn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_T1BLXGrb_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_EjUVUIZc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_lvyi5cYE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_GrUU7KbI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_nKfweGqM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_agUOhRjO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_CNdmGvnr_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_5ObZ6qKm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_B7QGTcJy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_knZggODO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_WRAon9TM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_hqkRTEuS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_fPNbaZof_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_PDMsQ4kI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_S9GLanpv_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_PU7UbYMo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_94dcSr5D_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Qh7mKHaf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_JomLczov_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_TyGxCV4x_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_trtSHc5p_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_h9RwgNmx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_InyIijju_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_GpOxKgCJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_LaqvjTc4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_cCtg7mG5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_mI9C4m2z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_W2X10DUq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_1uCxAqtq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_BoKlLRXK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_sYi0UCfG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_iu82Ensb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_VaKdq0lL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_yalr0UsB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_LEVeJnnW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_a623sDwO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_sKNC905A_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DMMQOLTT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ScLxVTVp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_IaUJf8wm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_YnIHrSpF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_2AcmE9EC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4U1AybHt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ICPsJQnq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_uNBLMKRr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_VDTcO6yZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_kGuNA4kw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_7kFqYHo0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_HKJaAgwj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_2cV4DY3m_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_ekcuMOOc;
  SignalPhasor sPhasor_Fcn5HsvH;
  SignalDel1 sDel1_mA6aXWoV;
  SignalSamphold sSamphold_aPoO4z6t;
  SignalPhasor sPhasor_3VJgdfFJ;
  SignalTabread sTabread_4ganFZ9P;
  SignalDel1 sDel1_NrzHFwEI;
  SignalSamphold sSamphold_LzcVZGIG;
  SignalPhasor sPhasor_lIYhBKKm;
  SignalTabread sTabread_eAOgzWJj;
  SignalTabwrite sTabwrite_kuVgAfyY;
  SignalPhasor sPhasor_el74ecSt;
  SignalTabread sTabread_evddYNmf;
  SignalTabread sTabread_JGZasFtq;
  SignalPhasor sPhasor_H9DQoIc7;
  SignalTabread sTabread_HATnYVOr;
  SignalRPole sRPole_nVmtF4aO;
  SignalPhasor sPhasor_YYhyGSaC;
  SignalPhasor sPhasor_ZiC9F6a6;
  SignalDel1 sDel1_bOtVv0G8;
  SignalSamphold sSamphold_wFaeDLkP;
  SignalPhasor sPhasor_cKBSuNHy;
  SignalTabread sTabread_J0KKiP2N;
  SignalDel1 sDel1_6WZyQQ0o;
  SignalSamphold sSamphold_IEMqnpN9;
  SignalPhasor sPhasor_HFvtNFf5;
  SignalTabread sTabread_xU6fBMgD;
  SignalPhasor sPhasor_oEUtY9cW;
  HvTable hTable_fKiIW0XV;
  ControlDelay cDelay_uvmMCIas;
  ControlVar cVar_I9CVDef2;
  ControlBinop cBinop_NC9tNiym;
  ControlBinop cBinop_2xMGOfew;
  ControlBinop cBinop_qSq4Vmi3;
  ControlVar cVar_WEy3xGNP;
  ControlSlice cSlice_hUbOYUHq;
  ControlSlice cSlice_QDxawHWO;
  ControlVar cVar_oOVCaLoC;
  ControlVar cVar_mIbAaZpQ;
  ControlVar cVar_KCagZz8h;
  ControlVar cVar_DMashu6b;
  ControlVar cVar_g1oBuaWW;
  ControlSlice cSlice_P7UmFQd1;
  ControlSlice cSlice_lz1PakQY;
  ControlBinop cBinop_phkKPPzm;
  ControlBinop cBinop_0Wmh33jm;
  ControlBinop cBinop_Z3mPzPSQ;
  ControlBinop cBinop_2WRNriIo;
  ControlBinop cBinop_ayPCML5M;
  ControlBinop cBinop_AgpNgzXN;
  ControlBinop cBinop_RaXHOxpJ;
  ControlBinop cBinop_mHD5FLI6;
  ControlBinop cBinop_7SVOhoOp;
  ControlBinop cBinop_QAqDMHdI;
  ControlBinop cBinop_X7urbrYc;
  ControlVar cVar_kQqkKJ6L;
  ControlVar cVar_OrS7w7FT;
  ControlVar cVar_mYsaHcsK;
  ControlBinop cBinop_LDyRzAsJ;
  ControlBinop cBinop_rCPcPjBi;
  SignalVarf sVarf_kTBVqscG;
  ControlBinop cBinop_xlsZnBT2;
  ControlBinop cBinop_kCbyGQsP;
  ControlBinop cBinop_MjB3M5wD;
  SignalVarf sVarf_WYS3AGIN;
  ControlBinop cBinop_G7jkabk9;
  ControlVar cVar_qYKTHJeR;
  ControlSlice cSlice_DYPwW2I3;
  ControlBinop cBinop_VYj9Sddo;
  SignalVarf sVarf_4BVdOPRF;
  ControlVar cVar_HvHftByA;
  ControlBinop cBinop_M49DjQLY;
  ControlVar cVar_9wOy5tNw;
  ControlBinop cBinop_mjfOT5eW;
  ControlVar cVar_9USi1bGD;
  ControlVar cVar_Ns4rBK2t;
  ControlBinop cBinop_BQqTF06H;
  ControlIf cIf_9RC54elg;
  ControlBinop cBinop_vjocZIW7;
  ControlVar cVar_PF0OAQt9;
  ControlVar cVar_I9v4H6Mn;
  ControlDelay cDelay_x5F4QmLH;
  ControlVar cVar_mnNlLW9x;
  ControlBinop cBinop_dO6Qjnir;
  ControlBinop cBinop_VVNSElUg;
  ControlBinop cBinop_7UqGEDVj;
  HvTable hTable_0IRinph8;
  ControlBinop cBinop_gn3S0iS1;
  ControlBinop cBinop_goErZMj2;
  ControlBinop cBinop_UQ2OT6D9;
  ControlDelay cDelay_nalTcgbi;
  ControlVar cVar_Pnvsjd3F;
  ControlBinop cBinop_nzrlgXE0;
  ControlBinop cBinop_IgyJq2HS;
  ControlBinop cBinop_FbdY9upx;
  ControlVar cVar_9KmW9XOo;
  ControlSlice cSlice_e7Y1gWvl;
  ControlSlice cSlice_rBMqoXp8;
  ControlVar cVar_HYw6cFWG;
  ControlVar cVar_bh183G6m;
  ControlVar cVar_NkC5Mctd;
  ControlVar cVar_V722g2EZ;
  ControlVar cVar_AgHolfkJ;
  ControlSlice cSlice_oyQ4AzOD;
  ControlSlice cSlice_04AfUg1V;
  ControlBinop cBinop_hvIzhBUc;
  ControlBinop cBinop_tq0zgSUh;
  ControlBinop cBinop_tcfWKqLn;
  ControlBinop cBinop_kEoG1jMg;
  ControlBinop cBinop_XlvOTXZ1;
  ControlBinop cBinop_zsuWQ9p2;
  ControlBinop cBinop_gqDyb95s;
  ControlBinop cBinop_KdMF2jrK;
  ControlBinop cBinop_FaVnmiq8;
  ControlBinop cBinop_sZI1S4B0;
  ControlBinop cBinop_LpV0F9xa;
  ControlVar cVar_8Dctnd1v;
  ControlVar cVar_Z67CjfuJ;
  ControlBinop cBinop_KoPnBVtS;
  ControlBinop cBinop_RS5vAzAe;
  SignalVarf sVarf_pih6oyOa;
  ControlBinop cBinop_8HLASfv0;
  ControlRandom cRandom_WnHkkmYv;
  ControlSlice cSlice_pTb9dXdh;
  ControlBinop cBinop_MxE8gEbE;
  ControlRandom cRandom_AhnlKLqM;
  ControlSlice cSlice_Kbpxxm81;
  ControlBinop cBinop_NIfgpfJd;
  ControlRandom cRandom_2cnvQtND;
  ControlSlice cSlice_XsItKfKg;
  ControlDelay cDelay_KeU0adYk;
  ControlVar cVar_P3xKJjrv;
  ControlSlice cSlice_2gGzKYJ1;
  ControlSlice cSlice_m6lm5q1p;
  ControlBinop cBinop_esnWj0bb;
  ControlBinop cBinop_SwbMFJHR;
  ControlBinop cBinop_aEI58Epe;
  ControlBinop cBinop_KrnkSY8K;
  ControlVar cVar_lhfHBjD6;
  ControlBinop cBinop_8Y2zMWuT;
  ControlSlice cSlice_gRgLfr6C;
  SignalVarf sVarf_6WAWlZfh;
  ControlVar cVar_Qxuf9t9Q;
  ControlBinop cBinop_eCBO7kPs;
  ControlRandom cRandom_bOzTi1Za;
  ControlSlice cSlice_iIOfKNOT;
  SignalVari sVari_ASLf9wfE;
  ControlVar cVar_I8CJRgRl;
  ControlSlice cSlice_u05Jr74a;
  ControlBinop cBinop_i0g2MsJC;
  SignalVarf sVarf_YBUaIaud;
  ControlVar cVar_QTlETYk6;
  ControlVar cVar_7k61r2G5;
  ControlVar cVar_xmvA15ai;
  ControlSlice cSlice_6HUHgbLE;
  ControlBinop cBinop_K9ZuWQ79;
  SignalVarf sVarf_H6zCkV6n;
  ControlBinop cBinop_ifcaMAgv;
  ControlBinop cBinop_Um2yiOZF;
  ControlBinop cBinop_7pwOOwo6;
  SignalVarf sVarf_UERNR3Bd;
  SignalVarf sVarf_LlDttpyA;
  SignalVarf sVarf_nbZNhxfg;
  SignalVarf sVarf_1dNfVTG8;
  ControlVar cVar_vChBdXUn;
  ControlBinop cBinop_EjUVUIZc;
  ControlRandom cRandom_GrUU7KbI;
  ControlSlice cSlice_nKfweGqM;
  SignalVari sVari_aFs7YpR4;
  ControlVar cVar_5ObZ6qKm;
  ControlSlice cSlice_WRAon9TM;
  ControlBinop cBinop_hqkRTEuS;
  SignalVarf sVarf_oHh7sTsp;
  ControlVar cVar_fPNbaZof;
  ControlVar cVar_PDMsQ4kI;
  ControlVar cVar_PU7UbYMo;
  ControlSlice cSlice_JomLczov;
  ControlBinop cBinop_TyGxCV4x;
  SignalVarf sVarf_OAuC1DVW;
  ControlBinop cBinop_trtSHc5p;
  ControlBinop cBinop_h9RwgNmx;
  ControlBinop cBinop_InyIijju;
  ControlBinop cBinop_GpOxKgCJ;
  ControlBinop cBinop_LaqvjTc4;
  SignalVarf sVarf_jg8afP2U;
  SignalVarf sVarf_joS8eQes;
  SignalVarf sVarf_dEG7qAjo;
  SignalVarf sVarf_f89oAcfe;
  ControlBinop cBinop_DMMQOLTT;
  ControlBinop cBinop_4U1AybHt;
  ControlBinop cBinop_uNBLMKRr;
  HvTable hTable_VDTcO6yZ;
  SignalVarf sVarf_QmycUAze;
};

#endif // _HEAVY_CONTEXT_PROG_HPP_
