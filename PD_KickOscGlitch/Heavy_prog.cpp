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
  numBytes += sPhasor_k_init(&sPhasor_FrvGUYwL, 0.0f, sampleRate);
  numBytes += sDel1_init(&sDel1_v6OPJnH1);
  numBytes += sSamphold_init(&sSamphold_pUSDt9Ko);
  numBytes += sPhasor_init(&sPhasor_3l1qioez, sampleRate);
  numBytes += sPhasor_init(&sPhasor_xcLMLMUw, sampleRate);
  numBytes += sLine_init(&sLine_wATI4Duh);
  numBytes += sTabwrite_init(&sTabwrite_uP44u9PG, &hTable_rwZk4vI1);
  numBytes += sPhasor_k_init(&sPhasor_U8mXelwc, 0.0f, sampleRate);
  numBytes += sTabread_init(&sTabread_vLQe2rv1, &hTable_rwZk4vI1, false);
  numBytes += sTabread_init(&sTabread_ZrGsG8tG, &hTable_rwZk4vI1, false);
  numBytes += sPhasor_k_init(&sPhasor_CJY3EslH, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_dVp3gUZz, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_u1ODDWNc);
  numBytes += sPhasor_init(&sPhasor_0Un2ag4f, sampleRate);
  numBytes += cRandom_init(&cRandom_EARiZqtJ, -91443895);
  numBytes += cSlice_init(&cSlice_rpn8xcDw, 1, 1);
  numBytes += sVari_init(&sVari_Gunz2nAC, 0, 0, false);
  numBytes += cVar_init_f(&cVar_DlAG9RyO, 1.0f);
  numBytes += cVar_init_f(&cVar_QMNhEYDw, 0.0f);
  numBytes += cVar_init_f(&cVar_ZWFV4MYL, 0.0f);
  numBytes += cVar_init_f(&cVar_KrjBqIGb, 0.0f);
  numBytes += cBinop_init(&cBinop_cTabsQ4D, 29.0f); // __div
  numBytes += sVarf_init(&sVarf_TdYr8Tww, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_pWYDL0qJ, -1794538862);
  numBytes += cSlice_init(&cSlice_Cb6GcJiD, 1, 1);
  numBytes += cRandom_init(&cRandom_OxyVgjIi, -921462131);
  numBytes += cSlice_init(&cSlice_ZcB3H0hD, 1, 1);
  numBytes += cBinop_init(&cBinop_SVEjahs0, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_RPhsNLWG, 0.0f); // __div
  numBytes += cDelay_init(this, &cDelay_sStucTQr, 0.0f);
  numBytes += cVar_init_s(&cVar_hRSiq9L0, "samplebuf");
  numBytes += cSlice_init(&cSlice_B4A6J0yd, 1, 1);
  numBytes += cSlice_init(&cSlice_HwWPBFON, 1, 1);
  numBytes += cBinop_init(&cBinop_xIBmvJ0I, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_6uv13phU, 0.0f); // __sub
  numBytes += cVar_init_s(&cVar_KeP8Fm04, "samplebuf");
  numBytes += cSlice_init(&cSlice_JsmePiFD, 1, 1);
  numBytes += sVarf_init(&sVarf_bJhunsU3, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_ICwXJ2vP, 1.0f);
  numBytes += cDelay_init(this, &cDelay_w3wS3juz, 0.0f);
  numBytes += cVar_init_f(&cVar_hnVn2Ux1, 480.0f);
  numBytes += cBinop_init(&cBinop_tmoZSaIh, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_z4C6p5aZ, 0.0f);
  numBytes += cVar_init_f(&cVar_OycZXKNX, 240.0f);
  numBytes += cBinop_init(&cBinop_2idkQDPD, 0.0f); // __mul
  numBytes += cPack_init(&cPack_I7EFeQZm, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_kVCe1psa, 4, 1);
  numBytes += cSlice_init(&cSlice_zuBHi1Ph, 3, 1);
  numBytes += cSlice_init(&cSlice_XceWjjM5, 2, 1);
  numBytes += cSlice_init(&cSlice_kVQPEjmY, 1, 1);
  numBytes += cSlice_init(&cSlice_LH9S2wwt, 0, 1);
  numBytes += sVarf_init(&sVarf_ti9Gdbv8, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_fCj5KBJA, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_Gu2r3zhD, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_bcrCwZD6, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_WPNwWMu6, 1.0f);
  numBytes += cRandom_init(&cRandom_m5khzM0Y, 421225850);
  numBytes += cSlice_init(&cSlice_mlPBmE7z, 1, 1);
  numBytes += cRandom_init(&cRandom_QV5OgcpE, 990513022);
  numBytes += cSlice_init(&cSlice_j8zETMVe, 1, 1);
  numBytes += sVarf_init(&sVarf_n66cwTt2, 0.3f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_EV2Z3acf, 0.0f); // __div
  numBytes += hTable_init(&hTable_rwZk4vI1, 10000);
  numBytes += cBinop_init(&cBinop_3qJBfNWh, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_XN3536Ej, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_6QID61w2, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Pm6QRjz6, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_prog::~Heavy_prog() {
  cPack_free(&cPack_I7EFeQZm);
  hTable_free(&hTable_rwZk4vI1);
}

HvTable *Heavy_prog::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x130A899: return &hTable_rwZk4vI1; // samplebuf
    default: return nullptr;
  }
}

