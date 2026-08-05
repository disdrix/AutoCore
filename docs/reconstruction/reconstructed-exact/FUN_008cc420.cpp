// =============================================================================
// FUN_008cc420
// -----------------------------------------------------------------------------
// Stable ID: aa_008cc420
// Address:   0x008cc420  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008cc420 @ 0x008cc420
// Stable ID: aa_008cc420
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×9, goto×3, return×3, while×2, switch×1.
//  - Notable callees: FUN_00790020×3, FUN_008cc420.
//  - Return sites: 3.

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

void __thiscall FUN_008cc420(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  

  if (((-1 < DAT_00d1a980) && (DAT_00d1a980 < 0xc)) && ((&DAT_00d1b6dc)[DAT_00d1a980] != 0)) {

    switch(param_2) {

    case 0x25:

    case 0x26:

      iVar1 = DAT_00d1a980 + -1;

      if (iVar1 == DAT_00d1a980) goto LAB_008cc4dc;

      while( true ) {

        if (iVar1 < 0) {

          iVar1 = 0xb;

        }

        if ((&DAT_00d1b6dc)[iVar1] != 0) break;

        iVar1 = iVar1 + -1;

        if (iVar1 == DAT_00d1a980) {

          FUN_00790020(param_2,param_3);

          return;

        }

      }

      break;

    case 0x27:

    case 0x28:

      iVar1 = DAT_00d1a980 + 1;

      if (iVar1 == DAT_00d1a980) goto LAB_008cc4dc;

      while( true ) {

        if (0xb < iVar1) {

          iVar1 = 0;

        }

        if ((&DAT_00d1b6dc)[iVar1] != 0) break;

        iVar1 = iVar1 + 1;

        if (iVar1 == DAT_00d1a980) {

          FUN_00790020(param_2,param_3);

          return;

        }

      }

      break;

    default:

      goto LAB_008cc4dc;

    }

    (**(code **)(*param_1 + 0x338))(8,iVar1 + 0x9c47);

  }

LAB_008cc4dc:

  FUN_00790020(param_2,param_3);

  return;

}
