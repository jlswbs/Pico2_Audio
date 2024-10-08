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
  numBytes += sTabread_init(&sTabread_uo0OBiAM, &hTable_ElWEIygO, true);
  numBytes += sPhasor_k_init(&sPhasor_HDkGQCpp, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_G7OMnlKW);
  numBytes += sRPole_init(&sRPole_ymGctuwH);
  numBytes += sTabwrite_init(&sTabwrite_8BaqlGsf, &hTable_ElWEIygO);
  numBytes += sPhasor_k_init(&sPhasor_gldyenqC, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_FkLrNy0y);
  numBytes += sPhasor_init(&sPhasor_ubydacGm, sampleRate);
  numBytes += sLine_init(&sLine_XkmIvcAe);
  numBytes += sRPole_init(&sRPole_94gjxaDI);
  numBytes += sPhasor_k_init(&sPhasor_tsuMVecm, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_EV713p3j);
  numBytes += sLine_init(&sLine_lvO83xh3);
  numBytes += sLine_init(&sLine_wjVHc5oo);
  numBytes += sBiquad_init(&sBiquad_s_54xTfrk2);
  numBytes += sBiquad_init(&sBiquad_s_Afz4mgme);
  numBytes += sPhasor_k_init(&sPhasor_NbBTov1k, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_PIjhwkLE, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_tc4YMTy8);
  numBytes += sPhasor_init(&sPhasor_BWCUjx9q, sampleRate);
  numBytes += sLine_init(&sLine_dOa8UFWq);
  numBytes += sTabhead_init(&sTabhead_FRYqmwTo, &hTable_6NnYa1gW);
  numBytes += sTabread_init(&sTabread_Ox1ck9vq, &hTable_6NnYa1gW, false);
  numBytes += sTabread_init(&sTabread_zJsYPHiK, &hTable_6NnYa1gW, false);
  numBytes += sLine_init(&sLine_DocSZ9mM);
  numBytes += sLine_init(&sLine_Jbj7q6P5);
  numBytes += sTabhead_init(&sTabhead_4zAMiQln, &hTable_RSCHpM7S);
  numBytes += sTabread_init(&sTabread_VgyvTCOg, &hTable_RSCHpM7S, false);
  numBytes += sTabread_init(&sTabread_kgkBdsw2, &hTable_RSCHpM7S, false);
  numBytes += sLine_init(&sLine_nV1G1Hp5);
  numBytes += sTabwrite_init(&sTabwrite_t8PP8ETu, &hTable_6NnYa1gW);
  numBytes += sTabwrite_init(&sTabwrite_JLley0Oi, &hTable_RSCHpM7S);
  numBytes += sTabread_init(&sTabread_5xuekenN, &hTable_dYarlN3y, true);
  numBytes += sPhasor_k_init(&sPhasor_pRKaKxDF, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_D18u364V);
  numBytes += sRPole_init(&sRPole_YHgQ23dg);
  numBytes += sTabwrite_init(&sTabwrite_2Ue0SpcF, &hTable_dYarlN3y);
  numBytes += sPhasor_k_init(&sPhasor_n4zIwrke, 0.0f, sampleRate);
  numBytes += cPack_init(&cPack_Umtc8m7B, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_uCeeaDCi, 4, 1);
  numBytes += cSlice_init(&cSlice_w1DFK18j, 3, 1);
  numBytes += cSlice_init(&cSlice_oSYt3JsO, 2, 1);
  numBytes += cSlice_init(&cSlice_31dcTInX, 1, 1);
  numBytes += cSlice_init(&cSlice_91SpY1hJ, 0, 1);
  numBytes += sVarf_init(&sVarf_iehjSlKL, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_ZqyBf6eY, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_KgMG07PG, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_YWMRTbAs, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_kjGhRJJQ, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_nRgWFnx9, 2, 0.0f, 0.0f);
  numBytes += cVar_init_s(&cVar_mDnAClNK, "del-1013-inputdelay");
  numBytes += sVarf_init(&sVarf_toF4PZT7, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ovUceuj6, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_o5sdhfxt, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_FgfgFVLb, "del-1013-outputdelay");
  numBytes += sVarf_init(&sVarf_TzyroLZG, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_aCEWg1ui, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_A1pCm424, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_Qlgbf4DD, 0.0f);
  numBytes += cDelay_init(this, &cDelay_V7Bg8okb, 0.0f);
  numBytes += hTable_init(&hTable_6NnYa1gW, 256);
  numBytes += cDelay_init(this, &cDelay_9VjlLQij, 0.0f);
  numBytes += cDelay_init(this, &cDelay_R43F9e3h, 0.0f);
  numBytes += hTable_init(&hTable_RSCHpM7S, 256);
  numBytes += cVar_init_f(&cVar_94qkq5ls, 0.0f);
  numBytes += cSlice_init(&cSlice_XOAWATeM, 1, 1);
  numBytes += cSlice_init(&cSlice_ua2tuugZ, 0, 1);
  numBytes += cBinop_init(&cBinop_cprXhtMI, 1.0f); // __pow
  numBytes += cDelay_init(this, &cDelay_gtVahQSs, 2.0f);
  numBytes += cPack_init(&cPack_JgWUY116, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_azFy7afF, 1, 1);
  numBytes += cSlice_init(&cSlice_b5UVEUg7, 0, 1);
  numBytes += cVar_init_f(&cVar_6XAj1obJ, 22050.0f);
  numBytes += cBinop_init(&cBinop_xH22j4jf, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_wqIhnCAI, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_X8XdXNUC, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_1RTa6quG, 2.0f);
  numBytes += cPack_init(&cPack_Sq1Qf40Z, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_VNoPOyUy, 1, 1);
  numBytes += cSlice_init(&cSlice_DqSSfPyp, 0, 1);
  numBytes += cVar_init_f(&cVar_2dZfXi8m, 22050.0f);
  numBytes += cBinop_init(&cBinop_Xzpixm7T, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_bP1JzMf8, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_YVmmOr0h, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_1SRYQLQt, 1, -1);
  numBytes += cSlice_init(&cSlice_pWpPmdFM, 1, -1);
  numBytes += cBinop_init(&cBinop_BdOh3K18, 1.0f); // __pow
  numBytes += sVarf_init(&sVarf_pQlbcK5L, 44100.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_2riROFOT, 44100.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_5MBzcvtQ, 3.0f);
  numBytes += sVarf_init(&sVarf_3SJcfwyu, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_KTDqii1X, 2.0f);
  numBytes += cDelay_init(this, &cDelay_645btzoT, 3.0f);
  numBytes += cDelay_init(this, &cDelay_SePx1fj6, 3.0f);
  numBytes += cDelay_init(this, &cDelay_XjKTPns3, 3.0f);
  numBytes += cDelay_init(this, &cDelay_6Y9yFf5x, 3.0f);
  numBytes += cIf_init(&cIf_ny3pn3pV, false);
  numBytes += cBinop_init(&cBinop_YzekwAUv, 0.0f); // __pow
  numBytes += cPack_init(&cPack_dkZF1oSo, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_bGSixa7i, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_e7gENvKp, 2048.0f); // __mul
  numBytes += sVarf_init(&sVarf_xnzOEWvE, -1.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Q5UqM26M, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ZdnDhfhT, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Cf5Th4BF, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_BQ9OGn9B, 0.0f);
  numBytes += cRandom_init(&cRandom_nXGqg6IN, 1780425693);
  numBytes += cSlice_init(&cSlice_dPA6TQrA, 1, 1);
  numBytes += cVar_init_f(&cVar_yoA4VWMP, 0.0f);
  numBytes += cBinop_init(&cBinop_cRzooumg, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_osUzjoTe, -28121225);
  numBytes += cSlice_init(&cSlice_SkboIH0P, 1, 1);
  numBytes += sVari_init(&sVari_7vOtQ12w, 0, 0, false);
  numBytes += cTabhead_init(&cTabhead_vqx2fA6g, &hTable_ElWEIygO);
  numBytes += cVar_init_s(&cVar_Om9nZlGl, "del-1177-buf");
  numBytes += cDelay_init(this, &cDelay_sF8K9GQj, 100.0f);
  numBytes += cDelay_init(this, &cDelay_7LFX19wJ, 0.0f);
  numBytes += cBinop_init(&cBinop_5quD9JBM, 100.0f); // __mul
  numBytes += cBinop_init(&cBinop_iCIyBeks, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_6QchZZ9M, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_LbQHhmwT, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_lyEZyJes, 0.0f);
  numBytes += cDelay_init(this, &cDelay_zfBgdnGz, 0.0f);
  numBytes += hTable_init(&hTable_ElWEIygO, 256);
  numBytes += cVar_init_f(&cVar_gQExx4bt, 22050.0f);
  numBytes += cBinop_init(&cBinop_QI4QGwvv, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_9tQZsJvq, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_JqlbM8WQ, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_z6jclXAG, 0.0f); // __div
  numBytes += cRandom_init(&cRandom_z1t4y7oc, -678697051);
  numBytes += cSlice_init(&cSlice_gihxncnf, 1, 1);
  numBytes += cBinop_init(&cBinop_0qZFPKxj, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_Nzzi5PNv, -1361349363);
  numBytes += cSlice_init(&cSlice_O0yWS5Hw, 1, 1);
  numBytes += sVari_init(&sVari_S7fm1ihi, 0, 0, false);
  numBytes += cTabhead_init(&cTabhead_Tfk7hPio, &hTable_dYarlN3y);
  numBytes += cVar_init_s(&cVar_yEiVzCbD, "del-1198-buf");
  numBytes += cDelay_init(this, &cDelay_7HFkmvG1, 100.0f);
  numBytes += cDelay_init(this, &cDelay_iXhgRk57, 0.0f);
  numBytes += cBinop_init(&cBinop_bgT7QROq, 100.0f); // __mul
  numBytes += cBinop_init(&cBinop_nqFlC583, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_t79ifcPJ, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_gqfz90qD, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_4ypJVFxp, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Hz4h58R4, 0.0f);
  numBytes += hTable_init(&hTable_dYarlN3y, 256);
  numBytes += cVar_init_f(&cVar_0suCiwdB, 22050.0f);
  numBytes += cBinop_init(&cBinop_EiJcEoec, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_aT4V8xSI, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_13SyNhJe, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_v9zuj9br, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_CNlEAQyg, 0.0f);
  numBytes += cDelay_init(this, &cDelay_aTQm4aKw, 600.0f);
  numBytes += cBinop_init(&cBinop_E3XE285u, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_dTaESuTg, 0.0f);
  numBytes += cDelay_init(this, &cDelay_UI85S5KJ, 300.0f);
  numBytes += cBinop_init(&cBinop_9Q7KQ2bK, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_pBpPjVUC, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_8NVlX85H, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_prog::~Heavy_prog() {
  cPack_free(&cPack_Umtc8m7B);
  cPack_free(&cPack_kjGhRJJQ);
  cPack_free(&cPack_nRgWFnx9);
  hTable_free(&hTable_6NnYa1gW);
  hTable_free(&hTable_RSCHpM7S);
  cPack_free(&cPack_JgWUY116);
  cPack_free(&cPack_Sq1Qf40Z);
  cPack_free(&cPack_dkZF1oSo);
  cPack_free(&cPack_bGSixa7i);
  hTable_free(&hTable_ElWEIygO);
  hTable_free(&hTable_dYarlN3y);
}

HvTable *Heavy_prog::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0xB3E53CCF: return &hTable_6NnYa1gW; // del-1013-inputdelay
    case 0x40B2CE50: return &hTable_RSCHpM7S; // del-1013-outputdelay
    case 0xE9E6E8C4: return &hTable_ElWEIygO; // del-1177-buf
    case 0xED3387B3: return &hTable_dYarlN3y; // del-1198-buf
    default: return nullptr;
  }
}

