// =============================================================================
// Named_CalleeOf_Client_SkillTrainUiRequest_INFERRED_0083ee40
// -----------------------------------------------------------------------------
// Stable ID: aa_0083ee40
// Callee of Client_SkillTrainUiRequest_INFERRED
// Address:   0x0083ee40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_SkillTrainUiRequest_INFERRED: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_0083ee40.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_SkillTrainUiRequest_INFERRED
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

void __fastcall Named_CalleeOf_Client_SkillTrainUiRequest_INFERRED_0083ee40(uint32_t /* width from decompiler */ param_1,int *param_2,uint8_t param_3)



{

  int iVar1;

  uint8_t in_AL;

  int iVar2;

  int *unaff_EBX;

  int *piVar3;

  

  iVar1 = *unaff_EBX;

  piVar3 = unaff_EBX + 0x146;

  for (iVar2 = 0x18c; iVar2 != 0; iVar2 = iVar2 + -1) {

    *piVar3 = *param_2;

    param_2 = param_2 + 1;

    piVar3 = piVar3 + 1;

  }

  *(uint8_t *)((int)unaff_EBX + 0x4fe) = param_3;

  *(uint8_t *)(unaff_EBX + 0x13f) = in_AL;

  (**(code **)(iVar1 + 0x444))();

  (**(code **)(*unaff_EBX + 0x34c))();

  return;

}
