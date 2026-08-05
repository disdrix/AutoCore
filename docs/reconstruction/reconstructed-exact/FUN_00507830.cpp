// =============================================================================
// FUN_00507830
// -----------------------------------------------------------------------------
// Stable ID: aa_00507830
// Address:   0x00507830  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00507830 @ 0x00507830
// Stable ID: aa_00507830
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00507830, FUN_005081f0, FUN_0055df40.
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

void __fastcall FUN_00507830(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  iVar1 = *(int *)(param_1 + 0x24);

  if ((((iVar1 != 0) && (*(int *)(param_1 + 0x18) != 0)) &&

      (*(int *)(*(int *)(param_1 + 0x28) + 8) != 0)) && (*(int *)(iVar1 + 0x10) != 0)) {

    FUN_0055df40(iVar1);

    puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x24);

    *(short *)((int)puVar2 + 6) = *(short *)((int)puVar2 + 6) + -1;

    if (*(short *)((int)puVar2 + 6) == 0) {

      (**(code **)*puVar2)(1);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 0;

    *(uint8_t *)(*(int *)(param_1 + 0x28) + 0x102) = 0;

  }

  FUN_005081f0();

  return;

}
