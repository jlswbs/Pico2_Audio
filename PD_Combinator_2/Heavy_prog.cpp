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
  numBytes += sLine_init(&sLine_nJfYMCMC);
  numBytes += sPhasor_init(&sPhasor_hkABiTEE, sampleRate);
  numBytes += sLine_init(&sLine_EWkWwWZ6);
  numBytes += sPhasor_init(&sPhasor_8iIOs0GG, sampleRate);
  numBytes += sLine_init(&sLine_Z6DVMeGp);
  numBytes += sPhasor_k_init(&sPhasor_PVOBCXNN, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_w6bugCxu, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_Weo8l11X);
  numBytes += sPhasor_init(&sPhasor_PAJLFf79, sampleRate);
  numBytes += sDel1_init(&sDel1_VTn5l1EK);
  numBytes += sSamphold_init(&sSamphold_qYYwPwwj);
  numBytes += sRPole_init(&sRPole_yF2T3zAp);
  numBytes += sPhasor_k_init(&sPhasor_3KrGvG5f, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_ai1Xzu2L, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_UCZnggPO);
  numBytes += sPhasor_init(&sPhasor_s3v42jCl, sampleRate);
  numBytes += sPhasor_init(&sPhasor_G47Aclun, sampleRate);
  numBytes += sPhasor_init(&sPhasor_vsYdDqND, sampleRate);
  numBytes += sLine_init(&sLine_a5AmQPKu);
  numBytes += sLine_init(&sLine_hAAHSc6j);
  numBytes += sTabhead_init(&sTabhead_GMBUDSG3, &hTable_ShYD98Wr);
  numBytes += sTabread_init(&sTabread_Ax5TchwI, &hTable_ShYD98Wr, false);
  numBytes += sTabread_init(&sTabread_3GJ7jomA, &hTable_ShYD98Wr, false);
  numBytes += sLine_init(&sLine_Bnj82DFC);
  numBytes += sLine_init(&sLine_YVTMNqNi);
  numBytes += sTabhead_init(&sTabhead_XW47bxAE, &hTable_UBsTbrIQ);
  numBytes += sTabread_init(&sTabread_3RAqMdWy, &hTable_UBsTbrIQ, false);
  numBytes += sTabread_init(&sTabread_4e2jX6dl, &hTable_UBsTbrIQ, false);
  numBytes += sLine_init(&sLine_nw3wEL0j);
  numBytes += sTabwrite_init(&sTabwrite_bqH2eNDv, &hTable_UBsTbrIQ);
  numBytes += sTabwrite_init(&sTabwrite_PBlvOfaq, &hTable_ShYD98Wr);
  numBytes += cVar_init_f(&cVar_W8j6gANJ, 0.0f);
  numBytes += cVar_init_f(&cVar_rTUHUIMl, 1.0f);
  numBytes += cVar_init_f(&cVar_wxuOCmOO, 0.0f);
  numBytes += cRandom_init(&cRandom_7lcCkl59, -816215374);
  numBytes += cSlice_init(&cSlice_eB7QXUHP, 1, 1);
  numBytes += cPack_init(&cPack_A4rjOfuM, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_G2xEIGxz, 4, 1);
  numBytes += cSlice_init(&cSlice_CWmYWInk, 3, 1);
  numBytes += cSlice_init(&cSlice_rxU4oAhG, 2, 1);
  numBytes += cSlice_init(&cSlice_oIdO5Y1r, 1, 1);
  numBytes += cSlice_init(&cSlice_1BLFFInO, 0, 1);
  numBytes += sVarf_init(&sVarf_q7wy3ygM, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_wYzxqDRq, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_VjdvtlNC, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_lNWAKkKx, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_wdmaXtfD, 0.0f);
  numBytes += cDelay_init(this, &cDelay_3v6GfgXX, 0.0f);
  numBytes += cVar_init_f(&cVar_gbQfcyAx, 240.0f);
  numBytes += cBinop_init(&cBinop_CdtdvnZZ, 0.0f); // __mul
  numBytes += cPack_init(&cPack_wGwzRg11, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_SN3HcuRY, 4, 1);
  numBytes += cSlice_init(&cSlice_5sXhimTc, 3, 1);
  numBytes += cSlice_init(&cSlice_YWJ6GYwB, 2, 1);
  numBytes += cSlice_init(&cSlice_y8boNSEw, 1, 1);
  numBytes += cSlice_init(&cSlice_S6nIRUTa, 0, 1);
  numBytes += sVarf_init(&sVarf_ZD1qa7Ff, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_noSiBcjX, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_e9Q3n8OA, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_EgyP79ak, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_tgjvlkil, 0.0f);
  numBytes += cVar_init_f(&cVar_8FilOoYy, 0.0f);
  numBytes += cVar_init_f(&cVar_hErxSlMQ, 0.0f);
  numBytes += cVar_init_f(&cVar_HmbKGmB3, 0.0f);
  numBytes += cVar_init_f(&cVar_TJEqEWdP, 22050.0f);
  numBytes += cBinop_init(&cBinop_RjPx4TJE, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_GD7gFKDc, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_6p0GlcSf, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_JsuCNCri, 0.0f);
  numBytes += cPack_init(&cPack_C59JIOWH, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_0sWSdSc4, 2, 0.0f, 0.0f);
  numBytes += cVar_init_s(&cVar_NoVWSYbR, "del-1056-inputdelay");
  numBytes += sVarf_init(&sVarf_f9H4Z7tY, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_zVq9rX1c, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_tEVox5qL, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_oEfDmSFs, "del-1056-outputdelay");
  numBytes += sVarf_init(&sVarf_1yUpDfUL, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_cXycfIxT, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Pxc22I1a, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_481VmPEH, 0.0f);
  numBytes += cDelay_init(this, &cDelay_upIOsx9V, 0.0f);
  numBytes += hTable_init(&hTable_UBsTbrIQ, 256);
  numBytes += cDelay_init(this, &cDelay_ujVbuQGX, 0.0f);
  numBytes += cDelay_init(this, &cDelay_fIRsBMxH, 0.0f);
  numBytes += hTable_init(&hTable_ShYD98Wr, 256);
  numBytes += cDelay_init(this, &cDelay_Z43Yy3z3, 0.0f);
  numBytes += cVar_init_f(&cVar_Ci5yaceL, 360.0f);
  numBytes += cBinop_init(&cBinop_MjzwVz53, 0.0f); // __mul
  numBytes += cRandom_init(&cRandom_X7ZZMgde, 324120903);
  numBytes += cSlice_init(&cSlice_YAajXtAC, 1, 1);
  numBytes += cBinop_init(&cBinop_fFuoIuVL, 1.0f); // __pow
  numBytes += sVarf_init(&sVarf_MRkzqZnL, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_mNrVCgI7, 40.0f);
  numBytes += cVar_init_f(&cVar_K9G40gze, 30.0f);
  numBytes += cVar_init_f(&cVar_ROfQQtRN, 25.0f);
  numBytes += cPack_init(&cPack_HxWJjsrA, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_Cgn3DMlv, 50.0f);
  numBytes += cVar_init_f(&cVar_mxssSgvc, 60.0f);
  numBytes += cSlice_init(&cSlice_8CBjIrDJ, 2, 1);
  numBytes += cSlice_init(&cSlice_cBX6Pkex, 1, 1);
  numBytes += cSlice_init(&cSlice_AS7ppurV, 0, 1);
  numBytes += cSlice_init(&cSlice_IzEcvL1P, 1, -1);
  numBytes += cDelay_init(this, &cDelay_ENsxRd88, 0.0f);
  numBytes += cDelay_init(this, &cDelay_riDt1OxU, 0.0f);
  numBytes += cIf_init(&cIf_Hh8tJ2mL, false);
  numBytes += cSlice_init(&cSlice_L0nuVbEa, 1, -1);
  numBytes += cPack_init(&cPack_3yzU9g5T, 2, 0.0f, 0.0f);
  numBytes += sVarf_init(&sVarf_tFSl5x6N, 1.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_6g5v7mJZ, 1.0f); // __pow
  numBytes += sVarf_init(&sVarf_61avkbsr, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_q4qHLIKj, 100.0f);
  numBytes += cVar_init_f(&cVar_y3Bnfkl1, 8.0f);
  numBytes += cPack_init(&cPack_CFbqqqRw, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_DHJPWAOL, 30.0f);
  numBytes += cVar_init_f(&cVar_Jvpiho6N, 50.0f);
  numBytes += cVar_init_f(&cVar_qCrSdh3V, 50.0f);
  numBytes += cVar_init_f(&cVar_r53NBIYP, 120.0f);
  numBytes += cSlice_init(&cSlice_EiN4FkTm, 2, 1);
  numBytes += cSlice_init(&cSlice_9tOt6x61, 1, 1);
  numBytes += cSlice_init(&cSlice_ATcY1Td7, 0, 1);
  numBytes += cSlice_init(&cSlice_jq09hdfN, 1, -1);
  numBytes += cDelay_init(this, &cDelay_A7eJFRBj, 0.0f);
  numBytes += cDelay_init(this, &cDelay_PznM48Jl, 0.0f);
  numBytes += cIf_init(&cIf_RbYDYIbW, false);
  numBytes += cSlice_init(&cSlice_x3QGeGUl, 1, -1);
  numBytes += cPack_init(&cPack_rcQhsGdP, 2, 0.0f, 0.0f);
  numBytes += sVarf_init(&sVarf_H84vJuZl, 2.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_xiFM6HIu, 1.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_UF8WBoeW, 1.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_v1yoq5U6, 1236192905);
  numBytes += cSlice_init(&cSlice_ZQlXBqPn, 1, 1);
  numBytes += cRandom_init(&cRandom_YPRHUkkH, 176033737);
  numBytes += cSlice_init(&cSlice_M7rAMhW3, 1, 1);
  numBytes += cVar_init_f(&cVar_ooMGtvvF, 37.0f);
  numBytes += cVar_init_f(&cVar_Sjl3IabK, 28.0f);
  numBytes += cVar_init_f(&cVar_smxDCpVT, 10.0f);
  numBytes += cVar_init_f(&cVar_JUtWU4XH, 220.0f);
  numBytes += cBinop_init(&cBinop_PF5Mcfpt, 29.0f); // __div
  numBytes += sVarf_init(&sVarf_3Rrf6rlY, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_asg4tMMY, -1429338088);
  numBytes += cSlice_init(&cSlice_SQfSVFH7, 1, 1);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_prog::~Heavy_prog() {
  cPack_free(&cPack_A4rjOfuM);
  cPack_free(&cPack_wGwzRg11);
  cPack_free(&cPack_C59JIOWH);
  cPack_free(&cPack_0sWSdSc4);
  hTable_free(&hTable_UBsTbrIQ);
  hTable_free(&hTable_ShYD98Wr);
  cPack_free(&cPack_HxWJjsrA);
  cPack_free(&cPack_3yzU9g5T);
  cPack_free(&cPack_CFbqqqRw);
  cPack_free(&cPack_rcQhsGdP);
}

