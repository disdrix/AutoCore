// =============================================================================
// FUN_005d4c20
// -----------------------------------------------------------------------------
// Stable ID: aa_005d4c20
// Address:   0x005d4c20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d4c20 @ 0x005d4c20
// Stable ID: aa_005d4c20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_004e8860, FUN_004e8910, FUN_005d4c20.
//  - Return sites: 2.

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

void __fastcall FUN_005d4c20(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  

  if (*(int *)(param_1 + -0xd8) != 0) {

    iVar2 = *(int *)(*(int *)(param_1 + -0xd8) + 0x3c);

    puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0x5c + param_1);

    *puVar1 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0xb0);

    puVar1[1] = *(uint32_t /* width from decompiler */ *)(iVar2 + 0xb4);

    puVar1[2] = *(uint32_t /* width from decompiler */ *)(iVar2 + 0xb8);

    puVar1[3] = *(uint32_t /* width from decompiler */ *)(iVar2 + 0xbc);

    iVar2 = *(int *)(*(int *)(param_1 + -0xd8) + 0x3c);

    puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0x4c + param_1);

    *puVar1 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x30);

    puVar1[1] = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x34);

    puVar1[2] = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x38);

    puVar1[3] = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x3c);

    return;

  }

  if (*(int **)(param_1 + -0x98) != (int *)0x0) {

    iVar2 = (**(code **)(**(int **)(param_1 + -0x98) + 0xc))();

    FUN_004e8910(iVar2 + 0x90,*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0x5c + param_1);

    iVar2 = (**(code **)(**(int **)(param_1 + -0x98) + 0xc))();

    FUN_004e8860(iVar2 + 0x80,*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0x4c + param_1);

  }

  return;

}
