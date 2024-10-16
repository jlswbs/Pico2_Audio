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
  numBytes += sLine_init(&sLine_g5KyF95G);
  numBytes += sPhasor_init(&sPhasor_FbRz30fz, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_NaXa0xTr, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_QpWoFRfb, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_9wpmFxu6);
  numBytes += sPhasor_init(&sPhasor_ABLqzCyU, sampleRate);
  numBytes += sDel1_init(&sDel1_me8FL4nE);
  numBytes += sSamphold_init(&sSamphold_JQxob8ps);
  numBytes += sPhasor_init(&sPhasor_pDglqP1H, sampleRate);
  numBytes += sRPole_init(&sRPole_g6Ry6sxa);
  numBytes += sLine_init(&sLine_t8Usze2t);
  numBytes += sTabhead_init(&sTabhead_5S7UDsKN, &hTable_8CDDo8vp);
  numBytes += sTabread_init(&sTabread_m5JMSnQm, &hTable_8CDDo8vp, false);
  numBytes += sTabread_init(&sTabread_BpfX092f, &hTable_8CDDo8vp, false);
  numBytes += sLine_init(&sLine_BrnRlOS3);
  numBytes += sLine_init(&sLine_LKRb39xS);
  numBytes += sTabhead_init(&sTabhead_TTcVIYFz, &hTable_cDOXciKF);
  numBytes += sTabread_init(&sTabread_hGd9Cjsw, &hTable_cDOXciKF, false);
  numBytes += sTabread_init(&sTabread_kliJexTI, &hTable_cDOXciKF, false);
  numBytes += sLine_init(&sLine_LlJVTA5d);
  numBytes += sTabwrite_init(&sTabwrite_C0DOrCc8, &hTable_8CDDo8vp);
  numBytes += sTabwrite_init(&sTabwrite_03e0ZJQL, &hTable_cDOXciKF);
  numBytes += sLine_init(&sLine_dmsNWyxh);
  numBytes += sPhasor_init(&sPhasor_0mndNZqE, sampleRate);
  numBytes += sLine_init(&sLine_2WoiwUMu);
  numBytes += sTabread_init(&sTabread_NfforoI9, &hTable_qMBY2bex, true);
  numBytes += sPhasor_k_init(&sPhasor_cMstxnuW, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_53rY9gEc);
  numBytes += sRPole_init(&sRPole_stWFVLbV);
  numBytes += sTabwrite_init(&sTabwrite_vwkI9rv0, &hTable_qMBY2bex);
  numBytes += sRPole_init(&sRPole_JwNwtTjl);
  numBytes += cVar_init_f(&cVar_TcKUj30G, 0.0f);
  numBytes += cBinop_init(&cBinop_Qa184Kzx, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_JgrCCxjJ, 0.0f);
  numBytes += cPack_init(&cPack_YbUz0K0D, 2, 0.0f, 0.0f);
  numBytes += sVarf_init(&sVarf_LFX7k2Va, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_xSu7umeE, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_gETB6QGm, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_DBLG0iM8, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_WrpXZ7zp, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_mmTNXwyr, 0.0f);
  numBytes += cPack_init(&cPack_sKqzznBf, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_4vJIJAKT, 4, 1);
  numBytes += cSlice_init(&cSlice_jdSouoj8, 3, 1);
  numBytes += cSlice_init(&cSlice_93XFykoi, 2, 1);
  numBytes += cSlice_init(&cSlice_gxUNVYOj, 1, 1);
  numBytes += cSlice_init(&cSlice_7DVFbTKU, 0, 1);
  numBytes += sVarf_init(&sVarf_RxSjtlWv, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_aYFgAqQT, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_o78tQ3Qq, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_0gYnCE0f, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_59RtojPm, 2098022907);
  numBytes += cSlice_init(&cSlice_tBGzJKho, 1, 1);
  numBytes += cVar_init_f(&cVar_jOJCSspO, 22050.0f);
  numBytes += cBinop_init(&cBinop_4zgWOiZ6, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_z0snXtHr, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_HwskvUJx, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_rrgwGpAw, 22050.0f);
  numBytes += cBinop_init(&cBinop_LrNWiyca, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_7g0OilzL, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_gTIvVE1i, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_YClxjlcz, -1147670990);
  numBytes += cSlice_init(&cSlice_2ZjpHkd8, 1, 1);
  numBytes += cPack_init(&cPack_elp4L5I4, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_I7J0J8aL, 2, 0.0f, 0.0f);
  numBytes += cVar_init_s(&cVar_sHOud2ay, "del-1042-inputdelay");
  numBytes += sVarf_init(&sVarf_EBECv8VG, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ipJHjSul, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_HYt3yWAS, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_DrBiaXkc, "del-1042-outputdelay");
  numBytes += sVarf_init(&sVarf_GX9iSPxG, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_nYszIQ4f, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ZhDKGkYS, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_0jl5Nu06, 0.0f);
  numBytes += cDelay_init(this, &cDelay_ikjQ8FJc, 0.0f);
  numBytes += hTable_init(&hTable_8CDDo8vp, 256);
  numBytes += cDelay_init(this, &cDelay_3jEiMhUz, 0.0f);
  numBytes += cDelay_init(this, &cDelay_q0s4cemx, 0.0f);
  numBytes += hTable_init(&hTable_cDOXciKF, 256);
  numBytes += cBinop_init(&cBinop_Y6H0t1sq, 1.0f); // __pow
  numBytes += cRandom_init(&cRandom_QmVMMAY2, -976249499);
  numBytes += cSlice_init(&cSlice_I0N2UvYb, 1, 1);
  numBytes += sVari_init(&sVari_ModgsPP6, 0, 0, false);
  numBytes += cTabhead_init(&cTabhead_LS1XrLXO, &hTable_qMBY2bex);
  numBytes += cVar_init_s(&cVar_4QQjVg3L, "del-1065-buf");
  numBytes += cDelay_init(this, &cDelay_gjbQa1Q3, 100.0f);
  numBytes += cDelay_init(this, &cDelay_sLfY13QE, 0.0f);
  numBytes += cBinop_init(&cBinop_N8bEUnv9, 100.0f); // __mul
  numBytes += cBinop_init(&cBinop_Sor5BSgg, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_Mq5SBFJm, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_h9ltkHNo, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_h8NfLZuG, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Idg2ua2A, 0.0f);
  numBytes += hTable_init(&hTable_qMBY2bex, 256);
  numBytes += cVar_init_f(&cVar_CJiTvmrq, 22050.0f);
  numBytes += cBinop_init(&cBinop_UmSKQClr, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_g4qf68OI, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_6O56S4Xl, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_0ez8Y2bQ, 0.0f); // __div
  numBytes += cRandom_init(&cRandom_CnyPbM6y, 1829169582);
  numBytes += cSlice_init(&cSlice_lqwZmexZ, 1, 1);
  numBytes += sVari_init(&sVari_bA8gj8sb, 0, 0, false);
  numBytes += cVar_init_f(&cVar_g62lVL3g, 0.0f);
  numBytes += cDelay_init(this, &cDelay_wf9hpLeB, 180.0f);
  numBytes += cBinop_init(&cBinop_WEaklsdk, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_sYhN3LQe, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_prog::~Heavy_prog() {
  cPack_free(&cPack_YbUz0K0D);
  cPack_free(&cPack_sKqzznBf);
  cPack_free(&cPack_elp4L5I4);
  cPack_free(&cPack_I7J0J8aL);
  hTable_free(&hTable_8CDDo8vp);
  hTable_free(&hTable_cDOXciKF);
  hTable_free(&hTable_qMBY2bex);
}

HvTable *Heavy_prog::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0xAA25E611: return &hTable_8CDDo8vp; // del-1042-inputdelay
    case 0x586A0849: return &hTable_cDOXciKF; // del-1042-outputdelay
    case 0x62FE87D8: return &hTable_qMBY2bex; // del-1065-buf
    default: return nullptr;
  }
}