void Heavy_prog::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_AlPEOV8w_sendMessage);
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


void Heavy_prog::cSwitchcase_vYvGfk2K_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_rpn8xcDw, 0, m, &cSlice_rpn8xcDw_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_EARiZqtJ, 0, m, &cRandom_EARiZqtJ_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_GGy0VOAZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_5B6qAs93_sendMessage);
}

void Heavy_prog::cUnop_5B6qAs93_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nQd6OmMK_sendMessage(_c, 0, m);
}

void Heavy_prog::cRandom_EARiZqtJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_GGy0VOAZ_sendMessage);
}

void Heavy_prog::cSlice_rpn8xcDw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_EARiZqtJ, 1, m, &cRandom_EARiZqtJ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cMsg_nQd6OmMK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_Gunz2nAC, m);
}

void Heavy_prog::cVar_DlAG9RyO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_OsuqMVDd_sendMessage);
  cSwitchcase_I17dybsM_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_bq5bZWcn_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_OsuqMVDd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DlAG9RyO, 1, m, &cVar_DlAG9RyO_sendMessage);
}

void Heavy_prog::cVar_QMNhEYDw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_otzVWd1P_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cVar_ZWFV4MYL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 32.0f, 0, m, &cBinop_xUMC80VC_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_3qJBfNWh, HV_BINOP_MULTIPLY, 1, m, &cBinop_3qJBfNWh_sendMessage);
}

void Heavy_prog::cVar_KrjBqIGb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_FrvGUYwL, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 10.0f, 0, m, &cBinop_zUNtXqrL_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_6QID61w2, m);
}

void Heavy_prog::cSwitchcase_otzVWd1P_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_czIRaJMq_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZeBfXhJ0_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nx4K6PVa_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_czIRaJMq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FER2Lsah_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WTzrJoab_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_D4IwrBg8_sendMessage);
}

void Heavy_prog::cCast_ZeBfXhJ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LjB9rmub_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4ZVlpwhI_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8A2rUMmj_sendMessage);
}

void Heavy_prog::cCast_nx4K6PVa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_I2KDKVy8_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Yc5k7kAi_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SwICj4sO_sendMessage);
}

void Heavy_prog::cCast_wEF1ccLo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7sDdDtBB_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_QH9tZtCV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cTabsQ4D, HV_BINOP_DIVIDE, 0, m, &cBinop_cTabsQ4D_sendMessage);
}

void Heavy_prog::cCast_Yc5k7kAi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_liSIW0lZ_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_I2KDKVy8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_SwICj4sO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_v5dzhGhR_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_8A2rUMmj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_v5dzhGhR_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_4ZVlpwhI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jWNvjCfI_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_LjB9rmub_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_D4IwrBg8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_v5dzhGhR_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_FER2Lsah_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_WTzrJoab_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KW8z9T4x_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_7sDdDtBB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_wATI4Duh, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_wATI4Duh, 0, m, NULL);
}

void Heavy_prog::cMsg_KW8z9T4x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.5f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_cTabsQ4D, HV_BINOP_DIVIDE, 1, m, &cBinop_cTabsQ4D_sendMessage);
}

void Heavy_prog::cBinop_cTabsQ4D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_TdYr8Tww, m);
}

void Heavy_prog::cMsg_v5dzhGhR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 110.0f);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wEF1ccLo_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QH9tZtCV_sendMessage);
}

