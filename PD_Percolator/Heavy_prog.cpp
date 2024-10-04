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
 * Table Data
 */

float hTable_pyMly1PH_data[256] = {0.206667f, 0.216667f, 0.22f, 0.22f, 0.226667f, 0.23f, 0.233333f, 0.233333f, 0.236667f, 0.243333f, 0.243333f, 0.243333f, 0.246667f, 0.25f, 0.252222f, 0.254444f, 0.256667f, 0.26f, 0.263333f, 0.266667f, 0.273333f, 0.28f, 0.286667f, 0.283333f, 0.3f, 0.306667f, 0.313333f, 0.32f, 0.326667f, 0.34f, 0.348333f, 0.356667f, 0.366667f, 0.373333f, 0.38f, 0.386667f, 0.4f, 0.406667f, 0.413333f, 0.42f, 0.43f, 0.436667f, 0.438333f, 0.44f, 0.443333f, 0.446667f, 0.448333f, 0.45f, 0.453333f, 0.453333f, 0.453333f, 0.453333f, 0.453333f, 0.453333f, 0.453333f, 0.453333f, 0.453333f, 0.453333f, 0.453333f, 0.453333f, 0.453333f, 0.453333f, 0.453333f, 0.453333f, 0.452778f, 0.452222f, 0.451667f, 0.451111f, 0.450556f, 0.45f, 0.448889f, 0.447778f, 0.446667f, 0.445556f, 0.444444f, 0.443333f, 0.442f, 0.440667f, 0.439333f, 0.438f, 0.436667f, 0.435333f, 0.434f, 0.432667f, 0.431333f, 0.43f, 0.4275f, 0.425f, 0.4225f, 0.42f, 0.417778f, 0.415556f, 0.413333f, 0.41f, 0.406667f, 0.403333f, 0.4f, 0.396667f, 0.39f, 0.38f, 0.376667f, 0.37f, 0.366667f, 0.363333f, 0.356667f, 0.353333f, 0.35f, 0.346667f, 0.34f, 0.336667f, 0.333333f, 0.326667f, 0.323333f, 0.316667f, 0.313333f, 0.311111f, 0.308889f, 0.306667f, 0.303333f, 0.302222f, 0.301111f, 0.3f, 0.296667f, 0.293334f, 0.292222f, 0.291111f, 0.29f, 0.288333f, 0.286667f, 0.285f, 0.283333f, 0.281667f, 0.28f, 0.278333f, 0.276667f, 0.275f, 0.273334f, 0.272222f, 0.271111f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.27f, 0.271667f, 0.273333f, 0.276667f, 0.28f, 0.281111f, 0.282222f, 0.283333f, 0.283333f, 0.283333f, 0.283333f, 0.285f, 0.286667f, 0.288333f, 0.29f, 0.291667f, 0.293333f, 0.295f, 0.296667f, 0.303333f, 0.303333f, 0.305f, 0.31f, 0.31f, 0.311667f, 0.313333f, 0.313333f, 0.313333f, 0.315f, 0.316667f, 0.316667f, 0.316667f, 0.316667f, 0.316667f, 0.313333f, 0.31f, 0.306667f, 0.301667f, 0.296667f, 0.293333f, 0.286667f, 0.27f, 0.266667f, 0.246667f, 0.236667f, 0.226667f, 0.213334f, 0.203334f, 0.196667f, 0.183334f, 0.183334f, 0.17f, 0.163334f, 0.153334f, 0.146667f, 0.133334f, 0.313333f, 0.0611115f, 0.0588893f, 0.0566671f, 0.0433338f, 0.0400004f};



/*
 * Class Functions
 */

