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

float hTable_RPybrwyL_data[256] = {0.1f, 0.206667f, 0.233333f, 0.24f, 0.266667f, 0.306666f, 0.32f, 0.333333f, 0.35f, 0.353333f, 0.383333f, 0.388333f, 0.393333f, 0.423333f, 0.443333f, 0.45f, 0.473333f, 0.478333f, 0.496666f, 0.506666f, 0.51f, 0.54f, 0.556666f, 0.566666f, 0.573333f, 0.59f, 0.6f, 0.623333f, 0.63f, 0.573333f, 0.586667f, 0.592222f, 0.597778f, 0.603333f, 0.608889f, 0.614444f, 0.62f, 0.624444f, 0.628889f, 0.633333f, 0.641111f, 0.648889f, 0.656667f, 0.661667f, 0.666667f, 0.68f, 0.681667f, 0.686667f, 0.686667f, 0.68f, 0.672222f, 0.664444f, 0.656667f, 0.645555f, 0.634444f, 0.623333f, 0.611111f, 0.598889f, 0.586667f, 0.55f, 0.513333f, 0.46f, 0.45f, 0.433333f, 0.423333f, 0.403333f, 0.396667f, 0.39f, 0.383334f, 0.371667f, 0.36f, 0.35f, 0.343334f, 0.336667f, 0.333334f, 0.326667f, 0.326667f, 0.332222f, 0.337778f, 0.343334f, 0.35f, 0.356667f, 0.363334f, 0.37f, 0.385f, 0.4f, 0.412222f, 0.424445f, 0.436667f, 0.476667f, 0.526667f, 0.546667f, 0.61f, 0.583333f, 0.551667f, 0.52f, 0.493333f, 0.466667f, 0.44f, 0.418889f, 0.397778f, 0.376667f, 0.3625f, 0.348334f, 0.334167f, 0.32f, 0.301667f, 0.283334f, 0.277778f, 0.272222f, 0.266667f, 0.26f, 0.26f, 0.26f, 0.26f, 0.26f, 0.26f, 0.26f, 0.26f, 0.26f, 0.26f, 0.263334f, 0.266667f, 0.27f, 0.273334f, 0.276667f, 0.28f, 0.286667f, 0.293334f, 0.3f, 0.306667f, 0.313334f, 0.321111f, 0.328889f, 0.336667f, 0.344445f, 0.352222f, 0.36f, 0.375333f, 0.390667f, 0.406f, 0.421333f, 0.436667f, 0.449583f, 0.4625f, 0.475417f, 0.488333f, 0.50125f, 0.514167f, 0.527083f, 0.54f, 0.562f, 0.584f, 0.606f, 0.628f, 0.65f, 0.665833f, 0.681667f, 0.6975f, 0.713333f, 0.736667f, 0.76f, 0.78f, 0.791666f, 0.796666f, 0.775f, 0.753333f, 0.69f, 0.646667f, 0.603333f, 0.565f, 0.526667f, 0.48f, 0.466667f, 0.453333f, 0.445f, 0.436667f, 0.433333f, 0.433333f, 0.433333f, 0.433333f, 0.435333f, 0.437333f, 0.439333f, 0.441333f, 0.443334f, 0.447667f, 0.452f, 0.456334f, 0.460667f, 0.465f, 0.469333f, 0.473667f, 0.478f, 0.482333f, 0.486667f, 0.495f, 0.503333f, 0.511667f, 0.52f, 0.528333f, 0.536667f, 0.545f, 0.553333f, 0.561667f, 0.57f, 0.58f, 0.59f, 0.6f, 0.61f, 0.62f, 0.63f, 0.64f, 0.65f, 0.662083f, 0.674167f, 0.68625f, 0.698333f, 0.710417f, 0.7225f, 0.734583f, 0.746667f, 0.757619f, 0.768571f, 0.779524f, 0.790476f, 0.801428f, 0.812381f, 0.823333f, 0.834166f, 0.845f, 0.855833f, 0.866666f, 0.876666f, 0.886666f, 0.893333f, 0.78f, 0.376667f, 0.353333f, 0.333333f, 0.31f, 0.298334f, 0.286667f, 0.266667f, 0.233334f, 0.213334f, 0.183334f, 0.143334f, 0.126667f, 0.11f, 0.101667f, 0.0833337f, 4.76837e-07f, 4.76837e-07f, -0.00333285f, -0.00333285f};
float hTable_YzALYAHs_data[256] = {0.0666637f, 0.0685156f, 0.0703675f, 0.0722193f, 0.0740712f, 0.075923f, 0.333332f, 0.333332f, 0.333332f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.81f, 0.808333f, 0.806667f, 0.805f, 0.803333f, 0.801667f, 0.8f, 0.7975f, 0.795f, 0.7925f, 0.79f, 0.7875f, 0.785f, 0.7825f, 0.78f, 0.778667f, 0.777333f, 0.776f, 0.774667f, 0.773333f, 0.7725f, 0.771667f, 0.770833f, 0.77f, 0.769167f, 0.768333f, 0.7675f, 0.283334f, 0.280001f, 0.276667f, 0.273334f, 0.27f, 0.267334f, 0.264667f, 0.262001f, 0.259334f, 0.256667f, 0.254001f, 0.251334f, 0.248667f, 0.246001f, 0.243334f, 0.240667f, 0.238001f, 0.235334f, 0.232667f, 0.23f, 0.228422f, 0.226843f, 0.225264f, 0.223685f, 0.222106f, 0.220527f, 0.218948f, 0.217369f, 0.21579f, 0.214211f, 0.212632f, 0.211053f, 0.209474f, 0.207895f, 0.206316f, 0.204737f, 0.203158f, 0.20158f, 0.2f, 0.198667f, 0.197334f, 0.196001f, 0.194667f, 0.193334f, 0.192001f, 0.190667f, 0.189334f, 0.188001f, 0.186667f, 0.185334f, 0.184001f, 0.182667f, 0.181334f, 0.180001f, 0.179092f, 0.178182f, 0.177273f, 0.176364f, 0.175455f, 0.174546f, 0.173637f, 0.172728f, 0.171819f, 0.17091f, 0.170001f, 0.169395f, 0.168788f, 0.168182f, 0.167576f, 0.16697f, 0.166364f, 0.165758f, 0.165152f, 0.164546f, 0.16394f, 0.163334f, 0.163334f, 0.163334f, 0.163334f, 0.163334f, 0.163334f, 0.163334f, 0.163334f, 0.163334f, 0.163334f, 0.163334f, 0.163334f, 0.163334f, 0.163334f, 0.163334f, 0.163334f, 0.163334f, 0.163334f, 0.160001f, 0.153334f, 0.153334f, 0.153334f, 0.146667f, 0.146667f, 0.156667f, 0.163334f, 0.200001f, 0.236667f, 0.268334f, 0.813333f, 0.813333f, 0.813333f, 0.8125f, 0.811667f, 0.810833f, 0.81f, 0.807778f, 0.805556f, 0.803333f, 0.801111f, 0.798889f, 0.796667f, 0.795f, 0.793333f, 0.791667f, 0.79f, 0.788333f, 0.786667f, 0.785417f, 0.784167f, 0.782917f, 0.781667f, 0.780417f, 0.779167f, 0.777917f, 0.776667f, 0.775185f, 0.773704f, 0.772222f, 0.770741f, 0.769259f, 0.767778f, 0.766296f, 0.764815f, 0.763333f, 0.7625f, 0.761667f, 0.760833f, 0.76f, 0.759167f, 0.758333f, 0.7575f, 0.756667f, 0.755833f, 0.755f, 0.754167f, 0.753333f, 0.753333f, 0.753333f, 0.753333f, 0.753333f, 0.753333f, 0.753333f, 0.753333f, 0.753333f, 0.756667f, 0.756667f, 0.756667f, 0.756667f, 0.753333f, 0.751111f, 0.748889f, 0.746667f, 0.745f, 0.743333f, 0.743333f, 0.743333f, 0.743333f, 0.38f, 0.383333f, 0.385f, 0.386667f, 0.39f, 0.391667f, 0.393333f, 0.396667f, 0.403333f, -3.09944e-06f, -3.09944e-06f, -3.09944e-06f, -3.09944e-06f, -3.09944e-06f};



/*
 * Class Functions
 */

