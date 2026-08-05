// =============================================================================
// FUN_00829fa0
// -----------------------------------------------------------------------------
// Stable ID: aa_00829fa0
// Address:   0x00829fa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00829fa0 @ 0x00829fa0
// Stable ID: aa_00829fa0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_00829fa0, FUN_0092fd90.
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

void FUN_00829fa0(void)



{

  int iVar1;

  int iVar2;

  int *unaff_ESI;

  

  if ((unaff_ESI[0x141] != 0) && (*(int *)(unaff_ESI[0x141] + 0x14c) != 0)) {

    if (unaff_ESI[0x149] != 0) {

      iVar2 = unaff_ESI[0xac];

      if ((iVar2 == 0) ||

         (iVar1 = (**(code **)(*unaff_ESI + 0x78))(), *(int *)(iVar2 + 0x518) != iVar1)) {

        (**(code **)(*(int *)unaff_ESI[0x149] + 0x3c8))(0,1);

      }

      else {

        (**(code **)(*(int *)unaff_ESI[0x149] + 0x3c8))(1,1);

      }

    }

    if (unaff_ESI[0x14a] != 0) {

      iVar2 = FUN_0092fd90();

      if (iVar2 == **(int **)(unaff_ESI[0x141] + 0x14c)) {

        (**(code **)(*(int *)unaff_ESI[0x14a] + 0x3c8))(1);

        return;

      }

      (**(code **)(*(int *)unaff_ESI[0x14a] + 0x3c8))(0,1);

    }

  }

  return;

}
