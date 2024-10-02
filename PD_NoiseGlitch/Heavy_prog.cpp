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

float hTable_fKiIW0XV_data[256] = {-0.0133332f, 0.0566667f, 0.0600001f, 0.0633334f, 0.0700001f, 0.0716667f, 0.0733334f, 0.075f, 0.0766667f, 0.863333f, 0.86f, 0.856667f, 0.854167f, 0.851667f, 0.849167f, 0.846667f, 0.844667f, 0.842667f, 0.840667f, 0.838667f, 0.836667f, 0.835333f, 0.834f, 0.832667f, 0.831333f, 0.83f, 0.827778f, 0.825556f, 0.823333f, 0.133334f, 0.126667f, 0.100001f, 0.0966674f, 0.0933341f, 0.0933341f, 0.0933341f, 0.0933341f, 0.0916674f, 0.0900007f, 0.0883341f, 0.0866674f, 0.0866674f, 0.0866674f, 0.0866674f, 0.0858341f, 0.0850008f, 0.0841674f, 0.0833341f, 0.0816674f, 0.0800008f, 0.0800008f, 0.0800008f, 0.0800008f, 0.0800008f, 0.0800008f, 0.0800008f, 0.0800008f, 0.0800008f, 0.0800008f, 0.0800008f, 0.0800008f, 0.0800008f, 0.0800008f, 0.0800008f, 0.0800008f, 0.0800008f, 0.0800008f, 0.0800008f, 0.0800008f, 0.696667f, 0.696667f, 0.696667f, 0.696667f, 0.696667f, 0.696667f, 0.696667f, 0.696667f, 0.696f, 0.695334f, 0.694667f, 0.694f, 0.693333f, 0.691333f, 0.689333f, 0.687333f, 0.685333f, 0.683334f, 0.681667f, 0.68f, 0.678334f, 0.676667f, 0.675556f, 0.674445f, 0.673334f, 0.67f, 0.666667f, 0.663334f, 0.206667f, 0.160001f, 0.100001f, 0.0966674f, 0.0900007f, 0.0833341f, 0.0800008f, 0.0766674f, 0.0733341f, 0.0700008f, 0.0666674f, 0.0616674f, 0.0566674f, 0.0516675f, 0.0466675f, 0.0444452f, 0.042223f, 0.0400008f, 0.0377786f, 0.0355564f, 0.0333341f, 0.0325008f, 0.0316675f, 0.0308341f, 0.0300008f, 0.0293341f, 0.0286675f, 0.0280008f, 0.0273341f, 0.0266675f, 0.0266675f, 0.0266675f, 0.0266675f, 0.0266675f, 0.0266675f, 0.0266675f, 0.0266675f, 0.0262971f, 0.0259267f, 0.0255564f, 0.025186f, 0.0248156f, 0.0244453f, 0.0240749f, 0.0237045f, 0.0233341f, 0.0233341f, 0.0233341f, 0.0233341f, 0.0233341f, 0.0233341f, 0.0233341f, 0.0233341f, 0.0233341f, 0.0233341f, 0.0233341f, 0.0233341f, 0.0233341f, 0.0233341f, 0.0233341f, 0.0233341f, 0.0233341f, 0.0233341f, 0.0233341f, 0.0233341f, 0.0233341f, 0.0233341f, 0.886667f, 0.89f, 0.891667f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.893333f, 0.203334f, 0.190001f, 0.170001f, 0.156667f, 0.150001f, 0.146667f, 0.143334f, 0.139167f, 0.135001f, 0.130834f, 0.126667f, 0.124001f, 0.121334f, 0.118667f, 0.116001f, 0.113334f, 0.110667f, 0.108001f, 0.105334f, 0.102667f, 0.100001f, 0.0980007f, 0.0960007f, 0.0940007f, 0.0920007f, 0.0900008f, 0.0888896f, 0.0877785f, 0.0866674f, 0.0850008f, 0.0833341f, 0.0833341f, 0.0833341f, 0.0833341f, 0.0800008f, 0.0766674f, 0.0750008f, 0.0733341f, 0.0733341f, 0.0733341f, 0.0700008f, 0.0666674f, 0.0633341f, 0.819999f, 0.816666f, 0.0600001f, 0.0566667f, 0.0533334f};
float hTable_0IRinph8_data[256] = {0.326666f, 0.35f, 0.355f, 0.386666f, 0.4f, 0.416666f, 0.42f, 0.43f, 0.453333f, 0.46f, 0.47f, 0.476666f, 0.496666f, 0.503333f, 0.51f, 0.516666f, 0.53f, 0.536666f, 0.546666f, 0.553333f, 0.56f, 0.576666f, 0.58f, 0.583333f, 0.593333f, 0.599999f, 0.613333f, 0.616666f, 0.623333f, 0.633333f, 0.643333f, 0.649999f, 0.656666f, 0.666666f, 0.673333f, 0.678333f, 0.689999f, 0.699999f, 0.706666f, 0.709999f, 0.716666f, 0.723333f, 0.726666f, 0.733333f, 0.736666f, 0.739999f, 0.749999f, 0.756666f, 0.759999f, 0.763333f, 0.766666f, 0.769999f, 0.773333f, 0.774999f, 0.776666f, 0.779999f, 0.783333f, 0.786666f, 0.793333f, 0.796666f, 0.796666f, 0.799999f, 0.803333f, 0.809999f, 0.809999f, 0.809999f, 0.813333f, 0.819999f, 0.819999f, 0.823333f, 0.824999f, 0.826666f, 0.833333f, 0.836666f, 0.836666f, 0.836666f, 0.843333f, 0.846666f, 0.846666f, 0.849999f, 0.85111f, 0.852221f, 0.853333f, 0.853333f, 0.854999f, 0.856666f, 0.863333f, 0.866666f, 0.868333f, 0.869999f, 0.872221f, 0.874444f, 0.879999f, 0.881666f, 0.883333f, 0.889999f, 0.889999f, 0.889999f, 0.889999f, 0.893333f, 0.893333f, 0.893333f, 0.894999f, 0.896666f, 0.896666f, 0.898333f, 0.899999f, 0.899999f, 0.899999f, 0.899999f, 0.899999f, 0.903333f, 0.903333f, 0.903333f, 0.904999f, 0.906666f, 0.909999f, 0.909999f, 0.909999f, 0.909999f, 0.913333f, 0.914444f, 0.915555f, 0.916666f, 0.916666f, 0.916666f, 0.919999f, 0.919999f, 0.921666f, 0.923333f, 0.923333f, 0.923333f, 0.923333f, 0.926666f, 0.926666f, 0.926666f, 0.928333f, 0.929999f, 0.931666f, 0.933333f, 0.933333f, 0.939999f, 0.941666f, 0.943332f, 0.943332f, 0.943332f, 0.944999f, 0.946666f, 0.949999f, 0.949999f, 0.953332f, 0.956666f, 0.959999f, 0.963332f, 0.963332f, 0.963332f, 0.963332f, 0.963332f, 0.963332f, 0.963332f, 0.963332f, 0.963332f, 0.963332f, 0.963332f, 0.963332f, 0.963332f, 0.963332f, 0.963332f, 0.959999f, 0.954999f, 0.949999f, 0.945555f, 0.94111f, 0.936666f, 0.933333f, 0.929999f, 0.926666f, 0.919999f, 0.913333f, 0.906666f, 0.899999f, 0.896666f, 0.893333f, 0.889999f, 0.883333f, 0.878333f, 0.873333f, 0.867777f, 0.862221f, 0.856666f, 0.846666f, 0.836666f, 0.829999f, 0.823333f, 0.816666f, 0.809999f, 0.803333f, 0.796666f, 0.779999f, 0.769999f, 0.759999f, 0.746666f, 0.736666f, 0.726666f, 0.709999f, 0.699999f, 0.686666f, 0.639999f, 0.633333f, 0.609999f, 0.596666f, 0.589999f, 0.58f, 0.57f, 0.549999f, 0.542222f, 0.534444f, 0.526666f, 0.521666f, 0.516666f, 0.503333f, 0.498333f, 0.493333f, 0.473333f, 0.463333f, 0.45f, 0.436666f, 0.425f, 0.413333f, 0.403333f, 0.393333f, 0.37f, 0.353333f, 0.346666f, 0.333333f, 0.313333f, 0.296666f, 0.286666f, 0.266666f, 0.26f, 0.243333f, 0.235f, 0.216667f, 0.19f, 0.17f, 0.16f, 0.136667f, 0.13f, 0.113333f, 0.103333f, 0.0733333f, 0.06f, 0.04f, 0.0266667f, 0.0166667f, -0.0133333f};



/*
 * Class Functions
 */