Heavy_prog::Heavy_prog(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sLine_init(&sLine_Wn4xGTap);
  numBytes += sTabhead_init(&sTabhead_3Jg1d84C, &hTable_ToPW3UQS);
  numBytes += sTabread_init(&sTabread_llG7Hkm1, &hTable_ToPW3UQS, false);
  numBytes += sTabread_init(&sTabread_gMlwLtdZ, &hTable_ToPW3UQS, false);
  numBytes += sPhasor_k_init(&sPhasor_i6IXorOW, 0.0f, sampleRate);
  numBytes += sDel1_init(&sDel1_Mgx5RUVM);
  numBytes += sSamphold_init(&sSamphold_DHHG7BtT);
  numBytes += sPhasor_k_init(&sPhasor_g3ELGpII, 10.0f, sampleRate);
  numBytes += sTabread_init(&sTabread_zZkLsy0S, &hTable_RPybrwyL, false);
  numBytes += sRPole_init(&sRPole_3zvzGcbH);
  numBytes += sDel1_init(&sDel1_WTX9mCyY);
  numBytes += sSamphold_init(&sSamphold_3SoJdobP);
  numBytes += sPhasor_init(&sPhasor_rQRUfaH6, sampleRate);
  numBytes += sPhasor_init(&sPhasor_9tkoB20b, sampleRate);
  numBytes += sLine_init(&sLine_XP150LC0);
  numBytes += sTabread_init(&sTabread_q0Nv109U, &hTable_YzALYAHs, false);
  numBytes += sLine_init(&sLine_PAANS8fd);
  numBytes += sTabwrite_init(&sTabwrite_1LpRqB1M, &hTable_ToPW3UQS);
  numBytes += sPhasor_k_init(&sPhasor_dgHVr5b1, 10.0f, sampleRate);
  numBytes += sTabread_init(&sTabread_2BpHVnS5, &hTable_RPybrwyL, false);
  numBytes += sRPole_init(&sRPole_aHCsP9fw);
  numBytes += sTabread_init(&sTabread_FRPPLcoI, &hTable_RPybrwyL, false);
  numBytes += hTable_initWithData(&hTable_RPybrwyL, 256, hTable_RPybrwyL_data);
  numBytes += cRandom_init(&cRandom_NxmAdL4j, -1870335064);
  numBytes += cSlice_init(&cSlice_7PWKjbuI, 1, 1);
  numBytes += sVari_init(&sVari_ebEiUZe1, 0, 0, false);
  numBytes += cVar_init_s(&cVar_DIdRVfnd, "soft");
  numBytes += cSlice_init(&cSlice_A8fDG0AD, 1, 1);
  numBytes += sVarf_init(&sVarf_0rouOuEK, 0.0f, 0.0f, false);
  numBytes += hTable_initWithData(&hTable_YzALYAHs, 256, hTable_YzALYAHs_data);
  numBytes += cVar_init_s(&cVar_Y3cbda9K, "hard");
  numBytes += cSlice_init(&cSlice_hZVHbfpP, 1, 1);
  numBytes += sVarf_init(&sVarf_EOxSq7SM, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_0ZuVoSqE, 1.0f);
  numBytes += cVar_init_f(&cVar_nOEyHi70, 0.0f);
  numBytes += cVar_init_f(&cVar_XHNXr2pF, 0.0f);
  numBytes += cVar_init_f(&cVar_rYtio41B, 0.0f);
  numBytes += cRandom_init(&cRandom_k2XoZ2w8, 1226126721);
  numBytes += cSlice_init(&cSlice_LY2ZymZR, 1, 1);
  numBytes += cBinop_init(&cBinop_zUL7lbCF, 29.0f); // __div
  numBytes += sVarf_init(&sVarf_saQvZ3iN, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_vrc1CUtI, 29.0f); // __div
  numBytes += sVarf_init(&sVarf_hupngRmY, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_SfawAqxR, 0.0f);
  numBytes += cVar_init_f(&cVar_SnOBO9j0, 30.0f);
  numBytes += cBinop_init(&cBinop_8ZDjxtSd, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_jr8Ca8hg, 1.0f);
  numBytes += cVar_init_f(&cVar_3ZwSbsEc, 1.0f);
  numBytes += cVar_init_s(&cVar_HybCuGtQ, "soft");
  numBytes += cSlice_init(&cSlice_ImyOuUGp, 1, 1);
  numBytes += sVarf_init(&sVarf_AmiAXVq4, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_fdH6qdv2, 0.0f);
  numBytes += cVar_init_f(&cVar_D0cEkarV, 20.0f);
  numBytes += cBinop_init(&cBinop_spsDT5OI, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_wg5qY8bA, 0.0f);
  numBytes += cSlice_init(&cSlice_5g6P4c1V, 1, -1);
  numBytes += cSlice_init(&cSlice_fpHUHaLt, 1, -1);
  numBytes += cVar_init_f(&cVar_FTe6QJjj, 0.0f);
  numBytes += cVar_init_f(&cVar_i0hiHACv, 1.0f);
  numBytes += cVar_init_f(&cVar_8WBEbD2e, 0.0f);
  numBytes += cVar_init_f(&cVar_89VQm834, 0.0f);
  numBytes += cVar_init_f(&cVar_iLmaKfZz, 0.0f);
  numBytes += cSlice_init(&cSlice_ESOTVdZz, 1, 1);
  numBytes += cSlice_init(&cSlice_hRYjz46H, 0, 1);
  numBytes += cBinop_init(&cBinop_VXAgrh9K, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_7FynoUqJ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_DleDTZjq, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_BjZy6IJu, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_9ZXAVl2w, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_Gm1kQSP4, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_zxCa1cjO, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_upcoXnDC, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_2la0ru3u, 0.0f);
  numBytes += cVar_init_f(&cVar_sV6zJ1op, 0.0f);
  numBytes += cVar_init_f(&cVar_PsxYpv36, 22050.0f);
  numBytes += cBinop_init(&cBinop_g3dlt2cL, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_771Hl0qJ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_D9uWrCeC, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_DShILYSK, "soft");
  numBytes += cSlice_init(&cSlice_eWDxf5oR, 1, 1);
  numBytes += sVarf_init(&sVarf_F0N8VNNn, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_bpm8RBsk, 0.0f);
  numBytes += cVar_init_f(&cVar_LAtSLMje, 20.0f);
  numBytes += cBinop_init(&cBinop_qc5I9DdI, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_IcjehQRy, 0.0f);
  numBytes += cSlice_init(&cSlice_VfvZNKCa, 1, -1);
  numBytes += cSlice_init(&cSlice_Kq4bUuIT, 1, -1);
  numBytes += cVar_init_f(&cVar_XZT9R5SK, 0.0f);
  numBytes += cVar_init_f(&cVar_seT2eV2v, 1.0f);
  numBytes += cVar_init_f(&cVar_wl1nnByO, 0.0f);
  numBytes += cVar_init_f(&cVar_NoVIsnBC, 0.0f);
  numBytes += cVar_init_f(&cVar_nnHIaXVT, 0.0f);
  numBytes += cSlice_init(&cSlice_4T7qwEJz, 1, 1);
  numBytes += cSlice_init(&cSlice_D9x4KREN, 0, 1);
  numBytes += cBinop_init(&cBinop_sxFmoikJ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_nWcScPzL, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_KYktjVsA, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_RqvbQYqf, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_ZmOiM4Wf, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_apbEW0CM, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_armmSPWm, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_6fjzYiQw, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_H4piAIN2, 0.0f);
  numBytes += cVar_init_f(&cVar_YCOhlR5C, 0.0f);
  numBytes += cVar_init_f(&cVar_6k5ze4ta, 22050.0f);
  numBytes += cBinop_init(&cBinop_ZusCWYHG, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_YPz7pNXi, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_zVe07gie, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_JxG8mkEi, -407248932);
  numBytes += cSlice_init(&cSlice_UUTRu7aX, 1, 1);
  numBytes += cRandom_init(&cRandom_iS6JIoz8, -2045267236);
  numBytes += cSlice_init(&cSlice_2v6vDrzi, 1, 1);
  numBytes += cIf_init(&cIf_zQRB2P9v, false);
  numBytes += cBinop_init(&cBinop_WxJyEOf4, 12.0f); // __gte
  numBytes += cVar_init_s(&cVar_MIcD3Kku, "del-del");
  numBytes += sVarf_init(&sVarf_Jjf6gCEl, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Aov3NyUl, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_t7y0Bxki, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_BMJ0wvEM, 0.0f);
  numBytes += cVar_init_f(&cVar_hvy9d5nq, 20.0f);
  numBytes += cBinop_init(&cBinop_HBaxAvdu, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_wXWWX23S, 0.0f);
  numBytes += cSlice_init(&cSlice_TGax4pJi, 1, -1);
  numBytes += cSlice_init(&cSlice_KxCPzJVV, 1, -1);
  numBytes += cVar_init_f(&cVar_XCaUsISU, 0.0f);
  numBytes += cVar_init_f(&cVar_ycxLVGkb, 1.0f);
  numBytes += cVar_init_f(&cVar_KfMyo88r, 0.0f);
  numBytes += cVar_init_f(&cVar_0XXKNvAV, 0.0f);
  numBytes += cVar_init_f(&cVar_ORIxzAtG, 0.0f);
  numBytes += cSlice_init(&cSlice_bDzVhOnQ, 1, 1);
  numBytes += cSlice_init(&cSlice_2au1wLlK, 0, 1);
  numBytes += cBinop_init(&cBinop_zkmtqCjL, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_K21HBUVF, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_L46t4IMZ, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_M9mTMyVw, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_9faFPxs1, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_r9CgljTz, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_38Pl3nMq, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_ipAz7kjd, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_LgUyw1tZ, 0.0f);
  numBytes += cDelay_init(this, &cDelay_E7RmBtPd, 0.0f);
  numBytes += cDelay_init(this, &cDelay_ANJncfR0, 0.0f);
  numBytes += hTable_init(&hTable_ToPW3UQS, 256);
  numBytes += sVarf_init(&sVarf_XvZVkes5, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_NW0SJJDr, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_mmmh0Fsa, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_6mRg3hUI, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_prog::~Heavy_prog() {
  hTable_free(&hTable_RPybrwyL);
  hTable_free(&hTable_YzALYAHs);
  hTable_free(&hTable_ToPW3UQS);
}

HvTable *Heavy_prog::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x69706D21: return &hTable_RPybrwyL; // soft
    case 0x726EF81D: return &hTable_YzALYAHs; // hard
    case 0x7BAC8768: return &hTable_ToPW3UQS; // del-del
    default: return nullptr;
  }
}

void Heavy_prog::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_U9k74GC0_sendMessage);
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


void Heavy_prog::hTable_RPybrwyL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cSwitchcase_PUzx5J4j_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_7PWKjbuI, 0, m, &cSlice_7PWKjbuI_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_NxmAdL4j, 0, m, &cRandom_NxmAdL4j_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_Z2ETUH2l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_zUFw6YIe_sendMessage);
}