Heavy_prog::Heavy_prog(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sPhasor_k_init(&sPhasor_p5Tgl76A, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_lE765kvS);
  numBytes += sPhasor_init(&sPhasor_zJriyjmR, sampleRate);
  numBytes += sLine_init(&sLine_h7mjnjXM);
  numBytes += sTabread_init(&sTabread_LfyWcIfJ, &hTable_pyMly1PH, false);
  numBytes += sPhasor_k_init(&sPhasor_3kM10C70, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_pEc1mTv2, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_Z4ZJAREW);
  numBytes += sPhasor_init(&sPhasor_2bugMkWS, sampleRate);
  numBytes += sTabread_init(&sTabread_U4T6nfp9, &hTable_4a2NYJ2e, true);
  numBytes += sPhasor_k_init(&sPhasor_6k4QUyC9, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_UzsHDhYq);
  numBytes += sRPole_init(&sRPole_YqSwF43r);
  numBytes += sTabwrite_init(&sTabwrite_Y6fiqUTx, &hTable_4a2NYJ2e);
  numBytes += sBiquad_k_init(&sBiquad_k_zEAHz4hb, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sLine_init(&sLine_xTWoxp5n);
  numBytes += sTabhead_init(&sTabhead_CaWg4r82, &hTable_Jn8DpTrG);
  numBytes += sTabread_init(&sTabread_27UM8P4d, &hTable_Jn8DpTrG, false);
  numBytes += sTabread_init(&sTabread_HdxpFTTk, &hTable_Jn8DpTrG, false);
  numBytes += sLine_init(&sLine_i9H0kCAo);
  numBytes += sLine_init(&sLine_mybgC5bn);
  numBytes += sTabhead_init(&sTabhead_TvPkfyi4, &hTable_Ub9gekAh);
  numBytes += sTabread_init(&sTabread_d1q6e24C, &hTable_Ub9gekAh, false);
  numBytes += sTabread_init(&sTabread_JpDIdtKs, &hTable_Ub9gekAh, false);
  numBytes += sLine_init(&sLine_yikKq08A);
  numBytes += sTabwrite_init(&sTabwrite_Qs5PzVhA, &hTable_Jn8DpTrG);
  numBytes += sTabwrite_init(&sTabwrite_TbVvJ6kn, &hTable_Ub9gekAh);
  numBytes += sPhasor_k_init(&sPhasor_JjcpztXJ, 0.0f, sampleRate);
  numBytes += sTabread_init(&sTabread_YursPVP1, &hTable_yoANTlmv, true);
  numBytes += sPhasor_k_init(&sPhasor_3aKv930E, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_vzCVj8E3);
  numBytes += sRPole_init(&sRPole_zzpzvYdp);
  numBytes += sTabwrite_init(&sTabwrite_YS7RaK5T, &hTable_yoANTlmv);
  numBytes += cBinop_init(&cBinop_NvNZfntG, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_W51xktNs, 791960802);
  numBytes += cSlice_init(&cSlice_Q8uSaD8A, 1, 1);
  numBytes += sVari_init(&sVari_mdF9j3v0, 0, 0, false);
  numBytes += cTabhead_init(&cTabhead_P3uNalpp, &hTable_yoANTlmv);
  numBytes += cVar_init_s(&cVar_wHkXSSjw, "del-1002-buf");
  numBytes += cDelay_init(this, &cDelay_4l4zmC3Q, 100.0f);
  numBytes += cDelay_init(this, &cDelay_sF3Wu5XU, 0.0f);
  numBytes += cBinop_init(&cBinop_NSm8z2uJ, 100.0f); // __mul
  numBytes += cBinop_init(&cBinop_Lyvjzkht, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_cqjWYeXD, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_LVqOJBaO, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_YtboBCav, 0.0f);
  numBytes += cDelay_init(this, &cDelay_cX3CSIKX, 0.0f);
  numBytes += hTable_init(&hTable_yoANTlmv, 256);
  numBytes += cVar_init_f(&cVar_Zmfn4Thx, 22050.0f);
  numBytes += cBinop_init(&cBinop_LAEf7zJx, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_C2qccrfG, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_SLBa4PGw, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_wXThpdCs, 0.0f); // __div
  numBytes += cPack_init(&cPack_dWRi7L0D, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_bpLLwQyM, 4, 1);
  numBytes += cSlice_init(&cSlice_y3Ks91TE, 3, 1);
  numBytes += cSlice_init(&cSlice_gIjEhzY7, 2, 1);
  numBytes += cSlice_init(&cSlice_CegCF8J2, 1, 1);
  numBytes += cSlice_init(&cSlice_emS35dtd, 0, 1);
  numBytes += sVarf_init(&sVarf_g6rj8uKb, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_4uTycqq8, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_vqoP0jaB, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_AFgoUlSM, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_QFYgMNCc, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_PDhm312h, 2, 0.0f, 0.0f);
  numBytes += cVar_init_s(&cVar_MY5GRjVV, "del-1033-inputdelay");
  numBytes += sVarf_init(&sVarf_PPxAvq4z, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_J3cCL6hE, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_D86feJP3, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_TQJPoo9N, "del-1033-outputdelay");
  numBytes += sVarf_init(&sVarf_NZR5JOXk, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_apijj2Kq, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_9nTIKcxH, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_V4Dlnmhz, 0.0f);
  numBytes += cDelay_init(this, &cDelay_72ZSIW28, 0.0f);
  numBytes += hTable_init(&hTable_Jn8DpTrG, 256);
  numBytes += cDelay_init(this, &cDelay_RRCmZ1F3, 0.0f);
  numBytes += cDelay_init(this, &cDelay_jwPqNSyk, 0.0f);
  numBytes += hTable_init(&hTable_Ub9gekAh, 256);
  numBytes += cVar_init_f(&cVar_6F6hBUiI, 0.0f);
  numBytes += cRandom_init(&cRandom_RXwNOozZ, 340869142);
  numBytes += cSlice_init(&cSlice_YXtVZYvx, 1, 1);
  numBytes += cVar_init_f(&cVar_g0Qqd213, 0.0f);
  numBytes += cDelay_init(this, &cDelay_GcCX8z8g, 600.0f);
  numBytes += cBinop_init(&cBinop_Rc5U6NxU, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_3NNmYuvJ, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_NElCpblh, -1510917684);
  numBytes += cSlice_init(&cSlice_Et7AGMDl, 1, 1);
  numBytes += sVari_init(&sVari_w70QM8dB, 0, 0, false);
  numBytes += cTabhead_init(&cTabhead_OvZQC9Gi, &hTable_4a2NYJ2e);
  numBytes += cVar_init_s(&cVar_gzCG7ylf, "del-1068-buf");
  numBytes += cDelay_init(this, &cDelay_WB5yLmHx, 100.0f);
  numBytes += cDelay_init(this, &cDelay_m4Nlcez9, 0.0f);
  numBytes += cBinop_init(&cBinop_p55R9fuk, 100.0f); // __mul
  numBytes += cBinop_init(&cBinop_bzBbaaTf, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_39iW8Ohz, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_NXypHPyy, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_3bAGStkX, 0.0f);
  numBytes += cDelay_init(this, &cDelay_w5Z9lhD8, 0.0f);
  numBytes += hTable_init(&hTable_4a2NYJ2e, 256);
  numBytes += cVar_init_f(&cVar_yP0Y8xnG, 22050.0f);
  numBytes += cBinop_init(&cBinop_jP0sx8mx, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_isWowbsF, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_NdOw1akm, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_JvvkkyKh, 0.0f); // __div
  numBytes += cRandom_init(&cRandom_A8QSVJi0, -1481937648);
  numBytes += cSlice_init(&cSlice_QlD9hx3A, 1, 1);
  numBytes += sVari_init(&sVari_xUTVezR4, 0, 0, false);
  numBytes += cVar_init_f(&cVar_aJyQk1Y4, 22050.0f);
  numBytes += cVar_init_f(&cVar_UG8M8hdq, 1.0f);
  numBytes += cBinop_init(&cBinop_l7Dlf2Du, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_fpJtpY2y, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_6vrHt5zh, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_XwZuxGJC, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_thMbhhEQ, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_sKRKJ2pi, 0.0f); // __mul
  numBytes += hTable_initWithData(&hTable_pyMly1PH, 256, hTable_pyMly1PH_data);
  numBytes += cVar_init_s(&cVar_Nj3mz8b1, "shape");
  numBytes += cSlice_init(&cSlice_L9VIqt17, 1, 1);
  numBytes += sVarf_init(&sVarf_BdD58aQC, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_u4enbaNe, 0.0f);
  numBytes += cDelay_init(this, &cDelay_zp0jocVa, 200.0f);
  numBytes += cBinop_init(&cBinop_zum3vKax, 0.0f); // __mul
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_prog::~Heavy_prog() {
  hTable_free(&hTable_yoANTlmv);
  cPack_free(&cPack_dWRi7L0D);
  cPack_free(&cPack_QFYgMNCc);
  cPack_free(&cPack_PDhm312h);
  hTable_free(&hTable_Jn8DpTrG);
  hTable_free(&hTable_Ub9gekAh);
  hTable_free(&hTable_4a2NYJ2e);
  hTable_free(&hTable_pyMly1PH);
}

HvTable *Heavy_prog::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0xD8E4DE0C: return &hTable_yoANTlmv; // del-1002-buf
    case 0xE8456729: return &hTable_Jn8DpTrG; // del-1033-inputdelay
    case 0xA31B0EC2: return &hTable_Ub9gekAh; // del-1033-outputdelay
    case 0x608DF8E7: return &hTable_4a2NYJ2e; // del-1068-buf
    case 0xB063C1EC: return &hTable_pyMly1PH; // shape
    default: return nullptr;
  }
}

void Heavy_prog::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_dPQvq6XS_sendMessage);
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


void Heavy_prog::cBinop_AuJw2oek_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QchiwOHm_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EiG8OnQ3_sendMessage);
}

void Heavy_prog::cBinop_019JhJyD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_3P5Y59Ys_sendMessage);
}

void Heavy_prog::cBinop_3P5Y59Ys_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NvNZfntG, HV_BINOP_POW, 1, m, &cBinop_NvNZfntG_sendMessage);
  cMsg_1x6Zn2CS_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_NvNZfntG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_AuJw2oek_sendMessage);
}

void Heavy_prog::cMsg_1x6Zn2CS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_NvNZfntG, HV_BINOP_POW, 0, m, &cBinop_NvNZfntG_sendMessage);
}

void Heavy_prog::cSwitchcase_5xQo5FrO_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Q8uSaD8A, 0, m, &cSlice_Q8uSaD8A_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_W51xktNs, 0, m, &cRandom_W51xktNs_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_JMeov7LZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_QU3JNlYh_sendMessage);
}

void Heavy_prog::cUnop_QU3JNlYh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Kqcg1tsA_sendMessage(_c, 0, m);
}

void Heavy_prog::cRandom_W51xktNs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_JMeov7LZ_sendMessage);
}

void Heavy_prog::cSlice_Q8uSaD8A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_W51xktNs, 1, m, &cRandom_W51xktNs_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cMsg_Kqcg1tsA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_mdF9j3v0, m);
}

void Heavy_prog::cTabhead_P3uNalpp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Lyvjzkht, HV_BINOP_SUBTRACT, 0, m, &cBinop_Lyvjzkht_sendMessage);
}

void Heavy_prog::cMsg_lZk3h5U7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_j9PjxO4V_sendMessage);
}

void Heavy_prog::cSystem_j9PjxO4V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_KLL4hGQm_sendMessage);
}

void Heavy_prog::cVar_wHkXSSjw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VljxZcGX_sendMessage(_c, 0, m);
}

void Heavy_prog::cDelay_4l4zmC3Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_4l4zmC3Q, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sF3Wu5XU, 0, m, &cDelay_sF3Wu5XU_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_YursPVP1, 0, m, &sTabread_YursPVP1_sendMessage);
}

