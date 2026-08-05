// =============================================================================
// FUN_005dec40
// -----------------------------------------------------------------------------
// Stable ID: aa_005dec40
// Address:   0x005dec40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005dec40 @ 0x005dec40
// Stable ID: aa_005dec40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: return×2, while×1, if×1.
//  - Notable callees: FUN_005dec40.
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

uint32_t /* width from decompiler */ * __thiscall FUN_005dec40(uint32_t /* width from decompiler */ *param_1,byte param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  iVar1 = param_1[6];

  *param_1 = &PTR_LAB_009db9e0;

  while (iVar1 != 0) {

    puVar2 = (uint32_t /* width from decompiler */ *)param_1[6];

    param_1[6] = *puVar2;

    (*(code *)PTR__aligned_free_00af3bd0)(puVar2);

    iVar1 = param_1[6];

  }

  *param_1 = &PTR_LAB_009db9b4;

  if ((param_2 & 1) == 0) {

    return param_1;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(param_1);

}