void Heavy_prog::cUnop_zUFw6YIe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9Hi8Lehd_sendMessage(_c, 0, m);
}

void Heavy_prog::cRandom_NxmAdL4j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_Z2ETUH2l_sendMessage);
}

void Heavy_prog::cSlice_7PWKjbuI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_NxmAdL4j, 1, m, &cRandom_NxmAdL4j_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cMsg_9Hi8Lehd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_ebEiUZe1, m);
}

void Heavy_prog::cSwitchcase_A4TrlUct_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_A8fDG0AD, 0, m, &cSlice_A8fDG0AD_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cVar_DIdRVfnd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0jqJDRfH_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_lE2tvkIQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_YCWHuW0E_sendMessage);
}

void Heavy_prog::cMsg_0jqJDRfH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_lE2tvkIQ_sendMessage);
}

void Heavy_prog::cSlice_A8fDG0AD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_FRPPLcoI, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_DIdRVfnd, 0, m, &cVar_DIdRVfnd_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_YCWHuW0E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_0rouOuEK, m);
}

void Heavy_prog::hTable_YzALYAHs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cSwitchcase_f44YIuir_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_hZVHbfpP, 0, m, &cSlice_hZVHbfpP_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cVar_Y3cbda9K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WPyuVZZF_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_6z2fPESs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_FZQbGmrj_sendMessage);
}

void Heavy_prog::cMsg_WPyuVZZF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6z2fPESs_sendMessage);
}

void Heavy_prog::cSlice_hZVHbfpP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_q0Nv109U, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_Y3cbda9K, 0, m, &cVar_Y3cbda9K_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_FZQbGmrj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_EOxSq7SM, m);
}

void Heavy_prog::cVar_0ZuVoSqE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_NTcDpuIf_sendMessage);
  cSwitchcase_S0cikNAI_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_NTcDpuIf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0ZuVoSqE, 1, m, &cVar_0ZuVoSqE_sendMessage);
}

void Heavy_prog::cVar_nOEyHi70_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_i6IXorOW, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_rbRPtNdU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wqFhdin6_sendMessage);
}

void Heavy_prog::cVar_XHNXr2pF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_UL3nE32M_sendMessage);
}

void Heavy_prog::cVar_rYtio41B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 50.0f, 0, m, &cBinop_kPA0dLJD_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_WxJyEOf4, HV_BINOP_GREATER_THAN_EQL, 1, m, &cBinop_WxJyEOf4_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 60.0f, 0, m, &cBinop_Cuv3H57T_sendMessage);
}

void Heavy_prog::cSwitchcase_S5xfh6CL_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_LY2ZymZR, 0, m, &cSlice_LY2ZymZR_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_k2XoZ2w8, 0, m, &cRandom_k2XoZ2w8_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_3riWEw75_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_6BrnfrRu_sendMessage);
}

void Heavy_prog::cUnop_6BrnfrRu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XHNXr2pF, 0, m, &cVar_XHNXr2pF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NIpxk2Q9_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_WxJyEOf4, HV_BINOP_GREATER_THAN_EQL, 0, m, &cBinop_WxJyEOf4_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_zQRB2P9v, 0, m, &cIf_zQRB2P9v_sendMessage);
}

void Heavy_prog::cRandom_k2XoZ2w8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 24.0f, 0, m, &cBinop_3riWEw75_sendMessage);
}

void Heavy_prog::cSlice_LY2ZymZR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_k2XoZ2w8, 1, m, &cRandom_k2XoZ2w8_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_t1YLww9E_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VK7B9Wl5_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JENHcmIR_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_U58fPOPy_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_VK7B9Wl5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9YIRdBQ1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dC1efwJt_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_M6pfpqYc_sendMessage);
}

void Heavy_prog::cCast_JENHcmIR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VEnwZih7_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qTUbHXbW_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_z1PsCsLt_sendMessage);
}

void Heavy_prog::cCast_U58fPOPy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KNrbREf3_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RBHPkfW8_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SztCNhM2_sendMessage);
}

void Heavy_prog::cCast_RJ6MgK3l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zUL7lbCF, HV_BINOP_DIVIDE, 0, m, &cBinop_zUL7lbCF_sendMessage);
}

void Heavy_prog::cCast_91sfLIvG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DQ2RDtrD_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_RLkz05Bo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 33.9f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_zUL7lbCF, HV_BINOP_DIVIDE, 1, m, &cBinop_zUL7lbCF_sendMessage);
}

void Heavy_prog::cCast_RBHPkfW8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1gL6Rlxv_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_KNrbREf3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_SztCNhM2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8aRKPNJU_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_VEnwZih7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_qTUbHXbW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RLkz05Bo_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_z1PsCsLt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8aRKPNJU_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_M6pfpqYc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8aRKPNJU_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_9YIRdBQ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_dC1efwJt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Wg5YprUu_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_DQ2RDtrD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_PAANS8fd, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_PAANS8fd, 0, m, NULL);
}

void Heavy_prog::cMsg_Wg5YprUu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 30.5f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_zUL7lbCF, HV_BINOP_DIVIDE, 1, m, &cBinop_zUL7lbCF_sendMessage);
}

void Heavy_prog::cMsg_1gL6Rlxv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 36.1f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_zUL7lbCF, HV_BINOP_DIVIDE, 1, m, &cBinop_zUL7lbCF_sendMessage);
}

void Heavy_prog::cBinop_zUL7lbCF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_saQvZ3iN, m);
}

void Heavy_prog::cMsg_8aRKPNJU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 110.0f);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_91sfLIvG_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_RJ6MgK3l_sendMessage);
}

void Heavy_prog::cSwitchcase_ntndhPz8_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_T857R1xP_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gNJ1Wlke_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZgVEWp6e_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_T857R1xP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9SyzrrDf_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Ip4jN9Uc_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ewM44c36_sendMessage);
}

void Heavy_prog::cCast_gNJ1Wlke_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Uqq5fzS1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_96jvUkca_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QX6IspvZ_sendMessage);
}

void Heavy_prog::cCast_ZgVEWp6e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qS9ofKEV_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ajAU4xS3_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3MIfEG3H_sendMessage);
}

void Heavy_prog::cCast_IDE2DtRJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GNlI5elM_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_J0dqboxp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vrc1CUtI, HV_BINOP_DIVIDE, 0, m, &cBinop_vrc1CUtI_sendMessage);
}

void Heavy_prog::cCast_qS9ofKEV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_ajAU4xS3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZXSZc9XK_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_3MIfEG3H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UPVoeEHn_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_QX6IspvZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UPVoeEHn_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_96jvUkca_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vcTAt9hK_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_Uqq5fzS1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_ewM44c36_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UPVoeEHn_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_9SyzrrDf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_Ip4jN9Uc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sYmLvgi1_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_GNlI5elM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_XP150LC0, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_XP150LC0, 0, m, NULL);
}

void Heavy_prog::cBinop_vrc1CUtI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_hupngRmY, m);
}

void Heavy_prog::cMsg_ZXSZc9XK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 30.1f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_vrc1CUtI, HV_BINOP_DIVIDE, 1, m, &cBinop_vrc1CUtI_sendMessage);
}

void Heavy_prog::cMsg_sYmLvgi1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 30.5f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_vrc1CUtI, HV_BINOP_DIVIDE, 1, m, &cBinop_vrc1CUtI_sendMessage);
}

void Heavy_prog::cMsg_vcTAt9hK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 50.9f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_vrc1CUtI, HV_BINOP_DIVIDE, 1, m, &cBinop_vrc1CUtI_sendMessage);
}

void Heavy_prog::cMsg_UPVoeEHn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 440.0f);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IDE2DtRJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_J0dqboxp_sendMessage);
}

void Heavy_prog::cSwitchcase_S0cikNAI_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_ewANWjOr_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_ewANWjOr_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QxlAcxqw_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_SfawAqxR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_SfawAqxR, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SfawAqxR, 0, m, &cDelay_SfawAqxR_sendMessage);
  cSwitchcase_S5xfh6CL_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_HgTx5jVE_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_8QI7YkcU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_QxlAcxqw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ewANWjOr_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_SfawAqxR, 0, m, &cDelay_SfawAqxR_sendMessage);
  cSwitchcase_S5xfh6CL_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_HgTx5jVE_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_8QI7YkcU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_Ux59tf7V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_N7WSYgsY_sendMessage);
}

void Heavy_prog::cSystem_N7WSYgsY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_5k9FiQEC_sendMessage);
}

void Heavy_prog::cVar_SnOBO9j0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8ZDjxtSd, HV_BINOP_MULTIPLY, 0, m, &cBinop_8ZDjxtSd_sendMessage);
}

void Heavy_prog::cMsg_ewANWjOr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_SfawAqxR, 0, m, &cDelay_SfawAqxR_sendMessage);
}

void Heavy_prog::cBinop_jh1QNYEv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_SfawAqxR, 2, m, &cDelay_SfawAqxR_sendMessage);
}

void Heavy_prog::cBinop_5k9FiQEC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8ZDjxtSd, HV_BINOP_MULTIPLY, 1, m, &cBinop_8ZDjxtSd_sendMessage);
}

void Heavy_prog::cBinop_8ZDjxtSd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_jh1QNYEv_sendMessage);
}

void Heavy_prog::cVar_jr8Ca8hg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_zOCOO7KW_sendMessage);
  cMsg_FlFT4gzu_sendMessage(_c, 0, m);
  cMsg_MdYX8rOX_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_zOCOO7KW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jr8Ca8hg, 1, m, &cVar_jr8Ca8hg_sendMessage);
}

