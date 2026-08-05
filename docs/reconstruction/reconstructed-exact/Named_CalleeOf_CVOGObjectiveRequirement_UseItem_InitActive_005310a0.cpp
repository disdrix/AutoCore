// =============================================================================
// Named_CalleeOf_CVOGObjectiveRequirement_UseItem_InitActive_005310a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005310a0
// Callee of CVOGObjectiveRequirement_UseItem_InitActive
// Address:   0x005310a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGObjectiveRequirement_UseItem_InitActive: mission/objective helper. Evidence string: "Invalid CBID: %d (bad item)". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Invalid CBID: %d (bad item)"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, while×1.
//  - Notable callees: CONCAT31, CVOGReaction_GiveItemByCbid, Client_SendInventoryAddItem, FUN_00512160, FUN_00513e70, FUN_005310a0, FUN_007a4480, d.
//  - Strings: "Invalid CBID: %d (bad item)".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of CVOGObjectiveRequirement_UseItem_InitActive
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

uint __thiscall Named_CalleeOf_CVOGObjectiveRequirement_UseItem_InitActive_005310a0(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  char cVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint uVar6;

  uint32_t /* width from decompiler */ uVar7;

  

  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1);

  if (*(char *)(iVar1 + 0x7e) != '\0') {

    while (piVar4 = (int *)CVOGReaction_GiveItemByCbid(param_2), piVar4 != (int *)0x0) {

      uVar7 = *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1);

      (**(code **)(*piVar4 + 8))(param_2,uVar7,1);

      iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1);

      uVar6 = *(uint *)(iVar1 + 0xe6e0);

      iVar2 = *(int *)(iVar1 + 0xe6e4);

      *(uint *)(iVar1 + 0xe6e0) = uVar6 + 1;

      *(uint *)(iVar1 + 0xe6e4) = iVar2 + (uint)(0xfffffffe < uVar6);

      FUN_00512160(uVar6,iVar2,1);

      puVar5 = (uint32_t /* width from decompiler */ *)(**(code **)(*piVar4 + 0x1cc))();

      cVar3 = '\0';

      (**(code **)*puVar5)(1,0,0,0,0,0,0,g_flOne,0);

      (**(code **)(*piVar4 + 0x2a4))

                (*(uint32_t /* width from decompiler */ *)

                  (*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) + 0xe4e8));

      (**(code **)(*piVar4 + 0x218))

                (*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1));

      if ((cVar3 == '\0') && (cVar3 = FUN_00513e70(), cVar3 == '\0')) {

        uVar7 = 1;

      }

      (**(code **)(*piVar4 + 0x260))(uVar7);

      Client_SendInventoryAddItem(piVar4,uVar7);

    }

    uVar6 = FUN_007a4480(1,"Invalid CBID: %d (bad item)",param_2);

    return uVar6 & 0xffffff00;

  }

  return CONCAT31((int3)((uint)iVar1 >> 8),1);

}
