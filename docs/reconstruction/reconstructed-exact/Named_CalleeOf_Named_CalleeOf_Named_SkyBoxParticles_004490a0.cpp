// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles_004490a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004490a0
// Callee of Named_CalleeOf_Named_SkyBoxParticles
// Address:   0x004490a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_SkyBoxParticles: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~96 non-empty decompiler lines.
//  - Control keywords: if×13, return×4.
//  - Notable callees: FUN_004e2e80×4, FUN_004e2f70×2, FUN_005739b0×2, CONCAT44, FUN_004490a0, FUN_004540b0, FUN_004e24d0.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_SkyBoxParticles
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles_004490a0(int param_1,int param_2,uint param_3,uint32_t /* width from decompiler */ *param_4)



{

  void *pvVar1;

  int iVar2;

  uint uVar3;

  void *pvVar4;

  uint32_t /* width from decompiler */ uVar5;

  int iVar6;

  int iVar7;

  uint64_t uVar8;

  

  param_4 = (uint32_t /* width from decompiler */ *)*param_4;

  iVar6 = *(int *)(param_1 + 4);

  if (iVar6 == 0) {

    iVar2 = 0;

  }

  else {

    iVar2 = *(int *)(param_1 + 0xc) - iVar6 >> 2;

  }

  uVar8 = CONCAT44(iVar6,iVar2);

  if (param_3 != 0) {

    if (iVar6 == 0) {

      iVar6 = 0;

    }

    else {

      iVar6 = *(int *)(param_1 + 8) - iVar6 >> 2;

    }

    if (0x3fffffffU - iVar6 < param_3) {

      uVar8 = FUN_004540b0();

    }

    iVar6 = (int)((ulonglong)uVar8 >> 0x20);

    uVar3 = (uint)uVar8;

    if (iVar6 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = *(int *)(param_1 + 8) - iVar6 >> 2;

    }

    if (uVar3 < iVar2 + param_3) {

      if (0x3fffffff - (uVar3 >> 1) < uVar3) {

        uVar3 = 0;

      }

      else {

        uVar3 = uVar3 + (uVar3 >> 1);

      }

      if (iVar6 == 0) {

        iVar2 = 0;

      }

      else {

        iVar2 = *(int *)(param_1 + 8) - iVar6 >> 2;

      }

      if (uVar3 < iVar2 + param_3) {

        if (iVar6 == 0) {

          iVar6 = 0;

        }

        else {

          iVar6 = *(int *)(param_1 + 8) - iVar6 >> 2;

        }

        uVar3 = iVar6 + param_3;

      }

      pvVar4 = operator_new(uVar3 * 4);

      uVar5 = FUN_004e2e80(*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_2,pvVar4);

      uVar5 = FUN_004e2f70(uVar5,param_3,&param_4);

      FUN_004e2e80(param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 8),uVar5);

      pvVar1 = *(void **)(param_1 + 4);

      if (pvVar1 == (void *)0x0) {

        iVar6 = 0;

      }

      else {

        iVar6 = *(int *)(param_1 + 8) - (int)pvVar1 >> 2;

      }

      if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      *(void **)(param_1 + 4) = pvVar4;

      *(void **)(param_1 + 0xc) = (void *)(uVar3 * 4 + (int)pvVar4);

      *(void **)(param_1 + 8) = (void *)((int)pvVar4 + (param_3 + iVar6) * 4);

      return;

    }

    iVar2 = *(int *)(param_1 + 8);

    iVar6 = param_3 * 4;

    if ((uint)(iVar2 - param_2 >> 2) < param_3) {

      FUN_004e2e80(param_2,iVar2,iVar6 + param_2);

      FUN_004e2f70(*(int *)(param_1 + 8),param_3 - (*(int *)(param_1 + 8) - param_2 >> 2),&param_4);

      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + iVar6;

      FUN_005739b0(param_2,*(int *)(param_1 + 8) + param_3 * -4,&param_4);

      return;

    }

    iVar7 = iVar2 + param_3 * -4;

    uVar5 = FUN_004e2e80(iVar7,iVar2,iVar2);

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar5;

    FUN_004e24d0(param_2,iVar7,iVar2);

    FUN_005739b0(param_2,iVar6 + param_2,&param_4);

  }

  return;

}