void Heavy_prog::cDelay_sF3Wu5XU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_sF3Wu5XU, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_YursPVP1, 0, m, &sTabread_YursPVP1_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sF3Wu5XU, 0, m, &cDelay_sF3Wu5XU_sendMessage);
}

void Heavy_prog::sTabread_YursPVP1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_LVqOJBaO, HV_BINOP_SUBTRACT, 0, m, &cBinop_LVqOJBaO_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_NSm8z2uJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cqjWYeXD, HV_BINOP_MAX, 0, m, &cBinop_cqjWYeXD_sendMessage);
}

void Heavy_prog::cBinop_KLL4hGQm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NSm8z2uJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_NSm8z2uJ_sendMessage);
}

void Heavy_prog::cBinop_Lyvjzkht_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wasloP4a_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_YursPVP1, 0, m, &sTabread_YursPVP1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YnBH7GpI_sendMessage);
}

void Heavy_prog::cSystem_1BhTkVWj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LVqOJBaO, HV_BINOP_SUBTRACT, 1, m, &cBinop_LVqOJBaO_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sF3Wu5XU, 2, m, &cDelay_sF3Wu5XU_sendMessage);
}

void Heavy_prog::cMsg_VljxZcGX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1BhTkVWj_sendMessage);
}

void Heavy_prog::cMsg_wasloP4a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_4l4zmC3Q, 0, m, &cDelay_4l4zmC3Q_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sF3Wu5XU, 0, m, &cDelay_sF3Wu5XU_sendMessage);
}

void Heavy_prog::cMsg_o6175oon_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_cqjWYeXD, HV_BINOP_MAX, 1, m, &cBinop_cqjWYeXD_sendMessage);
}

void Heavy_prog::cBinop_cqjWYeXD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Lyvjzkht, HV_BINOP_SUBTRACT, 1, m, &cBinop_Lyvjzkht_sendMessage);
}

void Heavy_prog::cCast_YnBH7GpI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_4l4zmC3Q, 0, m, &cDelay_4l4zmC3Q_sendMessage);
}

void Heavy_prog::cBinop_Jztpd3N3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_4l4zmC3Q, 2, m, &cDelay_4l4zmC3Q_sendMessage);
}

void Heavy_prog::cBinop_LVqOJBaO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Jztpd3N3_sendMessage);
}

void Heavy_prog::cCast_Wy3PeJ6T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wHkXSSjw, 0, m, &cVar_wHkXSSjw_sendMessage);
  cMsg_lZk3h5U7_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_P3uNalpp, 0, m, &cTabhead_P3uNalpp_sendMessage);
}

void Heavy_prog::cMsg_4f0uI6ns_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_FDwRtfSh_sendMessage);
}

void Heavy_prog::cSystem_FDwRtfSh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_gLUsWXVu_sendMessage);
}

void Heavy_prog::cDelay_YtboBCav_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_YtboBCav, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cX3CSIKX, 0, m, &cDelay_cX3CSIKX_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_YtboBCav, 0, m, &cDelay_YtboBCav_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_YS7RaK5T, 1, m, NULL);
}

void Heavy_prog::cDelay_cX3CSIKX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_cX3CSIKX, m);
  cMsg_NLJQ1Lio_sendMessage(_c, 0, m);
}

void Heavy_prog::cSwitchcase_1xC22qgw_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_OPQEqCc7_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cBinop_1QSrfW0l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AJMYLtbH_sendMessage(_c, 0, m);
}

void Heavy_prog::hTable_yoANTlmv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CqjvXgZ4_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_YtboBCav, 2, m, &cDelay_YtboBCav_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_J7sSopu2_sendMessage);
}

void Heavy_prog::cMsg_AJMYLtbH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_yoANTlmv, 0, m, &hTable_yoANTlmv_sendMessage);
}

void Heavy_prog::cBinop_gLUsWXVu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_1QSrfW0l_sendMessage);
}

void Heavy_prog::cMsg_NLJQ1Lio_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_yoANTlmv, 0, m, &hTable_yoANTlmv_sendMessage);
}

void Heavy_prog::cCast_J7sSopu2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_YtboBCav, 0, m, &cDelay_YtboBCav_sendMessage);
}

void Heavy_prog::cMsg_CqjvXgZ4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_cX3CSIKX, 2, m, &cDelay_cX3CSIKX_sendMessage);
}

void Heavy_prog::cMsg_OPQEqCc7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_YS7RaK5T, 1, m, NULL);
}

void Heavy_prog::cVar_Zmfn4Thx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LAEf7zJx, HV_BINOP_MULTIPLY, 0, m, &cBinop_LAEf7zJx_sendMessage);
}

void Heavy_prog::cMsg_eHgT5O95_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JL1wIO74_sendMessage);
}

void Heavy_prog::cSystem_JL1wIO74_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RUmvZ4f1_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_LAEf7zJx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_rS6dJH0M_sendMessage);
}

void Heavy_prog::cBinop_WEf61pOO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LAEf7zJx, HV_BINOP_MULTIPLY, 1, m, &cBinop_LAEf7zJx_sendMessage);
}

void Heavy_prog::cMsg_RUmvZ4f1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_WEf61pOO_sendMessage);
}

void Heavy_prog::cBinop_rS6dJH0M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_yiWFOsJ7_sendMessage);
}

void Heavy_prog::cBinop_yiWFOsJ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_xpYxlibK_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_SLBa4PGw, m);
}

void Heavy_prog::cBinop_xpYxlibK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_C2qccrfG, m);
}

void Heavy_prog::cBinop_wXThpdCs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NSm8z2uJ, HV_BINOP_MULTIPLY, 1, m, &cBinop_NSm8z2uJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Wy3PeJ6T_sendMessage);
}

void Heavy_prog::cCast_QchiwOHm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wXThpdCs, HV_BINOP_DIVIDE, 1, m, &cBinop_wXThpdCs_sendMessage);
}

void Heavy_prog::cCast_EiG8OnQ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jiny781H_sendMessage(_c, 0, m);
  cMsg_w50XZCAe_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_w50XZCAe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_vzCVj8E3, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_vzCVj8E3, 0, m, NULL);
}

void Heavy_prog::cBinop_6gFJRQG3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_019JhJyD_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 50.0f, 0, m, &cBinop_6ibDgD3I_sendMessage);
}

void Heavy_prog::cMsg_jiny781H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_wXThpdCs, HV_BINOP_DIVIDE, 0, m, &cBinop_wXThpdCs_sendMessage);
}

void Heavy_prog::cBinop_6ibDgD3I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_3aKv930E, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Zmfn4Thx, 0, m, &cVar_Zmfn4Thx_sendMessage);
}

void Heavy_prog::cPack_dWRi7L0D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jz5WN6jW_sendMessage(_c, 0, m);
}

void Heavy_prog::cSlice_bpLLwQyM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_g6rj8uKb, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_y3Ks91TE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_AFgoUlSM, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_gIjEhzY7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_vqoP0jaB, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_CegCF8J2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_pEc1mTv2, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_emS35dtd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_3kM10C70, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_fbQOenbt_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_T7RRm1fY_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_T7RRm1fY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0ILI2K5M_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VyKDZwhs_sendMessage);
}

void Heavy_prog::cCast_0ILI2K5M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_VyKDZwhs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XfYYg44l_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_GFEPE95E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4uTycqq8, HV_BINOP_MULTIPLY, 0, m, &cBinop_4uTycqq8_sendMessage);
}

void Heavy_prog::cCast_nQHsCv2n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_dWRi7L0D, 0, m, &cPack_dWRi7L0D_sendMessage);
}

void Heavy_prog::cMsg_XfYYg44l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_GFEPE95E_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nQHsCv2n_sendMessage);
}

