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
  numBytes += sPhasor_k_init(&sPhasor_9RdoAMYF, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_IaWqHVQG, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_kRNUmMVO);
  numBytes += sPhasor_init(&sPhasor_tWc7HPvM, sampleRate);
  numBytes += sLine_init(&sLine_is1u3QG1);
  numBytes += sLine_init(&sLine_rNEt1U90);
  numBytes += sPhasor_init(&sPhasor_wKJiUmR4, sampleRate);
  numBytes += sPhasor_init(&sPhasor_CMdIQHMm, sampleRate);
  numBytes += sLine_init(&sLine_LDciaiwo);
  numBytes += sLine_init(&sLine_YJjCAfef);
  numBytes += sPhasor_init(&sPhasor_EPXLfXdS, sampleRate);
  numBytes += sPhasor_init(&sPhasor_J3aFXVSr, sampleRate);
  numBytes += sLine_init(&sLine_tq2mqZZn);
  numBytes += cVar_init_f(&cVar_CcUIW8lW, 0.0f);
  numBytes += cVar_init_f(&cVar_ycDc7mjb, 0.0f);
  numBytes += cVar_init_f(&cVar_LsYWYW7b, 0.0f);
  numBytes += cVar_init_f(&cVar_mrKQvCwT, 0.0f);
  numBytes += cVar_init_f(&cVar_JUJBBUwh, 1.0f);
  numBytes += cVar_init_f(&cVar_8A9HXOA9, 0.0f);
  numBytes += cRandom_init(&cRandom_SNSiARlo, 1558710024);
  numBytes += cSlice_init(&cSlice_IKNb3lAY, 1, 1);
  numBytes += cVar_init_f(&cVar_6neEiWqS, 0.0f);
  numBytes += cVar_init_f(&cVar_fnHJJ9NH, 0.0f);
  numBytes += cRandom_init(&cRandom_3U92EOCS, 1670320771);
  numBytes += cSlice_init(&cSlice_yurWz1pW, 1, 1);
  numBytes += cVar_init_f(&cVar_b6fNFdLO, 0.0f);
  numBytes += cDelay_init(this, &cDelay_RfH8lTX4, 0.0f);
  numBytes += cVar_init_f(&cVar_GODYLGDd, 360.0f);
  numBytes += cBinop_init(&cBinop_mDj7gBa4, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_SgGsMy0X, 0.0f);
  numBytes += cVar_init_f(&cVar_Be9Cpk94, 480.0f);
  numBytes += cBinop_init(&cBinop_KyM8EFqD, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_OPLIfxUj, 29.0f); // __div
  numBytes += sVarf_init(&sVarf_objPY7Gh, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_EqpVwuwK, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_A7PLT9LQ, 4, 1);
  numBytes += cSlice_init(&cSlice_xlYHpD5W, 3, 1);
  numBytes += cSlice_init(&cSlice_pj34wOVZ, 2, 1);
  numBytes += cSlice_init(&cSlice_BwelTstx, 1, 1);
  numBytes += cSlice_init(&cSlice_uclruHvb, 0, 1);
  numBytes += sVarf_init(&sVarf_UhgNplRe, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_dDEGfCJr, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_YPCFi00d, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_xNbHlG5o, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_3vuEnRUX, 0.0f);
  numBytes += cVar_init_f(&cVar_78mDvQu1, 120.0f);
  numBytes += cBinop_init(&cBinop_cl3tevI3, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_eZcvZenU, 0.0f);
  numBytes += cVar_init_f(&cVar_J2kM03wP, 240.0f);
  numBytes += cBinop_init(&cBinop_ZtVKqaQ3, 0.0f); // __mul
  numBytes += cRandom_init(&cRandom_OlRQAG6E, -582279594);
  numBytes += cSlice_init(&cSlice_BXAUIHkq, 1, 1);
  numBytes += cRandom_init(&cRandom_bt3eH68z, -1917609884);
  numBytes += cSlice_init(&cSlice_4Thkg9H9, 1, 1);
  numBytes += cRandom_init(&cRandom_aTSew397, -1120286297);
  numBytes += cSlice_init(&cSlice_9tnFHl0Q, 1, 1);
  numBytes += cBinop_init(&cBinop_jwWku2pL, 0.0f); // __add
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_prog::~Heavy_prog() {
  cPack_free(&cPack_EqpVwuwK);
}

