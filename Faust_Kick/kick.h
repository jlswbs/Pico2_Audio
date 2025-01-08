/* ------------------------------------------------------------
name: "kick"
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

typedef struct {
	int iVec0[2];
	int iRec0[2];
} mydspSIG0;

static mydspSIG0* newmydspSIG0() { return (mydspSIG0*)calloc(1, sizeof(mydspSIG0)); }
static void deletemydspSIG0(mydspSIG0* dsp) { free(dsp); }

int getNumInputsmydspSIG0(mydspSIG0* RESTRICT dsp) {
	return 0;
}
int getNumOutputsmydspSIG0(mydspSIG0* RESTRICT dsp) {
	return 1;
}

static void instanceInitmydspSIG0(mydspSIG0* dsp, int sample_rate) {
	/* C99 loop */
	{
		int l0;
		for (l0 = 0; l0 < 2; l0 = l0 + 1) {
			dsp->iVec0[l0] = 0;
		}
	}
	/* C99 loop */
	{
		int l1;
		for (l1 = 0; l1 < 2; l1 = l1 + 1) {
			dsp->iRec0[l1] = 0;
		}
	}
}

static void fillmydspSIG0(mydspSIG0* dsp, int count, float* table) {
	/* C99 loop */
	{
		int i1;
		for (i1 = 0; i1 < count; i1 = i1 + 1) {
			dsp->iVec0[0] = 1;
			dsp->iRec0[0] = (dsp->iVec0[1] + dsp->iRec0[1]) % 65536;
			table[i1] = sinf(9.58738e-05f * (float)(dsp->iRec0[0]));
			dsp->iVec0[1] = dsp->iVec0[0];
			dsp->iRec0[1] = dsp->iRec0[0];
		}
	}
}

static float ftbl0mydspSIG0[65536];

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

typedef struct {
	int iVec1[2];
	FAUSTFLOAT fButton0;
	int iVec2[2];
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	int fSampleRate;
	float fConst0;
	int iRec3[2];
	float fConst1;
	float fRec2[2];
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	float fConst2;
	float fRec1[2];
	FAUSTFLOAT fHslider4;
	FAUSTFLOAT fHslider5;
	float fRec4[2];
	FAUSTFLOAT fHslider6;
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
	mydspSIG0* sig0 = newmydspSIG0();
	instanceInitmydspSIG0(sig0, sample_rate);
	fillmydspSIG0(sig0, 65536, ftbl0mydspSIG0);
	deletemydspSIG0(sig0);
}

void instanceResetUserInterfacemydsp(mydsp* dsp) {
	dsp->fButton0 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider0 = (FAUSTFLOAT)(0.1f);
	dsp->fHslider1 = (FAUSTFLOAT)(0.001f);
	dsp->fHslider2 = (FAUSTFLOAT)(12.0f);
	dsp->fHslider3 = (FAUSTFLOAT)(55.0f);
	dsp->fHslider4 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider5 = (FAUSTFLOAT)(0.001f);
	dsp->fHslider6 = (FAUSTFLOAT)(0.5f);
}

