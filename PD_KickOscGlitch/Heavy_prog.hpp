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
#include "HvControlCast.h"
#include "HvSignalPhasor.h"
#include "HvSignalTabread.h"
#include "HvSignalVar.h"
#include "HvControlDelay.h"
#include "HvControlPack.h"
#include "HvTable.h"
#include "HvControlRandom.h"
#include "HvControlBinop.h"
#include "HvControlUnop.h"
#include "HvSignalDel1.h"
#include "HvSignalLine.h"
#include "HvMath.h"
#include "HvControlSlice.h"
#include "HvSignalSamphold.h"
#include "HvControlSystem.h"
#include "HvSignalTabwrite.h"
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
  static void cSwitchcase_vYvGfk2K_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_GGy0VOAZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_5B6qAs93_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_EARiZqtJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_rpn8xcDw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_nQd6OmMK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_DlAG9RyO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OsuqMVDd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_QMNhEYDw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ZWFV4MYL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_KrjBqIGb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_otzVWd1P_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_czIRaJMq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ZeBfXhJ0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_nx4K6PVa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_wEF1ccLo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_QH9tZtCV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Yc5k7kAi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_I2KDKVy8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_SwICj4sO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_8A2rUMmj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_4ZVlpwhI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_LjB9rmub_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_D4IwrBg8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_FER2Lsah_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_WTzrJoab_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_7sDdDtBB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_KW8z9T4x_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cTabsQ4D_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_v5dzhGhR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_jWNvjCfI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_liSIW0lZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_7qpM6DfS_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_e0hb0CnQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_jJX3bedv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_pWYDL0qJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_Cb6GcJiD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_HDa0qSCU_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_9Yja4iSp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_NMcrZQYw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_OxyVgjIi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_ZcB3H0hD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_dVgpEOG6_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_wYWYbyiW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_pjffm9Zs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_bMpgSO9X_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_nHHXlqp3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_SVEjahs0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_fUINjoIe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_9jcemq1I_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_RPhsNLWG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_NoF4DoVR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_A19IuVta_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_IISnToH0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_SGvk2oEo_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_sStucTQr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_hRSiq9L0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_B4A6J0yd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_HwWPBFON_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_mypqXt7V_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xIBmvJ0I_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_fdmoCUDr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_4gd0q8Ic_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_zw4urugS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6uv13phU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8AxnKOJl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_V1f0bops_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_T4eiqDWf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Aiw4fCyp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_k2DNUJej_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_1KcxksSI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_o90esv1a_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_KeP8Fm04_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_AeFlLLy8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4MbFvWJe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Jd73q0Cz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_JsmePiFD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ICwXJ2vP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_781qAtCW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_I17dybsM_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_w3wS3juz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_i1KJHwwL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_FFdOLftw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_EF4yhmM1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_hnVn2Ux1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Kpe2vU8R_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_7vYChIBG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ZWKa3GlB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_tmoZSaIh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_bq5bZWcn_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_z4C6p5aZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_j7IvkCkb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_BQWP4iFG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_3iGaccdS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_OycZXKNX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ZM2enndD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cecEuXkw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_H3dPOH8B_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2idkQDPD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_I7EFeQZm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_kVCe1psa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_zuBHi1Ph_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_XceWjjM5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_kVQPEjmY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_LH9S2wwt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_b0gP43vN_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_EdzGdnyV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_RiiwUdUz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_y6XM9eEz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_fA3TFaxs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_SJgnhaDB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_OVA76DEF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_fCj5KBJA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9taqyuO7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_3oPXfren_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_9oXF30X9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_WO4qdbCf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_WPNwWMu6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cRgE2p3h_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_dYwix0CZ_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_IAHS97VE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_9MVwy2uD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_m5khzM0Y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_mlPBmE7z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_mQTVU4a5_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_huGYcyIY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_giVKzRjO_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_IbiNhehT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_SfqifxyK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_QV5OgcpE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_j8zETMVe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zUNtXqrL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_z7sWmpyM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_rmjGo25R_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_BDHaw2rB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Q1OA5Tcf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_GOMnI1jy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ZDJEZfxQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_weMXVgvR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_EV2Z3acf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_PgUYZaiX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_DSipWGPP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_pN1KUZbF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_9Ngz9zeQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_rwZk4vI1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xUMC80VC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3qJBfNWh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_NmR6RHAJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VhsfY9A4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_AlPEOV8w_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_FrvGUYwL;
  SignalDel1 sDel1_v6OPJnH1;
  SignalSamphold sSamphold_pUSDt9Ko;
  SignalPhasor sPhasor_3l1qioez;
  SignalPhasor sPhasor_xcLMLMUw;
  SignalLine sLine_wATI4Duh;
  SignalTabwrite sTabwrite_uP44u9PG;
  SignalPhasor sPhasor_U8mXelwc;
  SignalTabread sTabread_vLQe2rv1;
  SignalTabread sTabread_ZrGsG8tG;
  SignalPhasor sPhasor_CJY3EslH;
  SignalPhasor sPhasor_dVp3gUZz;
  SignalLine sLine_u1ODDWNc;
  SignalPhasor sPhasor_0Un2ag4f;
  ControlBinop cBinop_GGy0VOAZ;
  ControlRandom cRandom_EARiZqtJ;
  ControlSlice cSlice_rpn8xcDw;
  SignalVari sVari_Gunz2nAC;
  ControlVar cVar_DlAG9RyO;
  ControlBinop cBinop_OsuqMVDd;
  ControlVar cVar_QMNhEYDw;
  ControlVar cVar_ZWFV4MYL;
  ControlVar cVar_KrjBqIGb;
  ControlBinop cBinop_cTabsQ4D;
  SignalVarf sVarf_TdYr8Tww;
  ControlBinop cBinop_e0hb0CnQ;
  ControlRandom cRandom_pWYDL0qJ;
  ControlSlice cSlice_Cb6GcJiD;
  ControlBinop cBinop_9Yja4iSp;
  ControlRandom cRandom_OxyVgjIi;
  ControlSlice cSlice_ZcB3H0hD;
  ControlBinop cBinop_SVEjahs0;
  ControlBinop cBinop_RPhsNLWG;
  ControlBinop cBinop_IISnToH0;
  ControlDelay cDelay_sStucTQr;
  ControlVar cVar_hRSiq9L0;
  ControlSlice cSlice_B4A6J0yd;
  ControlSlice cSlice_HwWPBFON;
  ControlBinop cBinop_mypqXt7V;
  ControlBinop cBinop_xIBmvJ0I;
  ControlBinop cBinop_6uv13phU;
  ControlBinop cBinop_8AxnKOJl;
  ControlVar cVar_KeP8Fm04;
  ControlBinop cBinop_4MbFvWJe;
  ControlSlice cSlice_JsmePiFD;
  SignalVarf sVarf_bJhunsU3;
  ControlVar cVar_ICwXJ2vP;
  ControlBinop cBinop_781qAtCW;
  ControlDelay cDelay_w3wS3juz;
  ControlVar cVar_hnVn2Ux1;
  ControlBinop cBinop_7vYChIBG;
  ControlBinop cBinop_ZWKa3GlB;
  ControlBinop cBinop_tmoZSaIh;
  ControlDelay cDelay_z4C6p5aZ;
  ControlVar cVar_OycZXKNX;
  ControlBinop cBinop_cecEuXkw;
  ControlBinop cBinop_H3dPOH8B;
  ControlBinop cBinop_2idkQDPD;
  ControlPack cPack_I7EFeQZm;
  ControlSlice cSlice_kVCe1psa;
  ControlSlice cSlice_zuBHi1Ph;
  ControlSlice cSlice_XceWjjM5;
  ControlSlice cSlice_kVQPEjmY;
  ControlSlice cSlice_LH9S2wwt;
  SignalVarf sVarf_ti9Gdbv8;
  ControlBinop cBinop_fCj5KBJA;
  ControlBinop cBinop_9taqyuO7;
  SignalVarf sVarf_Gu2r3zhD;
  SignalVarf sVarf_bcrCwZD6;
  ControlVar cVar_WPNwWMu6;
  ControlBinop cBinop_cRgE2p3h;
  ControlBinop cBinop_IAHS97VE;
  ControlRandom cRandom_m5khzM0Y;
  ControlSlice cSlice_mlPBmE7z;
  ControlBinop cBinop_IbiNhehT;
  ControlRandom cRandom_QV5OgcpE;
  ControlSlice cSlice_j8zETMVe;
  ControlBinop cBinop_zUNtXqrL;
  SignalVarf sVarf_n66cwTt2;
  ControlBinop cBinop_EV2Z3acf;
  HvTable hTable_rwZk4vI1;
  ControlBinop cBinop_xUMC80VC;
  ControlBinop cBinop_3qJBfNWh;
  ControlBinop cBinop_VhsfY9A4;
  SignalVarf sVarf_XN3536Ej;
  SignalVarf sVarf_6QID61w2;
  SignalVarf sVarf_Pm6QRjz6;
};

#endif // _HEAVY_CONTEXT_PROG_HPP_
