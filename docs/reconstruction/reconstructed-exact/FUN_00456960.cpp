// =============================================================================
// FUN_00456960
// -----------------------------------------------------------------------------
// Stable ID: aa_00456960
// Address:   0x00456960  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00456960 @ 0x00456960
// Stable ID: aa_00456960
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~106 non-empty decompiler lines.
//  - Control keywords: if×14, return×4, do×1, while×1, for×1.
//  - Notable callees: memmove×3, FUN_0040c7c0×2, FUN_004651d0×2, FUN_004540b0, FUN_00456960.
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

void __fastcall FUN_00456960(uint param_1,int param_2,uint32_t /* width from decompiler */ *param_3)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ *in_EAX;

  uint uVar2;

  int iVar3;

  void *_Dst;

  void *pvVar4;

  uint32_t /* width from decompiler */ uVar5;

  int extraout_ECX;

  int iVar6;

  uint32_t /* width from decompiler */ *puVar7;

  

  uVar1 = *in_EAX;

  iVar3 = *(int *)(param_2 + 4);

  if (iVar3 == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = *(int *)(param_2 + 0xc) - iVar3 >> 2;

  }

  if (param_1 != 0) {

    if (iVar3 == 0) {

      iVar6 = 0;

    }

    else {

      iVar6 = *(int *)(param_2 + 8) - iVar3 >> 2;

    }

    if (0x3fffffffU - iVar6 < param_1) {

      uVar2 = FUN_004540b0();

      iVar3 = extraout_ECX;

    }

    if (iVar3 == 0) {

      iVar6 = 0;

    }

    else {

      iVar6 = *(int *)(param_2 + 8) - iVar3 >> 2;

    }

    if (uVar2 < iVar6 + param_1) {

      if (0x3fffffff - (uVar2 >> 1) < uVar2) {

        uVar2 = 0;

      }

      else {

        uVar2 = uVar2 + (uVar2 >> 1);

      }

      if (iVar3 == 0) {

        iVar6 = 0;

      }

      else {

        iVar6 = *(int *)(param_2 + 8) - iVar3 >> 2;

      }

      if (uVar2 < iVar6 + param_1) {

        if (iVar3 == 0) {

          iVar3 = 0;

        }

        else {

          iVar3 = *(int *)(param_2 + 8) - iVar3 >> 2;

        }

        uVar2 = iVar3 + param_1;

      }

      _Dst = operator_new(uVar2 * 4);

      memmove(_Dst,*(void **)(param_2 + 4),((int)param_3 - (int)*(void **)(param_2 + 4) >> 2) * 4);

      pvVar4 = (void *)FUN_004651d0();

      memmove(pvVar4,param_3,(*(int *)(param_2 + 8) - (int)param_3 >> 2) * 4);

      pvVar4 = *(void **)(param_2 + 4);

      if (pvVar4 == (void *)0x0) {

        iVar3 = 0;

      }

      else {

        iVar3 = *(int *)(param_2 + 8) - (int)pvVar4 >> 2;

      }

      if (pvVar4 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar4);

      }

      *(void **)(param_2 + 0xc) = (void *)(uVar2 * 4 + (int)_Dst);

      *(void **)(param_2 + 8) = (void *)((int)_Dst + (param_1 + iVar3) * 4);

      *(void **)(param_2 + 4) = _Dst;

      return;

    }

    iVar3 = *(int *)(param_2 + 8);

    if ((uint)(iVar3 - (int)param_3 >> 2) < param_1) {

      FUN_0040c7c0(param_3 + param_1);

      FUN_004651d0();

      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + param_1 * 4;

      puVar7 = (uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 8) + param_1 * -4);

      if (param_3 != puVar7) {

        do {

          *param_3 = uVar1;

          param_3 = param_3 + 1;

        } while (param_3 != puVar7);

        return;

      }

    }

    else {

      uVar5 = FUN_0040c7c0(iVar3);

      *(uint32_t /* width from decompiler */ *)(param_2 + 8) = uVar5;

      iVar6 = (int)((iVar3 + param_1 * -4) - (int)param_3) >> 2;

      memmove((void *)(iVar3 + iVar6 * -4),param_3,iVar6 * 4);

      puVar7 = param_3 + param_1;

      for (; param_3 != puVar7; param_3 = param_3 + 1) {

        *param_3 = uVar1;

      }

    }

  }

  return;

}
