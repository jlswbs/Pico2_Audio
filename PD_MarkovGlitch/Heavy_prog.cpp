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

float hTable_lsi2VL8T_data[256] = {0.16f, 0.196667f, 0.236667f, 0.293334f, 0.323334f, 0.353334f, 0.486667f, 0.526667f, 0.566667f, 0.585f, 0.603333f, 0.623333f, 0.643333f, 0.68f, 0.689167f, 0.698333f, 0.7075f, 0.716667f, 0.728333f, 0.74f, 0.75f, 0.76f, 0.77f, 0.78f, 0.786667f, 0.793333f, 0.8f, 0.806666f, 0.810833f, 0.815f, 0.819166f, 0.823333f, 0.831111f, 0.838889f, 0.846667f, 0.852f, 0.857333f, 0.862666f, 0.868f, 0.873333f, 0.88f, 0.886666f, 0.893333f, 0.9f, 0.905f, 0.91f, 0.916666f, 0.916666f, 0.916666f, 0.916666f, 0.916666f, 0.9075f, 0.898333f, 0.889166f, 0.44f, 0.426667f, 0.413334f, 0.386667f, 0.376667f, 0.366667f, 0.336667f, 0.32f, 0.296667f, 0.285f, 0.273334f, 0.256667f, 0.25f, 0.25f, 0.253334f, 0.255f, 0.256667f, 0.258334f, 0.26f, 0.264445f, 0.268889f, 0.273334f, 0.2775f, 0.281667f, 0.285834f, 0.29f, 0.295334f, 0.300667f, 0.306f, 0.311334f, 0.316667f, 0.324445f, 0.332222f, 0.34f, 0.35f, 0.36f, 0.37f, 0.38f, 0.403334f, 0.426667f, 0.466667f, 0.706667f, 0.733333f, 0.78f, 0.979999f, 0.979583f, 0.979166f, 0.97875f, 0.978333f, 0.977916f, 0.9775f, 0.977083f, 0.976666f, 0.974166f, 0.971666f, 0.969166f, 0.966666f, 0.964166f, 0.961666f, 0.959166f, 0.956666f, 0.953939f, 0.951212f, 0.948485f, 0.945757f, 0.94303f, 0.940303f, 0.937575f, 0.934848f, 0.932121f, 0.929394f, 0.926667f, 0.92375f, 0.920833f, 0.917917f, 0.915f, 0.912083f, 0.909166f, 0.90625f, 0.903333f, 0.9f, 0.896666f, 0.893333f, 0.89f, 0.886666f, 0.883333f, 0.88f, 0.876666f, 0.31f, 0.306667f, 0.305834f, 0.305f, 0.304167f, 0.303334f, 0.302f, 0.300667f, 0.299334f, 0.298f, 0.296667f, 0.295834f, 0.295f, 0.294167f, 0.293334f, 0.292857f, 0.292381f, 0.291905f, 0.291429f, 0.290953f, 0.290477f, 0.29f, 0.288667f, 0.84f, 0.843333f, 0.85f, 0.856666f, 0.856667f, 0.857778f, 0.858889f, 0.86f, 0.86f, 0.86f, 0.86f, 0.86f, 0.86f, 0.86f, 0.86f, 0.86f, 0.857333f, 0.854666f, 0.852f, 0.849333f, 0.846667f, 0.844762f, 0.842857f, 0.840952f, 0.839047f, 0.837143f, 0.835238f, 0.833333f, 0.831666f, 0.83f, 0.828333f, 0.826666f, 0.823333f, 0.82f, 0.816666f, 0.813333f, 0.81f, 0.806666f, 0.803333f, 0.8f, 0.79f, 0.785555f, 0.781111f, 0.776667f, 0.773333f, 0.77f, 0.766667f, 0.763333f, 0.76f, 0.756667f, 0.755f, 0.753333f, 0.753333f, 0.753333f, 0.753333f, 0.751667f, 0.75f, 0.748889f, 0.747778f, 0.746667f, 0.745f, 0.743333f, 0.741667f, 0.74f, 0.738333f, 0.736667f, 0.735f, 0.733333f, 0.731667f, 0.73f, 0.728333f, 0.726667f, 0.723333f, 0.72f, 0.716667f, 0.714444f, 0.712222f, 0.71f, 0.706667f, 0.703333f, 0.7f, 0.697778f, 0.695556f, 0.693333f, 0.691667f, 0.69f, 0.683333f, 0.68f, 0.676667f, 0.673333f, 0.63f};
float hTable_llXpPysK_data[256] = {0.16f, 0.196667f, 0.236667f, 0.293334f, 0.323334f, 0.353334f, 0.486667f, 0.526667f, 0.566667f, 0.585f, 0.603333f, 0.623333f, 0.643333f, 0.68f, 0.689167f, 0.698333f, 0.7075f, 0.716667f, 0.728333f, 0.74f, 0.75f, 0.76f, 0.77f, 0.78f, 0.786667f, 0.793333f, 0.8f, 0.806666f, 0.810833f, 0.815f, 0.819166f, 0.823333f, 0.831111f, 0.838889f, 0.846667f, 0.852f, 0.857333f, 0.862666f, 0.868f, 0.873333f, 0.88f, 0.886666f, 0.893333f, 0.9f, 0.905f, 0.91f, 0.916666f, 0.916666f, 0.916666f, 0.916666f, 0.916666f, 0.9075f, 0.898333f, 0.889166f, 0.44f, 0.426667f, 0.413334f, 0.386667f, 0.376667f, 0.366667f, 0.336667f, 0.32f, 0.296667f, 0.285f, 0.273334f, 0.256667f, 0.25f, 0.25f, 0.253334f, 0.255f, 0.256667f, 0.258334f, 0.26f, 0.264445f, 0.268889f, 0.273334f, 0.2775f, 0.281667f, 0.285834f, 0.29f, 0.295334f, 0.300667f, 0.306f, 0.311334f, 0.316667f, 0.324445f, 0.332222f, 0.34f, 0.35f, 0.36f, 0.37f, 0.38f, 0.403334f, 0.426667f, 0.466667f, 0.706667f, 0.733333f, 0.78f, 0.979999f, 0.979583f, 0.979166f, 0.97875f, 0.978333f, 0.977916f, 0.9775f, 0.977083f, 0.976666f, 0.974166f, 0.971666f, 0.969166f, 0.966666f, 0.964166f, 0.961666f, 0.959166f, 0.956666f, 0.953939f, 0.951212f, 0.948485f, 0.945757f, 0.94303f, 0.940303f, 0.937575f, 0.934848f, 0.932121f, 0.929394f, 0.926667f, 0.92375f, 0.920833f, 0.917917f, 0.915f, 0.912083f, 0.909166f, 0.90625f, 0.903333f, 0.9f, 0.896666f, 0.893333f, 0.89f, 0.886666f, 0.883333f, 0.88f, 0.876666f, 0.31f, 0.306667f, 0.305834f, 0.305f, 0.304167f, 0.303334f, 0.302f, 0.300667f, 0.299334f, 0.298f, 0.296667f, 0.295834f, 0.295f, 0.294167f, 0.293334f, 0.292857f, 0.292381f, 0.291905f, 0.291429f, 0.290953f, 0.290477f, 0.29f, 0.288667f, 0.84f, 0.843333f, 0.85f, 0.856666f, 0.856667f, 0.857778f, 0.858889f, 0.86f, 0.86f, 0.86f, 0.86f, 0.86f, 0.86f, 0.86f, 0.86f, 0.86f, 0.857333f, 0.854666f, 0.852f, 0.849333f, 0.846667f, 0.844762f, 0.842857f, 0.840952f, 0.839047f, 0.837143f, 0.835238f, 0.833333f, 0.831666f, 0.83f, 0.828333f, 0.826666f, 0.823333f, 0.82f, 0.816666f, 0.813333f, 0.81f, 0.806666f, 0.803333f, 0.8f, 0.79f, 0.785555f, 0.781111f, 0.776667f, 0.773333f, 0.77f, 0.766667f, 0.763333f, 0.76f, 0.756667f, 0.755f, 0.753333f, 0.753333f, 0.753333f, 0.753333f, 0.751667f, 0.75f, 0.748889f, 0.747778f, 0.746667f, 0.745f, 0.743333f, 0.741667f, 0.74f, 0.738333f, 0.736667f, 0.735f, 0.733333f, 0.731667f, 0.73f, 0.728333f, 0.726667f, 0.723333f, 0.72f, 0.716667f, 0.714444f, 0.712222f, 0.71f, 0.706667f, 0.703333f, 0.7f, 0.697778f, 0.695556f, 0.693333f, 0.691667f, 0.69f, 0.683333f, 0.68f, 0.676667f, 0.673333f, 0.63f};



/*
 * Class Functions
 */