void Heavy_prog::cMsg_jWNvjCfI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 15.9f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_cTabsQ4D, HV_BINOP_DIVIDE, 1, m, &cBinop_cTabsQ4D_sendMessage);
}

void Heavy_prog::cMsg_liSIW0lZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.1f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_cTabsQ4D, HV_BINOP_DIVIDE, 1, m, &cBinop_cTabsQ4D_sendMessage);
}

void Heavy_prog::cSwitchcase_7qpM6DfS_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Cb6GcJiD, 0, m, &cSlice_Cb6GcJiD_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_pWYDL0qJ, 0, m, &cRandom_pWYDL0qJ_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_e0hb0CnQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_jJX3bedv_sendMessage);
}

void Heavy_prog::cUnop_jJX3bedv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QMNhEYDw, 0, m, &cVar_QMNhEYDw_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ICwXJ2vP, 0, m, &cVar_ICwXJ2vP_sendMessage);
}

void Heavy_prog::cRandom_pWYDL0qJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 3.0f, 0, m, &cBinop_e0hb0CnQ_sendMessage);
}

void Heavy_prog::cSlice_Cb6GcJiD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_pWYDL0qJ, 1, m, &cRandom_pWYDL0qJ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_HDa0qSCU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ZcB3H0hD, 0, m, &cSlice_ZcB3H0hD_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_OxyVgjIi, 0, m, &cRandom_OxyVgjIi_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_9Yja4iSp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_NMcrZQYw_sendMessage);
}

void Heavy_prog::cUnop_NMcrZQYw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KrjBqIGb, 0, m, &cVar_KrjBqIGb_sendMessage);
}

void Heavy_prog::cRandom_OxyVgjIi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_9Yja4iSp_sendMessage);
}

void Heavy_prog::cSlice_ZcB3H0hD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_OxyVgjIi, 1, m, &cRandom_OxyVgjIi_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_dVgpEOG6_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wYWYbyiW_sendMessage);
      break;
    }
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pjffm9Zs_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_wYWYbyiW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rmjGo25R_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BDHaw2rB_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_z7sWmpyM_sendMessage);
}

void Heavy_prog::cCast_pjffm9Zs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZDJEZfxQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GOMnI1jy_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Q1OA5Tcf_sendMessage);
}

void Heavy_prog::cSystem_bMpgSO9X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SVEjahs0, HV_BINOP_SUBTRACT, 1, m, &cBinop_SVEjahs0_sendMessage);
}

void Heavy_prog::cMsg_nHHXlqp3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "currentTime");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_bMpgSO9X_sendMessage);
}

void Heavy_prog::cBinop_SVEjahs0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RPhsNLWG, HV_BINOP_DIVIDE, 0, m, &cBinop_RPhsNLWG_sendMessage);
}

void Heavy_prog::cSystem_fUINjoIe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SVEjahs0, HV_BINOP_SUBTRACT, 0, m, &cBinop_SVEjahs0_sendMessage);
}

void Heavy_prog::cMsg_9jcemq1I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "currentTime");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_fUINjoIe_sendMessage);
}

void Heavy_prog::cBinop_RPhsNLWG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_pN1KUZbF_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DSipWGPP_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9Ngz9zeQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PgUYZaiX_sendMessage);
  cSwitchcase_mQTVU4a5_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cSystem_NoF4DoVR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_IISnToH0_sendMessage);
}

void Heavy_prog::cMsg_A19IuVta_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_NoF4DoVR_sendMessage);
}

void Heavy_prog::cBinop_IISnToH0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RPhsNLWG, HV_BINOP_DIVIDE, 1, m, &cBinop_RPhsNLWG_sendMessage);
}

void Heavy_prog::cSwitchcase_SGvk2oEo_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x6FF57CB4: { // "start"
      cSlice_onMessage(_c, &Context(_c)->cSlice_HwWPBFON, 0, m, &cSlice_HwWPBFON_sendMessage);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_T4eiqDWf_sendMessage(_c, 0, m);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_B4A6J0yd, 0, m, &cSlice_B4A6J0yd_sendMessage);
      break;
    }
    default: {
      cMsg_fdmoCUDr_sendMessage(_c, 0, m);
      break;
    }
  }
}

void Heavy_prog::cDelay_sStucTQr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_sStucTQr, m);
  cMsg_T4eiqDWf_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_hRSiq9L0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zw4urugS_sendMessage(_c, 0, m);
}

