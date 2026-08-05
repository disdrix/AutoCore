// =============================================================================
// FUN_007a60e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007a60e0
// Address:   0x007a60e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a60e0 @ 0x007a60e0
// Stable ID: aa_007a60e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: return×2, for×1, if×1.
//  - Notable callees: FUN_00456780, FUN_007a60e0.
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

void __fastcall FUN_007a60e0(int param_1)



{

  void *pvVar1;

  uint uVar2;

  

  for (uVar2 = 0;

      (*(int *)(param_1 + 0x18) != 0 &&

      (uVar2 < (uint)(*(int *)(param_1 + 0x1c) - *(int *)(param_1 + 0x18) >> 2))); uVar2 = uVar2 + 1

      ) {

    pvVar1 = *(void **)(*(int *)(param_1 + 0x18) + uVar2 * 4);

    if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

  }

  FUN_00456780(0);

  *(uint16_t *)(param_1 + 0x24) = 0;

  *(uint16_t *)(param_1 + 0x26) = 0;

  return;

}
