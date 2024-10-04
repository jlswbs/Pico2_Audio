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
  numBytes += sPhasor_init(&sPhasor_2nzknvo2, sampleRate);
  numBytes += sLine_init(&sLine_eBKI5gSb);
  numBytes += sPhasor_init(&sPhasor_EyAvJncG, sampleRate);
  numBytes += sLine_init(&sLine_RcL7jbNB);
  numBytes += sPhasor_k_init(&sPhasor_fb30VM52, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_PLyU98zV, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_8xZuxxIq);
  numBytes += sPhasor_init(&sPhasor_dY9bksQT, sampleRate);
  numBytes += sPhasor_init(&sPhasor_Kp6pfADo, sampleRate);
  numBytes += sPhasor_init(&sPhasor_favMWr5T, sampleRate);
  numBytes += sLine_init(&sLine_puXWWNP2);
  numBytes += sPhasor_k_init(&sPhasor_M6e5wPsf, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_TjmuA1zl, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_e4c5MxLI);
  numBytes += sPhasor_init(&sPhasor_z1D2svmR, sampleRate);
  numBytes += sLine_init(&sLine_Tc5ROhQw);
  numBytes += sTabhead_init(&sTabhead_897iqLJ6, &hTable_6F5kI6MG);
  numBytes += sTabread_init(&sTabread_mwLz3Xyo, &hTable_6F5kI6MG, false);
  numBytes += sTabread_init(&sTabread_ucEGJi5m, &hTable_6F5kI6MG, false);
  numBytes += sLine_init(&sLine_HRPJ36te);
  numBytes += sLine_init(&sLine_Dycv4cv8);
  numBytes += sTabhead_init(&sTabhead_Rk99td38, &hTable_ON1C7Wxf);
  numBytes += sTabread_init(&sTabread_UIcQpSw0, &hTable_ON1C7Wxf, false);
  numBytes += sTabread_init(&sTabread_Pg7dfuvx, &hTable_ON1C7Wxf, false);
  numBytes += sLine_init(&sLine_dPHrdpuN);
  numBytes += sTabwrite_init(&sTabwrite_Lb8z0cI8, &hTable_6F5kI6MG);
  numBytes += sTabwrite_init(&sTabwrite_NO16AwuL, &hTable_ON1C7Wxf);
  numBytes += sLine_init(&sLine_yvFasSQA);
  numBytes += cVar_init_f(&cVar_Y1n269E8, 0.0f);
  numBytes += cVar_init_f(&cVar_7jKV1DcY, 1.0f);
  numBytes += cVar_init_f(&cVar_RzAe9niw, 0.0f);
  numBytes += cRandom_init(&cRandom_rsb6Sc05, -1758425099);
  numBytes += cSlice_init(&cSlice_Vd93ILrK, 1, 1);
  numBytes += cRandom_init(&cRandom_RxnkBmy1, -1660134995);
  numBytes += cSlice_init(&cSlice_Rds8anBq, 1, 1);
  numBytes += cPack_init(&cPack_Aia28Ah1, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_DWgU0SN0, 4, 1);
  numBytes += cSlice_init(&cSlice_mKeYlGfs, 3, 1);
  numBytes += cSlice_init(&cSlice_orf0b9WY, 2, 1);
  numBytes += cSlice_init(&cSlice_lAgzzqqE, 1, 1);
  numBytes += cSlice_init(&cSlice_DXV5o3Lw, 0, 1);
  numBytes += sVarf_init(&sVarf_bdlqFuuL, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_J0fRPZsk, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_XnBj1JPX, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_cKLWdxD7, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_PF1y9EAN, 944634551);
  numBytes += cSlice_init(&cSlice_4Vs4DX50, 1, 1);
  numBytes += cPack_init(&cPack_hws0HNaI, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_FI9VPFCw, 2, 0.0f, 0.0f);
  numBytes += cVar_init_s(&cVar_exuJqNjf, "del-1023-inputdelay");
  numBytes += sVarf_init(&sVarf_Xs647X4K, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_rr0SdXhn, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_LtEyJLQp, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_VAio10WH, "del-1023-outputdelay");
  numBytes += sVarf_init(&sVarf_KY9Vg7zj, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_EM5phRoD, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_OsHJd4xu, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_mYhdyjgj, 0.0f);
  numBytes += cDelay_init(this, &cDelay_qD6RoSbW, 0.0f);
  numBytes += hTable_init(&hTable_6F5kI6MG, 256);
  numBytes += cDelay_init(this, &cDelay_ArreQD0W, 0.0f);
  numBytes += cDelay_init(this, &cDelay_6q0Llt3F, 0.0f);
  numBytes += hTable_init(&hTable_ON1C7Wxf, 256);
  numBytes += cVar_init_f(&cVar_4wAQtwl4, 0.0f);
  numBytes += cDelay_init(this, &cDelay_m4q0OXkw, 0.0f);
  numBytes += cVar_init_f(&cVar_Nk22g96w, 240.0f);
  numBytes += cBinop_init(&cBinop_x078sjED, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_MyvNL4Nc, 0.0f);
  numBytes += cVar_init_f(&cVar_tK4j9RFP, 480.0f);
  numBytes += cBinop_init(&cBinop_FFyPN5Cq, 0.0f); // __mul
  numBytes += cRandom_init(&cRandom_o0u06kJD, -1151359138);
  numBytes += cSlice_init(&cSlice_gm9tCWMR, 1, 1);
  numBytes += cPack_init(&cPack_X3FGyhs7, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_QEwXDSVp, 4, 1);
  numBytes += cSlice_init(&cSlice_Kj2FISwG, 3, 1);
  numBytes += cSlice_init(&cSlice_M6b7OaW3, 2, 1);
  numBytes += cSlice_init(&cSlice_mURdKEkU, 1, 1);
  numBytes += cSlice_init(&cSlice_pTWztxdf, 0, 1);
  numBytes += sVarf_init(&sVarf_fmoXBxZo, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_iMxBluSy, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_31kGsukl, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_qJCyIbYI, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_zwopfjU4, -919714096);
  numBytes += cSlice_init(&cSlice_FebRG7uN, 1, 1);
  numBytes += cVar_init_f(&cVar_wrpV92oY, 0.0f);
  numBytes += cVar_init_f(&cVar_cXWVgS37, 0.0f);
  numBytes += cVar_init_f(&cVar_vQR4bZLt, 25.0f);
  numBytes += cVar_init_f(&cVar_mT2nO8Wg, 32.0f);
  numBytes += cVar_init_f(&cVar_wECCakCv, 18.0f);
  numBytes += cVar_init_f(&cVar_gHacxFY5, 110.0f);
  numBytes += cBinop_init(&cBinop_VHPB3uOZ, 29.0f); // __div
  numBytes += sVarf_init(&sVarf_2SoprVX7, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_Waedi30r, 1.0f); // __pow
  numBytes += sVarf_init(&sVarf_u8NiChKT, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_uxEmp4hE, 4.0f);
  numBytes += cVar_init_f(&cVar_0vc25TxV, 60.0f);
  numBytes += cVar_init_f(&cVar_cOJWuMGJ, 150.0f);
  numBytes += cPack_init(&cPack_2Fvn1bJL, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_K4tGZ13H, 500.0f);
  numBytes += cVar_init_f(&cVar_uf0h2qCm, 6.0f);
  numBytes += cSlice_init(&cSlice_ulliU4ZT, 2, 1);
  numBytes += cSlice_init(&cSlice_kn2SeFMS, 1, 1);
  numBytes += cSlice_init(&cSlice_uA2pEUS1, 0, 1);
  numBytes += cSlice_init(&cSlice_fxhe9sgf, 1, -1);
  numBytes += cDelay_init(this, &cDelay_zU9avkjl, 0.0f);
  numBytes += cDelay_init(this, &cDelay_CouypCls, 0.0f);
  numBytes += cIf_init(&cIf_g28ckT0T, false);
  numBytes += cSlice_init(&cSlice_Ohvljzq8, 1, -1);
  numBytes += cPack_init(&cPack_ugW9QQRP, 2, 0.0f, 0.0f);
  numBytes += sVarf_init(&sVarf_tDKBcNvk, 1.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_Jfvr80ch, 0.0f);
  numBytes += cVar_init_f(&cVar_KnAFTeWx, 0.0f);
  numBytes += cBinop_init(&cBinop_y6hvOO66, 1.0f); // __pow
  numBytes += sVarf_init(&sVarf_ny9v4c4x, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_YHYx9sZ8, 220.0f);
  numBytes += cVar_init_f(&cVar_VKGYcUH2, 6.0f);
  numBytes += cPack_init(&cPack_AiHJgBpy, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_GeJZF1sp, 30.0f);
  numBytes += cVar_init_f(&cVar_cojxLUEE, 50.0f);
  numBytes += cVar_init_f(&cVar_ag7tEh6h, 500.0f);
  numBytes += cVar_init_f(&cVar_l0Di9L2U, 110.0f);
  numBytes += cSlice_init(&cSlice_mkTbKFYA, 2, 1);
  numBytes += cSlice_init(&cSlice_mMbU0YiB, 1, 1);
  numBytes += cSlice_init(&cSlice_QL7GvIQn, 0, 1);
  numBytes += cSlice_init(&cSlice_UC4NigbB, 1, -1);
  numBytes += cDelay_init(this, &cDelay_uyUqSx9K, 0.0f);
  numBytes += cDelay_init(this, &cDelay_BYMlgNA9, 0.0f);
  numBytes += cIf_init(&cIf_uBlVa8OC, false);
  numBytes += cSlice_init(&cSlice_jr1uXGVr, 1, -1);
  numBytes += cPack_init(&cPack_cXDKFJgB, 2, 0.0f, 0.0f);
  numBytes += sVarf_init(&sVarf_w0qEdyrk, 2.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_jsKAGKyf, 1.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_8uvF5VEO, 1.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_prog::~Heavy_prog() {
  cPack_free(&cPack_Aia28Ah1);
  cPack_free(&cPack_hws0HNaI);
  cPack_free(&cPack_FI9VPFCw);
  hTable_free(&hTable_6F5kI6MG);
  hTable_free(&hTable_ON1C7Wxf);
  cPack_free(&cPack_X3FGyhs7);
  cPack_free(&cPack_2Fvn1bJL);
  cPack_free(&cPack_ugW9QQRP);
  cPack_free(&cPack_AiHJgBpy);
  cPack_free(&cPack_cXDKFJgB);
}

HvTable *Heavy_prog::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x7F849157: return &hTable_6F5kI6MG; // del-1023-inputdelay
    case 0x7CCDEFBD: return &hTable_ON1C7Wxf; // del-1023-outputdelay
    default: return nullptr;
  }
}

