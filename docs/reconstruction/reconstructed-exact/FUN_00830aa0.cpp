// =============================================================================
// FUN_00830aa0
// -----------------------------------------------------------------------------
// Stable ID: aa_00830aa0
// Address:   0x00830aa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00830aa0 @ 0x00830aa0
// Stable ID: aa_00830aa0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×7, return×4, goto×1.
//  - Notable callees: FUN_0090d400×3, FUN_0082c780, FUN_00830aa0, FUN_00937470, FUN_0093a8e0, FUN_0093a910.
//  - Return sites: 4.

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

uint32_t /* width from decompiler */ FUN_00830aa0(int param_1,int param_2)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  if (param_2 == 0x11171) {

    if (param_1 == 8) {

      FUN_0093a910();

LAB_00830b4a:

      FUN_0090d400();

      return 1;

    }

  }

  else if (param_2 == 0x11172) {

    if (param_1 == 8) {

      FUN_00937470();

      if (DAT_00d1b8c0 != (int *)0x0) {

        cVar1 = (**(code **)(*DAT_00d1b8c0 + 0x3d8))();

        if (cVar1 != '\0') {

          (**(code **)(*DAT_00d1b8c0 + 0x338))(0xe,0xffffffff);

          FUN_0090d400();

          return 1;

        }

      }

      goto LAB_00830b4a;

    }

  }

  else if ((param_2 == 0x11173) && (param_1 == 8)) {

    FUN_0093a8e0();

    FUN_0090d400();

    return 1;

  }

  uVar2 = FUN_0082c780(param_1,param_2);

  return uVar2;

}
