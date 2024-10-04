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

#include "Heavy_prog.hpp"

#include <new>

#define Context(_c) static_cast<Heavy_prog *>(_c)


/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_prog_new(double sampleRate) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_prog));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_prog(sampleRate);
    return Context(ptr);
  }

  HV_EXPORT HeavyContextInterface *hv_prog_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_prog));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_prog(sampleRate, poolKb, inQueueKb, outQueueKb);
    return Context(ptr);
  }

  HV_EXPORT void hv_prog_free(HeavyContextInterface *instance) {
    // call destructor
    Context(instance)->~Heavy_prog();
    // free memory
    hv_free(instance);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_prog::Heavy_prog(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sPhasor_k_init(&sPhasor_kG0jqmqW, 0.0f, sampleRate);
  numBytes += sDel1_init(&sDel1_hSyuXkW6);
  numBytes += sSamphold_init(&sSamphold_iMqXbhDY);
  numBytes += sRPole_init(&sRPole_l95GvnCm);
  numBytes += sDel1_init(&sDel1_B82cpUDL);
  numBytes += sLine_init(&sLine_4fpzOE9t);
  numBytes += sPhasor_init(&sPhasor_Dvyw69vN, sampleRate);
  numBytes += sLine_init(&sLine_RBQizvZ5);
  numBytes += sTabhead_init(&sTabhead_Iyc2DSsv, &hTable_1aYRT8cO);
  numBytes += sTabread_init(&sTabread_Nkg5TmFf, &hTable_1aYRT8cO, false);
  numBytes += sTabread_init(&sTabread_jyu4FqkL, &hTable_1aYRT8cO, false);
  numBytes += sLine_init(&sLine_6oZu4BrQ);
  numBytes += sLine_init(&sLine_ZIeSyHu5);
  numBytes += sTabhead_init(&sTabhead_aP4CmbsV, &hTable_NSkeEpty);
  numBytes += sTabread_init(&sTabread_sUepTZ4s, &hTable_NSkeEpty, false);
  numBytes += sTabread_init(&sTabread_aLrVZTxD, &hTable_NSkeEpty, false);
  numBytes += sLine_init(&sLine_KAckL2vt);
  numBytes += sTabwrite_init(&sTabwrite_7mJnEhGn, &hTable_1aYRT8cO);
  numBytes += sTabwrite_init(&sTabwrite_L2RPHpTJ, &hTable_NSkeEpty);
  numBytes += sPhasor_k_init(&sPhasor_JjjOFbU2, 700.0f, sampleRate);
  numBytes += sLine_init(&sLine_W5J15VYc);
  numBytes += sRPole_init(&sRPole_RTSjMk0x);
  numBytes += sLine_init(&sLine_E1zc1LNI);
  numBytes += sPhasor_init(&sPhasor_liJxjIhL, sampleRate);
  numBytes += cRandom_init(&cRandom_3MWDTDjD, -984571588);
  numBytes += cSlice_init(&cSlice_E9e5QwVB, 1, 1);
  numBytes += sVari_init(&sVari_OBeaNEks, 0, 0, false);
  numBytes += cVar_init_f(&cVar_yYUkpBV7, 1.0f);
  numBytes += cVar_init_f(&cVar_AEcZ4vUh, 0.0f);
  numBytes += cVar_init_f(&cVar_6apeTkQl, 0.0f);
  numBytes += cVar_init_f(&cVar_GbXiXSRH, 0.0f);
  numBytes += cBinop_init(&cBinop_MqnaKaHc, 29.0f); // __div
  numBytes += sVarf_init(&sVarf_eYV9GUiW, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_3NO5qWok, 22050.0f);
  numBytes += cBinop_init(&cBinop_X574sfrk, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_5l9cAdVg, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_wx94e9Lh, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_Vr13dM1k, 0.0f);
  numBytes += sVarf_init(&sVarf_YbR5L0RU, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_nkC9aZjZ, 8000.0f);
  numBytes += cBinop_init(&cBinop_iQtFbVbm, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_rkVKnEft, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_4bdvp9nF, 0.0f);
  numBytes += cPack_init(&cPack_ImVEHuKd, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_PMb6srW1, 2, 0.0f, 0.0f);
  numBytes += cVar_init_s(&cVar_rYRlLLsC, "del-1043-inputdelay");
  numBytes += sVarf_init(&sVarf_t7z7Wd9L, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Lq5EhWWr, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_IsExpAKk, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_ownfogpN, "del-1043-outputdelay");
  numBytes += sVarf_init(&sVarf_ux8ybj3W, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_RS1PbHBs, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_8J8NuE1j, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_vIx3GlUr, 0.0f);
  numBytes += cDelay_init(this, &cDelay_z8xAowZt, 0.0f);
  numBytes += hTable_init(&hTable_1aYRT8cO, 256);
  numBytes += cDelay_init(this, &cDelay_TLhCJ9x1, 0.0f);
  numBytes += cDelay_init(this, &cDelay_elTMDd85, 0.0f);
  numBytes += hTable_init(&hTable_NSkeEpty, 256);
  numBytes += cVar_init_f(&cVar_qEby0j2q, 0.0f);
  numBytes += cDelay_init(this, &cDelay_mNwfmiH4, 0.0f);
  numBytes += cVar_init_f(&cVar_jkVbSv1L, 360.0f);
  numBytes += cBinop_init(&cBinop_S5cQuNLy, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_L3ILxl4X, 0.0f);
  numBytes += cVar_init_f(&cVar_V7OXJevk, 240.0f);
  numBytes += cBinop_init(&cBinop_TTS0ckFl, 0.0f); // __mul
  numBytes += cRandom_init(&cRandom_Pd05n4tb, -476193022);
  numBytes += cSlice_init(&cSlice_PeWNarRz, 1, 1);
  numBytes += cRandom_init(&cRandom_065Fn4Zz, 1347160718);
  numBytes += cSlice_init(&cSlice_p4Pl7qjr, 1, 1);
  numBytes += cRandom_init(&cRandom_Kwy4seke, 1718203060);
  numBytes += cSlice_init(&cSlice_iYpyJEVG, 1, 1);
  numBytes += cRandom_init(&cRandom_vTuQTrgY, -797332714);
  numBytes += cSlice_init(&cSlice_HSURXpFS, 1, 1);
  numBytes += cBinop_init(&cBinop_fmEKaNRx, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_znQkF9oG, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_kQvbYgxJ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_QmcOOABT, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_prog::~Heavy_prog() {
  cPack_free(&cPack_ImVEHuKd);
  cPack_free(&cPack_PMb6srW1);
  hTable_free(&hTable_1aYRT8cO);
  hTable_free(&hTable_NSkeEpty);
}

HvTable *Heavy_prog::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0xD5A8996D: return &hTable_1aYRT8cO; // del-1043-inputdelay
    case 0x75415931: return &hTable_NSkeEpty; // del-1043-outputdelay
    default: return nullptr;
  }
}

void Heavy_prog::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_hNMSl3rL_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_prog::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      default: {
        info->name = "invalid parameter index";
        info->hash = 0;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 0.0f;
        info->defaultVal = 0.0f;
        break;
      }
    }
  }
  return 0;
}