HvTable *Heavy_prog::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_prog::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_LFao3aTI_sendMessage);
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


void Heavy_prog::cVar_CcUIW8lW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UkYhYMDx_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_ycDc7mjb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qoHggZJd_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_LsYWYW7b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ksHs3nI5_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_mrKQvCwT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SLcPiep0_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_JUJBBUwh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_YMwBI2wt_sendMessage);
  cSwitchcase_y4pBohkl_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_otfOLLtb_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_KAAKeSoT_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_SpJKTZRo_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_YMwBI2wt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JUJBBUwh, 1, m, &cVar_JUJBBUwh_sendMessage);
}

void Heavy_prog::cVar_8A9HXOA9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CcUIW8lW, 0, m, &cVar_CcUIW8lW_sendMessage);
  cMsg_uR1bFQyG_sendMessage(_c, 0, m);
}

void Heavy_prog::cSwitchcase_aP7I04to_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_IKNb3lAY, 0, m, &cSlice_IKNb3lAY_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_SNSiARlo, 0, m, &cRandom_SNSiARlo_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_U13xMjwn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_vERf2zwS_sendMessage);
}

void Heavy_prog::cUnop_vERf2zwS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 10.0f, 0, m, &cBinop_vjweMfpB_sendMessage);
}

void Heavy_prog::cRandom_SNSiARlo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10.0f, 0, m, &cBinop_U13xMjwn_sendMessage);
}

void Heavy_prog::cSlice_IKNb3lAY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_SNSiARlo, 1, m, &cRandom_SNSiARlo_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cVar_6neEiWqS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ycDc7mjb, 0, m, &cVar_ycDc7mjb_sendMessage);
}

void Heavy_prog::cVar_fnHJJ9NH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LsYWYW7b, 0, m, &cVar_LsYWYW7b_sendMessage);
}

void Heavy_prog::cSwitchcase_5yZ2JyvA_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_yurWz1pW, 0, m, &cSlice_yurWz1pW_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_3U92EOCS, 0, m, &cRandom_3U92EOCS_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_YyY5SRvE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_sAko0bSf_sendMessage);
}

void Heavy_prog::cUnop_sAko0bSf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 10.0f, 0, m, &cBinop_8T9pEPns_sendMessage);
}

void Heavy_prog::cRandom_3U92EOCS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10.0f, 0, m, &cBinop_YyY5SRvE_sendMessage);
}

void Heavy_prog::cSlice_yurWz1pW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_3U92EOCS, 1, m, &cRandom_3U92EOCS_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cVar_b6fNFdLO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mrKQvCwT, 0, m, &cVar_mrKQvCwT_sendMessage);
}

void Heavy_prog::cSwitchcase_y4pBohkl_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_qzRRPZiz_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_qzRRPZiz_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_sICLn37C_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_RfH8lTX4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_RfH8lTX4, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RfH8lTX4, 0, m, &cDelay_RfH8lTX4_sendMessage);
  cSwitchcase_5yZ2JyvA_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_sICLn37C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qzRRPZiz_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RfH8lTX4, 0, m, &cDelay_RfH8lTX4_sendMessage);
  cSwitchcase_5yZ2JyvA_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_q9u7bKNv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_qrdRIHn4_sendMessage);
}

void Heavy_prog::cSystem_qrdRIHn4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_81NtG76V_sendMessage);
}

void Heavy_prog::cVar_GODYLGDd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mDj7gBa4, HV_BINOP_MULTIPLY, 0, m, &cBinop_mDj7gBa4_sendMessage);
}

void Heavy_prog::cMsg_qzRRPZiz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_RfH8lTX4, 0, m, &cDelay_RfH8lTX4_sendMessage);
}

void Heavy_prog::cBinop_CFQnJGF2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_RfH8lTX4, 2, m, &cDelay_RfH8lTX4_sendMessage);
}

void Heavy_prog::cBinop_81NtG76V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mDj7gBa4, HV_BINOP_MULTIPLY, 1, m, &cBinop_mDj7gBa4_sendMessage);
}

void Heavy_prog::cBinop_mDj7gBa4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_CFQnJGF2_sendMessage);
}

