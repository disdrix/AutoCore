// =============================================================================
// FUN_007123d0
// -----------------------------------------------------------------------------
// Stable ID: aa_007123d0
// Address:   0x007123d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007123d0 @ 0x007123d0
// Stable ID: aa_007123d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×7, return×1.
//  - Notable callees: FUN_007123d0, FUN_007166f0.
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

uint FUN_007123d0(int *param_1)



{

  int iVar1;

  

  iVar1 = *param_1;

  if (iVar1 != 0) {

    if (*(int *)(iVar1 + 4) != 0) {

      (*(code *)PTR_free_00af8a4c)(*(int *)(iVar1 + 4));

      *(uint32_t /* width from decompiler */ *)(iVar1 + 4) = 0;

    }

    FUN_007166f0(iVar1);

    if (*(int *)(iVar1 + 0xc) != 0) {

      (*(code *)PTR_free_00af8a4c)(*(int *)(iVar1 + 0xc));

      *(uint32_t /* width from decompiler */ *)(iVar1 + 0xc) = 0;

    }

    if (*(int *)(iVar1 + 0x10) != 0) {

      (*(code *)PTR_free_00af8a4c)(*(int *)(iVar1 + 0x10));

      *(uint32_t /* width from decompiler */ *)(iVar1 + 0x10) = 0;

    }

    if (*(int *)(iVar1 + 0x14) != 0) {

      (*(code *)PTR_free_00af8a4c)(*(int *)(iVar1 + 0x14));

      *(uint32_t /* width from decompiler */ *)(iVar1 + 0x14) = 0;

    }

    if (*(int *)(iVar1 + 0x18) != 0) {

      (*(code *)PTR_free_00af8a4c)(*(int *)(iVar1 + 0x18));

      *(uint32_t /* width from decompiler */ *)(iVar1 + 0x18) = 0;

    }

    if (*(int *)(iVar1 + 8) != 0) {

      (*(code *)PTR_free_00af8a4c)(*(int *)(iVar1 + 8));

      *(uint32_t /* width from decompiler */ *)(iVar1 + 8) = 0;

    }

    param_1 = (int *)(*(code *)PTR_free_00af8a4c)(iVar1);

  }

  return (uint)param_1 & 0xffff0000;

}