/*
 * Send Function Implementations
 */


void Heavy_prog::cSwitchcase_9EhrZJZK_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_E9e5QwVB, 0, m, &cSlice_E9e5QwVB_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_3MWDTDjD, 0, m, &cRandom_3MWDTDjD_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_dMyuGgFO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_2mJikNID_sendMessage);
}

void Heavy_prog::cUnop_2mJikNID_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LdxIDLyR_sendMessage(_c, 0, m);
}

void Heavy_prog::cRandom_3MWDTDjD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_dMyuGgFO_sendMessage);
}

void Heavy_prog::cSlice_E9e5QwVB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_3MWDTDjD, 1, m, &cRandom_3MWDTDjD_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cMsg_LdxIDLyR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_OBeaNEks, m);
}

void Heavy_prog::cVar_yYUkpBV7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_VpNxX2Gv_sendMessage);
  cSwitchcase_BzLJ2IMt_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_c1iq7j63_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_VpNxX2Gv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yYUkpBV7, 1, m, &cVar_yYUkpBV7_sendMessage);
}

void Heavy_prog::cVar_AEcZ4vUh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_qSTzNEip_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cVar_6apeTkQl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 30.0f, 0, m, &cBinop_FUtyx7NF_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_fmEKaNRx, HV_BINOP_MULTIPLY, 1, m, &cBinop_fmEKaNRx_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_tcRGxL3A_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_YiUp0t0Y_sendMessage);
}

void Heavy_prog::cVar_GbXiXSRH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_kG0jqmqW, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 16.0f, 0, m, &cBinop_3b6pN2yV_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_fmEKaNRx, HV_BINOP_MULTIPLY, 0, m, &cBinop_fmEKaNRx_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_kQvbYgxJ, m);
}

void Heavy_prog::cSwitchcase_qSTzNEip_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3pe6Myd5_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vqwMkpPD_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WvzR7yRY_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_3pe6Myd5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iESzV0Tk_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1MOxEvol_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kgV5Xii6_sendMessage);
}

void Heavy_prog::cCast_vqwMkpPD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KidnOlPr_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PakQAMn7_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SRusE5Bg_sendMessage);
}

void Heavy_prog::cCast_WvzR7yRY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iWjIjvCq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oiOsT6Tb_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9auqy9zD_sendMessage);
}

void Heavy_prog::cCast_ALpKcDlr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MqnaKaHc, HV_BINOP_DIVIDE, 0, m, &cBinop_MqnaKaHc_sendMessage);
}

void Heavy_prog::cCast_2YWemfAZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fGP7HJVa_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_iWjIjvCq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_oiOsT6Tb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tZsXtI6T_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_9auqy9zD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GQftutnu_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_PakQAMn7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HH09uQul_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_KidnOlPr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_SRusE5Bg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GQftutnu_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_iESzV0Tk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_kgV5Xii6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GQftutnu_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_1MOxEvol_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_d4l7Ig2Z_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_fGP7HJVa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_E1zc1LNI, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_E1zc1LNI, 0, m, NULL);
}

void Heavy_prog::cBinop_MqnaKaHc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_eYV9GUiW, m);
}

void Heavy_prog::cMsg_GQftutnu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 110.0f);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2YWemfAZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ALpKcDlr_sendMessage);
}

void Heavy_prog::cMsg_tZsXtI6T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.1f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_MqnaKaHc, HV_BINOP_DIVIDE, 1, m, &cBinop_MqnaKaHc_sendMessage);
}

