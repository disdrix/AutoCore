// =============================================================================
// FUN_0043ed30
// -----------------------------------------------------------------------------
// Stable ID: aa_0043ed30
// Address:   0x0043ed30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0043ed30 @ 0x0043ed30
// Stable ID: aa_0043ed30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_0043ed30, FUN_00448fc0, FUN_00752370, FUN_00753560, FUN_0096fdf0.
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

int FUN_0043ed30(void)



{

  int iVar1;

  char cVar2;

  uint32_t /* width from decompiler */ in_EAX;

  int *piVar3;

  int iVar4;

  int iVar5;

  int *unaff_ESI;

  int local_4;

  

  piVar3 = &local_4;

  if (*unaff_ESI == 0) {

    local_4 = -1;

  }

  else {

    piVar3 = (int *)FUN_00752370(&local_4,in_EAX);

  }

  iVar4 = *piVar3;

  if (-1 < iVar4) {

    cVar2 = FUN_0096fdf0();

    iVar4 = FUN_00753560(*unaff_ESI,iVar4);

    if (((iVar4 == -1) && (cVar2 != '\0')) && (iVar1 = *unaff_ESI, iVar1 != 0)) {

      iVar5 = *(int *)(iVar1 + 0x18);

      if (*(int *)(iVar1 + 0x18) == 0) {

        iVar5 = iVar1;

      }

      if (iVar5 != iVar1) {

        FUN_00448fc0(iVar5);

      }

    }

    return iVar4;

  }

  return 1;

}
