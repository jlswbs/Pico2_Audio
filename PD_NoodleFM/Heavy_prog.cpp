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

float hTable_lvJbLiGL_data[256] = {0.643333f, 0.693333f, 0.703333f, 0.72f, 0.734444f, 0.738889f, 0.743333f, 0.75f, 0.756667f, 0.762222f, 0.767778f, 0.773333f, 0.78f, 0.786667f, 0.793333f, 0.8f, 0.808333f, 0.816667f, 0.825f, 0.833333f, 0.843333f, 0.853333f, 0.858333f, 0.863333f, 0.873333f, 0.883333f, 0.885f, 0.886667f, 0.896667f, 0.896667f, 0.898333f, 0.9f, 0.903333f, 0.906667f, 0.906667f, 0.906667f, 0.908333f, 0.91f, 0.91f, 0.91f, 0.913333f, 0.916667f, 0.918333f, 0.92f, 0.92f, 0.92f, 0.92f, 0.92f, 0.92f, 0.92f, 0.92f, 0.92f, 0.92f, 0.92f, 0.92f, 0.92f, 0.92f, 0.92f, 0.916667f, 0.913333f, 0.91f, 0.907333f, 0.904666f, 0.902f, 0.899333f, 0.896667f, 0.895f, 0.893333f, 0.891667f, 0.89f, 0.889167f, 0.888333f, 0.8875f, 0.886666f, 0.885555f, 0.884444f, 0.883333f, 0.882222f, 0.881111f, 0.88f, 0.878333f, 0.876667f, 0.876667f, 0.873333f, 0.87f, 0.866667f, 0.863333f, 0.86f, 0.858333f, 0.856667f, 0.855f, 0.853333f, 0.85f, 0.846667f, 0.843333f, 0.84f, 0.836667f, 0.833333f, 0.831667f, 0.83f, 0.828333f, 0.826667f, 0.825f, 0.823333f, 0.820555f, 0.817778f, 0.815f, 0.812222f, 0.809444f, 0.806667f, 0.802667f, 0.798667f, 0.794667f, 0.790667f, 0.786667f, 0.783889f, 0.781111f, 0.778333f, 0.775555f, 0.772778f, 0.77f, 0.766667f, 0.763333f, 0.76f, 0.756667f, 0.753333f, 0.75f, 0.746667f, 0.743333f, 0.74f, 0.736667f, 0.733333f, 0.73f, 0.726667f, 0.723333f, 0.72f, 0.716667f, 0.711111f, 0.705556f, 0.7f, 0.693333f, 0.686667f, 0.68f, 0.674445f, 0.668889f, 0.663333f, 0.655f, 0.646667f, 0.636667f, 0.626667f, 0.621111f, 0.615556f, 0.61f, 0.6f, 0.59f, 0.58f, 0.571667f, 0.563333f, 0.558f, 0.552667f, 0.547333f, 0.542f, 0.536667f, 0.533334f, 0.53f, 0.526667f, 0.523334f, 0.52f, 0.516667f, 0.511667f, 0.506667f, 0.501667f, 0.496667f, 0.492667f, 0.488667f, 0.484667f, 0.480667f, 0.476667f, 0.471667f, 0.466667f, 0.461667f, 0.456667f, 0.451334f, 0.446f, 0.440667f, 0.435334f, 0.43f, 0.424445f, 0.418889f, 0.413334f, 0.408889f, 0.404445f, 0.396667f, 0.383334f, 0.38f, 0.373334f, 0.366667f, 0.36f, 0.346667f, 0.341667f, 0.336667f, 0.331667f, 0.326667f, 0.322223f, 0.317778f, 0.313334f, 0.307778f, 0.302223f, 0.296667f, 0.291667f, 0.286667f, 0.28f, 0.278334f, 0.276667f, 0.256667f, 0.246667f, 0.238334f, 0.23f, 0.220001f, 0.216667f, 0.200001f, 0.196667f, 0.186667f, 0.176667f, 0.175001f, 0.170001f, 0.160001f, 0.156667f, 0.151667f, 0.146667f, 0.130001f, 0.123334f, 0.106667f, 0.103333f, 0.103333f, 0.1f, 0.0966667f, 0.095f, 0.0933334f, 0.0911111f, 0.0888889f, 0.0866667f, 0.085f, 0.0833334f, 0.08f, 0.0766667f, 0.0666667f, 0.0666667f, 0.0666667f, 0.0666667f, 0.065f, 0.06f, 0.0566667f, 0.0533333f, 0.0533333f, 0.0333334f};
float hTable_faVCYyc0_data[256] = {0.0666637f, 0.0685156f, 0.0703675f, 0.0722193f, 0.0740712f, 0.075923f, 0.333332f, 0.333332f, 0.333332f, 0.333332f, 0.333332f, 0.333332f, 0.466667f, 0.466667f, 0.466667f, 0.466667f, 0.466667f, 0.386667f, 0.395556f, 0.404444f, 0.413333f, 0.433333f, 0.453333f, 0.476667f, 0.5f, 0.528333f, 0.556666f, 0.626666f, 0.676666f, 0.695f, 0.713333f, 0.725f, 0.74f, 0.75f, 0.75f, 0.746666f, 0.743333f, 0.706666f, 0.693333f, 0.68f, 0.663333f, 0.646666f, 0.63f, 0.613333f, 0.585f, 0.556667f, 0.541111f, 0.525555f, 0.51f, 0.500833f, 0.491667f, 0.4825f, 0.473333f, 0.465555f, 0.457778f, 0.45f, 0.436667f, 0.433333f, 0.426667f, 0.42f, 0.42f, 0.42f, 0.424f, 0.428f, 0.432f, 0.436f, 0.44f, 0.445f, 0.45f, 0.455f, 0.46f, 0.465f, 0.47f, 0.477143f, 0.484286f, 0.491428f, 0.498571f, 0.505714f, 0.512857f, 0.52f, 0.53f, 0.54f, 0.55f, 0.56f, 0.57f, 0.58f, 0.59f, 0.606666f, 0.623333f, 0.64f, 0.657778f, 0.675555f, 0.466667f, 0.456667f, 0.446667f, 0.445556f, 0.444444f, 0.443333f, 0.441667f, 0.44f, 0.44f, 0.44f, 0.44f, 0.44f, 0.44f, 0.44f, 0.440833f, 0.441667f, 0.4425f, 0.443333f, 0.446667f, 0.45f, 0.453333f, 0.456667f, 0.46f, 0.466f, 0.472f, 0.478f, 0.484f, 0.49f, 0.499167f, 0.508333f, 0.5175f, 0.526666f, 0.538889f, 0.551111f, 0.563333f, 0.456667f, 0.44f, 0.423333f, 0.411667f, 0.4f, 0.394444f, 0.388889f, 0.383333f, 0.376667f, 0.37f, 0.368333f, 0.366667f, 0.366667f, 0.366667f, 0.366667f, 0.366667f, 0.366667f, 0.366667f, 0.366667f, 0.366667f, 0.371667f, 0.376667f, 0.381667f, 0.386667f, 0.3925f, 0.398333f, 0.404167f, 0.41f, 0.419333f, 0.428667f, 0.438f, 0.447333f, 0.456667f, 0.470833f, 0.485f, 0.499167f, 0.513333f, 0.533333f, 0.553333f, 0.573333f, 0.593333f, 0.636666f, 0.68f, 0.718333f, 0.756666f, 0.793333f, 0.82f, 0.776666f, 0.493333f, 0.476667f, 0.476667f, 0.476667f, 0.476667f, 0.476667f, 0.476667f, 0.476667f, 0.476667f, 0.479444f, 0.482222f, 0.485f, 0.487778f, 0.490555f, 0.493333f, 0.496111f, 0.498889f, 0.501667f, 0.504444f, 0.507222f, 0.51f, 0.515f, 0.52f, 0.525f, 0.53f, 0.535f, 0.54f, 0.551111f, 0.562222f, 0.573333f, 0.591666f, 0.46f, 0.45f, 0.446667f, 0.446667f, 0.446667f, 0.446667f, 0.446667f, 0.446667f, 0.446667f, 0.448333f, 0.45f, 0.456667f, 0.456667f, 0.448333f, 0.44f, 0.42f, 0.408333f, 0.396667f, 0.386667f, 0.376667f, 0.373333f, 0.37f, 0.37f, 0.37f, 0.37f, 0.37f, 0.37f, 0.37f, 0.37f, 0.37f, 0.37f, 0.37f, 0.37f, 0.373333f, 0.38f, 0.38f, 0.38f, 0.383333f, 0.385f, 0.386667f, 0.39f, 0.391667f, 0.393333f, 0.396667f, 0.403333f, -3.09944e-06f, -3.09944e-06f, -3.09944e-06f, -3.09944e-06f, -3.09944e-06f};