void Heavy_prog::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_6XGO9Nf0_sendMessage);
      break;
    }
    case 0xF7AB77BA: { // dur
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_swBg2dY9_sendMessage);
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


void Heavy_prog::cVar_Y1n269E8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_YhMKh4UR_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cVar_7jKV1DcY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_n4OeWMZO_sendMessage);
  cSwitchcase_54z8w8f3_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_Co50Qpyj_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_n4OeWMZO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7jKV1DcY, 1, m, &cVar_7jKV1DcY_sendMessage);
}

void Heavy_prog::cVar_RzAe9niw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DQG300gv_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vhm2UQoS_sendMessage);
}

void Heavy_prog::cSwitchcase_GvYcLbDR_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Vd93ILrK, 0, m, &cSlice_Vd93ILrK_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_rsb6Sc05, 0, m, &cRandom_rsb6Sc05_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_j9vrMWXL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_ZwUZRMuh_sendMessage);
}

void Heavy_prog::cUnop_ZwUZRMuh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Y1n269E8, 0, m, &cVar_Y1n269E8_sendMessage);
}

void Heavy_prog::cRandom_rsb6Sc05_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 3.0f, 0, m, &cBinop_j9vrMWXL_sendMessage);
}

void Heavy_prog::cSlice_Vd93ILrK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_rsb6Sc05, 1, m, &cRandom_rsb6Sc05_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_Hg7Sc7Wt_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Rds8anBq, 0, m, &cSlice_Rds8anBq_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_RxnkBmy1, 0, m, &cRandom_RxnkBmy1_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_yn1A5HIv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_13b8X1TM_sendMessage);
}

void Heavy_prog::cUnop_13b8X1TM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wrpV92oY, 0, m, &cVar_wrpV92oY_sendMessage);
}

void Heavy_prog::cRandom_RxnkBmy1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_yn1A5HIv_sendMessage);
}

void Heavy_prog::cSlice_Rds8anBq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_RxnkBmy1, 1, m, &cRandom_RxnkBmy1_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cPack_Aia28Ah1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DnzrqGb6_sendMessage(_c, 0, m);
}

void Heavy_prog::cSlice_DWgU0SN0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_bdlqFuuL, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_mKeYlGfs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_cKLWdxD7, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_orf0b9WY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_XnBj1JPX, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_lAgzzqqE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_TjmuA1zl, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_DXV5o3Lw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_M6e5wPsf, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_q4jPZyJg_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KIN4iSl2_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_KIN4iSl2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7u2sprAa_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GkD3Djq8_sendMessage);
}

void Heavy_prog::cCast_GkD3Djq8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Kgzo63Yn_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_7u2sprAa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_bw1DUQFR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_J0fRPZsk, HV_BINOP_MULTIPLY, 0, m, &cBinop_J0fRPZsk_sendMessage);
}

void Heavy_prog::cCast_wrReOrEr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Aia28Ah1, 0, m, &cPack_Aia28Ah1_sendMessage);
}

void Heavy_prog::cMsg_Kgzo63Yn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bw1DUQFR_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wrReOrEr_sendMessage);
}

void Heavy_prog::cBinop_J0fRPZsk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Aia28Ah1, 1, m, &cPack_Aia28Ah1_sendMessage);
}