HvTable *Heavy_prog::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x35785DD9: return &hTable_UBsTbrIQ; // del-1056-outputdelay
    case 0xF3BC6302: return &hTable_ShYD98Wr; // del-1056-inputdelay
    default: return nullptr;
  }
}

void Heavy_prog::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_MlD2gUGZ_sendMessage);
      break;
    }
    case 0xF7AB77BA: { // dur
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_CqtpddWc_sendMessage);
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


void Heavy_prog::cVar_W8j6gANJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_l0oCMhFc_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cVar_rTUHUIMl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_8ZLhFHfI_sendMessage);
  cSwitchcase_oJGSsNrS_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_3m8eWnpA_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_8ZLhFHfI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rTUHUIMl, 1, m, &cVar_rTUHUIMl_sendMessage);
}

void Heavy_prog::cVar_wxuOCmOO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WwFIQrLt_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZHBPwXxr_sendMessage);
}

void Heavy_prog::cSwitchcase_ivHa8HMy_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_eB7QXUHP, 0, m, &cSlice_eB7QXUHP_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_7lcCkl59, 0, m, &cRandom_7lcCkl59_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_NrbziHn1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_is4A4rCS_sendMessage);
}

void Heavy_prog::cUnop_is4A4rCS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tgjvlkil, 0, m, &cVar_tgjvlkil_sendMessage);
}

void Heavy_prog::cRandom_7lcCkl59_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_NrbziHn1_sendMessage);
}

void Heavy_prog::cSlice_eB7QXUHP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_7lcCkl59, 1, m, &cRandom_7lcCkl59_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cPack_A4rjOfuM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tgokL91T_sendMessage(_c, 0, m);
}

void Heavy_prog::cSlice_G2xEIGxz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_q7wy3ygM, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_CWmYWInk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_lNWAKkKx, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_rxU4oAhG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_VjdvtlNC, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_oIdO5Y1r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_w6bugCxu, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_1BLFFInO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_PVOBCXNN, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_jGggqWEV_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7fX6IAZj_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_7fX6IAZj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KrcZyIhU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0nvrGLLS_sendMessage);
}

void Heavy_prog::cCast_KrcZyIhU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_0nvrGLLS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DQxJcYTR_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_49hEj0nq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wYzxqDRq, HV_BINOP_MULTIPLY, 0, m, &cBinop_wYzxqDRq_sendMessage);
}

void Heavy_prog::cCast_418HkmhO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_A4rjOfuM, 0, m, &cPack_A4rjOfuM_sendMessage);
}

void Heavy_prog::cMsg_DQxJcYTR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_49hEj0nq_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_418HkmhO_sendMessage);
}

void Heavy_prog::cBinop_wYzxqDRq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_A4rjOfuM, 1, m, &cPack_A4rjOfuM_sendMessage);
}

void Heavy_prog::cBinop_ih44YR3v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wYzxqDRq, HV_BINOP_MULTIPLY, 1, m, &cBinop_wYzxqDRq_sendMessage);
}

void Heavy_prog::cMsg_NrLSGoyx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.1f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 600.0f, 0, m, &cBinop_ih44YR3v_sendMessage);
}

void Heavy_prog::cMsg_tgokL91T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Weo8l11X, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 1);
  sLine_onMessage(_c, &Context(_c)->sLine_Weo8l11X, 0, m, NULL);
}

void Heavy_prog::cMsg_Dxrso7ah_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(5);
  msg_init(m, 5, msg_getTimestamp(n));
  msg_setFloat(m, 0, 748.031f);
  msg_setFloat(m, 1, 1023.62f);
  msg_setFloat(m, 2, 0.173228f);
  msg_setFloat(m, 3, 1968.5f);
  msg_setFloat(m, 4, 9259.84f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_G2xEIGxz, 0, m, &cSlice_G2xEIGxz_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_CWmYWInk, 0, m, &cSlice_CWmYWInk_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_rxU4oAhG, 0, m, &cSlice_rxU4oAhG_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_oIdO5Y1r, 0, m, &cSlice_oIdO5Y1r_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_1BLFFInO, 0, m, &cSlice_1BLFFInO_sendMessage);
}

