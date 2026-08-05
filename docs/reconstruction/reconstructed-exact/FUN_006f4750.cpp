// =============================================================================
// FUN_006f4750
// -----------------------------------------------------------------------------
// Stable ID: aa_006f4750
// Address:   0x006f4750  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f4750 @ 0x006f4750
// Stable ID: aa_006f4750
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, return×1.
//  - Notable callees: FUN_006f3d20, FUN_006f4170, FUN_006f4750.
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

uint32_t /* width from decompiler */ * __thiscall FUN_006f4750(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ *param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x18);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = *puVar1;

  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + -1;

  FUN_006f3d20();

  *puVar1 = param_2;

  *(uint8_t *)(puVar1 + 1) = 1;

  puVar1[0x2e] = *param_3;

  FUN_006f4170(param_3,puVar1);

  iVar2 = 0;

  puVar3 = puVar1 + 3;

  do {

    (**(code **)(**(int **)(param_1 + 0x28) + 0x10))

              (*(int *)(param_1 + 0x34) + iVar2,*param_3,param_3[1],puVar3,puVar3 + 1);

    iVar2 = iVar2 + 0x20;

    puVar3 = puVar3 + 2;

  } while (iVar2 < 0x60);

  return puVar1;

}