Heavy_prog::Heavy_prog(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sPhasor_k_init(&sPhasor_ekcuMOOc, 110.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_Fcn5HsvH, 0.0f, sampleRate);
  numBytes += sDel1_init(&sDel1_mA6aXWoV);
  numBytes += sSamphold_init(&sSamphold_aPoO4z6t);
  numBytes += sPhasor_init(&sPhasor_3VJgdfFJ, sampleRate);
  numBytes += sTabread_init(&sTabread_4ganFZ9P, &hTable_fKiIW0XV, false);
  numBytes += sDel1_init(&sDel1_NrzHFwEI);
  numBytes += sSamphold_init(&sSamphold_LzcVZGIG);
  numBytes += sPhasor_init(&sPhasor_lIYhBKKm, sampleRate);
  numBytes += sTabread_init(&sTabread_eAOgzWJj, &hTable_0IRinph8, false);
  numBytes += sTabwrite_init(&sTabwrite_kuVgAfyY, &hTable_VDTcO6yZ);
  numBytes += sPhasor_k_init(&sPhasor_el74ecSt, 0.0f, sampleRate);
  numBytes += sTabread_init(&sTabread_evddYNmf, &hTable_VDTcO6yZ, false);
  numBytes += sTabread_init(&sTabread_JGZasFtq, &hTable_VDTcO6yZ, false);
  numBytes += sPhasor_k_init(&sPhasor_H9DQoIc7, 0.0f, sampleRate);
  numBytes += sTabread_init(&sTabread_HATnYVOr, &hTable_0IRinph8, false);
  numBytes += sRPole_init(&sRPole_nVmtF4aO);
  numBytes += sPhasor_k_init(&sPhasor_YYhyGSaC, 50.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_ZiC9F6a6, 0.0f, sampleRate);
  numBytes += sDel1_init(&sDel1_bOtVv0G8);
  numBytes += sSamphold_init(&sSamphold_wFaeDLkP);
  numBytes += sPhasor_init(&sPhasor_cKBSuNHy, sampleRate);
  numBytes += sTabread_init(&sTabread_J0KKiP2N, &hTable_0IRinph8, false);
  numBytes += sDel1_init(&sDel1_6WZyQQ0o);
  numBytes += sSamphold_init(&sSamphold_IEMqnpN9);
  numBytes += sPhasor_init(&sPhasor_HFvtNFf5, sampleRate);
  numBytes += sTabread_init(&sTabread_xU6fBMgD, &hTable_fKiIW0XV, false);
  numBytes += sPhasor_k_init(&sPhasor_oEUtY9cW, 1.0f, sampleRate);
  numBytes += hTable_initWithData(&hTable_fKiIW0XV, 256, hTable_fKiIW0XV_data);
  numBytes += cDelay_init(this, &cDelay_uvmMCIas, 0.0f);
  numBytes += cVar_init_f(&cVar_I9CVDef2, 20.0f);
  numBytes += cBinop_init(&cBinop_qSq4Vmi3, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_WEy3xGNP, 0.0f);
  numBytes += cSlice_init(&cSlice_hUbOYUHq, 1, -1);
  numBytes += cSlice_init(&cSlice_QDxawHWO, 1, -1);
  numBytes += cVar_init_f(&cVar_oOVCaLoC, 0.0f);
  numBytes += cVar_init_f(&cVar_mIbAaZpQ, 1.0f);
  numBytes += cVar_init_f(&cVar_KCagZz8h, 0.0f);
  numBytes += cVar_init_f(&cVar_DMashu6b, 0.0f);
  numBytes += cVar_init_f(&cVar_g1oBuaWW, 0.0f);
  numBytes += cSlice_init(&cSlice_P7UmFQd1, 1, 1);
  numBytes += cSlice_init(&cSlice_lz1PakQY, 0, 1);
  numBytes += cBinop_init(&cBinop_0Wmh33jm, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Z3mPzPSQ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_ayPCML5M, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_RaXHOxpJ, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_mHD5FLI6, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_7SVOhoOp, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_QAqDMHdI, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_X7urbrYc, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_kQqkKJ6L, 0.0f);
  numBytes += cVar_init_f(&cVar_OrS7w7FT, 0.0f);
  numBytes += cVar_init_f(&cVar_mYsaHcsK, 22050.0f);
  numBytes += cBinop_init(&cBinop_LDyRzAsJ, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_kTBVqscG, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_WYS3AGIN, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_qYKTHJeR, "soft2");
  numBytes += cSlice_init(&cSlice_DYPwW2I3, 1, 1);
  numBytes += sVarf_init(&sVarf_4BVdOPRF, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_HvHftByA, 1.0f);
  numBytes += cVar_init_f(&cVar_9wOy5tNw, 1.0f);
  numBytes += cVar_init_f(&cVar_9USi1bGD, 0.0f);
  numBytes += cVar_init_f(&cVar_Ns4rBK2t, 1.0f);
  numBytes += cIf_init(&cIf_9RC54elg, false);
  numBytes += cBinop_init(&cBinop_vjocZIW7, 0.0f); // __gte
  numBytes += cVar_init_f(&cVar_PF0OAQt9, 0.0f);
  numBytes += cVar_init_f(&cVar_I9v4H6Mn, 0.0f);
  numBytes += cDelay_init(this, &cDelay_x5F4QmLH, 0.0f);
  numBytes += cVar_init_f(&cVar_mnNlLW9x, 100.0f);
  numBytes += cBinop_init(&cBinop_7UqGEDVj, 0.0f); // __mul
  numBytes += hTable_initWithData(&hTable_0IRinph8, 256, hTable_0IRinph8_data);
  numBytes += cBinop_init(&cBinop_gn3S0iS1, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_goErZMj2, 0.0f); // __div
  numBytes += cDelay_init(this, &cDelay_nalTcgbi, 0.0f);
  numBytes += cVar_init_f(&cVar_Pnvsjd3F, 20.0f);
  numBytes += cBinop_init(&cBinop_FbdY9upx, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_9KmW9XOo, 0.0f);
  numBytes += cSlice_init(&cSlice_e7Y1gWvl, 1, -1);
  numBytes += cSlice_init(&cSlice_rBMqoXp8, 1, -1);
  numBytes += cVar_init_f(&cVar_HYw6cFWG, 0.0f);
  numBytes += cVar_init_f(&cVar_bh183G6m, 1.0f);
  numBytes += cVar_init_f(&cVar_NkC5Mctd, 0.0f);
  numBytes += cVar_init_f(&cVar_V722g2EZ, 0.0f);
  numBytes += cVar_init_f(&cVar_AgHolfkJ, 0.0f);
  numBytes += cSlice_init(&cSlice_oyQ4AzOD, 1, 1);
  numBytes += cSlice_init(&cSlice_04AfUg1V, 0, 1);
  numBytes += cBinop_init(&cBinop_tq0zgSUh, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_tcfWKqLn, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_XlvOTXZ1, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_gqDyb95s, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_KdMF2jrK, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_FaVnmiq8, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_sZI1S4B0, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_LpV0F9xa, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_8Dctnd1v, 0.0f);
  numBytes += cVar_init_f(&cVar_Z67CjfuJ, 0.0f);
  numBytes += sVarf_init(&sVarf_pih6oyOa, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_WnHkkmYv, 280889525);
  numBytes += cSlice_init(&cSlice_pTb9dXdh, 1, 1);
  numBytes += cRandom_init(&cRandom_AhnlKLqM, -1200316192);
  numBytes += cSlice_init(&cSlice_Kbpxxm81, 1, 1);
  numBytes += cRandom_init(&cRandom_2cnvQtND, 1400398701);
  numBytes += cSlice_init(&cSlice_XsItKfKg, 1, 1);
  numBytes += cDelay_init(this, &cDelay_KeU0adYk, 0.0f);
  numBytes += cVar_init_s(&cVar_P3xKJjrv, "samplebuf");
  numBytes += cSlice_init(&cSlice_2gGzKYJ1, 1, 1);
  numBytes += cSlice_init(&cSlice_m6lm5q1p, 1, 1);
  numBytes += cBinop_init(&cBinop_SwbMFJHR, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_aEI58Epe, 0.0f); // __sub
  numBytes += cVar_init_s(&cVar_lhfHBjD6, "samplebuf");
  numBytes += cSlice_init(&cSlice_gRgLfr6C, 1, 1);
  numBytes += sVarf_init(&sVarf_6WAWlZfh, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_Qxuf9t9Q, 0.0f);
  numBytes += cRandom_init(&cRandom_bOzTi1Za, 1973872488);
  numBytes += cSlice_init(&cSlice_iIOfKNOT, 1, 1);
  numBytes += sVari_init(&sVari_ASLf9wfE, 0, 0, false);
  numBytes += cVar_init_s(&cVar_I8CJRgRl, "soft");
  numBytes += cSlice_init(&cSlice_u05Jr74a, 1, 1);
  numBytes += sVarf_init(&sVarf_YBUaIaud, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_QTlETYk6, 0.0f);
  numBytes += cVar_init_f(&cVar_7k61r2G5, 0.0f);
  numBytes += cVar_init_s(&cVar_xmvA15ai, "soft2");
  numBytes += cSlice_init(&cSlice_6HUHgbLE, 1, 1);
  numBytes += sVarf_init(&sVarf_H6zCkV6n, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_UERNR3Bd, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_LlDttpyA, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_nbZNhxfg, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_1dNfVTG8, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_vChBdXUn, 0.0f);
  numBytes += cRandom_init(&cRandom_GrUU7KbI, 1101344370);
  numBytes += cSlice_init(&cSlice_nKfweGqM, 1, 1);
  numBytes += sVari_init(&sVari_aFs7YpR4, 0, 0, false);
  numBytes += cVar_init_s(&cVar_5ObZ6qKm, "soft");
  numBytes += cSlice_init(&cSlice_WRAon9TM, 1, 1);
  numBytes += sVarf_init(&sVarf_oHh7sTsp, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_fPNbaZof, 0.0f);
  numBytes += cVar_init_f(&cVar_PDMsQ4kI, 0.0f);
  numBytes += cVar_init_s(&cVar_PU7UbYMo, "soft2");
  numBytes += cSlice_init(&cSlice_JomLczov, 1, 1);
  numBytes += sVarf_init(&sVarf_OAuC1DVW, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_jg8afP2U, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_joS8eQes, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_dEG7qAjo, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_f89oAcfe, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_DMMQOLTT, 0.0f); // __div
  numBytes += hTable_init(&hTable_VDTcO6yZ, 10000);
  numBytes += sVarf_init(&sVarf_QmycUAze, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_prog::~Heavy_prog() {
  hTable_free(&hTable_fKiIW0XV);
  hTable_free(&hTable_0IRinph8);
  hTable_free(&hTable_VDTcO6yZ);
}

HvTable *Heavy_prog::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x130A899: return &hTable_VDTcO6yZ; // samplebuf
    case 0x69706D21: return &hTable_fKiIW0XV; // soft
    case 0x18702E06: return &hTable_0IRinph8; // soft2
    default: return nullptr;
  }
}

