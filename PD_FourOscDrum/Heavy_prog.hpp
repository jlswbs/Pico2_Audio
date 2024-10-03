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
#include "HvMath.h"
#include "HvControlRandom.h"
#include "HvControlDelay.h"
#include "HvControlSystem.h"
#include "HvSignalVar.h"
#include "HvSignalPhasor.h"
#include "HvControlPack.h"
#include "HvControlCast.h"
#include "HvControlSlice.h"
#include "HvControlUnop.h"
#include "HvControlVar.h"
#include "HvSignalLine.h"
#include "HvControlBinop.h"

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
  static void cVar_CcUIW8lW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ycDc7mjb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_LsYWYW7b_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_mrKQvCwT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_JUJBBUwh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YMwBI2wt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_8A9HXOA9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_aP7I04to_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_U13xMjwn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_vERf2zwS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_SNSiARlo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_IKNb3lAY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_6neEiWqS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_fnHJJ9NH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_5yZ2JyvA_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_YyY5SRvE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_sAko0bSf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_3U92EOCS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_yurWz1pW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_b6fNFdLO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_y4pBohkl_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_RfH8lTX4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_sICLn37C_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_q9u7bKNv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_qrdRIHn4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_GODYLGDd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_qzRRPZiz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_CFQnJGF2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_81NtG76V_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_mDj7gBa4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_otfOLLtb_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_SgGsMy0X_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_hQcaHCUf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_hTQ9njqj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_erL2rWj9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Be9Cpk94_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_m5NQ9C9S_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_UMt59cx3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_T0gg0YzC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KyM8EFqD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_AuAqbTvN_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_QG7DqQcy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_UMpN6EVZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_6jweJ1lF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_6ZwzHMaT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_aAmLaOAf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OPLIfxUj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_5jRVr2Kj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_7NyZDW7M_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Ba4Kpgeq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_g5WGaPAm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_vxo7bTFP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_rMj5beCc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_6QZwgNHz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_zIywZIMV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_OiV1JS48_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_NbwJEMyC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_grkDeOur_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_KQ69bvdR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_afdC3Vi0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_L0TKiDrL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_EqpVwuwK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_A7PLT9LQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_xlYHpD5W_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_pj34wOVZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_BwelTstx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_uclruHvb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_ZwiifBoS_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_cpJgeg9H_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_dHDjFVH1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_zh4VVqvU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Wvr4Nufv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_0MyM9buc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_k02X2vwT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_dDEGfCJr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2xHfckJo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_VfM3Y9tz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_PZVevyQC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ZixlXCsM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_KAAKeSoT_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_3vuEnRUX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ZwOnXhYl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_iKVF9Cn2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_Yd8Drsjg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_78mDvQu1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ezFfyMvF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_dCq0Ir8L_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_XCH2RZHZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cl3tevI3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_SpJKTZRo_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_eZcvZenU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_vpxpCCFe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_mBllIngd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_7P9vQhLl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_J2kM03wP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_1YE9lbFD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xL0sG40u_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1E37PtiI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ZtVKqaQ3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_KSbIl0wg_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_9KjVuOjj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_YXej3NEb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_OlRQAG6E_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_BXAUIHkq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_1SBhD025_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_1udqGFWq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_WnYohth6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_bt3eH68z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_4Thkg9H9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_I5Af8MGw_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_2fxMZGIi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_8qzTe4zH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_aTSew397_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_9tnFHl0Q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_UkYhYMDx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_qoHggZJd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ksHs3nI5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_SLcPiep0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vjweMfpB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kQzLgc4L_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8T9pEPns_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_lgYQnBig_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_nit861eT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_uR1bFQyG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_jwWku2pL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_LFao3aTI_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_9RdoAMYF;
  SignalPhasor sPhasor_IaWqHVQG;
  SignalLine sLine_kRNUmMVO;
  SignalPhasor sPhasor_tWc7HPvM;
  SignalLine sLine_is1u3QG1;
  SignalLine sLine_rNEt1U90;
  SignalPhasor sPhasor_wKJiUmR4;
  SignalPhasor sPhasor_CMdIQHMm;
  SignalLine sLine_LDciaiwo;
  SignalLine sLine_YJjCAfef;
  SignalPhasor sPhasor_EPXLfXdS;
  SignalPhasor sPhasor_J3aFXVSr;
  SignalLine sLine_tq2mqZZn;
  ControlVar cVar_CcUIW8lW;
  ControlVar cVar_ycDc7mjb;
  ControlVar cVar_LsYWYW7b;
  ControlVar cVar_mrKQvCwT;
  ControlVar cVar_JUJBBUwh;
  ControlBinop cBinop_YMwBI2wt;
  ControlVar cVar_8A9HXOA9;
  ControlBinop cBinop_U13xMjwn;
  ControlRandom cRandom_SNSiARlo;
  ControlSlice cSlice_IKNb3lAY;
  ControlVar cVar_6neEiWqS;
  ControlVar cVar_fnHJJ9NH;
  ControlBinop cBinop_YyY5SRvE;
  ControlRandom cRandom_3U92EOCS;
  ControlSlice cSlice_yurWz1pW;
  ControlVar cVar_b6fNFdLO;
  ControlDelay cDelay_RfH8lTX4;
  ControlVar cVar_GODYLGDd;
  ControlBinop cBinop_CFQnJGF2;
  ControlBinop cBinop_81NtG76V;
  ControlBinop cBinop_mDj7gBa4;
  ControlDelay cDelay_SgGsMy0X;
  ControlVar cVar_Be9Cpk94;
  ControlBinop cBinop_UMt59cx3;
  ControlBinop cBinop_T0gg0YzC;
  ControlBinop cBinop_KyM8EFqD;
  ControlBinop cBinop_OPLIfxUj;
  SignalVarf sVarf_objPY7Gh;
  ControlPack cPack_EqpVwuwK;
  ControlSlice cSlice_A7PLT9LQ;
  ControlSlice cSlice_xlYHpD5W;
  ControlSlice cSlice_pj34wOVZ;
  ControlSlice cSlice_BwelTstx;
  ControlSlice cSlice_uclruHvb;
  SignalVarf sVarf_UhgNplRe;
  ControlBinop cBinop_dDEGfCJr;
  ControlBinop cBinop_2xHfckJo;
  SignalVarf sVarf_YPCFi00d;
  SignalVarf sVarf_xNbHlG5o;
  ControlDelay cDelay_3vuEnRUX;
  ControlVar cVar_78mDvQu1;
  ControlBinop cBinop_dCq0Ir8L;
  ControlBinop cBinop_XCH2RZHZ;
  ControlBinop cBinop_cl3tevI3;
  ControlDelay cDelay_eZcvZenU;
  ControlVar cVar_J2kM03wP;
  ControlBinop cBinop_xL0sG40u;
  ControlBinop cBinop_1E37PtiI;
  ControlBinop cBinop_ZtVKqaQ3;
  ControlBinop cBinop_9KjVuOjj;
  ControlRandom cRandom_OlRQAG6E;
  ControlSlice cSlice_BXAUIHkq;
  ControlBinop cBinop_1udqGFWq;
  ControlRandom cRandom_bt3eH68z;
  ControlSlice cSlice_4Thkg9H9;
  ControlBinop cBinop_2fxMZGIi;
  ControlRandom cRandom_aTSew397;
  ControlSlice cSlice_9tnFHl0Q;
  ControlBinop cBinop_vjweMfpB;
  ControlBinop cBinop_kQzLgc4L;
  ControlBinop cBinop_8T9pEPns;
  ControlBinop cBinop_lgYQnBig;
  ControlBinop cBinop_jwWku2pL;
};

#endif // _HEAVY_CONTEXT_PROG_HPP_
