/* ------------------------------------------------------------
name: "marimba"
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
	int iVec1[2];
	int iRec3[2];
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
		int l3;
		for (l3 = 0; l3 < 2; l3 = l3 + 1) {
			dsp->iVec1[l3] = 0;
		}
	}
	/* C99 loop */
	{
		int l4;
		for (l4 = 0; l4 < 2; l4 = l4 + 1) {
			dsp->iRec3[l4] = 0;
		}
	}
}

static void fillmydspSIG0(mydspSIG0* dsp, int count, float* table) {
	/* C99 loop */
	{
		int i1;
		for (i1 = 0; i1 < count; i1 = i1 + 1) {
			dsp->iVec1[0] = 1;
			dsp->iRec3[0] = (dsp->iVec1[1] + dsp->iRec3[1]) % 32768;
			table[i1] = cosf(9.58738e-05f * (float)(dsp->iRec3[0]));
			dsp->iVec1[1] = dsp->iVec1[0];
			dsp->iRec3[1] = dsp->iRec3[0];
		}
	}
}

typedef struct {
	int iVec3[2];
	int iRec7[2];
} mydspSIG1;

static mydspSIG1* newmydspSIG1() { return (mydspSIG1*)calloc(1, sizeof(mydspSIG1)); }
static void deletemydspSIG1(mydspSIG1* dsp) { free(dsp); }

int getNumInputsmydspSIG1(mydspSIG1* RESTRICT dsp) {
	return 0;
}
int getNumOutputsmydspSIG1(mydspSIG1* RESTRICT dsp) {
	return 1;
}

static void instanceInitmydspSIG1(mydspSIG1* dsp, int sample_rate) {
	/* C99 loop */
	{
		int l9;
		for (l9 = 0; l9 < 2; l9 = l9 + 1) {
			dsp->iVec3[l9] = 0;
		}
	}
	/* C99 loop */
	{
		int l10;
		for (l10 = 0; l10 < 2; l10 = l10 + 1) {
			dsp->iRec7[l10] = 0;
		}
	}
}

static void fillmydspSIG1(mydspSIG1* dsp, int count, float* table) {
	/* C99 loop */
	{
		int i2;
		for (i2 = 0; i2 < count; i2 = i2 + 1) {
			dsp->iVec3[0] = 1;
			dsp->iRec7[0] = (dsp->iVec3[1] + dsp->iRec7[1]) % 32768;
			table[i2] = sinf(9.58738e-05f * (float)(dsp->iRec7[0]));
			dsp->iVec3[1] = dsp->iVec3[0];
			dsp->iRec7[1] = dsp->iRec7[0];
		}
	}
}

static float mydsp_faustpower2_f(float value) {
	return value * value;
}
static float ftbl0mydspSIG0[32768];
static float ftbl1mydspSIG1[32768];

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

typedef struct {
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	int iVec0[2];
	FAUSTFLOAT fHslider0;
	float fConst3;
	float fConst4;
	int iRec2[2];
	float fRec1[4];
	FAUSTFLOAT fButton0;
	int iVec2[2];
	int iConst5;
	int iRec6[2];
	float fConst6;
	float fRec5[2];
	float fRec4[2];
	float fRec8[2];
	FAUSTFLOAT fHslider1;
	float fRec0[3];
	float fConst7;
	float fConst8;
	float fConst9;
	float fConst10;
	float fRec9[3];
	float fConst11;
	float fConst12;
	float fConst13;
	float fRec10[3];
	float fConst14;
	float fConst15;
	float fConst16;
	float fRec11[3];
	float fConst17;
	float fConst18;
	float fConst19;
	float fRec12[3];
	float fConst20;
	float fConst21;
	float fConst22;
	float fRec13[3];
	float fConst23;
	float fConst24;
	float fConst25;
	float fRec14[3];
	float fConst26;
	float fConst27;
	float fConst28;
	float fRec15[3];
	float fConst29;
	float fConst30;
	float fConst31;
	float fRec16[3];
	float fConst32;
	float fConst33;
	float fConst34;
	float fRec17[3];
	float fConst35;
	float fConst36;
	float fConst37;
	float fRec18[3];
	float fConst38;
	float fConst39;
	float fConst40;
	float fRec19[3];
	float fConst41;
	float fConst42;
	float fConst43;
	float fRec20[3];
	float fConst44;
	float fConst45;
	float fConst46;
	float fRec21[3];
	float fConst47;
	float fConst48;
	float fConst49;
	float fRec22[3];
	float fConst50;
	float fConst51;
	float fConst52;
	float fRec23[3];
	float fConst53;
	float fConst54;
	float fConst55;
	float fRec24[3];
	float fConst56;
	float fConst57;
	float fConst58;
	float fRec25[3];
	float fConst59;
	float fConst60;
	float fConst61;
	float fRec26[3];
	float fConst62;
	float fConst63;
	float fConst64;
	float fRec27[3];
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
	fillmydspSIG0(sig0, 32768, ftbl0mydspSIG0);
	mydspSIG1* sig1 = newmydspSIG1();
	instanceInitmydspSIG1(sig1, sample_rate);
	fillmydspSIG1(sig1, 32768, ftbl1mydspSIG1);
	deletemydspSIG0(sig0);
	deletemydspSIG1(sig1);
}