void Heavy_prog::cVar_wdmaXtfD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HxOMnV7f_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0ndpx8dr_sendMessage);
}

void Heavy_prog::cSwitchcase_oJGSsNrS_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_okIpauTa_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_okIpauTa_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_avplGojE_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_3v6GfgXX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_3v6GfgXX, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3v6GfgXX, 0, m, &cDelay_3v6GfgXX_sendMessage);
  cSwitchcase_CwpCYNsH_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_ewCaq7Qy_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_avplGojE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_okIpauTa_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3v6GfgXX, 0, m, &cDelay_3v6GfgXX_sendMessage);
  cSwitchcase_CwpCYNsH_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_ewCaq7Qy_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_YlUigL53_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_EPIjW80u_sendMessage);
}

void Heavy_prog::cSystem_EPIjW80u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_fh2yWSHm_sendMessage);
}

void Heavy_prog::cVar_gbQfcyAx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CdtdvnZZ, HV_BINOP_MULTIPLY, 0, m, &cBinop_CdtdvnZZ_sendMessage);
}

void Heavy_prog::cMsg_okIpauTa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_3v6GfgXX, 0, m, &cDelay_3v6GfgXX_sendMessage);
}

void Heavy_prog::cBinop_yGQmhAUQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_3v6GfgXX, 2, m, &cDelay_3v6GfgXX_sendMessage);
}

void Heavy_prog::cBinop_fh2yWSHm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CdtdvnZZ, HV_BINOP_MULTIPLY, 1, m, &cBinop_CdtdvnZZ_sendMessage);
}

void Heavy_prog::cBinop_CdtdvnZZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_yGQmhAUQ_sendMessage);
}

void Heavy_prog::cPack_wGwzRg11_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZX6e4YKU_sendMessage(_c, 0, m);
}

void Heavy_prog::cSlice_SN3HcuRY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_ZD1qa7Ff, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_5sXhimTc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_EgyP79ak, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_YWJ6GYwB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_e9Q3n8OA, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_y8boNSEw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_ai1Xzu2L, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_S6nIRUTa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_3KrGvG5f, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_eWYAbQim_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1OLBWRoH_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_1OLBWRoH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_K6kJknxn_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qthYvSxh_sendMessage);
}

void Heavy_prog::cCast_K6kJknxn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_qthYvSxh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1KJD707S_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_2zmfCaTE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_noSiBcjX, HV_BINOP_MULTIPLY, 0, m, &cBinop_noSiBcjX_sendMessage);
}

void Heavy_prog::cCast_u1psvoS3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_wGwzRg11, 0, m, &cPack_wGwzRg11_sendMessage);
}

void Heavy_prog::cMsg_1KJD707S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2zmfCaTE_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_u1psvoS3_sendMessage);
}

void Heavy_prog::cBinop_noSiBcjX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_wGwzRg11, 1, m, &cPack_wGwzRg11_sendMessage);
}

void Heavy_prog::cBinop_AUKnAoyi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_noSiBcjX, HV_BINOP_MULTIPLY, 1, m, &cBinop_noSiBcjX_sendMessage);
}

void Heavy_prog::cMsg_bDKyf99O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.1f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 600.0f, 0, m, &cBinop_AUKnAoyi_sendMessage);
}

void Heavy_prog::cMsg_ZX6e4YKU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_UCZnggPO, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 1);
  sLine_onMessage(_c, &Context(_c)->sLine_UCZnggPO, 0, m, NULL);
}

void Heavy_prog::cMsg_jeh2kG9F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(5);
  msg_init(m, 5, msg_getTimestamp(n));
  msg_setFloat(m, 0, 748.031f);
  msg_setFloat(m, 1, 1023.62f);
  msg_setFloat(m, 2, 0.173228f);
  msg_setFloat(m, 3, 1968.5f);
  msg_setFloat(m, 4, 9259.84f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_SN3HcuRY, 0, m, &cSlice_SN3HcuRY_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_5sXhimTc, 0, m, &cSlice_5sXhimTc_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_YWJ6GYwB, 0, m, &cSlice_YWJ6GYwB_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_y8boNSEw, 0, m, &cSlice_y8boNSEw_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_S6nIRUTa, 0, m, &cSlice_S6nIRUTa_sendMessage);
}

void Heavy_prog::cVar_tgjvlkil_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_jGggqWEV_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cVar_8FilOoYy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_eWYAbQim_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cVar_hErxSlMQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1000.0f, 0, m, &cBinop_VJbO38i3_sendMessage);
}

void Heavy_prog::cVar_HmbKGmB3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 0.999f, 0, m, &cBinop_8tr8xaJ9_sendMessage);
}

void Heavy_prog::cVar_TJEqEWdP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RjPx4TJE, HV_BINOP_MULTIPLY, 0, m, &cBinop_RjPx4TJE_sendMessage);
}

void Heavy_prog::cMsg_AxbCM1YZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_7BP832xf_sendMessage);
}

void Heavy_prog::cSystem_7BP832xf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wYhgGbc9_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_RjPx4TJE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_VpnPBS1I_sendMessage);
}

void Heavy_prog::cBinop_jHchOYOK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RjPx4TJE, HV_BINOP_MULTIPLY, 1, m, &cBinop_RjPx4TJE_sendMessage);
}

void Heavy_prog::cMsg_wYhgGbc9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_jHchOYOK_sendMessage);
}

void Heavy_prog::cBinop_VpnPBS1I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_TQYKwxlk_sendMessage);
}

void Heavy_prog::cBinop_TQYKwxlk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_nDfjEbp5_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_6p0GlcSf, m);
}

void Heavy_prog::cBinop_nDfjEbp5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_GD7gFKDc, m);
}

void Heavy_prog::cVar_JsuCNCri_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TJEqEWdP, 0, m, &cVar_TJEqEWdP_sendMessage);
}

void Heavy_prog::cPack_C59JIOWH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_hAAHSc6j, 0, m, NULL);
}

void Heavy_prog::cPack_0sWSdSc4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_YVTMNqNi, 0, m, NULL);
}

void Heavy_prog::cMsg_41HS0QRV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_RXlcJnYm_sendMessage);
}

void Heavy_prog::cSystem_RXlcJnYm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_LW7Vmdb2_sendMessage);
}

void Heavy_prog::cVar_NoVWSYbR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KGnpojq6_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_ryCBDPlV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_oyiD1N6F_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_f9H4Z7tY, m);
}

void Heavy_prog::cBinop_LW7Vmdb2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_zVq9rX1c, m);
}

void Heavy_prog::cMsg_KGnpojq6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ryCBDPlV_sendMessage);
}

void Heavy_prog::cBinop_oyiD1N6F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_tEVox5qL, m);
}

void Heavy_prog::cMsg_dkQhA6Tv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_TdLWqMrb_sendMessage);
}

void Heavy_prog::cSystem_TdLWqMrb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_HzYwWLK8_sendMessage);
}

void Heavy_prog::cVar_oEfDmSFs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iqeuYFAD_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_G8QvOWT3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_YxYYt6sk_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_1yUpDfUL, m);
}

void Heavy_prog::cBinop_HzYwWLK8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_cXycfIxT, m);
}

void Heavy_prog::cMsg_iqeuYFAD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_G8QvOWT3_sendMessage);
}

void Heavy_prog::cBinop_YxYYt6sk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Pxc22I1a, m);
}

void Heavy_prog::cBinop_8tr8xaJ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_gnaHYos3_sendMessage);
}

