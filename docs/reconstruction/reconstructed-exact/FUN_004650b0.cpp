// =============================================================================
// FUN_004650b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004650b0
// Address:   0x004650b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004650b0 @ 0x004650b0
// Stable ID: aa_004650b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: FUN_00438d00, FUN_004533c0, FUN_004650b0.
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

void __fastcall FUN_004650b0(uint param_1,int param_2,uint32_t /* width from decompiler */ param_3,int *param_4)



{

  int *piVar1;

  uint uVar2;

  int iVar3;

  uint local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009be4c8;

  local_c = ExceptionList;

  local_4 = 0;

  iVar3 = *(int *)(param_2 + 4);

  if (iVar3 == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = *(int *)(param_2 + 8) - iVar3 >> 3;

  }

  local_10 = param_1;

  if (uVar2 < param_1) {

    if (iVar3 == 0) {

      iVar3 = 0;

    }

    else {

      iVar3 = *(int *)(param_2 + 8) - iVar3 >> 3;

    }

    ExceptionList = &local_c;

    FUN_004533c0(param_2,*(uint32_t /* width from decompiler */ *)(param_2 + 8),param_1 - iVar3,&param_3);

  }

  else {

    ExceptionList = &local_c;

    if ((iVar3 != 0) &&

       (ExceptionList = &local_c, param_1 < (uint)(*(int *)(param_2 + 8) - iVar3 >> 3))) {

      ExceptionList = &local_c;

      FUN_00438d00(param_2,&local_10,iVar3 + param_1 * 8,*(int *)(param_2 + 8));

    }

  }

  local_4 = 0xffffffff;

  if (param_4 != (int *)0x0) {

    piVar1 = param_4 + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*param_4 + 8))();

    }

  }

  ExceptionList = local_c;

  return;

}
