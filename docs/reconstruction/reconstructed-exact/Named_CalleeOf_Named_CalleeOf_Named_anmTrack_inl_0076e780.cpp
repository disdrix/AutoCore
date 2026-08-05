// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_anmTrack_inl_0076e780
// -----------------------------------------------------------------------------
// Stable ID: aa_0076e780
// Callee of Named_CalleeOf_Named_anmTrack_inl
// Address:   0x0076e780  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_anmTrack_inl: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: if×4, goto×1, return×1.
//  - Notable callees: ABS×5, fsin×3, FUN_0076e780, _CIacos.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_anmTrack_inl
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void Named_CalleeOf_Named_CalleeOf_Named_anmTrack_inl_0076e780(float param_1)



{

  float *in_EAX;

  float *pfVar1;

  float *unaff_ESI;

  float *unaff_EDI;

  float10 fVar2;

  float10 fVar3;

  float10 fVar4;

  float fVar5;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  local_20 = *unaff_ESI * *in_EAX + in_EAX[3] * unaff_ESI[3] + in_EAX[2] * unaff_ESI[2] +

             in_EAX[1] * unaff_ESI[1];

  if (0.0 <= local_20) {

    local_10 = *in_EAX;

    local_c = in_EAX[1];

    local_8 = in_EAX[2];

    local_4 = in_EAX[3];

  }

  else {

    local_20 = 0.0 - local_20;

    local_10 = 0.0 - *in_EAX;

    local_c = 0.0 - in_EAX[1];

    local_8 = 0.0 - in_EAX[2];

    local_4 = 0.0 - in_EAX[3];

  }

  local_14 = ABS(local_20 - g_flOne);

  if (_DAT_00a240ec < local_14) {

    pfVar1 = &local_1c;

    local_18 = ABS((float)_DAT_00aaa5f8);

    local_1c = ABS(local_20);

    if (ABS(local_20) <= ABS((float)_DAT_00aaa5f8)) {

      pfVar1 = &local_18;

    }

    if (*pfVar1 * _DAT_00a240ec < local_14) {

      fVar2 = (float10)_CIacos();

      fVar3 = (float10)fsin(fVar2);

      fVar4 = (float10)fsin(((float10)g_flOne - (float10)param_1) * fVar2);

      fVar5 = (float)(fVar4 * ((float10)g_flOne / fVar3));

      fVar2 = (float10)fsin(fVar2 * (float10)param_1);

      param_1 = (float)(fVar2 * ((float10)g_flOne / fVar3));

      goto LAB_0076e900;

    }

  }

  fVar5 = g_flOne - param_1;

LAB_0076e900:

  *unaff_EDI = *unaff_ESI * fVar5 + param_1 * local_10;

  unaff_EDI[1] = unaff_ESI[1] * fVar5 + param_1 * local_c;

  unaff_EDI[2] = param_1 * local_8 + fVar5 * unaff_ESI[2];

  unaff_EDI[3] = param_1 * local_4 + fVar5 * unaff_ESI[3];

  return;

}
