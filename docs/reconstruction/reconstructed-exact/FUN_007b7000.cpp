// =============================================================================
// FUN_007b7000
// -----------------------------------------------------------------------------
// Stable ID: aa_007b7000
// Address:   0x007b7000  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007b7000 @ 0x007b7000
// Stable ID: aa_007b7000
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_0076c330×2, FUN_0075de80, FUN_007b7000, FUN_00970e50.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_007b7000(uint32_t /* width from decompiler */ param_1,char param_2)



{

  float10 fVar1;

  

  if ((_DAT_00d20d90 & 1) == 0) {

    _DAT_00d20d90 = _DAT_00d20d90 | 1;

    fVar1 = (float10)FUN_0076c330(param_1);

    _DAT_00d20d8c = (float)fVar1;

  }

  fVar1 = (float10)FUN_0076c330(param_1);

  if ((float10)DAT_00aaa688 < fVar1 - (float10)_DAT_00d20d8c) {

    _DAT_00d20d8c = (float)fVar1;

    FUN_0075de80(2,0x43340000);

    if ((DAT_00d1793d != '\0') || (param_2 != '\0')) {

      if ((*(int *)(DAT_00d1f050 + 0x6c) != 0) && ((DAT_00d1f200 != '\0' || (param_2 != '\0')))) {

        FUN_00970e50(*(int *)(DAT_00d1f050 + 0x6c),0x43960000);

      }

      DAT_00d1f200 = DAT_00d1f200 == '\0';

    }

  }

  return;

}