void Heavy_prog::cBinop_gnaHYos3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_X2nkUyOV_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_5qQ6pQMb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_eMNQkMGS_sendMessage);
}

void Heavy_prog::cBinop_eMNQkMGS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LWDlQTap_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_VJbO38i3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_OFWHTa32_sendMessage);
}

void Heavy_prog::cBinop_OFWHTa32_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_tQe8ojDL_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_HmXi95qg_sendMessage);
}

void Heavy_prog::cMsg_qf0XwH9p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_H14ZMIf2_sendMessage);
}

void Heavy_prog::cSystem_H14ZMIf2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_0Y43JFbX_sendMessage);
}

void Heavy_prog::cDelay_481VmPEH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_481VmPEH, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_upIOsx9V, 0, m, &cDelay_upIOsx9V_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_481VmPEH, 0, m, &cDelay_481VmPEH_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_bqH2eNDv, 1, m, NULL);
}

void Heavy_prog::cDelay_upIOsx9V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_upIOsx9V, m);
  cMsg_TMHIXyXL_sendMessage(_c, 0, m);
}

void Heavy_prog::cSwitchcase_nplNJKpn_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_KvqamoJj_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cBinop_aRuz6xuF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5j2BiW00_sendMessage(_c, 0, m);
}

void Heavy_prog::hTable_UBsTbrIQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BYELWbPH_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_481VmPEH, 2, m, &cDelay_481VmPEH_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2JLGcnj2_sendMessage);
}

void Heavy_prog::cMsg_5j2BiW00_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_UBsTbrIQ, 0, m, &hTable_UBsTbrIQ_sendMessage);
}

void Heavy_prog::cBinop_0Y43JFbX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 500.0f, 0, m, &cBinop_aRuz6xuF_sendMessage);
}

void Heavy_prog::cMsg_TMHIXyXL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_UBsTbrIQ, 0, m, &hTable_UBsTbrIQ_sendMessage);
}

void Heavy_prog::cCast_2JLGcnj2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_481VmPEH, 0, m, &cDelay_481VmPEH_sendMessage);
}

void Heavy_prog::cMsg_BYELWbPH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_upIOsx9V, 2, m, &cDelay_upIOsx9V_sendMessage);
}

void Heavy_prog::cMsg_KvqamoJj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_bqH2eNDv, 1, m, NULL);
}

void Heavy_prog::cMsg_3uKYPcPz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_lwkhaFHX_sendMessage);
}

void Heavy_prog::cSystem_lwkhaFHX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Uf4sPWt3_sendMessage);
}

void Heavy_prog::cDelay_ujVbuQGX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ujVbuQGX, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fIRsBMxH, 0, m, &cDelay_fIRsBMxH_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ujVbuQGX, 0, m, &cDelay_ujVbuQGX_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_PBlvOfaq, 1, m, NULL);
}

void Heavy_prog::cDelay_fIRsBMxH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_fIRsBMxH, m);
  cMsg_jv09E43O_sendMessage(_c, 0, m);
}

void Heavy_prog::cSwitchcase_rHTr4hF9_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_LC9NdvTM_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cBinop_IwUMM7Ta_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ejnbeKLK_sendMessage(_c, 0, m);
}

void Heavy_prog::hTable_ShYD98Wr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yKkoRwqk_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ujVbuQGX, 2, m, &cDelay_ujVbuQGX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KRahda0m_sendMessage);
}

void Heavy_prog::cMsg_ejnbeKLK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_ShYD98Wr, 0, m, &hTable_ShYD98Wr_sendMessage);
}

void Heavy_prog::cBinop_Uf4sPWt3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 500.0f, 0, m, &cBinop_IwUMM7Ta_sendMessage);
}

void Heavy_prog::cMsg_jv09E43O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_ShYD98Wr, 0, m, &hTable_ShYD98Wr_sendMessage);
}

void Heavy_prog::cCast_KRahda0m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ujVbuQGX, 0, m, &cDelay_ujVbuQGX_sendMessage);
}

void Heavy_prog::cMsg_yKkoRwqk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_fIRsBMxH, 2, m, &cDelay_fIRsBMxH_sendMessage);
}

void Heavy_prog::cMsg_LC9NdvTM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_PBlvOfaq, 1, m, NULL);
}

void Heavy_prog::cMsg_LWDlQTap_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_nw3wEL0j, 0, m, NULL);
}

void Heavy_prog::cMsg_X2nkUyOV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Bnj82DFC, 0, m, NULL);
}

void Heavy_prog::cCast_HmXi95qg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_C59JIOWH, 1, m, &cPack_C59JIOWH_sendMessage);
}

void Heavy_prog::cCast_tQe8ojDL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_0sWSdSc4, 1, m, &cPack_0sWSdSc4_sendMessage);
}

void Heavy_prog::cBinop_FJI5r2Mt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_0sWSdSc4, 0, m, &cPack_0sWSdSc4_sendMessage);
}

void Heavy_prog::cBinop_ICissggF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_C59JIOWH, 0, m, &cPack_C59JIOWH_sendMessage);
}

void Heavy_prog::cMsg_ShkaDX72_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 250.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 500.0f, 0, m, &cBinop_ICissggF_sendMessage);
}

void Heavy_prog::cMsg_hN4ezQIN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 250.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 500.0f, 0, m, &cBinop_FJI5r2Mt_sendMessage);
}

void Heavy_prog::cMsg_snoB7RpS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.9f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 0.999f, 0, m, &cBinop_5qQ6pQMb_sendMessage);
}

void Heavy_prog::cSwitchcase_3m8eWnpA_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_uwg8WLsO_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_uwg8WLsO_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uhfSEOJ7_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_Z43Yy3z3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Z43Yy3z3, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Z43Yy3z3, 0, m, &cDelay_Z43Yy3z3_sendMessage);
  cSwitchcase_ivHa8HMy_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_Fela7A4P_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_UFqOczpK_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_uhfSEOJ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uwg8WLsO_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Z43Yy3z3, 0, m, &cDelay_Z43Yy3z3_sendMessage);
  cSwitchcase_ivHa8HMy_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_Fela7A4P_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_UFqOczpK_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_P3JZlb9J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6ojTtIS5_sendMessage);
}

void Heavy_prog::cSystem_6ojTtIS5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_NjEMYDrE_sendMessage);
}

void Heavy_prog::cVar_Ci5yaceL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MjzwVz53, HV_BINOP_MULTIPLY, 0, m, &cBinop_MjzwVz53_sendMessage);
}

void Heavy_prog::cMsg_uwg8WLsO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Z43Yy3z3, 0, m, &cDelay_Z43Yy3z3_sendMessage);
}

void Heavy_prog::cBinop_cJIH0466_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Z43Yy3z3, 2, m, &cDelay_Z43Yy3z3_sendMessage);
}

void Heavy_prog::cBinop_NjEMYDrE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MjzwVz53, HV_BINOP_MULTIPLY, 1, m, &cBinop_MjzwVz53_sendMessage);
}

void Heavy_prog::cBinop_MjzwVz53_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_cJIH0466_sendMessage);
}

void Heavy_prog::cSwitchcase_Fela7A4P_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_YAajXtAC, 0, m, &cSlice_YAajXtAC_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_X7ZZMgde, 0, m, &cRandom_X7ZZMgde_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_tUE9Vrvh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_aw4kWpNC_sendMessage);
}

void Heavy_prog::cUnop_aw4kWpNC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_W8j6gANJ, 0, m, &cVar_W8j6gANJ_sendMessage);
}

