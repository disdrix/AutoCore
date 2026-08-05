// =============================================================================
// FUN_0072b630
// -----------------------------------------------------------------------------
// Stable ID: aa_0072b630
// Address:   0x0072b630  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0072b630 @ 0x0072b630
// Stable ID: aa_0072b630
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_0046cfb0, FUN_0072b630.
//  - Return sites: 3.

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

void __fastcall FUN_0072b630(int param_1)



{

  void *pvVar1;

  

  *(uint8_t *)(param_1 + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  operator_delete__(*(void **)(param_1 + 0x18));

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;

  operator_delete__(*(void **)(param_1 + 0x14));

  pvVar1 = *(void **)(param_1 + 0x2c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

  if (pvVar1 != (void *)0x0) {

    FUN_0046cfb0(pvVar1);

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0;

  if (*(void **)(param_1 + 0x20) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x20));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = 0;

  return;

}
