// =============================================================================
// FUN_006053a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006053a0
// Address:   0x006053a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006053a0 @ 0x006053a0
// Stable ID: aa_006053a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004e88e0, FUN_006053a0.
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

void __thiscall FUN_006053a0(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  puVar2 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x84 + param_1);

  *puVar2 = *param_2;

  puVar2[1] = param_2[1];

  puVar2[2] = param_2[2];

  puVar2[3] = param_2[3];

  if (*(int **)(param_1 + 8) != (int *)0x0) {

    iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x10))(3);

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0xbc) = 0xffffffff;

    *(int *)(iVar1 + 0xb4) = *(int *)(iVar1 + 0xb4) + 1;

    puVar2 = (uint32_t /* width from decompiler */ *)

             FUN_004e88e0(&stack0xfffffff0,*(int *)(*(int *)(param_1 + 4) + 4) + 0x84 + param_1);

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x90) = *puVar2;

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x94) = puVar2[1];

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x98) = puVar2[2];

  }

  return;

}