void Heavy_prog::cBinop_4uTycqq8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_dWRi7L0D, 1, m, &cPack_dWRi7L0D_sendMessage);
}

void Heavy_prog::cBinop_9R846fy2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4uTycqq8, HV_BINOP_MULTIPLY, 1, m, &cBinop_4uTycqq8_sendMessage);
}

void Heavy_prog::cMsg_FX4w6qLN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.1f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 600.0f, 0, m, &cBinop_9R846fy2_sendMessage);
}

void Heavy_prog::cMsg_jz5WN6jW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Z4ZJAREW, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 1);
  sLine_onMessage(_c, &Context(_c)->sLine_Z4ZJAREW, 0, m, NULL);
}

void Heavy_prog::cMsg_g52FD0VO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(5);
  msg_init(m, 5, msg_getTimestamp(n));
  msg_setFloat(m, 0, 748.031f);
  msg_setFloat(m, 1, 1023.62f);
  msg_setFloat(m, 2, 0.173228f);
  msg_setFloat(m, 3, 1968.5f);
  msg_setFloat(m, 4, 9259.84f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_bpLLwQyM, 0, m, &cSlice_bpLLwQyM_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_y3Ks91TE, 0, m, &cSlice_y3Ks91TE_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_gIjEhzY7, 0, m, &cSlice_gIjEhzY7_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_CegCF8J2, 0, m, &cSlice_CegCF8J2_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_emS35dtd, 0, m, &cSlice_emS35dtd_sendMessage);
}

void Heavy_prog::cPack_QFYgMNCc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_xTWoxp5n, 0, m, NULL);
}

void Heavy_prog::cPack_PDhm312h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_mybgC5bn, 0, m, NULL);
}

void Heavy_prog::cMsg_Pr0CrA1c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_z40M2AR7_sendMessage);
}

void Heavy_prog::cSystem_z40M2AR7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Y4YcGSKI_sendMessage);
}

void Heavy_prog::cVar_MY5GRjVV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_V4pnRL0v_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_nSTkqnMf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_rymVOIZ3_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_PPxAvq4z, m);
}

void Heavy_prog::cBinop_Y4YcGSKI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_J3cCL6hE, m);
}

void Heavy_prog::cMsg_V4pnRL0v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_nSTkqnMf_sendMessage);
}

void Heavy_prog::cBinop_rymVOIZ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_D86feJP3, m);
}

void Heavy_prog::cMsg_vnmkYrNY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_KIN4LNn7_sendMessage);
}

void Heavy_prog::cSystem_KIN4LNn7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_xS3kda3e_sendMessage);
}

void Heavy_prog::cVar_TQJPoo9N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_a66NgyI8_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_vIQR1j7L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ghKOtnMG_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_NZR5JOXk, m);
}

void Heavy_prog::cBinop_xS3kda3e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_apijj2Kq, m);
}

void Heavy_prog::cMsg_a66NgyI8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_vIQR1j7L_sendMessage);
}

void Heavy_prog::cBinop_ghKOtnMG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_9nTIKcxH, m);
}

void Heavy_prog::cBinop_5Qhb5lUM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_AcV6tNNL_sendMessage);
}

void Heavy_prog::cBinop_AcV6tNNL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6qXRa3GI_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_q4mM0Fbe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_exKNTHDG_sendMessage);
}

void Heavy_prog::cBinop_exKNTHDG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JmNh316W_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_FKvDrMOY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_y9UYdecU_sendMessage);
}

void Heavy_prog::cBinop_y9UYdecU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MucfsoHt_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zOkwRjrj_sendMessage);
}

void Heavy_prog::cMsg_0LVM2v8v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_pssOYrr4_sendMessage);
}

void Heavy_prog::cSystem_pssOYrr4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_OKRRmx9P_sendMessage);
}

void Heavy_prog::cDelay_V4Dlnmhz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_V4Dlnmhz, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_72ZSIW28, 0, m, &cDelay_72ZSIW28_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_V4Dlnmhz, 0, m, &cDelay_V4Dlnmhz_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Qs5PzVhA, 1, m, NULL);
}

void Heavy_prog::cDelay_72ZSIW28_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_72ZSIW28, m);
  cMsg_1lRMwbYO_sendMessage(_c, 0, m);
}

void Heavy_prog::cSwitchcase_cd3N1RCF_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_c9dqEjfz_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cBinop_lSF8FeBd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oIAg5bPS_sendMessage(_c, 0, m);
}

void Heavy_prog::hTable_Jn8DpTrG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7wbgHzXw_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_V4Dlnmhz, 2, m, &cDelay_V4Dlnmhz_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9ELzJnoA_sendMessage);
}

void Heavy_prog::cMsg_oIAg5bPS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_Jn8DpTrG, 0, m, &hTable_Jn8DpTrG_sendMessage);
}

void Heavy_prog::cBinop_OKRRmx9P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 500.0f, 0, m, &cBinop_lSF8FeBd_sendMessage);
}

void Heavy_prog::cMsg_1lRMwbYO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_Jn8DpTrG, 0, m, &hTable_Jn8DpTrG_sendMessage);
}

void Heavy_prog::cCast_9ELzJnoA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_V4Dlnmhz, 0, m, &cDelay_V4Dlnmhz_sendMessage);
}

void Heavy_prog::cMsg_7wbgHzXw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_72ZSIW28, 2, m, &cDelay_72ZSIW28_sendMessage);
}

void Heavy_prog::cMsg_c9dqEjfz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Qs5PzVhA, 1, m, NULL);
}

void Heavy_prog::cMsg_f8IrrG2y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_x1u7QXAu_sendMessage);
}

void Heavy_prog::cSystem_x1u7QXAu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_fAzwkZqD_sendMessage);
}

void Heavy_prog::cDelay_RRCmZ1F3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_RRCmZ1F3, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jwPqNSyk, 0, m, &cDelay_jwPqNSyk_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RRCmZ1F3, 0, m, &cDelay_RRCmZ1F3_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_TbVvJ6kn, 1, m, NULL);
}

void Heavy_prog::cDelay_jwPqNSyk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_jwPqNSyk, m);
  cMsg_6T0pVlJd_sendMessage(_c, 0, m);
}

void Heavy_prog::cSwitchcase_NRN3M224_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_MvMHIZQF_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cBinop_9rklVAi3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_H2bY8pKI_sendMessage(_c, 0, m);
}

void Heavy_prog::hTable_Ub9gekAh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CTRJ99x9_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RRCmZ1F3, 2, m, &cDelay_RRCmZ1F3_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KiS4bBTD_sendMessage);
}

void Heavy_prog::cMsg_H2bY8pKI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_Ub9gekAh, 0, m, &hTable_Ub9gekAh_sendMessage);
}

void Heavy_prog::cBinop_fAzwkZqD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 500.0f, 0, m, &cBinop_9rklVAi3_sendMessage);
}

void Heavy_prog::cMsg_6T0pVlJd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_Ub9gekAh, 0, m, &hTable_Ub9gekAh_sendMessage);
}

void Heavy_prog::cCast_KiS4bBTD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_RRCmZ1F3, 0, m, &cDelay_RRCmZ1F3_sendMessage);
}

void Heavy_prog::cMsg_CTRJ99x9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_jwPqNSyk, 2, m, &cDelay_jwPqNSyk_sendMessage);
}

void Heavy_prog::cMsg_MvMHIZQF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_TbVvJ6kn, 1, m, NULL);
}

void Heavy_prog::cMsg_JmNh316W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_yikKq08A, 0, m, NULL);
}

void Heavy_prog::cMsg_6qXRa3GI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_i9H0kCAo, 0, m, NULL);
}

void Heavy_prog::cCast_zOkwRjrj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_QFYgMNCc, 1, m, &cPack_QFYgMNCc_sendMessage);
}

