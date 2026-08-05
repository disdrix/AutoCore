// =============================================================================
// FUN_00771760
// -----------------------------------------------------------------------------
// Stable ID: aa_00771760
// Address:   0x00771760  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00771760 @ 0x00771760
// Stable ID: aa_00771760
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×6, return×4, do×1, while×1.
//  - Notable callees: FUN_00770620, FUN_00771760.
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

int FUN_00771760(void)



{

  int iVar1;

  uint uVar2;

  uint *puVar3;

  int *unaff_ESI;

  int iVar4;

  

  iVar1 = *unaff_ESI;

  if (iVar1 == 0) {

    return iVar1;

  }

  if (iVar1 == 1) {

    return iVar1;

  }

  if (1 < iVar1) {

    iVar1 = FUN_00770620();

    uVar2 = 1;

    if (0x1c < iVar1) {

      puVar3 = (uint *)(unaff_ESI[3] + 4);

      iVar4 = 0x1c;

      do {

        if ((*puVar3 & uVar2) == 0) {

          return 0;

        }

        uVar2 = uVar2 * 2;

        if (0xfffffff < uVar2) {

          puVar3 = puVar3 + 1;

          uVar2 = 1;

        }

        iVar4 = iVar4 + 1;

      } while (iVar4 < iVar1);

    }

  }

  return 1;

}
