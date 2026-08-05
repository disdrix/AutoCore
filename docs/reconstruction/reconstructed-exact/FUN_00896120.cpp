// =============================================================================
// FUN_00896120
// -----------------------------------------------------------------------------
// Stable ID: aa_00896120
// Address:   0x00896120  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00896120 @ 0x00896120
// Stable ID: aa_00896120
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_00896120.
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

void FUN_00896120(void)



{

  int iVar1;

  uint uVar2;

  int iVar3;

  int *piVar4;

  int unaff_EDI;

  

  piVar4 = (int *)(unaff_EDI + 0x664);

  iVar3 = 0x36;

  do {

    if ((*piVar4 != 0) && (iVar1 = *(int *)(*piVar4 + 0x60c), iVar1 != 0)) {

      uVar2 = *(byte *)(iVar1 + 0x5fb) / 5;

      if (((uint)*(byte *)(iVar1 + 0x5f8) != *(uint *)(unaff_EDI + 0x51c)) ||

         (((int)uVar2 < *(int *)(unaff_EDI + 0x50c) ||

          (*(int *)(unaff_EDI + 0x514) <= (int)(uVar2 - *(int *)(unaff_EDI + 0x50c)))))) {

        (**(code **)(*(int *)*piVar4 + 0xcc))(0);

        if (piVar4[-0x36] != 0) {

          (**(code **)(*(int *)piVar4[-0x36] + 0xcc))(0);

        }

      }

    }

    piVar4 = piVar4 + 1;

    iVar3 = iVar3 + -1;

  } while (iVar3 != 0);

  return;

}
