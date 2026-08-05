// =============================================================================
// FUN_008a21e0
// -----------------------------------------------------------------------------
// Stable ID: aa_008a21e0
// Address:   0x008a21e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008a21e0 @ 0x008a21e0
// Stable ID: aa_008a21e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×6, do×2, while×2, return×1.
//  - Notable callees: FUN_008a21e0.
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

void FUN_008a21e0(void)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  int *unaff_ESI;

  

  if (unaff_ESI[0x169] == 0) {

    iVar4 = 0;

  }

  else {

    iVar4 = unaff_ESI[0x16a] - unaff_ESI[0x169] >> 2;

  }

  iVar3 = 0;

  if (0 < iVar4) {

    do {

      piVar2 = (int *)(unaff_ESI[0x169] + iVar3 * 4);

      if (*piVar2 != 0) {

        (**(code **)(*(int *)*piVar2 + 0x440))();

        (**(code **)(*unaff_ESI + 0xb0))(*(uint32_t /* width from decompiler */ *)(unaff_ESI[0x169] + iVar3 * 4));

      }

      iVar3 = iVar3 + 1;

    } while (iVar3 < iVar4);

  }

  if (unaff_ESI[0x16d] == 0) {

    iVar4 = 0;

  }

  else {

    iVar4 = unaff_ESI[0x16e] - unaff_ESI[0x16d] >> 2;

  }

  iVar3 = 0;

  if (0 < iVar4) {

    do {

      iVar1 = iVar3 * 4;

      if (*(int *)(unaff_ESI[0x16d] + iVar1) != 0) {

        (**(code **)(**(int **)(unaff_ESI[0x16d] + iVar1) + 0x440))();

        (**(code **)(*unaff_ESI + 0xb0))(*(uint32_t /* width from decompiler */ *)(unaff_ESI[0x16d] + iVar1));

      }

      iVar3 = iVar3 + 1;

    } while (iVar3 < iVar4);

  }

  return;

}