void Heavy_prog::cRandom_X7ZZMgde_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5.0f, 0, m, &cBinop_tUE9Vrvh_sendMessage);
}

void Heavy_prog::cSlice_YAajXtAC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_X7ZZMgde, 1, m, &cRandom_X7ZZMgde_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_5QBgsSwu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_MRkzqZnL, m);
}

void Heavy_prog::cBinop_sd0PCCPy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_ZkhmpYAA_sendMessage);
}

void Heavy_prog::cBinop_ZkhmpYAA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fFuoIuVL, HV_BINOP_POW, 1, m, &cBinop_fFuoIuVL_sendMessage);
  cMsg_X1bevG0c_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_fFuoIuVL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_5QBgsSwu_sendMessage);
}

void Heavy_prog::cMsg_X1bevG0c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_fFuoIuVL, HV_BINOP_POW, 0, m, &cBinop_fFuoIuVL_sendMessage);
}

void Heavy_prog::cBinop_GscrLBmC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -10.0f, 0, m, &cBinop_DqMJ6QQs_sendMessage);
}

void Heavy_prog::cBinop_DqMJ6QQs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_tFSl5x6N, m);
}

void Heavy_prog::cBinop_VXcc5LoE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -10.0f, 0, m, &cBinop_dOM3lYnW_sendMessage);
}

void Heavy_prog::cBinop_dOM3lYnW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_f5Ucll1k_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_mNrVCgI7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 10.0f, 0, m, &cBinop_GscrLBmC_sendMessage);
}

void Heavy_prog::cVar_K9G40gze_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 10.0f, 0, m, &cBinop_VXcc5LoE_sendMessage);
}

void Heavy_prog::cVar_ROfQQtRN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_HxWJjsrA, 0, m, &cPack_HxWJjsrA_sendMessage);
}

void Heavy_prog::cPack_HxWJjsrA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_u8DyI0Ua_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_Cgn3DMlv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_HxWJjsrA, 2, m, &cPack_HxWJjsrA_sendMessage);
}

void Heavy_prog::cVar_mxssSgvc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_HxWJjsrA, 1, m, &cPack_HxWJjsrA_sendMessage);
}

void Heavy_prog::cSlice_8CBjIrDJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cDelay_onMessage(_c, &Context(_c)->cDelay_ENsxRd88, 1, m, &cDelay_ENsxRd88_sendMessage);
      cDelay_onMessage(_c, &Context(_c)->cDelay_riDt1OxU, 1, m, &cDelay_riDt1OxU_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_cBX6Pkex_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9r8xC5TF_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eitDqaRx_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_AS7ppurV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_iFJyhGd0_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_fVhk0WM3_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_IzEcvL1P, 0, m, &cSlice_IzEcvL1P_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ww87yDZ6_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_8CBjIrDJ, 0, m, &cSlice_8CBjIrDJ_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_cBX6Pkex, 0, m, &cSlice_cBX6Pkex_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_AS7ppurV, 0, m, &cSlice_AS7ppurV_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cSlice_IzEcvL1P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bYCY9inA_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1N39z5ec_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bYCY9inA_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1N39z5ec_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cDelay_ENsxRd88_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ENsxRd88, m);
  cPack_onMessage(_c, &Context(_c)->cPack_3yzU9g5T, 0, m, &cPack_3yzU9g5T_sendMessage);
  cMsg_wlaYOeGP_sendMessage(_c, 0, m);
}

void Heavy_prog::cDelay_riDt1OxU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_riDt1OxU, m);
  cPack_onMessage(_c, &Context(_c)->cPack_3yzU9g5T, 1, m, &cPack_3yzU9g5T_sendMessage);
}

void Heavy_prog::cIf_Hh8tJ2mL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cDelay_onMessage(_c, &Context(_c)->cDelay_riDt1OxU, 0, m, &cDelay_riDt1OxU_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_iFJyhGd0_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cSlice_onMessage(_c, &Context(_c)->cSlice_L0nuVbEa, 0, m, &cSlice_L0nuVbEa_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DOl6QpC4_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_orGuVV6s_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cSlice_L0nuVbEa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_FWqQ2BhS_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_FWqQ2BhS_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cMsg_wlaYOeGP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cIf_onMessage(_c, &Context(_c)->cIf_Hh8tJ2mL, 1, m, &cIf_Hh8tJ2mL_sendMessage);
}

void Heavy_prog::cMsg_3NbIFw3K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cIf_onMessage(_c, &Context(_c)->cIf_Hh8tJ2mL, 1, m, &cIf_Hh8tJ2mL_sendMessage);
}

void Heavy_prog::cCast_DOl6QpC4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Hh8tJ2mL, 0, m, &cIf_Hh8tJ2mL_sendMessage);
}

void Heavy_prog::cCast_orGuVV6s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ENsxRd88, 0, m, &cDelay_ENsxRd88_sendMessage);
}

void Heavy_prog::cCast_9r8xC5TF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_riDt1OxU, 0, m, &cDelay_riDt1OxU_sendMessage);
}

void Heavy_prog::cCast_eitDqaRx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3NbIFw3K_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_FWqQ2BhS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_riDt1OxU, 0, m, &cDelay_riDt1OxU_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ENsxRd88, 0, m, &cDelay_ENsxRd88_sendMessage);
}

void Heavy_prog::cPack_3yzU9g5T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_Z6DVMeGp, 0, m, NULL);
}

void Heavy_prog::cCast_ww87yDZ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_63RFJIMJ_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_63RFJIMJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ENsxRd88, 1, m, &cDelay_ENsxRd88_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_riDt1OxU, 1, m, &cDelay_riDt1OxU_sendMessage);
}

void Heavy_prog::cMsg_9LHovrwg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  sLine_onMessage(_c, &Context(_c)->sLine_Z6DVMeGp, 0, m, NULL);
}

void Heavy_prog::cCast_1N39z5ec_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9LHovrwg_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_bYCY9inA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JBXaT1wn_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_JBXaT1wn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cSwitchcase_iFJyhGd0_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_f5Ucll1k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 50.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_EWkWwWZ6, 0, m, NULL);
}

void Heavy_prog::cCast_WwFIQrLt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_33XCdujB_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_q6r1dqk9_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_q8XERXLC_sendMessage);
}

void Heavy_prog::cCast_ZHBPwXxr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_sd0PCCPy_sendMessage);
}

void Heavy_prog::cCast_33XCdujB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Cgn3DMlv, 0, m, &cVar_Cgn3DMlv_sendMessage);
}

void Heavy_prog::cCast_q8XERXLC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ROfQQtRN, 0, m, &cVar_ROfQQtRN_sendMessage);
}

void Heavy_prog::cCast_q6r1dqk9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mxssSgvc, 0, m, &cVar_mxssSgvc_sendMessage);
}

void Heavy_prog::cMsg_u8DyI0Ua_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_fVhk0WM3_onMessage(_c, NULL, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 1);
  msg_setElementToFrom(m, 2, n, 2);
  cSwitchcase_fVhk0WM3_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_O8RhuduG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_61avkbsr, m);
}

void Heavy_prog::cBinop_9ipRZZ9i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_JTjlRUCU_sendMessage);
}

void Heavy_prog::cBinop_JTjlRUCU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6g5v7mJZ, HV_BINOP_POW, 1, m, &cBinop_6g5v7mJZ_sendMessage);
  cMsg_d5YUlhye_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_6g5v7mJZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_O8RhuduG_sendMessage);
}

