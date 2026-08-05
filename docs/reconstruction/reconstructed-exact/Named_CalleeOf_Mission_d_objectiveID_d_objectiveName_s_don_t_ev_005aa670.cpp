// =============================================================================
// Named_CalleeOf_Mission_d_objectiveID_d_objectiveName_s_don_t_ev_005aa670
// -----------------------------------------------------------------------------
// Stable ID: aa_005aa670
// Callee of Mission_d_objectiveID_d_objectiveName_s_don_t_ever_edit_
// Address:   0x005aa670  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_d_objectiveID_d_objectiveName_s_don_t_ev: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×4, goto×2, do×1, while×1, return×1.
//  - Notable callees: FUN_00404b30, FUN_00541a80, FUN_005aa670, FUN_007bd440, block, wcscpy.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Mission_d_objectiveID_d_objectiveName_s_don_t_ever_edit_
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

/* WARNING: Removing unreachable block (ram,0x005aa728) */



void __fastcall Named_CalleeOf_Mission_d_objectiveID_d_objectiveName_s_don_t_ev_005aa670(int param_1)



{

  uint uVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  wchar_t local_114 [128];

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009a64a5;

  local_10 = ExceptionList;

  local_14 = &stack0xfffffedc;

  uVar1 = *(uint *)(*(int *)(param_1 + 8) + 0xfc);

  ExceptionList = &local_10;

  iVar2 = FUN_00541a80();

  iVar2 = *(int *)(*(int *)(*(int *)(iVar2 + 0x10) + (*(uint *)(iVar2 + 8) & uVar1) * 4) + 4);

  if (iVar2 == 0) {

LAB_005aa6d4:

    iVar2 = 0;

  }

  else {

    do {

      if (uVar1 == *(uint *)(iVar2 + 0x10)) {

        if (iVar2 == 0) goto LAB_005aa6d4;

        iVar2 = *(int *)(iVar2 + 8);

        goto LAB_005aa6db;

      }

      iVar2 = *(int *)(iVar2 + 0xc);

    } while (iVar2 != 0);

    iVar2 = 0;

  }

LAB_005aa6db:

  if (iVar2 != 0) {

    uVar3 = (*(code *)PTR_FUN_00af8c9c)();

    FUN_00404b30(param_1 + 0xc,uVar3);

    wcscpy((wchar_t *)(iVar2 + 0xb4),local_114);

    local_8 = 0;

    FUN_007bd440(iVar2);

  }

  ExceptionList = local_10;

  return;

}
