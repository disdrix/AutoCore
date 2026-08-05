// =============================================================================
// FUN_0055f120
// -----------------------------------------------------------------------------
// Stable ID: aa_0055f120
// Address:   0x0055f120  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0055f120 @ 0x0055f120
// Stable ID: aa_0055f120
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×5, while×2, do×1, return×1.
//  - Notable callees: FUN_0055f120, FUN_005b3300.
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

void __fastcall FUN_0055f120(int param_1)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  uint uVar5;

  int iVar6;

  int *piVar7;

  

  piVar1 = (int *)(param_1 + 0x94);

  iVar6 = *(int *)(param_1 + 0x98);

  iVar4 = 0;

  iVar3 = iVar4;

  if (0 < iVar6) {

    piVar7 = (int *)*piVar1;

    do {

      iVar3 = iVar4;

      if (*piVar7 == 0) break;

      iVar4 = iVar4 + 1;

      piVar7 = piVar7 + 1;

      iVar3 = iVar4;

    } while (iVar4 < iVar6);

  }

  while (iVar3 = iVar3 + 1, iVar3 < iVar6) {

    iVar2 = *(int *)(*piVar1 + iVar3 * 4);

    if (iVar2 != 0) {

      *(int *)(*piVar1 + iVar4 * 4) = iVar2;

      iVar4 = iVar4 + 1;

    }

  }

  uVar5 = *(uint *)(param_1 + 0x9c) & 0x7fffffff;

  if ((int)uVar5 < iVar4) {

    iVar6 = uVar5 * 2;

    if (iVar6 <= iVar4) {

      iVar6 = iVar4;

    }

    FUN_005b3300(piVar1,iVar6,4);

  }

  *(int *)(param_1 + 0x98) = iVar4;

  return;

}