void Heavy_prog::cSwitchcase_otfOLLtb_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_m5NQ9C9S_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_m5NQ9C9S_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hQcaHCUf_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_SgGsMy0X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_SgGsMy0X, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SgGsMy0X, 0, m, &cDelay_SgGsMy0X_sendMessage);
  cSwitchcase_1SBhD025_onMessage(_c, NULL, 0, m, NULL);
  cMsg_nit861eT_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_hQcaHCUf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_m5NQ9C9S_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SgGsMy0X, 0, m, &cDelay_SgGsMy0X_sendMessage);
  cSwitchcase_1SBhD025_onMessage(_c, NULL, 0, m, NULL);
  cMsg_nit861eT_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_hTQ9njqj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_erL2rWj9_sendMessage);
}

void Heavy_prog::cSystem_erL2rWj9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_T0gg0YzC_sendMessage);
}

void Heavy_prog::cVar_Be9Cpk94_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KyM8EFqD, HV_BINOP_MULTIPLY, 0, m, &cBinop_KyM8EFqD_sendMessage);
}

void Heavy_prog::cMsg_m5NQ9C9S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_SgGsMy0X, 0, m, &cDelay_SgGsMy0X_sendMessage);
}

void Heavy_prog::cBinop_UMt59cx3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_SgGsMy0X, 2, m, &cDelay_SgGsMy0X_sendMessage);
}

void Heavy_prog::cBinop_T0gg0YzC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KyM8EFqD, HV_BINOP_MULTIPLY, 1, m, &cBinop_KyM8EFqD_sendMessage);
}

void Heavy_prog::cBinop_KyM8EFqD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_UMt59cx3_sendMessage);
}

void Heavy_prog::cSwitchcase_AuAqbTvN_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QG7DqQcy_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UMpN6EVZ_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6jweJ1lF_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_QG7DqQcy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zIywZIMV_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OiV1JS48_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NbwJEMyC_sendMessage);
}

void Heavy_prog::cCast_UMpN6EVZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rMj5beCc_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vxo7bTFP_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6QZwgNHz_sendMessage);
}

void Heavy_prog::cCast_6jweJ1lF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_g5WGaPAm_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7NyZDW7M_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Ba4Kpgeq_sendMessage);
}

void Heavy_prog::cCast_6ZwzHMaT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_grkDeOur_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_aAmLaOAf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OPLIfxUj, HV_BINOP_DIVIDE, 0, m, &cBinop_OPLIfxUj_sendMessage);
}

void Heavy_prog::cBinop_OPLIfxUj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_objPY7Gh, m);
}

void Heavy_prog::cMsg_5jRVr2Kj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 36.1f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_OPLIfxUj, HV_BINOP_DIVIDE, 1, m, &cBinop_OPLIfxUj_sendMessage);
}

void Heavy_prog::cCast_7NyZDW7M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5jRVr2Kj_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_Ba4Kpgeq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KQ69bvdR_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_g5WGaPAm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_vxo7bTFP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_L0TKiDrL_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_rMj5beCc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_6QZwgNHz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KQ69bvdR_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_zIywZIMV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_OiV1JS48_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_afdC3Vi0_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_NbwJEMyC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KQ69bvdR_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_grkDeOur_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_tq2mqZZn, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_tq2mqZZn, 0, m, NULL);
}

void Heavy_prog::cMsg_KQ69bvdR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 110.0f);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6ZwzHMaT_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_aAmLaOAf_sendMessage);
}

void Heavy_prog::cMsg_afdC3Vi0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.5f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_OPLIfxUj, HV_BINOP_DIVIDE, 1, m, &cBinop_OPLIfxUj_sendMessage);
}

void Heavy_prog::cMsg_L0TKiDrL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 50.9f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_OPLIfxUj, HV_BINOP_DIVIDE, 1, m, &cBinop_OPLIfxUj_sendMessage);
}

void Heavy_prog::cPack_EqpVwuwK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PZVevyQC_sendMessage(_c, 0, m);
}

void Heavy_prog::cSlice_A7PLT9LQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_UhgNplRe, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_xlYHpD5W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_xNbHlG5o, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_pj34wOVZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_YPCFi00d, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_BwelTstx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_IaWqHVQG, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_uclruHvb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_9RdoAMYF, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_ZwiifBoS_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cpJgeg9H_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_cpJgeg9H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zh4VVqvU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dHDjFVH1_sendMessage);
}

