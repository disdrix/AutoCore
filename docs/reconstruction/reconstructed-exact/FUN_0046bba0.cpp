// =============================================================================
// FUN_0046bba0
// -----------------------------------------------------------------------------
// Stable ID: aa_0046bba0
// Address:   0x0046bba0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0046bba0 @ 0x0046bba0
// Stable ID: aa_0046bba0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~96 non-empty decompiler lines.
//  - Control keywords: if×12, return×3.
//  - Notable callees: FUN_0046be60×4, FUN_00455f50×2, FUN_00409ed0, FUN_004426e0, FUN_004540b0, FUN_0046bba0, SkillSet_GetEntryCount.
//  - Return sites: 3.

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

void __fastcall FUN_0046bba0(uint param_1,void *param_2,int param_3)



{

  void *pvVar1;

  int iVar2;

  int iVar3;

  void *pvVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint uVar6;

  uint extraout_ECX;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bdeb0;

  local_10 = ExceptionList;

  iVar3 = *(int *)((int)param_2 + 4);

  if (iVar3 == 0) {

    uVar6 = 0;

  }

  else {

    uVar6 = (*(int *)((int)param_2 + 0xc) - iVar3) / 0x18;

  }

  if (param_1 != 0) {

    if (iVar3 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)((int)param_2 + 8) - iVar3) / 0x18;

    }

    ExceptionList = &local_10;

    if (0xaaaaaaaU - iVar2 < param_1) {

      ExceptionList = &local_10;

      FUN_004540b0();

      uVar6 = extraout_ECX;

    }

    if (iVar3 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)((int)param_2 + 8) - iVar3) / 0x18;

    }

    if (uVar6 < iVar2 + param_1) {

      if (0xaaaaaaa - (uVar6 >> 1) < uVar6) {

        uVar6 = 0;

      }

      else {

        uVar6 = uVar6 + (uVar6 >> 1);

      }

      if (iVar3 == 0) {

        iVar3 = 0;

      }

      else {

        iVar3 = (*(int *)((int)param_2 + 8) - iVar3) / 0x18;

      }

      if (uVar6 < iVar3 + param_1) {

        iVar3 = SkillSet_GetEntryCount(param_2);

        uVar6 = iVar3 + param_1;

      }

      pvVar4 = operator_new(uVar6 * 0x18);

      local_8 = 0;

      FUN_0046be60(param_3);

      FUN_00455f50(param_3);

      FUN_0046be60(param_3);

      pvVar1 = *(void **)((int)param_2 + 4);

      if (pvVar1 == (void *)0x0) {

        iVar3 = 0;

      }

      else {

        iVar3 = (*(int *)((int)param_2 + 8) - (int)pvVar1) / 0x18;

      }

      if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      *(void **)((int)param_2 + 0xc) = (void *)(uVar6 * 0x18 + (int)pvVar4);

      *(void **)((int)param_2 + 8) = (void *)((int)pvVar4 + (param_1 + iVar3) * 0x18);

      *(void **)((int)param_2 + 4) = pvVar4;

      ExceptionList = local_10;

      return;

    }

    if ((uint)((*(int *)((int)param_2 + 8) - param_3) / 0x18) < param_1) {

      FUN_0046be60(param_3);

      local_8 = 2;

      FUN_00455f50(param_3);

      *(int *)((int)param_2 + 8) = *(int *)((int)param_2 + 8) + param_1 * 0x18;

    }

    else {

      uVar5 = FUN_0046be60(param_3);

      *(uint32_t /* width from decompiler */ *)((int)param_2 + 8) = uVar5;

      FUN_00409ed0(param_3);

    }

    FUN_004426e0();

  }

  ExceptionList = local_10;

  return;

}