void Heavy_prog::cMsg_d5YUlhye_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_6g5v7mJZ, HV_BINOP_POW, 0, m, &cBinop_6g5v7mJZ_sendMessage);
}

void Heavy_prog::cBinop_X7LF0Dyq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -10.0f, 0, m, &cBinop_9ghPSPVh_sendMessage);
}

void Heavy_prog::cBinop_9ghPSPVh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_UF8WBoeW, m);
}

void Heavy_prog::cBinop_8whutfFA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -10.0f, 0, m, &cBinop_2jGNQNe1_sendMessage);
}

void Heavy_prog::cBinop_2jGNQNe1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_H84vJuZl, m);
}

void Heavy_prog::cVar_q4qHLIKj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 10.0f, 0, m, &cBinop_X7LF0Dyq_sendMessage);
}

void Heavy_prog::cVar_y3Bnfkl1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 10.0f, 0, m, &cBinop_8whutfFA_sendMessage);
}

void Heavy_prog::cPack_CFbqqqRw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jjIogc5O_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_DHJPWAOL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_CFbqqqRw, 2, m, &cPack_CFbqqqRw_sendMessage);
}

void Heavy_prog::cVar_Jvpiho6N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_CFbqqqRw, 1, m, &cPack_CFbqqqRw_sendMessage);
}

void Heavy_prog::cVar_qCrSdh3V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_CFbqqqRw, 0, m, &cPack_CFbqqqRw_sendMessage);
}

void Heavy_prog::cVar_r53NBIYP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 10.0f, 0, m, &cBinop_H4lIUZRk_sendMessage);
}

void Heavy_prog::cBinop_H4lIUZRk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_MojyC66V_sendMessage);
}

void Heavy_prog::cBinop_MojyC66V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_xiFM6HIu, m);
}

void Heavy_prog::cSlice_EiN4FkTm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cDelay_onMessage(_c, &Context(_c)->cDelay_A7eJFRBj, 1, m, &cDelay_A7eJFRBj_sendMessage);
      cDelay_onMessage(_c, &Context(_c)->cDelay_PznM48Jl, 1, m, &cDelay_PznM48Jl_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_9tOt6x61_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UQBit3Ow_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pEe3cUpm_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_ATcY1Td7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_KisYa0eX_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_SNdBDiR9_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_jq09hdfN, 0, m, &cSlice_jq09hdfN_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MxFcjBBV_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_EiN4FkTm, 0, m, &cSlice_EiN4FkTm_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_9tOt6x61, 0, m, &cSlice_9tOt6x61_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_ATcY1Td7, 0, m, &cSlice_ATcY1Td7_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cSlice_jq09hdfN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_K6ZyhK07_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_A9f8PmPA_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_K6ZyhK07_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_A9f8PmPA_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cDelay_A7eJFRBj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_A7eJFRBj, m);
  cPack_onMessage(_c, &Context(_c)->cPack_rcQhsGdP, 0, m, &cPack_rcQhsGdP_sendMessage);
  cMsg_vPF3jgPM_sendMessage(_c, 0, m);
}

void Heavy_prog::cDelay_PznM48Jl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_PznM48Jl, m);
  cPack_onMessage(_c, &Context(_c)->cPack_rcQhsGdP, 1, m, &cPack_rcQhsGdP_sendMessage);
}

void Heavy_prog::cIf_RbYDYIbW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cDelay_onMessage(_c, &Context(_c)->cDelay_PznM48Jl, 0, m, &cDelay_PznM48Jl_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_KisYa0eX_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cSlice_onMessage(_c, &Context(_c)->cSlice_x3QGeGUl, 0, m, &cSlice_x3QGeGUl_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_p9Ou7eUq_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_iDsTIokd_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cSlice_x3QGeGUl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_Sr30jzln_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_Sr30jzln_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cMsg_vPF3jgPM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cIf_onMessage(_c, &Context(_c)->cIf_RbYDYIbW, 1, m, &cIf_RbYDYIbW_sendMessage);
}

void Heavy_prog::cMsg_Zva4iDlX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cIf_onMessage(_c, &Context(_c)->cIf_RbYDYIbW, 1, m, &cIf_RbYDYIbW_sendMessage);
}

void Heavy_prog::cCast_p9Ou7eUq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_RbYDYIbW, 0, m, &cIf_RbYDYIbW_sendMessage);
}

void Heavy_prog::cCast_iDsTIokd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_A7eJFRBj, 0, m, &cDelay_A7eJFRBj_sendMessage);
}

void Heavy_prog::cCast_pEe3cUpm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Zva4iDlX_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_UQBit3Ow_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_PznM48Jl, 0, m, &cDelay_PznM48Jl_sendMessage);
}

void Heavy_prog::cMsg_Sr30jzln_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_PznM48Jl, 0, m, &cDelay_PznM48Jl_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_A7eJFRBj, 0, m, &cDelay_A7eJFRBj_sendMessage);
}

void Heavy_prog::cPack_rcQhsGdP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_a5AmQPKu, 0, m, NULL);
}

void Heavy_prog::cCast_MxFcjBBV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iLfqxJez_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_iLfqxJez_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cDelay_onMessage(_c, &Context(_c)->cDelay_A7eJFRBj, 1, m, &cDelay_A7eJFRBj_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PznM48Jl, 1, m, &cDelay_PznM48Jl_sendMessage);
}

void Heavy_prog::cMsg_NxOHyMcF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  sLine_onMessage(_c, &Context(_c)->sLine_a5AmQPKu, 0, m, NULL);
}

void Heavy_prog::cCast_A9f8PmPA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NxOHyMcF_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_K6ZyhK07_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WVJxo91V_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_WVJxo91V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cSwitchcase_KisYa0eX_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_HxOMnV7f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dsNeX709_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SoXwo7YS_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9iGCnCQP_sendMessage);
}

void Heavy_prog::cCast_0ndpx8dr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_9ipRZZ9i_sendMessage);
}

void Heavy_prog::cCast_SoXwo7YS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Jvpiho6N, 0, m, &cVar_Jvpiho6N_sendMessage);
}

void Heavy_prog::cCast_dsNeX709_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DHJPWAOL, 0, m, &cVar_DHJPWAOL_sendMessage);
}

void Heavy_prog::cCast_9iGCnCQP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qCrSdh3V, 0, m, &cVar_qCrSdh3V_sendMessage);
}

void Heavy_prog::cMsg_jjIogc5O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_SNdBDiR9_onMessage(_c, NULL, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 1);
  msg_setElementToFrom(m, 2, n, 2);
  cSwitchcase_SNdBDiR9_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cSwitchcase_CwpCYNsH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ZQlXBqPn, 0, m, &cSlice_ZQlXBqPn_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_v1yoq5U6, 0, m, &cRandom_v1yoq5U6_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_04RN7EFO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_xD9VY3dV_sendMessage);
}

void Heavy_prog::cUnop_xD9VY3dV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_40CKhTId_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 40.0f, 0, m, &cBinop_Nx2JqE5g_sendMessage);
}

void Heavy_prog::cRandom_v1yoq5U6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_04RN7EFO_sendMessage);
}

void Heavy_prog::cSlice_ZQlXBqPn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_v1yoq5U6, 1, m, &cRandom_v1yoq5U6_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_ewCaq7Qy_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_M7rAMhW3, 0, m, &cSlice_M7rAMhW3_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_YPRHUkkH, 0, m, &cRandom_YPRHUkkH_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_slNZ0mAd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Lh3d1fBV_sendMessage);
}

void Heavy_prog::cUnop_Lh3d1fBV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8FilOoYy, 0, m, &cVar_8FilOoYy_sendMessage);
}