void Heavy_prog::cCast_dHDjFVH1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_k02X2vwT_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_zh4VVqvU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_Wvr4Nufv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_EqpVwuwK, 0, m, &cPack_EqpVwuwK_sendMessage);
}

void Heavy_prog::cCast_0MyM9buc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dDEGfCJr, HV_BINOP_MULTIPLY, 0, m, &cBinop_dDEGfCJr_sendMessage);
}

void Heavy_prog::cMsg_k02X2vwT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0MyM9buc_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Wvr4Nufv_sendMessage);
}

void Heavy_prog::cBinop_dDEGfCJr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_EqpVwuwK, 1, m, &cPack_EqpVwuwK_sendMessage);
}

void Heavy_prog::cBinop_2xHfckJo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dDEGfCJr, HV_BINOP_MULTIPLY, 1, m, &cBinop_dDEGfCJr_sendMessage);
}

void Heavy_prog::cMsg_VfM3Y9tz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.1f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 600.0f, 0, m, &cBinop_2xHfckJo_sendMessage);
}

void Heavy_prog::cMsg_PZVevyQC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_kRNUmMVO, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 1);
  sLine_onMessage(_c, &Context(_c)->sLine_kRNUmMVO, 0, m, NULL);
}

void Heavy_prog::cMsg_ZixlXCsM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(5);
  msg_init(m, 5, msg_getTimestamp(n));
  msg_setFloat(m, 0, 748.031f);
  msg_setFloat(m, 1, 1023.62f);
  msg_setFloat(m, 2, 0.173228f);
  msg_setFloat(m, 3, 1968.5f);
  msg_setFloat(m, 4, 9259.84f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_A7PLT9LQ, 0, m, &cSlice_A7PLT9LQ_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_xlYHpD5W, 0, m, &cSlice_xlYHpD5W_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_pj34wOVZ, 0, m, &cSlice_pj34wOVZ_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_BwelTstx, 0, m, &cSlice_BwelTstx_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_uclruHvb, 0, m, &cSlice_uclruHvb_sendMessage);
}

void Heavy_prog::cSwitchcase_KAAKeSoT_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_ezFfyMvF_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_ezFfyMvF_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZwOnXhYl_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_3vuEnRUX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_3vuEnRUX, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3vuEnRUX, 0, m, &cDelay_3vuEnRUX_sendMessage);
  cSwitchcase_aP7I04to_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_I5Af8MGw_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_ZwOnXhYl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ezFfyMvF_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3vuEnRUX, 0, m, &cDelay_3vuEnRUX_sendMessage);
  cSwitchcase_aP7I04to_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_I5Af8MGw_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_iKVF9Cn2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Yd8Drsjg_sendMessage);
}

void Heavy_prog::cSystem_Yd8Drsjg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_XCH2RZHZ_sendMessage);
}

void Heavy_prog::cVar_78mDvQu1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cl3tevI3, HV_BINOP_MULTIPLY, 0, m, &cBinop_cl3tevI3_sendMessage);
}

void Heavy_prog::cMsg_ezFfyMvF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_3vuEnRUX, 0, m, &cDelay_3vuEnRUX_sendMessage);
}

void Heavy_prog::cBinop_dCq0Ir8L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_3vuEnRUX, 2, m, &cDelay_3vuEnRUX_sendMessage);
}

void Heavy_prog::cBinop_XCH2RZHZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cl3tevI3, HV_BINOP_MULTIPLY, 1, m, &cBinop_cl3tevI3_sendMessage);
}

void Heavy_prog::cBinop_cl3tevI3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_dCq0Ir8L_sendMessage);
}

void Heavy_prog::cSwitchcase_SpJKTZRo_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_1YE9lbFD_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_1YE9lbFD_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vpxpCCFe_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_eZcvZenU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_eZcvZenU, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eZcvZenU, 0, m, &cDelay_eZcvZenU_sendMessage);
  cSwitchcase_KSbIl0wg_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_vpxpCCFe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1YE9lbFD_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eZcvZenU, 0, m, &cDelay_eZcvZenU_sendMessage);
  cSwitchcase_KSbIl0wg_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_mBllIngd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_7P9vQhLl_sendMessage);
}