void Heavy_prog::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0x858A0D39: { // 1046-buz-pha
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_K2z89Su4_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_cdwLBKQ1_sendMessage);
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


void Heavy_prog::cPack_Umtc8m7B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XVK1tZAN_sendMessage(_c, 0, m);
}

void Heavy_prog::cSlice_uCeeaDCi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_iehjSlKL, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_w1DFK18j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_YWMRTbAs, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_oSYt3JsO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_KgMG07PG, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_31dcTInX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_PIjhwkLE, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_91SpY1hJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_NbBTov1k, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_ELzPgKTV_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hVBStpxO_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_hVBStpxO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZHAAwlf5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hodciYNl_sendMessage);
}

void Heavy_prog::cCast_hodciYNl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZIwCdk8G_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_ZHAAwlf5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_4auEkFM8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Umtc8m7B, 0, m, &cPack_Umtc8m7B_sendMessage);
}

void Heavy_prog::cCast_oYrNPXvt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZqyBf6eY, HV_BINOP_MULTIPLY, 0, m, &cBinop_ZqyBf6eY_sendMessage);
}

void Heavy_prog::cMsg_ZIwCdk8G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_oYrNPXvt_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4auEkFM8_sendMessage);
}

void Heavy_prog::cBinop_ZqyBf6eY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Umtc8m7B, 1, m, &cPack_Umtc8m7B_sendMessage);
}

void Heavy_prog::cBinop_IsxbPcyJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZqyBf6eY, HV_BINOP_MULTIPLY, 1, m, &cBinop_ZqyBf6eY_sendMessage);
}

void Heavy_prog::cMsg_sx8qwf0O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.1f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 600.0f, 0, m, &cBinop_IsxbPcyJ_sendMessage);
}

void Heavy_prog::cMsg_XVK1tZAN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_tc4YMTy8, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 1);
  sLine_onMessage(_c, &Context(_c)->sLine_tc4YMTy8, 0, m, NULL);
}

void Heavy_prog::cMsg_MpxQi47r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(5);
  msg_init(m, 5, msg_getTimestamp(n));
  msg_setFloat(m, 0, 748.031f);
  msg_setFloat(m, 1, 1023.62f);
  msg_setFloat(m, 2, 0.173228f);
  msg_setFloat(m, 3, 1968.5f);
  msg_setFloat(m, 4, 9259.84f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_uCeeaDCi, 0, m, &cSlice_uCeeaDCi_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_w1DFK18j, 0, m, &cSlice_w1DFK18j_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_oSYt3JsO, 0, m, &cSlice_oSYt3JsO_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_31dcTInX, 0, m, &cSlice_31dcTInX_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_91SpY1hJ, 0, m, &cSlice_91SpY1hJ_sendMessage);
}

void Heavy_prog::cPack_kjGhRJJQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_dOa8UFWq, 0, m, NULL);
}

void Heavy_prog::cPack_nRgWFnx9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_Jbj7q6P5, 0, m, NULL);
}

void Heavy_prog::cMsg_mVXjzZ72_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_hnJsdOUx_sendMessage);
}

void Heavy_prog::cSystem_hnJsdOUx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_zOykHCQO_sendMessage);
}

void Heavy_prog::cVar_mDnAClNK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jHzd5IJd_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_L0p4HWhm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_1LAl7JTY_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_toF4PZT7, m);
}

void Heavy_prog::cBinop_zOykHCQO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ovUceuj6, m);
}

void Heavy_prog::cMsg_jHzd5IJd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_L0p4HWhm_sendMessage);
}

void Heavy_prog::cBinop_1LAl7JTY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_o5sdhfxt, m);
}

void Heavy_prog::cMsg_09VqSU6z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_diuSIZE3_sendMessage);
}

void Heavy_prog::cSystem_diuSIZE3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_8ffIoxHZ_sendMessage);
}

void Heavy_prog::cVar_FgfgFVLb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UYabfOg4_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_vkFXRbo3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_7J17VLNK_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_TzyroLZG, m);
}

void Heavy_prog::cBinop_8ffIoxHZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_aCEWg1ui, m);
}

void Heavy_prog::cMsg_UYabfOg4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_vkFXRbo3_sendMessage);
}

void Heavy_prog::cBinop_7J17VLNK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_A1pCm424, m);
}

void Heavy_prog::cBinop_u0krAgoW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_CMQ4kMGL_sendMessage);
}

void Heavy_prog::cBinop_CMQ4kMGL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Eo9VchYv_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_KU90j0Rg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_kuEBFWGG_sendMessage);
}

void Heavy_prog::cBinop_kuEBFWGG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GGldd6DJ_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_F8RbaFmz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_njsSib3M_sendMessage);
}

void Heavy_prog::cBinop_njsSib3M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_mEQDhxJr_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_HbdXdJD0_sendMessage);
}

void Heavy_prog::cMsg_ejXEBBBw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_2t0UYWKH_sendMessage);
}

void Heavy_prog::cSystem_2t0UYWKH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_uJf073Y9_sendMessage);
}

void Heavy_prog::cDelay_Qlgbf4DD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Qlgbf4DD, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_V7Bg8okb, 0, m, &cDelay_V7Bg8okb_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Qlgbf4DD, 0, m, &cDelay_Qlgbf4DD_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_t8PP8ETu, 1, m, NULL);
}

void Heavy_prog::cDelay_V7Bg8okb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_V7Bg8okb, m);
  cMsg_8LLsYA8S_sendMessage(_c, 0, m);
}

void Heavy_prog::cSwitchcase_qhpuBP8e_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_cob5pa1D_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cBinop_vgfLWJbo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DPwXgPCK_sendMessage(_c, 0, m);
}

void Heavy_prog::hTable_6NnYa1gW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_A3YjrHnR_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Qlgbf4DD, 2, m, &cDelay_Qlgbf4DD_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DgzGT3a4_sendMessage);
}

void Heavy_prog::cMsg_DPwXgPCK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_6NnYa1gW, 0, m, &hTable_6NnYa1gW_sendMessage);
}

void Heavy_prog::cBinop_uJf073Y9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 500.0f, 0, m, &cBinop_vgfLWJbo_sendMessage);
}

void Heavy_prog::cMsg_8LLsYA8S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_6NnYa1gW, 0, m, &hTable_6NnYa1gW_sendMessage);
}

void Heavy_prog::cCast_DgzGT3a4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Qlgbf4DD, 0, m, &cDelay_Qlgbf4DD_sendMessage);
}

void Heavy_prog::cMsg_A3YjrHnR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_V7Bg8okb, 2, m, &cDelay_V7Bg8okb_sendMessage);
}

void Heavy_prog::cMsg_cob5pa1D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_t8PP8ETu, 1, m, NULL);
}

void Heavy_prog::cMsg_oELgZ5Zh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_GX96SX14_sendMessage);
}

void Heavy_prog::cSystem_GX96SX14_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_PPsWWxJq_sendMessage);
}

void Heavy_prog::cDelay_9VjlLQij_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_9VjlLQij, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_R43F9e3h, 0, m, &cDelay_R43F9e3h_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9VjlLQij, 0, m, &cDelay_9VjlLQij_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_JLley0Oi, 1, m, NULL);
}

void Heavy_prog::cDelay_R43F9e3h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_R43F9e3h, m);
  cMsg_cvfMTLRu_sendMessage(_c, 0, m);
}

void Heavy_prog::cSwitchcase_e4ayJNUW_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_5hNFIN3q_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cBinop_DBG7axuZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ChNnpggJ_sendMessage(_c, 0, m);
}

void Heavy_prog::hTable_RSCHpM7S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4wpScoxW_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9VjlLQij, 2, m, &cDelay_9VjlLQij_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gOotHBDf_sendMessage);
}

void Heavy_prog::cMsg_ChNnpggJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_RSCHpM7S, 0, m, &hTable_RSCHpM7S_sendMessage);
}

void Heavy_prog::cBinop_PPsWWxJq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 500.0f, 0, m, &cBinop_DBG7axuZ_sendMessage);
}

void Heavy_prog::cMsg_cvfMTLRu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_RSCHpM7S, 0, m, &hTable_RSCHpM7S_sendMessage);
}

void Heavy_prog::cCast_gOotHBDf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_9VjlLQij, 0, m, &cDelay_9VjlLQij_sendMessage);
}

void Heavy_prog::cMsg_4wpScoxW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_R43F9e3h, 2, m, &cDelay_R43F9e3h_sendMessage);
}

void Heavy_prog::cMsg_5hNFIN3q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_JLley0Oi, 1, m, NULL);
}

void Heavy_prog::cMsg_GGldd6DJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_nV1G1Hp5, 0, m, NULL);
}

void Heavy_prog::cMsg_Eo9VchYv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_DocSZ9mM, 0, m, NULL);
}

void Heavy_prog::cCast_HbdXdJD0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_kjGhRJJQ, 1, m, &cPack_kjGhRJJQ_sendMessage);
}

void Heavy_prog::cCast_mEQDhxJr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_nRgWFnx9, 1, m, &cPack_nRgWFnx9_sendMessage);
}

void Heavy_prog::cBinop_eYRuPsor_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_kjGhRJJQ, 0, m, &cPack_kjGhRJJQ_sendMessage);
}

void Heavy_prog::cBinop_lcgrgkuG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_nRgWFnx9, 0, m, &cPack_nRgWFnx9_sendMessage);
}

void Heavy_prog::cMsg_H7PydLiK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 250.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 500.0f, 0, m, &cBinop_eYRuPsor_sendMessage);
}

