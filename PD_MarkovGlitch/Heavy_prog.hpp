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
#include "HvControlTabhead.h"
#include "HvSignalLine.h"
#include "HvSignalTabwrite.h"
#include "HvSignalRPole.h"
#include "HvSignalVar.h"
#include "HvControlSlice.h"
#include "HvSignalTabread.h"
#include "HvControlDelay.h"
#include "HvControlRandom.h"
#include "HvMath.h"
#include "HvTable.h"
#include "HvControlVar.h"
#include "HvControlSystem.h"
#include "HvSignalPhasor.h"
#include "HvSignalDel1.h"
#include "HvControlPack.h"
#include "HvControlCast.h"
#include "HvControlBinop.h"
#include "HvControlIf.h"
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
  static void cVar_AaymSuam_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6giyNETL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_sZ5s1iVH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_ufQ4GwgW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_Knnhwb3J_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_Wcz7WzWV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_xC42wDze_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_vkyD4CNF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_rAClLOSw_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_H7ftZfqm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_JTT122zL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_7YDr0Iqg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_AELrZ2Ko_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_0Vh7LEhu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_jFXcoiPg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cjJiRDOr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Jd5ysXhc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_3y5P4V2U_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_jJOc9BNX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_FBV1lcy3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_xNLlPo1V_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_e4QymLdf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_2DHelPdD_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_EoSecKjI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_NJxukWjy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_wMjcVEo1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_LP3oWV7t_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_4eZvsRPm_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_bBTtV8IN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_5sm8JYf8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DJCEDBwq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_UQT9HAxJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_BoxfpylM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_WHixCWNb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MCEIZhTJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WIA6VWME_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BMPspxET_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_jzQfGko0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_vgUAVeWB_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_XqnvFfnA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_hEHXERXO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_NTC0mvCA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_IVNZYHjh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_pvYPxmvt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_SNuRZOQ0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_3M6Mri4r_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_gO8cLOrs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_wIZ99lW0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_dUpyfaKL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_yff3zfnK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_bZuXaWrF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_AG5zpQcy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_lSueXwBG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_uvzFDHsg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Dq7bONjL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ElJORIDv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_UUIenDCN_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_lqIVLkxJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_7Wrf1oiT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_WY6HMG6w_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_GIJmB4oZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_lKBokOjn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_8KokHKUH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_rccISklN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_H7SYJ6W1_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_oA83vLMm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ML9W6yhG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_u7WZHMSj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_HIy6rrwg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_3WCwzqns_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_6iKcFTkA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_exfgDbBj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bQkgiB8b_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Z2D1AoPy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_d0Yuat9Z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9jYSAvtU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_FgxZ0JO1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_KIknfwje_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_XYDPpnyo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9JB30LYR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Vp3GB4ip_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_GiFpQrWi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_9HvjtDL0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_LrdQeGRU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_X4c1wOBV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_M23qeqGD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_aEJQcPZR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_HYOKKsjG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_QxUtNsV5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_oSfySvk3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_iriXtmCp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_5BD2iV9p_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_kmPUlTiS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_vRzqU9Ox_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gYX6vNvh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_CBFv5OcX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Cp3KJiwV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_0r455zOa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_XYscivxv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ZSntXjca_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_qE4biTdr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_eygmU38y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Vhy9Ljwm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_72vWWyUf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_LmwgQNFu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Y0EhszAC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_uK7Oh3Zy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ih7aRXrH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_pBdIdEdJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YWHjnHsE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vO5Ms71m_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_lsi2VL8T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_C0w3Hs1X_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_6EV6DgMZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_j1vN51QL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_xGdnlqOM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_NAxXAOJi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_etUivJbC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_NUzhTBFB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_T4cqS1IB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_RLCMnNpG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_0mjtASoW_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_LL4hFhfW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_UjCr8Ttb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ZHq5TCu3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_XIS7pFI8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_7jwJfvj3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_tWkCn2oG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_oKmynODN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_D47x7lEH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Em6z35fL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ciet6Cgu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_ImUo7LeJ_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_5nNfCVfH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_WWH4lc5m_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_aK3uPorf_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_2EDI0i1v_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_8BSPdje3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_joRAMf4s_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_nSNuEzbs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_6BNxhmjc_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_AW3ldChZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_QBCAlWsG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_JX7ANc3D_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_3Vsfx1EA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_TeQErGi0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_qNs2lfsT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_NUFQxPx2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_l89cWWiU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_o56S8kpL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KzSRlM1Y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_fiddwMlu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_eOKWse0U_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Os4Cv64b_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_s0C74avW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_eC3H1Nm2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KhsrWRPo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_A1uvxR4z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_C03QPYBD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_9zqZXTbc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_b2YmrDpl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_PTSg5obd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_JJXzkSKU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_fb973VDp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_nzXACSy9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_zl8dPOY2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_V2QFTabO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_mBGoT2yn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_J4wuucPG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_nAuqR6Bb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Wsuhkue2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_aWhTJBhi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_5WTAEww6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_6r0TuwMM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_i2F0c8kK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ELynJXMq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_uuhItCSl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_xLtxndGe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_wEGr10jH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_w07nnW9V_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bJ2oke1q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_NHpDamoq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_aA3aMtlD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VIdmzlYL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_FsikrYT5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gAFDzQ7a_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YZctHESc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_llXpPysK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_QrgtYhZC_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_uvdKTaTE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_QBHT0ZDk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_0lXyvqqF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_3iygS86U_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_M2JYInlJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_TfVfP4uJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_T4bWGBHJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_cjqwhl1k_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_GotDReFN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_iugoe4MU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_KZklkB9D_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_RrU6VvCa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_V9zw9Tef_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_lQIH6uUn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9cKmT8Pk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_zMowwhBY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_GIakfTSX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_GGNAG8zg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_QYR1VOUS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cTabhead_jBFlC4K5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_X22QzULq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_lCzaeyBp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ulYJ5Ij5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_izQjetGY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_Usu8JKBB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void sTabread_gmREo7Wb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_7POsT1QO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ktVGspfV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_V7mdfOlg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_dDtJzNlH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_76t6onwP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_6pCTtImA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_kCkzhH0k_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_smFQPSvR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_PTJP7nVG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_S6z5kEFq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_NuilK1FR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_1AWH8TZn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_kUhSzSf5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_8UsGLTKY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_4HFhLX7W_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_PfkXwHUW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_yjM4O5AR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_0Foe1Iam_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_tNWf4h6c_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_XoffS0EY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_xwMCVRVz_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_LYqDWZmG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_qe1tWlzL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_LPDmqiMV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_d4XpbOTU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_gWdgzk03_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Ib2A2eDH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_9GDdSFH1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_heuGvHrE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_yXu0G02B_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_S9zvT5DJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_54c5hF15_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_RL9nSYlM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_EwrrARxD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_a0cyMkFr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_yfOY0dfO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_pFlz6XqZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_7czPvw98_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Nf1ErkMy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_jk3oMIg7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_r7kQGTot_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_2h1sSiMB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_nt5hkGTx_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_qVTI6UWt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_KDOkZV6l_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_0IcPHgAJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_UZXe5Ker_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Eeg4onnI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_mA5wtt3Z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_uSk3T6cG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_A03Oxra1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_J4dXgGn5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_6hxutXuQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_rGuLufYM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_fgTiouSa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_uIY6Kn7x_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_kzp6vT7Y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_Jk23htjw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_tEwqeRrC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_9RCWM545_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_AD4b4HOg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_C7lbts4s_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_itM8kEum_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_PufbFRIb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_4YYsP28X_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_GZyi7LQH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_z69hWngy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_l1UmFwzA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_flyhqb98_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_Dnc29aY9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_m8vrZqf5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_PXAHcu10_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_XdGY8wuK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_O0N8YS3r_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_d6BbF4d6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_1PohUBjB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_Ozpbg6O8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_d1KEYfGE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_hnsAIm8j_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_fFKoyj6R_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_OrOsaYFt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_hbNUm94R_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_pSZw3WZR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_aKAkqMtP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ttXX9kUs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_2iEglnsD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_WdeEt5vx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_yMx9RnPd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_MLO51Rfg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_hJ7Es7Rs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_rPaq4YKp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_1sJzSHst_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_s321EFxv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_vxsWYCY7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_4edguG1Q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_UhnjyW20_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3JW3qKg1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5lCEcgpE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_hElhGYst_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_3ulkTAI0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_AMWPa46x_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_o50isVRw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4UOfVknK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Wdx2Di9P_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_rySd3zVT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_RF9KxeuC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_HrIQ05x9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_QDF14YyU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_crgKfTyP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_waySxu1W_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_XrmJv1Tt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_jQNnwu9P_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_RQcGz47s_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_Zjy2OJYS_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_VmAPOJyR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_HlNes71z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_oiB3q9er_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_CRpxSnXj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_MuNVHD7l_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_oYgeEYkl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0l9bepjY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_mSWRDxFF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_vJILJWEZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_8DQMOOEk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Rsm8S1Fw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_d85seDaM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_HNC1PHVA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ma9JHPAe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_03hy4Hc1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Eq8baGTX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_fL7MHCc7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8OYZgZIC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Hg2PG2S7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_G9mBqkf4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_psKIkY04_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_FVTRbR5k_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DVU6sTa2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_uZJS3GWf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ogkiUqdp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_IeMWzKb7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_FYic2swv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_lplaENWl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HrgpbMo8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_j1REFVn3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_tsFT8Wsr_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_Cy545AmJ;
  SignalPhasor sPhasor_j1i4fTBC;
  SignalLine sLine_XFm9zecC;
  SignalPhasor sPhasor_bXyNIWmJ;
  SignalLine sLine_qGbFiov5;
  SignalPhasor sPhasor_cc3BH84m;
  SignalLine sLine_JIaJBOYI;
  SignalPhasor sPhasor_Sk5QJxKv;
  SignalPhasor sPhasor_FkXRaxJc;
  SignalTabread sTabread_PxVbxWOm;
  SignalRPole sRPole_Ge2MRIXu;
  SignalLine sLine_5qnKEH7x;
  SignalPhasor sPhasor_qPd4kw7N;
  SignalRPole sRPole_haU9R7Ky;
  SignalDel1 sDel1_Iaprhhpm;
  SignalTabread sTabread_gmREo7Wb;
  SignalTabwrite sTabwrite_IoyIZfBL;
  SignalPhasor sPhasor_3G2Lz06L;
  SignalLine sLine_X69Ir8I5;
  SignalPhasor sPhasor_gaXHzdUd;
  SignalTabread sTabread_jpAzKPrF;
  SignalRPole sRPole_5SykEgRW;
  ControlVar cVar_AaymSuam;
  ControlBinop cBinop_6giyNETL;
  ControlPack cPack_sZ5s1iVH;
  ControlSlice cSlice_ufQ4GwgW;
  ControlSlice cSlice_Knnhwb3J;
  ControlSlice cSlice_Wcz7WzWV;
  ControlSlice cSlice_xC42wDze;
  ControlSlice cSlice_vkyD4CNF;
  SignalVarf sVarf_DSDJJAQs;
  ControlBinop cBinop_cjJiRDOr;
  ControlBinop cBinop_Jd5ysXhc;
  SignalVarf sVarf_58od7xBU;
  SignalVarf sVarf_GX4tbW3s;
  ControlVar cVar_xNLlPo1V;
  ControlVar cVar_e4QymLdf;
  ControlBinop cBinop_EoSecKjI;
  ControlRandom cRandom_wMjcVEo1;
  ControlSlice cSlice_LP3oWV7t;
  ControlDelay cDelay_bBTtV8IN;
  ControlVar cVar_BoxfpylM;
  ControlBinop cBinop_MCEIZhTJ;
  ControlBinop cBinop_WIA6VWME;
  ControlBinop cBinop_BMPspxET;
  ControlVar cVar_jzQfGko0;
  ControlBinop cBinop_XqnvFfnA;
  ControlRandom cRandom_NTC0mvCA;
  ControlSlice cSlice_IVNZYHjh;
  ControlDelay cDelay_gO8cLOrs;
  ControlVar cVar_bZuXaWrF;
  ControlBinop cBinop_lSueXwBG;
  ControlBinop cBinop_uvzFDHsg;
  ControlBinop cBinop_Dq7bONjL;
  ControlVar cVar_ElJORIDv;
  ControlSlice cSlice_GIJmB4oZ;
  ControlSlice cSlice_lKBokOjn;
  ControlVar cVar_8KokHKUH;
  ControlVar cVar_rccISklN;
  ControlVar cVar_ML9W6yhG;
  ControlVar cVar_u7WZHMSj;
  ControlVar cVar_HIy6rrwg;
  ControlSlice cSlice_3WCwzqns;
  ControlSlice cSlice_6iKcFTkA;
  ControlBinop cBinop_exfgDbBj;
  ControlBinop cBinop_bQkgiB8b;
  ControlBinop cBinop_Z2D1AoPy;
  ControlBinop cBinop_d0Yuat9Z;
  ControlBinop cBinop_9jYSAvtU;
  ControlBinop cBinop_XYDPpnyo;
  ControlBinop cBinop_9JB30LYR;
  ControlBinop cBinop_Vp3GB4ip;
  ControlBinop cBinop_GiFpQrWi;
  ControlBinop cBinop_QxUtNsV5;
  ControlBinop cBinop_gYX6vNvh;
  ControlVar cVar_ZSntXjca;
  ControlVar cVar_qE4biTdr;
  ControlVar cVar_eygmU38y;
  ControlBinop cBinop_LmwgQNFu;
  ControlBinop cBinop_Y0EhszAC;
  SignalVarf sVarf_wUHthjko;
  ControlBinop cBinop_ih7aRXrH;
  ControlBinop cBinop_pBdIdEdJ;
  ControlBinop cBinop_YWHjnHsE;
  SignalVarf sVarf_YmrUviDO;
  ControlBinop cBinop_vO5Ms71m;
  HvTable hTable_lsi2VL8T;
  ControlVar cVar_6EV6DgMZ;
  ControlSlice cSlice_NAxXAOJi;
  ControlBinop cBinop_etUivJbC;
  SignalVarf sVarf_wpKlUsaX;
  ControlBinop cBinop_NUzhTBFB;
  ControlDelay cDelay_LL4hFhfW;
  ControlVar cVar_7jwJfvj3;
  ControlBinop cBinop_oKmynODN;
  ControlBinop cBinop_D47x7lEH;
  ControlBinop cBinop_Em6z35fL;
  ControlVar cVar_ciet6Cgu;
  ControlSlice cSlice_2EDI0i1v;
  ControlSlice cSlice_8BSPdje3;
  ControlVar cVar_joRAMf4s;
  ControlVar cVar_nSNuEzbs;
  ControlVar cVar_QBCAlWsG;
  ControlVar cVar_JX7ANc3D;
  ControlVar cVar_3Vsfx1EA;
  ControlSlice cSlice_TeQErGi0;
  ControlSlice cSlice_qNs2lfsT;
  ControlBinop cBinop_NUFQxPx2;
  ControlBinop cBinop_l89cWWiU;
  ControlBinop cBinop_o56S8kpL;
  ControlBinop cBinop_KzSRlM1Y;
  ControlBinop cBinop_fiddwMlu;
  ControlBinop cBinop_s0C74avW;
  ControlBinop cBinop_eC3H1Nm2;
  ControlBinop cBinop_KhsrWRPo;
  ControlBinop cBinop_A1uvxR4z;
  ControlBinop cBinop_nzXACSy9;
  ControlBinop cBinop_Wsuhkue2;
  ControlVar cVar_ELynJXMq;
  ControlVar cVar_uuhItCSl;
  ControlVar cVar_xLtxndGe;
  ControlBinop cBinop_bJ2oke1q;
  ControlBinop cBinop_NHpDamoq;
  SignalVarf sVarf_hhyhVV9R;
  ControlBinop cBinop_VIdmzlYL;
  ControlBinop cBinop_FsikrYT5;
  ControlBinop cBinop_gAFDzQ7a;
  SignalVarf sVarf_P5kJeUfq;
  ControlBinop cBinop_YZctHESc;
  HvTable hTable_llXpPysK;
  ControlVar cVar_uvdKTaTE;
  ControlSlice cSlice_3iygS86U;
  ControlBinop cBinop_M2JYInlJ;
  SignalVarf sVarf_EQIBtitm;
  ControlBinop cBinop_TfVfP4uJ;
  ControlDelay cDelay_GotDReFN;
  ControlDelay cDelay_iugoe4MU;
  ControlBinop cBinop_RrU6VvCa;
  HvTable hTable_V9zw9Tef;
  ControlBinop cBinop_9cKmT8Pk;
  ControlTabhead cTabhead_jBFlC4K5;
  ControlVar cVar_ulYJ5Ij5;
  ControlDelay cDelay_izQjetGY;
  ControlDelay cDelay_Usu8JKBB;
  ControlBinop cBinop_7POsT1QO;
  ControlBinop cBinop_ktVGspfV;
  ControlBinop cBinop_V7mdfOlg;
  ControlBinop cBinop_smFQPSvR;
  ControlBinop cBinop_S6z5kEFq;
  ControlBinop cBinop_NuilK1FR;
  ControlVar cVar_kUhSzSf5;
  ControlVar cVar_8UsGLTKY;
  SignalVarf sVarf_m7M056GW;
  ControlBinop cBinop_PfkXwHUW;
  ControlRandom cRandom_0Foe1Iam;
  ControlSlice cSlice_tNWf4h6c;
  ControlVar cVar_XoffS0EY;
  ControlVar cVar_d4XpbOTU;
  ControlVar cVar_gWdgzk03;
  ControlVar cVar_Ib2A2eDH;
  ControlVar cVar_9GDdSFH1;
  ControlBinop cBinop_S9zvT5DJ;
  SignalVarf sVarf_CN8UHI72;
  ControlVar cVar_fgTiouSa;
  ControlBinop cBinop_kzp6vT7Y;
  ControlRandom cRandom_tEwqeRrC;
  ControlSlice cSlice_9RCWM545;
  ControlIf cIf_AD4b4HOg;
  ControlBinop cBinop_C7lbts4s;
  ControlIf cIf_itM8kEum;
  ControlBinop cBinop_PufbFRIb;
  ControlBinop cBinop_GZyi7LQH;
  ControlRandom cRandom_l1UmFwzA;
  ControlSlice cSlice_flyhqb98;
  ControlIf cIf_Dnc29aY9;
  ControlBinop cBinop_m8vrZqf5;
  ControlIf cIf_PXAHcu10;
  ControlBinop cBinop_XdGY8wuK;
  ControlBinop cBinop_d6BbF4d6;
  ControlRandom cRandom_Ozpbg6O8;
  ControlSlice cSlice_d1KEYfGE;
  ControlIf cIf_hnsAIm8j;
  ControlBinop cBinop_fFKoyj6R;
  ControlIf cIf_OrOsaYFt;
  ControlBinop cBinop_hbNUm94R;
  ControlVar cVar_pSZw3WZR;
  ControlBinop cBinop_UhnjyW20;
  ControlBinop cBinop_3JW3qKg1;
  ControlBinop cBinop_5lCEcgpE;
  ControlBinop cBinop_hElhGYst;
  SignalVarf sVarf_Ga0gnYM9;
  ControlBinop cBinop_AMWPa46x;
  ControlBinop cBinop_o50isVRw;
  ControlBinop cBinop_4UOfVknK;
  ControlBinop cBinop_Wdx2Di9P;
  ControlVar cVar_rySd3zVT;
  ControlVar cVar_RF9KxeuC;
  SignalVarf sVarf_0gFiSTJT;
  ControlBinop cBinop_VmAPOJyR;
  ControlRandom cRandom_oiB3q9er;
  ControlSlice cSlice_CRpxSnXj;
  SignalVari sVari_9xWEeNdV;
  ControlBinop cBinop_oYgeEYkl;
  ControlBinop cBinop_0l9bepjY;
  SignalVarf sVarf_CxBm4ln3;
  ControlVar cVar_mSWRDxFF;
  ControlBinop cBinop_Rsm8S1Fw;
  ControlBinop cBinop_d85seDaM;
  ControlBinop cBinop_ma9JHPAe;
  ControlBinop cBinop_03hy4Hc1;
  ControlBinop cBinop_Eq8baGTX;
  ControlBinop cBinop_fL7MHCc7;
  ControlBinop cBinop_8OYZgZIC;
  SignalVarf sVarf_2iA8Hm9A;
  ControlBinop cBinop_DVU6sTa2;
  ControlBinop cBinop_uZJS3GWf;
  ControlBinop cBinop_ogkiUqdp;
  ControlBinop cBinop_IeMWzKb7;
  ControlBinop cBinop_FYic2swv;
  ControlBinop cBinop_HrgpbMo8;
};

#endif // _HEAVY_CONTEXT_PROG_HPP_