/*
 * Class Functions
 */

Heavy_prog::Heavy_prog(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sPhasor_k_init(&sPhasor_C753b4b4, 110.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_QUCVXl5s, 0.0f, sampleRate);
  numBytes += sTabread_init(&sTabread_dcQFDX0O, &hTable_lvJbLiGL, false);
  numBytes += sRPole_init(&sRPole_UPtwyIgg);
  numBytes += sPhasor_k_init(&sPhasor_M587ym8p, 0.0f, sampleRate);
  numBytes += sDel1_init(&sDel1_wfZtSdd0);
  numBytes += sSamphold_init(&sSamphold_FPQwX9nO);
  numBytes += sDel1_init(&sDel1_ry3DWd1S);
  numBytes += sSamphold_init(&sSamphold_PmqKZGcL);
  numBytes += sPhasor_init(&sPhasor_PLet9XGU, sampleRate);
  numBytes += sPhasor_init(&sPhasor_FMZxZoYt, sampleRate);
  numBytes += sTabread_init(&sTabread_8LzTb8Il, &hTable_faVCYyc0, false);
  numBytes += sPhasor_init(&sPhasor_sNHjiXuu, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_CjRV26IM, 220.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_IVa3auyZ, 0.0f, sampleRate);
  numBytes += sTabread_init(&sTabread_liNiT6Dt, &hTable_lvJbLiGL, false);
  numBytes += sRPole_init(&sRPole_5cgsYbKQ);
  numBytes += sTabread_init(&sTabread_71OqpAPm, &hTable_lvJbLiGL, false);
  numBytes += sPhasor_init(&sPhasor_IzIVOOY7, sampleRate);
  numBytes += hTable_initWithData(&hTable_lvJbLiGL, 256, hTable_lvJbLiGL_data);
  numBytes += cRandom_init(&cRandom_WK1LRdV0, 1847407148);
  numBytes += cSlice_init(&cSlice_MX5DLi8q, 1, 1);
  numBytes += sVari_init(&sVari_UzLx6anC, 0, 0, false);
  numBytes += cVar_init_s(&cVar_BEJmarMh, "soft");
  numBytes += cSlice_init(&cSlice_GdX0firh, 1, 1);
  numBytes += sVarf_init(&sVarf_fpaBEcU4, 0.0f, 0.0f, false);
  numBytes += hTable_initWithData(&hTable_faVCYyc0, 256, hTable_faVCYyc0_data);
  numBytes += cVar_init_s(&cVar_IZBuS5Kf, "hard");
  numBytes += cSlice_init(&cSlice_oZsi7xCi, 1, 1);
  numBytes += sVarf_init(&sVarf_jFULZl59, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_zfV4Yl6k, 1.0f);
  numBytes += cVar_init_f(&cVar_8WwP8MZX, 0.0f);
  numBytes += cVar_init_f(&cVar_waE3m75T, 0.0f);
  numBytes += cVar_init_f(&cVar_0dkCVsIr, 0.0f);
  numBytes += cVar_init_s(&cVar_odVcnI2w, "soft");
  numBytes += cSlice_init(&cSlice_FShT9K55, 1, 1);
  numBytes += sVarf_init(&sVarf_Dh5FMze2, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_MV3BFikQ, 0.0f);
  numBytes += cVar_init_f(&cVar_hPM2L4C5, 20.0f);
  numBytes += cBinop_init(&cBinop_RWvARcPF, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_WtrOixC9, 0.0f);
  numBytes += cSlice_init(&cSlice_sbV92jll, 1, -1);
  numBytes += cSlice_init(&cSlice_E3gE71Xh, 1, -1);
  numBytes += cVar_init_f(&cVar_uLnoWaDo, 0.0f);
  numBytes += cVar_init_f(&cVar_sb2HAKYm, 1.0f);
  numBytes += cVar_init_f(&cVar_cIwx2B7F, 0.0f);
  numBytes += cVar_init_f(&cVar_OlJ7f6UV, 0.0f);
  numBytes += cVar_init_f(&cVar_6lcNjJoK, 0.0f);
  numBytes += cSlice_init(&cSlice_ipNHKD7b, 1, 1);
  numBytes += cSlice_init(&cSlice_g8JThVX8, 0, 1);
  numBytes += cBinop_init(&cBinop_to0uH418, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Ae9dzJc7, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_m2VT0X0B, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_63XhKRCB, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_chZqhCc2, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_bXoGWi0h, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_BUHgxqrL, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_0XIYLLpI, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_HaFVcqqH, 0.0f);
  numBytes += cVar_init_f(&cVar_U6DCEYH7, 0.0f);
  numBytes += cVar_init_f(&cVar_YGC2Z8De, 22050.0f);
  numBytes += cBinop_init(&cBinop_Z26trWiG, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_WhHaMB6w, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ig3w0C6R, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_nr4id9Wf, "soft");
  numBytes += cSlice_init(&cSlice_jj9itnUJ, 1, 1);
  numBytes += sVarf_init(&sVarf_zQb0SQUu, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_xDO5wPDq, 0.0f);
  numBytes += cVar_init_f(&cVar_ZK44swLH, 20.0f);
  numBytes += cBinop_init(&cBinop_6vwESt0s, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_Tx2xkCv1, 0.0f);
  numBytes += cSlice_init(&cSlice_zDHrTlO0, 1, -1);
  numBytes += cSlice_init(&cSlice_trX1ynUL, 1, -1);
  numBytes += cVar_init_f(&cVar_haFlXsHu, 0.0f);
  numBytes += cVar_init_f(&cVar_pLrAy02f, 1.0f);
  numBytes += cVar_init_f(&cVar_qZ7Mg9jw, 0.0f);
  numBytes += cVar_init_f(&cVar_pdY144oz, 0.0f);
  numBytes += cVar_init_f(&cVar_Bq2Ko4ST, 0.0f);
  numBytes += cSlice_init(&cSlice_lDElroan, 1, 1);
  numBytes += cSlice_init(&cSlice_cS62Lsrb, 0, 1);
  numBytes += cBinop_init(&cBinop_iPDvRkfT, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_1LbxG2C7, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_KCX0V5zy, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_vRIjZJuj, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_yhjJYd5V, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_cZksxt5C, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_1GeXzg4N, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_QHSZojX2, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_cCOFNU5o, 0.0f);
  numBytes += cVar_init_f(&cVar_ujjKfFsq, 0.0f);
  numBytes += cVar_init_f(&cVar_A6EOz2MX, 22050.0f);
  numBytes += cBinop_init(&cBinop_sdqd0jNH, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_fODK2IQY, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_X643wL3c, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_pO2tFV3G, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_KPeCqkss, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_EcQdOxSB, 0.0f);
  numBytes += cVar_init_f(&cVar_EUQ3ezXH, 30.0f);
  numBytes += cBinop_init(&cBinop_h2PMVSYP, 0.0f); // __mul
  numBytes += cRandom_init(&cRandom_vyt9MsA0, 422948669);
  numBytes += cSlice_init(&cSlice_WeBnhHFW, 1, 1);
  numBytes += cRandom_init(&cRandom_Bw9kf9uO, 724377669);
  numBytes += cSlice_init(&cSlice_QBPtDShY, 1, 1);
  numBytes += cRandom_init(&cRandom_9YCMRWL7, -1480686983);
  numBytes += cSlice_init(&cSlice_KYQrbbAF, 1, 1);
  numBytes += sVarf_init(&sVarf_FWYh9Vrk, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_KDIYTzno, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_kFJd40nN, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Gv263fd5, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_prog::~Heavy_prog() {
  hTable_free(&hTable_lvJbLiGL);
  hTable_free(&hTable_faVCYyc0);
}

HvTable *Heavy_prog::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x69706D21: return &hTable_lvJbLiGL; // soft
    case 0x726EF81D: return &hTable_faVCYyc0; // hard
    default: return nullptr;
  }
}