Heavy_prog::Heavy_prog(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sPhasor_k_init(&sPhasor_Cy545AmJ, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_j1i4fTBC, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_XFm9zecC);
  numBytes += sPhasor_init(&sPhasor_bXyNIWmJ, sampleRate);
  numBytes += sLine_init(&sLine_qGbFiov5);
  numBytes += sPhasor_init(&sPhasor_cc3BH84m, sampleRate);
  numBytes += sLine_init(&sLine_JIaJBOYI);
  numBytes += sPhasor_init(&sPhasor_Sk5QJxKv, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_FkXRaxJc, 0.0f, sampleRate);
  numBytes += sTabread_init(&sTabread_PxVbxWOm, &hTable_llXpPysK, false);
  numBytes += sRPole_init(&sRPole_Ge2MRIXu);
  numBytes += sLine_init(&sLine_5qnKEH7x);
  numBytes += sPhasor_k_init(&sPhasor_qPd4kw7N, 230.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_haU9R7Ky);
  numBytes += sDel1_init(&sDel1_Iaprhhpm);
  numBytes += sTabread_init(&sTabread_gmREo7Wb, &hTable_V9zw9Tef, true);
  numBytes += sTabwrite_init(&sTabwrite_IoyIZfBL, &hTable_V9zw9Tef);
  numBytes += sPhasor_k_init(&sPhasor_3G2Lz06L, 700.0f, sampleRate);
  numBytes += sLine_init(&sLine_X69Ir8I5);
  numBytes += sPhasor_k_init(&sPhasor_gaXHzdUd, 0.0f, sampleRate);
  numBytes += sTabread_init(&sTabread_jpAzKPrF, &hTable_lsi2VL8T, false);
  numBytes += sRPole_init(&sRPole_5SykEgRW);
  numBytes += cVar_init_f(&cVar_AaymSuam, 1.0f);
  numBytes += cPack_init(&cPack_sZ5s1iVH, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_ufQ4GwgW, 4, 1);
  numBytes += cSlice_init(&cSlice_Knnhwb3J, 3, 1);
  numBytes += cSlice_init(&cSlice_Wcz7WzWV, 2, 1);
  numBytes += cSlice_init(&cSlice_xC42wDze, 1, 1);
  numBytes += cSlice_init(&cSlice_vkyD4CNF, 0, 1);
  numBytes += sVarf_init(&sVarf_DSDJJAQs, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_cjJiRDOr, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_58od7xBU, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_GX4tbW3s, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_xNLlPo1V, 0.0f);
  numBytes += cVar_init_f(&cVar_e4QymLdf, 0.0f);
  numBytes += cBinop_init(&cBinop_EoSecKjI, 2.0f); // __mul
  numBytes += cRandom_init(&cRandom_wMjcVEo1, 646388344);
  numBytes += cSlice_init(&cSlice_LP3oWV7t, 1, 1);
  numBytes += cDelay_init(this, &cDelay_bBTtV8IN, 0.0f);
  numBytes += cVar_init_f(&cVar_BoxfpylM, 240.0f);
  numBytes += cBinop_init(&cBinop_BMPspxET, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_jzQfGko0, 0.0f);
  numBytes += cBinop_init(&cBinop_XqnvFfnA, 2.0f); // __mul
  numBytes += cRandom_init(&cRandom_NTC0mvCA, -255880935);
  numBytes += cSlice_init(&cSlice_IVNZYHjh, 1, 1);
  numBytes += cDelay_init(this, &cDelay_gO8cLOrs, 0.0f);
  numBytes += cVar_init_f(&cVar_bZuXaWrF, 20.0f);
  numBytes += cBinop_init(&cBinop_Dq7bONjL, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_ElJORIDv, 0.0f);
  numBytes += cSlice_init(&cSlice_GIJmB4oZ, 1, -1);
  numBytes += cSlice_init(&cSlice_lKBokOjn, 1, -1);
  numBytes += cVar_init_f(&cVar_8KokHKUH, 0.0f);
  numBytes += cVar_init_f(&cVar_rccISklN, 1.0f);
  numBytes += cVar_init_f(&cVar_ML9W6yhG, 0.0f);
  numBytes += cVar_init_f(&cVar_u7WZHMSj, 0.0f);
  numBytes += cVar_init_f(&cVar_HIy6rrwg, 0.0f);
  numBytes += cSlice_init(&cSlice_3WCwzqns, 1, 1);
  numBytes += cSlice_init(&cSlice_6iKcFTkA, 0, 1);
  numBytes += cBinop_init(&cBinop_bQkgiB8b, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Z2D1AoPy, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_9jYSAvtU, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_9JB30LYR, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_Vp3GB4ip, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_GiFpQrWi, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_QxUtNsV5, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_gYX6vNvh, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_ZSntXjca, 0.0f);
  numBytes += cVar_init_f(&cVar_qE4biTdr, 0.0f);
  numBytes += cVar_init_f(&cVar_eygmU38y, 22050.0f);
  numBytes += cBinop_init(&cBinop_LmwgQNFu, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_wUHthjko, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_YmrUviDO, 0.0f, 0.0f, false);
  numBytes += hTable_initWithData(&hTable_lsi2VL8T, 256, hTable_lsi2VL8T_data);
  numBytes += cVar_init_s(&cVar_6EV6DgMZ, "1029-table");
  numBytes += cSlice_init(&cSlice_NAxXAOJi, 1, 1);
  numBytes += sVarf_init(&sVarf_wpKlUsaX, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_LL4hFhfW, 0.0f);
  numBytes += cVar_init_f(&cVar_7jwJfvj3, 20.0f);
  numBytes += cBinop_init(&cBinop_Em6z35fL, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_ciet6Cgu, 0.0f);
  numBytes += cSlice_init(&cSlice_2EDI0i1v, 1, -1);
  numBytes += cSlice_init(&cSlice_8BSPdje3, 1, -1);
  numBytes += cVar_init_f(&cVar_joRAMf4s, 0.0f);
  numBytes += cVar_init_f(&cVar_nSNuEzbs, 1.0f);
  numBytes += cVar_init_f(&cVar_QBCAlWsG, 0.0f);
  numBytes += cVar_init_f(&cVar_JX7ANc3D, 0.0f);
  numBytes += cVar_init_f(&cVar_3Vsfx1EA, 0.0f);
  numBytes += cSlice_init(&cSlice_TeQErGi0, 1, 1);
  numBytes += cSlice_init(&cSlice_qNs2lfsT, 0, 1);
  numBytes += cBinop_init(&cBinop_l89cWWiU, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_o56S8kpL, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_fiddwMlu, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_eC3H1Nm2, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_KhsrWRPo, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_A1uvxR4z, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_nzXACSy9, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_Wsuhkue2, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_ELynJXMq, 0.0f);
  numBytes += cVar_init_f(&cVar_uuhItCSl, 0.0f);
  numBytes += cVar_init_f(&cVar_xLtxndGe, 22050.0f);
  numBytes += cBinop_init(&cBinop_bJ2oke1q, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_hhyhVV9R, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_P5kJeUfq, 0.0f, 0.0f, false);
  numBytes += hTable_initWithData(&hTable_llXpPysK, 256, hTable_llXpPysK_data);
  numBytes += cVar_init_s(&cVar_uvdKTaTE, "1058-table");
  numBytes += cSlice_init(&cSlice_3iygS86U, 1, 1);
  numBytes += sVarf_init(&sVarf_EQIBtitm, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_GotDReFN, 0.0f);
  numBytes += cDelay_init(this, &cDelay_iugoe4MU, 0.0f);
  numBytes += hTable_init(&hTable_V9zw9Tef, 256);
  numBytes += cTabhead_init(&cTabhead_jBFlC4K5, &hTable_V9zw9Tef);
  numBytes += cVar_init_s(&cVar_ulYJ5Ij5, "del-1087-buffer");
  numBytes += cDelay_init(this, &cDelay_izQjetGY, 10.0f);
  numBytes += cDelay_init(this, &cDelay_Usu8JKBB, 0.0f);
  numBytes += cBinop_init(&cBinop_7POsT1QO, 10.0f); // __mul
  numBytes += cBinop_init(&cBinop_V7mdfOlg, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_smFQPSvR, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_NuilK1FR, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_kUhSzSf5, 0.0f);
  numBytes += cVar_init_f(&cVar_8UsGLTKY, 0.0f);
  numBytes += sVarf_init(&sVarf_m7M056GW, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_0Foe1Iam, 525603659);
  numBytes += cSlice_init(&cSlice_tNWf4h6c, 1, 1);
  numBytes += cVar_init_f(&cVar_XoffS0EY, 0.0f);
  numBytes += cVar_init_f(&cVar_d4XpbOTU, 25.0f);
  numBytes += cVar_init_f(&cVar_gWdgzk03, 35.0f);
  numBytes += cVar_init_f(&cVar_Ib2A2eDH, 20.0f);
  numBytes += cVar_init_f(&cVar_9GDdSFH1, 110.0f);
  numBytes += cBinop_init(&cBinop_S9zvT5DJ, 29.0f); // __div
  numBytes += sVarf_init(&sVarf_CN8UHI72, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_fgTiouSa, 1.0f);
  numBytes += cRandom_init(&cRandom_tEwqeRrC, 1951976237);
  numBytes += cSlice_init(&cSlice_9RCWM545, 1, 1);
  numBytes += cIf_init(&cIf_AD4b4HOg, false);
  numBytes += cIf_init(&cIf_itM8kEum, false);
  numBytes += cRandom_init(&cRandom_l1UmFwzA, -1964516291);
  numBytes += cSlice_init(&cSlice_flyhqb98, 1, 1);
  numBytes += cIf_init(&cIf_Dnc29aY9, false);
  numBytes += cIf_init(&cIf_PXAHcu10, false);
  numBytes += cRandom_init(&cRandom_Ozpbg6O8, 2142477055);
  numBytes += cSlice_init(&cSlice_d1KEYfGE, 1, 1);
  numBytes += cIf_init(&cIf_hnsAIm8j, false);
  numBytes += cIf_init(&cIf_OrOsaYFt, false);
  numBytes += cVar_init_f(&cVar_pSZw3WZR, 0.0f);
  numBytes += cBinop_init(&cBinop_hElhGYst, 1.0f); // __pow
  numBytes += sVarf_init(&sVarf_Ga0gnYM9, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_rySd3zVT, 50.0f);
  numBytes += cVar_init_f(&cVar_RF9KxeuC, 220.0f);
  numBytes += sVarf_init(&sVarf_0gFiSTJT, 1.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_oiB3q9er, 1607117635);
  numBytes += cSlice_init(&cSlice_CRpxSnXj, 1, 1);
  numBytes += sVari_init(&sVari_9xWEeNdV, 0, 0, false);
  numBytes += sVarf_init(&sVarf_CxBm4ln3, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_mSWRDxFF, 700.0f);
  numBytes += cBinop_init(&cBinop_8OYZgZIC, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_2iA8Hm9A, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_prog::~Heavy_prog() {
  cPack_free(&cPack_sZ5s1iVH);
  hTable_free(&hTable_lsi2VL8T);
  hTable_free(&hTable_llXpPysK);
  hTable_free(&hTable_V9zw9Tef);
}

HvTable *Heavy_prog::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x758382CA: return &hTable_lsi2VL8T; // 1029-table
    case 0x3C04FB7D: return &hTable_llXpPysK; // 1058-table
    case 0x84B90FF0: return &hTable_V9zw9Tef; // del-1087-buffer
    default: return nullptr;
  }
}