void Heavy_prog::cMsg_qMPh04nq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.8f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 0.999f, 0, m, &cBinop_KU90j0Rg_sendMessage);
}

void Heavy_prog::cMsg_MSfFIUlq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1000.0f, 0, m, &cBinop_lcgrgkuG_sendMessage);
}

void Heavy_prog::cVar_94qkq5ls_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 40.0f, 0, m, &cBinop_P0pMkGD1_sendMessage);
}

void Heavy_prog::cMsg_PMQCDa8N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  sPhasor_onMessage(_c, &Context(_c)->sPhasor_ubydacGm, 1, m);
}

void Heavy_prog::cMsg_du1eT0p1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_XkmIvcAe, 0, m, NULL);
}

void Heavy_prog::cMsg_LkCQHWat_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_FkLrNy0y, 0, m, NULL);
}

void Heavy_prog::cCast_wAx7EdtM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PMQCDa8N_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_LCIJSZ2s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VoYbQ9ku_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_o2mjTCxS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_du1eT0p1_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_t1pmA560_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_94qkq5ls, 0, m, &cVar_94qkq5ls_sendMessage);
}

void Heavy_prog::cBinop_cCKr9iv9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 20.0f, 0, m, &cBinop_8dqg9Uqz_sendMessage);
}

void Heavy_prog::cBinop_P0pMkGD1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LkCQHWat_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_8dqg9Uqz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_94qkq5ls, 1, m, &cVar_94qkq5ls_sendMessage);
}

void Heavy_prog::cMsg_VoYbQ9ku_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 200.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_XkmIvcAe, 0, m, NULL);
}

void Heavy_prog::cSlice_XOAWATeM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_Fl6cjQEs_sendMessage);
      cSwitchcase_5foSaRYK_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_ua2tuugZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cDelay_onMessage(_c, &Context(_c)->cDelay_5MBzcvtQ, 0, m, &cDelay_5MBzcvtQ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_AlzKO5pl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jirvkrIp_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3s6ycpXZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gD42ZJy2_sendMessage);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_tsuMVecm, 0, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_3SJcfwyu, m);
}

void Heavy_prog::cBinop_swgUzl0Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_v1OJ2aA7_sendMessage);
}

void Heavy_prog::cBinop_v1OJ2aA7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cprXhtMI, HV_BINOP_POW, 1, m, &cBinop_cprXhtMI_sendMessage);
  cMsg_mpuXSgqe_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_cprXhtMI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_AlzKO5pl_sendMessage);
}

void Heavy_prog::cMsg_mpuXSgqe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_cprXhtMI, HV_BINOP_POW, 0, m, &cBinop_cprXhtMI_sendMessage);
}

void Heavy_prog::cSwitchcase_3bSAk3TT_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_JayWHoVl_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_JayWHoVl_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_gtVahQSs, 1, m, &cDelay_gtVahQSs_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_d2vMPun7_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_gtVahQSs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_gtVahQSs, m);
  cPack_onMessage(_c, &Context(_c)->cPack_JgWUY116, 0, m, &cPack_JgWUY116_sendMessage);
}

void Heavy_prog::cMsg_JayWHoVl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_gtVahQSs, 0, m, &cDelay_gtVahQSs_sendMessage);
}

void Heavy_prog::cCast_d2vMPun7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_gtVahQSs, 0, m, &cDelay_gtVahQSs_sendMessage);
}

void Heavy_prog::cPack_JgWUY116_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TnYyXjO5_sendMessage(_c, 0, m);
}

void Heavy_prog::cSlice_azFy7afF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_gb5MEIpU_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_b5UVEUg7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_Q5UqM26M, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cVar_6XAj1obJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xH22j4jf, HV_BINOP_MULTIPLY, 0, m, &cBinop_xH22j4jf_sendMessage);
}

void Heavy_prog::cMsg_4GGFHtgZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_2y5Acj4k_sendMessage);
}

void Heavy_prog::cSystem_2y5Acj4k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_62AhM6ST_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_xH22j4jf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_JdLl49NG_sendMessage);
}

void Heavy_prog::cBinop_ZeeCFWMH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xH22j4jf, HV_BINOP_MULTIPLY, 1, m, &cBinop_xH22j4jf_sendMessage);
}

void Heavy_prog::cMsg_62AhM6ST_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_ZeeCFWMH_sendMessage);
}

void Heavy_prog::cBinop_JdLl49NG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_mz7pjecg_sendMessage);
}

void Heavy_prog::cBinop_mz7pjecg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_84bIARAc_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_X8XdXNUC, m);
}

void Heavy_prog::cBinop_84bIARAc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_wqIhnCAI, m);
}

void Heavy_prog::cSwitchcase_sv7yxcwp_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_Gp2LsnFj_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_Gp2LsnFj_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_1RTa6quG, 1, m, &cDelay_1RTa6quG_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kNPEigZF_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_1RTa6quG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_1RTa6quG, m);
  cPack_onMessage(_c, &Context(_c)->cPack_Sq1Qf40Z, 0, m, &cPack_Sq1Qf40Z_sendMessage);
}

void Heavy_prog::cMsg_Gp2LsnFj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_1RTa6quG, 0, m, &cDelay_1RTa6quG_sendMessage);
}

void Heavy_prog::cCast_kNPEigZF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_1RTa6quG, 0, m, &cDelay_1RTa6quG_sendMessage);
}

void Heavy_prog::cPack_Sq1Qf40Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kuEL7J5t_sendMessage(_c, 0, m);
}

void Heavy_prog::cSlice_VNoPOyUy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_UKAV8QTO_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_DqSSfPyp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_ZdnDhfhT, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cVar_2dZfXi8m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Xzpixm7T, HV_BINOP_MULTIPLY, 0, m, &cBinop_Xzpixm7T_sendMessage);
}

void Heavy_prog::cMsg_Pw7JTjRm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_v3CbBV4l_sendMessage);
}

void Heavy_prog::cSystem_v3CbBV4l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KTql2ELd_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_Xzpixm7T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_zDcWK4ru_sendMessage);
}

void Heavy_prog::cBinop_QLDNW2o9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Xzpixm7T, HV_BINOP_MULTIPLY, 1, m, &cBinop_Xzpixm7T_sendMessage);
}

void Heavy_prog::cMsg_KTql2ELd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_QLDNW2o9_sendMessage);
}

void Heavy_prog::cBinop_zDcWK4ru_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_8gMXtXuc_sendMessage);
}

void Heavy_prog::cBinop_8gMXtXuc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_m1Dy7wNN_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_YVmmOr0h, m);
}

void Heavy_prog::cBinop_m1Dy7wNN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_bP1JzMf8, m);
}

void Heavy_prog::cSwitchcase_T3Gq0gpM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_1SRYQLQt, 0, m, &cSlice_1SRYQLQt_sendMessage);
      break;
    }
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_pWpPmdFM, 0, m, &cSlice_pWpPmdFM_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cSlice_1SRYQLQt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_swgUzl0Y_sendMessage);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_swgUzl0Y_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_pWpPmdFM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_9eFNOunO_sendMessage);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_9eFNOunO_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_bvl8BMSv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aDoNfOEA_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rAXDtk8T_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hgbksNPt_sendMessage);
}

void Heavy_prog::cBinop_9eFNOunO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_lGJwIJzh_sendMessage);
}

void Heavy_prog::cBinop_lGJwIJzh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BdOh3K18, HV_BINOP_POW, 1, m, &cBinop_BdOh3K18_sendMessage);
  cMsg_8naDOI7D_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_BdOh3K18_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_bvl8BMSv_sendMessage);
}

void Heavy_prog::cMsg_8naDOI7D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_BdOh3K18, HV_BINOP_POW, 0, m, &cBinop_BdOh3K18_sendMessage);
}

void Heavy_prog::cSwitchcase_ysje4zNi_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mnLlxfy1_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_mnLlxfy1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_csSP8RcE_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jbPuCfrm_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QQCkJjjJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9ZufqMej_sendMessage);
  cSwitchcase_5KS463DQ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_hVo5coaF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_s5cmr2Ek_sendMessage);
}

void Heavy_prog::cSystem_s5cmr2Ek_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_pQlbcK5L, m);
}

void Heavy_prog::cMsg_kV4sV5ka_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_WHfHHgek_sendMessage);
}

void Heavy_prog::cSystem_WHfHHgek_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_2riROFOT, m);
}

void Heavy_prog::cDelay_5MBzcvtQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_5MBzcvtQ, m);
  cPack_onMessage(_c, &Context(_c)->cPack_dkZF1oSo, 0, m, &cPack_dkZF1oSo_sendMessage);
}

void Heavy_prog::cSwitchcase_j748SDwM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_r1VO5Pkv_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_r1VO5Pkv_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_KTDqii1X, 1, m, &cDelay_KTDqii1X_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_87zNzrt4_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_KTDqii1X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_KTDqii1X, m);
  cMsg_00zQnxAJ_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_r1VO5Pkv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_KTDqii1X, 0, m, &cDelay_KTDqii1X_sendMessage);
}

void Heavy_prog::cCast_87zNzrt4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_KTDqii1X, 0, m, &cDelay_KTDqii1X_sendMessage);
}

void Heavy_prog::cSwitchcase_Hg1a7fFy_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_5emCu49O_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_5emCu49O_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_645btzoT, 1, m, &cDelay_645btzoT_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zklMGZct_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_645btzoT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_645btzoT, m);
  cMsg_jon8KqY7_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_5emCu49O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_645btzoT, 0, m, &cDelay_645btzoT_sendMessage);
}

void Heavy_prog::cCast_zklMGZct_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_645btzoT, 0, m, &cDelay_645btzoT_sendMessage);
}

void Heavy_prog::cSwitchcase_5KS463DQ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_O6mRuvKU_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_O6mRuvKU_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_SePx1fj6, 1, m, &cDelay_SePx1fj6_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xNB9tKot_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_SePx1fj6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_SePx1fj6, m);
  cMsg_95HrKg8L_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_O6mRuvKU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_SePx1fj6, 0, m, &cDelay_SePx1fj6_sendMessage);
}

void Heavy_prog::cCast_xNB9tKot_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_SePx1fj6, 0, m, &cDelay_SePx1fj6_sendMessage);
}

void Heavy_prog::cSwitchcase_7ptmNGvr_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cMsg_s9kMtrMe_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_s9kMtrMe_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_XjKTPns3, 1, m, &cDelay_XjKTPns3_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OsYVqOHq_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_XjKTPns3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_XjKTPns3, m);
  cMsg_Go9t6spH_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_s9kMtrMe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_XjKTPns3, 0, m, &cDelay_XjKTPns3_sendMessage);
}

void Heavy_prog::cCast_OsYVqOHq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_XjKTPns3, 0, m, &cDelay_XjKTPns3_sendMessage);
}

