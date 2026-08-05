// =============================================================================
// FUN_00576790
// -----------------------------------------------------------------------------
// Stable ID: aa_00576790
// Address:   0x00576790  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00576790 @ 0x00576790
// Stable ID: aa_00576790
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00576790, FUN_00756be0.
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

void __fastcall FUN_00576790(int param_1)



{

  int iVar1;

  

  if (*(int *)(param_1 + 0x1c) != 0) {

    iVar1 = FUN_00756be0(*(int *)(param_1 + 0x1c));

    if (-1 < iVar1) {

      if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x1c) != (uint32_t /* width from decompiler */ *)0x0) {

        (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x1c))(1);

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0;

    }

  }

  return;

}