void Heavy_prog::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_kvv0NHR9_sendMessage);
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


void Heavy_prog::cVar_TcKUj30G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JgrCCxjJ, 1, m, &cVar_JgrCCxjJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DaEHskIx_sendMessage);
}

void Heavy_prog::cBinop_WiZW4OYe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_gETB6QGm, m);
}

void Heavy_prog::cBinop_FadPedbA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_BwI2AylW_sendMessage);
}

void Heavy_prog::cBinop_BwI2AylW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Qa184Kzx, HV_BINOP_POW, 1, m, &cBinop_Qa184Kzx_sendMessage);
  cMsg_2VRdLiXP_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_Qa184Kzx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_WiZW4OYe_sendMessage);
}

void Heavy_prog::cMsg_2VRdLiXP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Qa184Kzx, HV_BINOP_POW, 0, m, &cBinop_Qa184Kzx_sendMessage);
}

void Heavy_prog::cVar_JgrCCxjJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_g5KyF95G, 0, m, NULL);
}

void Heavy_prog::cPack_YbUz0K0D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_g5KyF95G, 0, m, NULL);
}

void Heavy_prog::cBinop_xSu7umeE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_DBLG0iM8, m);
}

void Heavy_prog::cCast_aWEYdcGv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xSu7umeE, HV_BINOP_MULTIPLY, 1, m, &cBinop_xSu7umeE_sendMessage);
}

void Heavy_prog::cCast_Ov5jTnX2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xSu7umeE, HV_BINOP_MULTIPLY, 0, m, &cBinop_xSu7umeE_sendMessage);
}

void Heavy_prog::cCast_DaEHskIx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xKTG4b8r_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Q6QsP5fL_sendMessage);
}

void Heavy_prog::cCast_xKTG4b8r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JgrCCxjJ, 0, m, &cVar_JgrCCxjJ_sendMessage);
}

void Heavy_prog::cCast_Q6QsP5fL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_YbUz0K0D, 0, m, &cPack_YbUz0K0D_sendMessage);
}

void Heavy_prog::cVar_mmTNXwyr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 40.0f, 0, m, &cBinop_JBoQLkEY_sendMessage);
}

void Heavy_prog::cMsg_sHhmAOms_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.5f);
  sPhasor_onMessage(_c, &Context(_c)->sPhasor_0mndNZqE, 1, m);
}

void Heavy_prog::cMsg_8XPLzcyE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_2WoiwUMu, 0, m, NULL);
}

void Heavy_prog::cMsg_ozmYMGS0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_dmsNWyxh, 0, m, NULL);
}

void Heavy_prog::cCast_wky49RhV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8XPLzcyE_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_pzSuDuz2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sHhmAOms_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_mTlvyzan_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_S4XDu9bP_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_UPzeqLV0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mmTNXwyr, 0, m, &cVar_mmTNXwyr_sendMessage);
}

void Heavy_prog::cBinop_2hj6zS4A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 20.0f, 0, m, &cBinop_zkWt4FNY_sendMessage);
}

void Heavy_prog::cBinop_JBoQLkEY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ozmYMGS0_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_zkWt4FNY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mmTNXwyr, 1, m, &cVar_mmTNXwyr_sendMessage);
}

void Heavy_prog::cMsg_S4XDu9bP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 200.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_2WoiwUMu, 0, m, NULL);
}

void Heavy_prog::cPack_sKqzznBf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CUDDwf7z_sendMessage(_c, 0, m);
}

void Heavy_prog::cSlice_4vJIJAKT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_RxSjtlWv, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_jdSouoj8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_0gYnCE0f, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_93XFykoi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_o78tQ3Qq, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_gxUNVYOj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_QpWoFRfb, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_7DVFbTKU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_NaXa0xTr, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_9fyfFmCM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LClbQWWQ_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_LClbQWWQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KBwn0ja1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_w2gC4Agj_sendMessage);
}

void Heavy_prog::cCast_KBwn0ja1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_w2gC4Agj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5CObGk4F_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_UgLt0n4i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_sKqzznBf, 0, m, &cPack_sKqzznBf_sendMessage);
}