void Heavy_prog::cSlice_B4A6J0yd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_uP44u9PG, 2, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_hRSiq9L0, 0, m, &cVar_hRSiq9L0_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_HwWPBFON_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_uP44u9PG, 1, m, NULL);
      cBinop_onMessage(_c, &Context(_c)->cBinop_6uv13phU, HV_BINOP_SUBTRACT, 0, m, &cBinop_6uv13phU_sendMessage);
      break;
    }
    case 1: {
      cMsg_1KcxksSI_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_mypqXt7V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xIBmvJ0I, HV_BINOP_DIVIDE, 1, m, &cBinop_xIBmvJ0I_sendMessage);
}

void Heavy_prog::cBinop_xIBmvJ0I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_V1f0bops_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sStucTQr, 1, m, &cDelay_sStucTQr_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sStucTQr, 0, m, &cDelay_sStucTQr_sendMessage);
}

void Heavy_prog::cMsg_fdmoCUDr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_uP44u9PG, 1, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_6uv13phU, HV_BINOP_SUBTRACT, 0, m, &cBinop_6uv13phU_sendMessage);
}

void Heavy_prog::cSystem_4gd0q8Ic_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6uv13phU, HV_BINOP_SUBTRACT, 1, m, &cBinop_6uv13phU_sendMessage);
}

void Heavy_prog::cMsg_zw4urugS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4gd0q8Ic_sendMessage);
}

void Heavy_prog::cBinop_6uv13phU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_8AxnKOJl_sendMessage);
}

void Heavy_prog::cBinop_8AxnKOJl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xIBmvJ0I, HV_BINOP_DIVIDE, 0, m, &cBinop_xIBmvJ0I_sendMessage);
}

void Heavy_prog::cMsg_V1f0bops_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_sStucTQr, 0, m, &cDelay_sStucTQr_sendMessage);
}

void Heavy_prog::cMsg_T4eiqDWf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_uP44u9PG, 1, m, NULL);
}

void Heavy_prog::cMsg_Aiw4fCyp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_k2DNUJej_sendMessage);
}

void Heavy_prog::cSystem_k2DNUJej_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_mypqXt7V_sendMessage);
}

void Heavy_prog::cMsg_1KcxksSI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_uP44u9PG, 1, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_6uv13phU, HV_BINOP_SUBTRACT, 0, m, &cBinop_6uv13phU_sendMessage);
}

void Heavy_prog::cSwitchcase_o90esv1a_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_JsmePiFD, 0, m, &cSlice_JsmePiFD_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cVar_KeP8Fm04_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Jd73q0Cz_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_AeFlLLy8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_4MbFvWJe_sendMessage);
}

void Heavy_prog::cBinop_4MbFvWJe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_bJhunsU3, m);
}

void Heavy_prog::cMsg_Jd73q0Cz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_AeFlLLy8_sendMessage);
}

void Heavy_prog::cSlice_JsmePiFD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_vLQe2rv1, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_ZrGsG8tG, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_KeP8Fm04, 0, m, &cVar_KeP8Fm04_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cVar_ICwXJ2vP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_781qAtCW_sendMessage);
  cSwitchcase_dVgpEOG6_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_781qAtCW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ICwXJ2vP, 1, m, &cVar_ICwXJ2vP_sendMessage);
}

void Heavy_prog::cSwitchcase_I17dybsM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_Kpe2vU8R_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_Kpe2vU8R_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_i1KJHwwL_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_w3wS3juz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_w3wS3juz, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_w3wS3juz, 0, m, &cDelay_w3wS3juz_sendMessage);
  cSwitchcase_7qpM6DfS_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_HDa0qSCU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_i1KJHwwL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Kpe2vU8R_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_w3wS3juz, 0, m, &cDelay_w3wS3juz_sendMessage);
  cSwitchcase_7qpM6DfS_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_HDa0qSCU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_FFdOLftw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_EF4yhmM1_sendMessage);
}

void Heavy_prog::cSystem_EF4yhmM1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ZWKa3GlB_sendMessage);
}

void Heavy_prog::cVar_hnVn2Ux1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tmoZSaIh, HV_BINOP_MULTIPLY, 0, m, &cBinop_tmoZSaIh_sendMessage);
}

void Heavy_prog::cMsg_Kpe2vU8R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_w3wS3juz, 0, m, &cDelay_w3wS3juz_sendMessage);
}

