// =============================================================================
// FUN_00837e80
// -----------------------------------------------------------------------------
// Stable ID: aa_00837e80
// Address:   0x00837e80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00837e80 @ 0x00837e80
// Stable ID: aa_00837e80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×7, return×5, while×1.
//  - Notable callees: FUN_00415cb0, FUN_00574730, FUN_00837e80.
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

uint32_t /* width from decompiler */ FUN_00837e80(void)



{

  int iVar1;

  int iVar2;

  int iVar3;

  longlong lVar4;

  int *in_EAX;

  int iVar5;

  int *piVar6;

  longlong lVar7;

  uint8_t auStack_14 [20];

  

  if ((in_EAX == (int *)0x0) || (DAT_00d1b6d8 == 0)) {

    return 0;

  }

  iVar5 = (**(code **)(*in_EAX + 0x210))(0);

  iVar3 = DAT_00d1b6d8;

  if (iVar5 != DAT_00d1b6d8) {

    iVar5 = *(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4);

    if (((int)*(longlong *)(in_EAX + 0x10) != *(int *)(iVar5 + 0x164 + DAT_00d1b6d8)) ||

       (in_EAX[0x11] != *(int *)(iVar5 + 0x168 + DAT_00d1b6d8))) {

      if (*(int *)(DAT_00d1b6d8 + 0x250) != 0) {

        iVar5 = *(int *)(DAT_00d1b6d8 + 0x250);

        iVar1 = *(int *)(*(int *)(iVar5 + 4) + 4);

        iVar2 = *(int *)(iVar1 + 0x164 + iVar5);

        iVar5 = *(int *)(iVar1 + 0x168 + iVar5);

        piVar6 = (int *)FUN_00415cb0(auStack_14);

        if ((*piVar6 == iVar2) && (piVar6[1] == iVar5)) {

          return 1;

        }

      }

      iVar3 = *(int *)(iVar3 + 0xcb0);

      if ((iVar3 == 0) || (iVar5 = 0, *(char *)(iVar3 + 0x1d8) == '\0')) {

        return 0;

      }

      while (lVar4 = *(longlong *)(in_EAX + 0x10), lVar7 = FUN_00574730(iVar5), lVar7 != lVar4) {

        iVar5 = iVar5 + 1;

        if ((int)(uint)*(byte *)(iVar3 + 0x1d8) <= iVar5) {

          return 0;

        }

      }

    }

  }

  return 1;

}
