// =============================================================================
// FUN_00426ed0
// -----------------------------------------------------------------------------
// Stable ID: aa_00426ed0
// Address:   0x00426ed0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00426ed0 @ 0x00426ed0
// Stable ID: aa_00426ed0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, while×1.
//  - Notable callees: FUN_00426ed0, FUN_00426f20.
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

void FUN_00426ed0(int param_1)



{

  int in_EAX;

  

  while( true ) {

    if (in_EAX == param_1) {

      return;

    }

    if (*(int *)(in_EAX + 4) != 0) break;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 4) = 0;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = 0;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc) = 0;

    in_EAX = in_EAX + 0x10;

  }

  FUN_00426f20(param_1);

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(in_EAX + 4));

}
