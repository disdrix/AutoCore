// =============================================================================
// FUN_00446860
// -----------------------------------------------------------------------------
// Stable ID: aa_00446860
// Address:   0x00446860  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00446860 @ 0x00446860
// Stable ID: aa_00446860
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~93 non-empty decompiler lines.
//  - Control keywords: if×13, return×4.
//  - Notable callees: FUN_00446a20×2, FUN_00447d00×2, FUN_00447d30×2, memmove×2, CONCAT31, FUN_00446860, FUN_00447d50, FUN_004540b0.
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

void __thiscall FUN_00446860(int param_1,void *param_2,uint param_3,uint8_t *param_4)



{

  int iVar1;

  void *_Dst;

  void *pvVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint extraout_ECX;

  int iVar4;

  size_t _Size;

  uint local_4;

  

  iVar1 = *(int *)(param_1 + 4);

  param_4 = (uint8_t *)CONCAT31(param_4._1_3_,*param_4);

  if (iVar1 == 0) {

    local_4 = 0;

  }

  else {

    local_4 = *(int *)(param_1 + 0xc) - iVar1;

  }

  if (param_3 != 0) {

    if (iVar1 == 0) {

      iVar4 = 0;

    }

    else {

      iVar4 = *(int *)(param_1 + 8) - iVar1;

    }

    if (-iVar4 - 1U < param_3) {

      iVar1 = FUN_004540b0();

      local_4 = extraout_ECX;

    }

    if (iVar1 == 0) {

      iVar4 = 0;

    }

    else {

      iVar4 = *(int *)(param_1 + 8) - iVar1;

    }

    if (local_4 < iVar4 + param_3) {

      if (-(local_4 >> 1) - 1 < local_4) {

        local_4 = 0;

      }

      else {

        local_4 = local_4 + (local_4 >> 1);

      }

      if (iVar1 == 0) {

        iVar4 = 0;

      }

      else {

        iVar4 = *(int *)(param_1 + 8) - iVar1;

      }

      if (local_4 < iVar4 + param_3) {

        if (iVar1 == 0) {

          iVar1 = 0;

        }

        else {

          iVar1 = *(int *)(param_1 + 8) - iVar1;

        }

        local_4 = iVar1 + param_3;

      }

      _Dst = operator_new(local_4);

      _Size = (int)param_2 - (int)*(void **)(param_1 + 4);

      pvVar2 = memmove(_Dst,*(void **)(param_1 + 4),_Size);

      pvVar2 = (void *)FUN_00446a20((int)pvVar2 + _Size,param_3,&param_4);

      memmove(pvVar2,param_2,*(int *)(param_1 + 8) - (int)param_2);

      pvVar2 = *(void **)(param_1 + 4);

      if (pvVar2 == (void *)0x0) {

        iVar1 = 0;

      }

      else {

        iVar1 = *(int *)(param_1 + 8) - (int)pvVar2;

      }

      if (pvVar2 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar2);

      }

      *(uint *)(param_1 + 0xc) = (int)_Dst + local_4;

      *(uint *)(param_1 + 8) = (int)_Dst + param_3 + iVar1;

      *(void **)(param_1 + 4) = _Dst;

      return;

    }

    iVar1 = *(int *)(param_1 + 8);

    if ((uint)(iVar1 - (int)param_2) < param_3) {

      FUN_00447d00(param_2,iVar1,(int)param_2 + param_3);

      FUN_00446a20(*(int *)(param_1 + 8),(int)param_2 + (param_3 - *(int *)(param_1 + 8)),&param_4);

      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + param_3;

      FUN_00447d30(param_2,*(int *)(param_1 + 8) - param_3,&param_4);

      return;

    }

    uVar3 = FUN_00447d00(iVar1 - param_3,iVar1,iVar1);

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar3;

    FUN_00447d50(param_2,iVar1 - param_3,iVar1);

    FUN_00447d30(param_2,(int)param_2 + param_3,&param_4);

  }

  return;

}
