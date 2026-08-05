// =============================================================================
// FUN_005552c0
// -----------------------------------------------------------------------------
// Stable ID: aa_005552c0
// Address:   0x005552c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005552c0 @ 0x005552c0
// Stable ID: aa_005552c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: for×2, if×1, return×1.
//  - Notable callees: FUN_005552c0, FUN_005b3370.
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

void __thiscall FUN_005552c0(int param_1,float param_2,uint32_t /* width from decompiler */ *param_3)



{

  uint uVar1;

  uint uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ local_b8 [42];

  float local_10;

  

  uVar1 = *(uint *)(param_1 + 0x1d0);

  uVar2 = *(uint *)(param_1 + 0x1cc);

  puVar4 = local_b8;

  for (iVar3 = 0x2a; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar4 = *param_3;

    param_3 = param_3 + 1;

    puVar4 = puVar4 + 1;

  }

  local_10 = param_2;

  if (uVar2 == (uVar1 & 0x7fffffff)) {

    FUN_005b3370((int *)(param_1 + 0x1c8),0xac);

  }

  puVar4 = local_b8;

  puVar5 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x1c8) + *(int *)(param_1 + 0x1cc) * 0xac);

  for (iVar3 = 0x2b; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar5 = *puVar4;

    puVar4 = puVar4 + 1;

    puVar5 = puVar5 + 1;

  }

  *(int *)(param_1 + 0x1cc) = *(int *)(param_1 + 0x1cc) + 1;

  *(float *)(param_1 + 0x1c4) = *(float *)(param_1 + 0x1c4) + param_2;

  return;

}
