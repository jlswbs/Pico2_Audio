/* ------------------------------------------------------------
name: "waveguide"
Code generated with Faust 2.78.1 (https://faust.grame.fr)
Compilation options: -lang c -ct 1 -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __mydsp_H__
#define  __mydsp_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 


#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif

#include <math.h>
#include <stdint.h>
#include <stdlib.h>


#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

typedef struct {
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fRec21[2];
	float fRec22[2];
	FAUSTFLOAT fHslider1;
	int IOTA0;
	float fRec23[4096];
	float fConst2;
	float fConst3;
	float fConst4;
	FAUSTFLOAT fHslider2;
	float fRec24[2];
	float fConst5;
	float fVec0[2];
	FAUSTFLOAT fButton0;
	float fVec1[4096];
	float fConst6;
	float fRec19[2];
	float fRec14[4096];
	float fRec10[2];
	float fRec6[2];
	float fRec2[4096];
	float fRec0[2];
} mydsp;

mydsp* newmydsp() { 
	mydsp* dsp = (mydsp*)calloc(1, sizeof(mydsp));
	return dsp;
}

void deletemydsp(mydsp* dsp) { 
	free(dsp);
}

int getSampleRatemydsp(mydsp* RESTRICT dsp) {
	return dsp->fSampleRate;
}

int getNumInputsmydsp(mydsp* RESTRICT dsp) {
	return 0;
}
int getNumOutputsmydsp(mydsp* RESTRICT dsp) {
	return 2;
}

void classInitmydsp(int sample_rate) {
}

void instanceResetUserInterfacemydsp(mydsp* dsp) {
	dsp->fHslider0 = (FAUSTFLOAT)(1e+03f);
	dsp->fHslider1 = (FAUSTFLOAT)(0.99f);
	dsp->fHslider2 = (FAUSTFLOAT)(1.0f);
	dsp->fButton0 = (FAUSTFLOAT)(0.0f);
}

void instanceClearmydsp(mydsp* dsp) {
	/* C99 loop */
	{
		int l0;
		for (l0 = 0; l0 < 2; l0 = l0 + 1) {
			dsp->fRec21[l0] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l1;
		for (l1 = 0; l1 < 2; l1 = l1 + 1) {
			dsp->fRec22[l1] = 0.0f;
		}
	}
	dsp->IOTA0 = 0;
	/* C99 loop */
	{
		int l2;
		for (l2 = 0; l2 < 4096; l2 = l2 + 1) {
			dsp->fRec23[l2] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l3;
		for (l3 = 0; l3 < 2; l3 = l3 + 1) {
			dsp->fRec24[l3] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l4;
		for (l4 = 0; l4 < 2; l4 = l4 + 1) {
			dsp->fVec0[l4] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l5;
		for (l5 = 0; l5 < 4096; l5 = l5 + 1) {
			dsp->fVec1[l5] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l6;
		for (l6 = 0; l6 < 2; l6 = l6 + 1) {
			dsp->fRec19[l6] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l7;
		for (l7 = 0; l7 < 4096; l7 = l7 + 1) {
			dsp->fRec14[l7] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l8;
		for (l8 = 0; l8 < 2; l8 = l8 + 1) {
			dsp->fRec10[l8] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l9;
		for (l9 = 0; l9 < 2; l9 = l9 + 1) {
			dsp->fRec6[l9] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l10;
		for (l10 = 0; l10 < 4096; l10 = l10 + 1) {
			dsp->fRec2[l10] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l11;
		for (l11 = 0; l11 < 2; l11 = l11 + 1) {
			dsp->fRec0[l11] = 0.0f;
		}
	}
}

void instanceConstantsmydsp(mydsp* dsp, int sample_rate) {
	dsp->fSampleRate = sample_rate;
	dsp->fConst0 = fminf(1.92e+05f, fmaxf(1.0f, (float)(dsp->fSampleRate)));
	dsp->fConst1 = 2.0f / dsp->fConst0;
	dsp->fConst2 = 0.01764706f * dsp->fConst0;
	dsp->fConst3 = 48.0f / dsp->fConst0;
	dsp->fConst4 = 1.0f - dsp->fConst3;
	dsp->fConst5 = 0.00022058823f * dsp->fConst0;
	dsp->fConst6 = 0.00125f * dsp->fConst0;
}
	
void instanceInitmydsp(mydsp* dsp, int sample_rate) {
	instanceConstantsmydsp(dsp, sample_rate);
	instanceResetUserInterfacemydsp(dsp);
	instanceClearmydsp(dsp);
}

void initmydsp(mydsp* dsp, int sample_rate) {
	classInitmydsp(sample_rate);
	instanceInitmydsp(dsp, sample_rate);
}

void computemydsp(mydsp* dsp, int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
	FAUSTFLOAT* output0 = outputs[0];
	FAUSTFLOAT* output1 = outputs[1];
	float fSlow0 = dsp->fConst1 * (float)(dsp->fHslider0);
	float fSlow1 = 1.0f - fSlow0;
	float fSlow2 = (float)(dsp->fHslider1);
	float fSlow3 = dsp->fConst3 * (float)(dsp->fHslider2);
	float fSlow4 = (float)(dsp->fButton0);
	/* C99 loop */
	{
		int i0;
		for (i0 = 0; i0 < count; i0 = i0 + 1) {
			dsp->fRec21[0] = fSlow1 * dsp->fRec21[1] - fSlow0 * dsp->fRec19[1];
			float fRec18 = dsp->fRec21[0];
			dsp->fRec22[0] = dsp->fRec0[1];
			dsp->fRec23[dsp->IOTA0 & 4095] = -(fSlow2 * dsp->fRec22[1]);
			dsp->fRec24[0] = fSlow3 + dsp->fConst4 * dsp->fRec24[1];
			float fTemp0 = dsp->fConst5 * dsp->fRec24[0];
			float fTemp1 = fTemp0 + -1.499995f;
			int iTemp2 = (int)(fTemp1);
			int iTemp3 = (int)(fminf(dsp->fConst2, (float)(max(0, iTemp2 + 4)))) + 1;
			float fTemp4 = floorf(fTemp1);
			float fTemp5 = fTemp0 + (-3.0f - fTemp4);
			float fTemp6 = fTemp0 + (-2.0f - fTemp4);
			float fTemp7 = fTemp0 + (-1.0f - fTemp4);
			float fTemp8 = fTemp0 - fTemp4;
			float fTemp9 = fTemp8 * fTemp7;
			float fTemp10 = fTemp9 * fTemp6;
			float fTemp11 = fTemp10 * fTemp5;
			int iTemp12 = (int)(fminf(dsp->fConst2, (float)(max(0, iTemp2 + 3)))) + 1;
			int iTemp13 = (int)(fminf(dsp->fConst2, (float)(max(0, iTemp2 + 2)))) + 1;
			int iTemp14 = (int)(fminf(dsp->fConst2, (float)(max(0, iTemp2 + 1)))) + 1;
			int iTemp15 = (int)(fminf(dsp->fConst2, (float)(max(0, iTemp2)))) + 1;
			float fTemp16 = fTemp0 + (-4.0f - fTemp4);
			dsp->fVec0[0] = fTemp16 * (fTemp5 * (fTemp6 * (0.041666668f * dsp->fRec23[(dsp->IOTA0 - iTemp15) & 4095] * fTemp7 - 0.16666667f * fTemp8 * dsp->fRec23[(dsp->IOTA0 - iTemp14) & 4095]) + 0.25f * fTemp9 * dsp->fRec23[(dsp->IOTA0 - iTemp13) & 4095]) - 0.16666667f * fTemp10 * dsp->fRec23[(dsp->IOTA0 - iTemp12) & 4095]) + 0.041666668f * fTemp11 * dsp->fRec23[(dsp->IOTA0 - iTemp3) & 4095];
			float fTemp17 = fSlow4 + dsp->fVec0[1];
			dsp->fVec1[dsp->IOTA0 & 4095] = fTemp17;
			float fTemp18 = dsp->fConst6 * dsp->fRec24[0];
			float fTemp19 = fTemp18 + -1.499995f;
			int iTemp20 = (int)(fTemp19);
			int iTemp21 = (int)(fminf(dsp->fConst2, (float)(max(0, iTemp20 + 4))));
			float fTemp22 = floorf(fTemp19);
			float fTemp23 = fTemp18 + (-3.0f - fTemp22);
			float fTemp24 = fTemp18 + (-2.0f - fTemp22);
			float fTemp25 = fTemp18 + (-1.0f - fTemp22);
			float fTemp26 = fTemp18 - fTemp22;
			float fTemp27 = fTemp26 * fTemp25;
			float fTemp28 = fTemp27 * fTemp24;
			float fTemp29 = fTemp28 * fTemp23;
			int iTemp30 = (int)(fminf(dsp->fConst2, (float)(max(0, iTemp20 + 3))));
			int iTemp31 = (int)(fminf(dsp->fConst2, (float)(max(0, iTemp20 + 2))));
			int iTemp32 = (int)(fminf(dsp->fConst2, (float)(max(0, iTemp20 + 1))));
			int iTemp33 = (int)(fminf(dsp->fConst2, (float)(max(0, iTemp20))));
			float fTemp34 = fTemp18 + (-4.0f - fTemp22);
			dsp->fRec19[0] = fTemp34 * (fTemp23 * (fTemp24 * (0.041666668f * dsp->fVec1[(dsp->IOTA0 - (iTemp33 + 2)) & 4095] * fTemp25 - 0.16666667f * fTemp26 * dsp->fVec1[(dsp->IOTA0 - (iTemp32 + 2)) & 4095]) + 0.25f * fTemp27 * dsp->fVec1[(dsp->IOTA0 - (iTemp31 + 2)) & 4095]) - 0.16666667f * fTemp28 * dsp->fVec1[(dsp->IOTA0 - (iTemp30 + 2)) & 4095]) + 0.041666668f * fTemp29 * dsp->fVec1[(dsp->IOTA0 - (iTemp21 + 2)) & 4095];
			float fRec20 = dsp->fVec1[(dsp->IOTA0 - 1) & 4095] + dsp->fRec10[1];
			dsp->fRec14[dsp->IOTA0 & 4095] = fRec18;
			float fRec15 = fTemp34 * (fTemp23 * (fTemp24 * (0.041666668f * fTemp25 * dsp->fRec14[(dsp->IOTA0 - (iTemp33 + 1)) & 4095] - 0.16666667f * fTemp26 * dsp->fRec14[(dsp->IOTA0 - (iTemp32 + 1)) & 4095]) + 0.25f * fTemp27 * dsp->fRec14[(dsp->IOTA0 - (iTemp31 + 1)) & 4095]) - 0.16666667f * fTemp28 * dsp->fRec14[(dsp->IOTA0 - (iTemp30 + 1)) & 4095]) + 0.041666668f * fTemp29 * dsp->fRec14[(dsp->IOTA0 - (iTemp21 + 1)) & 4095];
			float fRec16 = dsp->fRec19[0];
			float fRec17 = fRec20;
			dsp->fRec10[0] = fRec15;
			float fRec11 = dsp->fRec10[1];
			float fRec12 = fRec16;
			float fRec13 = fRec17;
			dsp->fRec6[0] = fRec11;
			float fRec7 = fSlow4 + dsp->fRec6[1];
			float fRec8 = fRec12;
			float fRec9 = fRec13;
			dsp->fRec2[dsp->IOTA0 & 4095] = fRec7;
			float fRec3 = fTemp16 * (fTemp5 * (fTemp6 * (0.041666668f * fTemp7 * dsp->fRec2[(dsp->IOTA0 - iTemp15) & 4095] - 0.16666667f * fTemp8 * dsp->fRec2[(dsp->IOTA0 - iTemp14) & 4095]) + 0.25f * fTemp9 * dsp->fRec2[(dsp->IOTA0 - iTemp13) & 4095]) - 0.16666667f * fTemp10 * dsp->fRec2[(dsp->IOTA0 - iTemp12) & 4095]) + 0.041666668f * fTemp11 * dsp->fRec2[(dsp->IOTA0 - iTemp3) & 4095];
			float fRec4 = fRec8;
			float fRec5 = fRec9;
			dsp->fRec0[0] = fRec3;
			float fRec1 = fRec5;
			output0[i0] = (FAUSTFLOAT)(fRec1);
			output1[i0] = (FAUSTFLOAT)(fRec1);
			dsp->fRec21[1] = dsp->fRec21[0];
			dsp->fRec22[1] = dsp->fRec22[0];
			dsp->IOTA0 = dsp->IOTA0 + 1;
			dsp->fRec24[1] = dsp->fRec24[0];
			dsp->fVec0[1] = dsp->fVec0[0];
			dsp->fRec19[1] = dsp->fRec19[0];
			dsp->fRec10[1] = dsp->fRec10[0];
			dsp->fRec6[1] = dsp->fRec6[0];
			dsp->fRec0[1] = dsp->fRec0[0];
		}
	}
}

#ifdef __cplusplus
}
#endif

#endif