void Heavy_prog::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_kGuNA4kw_sendMessage);
      break;
    }
    case 0x5C8E49B6: { // freqA
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_7kFqYHo0_sendMessage);
      break;
    }
    case 0x24D2FF6A: { // freqB
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_HKJaAgwj_sendMessage);
      break;
    }
    case 0xB3BE0950: { // freqC
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_2cV4DY3m_sendMessage);
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


void Heavy_prog::hTable_fKiIW0XV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cMsg_W5qFgpPD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4ongLnOn_sendMessage);
}

void Heavy_prog::cSystem_4ongLnOn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Z3mPzPSQ, HV_BINOP_MULTIPLY, 1, m, &cBinop_Z3mPzPSQ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_0Wmh33jm, HV_BINOP_MULTIPLY, 1, m, &cBinop_0Wmh33jm_sendMessage);
}

void Heavy_prog::cSwitchcase_p2decAiI_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_MeygDXML_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_MeygDXML_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_i6F7MFJA_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_uvmMCIas_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_uvmMCIas, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uvmMCIas, 0, m, &cDelay_uvmMCIas_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_WEy3xGNP, 0, m, &cVar_WEy3xGNP_sendMessage);
}

void Heavy_prog::cCast_i6F7MFJA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MeygDXML_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_uvmMCIas, 0, m, &cDelay_uvmMCIas_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_WEy3xGNP, 0, m, &cVar_WEy3xGNP_sendMessage);
}

void Heavy_prog::cMsg_Vi4fKRwz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_eiNyx99P_sendMessage);
}

void Heavy_prog::cSystem_eiNyx99P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_2xMGOfew_sendMessage);
}

void Heavy_prog::cVar_I9CVDef2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qSq4Vmi3, HV_BINOP_MULTIPLY, 0, m, &cBinop_qSq4Vmi3_sendMessage);
}

void Heavy_prog::cMsg_MeygDXML_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_uvmMCIas, 0, m, &cDelay_uvmMCIas_sendMessage);
}

void Heavy_prog::cBinop_NC9tNiym_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_uvmMCIas, 2, m, &cDelay_uvmMCIas_sendMessage);
}

void Heavy_prog::cBinop_2xMGOfew_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qSq4Vmi3, HV_BINOP_MULTIPLY, 1, m, &cBinop_qSq4Vmi3_sendMessage);
}

void Heavy_prog::cBinop_qSq4Vmi3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_NC9tNiym_sendMessage);
}

void Heavy_prog::cVar_WEy3xGNP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ayPCML5M, HV_BINOP_SUBTRACT, 0, m, &cBinop_ayPCML5M_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_AgpNgzXN_sendMessage);
}

void Heavy_prog::cSwitchcase_TL1nwg3Q_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TOubOCp3_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MYXbbBvb_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_TOubOCp3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_g1oBuaWW, 0, m, &cVar_g1oBuaWW_sendMessage);
}

void Heavy_prog::cCast_MYXbbBvb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_29hTB5Ef_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dYWXJvQ5_sendMessage);
}

void Heavy_prog::cSwitchcase_HRWWF04F_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_hUbOYUHq, 0, m, &cSlice_hUbOYUHq_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_QDxawHWO, 0, m, &cSlice_QDxawHWO_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WuiWeiQo_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_P7UmFQd1, 0, m, &cSlice_P7UmFQd1_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_lz1PakQY, 0, m, &cSlice_lz1PakQY_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gCuJTnUs_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Cfv9KH9N_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cSlice_hUbOYUHq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_y0tKb7kL_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_y0tKb7kL_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_QDxawHWO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nB2tHsTa_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ygDOwYpf_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nB2tHsTa_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ygDOwYpf_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cVar_oOVCaLoC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_HAFBjVno_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5DvjtkpD_sendMessage);
}

void Heavy_prog::cVar_mIbAaZpQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_c4JNtdil_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cSwitchcase_c4JNtdil_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2w9ra88w_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_Z3mPzPSQ, HV_BINOP_MULTIPLY, 0, m, &cBinop_Z3mPzPSQ_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_mHD5FLI6, HV_BINOP_DIVIDE, 1, m, &cBinop_mHD5FLI6_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_I9CVDef2, 0, m, &cVar_I9CVDef2_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cCast_2w9ra88w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yfVqulBB_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_KCagZz8h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_X7urbrYc, HV_BINOP_SUBTRACT, 1, m, &cBinop_X7urbrYc_sendMessage);
}

void Heavy_prog::cVar_DMashu6b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_g1oBuaWW, 0, m, &cVar_g1oBuaWW_sendMessage);
}

void Heavy_prog::cVar_g1oBuaWW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RaXHOxpJ, HV_BINOP_ADD, 0, m, &cBinop_RaXHOxpJ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_QAqDMHdI, HV_BINOP_ADD, 0, m, &cBinop_QAqDMHdI_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_kQqkKJ6L, 0, m, &cVar_kQqkKJ6L_sendMessage);
}

void Heavy_prog::cSlice_P7UmFQd1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_HAFBjVno_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5DvjtkpD_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_lz1PakQY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6DDOwB87_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SwlwpLbm_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_phkKPPzm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WEy3xGNP, 1, m, &cVar_WEy3xGNP_sendMessage);
}

void Heavy_prog::cBinop_0Wmh33jm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_phkKPPzm_sendMessage);
}

void Heavy_prog::cBinop_Z3mPzPSQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_2WRNriIo_sendMessage);
}

void Heavy_prog::cBinop_2WRNriIo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ayPCML5M, HV_BINOP_SUBTRACT, 1, m, &cBinop_ayPCML5M_sendMessage);
}

void Heavy_prog::cBinop_ayPCML5M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WEy3xGNP, 1, m, &cVar_WEy3xGNP_sendMessage);
}

void Heavy_prog::cMsg_7wxCzoJu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_p2decAiI_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_n5aPDQWt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_p2decAiI_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_QAqDMHdI, HV_BINOP_ADD, 1, m, &cBinop_QAqDMHdI_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_RaXHOxpJ, HV_BINOP_ADD, 1, m, &cBinop_RaXHOxpJ_sendMessage);
}

void Heavy_prog::cBinop_AgpNgzXN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_TL1nwg3Q_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_RaXHOxpJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_g1oBuaWW, 1, m, &cVar_g1oBuaWW_sendMessage);
}

