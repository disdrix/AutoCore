// =============================================================================
// FUN_007afe20
// -----------------------------------------------------------------------------
// Stable ID: aa_007afe20
// Address:   0x007afe20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007afe20 @ 0x007afe20
// Stable ID: aa_007afe20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_007560a0, FUN_007afe20.
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

void __fastcall FUN_007afe20(int *param_1)



{

  int iVar1;

  

  if ((param_1[0xaa] != 0) && (param_1[0xa6] != 0)) {

    iVar1 = (**(code **)(*param_1 + 0x1a0))();

    if ((iVar1 != 0) && ((char)param_1[0x2e] == '\0')) {

      FUN_007560a0();

      if ((uint32_t /* width from decompiler */ *)param_1[0xad] != (uint32_t /* width from decompiler */ *)0x0) {

        (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0xad])(param_1[0xa6]);

      }

      *(uint8_t *)(param_1 + 0x2e) = 1;

    }

  }

  return;

}
