// =============================================================================
// Named_CalleeOf_Drive_CVOGVehicle_UpdateWaterFX_005a74f0
// -----------------------------------------------------------------------------
// Stable ID: aa_005a74f0
// Callee of Drive_CVOGVehicle_UpdateWaterFX
// Address:   0x005a74f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_CVOGVehicle_UpdateWaterFX: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0048fb10, FUN_005a74f0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Drive_CVOGVehicle_UpdateWaterFX
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Drive_CVOGVehicle_UpdateWaterFX_005a74f0(int param_1,char param_2)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  float fStack_18;

  float fStack_14;

  float fStack_10;

  float fStack_c;

  float fStack_8;

  float fStack_4;

  

  if ((((*(int *)(param_1 + 0xe8) != 0) && (-1 < param_2)) && (param_2 < *(char *)(param_1 + 0xb0)))

     && (piVar1 = (int *)(*(int *)(param_1 + 0xe8) + param_2 * 0x14c), piVar1 != (int *)0x0)) {

    iVar2 = (**(code **)(*piVar1 + 0xc))();

    iVar3 = (**(code **)(*piVar1 + 0x48))();

    fStack_4 = *(float *)(iVar3 + 0x1c) + *(float *)(iVar2 + 0x98);

    fStack_8 = *(float *)(iVar3 + 0x18) + *(float *)(iVar2 + 0x94);

    fStack_c = *(float *)(iVar2 + 0x90) + *(float *)(iVar3 + 0x14);

    iVar3 = (**(code **)(*piVar1 + 0x48))();

    fStack_10 = *(float *)(iVar3 + 0x28) + *(float *)(iVar2 + 0x98);

    fStack_14 = *(float *)(iVar3 + 0x24) + *(float *)(iVar2 + 0x94);

    fStack_18 = *(float *)(iVar3 + 0x20) + *(float *)(iVar2 + 0x90);

    uVar4 = FUN_0048fb10(&fStack_c,&fStack_18);

    return uVar4;

  }

  return 0xffffffff;

}
