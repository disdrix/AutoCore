// =============================================================================
// FUN_005f31e0
// -----------------------------------------------------------------------------
// Stable ID: aa_005f31e0
// Address:   0x005f31e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005f31e0 @ 0x005f31e0
// Stable ID: aa_005f31e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: if×7, while×1, return×1.
//  - Notable callees: FUN_005b3370×2, FUN_00638180×2, FUN_00643010×2, FUN_005b3300, FUN_005f2d70, FUN_005f31e0, FUN_00638060, FUN_006380a0.
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

int __fastcall FUN_005f31e0(int param_1)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  char *unaff_EBX;

  int *unaff_retaddr;

  uint local_c;

  uint local_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_c = 0;

  local_8 = 0;

  local_4 = 0x80000000;

  FUN_005b3300(&local_c,0x40,1);

  FUN_005f2d70();

  (**(code **)(**(int **)(param_1 + 8) + 0x14))(1);

  iVar2 = FUN_00643010();

  while ((((iVar2 != -1 && (iVar2 != 0x20)) && (iVar2 != 9)) && ((iVar2 != 0xd && (iVar2 != 10)))))

  {

    if (local_c == (local_8 & 0x7fffffff)) {

      FUN_005b3370(&stack0xfffffff0,1);

    }

    unaff_EBX[local_c] = (char)iVar2;

    local_c = local_c + 1;

    (**(code **)(**(int **)(param_1 + 8) + 0x14))(1);

    iVar2 = FUN_00643010();

  }

  (**(code **)(**(int **)(param_1 + 8) + 0x18))();

  if (local_c == (local_8 & 0x7fffffff)) {

    FUN_005b3370(&stack0xfffffff0,1);

  }

  unaff_EBX[local_c] = '\0';

  local_c = local_c + 1;

  if ((unaff_EBX == (char *)0x0) || (*unaff_EBX == '\0')) {

    piVar1 = (int *)(*unaff_retaddr + -4);

    *piVar1 = *piVar1 + -1;

    if (*piVar1 < 0) {

      FUN_00638180();

    }

    DAT_00d02c6c = DAT_00d02c6c + 1;

    *unaff_retaddr = (int)&DAT_00d02c70;

  }

  else {

    iVar3 = FUN_00638060(unaff_EBX);

    iVar2 = *unaff_retaddr;

    if ((*(int *)(iVar2 + -8) < iVar3) || (0 < *(int *)(iVar2 + -4))) {

      piVar1 = (int *)(iVar2 + -4);

      *piVar1 = *piVar1 + -1;

      if (*piVar1 < 0) {

        FUN_00638180();

      }

      iVar2 = FUN_006381a0(iVar3);

      *unaff_retaddr = iVar2 + 0xc;

    }

    FUN_006380a0(*unaff_retaddr,unaff_EBX,iVar3 + 1);

    *(int *)(*unaff_retaddr + -0xc) = iVar3;

  }

  if (-1 < (int)local_8) {

    (**(code **)(*DAT_00b05060 + 0x14))(unaff_EBX,local_8 & 0x7fffffff,0x12);

  }

  return param_1;

}