void Heavy_prog::cDelay_6Y9yFf5x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_6Y9yFf5x, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_QIlpUMW2_sendMessage);
}

void Heavy_prog::cSwitchcase_5foSaRYK_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FdP7iLVd_sendMessage);
      break;
    }
    default: {
      cDelay_onMessage(_c, &Context(_c)->cDelay_6Y9yFf5x, 0, m, &cDelay_6Y9yFf5x_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cCast_FdP7iLVd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cIf_ny3pn3pV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_TcJty9BS_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 485.0f, 0, m, &cBinop_X5DcXdYc_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cMsg_xPKFqMcA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_YzekwAUv, HV_BINOP_POW, 0, m, &cBinop_YzekwAUv_sendMessage);
}

void Heavy_prog::cBinop_YzekwAUv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Cf5Th4BF, m);
}

void Heavy_prog::cBinop_zaiVktH6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 20.0f, 0, m, &cBinop_dkVoqyot_sendMessage);
}

void Heavy_prog::cCast_iNtdz03s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_HwFy0KPN_sendMessage);
}

void Heavy_prog::cCast_wmoqHOuq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ny3pn3pV, 0, m, &cIf_ny3pn3pV_sendMessage);
}

void Heavy_prog::cBinop_HwFy0KPN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ny3pn3pV, 1, m, &cIf_ny3pn3pV_sendMessage);
}

void Heavy_prog::cBinop_X5DcXdYc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_zaiVktH6_sendMessage);
}

void Heavy_prog::cMsg_TcJty9BS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Cf5Th4BF, m);
}

void Heavy_prog::cBinop_dkVoqyot_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YzekwAUv, HV_BINOP_POW, 1, m, &cBinop_YzekwAUv_sendMessage);
  cMsg_xPKFqMcA_sendMessage(_c, 0, m);
}

void Heavy_prog::cPack_dkZF1oSo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cA4hkEOR_sendMessage(_c, 0, m);
}

void Heavy_prog::cPack_bGSixa7i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_XOAWATeM, 0, m, &cSlice_XOAWATeM_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_ua2tuugZ, 0, m, &cSlice_ua2tuugZ_sendMessage);
}

void Heavy_prog::cBinop_Fl6cjQEs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ysje4zNi_onMessage(_c, NULL, 0, m, NULL);
  cPack_onMessage(_c, &Context(_c)->cPack_dkZF1oSo, 1, m, &cPack_dkZF1oSo_sendMessage);
}

void Heavy_prog::cMsg_3dtNxbVW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_ne8xx7Yw_sendMessage);
}

void Heavy_prog::cBinop_ne8xx7Yw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_e7gENvKp, HV_BINOP_MULTIPLY, 0, m, &cBinop_e7gENvKp_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 128.0f, 0, m, &cBinop_K9qBW0Td_sendMessage);
}

void Heavy_prog::cCast_MNgF6rAo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_3bSAk3TT_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_7StI8iUO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OGTiuuXW_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_TnYyXjO5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 1);
  cSlice_onMessage(_c, &Context(_c)->cSlice_azFy7afF, 0, m, &cSlice_azFy7afF_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_b5UVEUg7, 0, m, &cSlice_b5UVEUg7_sendMessage);
}

void Heavy_prog::cMsg_gb5MEIpU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_aVPfItfk_sendMessage);
}

void Heavy_prog::cBinop_aVPfItfk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6XAj1obJ, 0, m, &cVar_6XAj1obJ_sendMessage);
}

void Heavy_prog::cMsg_95HrKg8L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_tsuMVecm, 1, m);
}

void Heavy_prog::cBinop_e7gENvKp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_JgWUY116, 1, m, &cPack_JgWUY116_sendMessage);
}

void Heavy_prog::cCast_csSP8RcE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Hg1a7fFy_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_jbPuCfrm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zXcQLUck_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_zXcQLUck_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_lvO83xh3, 0, m, NULL);
}

void Heavy_prog::cMsg_jon8KqY7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_lvO83xh3, 0, m, NULL);
}

void Heavy_prog::cCast_62s2ujjD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4cKceb5h_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_9Tl4h2ZF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_sv7yxcwp_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_kuEL7J5t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 1);
  cSlice_onMessage(_c, &Context(_c)->cSlice_VNoPOyUy, 0, m, &cSlice_VNoPOyUy_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_DqSSfPyp, 0, m, &cSlice_DqSSfPyp_sendMessage);
}

void Heavy_prog::cMsg_UKAV8QTO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_rc8ON79I_sendMessage);
}

void Heavy_prog::cBinop_rc8ON79I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2dZfXi8m, 0, m, &cVar_2dZfXi8m_sendMessage);
}

void Heavy_prog::cMsg_4cKceb5h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 1.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_VNoPOyUy, 0, m, &cSlice_VNoPOyUy_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_DqSSfPyp, 0, m, &cSlice_DqSSfPyp_sendMessage);
}

void Heavy_prog::cBinop_K9qBW0Td_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Sq1Qf40Z, 1, m, &cPack_Sq1Qf40Z_sendMessage);
}

void Heavy_prog::cMsg_uCffvnCz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 50.0f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_VNoPOyUy, 0, m, &cSlice_VNoPOyUy_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_DqSSfPyp, 0, m, &cSlice_DqSSfPyp_sendMessage);
}

void Heavy_prog::cCast_aDoNfOEA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_brVgDE9u_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_hgbksNPt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_JgWUY116, 0, m, &cPack_JgWUY116_sendMessage);
}

void Heavy_prog::cCast_rAXDtk8T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3dtNxbVW_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_jirvkrIp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jtIvsVdW_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_gD42ZJy2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7StI8iUO_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MNgF6rAo_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_62s2ujjD_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9Tl4h2ZF_sendMessage);
}

void Heavy_prog::cCast_3s6ycpXZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3dtNxbVW_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_jtIvsVdW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2048.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_e7gENvKp, HV_BINOP_MULTIPLY, 1, m, &cBinop_e7gENvKp_sendMessage);
}

void Heavy_prog::cCast_QQCkJjjJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_7ptmNGvr_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_9ZufqMej_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_j748SDwM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_Go9t6spH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_wjVHc5oo, 0, m, NULL);
}

void Heavy_prog::cMsg_00zQnxAJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20000.0f);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_wjVHc5oo, 0, m, NULL);
}

void Heavy_prog::cMsg_OGTiuuXW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.1f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_azFy7afF, 0, m, &cSlice_azFy7afF_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_b5UVEUg7, 0, m, &cSlice_b5UVEUg7_sendMessage);
}

void Heavy_prog::cBinop_QIlpUMW2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 126.0f, 0, m, &cBinop_epFMRQoE_sendMessage);
}

void Heavy_prog::cBinop_epFMRQoE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_thscegvE_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_thscegvE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_CcSDTgnv_sendMessage);
}

void Heavy_prog::cBinop_CcSDTgnv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -30.0f, 0, m, &cBinop_cIA3UCBJ_sendMessage);
}

void Heavy_prog::cBinop_cIA3UCBJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 100.0f, 0, m, &cBinop_xU377ePm_sendMessage);
}

void Heavy_prog::cBinop_xU377ePm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_iNtdz03s_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wmoqHOuq_sendMessage);
}

void Heavy_prog::cMsg_brVgDE9u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 8.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_e7gENvKp, HV_BINOP_MULTIPLY, 1, m, &cBinop_e7gENvKp_sendMessage);
}

void Heavy_prog::cMsg_cA4hkEOR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 1);
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_T3Gq0gpM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cVar_BQ9OGn9B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_bGSixa7i, 1, m, &cPack_bGSixa7i_sendMessage);
}

void Heavy_prog::cSwitchcase_CHSrKiRd_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_dPA6TQrA, 0, m, &cSlice_dPA6TQrA_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_nXGqg6IN, 0, m, &cRandom_nXGqg6IN_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_HQ5esm88_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_szqyQOCg_sendMessage);
}

void Heavy_prog::cUnop_szqyQOCg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 68.0f, 0, m, &cBinop_NJHVjnPb_sendMessage);
}

void Heavy_prog::cRandom_nXGqg6IN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 48.0f, 0, m, &cBinop_HQ5esm88_sendMessage);
}

void Heavy_prog::cSlice_dPA6TQrA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_nXGqg6IN, 1, m, &cRandom_nXGqg6IN_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cVar_yoA4VWMP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_bGSixa7i, 0, m, &cPack_bGSixa7i_sendMessage);
}

void Heavy_prog::cBinop_KkAMjfh9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ay14IWDK_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QbKAt358_sendMessage);
}

void Heavy_prog::cBinop_fhLUHh1Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_XtNeo2Zz_sendMessage);
}

void Heavy_prog::cBinop_XtNeo2Zz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cRzooumg, HV_BINOP_POW, 1, m, &cBinop_cRzooumg_sendMessage);
  cMsg_WgRLEnqJ_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_cRzooumg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_KkAMjfh9_sendMessage);
}

void Heavy_prog::cMsg_WgRLEnqJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_cRzooumg, HV_BINOP_POW, 0, m, &cBinop_cRzooumg_sendMessage);
}

void Heavy_prog::cSwitchcase_5GtPAsOr_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_SkboIH0P, 0, m, &cSlice_SkboIH0P_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_osUzjoTe, 0, m, &cRandom_osUzjoTe_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_FH6iAazo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_wcouy16g_sendMessage);
}

void Heavy_prog::cUnop_wcouy16g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AfwFZUb0_sendMessage(_c, 0, m);
}

void Heavy_prog::cRandom_osUzjoTe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_FH6iAazo_sendMessage);
}

void Heavy_prog::cSlice_SkboIH0P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_osUzjoTe, 1, m, &cRandom_osUzjoTe_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cMsg_AfwFZUb0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_7vOtQ12w, m);
}

void Heavy_prog::cTabhead_vqx2fA6g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iCIyBeks, HV_BINOP_SUBTRACT, 0, m, &cBinop_iCIyBeks_sendMessage);
}

void Heavy_prog::cMsg_WvpZXHxt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_nXVFIdgA_sendMessage);
}

void Heavy_prog::cSystem_nXVFIdgA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_VaEV5ETO_sendMessage);
}

void Heavy_prog::cVar_Om9nZlGl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8onuErGj_sendMessage(_c, 0, m);
}

void Heavy_prog::cDelay_sF8K9GQj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_sF8K9GQj, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7LFX19wJ, 0, m, &cDelay_7LFX19wJ_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_uo0OBiAM, 0, m, &sTabread_uo0OBiAM_sendMessage);
}

void Heavy_prog::cDelay_7LFX19wJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_7LFX19wJ, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_uo0OBiAM, 0, m, &sTabread_uo0OBiAM_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7LFX19wJ, 0, m, &cDelay_7LFX19wJ_sendMessage);
}