void Heavy_prog::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0x10B19E74: { // 1110-state
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_tsFT8Wsr_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_j1REFVn3_sendMessage);
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


void Heavy_prog::cVar_AaymSuam_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_6giyNETL_sendMessage);
  cSwitchcase_4eZvsRPm_onMessage(_c, NULL, 0, m, NULL);
  cMsg_lplaENWl_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_6giyNETL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_AaymSuam, 1, m, &cVar_AaymSuam_sendMessage);
}

void Heavy_prog::cPack_sZ5s1iVH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jJOc9BNX_sendMessage(_c, 0, m);
}

void Heavy_prog::cSlice_ufQ4GwgW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_DSDJJAQs, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_Knnhwb3J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_GX4tbW3s, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_Wcz7WzWV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_58od7xBU, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_xC42wDze_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_j1i4fTBC, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_vkyD4CNF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_Cy545AmJ, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_rAClLOSw_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_H7ftZfqm_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_H7ftZfqm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7YDr0Iqg_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JTT122zL_sendMessage);
}

void Heavy_prog::cCast_JTT122zL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jFXcoiPg_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_7YDr0Iqg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_AELrZ2Ko_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_sZ5s1iVH, 0, m, &cPack_sZ5s1iVH_sendMessage);
}

void Heavy_prog::cCast_0Vh7LEhu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cjJiRDOr, HV_BINOP_MULTIPLY, 0, m, &cBinop_cjJiRDOr_sendMessage);
}

void Heavy_prog::cMsg_jFXcoiPg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0Vh7LEhu_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_AELrZ2Ko_sendMessage);
}

void Heavy_prog::cBinop_cjJiRDOr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_sZ5s1iVH, 1, m, &cPack_sZ5s1iVH_sendMessage);
}

void Heavy_prog::cBinop_Jd5ysXhc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cjJiRDOr, HV_BINOP_MULTIPLY, 1, m, &cBinop_cjJiRDOr_sendMessage);
}

void Heavy_prog::cMsg_3y5P4V2U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.1f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 600.0f, 0, m, &cBinop_Jd5ysXhc_sendMessage);
}

void Heavy_prog::cMsg_jJOc9BNX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_XFm9zecC, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 1);
  sLine_onMessage(_c, &Context(_c)->sLine_XFm9zecC, 0, m, NULL);
}

void Heavy_prog::cMsg_FBV1lcy3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(5);
  msg_init(m, 5, msg_getTimestamp(n));
  msg_setFloat(m, 0, 748.031f);
  msg_setFloat(m, 1, 1023.62f);
  msg_setFloat(m, 2, 0.173228f);
  msg_setFloat(m, 3, 1968.5f);
  msg_setFloat(m, 4, 9259.84f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_ufQ4GwgW, 0, m, &cSlice_ufQ4GwgW_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Knnhwb3J, 0, m, &cSlice_Knnhwb3J_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Wcz7WzWV, 0, m, &cSlice_Wcz7WzWV_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_xC42wDze, 0, m, &cSlice_xC42wDze_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_vkyD4CNF, 0, m, &cSlice_vkyD4CNF_sendMessage);
}

void Heavy_prog::cVar_xNLlPo1V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_xwMCVRVz_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cVar_e4QymLdf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EoSecKjI, HV_BINOP_MULTIPLY, 1, m, &cBinop_EoSecKjI_sendMessage);
}

void Heavy_prog::cSwitchcase_2DHelPdD_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_LP3oWV7t, 0, m, &cSlice_LP3oWV7t_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_wMjcVEo1, 0, m, &cRandom_wMjcVEo1_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_EoSecKjI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_NJxukWjy_sendMessage);
}

void Heavy_prog::cUnop_NJxukWjy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_NUzhTBFB_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 8.0f, 0, m, &cBinop_HrgpbMo8_sendMessage);
}

void Heavy_prog::cRandom_wMjcVEo1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EoSecKjI, HV_BINOP_MULTIPLY, 0, m, &cBinop_EoSecKjI_sendMessage);
}

void Heavy_prog::cSlice_LP3oWV7t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_wMjcVEo1, 1, m, &cRandom_wMjcVEo1_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_4eZvsRPm_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_WHixCWNb_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_WHixCWNb_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5sm8JYf8_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_bBTtV8IN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_bBTtV8IN, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bBTtV8IN, 0, m, &cDelay_bBTtV8IN_sendMessage);
  cSwitchcase_2DHelPdD_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_vgUAVeWB_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_4HFhLX7W_onMessage(_c, NULL, 0, m, NULL);
  cVar_onMessage(_c, &Context(_c)->cVar_fgTiouSa, 0, m, &cVar_fgTiouSa_sendMessage);
}

void Heavy_prog::cCast_5sm8JYf8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WHixCWNb_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bBTtV8IN, 0, m, &cDelay_bBTtV8IN_sendMessage);
  cSwitchcase_2DHelPdD_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_vgUAVeWB_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_4HFhLX7W_onMessage(_c, NULL, 0, m, NULL);
  cVar_onMessage(_c, &Context(_c)->cVar_fgTiouSa, 0, m, &cVar_fgTiouSa_sendMessage);
}

void Heavy_prog::cMsg_DJCEDBwq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_UQT9HAxJ_sendMessage);
}

void Heavy_prog::cSystem_UQT9HAxJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_WIA6VWME_sendMessage);
}

void Heavy_prog::cVar_BoxfpylM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BMPspxET, HV_BINOP_MULTIPLY, 0, m, &cBinop_BMPspxET_sendMessage);
}

void Heavy_prog::cMsg_WHixCWNb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_bBTtV8IN, 0, m, &cDelay_bBTtV8IN_sendMessage);
}

void Heavy_prog::cBinop_MCEIZhTJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_bBTtV8IN, 2, m, &cDelay_bBTtV8IN_sendMessage);
}

void Heavy_prog::cBinop_WIA6VWME_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BMPspxET, HV_BINOP_MULTIPLY, 1, m, &cBinop_BMPspxET_sendMessage);
}

void Heavy_prog::cBinop_BMPspxET_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_MCEIZhTJ_sendMessage);
}

void Heavy_prog::cVar_jzQfGko0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XqnvFfnA, HV_BINOP_MULTIPLY, 1, m, &cBinop_XqnvFfnA_sendMessage);
}

void Heavy_prog::cSwitchcase_vgUAVeWB_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_IVNZYHjh, 0, m, &cSlice_IVNZYHjh_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_NTC0mvCA, 0, m, &cRandom_NTC0mvCA_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_XqnvFfnA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_hEHXERXO_sendMessage);
}

void Heavy_prog::cUnop_hEHXERXO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_TfVfP4uJ_sendMessage);
}

void Heavy_prog::cRandom_NTC0mvCA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XqnvFfnA, HV_BINOP_MULTIPLY, 0, m, &cBinop_XqnvFfnA_sendMessage);
}

void Heavy_prog::cSlice_IVNZYHjh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_NTC0mvCA, 1, m, &cRandom_NTC0mvCA_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cMsg_pvYPxmvt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_SNuRZOQ0_sendMessage);
}

void Heavy_prog::cSystem_SNuRZOQ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Z2D1AoPy, HV_BINOP_MULTIPLY, 1, m, &cBinop_Z2D1AoPy_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_bQkgiB8b, HV_BINOP_MULTIPLY, 1, m, &cBinop_bQkgiB8b_sendMessage);
}

void Heavy_prog::cSwitchcase_3M6Mri4r_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_AG5zpQcy_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_AG5zpQcy_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wIZ99lW0_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_gO8cLOrs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_gO8cLOrs, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gO8cLOrs, 0, m, &cDelay_gO8cLOrs_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ElJORIDv, 0, m, &cVar_ElJORIDv_sendMessage);
}

void Heavy_prog::cCast_wIZ99lW0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AG5zpQcy_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gO8cLOrs, 0, m, &cDelay_gO8cLOrs_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ElJORIDv, 0, m, &cVar_ElJORIDv_sendMessage);
}

void Heavy_prog::cMsg_dUpyfaKL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_yff3zfnK_sendMessage);
}

void Heavy_prog::cSystem_yff3zfnK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_uvzFDHsg_sendMessage);
}

void Heavy_prog::cVar_bZuXaWrF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Dq7bONjL, HV_BINOP_MULTIPLY, 0, m, &cBinop_Dq7bONjL_sendMessage);
}

void Heavy_prog::cMsg_AG5zpQcy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_gO8cLOrs, 0, m, &cDelay_gO8cLOrs_sendMessage);
}

void Heavy_prog::cBinop_lSueXwBG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_gO8cLOrs, 2, m, &cDelay_gO8cLOrs_sendMessage);
}

void Heavy_prog::cBinop_uvzFDHsg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Dq7bONjL, HV_BINOP_MULTIPLY, 1, m, &cBinop_Dq7bONjL_sendMessage);
}

void Heavy_prog::cBinop_Dq7bONjL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_lSueXwBG_sendMessage);
}

