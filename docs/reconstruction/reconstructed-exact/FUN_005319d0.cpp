// =============================================================================
// FUN_005319d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005319d0
// Address:   0x005319d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005319d0 @ 0x005319d0
// Stable ID: aa_005319d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×7, return×2, goto×1.
//  - Notable callees: CNDHash_LookupByKey, Client_SendLogicUiPacket, FUN_00522b30, FUN_005319d0, __RTDynamicCast.
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

uint32_t /* width from decompiler */ __thiscall

FUN_005319d0(int param_1,uint param_2,int param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5,

            uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7)



{

  int *piVar1;

  char cVar2;

  void *pvVar3;

  int iVar4;

  int local_138 [7];

  uint32_t /* width from decompiler */ local_11c;

  uint local_118;

  int local_114;

  

  if (*(char *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) + 0x7e) != '\0') {

    pvVar3 = CNDHash_LookupByKey(*(void **)(param_1 + 0x548),param_2);

    if (pvVar3 != (void *)0x0) {

      if (*(int *)((int)pvVar3 + 0x158) == 0) {

        iVar4 = 0;

      }

      else {

        iVar4 = *(int *)((int)pvVar3 + 0x15c) - *(int *)((int)pvVar3 + 0x158) >> 2;

      }

      if (param_3 < iVar4) {

        piVar1 = *(int **)(*(int *)((int)pvVar3 + 0x158) + param_3 * 4);

        iVar4 = (**(code **)(*piVar1 + 0x50))();

        if (iVar4 == 0xc) {

          iVar4 = __RTDynamicCast(piVar1,0,&CVOGObjectiveRequirement::RTTI_Type_Descriptor,

                                  &CVOGObjectiveRequirement_UseItem::RTTI_Type_Descriptor,0);

          if (*(int *)(iVar4 + 0x34) != 0) {

            cVar2 = FUN_00522b30(*(int *)(iVar4 + 0x34),param_4,param_5,param_6,param_7,

                                 *(uint8_t *)(iVar4 + 0x3c));

            if (cVar2 != '\0') goto LAB_00531abb;

          }

        }

      }

    }

    return 0;

  }

LAB_00531abb:

  local_114 = (int)param_2 >> 0x1f;

  local_118 = param_2;

  local_11c = 0xe;

  local_138[0] = param_3;

  Client_SendLogicUiPacket(local_138);

  return 1;

}