void Heavy_prog::cBinop_7vYChIBG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_w3wS3juz, 2, m, &cDelay_w3wS3juz_sendMessage);
}

void Heavy_prog::cBinop_ZWKa3GlB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tmoZSaIh, HV_BINOP_MULTIPLY, 1, m, &cBinop_tmoZSaIh_sendMessage);
}

void Heavy_prog::cBinop_tmoZSaIh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_7vYChIBG_sendMessage);
}

void Heavy_prog::cSwitchcase_bq5bZWcn_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_ZM2enndD_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_ZM2enndD_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_j7IvkCkb_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_z4C6p5aZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_z4C6p5aZ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_z4C6p5aZ, 0, m, &cDelay_z4C6p5aZ_sendMessage);
  cSwitchcase_dYwix0CZ_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_giVKzRjO_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_j7IvkCkb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZM2enndD_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_z4C6p5aZ, 0, m, &cDelay_z4C6p5aZ_sendMessage);
  cSwitchcase_dYwix0CZ_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_giVKzRjO_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_BQWP4iFG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3iGaccdS_sendMessage);
}

void Heavy_prog::cSystem_3iGaccdS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_H3dPOH8B_sendMessage);
}

void Heavy_prog::cVar_OycZXKNX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2idkQDPD, HV_BINOP_MULTIPLY, 0, m, &cBinop_2idkQDPD_sendMessage);
}

void Heavy_prog::cMsg_ZM2enndD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_z4C6p5aZ, 0, m, &cDelay_z4C6p5aZ_sendMessage);
}

void Heavy_prog::cBinop_cecEuXkw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_z4C6p5aZ, 2, m, &cDelay_z4C6p5aZ_sendMessage);
}

void Heavy_prog::cBinop_H3dPOH8B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2idkQDPD, HV_BINOP_MULTIPLY, 1, m, &cBinop_2idkQDPD_sendMessage);
}

void Heavy_prog::cBinop_2idkQDPD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_cecEuXkw_sendMessage);
}

void Heavy_prog::cPack_I7EFeQZm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9oXF30X9_sendMessage(_c, 0, m);
}

void Heavy_prog::cSlice_kVCe1psa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_ti9Gdbv8, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_zuBHi1Ph_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_bcrCwZD6, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_XceWjjM5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_Gu2r3zhD, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_kVQPEjmY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_dVp3gUZz, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_LH9S2wwt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_CJY3EslH, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_b0gP43vN_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EdzGdnyV_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_EdzGdnyV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RiiwUdUz_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_y6XM9eEz_sendMessage);
}

void Heavy_prog::cCast_RiiwUdUz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_y6XM9eEz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OVA76DEF_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_fA3TFaxs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fCj5KBJA, HV_BINOP_MULTIPLY, 0, m, &cBinop_fCj5KBJA_sendMessage);
}

void Heavy_prog::cCast_SJgnhaDB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_I7EFeQZm, 0, m, &cPack_I7EFeQZm_sendMessage);
}

void Heavy_prog::cMsg_OVA76DEF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fA3TFaxs_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SJgnhaDB_sendMessage);
}

void Heavy_prog::cBinop_fCj5KBJA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_I7EFeQZm, 1, m, &cPack_I7EFeQZm_sendMessage);
}

void Heavy_prog::cBinop_9taqyuO7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fCj5KBJA, HV_BINOP_MULTIPLY, 1, m, &cBinop_fCj5KBJA_sendMessage);
}

void Heavy_prog::cMsg_3oPXfren_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.1f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 600.0f, 0, m, &cBinop_9taqyuO7_sendMessage);
}

void Heavy_prog::cMsg_9oXF30X9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_u1ODDWNc, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 1);
  sLine_onMessage(_c, &Context(_c)->sLine_u1ODDWNc, 0, m, NULL);
}

void Heavy_prog::cMsg_WO4qdbCf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(5);
  msg_init(m, 5, msg_getTimestamp(n));
  msg_setFloat(m, 0, 748.031f);
  msg_setFloat(m, 1, 1023.62f);
  msg_setFloat(m, 2, 0.173228f);
  msg_setFloat(m, 3, 1968.5f);
  msg_setFloat(m, 4, 9259.84f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_kVCe1psa, 0, m, &cSlice_kVCe1psa_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_zuBHi1Ph, 0, m, &cSlice_zuBHi1Ph_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_XceWjjM5, 0, m, &cSlice_XceWjjM5_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_kVQPEjmY, 0, m, &cSlice_kVQPEjmY_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_LH9S2wwt, 0, m, &cSlice_LH9S2wwt_sendMessage);
}