void Heavy_prog::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_4nODoDr7_sendMessage);
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


void Heavy_prog::hTable_lvJbLiGL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cSwitchcase_VBjESlg5_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_MX5DLi8q, 0, m, &cSlice_MX5DLi8q_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_WK1LRdV0, 0, m, &cRandom_WK1LRdV0_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_YaIkuKVV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_PDSrBreC_sendMessage);
}

void Heavy_prog::cUnop_PDSrBreC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NU8roKf2_sendMessage(_c, 0, m);
}

void Heavy_prog::cRandom_WK1LRdV0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_YaIkuKVV_sendMessage);
}

void Heavy_prog::cSlice_MX5DLi8q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_WK1LRdV0, 1, m, &cRandom_WK1LRdV0_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cMsg_NU8roKf2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_UzLx6anC, m);
}

void Heavy_prog::cSwitchcase_MxdTsktK_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_GdX0firh, 0, m, &cSlice_GdX0firh_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cVar_BEJmarMh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6kG00Hzz_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_hExdgjag_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_6YAYIL1p_sendMessage);
}

void Heavy_prog::cMsg_6kG00Hzz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_hExdgjag_sendMessage);
}

void Heavy_prog::cSlice_GdX0firh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_71OqpAPm, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_BEJmarMh, 0, m, &cVar_BEJmarMh_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_6YAYIL1p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_fpaBEcU4, m);
}

void Heavy_prog::hTable_faVCYyc0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cSwitchcase_CuahfNpZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_oZsi7xCi, 0, m, &cSlice_oZsi7xCi_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cVar_IZBuS5Kf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WiNXG8Q4_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_kNbQUtWM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ug2U7Naw_sendMessage);
}

void Heavy_prog::cMsg_WiNXG8Q4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_kNbQUtWM_sendMessage);
}

void Heavy_prog::cSlice_oZsi7xCi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_8LzTb8Il, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_IZBuS5Kf, 0, m, &cVar_IZBuS5Kf_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_ug2U7Naw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_jFULZl59, m);
}

void Heavy_prog::cVar_zfV4Yl6k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_pPkrVwXr_sendMessage);
  cSwitchcase_nu8dZGkE_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_pPkrVwXr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zfV4Yl6k, 1, m, &cVar_zfV4Yl6k_sendMessage);
}

void Heavy_prog::cVar_8WwP8MZX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_M587ym8p, 0, m);
  cMsg_zCXyI1vE_sendMessage(_c, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_maXCof0a_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_KPeCqkss, m);
}

void Heavy_prog::cVar_waE3m75T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_PylUBsv7_sendMessage);
  cMsg_ofIQAJ6V_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_0dkCVsIr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 50.0f, 0, m, &cBinop_ZwN5teSY_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 120.0f, 0, m, &cBinop_awdV9gJ0_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_pO2tFV3G, m);
}

void Heavy_prog::cSwitchcase_cuySbm0H_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_FShT9K55, 0, m, &cSlice_FShT9K55_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cVar_odVcnI2w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pZFEcXuc_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_YkAP3oUi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_sGRDLRcw_sendMessage);
}

void Heavy_prog::cMsg_pZFEcXuc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_YkAP3oUi_sendMessage);
}

void Heavy_prog::cSlice_FShT9K55_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_dcQFDX0O, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_odVcnI2w, 0, m, &cVar_odVcnI2w_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_sGRDLRcw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Dh5FMze2, m);
}