void Heavy_prog::cVar_ElJORIDv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9jYSAvtU, HV_BINOP_SUBTRACT, 0, m, &cBinop_9jYSAvtU_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_XYDPpnyo_sendMessage);
}

void Heavy_prog::cSwitchcase_UUIenDCN_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lqIVLkxJ_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7Wrf1oiT_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_lqIVLkxJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HIy6rrwg, 0, m, &cVar_HIy6rrwg_sendMessage);
}

void Heavy_prog::cCast_7Wrf1oiT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HYOKKsjG_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aEJQcPZR_sendMessage);
}

void Heavy_prog::cSwitchcase_WY6HMG6w_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_GIJmB4oZ, 0, m, &cSlice_GIJmB4oZ_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_lKBokOjn, 0, m, &cSlice_lKBokOjn_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Cp3KJiwV_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_3WCwzqns, 0, m, &cSlice_3WCwzqns_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_6iKcFTkA, 0, m, &cSlice_6iKcFTkA_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0r455zOa_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XYscivxv_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cSlice_GIJmB4oZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_oSfySvk3_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_oSfySvk3_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_lKBokOjn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kmPUlTiS_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vRzqU9Ox_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kmPUlTiS_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vRzqU9Ox_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cVar_8KokHKUH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LrdQeGRU_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9HvjtDL0_sendMessage);
}

void Heavy_prog::cVar_rccISklN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_H7SYJ6W1_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cSwitchcase_H7SYJ6W1_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oA83vLMm_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_Z2D1AoPy, HV_BINOP_MULTIPLY, 0, m, &cBinop_Z2D1AoPy_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_Vp3GB4ip, HV_BINOP_DIVIDE, 1, m, &cBinop_Vp3GB4ip_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_bZuXaWrF, 0, m, &cVar_bZuXaWrF_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cCast_oA83vLMm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5BD2iV9p_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_ML9W6yhG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gYX6vNvh, HV_BINOP_SUBTRACT, 1, m, &cBinop_gYX6vNvh_sendMessage);
}

void Heavy_prog::cVar_u7WZHMSj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HIy6rrwg, 0, m, &cVar_HIy6rrwg_sendMessage);
}

void Heavy_prog::cVar_HIy6rrwg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9JB30LYR, HV_BINOP_ADD, 0, m, &cBinop_9JB30LYR_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_QxUtNsV5, HV_BINOP_ADD, 0, m, &cBinop_QxUtNsV5_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ZSntXjca, 0, m, &cVar_ZSntXjca_sendMessage);
}

void Heavy_prog::cSlice_3WCwzqns_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LrdQeGRU_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9HvjtDL0_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_6iKcFTkA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_M23qeqGD_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_X4c1wOBV_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_exfgDbBj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ElJORIDv, 1, m, &cVar_ElJORIDv_sendMessage);
}

void Heavy_prog::cBinop_bQkgiB8b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_exfgDbBj_sendMessage);
}

void Heavy_prog::cBinop_Z2D1AoPy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_d0Yuat9Z_sendMessage);
}

void Heavy_prog::cBinop_d0Yuat9Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9jYSAvtU, HV_BINOP_SUBTRACT, 1, m, &cBinop_9jYSAvtU_sendMessage);
}

void Heavy_prog::cBinop_9jYSAvtU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ElJORIDv, 1, m, &cVar_ElJORIDv_sendMessage);
}

void Heavy_prog::cMsg_FgxZ0JO1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_3M6Mri4r_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_KIknfwje_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_3M6Mri4r_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_QxUtNsV5, HV_BINOP_ADD, 1, m, &cBinop_QxUtNsV5_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_9JB30LYR, HV_BINOP_ADD, 1, m, &cBinop_9JB30LYR_sendMessage);
}

void Heavy_prog::cBinop_XYDPpnyo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_UUIenDCN_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_9JB30LYR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HIy6rrwg, 1, m, &cVar_HIy6rrwg_sendMessage);
}

void Heavy_prog::cBinop_Vp3GB4ip_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GiFpQrWi, HV_BINOP_DIVIDE, 1, m, &cBinop_GiFpQrWi_sendMessage);
}

void Heavy_prog::cBinop_GiFpQrWi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QxUtNsV5, HV_BINOP_ADD, 1, m, &cBinop_QxUtNsV5_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_9JB30LYR, HV_BINOP_ADD, 1, m, &cBinop_9JB30LYR_sendMessage);
}

void Heavy_prog::cCast_9HvjtDL0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Vp3GB4ip, HV_BINOP_DIVIDE, 0, m, &cBinop_Vp3GB4ip_sendMessage);
}

void Heavy_prog::cCast_LrdQeGRU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bQkgiB8b, HV_BINOP_MULTIPLY, 0, m, &cBinop_bQkgiB8b_sendMessage);
}

void Heavy_prog::cCast_X4c1wOBV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gYX6vNvh, HV_BINOP_SUBTRACT, 0, m, &cBinop_gYX6vNvh_sendMessage);
}

void Heavy_prog::cCast_M23qeqGD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_u7WZHMSj, 1, m, &cVar_u7WZHMSj_sendMessage);
}

void Heavy_prog::cCast_aEJQcPZR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_u7WZHMSj, 0, m, &cVar_u7WZHMSj_sendMessage);
}

void Heavy_prog::cCast_HYOKKsjG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KIknfwje_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_QxUtNsV5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ML9W6yhG, 0, m, &cVar_ML9W6yhG_sendMessage);
}

void Heavy_prog::cMsg_oSfySvk3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_3M6Mri4r_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_iriXtmCp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_8KokHKUH, 1, m, &cVar_8KokHKUH_sendMessage);
}

void Heavy_prog::cMsg_5BD2iV9p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Z2D1AoPy, HV_BINOP_MULTIPLY, 0, m, &cBinop_Z2D1AoPy_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Vp3GB4ip, HV_BINOP_DIVIDE, 1, m, &cBinop_Vp3GB4ip_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_bZuXaWrF, 0, m, &cVar_bZuXaWrF_sendMessage);
}

void Heavy_prog::cCast_kmPUlTiS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oSfySvk3_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_vRzqU9Ox_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CBFv5OcX_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_QxUtNsV5, HV_BINOP_ADD, 0, m, &cBinop_QxUtNsV5_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_HIy6rrwg, 1, m, &cVar_HIy6rrwg_sendMessage);
}

void Heavy_prog::cBinop_gYX6vNvh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GiFpQrWi, HV_BINOP_DIVIDE, 0, m, &cBinop_GiFpQrWi_sendMessage);
}

void Heavy_prog::cCast_CBFv5OcX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KIknfwje_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_Cp3KJiwV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8KokHKUH, 0, m, &cVar_8KokHKUH_sendMessage);
}

void Heavy_prog::cCast_0r455zOa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FgxZ0JO1_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_XYscivxv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iriXtmCp_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_ZSntXjca_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 3000.0f, 0, m, &cBinop_vO5Ms71m_sendMessage);
}

void Heavy_prog::cVar_qE4biTdr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eygmU38y, 0, m, &cVar_eygmU38y_sendMessage);
}

void Heavy_prog::cVar_eygmU38y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LmwgQNFu, HV_BINOP_MULTIPLY, 0, m, &cBinop_LmwgQNFu_sendMessage);
}

void Heavy_prog::cMsg_Vhy9Ljwm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_72vWWyUf_sendMessage);
}

void Heavy_prog::cSystem_72vWWyUf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uK7Oh3Zy_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_LmwgQNFu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_ih7aRXrH_sendMessage);
}

void Heavy_prog::cBinop_Y0EhszAC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LmwgQNFu, HV_BINOP_MULTIPLY, 1, m, &cBinop_LmwgQNFu_sendMessage);
}

void Heavy_prog::cMsg_uK7Oh3Zy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Y0EhszAC_sendMessage);
}

void Heavy_prog::cBinop_ih7aRXrH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_pBdIdEdJ_sendMessage);
}

void Heavy_prog::cBinop_pBdIdEdJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_YWHjnHsE_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_YmrUviDO, m);
}

void Heavy_prog::cBinop_YWHjnHsE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_wUHthjko, m);
}

void Heavy_prog::cBinop_vO5Ms71m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qE4biTdr, 0, m, &cVar_qE4biTdr_sendMessage);
}

void Heavy_prog::hTable_lsi2VL8T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cSwitchcase_C0w3Hs1X_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_NAxXAOJi, 0, m, &cSlice_NAxXAOJi_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cVar_6EV6DgMZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xGdnlqOM_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_j1vN51QL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_etUivJbC_sendMessage);
}

void Heavy_prog::cMsg_xGdnlqOM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_j1vN51QL_sendMessage);
}

void Heavy_prog::cSlice_NAxXAOJi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_jpAzKPrF, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_6EV6DgMZ, 0, m, &cVar_6EV6DgMZ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_etUivJbC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_wpKlUsaX, m);
}

void Heavy_prog::cBinop_NUzhTBFB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_WY6HMG6w_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_T4cqS1IB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_RLCMnNpG_sendMessage);
}

void Heavy_prog::cSystem_RLCMnNpG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_o56S8kpL, HV_BINOP_MULTIPLY, 1, m, &cBinop_o56S8kpL_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_l89cWWiU, HV_BINOP_MULTIPLY, 1, m, &cBinop_l89cWWiU_sendMessage);
}

void Heavy_prog::cSwitchcase_0mjtASoW_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_tWkCn2oG_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_tWkCn2oG_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UjCr8Ttb_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_LL4hFhfW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_LL4hFhfW, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LL4hFhfW, 0, m, &cDelay_LL4hFhfW_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ciet6Cgu, 0, m, &cVar_ciet6Cgu_sendMessage);
}

void Heavy_prog::cCast_UjCr8Ttb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tWkCn2oG_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LL4hFhfW, 0, m, &cDelay_LL4hFhfW_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ciet6Cgu, 0, m, &cVar_ciet6Cgu_sendMessage);
}

