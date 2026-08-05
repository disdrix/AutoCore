// =============================================================================
// FUN_00841ee0
// -----------------------------------------------------------------------------
// Stable ID: aa_00841ee0
// Address:   0x00841ee0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00841ee0 @ 0x00841ee0
// Stable ID: aa_00841ee0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00791f30×2, FUN_00840ac0, FUN_00841ee0.
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

void __thiscall FUN_00841ee0(int *param_1,float param_2)



{

  float fVar1;

  

  if ((char)param_1[0x13f] == '\0') {

    if (*(char *)((int)param_1 + 0x4fd) != DAT_00d1bdfa) {

      (**(code **)(*param_1 + 0x444))();

    }

  }

  else {

    fVar1 = (float)param_1[0x140];

    param_1[0x140] = (int)(param_2 + fVar1);

    if ((float)param_1[0x141] <= param_2 + fVar1) {

      FUN_00840ac0();

      param_1[0x140] = 0;

      FUN_00791f30(param_2);

      return;

    }

  }

  FUN_00791f30(param_2);

  return;

}