void Heavy_prog::cMsg_uFfOvOSb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_gQkUTANm_sendMessage);
}

void Heavy_prog::cSystem_gQkUTANm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ae9dzJc7, HV_BINOP_MULTIPLY, 1, m, &cBinop_Ae9dzJc7_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_to0uH418, HV_BINOP_MULTIPLY, 1, m, &cBinop_to0uH418_sendMessage);
}

void Heavy_prog::cSwitchcase_0IQsOwuZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_twzLPtiy_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_twzLPtiy_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_D2YxX1ra_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_MV3BFikQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_MV3BFikQ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_MV3BFikQ, 0, m, &cDelay_MV3BFikQ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_WtrOixC9, 0, m, &cVar_WtrOixC9_sendMessage);
}

void Heavy_prog::cCast_D2YxX1ra_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_twzLPtiy_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_MV3BFikQ, 0, m, &cDelay_MV3BFikQ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_WtrOixC9, 0, m, &cVar_WtrOixC9_sendMessage);
}

void Heavy_prog::cMsg_dfwL5bVo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Zk4iZOTZ_sendMessage);
}

void Heavy_prog::cSystem_Zk4iZOTZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_xgbUa11P_sendMessage);
}

void Heavy_prog::cVar_hPM2L4C5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RWvARcPF, HV_BINOP_MULTIPLY, 0, m, &cBinop_RWvARcPF_sendMessage);
}

void Heavy_prog::cMsg_twzLPtiy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_MV3BFikQ, 0, m, &cDelay_MV3BFikQ_sendMessage);
}

void Heavy_prog::cBinop_gdzFEccd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_MV3BFikQ, 2, m, &cDelay_MV3BFikQ_sendMessage);
}

void Heavy_prog::cBinop_xgbUa11P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RWvARcPF, HV_BINOP_MULTIPLY, 1, m, &cBinop_RWvARcPF_sendMessage);
}

void Heavy_prog::cBinop_RWvARcPF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_gdzFEccd_sendMessage);
}

void Heavy_prog::cVar_WtrOixC9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_m2VT0X0B, HV_BINOP_SUBTRACT, 0, m, &cBinop_m2VT0X0B_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_hh8Pz5Gn_sendMessage);
}

void Heavy_prog::cSwitchcase_eoTeUCkC_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wcXbxj8V_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qTkABywD_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_wcXbxj8V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6lcNjJoK, 0, m, &cVar_6lcNjJoK_sendMessage);
}

void Heavy_prog::cCast_qTkABywD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2oleM7A7_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZMEek87I_sendMessage);
}

void Heavy_prog::cSwitchcase_Vw1XQNFj_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_sbV92jll, 0, m, &cSlice_sbV92jll_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_E3gE71Xh, 0, m, &cSlice_E3gE71Xh_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Fwhqcvup_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_ipNHKD7b, 0, m, &cSlice_ipNHKD7b_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_g8JThVX8, 0, m, &cSlice_g8JThVX8_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_L3geQkql_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QSkwNlvr_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cSlice_sbV92jll_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_OARDUQkq_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_OARDUQkq_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_E3gE71Xh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7D2GXMJ1_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_gKD6Fwgj_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7D2GXMJ1_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_gKD6Fwgj_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cVar_uLnoWaDo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zBo1b8lb_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_plOchsw4_sendMessage);
}

void Heavy_prog::cVar_sb2HAKYm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_mZwPyW2N_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cSwitchcase_mZwPyW2N_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1sUARX9e_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_Ae9dzJc7, HV_BINOP_MULTIPLY, 0, m, &cBinop_Ae9dzJc7_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_chZqhCc2, HV_BINOP_DIVIDE, 1, m, &cBinop_chZqhCc2_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_hPM2L4C5, 0, m, &cVar_hPM2L4C5_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cCast_1sUARX9e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_14G1QKfN_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_cIwx2B7F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0XIYLLpI, HV_BINOP_SUBTRACT, 1, m, &cBinop_0XIYLLpI_sendMessage);
}

void Heavy_prog::cVar_OlJ7f6UV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6lcNjJoK, 0, m, &cVar_6lcNjJoK_sendMessage);
}

void Heavy_prog::cVar_6lcNjJoK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_63XhKRCB, HV_BINOP_ADD, 0, m, &cBinop_63XhKRCB_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_BUHgxqrL, HV_BINOP_ADD, 0, m, &cBinop_BUHgxqrL_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_HaFVcqqH, 0, m, &cVar_HaFVcqqH_sendMessage);
}

void Heavy_prog::cSlice_ipNHKD7b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zBo1b8lb_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_plOchsw4_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_g8JThVX8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_EnpLZ8kp_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xYO1EKyB_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_n4Sn2zkG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WtrOixC9, 1, m, &cVar_WtrOixC9_sendMessage);
}

void Heavy_prog::cBinop_to0uH418_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_n4Sn2zkG_sendMessage);
}

void Heavy_prog::cBinop_Ae9dzJc7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_SEZykTuc_sendMessage);
}

void Heavy_prog::cBinop_SEZykTuc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_m2VT0X0B, HV_BINOP_SUBTRACT, 1, m, &cBinop_m2VT0X0B_sendMessage);
}

void Heavy_prog::cBinop_m2VT0X0B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WtrOixC9, 1, m, &cVar_WtrOixC9_sendMessage);
}

void Heavy_prog::cMsg_5qP9X8jK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_0IQsOwuZ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_bWfcA5I9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_0IQsOwuZ_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_BUHgxqrL, HV_BINOP_ADD, 1, m, &cBinop_BUHgxqrL_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_63XhKRCB, HV_BINOP_ADD, 1, m, &cBinop_63XhKRCB_sendMessage);
}

void Heavy_prog::cBinop_hh8Pz5Gn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_eoTeUCkC_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_63XhKRCB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6lcNjJoK, 1, m, &cVar_6lcNjJoK_sendMessage);
}

void Heavy_prog::cBinop_chZqhCc2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bXoGWi0h, HV_BINOP_DIVIDE, 1, m, &cBinop_bXoGWi0h_sendMessage);
}

void Heavy_prog::cBinop_bXoGWi0h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BUHgxqrL, HV_BINOP_ADD, 1, m, &cBinop_BUHgxqrL_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_63XhKRCB, HV_BINOP_ADD, 1, m, &cBinop_63XhKRCB_sendMessage);
}

void Heavy_prog::cCast_zBo1b8lb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_to0uH418, HV_BINOP_MULTIPLY, 0, m, &cBinop_to0uH418_sendMessage);
}

