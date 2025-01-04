/* ------------------------------------------------------------
name: "karplus"
Code generated with Faust 2.78.0 (https://faust.grame.fr)
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
	int IOTA0;
	float fRec7[1024];
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider1;
	float fConst2;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	FAUSTFLOAT fHslider2;
	float fVec1[1024];
	float fRec3[2];
	float fRec0[3];
	float fRec1[3];
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
	dsp->fHslider0 = (FAUSTFLOAT)(0.01f);
	dsp->fHslider1 = (FAUSTFLOAT)(1.0f);
	dsp->fButton0 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider2 = (FAUSTFLOAT)(0.5f);
}

void instanceClearmydsp(mydsp* dsp) {
	dsp->IOTA0 = 0;
	/* C99 loop */
	{
		int l0;
		for (l0 = 0; l0 < 1024; l0 = l0 + 1) {
			dsp->fRec7[l0] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l1;
		for (l1 = 0; l1 < 2; l1 = l1 + 1) {
			dsp->fVec0[l1] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l2;
		for (l2 = 0; l2 < 1024; l2 = l2 + 1) {
			dsp->fVec1[l2] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l3;
		for (l3 = 0; l3 < 2; l3 = l3 + 1) {
			dsp->fRec3[l3] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l4;
		for (l4 = 0; l4 < 3; l4 = l4 + 1) {
			dsp->fRec0[l4] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l5;
		for (l5 = 0; l5 < 3; l5 = l5 + 1) {
			dsp->fRec1[l5] = 0.0f;
		}
	}
}

void instanceConstantsmydsp(mydsp* dsp, int sample_rate) {
	dsp->fSampleRate = sample_rate;
	dsp->fConst0 = fminf(1.92e+05f, fmaxf(1.0f, (float)(dsp->fSampleRate)));
	dsp->fConst1 = 0.00882353f * dsp->fConst0;
	dsp->fConst2 = 0.0014705883f * dsp->fConst0;
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
	float fSlow0 = 0.5f * (0.2f * (1.0f - (float)(dsp->fHslider0)) + 0.8f);
	float fSlow1 = dsp->fConst2 * ((float)(dsp->fHslider1) + -0.05f);
	float fSlow2 = fSlow1 + -1.499995f;
	int iSlow3 = (int)(fSlow2);
	int iSlow4 = (int)(fminf(dsp->fConst1, (float)(max(0, iSlow3 + 4)))) + 1;
	float fSlow5 = floorf(fSlow2);
	float fSlow6 = fSlow1 + (-3.0f - fSlow5);
	float fSlow7 = fSlow1 + (-2.0f - fSlow5);
	float fSlow8 = fSlow1 + (-1.0f - fSlow5);
	float fSlow9 = fSlow1 - fSlow5;
	float fSlow10 = fSlow9 * fSlow8;
	float fSlow11 = fSlow10 * fSlow7;
	float fSlow12 = 0.041666668f * fSlow11 * fSlow6;
	int iSlow13 = (int)(fminf(dsp->fConst1, (float)(max(0, iSlow3 + 3)))) + 1;
	float fSlow14 = 0.16666667f * fSlow11;
	int iSlow15 = (int)(fminf(dsp->fConst1, (float)(max(0, iSlow3 + 2)))) + 1;
	float fSlow16 = 0.25f * fSlow10;
	int iSlow17 = (int)(fminf(dsp->fConst1, (float)(max(0, iSlow3 + 1)))) + 1;
	float fSlow18 = 0.16666667f * fSlow9;
	int iSlow19 = (int)(fminf(dsp->fConst1, (float)(max(0, iSlow3)))) + 1;
	float fSlow20 = 0.041666668f * fSlow8;
	float fSlow21 = fSlow1 + (-4.0f - fSlow5);
	float fSlow22 = (float)(dsp->fButton0);
	float fSlow23 = (float)(dsp->fHslider2);
	/* C99 loop */
	{
		int i0;
		for (i0 = 0; i0 < count; i0 = i0 + 1) {
			float fTemp0 = fSlow0 * (dsp->fRec1[1] + dsp->fRec1[2]);
			dsp->fRec7[dsp->IOTA0 & 1023] = fTemp0;
			float fRec8 = fSlow21 * (fSlow6 * (fSlow7 * (fSlow20 * dsp->fRec7[(dsp->IOTA0 - iSlow19) & 1023] - fSlow18 * dsp->fRec7[(dsp->IOTA0 - iSlow17) & 1023]) + fSlow16 * dsp->fRec7[(dsp->IOTA0 - iSlow15) & 1023]) - fSlow14 * dsp->fRec7[(dsp->IOTA0 - iSlow13) & 1023]) + fSlow12 * dsp->fRec7[(dsp->IOTA0 - iSlow4) & 1023];
			dsp->fVec0[0] = fSlow22;
			float fTemp1 = fSlow22 - dsp->fVec0[1];
			float fTemp2 = fSlow23 * fTemp1 * (float)(fTemp1 > 0.0f);
			float fTemp3 = dsp->fRec0[2] + fTemp2;
			dsp->fVec1[dsp->IOTA0 & 1023] = fTemp3;
			float fTemp4 = fSlow12 * dsp->fVec1[(dsp->IOTA0 - iSlow4) & 1023];
			float fTemp5 = fSlow21 * (fSlow6 * (fSlow7 * (fSlow20 * dsp->fVec1[(dsp->IOTA0 - iSlow19) & 1023] - fSlow18 * dsp->fVec1[(dsp->IOTA0 - iSlow17) & 1023]) + fSlow16 * dsp->fVec1[(dsp->IOTA0 - iSlow15) & 1023]) - fSlow14 * dsp->fVec1[(dsp->IOTA0 - iSlow13) & 1023]);
			float fRec9 = fTemp5 + fTemp4;
			float fRec10 = fTemp4 + fTemp0 + fTemp5;
			dsp->fRec3[0] = fRec8;
			float fRec4 = fTemp2 + dsp->fRec3[1];
			float fRec5 = fRec9;
			float fRec6 = fRec10;
			dsp->fRec0[0] = fRec4;
			dsp->fRec1[0] = fRec5;
			float fRec2 = fRec6;
			output0[i0] = (FAUSTFLOAT)(fRec2);
			output1[i0] = (FAUSTFLOAT)(fRec2);
			dsp->IOTA0 = dsp->IOTA0 + 1;
			dsp->fVec0[1] = dsp->fVec0[0];
			dsp->fRec3[1] = dsp->fRec3[0];
			dsp->fRec0[2] = dsp->fRec0[1];
			dsp->fRec0[1] = dsp->fRec0[0];
			dsp->fRec1[2] = dsp->fRec1[1];
			dsp->fRec1[1] = dsp->fRec1[0];
		}
	}
}

#ifdef __cplusplus
}
#endif

#endif