void Heavy_prog::cBinop_Qudds8mF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_J0fRPZsk, HV_BINOP_MULTIPLY, 1, m, &cBinop_J0fRPZsk_sendMessage);
}

void Heavy_prog::cMsg_e6AtFHpj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.1f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 600.0f, 0, m, &cBinop_Qudds8mF_sendMessage);
}

void Heavy_prog::cMsg_DnzrqGb6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_e4c5MxLI, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 1);
  sLine_onMessage(_c, &Context(_c)->sLine_e4c5MxLI, 0, m, NULL);
}

void Heavy_prog::cMsg_LBCQQpoI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(5);
  msg_init(m, 5, msg_getTimestamp(n));
  msg_setFloat(m, 0, 748.031f);
  msg_setFloat(m, 1, 1023.62f);
  msg_setFloat(m, 2, 0.173228f);
  msg_setFloat(m, 3, 1968.5f);
  msg_setFloat(m, 4, 9259.84f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_DWgU0SN0, 0, m, &cSlice_DWgU0SN0_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_mKeYlGfs, 0, m, &cSlice_mKeYlGfs_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_orf0b9WY, 0, m, &cSlice_orf0b9WY_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_lAgzzqqE, 0, m, &cSlice_lAgzzqqE_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_DXV5o3Lw, 0, m, &cSlice_DXV5o3Lw_sendMessage);
}

void Heavy_prog::cSwitchcase_uegVsTVn_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_4Vs4DX50, 0, m, &cSlice_4Vs4DX50_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_PF1y9EAN, 0, m, &cRandom_PF1y9EAN_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_2fqSuDTk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Y9Je5yU7_sendMessage);
}

void Heavy_prog::cUnop_Y9Je5yU7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RzAe9niw, 0, m, &cVar_RzAe9niw_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_aagBk7y9_sendMessage);
}

void Heavy_prog::cRandom_PF1y9EAN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 60.0f, 0, m, &cBinop_2fqSuDTk_sendMessage);
}

void Heavy_prog::cSlice_4Vs4DX50_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_PF1y9EAN, 1, m, &cRandom_PF1y9EAN_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cPack_hws0HNaI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_Tc5ROhQw, 0, m, NULL);
}

void Heavy_prog::cPack_FI9VPFCw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_Dycv4cv8, 0, m, NULL);
}

void Heavy_prog::cMsg_1UxaNi2U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_vYMSVemh_sendMessage);
}

void Heavy_prog::cSystem_vYMSVemh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_QOF0LBeN_sendMessage);
}

void Heavy_prog::cVar_exuJqNjf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pkMmsCoH_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_5fJ9GSFc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_HeQFsWEI_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Xs647X4K, m);
}

void Heavy_prog::cBinop_QOF0LBeN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_rr0SdXhn, m);
}

void Heavy_prog::cMsg_pkMmsCoH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5fJ9GSFc_sendMessage);
}

void Heavy_prog::cBinop_HeQFsWEI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_LtEyJLQp, m);
}

void Heavy_prog::cMsg_eWC2jmIW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_EyV9N51M_sendMessage);
}

void Heavy_prog::cSystem_EyV9N51M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_4EIeDRRu_sendMessage);
}

void Heavy_prog::cVar_VAio10WH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JoPObvLj_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_ZlhsQHL1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ct00Jg58_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_KY9Vg7zj, m);
}

void Heavy_prog::cBinop_4EIeDRRu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_EM5phRoD, m);
}

void Heavy_prog::cMsg_JoPObvLj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ZlhsQHL1_sendMessage);
}

void Heavy_prog::cBinop_ct00Jg58_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_OsHJd4xu, m);
}

void Heavy_prog::cMsg_exDoqCbG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_T1ZlJ3At_sendMessage);
}

void Heavy_prog::cSystem_T1ZlJ3At_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_BflTAlie_sendMessage);
}

void Heavy_prog::cDelay_mYhdyjgj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_mYhdyjgj, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_qD6RoSbW, 0, m, &cDelay_qD6RoSbW_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mYhdyjgj, 0, m, &cDelay_mYhdyjgj_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Lb8z0cI8, 1, m, NULL);
}

void Heavy_prog::cDelay_qD6RoSbW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_qD6RoSbW, m);
  cMsg_SCwvXm5M_sendMessage(_c, 0, m);
}

void Heavy_prog::cSwitchcase_bPowcWSp_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_BQo9NhFb_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cBinop_JxmEVTuW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7HAz54hx_sendMessage(_c, 0, m);
}

void Heavy_prog::hTable_6F5kI6MG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DMVCyhNF_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mYhdyjgj, 2, m, &cDelay_mYhdyjgj_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_78BbIpCQ_sendMessage);
}

void Heavy_prog::cMsg_7HAz54hx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_6F5kI6MG, 0, m, &hTable_6F5kI6MG_sendMessage);
}

void Heavy_prog::cBinop_BflTAlie_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 50.0f, 0, m, &cBinop_JxmEVTuW_sendMessage);
}

void Heavy_prog::cMsg_SCwvXm5M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_6F5kI6MG, 0, m, &hTable_6F5kI6MG_sendMessage);
}

void Heavy_prog::cCast_78BbIpCQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_mYhdyjgj, 0, m, &cDelay_mYhdyjgj_sendMessage);
}

void Heavy_prog::cMsg_DMVCyhNF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_qD6RoSbW, 2, m, &cDelay_qD6RoSbW_sendMessage);
}

void Heavy_prog::cMsg_BQo9NhFb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Lb8z0cI8, 1, m, NULL);
}

void Heavy_prog::cMsg_ia6YC8Jt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_yIindWiC_sendMessage);
}

void Heavy_prog::cSystem_yIindWiC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_rNXeVdmT_sendMessage);
}

void Heavy_prog::cDelay_ArreQD0W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ArreQD0W, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6q0Llt3F, 0, m, &cDelay_6q0Llt3F_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ArreQD0W, 0, m, &cDelay_ArreQD0W_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_NO16AwuL, 1, m, NULL);
}

void Heavy_prog::cDelay_6q0Llt3F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_6q0Llt3F, m);
  cMsg_0VXmgNv1_sendMessage(_c, 0, m);
}

void Heavy_prog::cSwitchcase_XjQVbnko_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_TSCYMnZp_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cBinop_183SSlVe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BB8C7X4W_sendMessage(_c, 0, m);
}

void Heavy_prog::hTable_ON1C7Wxf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WKjGK62J_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ArreQD0W, 2, m, &cDelay_ArreQD0W_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LAZreMkj_sendMessage);
}

void Heavy_prog::cMsg_BB8C7X4W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_ON1C7Wxf, 0, m, &hTable_ON1C7Wxf_sendMessage);
}

void Heavy_prog::cBinop_rNXeVdmT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 50.0f, 0, m, &cBinop_183SSlVe_sendMessage);
}

void Heavy_prog::cMsg_0VXmgNv1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_ON1C7Wxf, 0, m, &hTable_ON1C7Wxf_sendMessage);
}

void Heavy_prog::cCast_LAZreMkj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ArreQD0W, 0, m, &cDelay_ArreQD0W_sendMessage);
}