void Heavy_prog::cCast_plOchsw4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_chZqhCc2, HV_BINOP_DIVIDE, 0, m, &cBinop_chZqhCc2_sendMessage);
}

void Heavy_prog::cCast_EnpLZ8kp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OlJ7f6UV, 1, m, &cVar_OlJ7f6UV_sendMessage);
}

void Heavy_prog::cCast_xYO1EKyB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0XIYLLpI, HV_BINOP_SUBTRACT, 0, m, &cBinop_0XIYLLpI_sendMessage);
}

void Heavy_prog::cCast_2oleM7A7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bWfcA5I9_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_ZMEek87I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OlJ7f6UV, 0, m, &cVar_OlJ7f6UV_sendMessage);
}

void Heavy_prog::cBinop_BUHgxqrL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cIwx2B7F, 0, m, &cVar_cIwx2B7F_sendMessage);
}

void Heavy_prog::cMsg_OARDUQkq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_0IQsOwuZ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_IV0XQoEP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_uLnoWaDo, 1, m, &cVar_uLnoWaDo_sendMessage);
}

void Heavy_prog::cMsg_14G1QKfN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ae9dzJc7, HV_BINOP_MULTIPLY, 0, m, &cBinop_Ae9dzJc7_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_chZqhCc2, HV_BINOP_DIVIDE, 1, m, &cBinop_chZqhCc2_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_hPM2L4C5, 0, m, &cVar_hPM2L4C5_sendMessage);
}

void Heavy_prog::cCast_gKD6Fwgj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SGHUALRU_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_BUHgxqrL, HV_BINOP_ADD, 0, m, &cBinop_BUHgxqrL_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_6lcNjJoK, 1, m, &cVar_6lcNjJoK_sendMessage);
}

void Heavy_prog::cCast_7D2GXMJ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OARDUQkq_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_0XIYLLpI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bXoGWi0h, HV_BINOP_DIVIDE, 0, m, &cBinop_bXoGWi0h_sendMessage);
}

void Heavy_prog::cCast_SGHUALRU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bWfcA5I9_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_L3geQkql_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5qP9X8jK_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_QSkwNlvr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IV0XQoEP_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_Fwhqcvup_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uLnoWaDo, 0, m, &cVar_uLnoWaDo_sendMessage);
}

void Heavy_prog::cVar_HaFVcqqH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 3000.0f, 0, m, &cBinop_vYsiadxz_sendMessage);
}

void Heavy_prog::cVar_U6DCEYH7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YGC2Z8De, 0, m, &cVar_YGC2Z8De_sendMessage);
}

void Heavy_prog::cVar_YGC2Z8De_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Z26trWiG, HV_BINOP_MULTIPLY, 0, m, &cBinop_Z26trWiG_sendMessage);
}

void Heavy_prog::cMsg_ZzBL8our_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_FUifdNJl_sendMessage);
}

void Heavy_prog::cSystem_FUifdNJl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CEwzv5dT_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_Z26trWiG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_CFWadtW7_sendMessage);
}

void Heavy_prog::cBinop_q33weLCt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Z26trWiG, HV_BINOP_MULTIPLY, 1, m, &cBinop_Z26trWiG_sendMessage);
}

void Heavy_prog::cMsg_CEwzv5dT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_q33weLCt_sendMessage);
}

void Heavy_prog::cBinop_CFWadtW7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_j11l8kFZ_sendMessage);
}

void Heavy_prog::cBinop_j11l8kFZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_bs7AAOK4_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ig3w0C6R, m);
}

void Heavy_prog::cBinop_bs7AAOK4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_WhHaMB6w, m);
}

void Heavy_prog::cBinop_vYsiadxz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_U6DCEYH7, 0, m, &cVar_U6DCEYH7_sendMessage);
}

void Heavy_prog::cMsg_zCXyI1vE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1000.0f);
  cSwitchcase_Vw1XQNFj_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cSwitchcase_vX7XVJDM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_jj9itnUJ, 0, m, &cSlice_jj9itnUJ_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cVar_nr4id9Wf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rUutPVrn_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_PQWdJCcK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_VKyfx96y_sendMessage);
}

void Heavy_prog::cMsg_rUutPVrn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_PQWdJCcK_sendMessage);
}

void Heavy_prog::cSlice_jj9itnUJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_liNiT6Dt, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_nr4id9Wf, 0, m, &cVar_nr4id9Wf_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_VKyfx96y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_zQb0SQUu, m);
}

void Heavy_prog::cMsg_yJ7GgO2h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_WoHRvnPO_sendMessage);
}

void Heavy_prog::cSystem_WoHRvnPO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1LbxG2C7, HV_BINOP_MULTIPLY, 1, m, &cBinop_1LbxG2C7_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_iPDvRkfT, HV_BINOP_MULTIPLY, 1, m, &cBinop_iPDvRkfT_sendMessage);
}

void Heavy_prog::cSwitchcase_Ol2AgiGD_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_KT8ksvDe_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_KT8ksvDe_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HW5lEsMu_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_xDO5wPDq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_xDO5wPDq, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_xDO5wPDq, 0, m, &cDelay_xDO5wPDq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Tx2xkCv1, 0, m, &cVar_Tx2xkCv1_sendMessage);
}

void Heavy_prog::cCast_HW5lEsMu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KT8ksvDe_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_xDO5wPDq, 0, m, &cDelay_xDO5wPDq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Tx2xkCv1, 0, m, &cVar_Tx2xkCv1_sendMessage);
}

void Heavy_prog::cMsg_8qSV018s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xkPnU8Xx_sendMessage);
}

void Heavy_prog::cSystem_xkPnU8Xx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_3R6FZwjg_sendMessage);
}

void Heavy_prog::cVar_ZK44swLH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6vwESt0s, HV_BINOP_MULTIPLY, 0, m, &cBinop_6vwESt0s_sendMessage);
}

void Heavy_prog::cMsg_KT8ksvDe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_xDO5wPDq, 0, m, &cDelay_xDO5wPDq_sendMessage);
}

void Heavy_prog::cBinop_Kn7b3n1D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_xDO5wPDq, 2, m, &cDelay_xDO5wPDq_sendMessage);
}

void Heavy_prog::cBinop_3R6FZwjg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6vwESt0s, HV_BINOP_MULTIPLY, 1, m, &cBinop_6vwESt0s_sendMessage);
}

void Heavy_prog::cBinop_6vwESt0s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_Kn7b3n1D_sendMessage);
}

void Heavy_prog::cVar_Tx2xkCv1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KCX0V5zy, HV_BINOP_SUBTRACT, 0, m, &cBinop_KCX0V5zy_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_FLZkeIhC_sendMessage);
}

