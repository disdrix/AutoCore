// =============================================================================
// FUN_004ba850
// -----------------------------------------------------------------------------
// Stable ID: aa_004ba850
// Address:   0x004ba850  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004ba850 @ 0x004ba850
// Stable ID: aa_004ba850
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~99 non-empty decompiler lines.
//  - Control keywords: if×13, return×4.
//  - Notable callees: FUN_004e2e80×2, FUN_004e2f70×2, FUN_005739b0×2, memmove×2, CONCAT44, FUN_004ba670, FUN_004ba850, FUN_004e24d0.
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

void __thiscall FUN_004ba850(int param_1,void *param_2,uint param_3,uint32_t /* width from decompiler */ *param_4)



{

  size_t _Size;

  int iVar1;

  uint uVar2;

  void *_Dst;

  void *pvVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  int iVar6;

  uint64_t uVar7;

  

  iVar5 = *(int *)(param_1 + 4);

  param_4 = (uint32_t /* width from decompiler */ *)*param_4;

  if (iVar5 == 0) {

    iVar1 = 0;

  }

  else {

    iVar1 = *(int *)(param_1 + 0xc) - iVar5 >> 2;

  }

  uVar7 = CONCAT44(iVar5,iVar1);

  if (param_3 != 0) {

    if (iVar5 == 0) {

      iVar5 = 0;

    }

    else {

      iVar5 = *(int *)(param_1 + 8) - iVar5 >> 2;

    }

    if (0x3fffffffU - iVar5 < param_3) {

      uVar7 = FUN_004ba670();

    }

    iVar5 = (int)((ulonglong)uVar7 >> 0x20);

    uVar2 = (uint)uVar7;

    if (iVar5 == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = *(int *)(param_1 + 8) - iVar5 >> 2;

    }

    if (uVar2 < iVar1 + param_3) {

      if (0x3fffffff - (uVar2 >> 1) < uVar2) {

        uVar2 = 0;

      }

      else {

        uVar2 = uVar2 + (uVar2 >> 1);

      }

      if (iVar5 == 0) {

        iVar1 = 0;

      }

      else {

        iVar1 = *(int *)(param_1 + 8) - iVar5 >> 2;

      }

      if (uVar2 < iVar1 + param_3) {

        if (iVar5 == 0) {

          iVar5 = 0;

        }

        else {

          iVar5 = *(int *)(param_1 + 8) - iVar5 >> 2;

        }

        uVar2 = iVar5 + param_3;

      }

      _Dst = operator_new(uVar2 * 4);

      _Size = ((int)param_2 - (int)*(void **)(param_1 + 4) >> 2) * 4;

      pvVar3 = memmove(_Dst,*(void **)(param_1 + 4),_Size);

      pvVar3 = (void *)FUN_004e2f70((void *)((int)pvVar3 + _Size),param_3,&param_4);

      memmove(pvVar3,param_2,(*(int *)(param_1 + 8) - (int)param_2 >> 2) * 4);

      pvVar3 = *(void **)(param_1 + 4);

      if (pvVar3 == (void *)0x0) {

        iVar5 = 0;

      }

      else {

        iVar5 = *(int *)(param_1 + 8) - (int)pvVar3 >> 2;

      }

      if (pvVar3 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar3);

      }

      *(void **)(param_1 + 0xc) = (void *)(uVar2 * 4 + (int)_Dst);

      *(void **)(param_1 + 8) = (void *)((int)_Dst + (param_3 + iVar5) * 4);

      *(void **)(param_1 + 4) = _Dst;

      return;

    }

    iVar1 = *(int *)(param_1 + 8);

    iVar5 = param_3 * 4;

    if ((uint)(iVar1 - (int)param_2 >> 2) < param_3) {

      FUN_004e2e80(param_2,iVar1,(void *)(iVar5 + (int)param_2));

      FUN_004e2f70(*(int *)(param_1 + 8),param_3 - (*(int *)(param_1 + 8) - (int)param_2 >> 2),

                   &param_4);

      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + iVar5;

      FUN_005739b0(param_2,*(int *)(param_1 + 8) + param_3 * -4,&param_4);

      return;

    }

    iVar6 = iVar1 + param_3 * -4;

    uVar4 = FUN_004e2e80(iVar6,iVar1,iVar1);

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar4;

    FUN_004e24d0(param_2,iVar6,iVar1);

    FUN_005739b0(param_2,(void *)(iVar5 + (int)param_2),&param_4);

  }

  return;

}