void Heavy_prog::cMsg_WKjGK62J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_6q0Llt3F, 2, m, &cDelay_6q0Llt3F_sendMessage);
}

void Heavy_prog::cMsg_TSCYMnZp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_NO16AwuL, 1, m, NULL);
}

void Heavy_prog::cBinop_49X0iU7n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_lH9QgYy0_sendMessage);
}

void Heavy_prog::cBinop_lH9QgYy0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DEtYihhg_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_1juND2oo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Gh7ckbsH_sendMessage);
}

void Heavy_prog::cBinop_Gh7ckbsH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TiMpz1Ub_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_RLET3RFB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_xrXQz5yD_sendMessage);
}

void Heavy_prog::cBinop_xrXQz5yD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_GGPjPvVW_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_AIDUneLW_sendMessage);
}

void Heavy_prog::cMsg_TiMpz1Ub_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_dPHrdpuN, 0, m, NULL);
}

void Heavy_prog::cMsg_DEtYihhg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_HRPJ36te, 0, m, NULL);
}

void Heavy_prog::cBinop_rxtJXBN6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_FI9VPFCw, 0, m, &cPack_FI9VPFCw_sendMessage);
}

void Heavy_prog::cBinop_qNOLMzk5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_hws0HNaI, 0, m, &cPack_hws0HNaI_sendMessage);
}

void Heavy_prog::cCast_GGPjPvVW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_FI9VPFCw, 1, m, &cPack_FI9VPFCw_sendMessage);
}

void Heavy_prog::cCast_AIDUneLW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_hws0HNaI, 1, m, &cPack_hws0HNaI_sendMessage);
}

void Heavy_prog::cMsg_ABrCU5CY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 50.0f, 0, m, &cBinop_qNOLMzk5_sendMessage);
}

void Heavy_prog::cMsg_Db2Guhet_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 25.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 50.0f, 0, m, &cBinop_rxtJXBN6_sendMessage);
}

void Heavy_prog::cMsg_xbUGXQhL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.95f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 0.999f, 0, m, &cBinop_1juND2oo_sendMessage);
}

void Heavy_prog::cVar_4wAQtwl4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AAmD5bTL_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_uhr8kppM_sendMessage);
}

void Heavy_prog::cSwitchcase_54z8w8f3_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_4osxvHNA_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_4osxvHNA_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Fk5TDtqd_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_m4q0OXkw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_m4q0OXkw, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_m4q0OXkw, 0, m, &cDelay_m4q0OXkw_sendMessage);
  cSwitchcase_Hg7Sc7Wt_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_uegVsTVn_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_uAKB7XzC_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_Fk5TDtqd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4osxvHNA_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_m4q0OXkw, 0, m, &cDelay_m4q0OXkw_sendMessage);
  cSwitchcase_Hg7Sc7Wt_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_uegVsTVn_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_uAKB7XzC_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_m3Tepfzy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_iBLJilpk_sendMessage);
}

void Heavy_prog::cSystem_iBLJilpk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_LGhSOOiK_sendMessage);
}

void Heavy_prog::cVar_Nk22g96w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_x078sjED, HV_BINOP_MULTIPLY, 0, m, &cBinop_x078sjED_sendMessage);
}

void Heavy_prog::cMsg_4osxvHNA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_m4q0OXkw, 0, m, &cDelay_m4q0OXkw_sendMessage);
}

void Heavy_prog::cBinop_vGKtmPJX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_m4q0OXkw, 2, m, &cDelay_m4q0OXkw_sendMessage);
}

void Heavy_prog::cBinop_LGhSOOiK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_x078sjED, HV_BINOP_MULTIPLY, 1, m, &cBinop_x078sjED_sendMessage);
}

void Heavy_prog::cBinop_x078sjED_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_vGKtmPJX_sendMessage);
}

void Heavy_prog::cSwitchcase_Co50Qpyj_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_YRmoYkID_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_YRmoYkID_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UAmX9KbE_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_MyvNL4Nc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_MyvNL4Nc, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_MyvNL4Nc, 0, m, &cDelay_MyvNL4Nc_sendMessage);
  cSwitchcase_GvYcLbDR_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_vo86KxmI_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_UAmX9KbE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YRmoYkID_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_MyvNL4Nc, 0, m, &cDelay_MyvNL4Nc_sendMessage);
  cSwitchcase_GvYcLbDR_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_vo86KxmI_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_Twl3VW0P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_GlLKrIeU_sendMessage);
}

void Heavy_prog::cSystem_GlLKrIeU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_RkfL6NrC_sendMessage);
}

void Heavy_prog::cVar_tK4j9RFP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FFyPN5Cq, HV_BINOP_MULTIPLY, 0, m, &cBinop_FFyPN5Cq_sendMessage);
}

void Heavy_prog::cMsg_YRmoYkID_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_MyvNL4Nc, 0, m, &cDelay_MyvNL4Nc_sendMessage);
}

void Heavy_prog::cBinop_w0bB3D6F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_MyvNL4Nc, 2, m, &cDelay_MyvNL4Nc_sendMessage);
}

void Heavy_prog::cBinop_RkfL6NrC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FFyPN5Cq, HV_BINOP_MULTIPLY, 1, m, &cBinop_FFyPN5Cq_sendMessage);
}

void Heavy_prog::cBinop_FFyPN5Cq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_w0bB3D6F_sendMessage);
}

void Heavy_prog::cSwitchcase_vo86KxmI_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_gm9tCWMR, 0, m, &cSlice_gm9tCWMR_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_o0u06kJD, 0, m, &cRandom_o0u06kJD_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_ZY1y8qM2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_8gkbSuoN_sendMessage);
}

void Heavy_prog::cUnop_8gkbSuoN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 60.0f, 0, m, &cBinop_9VCU9m0q_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_Ld0p5gTT_sendMessage);
}

void Heavy_prog::cRandom_o0u06kJD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_ZY1y8qM2_sendMessage);
}

void Heavy_prog::cSlice_gm9tCWMR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_o0u06kJD, 1, m, &cRandom_o0u06kJD_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cPack_X3FGyhs7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EtVjEf9Q_sendMessage(_c, 0, m);
}

void Heavy_prog::cSlice_QEwXDSVp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_fmoXBxZo, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_Kj2FISwG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_qJCyIbYI, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_M6b7OaW3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_31kGsukl, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_mURdKEkU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_PLyU98zV, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_pTWztxdf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_fb30VM52, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_AWEYY5t3_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ep7CdGvs_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_ep7CdGvs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0Bvp4Nle_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wgRiuBxC_sendMessage);
}

void Heavy_prog::cCast_wgRiuBxC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Di25bNcZ_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_0Bvp4Nle_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_Yrr6PPQW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_X3FGyhs7, 0, m, &cPack_X3FGyhs7_sendMessage);
}

void Heavy_prog::cCast_5YVYa2gX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iMxBluSy, HV_BINOP_MULTIPLY, 0, m, &cBinop_iMxBluSy_sendMessage);
}