void Heavy_prog::cCast_MucfsoHt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_PDhm312h, 1, m, &cPack_PDhm312h_sendMessage);
}

void Heavy_prog::cBinop_PtHSq25V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_QFYgMNCc, 0, m, &cPack_QFYgMNCc_sendMessage);
}

void Heavy_prog::cBinop_DWirRziK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_PDhm312h, 0, m, &cPack_PDhm312h_sendMessage);
}

void Heavy_prog::cMsg_Vy8vPkGJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 250.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 500.0f, 0, m, &cBinop_PtHSq25V_sendMessage);
}

void Heavy_prog::cMsg_S3Tw5nnT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.8f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 0.999f, 0, m, &cBinop_q4mM0Fbe_sendMessage);
}

void Heavy_prog::cMsg_AjEssTCL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1000.0f, 0, m, &cBinop_DWirRziK_sendMessage);
}

void Heavy_prog::cVar_6F6hBUiI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 40.0f, 0, m, &cBinop_klXewiY2_sendMessage);
}

void Heavy_prog::cMsg_jAFYF26y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  sPhasor_onMessage(_c, &Context(_c)->sPhasor_zJriyjmR, 1, m);
}

void Heavy_prog::cMsg_u0qecKUB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_h7mjnjXM, 0, m, NULL);
}

void Heavy_prog::cMsg_8T9Lp2kN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_lE765kvS, 0, m, NULL);
}

void Heavy_prog::cCast_AOO0hYlz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_u0qecKUB_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_fwIbhgAr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vxGZ7BuT_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_nUOnGJNS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jAFYF26y_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_54LRdGIn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6F6hBUiI, 0, m, &cVar_6F6hBUiI_sendMessage);
}

void Heavy_prog::cBinop_1WcJ3jEx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 20.0f, 0, m, &cBinop_8DOJj3Lp_sendMessage);
}

void Heavy_prog::cBinop_klXewiY2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8T9Lp2kN_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_8DOJj3Lp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6F6hBUiI, 1, m, &cVar_6F6hBUiI_sendMessage);
}

void Heavy_prog::cMsg_vxGZ7BuT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 200.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_h7mjnjXM, 0, m, NULL);
}

void Heavy_prog::cSwitchcase_XOxNKtDY_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_YXtVZYvx, 0, m, &cSlice_YXtVZYvx_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_RXwNOozZ, 0, m, &cRandom_RXwNOozZ_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_iTtamC6t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_UAzaF7Uy_sendMessage);
}

void Heavy_prog::cUnop_UAzaF7Uy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_fbQOenbt_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cRandom_RXwNOozZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 3.0f, 0, m, &cBinop_iTtamC6t_sendMessage);
}

void Heavy_prog::cSlice_YXtVZYvx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_RXwNOozZ, 1, m, &cRandom_RXwNOozZ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cVar_g0Qqd213_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Iqh9vfTj_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 500.0f, 0, m, &cBinop_dVAMeAQm_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 50.0f, 0, m, &cBinop_ZpdDIYyx_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_UG8M8hdq, 0, m, &cVar_UG8M8hdq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ftl0VpAb_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_GcCX8z8g, 0, m, &cDelay_GcCX8z8g_sendMessage);
}

void Heavy_prog::cDelay_GcCX8z8g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_GcCX8z8g, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_miUzOvcs_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5y4aWLWu_sendMessage);
}

void Heavy_prog::cCast_5y4aWLWu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_kCQjZqLL_sendMessage);
}

void Heavy_prog::cCast_miUzOvcs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 3.95f, 0, m, &cBinop_K6meOsRA_sendMessage);
}

void Heavy_prog::cBinop_kCQjZqLL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_AJ9JvHXJ_sendMessage);
}

void Heavy_prog::cBinop_AJ9JvHXJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Rc5U6NxU, HV_BINOP_MULTIPLY, 0, m, &cBinop_Rc5U6NxU_sendMessage);
}

void Heavy_prog::cBinop_Rc5U6NxU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_g0Qqd213, 0, m, &cVar_g0Qqd213_sendMessage);
}

void Heavy_prog::cMsg_Ftlo3WTM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.1f);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_miUzOvcs_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5y4aWLWu_sendMessage);
}

void Heavy_prog::cBinop_K6meOsRA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Rc5U6NxU, HV_BINOP_MULTIPLY, 1, m, &cBinop_Rc5U6NxU_sendMessage);
}

void Heavy_prog::cBinop_H7b7PKik_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Thwd10OR_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pKR0Z6dt_sendMessage);
}

void Heavy_prog::cBinop_Ald8luI4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_7W6B2vGI_sendMessage);
}

void Heavy_prog::cBinop_7W6B2vGI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3NNmYuvJ, HV_BINOP_POW, 1, m, &cBinop_3NNmYuvJ_sendMessage);
  cMsg_HsAygfYm_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_3NNmYuvJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_H7b7PKik_sendMessage);
}

void Heavy_prog::cMsg_HsAygfYm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_3NNmYuvJ, HV_BINOP_POW, 0, m, &cBinop_3NNmYuvJ_sendMessage);
}

void Heavy_prog::cSwitchcase_dkjYmqxd_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Et7AGMDl, 0, m, &cSlice_Et7AGMDl_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_NElCpblh, 0, m, &cRandom_NElCpblh_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_SBRuZJEy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_EdQFlfMH_sendMessage);
}

void Heavy_prog::cUnop_EdQFlfMH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AZ4FGC4L_sendMessage(_c, 0, m);
}

void Heavy_prog::cRandom_NElCpblh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_SBRuZJEy_sendMessage);
}

void Heavy_prog::cSlice_Et7AGMDl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_NElCpblh, 1, m, &cRandom_NElCpblh_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cMsg_AZ4FGC4L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_w70QM8dB, m);
}

void Heavy_prog::cTabhead_OvZQC9Gi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bzBbaaTf, HV_BINOP_SUBTRACT, 0, m, &cBinop_bzBbaaTf_sendMessage);
}

void Heavy_prog::cMsg_UOAWuRxQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_LHn7k8pR_sendMessage);
}

void Heavy_prog::cSystem_LHn7k8pR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_v7Zom7fu_sendMessage);
}

void Heavy_prog::cVar_gzCG7ylf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7jYTRYvN_sendMessage(_c, 0, m);
}

void Heavy_prog::cDelay_WB5yLmHx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_WB5yLmHx, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_m4Nlcez9, 0, m, &cDelay_m4Nlcez9_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_U4T6nfp9, 0, m, &sTabread_U4T6nfp9_sendMessage);
}

void Heavy_prog::cDelay_m4Nlcez9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_m4Nlcez9, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_U4T6nfp9, 0, m, &sTabread_U4T6nfp9_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_m4Nlcez9, 0, m, &cDelay_m4Nlcez9_sendMessage);
}

void Heavy_prog::sTabread_U4T6nfp9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_NXypHPyy, HV_BINOP_SUBTRACT, 0, m, &cBinop_NXypHPyy_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_p55R9fuk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_39iW8Ohz, HV_BINOP_MAX, 0, m, &cBinop_39iW8Ohz_sendMessage);
}

void Heavy_prog::cBinop_v7Zom7fu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_p55R9fuk, HV_BINOP_MULTIPLY, 0, m, &cBinop_p55R9fuk_sendMessage);
}

void Heavy_prog::cBinop_bzBbaaTf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IVMNMAos_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_U4T6nfp9, 0, m, &sTabread_U4T6nfp9_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bcwJXDVx_sendMessage);
}

void Heavy_prog::cSystem_ALEoGy5V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NXypHPyy, HV_BINOP_SUBTRACT, 1, m, &cBinop_NXypHPyy_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_m4Nlcez9, 2, m, &cDelay_m4Nlcez9_sendMessage);
}

