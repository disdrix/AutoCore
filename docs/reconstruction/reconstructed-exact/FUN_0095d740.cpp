// =============================================================================
// FUN_0095d740
// -----------------------------------------------------------------------------
// Stable ID: aa_0095d740
// Address:   0x0095d740  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0095d740 @ 0x0095d740
// Stable ID: aa_0095d740
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: for×2, if×2, return×1.
//  - Notable callees: FUN_0095d740.
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

void FUN_0095d740(void)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  int *piVar4;

  int unaff_ESI;

  

  piVar3 = DAT_00d1ef94;

  piVar1 = DAT_00d1ef84;

  for (piVar4 = DAT_00d1ef90; DAT_00d1ef84 = piVar1, piVar2 = DAT_00d1ef80, piVar4 != piVar3;

      piVar4 = piVar4 + 2) {

    if (piVar4[1] != -1) {

      *(uint32_t /* width from decompiler */ *)(*piVar4 + 0x58) =

           *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(*(int *)(unaff_ESI + 0xc) + piVar4[1] * 4) + 0xf4) + 8)

      ;

    }

    piVar1 = DAT_00d1ef84;

  }

  for (; piVar2 != piVar1; piVar2 = piVar2 + 2) {

    if (piVar2[1] != -1) {

      *(uint32_t /* width from decompiler */ *)(*piVar2 + 0x58) =

           *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(*(int *)(unaff_ESI + 0xc) + piVar2[1] * 4) + 0xf4) + 8)

      ;

    }

  }

  return;

}
