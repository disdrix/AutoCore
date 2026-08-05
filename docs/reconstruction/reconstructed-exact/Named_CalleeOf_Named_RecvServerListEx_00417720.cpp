// =============================================================================
// Named_CalleeOf_Named_RecvServerListEx_00417720
// -----------------------------------------------------------------------------
// Stable ID: aa_00417720
// Callee of Named_RecvServerListEx
// Address:   0x00417720  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_RecvServerListEx: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~106 non-empty decompiler lines.
//  - Control keywords: if×12, return×4.
//  - Notable callees: FUN_004175f0×2, FUN_004176b0×2, FUN_004179e0×2, FUN_00417a00×2, FUN_00417720, FUN_00418130, FUN_004433e0, FUN_0045c230.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_RecvServerListEx
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_CalleeOf_Named_RecvServerListEx_00417720(int param_1,int param_2,int param_3,int param_4)



{

  void *pvVar1;

  uint uVar2;

  int iVar3;

  int iVar4;

  void *pvVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint uVar7;

  uint extraout_ECX;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bd870;

  local_10 = ExceptionList;

  uVar2 = (param_4 - param_3) / 0x14;

  iVar4 = *(int *)(param_1 + 4);

  if (iVar4 == 0) {

    uVar7 = 0;

  }

  else {

    uVar7 = (*(int *)(param_1 + 0xc) - iVar4) / 0x14;

  }

  if (uVar2 != 0) {

    if (iVar4 == 0) {

      iVar3 = 0;

    }

    else {

      iVar3 = (*(int *)(param_1 + 8) - iVar4) / 0x14;

    }

    ExceptionList = &local_10;

    if (0xcccccccU - iVar3 < uVar2) {

      ExceptionList = &local_10;

      FUN_00418130();

      uVar7 = extraout_ECX;

    }

    if (iVar4 == 0) {

      iVar3 = 0;

    }

    else {

      iVar3 = (*(int *)(param_1 + 8) - iVar4) / 0x14;

    }

    if (uVar7 < iVar3 + uVar2) {

      if (0xccccccc - (uVar7 >> 1) < uVar7) {

        uVar7 = 0;

      }

      else {

        uVar7 = uVar7 + (uVar7 >> 1);

      }

      if (iVar4 == 0) {

        iVar4 = 0;

      }

      else {

        iVar4 = (*(int *)(param_1 + 8) - iVar4) / 0x14;

      }

      if (uVar7 < iVar4 + uVar2) {

        iVar4 = FUN_0045c230();

        uVar7 = iVar4 + uVar2;

      }

      pvVar5 = operator_new(uVar7 * 0x14);

      local_8 = 0;

      FUN_004175f0(*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_2);

      FUN_004179e0(param_3,param_4);

      FUN_004175f0(param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 8));

      local_8 = 0xffffffff;

      pvVar1 = *(void **)(param_1 + 4);

      if (pvVar1 == (void *)0x0) {

        iVar4 = 0;

      }

      else {

        iVar4 = (*(int *)(param_1 + 8) - (int)pvVar1) / 0x14;

      }

      if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      *(void **)(param_1 + 0xc) = (void *)(uVar7 * 0x14 + (int)pvVar5);

      *(void **)(param_1 + 8) = (void *)((int)pvVar5 + (uVar2 + iVar4) * 0x14);

      *(void **)(param_1 + 4) = pvVar5;

      ExceptionList = local_10;

      return;

    }

    iVar4 = *(int *)(param_1 + 8);

    if ((uint)((iVar4 - param_2) / 0x14) < uVar2) {

      FUN_004176b0(param_2,uVar2 * 0x14 + param_2,param_1,local_2c);

      iVar4 = param_3 + ((*(int *)(param_1 + 8) - param_2) / 0x14) * 0x14;

      local_8 = 2;

      FUN_004179e0(iVar4,param_4);

      local_8 = 0xffffffff;

      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + uVar2 * 0x14;

      FUN_00417a00(param_3,iVar4,param_2);

      ExceptionList = local_10;

      return;

    }

    uVar6 = FUN_004176b0(iVar4 + uVar2 * -0x14,iVar4,param_1,local_30);

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar6;

    FUN_004433e0(local_34);

    FUN_00417a00(param_3,param_4,param_2);

  }

  ExceptionList = local_10;

  return;

}