void Heavy_prog::cBinop_mHD5FLI6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7SVOhoOp, HV_BINOP_DIVIDE, 1, m, &cBinop_7SVOhoOp_sendMessage);
}

void Heavy_prog::cBinop_7SVOhoOp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QAqDMHdI, HV_BINOP_ADD, 1, m, &cBinop_QAqDMHdI_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_RaXHOxpJ, HV_BINOP_ADD, 1, m, &cBinop_RaXHOxpJ_sendMessage);
}

void Heavy_prog::cCast_HAFBjVno_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0Wmh33jm, HV_BINOP_MULTIPLY, 0, m, &cBinop_0Wmh33jm_sendMessage);
}

void Heavy_prog::cCast_5DvjtkpD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mHD5FLI6, HV_BINOP_DIVIDE, 0, m, &cBinop_mHD5FLI6_sendMessage);
}

void Heavy_prog::cCast_6DDOwB87_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DMashu6b, 1, m, &cVar_DMashu6b_sendMessage);
}

void Heavy_prog::cCast_SwlwpLbm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_X7urbrYc, HV_BINOP_SUBTRACT, 0, m, &cBinop_X7urbrYc_sendMessage);
}

void Heavy_prog::cCast_dYWXJvQ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DMashu6b, 0, m, &cVar_DMashu6b_sendMessage);
}

void Heavy_prog::cCast_29hTB5Ef_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_n5aPDQWt_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_QAqDMHdI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KCagZz8h, 0, m, &cVar_KCagZz8h_sendMessage);
}

void Heavy_prog::cMsg_y0tKb7kL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_p2decAiI_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_4NocfFwI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_oOVCaLoC, 1, m, &cVar_oOVCaLoC_sendMessage);
}

void Heavy_prog::cMsg_yfVqulBB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Z3mPzPSQ, HV_BINOP_MULTIPLY, 0, m, &cBinop_Z3mPzPSQ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_mHD5FLI6, HV_BINOP_DIVIDE, 1, m, &cBinop_mHD5FLI6_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_I9CVDef2, 0, m, &cVar_I9CVDef2_sendMessage);
}

void Heavy_prog::cCast_ygDOwYpf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VR3jeTiJ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_QAqDMHdI, HV_BINOP_ADD, 0, m, &cBinop_QAqDMHdI_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_g1oBuaWW, 1, m, &cVar_g1oBuaWW_sendMessage);
}

void Heavy_prog::cCast_nB2tHsTa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_y0tKb7kL_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_X7urbrYc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7SVOhoOp, HV_BINOP_DIVIDE, 0, m, &cBinop_7SVOhoOp_sendMessage);
}

void Heavy_prog::cCast_VR3jeTiJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_n5aPDQWt_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_Cfv9KH9N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4NocfFwI_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_gCuJTnUs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7wxCzoJu_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_WuiWeiQo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_oOVCaLoC, 0, m, &cVar_oOVCaLoC_sendMessage);
}

void Heavy_prog::cVar_kQqkKJ6L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 3000.0f, 0, m, &cBinop_G7jkabk9_sendMessage);
}

void Heavy_prog::cVar_OrS7w7FT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mYsaHcsK, 0, m, &cVar_mYsaHcsK_sendMessage);
}

void Heavy_prog::cVar_mYsaHcsK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LDyRzAsJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_LDyRzAsJ_sendMessage);
}

void Heavy_prog::cMsg_Qxdxy8vo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_A28rroyb_sendMessage);
}

void Heavy_prog::cSystem_A28rroyb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_L0VAYQ81_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_LDyRzAsJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_xlsZnBT2_sendMessage);
}

void Heavy_prog::cBinop_rCPcPjBi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LDyRzAsJ, HV_BINOP_MULTIPLY, 1, m, &cBinop_LDyRzAsJ_sendMessage);
}

void Heavy_prog::cMsg_L0VAYQ81_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_rCPcPjBi_sendMessage);
}

void Heavy_prog::cBinop_xlsZnBT2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_kCbyGQsP_sendMessage);
}

void Heavy_prog::cBinop_kCbyGQsP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_MjB3M5wD_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_WYS3AGIN, m);
}

void Heavy_prog::cBinop_MjB3M5wD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_kTBVqscG, m);
}

void Heavy_prog::cBinop_G7jkabk9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OrS7w7FT, 0, m, &cVar_OrS7w7FT_sendMessage);
}

void Heavy_prog::cSwitchcase_DE8wOGC4_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_DYPwW2I3, 0, m, &cSlice_DYPwW2I3_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cVar_qYKTHJeR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eQd5HbUb_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_QuOi4jk7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_VYj9Sddo_sendMessage);
}

void Heavy_prog::cMsg_eQd5HbUb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_QuOi4jk7_sendMessage);
}

void Heavy_prog::cSlice_DYPwW2I3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_HATnYVOr, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_qYKTHJeR, 0, m, &cVar_qYKTHJeR_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_VYj9Sddo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_4BVdOPRF, m);
}

void Heavy_prog::cMsg_5V9oECde_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1000.0f);
  cSwitchcase_HRWWF04F_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cVar_HvHftByA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_M49DjQLY_sendMessage);
  cMsg_5V9oECde_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_M49DjQLY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HvHftByA, 1, m, &cVar_HvHftByA_sendMessage);
}

void Heavy_prog::cVar_9wOy5tNw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_mjfOT5eW_sendMessage);
  cMsg_JJJcK8md_sendMessage(_c, 0, m);
  cSwitchcase_HpzuTRZ4_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_mjfOT5eW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9wOy5tNw, 1, m, &cVar_9wOy5tNw_sendMessage);
}

void Heavy_prog::cVar_9USi1bGD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cVar_Ns4rBK2t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_BQqTF06H_sendMessage);
  cSwitchcase_wlQnxYhn_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_BQqTF06H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Ns4rBK2t, 1, m, &cVar_Ns4rBK2t_sendMessage);
}

void Heavy_prog::cCast_3oxZQgeF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cIf_9RC54elg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1uCxAqtq_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_vjocZIW7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_9RC54elg, 1, m, &cIf_9RC54elg_sendMessage);
}

void Heavy_prog::cVar_PF0OAQt9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vjocZIW7, HV_BINOP_GREATER_THAN_EQL, 1, m, &cBinop_vjocZIW7_sendMessage);
}

void Heavy_prog::cVar_I9v4H6Mn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cSwitchcase_wlQnxYhn_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_isref72q_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_isref72q_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_caOcHcPl_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_x5F4QmLH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_x5F4QmLH, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_x5F4QmLH, 0, m, &cDelay_x5F4QmLH_sendMessage);
  cSwitchcase_yvA42JMM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_caOcHcPl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_isref72q_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_x5F4QmLH, 0, m, &cDelay_x5F4QmLH_sendMessage);
  cSwitchcase_yvA42JMM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_gaXEVxs7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ZEmCQWtu_sendMessage);
}

void Heavy_prog::cSystem_ZEmCQWtu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_VVNSElUg_sendMessage);
}

void Heavy_prog::cVar_mnNlLW9x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7UqGEDVj, HV_BINOP_MULTIPLY, 0, m, &cBinop_7UqGEDVj_sendMessage);
}

void Heavy_prog::cMsg_isref72q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_x5F4QmLH, 0, m, &cDelay_x5F4QmLH_sendMessage);
}

void Heavy_prog::cBinop_dO6Qjnir_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_x5F4QmLH, 2, m, &cDelay_x5F4QmLH_sendMessage);
}

void Heavy_prog::cBinop_VVNSElUg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7UqGEDVj, HV_BINOP_MULTIPLY, 1, m, &cBinop_7UqGEDVj_sendMessage);
}

void Heavy_prog::cBinop_7UqGEDVj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_dO6Qjnir_sendMessage);
}

void Heavy_prog::hTable_0IRinph8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cSwitchcase_HpzuTRZ4_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Hj4LCaRB_sendMessage);
      break;
    }
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wUK0hKsX_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_Hj4LCaRB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VaKdq0lL_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iu82Ensb_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_sYi0UCfG_sendMessage);
}

void Heavy_prog::cCast_wUK0hKsX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LEVeJnnW_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yalr0UsB_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_a623sDwO_sendMessage);
}

void Heavy_prog::cSystem_t4VfIqT7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gn3S0iS1, HV_BINOP_SUBTRACT, 1, m, &cBinop_gn3S0iS1_sendMessage);
}

void Heavy_prog::cMsg_d6cqH8V1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "currentTime");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_t4VfIqT7_sendMessage);
}