void Heavy_prog::cMsg_7jYTRYvN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ALEoGy5V_sendMessage);
}

void Heavy_prog::cMsg_IVMNMAos_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_WB5yLmHx, 0, m, &cDelay_WB5yLmHx_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_m4Nlcez9, 0, m, &cDelay_m4Nlcez9_sendMessage);
}

void Heavy_prog::cMsg_pe2hTTjl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_39iW8Ohz, HV_BINOP_MAX, 1, m, &cBinop_39iW8Ohz_sendMessage);
}

void Heavy_prog::cBinop_39iW8Ohz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bzBbaaTf, HV_BINOP_SUBTRACT, 1, m, &cBinop_bzBbaaTf_sendMessage);
}

void Heavy_prog::cCast_bcwJXDVx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_WB5yLmHx, 0, m, &cDelay_WB5yLmHx_sendMessage);
}

void Heavy_prog::cBinop_w03jQXFs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_WB5yLmHx, 2, m, &cDelay_WB5yLmHx_sendMessage);
}

void Heavy_prog::cBinop_NXypHPyy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_w03jQXFs_sendMessage);
}

void Heavy_prog::cCast_ACwZCcHW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gzCG7ylf, 0, m, &cVar_gzCG7ylf_sendMessage);
  cMsg_UOAWuRxQ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_OvZQC9Gi, 0, m, &cTabhead_OvZQC9Gi_sendMessage);
}

void Heavy_prog::cMsg_p3NVSK5A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_61kI3JCY_sendMessage);
}

void Heavy_prog::cSystem_61kI3JCY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Ee7X4Adm_sendMessage);
}

void Heavy_prog::cDelay_3bAGStkX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_3bAGStkX, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_w5Z9lhD8, 0, m, &cDelay_w5Z9lhD8_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3bAGStkX, 0, m, &cDelay_3bAGStkX_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Y6fiqUTx, 1, m, NULL);
}

void Heavy_prog::cDelay_w5Z9lhD8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_w5Z9lhD8, m);
  cMsg_juaqczjS_sendMessage(_c, 0, m);
}

void Heavy_prog::cSwitchcase_beZhBLWJ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_erI7a1p7_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cBinop_kgOTILqL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oM5S2aJ4_sendMessage(_c, 0, m);
}

void Heavy_prog::hTable_4a2NYJ2e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_k3TEi4QI_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3bAGStkX, 2, m, &cDelay_3bAGStkX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UKqyQlVy_sendMessage);
}

void Heavy_prog::cMsg_oM5S2aJ4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_4a2NYJ2e, 0, m, &hTable_4a2NYJ2e_sendMessage);
}

void Heavy_prog::cBinop_Ee7X4Adm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_kgOTILqL_sendMessage);
}

void Heavy_prog::cMsg_juaqczjS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_4a2NYJ2e, 0, m, &hTable_4a2NYJ2e_sendMessage);
}

void Heavy_prog::cCast_UKqyQlVy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_3bAGStkX, 0, m, &cDelay_3bAGStkX_sendMessage);
}

void Heavy_prog::cMsg_k3TEi4QI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_w5Z9lhD8, 2, m, &cDelay_w5Z9lhD8_sendMessage);
}

void Heavy_prog::cMsg_erI7a1p7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_Y6fiqUTx, 1, m, NULL);
}

void Heavy_prog::cVar_yP0Y8xnG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jP0sx8mx, HV_BINOP_MULTIPLY, 0, m, &cBinop_jP0sx8mx_sendMessage);
}

void Heavy_prog::cMsg_3OeJ37Ow_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4EY8vWob_sendMessage);
}

void Heavy_prog::cSystem_4EY8vWob_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Lv5ZIZHm_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_jP0sx8mx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_RmFQZlGQ_sendMessage);
}

void Heavy_prog::cBinop_SGy33OKE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jP0sx8mx, HV_BINOP_MULTIPLY, 1, m, &cBinop_jP0sx8mx_sendMessage);
}

void Heavy_prog::cMsg_Lv5ZIZHm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_SGy33OKE_sendMessage);
}

void Heavy_prog::cBinop_RmFQZlGQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_1SGRLXVJ_sendMessage);
}

void Heavy_prog::cBinop_1SGRLXVJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_D3m8XO5s_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_NdOw1akm, m);
}

void Heavy_prog::cBinop_D3m8XO5s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_isWowbsF, m);
}

void Heavy_prog::cBinop_JvvkkyKh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_p55R9fuk, HV_BINOP_MULTIPLY, 1, m, &cBinop_p55R9fuk_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ACwZCcHW_sendMessage);
}

void Heavy_prog::cCast_Thwd10OR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JvvkkyKh, HV_BINOP_DIVIDE, 1, m, &cBinop_JvvkkyKh_sendMessage);
}

void Heavy_prog::cCast_pKR0Z6dt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kFFkS7Aa_sendMessage(_c, 0, m);
  cMsg_3FdSR5ZC_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_3FdSR5ZC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_UzsHDhYq, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_UzsHDhYq, 0, m, NULL);
}

void Heavy_prog::cBinop_ZpdDIYyx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_Ald8luI4_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_jiGus1Cj_sendMessage);
}

void Heavy_prog::cMsg_kFFkS7Aa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_JvvkkyKh, HV_BINOP_DIVIDE, 0, m, &cBinop_JvvkkyKh_sendMessage);
}

void Heavy_prog::cBinop_jiGus1Cj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_6k4QUyC9, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_yP0Y8xnG, 0, m, &cVar_yP0Y8xnG_sendMessage);
}

void Heavy_prog::cSwitchcase_vm1sBByU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_QlD9hx3A, 0, m, &cSlice_QlD9hx3A_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_A8QSVJi0, 0, m, &cRandom_A8QSVJi0_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_INidkFlv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_SzCrB0iD_sendMessage);
}

void Heavy_prog::cUnop_SzCrB0iD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XNuSbcpg_sendMessage(_c, 0, m);
}

void Heavy_prog::cRandom_A8QSVJi0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_INidkFlv_sendMessage);
}

void Heavy_prog::cSlice_QlD9hx3A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_A8QSVJi0, 1, m, &cRandom_A8QSVJi0_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cMsg_XNuSbcpg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_xUTVezR4, m);
}

void Heavy_prog::cMsg_DtSvgxmg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_dlbwRmYT_sendMessage);
}

void Heavy_prog::cSystem_dlbwRmYT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_l7Dlf2Du, HV_BINOP_DIVIDE, 1, m, &cBinop_l7Dlf2Du_sendMessage);
}

void Heavy_prog::cVar_aJyQk1Y4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_gLrBnO67_sendMessage);
}

void Heavy_prog::cVar_UG8M8hdq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_s6ePdRTd_sendMessage);
}

void Heavy_prog::cUnop_0Ian9Nos_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_JLCkEeAY_sendMessage);
}

void Heavy_prog::cBinop_l7Dlf2Du_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XwZuxGJC, HV_BINOP_MULTIPLY, 1, m, &cBinop_XwZuxGJC_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_0Ian9Nos_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_fpJtpY2y, HV_BINOP_DIVIDE, 0, m, &cBinop_fpJtpY2y_sendMessage);
}

void Heavy_prog::cBinop_gLrBnO67_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_l7Dlf2Du, HV_BINOP_DIVIDE, 0, m, &cBinop_l7Dlf2Du_sendMessage);
}

void Heavy_prog::cBinop_fpJtpY2y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_Xrvx2lAK_sendMessage);
}

void Heavy_prog::cBinop_HiVfoxfX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_lXbSOxUM_sendMessage);
}