void Heavy_prog::cMsg_Di25bNcZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5YVYa2gX_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Yrr6PPQW_sendMessage);
}

void Heavy_prog::cBinop_iMxBluSy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_X3FGyhs7, 1, m, &cPack_X3FGyhs7_sendMessage);
}

void Heavy_prog::cBinop_vyoYI2NB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iMxBluSy, HV_BINOP_MULTIPLY, 1, m, &cBinop_iMxBluSy_sendMessage);
}

void Heavy_prog::cMsg_7Q1nLlIl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.1f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 600.0f, 0, m, &cBinop_vyoYI2NB_sendMessage);
}

void Heavy_prog::cMsg_EtVjEf9Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_8xZuxxIq, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 1);
  sLine_onMessage(_c, &Context(_c)->sLine_8xZuxxIq, 0, m, NULL);
}

void Heavy_prog::cMsg_GoNouLQE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(5);
  msg_init(m, 5, msg_getTimestamp(n));
  msg_setFloat(m, 0, 748.031f);
  msg_setFloat(m, 1, 1023.62f);
  msg_setFloat(m, 2, 0.173228f);
  msg_setFloat(m, 3, 1968.5f);
  msg_setFloat(m, 4, 9259.84f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_QEwXDSVp, 0, m, &cSlice_QEwXDSVp_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Kj2FISwG, 0, m, &cSlice_Kj2FISwG_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_M6b7OaW3, 0, m, &cSlice_M6b7OaW3_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_mURdKEkU, 0, m, &cSlice_mURdKEkU_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_pTWztxdf, 0, m, &cSlice_pTWztxdf_sendMessage);
}

void Heavy_prog::cSwitchcase_uAKB7XzC_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_FebRG7uN, 0, m, &cSlice_FebRG7uN_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_zwopfjU4, 0, m, &cRandom_zwopfjU4_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_YcfqfjLu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_MGHXlcOk_sendMessage);
}

void Heavy_prog::cUnop_MGHXlcOk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cXWVgS37, 0, m, &cVar_cXWVgS37_sendMessage);
}

void Heavy_prog::cRandom_zwopfjU4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_YcfqfjLu_sendMessage);
}

void Heavy_prog::cSlice_FebRG7uN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_zwopfjU4, 1, m, &cRandom_zwopfjU4_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cVar_wrpV92oY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_q4jPZyJg_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cVar_cXWVgS37_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_AWEYY5t3_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cSwitchcase_YhMKh4UR_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WVrquOKn_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RhDH9CF8_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_W46Jjo54_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_WVrquOKn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QWJLLiyu_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9Iyyl35H_sendMessage);
}

void Heavy_prog::cCast_RhDH9CF8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DszfnXEe_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tePGELr5_sendMessage);
}

void Heavy_prog::cCast_W46Jjo54_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ioS5qTT3_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DKqIt3Es_sendMessage);
}

void Heavy_prog::cVar_vQR4bZLt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VHPB3uOZ, HV_BINOP_DIVIDE, 1, m, &cBinop_VHPB3uOZ_sendMessage);
}

void Heavy_prog::cVar_mT2nO8Wg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VHPB3uOZ, HV_BINOP_DIVIDE, 1, m, &cBinop_VHPB3uOZ_sendMessage);
}

void Heavy_prog::cVar_wECCakCv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VHPB3uOZ, HV_BINOP_DIVIDE, 1, m, &cBinop_VHPB3uOZ_sendMessage);
}

void Heavy_prog::cVar_gHacxFY5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_eJhD5JCZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cPL9IK8E_sendMessage);
}

void Heavy_prog::cCast_eJhD5JCZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_A2JVdw1p_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_cPL9IK8E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VHPB3uOZ, HV_BINOP_DIVIDE, 0, m, &cBinop_VHPB3uOZ_sendMessage);
}

void Heavy_prog::cBinop_VHPB3uOZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_2SoprVX7, m);
}

void Heavy_prog::cCast_DKqIt3Es_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gHacxFY5, 0, m, &cVar_gHacxFY5_sendMessage);
}

void Heavy_prog::cCast_ioS5qTT3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wECCakCv, 0, m, &cVar_wECCakCv_sendMessage);
}

void Heavy_prog::cCast_DszfnXEe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mT2nO8Wg, 0, m, &cVar_mT2nO8Wg_sendMessage);
}

void Heavy_prog::cCast_tePGELr5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gHacxFY5, 0, m, &cVar_gHacxFY5_sendMessage);
}

void Heavy_prog::cCast_QWJLLiyu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vQR4bZLt, 0, m, &cVar_vQR4bZLt_sendMessage);
}

void Heavy_prog::cCast_9Iyyl35H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gHacxFY5, 0, m, &cVar_gHacxFY5_sendMessage);
}

void Heavy_prog::cMsg_A2JVdw1p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_yvFasSQA, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_yvFasSQA, 0, m, NULL);
}

void Heavy_prog::cBinop_G8D9T6Ad_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_u8NiChKT, m);
}

void Heavy_prog::cBinop_6WycUXP9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_sLkO61Vb_sendMessage);
}

void Heavy_prog::cBinop_sLkO61Vb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Waedi30r, HV_BINOP_POW, 1, m, &cBinop_Waedi30r_sendMessage);
  cMsg_bA2mDOWp_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_Waedi30r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_G8D9T6Ad_sendMessage);
}

void Heavy_prog::cMsg_bA2mDOWp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Waedi30r, HV_BINOP_POW, 0, m, &cBinop_Waedi30r_sendMessage);
}

void Heavy_prog::cBinop_1VuTebzA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -10.0f, 0, m, &cBinop_PGwMDcs5_sendMessage);
}

void Heavy_prog::cBinop_PGwMDcs5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_tDKBcNvk, m);
}

void Heavy_prog::cBinop_5DkVdlhw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -10.0f, 0, m, &cBinop_BgqLThw9_sendMessage);
}

void Heavy_prog::cBinop_BgqLThw9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iPW4RJSS_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_uxEmp4hE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 10.0f, 0, m, &cBinop_1VuTebzA_sendMessage);
}

void Heavy_prog::cVar_0vc25TxV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 10.0f, 0, m, &cBinop_5DkVdlhw_sendMessage);
}

void Heavy_prog::cVar_cOJWuMGJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_2Fvn1bJL, 0, m, &cPack_2Fvn1bJL_sendMessage);
}

void Heavy_prog::cPack_2Fvn1bJL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Voz1pUci_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_K4tGZ13H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_2Fvn1bJL, 2, m, &cPack_2Fvn1bJL_sendMessage);
}

void Heavy_prog::cVar_uf0h2qCm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_2Fvn1bJL, 1, m, &cPack_2Fvn1bJL_sendMessage);
}

