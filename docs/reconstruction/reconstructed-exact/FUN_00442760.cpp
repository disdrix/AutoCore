// =============================================================================
// FUN_00442760
// -----------------------------------------------------------------------------
// Stable ID: aa_00442760
// Address:   0x00442760  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00442760 @ 0x00442760
// Stable ID: aa_00442760
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~96 non-empty decompiler lines.
//  - Control keywords: if×12, return×4.
//  - Notable callees: FUN_00442b00×4, FUN_00442a90×2, FUN_00409ed0, FUN_004426c0, FUN_00442760, FUN_00442ab0, FUN_004540b0, SkillSet_GetEntryCount.
//  - Return sites: 4.

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

void __thiscall FUN_00442760(void *param_1,int param_2,int param_3,int param_4)



{

  uint uVar1;

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

  puStack_c = &LAB_009bd580;

  local_10 = ExceptionList;

  iVar3 = *(int *)((int)param_1 + 4);

  uVar1 = (param_4 - param_3) / 0x18;

  if (iVar3 == 0) {

    uVar6 = 0;

  }

  else {

    uVar6 = (*(int *)((int)param_1 + 0xc) - iVar3) / 0x18;

  }

  if (uVar1 != 0) {

    if (iVar3 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)((int)param_1 + 8) - iVar3) / 0x18;

    }

    ExceptionList = &local_10;

    if (0xaaaaaaaU - iVar2 < uVar1) {

      ExceptionList = &local_10;

      FUN_004540b0();

      uVar6 = extraout_ECX;

    }

    if (iVar3 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)((int)param_1 + 8) - iVar3) / 0x18;

    }

    if (uVar6 < iVar2 + uVar1) {

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

        iVar3 = (*(int *)((int)param_1 + 8) - iVar3) / 0x18;

      }

      if (uVar6 < iVar3 + uVar1) {

        iVar3 = SkillSet_GetEntryCount(param_1);

        uVar6 = iVar3 + uVar1;

      }

      pvVar4 = operator_new(uVar6 * 0x18);

      local_8 = 0;

      FUN_00442b00(param_3);

      FUN_00442ab0(param_3,param_4,param_3);

      FUN_00442b00(param_3);

      iVar3 = 0;

      if (*(int *)((int)param_1 + 4) != 0) {

        iVar3 = (*(int *)((int)param_1 + 8) - *(int *)((int)param_1 + 4)) / 0x18;

      }

      if (*(void **)((int)param_1 + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)((int)param_1 + 4));

      }

      *(void **)((int)param_1 + 0xc) = (void *)(uVar6 * 0x18 + (int)pvVar4);

      *(void **)((int)param_1 + 8) = (void *)((int)pvVar4 + (uVar1 + iVar3) * 0x18);

      *(void **)((int)param_1 + 4) = pvVar4;

      ExceptionList = local_10;

      return;

    }

    if ((uint)((*(int *)((int)param_1 + 8) - param_2) / 0x18) < uVar1) {

      FUN_00442b00(param_3);

      local_8 = 2;

      iVar3 = param_3 + ((*(int *)((int)param_1 + 8) - param_2) / 0x18) * 0x18;

      FUN_004426c0(param_1,iVar3,param_4,*(int *)((int)param_1 + 8));

      *(int *)((int)param_1 + 8) = *(int *)((int)param_1 + 8) + uVar1 * 0x18;

      FUN_00442a90(param_3,iVar3,param_2);

      ExceptionList = local_10;

      return;

    }

    uVar5 = FUN_00442b00(param_3);

    *(uint32_t /* width from decompiler */ *)((int)param_1 + 8) = uVar5;

    FUN_00409ed0(param_3);

    FUN_00442a90(param_3,param_4,param_2);

  }

  ExceptionList = local_10;

  return;

}