void Heavy_prog::cMsg_HH09uQul_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.9f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_MqnaKaHc, HV_BINOP_DIVIDE, 1, m, &cBinop_MqnaKaHc_sendMessage);
}

void Heavy_prog::cMsg_d4l7Ig2Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 5.5f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_MqnaKaHc, HV_BINOP_DIVIDE, 1, m, &cBinop_MqnaKaHc_sendMessage);
}

void Heavy_prog::cVar_3NO5qWok_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_X574sfrk, HV_BINOP_MULTIPLY, 0, m, &cBinop_X574sfrk_sendMessage);
}

void Heavy_prog::cMsg_M3O1K1MV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_VNn7z054_sendMessage);
}

void Heavy_prog::cSystem_VNn7z054_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iJiKvzp3_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_X574sfrk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_PpsQD4oC_sendMessage);
}

void Heavy_prog::cBinop_ae412CYQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_X574sfrk, HV_BINOP_MULTIPLY, 1, m, &cBinop_X574sfrk_sendMessage);
}

void Heavy_prog::cMsg_iJiKvzp3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_ae412CYQ_sendMessage);
}

void Heavy_prog::cBinop_PpsQD4oC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_SDJgk9iq_sendMessage);
}

void Heavy_prog::cBinop_SDJgk9iq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Kln7V72W_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_wx94e9Lh, m);
}

void Heavy_prog::cBinop_Kln7V72W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_5l9cAdVg, m);
}

void Heavy_prog::cVar_Vr13dM1k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3NO5qWok, 0, m, &cVar_3NO5qWok_sendMessage);
  cMsg_zqTpiVZY_sendMessage(_c, 0, m);
}

void Heavy_prog::cSwitchcase_WhQ2upUc_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FTznpuhl_sendMessage);
      break;
    }
    default: {
      cMsg_U7dpEWOy_sendMessage(_c, 0, m);
      break;
    }
  }
}

void Heavy_prog::cCast_FTznpuhl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DiVfrivO_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_B49mlDnf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_OrK6GuIb_sendMessage);
}

void Heavy_prog::cBinop_OrK6GuIb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_de4xblQU_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_y7mMuzYN_sendMessage);
}

void Heavy_prog::cVar_nkC9aZjZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_UykblolF_sendMessage);
}

void Heavy_prog::cMsg_PtPCRK33_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Q5tI5s2F_sendMessage);
}

void Heavy_prog::cSystem_Q5tI5s2F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iQtFbVbm, HV_BINOP_DIVIDE, 1, m, &cBinop_iQtFbVbm_sendMessage);
}

void Heavy_prog::cBinop_de4xblQU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_rXgSKXGx_sendMessage);
}

void Heavy_prog::cBinop_rXgSKXGx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_rkVKnEft, m);
}

void Heavy_prog::cMsg_QWRJBYiw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_EUtTXbk0_sendMessage);
}

void Heavy_prog::cBinop_EUtTXbk0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_B49mlDnf_sendMessage);
}

void Heavy_prog::cBinop_y7mMuzYN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_YbR5L0RU, m);
}

void Heavy_prog::cBinop_UykblolF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_n2ldLcf9_sendMessage);
}

void Heavy_prog::cBinop_n2ldLcf9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iQtFbVbm, HV_BINOP_DIVIDE, 0, m, &cBinop_iQtFbVbm_sendMessage);
}

void Heavy_prog::cBinop_iQtFbVbm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QWRJBYiw_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_4bdvp9nF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3NO5qWok, 0, m, &cVar_3NO5qWok_sendMessage);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_kG0jqmqW, 1, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1000.0f, 0, m, &cBinop_QahRpaGy_sendMessage);
}

void Heavy_prog::cPack_ImVEHuKd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_RBQizvZ5, 0, m, NULL);
}

void Heavy_prog::cPack_PMb6srW1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_ZIeSyHu5, 0, m, NULL);
}

void Heavy_prog::cMsg_LtPpyodB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zzlGNXLy_sendMessage);
}

void Heavy_prog::cSystem_zzlGNXLy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ywoyqnWL_sendMessage);
}

void Heavy_prog::cVar_rYRlLLsC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IsJRFDSR_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_LuWAHQKg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_R9HiRxtZ_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_t7z7Wd9L, m);
}

void Heavy_prog::cBinop_ywoyqnWL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Lq5EhWWr, m);
}

void Heavy_prog::cMsg_IsJRFDSR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_LuWAHQKg_sendMessage);
}

void Heavy_prog::cBinop_R9HiRxtZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_IsExpAKk, m);
}

void Heavy_prog::cMsg_5eFQ8jl4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_CRxtkdUG_sendMessage);
}

void Heavy_prog::cSystem_CRxtkdUG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_F1mWPRtF_sendMessage);
}

void Heavy_prog::cVar_ownfogpN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mW918oe2_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_veVFd0hV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_QVcwgVuW_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ux8ybj3W, m);
}

void Heavy_prog::cBinop_F1mWPRtF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_RS1PbHBs, m);
}

void Heavy_prog::cMsg_mW918oe2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_veVFd0hV_sendMessage);
}

void Heavy_prog::cBinop_QVcwgVuW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_8J8NuE1j, m);
}