void Heavy_prog::cCast_o8Uy5856_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aYFgAqQT, HV_BINOP_MULTIPLY, 0, m, &cBinop_aYFgAqQT_sendMessage);
}

void Heavy_prog::cMsg_5CObGk4F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_o8Uy5856_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UgLt0n4i_sendMessage);
}

void Heavy_prog::cBinop_aYFgAqQT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_sKqzznBf, 1, m, &cPack_sKqzznBf_sendMessage);
}

void Heavy_prog::cBinop_Bqm09PZn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aYFgAqQT, HV_BINOP_MULTIPLY, 1, m, &cBinop_aYFgAqQT_sendMessage);
}

void Heavy_prog::cMsg_xccTDSa7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.1f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 600.0f, 0, m, &cBinop_Bqm09PZn_sendMessage);
}

void Heavy_prog::cMsg_CUDDwf7z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_9wpmFxu6, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 1);
  sLine_onMessage(_c, &Context(_c)->sLine_9wpmFxu6, 0, m, NULL);
}

void Heavy_prog::cMsg_DmUfKpWc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(5);
  msg_init(m, 5, msg_getTimestamp(n));
  msg_setFloat(m, 0, 748.031f);
  msg_setFloat(m, 1, 1023.62f);
  msg_setFloat(m, 2, 0.173228f);
  msg_setFloat(m, 3, 1968.5f);
  msg_setFloat(m, 4, 9259.84f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_4vJIJAKT, 0, m, &cSlice_4vJIJAKT_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_jdSouoj8, 0, m, &cSlice_jdSouoj8_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_93XFykoi, 0, m, &cSlice_93XFykoi_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_gxUNVYOj, 0, m, &cSlice_gxUNVYOj_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_7DVFbTKU, 0, m, &cSlice_7DVFbTKU_sendMessage);
}

void Heavy_prog::cSwitchcase_BcA5yXuG_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_tBGzJKho, 0, m, &cSlice_tBGzJKho_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_59RtojPm, 0, m, &cRandom_59RtojPm_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_ltHnAmPG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_wiHoJZpT_sendMessage);
}

void Heavy_prog::cUnop_wiHoJZpT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_9fyfFmCM_onMessage(_c, NULL, 0, m, NULL);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_2hj6zS4A_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 880.0f, 0, m, &cBinop_9bL31tRc_sendMessage);
}

void Heavy_prog::cRandom_59RtojPm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 3.0f, 0, m, &cBinop_ltHnAmPG_sendMessage);
}

void Heavy_prog::cSlice_tBGzJKho_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_59RtojPm, 1, m, &cRandom_59RtojPm_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cVar_jOJCSspO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4zgWOiZ6, HV_BINOP_MULTIPLY, 0, m, &cBinop_4zgWOiZ6_sendMessage);
}

void Heavy_prog::cMsg_78MUjA7T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_7RKwXmg0_sendMessage);
}

void Heavy_prog::cSystem_7RKwXmg0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5yD3JQHI_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_4zgWOiZ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_fexLnSs5_sendMessage);
}

void Heavy_prog::cBinop_tib0cz7l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4zgWOiZ6, HV_BINOP_MULTIPLY, 1, m, &cBinop_4zgWOiZ6_sendMessage);
}

void Heavy_prog::cMsg_5yD3JQHI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_tib0cz7l_sendMessage);
}

void Heavy_prog::cBinop_fexLnSs5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_p4vIO7Cf_sendMessage);
}

void Heavy_prog::cBinop_p4vIO7Cf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_8fmKsl44_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_HwskvUJx, m);
}

void Heavy_prog::cBinop_8fmKsl44_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_z0snXtHr, m);
}

void Heavy_prog::cVar_rrgwGpAw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LrNWiyca, HV_BINOP_MULTIPLY, 0, m, &cBinop_LrNWiyca_sendMessage);
}

void Heavy_prog::cMsg_44IZTRF8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_iQ2Xs0gJ_sendMessage);
}

void Heavy_prog::cSystem_iQ2Xs0gJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oplyMOKK_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_LrNWiyca_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_myjGrgk1_sendMessage);
}

void Heavy_prog::cBinop_l1FY6qq0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LrNWiyca, HV_BINOP_MULTIPLY, 1, m, &cBinop_LrNWiyca_sendMessage);
}

void Heavy_prog::cMsg_oplyMOKK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_l1FY6qq0_sendMessage);
}

void Heavy_prog::cBinop_myjGrgk1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_to2kp7Mb_sendMessage);
}

void Heavy_prog::cBinop_to2kp7Mb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_VNcx7zmJ_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_gTIvVE1i, m);
}

void Heavy_prog::cBinop_VNcx7zmJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_7g0OilzL, m);
}

void Heavy_prog::cSwitchcase_UbAzjfgn_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_2ZjpHkd8, 0, m, &cSlice_2ZjpHkd8_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_YClxjlcz, 0, m, &cRandom_YClxjlcz_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_C3oegIzI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_gtgOQMvs_sendMessage);
}

void Heavy_prog::cUnop_gtgOQMvs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 480.0f, 0, m, &cBinop_ntoRrfBS_sendMessage);
}

void Heavy_prog::cRandom_YClxjlcz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5.0f, 0, m, &cBinop_C3oegIzI_sendMessage);
}

void Heavy_prog::cSlice_2ZjpHkd8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_YClxjlcz, 1, m, &cRandom_YClxjlcz_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cPack_elp4L5I4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_t8Usze2t, 0, m, NULL);
}

void Heavy_prog::cPack_I7J0J8aL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_LKRb39xS, 0, m, NULL);
}

void Heavy_prog::cMsg_VXo965aN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_MaPwvB0I_sendMessage);
}

void Heavy_prog::cSystem_MaPwvB0I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Sbywmybf_sendMessage);
}

void Heavy_prog::cVar_sHOud2ay_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2buxfsdF_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_WLgP1UVv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_49wBorWn_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_EBECv8VG, m);
}