void Heavy_prog::cMsg_ZHq5TCu3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_XIS7pFI8_sendMessage);
}

void Heavy_prog::cSystem_XIS7pFI8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_D47x7lEH_sendMessage);
}

void Heavy_prog::cVar_7jwJfvj3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Em6z35fL, HV_BINOP_MULTIPLY, 0, m, &cBinop_Em6z35fL_sendMessage);
}

void Heavy_prog::cMsg_tWkCn2oG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_LL4hFhfW, 0, m, &cDelay_LL4hFhfW_sendMessage);
}

void Heavy_prog::cBinop_oKmynODN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_LL4hFhfW, 2, m, &cDelay_LL4hFhfW_sendMessage);
}

void Heavy_prog::cBinop_D47x7lEH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Em6z35fL, HV_BINOP_MULTIPLY, 1, m, &cBinop_Em6z35fL_sendMessage);
}

void Heavy_prog::cBinop_Em6z35fL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_oKmynODN_sendMessage);
}

void Heavy_prog::cVar_ciet6Cgu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fiddwMlu, HV_BINOP_SUBTRACT, 0, m, &cBinop_fiddwMlu_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_s0C74avW_sendMessage);
}

void Heavy_prog::cSwitchcase_ImUo7LeJ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5nNfCVfH_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WWH4lc5m_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_5nNfCVfH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3Vsfx1EA, 0, m, &cVar_3Vsfx1EA_sendMessage);
}

void Heavy_prog::cCast_WWH4lc5m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fb973VDp_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JJXzkSKU_sendMessage);
}

void Heavy_prog::cSwitchcase_aK3uPorf_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_2EDI0i1v, 0, m, &cSlice_2EDI0i1v_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_8BSPdje3, 0, m, &cSlice_8BSPdje3_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6r0TuwMM_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_TeQErGi0, 0, m, &cSlice_TeQErGi0_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_qNs2lfsT, 0, m, &cSlice_qNs2lfsT_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5WTAEww6_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_i2F0c8kK_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cSlice_2EDI0i1v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_zl8dPOY2_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_zl8dPOY2_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_8BSPdje3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_J4wuucPG_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nAuqR6Bb_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_J4wuucPG_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nAuqR6Bb_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cVar_joRAMf4s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_C03QPYBD_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9zqZXTbc_sendMessage);
}

void Heavy_prog::cVar_nSNuEzbs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_6BNxhmjc_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cSwitchcase_6BNxhmjc_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AW3ldChZ_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_o56S8kpL, HV_BINOP_MULTIPLY, 0, m, &cBinop_o56S8kpL_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_KhsrWRPo, HV_BINOP_DIVIDE, 1, m, &cBinop_KhsrWRPo_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_7jwJfvj3, 0, m, &cVar_7jwJfvj3_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cCast_AW3ldChZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mBGoT2yn_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_QBCAlWsG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Wsuhkue2, HV_BINOP_SUBTRACT, 1, m, &cBinop_Wsuhkue2_sendMessage);
}

void Heavy_prog::cVar_JX7ANc3D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3Vsfx1EA, 0, m, &cVar_3Vsfx1EA_sendMessage);
}

void Heavy_prog::cVar_3Vsfx1EA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eC3H1Nm2, HV_BINOP_ADD, 0, m, &cBinop_eC3H1Nm2_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_nzXACSy9, HV_BINOP_ADD, 0, m, &cBinop_nzXACSy9_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ELynJXMq, 0, m, &cVar_ELynJXMq_sendMessage);
}

void Heavy_prog::cSlice_TeQErGi0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_C03QPYBD_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9zqZXTbc_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_qNs2lfsT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_PTSg5obd_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_b2YmrDpl_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_NUFQxPx2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ciet6Cgu, 1, m, &cVar_ciet6Cgu_sendMessage);
}

void Heavy_prog::cBinop_l89cWWiU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_NUFQxPx2_sendMessage);
}

void Heavy_prog::cBinop_o56S8kpL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_KzSRlM1Y_sendMessage);
}

void Heavy_prog::cBinop_KzSRlM1Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fiddwMlu, HV_BINOP_SUBTRACT, 1, m, &cBinop_fiddwMlu_sendMessage);
}

void Heavy_prog::cBinop_fiddwMlu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ciet6Cgu, 1, m, &cVar_ciet6Cgu_sendMessage);
}

void Heavy_prog::cMsg_eOKWse0U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_0mjtASoW_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_Os4Cv64b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_0mjtASoW_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_nzXACSy9, HV_BINOP_ADD, 1, m, &cBinop_nzXACSy9_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_eC3H1Nm2, HV_BINOP_ADD, 1, m, &cBinop_eC3H1Nm2_sendMessage);
}

void Heavy_prog::cBinop_s0C74avW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ImUo7LeJ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_eC3H1Nm2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3Vsfx1EA, 1, m, &cVar_3Vsfx1EA_sendMessage);
}

void Heavy_prog::cBinop_KhsrWRPo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_A1uvxR4z, HV_BINOP_DIVIDE, 1, m, &cBinop_A1uvxR4z_sendMessage);
}

void Heavy_prog::cBinop_A1uvxR4z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nzXACSy9, HV_BINOP_ADD, 1, m, &cBinop_nzXACSy9_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_eC3H1Nm2, HV_BINOP_ADD, 1, m, &cBinop_eC3H1Nm2_sendMessage);
}

void Heavy_prog::cCast_C03QPYBD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_l89cWWiU, HV_BINOP_MULTIPLY, 0, m, &cBinop_l89cWWiU_sendMessage);
}

void Heavy_prog::cCast_9zqZXTbc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KhsrWRPo, HV_BINOP_DIVIDE, 0, m, &cBinop_KhsrWRPo_sendMessage);
}

void Heavy_prog::cCast_b2YmrDpl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Wsuhkue2, HV_BINOP_SUBTRACT, 0, m, &cBinop_Wsuhkue2_sendMessage);
}

void Heavy_prog::cCast_PTSg5obd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JX7ANc3D, 1, m, &cVar_JX7ANc3D_sendMessage);
}

void Heavy_prog::cCast_JJXzkSKU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JX7ANc3D, 0, m, &cVar_JX7ANc3D_sendMessage);
}

void Heavy_prog::cCast_fb973VDp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Os4Cv64b_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_nzXACSy9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QBCAlWsG, 0, m, &cVar_QBCAlWsG_sendMessage);
}

void Heavy_prog::cMsg_zl8dPOY2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_0mjtASoW_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_V2QFTabO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_joRAMf4s, 1, m, &cVar_joRAMf4s_sendMessage);
}

void Heavy_prog::cMsg_mBGoT2yn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_o56S8kpL, HV_BINOP_MULTIPLY, 0, m, &cBinop_o56S8kpL_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_KhsrWRPo, HV_BINOP_DIVIDE, 1, m, &cBinop_KhsrWRPo_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_7jwJfvj3, 0, m, &cVar_7jwJfvj3_sendMessage);
}

void Heavy_prog::cCast_J4wuucPG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zl8dPOY2_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_nAuqR6Bb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aWhTJBhi_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_nzXACSy9, HV_BINOP_ADD, 0, m, &cBinop_nzXACSy9_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_3Vsfx1EA, 1, m, &cVar_3Vsfx1EA_sendMessage);
}

void Heavy_prog::cBinop_Wsuhkue2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_A1uvxR4z, HV_BINOP_DIVIDE, 0, m, &cBinop_A1uvxR4z_sendMessage);
}

void Heavy_prog::cCast_aWhTJBhi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Os4Cv64b_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_5WTAEww6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eOKWse0U_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_6r0TuwMM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_joRAMf4s, 0, m, &cVar_joRAMf4s_sendMessage);
}

void Heavy_prog::cCast_i2F0c8kK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_V2QFTabO_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_ELynJXMq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 3000.0f, 0, m, &cBinop_YZctHESc_sendMessage);
}

void Heavy_prog::cVar_uuhItCSl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_xLtxndGe, 0, m, &cVar_xLtxndGe_sendMessage);
}

void Heavy_prog::cVar_xLtxndGe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bJ2oke1q, HV_BINOP_MULTIPLY, 0, m, &cBinop_bJ2oke1q_sendMessage);
}

void Heavy_prog::cMsg_wEGr10jH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_w07nnW9V_sendMessage);
}

void Heavy_prog::cSystem_w07nnW9V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aA3aMtlD_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_bJ2oke1q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_VIdmzlYL_sendMessage);
}

void Heavy_prog::cBinop_NHpDamoq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bJ2oke1q, HV_BINOP_MULTIPLY, 1, m, &cBinop_bJ2oke1q_sendMessage);
}

void Heavy_prog::cMsg_aA3aMtlD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_NHpDamoq_sendMessage);
}

void Heavy_prog::cBinop_VIdmzlYL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_FsikrYT5_sendMessage);
}

void Heavy_prog::cBinop_FsikrYT5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_gAFDzQ7a_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_P5kJeUfq, m);
}

void Heavy_prog::cBinop_gAFDzQ7a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_hhyhVV9R, m);
}

void Heavy_prog::cBinop_YZctHESc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uuhItCSl, 0, m, &cVar_uuhItCSl_sendMessage);
}

void Heavy_prog::hTable_llXpPysK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cSwitchcase_QrgtYhZC_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_3iygS86U, 0, m, &cSlice_3iygS86U_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cVar_uvdKTaTE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0lXyvqqF_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_QBHT0ZDk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_M2JYInlJ_sendMessage);
}

void Heavy_prog::cMsg_0lXyvqqF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_QBHT0ZDk_sendMessage);
}