void Heavy_prog::cRandom_YPRHUkkH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.0f, 0, m, &cBinop_slNZ0mAd_sendMessage);
}

void Heavy_prog::cSlice_M7rAMhW3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_YPRHUkkH, 1, m, &cRandom_YPRHUkkH_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_l0oCMhFc_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Shbk4Leg_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kOWcIDz9_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7tj1Zfu5_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_Shbk4Leg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ObiDlhQ5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NAIJeotF_sendMessage);
}

void Heavy_prog::cCast_kOWcIDz9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DEJ2utTd_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tRaeAaJW_sendMessage);
}

void Heavy_prog::cCast_7tj1Zfu5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EsuFEUXQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cP5kraob_sendMessage);
}

void Heavy_prog::cVar_ooMGtvvF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PF5Mcfpt, HV_BINOP_DIVIDE, 1, m, &cBinop_PF5Mcfpt_sendMessage);
}

void Heavy_prog::cVar_Sjl3IabK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PF5Mcfpt, HV_BINOP_DIVIDE, 1, m, &cBinop_PF5Mcfpt_sendMessage);
}

void Heavy_prog::cVar_smxDCpVT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PF5Mcfpt, HV_BINOP_DIVIDE, 1, m, &cBinop_PF5Mcfpt_sendMessage);
}

void Heavy_prog::cVar_JUtWU4XH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7H9UG31T_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nWyJ44jd_sendMessage);
}

void Heavy_prog::cCast_nWyJ44jd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PF5Mcfpt, HV_BINOP_DIVIDE, 0, m, &cBinop_PF5Mcfpt_sendMessage);
}

void Heavy_prog::cCast_7H9UG31T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Jre201LV_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_PF5Mcfpt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_3Rrf6rlY, m);
}

void Heavy_prog::cCast_EsuFEUXQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_smxDCpVT, 0, m, &cVar_smxDCpVT_sendMessage);
}

void Heavy_prog::cCast_cP5kraob_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JUtWU4XH, 0, m, &cVar_JUtWU4XH_sendMessage);
}

void Heavy_prog::cCast_DEJ2utTd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Sjl3IabK, 0, m, &cVar_Sjl3IabK_sendMessage);
}

void Heavy_prog::cCast_tRaeAaJW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JUtWU4XH, 0, m, &cVar_JUtWU4XH_sendMessage);
}

void Heavy_prog::cCast_ObiDlhQ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ooMGtvvF, 0, m, &cVar_ooMGtvvF_sendMessage);
}

void Heavy_prog::cCast_NAIJeotF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JUtWU4XH, 0, m, &cVar_JUtWU4XH_sendMessage);
}

void Heavy_prog::cMsg_Jre201LV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_nJfYMCMC, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_nJfYMCMC, 0, m, NULL);
}

void Heavy_prog::cSwitchcase_UFqOczpK_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_SQfSVFH7, 0, m, &cSlice_SQfSVFH7_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_asg4tMMY, 0, m, &cRandom_asg4tMMY_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_bm75oD2q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_sLLaYteF_sendMessage);
}

void Heavy_prog::cUnop_sLLaYteF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wxuOCmOO, 0, m, &cVar_wxuOCmOO_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_mirnxlBe_sendMessage);
}

void Heavy_prog::cRandom_asg4tMMY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 160.0f, 0, m, &cBinop_bm75oD2q_sendMessage);
}

void Heavy_prog::cSlice_SQfSVFH7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_asg4tMMY, 1, m, &cRandom_asg4tMMY_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_40CKhTId_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HmbKGmB3, 0, m, &cVar_HmbKGmB3_sendMessage);
}

void Heavy_prog::cBinop_mirnxlBe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hErxSlMQ, 0, m, &cVar_hErxSlMQ_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.0f, 0, m, &cBinop_0ECfXXAT_sendMessage);
}

void Heavy_prog::cBinop_0ECfXXAT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JsuCNCri, 0, m, &cVar_JsuCNCri_sendMessage);
}

void Heavy_prog::cBinop_Nx2JqE5g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wdmaXtfD, 0, m, &cVar_wdmaXtfD_sendMessage);
}

void Heavy_prog::cReceive_MlD2gUGZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qf0XwH9p_sendMessage(_c, 0, m);
  cMsg_3uKYPcPz_sendMessage(_c, 0, m);
  cMsg_NrLSGoyx_sendMessage(_c, 0, m);
  cMsg_Dxrso7ah_sendMessage(_c, 0, m);
  cMsg_YlUigL53_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_gbQfcyAx, 0, m, &cVar_gbQfcyAx_sendMessage);
  cMsg_bDKyf99O_sendMessage(_c, 0, m);
  cMsg_jeh2kG9F_sendMessage(_c, 0, m);
  cMsg_AxbCM1YZ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_TJEqEWdP, 0, m, &cVar_TJEqEWdP_sendMessage);
  cMsg_ShkaDX72_sendMessage(_c, 0, m);
  cMsg_hN4ezQIN_sendMessage(_c, 0, m);
  cMsg_snoB7RpS_sendMessage(_c, 0, m);
  cMsg_P3JZlb9J_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Ci5yaceL, 0, m, &cVar_Ci5yaceL_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_mNrVCgI7, 0, m, &cVar_mNrVCgI7_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_K9G40gze, 0, m, &cVar_K9G40gze_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_q4qHLIKj, 0, m, &cVar_q4qHLIKj_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_y3Bnfkl1, 0, m, &cVar_y3Bnfkl1_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_r53NBIYP, 0, m, &cVar_r53NBIYP_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_rTUHUIMl, 0, m, &cVar_rTUHUIMl_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_NoVWSYbR, 0, m, &cVar_NoVWSYbR_sendMessage);
  cMsg_41HS0QRV_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_oEfDmSFs, 0, m, &cVar_oEfDmSFs_sendMessage);
  cMsg_dkQhA6Tv_sendMessage(_c, 0, m);
}

