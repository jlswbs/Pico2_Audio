/* ------------------------------------------------------------
name: "djestro"
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

static float mydsp_faustpower2_f(float value) {
	return value * value;
}

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
	FAUSTFLOAT fHslider0;
	float fConst3;
	float fConst4;
	FAUSTFLOAT fButton0;
	float fVec0[2];
	int iRec1[2];
	float fConst5;
	float fConst6;
	float fConst7;
	float fConst8;
	float fConst9;
	float fConst10;
	float fConst11;
	float fConst12;
	float fConst13;
	float fConst14;
	float fConst15;
	float fConst16;
	float fConst17;
	int iRec4[2];
	float fRec3[3];
	float fConst18;
	float fRec2[3];
	FAUSTFLOAT fHslider1;
	float fRec0[3];
	float fConst19;
	float fConst20;
	float fConst21;
	float fConst22;
	float fRec5[3];
	float fConst23;
	float fConst24;
	float fConst25;
	float fRec6[3];
	float fConst26;
	float fConst27;
	float fConst28;
	float fRec7[3];
	float fConst29;
	float fConst30;
	float fConst31;
	float fRec8[3];
	float fConst32;
	float fConst33;
	float fConst34;
	float fRec9[3];
	float fConst35;
	float fConst36;
	float fConst37;
	float fRec10[3];
	float fConst38;
	float fConst39;
	float fConst40;
	float fRec11[3];
	float fConst41;
	float fConst42;
	float fConst43;
	float fRec12[3];
	float fConst44;
	float fConst45;
	float fConst46;
	float fRec13[3];
	float fConst47;
	float fConst48;
	float fConst49;
	float fRec14[3];
	float fConst50;
	float fConst51;
	float fConst52;
	float fRec15[3];
	float fConst53;
	float fConst54;
	float fConst55;
	float fRec16[3];
	float fConst56;
	float fConst57;
	float fConst58;
	float fRec17[3];
	float fConst59;
	float fConst60;
	float fConst61;
	float fRec18[3];
	float fConst62;
	float fConst63;
	float fConst64;
	float fRec19[3];
	float fConst65;
	float fConst66;
	float fConst67;
	float fRec20[3];
	float fConst68;
	float fConst69;
	float fConst70;
	float fRec21[3];
	float fConst71;
	float fConst72;
	float fConst73;
	float fRec22[3];
	float fConst74;
	float fConst75;
	float fConst76;
	float fRec23[3];
	FAUSTFLOAT fHslider2;
	int IOTA0;
	float fRec31[512];
	float fConst77;
	float fConst78;
	float fVec1[512];
	float fRec27[2];
	float fRec24[3];
	float fRec25[3];
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
	dsp->fHslider0 = (FAUSTFLOAT)(0.5f);
	dsp->fButton0 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider1 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider2 = (FAUSTFLOAT)(0.01f);
}

void instanceClearmydsp(mydsp* dsp) {
	/* C99 loop */
	{
		int l0;
		for (l0 = 0; l0 < 2; l0 = l0 + 1) {
			dsp->fVec0[l0] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l1;
		for (l1 = 0; l1 < 2; l1 = l1 + 1) {
			dsp->iRec1[l1] = 0;
		}
	}
	/* C99 loop */
	{
		int l2;
		for (l2 = 0; l2 < 2; l2 = l2 + 1) {
			dsp->iRec4[l2] = 0;
		}
	}
	/* C99 loop */
	{
		int l3;
		for (l3 = 0; l3 < 3; l3 = l3 + 1) {
			dsp->fRec3[l3] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l4;
		for (l4 = 0; l4 < 3; l4 = l4 + 1) {
			dsp->fRec2[l4] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l5;
		for (l5 = 0; l5 < 3; l5 = l5 + 1) {
			dsp->fRec0[l5] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l6;
		for (l6 = 0; l6 < 3; l6 = l6 + 1) {
			dsp->fRec5[l6] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l7;
		for (l7 = 0; l7 < 3; l7 = l7 + 1) {
			dsp->fRec6[l7] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l8;
		for (l8 = 0; l8 < 3; l8 = l8 + 1) {
			dsp->fRec7[l8] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l9;
		for (l9 = 0; l9 < 3; l9 = l9 + 1) {
			dsp->fRec8[l9] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l10;
		for (l10 = 0; l10 < 3; l10 = l10 + 1) {
			dsp->fRec9[l10] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l11;
		for (l11 = 0; l11 < 3; l11 = l11 + 1) {
			dsp->fRec10[l11] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l12;
		for (l12 = 0; l12 < 3; l12 = l12 + 1) {
			dsp->fRec11[l12] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l13;
		for (l13 = 0; l13 < 3; l13 = l13 + 1) {
			dsp->fRec12[l13] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l14;
		for (l14 = 0; l14 < 3; l14 = l14 + 1) {
			dsp->fRec13[l14] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l15;
		for (l15 = 0; l15 < 3; l15 = l15 + 1) {
			dsp->fRec14[l15] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l16;
		for (l16 = 0; l16 < 3; l16 = l16 + 1) {
			dsp->fRec15[l16] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l17;
		for (l17 = 0; l17 < 3; l17 = l17 + 1) {
			dsp->fRec16[l17] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l18;
		for (l18 = 0; l18 < 3; l18 = l18 + 1) {
			dsp->fRec17[l18] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l19;
		for (l19 = 0; l19 < 3; l19 = l19 + 1) {
			dsp->fRec18[l19] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l20;
		for (l20 = 0; l20 < 3; l20 = l20 + 1) {
			dsp->fRec19[l20] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l21;
		for (l21 = 0; l21 < 3; l21 = l21 + 1) {
			dsp->fRec20[l21] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l22;
		for (l22 = 0; l22 < 3; l22 = l22 + 1) {
			dsp->fRec21[l22] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l23;
		for (l23 = 0; l23 < 3; l23 = l23 + 1) {
			dsp->fRec22[l23] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l24;
		for (l24 = 0; l24 < 3; l24 = l24 + 1) {
			dsp->fRec23[l24] = 0.0f;
		}
	}
	dsp->IOTA0 = 0;
	/* C99 loop */
	{
		int l25;
		for (l25 = 0; l25 < 512; l25 = l25 + 1) {
			dsp->fRec31[l25] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l26;
		for (l26 = 0; l26 < 512; l26 = l26 + 1) {
			dsp->fVec1[l26] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l27;
		for (l27 = 0; l27 < 2; l27 = l27 + 1) {
			dsp->fRec27[l27] = 0.0f;
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
}

void instanceConstantsmydsp(mydsp* dsp, int sample_rate) {
	dsp->fSampleRate = sample_rate;
	dsp->fConst0 = fminf(1.92e+05f, fmaxf(1.0f, (float)(dsp->fSampleRate)));
	dsp->fConst1 = powf(0.001f, 1.6666666f / dsp->fConst0);
	dsp->fConst2 = mydsp_faustpower2_f(dsp->fConst1);
	dsp->fConst3 = 5529.203f / dsp->fConst0;
	dsp->fConst4 = 2.0f * dsp->fConst1;
	dsp->fConst5 = 1.0f / fmaxf(1.0f, 0.001f * dsp->fConst0);
	dsp->fConst6 = tanf(25132.742f / dsp->fConst0);
	dsp->fConst7 = 2.0f * (1.0f - 1.0f / mydsp_faustpower2_f(dsp->fConst6));
	dsp->fConst8 = 1.0f / dsp->fConst6;
	dsp->fConst9 = (dsp->fConst8 + -1.4142135f) / dsp->fConst6 + 1.0f;
	dsp->fConst10 = 1.0f / ((dsp->fConst8 + 1.4142135f) / dsp->fConst6 + 1.0f);
	dsp->fConst11 = tanf(911.0619f / dsp->fConst0);
	dsp->fConst12 = mydsp_faustpower2_f(dsp->fConst11);
	dsp->fConst13 = 2.0f * (1.0f - 1.0f / dsp->fConst12);
	dsp->fConst14 = 1.0f / dsp->fConst11;
	dsp->fConst15 = (dsp->fConst14 + -1.4142135f) / dsp->fConst11 + 1.0f;
	dsp->fConst16 = (dsp->fConst14 + 1.4142135f) / dsp->fConst11 + 1.0f;
	dsp->fConst17 = 1.0f / dsp->fConst16;
	dsp->fConst18 = 1.0f / (dsp->fConst12 * dsp->fConst16);
	dsp->fConst19 = powf(0.001f, 33.333332f / dsp->fConst0);
	dsp->fConst20 = mydsp_faustpower2_f(dsp->fConst19);
	dsp->fConst21 = 6.2831855f / dsp->fConst0;
	dsp->fConst22 = 2.0f * dsp->fConst19;
	dsp->fConst23 = powf(0.001f, 16.666666f / dsp->fConst0);
	dsp->fConst24 = mydsp_faustpower2_f(dsp->fConst23);
	dsp->fConst25 = 2.0f * dsp->fConst23;
	dsp->fConst26 = powf(0.001f, 11.111111f / dsp->fConst0);
	dsp->fConst27 = mydsp_faustpower2_f(dsp->fConst26);
	dsp->fConst28 = 2.0f * dsp->fConst26;
	dsp->fConst29 = powf(0.001f, 8.333333f / dsp->fConst0);
	dsp->fConst30 = mydsp_faustpower2_f(dsp->fConst29);
	dsp->fConst31 = 2.0f * dsp->fConst29;
	dsp->fConst32 = powf(0.001f, 6.6666665f / dsp->fConst0);
	dsp->fConst33 = mydsp_faustpower2_f(dsp->fConst32);
	dsp->fConst34 = 2.0f * dsp->fConst32;
	dsp->fConst35 = powf(0.001f, 5.5555553f / dsp->fConst0);
	dsp->fConst36 = mydsp_faustpower2_f(dsp->fConst35);
	dsp->fConst37 = 2.0f * dsp->fConst35;
	dsp->fConst38 = powf(0.001f, 4.7619047f / dsp->fConst0);
	dsp->fConst39 = mydsp_faustpower2_f(dsp->fConst38);
	dsp->fConst40 = 2.0f * dsp->fConst38;
	dsp->fConst41 = powf(0.001f, 4.1666665f / dsp->fConst0);
	dsp->fConst42 = mydsp_faustpower2_f(dsp->fConst41);
	dsp->fConst43 = 2.0f * dsp->fConst41;
	dsp->fConst44 = powf(0.001f, 3.7037036f / dsp->fConst0);
	dsp->fConst45 = mydsp_faustpower2_f(dsp->fConst44);
	dsp->fConst46 = 2.0f * dsp->fConst44;
	dsp->fConst47 = powf(0.001f, 3.3333333f / dsp->fConst0);
	dsp->fConst48 = mydsp_faustpower2_f(dsp->fConst47);
	dsp->fConst49 = 2.0f * dsp->fConst47;
	dsp->fConst50 = powf(0.001f, 3.030303f / dsp->fConst0);
	dsp->fConst51 = mydsp_faustpower2_f(dsp->fConst50);
	dsp->fConst52 = 2.0f * dsp->fConst50;
	dsp->fConst53 = powf(0.001f, 2.7777777f / dsp->fConst0);
	dsp->fConst54 = mydsp_faustpower2_f(dsp->fConst53);
	dsp->fConst55 = 2.0f * dsp->fConst53;
	dsp->fConst56 = powf(0.001f, 2.5641026f / dsp->fConst0);
	dsp->fConst57 = mydsp_faustpower2_f(dsp->fConst56);
	dsp->fConst58 = 2.0f * dsp->fConst56;
	dsp->fConst59 = powf(0.001f, 2.3809524f / dsp->fConst0);
	dsp->fConst60 = mydsp_faustpower2_f(dsp->fConst59);
	dsp->fConst61 = 2.0f * dsp->fConst59;
	dsp->fConst62 = powf(0.001f, 2.2222223f / dsp->fConst0);
	dsp->fConst63 = mydsp_faustpower2_f(dsp->fConst62);
	dsp->fConst64 = 2.0f * dsp->fConst62;
	dsp->fConst65 = powf(0.001f, 2.0833333f / dsp->fConst0);
	dsp->fConst66 = mydsp_faustpower2_f(dsp->fConst65);
	dsp->fConst67 = 2.0f * dsp->fConst65;
	dsp->fConst68 = powf(0.001f, 1.9607843f / dsp->fConst0);
	dsp->fConst69 = mydsp_faustpower2_f(dsp->fConst68);
	dsp->fConst70 = 2.0f * dsp->fConst68;
	dsp->fConst71 = powf(0.001f, 1.8518518f / dsp->fConst0);
	dsp->fConst72 = mydsp_faustpower2_f(dsp->fConst71);
	dsp->fConst73 = 2.0f * dsp->fConst71;
	dsp->fConst74 = powf(0.001f, 1.754386f / dsp->fConst0);
	dsp->fConst75 = mydsp_faustpower2_f(dsp->fConst74);
	dsp->fConst76 = 2.0f * dsp->fConst74;
	dsp->fConst77 = 0.00882353f * dsp->fConst0;
	dsp->fConst78 = 0.0014705883f * dsp->fConst0;
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
	float fSlow2 = (float)(dsp->fButton0);
	float fSlow3 = (float)(dsp->fHslider1);
	float fSlow4 = dsp->fConst10 * fSlow3;
	float fSlow5 = 8.8e+02f * fSlow0;
	float fSlow6 = dsp->fConst22 * cosf(dsp->fConst21 * (fSlow5 + 3.8e+03f));
	float fSlow7 = dsp->fConst25 * cosf(dsp->fConst21 * (fSlow5 + 3.6e+03f));
	float fSlow8 = dsp->fConst28 * cosf(dsp->fConst21 * (fSlow5 + 3.4e+03f));
	float fSlow9 = dsp->fConst31 * cosf(dsp->fConst21 * (fSlow5 + 3.2e+03f));
	float fSlow10 = dsp->fConst34 * cosf(dsp->fConst21 * (fSlow5 + 3e+03f));
	float fSlow11 = dsp->fConst37 * cosf(dsp->fConst21 * (fSlow5 + 2.8e+03f));
	float fSlow12 = dsp->fConst40 * cosf(dsp->fConst21 * (fSlow5 + 2.6e+03f));
	float fSlow13 = dsp->fConst43 * cosf(dsp->fConst21 * (fSlow5 + 2.4e+03f));
	float fSlow14 = dsp->fConst46 * cosf(dsp->fConst21 * (fSlow5 + 2.2e+03f));
	float fSlow15 = dsp->fConst49 * cosf(dsp->fConst21 * (fSlow5 + 2e+03f));
	float fSlow16 = dsp->fConst52 * cosf(dsp->fConst21 * (fSlow5 + 1.8e+03f));
	float fSlow17 = dsp->fConst55 * cosf(dsp->fConst21 * (fSlow5 + 1.6e+03f));
	float fSlow18 = dsp->fConst58 * cosf(dsp->fConst21 * (fSlow5 + 1.4e+03f));
	float fSlow19 = dsp->fConst61 * cosf(dsp->fConst21 * (fSlow5 + 1.2e+03f));
	float fSlow20 = dsp->fConst64 * cosf(dsp->fConst21 * (fSlow5 + 1e+03f));
	float fSlow21 = dsp->fConst67 * cosf(dsp->fConst21 * (fSlow5 + 8e+02f));
	float fSlow22 = dsp->fConst70 * cosf(dsp->fConst21 * (fSlow5 + 6e+02f));
	float fSlow23 = dsp->fConst73 * cosf(dsp->fConst21 * (fSlow5 + 4e+02f));
	float fSlow24 = dsp->fConst76 * cosf(dsp->fConst21 * (fSlow5 + 2e+02f));
	float fSlow25 = 0.5f * (0.2f * (1.0f - (float)(dsp->fHslider2)) + 0.8f);
	float fSlow26 = dsp->fConst78 * (fSlow0 + -0.05f);
	float fSlow27 = fSlow26 + -1.499995f;
	int iSlow28 = (int)(fSlow27);
	int iSlow29 = (int)(fminf(dsp->fConst77, (float)(max(0, iSlow28 + 4)))) + 1;
	float fSlow30 = floorf(fSlow27);
	float fSlow31 = fSlow26 + (-3.0f - fSlow30);
	float fSlow32 = fSlow26 + (-2.0f - fSlow30);
	float fSlow33 = fSlow26 + (-1.0f - fSlow30);
	float fSlow34 = fSlow26 - fSlow30;
	float fSlow35 = fSlow34 * fSlow33;
	float fSlow36 = fSlow35 * fSlow32;
	float fSlow37 = 0.041666668f * fSlow36 * fSlow31;
	int iSlow38 = (int)(fminf(dsp->fConst77, (float)(max(0, iSlow28 + 3)))) + 1;
	float fSlow39 = 0.16666667f * fSlow36;
	int iSlow40 = (int)(fminf(dsp->fConst77, (float)(max(0, iSlow28 + 2)))) + 1;
	float fSlow41 = 0.25f * fSlow35;
	int iSlow42 = (int)(fminf(dsp->fConst77, (float)(max(0, iSlow28 + 1)))) + 1;
	float fSlow43 = 0.16666667f * fSlow34;
	int iSlow44 = (int)(fminf(dsp->fConst77, (float)(max(0, iSlow28)))) + 1;
	float fSlow45 = 0.041666668f * fSlow33;
	float fSlow46 = fSlow26 + (-4.0f - fSlow30);
	/* C99 loop */
	{
		int i0;
		for (i0 = 0; i0 < count; i0 = i0 + 1) {
			dsp->fVec0[0] = fSlow2;
			dsp->iRec1[0] = (dsp->iRec1[1] + (dsp->iRec1[1] > 0)) * (fSlow2 <= dsp->fVec0[1]) + (fSlow2 > dsp->fVec0[1]);
			float fTemp0 = dsp->fConst5 * (float)(dsp->iRec1[0]);
			dsp->iRec4[0] = 1103515245 * dsp->iRec4[1] + 12345;
			dsp->fRec3[0] = 4.656613e-10f * (float)(dsp->iRec4[0]) - dsp->fConst17 * (dsp->fConst15 * dsp->fRec3[2] + dsp->fConst13 * dsp->fRec3[1]);
			dsp->fRec2[0] = dsp->fConst18 * (dsp->fRec3[2] + (dsp->fRec3[0] - 2.0f * dsp->fRec3[1])) - dsp->fConst10 * (dsp->fConst9 * dsp->fRec2[2] + dsp->fConst7 * dsp->fRec2[1]);
			float fTemp1 = fSlow4 * (dsp->fRec2[2] + dsp->fRec2[0] + 2.0f * dsp->fRec2[1]) * fmaxf(0.0f, fminf(fTemp0, 2.0f - fTemp0));
			dsp->fRec0[0] = fTemp1 + fSlow1 * dsp->fRec0[1] - dsp->fConst2 * dsp->fRec0[2];
			dsp->fRec5[0] = fTemp1 + fSlow6 * dsp->fRec5[1] - dsp->fConst20 * dsp->fRec5[2];
			dsp->fRec6[0] = fTemp1 + fSlow7 * dsp->fRec6[1] - dsp->fConst24 * dsp->fRec6[2];
			dsp->fRec7[0] = fTemp1 + fSlow8 * dsp->fRec7[1] - dsp->fConst27 * dsp->fRec7[2];
			dsp->fRec8[0] = fTemp1 + fSlow9 * dsp->fRec8[1] - dsp->fConst30 * dsp->fRec8[2];
			dsp->fRec9[0] = fTemp1 + fSlow10 * dsp->fRec9[1] - dsp->fConst33 * dsp->fRec9[2];
			dsp->fRec10[0] = fTemp1 + fSlow11 * dsp->fRec10[1] - dsp->fConst36 * dsp->fRec10[2];
			dsp->fRec11[0] = fTemp1 + fSlow12 * dsp->fRec11[1] - dsp->fConst39 * dsp->fRec11[2];
			dsp->fRec12[0] = fTemp1 + fSlow13 * dsp->fRec12[1] - dsp->fConst42 * dsp->fRec12[2];
			dsp->fRec13[0] = fTemp1 + fSlow14 * dsp->fRec13[1] - dsp->fConst45 * dsp->fRec13[2];
			dsp->fRec14[0] = fTemp1 + fSlow15 * dsp->fRec14[1] - dsp->fConst48 * dsp->fRec14[2];
			dsp->fRec15[0] = fTemp1 + fSlow16 * dsp->fRec15[1] - dsp->fConst51 * dsp->fRec15[2];
			dsp->fRec16[0] = fTemp1 + fSlow17 * dsp->fRec16[1] - dsp->fConst54 * dsp->fRec16[2];
			dsp->fRec17[0] = fTemp1 + fSlow18 * dsp->fRec17[1] - dsp->fConst57 * dsp->fRec17[2];
			dsp->fRec18[0] = fTemp1 + fSlow19 * dsp->fRec18[1] - dsp->fConst60 * dsp->fRec18[2];
			dsp->fRec19[0] = fTemp1 + fSlow20 * dsp->fRec19[1] - dsp->fConst63 * dsp->fRec19[2];
			dsp->fRec20[0] = fTemp1 + fSlow21 * dsp->fRec20[1] - dsp->fConst66 * dsp->fRec20[2];
			dsp->fRec21[0] = fTemp1 + fSlow22 * dsp->fRec21[1] - dsp->fConst69 * dsp->fRec21[2];
			dsp->fRec22[0] = fTemp1 + fSlow23 * dsp->fRec22[1] - dsp->fConst72 * dsp->fRec22[2];
			dsp->fRec23[0] = fTemp1 + fSlow24 * dsp->fRec23[1] - dsp->fConst75 * dsp->fRec23[2];
			float fTemp2 = fSlow25 * (dsp->fRec25[1] + dsp->fRec25[2]);
			dsp->fRec31[dsp->IOTA0 & 511] = fTemp2;
			float fRec32 = fSlow46 * (fSlow31 * (fSlow32 * (fSlow45 * dsp->fRec31[(dsp->IOTA0 - iSlow44) & 511] - fSlow43 * dsp->fRec31[(dsp->IOTA0 - iSlow42) & 511]) + fSlow41 * dsp->fRec31[(dsp->IOTA0 - iSlow40) & 511]) - fSlow39 * dsp->fRec31[(dsp->IOTA0 - iSlow38) & 511]) + fSlow37 * dsp->fRec31[(dsp->IOTA0 - iSlow29) & 511];
			float fTemp3 = fSlow2 - dsp->fVec0[1];
			float fTemp4 = fSlow3 * fTemp3 * (float)(fTemp3 > 0.0f);
			float fTemp5 = dsp->fRec24[2] + fTemp4;
			dsp->fVec1[dsp->IOTA0 & 511] = fTemp5;
			float fTemp6 = fSlow37 * dsp->fVec1[(dsp->IOTA0 - iSlow29) & 511];
			float fTemp7 = fSlow46 * (fSlow31 * (fSlow32 * (fSlow45 * dsp->fVec1[(dsp->IOTA0 - iSlow44) & 511] - fSlow43 * dsp->fVec1[(dsp->IOTA0 - iSlow42) & 511]) + fSlow41 * dsp->fVec1[(dsp->IOTA0 - iSlow40) & 511]) - fSlow39 * dsp->fVec1[(dsp->IOTA0 - iSlow38) & 511]);
			float fRec33 = fTemp7 + fTemp6;
			float fRec34 = fTemp6 + fTemp2 + fTemp7;
			dsp->fRec27[0] = fRec32;
			float fRec28 = fTemp4 + dsp->fRec27[1];
			float fRec29 = fRec33;
			float fRec30 = fRec34;
			dsp->fRec24[0] = fRec28;
			dsp->fRec25[0] = fRec29;
			float fRec26 = fRec30;
			float fTemp8 = 0.5f * fRec26 + 0.025f * (dsp->fRec0[0] + 0.25f * (dsp->fRec23[0] - dsp->fRec23[2]) + 0.11111111f * (dsp->fRec22[0] - dsp->fRec22[2]) + 0.0625f * (dsp->fRec21[0] - dsp->fRec21[2]) + 0.04f * (dsp->fRec20[0] - dsp->fRec20[2]) + 0.027777778f * (dsp->fRec19[0] - dsp->fRec19[2]) + 0.020408163f * (dsp->fRec18[0] - dsp->fRec18[2]) + 0.015625f * (dsp->fRec17[0] - dsp->fRec17[2]) + 0.012345679f * (dsp->fRec16[0] - dsp->fRec16[2]) + 0.01f * (dsp->fRec15[0] - dsp->fRec15[2]) + 0.008264462f * (dsp->fRec14[0] - dsp->fRec14[2]) + 0.0069444445f * (dsp->fRec13[0] - dsp->fRec13[2]) + 0.00591716f * (dsp->fRec12[0] - dsp->fRec12[2]) + 0.0051020407f * (dsp->fRec11[0] - dsp->fRec11[2]) + 0.0044444446f * (dsp->fRec10[0] - dsp->fRec10[2]) + 0.00390625f * (dsp->fRec9[0] - dsp->fRec9[2]) + 0.0034602077f * (dsp->fRec8[0] - dsp->fRec8[2]) + 0.0030864198f * (dsp->fRec7[0] - dsp->fRec7[2]) + 0.002770083f * (dsp->fRec6[0] - dsp->fRec6[2]) + 0.0025f * (dsp->fRec5[0] - dsp->fRec5[2]) - dsp->fRec0[2]);
			output0[i0] = (FAUSTFLOAT)(fTemp8);
			output1[i0] = (FAUSTFLOAT)(fTemp8);
			dsp->fVec0[1] = dsp->fVec0[0];
			dsp->iRec1[1] = dsp->iRec1[0];
			dsp->iRec4[1] = dsp->iRec4[0];
			dsp->fRec3[2] = dsp->fRec3[1];
			dsp->fRec3[1] = dsp->fRec3[0];
			dsp->fRec2[2] = dsp->fRec2[1];
			dsp->fRec2[1] = dsp->fRec2[0];
			dsp->fRec0[2] = dsp->fRec0[1];
			dsp->fRec0[1] = dsp->fRec0[0];
			dsp->fRec5[2] = dsp->fRec5[1];
			dsp->fRec5[1] = dsp->fRec5[0];
			dsp->fRec6[2] = dsp->fRec6[1];
			dsp->fRec6[1] = dsp->fRec6[0];
			dsp->fRec7[2] = dsp->fRec7[1];
			dsp->fRec7[1] = dsp->fRec7[0];
			dsp->fRec8[2] = dsp->fRec8[1];
			dsp->fRec8[1] = dsp->fRec8[0];
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
			dsp->IOTA0 = dsp->IOTA0 + 1;
			dsp->fRec27[1] = dsp->fRec27[0];
			dsp->fRec24[2] = dsp->fRec24[1];
			dsp->fRec24[1] = dsp->fRec24[0];
			dsp->fRec25[2] = dsp->fRec25[1];
			dsp->fRec25[1] = dsp->fRec25[0];
		}
	}
}

#ifdef __cplusplus
}
#endif

#endif