void Heavy_prog::cVar_WPNwWMu6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_cRgE2p3h_sendMessage);
  cSwitchcase_b0gP43vN_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_cRgE2p3h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WPNwWMu6, 1, m, &cVar_WPNwWMu6_sendMessage);
}

void Heavy_prog::cSwitchcase_dYwix0CZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_mlPBmE7z, 0, m, &cSlice_mlPBmE7z_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_m5khzM0Y, 0, m, &cRandom_m5khzM0Y_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_IAHS97VE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_9MVwy2uD_sendMessage);
}

void Heavy_prog::cUnop_9MVwy2uD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WPNwWMu6, 0, m, &cVar_WPNwWMu6_sendMessage);
}

void Heavy_prog::cRandom_m5khzM0Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_IAHS97VE_sendMessage);
}

void Heavy_prog::cSlice_mlPBmE7z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_m5khzM0Y, 1, m, &cRandom_m5khzM0Y_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_mQTVU4a5_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x459C4000: { // "5000.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_huGYcyIY_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_huGYcyIY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_weMXVgvR_sendMessage(_c, 0, m);
}

void Heavy_prog::cSwitchcase_giVKzRjO_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_j8zETMVe, 0, m, &cSlice_j8zETMVe_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_QV5OgcpE, 0, m, &cRandom_QV5OgcpE_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_IbiNhehT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_SfqifxyK_sendMessage);
}

void Heavy_prog::cUnop_SfqifxyK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ZWFV4MYL, 0, m, &cVar_ZWFV4MYL_sendMessage);
}

void Heavy_prog::cRandom_QV5OgcpE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 80.0f, 0, m, &cBinop_IbiNhehT_sendMessage);
}

void Heavy_prog::cSlice_j8zETMVe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_QV5OgcpE, 1, m, &cRandom_QV5OgcpE_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_zUNtXqrL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_n66cwTt2, m);
}

void Heavy_prog::cCast_z7sWmpyM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nHHXlqp3_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_rmjGo25R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_BDHaw2rB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_SGvk2oEo_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_Q1OA5Tcf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_GOMnI1jy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_A19IuVta_sendMessage(_c, 0, m);
  cMsg_9jcemq1I_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_ZDJEZfxQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_weMXVgvR_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_weMXVgvR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  cSwitchcase_SGvk2oEo_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_EV2Z3acf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_U8mXelwc, 0, m);
}

void Heavy_prog::cCast_PgUYZaiX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NmR6RHAJ_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_DSipWGPP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 22.0f, 0, m, &cBinop_VhsfY9A4_sendMessage);
}

void Heavy_prog::cCast_pN1KUZbF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_9Ngz9zeQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EV2Z3acf, HV_BINOP_DIVIDE, 1, m, &cBinop_EV2Z3acf_sendMessage);
}

void Heavy_prog::hTable_rwZk4vI1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cBinop_xUMC80VC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_XN3536Ej, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_6QID61w2, m);
}

void Heavy_prog::cBinop_3qJBfNWh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EV2Z3acf, HV_BINOP_DIVIDE, 0, m, &cBinop_EV2Z3acf_sendMessage);
}

void Heavy_prog::cMsg_NmR6RHAJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_3qJBfNWh, HV_BINOP_MULTIPLY, 0, m, &cBinop_3qJBfNWh_sendMessage);
}

void Heavy_prog::cBinop_VhsfY9A4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Pm6QRjz6, m);
}