void Heavy_prog::cBinop_gn3S0iS1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_goErZMj2, HV_BINOP_DIVIDE, 0, m, &cBinop_goErZMj2_sendMessage);
}

void Heavy_prog::cSystem_Vnxkz4t7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gn3S0iS1, HV_BINOP_SUBTRACT, 0, m, &cBinop_gn3S0iS1_sendMessage);
}

void Heavy_prog::cMsg_x0o8w8hN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "currentTime");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Vnxkz4t7_sendMessage);
}

void Heavy_prog::cBinop_goErZMj2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_TsTtvE6C_onMessage(_c, NULL, 0, m, NULL);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_YnIHrSpF_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IaUJf8wm_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2AcmE9EC_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ScLxVTVp_sendMessage);
}

void Heavy_prog::cSystem_Y1A9BPIP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_UQ2OT6D9_sendMessage);
}

void Heavy_prog::cMsg_lsuVWx6j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Y1A9BPIP_sendMessage);
}

void Heavy_prog::cBinop_UQ2OT6D9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_goErZMj2, HV_BINOP_DIVIDE, 1, m, &cBinop_goErZMj2_sendMessage);
}

void Heavy_prog::cSwitchcase_TsTtvE6C_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x453B6000: { // "2998.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DadAOeN2_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_DadAOeN2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sKNC905A_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_bSaxZ4xJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_lzAy9WdL_sendMessage);
}

void Heavy_prog::cSystem_lzAy9WdL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tcfWKqLn, HV_BINOP_MULTIPLY, 1, m, &cBinop_tcfWKqLn_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_tq0zgSUh, HV_BINOP_MULTIPLY, 1, m, &cBinop_tq0zgSUh_sendMessage);
}

void Heavy_prog::cSwitchcase_I5Vo4jOJ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_HcvX76bN_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_HcvX76bN_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qg2wmv29_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_nalTcgbi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_nalTcgbi, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nalTcgbi, 0, m, &cDelay_nalTcgbi_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_9KmW9XOo, 0, m, &cVar_9KmW9XOo_sendMessage);
}

void Heavy_prog::cCast_qg2wmv29_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HcvX76bN_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nalTcgbi, 0, m, &cDelay_nalTcgbi_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_9KmW9XOo, 0, m, &cVar_9KmW9XOo_sendMessage);
}

void Heavy_prog::cMsg_PZteXITA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_cZHLhYfH_sendMessage);
}

void Heavy_prog::cSystem_cZHLhYfH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_IgyJq2HS_sendMessage);
}

void Heavy_prog::cVar_Pnvsjd3F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FbdY9upx, HV_BINOP_MULTIPLY, 0, m, &cBinop_FbdY9upx_sendMessage);
}

void Heavy_prog::cMsg_HcvX76bN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_nalTcgbi, 0, m, &cDelay_nalTcgbi_sendMessage);
}

void Heavy_prog::cBinop_nzrlgXE0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_nalTcgbi, 2, m, &cDelay_nalTcgbi_sendMessage);
}

void Heavy_prog::cBinop_IgyJq2HS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FbdY9upx, HV_BINOP_MULTIPLY, 1, m, &cBinop_FbdY9upx_sendMessage);
}

void Heavy_prog::cBinop_FbdY9upx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_nzrlgXE0_sendMessage);
}

void Heavy_prog::cVar_9KmW9XOo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XlvOTXZ1, HV_BINOP_SUBTRACT, 0, m, &cBinop_XlvOTXZ1_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_zsuWQ9p2_sendMessage);
}

void Heavy_prog::cSwitchcase_dcv0iF2n_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PKC3YDhv_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pHrju9HB_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_PKC3YDhv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_AgHolfkJ, 0, m, &cVar_AgHolfkJ_sendMessage);
}

void Heavy_prog::cCast_pHrju9HB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5r6uLnDy_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iaPHHYBC_sendMessage);
}

void Heavy_prog::cSwitchcase_jvHHoV5u_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_e7Y1gWvl, 0, m, &cSlice_e7Y1gWvl_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_rBMqoXp8, 0, m, &cSlice_rBMqoXp8_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ga9E3Xwz_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_oyQ4AzOD, 0, m, &cSlice_oyQ4AzOD_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_04AfUg1V, 0, m, &cSlice_04AfUg1V_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_M9ZYOuVE_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zB9CueAS_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cSlice_e7Y1gWvl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_gEe8SpGA_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_gEe8SpGA_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_rBMqoXp8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TIXT0Dii_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_PchfzXck_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TIXT0Dii_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_PchfzXck_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cVar_HYw6cFWG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6uBxdqzc_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_aM1D38hJ_sendMessage);
}

void Heavy_prog::cVar_bh183G6m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_yDanFwb0_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cSwitchcase_yDanFwb0_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qMqLP7xe_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_tcfWKqLn, HV_BINOP_MULTIPLY, 0, m, &cBinop_tcfWKqLn_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_KdMF2jrK, HV_BINOP_DIVIDE, 1, m, &cBinop_KdMF2jrK_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_Pnvsjd3F, 0, m, &cVar_Pnvsjd3F_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cCast_qMqLP7xe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zbM7j0ES_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_NkC5Mctd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LpV0F9xa, HV_BINOP_SUBTRACT, 1, m, &cBinop_LpV0F9xa_sendMessage);
}

void Heavy_prog::cVar_V722g2EZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_AgHolfkJ, 0, m, &cVar_AgHolfkJ_sendMessage);
}

void Heavy_prog::cVar_AgHolfkJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gqDyb95s, HV_BINOP_ADD, 0, m, &cBinop_gqDyb95s_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_sZI1S4B0, HV_BINOP_ADD, 0, m, &cBinop_sZI1S4B0_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_8Dctnd1v, 0, m, &cVar_8Dctnd1v_sendMessage);
}

void Heavy_prog::cSlice_oyQ4AzOD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6uBxdqzc_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_aM1D38hJ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_04AfUg1V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZzT0dVU7_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_B8bZES3T_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_hvIzhBUc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9KmW9XOo, 1, m, &cVar_9KmW9XOo_sendMessage);
}

void Heavy_prog::cBinop_tq0zgSUh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_hvIzhBUc_sendMessage);
}

void Heavy_prog::cBinop_tcfWKqLn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_kEoG1jMg_sendMessage);
}

void Heavy_prog::cBinop_kEoG1jMg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XlvOTXZ1, HV_BINOP_SUBTRACT, 1, m, &cBinop_XlvOTXZ1_sendMessage);
}

void Heavy_prog::cBinop_XlvOTXZ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9KmW9XOo, 1, m, &cVar_9KmW9XOo_sendMessage);
}

void Heavy_prog::cMsg_q8H2cgS7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_I5Vo4jOJ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_ESbvYltz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_I5Vo4jOJ_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_sZI1S4B0, HV_BINOP_ADD, 1, m, &cBinop_sZI1S4B0_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_gqDyb95s, HV_BINOP_ADD, 1, m, &cBinop_gqDyb95s_sendMessage);
}

void Heavy_prog::cBinop_zsuWQ9p2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_dcv0iF2n_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_gqDyb95s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_AgHolfkJ, 1, m, &cVar_AgHolfkJ_sendMessage);
}

void Heavy_prog::cBinop_KdMF2jrK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FaVnmiq8, HV_BINOP_DIVIDE, 1, m, &cBinop_FaVnmiq8_sendMessage);
}

void Heavy_prog::cBinop_FaVnmiq8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sZI1S4B0, HV_BINOP_ADD, 1, m, &cBinop_sZI1S4B0_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_gqDyb95s, HV_BINOP_ADD, 1, m, &cBinop_gqDyb95s_sendMessage);
}

void Heavy_prog::cCast_6uBxdqzc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tq0zgSUh, HV_BINOP_MULTIPLY, 0, m, &cBinop_tq0zgSUh_sendMessage);
}

void Heavy_prog::cCast_aM1D38hJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KdMF2jrK, HV_BINOP_DIVIDE, 0, m, &cBinop_KdMF2jrK_sendMessage);
}

void Heavy_prog::cCast_ZzT0dVU7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_V722g2EZ, 1, m, &cVar_V722g2EZ_sendMessage);
}

void Heavy_prog::cCast_B8bZES3T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LpV0F9xa, HV_BINOP_SUBTRACT, 0, m, &cBinop_LpV0F9xa_sendMessage);
}

void Heavy_prog::cCast_5r6uLnDy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ESbvYltz_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_iaPHHYBC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_V722g2EZ, 0, m, &cVar_V722g2EZ_sendMessage);
}

void Heavy_prog::cBinop_sZI1S4B0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NkC5Mctd, 0, m, &cVar_NkC5Mctd_sendMessage);
}