void Heavy_prog::cSwitchcase_F09TEjqi_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZDpKFGn0_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cOAPmYfh_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_ZDpKFGn0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Bq2Ko4ST, 0, m, &cVar_Bq2Ko4ST_sendMessage);
}

void Heavy_prog::cCast_cOAPmYfh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vWOpaQEF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4phI5lPW_sendMessage);
}

void Heavy_prog::cSwitchcase_5Tchwy3f_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_zDHrTlO0, 0, m, &cSlice_zDHrTlO0_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_trX1ynUL, 0, m, &cSlice_trX1ynUL_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VWVAkJyn_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_lDElroan, 0, m, &cSlice_lDElroan_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_cS62Lsrb, 0, m, &cSlice_cS62Lsrb_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pBfRswet_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bkEQhq1P_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cSlice_zDHrTlO0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_vgIoIsUX_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_vgIoIsUX_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_trX1ynUL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_X4GIGhCD_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ln6IaUHD_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_X4GIGhCD_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ln6IaUHD_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cVar_haFlXsHu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UtBKOuHD_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nhUuPiOh_sendMessage);
}

void Heavy_prog::cVar_pLrAy02f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_k6FZTyub_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cSwitchcase_k6FZTyub_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WZX5zwpM_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_1LbxG2C7, HV_BINOP_MULTIPLY, 0, m, &cBinop_1LbxG2C7_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_yhjJYd5V, HV_BINOP_DIVIDE, 1, m, &cBinop_yhjJYd5V_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_ZK44swLH, 0, m, &cVar_ZK44swLH_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cCast_WZX5zwpM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nHxlVZLP_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_qZ7Mg9jw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QHSZojX2, HV_BINOP_SUBTRACT, 1, m, &cBinop_QHSZojX2_sendMessage);
}

void Heavy_prog::cVar_pdY144oz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Bq2Ko4ST, 0, m, &cVar_Bq2Ko4ST_sendMessage);
}

void Heavy_prog::cVar_Bq2Ko4ST_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vRIjZJuj, HV_BINOP_ADD, 0, m, &cBinop_vRIjZJuj_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_1GeXzg4N, HV_BINOP_ADD, 0, m, &cBinop_1GeXzg4N_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_cCOFNU5o, 0, m, &cVar_cCOFNU5o_sendMessage);
}

void Heavy_prog::cSlice_lDElroan_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UtBKOuHD_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nhUuPiOh_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_cS62Lsrb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_XcmpDI8S_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QWc1RyI6_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_2O34A7rA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Tx2xkCv1, 1, m, &cVar_Tx2xkCv1_sendMessage);
}

void Heavy_prog::cBinop_iPDvRkfT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_2O34A7rA_sendMessage);
}

void Heavy_prog::cBinop_1LbxG2C7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_CKKt3Axx_sendMessage);
}

void Heavy_prog::cBinop_CKKt3Axx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KCX0V5zy, HV_BINOP_SUBTRACT, 1, m, &cBinop_KCX0V5zy_sendMessage);
}

void Heavy_prog::cBinop_KCX0V5zy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Tx2xkCv1, 1, m, &cVar_Tx2xkCv1_sendMessage);
}

void Heavy_prog::cMsg_PamuUXHw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_Ol2AgiGD_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_RigS9nG9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_Ol2AgiGD_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_1GeXzg4N, HV_BINOP_ADD, 1, m, &cBinop_1GeXzg4N_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_vRIjZJuj, HV_BINOP_ADD, 1, m, &cBinop_vRIjZJuj_sendMessage);
}

void Heavy_prog::cBinop_FLZkeIhC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_F09TEjqi_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_vRIjZJuj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Bq2Ko4ST, 1, m, &cVar_Bq2Ko4ST_sendMessage);
}

void Heavy_prog::cBinop_yhjJYd5V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cZksxt5C, HV_BINOP_DIVIDE, 1, m, &cBinop_cZksxt5C_sendMessage);
}

void Heavy_prog::cBinop_cZksxt5C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1GeXzg4N, HV_BINOP_ADD, 1, m, &cBinop_1GeXzg4N_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_vRIjZJuj, HV_BINOP_ADD, 1, m, &cBinop_vRIjZJuj_sendMessage);
}

void Heavy_prog::cCast_nhUuPiOh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yhjJYd5V, HV_BINOP_DIVIDE, 0, m, &cBinop_yhjJYd5V_sendMessage);
}

void Heavy_prog::cCast_UtBKOuHD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iPDvRkfT, HV_BINOP_MULTIPLY, 0, m, &cBinop_iPDvRkfT_sendMessage);
}

void Heavy_prog::cCast_QWc1RyI6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QHSZojX2, HV_BINOP_SUBTRACT, 0, m, &cBinop_QHSZojX2_sendMessage);
}

void Heavy_prog::cCast_XcmpDI8S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pdY144oz, 1, m, &cVar_pdY144oz_sendMessage);
}

void Heavy_prog::cCast_4phI5lPW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pdY144oz, 0, m, &cVar_pdY144oz_sendMessage);
}

void Heavy_prog::cCast_vWOpaQEF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RigS9nG9_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_1GeXzg4N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qZ7Mg9jw, 0, m, &cVar_qZ7Mg9jw_sendMessage);
}

void Heavy_prog::cMsg_vgIoIsUX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_Ol2AgiGD_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_TGipII8k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_haFlXsHu, 1, m, &cVar_haFlXsHu_sendMessage);
}

void Heavy_prog::cMsg_nHxlVZLP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_1LbxG2C7, HV_BINOP_MULTIPLY, 0, m, &cBinop_1LbxG2C7_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_yhjJYd5V, HV_BINOP_DIVIDE, 1, m, &cBinop_yhjJYd5V_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ZK44swLH, 0, m, &cVar_ZK44swLH_sendMessage);
}

void Heavy_prog::cCast_ln6IaUHD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Tlw7bOn8_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_1GeXzg4N, HV_BINOP_ADD, 0, m, &cBinop_1GeXzg4N_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Bq2Ko4ST, 1, m, &cVar_Bq2Ko4ST_sendMessage);
}

void Heavy_prog::cCast_X4GIGhCD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vgIoIsUX_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_QHSZojX2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cZksxt5C, HV_BINOP_DIVIDE, 0, m, &cBinop_cZksxt5C_sendMessage);
}

void Heavy_prog::cCast_Tlw7bOn8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RigS9nG9_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_VWVAkJyn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_haFlXsHu, 0, m, &cVar_haFlXsHu_sendMessage);
}

void Heavy_prog::cCast_pBfRswet_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PamuUXHw_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_bkEQhq1P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TGipII8k_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_cCOFNU5o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 3000.0f, 0, m, &cBinop_m5TNIf9J_sendMessage);
}