void Heavy_prog::cReceive_AlPEOV8w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_vYvGfk2K_onMessage(_c, NULL, 0, m, NULL);
  cVar_onMessage(_c, &Context(_c)->cVar_hRSiq9L0, 0, m, &cVar_hRSiq9L0_sendMessage);
  cMsg_Aiw4fCyp_sendMessage(_c, 0, m);
  cMsg_T4eiqDWf_sendMessage(_c, 0, m);
  cMsg_FFdOLftw_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_hnVn2Ux1, 0, m, &cVar_hnVn2Ux1_sendMessage);
  cMsg_BQWP4iFG_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_OycZXKNX, 0, m, &cVar_OycZXKNX_sendMessage);
  cMsg_3oPXfren_sendMessage(_c, 0, m);
  cMsg_WO4qdbCf_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_DlAG9RyO, 0, m, &cVar_DlAG9RyO_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_KeP8Fm04, 0, m, &cVar_KeP8Fm04_sendMessage);
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
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5, Bf6, Bf7, Bf8, Bf9, Bf10;
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
    __hv_varread_i(&sVari_Gunz2nAC, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varwrite_i(&sVari_Gunz2nAC, VIi(Bi1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_phasor_k_f(&sPhasor_FrvGUYwL, VOf(Bf0));
    __hv_del1_f(&sDel1_v6OPJnH1, VIf(Bf0), VOf(Bf2));
    __hv_lt_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_samphold_f(&sSamphold_pUSDt9Ko, VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_XN3536Ej, VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_6QID61w2, VOf(Bf2));
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_phasor_f(&sPhasor_3l1qioez, VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf4), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf2));
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf6), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf7), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf5), VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf2), VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf6), 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f);
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_phasor_f(&sPhasor_xcLMLMUw, VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf6), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf3), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf6));
    __hv_mul_f(VIf(Bf3), VIf(Bf6), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf2), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf7), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf0), VIf(Bf7), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf6), VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_varread_f(&sVarf_n66cwTt2, VOf(Bf6));
    __hv_line_f(&sLine_wATI4Duh, VOf(Bf7));
    __hv_varread_f(&sVarf_TdYr8Tww, VOf(Bf0));
    __hv_mul_f(VIf(Bf7), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf7), VOf(Bf0));
    __hv_floor_f(VIf(Bf0), VOf(Bf5));
    __hv_sub_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_abs_f(VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf0), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf0), VOf(Bf5));
    __hv_mul_f(VIf(Bf0), VIf(Bf5), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf9), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf10), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf5), VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf10), 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f);
    __hv_mul_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf1), VIf(Bf6), VIf(Bf10), VOf(Bf6));
    __hv_fma_f(VIf(Bf3), VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf2), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_mul_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_tabwrite_stoppable_f(&sTabwrite_uP44u9PG, VIf(Bf6));
    __hv_var_k_f(VOf(Bf6), 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f);
    __hv_phasor_k_f(&sPhasor_U8mXelwc, VOf(Bf2));
    __hv_varread_f(&sVarf_Pm6QRjz6, VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_bJhunsU3, VOf(Bf2));
    __hv_min_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_zero_f(VOf(Bf1));
    __hv_max_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_floor_f(VIf(Bf1), VOf(Bf2));
    __hv_cast_fi(VIf(Bf2), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_vLQe2rv1, VIi(Bi0), VOf(Bf7));
    __hv_tabread_if(&sTabread_ZrGsG8tG, VIi(Bi1), VOf(Bf9));
    __hv_sub_f(VIf(Bf7), VIf(Bf9), VOf(Bf7));
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf7), VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf4), VIf(Bf9), VOf(Bf4));
    __hv_fma_f(VIf(Bf10), VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_phasor_k_f(&sPhasor_CJY3EslH, VOf(Bf6));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf6), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf2), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf6));
    __hv_mul_f(VIf(Bf2), VIf(Bf6), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf1), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf5), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf7), VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf6), VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_phasor_k_f(&sPhasor_dVp3gUZz, VOf(Bf1));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_abs_f(VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf6), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf6), VOf(Bf1));
    __hv_mul_f(VIf(Bf6), VIf(Bf1), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf7), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf0), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf5), VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf1), VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf2), VIf(Bf6), VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_mul_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_u1ODDWNc, VOf(Bf2));
    __hv_varread_f(&sVarf_Gu2r3zhD, VOf(Bf0));
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_sub_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf7), VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_bcrCwZD6, VOf(Bf1));
    __hv_varread_f(&sVarf_ti9Gdbv8, VOf(Bf7));
    __hv_fma_f(VIf(Bf0), VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_phasor_f(&sPhasor_0Un2ag4f, VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf7), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf7));
    __hv_mul_f(VIf(Bf1), VIf(Bf7), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf6), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf5), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf0), VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf7), VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f);
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf4), VIf(Bf1), VOf(Bf4));
    __hv_var_k_f(VOf(Bf2), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf2), VIf(O1), VOf(O1));
    __hv_add_f(VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf9), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf9), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_mul_f(VIf(Bf1), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf9), VIf(O0), VOf(O0));

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