void Heavy_prog::cBinop_lXbSOxUM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_oppWUIjB_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_6vrHt5zh, HV_BINOP_MULTIPLY, 0, m, &cBinop_6vrHt5zh_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_XwZuxGJC, HV_BINOP_MULTIPLY, 0, m, &cBinop_XwZuxGJC_sendMessage);
}

void Heavy_prog::cBinop_JLCkEeAY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6vrHt5zh, HV_BINOP_MULTIPLY, 1, m, &cBinop_6vrHt5zh_sendMessage);
}

void Heavy_prog::cBinop_6vrHt5zh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_P269yGmL_sendMessage);
}

void Heavy_prog::cCast_ftl0VpAb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aJyQk1Y4, 0, m, &cVar_aJyQk1Y4_sendMessage);
}

void Heavy_prog::cBinop_MHsX9Z6b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_bJoM7oGl_sendMessage);
}

void Heavy_prog::cBinop_bJoM7oGl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_zEAHz4hb, 5, m);
}

void Heavy_prog::cBinop_P269yGmL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_zEAHz4hb, 4, m);
}

void Heavy_prog::cBinop_WgLGUhIl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sKRKJ2pi, HV_BINOP_MULTIPLY, 0, m, &cBinop_sKRKJ2pi_sendMessage);
}

void Heavy_prog::cBinop_XwZuxGJC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_thMbhhEQ, HV_BINOP_ADD, 1, m, &cBinop_thMbhhEQ_sendMessage);
}

void Heavy_prog::cBinop_oppWUIjB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_MHsX9Z6b_sendMessage);
}

void Heavy_prog::cBinop_thMbhhEQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sKRKJ2pi, HV_BINOP_MULTIPLY, 1, m, &cBinop_sKRKJ2pi_sendMessage);
}

void Heavy_prog::cBinop_sKRKJ2pi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_zEAHz4hb, 1, m);
}

void Heavy_prog::cBinop_s6ePdRTd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fpJtpY2y, HV_BINOP_DIVIDE, 1, m, &cBinop_fpJtpY2y_sendMessage);
}

void Heavy_prog::cBinop_Xrvx2lAK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_HiVfoxfX_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_thMbhhEQ, HV_BINOP_ADD, 0, m, &cBinop_thMbhhEQ_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_WgLGUhIl_sendMessage);
}

void Heavy_prog::hTable_pyMly1PH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cSwitchcase_zHcbFOUd_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_L9VIqt17, 0, m, &cSlice_L9VIqt17_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cVar_Nj3mz8b1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fBR6K1gy_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_qoM9SypF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ahs0IZec_sendMessage);
}

void Heavy_prog::cMsg_fBR6K1gy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_qoM9SypF_sendMessage);
}

void Heavy_prog::cSlice_L9VIqt17_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_LfyWcIfJ, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_Nj3mz8b1, 0, m, &cVar_Nj3mz8b1_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_ahs0IZec_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_BdD58aQC, m);
}

void Heavy_prog::cVar_u4enbaNe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 50.0f, 0, m, &cBinop_6gFJRQG3_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EmNIHsAY_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 0.999f, 0, m, &cBinop_5Qhb5lUM_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_KrI7DIkM_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 500.0f, 0, m, &cBinop_KxrlVmFn_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zp0jocVa, 0, m, &cDelay_zp0jocVa_sendMessage);
}

void Heavy_prog::cDelay_zp0jocVa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_zp0jocVa, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vrEYoHRO_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_a64tdNbs_sendMessage);
}

void Heavy_prog::cCast_vrEYoHRO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 3.8f, 0, m, &cBinop_QFsGctM8_sendMessage);
}

void Heavy_prog::cCast_a64tdNbs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_BPZX3tRz_sendMessage);
}

void Heavy_prog::cBinop_BPZX3tRz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_CyzYapUA_sendMessage);
}

void Heavy_prog::cBinop_CyzYapUA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zum3vKax, HV_BINOP_MULTIPLY, 0, m, &cBinop_zum3vKax_sendMessage);
}

void Heavy_prog::cBinop_zum3vKax_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_u4enbaNe, 0, m, &cVar_u4enbaNe_sendMessage);
}

void Heavy_prog::cMsg_7hGzaeqN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.1f);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vrEYoHRO_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_a64tdNbs_sendMessage);
}

void Heavy_prog::cBinop_QFsGctM8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zum3vKax, HV_BINOP_MULTIPLY, 1, m, &cBinop_zum3vKax_sendMessage);
}

void Heavy_prog::cCast_EmNIHsAY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_XOxNKtDY_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_Iqh9vfTj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AOO0hYlz_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fwIbhgAr_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nUOnGJNS_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_54LRdGIn_sendMessage);
}

void Heavy_prog::cBinop_dVAMeAQm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1000.0f, 0, m, &cBinop_FKvDrMOY_sendMessage);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_JjcpztXJ, 0, m);
}

void Heavy_prog::cBinop_KrI7DIkM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_1WcJ3jEx_sendMessage);
}

void Heavy_prog::cBinop_KxrlVmFn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aJyQk1Y4, 0, m, &cVar_aJyQk1Y4_sendMessage);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_p5Tgl76A, 0, m);
}

