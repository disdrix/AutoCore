// =============================================================================
// FUN_00574780
// -----------------------------------------------------------------------------
// Stable ID: aa_00574780
// Address:   0x00574780  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00574780 @ 0x00574780
// Stable ID: aa_00574780
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_00574780.
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

uint __fastcall FUN_00574780(int param_1)



{

  int iVar1;

  char cVar2;

  uint uVar3;

  int iVar4;

  uint uVar5;

  int iVar6;

  int *piVar7;

  

  uVar5 = (uint)*(byte *)(param_1 + 0x1d8);

  iVar6 = 0;

  piVar7 = (int *)(param_1 + 0x1a0);

  iVar4 = 4;

  do {

    if (((-1 < iVar6) && (iVar6 < 4)) && (iVar1 = *piVar7, iVar1 != 0)) {

      cVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x198))();

      if (cVar2 != '\0') {

        uVar5 = uVar5 - 1;

      }

    }

    iVar6 = iVar6 + 1;

    piVar7 = piVar7 + 4;

    iVar4 = iVar4 + -1;

  } while (iVar4 != 0);

  uVar3 = 1;

  if (0 < (int)uVar5) {

    uVar3 = uVar5;

  }

  return uVar3;

}
