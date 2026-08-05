// =============================================================================
// FUN_005ddbe0
// -----------------------------------------------------------------------------
// Stable ID: aa_005ddbe0
// Address:   0x005ddbe0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005ddbe0 @ 0x005ddbe0
// Stable ID: aa_005ddbe0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~115 non-empty decompiler lines.
//  - Control keywords: if×13, return×4.
//  - Notable callees: FUN_004190b0×2, FUN_005dd960×2, FUN_006a2be0×2, memmove×2, CONCAT44, FUN_00418130, FUN_004190e0, FUN_005ddbe0.
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

void __thiscall FUN_005ddbe0(int param_1,void *param_2,int param_3,int param_4)



{

  size_t _Size;

  int iVar1;

  uint uVar2;

  void *_Dst;

  void *pvVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint uVar5;

  uint extraout_ECX;

  uint uVar6;

  int iVar7;

  uint64_t uVar8;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009a7250;

  local_10 = ExceptionList;

  iVar7 = *(int *)(param_1 + 4);

  uVar5 = param_4 - param_3 >> 3;

  if (iVar7 == 0) {

    iVar1 = 0;

  }

  else {

    iVar1 = *(int *)(param_1 + 0xc) - iVar7 >> 3;

  }

  uVar8 = CONCAT44(iVar7,iVar1);

  if (uVar5 != 0) {

    if (iVar7 == 0) {

      iVar7 = 0;

    }

    else {

      iVar7 = *(int *)(param_1 + 8) - iVar7 >> 3;

    }

    uVar6 = uVar5;

    ExceptionList = &local_10;

    if (0x1fffffffU - iVar7 < uVar5) {

      ExceptionList = &local_10;

      uVar8 = FUN_00418130();

      uVar6 = extraout_ECX;

    }

    iVar7 = (int)((ulonglong)uVar8 >> 0x20);

    uVar2 = (uint)uVar8;

    if (iVar7 == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = *(int *)(param_1 + 8) - iVar7 >> 3;

    }

    if (uVar2 < iVar1 + uVar6) {

      if (0x1fffffff - (uVar2 >> 1) < uVar2) {

        uVar2 = 0;

      }

      else {

        uVar2 = uVar2 + (uVar2 >> 1);

      }

      if (iVar7 == 0) {

        iVar1 = 0;

      }

      else {

        iVar1 = *(int *)(param_1 + 8) - iVar7 >> 3;

      }

      if (uVar2 < iVar1 + uVar6) {

        if (iVar7 == 0) {

          iVar7 = 0;

        }

        else {

          iVar7 = *(int *)(param_1 + 8) - iVar7 >> 3;

        }

        uVar2 = iVar7 + uVar6;

      }

      _Dst = operator_new(uVar2 * 8);

      _Size = ((int)param_2 - (int)*(void **)(param_1 + 4) >> 3) * 8;

      local_8 = 0;

      pvVar3 = memmove(_Dst,*(void **)(param_1 + 4),_Size);

      pvVar3 = (void *)FUN_006a2be0(param_3,param_4,(void *)((int)pvVar3 + _Size),param_1,param_3);

      memmove(pvVar3,param_2,(*(int *)(param_1 + 8) - (int)param_2 >> 3) * 8);

      pvVar3 = *(void **)(param_1 + 4);

      if (pvVar3 == (void *)0x0) {

        iVar7 = 0;

      }

      else {

        iVar7 = *(int *)(param_1 + 8) - (int)pvVar3 >> 3;

      }

      if (pvVar3 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar3);

      }

      *(void **)(param_1 + 0xc) = (void *)(uVar2 * 8 + (int)_Dst);

      *(void **)(param_1 + 8) = (void *)((int)_Dst + (uVar5 + iVar7) * 8);

      *(void **)(param_1 + 4) = _Dst;

      ExceptionList = local_10;

      return;

    }

    iVar7 = *(int *)(param_1 + 8);

    if ((uint)(iVar7 - (int)param_2 >> 3) < uVar6) {

      FUN_004190b0(param_2,iVar7,(void *)(uVar6 * 8 + (int)param_2));

      iVar7 = param_3 + (*(int *)(param_1 + 8) - (int)param_2 >> 3) * 8;

      local_8 = 2;

      FUN_006a2be0(iVar7,param_4,*(int *)(param_1 + 8),param_1,param_3);

      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + uVar6 * 8;

      FUN_005dd960(param_3,iVar7,param_2);

      ExceptionList = local_10;

      return;

    }

    iVar1 = iVar7 + uVar6 * -8;

    uVar4 = FUN_004190b0(iVar1,iVar7,iVar7);

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar4;

    FUN_004190e0(param_2,iVar1,iVar7);

    FUN_005dd960(param_3,param_4,param_2);

  }

  ExceptionList = local_10;

  return;

}