void Heavy_prog::sTabread_uo0OBiAM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_LbQHhmwT, HV_BINOP_SUBTRACT, 0, m, &cBinop_LbQHhmwT_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_5quD9JBM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6QchZZ9M, HV_BINOP_MAX, 0, m, &cBinop_6QchZZ9M_sendMessage);
}

void Heavy_prog::cBinop_VaEV5ETO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5quD9JBM, HV_BINOP_MULTIPLY, 0, m, &cBinop_5quD9JBM_sendMessage);
}

void Heavy_prog::cBinop_iCIyBeks_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SoDemoGr_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_uo0OBiAM, 0, m, &sTabread_uo0OBiAM_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Gc8UyXb3_sendMessage);
}

void Heavy_prog::cSystem_NSafD5RR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LbQHhmwT, HV_BINOP_SUBTRACT, 1, m, &cBinop_LbQHhmwT_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7LFX19wJ, 2, m, &cDelay_7LFX19wJ_sendMessage);
}

void Heavy_prog::cMsg_8onuErGj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_NSafD5RR_sendMessage);
}

void Heavy_prog::cMsg_SoDemoGr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_sF8K9GQj, 0, m, &cDelay_sF8K9GQj_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_7LFX19wJ, 0, m, &cDelay_7LFX19wJ_sendMessage);
}

void Heavy_prog::cMsg_nTAE9uEG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_6QchZZ9M, HV_BINOP_MAX, 1, m, &cBinop_6QchZZ9M_sendMessage);
}

void Heavy_prog::cBinop_6QchZZ9M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iCIyBeks, HV_BINOP_SUBTRACT, 1, m, &cBinop_iCIyBeks_sendMessage);
}

void Heavy_prog::cCast_Gc8UyXb3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_sF8K9GQj, 0, m, &cDelay_sF8K9GQj_sendMessage);
}

void Heavy_prog::cBinop_VVhBqeoR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_sF8K9GQj, 2, m, &cDelay_sF8K9GQj_sendMessage);
}

void Heavy_prog::cBinop_LbQHhmwT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_VVhBqeoR_sendMessage);
}

void Heavy_prog::cCast_5VTJeFgz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Om9nZlGl, 0, m, &cVar_Om9nZlGl_sendMessage);
  cMsg_WvpZXHxt_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_vqx2fA6g, 0, m, &cTabhead_vqx2fA6g_sendMessage);
}

void Heavy_prog::cMsg_UA6PDbFk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0QOImq1e_sendMessage);
}

void Heavy_prog::cSystem_0QOImq1e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_1TJSxn6s_sendMessage);
}

void Heavy_prog::cDelay_lyEZyJes_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_lyEZyJes, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zfBgdnGz, 0, m, &cDelay_zfBgdnGz_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_lyEZyJes, 0, m, &cDelay_lyEZyJes_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_8BaqlGsf, 1, m, NULL);
}

void Heavy_prog::cDelay_zfBgdnGz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_zfBgdnGz, m);
  cMsg_fVfvgxMG_sendMessage(_c, 0, m);
}

void Heavy_prog::cSwitchcase_xwPDQcwI_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_sgbsmaCW_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cBinop_8XnBnSw2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8kDoudiM_sendMessage(_c, 0, m);
}

void Heavy_prog::hTable_ElWEIygO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_We9OfAAn_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_lyEZyJes, 2, m, &cDelay_lyEZyJes_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_y0JShZhm_sendMessage);
}

void Heavy_prog::cMsg_8kDoudiM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_ElWEIygO, 0, m, &hTable_ElWEIygO_sendMessage);
}

void Heavy_prog::cBinop_1TJSxn6s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_8XnBnSw2_sendMessage);
}

void Heavy_prog::cMsg_fVfvgxMG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_ElWEIygO, 0, m, &hTable_ElWEIygO_sendMessage);
}

void Heavy_prog::cCast_y0JShZhm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_lyEZyJes, 0, m, &cDelay_lyEZyJes_sendMessage);
}

void Heavy_prog::cMsg_We9OfAAn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_zfBgdnGz, 2, m, &cDelay_zfBgdnGz_sendMessage);
}

void Heavy_prog::cMsg_sgbsmaCW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_8BaqlGsf, 1, m, NULL);
}

void Heavy_prog::cVar_gQExx4bt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QI4QGwvv, HV_BINOP_MULTIPLY, 0, m, &cBinop_QI4QGwvv_sendMessage);
}

void Heavy_prog::cMsg_2Idglbhe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_tgDSGHrS_sendMessage);
}

void Heavy_prog::cSystem_tgDSGHrS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DYX5cTdX_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_QI4QGwvv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_MGGRFOV3_sendMessage);
}

void Heavy_prog::cBinop_m2Z3Pv5v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QI4QGwvv, HV_BINOP_MULTIPLY, 1, m, &cBinop_QI4QGwvv_sendMessage);
}

void Heavy_prog::cMsg_DYX5cTdX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_m2Z3Pv5v_sendMessage);
}

void Heavy_prog::cBinop_MGGRFOV3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_VQlWhYI3_sendMessage);
}

void Heavy_prog::cBinop_VQlWhYI3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_aq8esNR7_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_JqlbM8WQ, m);
}

void Heavy_prog::cBinop_aq8esNR7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_9tQZsJvq, m);
}

void Heavy_prog::cBinop_z6jclXAG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5quD9JBM, HV_BINOP_MULTIPLY, 1, m, &cBinop_5quD9JBM_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5VTJeFgz_sendMessage);
}

void Heavy_prog::cCast_ay14IWDK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_z6jclXAG, HV_BINOP_DIVIDE, 1, m, &cBinop_z6jclXAG_sendMessage);
}

void Heavy_prog::cCast_QbKAt358_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_y5vYhM9h_sendMessage(_c, 0, m);
  cMsg_3jQSFkDW_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_3jQSFkDW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_G7OMnlKW, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_G7OMnlKW, 0, m, NULL);
}

void Heavy_prog::cBinop_0395xywt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_fhLUHh1Y_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_qV8bzt0K_sendMessage);
}

void Heavy_prog::cMsg_y5vYhM9h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_z6jclXAG, HV_BINOP_DIVIDE, 0, m, &cBinop_z6jclXAG_sendMessage);
}

void Heavy_prog::cBinop_qV8bzt0K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_HDkGQCpp, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_gQExx4bt, 0, m, &cVar_gQExx4bt_sendMessage);
}

void Heavy_prog::cSwitchcase_Kv384DrO_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_gihxncnf, 0, m, &cSlice_gihxncnf_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_z1t4y7oc, 0, m, &cRandom_z1t4y7oc_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_BGrpPBhl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_4Yyt42ZN_sendMessage);
}

void Heavy_prog::cUnop_4Yyt42ZN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ELzPgKTV_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cRandom_z1t4y7oc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_BGrpPBhl_sendMessage);
}

void Heavy_prog::cSlice_gihxncnf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_z1t4y7oc, 1, m, &cRandom_z1t4y7oc_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_LA9nXji7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_pPNbIiOv_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_J8tjw3nw_sendMessage);
}

void Heavy_prog::cBinop_DOjncu7U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_eGqiCKSc_sendMessage);
}

void Heavy_prog::cBinop_eGqiCKSc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0qZFPKxj, HV_BINOP_POW, 1, m, &cBinop_0qZFPKxj_sendMessage);
  cMsg_ZCZKt9nV_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_0qZFPKxj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_LA9nXji7_sendMessage);
}

void Heavy_prog::cMsg_ZCZKt9nV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_0qZFPKxj, HV_BINOP_POW, 0, m, &cBinop_0qZFPKxj_sendMessage);
}

void Heavy_prog::cSwitchcase_TrgFOYMl_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_O0yWS5Hw, 0, m, &cSlice_O0yWS5Hw_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Nzzi5PNv, 0, m, &cRandom_Nzzi5PNv_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_EZzKi6vB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_sYlmt2lL_sendMessage);
}

void Heavy_prog::cUnop_sYlmt2lL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_t0Hy1j2A_sendMessage(_c, 0, m);
}

void Heavy_prog::cRandom_Nzzi5PNv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_EZzKi6vB_sendMessage);
}

void Heavy_prog::cSlice_O0yWS5Hw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Nzzi5PNv, 1, m, &cRandom_Nzzi5PNv_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cMsg_t0Hy1j2A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_S7fm1ihi, m);
}

void Heavy_prog::cTabhead_Tfk7hPio_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nqFlC583, HV_BINOP_SUBTRACT, 0, m, &cBinop_nqFlC583_sendMessage);
}

void Heavy_prog::cMsg_WG2LLPWl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_GXHeedgA_sendMessage);
}

void Heavy_prog::cSystem_GXHeedgA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_lIMrAFyM_sendMessage);
}

void Heavy_prog::cVar_yEiVzCbD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_owHjnmH9_sendMessage(_c, 0, m);
}

void Heavy_prog::cDelay_7HFkmvG1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_7HFkmvG1, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_iXhgRk57, 0, m, &cDelay_iXhgRk57_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_5xuekenN, 0, m, &sTabread_5xuekenN_sendMessage);
}

void Heavy_prog::cDelay_iXhgRk57_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_iXhgRk57, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_5xuekenN, 0, m, &sTabread_5xuekenN_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_iXhgRk57, 0, m, &cDelay_iXhgRk57_sendMessage);
}

void Heavy_prog::sTabread_5xuekenN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_gqfz90qD, HV_BINOP_SUBTRACT, 0, m, &cBinop_gqfz90qD_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_bgT7QROq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_t79ifcPJ, HV_BINOP_MAX, 0, m, &cBinop_t79ifcPJ_sendMessage);
}

void Heavy_prog::cBinop_lIMrAFyM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bgT7QROq, HV_BINOP_MULTIPLY, 0, m, &cBinop_bgT7QROq_sendMessage);
}

void Heavy_prog::cBinop_nqFlC583_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_R929Yr10_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_5xuekenN, 0, m, &sTabread_5xuekenN_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EW08l3VT_sendMessage);
}

void Heavy_prog::cSystem_g9wG2PhI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gqfz90qD, HV_BINOP_SUBTRACT, 1, m, &cBinop_gqfz90qD_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_iXhgRk57, 2, m, &cDelay_iXhgRk57_sendMessage);
}

void Heavy_prog::cMsg_owHjnmH9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_g9wG2PhI_sendMessage);
}

void Heavy_prog::cMsg_R929Yr10_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_7HFkmvG1, 0, m, &cDelay_7HFkmvG1_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_iXhgRk57, 0, m, &cDelay_iXhgRk57_sendMessage);
}