void Heavy_prog::cSlice_3iygS86U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_PxVbxWOm, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_uvdKTaTE, 0, m, &cVar_uvdKTaTE_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_M2JYInlJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_EQIBtitm, m);
}

void Heavy_prog::cBinop_TfVfP4uJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_aK3uPorf_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_T4bWGBHJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_cjqwhl1k_sendMessage);
}

void Heavy_prog::cSystem_cjqwhl1k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_9cKmT8Pk_sendMessage);
}

void Heavy_prog::cDelay_GotDReFN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_GotDReFN, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_iugoe4MU, 0, m, &cDelay_iugoe4MU_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_GotDReFN, 0, m, &cDelay_GotDReFN_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_IoyIZfBL, 1, m, NULL);
}

void Heavy_prog::cDelay_iugoe4MU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_iugoe4MU, m);
  cMsg_zMowwhBY_sendMessage(_c, 0, m);
}

void Heavy_prog::cSwitchcase_KZklkB9D_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_QYR1VOUS_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cBinop_RrU6VvCa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lQIH6uUn_sendMessage(_c, 0, m);
}

void Heavy_prog::hTable_V9zw9Tef_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GGNAG8zg_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_GotDReFN, 2, m, &cDelay_GotDReFN_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GIakfTSX_sendMessage);
}

void Heavy_prog::cMsg_lQIH6uUn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_V9zw9Tef, 0, m, &hTable_V9zw9Tef_sendMessage);
}

void Heavy_prog::cBinop_9cKmT8Pk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_RrU6VvCa_sendMessage);
}

void Heavy_prog::cMsg_zMowwhBY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_V9zw9Tef, 0, m, &hTable_V9zw9Tef_sendMessage);
}

void Heavy_prog::cCast_GIakfTSX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_GotDReFN, 0, m, &cDelay_GotDReFN_sendMessage);
}

void Heavy_prog::cMsg_GGNAG8zg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_iugoe4MU, 2, m, &cDelay_iugoe4MU_sendMessage);
}

void Heavy_prog::cMsg_QYR1VOUS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_IoyIZfBL, 1, m, NULL);
}

void Heavy_prog::cTabhead_jBFlC4K5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_V7mdfOlg, HV_BINOP_SUBTRACT, 0, m, &cBinop_V7mdfOlg_sendMessage);
}

void Heavy_prog::cMsg_X22QzULq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_lCzaeyBp_sendMessage);
}

void Heavy_prog::cSystem_lCzaeyBp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ktVGspfV_sendMessage);
}

void Heavy_prog::cVar_ulYJ5Ij5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_76t6onwP_sendMessage(_c, 0, m);
}

void Heavy_prog::cDelay_izQjetGY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_izQjetGY, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Usu8JKBB, 0, m, &cDelay_Usu8JKBB_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_gmREo7Wb, 0, m, &sTabread_gmREo7Wb_sendMessage);
}

void Heavy_prog::cDelay_Usu8JKBB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Usu8JKBB, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_gmREo7Wb, 0, m, &sTabread_gmREo7Wb_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Usu8JKBB, 0, m, &cDelay_Usu8JKBB_sendMessage);
}

void Heavy_prog::sTabread_gmREo7Wb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_NuilK1FR, HV_BINOP_SUBTRACT, 0, m, &cBinop_NuilK1FR_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_7POsT1QO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_smFQPSvR, HV_BINOP_MAX, 0, m, &cBinop_smFQPSvR_sendMessage);
}

void Heavy_prog::cBinop_ktVGspfV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7POsT1QO, HV_BINOP_MULTIPLY, 0, m, &cBinop_7POsT1QO_sendMessage);
}

void Heavy_prog::cBinop_V7mdfOlg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6pCTtImA_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_gmREo7Wb, 0, m, &sTabread_gmREo7Wb_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PTJP7nVG_sendMessage);
}

void Heavy_prog::cSystem_dDtJzNlH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NuilK1FR, HV_BINOP_SUBTRACT, 1, m, &cBinop_NuilK1FR_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Usu8JKBB, 2, m, &cDelay_Usu8JKBB_sendMessage);
}

void Heavy_prog::cMsg_76t6onwP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_dDtJzNlH_sendMessage);
}

void Heavy_prog::cMsg_6pCTtImA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_izQjetGY, 0, m, &cDelay_izQjetGY_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Usu8JKBB, 0, m, &cDelay_Usu8JKBB_sendMessage);
}

void Heavy_prog::cMsg_kCkzhH0k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_smFQPSvR, HV_BINOP_MAX, 1, m, &cBinop_smFQPSvR_sendMessage);
}

void Heavy_prog::cBinop_smFQPSvR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_V7mdfOlg, HV_BINOP_SUBTRACT, 1, m, &cBinop_V7mdfOlg_sendMessage);
}

void Heavy_prog::cCast_PTJP7nVG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_izQjetGY, 0, m, &cDelay_izQjetGY_sendMessage);
}

void Heavy_prog::cBinop_S6z5kEFq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_izQjetGY, 2, m, &cDelay_izQjetGY_sendMessage);
}

void Heavy_prog::cBinop_NuilK1FR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_S6z5kEFq_sendMessage);
}

void Heavy_prog::cCast_1AWH8TZn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ulYJ5Ij5, 0, m, &cVar_ulYJ5Ij5_sendMessage);
  cMsg_X22QzULq_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_jBFlC4K5, 0, m, &cTabhead_jBFlC4K5_sendMessage);
}

void Heavy_prog::cVar_kUhSzSf5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_m7M056GW, m);
}

void Heavy_prog::cVar_8UsGLTKY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7POsT1QO, HV_BINOP_MULTIPLY, 1, m, &cBinop_7POsT1QO_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1AWH8TZn_sendMessage);
}

void Heavy_prog::cSwitchcase_4HFhLX7W_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_tNWf4h6c, 0, m, &cSlice_tNWf4h6c_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_0Foe1Iam, 0, m, &cRandom_0Foe1Iam_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_PfkXwHUW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_yjM4O5AR_sendMessage);
}

void Heavy_prog::cUnop_yjM4O5AR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 200.0f, 0, m, &cBinop_FYic2swv_sendMessage);
}

void Heavy_prog::cRandom_0Foe1Iam_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_PfkXwHUW_sendMessage);
}

void Heavy_prog::cSlice_tNWf4h6c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_0Foe1Iam, 1, m, &cRandom_0Foe1Iam_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cVar_XoffS0EY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kUhSzSf5, 0, m, &cVar_kUhSzSf5_sendMessage);
}

void Heavy_prog::cSwitchcase_xwMCVRVz_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LYqDWZmG_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qe1tWlzL_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LPDmqiMV_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_LYqDWZmG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pFlz6XqZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yfOY0dfO_sendMessage);
}

void Heavy_prog::cCast_qe1tWlzL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EwrrARxD_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_a0cyMkFr_sendMessage);
}

void Heavy_prog::cCast_LPDmqiMV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RL9nSYlM_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_54c5hF15_sendMessage);
}

void Heavy_prog::cVar_d4XpbOTU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_S9zvT5DJ, HV_BINOP_DIVIDE, 1, m, &cBinop_S9zvT5DJ_sendMessage);
}

void Heavy_prog::cVar_gWdgzk03_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_S9zvT5DJ, HV_BINOP_DIVIDE, 1, m, &cBinop_S9zvT5DJ_sendMessage);
}

void Heavy_prog::cVar_Ib2A2eDH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_S9zvT5DJ, HV_BINOP_DIVIDE, 1, m, &cBinop_S9zvT5DJ_sendMessage);
}

void Heavy_prog::cVar_9GDdSFH1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_heuGvHrE_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yXu0G02B_sendMessage);
}

void Heavy_prog::cCast_heuGvHrE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7czPvw98_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_yXu0G02B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_S9zvT5DJ, HV_BINOP_DIVIDE, 0, m, &cBinop_S9zvT5DJ_sendMessage);
}

void Heavy_prog::cBinop_S9zvT5DJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_CN8UHI72, m);
}

void Heavy_prog::cCast_54c5hF15_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9GDdSFH1, 0, m, &cVar_9GDdSFH1_sendMessage);
}

void Heavy_prog::cCast_RL9nSYlM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Ib2A2eDH, 0, m, &cVar_Ib2A2eDH_sendMessage);
}

void Heavy_prog::cCast_EwrrARxD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gWdgzk03, 0, m, &cVar_gWdgzk03_sendMessage);
}

void Heavy_prog::cCast_a0cyMkFr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9GDdSFH1, 0, m, &cVar_9GDdSFH1_sendMessage);
}

void Heavy_prog::cCast_yfOY0dfO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9GDdSFH1, 0, m, &cVar_9GDdSFH1_sendMessage);
}

void Heavy_prog::cCast_pFlz6XqZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_d4XpbOTU, 0, m, &cVar_d4XpbOTU_sendMessage);
}

void Heavy_prog::cMsg_7czPvw98_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_qGbFiov5, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_qGbFiov5, 0, m, NULL);
}

void Heavy_prog::cCast_Nf1ErkMy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_uIY6Kn7x_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_jk3oMIg7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aKAkqMtP_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_r7kQGTot_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ttXX9kUs_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_2h1sSiMB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2iEglnsD_sendMessage(_c, 0, m);
}

void Heavy_prog::cSwitchcase_nt5hkGTx_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qVTI6UWt_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KDOkZV6l_sendMessage);
      break;
    }
    case 0x40400000: { // "3.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0IcPHgAJ_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_qVTI6UWt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Nf1ErkMy_sendMessage);
}

void Heavy_prog::cCast_KDOkZV6l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UZXe5Ker_sendMessage);
}

void Heavy_prog::cCast_0IcPHgAJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_A03Oxra1_sendMessage);
}