void Heavy_prog::cVar_3ZwSbsEc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_rbMoadIv_sendMessage);
  cMsg_8yPlSrws_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_rbMoadIv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3ZwSbsEc, 1, m, &cVar_3ZwSbsEc_sendMessage);
}

void Heavy_prog::cSwitchcase_BVJv4vSA_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ImyOuUGp, 0, m, &cSlice_ImyOuUGp_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cVar_HybCuGtQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_P01Uzsem_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_UBTcnyli_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_zm1B70yt_sendMessage);
}

void Heavy_prog::cMsg_P01Uzsem_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_UBTcnyli_sendMessage);
}

void Heavy_prog::cSlice_ImyOuUGp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_zZkLsy0S, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_HybCuGtQ, 0, m, &cVar_HybCuGtQ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_zm1B70yt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_AmiAXVq4, m);
}

void Heavy_prog::cMsg_ekwuzCWF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_QUd8stx2_sendMessage);
}

void Heavy_prog::cSystem_QUd8stx2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7FynoUqJ, HV_BINOP_MULTIPLY, 1, m, &cBinop_7FynoUqJ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_VXAgrh9K, HV_BINOP_MULTIPLY, 1, m, &cBinop_VXAgrh9K_sendMessage);
}

void Heavy_prog::cSwitchcase_aU2bIAy5_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_CTqYKW19_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_CTqYKW19_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6iDo3esw_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_fdH6qdv2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_fdH6qdv2, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fdH6qdv2, 0, m, &cDelay_fdH6qdv2_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_wg5qY8bA, 0, m, &cVar_wg5qY8bA_sendMessage);
}

void Heavy_prog::cCast_6iDo3esw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CTqYKW19_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fdH6qdv2, 0, m, &cDelay_fdH6qdv2_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_wg5qY8bA, 0, m, &cVar_wg5qY8bA_sendMessage);
}

void Heavy_prog::cMsg_QCsfuRNg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_pdcPZmqi_sendMessage);
}

void Heavy_prog::cSystem_pdcPZmqi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ciY4sDNo_sendMessage);
}

void Heavy_prog::cVar_D0cEkarV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_spsDT5OI, HV_BINOP_MULTIPLY, 0, m, &cBinop_spsDT5OI_sendMessage);
}

void Heavy_prog::cMsg_CTqYKW19_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_fdH6qdv2, 0, m, &cDelay_fdH6qdv2_sendMessage);
}

void Heavy_prog::cBinop_GcoERMzi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_fdH6qdv2, 2, m, &cDelay_fdH6qdv2_sendMessage);
}

void Heavy_prog::cBinop_ciY4sDNo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_spsDT5OI, HV_BINOP_MULTIPLY, 1, m, &cBinop_spsDT5OI_sendMessage);
}

void Heavy_prog::cBinop_spsDT5OI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_GcoERMzi_sendMessage);
}

void Heavy_prog::cVar_wg5qY8bA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DleDTZjq, HV_BINOP_SUBTRACT, 0, m, &cBinop_DleDTZjq_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_zpcS123e_sendMessage);
}

void Heavy_prog::cSwitchcase_B806sm5j_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_68hyqiX6_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ViKC17ZH_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_68hyqiX6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_iLmaKfZz, 0, m, &cVar_iLmaKfZz_sendMessage);
}

void Heavy_prog::cCast_ViKC17ZH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_82E6O9Qx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zcHzbyTc_sendMessage);
}

void Heavy_prog::cSwitchcase_6wBjFsQe_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_5g6P4c1V, 0, m, &cSlice_5g6P4c1V_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_fpHUHaLt, 0, m, &cSlice_fpHUHaLt_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_B36a8uZN_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_ESOTVdZz, 0, m, &cSlice_ESOTVdZz_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_hRYjz46H, 0, m, &cSlice_hRYjz46H_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_a7v4HRuW_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_d2dEagC9_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cSlice_5g6P4c1V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_0p76Drca_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_0p76Drca_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_fpHUHaLt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_s5aEJK1M_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Z6oyN6sZ_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_s5aEJK1M_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Z6oyN6sZ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cVar_FTe6QJjj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_aTWh4Jxk_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_606VL5LI_sendMessage);
}

void Heavy_prog::cVar_i0hiHACv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_heXrX7qJ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cSwitchcase_heXrX7qJ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tMYt1iLh_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_7FynoUqJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_7FynoUqJ_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_9ZXAVl2w, HV_BINOP_DIVIDE, 1, m, &cBinop_9ZXAVl2w_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_D0cEkarV, 0, m, &cVar_D0cEkarV_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cCast_tMYt1iLh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Me6Da1JP_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_8WBEbD2e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_upcoXnDC, HV_BINOP_SUBTRACT, 1, m, &cBinop_upcoXnDC_sendMessage);
}

void Heavy_prog::cVar_89VQm834_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_iLmaKfZz, 0, m, &cVar_iLmaKfZz_sendMessage);
}

void Heavy_prog::cVar_iLmaKfZz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BjZy6IJu, HV_BINOP_ADD, 0, m, &cBinop_BjZy6IJu_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_zxCa1cjO, HV_BINOP_ADD, 0, m, &cBinop_zxCa1cjO_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_2la0ru3u, 0, m, &cVar_2la0ru3u_sendMessage);
}

void Heavy_prog::cSlice_ESOTVdZz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_aTWh4Jxk_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_606VL5LI_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_hRYjz46H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_RXePku6N_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_w5sGTnhf_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_BHTNqq02_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wg5qY8bA, 1, m, &cVar_wg5qY8bA_sendMessage);
}

void Heavy_prog::cBinop_VXAgrh9K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_BHTNqq02_sendMessage);
}

void Heavy_prog::cBinop_7FynoUqJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_sDDcAT5A_sendMessage);
}

void Heavy_prog::cBinop_sDDcAT5A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DleDTZjq, HV_BINOP_SUBTRACT, 1, m, &cBinop_DleDTZjq_sendMessage);
}

void Heavy_prog::cBinop_DleDTZjq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wg5qY8bA, 1, m, &cVar_wg5qY8bA_sendMessage);
}

void Heavy_prog::cMsg_v5UVwLG4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_aU2bIAy5_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_KsJ9mrUA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_aU2bIAy5_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_zxCa1cjO, HV_BINOP_ADD, 1, m, &cBinop_zxCa1cjO_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_BjZy6IJu, HV_BINOP_ADD, 1, m, &cBinop_BjZy6IJu_sendMessage);
}

void Heavy_prog::cBinop_zpcS123e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_B806sm5j_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_BjZy6IJu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_iLmaKfZz, 1, m, &cVar_iLmaKfZz_sendMessage);
}

void Heavy_prog::cBinop_9ZXAVl2w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Gm1kQSP4, HV_BINOP_DIVIDE, 1, m, &cBinop_Gm1kQSP4_sendMessage);
}

void Heavy_prog::cBinop_Gm1kQSP4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zxCa1cjO, HV_BINOP_ADD, 1, m, &cBinop_zxCa1cjO_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_BjZy6IJu, HV_BINOP_ADD, 1, m, &cBinop_BjZy6IJu_sendMessage);
}

void Heavy_prog::cCast_aTWh4Jxk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VXAgrh9K, HV_BINOP_MULTIPLY, 0, m, &cBinop_VXAgrh9K_sendMessage);
}

void Heavy_prog::cCast_606VL5LI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9ZXAVl2w, HV_BINOP_DIVIDE, 0, m, &cBinop_9ZXAVl2w_sendMessage);
}

void Heavy_prog::cCast_w5sGTnhf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_upcoXnDC, HV_BINOP_SUBTRACT, 0, m, &cBinop_upcoXnDC_sendMessage);
}

void Heavy_prog::cCast_RXePku6N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_89VQm834, 1, m, &cVar_89VQm834_sendMessage);
}

void Heavy_prog::cCast_82E6O9Qx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KsJ9mrUA_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_zcHzbyTc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_89VQm834, 0, m, &cVar_89VQm834_sendMessage);
}

void Heavy_prog::cBinop_zxCa1cjO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8WBEbD2e, 0, m, &cVar_8WBEbD2e_sendMessage);
}

void Heavy_prog::cMsg_0p76Drca_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_aU2bIAy5_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_VsCO4u1f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_FTe6QJjj, 1, m, &cVar_FTe6QJjj_sendMessage);
}

void Heavy_prog::cMsg_Me6Da1JP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_7FynoUqJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_7FynoUqJ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_9ZXAVl2w, HV_BINOP_DIVIDE, 1, m, &cBinop_9ZXAVl2w_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_D0cEkarV, 0, m, &cVar_D0cEkarV_sendMessage);
}

void Heavy_prog::cCast_Z6oyN6sZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DNL0Uqoj_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_zxCa1cjO, HV_BINOP_ADD, 0, m, &cBinop_zxCa1cjO_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_iLmaKfZz, 1, m, &cVar_iLmaKfZz_sendMessage);
}

void Heavy_prog::cCast_s5aEJK1M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0p76Drca_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_upcoXnDC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Gm1kQSP4, HV_BINOP_DIVIDE, 0, m, &cBinop_Gm1kQSP4_sendMessage);
}

void Heavy_prog::cCast_DNL0Uqoj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KsJ9mrUA_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_B36a8uZN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FTe6QJjj, 0, m, &cVar_FTe6QJjj_sendMessage);
}

