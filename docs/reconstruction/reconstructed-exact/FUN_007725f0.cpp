// =============================================================================
// FUN_007725f0
// -----------------------------------------------------------------------------
// Stable ID: aa_007725f0
// Address:   0x007725f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007725f0 @ 0x007725f0
// Stable ID: aa_007725f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: if×9, return×5, do×2, while×2.
//  - Notable callees: FUN_00770440×2, FUN_00770650×2, FUN_007707d0, FUN_007725f0.
//  - Return sites: 5.

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

int FUN_007725f0(int *param_1,int *param_2)



{

  uint *puVar1;

  int *in_EAX;

  int iVar2;

  int iVar3;

  int *piVar4;

  int local_10;

  int local_c;

  int local_8;

  int local_4;

  

  if (*in_EAX < *param_1) {

    iVar2 = FUN_00770440();

    if (iVar2 != 0) {

      return iVar2;

    }

    iVar2 = FUN_00770650();

    if (iVar2 != 0) {

      return iVar2;

    }

    iVar2 = *in_EAX;

  }

  else {

    iVar2 = FUN_00770440();

    if (iVar2 != 0) {

      return iVar2;

    }

    iVar2 = FUN_00770650();

    if (iVar2 != 0) {

      return iVar2;

    }

    iVar2 = *param_1;

    in_EAX = param_1;

  }

  iVar3 = 0;

  if (0 < iVar2) {

    do {

      puVar1 = (uint *)(local_4 + iVar3 * 4);

      *puVar1 = *puVar1 ^ *(uint *)(in_EAX[3] + iVar3 * 4);

      iVar3 = iVar3 + 1;

    } while (iVar3 < iVar2);

  }

  if (0 < local_10) {

    piVar4 = (int *)(local_4 + -4 + local_10 * 4);

    do {

      if (*piVar4 != 0) break;

      local_10 = local_10 + -1;

      piVar4 = piVar4 + -1;

    } while (0 < local_10);

  }

  if (local_10 == 0) {

    local_8 = 0;

  }

  *param_2 = local_10;

  param_2[1] = local_c;

  param_2[2] = local_8;

  param_2[3] = local_4;

  FUN_007707d0();

  return 0;

}
