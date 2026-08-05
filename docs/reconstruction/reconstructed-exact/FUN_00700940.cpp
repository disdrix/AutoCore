// =============================================================================
// FUN_00700940
// -----------------------------------------------------------------------------
// Stable ID: aa_00700940
// Address:   0x00700940  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00700940 @ 0x00700940
// Stable ID: aa_00700940
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00700940.
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

void __thiscall FUN_00700940(float *param_1,uint32_t /* width from decompiler */ param_2,int param_3)



{

  float fVar1;

  float fVar2;

  float fVar3;

  

  (**(code **)(*(int *)param_1[0x10] + 0x30))(param_2,param_3);

  (**(code **)(*(int *)param_1[0x11] + 0x30))(&stack0xffffffd8,(float *)(param_3 + 0x10));

  fVar1 = *(float *)(param_3 + 0x10);

  fVar2 = *(float *)(param_3 + 0x14);

  fVar3 = *(float *)(param_3 + 0x18);

  *(float *)(param_3 + 0x20) =

       fVar1 * *param_1 + fVar3 * param_1[8] + fVar2 * param_1[4] + param_1[0xc];

  *(float *)(param_3 + 0x24) =

       fVar3 * param_1[9] + fVar2 * param_1[5] + fVar1 * param_1[1] + param_1[0xd];

  *(float *)(param_3 + 0x28) =

       fVar3 * param_1[10] + fVar2 * param_1[6] + fVar1 * param_1[2] + param_1[0xe];

  *(uint32_t /* width from decompiler */ *)(param_3 + 0x2c) = 0;

  return;

}