void Heavy_prog::cCast_d2dEagC9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VsCO4u1f_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_a7v4HRuW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_v5UVwLG4_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_2la0ru3u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 3000.0f, 0, m, &cBinop_C42bQUdF_sendMessage);
}

void Heavy_prog::cVar_sV6zJ1op_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PsxYpv36, 0, m, &cVar_PsxYpv36_sendMessage);
}

void Heavy_prog::cVar_PsxYpv36_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_g3dlt2cL, HV_BINOP_MULTIPLY, 0, m, &cBinop_g3dlt2cL_sendMessage);
}

void Heavy_prog::cMsg_6jEL6YOb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_PULZ8onL_sendMessage);
}

void Heavy_prog::cSystem_PULZ8onL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MyYarodY_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_g3dlt2cL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_uVVkLxiV_sendMessage);
}

void Heavy_prog::cBinop_6r1VMRFZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_g3dlt2cL, HV_BINOP_MULTIPLY, 1, m, &cBinop_g3dlt2cL_sendMessage);
}

void Heavy_prog::cMsg_MyYarodY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_6r1VMRFZ_sendMessage);
}

void Heavy_prog::cBinop_uVVkLxiV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_WzRRpJ9N_sendMessage);
}

void Heavy_prog::cBinop_WzRRpJ9N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_JGaTbcrf_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_D9uWrCeC, m);
}

void Heavy_prog::cBinop_JGaTbcrf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_771Hl0qJ, m);
}

void Heavy_prog::cBinop_C42bQUdF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sV6zJ1op, 0, m, &cVar_sV6zJ1op_sendMessage);
}

void Heavy_prog::cMsg_8yPlSrws_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1000.0f);
  cSwitchcase_6wBjFsQe_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cSwitchcase_fFrDgHfs_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_eWDxf5oR, 0, m, &cSlice_eWDxf5oR_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cVar_DShILYSK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_r6Wt5DFl_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_de473Hh0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ssaxiUQO_sendMessage);
}

void Heavy_prog::cMsg_r6Wt5DFl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_de473Hh0_sendMessage);
}

void Heavy_prog::cSlice_eWDxf5oR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_2BpHVnS5, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_DShILYSK, 0, m, &cVar_DShILYSK_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_ssaxiUQO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_F0N8VNNn, m);
}

void Heavy_prog::cMsg_e5auMNvv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_j7jyn2R2_sendMessage);
}

void Heavy_prog::cSystem_j7jyn2R2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nWcScPzL, HV_BINOP_MULTIPLY, 1, m, &cBinop_nWcScPzL_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_sxFmoikJ, HV_BINOP_MULTIPLY, 1, m, &cBinop_sxFmoikJ_sendMessage);
}

void Heavy_prog::cSwitchcase_Qi6p3h9V_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_JpAUte9n_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_JpAUte9n_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YRTv2RPa_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_bpm8RBsk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_bpm8RBsk, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bpm8RBsk, 0, m, &cDelay_bpm8RBsk_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_IcjehQRy, 0, m, &cVar_IcjehQRy_sendMessage);
}

void Heavy_prog::cCast_YRTv2RPa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JpAUte9n_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bpm8RBsk, 0, m, &cDelay_bpm8RBsk_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_IcjehQRy, 0, m, &cVar_IcjehQRy_sendMessage);
}

void Heavy_prog::cMsg_8813EPV5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_dzYM5zHI_sendMessage);
}

void Heavy_prog::cSystem_dzYM5zHI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_rHEiEK7K_sendMessage);
}

void Heavy_prog::cVar_LAtSLMje_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qc5I9DdI, HV_BINOP_MULTIPLY, 0, m, &cBinop_qc5I9DdI_sendMessage);
}

void Heavy_prog::cMsg_JpAUte9n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_bpm8RBsk, 0, m, &cDelay_bpm8RBsk_sendMessage);
}

void Heavy_prog::cBinop_uYrpCHO7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_bpm8RBsk, 2, m, &cDelay_bpm8RBsk_sendMessage);
}

void Heavy_prog::cBinop_rHEiEK7K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qc5I9DdI, HV_BINOP_MULTIPLY, 1, m, &cBinop_qc5I9DdI_sendMessage);
}

void Heavy_prog::cBinop_qc5I9DdI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_uYrpCHO7_sendMessage);
}

void Heavy_prog::cVar_IcjehQRy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KYktjVsA, HV_BINOP_SUBTRACT, 0, m, &cBinop_KYktjVsA_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_0E8gdAW7_sendMessage);
}

void Heavy_prog::cSwitchcase_Cd5emoYZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AR3P6B1S_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EI9HqyFN_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_AR3P6B1S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nnHIaXVT, 0, m, &cVar_nnHIaXVT_sendMessage);
}

void Heavy_prog::cCast_EI9HqyFN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FBJULFho_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_O9IuZjeJ_sendMessage);
}

void Heavy_prog::cSwitchcase_FEBKi0xq_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_VfvZNKCa, 0, m, &cSlice_VfvZNKCa_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Kq4bUuIT, 0, m, &cSlice_Kq4bUuIT_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oF4NkZRC_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_4T7qwEJz, 0, m, &cSlice_4T7qwEJz_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_D9x4KREN, 0, m, &cSlice_D9x4KREN_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VVbNi4Pc_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PKOf85TP_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cSlice_VfvZNKCa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_eJMbC5M9_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_eJMbC5M9_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_Kq4bUuIT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5L21tn6N_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_d5itjuX6_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5L21tn6N_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_d5itjuX6_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cVar_XZT9R5SK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SlawRg8H_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_mvdz8zCg_sendMessage);
}

void Heavy_prog::cVar_seT2eV2v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_w2hin7dg_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cSwitchcase_w2hin7dg_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TLQIdLE1_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_nWcScPzL, HV_BINOP_MULTIPLY, 0, m, &cBinop_nWcScPzL_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_ZmOiM4Wf, HV_BINOP_DIVIDE, 1, m, &cBinop_ZmOiM4Wf_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_LAtSLMje, 0, m, &cVar_LAtSLMje_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cCast_TLQIdLE1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wRuDHKm3_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_wl1nnByO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6fjzYiQw, HV_BINOP_SUBTRACT, 1, m, &cBinop_6fjzYiQw_sendMessage);
}

void Heavy_prog::cVar_NoVIsnBC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nnHIaXVT, 0, m, &cVar_nnHIaXVT_sendMessage);
}

void Heavy_prog::cVar_nnHIaXVT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RqvbQYqf, HV_BINOP_ADD, 0, m, &cBinop_RqvbQYqf_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_armmSPWm, HV_BINOP_ADD, 0, m, &cBinop_armmSPWm_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_H4piAIN2, 0, m, &cVar_H4piAIN2_sendMessage);
}

void Heavy_prog::cSlice_4T7qwEJz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SlawRg8H_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_mvdz8zCg_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_D9x4KREN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SMwFp36D_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_PMiUtajo_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_i0MXIn5d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_IcjehQRy, 1, m, &cVar_IcjehQRy_sendMessage);
}

void Heavy_prog::cBinop_sxFmoikJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_i0MXIn5d_sendMessage);
}

void Heavy_prog::cBinop_nWcScPzL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_BQzaXrHs_sendMessage);
}

void Heavy_prog::cBinop_BQzaXrHs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KYktjVsA, HV_BINOP_SUBTRACT, 1, m, &cBinop_KYktjVsA_sendMessage);
}

void Heavy_prog::cBinop_KYktjVsA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_IcjehQRy, 1, m, &cVar_IcjehQRy_sendMessage);
}

void Heavy_prog::cMsg_qqzuoaMi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_Qi6p3h9V_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_70lT2zuT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_Qi6p3h9V_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_armmSPWm, HV_BINOP_ADD, 1, m, &cBinop_armmSPWm_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_RqvbQYqf, HV_BINOP_ADD, 1, m, &cBinop_RqvbQYqf_sendMessage);
}

void Heavy_prog::cBinop_0E8gdAW7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Cd5emoYZ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_RqvbQYqf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nnHIaXVT, 1, m, &cVar_nnHIaXVT_sendMessage);
}

void Heavy_prog::cBinop_ZmOiM4Wf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_apbEW0CM, HV_BINOP_DIVIDE, 1, m, &cBinop_apbEW0CM_sendMessage);
}

void Heavy_prog::cBinop_apbEW0CM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_armmSPWm, HV_BINOP_ADD, 1, m, &cBinop_armmSPWm_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_RqvbQYqf, HV_BINOP_ADD, 1, m, &cBinop_RqvbQYqf_sendMessage);
}

void Heavy_prog::cCast_mvdz8zCg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZmOiM4Wf, HV_BINOP_DIVIDE, 0, m, &cBinop_ZmOiM4Wf_sendMessage);
}

void Heavy_prog::cCast_SlawRg8H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sxFmoikJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_sxFmoikJ_sendMessage);
}

void Heavy_prog::cCast_PMiUtajo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6fjzYiQw, HV_BINOP_SUBTRACT, 0, m, &cBinop_6fjzYiQw_sendMessage);
}

void Heavy_prog::cCast_SMwFp36D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NoVIsnBC, 1, m, &cVar_NoVIsnBC_sendMessage);
}

void Heavy_prog::cCast_O9IuZjeJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NoVIsnBC, 0, m, &cVar_NoVIsnBC_sendMessage);
}

void Heavy_prog::cCast_FBJULFho_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_70lT2zuT_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_armmSPWm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wl1nnByO, 0, m, &cVar_wl1nnByO_sendMessage);
}

void Heavy_prog::cMsg_eJMbC5M9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_Qi6p3h9V_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_NsK5SY90_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_XZT9R5SK, 1, m, &cVar_XZT9R5SK_sendMessage);
}

