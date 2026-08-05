// =============================================================================
// FUN_005b2c10
// -----------------------------------------------------------------------------
// Stable ID: aa_005b2c10
// Address:   0x005b2c10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b2c10 @ 0x005b2c10
// Stable ID: aa_005b2c10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~63 non-empty decompiler lines.
//  - Control keywords: if×7, for×2, return×2.
//  - Notable callees: memmove×4, FUN_005b2a80, FUN_005b2c10.
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

void __thiscall FUN_005b2c10(int param_1,uint param_2)



{

  size_t sVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ *_Dst;

  void *pvVar3;

  uint uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int iVar6;

  uint32_t /* width from decompiler */ *puVar7;

  

  uVar2 = *(uint *)(param_1 + 8);

  if (0xfffffff - uVar2 < param_2) {

    uVar2 = FUN_005b2a80();

  }

  uVar4 = uVar2 >> 1;

  if (uVar4 < 8) {

    uVar4 = 8;

  }

  if ((param_2 < uVar4) && (uVar2 <= 0xfffffff - uVar4)) {

    param_2 = uVar4;

  }

  uVar4 = *(uint *)(param_1 + 0xc) >> 2;

  _Dst = operator_new((uVar2 + param_2) * 4);

  iVar6 = uVar4 * 4;

  pvVar3 = (void *)(iVar6 + *(int *)(param_1 + 4));

  sVar1 = ((*(int *)(param_1 + 8) * 4 - (int)pvVar3) + *(int *)(param_1 + 4) >> 2) * 4;

  pvVar3 = memmove(_Dst + uVar4,pvVar3,sVar1);

  pvVar3 = (void *)((int)pvVar3 + sVar1);

  if (param_2 < uVar4) {

    memmove(pvVar3,*(void **)(param_1 + 4),((int)(param_2 * 4) >> 2) * 4);

    pvVar3 = (void *)(*(int *)(param_1 + 4) + param_2 * 4);

    sVar1 = ((iVar6 - (int)pvVar3) + *(int *)(param_1 + 4) >> 2) * 4;

    pvVar3 = memmove(_Dst,pvVar3,sVar1);

    puVar7 = (uint32_t /* width from decompiler */ *)((int)pvVar3 + sVar1);

    uVar4 = param_2;

  }

  else {

    sVar1 = (iVar6 >> 2) * 4;

    iVar6 = param_2 - uVar4;

    pvVar3 = memmove(pvVar3,*(void **)(param_1 + 4),sVar1);

    puVar5 = (uint32_t /* width from decompiler */ *)((int)pvVar3 + sVar1);

    puVar7 = _Dst;

    if (iVar6 != 0) {

      for (; iVar6 != 0; iVar6 = iVar6 + -1) {

        *puVar5 = 0;

        puVar5 = puVar5 + 1;

      }

    }

  }

  if (uVar4 != 0) {

    for (; uVar4 != 0; uVar4 = uVar4 - 1) {

      *puVar7 = 0;

      puVar7 = puVar7 + 1;

    }

  }

  if (*(void **)(param_1 + 4) == (void *)0x0) {

    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + param_2;

    *(uint32_t /* width from decompiler */ **)(param_1 + 4) = _Dst;

    return;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(param_1 + 4));

}