void Heavy_prog::cSystem_7P9vQhLl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_1E37PtiI_sendMessage);
}

void Heavy_prog::cVar_J2kM03wP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZtVKqaQ3, HV_BINOP_MULTIPLY, 0, m, &cBinop_ZtVKqaQ3_sendMessage);
}

void Heavy_prog::cMsg_1YE9lbFD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_eZcvZenU, 0, m, &cDelay_eZcvZenU_sendMessage);
}

void Heavy_prog::cBinop_xL0sG40u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_eZcvZenU, 2, m, &cDelay_eZcvZenU_sendMessage);
}

void Heavy_prog::cBinop_1E37PtiI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZtVKqaQ3, HV_BINOP_MULTIPLY, 1, m, &cBinop_ZtVKqaQ3_sendMessage);
}

void Heavy_prog::cBinop_ZtVKqaQ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_xL0sG40u_sendMessage);
}

void Heavy_prog::cSwitchcase_KSbIl0wg_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_BXAUIHkq, 0, m, &cSlice_BXAUIHkq_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_OlRQAG6E, 0, m, &cRandom_OlRQAG6E_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_9KjVuOjj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_YXej3NEb_sendMessage);
}

void Heavy_prog::cUnop_YXej3NEb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 10.0f, 0, m, &cBinop_kQzLgc4L_sendMessage);
}

void Heavy_prog::cRandom_OlRQAG6E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_9KjVuOjj_sendMessage);
}

void Heavy_prog::cSlice_BXAUIHkq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_OlRQAG6E, 1, m, &cRandom_OlRQAG6E_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_1SBhD025_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_4Thkg9H9, 0, m, &cSlice_4Thkg9H9_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_bt3eH68z, 0, m, &cRandom_bt3eH68z_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_1udqGFWq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_WnYohth6_sendMessage);
}

void Heavy_prog::cUnop_WnYohth6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 10.0f, 0, m, &cBinop_lgYQnBig_sendMessage);
}

void Heavy_prog::cRandom_bt3eH68z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_1udqGFWq_sendMessage);
}

void Heavy_prog::cSlice_4Thkg9H9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_bt3eH68z, 1, m, &cRandom_bt3eH68z_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_I5Af8MGw_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_9tnFHl0Q, 0, m, &cSlice_9tnFHl0Q_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_aTSew397, 0, m, &cRandom_aTSew397_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_2fxMZGIi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_8qzTe4zH_sendMessage);
}

void Heavy_prog::cUnop_8qzTe4zH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jwWku2pL, HV_BINOP_ADD, 1, m, &cBinop_jwWku2pL_sendMessage);
}

void Heavy_prog::cRandom_aTSew397_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_2fxMZGIi_sendMessage);
}

void Heavy_prog::cSlice_9tnFHl0Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_aTSew397, 1, m, &cRandom_aTSew397_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cMsg_UkYhYMDx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_LDciaiwo, 0, m, NULL);
}

void Heavy_prog::cMsg_qoHggZJd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_YJjCAfef, 0, m, NULL);
}

void Heavy_prog::cMsg_ksHs3nI5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_is1u3QG1, 0, m, NULL);
}

void Heavy_prog::cMsg_SLcPiep0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_rNEt1U90, 0, m, NULL);
}

void Heavy_prog::cBinop_vjweMfpB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8A9HXOA9, 0, m, &cVar_8A9HXOA9_sendMessage);
}

void Heavy_prog::cBinop_kQzLgc4L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6neEiWqS, 0, m, &cVar_6neEiWqS_sendMessage);
}

void Heavy_prog::cBinop_8T9pEPns_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fnHJJ9NH, 0, m, &cVar_fnHJJ9NH_sendMessage);
}

void Heavy_prog::cBinop_lgYQnBig_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_b6fNFdLO, 0, m, &cVar_b6fNFdLO_sendMessage);
}

void Heavy_prog::cMsg_nit861eT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_AuAqbTvN_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_uR1bFQyG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_jwWku2pL, HV_BINOP_ADD, 0, m, &cBinop_jwWku2pL_sendMessage);
}

