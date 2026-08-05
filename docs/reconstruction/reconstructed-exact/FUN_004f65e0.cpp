// =============================================================================
// FUN_004f65e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004f65e0
// Address:   0x004f65e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004f65e0 @ 0x004f65e0
// Stable ID: aa_004f65e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~97 non-empty decompiler lines.
//  - Control keywords: if×19, return×15.
//  - Notable callees: FUN_0040da70×2, FUN_004f65e0.
//  - Return sites: 15.

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

uint32_t /* width from decompiler */ __thiscall FUN_004f65e0(int param_1,int *param_2)



{

  byte bVar1;

  char cVar2;

  bool bVar3;

  int iVar4;

  int iVar5;

  

  if (param_2 == (int *)0x0) {

    return 8;

  }

  bVar3 = false;

  iVar4 = (**(code **)(*(int *)(*(int *)(param_2[1] + 4) + 4 + (int)param_2) + 0x210))(0);

  if ((iVar4 != 0) &&

     (iVar4 = (**(code **)(*(int *)(*(int *)(param_2[1] + 4) + 4 + (int)param_2) + 0x210))(0),

     0 < *(int *)(iVar4 + 0x6b4))) {

    bVar3 = true;

  }

  iVar4 = *(int *)(*(int *)(param_2[1] + 4) + 0xac + (int)param_2);

  iVar5 = *(int *)(param_2[1] + 4) + (int)param_2;

  if (iVar4 == 0) {

    iVar4 = 0;

  }

  else {

    iVar4 = *(int *)(iVar4 + 0x3c);

  }

  if (*(char *)(iVar4 + 0x3f4) == '\t') {

    iVar4 = *(int *)(param_1 + 0x264);

  }

  else {

    bVar1 = *(byte *)(param_2 + 0x31);

    if ((bVar1 & 2) != 0) {

      iVar4 = **(int **)(param_1 + 0x260);

      if ((iVar4 != 0) && (param_2 != (int *)0x0)) {

        iVar4 = *(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4;

        *param_2 = iVar4;

        iVar5 = *(int *)(param_2[1] + 4) + (int)param_2;

        if (iVar4 == iVar5 + 4) {

          return 3;

        }

      }

      if (bVar3) {

        return 0;

      }

      if (*(int *)(iVar5 + 0xac) == 0) {

        iVar4 = 0;

      }

      else {

        iVar4 = *(int *)(*(int *)(iVar5 + 0xac) + 0x3c);

      }

      if ((*(char *)(iVar4 + 0x535) == '\x01') &&

         (*(char *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c)

                   + 0x714) != '\x01')) {

        return 7;

      }

      if (*(char *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c)

                   + 0x714) != '\x01') {

        return 0;

      }

      iVar4 = FUN_0040da70();

      if (*(char *)(iVar4 + 0x535) == '\x01') {

        return 0;

      }

      return 7;

    }

    if ((bVar1 & 0x10) != 0) {

      iVar4 = *(int *)(*(int *)(param_1 + 0x260) + 4);

      if (((iVar4 != 0) && (param_2 != (int *)0x0)) &&

         (iVar4 = *(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4, *param_2 = iVar4,

         iVar4 == *(int *)(param_2[1] + 4) + 4 + (int)param_2)) {

        return 3;

      }

      if (bVar3) {

        return 0;

      }

      cVar2 = *(char *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) +

                                0x3c) + 0x714);

      iVar4 = FUN_0040da70();

      if (*(char *)(iVar4 + 0x535) == cVar2) {

        return 0;

      }

      if (cVar2 == '\0') {

        return 0;

      }

      return 7;

    }

    if ((bVar1 & 4) == 0) {

      return 8;

    }

    iVar4 = *(int *)(*(int *)(param_1 + 0x260) + 8);

  }

  if (((iVar4 != 0) && (param_2 != (int *)0x0)) &&

     (iVar4 = *(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4, *param_2 = iVar4,

     iVar4 == *(int *)(param_2[1] + 4) + 4 + (int)param_2)) {

    return 3;

  }

  return 0;

}