void Heavy_prog::cReceive_CqtpddWc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DHJPWAOL, 1, m, &cVar_DHJPWAOL_sendMessage);
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
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5, Bf6, Bf7, Bf8, Bf9, Bf10, Bf11, Bf12;
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
    __hv_line_f(&sLine_nJfYMCMC, VOf(Bf0));
    __hv_varread_f(&sVarf_3Rrf6rlY, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf1));
    __hv_floor_f(VIf(Bf1), VOf(Bf2));
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf4), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf5), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf2), VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf5), 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f);
    __hv_varread_f(&sVarf_MRkzqZnL, VOf(Bf4));
    __hv_varread_f(&sVarf_tFSl5x6N, VOf(Bf2));
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_phasor_f(&sPhasor_hkABiTEE, VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fms_f(VIf(Bf2), VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_EWkWwWZ6, VOf(Bf1));
    __hv_fma_f(VIf(Bf3), VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_phasor_f(&sPhasor_8iIOs0GG, VIf(Bf4), VOf(Bf4));
    __hv_neg_f(VIf(Bf4), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_min_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f);
    __hv_var_k_f(VOf(Bf1), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fms_f(VIf(Bf3), VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_Z6DVMeGp, VOf(Bf4));
    __hv_zero_f(VOf(Bf3));
    __hv_pow_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf1), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_min_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f);
    __hv_max_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_phasor_k_f(&sPhasor_PVOBCXNN, VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf3));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf6), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf7), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf2), VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf3), VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_phasor_k_f(&sPhasor_w6bugCxu, VOf(Bf6));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf6), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf3), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf6));
    __hv_mul_f(VIf(Bf3), VIf(Bf6), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf2), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf8), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf7), VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf6), VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf4), VIf(Bf3), VOf(Bf2));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_Weo8l11X, VOf(Bf4));
    __hv_varread_f(&sVarf_VjdvtlNC, VOf(Bf8));
    __hv_mul_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf2), VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_lNWAKkKx, VOf(Bf6));
    __hv_varread_f(&sVarf_q7wy3ygM, VOf(Bf2));
    __hv_fma_f(VIf(Bf8), VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_phasor_f(&sPhasor_PAJLFf79, VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_abs_f(VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf6), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf6), VOf(Bf2));
    __hv_mul_f(VIf(Bf6), VIf(Bf2), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf7), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf8), VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf2), VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf4), VIf(Bf1), VOf(Bf6));
    __hv_del1_f(&sDel1_VTn5l1EK, VIf(ZERO), VOf(Bf3));
    __hv_lt_f(VIf(ZERO), VIf(Bf3), VOf(Bf3));
    __hv_samphold_f(&sSamphold_qYYwPwwj, VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_6p0GlcSf, VOf(Bf6));
    __hv_mul_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_GD7gFKDc, VOf(Bf3));
    __hv_rpole_f(&sRPole_yF2T3zAp, VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf6), 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f);
    __hv_mul_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf1), VIf(Bf6), VOf(Bf3));
    __hv_fma_f(VIf(Bf0), VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_var_k_f(VOf(Bf2), 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f);
    __hv_phasor_k_f(&sPhasor_3KrGvG5f, VOf(Bf7));
    __hv_var_k_f(VOf(Bf8), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_abs_f(VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf7), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf8), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf8), VOf(Bf7));
    __hv_mul_f(VIf(Bf8), VIf(Bf7), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf10), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf11), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf9), VIf(Bf11), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf7), VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_phasor_k_f(&sPhasor_ai1Xzu2L, VOf(Bf10));
    __hv_var_k_f(VOf(Bf7), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_abs_f(VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf10), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf7), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf7), VOf(Bf10));
    __hv_mul_f(VIf(Bf7), VIf(Bf10), VOf(Bf11));
    __hv_mul_f(VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf9), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf12), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf11), VIf(Bf12), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf10), VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf8), VIf(Bf7), VOf(Bf9));
    __hv_var_k_f(VOf(Bf10), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_mul_f(VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_UCZnggPO, VOf(Bf8));
    __hv_varread_f(&sVarf_e9Q3n8OA, VOf(Bf12));
    __hv_mul_f(VIf(Bf8), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf10), VIf(Bf12), VOf(Bf12));
    __hv_mul_f(VIf(Bf7), VIf(Bf12), VOf(Bf12));
    __hv_fma_f(VIf(Bf9), VIf(Bf10), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_EgyP79ak, VOf(Bf10));
    __hv_varread_f(&sVarf_ZD1qa7Ff, VOf(Bf9));
    __hv_fma_f(VIf(Bf12), VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_phasor_f(&sPhasor_s3v42jCl, VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf10), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_abs_f(VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf9), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf10), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf10), VOf(Bf9));
    __hv_mul_f(VIf(Bf10), VIf(Bf9), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf7), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf11), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf12), VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf9), VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf8), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_61avkbsr, VOf(Bf10));
    __hv_varread_f(&sVarf_UF8WBoeW, VOf(Bf7));
    __hv_mul_f(VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_phasor_f(&sPhasor_G47Aclun, VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_H84vJuZl, VOf(Bf9));
    __hv_varread_f(&sVarf_xiFM6HIu, VOf(Bf11));
    __hv_fms_f(VIf(Bf7), VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_abs_f(VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_phasor_f(&sPhasor_vsYdDqND, VIf(Bf11), VOf(Bf11));
    __hv_neg_f(VIf(Bf11), VOf(Bf10));
    __hv_var_k_f(VOf(Bf9), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_min_f(VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf11), 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f);
    __hv_var_k_f(VOf(Bf10), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fms_f(VIf(Bf9), VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_a5AmQPKu, VOf(Bf11));
    __hv_zero_f(VOf(Bf9));
    __hv_pow_f(VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf10), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_min_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf9), -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f);
    __hv_max_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf10), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_mul_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_add_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf1), VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf2), 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f);
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf10), VIf(Bf2), VOf(Bf10));
    __hv_line_f(&sLine_hAAHSc6j, VOf(Bf4));
    __hv_tabhead_f(&sTabhead_GMBUDSG3, VOf(Bf1));
    __hv_var_k_f_r(VOf(Bf8), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf1), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_zVq9rX1c, VOf(Bf1));
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_tEVox5qL, VOf(Bf4));
    __hv_min_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_zero_f(VOf(Bf1));
    __hv_max_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf8), VIf(Bf1), VOf(Bf1));
    __hv_floor_f(VIf(Bf1), VOf(Bf8));
    __hv_varread_f(&sVarf_f9H4Z7tY, VOf(Bf4));
    __hv_zero_f(VOf(Bf9));
    __hv_lt_f(VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_and_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_cast_fi(VIf(Bf9), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_Ax5TchwI, VIi(Bi1), VOf(Bf9));
    __hv_tabread_if(&sTabread_3GJ7jomA, VIi(Bi0), VOf(Bf4));
    __hv_sub_f(VIf(Bf9), VIf(Bf4), VOf(Bf9));
    __hv_sub_f(VIf(Bf1), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf9), VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_Bnj82DFC, VOf(Bf8));
    __hv_fma_f(VIf(Bf4), VIf(Bf8), VIf(Bf10), VOf(Bf8));
    __hv_line_f(&sLine_YVTMNqNi, VOf(Bf4));
    __hv_tabhead_f(&sTabhead_XW47bxAE, VOf(Bf9));
    __hv_var_k_f_r(VOf(Bf1), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf9), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_cXycfIxT, VOf(Bf9));
    __hv_mul_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_Pxc22I1a, VOf(Bf4));
    __hv_min_f(VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_zero_f(VOf(Bf9));
    __hv_max_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf1), VIf(Bf9), VOf(Bf9));
    __hv_floor_f(VIf(Bf9), VOf(Bf1));
    __hv_varread_f(&sVarf_1yUpDfUL, VOf(Bf4));
    __hv_zero_f(VOf(Bf11));
    __hv_lt_f(VIf(Bf1), VIf(Bf11), VOf(Bf11));
    __hv_and_f(VIf(Bf4), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf1), VIf(Bf11), VOf(Bf11));
    __hv_cast_fi(VIf(Bf11), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_3RAqMdWy, VIi(Bi1), VOf(Bf11));
    __hv_tabread_if(&sTabread_4e2jX6dl, VIi(Bi0), VOf(Bf4));
    __hv_sub_f(VIf(Bf11), VIf(Bf4), VOf(Bf11));
    __hv_sub_f(VIf(Bf9), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf11), VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_nw3wEL0j, VOf(Bf1));
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf8), VIf(Bf1), VOf(Bf1));
    __hv_tabwrite_f(&sTabwrite_bqH2eNDv, VIf(Bf1));
    __hv_tabwrite_f(&sTabwrite_PBlvOfaq, VIf(Bf10));
    __hv_var_k_f(VOf(Bf10), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_fma_f(VIf(Bf1), VIf(Bf10), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf3), VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf5), VIf(O0), VOf(O0));
    __hv_add_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf1), 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f);
    __hv_var_k_f(VOf(Bf5), 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f);
    __hv_mul_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf6), VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf1), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_mul_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf1), VIf(O1), VOf(O1));

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