void Heavy_prog::cMsg_vRgk66Ai_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JZI3CJe1_sendMessage);
}

void Heavy_prog::cSystem_JZI3CJe1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_wLDdZ5PE_sendMessage);
}

void Heavy_prog::cDelay_vIx3GlUr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_vIx3GlUr, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_z8xAowZt, 0, m, &cDelay_z8xAowZt_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vIx3GlUr, 0, m, &cDelay_vIx3GlUr_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_7mJnEhGn, 1, m, NULL);
}

void Heavy_prog::cDelay_z8xAowZt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_z8xAowZt, m);
  cMsg_jJA4ny9f_sendMessage(_c, 0, m);
}

void Heavy_prog::cSwitchcase_mMeVVbKd_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_5upfJICq_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cBinop_1ZPGs9bp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XP6HLyt8_sendMessage(_c, 0, m);
}

void Heavy_prog::hTable_1aYRT8cO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oVdildAM_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vIx3GlUr, 2, m, &cDelay_vIx3GlUr_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JY90oWFU_sendMessage);
}

void Heavy_prog::cMsg_XP6HLyt8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_1aYRT8cO, 0, m, &hTable_1aYRT8cO_sendMessage);
}

void Heavy_prog::cBinop_wLDdZ5PE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 50.0f, 0, m, &cBinop_1ZPGs9bp_sendMessage);
}

void Heavy_prog::cMsg_jJA4ny9f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_1aYRT8cO, 0, m, &hTable_1aYRT8cO_sendMessage);
}

void Heavy_prog::cCast_JY90oWFU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_vIx3GlUr, 0, m, &cDelay_vIx3GlUr_sendMessage);
}

void Heavy_prog::cMsg_oVdildAM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_z8xAowZt, 2, m, &cDelay_z8xAowZt_sendMessage);
}

void Heavy_prog::cMsg_5upfJICq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_7mJnEhGn, 1, m, NULL);
}

void Heavy_prog::cMsg_BlhjL7Yg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_lcFv5wq1_sendMessage);
}

void Heavy_prog::cSystem_lcFv5wq1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_0pcg2RFE_sendMessage);
}

void Heavy_prog::cDelay_TLhCJ9x1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_TLhCJ9x1, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_elTMDd85, 0, m, &cDelay_elTMDd85_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_TLhCJ9x1, 0, m, &cDelay_TLhCJ9x1_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_L2RPHpTJ, 1, m, NULL);
}

void Heavy_prog::cDelay_elTMDd85_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_elTMDd85, m);
  cMsg_DmveDmSo_sendMessage(_c, 0, m);
}

void Heavy_prog::cSwitchcase_FKt4qxhq_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_FMeWFyLY_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cBinop_WQOcO5NN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PN6oCOvi_sendMessage(_c, 0, m);
}

void Heavy_prog::hTable_NSkeEpty_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4nBkliCU_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_TLhCJ9x1, 2, m, &cDelay_TLhCJ9x1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7Ld6kJjZ_sendMessage);
}

void Heavy_prog::cMsg_PN6oCOvi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_NSkeEpty, 0, m, &hTable_NSkeEpty_sendMessage);
}

void Heavy_prog::cBinop_0pcg2RFE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 50.0f, 0, m, &cBinop_WQOcO5NN_sendMessage);
}

void Heavy_prog::cMsg_DmveDmSo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_NSkeEpty, 0, m, &hTable_NSkeEpty_sendMessage);
}

void Heavy_prog::cCast_7Ld6kJjZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_TLhCJ9x1, 0, m, &cDelay_TLhCJ9x1_sendMessage);
}

void Heavy_prog::cMsg_4nBkliCU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_elTMDd85, 2, m, &cDelay_elTMDd85_sendMessage);
}

void Heavy_prog::cMsg_FMeWFyLY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_L2RPHpTJ, 1, m, NULL);
}

void Heavy_prog::cBinop_Lpo3pGNF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_xrPItjzL_sendMessage);
}

void Heavy_prog::cBinop_xrPItjzL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_O88Fm2Vq_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_It94o0f3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_shGKpRtI_sendMessage);
}

void Heavy_prog::cBinop_shGKpRtI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YSmz5fPc_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_QahRpaGy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_RoegVcba_sendMessage);
}

void Heavy_prog::cBinop_RoegVcba_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_kl3Lwf3r_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_r1EM4Uyr_sendMessage);
}

void Heavy_prog::cMsg_YSmz5fPc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_KAckL2vt, 0, m, NULL);
}

void Heavy_prog::cMsg_O88Fm2Vq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_6oZu4BrQ, 0, m, NULL);
}

void Heavy_prog::cBinop_kQ0BzeKD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_PMb6srW1, 0, m, &cPack_PMb6srW1_sendMessage);
}

void Heavy_prog::cBinop_t8zONssy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ImVEHuKd, 0, m, &cPack_ImVEHuKd_sendMessage);
}

void Heavy_prog::cCast_r1EM4Uyr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ImVEHuKd, 1, m, &cPack_ImVEHuKd_sendMessage);
}

void Heavy_prog::cCast_kl3Lwf3r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_PMb6srW1, 1, m, &cPack_PMb6srW1_sendMessage);
}

void Heavy_prog::cMsg_aqMjIGM0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 50.0f, 0, m, &cBinop_t8zONssy_sendMessage);
}

