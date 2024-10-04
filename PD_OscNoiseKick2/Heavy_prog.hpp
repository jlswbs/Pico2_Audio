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
#include "HvControlPack.h"
#include "HvControlUnop.h"
#include "HvSignalTabwrite.h"
#include "HvMath.h"
#include "HvControlSystem.h"
#include "HvSignalDel1.h"
#include "HvSignalLine.h"
#include "HvControlRandom.h"
#include "HvSignalRPole.h"
#include "HvControlSlice.h"
#include "HvSignalPhasor.h"
#include "HvSignalSamphold.h"
#include "HvControlCast.h"
#include "HvControlBinop.h"
#include "HvControlDelay.h"
#include "HvTable.h"
#include "HvSignalVar.h"
#include "HvControlVar.h"

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
  static void cSwitchcase_9EhrZJZK_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_dMyuGgFO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_2mJikNID_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_3MWDTDjD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_E9e5QwVB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_LdxIDLyR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_yYUkpBV7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VpNxX2Gv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_AEcZ4vUh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_6apeTkQl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_GbXiXSRH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_qSTzNEip_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_3pe6Myd5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_vqwMkpPD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_WvzR7yRY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ALpKcDlr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_2YWemfAZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_iWjIjvCq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_oiOsT6Tb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_9auqy9zD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_PakQAMn7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_KidnOlPr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_SRusE5Bg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_iESzV0Tk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_kgV5Xii6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_1MOxEvol_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_fGP7HJVa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MqnaKaHc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_GQftutnu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_tZsXtI6T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_HH09uQul_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_d4l7Ig2Z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_3NO5qWok_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_M3O1K1MV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_VNn7z054_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_X574sfrk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ae412CYQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_iJiKvzp3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_PpsQD4oC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_SDJgk9iq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Kln7V72W_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Vr13dM1k_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_WhQ2upUc_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_FTznpuhl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_B49mlDnf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OrK6GuIb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_nkC9aZjZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_PtPCRK33_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_Q5tI5s2F_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_de4xblQU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rXgSKXGx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_QWRJBYiw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_EUtTXbk0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_y7mMuzYN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_UykblolF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_n2ldLcf9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_iQtFbVbm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_4bdvp9nF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_ImVEHuKd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_PMb6srW1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_LtPpyodB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_zzlGNXLy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_rYRlLLsC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_LuWAHQKg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ywoyqnWL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_IsJRFDSR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_R9HiRxtZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_5eFQ8jl4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_CRxtkdUG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ownfogpN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_veVFd0hV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_F1mWPRtF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_mW918oe2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_QVcwgVuW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_vRgk66Ai_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_JZI3CJe1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_vIx3GlUr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_z8xAowZt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_mMeVVbKd_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_1ZPGs9bp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_1aYRT8cO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_XP6HLyt8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_wLDdZ5PE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_jJA4ny9f_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_JY90oWFU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_oVdildAM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_5upfJICq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_BlhjL7Yg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_lcFv5wq1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_TLhCJ9x1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_elTMDd85_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_FKt4qxhq_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_WQOcO5NN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_NSkeEpty_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_PN6oCOvi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0pcg2RFE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DmveDmSo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_7Ld6kJjZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_4nBkliCU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_FMeWFyLY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Lpo3pGNF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xrPItjzL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_It94o0f3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_shGKpRtI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_QahRpaGy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_RoegVcba_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_YSmz5fPc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_O88Fm2Vq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kQ0BzeKD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_t8zONssy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_r1EM4Uyr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_kl3Lwf3r_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_aqMjIGM0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_hvMUH6cG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_tHh39JNR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_qEby0j2q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_BzLJ2IMt_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_mNwfmiH4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_R0CVrAzQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Sqr7wbEY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_aOsWTqhU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_jkVbSv1L_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_wPGlNWuR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_za6LErkF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2T3l7PWz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_S5cQuNLy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_c1iq7j63_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_L3ILxl4X_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Umx4GQug_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_0L73rrGu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_TOzku0hC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_V7OXJevk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_VM9YaCkS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_AYjaw31S_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KQmd8IJ4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_TTS0ckFl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_TyRVw9Ye_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_JtsLO7Xa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_If0JkTVZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_Pd05n4tb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_PeWNarRz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_YpP3yUWl_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_jZFGOfet_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_WeOGdJcP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_065Fn4Zz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_p4Pl7qjr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_vhVUZ4Cq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_phfHL6OB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_46wvpChK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_yS4GL5Ap_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_alSEijKW_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_W7Tst3aH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_YnPKU0vu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_Kwy4seke_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_iYpyJEVG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_mb6OpclG_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_pXmyEwI8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_J2Cj8JPm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_vTuQTrgY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_HSURXpFS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_FUtyx7NF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_e7JKsv8d_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_U7dpEWOy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_RQNalBK2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_6qR8QKpL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DiVfrivO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3b6pN2yV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OC0j9QZC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_fmEKaNRx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_tcRGxL3A_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YiUp0t0Y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_zqTpiVZY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_hNMSl3rL_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_kG0jqmqW;
  SignalDel1 sDel1_hSyuXkW6;
  SignalSamphold sSamphold_iMqXbhDY;
  SignalRPole sRPole_l95GvnCm;
  SignalDel1 sDel1_B82cpUDL;
  SignalLine sLine_4fpzOE9t;
  SignalPhasor sPhasor_Dvyw69vN;
  SignalLine sLine_RBQizvZ5;
  SignalTabhead sTabhead_Iyc2DSsv;
  SignalTabread sTabread_Nkg5TmFf;
  SignalTabread sTabread_jyu4FqkL;
  SignalLine sLine_6oZu4BrQ;
  SignalLine sLine_ZIeSyHu5;
  SignalTabhead sTabhead_aP4CmbsV;
  SignalTabread sTabread_sUepTZ4s;
  SignalTabread sTabread_aLrVZTxD;
  SignalLine sLine_KAckL2vt;
  SignalTabwrite sTabwrite_7mJnEhGn;
  SignalTabwrite sTabwrite_L2RPHpTJ;
  SignalPhasor sPhasor_JjjOFbU2;
  SignalLine sLine_W5J15VYc;
  SignalRPole sRPole_RTSjMk0x;
  SignalLine sLine_E1zc1LNI;
  SignalPhasor sPhasor_liJxjIhL;
  ControlBinop cBinop_dMyuGgFO;
  ControlRandom cRandom_3MWDTDjD;
  ControlSlice cSlice_E9e5QwVB;
  SignalVari sVari_OBeaNEks;
  ControlVar cVar_yYUkpBV7;
  ControlBinop cBinop_VpNxX2Gv;
  ControlVar cVar_AEcZ4vUh;
  ControlVar cVar_6apeTkQl;
  ControlVar cVar_GbXiXSRH;
  ControlBinop cBinop_MqnaKaHc;
  SignalVarf sVarf_eYV9GUiW;
  ControlVar cVar_3NO5qWok;
  ControlBinop cBinop_X574sfrk;
  ControlBinop cBinop_ae412CYQ;
  SignalVarf sVarf_5l9cAdVg;
  ControlBinop cBinop_PpsQD4oC;
  ControlBinop cBinop_SDJgk9iq;
  ControlBinop cBinop_Kln7V72W;
  SignalVarf sVarf_wx94e9Lh;
  ControlVar cVar_Vr13dM1k;
  ControlBinop cBinop_B49mlDnf;
  ControlBinop cBinop_OrK6GuIb;
  SignalVarf sVarf_YbR5L0RU;
  ControlVar cVar_nkC9aZjZ;
  ControlBinop cBinop_de4xblQU;
  ControlBinop cBinop_rXgSKXGx;
  ControlBinop cBinop_EUtTXbk0;
  ControlBinop cBinop_y7mMuzYN;
  ControlBinop cBinop_UykblolF;
  ControlBinop cBinop_n2ldLcf9;
  ControlBinop cBinop_iQtFbVbm;
  SignalVarf sVarf_rkVKnEft;
  ControlVar cVar_4bdvp9nF;
  ControlPack cPack_ImVEHuKd;
  ControlPack cPack_PMb6srW1;
  ControlVar cVar_rYRlLLsC;
  ControlBinop cBinop_ywoyqnWL;
  ControlBinop cBinop_R9HiRxtZ;
  SignalVarf sVarf_t7z7Wd9L;
  SignalVarf sVarf_Lq5EhWWr;
  SignalVarf sVarf_IsExpAKk;
  ControlVar cVar_ownfogpN;
  ControlBinop cBinop_F1mWPRtF;
  ControlBinop cBinop_QVcwgVuW;
  SignalVarf sVarf_ux8ybj3W;
  SignalVarf sVarf_RS1PbHBs;
  SignalVarf sVarf_8J8NuE1j;
  ControlDelay cDelay_vIx3GlUr;
  ControlDelay cDelay_z8xAowZt;
  ControlBinop cBinop_1ZPGs9bp;
  HvTable hTable_1aYRT8cO;
  ControlBinop cBinop_wLDdZ5PE;
  ControlDelay cDelay_TLhCJ9x1;
  ControlDelay cDelay_elTMDd85;
  ControlBinop cBinop_WQOcO5NN;
  HvTable hTable_NSkeEpty;
  ControlBinop cBinop_0pcg2RFE;
  ControlBinop cBinop_Lpo3pGNF;
  ControlBinop cBinop_xrPItjzL;
  ControlBinop cBinop_It94o0f3;
  ControlBinop cBinop_shGKpRtI;
  ControlBinop cBinop_QahRpaGy;
  ControlBinop cBinop_RoegVcba;
  ControlBinop cBinop_kQ0BzeKD;
  ControlBinop cBinop_t8zONssy;
  ControlVar cVar_qEby0j2q;
  ControlDelay cDelay_mNwfmiH4;
  ControlVar cVar_jkVbSv1L;
  ControlBinop cBinop_za6LErkF;
  ControlBinop cBinop_2T3l7PWz;
  ControlBinop cBinop_S5cQuNLy;
  ControlDelay cDelay_L3ILxl4X;
  ControlVar cVar_V7OXJevk;
  ControlBinop cBinop_AYjaw31S;
  ControlBinop cBinop_KQmd8IJ4;
  ControlBinop cBinop_TTS0ckFl;
  ControlBinop cBinop_JtsLO7Xa;
  ControlRandom cRandom_Pd05n4tb;
  ControlSlice cSlice_PeWNarRz;
  ControlBinop cBinop_jZFGOfet;
  ControlRandom cRandom_065Fn4Zz;
  ControlSlice cSlice_p4Pl7qjr;
  ControlBinop cBinop_W7Tst3aH;
  ControlRandom cRandom_Kwy4seke;
  ControlSlice cSlice_iYpyJEVG;
  ControlBinop cBinop_pXmyEwI8;
  ControlRandom cRandom_vTuQTrgY;
  ControlSlice cSlice_HSURXpFS;
  ControlBinop cBinop_FUtyx7NF;
  ControlBinop cBinop_3b6pN2yV;
  ControlBinop cBinop_OC0j9QZC;
  ControlBinop cBinop_fmEKaNRx;
  ControlBinop cBinop_tcRGxL3A;
  ControlBinop cBinop_YiUp0t0Y;
  SignalVarf sVarf_znQkF9oG;
  SignalVarf sVarf_kQvbYgxJ;
  SignalVarf sVarf_QmcOOABT;
};

#endif // _HEAVY_CONTEXT_PROG_HPP_
