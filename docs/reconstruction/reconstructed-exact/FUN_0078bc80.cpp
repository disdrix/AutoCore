// =============================================================================
// FUN_0078bc80
// -----------------------------------------------------------------------------
// Stable ID: aa_0078bc80
// Address:   0x0078bc80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0078bc80 @ 0x0078bc80
// Stable ID: aa_0078bc80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0076df50, FUN_0076f5f0, FUN_0078bc80, fcos, fsin.
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

void __thiscall FUN_0078bc80(int param_1,float param_2)



{

  int iVar1;

  int *extraout_EDX;

  float10 fVar2;

  float unaff_retaddr;

  float local_1c;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  if ((*(int *)(param_1 + 8) != 0) && (param_2 != g_flZero)) {

    FUN_0076f5f0(&local_1c,param_1 + 0x18);

    fVar2 = (float10)fsin((float10)param_2 * (float10)DAT_00a0f298);

    local_10 = (float)((float10)local_1c * fVar2);

    local_c = (float)((float10)local_18 * fVar2);

    local_8 = (float)((float10)local_14 * fVar2);

    fVar2 = (float10)fcos((float10)param_2 * (float10)DAT_00a0f298);

    local_4 = (float)fVar2;

    iVar1 = (**(code **)(*extraout_EDX + 0x10))(3);

    FUN_0076df50(iVar1 + 0x80,iVar1 + 0x80,&local_14);

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0xbc) = 0xffffffff;

    *(int *)(iVar1 + 0xb4) = *(int *)(iVar1 + 0xb4) + 1;

    *(float *)(param_1 + 0x14) = unaff_retaddr + *(float *)(param_1 + 0x14);

  }

  return;

}