void Heavy_prog::cMsg_hvMUH6cG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 50.0f, 0, m, &cBinop_kQ0BzeKD_sendMessage);
}

void Heavy_prog::cMsg_tHh39JNR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.95f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 0.999f, 0, m, &cBinop_It94o0f3_sendMessage);
}

void Heavy_prog::cVar_qEby0j2q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 0.999f, 0, m, &cBinop_Lpo3pGNF_sendMessage);
}

void Heavy_prog::cSwitchcase_BzLJ2IMt_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_wPGlNWuR_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_wPGlNWuR_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_R0CVrAzQ_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_mNwfmiH4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_mNwfmiH4, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mNwfmiH4, 0, m, &cDelay_mNwfmiH4_sendMessage);
  cSwitchcase_TyRVw9Ye_onMessage(_c, NULL, 0, m, NULL);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RQNalBK2_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6qR8QKpL_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vhVUZ4Cq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_phfHL6OB_sendMessage);
}

void Heavy_prog::cCast_R0CVrAzQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wPGlNWuR_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mNwfmiH4, 0, m, &cDelay_mNwfmiH4_sendMessage);
  cSwitchcase_TyRVw9Ye_onMessage(_c, NULL, 0, m, NULL);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RQNalBK2_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6qR8QKpL_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vhVUZ4Cq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_phfHL6OB_sendMessage);
}

void Heavy_prog::cMsg_Sqr7wbEY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_aOsWTqhU_sendMessage);
}

void Heavy_prog::cSystem_aOsWTqhU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_2T3l7PWz_sendMessage);
}

void Heavy_prog::cVar_jkVbSv1L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_S5cQuNLy, HV_BINOP_MULTIPLY, 0, m, &cBinop_S5cQuNLy_sendMessage);
}

void Heavy_prog::cMsg_wPGlNWuR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_mNwfmiH4, 0, m, &cDelay_mNwfmiH4_sendMessage);
}

void Heavy_prog::cBinop_za6LErkF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_mNwfmiH4, 2, m, &cDelay_mNwfmiH4_sendMessage);
}

void Heavy_prog::cBinop_2T3l7PWz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_S5cQuNLy, HV_BINOP_MULTIPLY, 1, m, &cBinop_S5cQuNLy_sendMessage);
}

void Heavy_prog::cBinop_S5cQuNLy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_za6LErkF_sendMessage);
}

void Heavy_prog::cSwitchcase_c1iq7j63_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_VM9YaCkS_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_VM9YaCkS_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Umx4GQug_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_L3ILxl4X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_L3ILxl4X, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_L3ILxl4X, 0, m, &cDelay_L3ILxl4X_sendMessage);
  cSwitchcase_YpP3yUWl_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_alSEijKW_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_Umx4GQug_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VM9YaCkS_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_L3ILxl4X, 0, m, &cDelay_L3ILxl4X_sendMessage);
  cSwitchcase_YpP3yUWl_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_alSEijKW_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_0L73rrGu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_TOzku0hC_sendMessage);
}

void Heavy_prog::cSystem_TOzku0hC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_KQmd8IJ4_sendMessage);
}

void Heavy_prog::cVar_V7OXJevk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TTS0ckFl, HV_BINOP_MULTIPLY, 0, m, &cBinop_TTS0ckFl_sendMessage);
}

void Heavy_prog::cMsg_VM9YaCkS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_L3ILxl4X, 0, m, &cDelay_L3ILxl4X_sendMessage);
}

void Heavy_prog::cBinop_AYjaw31S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_L3ILxl4X, 2, m, &cDelay_L3ILxl4X_sendMessage);
}

void Heavy_prog::cBinop_KQmd8IJ4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TTS0ckFl, HV_BINOP_MULTIPLY, 1, m, &cBinop_TTS0ckFl_sendMessage);
}

void Heavy_prog::cBinop_TTS0ckFl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_AYjaw31S_sendMessage);
}

void Heavy_prog::cSwitchcase_TyRVw9Ye_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_PeWNarRz, 0, m, &cSlice_PeWNarRz_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Pd05n4tb, 0, m, &cRandom_Pd05n4tb_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_JtsLO7Xa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_If0JkTVZ_sendMessage);
}

void Heavy_prog::cUnop_If0JkTVZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GbXiXSRH, 0, m, &cVar_GbXiXSRH_sendMessage);
}

void Heavy_prog::cRandom_Pd05n4tb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.0f, 0, m, &cBinop_JtsLO7Xa_sendMessage);
}

void Heavy_prog::cSlice_PeWNarRz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Pd05n4tb, 1, m, &cRandom_Pd05n4tb_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_YpP3yUWl_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_p4Pl7qjr, 0, m, &cSlice_p4Pl7qjr_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_065Fn4Zz, 0, m, &cRandom_065Fn4Zz_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_jZFGOfet_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_WeOGdJcP_sendMessage);
}

void Heavy_prog::cUnop_WeOGdJcP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6apeTkQl, 0, m, &cVar_6apeTkQl_sendMessage);
}

void Heavy_prog::cRandom_065Fn4Zz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 120.0f, 0, m, &cBinop_jZFGOfet_sendMessage);
}