void Heavy_prog::cMsg_5d0MMeuL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_t79ifcPJ, HV_BINOP_MAX, 1, m, &cBinop_t79ifcPJ_sendMessage);
}

void Heavy_prog::cBinop_t79ifcPJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nqFlC583, HV_BINOP_SUBTRACT, 1, m, &cBinop_nqFlC583_sendMessage);
}

void Heavy_prog::cCast_EW08l3VT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_7HFkmvG1, 0, m, &cDelay_7HFkmvG1_sendMessage);
}

void Heavy_prog::cBinop_iECOj6aU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_7HFkmvG1, 2, m, &cDelay_7HFkmvG1_sendMessage);
}

void Heavy_prog::cBinop_gqfz90qD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_iECOj6aU_sendMessage);
}

void Heavy_prog::cCast_a78lxG6u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yEiVzCbD, 0, m, &cVar_yEiVzCbD_sendMessage);
  cMsg_WG2LLPWl_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Tfk7hPio, 0, m, &cTabhead_Tfk7hPio_sendMessage);
}

void Heavy_prog::cMsg_ZEvov2mY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_jUQbaQnt_sendMessage);
}

void Heavy_prog::cSystem_jUQbaQnt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_M1MuiGXK_sendMessage);
}

void Heavy_prog::cDelay_4ypJVFxp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_4ypJVFxp, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Hz4h58R4, 0, m, &cDelay_Hz4h58R4_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4ypJVFxp, 0, m, &cDelay_4ypJVFxp_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_2Ue0SpcF, 1, m, NULL);
}

void Heavy_prog::cDelay_Hz4h58R4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Hz4h58R4, m);
  cMsg_3LZh1jRx_sendMessage(_c, 0, m);
}

void Heavy_prog::cSwitchcase_OPWXc48k_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_ncZu83Ma_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cBinop_i01xm9sV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kHu00dgL_sendMessage(_c, 0, m);
}

void Heavy_prog::hTable_dYarlN3y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DAedXgUX_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4ypJVFxp, 2, m, &cDelay_4ypJVFxp_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_46pfl2pL_sendMessage);
}

void Heavy_prog::cMsg_kHu00dgL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_dYarlN3y, 0, m, &hTable_dYarlN3y_sendMessage);
}

void Heavy_prog::cBinop_M1MuiGXK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_i01xm9sV_sendMessage);
}

void Heavy_prog::cMsg_3LZh1jRx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_dYarlN3y, 0, m, &hTable_dYarlN3y_sendMessage);
}

void Heavy_prog::cCast_46pfl2pL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_4ypJVFxp, 0, m, &cDelay_4ypJVFxp_sendMessage);
}

void Heavy_prog::cMsg_DAedXgUX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_Hz4h58R4, 2, m, &cDelay_Hz4h58R4_sendMessage);
}

void Heavy_prog::cMsg_ncZu83Ma_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_2Ue0SpcF, 1, m, NULL);
}

void Heavy_prog::cVar_0suCiwdB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EiJcEoec, HV_BINOP_MULTIPLY, 0, m, &cBinop_EiJcEoec_sendMessage);
}

void Heavy_prog::cMsg_SV9fd9Av_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JH0X3H64_sendMessage);
}

void Heavy_prog::cSystem_JH0X3H64_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PzT25nIs_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_EiJcEoec_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_I4lVJ3GX_sendMessage);
}

void Heavy_prog::cBinop_12qLszJa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EiJcEoec, HV_BINOP_MULTIPLY, 1, m, &cBinop_EiJcEoec_sendMessage);
}

void Heavy_prog::cMsg_PzT25nIs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_12qLszJa_sendMessage);
}

void Heavy_prog::cBinop_I4lVJ3GX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Ft6HLwCS_sendMessage);
}

void Heavy_prog::cBinop_Ft6HLwCS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ReDlJGp0_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_13SyNhJe, m);
}

void Heavy_prog::cBinop_ReDlJGp0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_aT4V8xSI, m);
}

void Heavy_prog::cBinop_v9zuj9br_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bgT7QROq, HV_BINOP_MULTIPLY, 1, m, &cBinop_bgT7QROq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_a78lxG6u_sendMessage);
}

void Heavy_prog::cCast_J8tjw3nw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_x74VS8R7_sendMessage(_c, 0, m);
  cMsg_m842SMLk_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_pPNbIiOv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_v9zuj9br, HV_BINOP_DIVIDE, 1, m, &cBinop_v9zuj9br_sendMessage);
}

void Heavy_prog::cMsg_m842SMLk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_D18u364V, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_D18u364V, 0, m, NULL);
}

void Heavy_prog::cBinop_9AmGk4jY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_DOjncu7U_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 80.0f, 0, m, &cBinop_H2vaRBZ7_sendMessage);
}

void Heavy_prog::cMsg_x74VS8R7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_v9zuj9br, HV_BINOP_DIVIDE, 0, m, &cBinop_v9zuj9br_sendMessage);
}

void Heavy_prog::cBinop_H2vaRBZ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_pRKaKxDF, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_0suCiwdB, 0, m, &cVar_0suCiwdB_sendMessage);
}

void Heavy_prog::cVar_CNlEAQyg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Fs1vYBFq_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 0.999f, 0, m, &cBinop_u0krAgoW_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 110.0f, 0, m, &cBinop_tFgEVlrZ_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 50.0f, 0, m, &cBinop_0395xywt_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 4.0f, 0, m, &cBinop_3mKJSCew_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_8NVlX85H, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_aTQm4aKw, 0, m, &cDelay_aTQm4aKw_sendMessage);
}

void Heavy_prog::cDelay_aTQm4aKw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_aTQm4aKw, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nvaH7Sje_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yuigtzsA_sendMessage);
}

void Heavy_prog::cCast_nvaH7Sje_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 3.7f, 0, m, &cBinop_41Qyy9r3_sendMessage);
}

void Heavy_prog::cCast_yuigtzsA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_p4WHyUqU_sendMessage);
}

void Heavy_prog::cBinop_p4WHyUqU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_aNJPAWBI_sendMessage);
}

void Heavy_prog::cBinop_aNJPAWBI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_E3XE285u, HV_BINOP_MULTIPLY, 0, m, &cBinop_E3XE285u_sendMessage);
}

void Heavy_prog::cBinop_E3XE285u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CNlEAQyg, 0, m, &cVar_CNlEAQyg_sendMessage);
}

void Heavy_prog::cMsg_SLG3ACCH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.1f);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nvaH7Sje_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yuigtzsA_sendMessage);
}

void Heavy_prog::cBinop_41Qyy9r3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_E3XE285u, HV_BINOP_MULTIPLY, 1, m, &cBinop_E3XE285u_sendMessage);
}

void Heavy_prog::cVar_dTaESuTg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HIzXgDOS_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 36.0f, 0, m, &cBinop_qSRO9ipS_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 220.0f, 0, m, &cBinop_AgzC0Rux_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 50.0f, 0, m, &cBinop_9AmGk4jY_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_pBpPjVUC, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_UI85S5KJ, 0, m, &cDelay_UI85S5KJ_sendMessage);
}

void Heavy_prog::cDelay_UI85S5KJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_UI85S5KJ, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_J8FK5EWO_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4mEzioo1_sendMessage);
}

void Heavy_prog::cCast_J8FK5EWO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 3.75f, 0, m, &cBinop_mYZGuWaf_sendMessage);
}

void Heavy_prog::cCast_4mEzioo1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_5jt9q7nJ_sendMessage);
}

void Heavy_prog::cBinop_5jt9q7nJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_q6fyIJtQ_sendMessage);
}

void Heavy_prog::cBinop_q6fyIJtQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9Q7KQ2bK, HV_BINOP_MULTIPLY, 0, m, &cBinop_9Q7KQ2bK_sendMessage);
}

void Heavy_prog::cBinop_9Q7KQ2bK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dTaESuTg, 0, m, &cVar_dTaESuTg_sendMessage);
}

void Heavy_prog::cMsg_FenE2xJN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.1f);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_J8FK5EWO_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4mEzioo1_sendMessage);
}

void Heavy_prog::cBinop_mYZGuWaf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9Q7KQ2bK, HV_BINOP_MULTIPLY, 1, m, &cBinop_9Q7KQ2bK_sendMessage);
}

void Heavy_prog::cCast_Fs1vYBFq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_CHSrKiRd_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_Kv384DrO_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_HIzXgDOS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_o2mjTCxS_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LCIJSZ2s_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wAx7EdtM_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_t1pmA560_sendMessage);
}

void Heavy_prog::cBinop_qSRO9ipS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 32.0f, 0, m, &cBinop_VyfDPWlS_sendMessage);
}

void Heavy_prog::cBinop_AgzC0Rux_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1000.0f, 0, m, &cBinop_F8RbaFmz_sendMessage);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_gldyenqC, 0, m);
}

void Heavy_prog::cBinop_tFgEVlrZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_n4zIwrke, 0, m);
}

void Heavy_prog::cBinop_VyfDPWlS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yoA4VWMP, 0, m, &cVar_yoA4VWMP_sendMessage);
}

void Heavy_prog::cBinop_3mKJSCew_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_cCKr9iv9_sendMessage);
}

void Heavy_prog::cBinop_NJHVjnPb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BQ9OGn9B, 0, m, &cVar_BQ9OGn9B_sendMessage);
}

void Heavy_prog::cReceive_cdwLBKQ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hVo5coaF_sendMessage(_c, 0, m);
  cMsg_kV4sV5ka_sendMessage(_c, 0, m);
  cMsg_ejXEBBBw_sendMessage(_c, 0, m);
  cMsg_oELgZ5Zh_sendMessage(_c, 0, m);
  cMsg_4GGFHtgZ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_6XAj1obJ, 0, m, &cVar_6XAj1obJ_sendMessage);
  cMsg_Pw7JTjRm_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_2dZfXi8m, 0, m, &cVar_2dZfXi8m_sendMessage);
  cSwitchcase_5GtPAsOr_onMessage(_c, NULL, 0, m, NULL);
  cMsg_UA6PDbFk_sendMessage(_c, 0, m);
  cMsg_2Idglbhe_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_gQExx4bt, 0, m, &cVar_gQExx4bt_sendMessage);
  cSwitchcase_TrgFOYMl_onMessage(_c, NULL, 0, m, NULL);
  cMsg_ZEvov2mY_sendMessage(_c, 0, m);
  cMsg_SV9fd9Av_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_0suCiwdB, 0, m, &cVar_0suCiwdB_sendMessage);
  cMsg_sx8qwf0O_sendMessage(_c, 0, m);
  cMsg_MpxQi47r_sendMessage(_c, 0, m);
  cMsg_H7PydLiK_sendMessage(_c, 0, m);
  cMsg_MSfFIUlq_sendMessage(_c, 0, m);
  cMsg_qMPh04nq_sendMessage(_c, 0, m);
  cMsg_SLG3ACCH_sendMessage(_c, 0, m);
  cMsg_FenE2xJN_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_mDnAClNK, 0, m, &cVar_mDnAClNK_sendMessage);
  cMsg_mVXjzZ72_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_FgfgFVLb, 0, m, &cVar_FgfgFVLb_sendMessage);
  cMsg_09VqSU6z_sendMessage(_c, 0, m);
  cMsg_nTAE9uEG_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Om9nZlGl, 0, m, &cVar_Om9nZlGl_sendMessage);
  cMsg_WvpZXHxt_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_vqx2fA6g, 0, m, &cTabhead_vqx2fA6g_sendMessage);
  cMsg_5d0MMeuL_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_yEiVzCbD, 0, m, &cVar_yEiVzCbD_sendMessage);
  cMsg_WG2LLPWl_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_Tfk7hPio, 0, m, &cTabhead_Tfk7hPio_sendMessage);
}

