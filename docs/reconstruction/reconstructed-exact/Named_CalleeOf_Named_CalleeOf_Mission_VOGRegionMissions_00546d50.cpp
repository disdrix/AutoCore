// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Mission_VOGRegionMissions_00546d50
// -----------------------------------------------------------------------------
// Stable ID: aa_00546d50
// Callee of Named_CalleeOf_Mission_VOGRegionMissions
// Address:   0x00546d50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Mission_VOGRegionMissions: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_00546d50, FUN_00548210, FUN_00548480, FUN_0059dcc0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Mission_VOGRegionMissions
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Mission_VOGRegionMissions_00546d50(void *param_1,int param_2)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  void *local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a4213;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  local_10 = param_1;

  FUN_00548480(*(uint8_t *)(param_2 + 0x130));

  iVar3 = 0;

  if (*(char *)((int)param_1 + 0x130) != '\0') {

    do {

      local_10 = operator_new(0x168);

      local_4 = 0;

      if (local_10 == (void *)0x0) {

        local_10 = (void *)0x0;

      }

      else {

        local_10 = (void *)FUN_0059dcc0(*(uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 0x134) + iVar3 * 4),

                                        param_1);

      }

      iVar1 = *(int *)((int)param_1 + 0x13c);

      local_4 = 0xffffffff;

      if ((iVar1 == 0) ||

         ((uint)(*(int *)((int)param_1 + 0x144) - iVar1 >> 2) <=

          (uint)(*(int *)((int)param_1 + 0x140) - iVar1 >> 2))) {

        FUN_00548210(*(uint32_t /* width from decompiler */ *)((int)param_1 + 0x140),1,&local_10);

      }

      else {

        piVar2 = *(int **)((int)param_1 + 0x140);

        *piVar2 = (int)local_10;

        *(int **)((int)param_1 + 0x140) = piVar2 + 1;

      }

      iVar3 = iVar3 + 1;

    } while (iVar3 < (int)(uint)*(byte *)((int)param_1 + 0x130));

  }

  ExceptionList = local_c;

  return;

}