void Heavy_prog::cMsg_wRuDHKm3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_nWcScPzL, HV_BINOP_MULTIPLY, 0, m, &cBinop_nWcScPzL_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZmOiM4Wf, HV_BINOP_DIVIDE, 1, m, &cBinop_ZmOiM4Wf_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_LAtSLMje, 0, m, &cVar_LAtSLMje_sendMessage);
}

void Heavy_prog::cCast_5L21tn6N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eJMbC5M9_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_d5itjuX6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WG52xhO0_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_armmSPWm, HV_BINOP_ADD, 0, m, &cBinop_armmSPWm_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_nnHIaXVT, 1, m, &cVar_nnHIaXVT_sendMessage);
}

void Heavy_prog::cBinop_6fjzYiQw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_apbEW0CM, HV_BINOP_DIVIDE, 0, m, &cBinop_apbEW0CM_sendMessage);
}

void Heavy_prog::cCast_WG52xhO0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_70lT2zuT_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_PKOf85TP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NsK5SY90_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_oF4NkZRC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XZT9R5SK, 0, m, &cVar_XZT9R5SK_sendMessage);
}

void Heavy_prog::cCast_VVbNi4Pc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qqzuoaMi_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_H4piAIN2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 3000.0f, 0, m, &cBinop_faGqVW0B_sendMessage);
}

void Heavy_prog::cVar_YCOhlR5C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6k5ze4ta, 0, m, &cVar_6k5ze4ta_sendMessage);
}

void Heavy_prog::cVar_6k5ze4ta_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZusCWYHG, HV_BINOP_MULTIPLY, 0, m, &cBinop_ZusCWYHG_sendMessage);
}

void Heavy_prog::cMsg_caU1RzYj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_GScugVGS_sendMessage);
}

void Heavy_prog::cSystem_GScugVGS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bJxM0Zq5_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_ZusCWYHG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_eW21dpQX_sendMessage);
}

void Heavy_prog::cBinop_L50m1Mow_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZusCWYHG, HV_BINOP_MULTIPLY, 1, m, &cBinop_ZusCWYHG_sendMessage);
}

void Heavy_prog::cMsg_bJxM0Zq5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_L50m1Mow_sendMessage);
}

void Heavy_prog::cBinop_eW21dpQX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_grTuOQs2_sendMessage);
}

void Heavy_prog::cBinop_grTuOQs2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ny98PFUf_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_zVe07gie, m);
}

void Heavy_prog::cBinop_ny98PFUf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_YPz7pNXi, m);
}

void Heavy_prog::cBinop_faGqVW0B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YCOhlR5C, 0, m, &cVar_YCOhlR5C_sendMessage);
}

void Heavy_prog::cMsg_FlFT4gzu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1000.0f);
  cSwitchcase_FEBKi0xq_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cSwitchcase_HgTx5jVE_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_UUTRu7aX, 0, m, &cSlice_UUTRu7aX_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_JxG8mkEi, 0, m, &cRandom_JxG8mkEi_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_5WdJoRC5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_wsrtc66w_sendMessage);
}

void Heavy_prog::cUnop_wsrtc66w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nOEyHi70, 0, m, &cVar_nOEyHi70_sendMessage);
}

void Heavy_prog::cRandom_JxG8mkEi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 16.0f, 0, m, &cBinop_5WdJoRC5_sendMessage);
}

void Heavy_prog::cSlice_UUTRu7aX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_JxG8mkEi, 1, m, &cRandom_JxG8mkEi_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_8QI7YkcU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_2v6vDrzi, 0, m, &cSlice_2v6vDrzi_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_iS6JIoz8, 0, m, &cRandom_iS6JIoz8_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_DYwMHVci_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_rDJdRrbX_sendMessage);
}

void Heavy_prog::cUnop_rDJdRrbX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rYtio41B, 0, m, &cVar_rYtio41B_sendMessage);
}

void Heavy_prog::cRandom_iS6JIoz8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 32.0f, 0, m, &cBinop_DYwMHVci_sendMessage);
}

void Heavy_prog::cSlice_2v6vDrzi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_iS6JIoz8, 1, m, &cRandom_iS6JIoz8_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cIf_zQRB2P9v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_kMtSqZR2_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_yE62pBdh_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_WxJyEOf4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_zQRB2P9v, 1, m, &cIf_zQRB2P9v_sendMessage);
}

void Heavy_prog::cMsg_9SqdVFxV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_2QelaX80_sendMessage);
}

void Heavy_prog::cSystem_2QelaX80_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_hktaKlWF_sendMessage);
}

void Heavy_prog::cVar_MIcD3Kku_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NqokPbQb_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_dz9ksWt7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_a4uSFIya_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Jjf6gCEl, m);
}

void Heavy_prog::cBinop_hktaKlWF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Aov3NyUl, m);
}

void Heavy_prog::cMsg_NqokPbQb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_dz9ksWt7_sendMessage);
}

void Heavy_prog::cBinop_a4uSFIya_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_t7y0Bxki, m);
}

void Heavy_prog::cMsg_V3H9Cqo1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_qbxjeyM5_sendMessage);
}

void Heavy_prog::cSystem_qbxjeyM5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_K21HBUVF, HV_BINOP_MULTIPLY, 1, m, &cBinop_K21HBUVF_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_zkmtqCjL, HV_BINOP_MULTIPLY, 1, m, &cBinop_zkmtqCjL_sendMessage);
}

void Heavy_prog::cSwitchcase_Z1f3RJYd_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_Jcpl7OoL_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_Jcpl7OoL_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AKSubafE_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_BMJ0wvEM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_BMJ0wvEM, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BMJ0wvEM, 0, m, &cDelay_BMJ0wvEM_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_wXWWX23S, 0, m, &cVar_wXWWX23S_sendMessage);
}

void Heavy_prog::cCast_AKSubafE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Jcpl7OoL_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_BMJ0wvEM, 0, m, &cDelay_BMJ0wvEM_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_wXWWX23S, 0, m, &cVar_wXWWX23S_sendMessage);
}

void Heavy_prog::cMsg_YX9oAOCs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1uOOPjn1_sendMessage);
}

void Heavy_prog::cSystem_1uOOPjn1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_PZFcrWBo_sendMessage);
}

void Heavy_prog::cVar_hvy9d5nq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HBaxAvdu, HV_BINOP_MULTIPLY, 0, m, &cBinop_HBaxAvdu_sendMessage);
}

void Heavy_prog::cMsg_Jcpl7OoL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_BMJ0wvEM, 0, m, &cDelay_BMJ0wvEM_sendMessage);
}

void Heavy_prog::cBinop_kwa6daRT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_BMJ0wvEM, 2, m, &cDelay_BMJ0wvEM_sendMessage);
}

void Heavy_prog::cBinop_PZFcrWBo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HBaxAvdu, HV_BINOP_MULTIPLY, 1, m, &cBinop_HBaxAvdu_sendMessage);
}

void Heavy_prog::cBinop_HBaxAvdu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_kwa6daRT_sendMessage);
}

void Heavy_prog::cVar_wXWWX23S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_L46t4IMZ, HV_BINOP_SUBTRACT, 0, m, &cBinop_L46t4IMZ_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_qw3gceKR_sendMessage);
}

void Heavy_prog::cSwitchcase_03Z4l1cW_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XrhaeER5_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4dW4NfKv_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_XrhaeER5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ORIxzAtG, 0, m, &cVar_ORIxzAtG_sendMessage);
}

void Heavy_prog::cCast_4dW4NfKv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UoDYYhgJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VPR9D8uU_sendMessage);
}

void Heavy_prog::cSwitchcase_mBWkjrnn_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_TGax4pJi, 0, m, &cSlice_TGax4pJi_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_KxCPzJVV, 0, m, &cSlice_KxCPzJVV_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nUbw5jhD_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_bDzVhOnQ, 0, m, &cSlice_bDzVhOnQ_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_2au1wLlK, 0, m, &cSlice_2au1wLlK_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4YIrYFgP_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QLvRla8d_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cSlice_TGax4pJi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_KwzqhoKI_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_KwzqhoKI_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_KxCPzJVV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1kDccx21_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_AtY3pVdv_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1kDccx21_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_AtY3pVdv_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cVar_XCaUsISU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_TOgTWy2Q_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Ju9yqpox_sendMessage);
}

void Heavy_prog::cVar_ycxLVGkb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_v97Jw2Yg_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cSwitchcase_v97Jw2Yg_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GOQ5vOCM_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_K21HBUVF, HV_BINOP_MULTIPLY, 0, m, &cBinop_K21HBUVF_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_9faFPxs1, HV_BINOP_DIVIDE, 1, m, &cBinop_9faFPxs1_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_hvy9d5nq, 0, m, &cVar_hvy9d5nq_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cCast_GOQ5vOCM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xnwFIMbC_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_KfMyo88r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ipAz7kjd, HV_BINOP_SUBTRACT, 1, m, &cBinop_ipAz7kjd_sendMessage);
}

void Heavy_prog::cVar_0XXKNvAV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ORIxzAtG, 0, m, &cVar_ORIxzAtG_sendMessage);
}

void Heavy_prog::cVar_ORIxzAtG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_M9mTMyVw, HV_BINOP_ADD, 0, m, &cBinop_M9mTMyVw_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_38Pl3nMq, HV_BINOP_ADD, 0, m, &cBinop_38Pl3nMq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_LgUyw1tZ, 0, m, &cVar_LgUyw1tZ_sendMessage);
}