void Heavy_prog::cReceive_K2z89Su4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_xnzOEWvE, m);
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
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5, Bf6, Bf7, Bf8, Bf9, Bf10, Bf11, Bf12, Bf13, Bf14, Bf15, Bf16, Bf17;
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
    __hv_tabread_f(&sTabread_uo0OBiAM, VOf(Bf0));
    __hv_varread_i(&sVari_7vOtQ12w, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varwrite_i(&sVari_7vOtQ12w, VIi(Bi1));
    __hv_phasor_k_f(&sPhasor_HDkGQCpp, VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf1));
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf5), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf6), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf4), VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf1), VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_G7OMnlKW, VOf(Bf2));
    __hv_varread_f(&sVarf_JqlbM8WQ, VOf(Bf5));
    __hv_mul_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_9tQZsJvq, VOf(Bf1));
    __hv_rpole_f(&sRPole_ymGctuwH, VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf5), 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f);
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf3), VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_8BaqlGsf, VIf(Bf5));
    __hv_var_k_f(VOf(Bf5), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_phasor_k_f(&sPhasor_gldyenqC, VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf2));
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf6), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf4), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf1), VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf2), VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_8NVlX85H, VOf(Bf6));
    __hv_line_f(&sLine_FkLrNy0y, VOf(Bf2));
    __hv_phasor_f(&sPhasor_ubydacGm, VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf4), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf2));
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf7), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf8), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf1), VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf2), VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_XkmIvcAe, VOf(Bf7));
    __hv_mul_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf4), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_varread_f(&sVarf_Q5UqM26M, VOf(Bf2));
    __hv_varread_f(&sVarf_X8XdXNUC, VOf(Bf8));
    __hv_mul_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_wqIhnCAI, VOf(Bf2));
    __hv_rpole_f(&sRPole_94gjxaDI, VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_phasor_k_f(&sPhasor_tsuMVecm, VOf(Bf8));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf8), VIf(Bf1), VOf(Bf1));
    __hv_floor_f(VIf(Bf1), VOf(Bf9));
    __hv_sub_f(VIf(Bf1), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf9), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf9), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf1), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf9), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf9));
    __hv_mul_f(VIf(Bf1), VIf(Bf9), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf11), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf12), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf10), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf1), VIf(Bf12), VOf(Bf12));
    __hv_fma_f(VIf(Bf9), VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf11), 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f);
    __hv_var_k_f(VOf(Bf9), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_fms_f(VIf(Bf8), VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_floor_f(VIf(Bf9), VOf(Bf11));
    __hv_sub_f(VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf9), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_abs_f(VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf11), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf9), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf9), VOf(Bf11));
    __hv_mul_f(VIf(Bf9), VIf(Bf11), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf10), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf13), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf1), VIf(Bf13), VOf(Bf13));
    __hv_sub_f(VIf(Bf9), VIf(Bf13), VOf(Bf13));
    __hv_fma_f(VIf(Bf11), VIf(Bf10), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf10), 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f);
    __hv_div_f(VIf(Bf13), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf13), 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f);
    __hv_var_k_f(VOf(Bf11), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_fms_f(VIf(Bf8), VIf(Bf13), VIf(Bf11), VOf(Bf11));
    __hv_floor_f(VIf(Bf11), VOf(Bf13));
    __hv_sub_f(VIf(Bf11), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf11), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf13), VIf(Bf11), VOf(Bf11));
    __hv_abs_f(VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf13), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf11), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf11), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf13), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf11), VIf(Bf11), VOf(Bf13));
    __hv_mul_f(VIf(Bf11), VIf(Bf13), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf9), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf1), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf8), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf11), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf13), VIf(Bf9), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf9), 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f);
    __hv_div_f(VIf(Bf1), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_ZdnDhfhT, VOf(Bf10));
    __hv_varread_f(&sVarf_YVmmOr0h, VOf(Bf1));
    __hv_mul_f(VIf(Bf10), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_bP1JzMf8, VOf(Bf10));
    __hv_rpole_f(&sRPole_EV713p3j, VIf(Bf1), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf9), 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f, 7.0f);
    __hv_div_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf2), VIf(Bf12), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_Cf5Th4BF, VOf(Bf12));
    __hv_mul_f(VIf(Bf9), VIf(Bf12), VOf(Bf12));
    __hv_line_f(&sLine_lvO83xh3, VOf(Bf9));
    __hv_mul_f(VIf(Bf12), VIf(Bf9), VOf(Bf12));
    __hv_var_k_f(VOf(Bf2), 0.707946f, 0.707946f, 0.707946f, 0.707946f, 0.707946f, 0.707946f, 0.707946f, 0.707946f);
    __hv_mul_f(VIf(Bf12), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf10), 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f, 1000.0f);
    __hv_line_f(&sLine_wjVHc5oo, VOf(Bf1));
    __hv_add_f(VIf(Bf10), VIf(Bf1), VOf(Bf10));
    __hv_var_k_f(VOf(Bf13), 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f);
    __hv_var_k_f(VOf(Bf11), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf8), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf14), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_max_f(VIf(Bf13), VIf(Bf14), VOf(Bf14));
    __hv_div_f(VIf(Bf8), VIf(Bf14), VOf(Bf14));
    __hv_var_k_f(VOf(Bf8), 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f);
    __hv_min_f(VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf10), 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f);
    __hv_max_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_pQlbcK5L, VOf(Bf8));
    __hv_div_f(VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf10), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_floor_f(VIf(Bf10), VOf(Bf13));
    __hv_sub_f(VIf(Bf10), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf10), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf13), VIf(Bf10), VOf(Bf10));
    __hv_abs_f(VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf13), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf10), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf10), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf13), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf10), VOf(Bf13));
    __hv_mul_f(VIf(Bf10), VIf(Bf13), VOf(Bf15));
    __hv_mul_f(VIf(Bf15), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf16), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf17), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf15), VIf(Bf17), VOf(Bf17));
    __hv_sub_f(VIf(Bf10), VIf(Bf17), VOf(Bf17));
    __hv_fma_f(VIf(Bf13), VIf(Bf16), VIf(Bf17), VOf(Bf17));
    __hv_mul_f(VIf(Bf14), VIf(Bf17), VOf(Bf17));
    __hv_var_k_f(VOf(Bf14), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf17), VIf(Bf14), VOf(Bf14));
    __hv_var_k_f(VOf(Bf17), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf14), VIf(Bf17), VOf(Bf17));
    __hv_div_f(VIf(Bf11), VIf(Bf17), VOf(Bf17));
    __hv_var_k_f(VOf(Bf11), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_floor_f(VIf(Bf8), VOf(Bf16));
    __hv_sub_f(VIf(Bf8), VIf(Bf16), VOf(Bf16));
    __hv_var_k_f(VOf(Bf8), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf16), VIf(Bf8), VOf(Bf8));
    __hv_abs_f(VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf16), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf8), VIf(Bf16), VOf(Bf16));
    __hv_var_k_f(VOf(Bf8), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf16), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf8), VOf(Bf16));
    __hv_mul_f(VIf(Bf8), VIf(Bf16), VOf(Bf13));
    __hv_mul_f(VIf(Bf13), VIf(Bf16), VOf(Bf16));
    __hv_var_k_f(VOf(Bf10), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf15), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf13), VIf(Bf15), VOf(Bf15));
    __hv_sub_f(VIf(Bf8), VIf(Bf15), VOf(Bf15));
    __hv_fma_f(VIf(Bf16), VIf(Bf10), VIf(Bf15), VOf(Bf15));
    __hv_sub_f(VIf(Bf11), VIf(Bf15), VOf(Bf11));
    __hv_var_k_f(VOf(Bf10), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf17), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf11), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf11), VIf(Bf15), VOf(Bf11));
    __hv_mul_f(VIf(Bf17), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf16), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf16), VIf(Bf15), VOf(Bf16));
    __hv_var_k_f(VOf(Bf8), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf16), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf17), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf16), -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f);
    __hv_mul_f(VIf(Bf15), VIf(Bf16), VOf(Bf16));
    __hv_mul_f(VIf(Bf17), VIf(Bf16), VOf(Bf16));
    __hv_var_k_f(VOf(Bf15), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf15), VIf(Bf14), VOf(Bf14));
    __hv_mul_f(VIf(Bf17), VIf(Bf14), VOf(Bf14));
    __hv_biquad_f(&sBiquad_s_54xTfrk2, VIf(Bf2), VIf(Bf10), VIf(Bf11), VIf(Bf8), VIf(Bf16), VIf(Bf14), VOf(Bf14));
    __hv_var_k_f(VOf(Bf16), 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f);
    __hv_mul_f(VIf(Bf14), VIf(Bf16), VOf(Bf16));
    __hv_var_k_f(VOf(Bf14), 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f);
    __hv_min_f(VIf(Bf16), VIf(Bf14), VOf(Bf14));
    __hv_var_k_f(VOf(Bf16), -3.0f, -3.0f, -3.0f, -3.0f, -3.0f, -3.0f, -3.0f, -3.0f);
    __hv_max_f(VIf(Bf14), VIf(Bf16), VOf(Bf16));
    __hv_mul_f(VIf(Bf16), VIf(Bf16), VOf(Bf14));
    __hv_var_k_f(VOf(Bf8), 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f);
    __hv_add_f(VIf(Bf14), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf11), 9.0f, 9.0f, 9.0f, 9.0f, 9.0f, 9.0f, 9.0f, 9.0f);
    __hv_var_k_f(VOf(Bf10), 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f, 27.0f);
    __hv_fma_f(VIf(Bf14), VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_div_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf16), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf16), 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f);
    __hv_mul_f(VIf(Bf10), VIf(Bf16), VOf(Bf10));
    __hv_pow_f(VIf(Bf4), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf4), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf10), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf10), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf8), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_pow_f(VIf(Bf8), VIf(Bf16), VOf(Bf16));
    __hv_div_f(VIf(Bf10), VIf(Bf16), VOf(Bf16));
    __hv_mul_f(VIf(Bf4), VIf(Bf16), VOf(Bf16));
    __hv_var_k_f(VOf(Bf4), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf10), 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f);
    __hv_pow_f(VIf(Bf16), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_xnzOEWvE, VOf(Bf8));
    __hv_mul_f(VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf10), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf16), VIf(Bf4), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_3SJcfwyu, VOf(Bf4));
    __hv_add_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f, 0.404061f);
    __hv_var_k_f(VOf(Bf16), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf8), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_var_k_f(VOf(Bf11), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_min_f(VIf(Bf1), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf1), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_max_f(VIf(Bf11), VIf(Bf1), VOf(Bf1));
    __hv_div_f(VIf(Bf8), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf8), 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f, 20000.0f);
    __hv_min_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf4), 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f);
    __hv_max_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_2riROFOT, VOf(Bf8));
    __hv_div_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_floor_f(VIf(Bf4), VOf(Bf11));
    __hv_sub_f(VIf(Bf4), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf11), VIf(Bf4), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf11), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf4), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf11), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf11));
    __hv_mul_f(VIf(Bf4), VIf(Bf11), VOf(Bf14));
    __hv_mul_f(VIf(Bf14), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf2), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf17), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf14), VIf(Bf17), VOf(Bf17));
    __hv_sub_f(VIf(Bf4), VIf(Bf17), VOf(Bf17));
    __hv_fma_f(VIf(Bf11), VIf(Bf2), VIf(Bf17), VOf(Bf17));
    __hv_mul_f(VIf(Bf1), VIf(Bf17), VOf(Bf17));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf17), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf17), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf1), VIf(Bf17), VOf(Bf17));
    __hv_div_f(VIf(Bf16), VIf(Bf17), VOf(Bf17));
    __hv_floor_f(VIf(Bf8), VOf(Bf16));
    __hv_sub_f(VIf(Bf8), VIf(Bf16), VOf(Bf16));
    __hv_var_k_f(VOf(Bf8), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf16), VIf(Bf8), VOf(Bf8));
    __hv_abs_f(VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf16), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf8), VIf(Bf16), VOf(Bf16));
    __hv_var_k_f(VOf(Bf8), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf16), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf8), VOf(Bf16));
    __hv_mul_f(VIf(Bf8), VIf(Bf16), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf16), VOf(Bf16));
    __hv_var_k_f(VOf(Bf11), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf4), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf16), VIf(Bf11), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf11), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf4), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf16), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf11), VIf(Bf16), VOf(Bf16));
    __hv_mul_f(VIf(Bf17), VIf(Bf16), VOf(Bf16));
    __hv_var_k_f(VOf(Bf11), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf4), VIf(Bf11), VOf(Bf11));
    __hv_neg_f(VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf17), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf8), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf17), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf8), -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f, -2.0f);
    __hv_mul_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf17), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf4), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf17), VIf(Bf1), VOf(Bf1));
    __hv_biquad_f(&sBiquad_s_Afz4mgme, VIf(Bf10), VIf(Bf16), VIf(Bf11), VIf(Bf2), VIf(Bf8), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf1), VIf(Bf9), VIf(Bf12), VOf(Bf12));
    __hv_add_f(VIf(Bf7), VIf(Bf12), VOf(Bf9));
    __hv_phasor_k_f(&sPhasor_NbBTov1k, VOf(Bf1));
    __hv_var_k_f(VOf(Bf8), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf8), VOf(Bf8));
    __hv_abs_f(VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf8), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf8), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf1), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf8), VOf(Bf1));
    __hv_mul_f(VIf(Bf8), VIf(Bf1), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf11), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf16), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf2), VIf(Bf16), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf1), VIf(Bf11), VIf(Bf8), VOf(Bf8));
    __hv_phasor_k_f(&sPhasor_PIjhwkLE, VOf(Bf11));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf11), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf11), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf1), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf11), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf11));
    __hv_mul_f(VIf(Bf1), VIf(Bf11), VOf(Bf16));
    __hv_mul_f(VIf(Bf16), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf2), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf10), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf16), VIf(Bf10), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf11), VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf8), VIf(Bf1), VOf(Bf2));
    __hv_var_k_f(VOf(Bf11), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_mul_f(VIf(Bf8), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_tc4YMTy8, VOf(Bf8));
    __hv_varread_f(&sVarf_KgMG07PG, VOf(Bf10));
    __hv_mul_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf1), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf2), VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_YWMRTbAs, VOf(Bf11));
    __hv_varread_f(&sVarf_iehjSlKL, VOf(Bf2));
    __hv_fma_f(VIf(Bf10), VIf(Bf11), VIf(Bf2), VOf(Bf2));
    __hv_phasor_f(&sPhasor_BWCUjx9q, VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf11), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_abs_f(VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf11), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf11), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf11), VIf(Bf11), VOf(Bf2));
    __hv_mul_f(VIf(Bf11), VIf(Bf2), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf16), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf10), VIf(Bf16), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf2), VIf(Bf1), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf8), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf11), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf8), VIf(Bf12), VOf(Bf11));
    __hv_line_f(&sLine_dOa8UFWq, VOf(Bf1));
    __hv_tabhead_f(&sTabhead_FRYqmwTo, VOf(Bf2));
    __hv_var_k_f_r(VOf(Bf16), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf2), VIf(Bf16), VOf(Bf16));
    __hv_varread_f(&sVarf_ovUceuj6, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_o5sdhfxt, VOf(Bf1));
    __hv_min_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_zero_f(VOf(Bf2));
    __hv_max_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf16), VIf(Bf2), VOf(Bf2));
    __hv_floor_f(VIf(Bf2), VOf(Bf16));
    __hv_varread_f(&sVarf_toF4PZT7, VOf(Bf1));
    __hv_zero_f(VOf(Bf10));
    __hv_lt_f(VIf(Bf16), VIf(Bf10), VOf(Bf10));
    __hv_and_f(VIf(Bf1), VIf(Bf10), VOf(Bf10));
    __hv_add_f(VIf(Bf16), VIf(Bf10), VOf(Bf10));
    __hv_cast_fi(VIf(Bf10), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_Ox1ck9vq, VIi(Bi0), VOf(Bf10));
    __hv_tabread_if(&sTabread_zJsYPHiK, VIi(Bi1), VOf(Bf1));
    __hv_sub_f(VIf(Bf10), VIf(Bf1), VOf(Bf10));
    __hv_sub_f(VIf(Bf2), VIf(Bf16), VOf(Bf16));
    __hv_fma_f(VIf(Bf10), VIf(Bf16), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_DocSZ9mM, VOf(Bf16));
    __hv_fma_f(VIf(Bf1), VIf(Bf16), VIf(Bf11), VOf(Bf16));
    __hv_line_f(&sLine_Jbj7q6P5, VOf(Bf1));
    __hv_tabhead_f(&sTabhead_4zAMiQln, VOf(Bf10));
    __hv_var_k_f_r(VOf(Bf2), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf10), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_aCEWg1ui, VOf(Bf10));
    __hv_mul_f(VIf(Bf1), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_A1pCm424, VOf(Bf1));
    __hv_min_f(VIf(Bf10), VIf(Bf1), VOf(Bf1));
    __hv_zero_f(VOf(Bf10));
    __hv_max_f(VIf(Bf1), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_floor_f(VIf(Bf10), VOf(Bf2));
    __hv_varread_f(&sVarf_TzyroLZG, VOf(Bf1));
    __hv_zero_f(VOf(Bf17));
    __hv_lt_f(VIf(Bf2), VIf(Bf17), VOf(Bf17));
    __hv_and_f(VIf(Bf1), VIf(Bf17), VOf(Bf17));
    __hv_add_f(VIf(Bf2), VIf(Bf17), VOf(Bf17));
    __hv_cast_fi(VIf(Bf17), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_VgyvTCOg, VIi(Bi0), VOf(Bf17));
    __hv_tabread_if(&sTabread_kgkBdsw2, VIi(Bi1), VOf(Bf1));
    __hv_sub_f(VIf(Bf17), VIf(Bf1), VOf(Bf17));
    __hv_sub_f(VIf(Bf10), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf17), VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_nV1G1Hp5, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf16), VIf(Bf2), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_t8PP8ETu, VIf(Bf11));
    __hv_tabwrite_f(&sTabwrite_JLley0Oi, VIf(Bf2));
    __hv_var_k_f(VOf(Bf11), 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f);
    __hv_mul_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf9), VIf(Bf11), VOf(Bf9));
    __hv_fma_f(VIf(Bf3), VIf(Bf6), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf0), VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf5), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_mul_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf5), VIf(O1), VOf(O1));
    __hv_tabread_f(&sTabread_5xuekenN, VOf(Bf5));
    __hv_varread_i(&sVari_S7fm1ihi, VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_cast_if(VIi(Bi0), VOf(Bf9));
    __hv_var_k_f(VOf(Bf0), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf9), VIf(Bf0), VOf(Bf0));
    __hv_varwrite_i(&sVari_S7fm1ihi, VIi(Bi0));
    __hv_phasor_k_f(&sPhasor_pRKaKxDF, VOf(Bf9));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_abs_f(VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf9), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf6), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf6), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf6), VOf(Bf9));
    __hv_mul_f(VIf(Bf6), VIf(Bf9), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf2), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf16), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf3), VIf(Bf16), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf9), VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_D18u364V, VOf(Bf0));
    __hv_varread_f(&sVarf_13SyNhJe, VOf(Bf2));
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_aT4V8xSI, VOf(Bf9));
    __hv_rpole_f(&sRPole_YHgQ23dg, VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf2), 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f);
    __hv_mul_f(VIf(Bf9), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf6), VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_2Ue0SpcF, VIf(Bf2));
    __hv_var_k_f(VOf(Bf2), 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f);
    __hv_phasor_k_f(&sPhasor_n4zIwrke, VOf(Bf0));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_abs_f(VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf6), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf6), VOf(Bf0));
    __hv_mul_f(VIf(Bf6), VIf(Bf0), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf16), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf3), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf9), VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf0), VIf(Bf16), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_pBpPjVUC, VOf(Bf16));
    __hv_add_f(VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf7), VIf(Bf12), VOf(Bf12));
    __hv_add_f(VIf(Bf12), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf6), VIf(Bf16), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf5), VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf2), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_mul_f(VIf(Bf11), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf2), VIf(O0), VOf(O0));

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