void Heavy_prog::cMsg_gEe8SpGA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_I5Vo4jOJ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_SbdT5QHB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_HYw6cFWG, 1, m, &cVar_HYw6cFWG_sendMessage);
}

void Heavy_prog::cMsg_zbM7j0ES_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_tcfWKqLn, HV_BINOP_MULTIPLY, 0, m, &cBinop_tcfWKqLn_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_KdMF2jrK, HV_BINOP_DIVIDE, 1, m, &cBinop_KdMF2jrK_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Pnvsjd3F, 0, m, &cVar_Pnvsjd3F_sendMessage);
}

void Heavy_prog::cCast_TIXT0Dii_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gEe8SpGA_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_PchfzXck_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kbFs8RZc_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_sZI1S4B0, HV_BINOP_ADD, 0, m, &cBinop_sZI1S4B0_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_AgHolfkJ, 1, m, &cVar_AgHolfkJ_sendMessage);
}

void Heavy_prog::cBinop_LpV0F9xa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FaVnmiq8, HV_BINOP_DIVIDE, 0, m, &cBinop_FaVnmiq8_sendMessage);
}

void Heavy_prog::cCast_kbFs8RZc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ESbvYltz_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_ga9E3Xwz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HYw6cFWG, 0, m, &cVar_HYw6cFWG_sendMessage);
}

void Heavy_prog::cCast_M9ZYOuVE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_q8H2cgS7_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_zB9CueAS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SbdT5QHB_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_8Dctnd1v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_pih6oyOa, m);
}

void Heavy_prog::cVar_Z67CjfuJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_oEUtY9cW, 0, m);
}

void Heavy_prog::cMsg_JJJcK8md_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1000.0f);
  cSwitchcase_jvHHoV5u_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_KoPnBVtS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 10.0f, 0, m, &cBinop_RS5vAzAe_sendMessage);
}

void Heavy_prog::cBinop_RS5vAzAe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Z67CjfuJ, 0, m, &cVar_Z67CjfuJ_sendMessage);
}

void Heavy_prog::cSwitchcase_yvA42JMM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_pTb9dXdh, 0, m, &cSlice_pTb9dXdh_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_WnHkkmYv, 0, m, &cRandom_WnHkkmYv_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_8HLASfv0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_BXX5Hyz1_sendMessage);
}

void Heavy_prog::cUnop_BXX5Hyz1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9USi1bGD, 0, m, &cVar_9USi1bGD_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_vjocZIW7, HV_BINOP_GREATER_THAN_EQL, 0, m, &cBinop_vjocZIW7_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_9RC54elg, 0, m, &cIf_9RC54elg_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BoKlLRXK_sendMessage);
}

void Heavy_prog::cRandom_WnHkkmYv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_8HLASfv0_sendMessage);
}

void Heavy_prog::cSlice_pTb9dXdh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_WnHkkmYv, 1, m, &cRandom_WnHkkmYv_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_dusj7UPM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Kbpxxm81, 0, m, &cSlice_Kbpxxm81_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_AhnlKLqM, 0, m, &cRandom_AhnlKLqM_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_MxE8gEbE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_ilO3Qh8Q_sendMessage);
}

void Heavy_prog::cUnop_ilO3Qh8Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_I9v4H6Mn, 0, m, &cVar_I9v4H6Mn_sendMessage);
  cSend_cCtg7mG5_sendMessage(_c, 0, m);
}

void Heavy_prog::cRandom_AhnlKLqM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.0f, 0, m, &cBinop_MxE8gEbE_sendMessage);
}

void Heavy_prog::cSlice_Kbpxxm81_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_AhnlKLqM, 1, m, &cRandom_AhnlKLqM_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_17bmFlEr_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_XsItKfKg, 0, m, &cSlice_XsItKfKg_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_2cnvQtND, 0, m, &cRandom_2cnvQtND_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_NIfgpfJd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_QGc5JNSO_sendMessage);
}

void Heavy_prog::cUnop_QGc5JNSO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PF0OAQt9, 0, m, &cVar_PF0OAQt9_sendMessage);
  cSend_mI9C4m2z_sendMessage(_c, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 12.0f, 0, m, &cBinop_uNBLMKRr_sendMessage);
}

void Heavy_prog::cRandom_2cnvQtND_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 54.0f, 0, m, &cBinop_NIfgpfJd_sendMessage);
}

void Heavy_prog::cSlice_XsItKfKg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_2cnvQtND, 1, m, &cRandom_2cnvQtND_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_GzwpqvBM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x6FF57CB4: { // "start"
      cSlice_onMessage(_c, &Context(_c)->cSlice_m6lm5q1p, 0, m, &cSlice_m6lm5q1p_sendMessage);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_zlDcFU66_sendMessage(_c, 0, m);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_2gGzKYJ1, 0, m, &cSlice_2gGzKYJ1_sendMessage);
      break;
    }
    default: {
      cMsg_EzHDjlMr_sendMessage(_c, 0, m);
      break;
    }
  }
}

void Heavy_prog::cDelay_KeU0adYk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_KeU0adYk, m);
  cMsg_zlDcFU66_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_P3xKJjrv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6osVXNUF_sendMessage(_c, 0, m);
}

void Heavy_prog::cSlice_2gGzKYJ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_kuVgAfyY, 2, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_P3xKJjrv, 0, m, &cVar_P3xKJjrv_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_m6lm5q1p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_kuVgAfyY, 1, m, NULL);
      cBinop_onMessage(_c, &Context(_c)->cBinop_aEI58Epe, HV_BINOP_SUBTRACT, 0, m, &cBinop_aEI58Epe_sendMessage);
      break;
    }
    case 1: {
      cMsg_K6ANqsMT_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_esnWj0bb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SwbMFJHR, HV_BINOP_DIVIDE, 1, m, &cBinop_SwbMFJHR_sendMessage);
}

void Heavy_prog::cBinop_SwbMFJHR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_co191QgJ_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KeU0adYk, 1, m, &cDelay_KeU0adYk_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KeU0adYk, 0, m, &cDelay_KeU0adYk_sendMessage);
}

void Heavy_prog::cMsg_EzHDjlMr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_kuVgAfyY, 1, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_aEI58Epe, HV_BINOP_SUBTRACT, 0, m, &cBinop_aEI58Epe_sendMessage);
}

void Heavy_prog::cSystem_KISAv7UZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aEI58Epe, HV_BINOP_SUBTRACT, 1, m, &cBinop_aEI58Epe_sendMessage);
}

void Heavy_prog::cMsg_6osVXNUF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_KISAv7UZ_sendMessage);
}

void Heavy_prog::cBinop_aEI58Epe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_KrnkSY8K_sendMessage);
}

void Heavy_prog::cBinop_KrnkSY8K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SwbMFJHR, HV_BINOP_DIVIDE, 0, m, &cBinop_SwbMFJHR_sendMessage);
}

void Heavy_prog::cMsg_co191QgJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_KeU0adYk, 0, m, &cDelay_KeU0adYk_sendMessage);
}

void Heavy_prog::cMsg_zlDcFU66_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_kuVgAfyY, 1, m, NULL);
}

void Heavy_prog::cMsg_jE2gHkE6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_wzOsf9IV_sendMessage);
}

void Heavy_prog::cSystem_wzOsf9IV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_esnWj0bb_sendMessage);
}

void Heavy_prog::cMsg_K6ANqsMT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_kuVgAfyY, 1, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_aEI58Epe, HV_BINOP_SUBTRACT, 0, m, &cBinop_aEI58Epe_sendMessage);
}

void Heavy_prog::cSwitchcase_oIk4tdHr_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_gRgLfr6C, 0, m, &cSlice_gRgLfr6C_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cVar_lhfHBjD6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KElujq3v_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_JHrGclky_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 2.0f, 0, m, &cBinop_8Y2zMWuT_sendMessage);
}

void Heavy_prog::cBinop_8Y2zMWuT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_6WAWlZfh, m);
}

void Heavy_prog::cMsg_KElujq3v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JHrGclky_sendMessage);
}

void Heavy_prog::cSlice_gRgLfr6C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_evddYNmf, 1, m, NULL);
      sTabread_onMessage(_c, &Context(_c)->sTabread_JGZasFtq, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_lhfHBjD6, 0, m, &cVar_lhfHBjD6_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cVar_Qxuf9t9Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_Fcn5HsvH, 0, m);
}

void Heavy_prog::cSwitchcase_JpS84zFi_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_iIOfKNOT, 0, m, &cSlice_iIOfKNOT_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_bOzTi1Za, 0, m, &cRandom_bOzTi1Za_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_eCBO7kPs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_5sptwqFs_sendMessage);
}

