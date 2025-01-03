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
	int iVec0[2];
	int iRec2[2];
	int iVec1[2];
	int iRec3[2];
	float fRec1[2];
	float fConst3;
	float fConst4;
	int iRec4[2];
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
	float fConst18;
	float fRec6[3];
	float fConst19;
	float fRec5[3];
	float fConst20;
	float fRec0[3];
	float fConst21;
	float fConst22;
	float fConst23;
	float fRec7[3];
	float fConst24;
	float fConst25;
	float fConst26;
	float fRec8[3];
	float fConst27;
	float fConst28;
	float fConst29;
	float fRec9[3];
	float fConst30;
	float fConst31;
	float fConst32;
	float fRec10[3];
	float fConst33;
	float fConst34;
	float fConst35;
	float fRec11[3];
	float fConst36;
	float fConst37;
	float fConst38;
	float fRec12[3];
	float fConst39;
	float fConst40;
	float fConst41;
	float fRec13[3];
	float fConst42;
	float fConst43;
	float fConst44;
	float fRec14[3];
	float fConst45;
	float fConst46;
	float fConst47;
	float fRec15[3];
	float fConst48;
	float fConst49;
	float fConst50;
	float fRec16[3];
	float fConst51;
	float fConst52;
	float fConst53;
	float fRec17[3];
	float fConst54;
	float fConst55;
	float fConst56;
	float fRec18[3];
	float fConst57;
	float fConst58;
	float fConst59;
	float fRec19[3];
	float fConst60;
	float fConst61;
	float fConst62;
	float fRec20[3];
	float fConst63;
	float fConst64;
	float fConst65;
	float fRec21[3];
	float fConst66;
	float fConst67;
	float fConst68;
	float fRec22[3];
	float fConst69;
	float fConst70;
	float fConst71;
	float fRec23[3];
	float fConst72;
	float fConst73;
	float fConst74;
	float fRec24[3];
	float fConst75;
	float fConst76;
	float fConst77;
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
		for (l2 = 0; l2 < 2; l2 = l2 + 1) {
			dsp->iVec1[l2] = 0;
		}
	}
	/* C99 loop */
	{
		int l3;
		for (l3 = 0; l3 < 2; l3 = l3 + 1) {
			dsp->iRec3[l3] = 0;
		}
	}
	/* C99 loop */
	{
		int l4;
		for (l4 = 0; l4 < 2; l4 = l4 + 1) {
			dsp->fRec1[l4] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l5;
		for (l5 = 0; l5 < 2; l5 = l5 + 1) {
			dsp->iRec4[l5] = 0;
		}
	}
	/* C99 loop */
	{
		int l6;
		for (l6 = 0; l6 < 3; l6 = l6 + 1) {
			dsp->fRec6[l6] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l7;
		for (l7 = 0; l7 < 3; l7 = l7 + 1) {
			dsp->fRec5[l7] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l8;
		for (l8 = 0; l8 < 3; l8 = l8 + 1) {
			dsp->fRec0[l8] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l9;
		for (l9 = 0; l9 < 3; l9 = l9 + 1) {
			dsp->fRec7[l9] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l10;
		for (l10 = 0; l10 < 3; l10 = l10 + 1) {
			dsp->fRec8[l10] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l11;
		for (l11 = 0; l11 < 3; l11 = l11 + 1) {
			dsp->fRec9[l11] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l12;
		for (l12 = 0; l12 < 3; l12 = l12 + 1) {
			dsp->fRec10[l12] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l13;
		for (l13 = 0; l13 < 3; l13 = l13 + 1) {
			dsp->fRec11[l13] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l14;
		for (l14 = 0; l14 < 3; l14 = l14 + 1) {
			dsp->fRec12[l14] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l15;
		for (l15 = 0; l15 < 3; l15 = l15 + 1) {
			dsp->fRec13[l15] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l16;
		for (l16 = 0; l16 < 3; l16 = l16 + 1) {
			dsp->fRec14[l16] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l17;
		for (l17 = 0; l17 < 3; l17 = l17 + 1) {
			dsp->fRec15[l17] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l18;
		for (l18 = 0; l18 < 3; l18 = l18 + 1) {
			dsp->fRec16[l18] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l19;
		for (l19 = 0; l19 < 3; l19 = l19 + 1) {
			dsp->fRec17[l19] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l20;
		for (l20 = 0; l20 < 3; l20 = l20 + 1) {
			dsp->fRec18[l20] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l21;
		for (l21 = 0; l21 < 3; l21 = l21 + 1) {
			dsp->fRec19[l21] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l22;
		for (l22 = 0; l22 < 3; l22 = l22 + 1) {
			dsp->fRec20[l22] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l23;
		for (l23 = 0; l23 < 3; l23 = l23 + 1) {
			dsp->fRec21[l23] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l24;
		for (l24 = 0; l24 < 3; l24 = l24 + 1) {
			dsp->fRec22[l24] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l25;
		for (l25 = 0; l25 < 3; l25 = l25 + 1) {
			dsp->fRec23[l25] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l26;
		for (l26 = 0; l26 < 3; l26 = l26 + 1) {
			dsp->fRec24[l26] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l27;
		for (l27 = 0; l27 < 3; l27 = l27 + 1) {
			dsp->fRec25[l27] = 0.0f;
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
	dsp->fConst5 = 1.0f / fmaxf(1.0f, 0.001f * dsp->fConst0);
	dsp->fConst6 = tanf(25132.742f / dsp->fConst0);
	dsp->fConst7 = 2.0f * (1.0f - 1.0f / mydsp_faustpower2_f(dsp->fConst6));
	dsp->fConst8 = 1.0f / dsp->fConst6;
	dsp->fConst9 = (dsp->fConst8 + -1.4142135f) / dsp->fConst6 + 1.0f;
	dsp->fConst10 = (dsp->fConst8 + 1.4142135f) / dsp->fConst6 + 1.0f;
	dsp->fConst11 = 1.0f / dsp->fConst10;
	dsp->fConst12 = tanf(911.0619f / dsp->fConst0);
	dsp->fConst13 = mydsp_faustpower2_f(dsp->fConst12);
	dsp->fConst14 = 2.0f * (1.0f - 1.0f / dsp->fConst13);
	dsp->fConst15 = 1.0f / dsp->fConst12;
	dsp->fConst16 = (dsp->fConst15 + -1.4142135f) / dsp->fConst12 + 1.0f;
	dsp->fConst17 = (dsp->fConst15 + 1.4142135f) / dsp->fConst12 + 1.0f;
	dsp->fConst18 = 1.0f / dsp->fConst17;
	dsp->fConst19 = 1.0f / (dsp->fConst13 * dsp->fConst17);
	dsp->fConst20 = 0.7f / dsp->fConst10;
	dsp->fConst21 = powf(0.001f, 33.333332f / dsp->fConst0);
	dsp->fConst22 = mydsp_faustpower2_f(dsp->fConst21);
	dsp->fConst23 = 2.0f * dsp->fConst21;
	dsp->fConst24 = powf(0.001f, 16.666666f / dsp->fConst0);
	dsp->fConst25 = mydsp_faustpower2_f(dsp->fConst24);
	dsp->fConst26 = 2.0f * dsp->fConst24;
	dsp->fConst27 = powf(0.001f, 11.111111f / dsp->fConst0);
	dsp->fConst28 = mydsp_faustpower2_f(dsp->fConst27);
	dsp->fConst29 = 2.0f * dsp->fConst27;
	dsp->fConst30 = powf(0.001f, 8.333333f / dsp->fConst0);
	dsp->fConst31 = mydsp_faustpower2_f(dsp->fConst30);
	dsp->fConst32 = 2.0f * dsp->fConst30;
	dsp->fConst33 = powf(0.001f, 6.6666665f / dsp->fConst0);
	dsp->fConst34 = mydsp_faustpower2_f(dsp->fConst33);
	dsp->fConst35 = 2.0f * dsp->fConst33;
	dsp->fConst36 = powf(0.001f, 5.5555553f / dsp->fConst0);
	dsp->fConst37 = mydsp_faustpower2_f(dsp->fConst36);
	dsp->fConst38 = 2.0f * dsp->fConst36;
	dsp->fConst39 = powf(0.001f, 4.7619047f / dsp->fConst0);
	dsp->fConst40 = mydsp_faustpower2_f(dsp->fConst39);
	dsp->fConst41 = 2.0f * dsp->fConst39;
	dsp->fConst42 = powf(0.001f, 4.1666665f / dsp->fConst0);
	dsp->fConst43 = mydsp_faustpower2_f(dsp->fConst42);
	dsp->fConst44 = 2.0f * dsp->fConst42;
	dsp->fConst45 = powf(0.001f, 3.7037036f / dsp->fConst0);
	dsp->fConst46 = mydsp_faustpower2_f(dsp->fConst45);
	dsp->fConst47 = 2.0f * dsp->fConst45;
	dsp->fConst48 = powf(0.001f, 3.3333333f / dsp->fConst0);
	dsp->fConst49 = mydsp_faustpower2_f(dsp->fConst48);
	dsp->fConst50 = 2.0f * dsp->fConst48;
	dsp->fConst51 = powf(0.001f, 3.030303f / dsp->fConst0);
	dsp->fConst52 = mydsp_faustpower2_f(dsp->fConst51);
	dsp->fConst53 = 2.0f * dsp->fConst51;
	dsp->fConst54 = powf(0.001f, 2.7777777f / dsp->fConst0);
	dsp->fConst55 = mydsp_faustpower2_f(dsp->fConst54);
	dsp->fConst56 = 2.0f * dsp->fConst54;
	dsp->fConst57 = powf(0.001f, 2.5641026f / dsp->fConst0);
	dsp->fConst58 = mydsp_faustpower2_f(dsp->fConst57);
	dsp->fConst59 = 2.0f * dsp->fConst57;
	dsp->fConst60 = powf(0.001f, 2.3809524f / dsp->fConst0);
	dsp->fConst61 = mydsp_faustpower2_f(dsp->fConst60);
	dsp->fConst62 = 2.0f * dsp->fConst60;
	dsp->fConst63 = powf(0.001f, 2.2222223f / dsp->fConst0);
	dsp->fConst64 = mydsp_faustpower2_f(dsp->fConst63);
	dsp->fConst65 = 2.0f * dsp->fConst63;
	dsp->fConst66 = powf(0.001f, 2.0833333f / dsp->fConst0);
	dsp->fConst67 = mydsp_faustpower2_f(dsp->fConst66);
	dsp->fConst68 = 2.0f * dsp->fConst66;
	dsp->fConst69 = powf(0.001f, 1.9607843f / dsp->fConst0);
	dsp->fConst70 = mydsp_faustpower2_f(dsp->fConst69);
	dsp->fConst71 = 2.0f * dsp->fConst69;
	dsp->fConst72 = powf(0.001f, 1.8518518f / dsp->fConst0);
	dsp->fConst73 = mydsp_faustpower2_f(dsp->fConst72);
	dsp->fConst74 = 2.0f * dsp->fConst72;
	dsp->fConst75 = powf(0.001f, 1.754386f / dsp->fConst0);
	dsp->fConst76 = mydsp_faustpower2_f(dsp->fConst75);
	dsp->fConst77 = 2.0f * dsp->fConst75;
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
	/* C99 loop */
	{
		int i0;
		for (i0 = 0; i0 < count; i0 = i0 + 1) {
			dsp->iVec0[0] = 1;
			dsp->iRec2[0] = (dsp->iVec0[1] + dsp->iRec2[1]) % 10000;
			int iTemp0 = dsp->iRec2[0] < 1;
			dsp->iVec1[0] = iTemp0;
			dsp->iRec3[0] = 1103515245 * dsp->iRec3[1] + 12345;
			float fTemp1 = 4.656613e-10f * (float)(dsp->iRec3[0]);
			dsp->fRec1[0] = ((iTemp0) ? fabsf(fTemp1) : dsp->fRec1[1]);
			float fTemp2 = 4.4e+02f * dsp->fRec1[0];
			dsp->iRec4[0] = (dsp->iRec4[1] + (dsp->iRec4[1] > 0)) * (iTemp0 <= dsp->iVec1[1]) + (iTemp0 > dsp->iVec1[1]);
			float fTemp3 = dsp->fConst5 * (float)(dsp->iRec4[0]);
			dsp->fRec6[0] = fTemp1 - dsp->fConst18 * (dsp->fConst16 * dsp->fRec6[2] + dsp->fConst14 * dsp->fRec6[1]);
			dsp->fRec5[0] = dsp->fConst19 * (dsp->fRec6[2] + (dsp->fRec6[0] - 2.0f * dsp->fRec6[1])) - dsp->fConst11 * (dsp->fConst9 * dsp->fRec5[2] + dsp->fConst7 * dsp->fRec5[1]);
			float fTemp4 = dsp->fConst20 * (dsp->fRec5[2] + dsp->fRec5[0] + 2.0f * dsp->fRec5[1]) * fmaxf(0.0f, fminf(fTemp3, 2.0f - fTemp3));
			dsp->fRec0[0] = fTemp4 + dsp->fConst4 * dsp->fRec0[1] * cosf(dsp->fConst3 * (fTemp2 + 55.0f)) - dsp->fConst2 * dsp->fRec0[2];
			dsp->fRec7[0] = fTemp4 + dsp->fConst23 * dsp->fRec7[1] * cosf(dsp->fConst3 * (fTemp2 + 3855.0f)) - dsp->fConst22 * dsp->fRec7[2];
			dsp->fRec8[0] = fTemp4 + dsp->fConst26 * dsp->fRec8[1] * cosf(dsp->fConst3 * (fTemp2 + 3655.0f)) - dsp->fConst25 * dsp->fRec8[2];
			dsp->fRec9[0] = fTemp4 + dsp->fConst29 * dsp->fRec9[1] * cosf(dsp->fConst3 * (fTemp2 + 3455.0f)) - dsp->fConst28 * dsp->fRec9[2];
			dsp->fRec10[0] = fTemp4 + dsp->fConst32 * dsp->fRec10[1] * cosf(dsp->fConst3 * (fTemp2 + 3255.0f)) - dsp->fConst31 * dsp->fRec10[2];
			dsp->fRec11[0] = fTemp4 + dsp->fConst35 * dsp->fRec11[1] * cosf(dsp->fConst3 * (fTemp2 + 3055.0f)) - dsp->fConst34 * dsp->fRec11[2];
			dsp->fRec12[0] = fTemp4 + dsp->fConst38 * dsp->fRec12[1] * cosf(dsp->fConst3 * (fTemp2 + 2855.0f)) - dsp->fConst37 * dsp->fRec12[2];
			dsp->fRec13[0] = fTemp4 + dsp->fConst41 * dsp->fRec13[1] * cosf(dsp->fConst3 * (fTemp2 + 2655.0f)) - dsp->fConst40 * dsp->fRec13[2];
			dsp->fRec14[0] = fTemp4 + dsp->fConst44 * dsp->fRec14[1] * cosf(dsp->fConst3 * (fTemp2 + 2455.0f)) - dsp->fConst43 * dsp->fRec14[2];
			dsp->fRec15[0] = fTemp4 + dsp->fConst47 * dsp->fRec15[1] * cosf(dsp->fConst3 * (fTemp2 + 2255.0f)) - dsp->fConst46 * dsp->fRec15[2];
			dsp->fRec16[0] = fTemp4 + dsp->fConst50 * dsp->fRec16[1] * cosf(dsp->fConst3 * (fTemp2 + 2055.0f)) - dsp->fConst49 * dsp->fRec16[2];
			dsp->fRec17[0] = fTemp4 + dsp->fConst53 * dsp->fRec17[1] * cosf(dsp->fConst3 * (fTemp2 + 1855.0f)) - dsp->fConst52 * dsp->fRec17[2];
			dsp->fRec18[0] = fTemp4 + dsp->fConst56 * dsp->fRec18[1] * cosf(dsp->fConst3 * (fTemp2 + 1655.0f)) - dsp->fConst55 * dsp->fRec18[2];
			dsp->fRec19[0] = fTemp4 + dsp->fConst59 * dsp->fRec19[1] * cosf(dsp->fConst3 * (fTemp2 + 1455.0f)) - dsp->fConst58 * dsp->fRec19[2];
			dsp->fRec20[0] = fTemp4 + dsp->fConst62 * dsp->fRec20[1] * cosf(dsp->fConst3 * (fTemp2 + 1255.0f)) - dsp->fConst61 * dsp->fRec20[2];
			dsp->fRec21[0] = fTemp4 + dsp->fConst65 * dsp->fRec21[1] * cosf(dsp->fConst3 * (fTemp2 + 1055.0f)) - dsp->fConst64 * dsp->fRec21[2];
			dsp->fRec22[0] = fTemp4 + dsp->fConst68 * dsp->fRec22[1] * cosf(dsp->fConst3 * (fTemp2 + 855.0f)) - dsp->fConst67 * dsp->fRec22[2];
			dsp->fRec23[0] = fTemp4 + dsp->fConst71 * dsp->fRec23[1] * cosf(dsp->fConst3 * (fTemp2 + 655.0f)) - dsp->fConst70 * dsp->fRec23[2];
			dsp->fRec24[0] = fTemp4 + dsp->fConst74 * dsp->fRec24[1] * cosf(dsp->fConst3 * (fTemp2 + 455.0f)) - dsp->fConst73 * dsp->fRec24[2];
			dsp->fRec25[0] = fTemp4 + dsp->fConst77 * dsp->fRec25[1] * cosf(dsp->fConst3 * (fTemp2 + 255.0f)) - dsp->fConst76 * dsp->fRec25[2];
			float fTemp5 = 0.05f * (dsp->fRec0[0] + 0.25f * (dsp->fRec25[0] - dsp->fRec25[2]) + 0.11111111f * (dsp->fRec24[0] - dsp->fRec24[2]) + 0.0625f * (dsp->fRec23[0] - dsp->fRec23[2]) + 0.04f * (dsp->fRec22[0] - dsp->fRec22[2]) + 0.027777778f * (dsp->fRec21[0] - dsp->fRec21[2]) + 0.020408163f * (dsp->fRec20[0] - dsp->fRec20[2]) + 0.015625f * (dsp->fRec19[0] - dsp->fRec19[2]) + 0.012345679f * (dsp->fRec18[0] - dsp->fRec18[2]) + 0.01f * (dsp->fRec17[0] - dsp->fRec17[2]) + 0.008264462f * (dsp->fRec16[0] - dsp->fRec16[2]) + 0.0069444445f * (dsp->fRec15[0] - dsp->fRec15[2]) + 0.00591716f * (dsp->fRec14[0] - dsp->fRec14[2]) + 0.0051020407f * (dsp->fRec13[0] - dsp->fRec13[2]) + 0.0044444446f * (dsp->fRec12[0] - dsp->fRec12[2]) + 0.00390625f * (dsp->fRec11[0] - dsp->fRec11[2]) + 0.0034602077f * (dsp->fRec10[0] - dsp->fRec10[2]) + 0.0030864198f * (dsp->fRec9[0] - dsp->fRec9[2]) + 0.002770083f * (dsp->fRec8[0] - dsp->fRec8[2]) + 0.0025f * (dsp->fRec7[0] - dsp->fRec7[2]) - dsp->fRec0[2]);
			output0[i0] = (FAUSTFLOAT)(fTemp5);
			output1[i0] = (FAUSTFLOAT)(fTemp5);
			dsp->iVec0[1] = dsp->iVec0[0];
			dsp->iRec2[1] = dsp->iRec2[0];
			dsp->iVec1[1] = dsp->iVec1[0];
			dsp->iRec3[1] = dsp->iRec3[0];
			dsp->fRec1[1] = dsp->fRec1[0];
			dsp->iRec4[1] = dsp->iRec4[0];
			dsp->fRec6[2] = dsp->fRec6[1];
			dsp->fRec6[1] = dsp->fRec6[0];
			dsp->fRec5[2] = dsp->fRec5[1];
			dsp->fRec5[1] = dsp->fRec5[0];
			dsp->fRec0[2] = dsp->fRec0[1];
			dsp->fRec0[1] = dsp->fRec0[0];
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