void instanceResetUserInterfacemydsp(mydsp* dsp) {
	dsp->fHslider0 = (FAUSTFLOAT)(4.4e+02f);
	dsp->fButton0 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider1 = (FAUSTFLOAT)(0.5f);
}

void instanceClearmydsp(mydsp* dsp) {
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
			dsp->iRec2[l1] = 0;
		}
	}
	/* C99 loop */
	{
		int l2;
		for (l2 = 0; l2 < 4; l2 = l2 + 1) {
			dsp->fRec1[l2] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l5;
		for (l5 = 0; l5 < 2; l5 = l5 + 1) {
			dsp->iVec2[l5] = 0;
		}
	}
	/* C99 loop */
	{
		int l6;
		for (l6 = 0; l6 < 2; l6 = l6 + 1) {
			dsp->iRec6[l6] = 0;
		}
	}
	/* C99 loop */
	{
		int l7;
		for (l7 = 0; l7 < 2; l7 = l7 + 1) {
			dsp->fRec5[l7] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l8;
		for (l8 = 0; l8 < 2; l8 = l8 + 1) {
			dsp->fRec4[l8] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l11;
		for (l11 = 0; l11 < 2; l11 = l11 + 1) {
			dsp->fRec8[l11] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l12;
		for (l12 = 0; l12 < 3; l12 = l12 + 1) {
			dsp->fRec0[l12] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l13;
		for (l13 = 0; l13 < 3; l13 = l13 + 1) {
			dsp->fRec9[l13] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l14;
		for (l14 = 0; l14 < 3; l14 = l14 + 1) {
			dsp->fRec10[l14] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l15;
		for (l15 = 0; l15 < 3; l15 = l15 + 1) {
			dsp->fRec11[l15] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l16;
		for (l16 = 0; l16 < 3; l16 = l16 + 1) {
			dsp->fRec12[l16] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l17;
		for (l17 = 0; l17 < 3; l17 = l17 + 1) {
			dsp->fRec13[l17] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l18;
		for (l18 = 0; l18 < 3; l18 = l18 + 1) {
			dsp->fRec14[l18] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l19;
		for (l19 = 0; l19 < 3; l19 = l19 + 1) {
			dsp->fRec15[l19] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l20;
		for (l20 = 0; l20 < 3; l20 = l20 + 1) {
			dsp->fRec16[l20] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l21;
		for (l21 = 0; l21 < 3; l21 = l21 + 1) {
			dsp->fRec17[l21] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l22;
		for (l22 = 0; l22 < 3; l22 = l22 + 1) {
			dsp->fRec18[l22] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l23;
		for (l23 = 0; l23 < 3; l23 = l23 + 1) {
			dsp->fRec19[l23] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l24;
		for (l24 = 0; l24 < 3; l24 = l24 + 1) {
			dsp->fRec20[l24] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l25;
		for (l25 = 0; l25 < 3; l25 = l25 + 1) {
			dsp->fRec21[l25] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l26;
		for (l26 = 0; l26 < 3; l26 = l26 + 1) {
			dsp->fRec22[l26] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l27;
		for (l27 = 0; l27 < 3; l27 = l27 + 1) {
			dsp->fRec23[l27] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l28;
		for (l28 = 0; l28 < 3; l28 = l28 + 1) {
			dsp->fRec24[l28] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l29;
		for (l29 = 0; l29 < 3; l29 = l29 + 1) {
			dsp->fRec25[l29] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l30;
		for (l30 = 0; l30 < 3; l30 = l30 + 1) {
			dsp->fRec26[l30] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l31;
		for (l31 = 0; l31 < 3; l31 = l31 + 1) {
			dsp->fRec27[l31] = 0.0f;
		}
	}
}

void instanceConstantsmydsp(mydsp* dsp, int sample_rate) {
	dsp->fSampleRate = sample_rate;
	dsp->fConst0 = fminf(1.92e+05f, fmaxf(1.0f, (float)(dsp->fSampleRate)));
	dsp->fConst1 = powf(0.001f, 1.6666666f / dsp->fConst0);
	dsp->fConst2 = mydsp_faustpower2_f(dsp->fConst1);
	dsp->fConst3 = 12.566371f / dsp->fConst0;
	dsp->fConst4 = 2.0f * dsp->fConst1;
	dsp->iConst5 = (int)(0.001f * dsp->fConst0);
	dsp->fConst6 = 1.0f / dsp->fConst0;
	dsp->fConst7 = powf(0.001f, 33.333332f / dsp->fConst0);
	dsp->fConst8 = mydsp_faustpower2_f(dsp->fConst7);
	dsp->fConst9 = 6.2831855f / dsp->fConst0;
	dsp->fConst10 = 2.0f * dsp->fConst7;
	dsp->fConst11 = powf(0.001f, 16.666666f / dsp->fConst0);
	dsp->fConst12 = mydsp_faustpower2_f(dsp->fConst11);
	dsp->fConst13 = 2.0f * dsp->fConst11;
	dsp->fConst14 = powf(0.001f, 11.111111f / dsp->fConst0);
	dsp->fConst15 = mydsp_faustpower2_f(dsp->fConst14);
	dsp->fConst16 = 2.0f * dsp->fConst14;
	dsp->fConst17 = powf(0.001f, 8.333333f / dsp->fConst0);
	dsp->fConst18 = mydsp_faustpower2_f(dsp->fConst17);
	dsp->fConst19 = 2.0f * dsp->fConst17;
	dsp->fConst20 = powf(0.001f, 6.6666665f / dsp->fConst0);
	dsp->fConst21 = mydsp_faustpower2_f(dsp->fConst20);
	dsp->fConst22 = 2.0f * dsp->fConst20;
	dsp->fConst23 = powf(0.001f, 5.5555553f / dsp->fConst0);
	dsp->fConst24 = mydsp_faustpower2_f(dsp->fConst23);
	dsp->fConst25 = 2.0f * dsp->fConst23;
	dsp->fConst26 = powf(0.001f, 4.7619047f / dsp->fConst0);
	dsp->fConst27 = mydsp_faustpower2_f(dsp->fConst26);
	dsp->fConst28 = 2.0f * dsp->fConst26;
	dsp->fConst29 = powf(0.001f, 4.1666665f / dsp->fConst0);
	dsp->fConst30 = mydsp_faustpower2_f(dsp->fConst29);
	dsp->fConst31 = 2.0f * dsp->fConst29;
	dsp->fConst32 = powf(0.001f, 3.7037036f / dsp->fConst0);
	dsp->fConst33 = mydsp_faustpower2_f(dsp->fConst32);
	dsp->fConst34 = 2.0f * dsp->fConst32;
	dsp->fConst35 = powf(0.001f, 3.3333333f / dsp->fConst0);
	dsp->fConst36 = mydsp_faustpower2_f(dsp->fConst35);
	dsp->fConst37 = 2.0f * dsp->fConst35;
	dsp->fConst38 = powf(0.001f, 3.030303f / dsp->fConst0);
	dsp->fConst39 = mydsp_faustpower2_f(dsp->fConst38);
	dsp->fConst40 = 2.0f * dsp->fConst38;
	dsp->fConst41 = powf(0.001f, 2.7777777f / dsp->fConst0);
	dsp->fConst42 = mydsp_faustpower2_f(dsp->fConst41);
	dsp->fConst43 = 2.0f * dsp->fConst41;
	dsp->fConst44 = powf(0.001f, 2.5641026f / dsp->fConst0);
	dsp->fConst45 = mydsp_faustpower2_f(dsp->fConst44);
	dsp->fConst46 = 2.0f * dsp->fConst44;
	dsp->fConst47 = powf(0.001f, 2.3809524f / dsp->fConst0);
	dsp->fConst48 = mydsp_faustpower2_f(dsp->fConst47);
	dsp->fConst49 = 2.0f * dsp->fConst47;
	dsp->fConst50 = powf(0.001f, 2.2222223f / dsp->fConst0);
	dsp->fConst51 = mydsp_faustpower2_f(dsp->fConst50);
	dsp->fConst52 = 2.0f * dsp->fConst50;
	dsp->fConst53 = powf(0.001f, 2.0833333f / dsp->fConst0);
	dsp->fConst54 = mydsp_faustpower2_f(dsp->fConst53);
	dsp->fConst55 = 2.0f * dsp->fConst53;
	dsp->fConst56 = powf(0.001f, 1.9607843f / dsp->fConst0);
	dsp->fConst57 = mydsp_faustpower2_f(dsp->fConst56);
	dsp->fConst58 = 2.0f * dsp->fConst56;
	dsp->fConst59 = powf(0.001f, 1.8518518f / dsp->fConst0);
	dsp->fConst60 = mydsp_faustpower2_f(dsp->fConst59);
	dsp->fConst61 = 2.0f * dsp->fConst59;
	dsp->fConst62 = powf(0.001f, 1.754386f / dsp->fConst0);
	dsp->fConst63 = mydsp_faustpower2_f(dsp->fConst62);
	dsp->fConst64 = 2.0f * dsp->fConst62;
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
	float fSlow0 = (float)(dsp->fHslider0);
	float fSlow1 = dsp->fConst4 * cosf(dsp->fConst3 * fSlow0);
	int iSlow2 = (float)(dsp->fButton0) > 0.0f;
	float fSlow3 = (float)(iSlow2);
	float fSlow4 = 2.34f * fSlow0;
	float fSlow5 = 2.5f * (float)(dsp->fHslider1);
	float fSlow6 = 2.0f * fSlow0;
	float fSlow7 = dsp->fConst10 * cosf(dsp->fConst9 * (fSlow6 + 3.8e+03f));
	float fSlow8 = dsp->fConst13 * cosf(dsp->fConst9 * (fSlow6 + 3.6e+03f));
	float fSlow9 = dsp->fConst16 * cosf(dsp->fConst9 * (fSlow6 + 3.4e+03f));
	float fSlow10 = dsp->fConst19 * cosf(dsp->fConst9 * (fSlow6 + 3.2e+03f));
	float fSlow11 = dsp->fConst22 * cosf(dsp->fConst9 * (fSlow6 + 3e+03f));
	float fSlow12 = dsp->fConst25 * cosf(dsp->fConst9 * (fSlow6 + 2.8e+03f));
	float fSlow13 = dsp->fConst28 * cosf(dsp->fConst9 * (fSlow6 + 2.6e+03f));
	float fSlow14 = dsp->fConst31 * cosf(dsp->fConst9 * (fSlow6 + 2.4e+03f));
	float fSlow15 = dsp->fConst34 * cosf(dsp->fConst9 * (fSlow6 + 2.2e+03f));
	float fSlow16 = dsp->fConst37 * cosf(dsp->fConst9 * (fSlow6 + 2e+03f));
	float fSlow17 = dsp->fConst40 * cosf(dsp->fConst9 * (fSlow6 + 1.8e+03f));
	float fSlow18 = dsp->fConst43 * cosf(dsp->fConst9 * (fSlow6 + 1.6e+03f));
	float fSlow19 = dsp->fConst46 * cosf(dsp->fConst9 * (fSlow6 + 1.4e+03f));
	float fSlow20 = dsp->fConst49 * cosf(dsp->fConst9 * (fSlow6 + 1.2e+03f));
	float fSlow21 = dsp->fConst52 * cosf(dsp->fConst9 * (fSlow6 + 1e+03f));
	float fSlow22 = dsp->fConst55 * cosf(dsp->fConst9 * (fSlow6 + 8e+02f));
	float fSlow23 = dsp->fConst58 * cosf(dsp->fConst9 * (fSlow6 + 6e+02f));
	float fSlow24 = dsp->fConst61 * cosf(dsp->fConst9 * (fSlow6 + 4e+02f));
	float fSlow25 = dsp->fConst64 * cosf(dsp->fConst9 * (fSlow6 + 2e+02f));
	/* C99 loop */
	{
		int i0;
		for (i0 = 0; i0 < count; i0 = i0 + 1) {
			dsp->iVec0[0] = 1;
			dsp->iRec2[0] = 1103515245 * dsp->iRec2[1] + 12345;
			dsp->fRec1[0] = 0.5221894f * dsp->fRec1[3] + 4.656613e-10f * (float)(dsp->iRec2[0]) + 2.494956f * dsp->fRec1[1] - 2.0172658f * dsp->fRec1[2];
			float fTemp0 = 0.049922034f * dsp->fRec1[0] + 0.0506127f * dsp->fRec1[2] - (0.095993534f * dsp->fRec1[1] + 0.004408786f * dsp->fRec1[3]);
			dsp->iVec2[0] = iSlow2;
			int iTemp1 = iSlow2 - dsp->iVec2[1];
			dsp->iRec6[0] = iSlow2 * (dsp->iRec6[1] + 1);
			int iTemp2 = (dsp->iRec6[0] < dsp->iConst5) | (iTemp1 * (iTemp1 > 0));
			float fTemp3 = 0.1447178f * ((iSlow2) ? ((iTemp2) ? 0.001f : 0.005f) : 0.005f);
			int iTemp4 = fabsf(fTemp3) < 1.1920929e-07f;
			float fTemp5 = ((iTemp4) ? 0.0f : expf(-(dsp->fConst6 / ((iTemp4) ? 1.0f : fTemp3))));
			float fTemp6 = ((iSlow2) ? ((iTemp2) ? fSlow3 : 0.0f) : 0.0f);
			dsp->fRec5[0] = (1.0f - fTemp5) * fTemp6 + fTemp5 * dsp->fRec5[1];
			float fTemp7 = ((1 - dsp->iVec0[1]) ? 0.0f : dsp->fRec4[1] + dsp->fConst6 * (fSlow4 + 4e+03f * dsp->fRec5[0]));
			dsp->fRec4[0] = fTemp7 - floorf(fTemp7);
			int iTemp8 = max(0, min((int)(32768.0f * dsp->fRec4[0]), 32767));
			float fTemp9 = 0.1447178f * ((iSlow2) ? ((iTemp2) ? 0.001f : 0.07f) : 0.07f);
			int iTemp10 = fabsf(fTemp9) < 1.1920929e-07f;
			float fTemp11 = ((iTemp10) ? 0.0f : expf(-(dsp->fConst6 / ((iTemp10) ? 1.0f : fTemp9))));
			dsp->fRec8[0] = fTemp6 * (1.0f - fTemp11) + fTemp11 * dsp->fRec8[1];
			float fTemp12 = fSlow5 * dsp->fRec8[0] * (ftbl1mydspSIG1[iTemp8] * cosf(fTemp0) + ftbl0mydspSIG0[iTemp8] * sinf(fTemp0));
			dsp->fRec0[0] = fTemp12 + fSlow1 * dsp->fRec0[1] - dsp->fConst2 * dsp->fRec0[2];
			dsp->fRec9[0] = fTemp12 + fSlow7 * dsp->fRec9[1] - dsp->fConst8 * dsp->fRec9[2];
			dsp->fRec10[0] = fTemp12 + fSlow8 * dsp->fRec10[1] - dsp->fConst12 * dsp->fRec10[2];
			dsp->fRec11[0] = fTemp12 + fSlow9 * dsp->fRec11[1] - dsp->fConst15 * dsp->fRec11[2];
			dsp->fRec12[0] = fTemp12 + fSlow10 * dsp->fRec12[1] - dsp->fConst18 * dsp->fRec12[2];
			dsp->fRec13[0] = fTemp12 + fSlow11 * dsp->fRec13[1] - dsp->fConst21 * dsp->fRec13[2];
			dsp->fRec14[0] = fTemp12 + fSlow12 * dsp->fRec14[1] - dsp->fConst24 * dsp->fRec14[2];
			dsp->fRec15[0] = fTemp12 + fSlow13 * dsp->fRec15[1] - dsp->fConst27 * dsp->fRec15[2];
			dsp->fRec16[0] = fTemp12 + fSlow14 * dsp->fRec16[1] - dsp->fConst30 * dsp->fRec16[2];
			dsp->fRec17[0] = fTemp12 + fSlow15 * dsp->fRec17[1] - dsp->fConst33 * dsp->fRec17[2];
			dsp->fRec18[0] = fTemp12 + fSlow16 * dsp->fRec18[1] - dsp->fConst36 * dsp->fRec18[2];
			dsp->fRec19[0] = fTemp12 + fSlow17 * dsp->fRec19[1] - dsp->fConst39 * dsp->fRec19[2];
			dsp->fRec20[0] = fTemp12 + fSlow18 * dsp->fRec20[1] - dsp->fConst42 * dsp->fRec20[2];
			dsp->fRec21[0] = fTemp12 + fSlow19 * dsp->fRec21[1] - dsp->fConst45 * dsp->fRec21[2];
			dsp->fRec22[0] = fTemp12 + fSlow20 * dsp->fRec22[1] - dsp->fConst48 * dsp->fRec22[2];
			dsp->fRec23[0] = fTemp12 + fSlow21 * dsp->fRec23[1] - dsp->fConst51 * dsp->fRec23[2];
			dsp->fRec24[0] = fTemp12 + fSlow22 * dsp->fRec24[1] - dsp->fConst54 * dsp->fRec24[2];
			dsp->fRec25[0] = fTemp12 + fSlow23 * dsp->fRec25[1] - dsp->fConst57 * dsp->fRec25[2];
			dsp->fRec26[0] = fTemp12 + fSlow24 * dsp->fRec26[1] - dsp->fConst60 * dsp->fRec26[2];
			dsp->fRec27[0] = fTemp12 + fSlow25 * dsp->fRec27[1] - dsp->fConst63 * dsp->fRec27[2];
			float fTemp13 = 0.004f * (dsp->fRec0[0] + 0.25f * (dsp->fRec27[0] - dsp->fRec27[2]) + 0.11111111f * (dsp->fRec26[0] - dsp->fRec26[2]) + 0.0625f * (dsp->fRec25[0] - dsp->fRec25[2]) + 0.04f * (dsp->fRec24[0] - dsp->fRec24[2]) + 0.027777778f * (dsp->fRec23[0] - dsp->fRec23[2]) + 0.020408163f * (dsp->fRec22[0] - dsp->fRec22[2]) + 0.015625f * (dsp->fRec21[0] - dsp->fRec21[2]) + 0.012345679f * (dsp->fRec20[0] - dsp->fRec20[2]) + 0.01f * (dsp->fRec19[0] - dsp->fRec19[2]) + 0.008264462f * (dsp->fRec18[0] - dsp->fRec18[2]) + 0.0069444445f * (dsp->fRec17[0] - dsp->fRec17[2]) + 0.00591716f * (dsp->fRec16[0] - dsp->fRec16[2]) + 0.0051020407f * (dsp->fRec15[0] - dsp->fRec15[2]) + 0.0044444446f * (dsp->fRec14[0] - dsp->fRec14[2]) + 0.00390625f * (dsp->fRec13[0] - dsp->fRec13[2]) + 0.0034602077f * (dsp->fRec12[0] - dsp->fRec12[2]) + 0.0030864198f * (dsp->fRec11[0] - dsp->fRec11[2]) + 0.002770083f * (dsp->fRec10[0] - dsp->fRec10[2]) + 0.0025f * (dsp->fRec9[0] - dsp->fRec9[2]) - dsp->fRec0[2]);
			output0[i0] = (FAUSTFLOAT)(fTemp13);
			output1[i0] = (FAUSTFLOAT)(fTemp13);
			dsp->iVec0[1] = dsp->iVec0[0];
			dsp->iRec2[1] = dsp->iRec2[0];
			/* C99 loop */
			{
				int j0;
				for (j0 = 3; j0 > 0; j0 = j0 - 1) {
					dsp->fRec1[j0] = dsp->fRec1[j0 - 1];
				}
			}
			dsp->iVec2[1] = dsp->iVec2[0];
			dsp->iRec6[1] = dsp->iRec6[0];
			dsp->fRec5[1] = dsp->fRec5[0];
			dsp->fRec4[1] = dsp->fRec4[0];
			dsp->fRec8[1] = dsp->fRec8[0];
			dsp->fRec0[2] = dsp->fRec0[1];
			dsp->fRec0[1] = dsp->fRec0[0];
			dsp->fRec9[2] = dsp->fRec9[1];
			dsp->fRec9[1] = dsp->fRec9[0];
			dsp->fRec10[2] = dsp->fRec10[1];
			dsp->fRec10[1] = dsp->fRec10[0];
			dsp->fRec11[2] = dsp->fRec11[1];
			dsp->fRec11[1] = dsp->fRec11[0];
			dsp->fRec12[2] = dsp->fRec12[1];
			dsp->fRec12[1] = dsp->fRec12[0];
			dsp->fRec13[2] = dsp->fRec13[1];
			dsp->fRec13[1] = dsp->fRec13[0];
			dsp->fRec14[2] = dsp->fRec14[1];
			dsp->fRec14[1] = dsp->fRec14[0];
			dsp->fRec15[2] = dsp->fRec15[1];
			dsp->fRec15[1] = dsp->fRec15[0];
			dsp->fRec16[2] = dsp->fRec16[1];
			dsp->fRec16[1] = dsp->fRec16[0];
			dsp->fRec17[2] = dsp->fRec17[1];
			dsp->fRec17[1] = dsp->fRec17[0];
			dsp->fRec18[2] = dsp->fRec18[1];
			dsp->fRec18[1] = dsp->fRec18[0];
			dsp->fRec19[2] = dsp->fRec19[1];
			dsp->fRec19[1] = dsp->fRec19[0];
			dsp->fRec20[2] = dsp->fRec20[1];
			dsp->fRec20[1] = dsp->fRec20[0];
			dsp->fRec21[2] = dsp->fRec21[1];
			dsp->fRec21[1] = dsp->fRec21[0];
			dsp->fRec22[2] = dsp->fRec22[1];
			dsp->fRec22[1] = dsp->fRec22[0];
			dsp->fRec23[2] = dsp->fRec23[1];
			dsp->fRec23[1] = dsp->fRec23[0];
			dsp->fRec24[2] = dsp->fRec24[1];
			dsp->fRec24[1] = dsp->fRec24[0];
			dsp->fRec25[2] = dsp->fRec25[1];
			dsp->fRec25[1] = dsp->fRec25[0];
			dsp->fRec26[2] = dsp->fRec26[1];
			dsp->fRec26[1] = dsp->fRec26[0];
			dsp->fRec27[2] = dsp->fRec27[1];
			dsp->fRec27[1] = dsp->fRec27[0];
		}
	}
}

#ifdef __cplusplus
}
#endif

#endif