void Heavy_prog::cSlice_ulliU4ZT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cDelay_onMessage(_c, &Context(_c)->cDelay_zU9avkjl, 1, m, &cDelay_zU9avkjl_sendMessage);
      cDelay_onMessage(_c, &Context(_c)->cDelay_CouypCls, 1, m, &cDelay_CouypCls_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_kn2SeFMS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_W8UG5TGD_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UArr5yty_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_uA2pEUS1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_deXN5hiI_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_5ZkFD5nM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_fxhe9sgf, 0, m, &cSlice_fxhe9sgf_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CDtvJVMP_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_ulliU4ZT, 0, m, &cSlice_ulliU4ZT_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_kn2SeFMS, 0, m, &cSlice_kn2SeFMS_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_uA2pEUS1, 0, m, &cSlice_uA2pEUS1_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cSlice_fxhe9sgf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cka7OGrC_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UFr8jYil_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cka7OGrC_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UFr8jYil_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cDelay_zU9avkjl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_zU9avkjl, m);
  cPack_onMessage(_c, &Context(_c)->cPack_ugW9QQRP, 0, m, &cPack_ugW9QQRP_sendMessage);
  cMsg_GULlJezm_sendMessage(_c, 0, m);
}

void Heavy_prog::cDelay_CouypCls_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_CouypCls, m);
  cPack_onMessage(_c, &Context(_c)->cPack_ugW9QQRP, 1, m, &cPack_ugW9QQRP_sendMessage);
}

void Heavy_prog::cIf_g28ckT0T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cDelay_onMessage(_c, &Context(_c)->cDelay_CouypCls, 0, m, &cDelay_CouypCls_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_deXN5hiI_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Ohvljzq8, 0, m, &cSlice_Ohvljzq8_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_M9t4ohNc_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_oMTJ8C9S_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cSlice_Ohvljzq8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_rV8zmuKf_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_rV8zmuKf_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cMsg_GULlJezm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cIf_onMessage(_c, &Context(_c)->cIf_g28ckT0T, 1, m, &cIf_g28ckT0T_sendMessage);
}

void Heavy_prog::cMsg_lbU2mAHa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cIf_onMessage(_c, &Context(_c)->cIf_g28ckT0T, 1, m, &cIf_g28ckT0T_sendMessage);
}

void Heavy_prog::cCast_M9t4ohNc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_g28ckT0T, 0, m, &cIf_g28ckT0T_sendMessage);
}

void Heavy_prog::cCast_oMTJ8C9S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_zU9avkjl, 0, m, &cDelay_zU9avkjl_sendMessage);
}

void Heavy_prog::cCast_W8UG5TGD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_CouypCls, 0, m, &cDelay_CouypCls_sendMessage);
}

void Heavy_prog::cCast_UArr5yty_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lbU2mAHa_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_rV8zmuKf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_CouypCls, 0, m, &cDelay_CouypCls_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zU9avkjl, 0, m, &cDelay_zU9avkjl_sendMessage);
}

void Heavy_prog::cPack_ugW9QQRP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_RcL7jbNB, 0, m, NULL);
}

void Heavy_prog::cCast_CDtvJVMP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0Zl62TGD_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_0Zl62TGD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zU9avkjl, 1, m, &cDelay_zU9avkjl_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CouypCls, 1, m, &cDelay_CouypCls_sendMessage);
}

void Heavy_prog::cMsg_9N6QLjMN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  sLine_onMessage(_c, &Context(_c)->sLine_RcL7jbNB, 0, m, NULL);
}

void Heavy_prog::cCast_cka7OGrC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_seiBuLp4_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_UFr8jYil_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9N6QLjMN_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_seiBuLp4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cSwitchcase_deXN5hiI_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_iPW4RJSS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 50.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_eBKI5gSb, 0, m, NULL);
}

void Heavy_prog::cCast_DQG300gv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kTnp4MmB_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BwvNs83z_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_P3a6xalk_sendMessage);
}

void Heavy_prog::cCast_vhm2UQoS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_6WycUXP9_sendMessage);
}

void Heavy_prog::cCast_kTnp4MmB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_K4tGZ13H, 0, m, &cVar_K4tGZ13H_sendMessage);
}

void Heavy_prog::cCast_BwvNs83z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uf0h2qCm, 0, m, &cVar_uf0h2qCm_sendMessage);
}

void Heavy_prog::cCast_P3a6xalk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cOJWuMGJ, 0, m, &cVar_cOJWuMGJ_sendMessage);
}

void Heavy_prog::cMsg_Voz1pUci_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_5ZkFD5nM_onMessage(_c, NULL, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 1);
  msg_setElementToFrom(m, 2, n, 2);
  cSwitchcase_5ZkFD5nM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cVar_Jfvr80ch_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1000.0f, 0, m, &cBinop_RLET3RFB_sendMessage);
}

void Heavy_prog::cVar_KnAFTeWx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 0.999f, 0, m, &cBinop_49X0iU7n_sendMessage);
}

void Heavy_prog::cBinop_iWKboJeo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ny9v4c4x, m);
}

void Heavy_prog::cBinop_a9tSVIsa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_ZXqaOm3l_sendMessage);
}

void Heavy_prog::cBinop_ZXqaOm3l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_y6hvOO66, HV_BINOP_POW, 1, m, &cBinop_y6hvOO66_sendMessage);
  cMsg_mxc36ebf_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_y6hvOO66_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_iWKboJeo_sendMessage);
}

void Heavy_prog::cMsg_mxc36ebf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_y6hvOO66, HV_BINOP_POW, 0, m, &cBinop_y6hvOO66_sendMessage);
}

void Heavy_prog::cBinop_FJRJ7nnZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -10.0f, 0, m, &cBinop_Zqjsft7I_sendMessage);
}

void Heavy_prog::cBinop_Zqjsft7I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_8uvF5VEO, m);
}

void Heavy_prog::cBinop_qRLoc2CK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -10.0f, 0, m, &cBinop_Vze8jFrw_sendMessage);
}

void Heavy_prog::cBinop_Vze8jFrw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_w0qEdyrk, m);
}

void Heavy_prog::cVar_YHYx9sZ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 10.0f, 0, m, &cBinop_FJRJ7nnZ_sendMessage);
}

void Heavy_prog::cVar_VKGYcUH2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 10.0f, 0, m, &cBinop_qRLoc2CK_sendMessage);
}

void Heavy_prog::cPack_AiHJgBpy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2w2uJUjt_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_GeJZF1sp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_AiHJgBpy, 2, m, &cPack_AiHJgBpy_sendMessage);
}

void Heavy_prog::cVar_cojxLUEE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_AiHJgBpy, 1, m, &cPack_AiHJgBpy_sendMessage);
}

void Heavy_prog::cVar_ag7tEh6h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_AiHJgBpy, 0, m, &cPack_AiHJgBpy_sendMessage);
}

void Heavy_prog::cVar_l0Di9L2U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 10.0f, 0, m, &cBinop_5lPwLpxO_sendMessage);
}

void Heavy_prog::cBinop_5lPwLpxO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_yf8EHEhZ_sendMessage);
}

void Heavy_prog::cBinop_yf8EHEhZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_jsKAGKyf, m);
}

