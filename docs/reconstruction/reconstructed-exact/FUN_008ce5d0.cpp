// =============================================================================
// FUN_008ce5d0
// -----------------------------------------------------------------------------
// Stable ID: aa_008ce5d0
// Address:   0x008ce5d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008ce5d0 @ 0x008ce5d0
// Stable ID: aa_008ce5d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, goto×1, while×1, return×1.
//  - Notable callees: FUN_00792250, FUN_008cc5a0, FUN_008cd070, FUN_008cd200, FUN_008ce5d0, FUN_008d80c0, FUN_009100f0.
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

void __thiscall FUN_008ce5d0(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  byte bVar1;

  int *piVar2;

  

  if ((char)param_2 == '\0') {

    FUN_008d80c0(param_1);

  }

  FUN_00792250(param_2,param_3);

  DAT_00d1a8f7 = 1;

  if ((char)param_2 != '\0') {

    FUN_008cc5a0();

    if (DAT_00d1b77c != 0) {

      (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b77c + 0xaf0) + 4) + 4) + 4 +

                           *(int *)(DAT_00d1b77c + 0xaf0)) + 0x1cc))();

      FUN_009100f0();

    }

    FUN_008cd200(param_1);

    FUN_008cd070();

    (**(code **)(*param_1 + 0x444))();

    piVar2 = &DAT_00d1b6dc;

    do {

      if (*piVar2 != 0) {

        bVar1 = 1;

        goto LAB_008ce663;

      }

      piVar2 = piVar2 + 1;

    } while ((int)piVar2 < 0xd1b70c);

    bVar1 = 0;

LAB_008ce663:

    param_1[0x126] = (-(uint)bVar1 & 5) + 40000;

  }

  return;

}