void Heavy_prog::cBinop_Sbywmybf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ipJHjSul, m);
}

void Heavy_prog::cMsg_2buxfsdF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_WLgP1UVv_sendMessage);
}

void Heavy_prog::cBinop_49wBorWn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_HYt3yWAS, m);
}

void Heavy_prog::cMsg_QE4yxXX6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_dG4hGNFW_sendMessage);
}

void Heavy_prog::cSystem_dG4hGNFW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Ipt0Jz4T_sendMessage);
}

void Heavy_prog::cVar_DrBiaXkc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vyX4nNaD_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_pGkmOG8Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_fl66CZmW_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_GX9iSPxG, m);
}

void Heavy_prog::cBinop_Ipt0Jz4T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_nYszIQ4f, m);
}

void Heavy_prog::cMsg_vyX4nNaD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_pGkmOG8Z_sendMessage);
}

void Heavy_prog::cBinop_fl66CZmW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ZhDKGkYS, m);
}

void Heavy_prog::cBinop_d8ZQBjB8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_KxROLSwj_sendMessage);
}

void Heavy_prog::cBinop_KxROLSwj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MCitW5Us_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_BXpA184e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_QiCxZlbg_sendMessage);
}

void Heavy_prog::cBinop_QiCxZlbg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pSY8jYGW_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_dB64oBNt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_sdZaXGyp_sendMessage);
}

void Heavy_prog::cBinop_sdZaXGyp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_FQjj2yPb_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7lQkzMoc_sendMessage);
}

void Heavy_prog::cMsg_sDsQvuNN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_AU8eSOSq_sendMessage);
}

void Heavy_prog::cSystem_AU8eSOSq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_qP4kSTVH_sendMessage);
}

void Heavy_prog::cDelay_0jl5Nu06_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_0jl5Nu06, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ikjQ8FJc, 0, m, &cDelay_ikjQ8FJc_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0jl5Nu06, 0, m, &cDelay_0jl5Nu06_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_C0DOrCc8, 1, m, NULL);
}

void Heavy_prog::cDelay_ikjQ8FJc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ikjQ8FJc, m);
  cMsg_uMS66mmd_sendMessage(_c, 0, m);
}

void Heavy_prog::cSwitchcase_UxDsWIhS_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_4Sg9Fng1_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cBinop_lfFQLyXY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9xAI2Bjh_sendMessage(_c, 0, m);
}

void Heavy_prog::hTable_8CDDo8vp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wZOO7K6v_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0jl5Nu06, 2, m, &cDelay_0jl5Nu06_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_o7ijTQug_sendMessage);
}

void Heavy_prog::cMsg_9xAI2Bjh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_8CDDo8vp, 0, m, &hTable_8CDDo8vp_sendMessage);
}

void Heavy_prog::cBinop_qP4kSTVH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 500.0f, 0, m, &cBinop_lfFQLyXY_sendMessage);
}

void Heavy_prog::cMsg_uMS66mmd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_8CDDo8vp, 0, m, &hTable_8CDDo8vp_sendMessage);
}

void Heavy_prog::cCast_o7ijTQug_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_0jl5Nu06, 0, m, &cDelay_0jl5Nu06_sendMessage);
}

void Heavy_prog::cMsg_wZOO7K6v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_ikjQ8FJc, 2, m, &cDelay_ikjQ8FJc_sendMessage);
}

void Heavy_prog::cMsg_4Sg9Fng1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_C0DOrCc8, 1, m, NULL);
}

void Heavy_prog::cMsg_020Wz5Sm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_osXMQtEe_sendMessage);
}

void Heavy_prog::cSystem_osXMQtEe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_CsIWEGeK_sendMessage);
}

void Heavy_prog::cDelay_3jEiMhUz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_3jEiMhUz, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_q0s4cemx, 0, m, &cDelay_q0s4cemx_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3jEiMhUz, 0, m, &cDelay_3jEiMhUz_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_03e0ZJQL, 1, m, NULL);
}

void Heavy_prog::cDelay_q0s4cemx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_q0s4cemx, m);
  cMsg_Yq5Vrx6I_sendMessage(_c, 0, m);
}

void Heavy_prog::cSwitchcase_oSCbnwnT_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_mgvIt4gi_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cBinop_rByCdJzz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UZYt1pQJ_sendMessage(_c, 0, m);
}

void Heavy_prog::hTable_cDOXciKF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_swKNnwQb_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3jEiMhUz, 2, m, &cDelay_3jEiMhUz_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hyIAzKaD_sendMessage);
}

void Heavy_prog::cMsg_UZYt1pQJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_cDOXciKF, 0, m, &hTable_cDOXciKF_sendMessage);
}

void Heavy_prog::cBinop_CsIWEGeK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 500.0f, 0, m, &cBinop_rByCdJzz_sendMessage);
}

void Heavy_prog::cMsg_Yq5Vrx6I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_cDOXciKF, 0, m, &hTable_cDOXciKF_sendMessage);
}

void Heavy_prog::cCast_hyIAzKaD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_3jEiMhUz, 0, m, &cDelay_3jEiMhUz_sendMessage);
}

void Heavy_prog::cMsg_swKNnwQb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_q0s4cemx, 2, m, &cDelay_q0s4cemx_sendMessage);
}

void Heavy_prog::cMsg_mgvIt4gi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_03e0ZJQL, 1, m, NULL);
}

void Heavy_prog::cMsg_pSY8jYGW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_LlJVTA5d, 0, m, NULL);
}

void Heavy_prog::cMsg_MCitW5Us_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_BrnRlOS3, 0, m, NULL);
}

void Heavy_prog::cCast_7lQkzMoc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_elp4L5I4, 1, m, &cPack_elp4L5I4_sendMessage);
}

void Heavy_prog::cCast_FQjj2yPb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_I7J0J8aL, 1, m, &cPack_I7J0J8aL_sendMessage);
}

void Heavy_prog::cBinop_Nk7JLYI4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_elp4L5I4, 0, m, &cPack_elp4L5I4_sendMessage);
}

