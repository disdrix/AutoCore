// =============================================================================
// FUN_00915ad0
// -----------------------------------------------------------------------------
// Stable ID: aa_00915ad0
// Address:   0x00915ad0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00915ad0 @ 0x00915ad0
// Stable ID: aa_00915ad0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00915ad0, SQRT, fcos, fsin.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall

FUN_00915ad0(uint32_t /* width from decompiler */ param_1,float *param_2,int param_3,float *param_4,int param_5)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  int iVar10;

  float *in_EAX;

  float *unaff_ESI;

  float *unaff_EDI;

  float10 fVar11;

  float10 fVar12;

  

  iVar10 = *(int *)(param_3 + 0x2a4);

  fVar1 = *(float *)(iVar10 + 0xf0);

  fVar2 = param_2[1];

  fVar3 = param_2[2];

  fVar4 = unaff_EDI[1];

  fVar5 = unaff_ESI[2];

  fVar11 = SQRT((float10)*(float *)(iVar10 + 0xfc) * (float10)*(float *)(iVar10 + 0xfc) +

                (float10)*(float *)(iVar10 + 0xf8) * (float10)*(float *)(iVar10 + 0xf8) +

                (float10)*(float *)(iVar10 + 0xf0) * (float10)*(float *)(iVar10 + 0xf0));

  fVar12 = (float10)fcos((float10)param_5 * (float10)DAT_00aaa95c);

  fVar8 = (float)(fVar12 * fVar11);

  fVar12 = (float10)fsin((float10)param_5 * (float10)DAT_00aaa95c);

  fVar9 = (float)(fVar12 * fVar11);

  fVar6 = unaff_EDI[2];

  fVar7 = unaff_ESI[1];

  *in_EAX = *unaff_ESI * fVar8 + *unaff_EDI * fVar9 + *param_2 * fVar1;

  in_EAX[1] = fVar7 * fVar8 + fVar4 * fVar9 + fVar2 * fVar1;

  in_EAX[2] = fVar5 * fVar8 + fVar6 * fVar9 + fVar3 * fVar1;

  *in_EAX = *param_4 + *in_EAX;

  in_EAX[1] = param_4[1] + in_EAX[1];

  in_EAX[2] = param_4[2] + in_EAX[2];

  return;

}
