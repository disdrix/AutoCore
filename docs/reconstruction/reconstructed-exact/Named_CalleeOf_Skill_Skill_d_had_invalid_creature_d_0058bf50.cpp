// =============================================================================
// Named_CalleeOf_Skill_Skill_d_had_invalid_creature_d_0058bf50
// -----------------------------------------------------------------------------
// Stable ID: aa_0058bf50
// Callee of Skill_Skill_d_had_invalid_creature_d (+1 other named callers)
// Address:   0x0058bf50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Skill_Skill_d_had_invalid_creature_d: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Skill_Skill_d_had_invalid_creature_d (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: CVOGHBBase_Start, CVOGHBList_Enqueue, FUN_00501970, FUN_00503780, FUN_0058bf50, Vehicle_CreateWeaponTrackAction.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Skill_Skill_d_had_invalid_creature_d (+1 other named callers)
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

int Named_CalleeOf_Skill_Skill_d_had_invalid_creature_d_0058bf50(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,int param_3)



{

  char cVar1;

  void *pvVar2;

  int iVar3;

  int *piVar4;

  CVOGHBBase *pAction;

  void *unaff_EBP;

  int unaff_retaddr;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a5746;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  pvVar2 = operator_new(0x800);

  local_4 = 0;

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_00501970(1);

  }

  local_4 = 0xffffffff;

  cVar1 = FUN_00503780(param_1,*(uint32_t /* width from decompiler */ *)(param_3 + 0xa4),0);

  if (cVar1 != '\0') {

    piVar4 = (int *)(**(code **)(**(int **)(*(int *)(*(int *)(iVar3 + 4) + 4) + 0xb0 + iVar3) +

                                0x1d8))();

    (**(code **)(*piVar4 + 0xc0))(1,0xffffffff);

    if (*(float *)(unaff_retaddr + 0x164) == g_flZero) {

      *(uint8_t *)((int)piVar4 + 0x309) = 0;

    }

    pvVar2 = operator_new(0x28);

    local_c = (void *)0x1;

    if (pvVar2 == (void *)0x0) {

      pAction = (CVOGHBBase *)0x0;

    }

    else {

      pAction = (CVOGHBBase *)Vehicle_CreateWeaponTrackAction(iVar3);

    }

    local_c = (void *)0xffffffff;

    CVOGHBList_Enqueue(*(void **)(*(int *)(param_3 + 0xa4) + 0xe4ec),pAction);

    CVOGHBBase_Start(pAction);

    ExceptionList = unaff_EBP;

    return *(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3;

  }

  if (iVar3 != 0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3))(1);

  }

  ExceptionList = local_c;

  return 0;

}
