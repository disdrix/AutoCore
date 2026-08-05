// =============================================================================
// FUN_004a6790
// -----------------------------------------------------------------------------
// Stable ID: aa_004a6790
// Address:   0x004a6790  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004a6790 @ 0x004a6790
// Stable ID: aa_004a6790
// Embedded strings (evidence for future rename):
//   - "system_LightningEmitter"
//   - "system_BrickDestruction"
//   - "system_ConcreteDestruction"
//   - "system_GlassDestruction"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_004a6670×4, FUN_004a6790, FUN_004b85d0, FUN_004b99c0.
//  - Strings: "system_LightningEmitter"; "system_BrickDestruction"; "system_ConcreteDestruction"; "system_GlassDestruction".
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_004a6790(void)



{

  void *pvVar1;

  int *piVar2;

  

  if (DAT_00b035fc != 0) {

    piVar2 = &DAT_00b035e4;

    do {

      if (*piVar2 != 0) {

        FUN_004b85d0();

        pvVar1 = (void *)*piVar2;

        if (pvVar1 != (void *)0x0) {

          FUN_004b99c0();

                    /* WARNING: Subroutine does not return */

          operator_delete(pvVar1);

        }

        *piVar2 = 0;

      }

      piVar2 = piVar2 + 1;

    } while ((int)piVar2 < 0xb035fc);

    DAT_00b035e4 = FUN_004a6670("system_LightningEmitter");

    DAT_00b035e8 = FUN_004a6670("system_BrickDestruction");

    _DAT_00b035ec = FUN_004a6670("system_ConcreteDestruction");

    _DAT_00b035f0 = FUN_004a6670("system_GlassDestruction");

  }

  return;

}