void Heavy_prog::cSlice_p4Pl7qjr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_065Fn4Zz, 1, m, &cRandom_065Fn4Zz_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cCast_vhVUZ4Cq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yS4GL5Ap_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_phfHL6OB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_46wvpChK_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_46wvpChK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 40.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_W5J15VYc, 0, m, NULL);
}

void Heavy_prog::cMsg_yS4GL5Ap_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.1f);
  sLine_onMessage(_c, &Context(_c)->sLine_W5J15VYc, 0, m, NULL);
}

void Heavy_prog::cSwitchcase_alSEijKW_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_iYpyJEVG, 0, m, &cSlice_iYpyJEVG_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Kwy4seke, 0, m, &cRandom_Kwy4seke_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_W7Tst3aH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_YnPKU0vu_sendMessage);
}

void Heavy_prog::cUnop_YnPKU0vu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_AEcZ4vUh, 0, m, &cVar_AEcZ4vUh_sendMessage);
}

void Heavy_prog::cRandom_Kwy4seke_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 3.0f, 0, m, &cBinop_W7Tst3aH_sendMessage);
}

void Heavy_prog::cSlice_iYpyJEVG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Kwy4seke, 1, m, &cRandom_Kwy4seke_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_mb6OpclG_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_HSURXpFS, 0, m, &cSlice_HSURXpFS_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_vTuQTrgY, 0, m, &cRandom_vTuQTrgY_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_pXmyEwI8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_J2Cj8JPm_sendMessage);
}

void Heavy_prog::cUnop_J2Cj8JPm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_WhQ2upUc_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cRandom_vTuQTrgY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 9.0f, 0, m, &cBinop_pXmyEwI8_sendMessage);
}

void Heavy_prog::cSlice_HSURXpFS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_vTuQTrgY, 1, m, &cRandom_vTuQTrgY_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_FUtyx7NF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Vr13dM1k, 0, m, &cVar_Vr13dM1k_sendMessage);
}

void Heavy_prog::cMsg_e7JKsv8d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_4fpzOE9t, 0, m, NULL);
}

void Heavy_prog::cMsg_U7dpEWOy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_4fpzOE9t, 0, m, NULL);
}

void Heavy_prog::cCast_RQNalBK2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_e7JKsv8d_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_6qR8QKpL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_mb6OpclG_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_DiVfrivO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 80.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_4fpzOE9t, 0, m, NULL);
}

void Heavy_prog::cBinop_3b6pN2yV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_QmcOOABT, m);
}

void Heavy_prog::cBinop_OC0j9QZC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4bdvp9nF, 0, m, &cVar_4bdvp9nF_sendMessage);
}

void Heavy_prog::cBinop_fmEKaNRx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 110.0f, 0, m, &cBinop_OC0j9QZC_sendMessage);
}

void Heavy_prog::cBinop_tcRGxL3A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qEby0j2q, 0, m, &cVar_qEby0j2q_sendMessage);
}

void Heavy_prog::cBinop_YiUp0t0Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_znQkF9oG, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_kQvbYgxJ, m);
}

void Heavy_prog::cMsg_zqTpiVZY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "seed");
  msg_setFloat(m, 1, 123456.0f);
  cMsg_LdxIDLyR_sendMessage(_c, 0, m);
}

void Heavy_prog::cReceive_hNMSl3rL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vRgk66Ai_sendMessage(_c, 0, m);
  cMsg_BlhjL7Yg_sendMessage(_c, 0, m);
  cSwitchcase_9EhrZJZK_onMessage(_c, NULL, 0, m, NULL);
  cMsg_M3O1K1MV_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_3NO5qWok, 0, m, &cVar_3NO5qWok_sendMessage);
  cMsg_PtPCRK33_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_nkC9aZjZ, 0, m, &cVar_nkC9aZjZ_sendMessage);
  cMsg_aqMjIGM0_sendMessage(_c, 0, m);
  cMsg_hvMUH6cG_sendMessage(_c, 0, m);
  cMsg_tHh39JNR_sendMessage(_c, 0, m);
  cMsg_Sqr7wbEY_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_jkVbSv1L, 0, m, &cVar_jkVbSv1L_sendMessage);
  cMsg_0L73rrGu_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_V7OXJevk, 0, m, &cVar_V7OXJevk_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_yYUkpBV7, 0, m, &cVar_yYUkpBV7_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_rYRlLLsC, 0, m, &cVar_rYRlLLsC_sendMessage);
  cMsg_LtPpyodB_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ownfogpN, 0, m, &cVar_ownfogpN_sendMessage);
  cMsg_5eFQ8jl4_sendMessage(_c, 0, m);
}




/*
 * Context Process Implementation
 */

