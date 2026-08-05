// =============================================================================
// FUN_00582b00
// -----------------------------------------------------------------------------
// Stable ID: aa_00582b00
// Address:   0x00582b00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00582b00 @ 0x00582b00
// Stable ID: aa_00582b00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_004a2670, FUN_00581730, FUN_00582570, FUN_00582b00.
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

void __fastcall FUN_00582b00(int param_1)



{

  void *pvVar1;

  

  FUN_00581730(1);

  (**(code **)(*(int *)(param_1 + -0x90) + 4))();

  FUN_00582570();

  if (*(void **)(param_1 + -0x74) != (void *)0x0) {

    operator_delete__(*(void **)(param_1 + -0x74));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x74) = 0;

  if (*(void **)(param_1 + -0x78) != (void *)0x0) {

    operator_delete__(*(void **)(param_1 + -0x78));

  }

  pvVar1 = *(void **)(param_1 + -0x7c);

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x78) = 0;

  if (pvVar1 != (void *)0x0) {

    FUN_004a2670();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x7c) = 0;

  return;

}