void Heavy_prog::cVar_ujjKfFsq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_A6EOz2MX, 0, m, &cVar_A6EOz2MX_sendMessage);
}

void Heavy_prog::cVar_A6EOz2MX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sdqd0jNH, HV_BINOP_MULTIPLY, 0, m, &cBinop_sdqd0jNH_sendMessage);
}

void Heavy_prog::cMsg_oSR12xZO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_8AXE2xed_sendMessage);
}

void Heavy_prog::cSystem_8AXE2xed_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VUoZ7QBV_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_sdqd0jNH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_688RcFKu_sendMessage);
}

void Heavy_prog::cBinop_uNAE7spE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sdqd0jNH, HV_BINOP_MULTIPLY, 1, m, &cBinop_sdqd0jNH_sendMessage);
}

void Heavy_prog::cMsg_VUoZ7QBV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_uNAE7spE_sendMessage);
}

void Heavy_prog::cBinop_688RcFKu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_frCvKzSn_sendMessage);
}

void Heavy_prog::cBinop_frCvKzSn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Ys734ZHK_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_X643wL3c, m);
}

void Heavy_prog::cBinop_Ys734ZHK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_fODK2IQY, m);
}

void Heavy_prog::cBinop_m5TNIf9J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ujjKfFsq, 0, m, &cVar_ujjKfFsq_sendMessage);
}

void Heavy_prog::cMsg_ofIQAJ6V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1000.0f);
  cSwitchcase_5Tchwy3f_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cSwitchcase_nu8dZGkE_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_XdvoNVIK_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_XdvoNVIK_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nO7DHNH5_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_EcQdOxSB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_EcQdOxSB, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EcQdOxSB, 0, m, &cDelay_EcQdOxSB_sendMessage);
  cSwitchcase_qX8huQk5_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_pdVQEPJ0_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_cygrhSvI_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_nO7DHNH5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XdvoNVIK_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EcQdOxSB, 0, m, &cDelay_EcQdOxSB_sendMessage);
  cSwitchcase_qX8huQk5_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_pdVQEPJ0_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_cygrhSvI_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_rvXqYZGM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_C0RjP20E_sendMessage);
}

void Heavy_prog::cSystem_C0RjP20E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_3wf95yFy_sendMessage);
}

void Heavy_prog::cVar_EUQ3ezXH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_h2PMVSYP, HV_BINOP_MULTIPLY, 0, m, &cBinop_h2PMVSYP_sendMessage);
}

void Heavy_prog::cMsg_XdvoNVIK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_EcQdOxSB, 0, m, &cDelay_EcQdOxSB_sendMessage);
}

void Heavy_prog::cBinop_EGVu9oSr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_EcQdOxSB, 2, m, &cDelay_EcQdOxSB_sendMessage);
}

void Heavy_prog::cBinop_3wf95yFy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_h2PMVSYP, HV_BINOP_MULTIPLY, 1, m, &cBinop_h2PMVSYP_sendMessage);
}

void Heavy_prog::cBinop_h2PMVSYP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_EGVu9oSr_sendMessage);
}

void Heavy_prog::cSwitchcase_qX8huQk5_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_WeBnhHFW, 0, m, &cSlice_WeBnhHFW_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_vyt9MsA0, 0, m, &cRandom_vyt9MsA0_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_t3Rud7Dp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_ikQMXYqq_sendMessage);
}

void Heavy_prog::cUnop_ikQMXYqq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8WwP8MZX, 0, m, &cVar_8WwP8MZX_sendMessage);
}

void Heavy_prog::cRandom_vyt9MsA0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_t3Rud7Dp_sendMessage);
}

void Heavy_prog::cSlice_WeBnhHFW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_vyt9MsA0, 1, m, &cRandom_vyt9MsA0_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_pdVQEPJ0_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_QBPtDShY, 0, m, &cSlice_QBPtDShY_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Bw9kf9uO, 0, m, &cRandom_Bw9kf9uO_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_TkisLvpK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_HaBDkk6h_sendMessage);
}

void Heavy_prog::cUnop_HaBDkk6h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0dkCVsIr, 0, m, &cVar_0dkCVsIr_sendMessage);
}

void Heavy_prog::cRandom_Bw9kf9uO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.0f, 0, m, &cBinop_TkisLvpK_sendMessage);
}

void Heavy_prog::cSlice_QBPtDShY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Bw9kf9uO, 1, m, &cRandom_Bw9kf9uO_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_cygrhSvI_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_KYQrbbAF, 0, m, &cSlice_KYQrbbAF_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_9YCMRWL7, 0, m, &cRandom_9YCMRWL7_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_MKRngERP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_S8Tgv1EJ_sendMessage);
}

void Heavy_prog::cUnop_S8Tgv1EJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_waE3m75T, 0, m, &cVar_waE3m75T_sendMessage);
}

void Heavy_prog::cRandom_9YCMRWL7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 24.0f, 0, m, &cBinop_MKRngERP_sendMessage);
}

void Heavy_prog::cSlice_KYQrbbAF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_9YCMRWL7, 1, m, &cRandom_9YCMRWL7_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_PylUBsv7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_FWYh9Vrk, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_kFJd40nN, m);
}

void Heavy_prog::cBinop_ZwN5teSY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_CjRV26IM, 0, m);
}

void Heavy_prog::cBinop_maXCof0a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_C753b4b4, 0, m);
}

void Heavy_prog::cBinop_awdV9gJ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EUQ3ezXH, 0, m, &cVar_EUQ3ezXH_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_KDIYTzno, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Gv263fd5, m);
}

