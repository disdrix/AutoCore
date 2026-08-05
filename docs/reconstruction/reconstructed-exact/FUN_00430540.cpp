// =============================================================================
// FUN_00430540
// -----------------------------------------------------------------------------
// Stable ID: aa_00430540
// Address:   0x00430540  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00430540 @ 0x00430540
// Stable ID: aa_00430540
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_00426f20, FUN_00430540, FUN_00430d30, FUN_00430d80.
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

void __thiscall FUN_00430540(int param_1,uint param_2,uint32_t /* width from decompiler */ param_3,void *param_4)



{

  void *pvVar1;

  uint uVar2;

  int iVar3;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009beef8;

  local_c = ExceptionList;

  local_4 = 0;

  iVar3 = *(int *)(param_1 + 4);

  if (iVar3 == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = *(int *)(param_1 + 8) - iVar3 >> 4;

  }

  if (uVar2 < param_2) {

    if (iVar3 == 0) {

      iVar3 = 0;

    }

    else {

      iVar3 = *(int *)(param_1 + 8) - iVar3 >> 4;

    }

    ExceptionList = &local_c;

    FUN_00430d80(param_1,*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_2 - iVar3);

  }

  else {

    ExceptionList = &local_c;

    if ((iVar3 != 0) &&

       (ExceptionList = &local_c, param_2 < (uint)(*(int *)(param_1 + 8) - iVar3 >> 4))) {

      ExceptionList = &local_c;

      FUN_00430d30(param_1,&param_2,param_2 * 0x10 + iVar3,*(int *)(param_1 + 8));

    }

  }

  pvVar1 = param_4;

  if (param_4 != (void *)0x0) {

    FUN_00426f20(param_2);

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  ExceptionList = local_c;

  return;

}