void instanceClearmydsp(mydsp* dsp) {
	/* C99 loop */
	{
		int l2;
		for (l2 = 0; l2 < 2; l2 = l2 + 1) {
			dsp->iVec1[l2] = 0;
		}
	}
	/* C99 loop */
	{
		int l3;
		for (l3 = 0; l3 < 2; l3 = l3 + 1) {
			dsp->iVec2[l3] = 0;
		}
	}
	/* C99 loop */
	{
		int l4;
		for (l4 = 0; l4 < 2; l4 = l4 + 1) {
			dsp->iRec3[l4] = 0;
		}
	}
	/* C99 loop */
	{
		int l5;
		for (l5 = 0; l5 < 2; l5 = l5 + 1) {
			dsp->fRec2[l5] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l6;
		for (l6 = 0; l6 < 2; l6 = l6 + 1) {
			dsp->fRec1[l6] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l7;
		for (l7 = 0; l7 < 2; l7 = l7 + 1) {
			dsp->fRec4[l7] = 0.0f;
		}
	}
}

void instanceConstantsmydsp(mydsp* dsp, int sample_rate) {
	dsp->fSampleRate = sample_rate;
	dsp->fConst0 = fminf(1.92e+05f, fmaxf(1.0f, (float)(dsp->fSampleRate)));
	dsp->fConst1 = 1.0f / dsp->fConst0;
	dsp->fConst2 = 4.4e+02f / dsp->fConst0;
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
	int iSlow0 = (float)(dsp->fButton0) > 0.0f;
	float fSlow1 = (float)(dsp->fHslider0);
	float fSlow2 = (float)(dsp->fHslider1);
	int iSlow3 = (int)(dsp->fConst0 * fSlow2);
	float fSlow4 = (float)(iSlow0);
	float fSlow5 = (float)(dsp->fHslider2);
	float fSlow6 = 17.31234f * logf(0.0022727272f * (float)(dsp->fHslider3));
	float fSlow7 = (float)(dsp->fHslider4);
	float fSlow8 = (float)(dsp->fHslider5);
	int iSlow9 = (int)(dsp->fConst0 * fSlow8);
	float fSlow10 = (float)(dsp->fHslider6);
	/* C99 loop */
	{
		int i0;
		for (i0 = 0; i0 < count; i0 = i0 + 1) {
			dsp->iVec1[0] = 1;
			dsp->iVec2[0] = iSlow0;
			int iTemp0 = iSlow0 - dsp->iVec2[1];
			int iTemp1 = iTemp0 * (iTemp0 > 0);
			dsp->iRec3[0] = iSlow0 * (dsp->iRec3[1] + 1);
			int iTemp2 = (dsp->iRec3[0] < iSlow3) | iTemp1;
			float fTemp3 = 0.1447178f * ((iSlow0) ? ((iTemp2) ? fSlow2 : fSlow1) : fSlow1);
			int iTemp4 = fabsf(fTemp3) < 1.1920929e-07f;
			float fTemp5 = ((iTemp4) ? 0.0f : expf(-(dsp->fConst1 / ((iTemp4) ? 1.0f : fTemp3))));
			dsp->fRec2[0] = (1.0f - fTemp5) * ((iSlow0) ? ((iTemp2) ? fSlow4 : 0.0f) : 0.0f) + fTemp5 * dsp->fRec2[1];
			float fTemp6 = ((1 - dsp->iVec1[1]) ? 0.0f : dsp->fRec1[1] + dsp->fConst2 * powf(2.0f, 0.083333336f * (fSlow6 + fSlow5 * dsp->fRec2[0])));
			dsp->fRec1[0] = fTemp6 - floorf(fTemp6);
			int iTemp7 = (dsp->iRec3[0] < iSlow9) | iTemp1;
			float fTemp8 = 0.1447178f * ((iSlow0) ? ((iTemp7) ? fSlow8 : fSlow7) : fSlow7);
			int iTemp9 = fabsf(fTemp8) < 1.1920929e-07f;
			float fTemp10 = ((iTemp9) ? 0.0f : expf(-(dsp->fConst1 / ((iTemp9) ? 1.0f : fTemp8))));
			dsp->fRec4[0] = (1.0f - fTemp10) * ((iSlow0) ? ((iTemp7) ? fSlow4 : 0.0f) : 0.0f) + fTemp10 * dsp->fRec4[1];
			float fTemp11 = fSlow10 * dsp->fRec4[0] * ftbl0mydspSIG0[max(0, min((int)(65536.0f * dsp->fRec1[0]), 65535))];
			output0[i0] = (FAUSTFLOAT)(fTemp11);
			output1[i0] = (FAUSTFLOAT)(fTemp11);
			dsp->iVec1[1] = dsp->iVec1[0];
			dsp->iVec2[1] = dsp->iVec2[0];
			dsp->iRec3[1] = dsp->iRec3[0];
			dsp->fRec2[1] = dsp->fRec2[0];
			dsp->fRec1[1] = dsp->fRec1[0];
			dsp->fRec4[1] = dsp->fRec4[0];
		}
	}
}

#ifdef __cplusplus
}
#endif

#endif