void Heavy_prog::cReceive_4nODoDr7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dfwL5bVo_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_hPM2L4C5, 0, m, &cVar_hPM2L4C5_sendMessage);
  cMsg_ZzBL8our_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_YGC2Z8De, 0, m, &cVar_YGC2Z8De_sendMessage);
  cMsg_8qSV018s_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ZK44swLH, 0, m, &cVar_ZK44swLH_sendMessage);
  cMsg_oSR12xZO_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_A6EOz2MX, 0, m, &cVar_A6EOz2MX_sendMessage);
  cMsg_uFfOvOSb_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_cIwx2B7F, 0, m, &cVar_cIwx2B7F_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_sb2HAKYm, 0, m, &cVar_sb2HAKYm_sendMessage);
  cMsg_yJ7GgO2h_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_qZ7Mg9jw, 0, m, &cVar_qZ7Mg9jw_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_pLrAy02f, 0, m, &cVar_pLrAy02f_sendMessage);
  cSwitchcase_VBjESlg5_onMessage(_c, NULL, 0, m, NULL);
  cMsg_rvXqYZGM_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_EUQ3ezXH, 0, m, &cVar_EUQ3ezXH_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_zfV4Yl6k, 0, m, &cVar_zfV4Yl6k_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_BEJmarMh, 0, m, &cVar_BEJmarMh_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_IZBuS5Kf, 0, m, &cVar_IZBuS5Kf_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_odVcnI2w, 0, m, &cVar_odVcnI2w_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_nr4id9Wf, 0, m, &cVar_nr4id9Wf_sendMessage);
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
    __hv_phasor_k_f(&sPhasor_C753b4b4, VOf(Bf0));
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
    __hv_phasor_k_f(&sPhasor_QUCVXl5s, VOf(Bf3));
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
    __hv_var_k_f(VOf(Bf2), 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f);
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_Dh5FMze2, VOf(Bf3));
    __hv_min_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_zero_f(VOf(Bf2));
    __hv_max_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_cast_fi(VIf(Bf2), VOi(Bi0));
    __hv_tabread_if(&sTabread_dcQFDX0O, VIi(Bi0), VOf(Bf2));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf0), 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f);
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_ig3w0C6R, VOf(Bf2));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_WhHaMB6w, VOf(Bf0));
    __hv_rpole_f(&sRPole_UPtwyIgg, VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_varread_i(&sVari_UzLx6anC, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varwrite_i(&sVari_UzLx6anC, VIi(Bi1));
    __hv_abs_f(VIf(Bf3), VOf(Bf2));
    __hv_phasor_k_f(&sPhasor_M587ym8p, VOf(Bf5));
    __hv_del1_f(&sDel1_wfZtSdd0, VIf(Bf5), VOf(Bf4));
    __hv_lt_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_samphold_f(&sSamphold_FPQwX9nO, VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_FWYh9Vrk, VOf(Bf6));
    __hv_mul_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_add_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_floor_f(VIf(Bf4), VOf(Bf7));
    __hv_sub_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_del1_f(&sDel1_ry3DWd1S, VIf(Bf7), VOf(Bf4));
    __hv_lt_f(VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_samphold_f(&sSamphold_PmqKZGcL, VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_kFJd40nN, VOf(Bf8));
    __hv_mul_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_Gv263fd5, VOf(Bf4));
    __hv_fma_f(VIf(Bf8), VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_phasor_f(&sPhasor_PLet9XGU, VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf4));
    __hv_mul_f(VIf(Bf1), VIf(Bf4), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf9), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf10), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf8), VIf(Bf10), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf4), VIf(Bf9), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_KDIYTzno, VOf(Bf9));
    __hv_fma_f(VIf(Bf6), VIf(Bf1), VIf(Bf9), VOf(Bf9));
    __hv_phasor_f(&sPhasor_FMZxZoYt, VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_abs_f(VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf9), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf6), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf6), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf6), VOf(Bf9));
    __hv_mul_f(VIf(Bf6), VIf(Bf9), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf10), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf8), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf4), VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf9), VIf(Bf10), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf10), 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f);
    __hv_mul_f(VIf(Bf5), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_jFULZl59, VOf(Bf5));
    __hv_min_f(VIf(Bf10), VIf(Bf5), VOf(Bf5));
    __hv_zero_f(VOf(Bf10));
    __hv_max_f(VIf(Bf5), VIf(Bf10), VOf(Bf10));
    __hv_cast_fi(VIf(Bf10), VOi(Bi1));
    __hv_tabread_if(&sTabread_8LzTb8Il, VIi(Bi1), VOf(Bf10));
    __hv_mul_f(VIf(Bf6), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_pO2tFV3G, VOf(Bf5));
    __hv_min_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_KPeCqkss, VOf(Bf2));
    __hv_max_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf5));
    __hv_sub_f(VIf(Bf2), VIf(Bf5), VOf(Bf2));
    __hv_phasor_f(&sPhasor_sNHjiXuu, VIf(Bf2), VOf(Bf9));
    __hv_var_k_f(VOf(Bf8), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_abs_f(VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf9), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf8), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf8), VOf(Bf9));
    __hv_mul_f(VIf(Bf8), VIf(Bf9), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf11), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf12), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf4), VIf(Bf12), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf9), VIf(Bf11), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf1), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf0), VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf10), 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f);
    __hv_mul_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_add_f(VIf(Bf8), VIf(Bf10), VOf(Bf8));
    __hv_var_k_f(VOf(Bf2), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf8), VIf(Bf2), VOf(Bf8));
    __hv_var_k_f(VOf(Bf3), 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f);
    __hv_mul_f(VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(O0), VOf(O0));
    __hv_phasor_k_f(&sPhasor_CjRV26IM, VOf(Bf3));
    __hv_var_k_f(VOf(Bf8), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_abs_f(VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf8), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf8), VOf(Bf3));
    __hv_mul_f(VIf(Bf8), VIf(Bf3), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf11), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf9), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf0), VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf3), VIf(Bf11), VIf(Bf8), VOf(Bf8));
    __hv_phasor_k_f(&sPhasor_IVa3auyZ, VOf(Bf11));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf11), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf11), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf3), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf11), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf11));
    __hv_mul_f(VIf(Bf3), VIf(Bf11), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf0), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf12), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf9), VIf(Bf12), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf11), VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf0), 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f);
    __hv_mul_f(VIf(Bf8), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_zQb0SQUu, VOf(Bf8));
    __hv_min_f(VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_zero_f(VOf(Bf0));
    __hv_max_f(VIf(Bf8), VIf(Bf0), VOf(Bf0));
    __hv_cast_fi(VIf(Bf0), VOi(Bi1));
    __hv_tabread_if(&sTabread_liNiT6Dt, VIi(Bi1), VOf(Bf0));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf3), 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f);
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_X643wL3c, VOf(Bf0));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_fODK2IQY, VOf(Bf3));
    __hv_rpole_f(&sRPole_5cgsYbKQ, VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf0), 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f);
    __hv_mul_f(VIf(Bf7), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_fpaBEcU4, VOf(Bf7));
    __hv_min_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_zero_f(VOf(Bf0));
    __hv_max_f(VIf(Bf7), VIf(Bf0), VOf(Bf0));
    __hv_cast_fi(VIf(Bf0), VOi(Bi1));
    __hv_tabread_if(&sTabread_71OqpAPm, VIi(Bi1), VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_phasor_f(&sPhasor_IzIVOOY7, VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf1), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf5));
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf8), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf11), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf7), VIf(Bf11), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf5), VIf(Bf8), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf3), VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf1), VIf(Bf10), VOf(Bf10));
    __hv_add_f(VIf(Bf10), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf10), 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f);
    __hv_mul_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_add_f(VIf(Bf10), VIf(O1), VOf(O1));

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