void Heavy_prog::cUnop_5sptwqFs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QZQ1mHLn_sendMessage(_c, 0, m);
}

void Heavy_prog::cRandom_bOzTi1Za_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_eCBO7kPs_sendMessage);
}

void Heavy_prog::cSlice_iIOfKNOT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_bOzTi1Za, 1, m, &cRandom_bOzTi1Za_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cMsg_QZQ1mHLn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_ASLf9wfE, m);
}

void Heavy_prog::cSwitchcase_hLY1bVz8_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_u05Jr74a, 0, m, &cSlice_u05Jr74a_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cVar_I8CJRgRl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XLBvEwXq_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_chLAsyt1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_i0g2MsJC_sendMessage);
}

void Heavy_prog::cMsg_XLBvEwXq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_chLAsyt1_sendMessage);
}

void Heavy_prog::cSlice_u05Jr74a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_4ganFZ9P, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_I8CJRgRl, 0, m, &cVar_I8CJRgRl_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_i0g2MsJC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_YBUaIaud, m);
}

void Heavy_prog::cVar_QTlETYk6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cVar_7k61r2G5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cSwitchcase_Q4zLlDzI_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_6HUHgbLE, 0, m, &cSlice_6HUHgbLE_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cVar_xmvA15ai_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VvZ68Un7_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_xnp1YfOi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_K9ZuWQ79_sendMessage);
}

void Heavy_prog::cMsg_VvZ68Un7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xnp1YfOi_sendMessage);
}

void Heavy_prog::cSlice_6HUHgbLE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_eAOgzWJj, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_xmvA15ai, 0, m, &cVar_xmvA15ai_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_K9ZuWQ79_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_H6zCkV6n, m);
}

void Heavy_prog::cBinop_ifcaMAgv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QTlETYk6, 0, m, &cVar_QTlETYk6_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_UERNR3Bd, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_nbZNhxfg, m);
}

void Heavy_prog::cBinop_Um2yiOZF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Qxuf9t9Q, 0, m, &cVar_Qxuf9t9Q_sendMessage);
}

void Heavy_prog::cBinop_7pwOOwo6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7k61r2G5, 0, m, &cVar_7k61r2G5_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_LlDttpyA, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_1dNfVTG8, m);
}

void Heavy_prog::cVar_vChBdXUn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_ZiC9F6a6, 0, m);
}

void Heavy_prog::cSwitchcase_T1BLXGrb_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_nKfweGqM, 0, m, &cSlice_nKfweGqM_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_GrUU7KbI, 0, m, &cRandom_GrUU7KbI_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_EjUVUIZc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_lvyi5cYE_sendMessage);
}

void Heavy_prog::cUnop_lvyi5cYE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_agUOhRjO_sendMessage(_c, 0, m);
}

void Heavy_prog::cRandom_GrUU7KbI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_EjUVUIZc_sendMessage);
}

void Heavy_prog::cSlice_nKfweGqM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_GrUU7KbI, 1, m, &cRandom_GrUU7KbI_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cMsg_agUOhRjO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_aFs7YpR4, m);
}

void Heavy_prog::cSwitchcase_CNdmGvnr_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_WRAon9TM, 0, m, &cSlice_WRAon9TM_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cVar_5ObZ6qKm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_knZggODO_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_B7QGTcJy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_hqkRTEuS_sendMessage);
}

void Heavy_prog::cMsg_knZggODO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_B7QGTcJy_sendMessage);
}

void Heavy_prog::cSlice_WRAon9TM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_xU6fBMgD, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_5ObZ6qKm, 0, m, &cVar_5ObZ6qKm_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_hqkRTEuS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_oHh7sTsp, m);
}

void Heavy_prog::cVar_fPNbaZof_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cVar_PDMsQ4kI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cSwitchcase_S9GLanpv_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_JomLczov, 0, m, &cSlice_JomLczov_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cVar_PU7UbYMo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Qh7mKHaf_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_94dcSr5D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_TyGxCV4x_sendMessage);
}

void Heavy_prog::cMsg_Qh7mKHaf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_94dcSr5D_sendMessage);
}

void Heavy_prog::cSlice_JomLczov_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sTabread_onMessage(_c, &Context(_c)->sTabread_J0KKiP2N, 1, m, NULL);
      cVar_onMessage(_c, &Context(_c)->cVar_PU7UbYMo, 0, m, &cVar_PU7UbYMo_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cBinop_TyGxCV4x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_OAuC1DVW, m);
}

void Heavy_prog::cBinop_trtSHc5p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fPNbaZof, 0, m, &cVar_fPNbaZof_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_joS8eQes, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_f89oAcfe, m);
}

void Heavy_prog::cBinop_h9RwgNmx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 10.0f, 0, m, &cBinop_InyIijju_sendMessage);
}

void Heavy_prog::cBinop_InyIijju_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PDMsQ4kI, 0, m, &cVar_PDMsQ4kI_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_jg8afP2U, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_dEG7qAjo, m);
}

void Heavy_prog::cBinop_GpOxKgCJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 100.0f, 0, m, &cBinop_trtSHc5p_sendMessage);
}

void Heavy_prog::cBinop_LaqvjTc4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vChBdXUn, 0, m, &cVar_vChBdXUn_sendMessage);
}

void Heavy_prog::cSend_cCtg7mG5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_7kFqYHo0_sendMessage(_c, 0, m);
}

void Heavy_prog::cSend_mI9C4m2z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_HKJaAgwj_sendMessage(_c, 0, m);
}

void Heavy_prog::cSend_W2X10DUq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_2cV4DY3m_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_1uCxAqtq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3oxZQgeF_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_9wOy5tNw, 0, m, &cVar_9wOy5tNw_sendMessage);
  cSwitchcase_dusj7UPM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_BoKlLRXK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_17bmFlEr_onMessage(_c, NULL, 0, m, NULL);
  cVar_onMessage(_c, &Context(_c)->cVar_HvHftByA, 0, m, &cVar_HvHftByA_sendMessage);
}

void Heavy_prog::cCast_sYi0UCfG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_d6cqH8V1_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_iu82Ensb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_GzwpqvBM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_VaKdq0lL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_yalr0UsB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lsuVWx6j_sendMessage(_c, 0, m);
  cMsg_x0o8w8hN_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_LEVeJnnW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sKNC905A_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_a623sDwO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cMsg_sKNC905A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  cSwitchcase_GzwpqvBM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_DMMQOLTT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_el74ecSt, 0, m);
}

void Heavy_prog::cCast_ScLxVTVp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ICPsJQnq_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_IaUJf8wm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 48.0f, 0, m, &cBinop_4U1AybHt_sendMessage);
}

void Heavy_prog::cCast_YnIHrSpF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_2AcmE9EC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DMMQOLTT, HV_BINOP_DIVIDE, 1, m, &cBinop_DMMQOLTT_sendMessage);
}

void Heavy_prog::cBinop_4U1AybHt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_QmycUAze, m);
}

void Heavy_prog::cMsg_ICPsJQnq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1000.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_DMMQOLTT, HV_BINOP_DIVIDE, 0, m, &cBinop_DMMQOLTT_sendMessage);
}

void Heavy_prog::cBinop_uNBLMKRr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mnNlLW9x, 0, m, &cVar_mnNlLW9x_sendMessage);
  cSend_W2X10DUq_sendMessage(_c, 0, m);
}

void Heavy_prog::hTable_VDTcO6yZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cReceive_kGuNA4kw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Vi4fKRwz_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_I9CVDef2, 0, m, &cVar_I9CVDef2_sendMessage);
  cMsg_Qxdxy8vo_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_mYsaHcsK, 0, m, &cVar_mYsaHcsK_sendMessage);
  cMsg_PZteXITA_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Pnvsjd3F, 0, m, &cVar_Pnvsjd3F_sendMessage);
  cMsg_W5qFgpPD_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_KCagZz8h, 0, m, &cVar_KCagZz8h_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_mIbAaZpQ, 0, m, &cVar_mIbAaZpQ_sendMessage);
  cMsg_bSaxZ4xJ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_NkC5Mctd, 0, m, &cVar_NkC5Mctd_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_bh183G6m, 0, m, &cVar_bh183G6m_sendMessage);
  cSwitchcase_JpS84zFi_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_T1BLXGrb_onMessage(_c, NULL, 0, m, NULL);
  cMsg_gaXEVxs7_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_mnNlLW9x, 0, m, &cVar_mnNlLW9x_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_P3xKJjrv, 0, m, &cVar_P3xKJjrv_sendMessage);
  cMsg_jE2gHkE6_sendMessage(_c, 0, m);
  cMsg_zlDcFU66_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Ns4rBK2t, 0, m, &cVar_Ns4rBK2t_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_qYKTHJeR, 0, m, &cVar_qYKTHJeR_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_lhfHBjD6, 0, m, &cVar_lhfHBjD6_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_I8CJRgRl, 0, m, &cVar_I8CJRgRl_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_xmvA15ai, 0, m, &cVar_xmvA15ai_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_5ObZ6qKm, 0, m, &cVar_5ObZ6qKm_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_PU7UbYMo, 0, m, &cVar_PU7UbYMo_sendMessage);
}

