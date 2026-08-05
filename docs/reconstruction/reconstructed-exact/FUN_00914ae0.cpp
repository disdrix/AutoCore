// =============================================================================
// FUN_00914ae0
// -----------------------------------------------------------------------------
// Stable ID: aa_00914ae0
// Address:   0x00914ae0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00914ae0 @ 0x00914ae0
// Stable ID: aa_00914ae0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×7, return×1.
//  - Notable callees: FUN_007fc840, FUN_00914ae0.
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

int FUN_00914ae0(void)



{

  byte *pbVar1;

  int iVar2;

  char cVar3;

  int iVar4;

  

  if ((*(uint *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0x180 + DAT_00d1b6d8) >> 7 & 1) != 0) {

    if (DAT_00d1b87c != (int *)0x0) {

      cVar3 = (**(code **)(*DAT_00d1b87c + 0x3d8))();

      if (cVar3 != '\0') {

        (**(code **)(*DAT_00d1b87c + 0x448))();

      }

    }

    if (DAT_00d1b870 != (int *)0x0) {

      cVar3 = (**(code **)(*DAT_00d1b870 + 0x3d8))();

      if (cVar3 != '\0') {

        (**(code **)(*DAT_00d1b870 + 0x448))();

      }

    }

    pbVar1 = (byte *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0x180 + DAT_00d1b6d8);

    *pbVar1 = *pbVar1 & 0x7f;

  }

  iVar4 = *(int *)(DAT_00d1b6d8 + 0x250);

  if ((iVar4 != 0) && ((*(uint *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0x180 + iVar4) >> 7 & 1) != 0)

     ) {

    cVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x198))();

    if (cVar3 == '\0') {

      FUN_007fc840();

    }

    iVar4 = *(int *)(DAT_00d1b6d8 + 0x250);

    iVar2 = *(int *)(*(int *)(iVar4 + 4) + 4);

    pbVar1 = (byte *)(iVar2 + 0x180 + iVar4);

    *pbVar1 = *pbVar1 & 0x7f;

    iVar4 = iVar2 + 4 + iVar4;

  }

  return iVar4;

}