void Heavy_prog::cBinop_37rIKfVi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_I7J0J8aL, 0, m, &cPack_I7J0J8aL_sendMessage);
}

void Heavy_prog::cMsg_aK2gc4RO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 250.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 500.0f, 0, m, &cBinop_Nk7JLYI4_sendMessage);
}

void Heavy_prog::cMsg_F6UNaMy5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.8f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 0.999f, 0, m, &cBinop_BXpA184e_sendMessage);
}

void Heavy_prog::cMsg_98u8yxNY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1000.0f, 0, m, &cBinop_37rIKfVi_sendMessage);
}

void Heavy_prog::cBinop_yZZMSOs2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_hHvQqGXT_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_b358FKKU_sendMessage);
}

void Heavy_prog::cBinop_ft1N54oi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_i1FZEE13_sendMessage);
}

void Heavy_prog::cBinop_i1FZEE13_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y6H0t1sq, HV_BINOP_POW, 1, m, &cBinop_Y6H0t1sq_sendMessage);
  cMsg_VK0dFYEB_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_Y6H0t1sq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_yZZMSOs2_sendMessage);
}

void Heavy_prog::cMsg_VK0dFYEB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y6H0t1sq, HV_BINOP_POW, 0, m, &cBinop_Y6H0t1sq_sendMessage);
}

void Heavy_prog::cSwitchcase_ua4F6x6a_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_I0N2UvYb, 0, m, &cSlice_I0N2UvYb_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_QmVMMAY2, 0, m, &cRandom_QmVMMAY2_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_QyNDCaxw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_JOhnBbrr_sendMessage);
}

void Heavy_prog::cUnop_JOhnBbrr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sGYHYvpG_sendMessage(_c, 0, m);
}

void Heavy_prog::cRandom_QmVMMAY2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_QyNDCaxw_sendMessage);
}

void Heavy_prog::cSlice_I0N2UvYb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_QmVMMAY2, 1, m, &cRandom_QmVMMAY2_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cMsg_sGYHYvpG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_ModgsPP6, m);
}

void Heavy_prog::cTabhead_LS1XrLXO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Sor5BSgg, HV_BINOP_SUBTRACT, 0, m, &cBinop_Sor5BSgg_sendMessage);
}

void Heavy_prog::cMsg_NJi5l5dD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_y0h1cP54_sendMessage);
}

void Heavy_prog::cSystem_y0h1cP54_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_cuASbAoG_sendMessage);
}

void Heavy_prog::cVar_4QQjVg3L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_slLvmBNz_sendMessage(_c, 0, m);
}

void Heavy_prog::cDelay_gjbQa1Q3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_gjbQa1Q3, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sLfY13QE, 0, m, &cDelay_sLfY13QE_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_NfforoI9, 0, m, &sTabread_NfforoI9_sendMessage);
}

void Heavy_prog::cDelay_sLfY13QE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_sLfY13QE, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_NfforoI9, 0, m, &sTabread_NfforoI9_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sLfY13QE, 0, m, &cDelay_sLfY13QE_sendMessage);
}

void Heavy_prog::sTabread_NfforoI9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_h9ltkHNo, HV_BINOP_SUBTRACT, 0, m, &cBinop_h9ltkHNo_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_N8bEUnv9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Mq5SBFJm, HV_BINOP_MAX, 0, m, &cBinop_Mq5SBFJm_sendMessage);
}

void Heavy_prog::cBinop_cuASbAoG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_N8bEUnv9, HV_BINOP_MULTIPLY, 0, m, &cBinop_N8bEUnv9_sendMessage);
}

void Heavy_prog::cBinop_Sor5BSgg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8ZBZ9Q0X_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_NfforoI9, 0, m, &sTabread_NfforoI9_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IqNhsnzt_sendMessage);
}

void Heavy_prog::cSystem_QqRUunRo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_h9ltkHNo, HV_BINOP_SUBTRACT, 1, m, &cBinop_h9ltkHNo_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sLfY13QE, 2, m, &cDelay_sLfY13QE_sendMessage);
}

void Heavy_prog::cMsg_slLvmBNz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_QqRUunRo_sendMessage);
}

void Heavy_prog::cMsg_8ZBZ9Q0X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_gjbQa1Q3, 0, m, &cDelay_gjbQa1Q3_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sLfY13QE, 0, m, &cDelay_sLfY13QE_sendMessage);
}

void Heavy_prog::cMsg_jRJm1zCA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_Mq5SBFJm, HV_BINOP_MAX, 1, m, &cBinop_Mq5SBFJm_sendMessage);
}

void Heavy_prog::cBinop_Mq5SBFJm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Sor5BSgg, HV_BINOP_SUBTRACT, 1, m, &cBinop_Sor5BSgg_sendMessage);
}

void Heavy_prog::cCast_IqNhsnzt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_gjbQa1Q3, 0, m, &cDelay_gjbQa1Q3_sendMessage);
}

void Heavy_prog::cBinop_HSzu7Og0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_gjbQa1Q3, 2, m, &cDelay_gjbQa1Q3_sendMessage);
}

void Heavy_prog::cBinop_h9ltkHNo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_HSzu7Og0_sendMessage);
}

void Heavy_prog::cCast_le6qK3je_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4QQjVg3L, 0, m, &cVar_4QQjVg3L_sendMessage);
  cMsg_NJi5l5dD_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_LS1XrLXO, 0, m, &cTabhead_LS1XrLXO_sendMessage);
}

void Heavy_prog::cMsg_LkLcyVvI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_hCj1n9Lz_sendMessage);
}

void Heavy_prog::cSystem_hCj1n9Lz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_5lD8rpja_sendMessage);
}

void Heavy_prog::cDelay_h8NfLZuG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_h8NfLZuG, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Idg2ua2A, 0, m, &cDelay_Idg2ua2A_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_h8NfLZuG, 0, m, &cDelay_h8NfLZuG_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_vwkI9rv0, 1, m, NULL);
}