void Heavy_prog::cReceive_dPQvq6XS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_5xQo5FrO_onMessage(_c, NULL, 0, m, NULL);
  cMsg_4f0uI6ns_sendMessage(_c, 0, m);
  cMsg_eHgT5O95_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Zmfn4Thx, 0, m, &cVar_Zmfn4Thx_sendMessage);
  cMsg_0LVM2v8v_sendMessage(_c, 0, m);
  cMsg_f8IrrG2y_sendMessage(_c, 0, m);
  cSwitchcase_dkjYmqxd_onMessage(_c, NULL, 0, m, NULL);
  cMsg_p3NVSK5A_sendMessage(_c, 0, m);
  cMsg_3OeJ37Ow_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_yP0Y8xnG, 0, m, &cVar_yP0Y8xnG_sendMessage);
  cMsg_FX4w6qLN_sendMessage(_c, 0, m);
  cMsg_g52FD0VO_sendMessage(_c, 0, m);
  cMsg_Vy8vPkGJ_sendMessage(_c, 0, m);
  cMsg_AjEssTCL_sendMessage(_c, 0, m);
  cMsg_S3Tw5nnT_sendMessage(_c, 0, m);
  cMsg_Ftlo3WTM_sendMessage(_c, 0, m);
  cSwitchcase_vm1sBByU_onMessage(_c, NULL, 0, m, NULL);
  cVar_onMessage(_c, &Context(_c)->cVar_UG8M8hdq, 0, m, &cVar_UG8M8hdq_sendMessage);
  cMsg_DtSvgxmg_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_aJyQk1Y4, 0, m, &cVar_aJyQk1Y4_sendMessage);
  cMsg_7hGzaeqN_sendMessage(_c, 0, m);
  cMsg_o6175oon_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_wHkXSSjw, 0, m, &cVar_wHkXSSjw_sendMessage);
  cMsg_lZk3h5U7_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_P3uNalpp, 0, m, &cTabhead_P3uNalpp_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_MY5GRjVV, 0, m, &cVar_MY5GRjVV_sendMessage);
  cMsg_Pr0CrA1c_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_TQJPoo9N, 0, m, &cVar_TQJPoo9N_sendMessage);
  cMsg_vnmkYrNY_sendMessage(_c, 0, m);
  cMsg_pe2hTTjl_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_gzCG7ylf, 0, m, &cVar_gzCG7ylf_sendMessage);
  cMsg_UOAWuRxQ_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_OvZQC9Gi, 0, m, &cTabhead_OvZQC9Gi_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Nj3mz8b1, 0, m, &cVar_Nj3mz8b1_sendMessage);
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
    __hv_phasor_k_f(&sPhasor_p5Tgl76A, VOf(Bf0));
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
    __hv_line_f(&sLine_lE765kvS, VOf(Bf3));
    __hv_phasor_f(&sPhasor_zJriyjmR, VIf(Bf3), VOf(Bf3));
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
    __hv_line_f(&sLine_h7mjnjXM, VOf(Bf2));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf0), 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f);
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_BdD58aQC, VOf(Bf3));
    __hv_min_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_zero_f(VOf(Bf0));
    __hv_max_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_cast_fi(VIf(Bf0), VOi(Bi0));
    __hv_tabread_if(&sTabread_LfyWcIfJ, VIi(Bi0), VOf(Bf0));
    __hv_phasor_k_f(&sPhasor_3kM10C70, VOf(Bf3));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_abs_f(VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf5), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf3));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf6), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf7), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf4), VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf3), VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_phasor_k_f(&sPhasor_pEc1mTv2, VOf(Bf6));
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
    __hv_var_k_f(VOf(Bf4), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf8), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf7), VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf6), VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf5), VIf(Bf3), VOf(Bf4));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_Z4ZJAREW, VOf(Bf5));
    __hv_varread_f(&sVarf_vqoP0jaB, VOf(Bf8));
    __hv_mul_f(VIf(Bf5), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf4), VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_AFgoUlSM, VOf(Bf6));
    __hv_varread_f(&sVarf_g6rj8uKb, VOf(Bf4));
    __hv_fma_f(VIf(Bf8), VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_phasor_f(&sPhasor_2bugMkWS, VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_abs_f(VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf6), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf6), VOf(Bf4));
    __hv_mul_f(VIf(Bf6), VIf(Bf4), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf3), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf7), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf8), VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf4), VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf5), VIf(Bf2), VOf(Bf6));
    __hv_tabread_f(&sTabread_U4T6nfp9, VOf(Bf3));
    __hv_varread_i(&sVari_w70QM8dB, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf4));
    __hv_var_k_f(VOf(Bf7), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_varwrite_i(&sVari_w70QM8dB, VIi(Bi1));
    __hv_phasor_k_f(&sPhasor_6k4QUyC9, VOf(Bf4));
    __hv_var_k_f(VOf(Bf8), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_abs_f(VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf8), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf8), VOf(Bf4));
    __hv_mul_f(VIf(Bf8), VIf(Bf4), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf10), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf11), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf9), VIf(Bf11), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf4), VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_UzsHDhYq, VOf(Bf7));
    __hv_varread_f(&sVarf_NdOw1akm, VOf(Bf10));
    __hv_mul_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_isWowbsF, VOf(Bf4));
    __hv_rpole_f(&sRPole_YqSwF43r, VIf(Bf10), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf10), 0.9f, 0.9f, 0.9f, 0.9f, 0.9f, 0.9f, 0.9f, 0.9f);
    __hv_mul_f(VIf(Bf4), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf8), VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_tabwrite_f(&sTabwrite_Y6fiqUTx, VIf(Bf10));
    __hv_add_f(VIf(Bf6), VIf(Bf3), VOf(Bf6));
    __hv_varread_i(&sVari_xUTVezR4, VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_cast_if(VIi(Bi0), VOf(Bf10));
    __hv_var_k_f(VOf(Bf7), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_varwrite_i(&sVari_xUTVezR4, VIi(Bi0));
    __hv_biquad_k_f(&sBiquad_k_zEAHz4hb, VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf10), 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f);
    __hv_fma_f(VIf(Bf7), VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_xTWoxp5n, VOf(Bf10));
    __hv_tabhead_f(&sTabhead_CaWg4r82, VOf(Bf7));
    __hv_var_k_f_r(VOf(Bf8), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_J3cCL6hE, VOf(Bf7));
    __hv_mul_f(VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_D86feJP3, VOf(Bf10));
    __hv_min_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_zero_f(VOf(Bf7));
    __hv_max_f(VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_floor_f(VIf(Bf7), VOf(Bf8));
    __hv_varread_f(&sVarf_PPxAvq4z, VOf(Bf10));
    __hv_zero_f(VOf(Bf4));
    __hv_lt_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_and_f(VIf(Bf10), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_cast_fi(VIf(Bf4), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_27UM8P4d, VIi(Bi1), VOf(Bf4));
    __hv_tabread_if(&sTabread_HdxpFTTk, VIi(Bi0), VOf(Bf10));
    __hv_sub_f(VIf(Bf4), VIf(Bf10), VOf(Bf4));
    __hv_sub_f(VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf4), VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_i9H0kCAo, VOf(Bf8));
    __hv_fma_f(VIf(Bf10), VIf(Bf8), VIf(Bf3), VOf(Bf8));
    __hv_line_f(&sLine_mybgC5bn, VOf(Bf10));
    __hv_tabhead_f(&sTabhead_TvPkfyi4, VOf(Bf4));
    __hv_var_k_f_r(VOf(Bf7), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_apijj2Kq, VOf(Bf4));
    __hv_mul_f(VIf(Bf10), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_9nTIKcxH, VOf(Bf10));
    __hv_min_f(VIf(Bf4), VIf(Bf10), VOf(Bf10));
    __hv_zero_f(VOf(Bf4));
    __hv_max_f(VIf(Bf10), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_floor_f(VIf(Bf4), VOf(Bf7));
    __hv_varread_f(&sVarf_NZR5JOXk, VOf(Bf10));
    __hv_zero_f(VOf(Bf11));
    __hv_lt_f(VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_and_f(VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_cast_fi(VIf(Bf11), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_d1q6e24C, VIi(Bi1), VOf(Bf11));
    __hv_tabread_if(&sTabread_JpDIdtKs, VIi(Bi0), VOf(Bf10));
    __hv_sub_f(VIf(Bf11), VIf(Bf10), VOf(Bf11));
    __hv_sub_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf11), VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_yikKq08A, VOf(Bf7));
    __hv_mul_f(VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_tabwrite_f(&sTabwrite_Qs5PzVhA, VIf(Bf3));
    __hv_tabwrite_f(&sTabwrite_TbVvJ6kn, VIf(Bf7));
    __hv_var_k_f(VOf(Bf3), 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f);
    __hv_mul_f(VIf(Bf7), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf6), VIf(Bf3), VOf(Bf6));
    __hv_fma_f(VIf(Bf1), VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf1), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_mul_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf1), VIf(O0), VOf(O0));
    __hv_phasor_k_f(&sPhasor_JjcpztXJ, VOf(Bf1));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_abs_f(VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf6), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf6), VOf(Bf1));
    __hv_mul_f(VIf(Bf6), VIf(Bf1), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf8), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf10), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf7), VIf(Bf10), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf1), VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_tabread_f(&sTabread_YursPVP1, VOf(Bf8));
    __hv_varread_i(&sVari_mdF9j3v0, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf10), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf1), VIf(Bf10), VOf(Bf10));
    __hv_varwrite_i(&sVari_mdF9j3v0, VIi(Bi1));
    __hv_phasor_k_f(&sPhasor_3aKv930E, VOf(Bf1));
    __hv_var_k_f(VOf(Bf7), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_abs_f(VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf7), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf7), VOf(Bf1));
    __hv_mul_f(VIf(Bf7), VIf(Bf1), VOf(Bf11));
    __hv_mul_f(VIf(Bf11), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf9), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf11), VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf1), VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_vzCVj8E3, VOf(Bf10));
    __hv_varread_f(&sVarf_SLBa4PGw, VOf(Bf4));
    __hv_mul_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_C2qccrfG, VOf(Bf1));
    __hv_rpole_f(&sRPole_zzpzvYdp, VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf7), VIf(Bf10), VIf(Bf4), VOf(Bf4));
    __hv_tabwrite_f(&sTabwrite_YS7RaK5T, VIf(Bf4));
    __hv_add_f(VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf6), VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf0), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf0), VIf(O1), VOf(O1));

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
