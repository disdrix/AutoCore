// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGReaction_GiveItemByCbid_005776e0
// -----------------------------------------------------------------------------
// Stable ID: aa_005776e0
// Callee of Named_CalleeOf_CVOGReaction_GiveItemByCbid
// Address:   0x005776e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGReaction_GiveItemByCbid: inventory/item helper. Evidence string: "cont_icon_hit_sphere.geo". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "cont_icon_hit_sphere.geo"
//   - "Failed to create geo position pick instance: %s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, for×1.
//  - Notable callees: FUN_005776e0, FUN_00764030, FUN_007a44e0, FUN_00989e00, sprintf.
//  - Strings: "cont_icon_hit_sphere.geo"; "Failed to create geo position pick instance: %s".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGReaction_GiveItemByCbid
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

int __fastcall Named_CalleeOf_Named_CalleeOf_CVOGReaction_GiveItemByCbid_005776e0(int param_1)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  uint8_t *puVar4;

  int iVar5;

  char *pcVar6;

  char *pcVar7;

  void *pvStack_318;

  char local_314 [256];

  char acStack_214 [516];

  void *pvStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a51ae;

  pvStack_c = ExceptionList;

  iVar3 = *(int *)(param_1 + 500);

  pcVar6 = "cont_icon_hit_sphere.geo";

  pcVar7 = local_314;

  for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {

    *(uint32_t /* width from decompiler */ *)pcVar7 = *(uint32_t /* width from decompiler */ *)pcVar6;

    pcVar6 = pcVar6 + 4;

    pcVar7 = pcVar7 + 4;

  }

  *pcVar7 = *pcVar6;

  ExceptionList = &pvStack_c;

  if (iVar3 != 0) {

    pvVar1 = *(void **)(iVar3 + 0x78);

    if (pvVar1 != (void *)0x0) {

      ExceptionList = &pvStack_c;

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    ExceptionList = &pvStack_c;

    if (*(uint32_t /* width from decompiler */ **)(param_1 + 500) != (uint32_t /* width from decompiler */ *)0x0) {

      ExceptionList = &pvStack_c;

      (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 500))(1);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 500) = 0;

  }

  pvStack_318 = operator_new(0x14c);

  uStack_4 = 0;

  if (pvStack_318 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_00764030();

  }

  uStack_4 = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 500) = uVar2;

  FUN_00989e00(&pvStack_318,local_314);

  iVar3 = (**(code **)(**(int **)(param_1 + 500) + 0x5c))(&pvStack_318);

  if (iVar3 < 0) {

    sprintf(acStack_214,"Failed to create geo position pick instance: %s",&pvStack_318);

    FUN_007a44e0(acStack_214,1);

    if (*(uint32_t /* width from decompiler */ **)(param_1 + 500) != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 500))(1);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 500) = 0;

  }

  else {

    (**(code **)(**(int **)(param_1 + 500) + 0x18))(param_1 + 0x1e4);

    puVar4 = operator_new(0xc);

    *puVar4 = 8;

    *(int *)(puVar4 + 4) = param_1;

    *(uint8_t **)(*(int *)(param_1 + 500) + 0x78) = puVar4;

  }

  ExceptionList = pvStack_10;

  return iVar3;

}