void Heavy_prog::cDelay_Idg2ua2A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Idg2ua2A, m);
  cMsg_13WIjfHJ_sendMessage(_c, 0, m);
}

void Heavy_prog::cSwitchcase_h8L4w9s6_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_jf275kRt_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cBinop_FJYbV6dD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xI3iZEEn_sendMessage(_c, 0, m);
}

void Heavy_prog::hTable_qMBY2bex_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fp40Vlrq_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_h8NfLZuG, 2, m, &cDelay_h8NfLZuG_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IZJZgG5b_sendMessage);
}

void Heavy_prog::cMsg_xI3iZEEn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_qMBY2bex, 0, m, &hTable_qMBY2bex_sendMessage);
}

void Heavy_prog::cBinop_5lD8rpja_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_FJYbV6dD_sendMessage);
}

void Heavy_prog::cMsg_13WIjfHJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_qMBY2bex, 0, m, &hTable_qMBY2bex_sendMessage);
}

void Heavy_prog::cCast_IZJZgG5b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_h8NfLZuG, 0, m, &cDelay_h8NfLZuG_sendMessage);
}

void Heavy_prog::cMsg_fp40Vlrq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_Idg2ua2A, 2, m, &cDelay_Idg2ua2A_sendMessage);
}

void Heavy_prog::cMsg_jf275kRt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_vwkI9rv0, 1, m, NULL);
}

void Heavy_prog::cVar_CJiTvmrq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UmSKQClr, HV_BINOP_MULTIPLY, 0, m, &cBinop_UmSKQClr_sendMessage);
}

void Heavy_prog::cMsg_pybew1HX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_vE5spGp9_sendMessage);
}

void Heavy_prog::cSystem_vE5spGp9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hOItgQtS_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_UmSKQClr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_2EZKxV3l_sendMessage);
}

void Heavy_prog::cBinop_zP6MvgJJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UmSKQClr, HV_BINOP_MULTIPLY, 1, m, &cBinop_UmSKQClr_sendMessage);
}

void Heavy_prog::cMsg_hOItgQtS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_zP6MvgJJ_sendMessage);
}

void Heavy_prog::cBinop_2EZKxV3l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_fOrIaJNl_sendMessage);
}

void Heavy_prog::cBinop_fOrIaJNl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ERb8Rkap_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_6O56S4Xl, m);
}

void Heavy_prog::cBinop_ERb8Rkap_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_g4qf68OI, m);
}

void Heavy_prog::cBinop_0ez8Y2bQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_N8bEUnv9, HV_BINOP_MULTIPLY, 1, m, &cBinop_N8bEUnv9_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_le6qK3je_sendMessage);
}

void Heavy_prog::cCast_b358FKKU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uqfNEFII_sendMessage(_c, 0, m);
  cMsg_9KTsvS35_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_hHvQqGXT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0ez8Y2bQ, HV_BINOP_DIVIDE, 1, m, &cBinop_0ez8Y2bQ_sendMessage);
}

void Heavy_prog::cMsg_9KTsvS35_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_53rY9gEc, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_53rY9gEc, 0, m, NULL);
}

void Heavy_prog::cBinop_iQw9GMpp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_ft1N54oi_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 40.0f, 0, m, &cBinop_UmGgh2VJ_sendMessage);
}

void Heavy_prog::cMsg_uqfNEFII_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_0ez8Y2bQ, HV_BINOP_DIVIDE, 0, m, &cBinop_0ez8Y2bQ_sendMessage);
}

void Heavy_prog::cBinop_UmGgh2VJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_cMstxnuW, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_CJiTvmrq, 0, m, &cVar_CJiTvmrq_sendMessage);
}

void Heavy_prog::cSwitchcase_IbI3GxJg_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_lqwZmexZ, 0, m, &cSlice_lqwZmexZ_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_CnyPbM6y, 0, m, &cRandom_CnyPbM6y_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_3PAPFc9g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_6FP2TvCd_sendMessage);
}

void Heavy_prog::cUnop_6FP2TvCd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lT9usbm5_sendMessage(_c, 0, m);
}

void Heavy_prog::cRandom_CnyPbM6y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_3PAPFc9g_sendMessage);
}

void Heavy_prog::cSlice_lqwZmexZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_CnyPbM6y, 1, m, &cRandom_CnyPbM6y_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cMsg_lT9usbm5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_bA8gj8sb, m);
}

void Heavy_prog::cVar_g62lVL3g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UYuBrQew_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 64.0f, 0, m, &cBinop_BDb16Kqi_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 0.999f, 0, m, &cBinop_d8ZQBjB8_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 50.0f, 0, m, &cBinop_iQw9GMpp_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 18.0f, 0, m, &cBinop_vk4RVHIT_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_rsfM1l3R_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.8f, 0, m, &cBinop_dAPp3pDT_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_sYhN3LQe, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wf9hpLeB, 0, m, &cDelay_wf9hpLeB_sendMessage);
}

void Heavy_prog::cDelay_wf9hpLeB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wf9hpLeB, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qQyWnYwq_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rUcerbzT_sendMessage);
}

void Heavy_prog::cCast_rUcerbzT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_vAG3qNbo_sendMessage);
}

void Heavy_prog::cCast_qQyWnYwq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 3.95f, 0, m, &cBinop_yj3TNbBU_sendMessage);
}

void Heavy_prog::cBinop_vAG3qNbo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_jCkVzVxF_sendMessage);
}

void Heavy_prog::cBinop_jCkVzVxF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WEaklsdk, HV_BINOP_MULTIPLY, 0, m, &cBinop_WEaklsdk_sendMessage);
}

void Heavy_prog::cBinop_WEaklsdk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_g62lVL3g, 0, m, &cVar_g62lVL3g_sendMessage);
}

void Heavy_prog::cMsg_q4SZmBe1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.1f);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qQyWnYwq_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rUcerbzT_sendMessage);
}

void Heavy_prog::cBinop_yj3TNbBU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WEaklsdk, HV_BINOP_MULTIPLY, 1, m, &cBinop_WEaklsdk_sendMessage);
}

