// =============================================================================
// Named_CalleeOf_Mission_i_d_q_2d_btn_mission_xml_0082a3a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0082a3a0
// Callee of Mission_i_d_q_2d_btn_mission_xml
// Address:   0x0082a3a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_i_d_q_2d_btn_mission_xml: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0082a3a0, NDUIWindow_ReloadInterface.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Mission_i_d_q_2d_btn_mission_xml
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

void __thiscall Named_CalleeOf_Mission_i_d_q_2d_btn_mission_xml_0082a3a0(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int *piVar3;

  uint8_t local_8 [8];

  

  NDUIWindow_ReloadInterface(param_2);

  if (param_1[0x149] != 0) {

    iVar1 = *(int *)param_1[0x149];

    uVar2 = (**(code **)(*param_1 + 0x140))(local_8,1);

    (**(code **)(iVar1 + 0x138))(uVar2);

  }

  piVar3 = (int *)(**(code **)(*param_1 + 0x140))(local_8,1);

  iVar1 = piVar3[1];

  param_1[0x143] = *piVar3;

  param_1[0x144] = iVar1;

  (**(code **)(*param_1 + 0x34c))();

  return;

}