int Heavy_prog::process(float **inputBuffers, float **outputBuffers, int n) {
  while (hLp_hasData(&inQueue)) {
    hv_uint32_t numBytes = 0;
    ReceiverMessagePair *p = reinterpret_cast<ReceiverMessagePair *>(hLp_getReadBuffer(&inQueue, &numBytes));
    hv_assert(numBytes >= sizeof(ReceiverMessagePair));
    scheduleMessageForReceiver(p->receiverHash, &p->msg);
    hLp_consume(&inQueue);
  }

  sendBangToReceiver(0xDD21C0EB); // send to __hv_bang~ on next cycle
  const int n4 = n & ~HV_N_SIMD_MASK; // ensure that the block size is a multiple of HV_N_SIMD

  // temporary signal vars
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5, Bf6, Bf7, Bf8, Bf9, Bf10, Bf11, Bf12, Bf13, Bf14, Bf15;
  hv_bufferi_t Bi0, Bi1;

  // input and output vars
  hv_bufferf_t O0, O1;

  // declare and init the zero buffer
  hv_bufferf_t ZERO; __hv_zero_f(VOf(ZERO));

  hv_uint32_t nextBlock = blockStartTimestamp;
  for (int n = 0; n < n4; n += HV_N_SIMD) {

    // process all of the messages for this block
    nextBlock += HV_N_SIMD;
    while (mq_hasMessageBefore(&mq, nextBlock)) {
      MessageNode *const node = mq_peek(&mq);
      node->sendMessage(this, node->let, node->m);
      mq_pop(&mq);
    }

    

    // zero output buffers
    __hv_zero_f(VOf(O0));
    __hv_zero_f(VOf(O1));

    // process all signal functions
    __hv_varread_i(&sVari_OBeaNEks, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varwrite_i(&sVari_OBeaNEks, VIi(Bi1));
    __hv_phasor_k_f(&sPhasor_kG0jqmqW, VOf(Bf0));
    __hv_del1_f(&sDel1_hSyuXkW6, VIf(Bf0), VOf(Bf2));
    __hv_lt_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_samphold_f(&sSamphold_iMqXbhDY, VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_YbR5L0RU, VOf(Bf3));
    __hv_rpole_f(&sRPole_l95GvnCm, VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_B82cpUDL, VIf(Bf3), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_rkVKnEft, VOf(Bf3));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_4fpzOE9t, VOf(Bf4));
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf2), VIf(Bf4), VOf(Bf3));
    __hv_varread_f(&sVarf_znQkF9oG, VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf3), 128.0f, 128.0f, 128.0f, 128.0f, 128.0f, 128.0f, 128.0f, 128.0f);
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_phasor_f(&sPhasor_Dvyw69vN, VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_abs_f(VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf0), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf0), VOf(Bf3));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf7), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf8), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf6), VIf(Bf8), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf3), VIf(Bf7), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf0), VIf(Bf4), VOf(Bf7));
    __hv_line_f(&sLine_RBQizvZ5, VOf(Bf3));
    __hv_tabhead_f(&sTabhead_Iyc2DSsv, VOf(Bf8));
    __hv_var_k_f_r(VOf(Bf6), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_Lq5EhWWr, VOf(Bf8));
    __hv_mul_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_IsExpAKk, VOf(Bf3));
    __hv_min_f(VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_zero_f(VOf(Bf8));
    __hv_max_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_floor_f(VIf(Bf8), VOf(Bf6));
    __hv_varread_f(&sVarf_t7z7Wd9L, VOf(Bf3));
    __hv_zero_f(VOf(Bf9));
    __hv_lt_f(VIf(Bf6), VIf(Bf9), VOf(Bf9));
    __hv_and_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf6), VIf(Bf9), VOf(Bf9));
    __hv_cast_fi(VIf(Bf9), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_Nkg5TmFf, VIi(Bi0), VOf(Bf9));
    __hv_tabread_if(&sTabread_jyu4FqkL, VIi(Bi1), VOf(Bf3));
    __hv_sub_f(VIf(Bf9), VIf(Bf3), VOf(Bf9));
    __hv_sub_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf9), VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_6oZu4BrQ, VOf(Bf6));
    __hv_fma_f(VIf(Bf3), VIf(Bf6), VIf(Bf7), VOf(Bf6));
    __hv_line_f(&sLine_ZIeSyHu5, VOf(Bf3));
    __hv_tabhead_f(&sTabhead_aP4CmbsV, VOf(Bf9));
    __hv_var_k_f_r(VOf(Bf8), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_RS1PbHBs, VOf(Bf9));
    __hv_mul_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_8J8NuE1j, VOf(Bf3));
    __hv_min_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_zero_f(VOf(Bf9));
    __hv_max_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_floor_f(VIf(Bf9), VOf(Bf8));
    __hv_varread_f(&sVarf_ux8ybj3W, VOf(Bf3));
    __hv_zero_f(VOf(Bf10));
    __hv_lt_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_and_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_add_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_cast_fi(VIf(Bf10), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_sUepTZ4s, VIi(Bi0), VOf(Bf10));
    __hv_tabread_if(&sTabread_aLrVZTxD, VIi(Bi1), VOf(Bf3));
    __hv_sub_f(VIf(Bf10), VIf(Bf3), VOf(Bf10));
    __hv_sub_f(VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf10), VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_KAckL2vt, VOf(Bf8));
    __hv_mul_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_tabwrite_f(&sTabwrite_7mJnEhGn, VIf(Bf7));
    __hv_tabwrite_f(&sTabwrite_L2RPHpTJ, VIf(Bf8));
    __hv_var_k_f(VOf(Bf7), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_var_k_f(VOf(Bf6), 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f);
    __hv_phasor_k_f(&sPhasor_JjjOFbU2, VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf10));
    __hv_sub_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf10), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf3), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf10));
    __hv_mul_f(VIf(Bf3), VIf(Bf10), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf11), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf12), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf9), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf3), VIf(Bf12), VOf(Bf12));
    __hv_fma_f(VIf(Bf10), VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_line_f(&sLine_W5J15VYc, VOf(Bf11));
    __hv_mul_f(VIf(Bf12), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf12), 8.0f, 8.0f, 8.0f, 8.0f, 8.0f, 8.0f, 8.0f, 8.0f);
    __hv_mul_f(VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_add_f(VIf(Bf0), VIf(Bf12), VOf(Bf11));
    __hv_fma_f(VIf(Bf4), VIf(Bf6), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_QmcOOABT, VOf(Bf6));
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_wx94e9Lh, VOf(Bf1));
    __hv_mul_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_5l9cAdVg, VOf(Bf6));
    __hv_rpole_f(&sRPole_RTSjMk0x, VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf1), 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f);
    __hv_line_f(&sLine_E1zc1LNI, VOf(Bf10));
    __hv_varread_f(&sVarf_eYV9GUiW, VOf(Bf3));
    __hv_mul_f(VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf10), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf9));
    __hv_sub_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf9), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf3), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf9));
    __hv_mul_f(VIf(Bf3), VIf(Bf9), VOf(Bf13));
    __hv_mul_f(VIf(Bf13), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf14), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf15), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf13), VIf(Bf15), VOf(Bf15));
    __hv_sub_f(VIf(Bf3), VIf(Bf15), VOf(Bf15));
    __hv_fma_f(VIf(Bf9), VIf(Bf14), VIf(Bf15), VOf(Bf15));
    __hv_mul_f(VIf(Bf15), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf15), 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f);
    __hv_mul_f(VIf(Bf10), VIf(Bf15), VOf(Bf15));
    __hv_fma_f(VIf(Bf6), VIf(Bf1), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf1), 1.2f, 1.2f, 1.2f, 1.2f, 1.2f, 1.2f, 1.2f, 1.2f);
    __hv_mul_f(VIf(Bf15), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf11), VIf(Bf1), VOf(Bf11));
    __hv_fma_f(VIf(Bf8), VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf7), 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f);
    __hv_mul_f(VIf(Bf11), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf7), VIf(O0), VOf(O0));
    __hv_var_k_f(VOf(Bf7), 0.16f, 0.16f, 0.16f, 0.16f, 0.16f, 0.16f, 0.16f, 0.16f);
    __hv_var_k_f(VOf(Bf11), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_add_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_kQvbYgxJ, VOf(Bf0));
    __hv_fma_f(VIf(Bf5), VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_phasor_f(&sPhasor_liJxjIhL, VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_abs_f(VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf0), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf0), VOf(Bf2));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf15), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf6), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf5), VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf2), VIf(Bf15), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf0), VIf(Bf12), VOf(Bf12));
    __hv_fma_f(VIf(Bf4), VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_add_f(VIf(Bf12), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf8), VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf7), 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f);
    __hv_mul_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf7), VIf(O1), VOf(O1));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed

}

