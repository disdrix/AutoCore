// =============================================================================
// FUN_0043a1d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0043a1d0
// Address:   0x0043a1d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0043a1d0 @ 0x0043a1d0
// Stable ID: aa_0043a1d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~113 non-empty decompiler lines.
//  - Control keywords: if×13, return×4.
//  - Notable callees: memmove×3, FUN_0040c7c0×2, FUN_0046d110×2, CONCAT44, FUN_0043a1d0, FUN_004540b0, FUN_00469470, FUN_0046d0f0.
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

void __thiscall FUN_0043a1d0(int param_1,void *param_2,int param_3,int param_4)



{

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

  puStack_c = &LAB_009bd630;

  local_10 = ExceptionList;

  iVar7 = *(int *)(param_1 + 4);

  uVar5 = param_4 - param_3 >> 2;

  if (iVar7 == 0) {

    iVar1 = 0;

  }

  else {

    iVar1 = *(int *)(param_1 + 0xc) - iVar7 >> 2;

  }

  uVar8 = CONCAT44(iVar7,iVar1);

  if (uVar5 != 0) {

    if (iVar7 == 0) {

      iVar7 = 0;

    }

    else {

      iVar7 = *(int *)(param_1 + 8) - iVar7 >> 2;

    }

    uVar6 = uVar5;

    ExceptionList = &local_10;

    if (0x3fffffffU - iVar7 < uVar5) {

      ExceptionList = &local_10;

      uVar8 = FUN_004540b0();

      uVar6 = extraout_ECX;

    }

    iVar7 = (int)((ulonglong)uVar8 >> 0x20);

    uVar2 = (uint)uVar8;

    if (iVar7 == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = *(int *)(param_1 + 8) - iVar7 >> 2;

    }

    if (uVar2 < iVar1 + uVar6) {

      if (0x3fffffff - (uVar2 >> 1) < uVar2) {

        uVar2 = 0;

      }

      else {

        uVar2 = uVar2 + (uVar2 >> 1);

      }

      if (iVar7 == 0) {

        iVar1 = 0;

      }

      else {

        iVar1 = *(int *)(param_1 + 8) - iVar7 >> 2;

      }

      if (uVar2 < iVar1 + uVar6) {

        if (iVar7 == 0) {

          iVar7 = 0;

        }

        else {

          iVar7 = *(int *)(param_1 + 8) - iVar7 >> 2;

        }

        uVar2 = iVar7 + uVar6;

      }

      _Dst = operator_new(uVar2 * 4);

      local_8 = 0;

      memmove(_Dst,*(void **)(param_1 + 4),((int)param_2 - (int)*(void **)(param_1 + 4) >> 2) * 4);

      pvVar3 = (void *)FUN_00469470(param_3,param_4,param_3);

      memmove(pvVar3,param_2,(*(int *)(param_1 + 8) - (int)param_2 >> 2) * 4);

      pvVar3 = *(void **)(param_1 + 4);

      if (pvVar3 == (void *)0x0) {

        iVar7 = 0;

      }

      else {

        iVar7 = *(int *)(param_1 + 8) - (int)pvVar3 >> 2;

      }

      if (pvVar3 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar3);

      }

      *(void **)(param_1 + 0xc) = (void *)(uVar2 * 4 + (int)_Dst);

      *(void **)(param_1 + 8) = (void *)((int)_Dst + (uVar5 + iVar7) * 4);

      *(void **)(param_1 + 4) = _Dst;

      ExceptionList = local_10;

      return;

    }

    iVar7 = *(int *)(param_1 + 8);

    if ((uint)(iVar7 - (int)param_2 >> 2) < uVar6) {

      FUN_0040c7c0((void *)(uVar6 * 4 + (int)param_2));

      local_8 = 2;

      iVar7 = param_3 + (*(int *)(param_1 + 8) - (int)param_2 >> 2) * 4;

      FUN_0046d0f0(param_1,iVar7,param_4,*(int *)(param_1 + 8));

      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + uVar6 * 4;

      FUN_0046d110(param_3,iVar7);

      ExceptionList = local_10;

      return;

    }

    uVar4 = FUN_0040c7c0(iVar7);

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar4;

    iVar1 = (int)((iVar7 + uVar6 * -4) - (int)param_2) >> 2;

    memmove((void *)(iVar7 + iVar1 * -4),param_2,iVar1 * 4);

    FUN_0046d110(param_3,param_4);

  }

  ExceptionList = local_10;

  return;

}