void Heavy_prog::cBinop_R6NkXVwQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_FadPedbA_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_7kjH41YQ_sendMessage);
}

void Heavy_prog::cCast_UYuBrQew_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wky49RhV_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mTlvyzan_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pzSuDuz2_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UPzeqLV0_sendMessage);
  cSwitchcase_BcA5yXuG_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_UbAzjfgn_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_9bL31tRc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jOJCSspO, 0, m, &cVar_jOJCSspO_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1000.0f, 0, m, &cBinop_dB64oBNt_sendMessage);
}

void Heavy_prog::cBinop_ntoRrfBS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rrgwGpAw, 0, m, &cVar_rrgwGpAw_sendMessage);
}

void Heavy_prog::cBinop_BDb16Kqi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 12.0f, 0, m, &cBinop_R6NkXVwQ_sendMessage);
}

void Heavy_prog::cBinop_7kjH41YQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_YbUz0K0D, 1, m, &cPack_YbUz0K0D_sendMessage);
}

void Heavy_prog::cBinop_vk4RVHIT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_aWEYdcGv_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Ov5jTnX2_sendMessage);
}

void Heavy_prog::cBinop_rsfM1l3R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TcKUj30G, 0, m, &cVar_TcKUj30G_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_2hj6zS4A_sendMessage);
}

void Heavy_prog::cBinop_dAPp3pDT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_WrpXZ7zp, m);
}