void Heavy_prog::cSlice_bDzVhOnQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_TOgTWy2Q_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Ju9yqpox_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_2au1wLlK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MW8aldS2_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qfRDuYJ7_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_KuapHPix_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wXWWX23S, 1, m, &cVar_wXWWX23S_sendMessage);
}

void Heavy_prog::cBinop_zkmtqCjL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_KuapHPix_sendMessage);
}

void Heavy_prog::cBinop_K21HBUVF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_9QWjhwdC_sendMessage);
}

void Heavy_prog::cBinop_9QWjhwdC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_L46t4IMZ, HV_BINOP_SUBTRACT, 1, m, &cBinop_L46t4IMZ_sendMessage);
}

void Heavy_prog::cBinop_L46t4IMZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wXWWX23S, 1, m, &cVar_wXWWX23S_sendMessage);
}

void Heavy_prog::cMsg_us4sJybV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_Z1f3RJYd_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_9VYaB8vG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_Z1f3RJYd_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_38Pl3nMq, HV_BINOP_ADD, 1, m, &cBinop_38Pl3nMq_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_M9mTMyVw, HV_BINOP_ADD, 1, m, &cBinop_M9mTMyVw_sendMessage);
}

void Heavy_prog::cBinop_qw3gceKR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_03Z4l1cW_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_M9mTMyVw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ORIxzAtG, 1, m, &cVar_ORIxzAtG_sendMessage);
}

void Heavy_prog::cBinop_9faFPxs1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_r9CgljTz, HV_BINOP_DIVIDE, 1, m, &cBinop_r9CgljTz_sendMessage);
}

void Heavy_prog::cBinop_r9CgljTz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_38Pl3nMq, HV_BINOP_ADD, 1, m, &cBinop_38Pl3nMq_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_M9mTMyVw, HV_BINOP_ADD, 1, m, &cBinop_M9mTMyVw_sendMessage);
}

void Heavy_prog::cCast_TOgTWy2Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zkmtqCjL, HV_BINOP_MULTIPLY, 0, m, &cBinop_zkmtqCjL_sendMessage);
}

void Heavy_prog::cCast_Ju9yqpox_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9faFPxs1, HV_BINOP_DIVIDE, 0, m, &cBinop_9faFPxs1_sendMessage);
}

void Heavy_prog::cCast_qfRDuYJ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ipAz7kjd, HV_BINOP_SUBTRACT, 0, m, &cBinop_ipAz7kjd_sendMessage);
}

void Heavy_prog::cCast_MW8aldS2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0XXKNvAV, 1, m, &cVar_0XXKNvAV_sendMessage);
}

void Heavy_prog::cCast_UoDYYhgJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9VYaB8vG_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_VPR9D8uU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0XXKNvAV, 0, m, &cVar_0XXKNvAV_sendMessage);
}

void Heavy_prog::cBinop_38Pl3nMq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KfMyo88r, 0, m, &cVar_KfMyo88r_sendMessage);
}

void Heavy_prog::cMsg_KwzqhoKI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_Z1f3RJYd_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_eCMEh9Wx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_XCaUsISU, 1, m, &cVar_XCaUsISU_sendMessage);
}

void Heavy_prog::cMsg_xnwFIMbC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_K21HBUVF, HV_BINOP_MULTIPLY, 0, m, &cBinop_K21HBUVF_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_9faFPxs1, HV_BINOP_DIVIDE, 1, m, &cBinop_9faFPxs1_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_hvy9d5nq, 0, m, &cVar_hvy9d5nq_sendMessage);
}

void Heavy_prog::cCast_1kDccx21_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KwzqhoKI_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_AtY3pVdv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UR4cqD1Z_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_38Pl3nMq, HV_BINOP_ADD, 0, m, &cBinop_38Pl3nMq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ORIxzAtG, 1, m, &cVar_ORIxzAtG_sendMessage);
}

void Heavy_prog::cBinop_ipAz7kjd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_r9CgljTz, HV_BINOP_DIVIDE, 0, m, &cBinop_r9CgljTz_sendMessage);
}

void Heavy_prog::cCast_UR4cqD1Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9VYaB8vG_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_nUbw5jhD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XCaUsISU, 0, m, &cVar_XCaUsISU_sendMessage);
}

void Heavy_prog::cCast_QLvRla8d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eCMEh9Wx_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_4YIrYFgP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_us4sJybV_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_LgUyw1tZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 500.0f, 0, m, &cBinop_qJXLDTsp_sendMessage);
}

void Heavy_prog::cMsg_ce0ZlvB6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_O06H60Og_sendMessage);
}

void Heavy_prog::cSystem_O06H60Og_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_1eWf44U3_sendMessage);
}

void Heavy_prog::cDelay_E7RmBtPd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_E7RmBtPd, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ANJncfR0, 0, m, &cDelay_ANJncfR0_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_E7RmBtPd, 0, m, &cDelay_E7RmBtPd_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_1LpRqB1M, 1, m, NULL);
}

void Heavy_prog::cDelay_ANJncfR0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ANJncfR0, m);
  cMsg_kJBUe96a_sendMessage(_c, 0, m);
}

void Heavy_prog::cSwitchcase_TO0V0KMU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_JlRcNtP0_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cBinop_RdbfgFrv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dEsYqyXn_sendMessage(_c, 0, m);
}

void Heavy_prog::hTable_ToPW3UQS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qCVhPtz1_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_E7RmBtPd, 2, m, &cDelay_E7RmBtPd_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uJsqLaQL_sendMessage);
}

void Heavy_prog::cMsg_dEsYqyXn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_ToPW3UQS, 0, m, &hTable_ToPW3UQS_sendMessage);
}

void Heavy_prog::cBinop_1eWf44U3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 500.0f, 0, m, &cBinop_RdbfgFrv_sendMessage);
}

void Heavy_prog::cMsg_kJBUe96a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_ToPW3UQS, 0, m, &hTable_ToPW3UQS_sendMessage);
}

void Heavy_prog::cCast_uJsqLaQL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_E7RmBtPd, 0, m, &cDelay_E7RmBtPd_sendMessage);
}

void Heavy_prog::cMsg_qCVhPtz1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_ANJncfR0, 2, m, &cDelay_ANJncfR0_sendMessage);
}

void Heavy_prog::cMsg_JlRcNtP0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_1LpRqB1M, 1, m, NULL);
}

void Heavy_prog::cBinop_kPA0dLJD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_dgHVr5b1, 0, m);
}

void Heavy_prog::cBinop_rbRPtNdU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_g3ELGpII, 0, m);
}

void Heavy_prog::cMsg_yE62pBdh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_ntndhPz8_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_kMtSqZR2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_t1YLww9E_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_NIpxk2Q9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jr8Ca8hg, 0, m, &cVar_jr8Ca8hg_sendMessage);
}

void Heavy_prog::cCast_wqFhdin6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3ZwSbsEc, 0, m, &cVar_3ZwSbsEc_sendMessage);
}

void Heavy_prog::cBinop_UL3nE32M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_XvZVkes5, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_mmmh0Fsa, m);
}

void Heavy_prog::cMsg_ojRXyRKc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Wn4xGTap, 0, m, NULL);
}

void Heavy_prog::cBinop_Cuv3H57T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_SnOBO9j0, 0, m, &cVar_SnOBO9j0_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_NW0SJJDr, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_6mRg3hUI, m);
}

void Heavy_prog::cMsg_MdYX8rOX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1800.0f);
  cSwitchcase_mBWkjrnn_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_qJXLDTsp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ojRXyRKc_sendMessage(_c, 0, m);
}