void Heavy_prog::cBinop_jwWku2pL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ZwiifBoS_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cReceive_LFao3aTI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_q9u7bKNv_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_GODYLGDd, 0, m, &cVar_GODYLGDd_sendMessage);
  cMsg_hTQ9njqj_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Be9Cpk94, 0, m, &cVar_Be9Cpk94_sendMessage);
  cMsg_VfM3Y9tz_sendMessage(_c, 0, m);
  cMsg_ZixlXCsM_sendMessage(_c, 0, m);
  cMsg_iKVF9Cn2_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_78mDvQu1, 0, m, &cVar_78mDvQu1_sendMessage);
  cMsg_mBllIngd_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_J2kM03wP, 0, m, &cVar_J2kM03wP_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_JUJBBUwh, 0, m, &cVar_JUJBBUwh_sendMessage);
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
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5, Bf6, Bf7, Bf8, Bf9, Bf10, Bf11;

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
    __hv_phasor_k_f(&sPhasor_9RdoAMYF, VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf3), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf4), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf2), VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf0), VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_phasor_k_f(&sPhasor_IaWqHVQG, VOf(Bf3));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_abs_f(VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf0), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf0), VOf(Bf3));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf5), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf4), VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf3), VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf1), VIf(Bf0), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_kRNUmMVO, VOf(Bf1));
    __hv_varread_f(&sVarf_YPCFi00d, VOf(Bf5));
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf2), VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_xNbHlG5o, VOf(Bf3));
    __hv_varread_f(&sVarf_UhgNplRe, VOf(Bf2));
    __hv_fma_f(VIf(Bf5), VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_phasor_f(&sPhasor_tWc7HPvM, VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf2));
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf0), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf4), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf5), VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf2), VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f);
    __hv_line_f(&sLine_is1u3QG1, VOf(Bf0));
    __hv_line_f(&sLine_rNEt1U90, VOf(Bf2));
    __hv_var_k_f(VOf(Bf4), 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f);
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_phasor_f(&sPhasor_wKJiUmR4, VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf2), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf4));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf6), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf7), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf5), VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf4), VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf0), VIf(Bf2), VOf(Bf0));
    __hv_var_k_f(VOf(Bf6), 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f);
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_phasor_f(&sPhasor_CMdIQHMm, VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_abs_f(VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf6), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf0), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf0), VOf(Bf6));
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf7), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf5), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf4), VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf6), VIf(Bf7), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_LDciaiwo, VOf(Bf7));
    __hv_line_f(&sLine_YJjCAfef, VOf(Bf6));
    __hv_add_f(VIf(Bf6), VIf(Bf0), VOf(Bf6));
    __hv_var_k_f(VOf(Bf5), 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f);
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_phasor_f(&sPhasor_EPXLfXdS, VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_abs_f(VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf6), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf6), VOf(Bf5));
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf8), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf9), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf4), VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf5), VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf7), VIf(Bf6), VOf(Bf7));
    __hv_var_k_f(VOf(Bf8), 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f);
    __hv_mul_f(VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_phasor_f(&sPhasor_J3aFXVSr, VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf7), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_abs_f(VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf8), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf7), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf7), VOf(Bf8));
    __hv_mul_f(VIf(Bf7), VIf(Bf8), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf9), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf4), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf5), VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf8), VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf0), 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f);
    __hv_line_f(&sLine_tq2mqZZn, VOf(Bf9));
    __hv_varread_f(&sVarf_objPY7Gh, VOf(Bf8));
    __hv_mul_f(VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf9), VOf(Bf8));
    __hv_floor_f(VIf(Bf8), VOf(Bf4));
    __hv_sub_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf8), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_abs_f(VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf8), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf8), VOf(Bf4));
    __hv_mul_f(VIf(Bf8), VIf(Bf4), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf10), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf11), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf5), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf8), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf4), VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf7), VIf(Bf0), VIf(Bf9), VOf(Bf0));
    __hv_fma_f(VIf(Bf1), VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf3), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(O0), VOf(O0));
    __hv_var_k_f(VOf(Bf3), 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f);
    __hv_add_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf6), 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f);
    __hv_fma_f(VIf(Bf2), VIf(Bf6), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf1), VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf3), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_mul_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(O1), VOf(O1));

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
