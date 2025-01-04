/* ------------------------------------------------------------
name: "djembe"
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
	FAUSTFLOAT fHslider1;
	float fConst5;
	FAUSTFLOAT fHslider2;
	float fConst6;
	int iRec4[2];
	float fRec3[3];
	float fRec2[3];
	FAUSTFLOAT fHslider3;
	float fRec0[3];
	float fConst7;
	float fConst8;
	float fConst9;
	float fRec5[3];
	float fConst10;
	float fConst11;
	float fConst12;
	float fRec6[3];
	float fConst13;
	float fConst14;
	float fConst15;
	float fRec7[3];
	float fConst16;
	float fConst17;
	float fConst18;
	float fRec8[3];
	float fConst19;
	float fConst20;
	float fConst21;
	float fRec9[3];
	float fConst22;
	float fConst23;
	float fConst24;
	float fRec10[3];
	float fConst25;
	float fConst26;
	float fConst27;
	float fRec11[3];
	float fConst28;
	float fConst29;
	float fConst30;
	float fRec12[3];
	float fConst31;
	float fConst32;
	float fConst33;
	float fRec13[3];
	float fConst34;
	float fConst35;
	float fConst36;
	float fRec14[3];
	float fConst37;
	float fConst38;
	float fConst39;
	float fRec15[3];
	float fConst40;
	float fConst41;
	float fConst42;
	float fRec16[3];
	float fConst43;
	float fConst44;
	float fConst45;
	float fRec17[3];
	float fConst46;
	float fConst47;
	float fConst48;
	float fRec18[3];
	float fConst49;
	float fConst50;
	float fConst51;
	float fRec19[3];
	float fConst52;
	float fConst53;
	float fConst54;
	float fRec20[3];
	float fConst55;
	float fConst56;
	float fConst57;
	float fRec21[3];
	float fConst58;
	float fConst59;
	float fConst60;
	float fRec22[3];
	float fConst61;
	float fConst62;
	float fConst63;
	float fRec23[3];
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
	dsp->fHslider0 = (FAUSTFLOAT)(4.4e+02f);
	dsp->fButton0 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider1 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider2 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider3 = (FAUSTFLOAT)(0.5f);
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
}

void instanceConstantsmydsp(mydsp* dsp, int sample_rate) {
	dsp->fSampleRate = sample_rate;
	dsp->fConst0 = fminf(1.92e+05f, fmaxf(1.0f, (float)(dsp->fSampleRate)));
	dsp->fConst1 = powf(0.001f, 1.6666666f / dsp->fConst0);
	dsp->fConst2 = mydsp_faustpower2_f(dsp->fConst1);
	dsp->fConst3 = 6.2831855f / dsp->fConst0;
	dsp->fConst4 = 2.0f * dsp->fConst1;
	dsp->fConst5 = 0.002f * dsp->fConst0;
	dsp->fConst6 = 3.1415927f / dsp->fConst0;
	dsp->fConst7 = powf(0.001f, 33.333332f / dsp->fConst0);
	dsp->fConst8 = mydsp_faustpower2_f(dsp->fConst7);
	dsp->fConst9 = 2.0f * dsp->fConst7;
	dsp->fConst10 = powf(0.001f, 16.666666f / dsp->fConst0);
	dsp->fConst11 = mydsp_faustpower2_f(dsp->fConst10);
	dsp->fConst12 = 2.0f * dsp->fConst10;
	dsp->fConst13 = powf(0.001f, 11.111111f / dsp->fConst0);
	dsp->fConst14 = mydsp_faustpower2_f(dsp->fConst13);
	dsp->fConst15 = 2.0f * dsp->fConst13;
	dsp->fConst16 = powf(0.001f, 8.333333f / dsp->fConst0);
	dsp->fConst17 = mydsp_faustpower2_f(dsp->fConst16);
	dsp->fConst18 = 2.0f * dsp->fConst16;
	dsp->fConst19 = powf(0.001f, 6.6666665f / dsp->fConst0);
	dsp->fConst20 = mydsp_faustpower2_f(dsp->fConst19);
	dsp->fConst21 = 2.0f * dsp->fConst19;
	dsp->fConst22 = powf(0.001f, 5.5555553f / dsp->fConst0);
	dsp->fConst23 = mydsp_faustpower2_f(dsp->fConst22);
	dsp->fConst24 = 2.0f * dsp->fConst22;
	dsp->fConst25 = powf(0.001f, 4.7619047f / dsp->fConst0);
	dsp->fConst26 = mydsp_faustpower2_f(dsp->fConst25);
	dsp->fConst27 = 2.0f * dsp->fConst25;
	dsp->fConst28 = powf(0.001f, 4.1666665f / dsp->fConst0);
	dsp->fConst29 = mydsp_faustpower2_f(dsp->fConst28);
	dsp->fConst30 = 2.0f * dsp->fConst28;
	dsp->fConst31 = powf(0.001f, 3.7037036f / dsp->fConst0);
	dsp->fConst32 = mydsp_faustpower2_f(dsp->fConst31);
	dsp->fConst33 = 2.0f * dsp->fConst31;
	dsp->fConst34 = powf(0.001f, 3.3333333f / dsp->fConst0);
	dsp->fConst35 = mydsp_faustpower2_f(dsp->fConst34);
	dsp->fConst36 = 2.0f * dsp->fConst34;
	dsp->fConst37 = powf(0.001f, 3.030303f / dsp->fConst0);
	dsp->fConst38 = mydsp_faustpower2_f(dsp->fConst37);
	dsp->fConst39 = 2.0f * dsp->fConst37;
	dsp->fConst40 = powf(0.001f, 2.7777777f / dsp->fConst0);
	dsp->fConst41 = mydsp_faustpower2_f(dsp->fConst40);
	dsp->fConst42 = 2.0f * dsp->fConst40;
	dsp->fConst43 = powf(0.001f, 2.5641026f / dsp->fConst0);
	dsp->fConst44 = mydsp_faustpower2_f(dsp->fConst43);
	dsp->fConst45 = 2.0f * dsp->fConst43;
	dsp->fConst46 = powf(0.001f, 2.3809524f / dsp->fConst0);
	dsp->fConst47 = mydsp_faustpower2_f(dsp->fConst46);
	dsp->fConst48 = 2.0f * dsp->fConst46;
	dsp->fConst49 = powf(0.001f, 2.2222223f / dsp->fConst0);
	dsp->fConst50 = mydsp_faustpower2_f(dsp->fConst49);
	dsp->fConst51 = 2.0f * dsp->fConst49;
	dsp->fConst52 = powf(0.001f, 2.0833333f / dsp->fConst0);
	dsp->fConst53 = mydsp_faustpower2_f(dsp->fConst52);
	dsp->fConst54 = 2.0f * dsp->fConst52;
	dsp->fConst55 = powf(0.001f, 1.9607843f / dsp->fConst0);
	dsp->fConst56 = mydsp_faustpower2_f(dsp->fConst55);
	dsp->fConst57 = 2.0f * dsp->fConst55;
	dsp->fConst58 = powf(0.001f, 1.8518518f / dsp->fConst0);
	dsp->fConst59 = mydsp_faustpower2_f(dsp->fConst58);
	dsp->fConst60 = 2.0f * dsp->fConst58;
	dsp->fConst61 = powf(0.001f, 1.754386f / dsp->fConst0);
	dsp->fConst62 = mydsp_faustpower2_f(dsp->fConst61);
	dsp->fConst63 = 2.0f * dsp->fConst61;
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
	float fSlow3 = 1.0f / fmaxf(1.0f, dsp->fConst5 * (float)(dsp->fHslider1));
	float fSlow4 = (float)(dsp->fHslider2);
	float fSlow5 = tanf(dsp->fConst6 * (1.5e+04f * fSlow4 + 5e+02f));
	float fSlow6 = 2.0f * (1.0f - 1.0f / mydsp_faustpower2_f(fSlow5));
	float fSlow7 = 1.0f / fSlow5;
	float fSlow8 = (fSlow7 + -1.4142135f) / fSlow5 + 1.0f;
	float fSlow9 = (fSlow7 + 1.4142135f) / fSlow5 + 1.0f;
	float fSlow10 = 1.0f / fSlow9;
	float fSlow11 = tanf(dsp->fConst6 * (5e+02f * fSlow4 + 4e+01f));
	float fSlow12 = mydsp_faustpower2_f(fSlow11);
	float fSlow13 = 2.0f * (1.0f - 1.0f / fSlow12);
	float fSlow14 = 1.0f / fSlow11;
	float fSlow15 = (fSlow14 + -1.4142135f) / fSlow11 + 1.0f;
	float fSlow16 = (fSlow14 + 1.4142135f) / fSlow11 + 1.0f;
	float fSlow17 = 1.0f / fSlow16;
	float fSlow18 = 1.0f / (fSlow12 * fSlow16);
	float fSlow19 = (float)(dsp->fHslider3) / fSlow9;
	float fSlow20 = dsp->fConst9 * cosf(dsp->fConst3 * (fSlow0 + 3.8e+03f));
	float fSlow21 = dsp->fConst12 * cosf(dsp->fConst3 * (fSlow0 + 3.6e+03f));
	float fSlow22 = dsp->fConst15 * cosf(dsp->fConst3 * (fSlow0 + 3.4e+03f));
	float fSlow23 = dsp->fConst18 * cosf(dsp->fConst3 * (fSlow0 + 3.2e+03f));
	float fSlow24 = dsp->fConst21 * cosf(dsp->fConst3 * (fSlow0 + 3e+03f));
	float fSlow25 = dsp->fConst24 * cosf(dsp->fConst3 * (fSlow0 + 2.8e+03f));
	float fSlow26 = dsp->fConst27 * cosf(dsp->fConst3 * (fSlow0 + 2.6e+03f));
	float fSlow27 = dsp->fConst30 * cosf(dsp->fConst3 * (fSlow0 + 2.4e+03f));
	float fSlow28 = dsp->fConst33 * cosf(dsp->fConst3 * (fSlow0 + 2.2e+03f));
	float fSlow29 = dsp->fConst36 * cosf(dsp->fConst3 * (fSlow0 + 2e+03f));
	float fSlow30 = dsp->fConst39 * cosf(dsp->fConst3 * (fSlow0 + 1.8e+03f));
	float fSlow31 = dsp->fConst42 * cosf(dsp->fConst3 * (fSlow0 + 1.6e+03f));
	float fSlow32 = dsp->fConst45 * cosf(dsp->fConst3 * (fSlow0 + 1.4e+03f));
	float fSlow33 = dsp->fConst48 * cosf(dsp->fConst3 * (fSlow0 + 1.2e+03f));
	float fSlow34 = dsp->fConst51 * cosf(dsp->fConst3 * (fSlow0 + 1e+03f));
	float fSlow35 = dsp->fConst54 * cosf(dsp->fConst3 * (fSlow0 + 8e+02f));
	float fSlow36 = dsp->fConst57 * cosf(dsp->fConst3 * (fSlow0 + 6e+02f));
	float fSlow37 = dsp->fConst60 * cosf(dsp->fConst3 * (fSlow0 + 4e+02f));
	float fSlow38 = dsp->fConst63 * cosf(dsp->fConst3 * (fSlow0 + 2e+02f));
	/* C99 loop */
	{
		int i0;
		for (i0 = 0; i0 < count; i0 = i0 + 1) {
			dsp->fVec0[0] = fSlow2;
			dsp->iRec1[0] = (dsp->iRec1[1] + (dsp->iRec1[1] > 0)) * (fSlow2 <= dsp->fVec0[1]) + (fSlow2 > dsp->fVec0[1]);
			float fTemp0 = fSlow3 * (float)(dsp->iRec1[0]);
			dsp->iRec4[0] = 1103515245 * dsp->iRec4[1] + 12345;
			dsp->fRec3[0] = 4.656613e-10f * (float)(dsp->iRec4[0]) - fSlow17 * (fSlow15 * dsp->fRec3[2] + fSlow13 * dsp->fRec3[1]);
			dsp->fRec2[0] = fSlow18 * (dsp->fRec3[2] + (dsp->fRec3[0] - 2.0f * dsp->fRec3[1])) - fSlow10 * (fSlow8 * dsp->fRec2[2] + fSlow6 * dsp->fRec2[1]);
			float fTemp1 = fSlow19 * (dsp->fRec2[2] + dsp->fRec2[0] + 2.0f * dsp->fRec2[1]) * fmaxf(0.0f, fminf(fTemp0, 2.0f - fTemp0));
			dsp->fRec0[0] = fTemp1 + fSlow1 * dsp->fRec0[1] - dsp->fConst2 * dsp->fRec0[2];
			dsp->fRec5[0] = fTemp1 + fSlow20 * dsp->fRec5[1] - dsp->fConst8 * dsp->fRec5[2];
			dsp->fRec6[0] = fTemp1 + fSlow21 * dsp->fRec6[1] - dsp->fConst11 * dsp->fRec6[2];
			dsp->fRec7[0] = fTemp1 + fSlow22 * dsp->fRec7[1] - dsp->fConst14 * dsp->fRec7[2];
			dsp->fRec8[0] = fTemp1 + fSlow23 * dsp->fRec8[1] - dsp->fConst17 * dsp->fRec8[2];
			dsp->fRec9[0] = fTemp1 + fSlow24 * dsp->fRec9[1] - dsp->fConst20 * dsp->fRec9[2];
			dsp->fRec10[0] = fTemp1 + fSlow25 * dsp->fRec10[1] - dsp->fConst23 * dsp->fRec10[2];
			dsp->fRec11[0] = fTemp1 + fSlow26 * dsp->fRec11[1] - dsp->fConst26 * dsp->fRec11[2];
			dsp->fRec12[0] = fTemp1 + fSlow27 * dsp->fRec12[1] - dsp->fConst29 * dsp->fRec12[2];
			dsp->fRec13[0] = fTemp1 + fSlow28 * dsp->fRec13[1] - dsp->fConst32 * dsp->fRec13[2];
			dsp->fRec14[0] = fTemp1 + fSlow29 * dsp->fRec14[1] - dsp->fConst35 * dsp->fRec14[2];
			dsp->fRec15[0] = fTemp1 + fSlow30 * dsp->fRec15[1] - dsp->fConst38 * dsp->fRec15[2];
			dsp->fRec16[0] = fTemp1 + fSlow31 * dsp->fRec16[1] - dsp->fConst41 * dsp->fRec16[2];
			dsp->fRec17[0] = fTemp1 + fSlow32 * dsp->fRec17[1] - dsp->fConst44 * dsp->fRec17[2];
			dsp->fRec18[0] = fTemp1 + fSlow33 * dsp->fRec18[1] - dsp->fConst47 * dsp->fRec18[2];
			dsp->fRec19[0] = fTemp1 + fSlow34 * dsp->fRec19[1] - dsp->fConst50 * dsp->fRec19[2];
			dsp->fRec20[0] = fTemp1 + fSlow35 * dsp->fRec20[1] - dsp->fConst53 * dsp->fRec20[2];
			dsp->fRec21[0] = fTemp1 + fSlow36 * dsp->fRec21[1] - dsp->fConst56 * dsp->fRec21[2];
			dsp->fRec22[0] = fTemp1 + fSlow37 * dsp->fRec22[1] - dsp->fConst59 * dsp->fRec22[2];
			dsp->fRec23[0] = fTemp1 + fSlow38 * dsp->fRec23[1] - dsp->fConst62 * dsp->fRec23[2];
			float fTemp2 = 0.05f * (dsp->fRec0[0] + 0.25f * (dsp->fRec23[0] - dsp->fRec23[2]) + 0.11111111f * (dsp->fRec22[0] - dsp->fRec22[2]) + 0.0625f * (dsp->fRec21[0] - dsp->fRec21[2]) + 0.04f * (dsp->fRec20[0] - dsp->fRec20[2]) + 0.027777778f * (dsp->fRec19[0] - dsp->fRec19[2]) + 0.020408163f * (dsp->fRec18[0] - dsp->fRec18[2]) + 0.015625f * (dsp->fRec17[0] - dsp->fRec17[2]) + 0.012345679f * (dsp->fRec16[0] - dsp->fRec16[2]) + 0.01f * (dsp->fRec15[0] - dsp->fRec15[2]) + 0.008264462f * (dsp->fRec14[0] - dsp->fRec14[2]) + 0.0069444445f * (dsp->fRec13[0] - dsp->fRec13[2]) + 0.00591716f * (dsp->fRec12[0] - dsp->fRec12[2]) + 0.0051020407f * (dsp->fRec11[0] - dsp->fRec11[2]) + 0.0044444446f * (dsp->fRec10[0] - dsp->fRec10[2]) + 0.00390625f * (dsp->fRec9[0] - dsp->fRec9[2]) + 0.0034602077f * (dsp->fRec8[0] - dsp->fRec8[2]) + 0.0030864198f * (dsp->fRec7[0] - dsp->fRec7[2]) + 0.002770083f * (dsp->fRec6[0] - dsp->fRec6[2]) + 0.0025f * (dsp->fRec5[0] - dsp->fRec5[2]) - dsp->fRec0[2]);
			output0[i0] = (FAUSTFLOAT)(fTemp2);
			output1[i0] = (FAUSTFLOAT)(fTemp2);
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
		}
	}
}

#ifdef __cplusplus
}
#endif

#endif