void Heavy_prog::cReceive_U9k74GC0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QCsfuRNg_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_D0cEkarV, 0, m, &cVar_D0cEkarV_sendMessage);
  cMsg_6jEL6YOb_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_PsxYpv36, 0, m, &cVar_PsxYpv36_sendMessage);
  cMsg_8813EPV5_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_LAtSLMje, 0, m, &cVar_LAtSLMje_sendMessage);
  cMsg_caU1RzYj_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_6k5ze4ta, 0, m, &cVar_6k5ze4ta_sendMessage);
  cMsg_ekwuzCWF_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_8WBEbD2e, 0, m, &cVar_8WBEbD2e_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_i0hiHACv, 0, m, &cVar_i0hiHACv_sendMessage);
  cMsg_e5auMNvv_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_wl1nnByO, 0, m, &cVar_wl1nnByO_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_seT2eV2v, 0, m, &cVar_seT2eV2v_sendMessage);
  cMsg_YX9oAOCs_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_hvy9d5nq, 0, m, &cVar_hvy9d5nq_sendMessage);
  cSwitchcase_PUzx5J4j_onMessage(_c, NULL, 0, m, NULL);
  cMsg_Ux59tf7V_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_SnOBO9j0, 0, m, &cVar_SnOBO9j0_sendMessage);
  cMsg_V3H9Cqo1_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_KfMyo88r, 0, m, &cVar_KfMyo88r_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ycxLVGkb, 0, m, &cVar_ycxLVGkb_sendMessage);
  cMsg_ce0ZlvB6_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_0ZuVoSqE, 0, m, &cVar_0ZuVoSqE_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_DIdRVfnd, 0, m, &cVar_DIdRVfnd_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Y3cbda9K, 0, m, &cVar_Y3cbda9K_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_HybCuGtQ, 0, m, &cVar_HybCuGtQ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_DShILYSK, 0, m, &cVar_DShILYSK_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_MIcD3Kku, 0, m, &cVar_MIcD3Kku_sendMessage);
  cMsg_9SqdVFxV_sendMessage(_c, 0, m);
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
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5, Bf6, Bf7, Bf8, Bf9, Bf10, Bf11, Bf12, Bf13, Bf14, Bf15, Bf16;
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
    __hv_line_f(&sLine_Wn4xGTap, VOf(Bf0));
    __hv_tabhead_f(&sTabhead_3Jg1d84C, VOf(Bf1));
    __hv_var_k_f_r(VOf(Bf2), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_Aov3NyUl, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_t7y0Bxki, VOf(Bf0));
    __hv_min_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_zero_f(VOf(Bf1));
    __hv_max_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_floor_f(VIf(Bf1), VOf(Bf2));
    __hv_varread_f(&sVarf_Jjf6gCEl, VOf(Bf0));
    __hv_zero_f(VOf(Bf3));
    __hv_lt_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_and_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_cast_fi(VIf(Bf3), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_llG7Hkm1, VIi(Bi1), VOf(Bf3));
    __hv_tabread_if(&sTabread_gMlwLtdZ, VIi(Bi0), VOf(Bf0));
    __hv_sub_f(VIf(Bf3), VIf(Bf0), VOf(Bf3));
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf3), VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_varread_i(&sVari_ebEiUZe1, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf3));
    __hv_var_k_f(VOf(Bf1), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_varwrite_i(&sVari_ebEiUZe1, VIi(Bi1));
    __hv_abs_f(VIf(Bf1), VOf(Bf3));
    __hv_phasor_k_f(&sPhasor_i6IXorOW, VOf(Bf4));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_add_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf6));
    __hv_sub_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_del1_f(&sDel1_Mgx5RUVM, VIf(Bf6), VOf(Bf5));
    __hv_lt_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_samphold_f(&sSamphold_DHHG7BtT, VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_phasor_k_f(&sPhasor_g3ELGpII, VOf(Bf7));
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
    __hv_var_k_f(VOf(Bf10), 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f);
    __hv_mul_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_AmiAXVq4, VOf(Bf7));
    __hv_min_f(VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_zero_f(VOf(Bf10));
    __hv_max_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_cast_fi(VIf(Bf10), VOi(Bi1));
    __hv_tabread_if(&sTabread_zZkLsy0S, VIi(Bi1), VOf(Bf10));
    __hv_var_k_f(VOf(Bf7), 2.5f, 2.5f, 2.5f, 2.5f, 2.5f, 2.5f, 2.5f, 2.5f);
    __hv_mul_f(VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_D9uWrCeC, VOf(Bf10));
    __hv_mul_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_771Hl0qJ, VOf(Bf7));
    __hv_rpole_f(&sRPole_3zvzGcbH, VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_del1_f(&sDel1_WTX9mCyY, VIf(Bf4), VOf(Bf10));
    __hv_lt_f(VIf(Bf4), VIf(Bf10), VOf(Bf10));
    __hv_samphold_f(&sSamphold_3SoJdobP, VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_XvZVkes5, VOf(Bf3));
    __hv_mul_f(VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_mmmh0Fsa, VOf(Bf11));
    __hv_mul_f(VIf(Bf5), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_6mRg3hUI, VOf(Bf9));
    __hv_fma_f(VIf(Bf11), VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_phasor_f(&sPhasor_rQRUfaH6, VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf8), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_abs_f(VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf9), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf8), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf8), VOf(Bf9));
    __hv_mul_f(VIf(Bf8), VIf(Bf9), VOf(Bf11));
    __hv_mul_f(VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf12), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf13), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf11), VIf(Bf13), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf9), VIf(Bf12), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_NW0SJJDr, VOf(Bf12));
    __hv_fma_f(VIf(Bf3), VIf(Bf8), VIf(Bf12), VOf(Bf12));
    __hv_phasor_f(&sPhasor_9tkoB20b, VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf12), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf12), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf3), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf12), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf12));
    __hv_mul_f(VIf(Bf3), VIf(Bf12), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf13), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf11), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf9), VIf(Bf11), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf12), VIf(Bf13), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_XP150LC0, VOf(Bf13));
    __hv_varread_f(&sVarf_hupngRmY, VOf(Bf12));
    __hv_mul_f(VIf(Bf13), VIf(Bf12), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf12), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf13), VOf(Bf12));
    __hv_floor_f(VIf(Bf12), VOf(Bf11));
    __hv_sub_f(VIf(Bf12), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf12), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_abs_f(VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf11), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf12), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf12), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf12), VOf(Bf11));
    __hv_mul_f(VIf(Bf12), VIf(Bf11), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf14), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf15), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf9), VIf(Bf15), VOf(Bf15));
    __hv_sub_f(VIf(Bf12), VIf(Bf15), VOf(Bf15));
    __hv_fma_f(VIf(Bf11), VIf(Bf14), VIf(Bf15), VOf(Bf15));
    __hv_mul_f(VIf(Bf15), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf15), 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f);
    __hv_mul_f(VIf(Bf13), VIf(Bf15), VOf(Bf15));
    __hv_add_f(VIf(Bf3), VIf(Bf15), VOf(Bf13));
    __hv_var_k_f(VOf(Bf14), 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f);
    __hv_mul_f(VIf(Bf4), VIf(Bf14), VOf(Bf14));
    __hv_varread_f(&sVarf_EOxSq7SM, VOf(Bf4));
    __hv_min_f(VIf(Bf14), VIf(Bf4), VOf(Bf4));
    __hv_zero_f(VOf(Bf14));
    __hv_max_f(VIf(Bf4), VIf(Bf14), VOf(Bf14));
    __hv_cast_fi(VIf(Bf14), VOi(Bi1));
    __hv_tabread_if(&sTabread_q0Nv109U, VIi(Bi1), VOf(Bf14));
    __hv_mul_f(VIf(Bf13), VIf(Bf14), VOf(Bf14));
    __hv_line_f(&sLine_PAANS8fd, VOf(Bf13));
    __hv_varread_f(&sVarf_saQvZ3iN, VOf(Bf4));
    __hv_mul_f(VIf(Bf13), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf13), VOf(Bf4));
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
    __hv_mul_f(VIf(Bf4), VIf(Bf11), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf9), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf16), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf12), VIf(Bf16), VOf(Bf16));
    __hv_sub_f(VIf(Bf4), VIf(Bf16), VOf(Bf16));
    __hv_fma_f(VIf(Bf11), VIf(Bf9), VIf(Bf16), VOf(Bf16));
    __hv_mul_f(VIf(Bf16), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf16), 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f, 3.0f);
    __hv_mul_f(VIf(Bf13), VIf(Bf16), VOf(Bf16));
    __hv_add_f(VIf(Bf8), VIf(Bf16), VOf(Bf13));
    __hv_fma_f(VIf(Bf7), VIf(Bf14), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf14), 0.04f, 0.04f, 0.04f, 0.04f, 0.04f, 0.04f, 0.04f, 0.04f);
    __hv_mul_f(VIf(Bf1), VIf(Bf14), VOf(Bf14));
    __hv_add_f(VIf(Bf13), VIf(Bf14), VOf(Bf13));
    __hv_add_f(VIf(Bf5), VIf(Bf13), VOf(Bf13));
    __hv_fma_f(VIf(Bf0), VIf(Bf2), VIf(Bf13), VOf(Bf2));
    __hv_tabwrite_f(&sTabwrite_1LpRqB1M, VIf(Bf2));
    __hv_phasor_k_f(&sPhasor_dgHVr5b1, VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_abs_f(VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf2));
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf7), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf9), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf1), VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf2), VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf7), 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f);
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_F0N8VNNn, VOf(Bf5));
    __hv_min_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_zero_f(VOf(Bf7));
    __hv_max_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_cast_fi(VIf(Bf7), VOi(Bi1));
    __hv_tabread_if(&sTabread_2BpHVnS5, VIi(Bi1), VOf(Bf7));
    __hv_var_k_f(VOf(Bf5), 2.5f, 2.5f, 2.5f, 2.5f, 2.5f, 2.5f, 2.5f, 2.5f);
    __hv_mul_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_zVe07gie, VOf(Bf7));
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_YPz7pNXi, VOf(Bf5));
    __hv_rpole_f(&sRPole_aHCsP9fw, VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf8), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf8), 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f);
    __hv_mul_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_0rouOuEK, VOf(Bf6));
    __hv_min_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_zero_f(VOf(Bf8));
    __hv_max_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_cast_fi(VIf(Bf8), VOi(Bi1));
    __hv_tabread_if(&sTabread_FRPPLcoI, VIi(Bi1), VOf(Bf8));
    __hv_mul_f(VIf(Bf15), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf3), VIf(Bf16), VOf(Bf16));
    __hv_fma_f(VIf(Bf5), VIf(Bf8), VIf(Bf16), VOf(Bf16));
    __hv_add_f(VIf(Bf16), VIf(Bf14), VOf(Bf14));
    __hv_add_f(VIf(Bf10), VIf(Bf14), VOf(Bf14));
    __hv_add_f(VIf(Bf14), VIf(Bf0), VOf(Bf14));
    __hv_var_k_f(VOf(Bf10), 0.02f, 0.02f, 0.02f, 0.02f, 0.02f, 0.02f, 0.02f, 0.02f);
    __hv_mul_f(VIf(Bf14), VIf(Bf10), VOf(Bf10));
    __hv_add_f(VIf(Bf10), VIf(O1), VOf(O1));
    __hv_add_f(VIf(Bf13), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf13), 0.02f, 0.02f, 0.02f, 0.02f, 0.02f, 0.02f, 0.02f, 0.02f);
    __hv_mul_f(VIf(Bf0), VIf(Bf13), VOf(Bf13));
    __hv_add_f(VIf(Bf13), VIf(O0), VOf(O0));

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
