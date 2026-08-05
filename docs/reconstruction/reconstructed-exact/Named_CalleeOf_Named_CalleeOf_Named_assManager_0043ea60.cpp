// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_assManager_0043ea60
// -----------------------------------------------------------------------------
// Stable ID: aa_0043ea60
// Callee of Named_CalleeOf_Named_assManager (+1 other named callers)
// Address:   0x0043ea60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_assManager: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_assManager (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~64 non-empty decompiler lines.
//  - Control keywords: if×7, for×2, return×2.
//  - Notable callees: memmove×4, FUN_00436860, FUN_0043ea60.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_assManager (+1 other named callers)
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

void Named_CalleeOf_Named_CalleeOf_Named_assManager_0043ea60(uint param_1)



{

  size_t sVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ *_Dst;

  void *pvVar3;

  uint uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int unaff_EBX;

  int iVar6;

  uint32_t /* width from decompiler */ *puVar7;

  

  uVar2 = *(uint *)(unaff_EBX + 8);

  if (0xfffffff - uVar2 < param_1) {

    uVar2 = FUN_00436860();

  }

  uVar4 = uVar2 >> 1;

  if (uVar4 < 8) {

    uVar4 = 8;

  }

  if ((param_1 < uVar4) && (uVar2 <= 0xfffffff - uVar4)) {

    param_1 = uVar4;

  }

  uVar4 = *(uint *)(unaff_EBX + 0xc) >> 1;

  _Dst = operator_new((uVar2 + param_1) * 4);

  iVar6 = uVar4 * 4;

  pvVar3 = (void *)(iVar6 + *(int *)(unaff_EBX + 4));

  sVar1 = ((*(int *)(unaff_EBX + 8) * 4 - (int)pvVar3) + *(int *)(unaff_EBX + 4) >> 2) * 4;

  pvVar3 = memmove(_Dst + uVar4,pvVar3,sVar1);

  pvVar3 = (void *)((int)pvVar3 + sVar1);

  if (param_1 < uVar4) {

    memmove(pvVar3,*(void **)(unaff_EBX + 4),((int)(param_1 * 4) >> 2) * 4);

    pvVar3 = (void *)(*(int *)(unaff_EBX + 4) + param_1 * 4);

    sVar1 = ((iVar6 - (int)pvVar3) + *(int *)(unaff_EBX + 4) >> 2) * 4;

    pvVar3 = memmove(_Dst,pvVar3,sVar1);

    puVar7 = (uint32_t /* width from decompiler */ *)((int)pvVar3 + sVar1);

    uVar4 = param_1;

  }

  else {

    sVar1 = (iVar6 >> 2) * 4;

    iVar6 = param_1 - uVar4;

    pvVar3 = memmove(pvVar3,*(void **)(unaff_EBX + 4),sVar1);

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

  if (*(void **)(unaff_EBX + 4) == (void *)0x0) {

    *(int *)(unaff_EBX + 8) = *(int *)(unaff_EBX + 8) + param_1;

    *(uint32_t /* width from decompiler */ **)(unaff_EBX + 4) = _Dst;

    return;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(unaff_EBX + 4));

}