void Heavy_prog::cReceive_kvv0NHR9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sDsQvuNN_sendMessage(_c, 0, m);
  cMsg_020Wz5Sm_sendMessage(_c, 0, m);
  cSwitchcase_ua4F6x6a_onMessage(_c, NULL, 0, m, NULL);
  cMsg_LkLcyVvI_sendMessage(_c, 0, m);
  cMsg_pybew1HX_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_CJiTvmrq, 0, m, &cVar_CJiTvmrq_sendMessage);
  cMsg_xccTDSa7_sendMessage(_c, 0, m);
  cMsg_DmUfKpWc_sendMessage(_c, 0, m);
  cMsg_78MUjA7T_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_jOJCSspO, 0, m, &cVar_jOJCSspO_sendMessage);
  cMsg_44IZTRF8_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_rrgwGpAw, 0, m, &cVar_rrgwGpAw_sendMessage);
  cMsg_aK2gc4RO_sendMessage(_c, 0, m);
  cMsg_98u8yxNY_sendMessage(_c, 0, m);
  cMsg_F6UNaMy5_sendMessage(_c, 0, m);
  cSwitchcase_IbI3GxJg_onMessage(_c, NULL, 0, m, NULL);
  cMsg_q4SZmBe1_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_sHOud2ay, 0, m, &cVar_sHOud2ay_sendMessage);
  cMsg_VXo965aN_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_DrBiaXkc, 0, m, &cVar_DrBiaXkc_sendMessage);
  cMsg_QE4yxXX6_sendMessage(_c, 0, m);
  cMsg_jRJm1zCA_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_4QQjVg3L, 0, m, &cVar_4QQjVg3L_sendMessage);
  cMsg_NJi5l5dD_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_LS1XrLXO, 0, m, &cTabhead_LS1XrLXO_sendMessage);
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
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5, Bf6, Bf7, Bf8, Bf9, Bf10, Bf11, Bf12, Bf13, Bf14;
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
    __hv_line_f(&sLine_g5KyF95G, VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_LFX7k2Va, VOf(Bf1));
    __hv_varread_f(&sVarf_DBLG0iM8, VOf(Bf2));
    __hv_varread_f(&sVarf_gETB6QGm, VOf(Bf3));
    __hv_fma_f(VIf(Bf1), VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_phasor_f(&sPhasor_FbRz30fz, VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf5), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf1), VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf3), VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf0));
    __hv_varread_f(&sVarf_WrpXZ7zp, VOf(Bf4));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_varwrite_f(&sVarf_LFX7k2Va, VIf(Bf4));
    __hv_phasor_k_f(&sPhasor_NaXa0xTr, VOf(Bf4));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf2), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf4));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf5), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf1), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf3), VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf4), VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_phasor_k_f(&sPhasor_QpWoFRfb, VOf(Bf5));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf4), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf5));
    __hv_mul_f(VIf(Bf4), VIf(Bf5), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf3), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf6), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf1), VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf5), VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf2), VIf(Bf4), VOf(Bf3));
    __hv_var_k_f(VOf(Bf5), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_line_f(&sLine_9wpmFxu6, VOf(Bf2));
    __hv_varread_f(&sVarf_o78tQ3Qq, VOf(Bf6));
    __hv_mul_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf3), VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_0gYnCE0f, VOf(Bf5));
    __hv_varread_f(&sVarf_RxSjtlWv, VOf(Bf3));
    __hv_fma_f(VIf(Bf6), VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_phasor_f(&sPhasor_ABLqzCyU, VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_abs_f(VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf5), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf3));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf1), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf6), VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf3), VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_varread_i(&sVari_bA8gj8sb, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf5));
    __hv_var_k_f(VOf(Bf4), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_varwrite_i(&sVari_bA8gj8sb, VIi(Bi1));
    __hv_add_f(VIf(Bf2), VIf(Bf4), VOf(Bf5));
    __hv_del1_f(&sDel1_me8FL4nE, VIf(ZERO), VOf(Bf3));
    __hv_lt_f(VIf(ZERO), VIf(Bf3), VOf(Bf3));
    __hv_samphold_f(&sSamphold_JQxob8ps, VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf5), 440.0f, 440.0f, 440.0f, 440.0f, 440.0f, 440.0f, 440.0f, 440.0f);
    __hv_var_k_f(VOf(Bf1), 220.0f, 220.0f, 220.0f, 220.0f, 220.0f, 220.0f, 220.0f, 220.0f);
    __hv_fma_f(VIf(Bf3), VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_phasor_f(&sPhasor_pDglqP1H, VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_sYhN3LQe, VOf(Bf5));
    __hv_mul_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf4), 2.5f, 2.5f, 2.5f, 2.5f, 2.5f, 2.5f, 2.5f, 2.5f);
    __hv_div_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf1), VIf(Bf4), VOf(Bf5));
    __hv_varread_f(&sVarf_HwskvUJx, VOf(Bf3));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_z0snXtHr, VOf(Bf5));
    __hv_rpole_f(&sRPole_g6Ry6sxa, VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf0), VIf(Bf5), VOf(Bf3));
    __hv_line_f(&sLine_t8Usze2t, VOf(Bf6));
    __hv_tabhead_f(&sTabhead_5S7UDsKN, VOf(Bf7));
    __hv_var_k_f_r(VOf(Bf8), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_ipJHjSul, VOf(Bf7));
    __hv_mul_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_HYt3yWAS, VOf(Bf6));
    __hv_min_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_zero_f(VOf(Bf7));
    __hv_max_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_floor_f(VIf(Bf7), VOf(Bf8));
    __hv_varread_f(&sVarf_EBECv8VG, VOf(Bf6));
    __hv_zero_f(VOf(Bf9));
    __hv_lt_f(VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_and_f(VIf(Bf6), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_cast_fi(VIf(Bf9), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_m5JMSnQm, VIi(Bi0), VOf(Bf9));
    __hv_tabread_if(&sTabread_BpfX092f, VIi(Bi1), VOf(Bf6));
    __hv_sub_f(VIf(Bf9), VIf(Bf6), VOf(Bf9));
    __hv_sub_f(VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf9), VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_BrnRlOS3, VOf(Bf8));
    __hv_fma_f(VIf(Bf6), VIf(Bf8), VIf(Bf3), VOf(Bf8));
    __hv_line_f(&sLine_LKRb39xS, VOf(Bf6));
    __hv_tabhead_f(&sTabhead_TTcVIYFz, VOf(Bf9));
    __hv_var_k_f_r(VOf(Bf7), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_nYszIQ4f, VOf(Bf9));
    __hv_mul_f(VIf(Bf6), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_ZhDKGkYS, VOf(Bf6));
    __hv_min_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_zero_f(VOf(Bf9));
    __hv_max_f(VIf(Bf6), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_floor_f(VIf(Bf9), VOf(Bf7));
    __hv_varread_f(&sVarf_GX9iSPxG, VOf(Bf6));
    __hv_zero_f(VOf(Bf10));
    __hv_lt_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_and_f(VIf(Bf6), VIf(Bf10), VOf(Bf10));
    __hv_add_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_cast_fi(VIf(Bf10), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_hGd9Cjsw, VIi(Bi0), VOf(Bf10));
    __hv_tabread_if(&sTabread_kliJexTI, VIi(Bi1), VOf(Bf6));
    __hv_sub_f(VIf(Bf10), VIf(Bf6), VOf(Bf10));
    __hv_sub_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf10), VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_LlJVTA5d, VOf(Bf7));
    __hv_mul_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_tabwrite_f(&sTabwrite_C0DOrCc8, VIf(Bf3));
    __hv_tabwrite_f(&sTabwrite_03e0ZJQL, VIf(Bf7));
    __hv_var_k_f(VOf(Bf3), 0.15f, 0.15f, 0.15f, 0.15f, 0.15f, 0.15f, 0.15f, 0.15f);
    __hv_line_f(&sLine_dmsNWyxh, VOf(Bf8));
    __hv_phasor_f(&sPhasor_0mndNZqE, VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_abs_f(VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf8), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf6), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf6), VOf(Bf8));
    __hv_mul_f(VIf(Bf6), VIf(Bf8), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf9), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf11), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf10), VIf(Bf11), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf8), VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_2WoiwUMu, VOf(Bf9));
    __hv_mul_f(VIf(Bf6), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf9), VIf(Bf2), VOf(Bf6));
    __hv_add_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_tabread_f(&sTabread_NfforoI9, VOf(Bf6));
    __hv_varread_i(&sVari_ModgsPP6, VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_cast_if(VIi(Bi0), VOf(Bf8));
    __hv_var_k_f(VOf(Bf11), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf8), VIf(Bf11), VOf(Bf11));
    __hv_varwrite_i(&sVari_ModgsPP6, VIi(Bi0));
    __hv_phasor_k_f(&sPhasor_cMstxnuW, VOf(Bf8));
    __hv_var_k_f(VOf(Bf10), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_abs_f(VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf8), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf10), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf10), VOf(Bf8));
    __hv_mul_f(VIf(Bf10), VIf(Bf8), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf13), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf14), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf12), VIf(Bf14), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf8), VIf(Bf13), VIf(Bf10), VOf(Bf10));
    __hv_add_f(VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_line_f(&sLine_53rY9gEc, VOf(Bf11));
    __hv_varread_f(&sVarf_6O56S4Xl, VOf(Bf13));
    __hv_mul_f(VIf(Bf6), VIf(Bf13), VOf(Bf13));
    __hv_varread_f(&sVarf_g4qf68OI, VOf(Bf8));
    __hv_rpole_f(&sRPole_stWFVLbV, VIf(Bf13), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf13), 0.95f, 0.95f, 0.95f, 0.95f, 0.95f, 0.95f, 0.95f, 0.95f);
    __hv_mul_f(VIf(Bf8), VIf(Bf13), VOf(Bf13));
    __hv_fma_f(VIf(Bf10), VIf(Bf11), VIf(Bf13), VOf(Bf13));
    __hv_tabwrite_f(&sTabwrite_vwkI9rv0, VIf(Bf13));
    __hv_add_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf7), VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf3), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(O0), VOf(O0));
    __hv_var_k_f(VOf(Bf3), 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f);
    __hv_add_f(VIf(Bf0), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf9), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_gTIvVE1i, VOf(Bf1));
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_7g0OilzL, VOf(Bf4));
    __hv_rpole_f(&sRPole_JwNwtTjl, VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf7), VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf3), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
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
