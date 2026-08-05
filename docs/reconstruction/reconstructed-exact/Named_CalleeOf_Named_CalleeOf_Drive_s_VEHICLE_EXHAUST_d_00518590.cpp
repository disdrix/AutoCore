// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Drive_s_VEHICLE_EXHAUST_d_00518590
// -----------------------------------------------------------------------------
// Stable ID: aa_00518590
// Callee of Named_CalleeOf_Drive_s_VEHICLE_EXHAUST_d
// Address:   0x00518590  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Drive_s_VEHICLE_EXHAUST_d: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: CVOGReaction_FailMissionNotify, FUN_004b73c0, FUN_004b75d0, FUN_004b9300, FUN_00518590.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Drive_s_VEHICLE_EXHAUST_d
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Drive_s_VEHICLE_EXHAUST_d_00518590(int *param_1,int param_2,char param_3)



{

  int iVar1;

  int iVar2;

  

  iVar1 = param_2;

  if (param_3 == '\0') {

    *(uint8_t *)(param_2 + 9) = 1;

  }

  else {

    CVOGReaction_FailMissionNotify(&param_2);

  }

  FUN_004b73c0(param_1);

  *(int *)(iVar1 + 0x2c) = param_1[0x29];

  FUN_004b9300(0);

  iVar2 = (**(code **)(*param_1 + 0x210))(0);

  if (iVar2 != 0) {

    iVar2 = (**(code **)(*param_1 + 0x210))(0);

    if (*(int *)(iVar2 + 0x250) != 0) {

      iVar2 = (**(code **)(*param_1 + 0x210))(0);

      if ((*(char *)(*(int *)(iVar2 + 0x250) + 0x103) != '\0') && (*(int *)(iVar1 + 0x230) < 3)) {

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x230) = 3;

      }

    }

  }

  FUN_004b75d0();

  return;

}
