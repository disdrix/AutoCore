// =============================================================================
// FUN_005cb150
// -----------------------------------------------------------------------------
// Stable ID: aa_005cb150
// Address:   0x005cb150  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005cb150 @ 0x005cb150
// Stable ID: aa_005cb150
// Embedded strings (evidence for future rename):
//   - "*****************************Clearing Gadgets\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_005cb150, FUN_007a4480.
//  - Strings: "*****************************Clearing Gadgets\n".
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

void __fastcall FUN_005cb150(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + -0x40);

  if (iVar1 != 0) {

    if (*(void **)(iVar1 + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(*(void **)(iVar1 + 4));

    }

    *(uint32_t /* width from decompiler */ *)(iVar1 + 4) = 0;

    *(uint32_t /* width from decompiler */ *)(iVar1 + 8) = 0;

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0xc) = 0;

  }

  FUN_007a4480(0xffffffff,"*****************************Clearing Gadgets\n");

  return;

}