void Heavy_prog::cSlice_mkTbKFYA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cDelay_onMessage(_c, &Context(_c)->cDelay_uyUqSx9K, 1, m, &cDelay_uyUqSx9K_sendMessage);
      cDelay_onMessage(_c, &Context(_c)->cDelay_BYMlgNA9, 1, m, &cDelay_BYMlgNA9_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_mMbU0YiB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_1QoyFhU9_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oQliWnk1_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_QL7GvIQn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_5BxPnaIF_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_WY9GETro_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_UC4NigbB, 0, m, &cSlice_UC4NigbB_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OlYB2iRp_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_mkTbKFYA, 0, m, &cSlice_mkTbKFYA_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_mMbU0YiB, 0, m, &cSlice_mMbU0YiB_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_QL7GvIQn, 0, m, &cSlice_QL7GvIQn_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cSlice_UC4NigbB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DSBfWGJn_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IPXSWABL_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DSBfWGJn_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IPXSWABL_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cDelay_uyUqSx9K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_uyUqSx9K, m);
  cPack_onMessage(_c, &Context(_c)->cPack_cXDKFJgB, 0, m, &cPack_cXDKFJgB_sendMessage);
  cMsg_rqI3VxP2_sendMessage(_c, 0, m);
}

void Heavy_prog::cDelay_BYMlgNA9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_BYMlgNA9, m);
  cPack_onMessage(_c, &Context(_c)->cPack_cXDKFJgB, 1, m, &cPack_cXDKFJgB_sendMessage);
}

void Heavy_prog::cIf_uBlVa8OC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cDelay_onMessage(_c, &Context(_c)->cDelay_BYMlgNA9, 0, m, &cDelay_BYMlgNA9_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_5BxPnaIF_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cSlice_onMessage(_c, &Context(_c)->cSlice_jr1uXGVr, 0, m, &cSlice_jr1uXGVr_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bFyRg4iL_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2tKhvxzp_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cSlice_jr1uXGVr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_sOg1oYsN_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_sOg1oYsN_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cMsg_rqI3VxP2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cIf_onMessage(_c, &Context(_c)->cIf_uBlVa8OC, 1, m, &cIf_uBlVa8OC_sendMessage);
}

void Heavy_prog::cMsg_PU6CK5SJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cIf_onMessage(_c, &Context(_c)->cIf_uBlVa8OC, 1, m, &cIf_uBlVa8OC_sendMessage);
}

void Heavy_prog::cCast_2tKhvxzp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_uyUqSx9K, 0, m, &cDelay_uyUqSx9K_sendMessage);
}

void Heavy_prog::cCast_bFyRg4iL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_uBlVa8OC, 0, m, &cIf_uBlVa8OC_sendMessage);
}

void Heavy_prog::cCast_1QoyFhU9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_BYMlgNA9, 0, m, &cDelay_BYMlgNA9_sendMessage);
}

void Heavy_prog::cCast_oQliWnk1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PU6CK5SJ_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_sOg1oYsN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_BYMlgNA9, 0, m, &cDelay_BYMlgNA9_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uyUqSx9K, 0, m, &cDelay_uyUqSx9K_sendMessage);
}

void Heavy_prog::cPack_cXDKFJgB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_puXWWNP2, 0, m, NULL);
}

void Heavy_prog::cCast_OlYB2iRp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zlALpkqk_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_zlALpkqk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uyUqSx9K, 1, m, &cDelay_uyUqSx9K_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BYMlgNA9, 1, m, &cDelay_BYMlgNA9_sendMessage);
}

void Heavy_prog::cMsg_yhnOJlo1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  sLine_onMessage(_c, &Context(_c)->sLine_puXWWNP2, 0, m, NULL);
}

void Heavy_prog::cCast_DSBfWGJn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_f5aZ276n_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_IPXSWABL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yhnOJlo1_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_f5aZ276n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cSwitchcase_5BxPnaIF_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_uhr8kppM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_a9tSVIsa_sendMessage);
}

void Heavy_prog::cCast_AAmD5bTL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CD79Nslw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2i56cyVv_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ORJUlePY_sendMessage);
}

void Heavy_prog::cCast_ORJUlePY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ag7tEh6h, 0, m, &cVar_ag7tEh6h_sendMessage);
}

void Heavy_prog::cCast_2i56cyVv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cojxLUEE, 0, m, &cVar_cojxLUEE_sendMessage);
}

void Heavy_prog::cCast_CD79Nslw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GeJZF1sp, 0, m, &cVar_GeJZF1sp_sendMessage);
}

void Heavy_prog::cMsg_2w2uJUjt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_WY9GETro_onMessage(_c, NULL, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 1);
  msg_setElementToFrom(m, 2, n, 2);
  cSwitchcase_WY9GETro_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_9VCU9m0q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4wAQtwl4, 0, m, &cVar_4wAQtwl4_sendMessage);
}

void Heavy_prog::cBinop_aagBk7y9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Jfvr80ch, 0, m, &cVar_Jfvr80ch_sendMessage);
}

void Heavy_prog::cBinop_Ld0p5gTT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KnAFTeWx, 0, m, &cVar_KnAFTeWx_sendMessage);
}

void Heavy_prog::cReceive_6XGO9Nf0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_exDoqCbG_sendMessage(_c, 0, m);
  cMsg_ia6YC8Jt_sendMessage(_c, 0, m);
  cMsg_e6AtFHpj_sendMessage(_c, 0, m);
  cMsg_LBCQQpoI_sendMessage(_c, 0, m);
  cMsg_ABrCU5CY_sendMessage(_c, 0, m);
  cMsg_Db2Guhet_sendMessage(_c, 0, m);
  cMsg_xbUGXQhL_sendMessage(_c, 0, m);
  cMsg_m3Tepfzy_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Nk22g96w, 0, m, &cVar_Nk22g96w_sendMessage);
  cMsg_Twl3VW0P_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_tK4j9RFP, 0, m, &cVar_tK4j9RFP_sendMessage);
  cMsg_7Q1nLlIl_sendMessage(_c, 0, m);
  cMsg_GoNouLQE_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_uxEmp4hE, 0, m, &cVar_uxEmp4hE_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_0vc25TxV, 0, m, &cVar_0vc25TxV_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_YHYx9sZ8, 0, m, &cVar_YHYx9sZ8_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_VKGYcUH2, 0, m, &cVar_VKGYcUH2_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_l0Di9L2U, 0, m, &cVar_l0Di9L2U_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_7jKV1DcY, 0, m, &cVar_7jKV1DcY_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_exuJqNjf, 0, m, &cVar_exuJqNjf_sendMessage);
  cMsg_1UxaNi2U_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_VAio10WH, 0, m, &cVar_VAio10WH_sendMessage);
  cMsg_eWC2jmIW_sendMessage(_c, 0, m);
}