void Heavy_prog::cCast_UZXe5Ker_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_4YYsP28X_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_Eeg4onnI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WdeEt5vx_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_mA5wtt3Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yMx9RnPd_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_uSk3T6cG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MLO51Rfg_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_A03Oxra1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_O0N8YS3r_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_J4dXgGn5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hJ7Es7Rs_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_6hxutXuQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rPaq4YKp_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_rGuLufYM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1sJzSHst_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_fgTiouSa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_nt5hkGTx_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cSwitchcase_uIY6Kn7x_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_9RCWM545, 0, m, &cSlice_9RCWM545_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_tEwqeRrC, 0, m, &cRandom_tEwqeRrC_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_kzp6vT7Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Jk23htjw_sendMessage);
}

void Heavy_prog::cUnop_Jk23htjw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 30.0f, 0, m, &cBinop_C7lbts4s_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_AD4b4HOg, 0, m, &cIf_AD4b4HOg_sendMessage);
}

void Heavy_prog::cRandom_tEwqeRrC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_kzp6vT7Y_sendMessage);
}

void Heavy_prog::cSlice_9RCWM545_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_tEwqeRrC, 1, m, &cRandom_tEwqeRrC_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cIf_AD4b4HOg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jk3oMIg7_sendMessage);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 60.0f, 0, m, &cBinop_PufbFRIb_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_itM8kEum, 0, m, &cIf_itM8kEum_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_C7lbts4s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_AD4b4HOg, 1, m, &cIf_AD4b4HOg_sendMessage);
}

void Heavy_prog::cIf_itM8kEum_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_r7kQGTot_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2h1sSiMB_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_PufbFRIb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_itM8kEum, 1, m, &cIf_itM8kEum_sendMessage);
}

void Heavy_prog::cSwitchcase_4YYsP28X_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_flyhqb98, 0, m, &cSlice_flyhqb98_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_l1UmFwzA, 0, m, &cRandom_l1UmFwzA_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_GZyi7LQH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_z69hWngy_sendMessage);
}

void Heavy_prog::cUnop_z69hWngy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 10.0f, 0, m, &cBinop_m8vrZqf5_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Dnc29aY9, 0, m, &cIf_Dnc29aY9_sendMessage);
}

void Heavy_prog::cRandom_l1UmFwzA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_GZyi7LQH_sendMessage);
}

void Heavy_prog::cSlice_flyhqb98_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_l1UmFwzA, 1, m, &cRandom_l1UmFwzA_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cIf_Dnc29aY9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Eeg4onnI_sendMessage);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 60.0f, 0, m, &cBinop_XdGY8wuK_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_PXAHcu10, 0, m, &cIf_PXAHcu10_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_m8vrZqf5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Dnc29aY9, 1, m, &cIf_Dnc29aY9_sendMessage);
}

void Heavy_prog::cIf_PXAHcu10_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mA5wtt3Z_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uSk3T6cG_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_XdGY8wuK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_PXAHcu10, 1, m, &cIf_PXAHcu10_sendMessage);
}

void Heavy_prog::cSwitchcase_O0N8YS3r_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_d1KEYfGE, 0, m, &cSlice_d1KEYfGE_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Ozpbg6O8, 0, m, &cRandom_Ozpbg6O8_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_d6BbF4d6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_1PohUBjB_sendMessage);
}

void Heavy_prog::cUnop_1PohUBjB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 70.0f, 0, m, &cBinop_fFKoyj6R_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_hnsAIm8j, 0, m, &cIf_hnsAIm8j_sendMessage);
}

void Heavy_prog::cRandom_Ozpbg6O8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_d6BbF4d6_sendMessage);
}

void Heavy_prog::cSlice_d1KEYfGE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Ozpbg6O8, 1, m, &cRandom_Ozpbg6O8_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cIf_hnsAIm8j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_J4dXgGn5_sendMessage);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 80.0f, 0, m, &cBinop_hbNUm94R_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_OrOsaYFt, 0, m, &cIf_OrOsaYFt_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_fFKoyj6R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_hnsAIm8j, 1, m, &cIf_hnsAIm8j_sendMessage);
}

void Heavy_prog::cIf_OrOsaYFt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6hxutXuQ_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rGuLufYM_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_hbNUm94R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_OrOsaYFt, 1, m, &cIf_OrOsaYFt_sendMessage);
}

void Heavy_prog::cVar_pSZw3WZR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fgTiouSa, 1, m, &cVar_fgTiouSa_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_DVU6sTa2_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 50.0f, 0, m, &cBinop_uZJS3GWf_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 40.0f, 0, m, &cBinop_ogkiUqdp_sendMessage);
}

void Heavy_prog::cMsg_aKAkqMtP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_s321EFxv_sendMessage(_c, 0, m);
  cSwitchcase_rAClLOSw_onMessage(_c, NULL, 0, m, NULL);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Hg2PG2S7_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_G9mBqkf4_sendMessage);
}

void Heavy_prog::cMsg_ttXX9kUs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cSend_s321EFxv_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_2iEglnsD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3.0f);
  cSend_s321EFxv_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_WdeEt5vx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_vxsWYCY7_sendMessage(_c, 0, m);
  cSwitchcase_rAClLOSw_onMessage(_c, NULL, 0, m, NULL);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XrmJv1Tt_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_waySxu1W_sendMessage);
}

void Heavy_prog::cMsg_yMx9RnPd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cSend_vxsWYCY7_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_MLO51Rfg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3.0f);
  cSend_vxsWYCY7_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_hJ7Es7Rs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_4edguG1Q_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XrmJv1Tt_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_waySxu1W_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Hg2PG2S7_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_G9mBqkf4_sendMessage);
}

void Heavy_prog::cMsg_rPaq4YKp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cSend_4edguG1Q_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_1sJzSHst_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3.0f);
  cSend_4edguG1Q_sendMessage(_c, 0, m);
}

void Heavy_prog::cSend_s321EFxv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_tsFT8Wsr_sendMessage(_c, 0, m);
}

void Heavy_prog::cSend_vxsWYCY7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_tsFT8Wsr_sendMessage(_c, 0, m);
}

void Heavy_prog::cSend_4edguG1Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_tsFT8Wsr_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_UhnjyW20_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Ga0gnYM9, m);
}

void Heavy_prog::cBinop_3JW3qKg1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_5lCEcgpE_sendMessage);
}

void Heavy_prog::cBinop_5lCEcgpE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hElhGYst, HV_BINOP_POW, 1, m, &cBinop_hElhGYst_sendMessage);
  cMsg_3ulkTAI0_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_hElhGYst_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_UhnjyW20_sendMessage);
}

void Heavy_prog::cMsg_3ulkTAI0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_hElhGYst, HV_BINOP_POW, 0, m, &cBinop_hElhGYst_sendMessage);
}

void Heavy_prog::cBinop_AMWPa46x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -10.0f, 0, m, &cBinop_o50isVRw_sendMessage);
}

void Heavy_prog::cBinop_o50isVRw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_0gFiSTJT, m);
}

void Heavy_prog::cBinop_4UOfVknK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -10.0f, 0, m, &cBinop_Wdx2Di9P_sendMessage);
}

void Heavy_prog::cBinop_Wdx2Di9P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HrIQ05x9_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_rySd3zVT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 10.0f, 0, m, &cBinop_AMWPa46x_sendMessage);
}

void Heavy_prog::cVar_RF9KxeuC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 10.0f, 0, m, &cBinop_4UOfVknK_sendMessage);
}

void Heavy_prog::cMsg_HrIQ05x9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 50.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_JIaJBOYI, 0, m, NULL);
}

void Heavy_prog::cCast_QDF14YyU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_3JW3qKg1_sendMessage);
}

void Heavy_prog::cCast_crgKfTyP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_waySxu1W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jQNnwu9P_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_XrmJv1Tt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RQcGz47s_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_jQNnwu9P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 40.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_X69Ir8I5, 0, m, NULL);
}

void Heavy_prog::cMsg_RQcGz47s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.1f);
  sLine_onMessage(_c, &Context(_c)->sLine_X69Ir8I5, 0, m, NULL);
}

void Heavy_prog::cSwitchcase_Zjy2OJYS_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_CRpxSnXj, 0, m, &cSlice_CRpxSnXj_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_oiB3q9er, 0, m, &cRandom_oiB3q9er_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_VmAPOJyR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_HlNes71z_sendMessage);
}

void Heavy_prog::cUnop_HlNes71z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MuNVHD7l_sendMessage(_c, 0, m);
}

void Heavy_prog::cRandom_oiB3q9er_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_VmAPOJyR_sendMessage);
}

void Heavy_prog::cSlice_CRpxSnXj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_oiB3q9er, 1, m, &cRandom_oiB3q9er_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cMsg_MuNVHD7l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_9xWEeNdV, m);
}

void Heavy_prog::cBinop_oYgeEYkl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_0l9bepjY_sendMessage);
}

void Heavy_prog::cBinop_0l9bepjY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_Rsm8S1Fw_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_03hy4Hc1_sendMessage);
}

void Heavy_prog::cVar_mSWRDxFF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_Eq8baGTX_sendMessage);
}

void Heavy_prog::cMsg_vJILJWEZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_8DQMOOEk_sendMessage);
}

void Heavy_prog::cSystem_8DQMOOEk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8OYZgZIC, HV_BINOP_DIVIDE, 1, m, &cBinop_8OYZgZIC_sendMessage);
}

void Heavy_prog::cBinop_Rsm8S1Fw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_d85seDaM_sendMessage);
}

void Heavy_prog::cBinop_d85seDaM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_2iA8Hm9A, m);
}

void Heavy_prog::cMsg_HNC1PHVA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_ma9JHPAe_sendMessage);
}

void Heavy_prog::cBinop_ma9JHPAe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_oYgeEYkl_sendMessage);
}

void Heavy_prog::cBinop_03hy4Hc1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_CxBm4ln3, m);
}