void Heavy_prog::cReceive_7kFqYHo0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 400.0f, 0, m, &cBinop_KoPnBVtS_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 50.0f, 0, m, &cBinop_Um2yiOZF_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_LaqvjTc4_sendMessage);
}

void Heavy_prog::cReceive_HKJaAgwj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 50.0f, 0, m, &cBinop_ifcaMAgv_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_h9RwgNmx_sendMessage);
}

void Heavy_prog::cReceive_2cV4DY3m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_7pwOOwo6_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 200.0f, 0, m, &cBinop_GpOxKgCJ_sendMessage);
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
    __hv_varread_i(&sVari_ASLf9wfE, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varwrite_i(&sVari_ASLf9wfE, VIi(Bi1));
    __hv_var_k_f(VOf(Bf0), 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f, 0.05f);
    __hv_phasor_k_f(&sPhasor_ekcuMOOc, VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf2));
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf6), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf4), VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf2), VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf1), VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_phasor_k_f(&sPhasor_Fcn5HsvH, VOf(Bf0));
    __hv_del1_f(&sDel1_mA6aXWoV, VIf(Bf0), VOf(Bf1));
    __hv_lt_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_samphold_f(&sSamphold_aPoO4z6t, VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_UERNR3Bd, VOf(Bf5));
    __hv_varread_f(&sVarf_LlDttpyA, VOf(Bf2));
    __hv_fma_f(VIf(Bf1), VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_phasor_f(&sPhasor_3VJgdfFJ, VIf(Bf2), VOf(Bf2));
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
    __hv_var_k_f(VOf(Bf6), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf4), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf1), VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf2), VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf6), 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f);
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_YBUaIaud, VOf(Bf2));
    __hv_min_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_zero_f(VOf(Bf6));
    __hv_max_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_cast_fi(VIf(Bf6), VOi(Bi1));
    __hv_tabread_if(&sTabread_4ganFZ9P, VIi(Bi1), VOf(Bf6));
    __hv_var_k_f(VOf(Bf2), 10.0f, 10.0f, 10.0f, 10.0f, 10.0f, 10.0f, 10.0f, 10.0f);
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_add_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf0));
    __hv_sub_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_del1_f(&sDel1_NrzHFwEI, VIf(Bf0), VOf(Bf3));
    __hv_lt_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_samphold_f(&sSamphold_LzcVZGIG, VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_nbZNhxfg, VOf(Bf2));
    __hv_varread_f(&sVarf_1dNfVTG8, VOf(Bf4));
    __hv_fma_f(VIf(Bf3), VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_phasor_f(&sPhasor_lIYhBKKm, VIf(Bf4), VOf(Bf4));
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
    __hv_var_k_f(VOf(Bf1), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf7), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf3), VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf4), VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f);
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_H6zCkV6n, VOf(Bf0));
    __hv_min_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_zero_f(VOf(Bf1));
    __hv_max_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_cast_fi(VIf(Bf1), VOi(Bi1));
    __hv_tabread_if(&sTabread_eAOgzWJj, VIi(Bi1), VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf5), VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf1), 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f);
    __hv_mul_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_tabwrite_stoppable_f(&sTabwrite_kuVgAfyY, VIf(Bf1));
    __hv_phasor_k_f(&sPhasor_el74ecSt, VOf(Bf1));
    __hv_varread_f(&sVarf_QmycUAze, VOf(Bf5));
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_6WAWlZfh, VOf(Bf1));
    __hv_min_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_zero_f(VOf(Bf5));
    __hv_max_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf5), VOf(Bf1));
    __hv_cast_fi(VIf(Bf1), VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_tabread_if(&sTabread_evddYNmf, VIi(Bi0), VOf(Bf2));
    __hv_tabread_if(&sTabread_JGZasFtq, VIi(Bi1), VOf(Bf0));
    __hv_sub_f(VIf(Bf2), VIf(Bf0), VOf(Bf2));
    __hv_sub_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf2), VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf0), VIf(Bf6), VOf(Bf1));
    __hv_phasor_k_f(&sPhasor_H9DQoIc7, VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_abs_f(VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf2));
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf7), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf3), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf4), VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf2), VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf7), 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f);
    __hv_mul_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_4BVdOPRF, VOf(Bf1));
    __hv_min_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_zero_f(VOf(Bf7));
    __hv_max_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_cast_fi(VIf(Bf7), VOi(Bi1));
    __hv_tabread_if(&sTabread_HATnYVOr, VIi(Bi1), VOf(Bf7));
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf5), 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f, 0.3f);
    __hv_mul_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_WYS3AGIN, VOf(Bf7));
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_kTBVqscG, VOf(Bf5));
    __hv_rpole_f(&sRPole_nVmtF4aO, VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf0), VIf(Bf6), VOf(Bf0));
    __hv_varread_i(&sVari_aFs7YpR4, VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_cast_if(VIi(Bi0), VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_varwrite_i(&sVari_aFs7YpR4, VIi(Bi0));
    __hv_var_k_f(VOf(Bf7), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_phasor_k_f(&sPhasor_YYhyGSaC, VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf2));
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf8), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf9), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf4), VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf2), VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf1), VIf(Bf7), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_phasor_k_f(&sPhasor_ZiC9F6a6, VOf(Bf7));
    __hv_del1_f(&sDel1_bOtVv0G8, VIf(Bf7), VOf(Bf1));
    __hv_lt_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_samphold_f(&sSamphold_wFaeDLkP, VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_jg8afP2U, VOf(Bf8));
    __hv_varread_f(&sVarf_joS8eQes, VOf(Bf2));
    __hv_fma_f(VIf(Bf1), VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_phasor_f(&sPhasor_cKBSuNHy, VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf8), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_abs_f(VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf8), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf8), VOf(Bf2));
    __hv_mul_f(VIf(Bf8), VIf(Bf2), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf9), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf4), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf1), VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf2), VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf9), 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f);
    __hv_mul_f(VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_OAuC1DVW, VOf(Bf2));
    __hv_min_f(VIf(Bf9), VIf(Bf2), VOf(Bf2));
    __hv_zero_f(VOf(Bf9));
    __hv_max_f(VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_cast_fi(VIf(Bf9), VOi(Bi0));
    __hv_tabread_if(&sTabread_J0KKiP2N, VIi(Bi0), VOf(Bf9));
    __hv_var_k_f(VOf(Bf2), 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f);
    __hv_add_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_floor_f(VIf(Bf2), VOf(Bf7));
    __hv_sub_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_del1_f(&sDel1_6WZyQQ0o, VIf(Bf7), VOf(Bf2));
    __hv_lt_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_samphold_f(&sSamphold_IEMqnpN9, VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_dEG7qAjo, VOf(Bf3));
    __hv_varread_f(&sVarf_f89oAcfe, VOf(Bf4));
    __hv_fma_f(VIf(Bf2), VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_phasor_f(&sPhasor_HFvtNFf5, VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf3), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf4));
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf10), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf2), VIf(Bf10), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf4), VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf1), 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f, 256.0f);
    __hv_mul_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_oHh7sTsp, VOf(Bf7));
    __hv_min_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_zero_f(VOf(Bf1));
    __hv_max_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_cast_fi(VIf(Bf1), VOi(Bi0));
    __hv_tabread_if(&sTabread_xU6fBMgD, VIi(Bi0), VOf(Bf1));
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf8), VIf(Bf9), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf9), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf1), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf0), VIf(Bf9), VOf(Bf0));
    __hv_phasor_k_f(&sPhasor_oEUtY9cW, VOf(Bf1));
    __hv_var_k_f(VOf(Bf8), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf8), VOf(Bf8));
    __hv_abs_f(VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf8), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf8), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf1), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf8), VOf(Bf1));
    __hv_mul_f(VIf(Bf8), VIf(Bf1), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf7), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf4), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf3), VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf1), VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_pih6oyOa, VOf(Bf0));
    __hv_mul_f(VIf(Bf8), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf5), VIf(Bf0), VOf(Bf8));
    __hv_add_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf8), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_mul_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf8), VIf(O0), VOf(O0));
    __hv_add_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf0), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf0), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_mul_f(VIf(Bf9), VIf(Bf0), VOf(Bf0));
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