void Heavy_prog::cReceive_swBg2dY9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GeJZF1sp, 1, m, &cVar_GeJZF1sp_sendMessage);
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
    __hv_varread_f(&sVarf_u8NiChKT, VOf(Bf0));
    __hv_varread_f(&sVarf_tDKBcNvk, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_phasor_f(&sPhasor_2nzknvo2, VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fms_f(VIf(Bf1), VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_eBKI5gSb, VOf(Bf2));
    __hv_fma_f(VIf(Bf3), VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_phasor_f(&sPhasor_EyAvJncG, VIf(Bf0), VOf(Bf0));
    __hv_neg_f(VIf(Bf0), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_min_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf0), 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f);
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fms_f(VIf(Bf3), VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_RcL7jbNB, VOf(Bf0));
    __hv_zero_f(VOf(Bf3));
    __hv_pow_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_min_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f);
    __hv_max_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f);
    __hv_var_k_f(VOf(Bf0), 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f);
    __hv_phasor_k_f(&sPhasor_fb30VM52, VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf1));
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf6), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf7), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf5), VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf1), VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_phasor_k_f(&sPhasor_PLyU98zV, VOf(Bf6));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf6), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf1), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf6));
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf5), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf8), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf7), VIf(Bf8), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf6), VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf4), VIf(Bf1), VOf(Bf5));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_8xZuxxIq, VOf(Bf4));
    __hv_varread_f(&sVarf_31kGsukl, VOf(Bf8));
    __hv_mul_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf1), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf5), VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_qJCyIbYI, VOf(Bf6));
    __hv_varread_f(&sVarf_fmoXBxZo, VOf(Bf5));
    __hv_fma_f(VIf(Bf8), VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_phasor_f(&sPhasor_dY9bksQT, VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_abs_f(VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf6), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf6), VOf(Bf5));
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf1), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf7), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf8), VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf5), VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_ny9v4c4x, VOf(Bf6));
    __hv_varread_f(&sVarf_8uvF5VEO, VOf(Bf1));
    __hv_mul_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_phasor_f(&sPhasor_Kp6pfADo, VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_w0qEdyrk, VOf(Bf5));
    __hv_varread_f(&sVarf_jsKAGKyf, VOf(Bf7));
    __hv_fms_f(VIf(Bf1), VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_abs_f(VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_phasor_f(&sPhasor_favMWr5T, VIf(Bf7), VOf(Bf7));
    __hv_neg_f(VIf(Bf7), VOf(Bf6));
    __hv_var_k_f(VOf(Bf5), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_min_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf7), 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f);
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fms_f(VIf(Bf5), VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_puXWWNP2, VOf(Bf7));
    __hv_zero_f(VOf(Bf5));
    __hv_pow_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_min_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf5), -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f);
    __hv_max_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf6), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_mul_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_phasor_k_f(&sPhasor_M6e5wPsf, VOf(Bf4));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_abs_f(VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf5), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf4));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf8), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf7), VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf4), VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_phasor_k_f(&sPhasor_TjmuA1zl, VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf1));
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf7), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf9), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf8), VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf1), VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf5), VIf(Bf4), VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_e4c5MxLI, VOf(Bf5));
    __hv_varread_f(&sVarf_XnBj1JPX, VOf(Bf9));
    __hv_mul_f(VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf1), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf7), VIf(Bf1), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_cKLWdxD7, VOf(Bf1));
    __hv_varread_f(&sVarf_bdlqFuuL, VOf(Bf7));
    __hv_fma_f(VIf(Bf9), VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_phasor_f(&sPhasor_z1D2svmR, VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf7), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf7));
    __hv_mul_f(VIf(Bf1), VIf(Bf7), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf4), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf8), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf9), VIf(Bf8), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf7), VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf1), 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f);
    __hv_mul_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf6), VIf(Bf1), VOf(Bf6));
    __hv_fma_f(VIf(Bf2), VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_Tc5ROhQw, VOf(Bf0));
    __hv_tabhead_f(&sTabhead_897iqLJ6, VOf(Bf5));
    __hv_var_k_f_r(VOf(Bf4), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_rr0SdXhn, VOf(Bf5));
    __hv_mul_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_LtEyJLQp, VOf(Bf0));
    __hv_min_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_zero_f(VOf(Bf5));
    __hv_max_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf4));
    __hv_varread_f(&sVarf_Xs647X4K, VOf(Bf0));
    __hv_zero_f(VOf(Bf7));
    __hv_lt_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_and_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_cast_fi(VIf(Bf7), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_mwLz3Xyo, VIi(Bi1), VOf(Bf7));
    __hv_tabread_if(&sTabread_ucEGJi5m, VIi(Bi0), VOf(Bf0));
    __hv_sub_f(VIf(Bf7), VIf(Bf0), VOf(Bf7));
    __hv_sub_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf7), VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_HRPJ36te, VOf(Bf4));
    __hv_fma_f(VIf(Bf0), VIf(Bf4), VIf(Bf6), VOf(Bf4));
    __hv_line_f(&sLine_Dycv4cv8, VOf(Bf0));
    __hv_tabhead_f(&sTabhead_Rk99td38, VOf(Bf7));
    __hv_var_k_f_r(VOf(Bf5), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_EM5phRoD, VOf(Bf7));
    __hv_mul_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_OsHJd4xu, VOf(Bf0));
    __hv_min_f(VIf(Bf7), VIf(Bf0), VOf(Bf0));
    __hv_zero_f(VOf(Bf7));
    __hv_max_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_floor_f(VIf(Bf7), VOf(Bf5));
    __hv_varread_f(&sVarf_KY9Vg7zj, VOf(Bf0));
    __hv_zero_f(VOf(Bf8));
    __hv_lt_f(VIf(Bf5), VIf(Bf8), VOf(Bf8));
    __hv_and_f(VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf5), VIf(Bf8), VOf(Bf8));
    __hv_cast_fi(VIf(Bf8), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_UIcQpSw0, VIi(Bi1), VOf(Bf8));
    __hv_tabread_if(&sTabread_Pg7dfuvx, VIi(Bi0), VOf(Bf0));
    __hv_sub_f(VIf(Bf8), VIf(Bf0), VOf(Bf8));
    __hv_sub_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf8), VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_dPHrdpuN, VOf(Bf5));
    __hv_mul_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_Lb8z0cI8, VIf(Bf6));
    __hv_tabwrite_f(&sTabwrite_NO16AwuL, VIf(Bf5));
    __hv_var_k_f(VOf(Bf6), 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f);
    __hv_line_f(&sLine_yvFasSQA, VOf(Bf4));
    __hv_varread_f(&sVarf_2SoprVX7, VOf(Bf0));
    __hv_mul_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf4), VOf(Bf0));
    __hv_floor_f(VIf(Bf0), VOf(Bf8));
    __hv_sub_f(VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf8), VIf(Bf0), VOf(Bf0));
    __hv_abs_f(VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf8), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf0), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf8), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf0), VOf(Bf8));
    __hv_mul_f(VIf(Bf0), VIf(Bf8), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf9), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf10), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf8), VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf5), VIf(Bf6), VIf(Bf4), VOf(Bf6));
    __hv_add_f(VIf(Bf6), VIf(Bf1), VOf(Bf6));
    __hv_fma_f(VIf(Bf2), VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf3), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(O1), VOf(O1));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_var_k_f(VOf(Bf6), 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f);
    __hv_add_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf2), VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf5), VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(O0), VOf(O0));

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