int Heavy_prog::processInline(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(!(n4 & HV_N_SIMD_MASK)); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s)
  float **const bIn = NULL;

  // define the heavy output buffer for 2 channel(s)
  float **const bOut = reinterpret_cast<float **>(hv_alloca(2*sizeof(float *)));
  bOut[0] = outputBuffers+(0*n4);
  bOut[1] = outputBuffers+(1*n4);

  int n = process(bIn, bOut, n4);
  return n;
}

int Heavy_prog::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(n4 & ~HV_N_SIMD_MASK); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s), uninterleave
  float *const bIn = NULL;

  // define the heavy output buffer for 2 channel(s)
  float *const bOut = reinterpret_cast<float *>(hv_alloca(2*n4*sizeof(float)));

  int n = processInline(bIn, bOut, n4);

  // interleave the heavy output into the output buffer
  #if HV_SIMD_AVX
  for (int i = 0, j = 0; j < n4; j += 8, i += 16) {
    __m256 x = _mm256_load_ps(bOut+j);    // LLLLLLLL
    __m256 y = _mm256_load_ps(bOut+n4+j); // RRRRRRRR
    __m256 a = _mm256_unpacklo_ps(x, y);  // LRLRLRLR
    __m256 b = _mm256_unpackhi_ps(x, y);  // LRLRLRLR
    _mm256_store_ps(outputBuffers+i, a);
    _mm256_store_ps(outputBuffers+8+i, b);
  }
  #elif HV_SIMD_SSE
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    __m128 x = _mm_load_ps(bOut+j);    // LLLL
    __m128 y = _mm_load_ps(bOut+n4+j); // RRRR
    __m128 a = _mm_unpacklo_ps(x, y);  // LRLR
    __m128 b = _mm_unpackhi_ps(x, y);  // LRLR
    _mm_store_ps(outputBuffers+i, a);
    _mm_store_ps(outputBuffers+4+i, b);
  }
  #elif HV_SIMD_NEON
  // https://community.arm.com/groups/processors/blog/2012/03/13/coding-for-neon--part-5-rearranging-vectors
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    float32x4_t x = vld1q_f32(bOut+j);
    float32x4_t y = vld1q_f32(bOut+n4+j);
    float32x4x2_t z = {x, y};
    vst2q_f32(outputBuffers+i, z); // interleave and store
  }
  #else // HV_SIMD_NONE
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n4; ++j) {
      outputBuffers[i+2*j] = bOut[i*n4+j];
    }
  }
  #endif

  return n;
}