void Heavy_prog::cBinop_Eq8baGTX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_fL7MHCc7_sendMessage);
}

void Heavy_prog::cBinop_fL7MHCc7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8OYZgZIC, HV_BINOP_DIVIDE, 0, m, &cBinop_8OYZgZIC_sendMessage);
}

void Heavy_prog::cBinop_8OYZgZIC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HNC1PHVA_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_Hg2PG2S7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_psKIkY04_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_G9mBqkf4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FVTRbR5k_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_psKIkY04_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_5qnKEH7x, 0, m, NULL);
}

void Heavy_prog::cMsg_FVTRbR5k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 40.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_5qnKEH7x, 0, m, NULL);
}

void Heavy_prog::cBinop_DVU6sTa2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_xNLlPo1V, 0, m, &cVar_xNLlPo1V_sendMessage);
}

void Heavy_prog::cBinop_uZJS3GWf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_e4QymLdf, 0, m, &cVar_e4QymLdf_sendMessage);
}

void Heavy_prog::cBinop_ogkiUqdp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jzQfGko0, 0, m, &cVar_jzQfGko0_sendMessage);
}

void Heavy_prog::cBinop_IeMWzKb7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XoffS0EY, 0, m, &cVar_XoffS0EY_sendMessage);
}

void Heavy_prog::cBinop_FYic2swv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.5f, 0, m, &cBinop_IeMWzKb7_sendMessage);
}

void Heavy_prog::cMsg_lplaENWl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 50.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_8UsGLTKY, 0, m, &cVar_8UsGLTKY_sendMessage);
}

void Heavy_prog::cBinop_HrgpbMo8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_crgKfTyP_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QDF14YyU_sendMessage);
}

void Heavy_prog::cReceive_j1REFVn3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dUpyfaKL_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_bZuXaWrF, 0, m, &cVar_bZuXaWrF_sendMessage);
  cMsg_Vhy9Ljwm_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_eygmU38y, 0, m, &cVar_eygmU38y_sendMessage);
  cMsg_ZHq5TCu3_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_7jwJfvj3, 0, m, &cVar_7jwJfvj3_sendMessage);
  cMsg_wEGr10jH_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_xLtxndGe, 0, m, &cVar_xLtxndGe_sendMessage);
  cMsg_pvYPxmvt_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ML9W6yhG, 0, m, &cVar_ML9W6yhG_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_rccISklN, 0, m, &cVar_rccISklN_sendMessage);
  cMsg_T4cqS1IB_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_QBCAlWsG, 0, m, &cVar_QBCAlWsG_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_nSNuEzbs, 0, m, &cVar_nSNuEzbs_sendMessage);
  cMsg_T4bWGBHJ_sendMessage(_c, 0, m);
  cSwitchcase_Zjy2OJYS_onMessage(_c, NULL, 0, m, NULL);
  cMsg_vJILJWEZ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_mSWRDxFF, 0, m, &cVar_mSWRDxFF_sendMessage);
  cMsg_3y5P4V2U_sendMessage(_c, 0, m);
  cMsg_FBV1lcy3_sendMessage(_c, 0, m);
  cMsg_DJCEDBwq_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_BoxfpylM, 0, m, &cVar_BoxfpylM_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_rySd3zVT, 0, m, &cVar_rySd3zVT_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_RF9KxeuC, 0, m, &cVar_RF9KxeuC_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_AaymSuam, 0, m, &cVar_AaymSuam_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_6EV6DgMZ, 0, m, &cVar_6EV6DgMZ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_uvdKTaTE, 0, m, &cVar_uvdKTaTE_sendMessage);
  cMsg_kCkzhH0k_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ulYJ5Ij5, 0, m, &cVar_ulYJ5Ij5_sendMessage);
  cMsg_X22QzULq_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_jBFlC4K5, 0, m, &cTabhead_jBFlC4K5_sendMessage);
}

void Heavy_prog::cReceive_tsFT8Wsr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pSZw3WZR, 0, m, &cVar_pSZw3WZR_sendMessage);
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
    __hv_phasor_k_f(&sPhasor_Cy545AmJ, VOf(Bf0));
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
    __hv_phasor_k_f(&sPhasor_j1i4fTBC, VOf(Bf3));
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
    __hv_line_f(&sLine_XFm9zecC, VOf(Bf1));
    __hv_varread_f(&sVarf_58od7xBU, VOf(Bf5));
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf2), VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_GX4tbW3s, VOf(Bf3));
    __hv_varread_f(&sVarf_DSDJJAQs, VOf(Bf2));
    __hv_fma_f(VIf(Bf5), VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_phasor_f(&sPhasor_bXyNIWmJ, VIf(Bf2), VOf(Bf2));
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
    __hv_line_f(&sLine_qGbFiov5, VOf(Bf3));
    __hv_varread_f(&sVarf_CN8UHI72, VOf(Bf0));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf0));
    __hv_floor_f(VIf(Bf0), VOf(Bf2));
    __hv_sub_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_abs_f(VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf0), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf0), VOf(Bf2));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf6), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf2), VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_Ga0gnYM9, VOf(Bf6));
    __hv_varread_f(&sVarf_0gFiSTJT, VOf(Bf5));
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_phasor_f(&sPhasor_cc3BH84m, VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf2), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_var_k_f(VOf(Bf0), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fms_f(VIf(Bf5), VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_abs_f(VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_JIaJBOYI, VOf(Bf2));
    __hv_fma_f(VIf(Bf0), VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_phasor_f(&sPhasor_Sk5QJxKv, VIf(Bf6), VOf(Bf6));
    __hv_neg_f(VIf(Bf6), VOf(Bf0));
    __hv_var_k_f(VOf(Bf5), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_min_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf6), 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f);
    __hv_var_k_f(VOf(Bf0), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fms_f(VIf(Bf5), VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf0), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_min_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f);
    __hv_max_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf3), VIf(Bf0), VOf(Bf2));
    __hv_phasor_k_f(&sPhasor_FkXRaxJc, VOf(Bf6));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_abs_f(VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf6), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf5), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf6));
    __hv_mul_f(VIf(Bf5), VIf(Bf6), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf7), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf8), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf4), VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf6), VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf7), 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f);
    __hv_mul_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_EQIBtitm, VOf(Bf2));
    __hv_min_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_zero_f(VOf(Bf7));
    __hv_max_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_cast_fi(VIf(Bf7), VOi(Bi0));
    __hv_tabread_if(&sTabread_PxVbxWOm, VIi(Bi0), VOf(Bf7));
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf5), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_P5kJeUfq, VOf(Bf7));
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_hhyhVV9R, VOf(Bf5));
    __hv_rpole_f(&sRPole_Ge2MRIXu, VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_5qnKEH7x, VOf(Bf7));
    __hv_phasor_k_f(&sPhasor_qPd4kw7N, VOf(Bf2));
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
    __hv_var_k_f(VOf(Bf4), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf9), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf8), VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf2), VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf4), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_varread_i(&sVari_9xWEeNdV, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf2));
    __hv_var_k_f(VOf(Bf9), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_varwrite_i(&sVari_9xWEeNdV, VIi(Bi1));
    __hv_var_k_f(VOf(Bf2), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_mul_f(VIf(Bf9), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_CxBm4ln3, VOf(Bf9));
    __hv_rpole_f(&sRPole_haU9R7Ky, VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_Iaprhhpm, VIf(Bf9), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf9), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_2iA8Hm9A, VOf(Bf9));
    __hv_mul_f(VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf6), VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf7), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_var_k_f(VOf(Bf4), 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f);
    __hv_mul_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf9), VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_tabread_f(&sTabread_gmREo7Wb, VOf(Bf7));
    __hv_varread_f(&sVarf_m7M056GW, VOf(Bf6));
    __hv_mul_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf4), VIf(Bf6), VOf(Bf4));
    __hv_tabwrite_f(&sTabwrite_IoyIZfBL, VIf(Bf4));
    __hv_add_f(VIf(Bf5), VIf(Bf6), VOf(Bf5));
    __hv_add_f(VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_phasor_k_f(&sPhasor_3G2Lz06L, VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf4));
    __hv_sub_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_abs_f(VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf5), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf4));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf2), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf8), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf5), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf4), VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_X69Ir8I5, VOf(Bf2));
    __hv_mul_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf8), 6.0f, 6.0f, 6.0f, 6.0f, 6.0f, 6.0f, 6.0f, 6.0f);
    __hv_mul_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf9), VIf(Bf8), VOf(Bf9));
    __hv_var_k_f(VOf(Bf2), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_mul_f(VIf(Bf9), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf2), VIf(O1), VOf(O1));
    __hv_var_k_f(VOf(Bf2), 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f);
    __hv_var_k_f(VOf(Bf9), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_fma_f(VIf(Bf3), VIf(Bf9), VIf(Bf0), VOf(Bf0));
    __hv_phasor_k_f(&sPhasor_gaXHzdUd, VOf(Bf9));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf9), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf4), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf9));
    __hv_mul_f(VIf(Bf4), VIf(Bf9), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf7), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf10), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf5), VIf(Bf10), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf9), VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf7), 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f);
    __hv_mul_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_wpKlUsaX, VOf(Bf0));
    __hv_min_f(VIf(Bf7), VIf(Bf0), VOf(Bf0));
    __hv_zero_f(VOf(Bf7));
    __hv_max_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_cast_fi(VIf(Bf7), VOi(Bi1));
    __hv_tabread_if(&sTabread_jpAzKPrF, VIi(Bi1), VOf(Bf7));
    __hv_mul_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf4), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_YmrUviDO, VOf(Bf7));
    __hv_mul_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_wUHthjko, VOf(Bf4));
    __hv_rpole_f(&sRPole_5SykEgRW, VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf3), VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf2), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_mul_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
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
