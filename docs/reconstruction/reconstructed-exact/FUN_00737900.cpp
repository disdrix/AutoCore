// =============================================================================
// FUN_00737900
// -----------------------------------------------------------------------------
// Stable ID: aa_00737900
// Address:   0x00737900  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00737900 @ 0x00737900
// Stable ID: aa_00737900
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~63 non-empty decompiler lines.
//  - Control keywords: if×11, return×2, goto×1.
//  - Notable callees: FUN_00752510×3, FUN_0096f740×3, FUN_0096fdf0×3, CONCAT31, FUN_00737900.
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

uint FUN_00737900(void)



{

  char cVar1;

  uint uVar2;

  int iVar3;

  int unaff_ESI;

  bool bVar4;

  

  if (*(char *)(unaff_ESI + 0xcc) == '\0') {

    if (*(char *)(DAT_00d1f044 + 0x774) == '\0') {

      *(uint8_t *)(unaff_ESI + 0xcd) = 0;

    }

    else {

      cVar1 = FUN_0096fdf0();

      iVar3 = -1;

      if (*(int *)(unaff_ESI + 0x20) != 0) {

        iVar3 = FUN_00752510();

      }

      if (cVar1 != '\0') {

        FUN_0096f740();

      }

      *(bool *)(unaff_ESI + 0xcd) = -1 < iVar3;

      if ((-1 < iVar3) && (*(char *)(unaff_ESI + 0xce) != '\0')) {

        bVar4 = true;

        goto LAB_0073799f;

      }

    }

    bVar4 = false;

  }

  else {

    cVar1 = FUN_0096fdf0();

    iVar3 = -1;

    if (*(int *)(unaff_ESI + 0x20) != 0) {

      iVar3 = FUN_00752510();

    }

    if (cVar1 != '\0') {

      FUN_0096f740();

    }

    bVar4 = -1 < iVar3;

  }

LAB_0073799f:

  iVar3 = *(int *)(*(int *)(unaff_ESI + 0x20) + 0x14);

  if (iVar3 == 0) {

    iVar3 = 0;

  }

  else {

    iVar3 = *(int *)(iVar3 + 0x18);

  }

  *(int *)(unaff_ESI + 0xb4) = iVar3;

  if ((((*(char *)(unaff_ESI + 0xcc) == '\0') ||

       (iVar3 = iVar3 + -2 + *(int *)(*(int *)(unaff_ESI + 200) + 0x14) * 2, iVar3 < 0x11)) &&

      (bVar4)) && (DAT_00d1a5b9 == '\0')) {

    return CONCAT31((int3)((uint)iVar3 >> 8),1);

  }

  uVar2 = FUN_0096fdf0();

  cVar1 = (char)uVar2;

  if (*(int *)(unaff_ESI + 0x20) != 0) {

    uVar2 = FUN_00752510();

  }

  if (cVar1 != '\0') {

    uVar2 = FUN_0096f740();

  }

  return uVar2 & 0xffffff00;

}
