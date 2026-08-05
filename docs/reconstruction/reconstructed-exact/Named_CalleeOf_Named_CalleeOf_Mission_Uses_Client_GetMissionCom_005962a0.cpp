// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Mission_Uses_Client_GetMissionCom_005962a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005962a0
// Callee of Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable
// Address:   0x005962a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_004f2c90, FUN_005962a0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Named_CalleeOf_Mission_Uses_Client_GetMissionCom_005962a0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  *param_1 = *param_2;

  FUN_004f2c90(param_2 + 1);

  param_1[0xd] = param_2[0xd];

  param_1[0xe] = param_2[0xe];

  param_1[0xf] = param_2[0xf];

  param_1[0x10] = param_2[0x10];

  param_1[0x11] = param_2[0x11];

  param_1[0x12] = param_2[0x12];

  param_1[0x13] = param_2[0x13];

  param_1[0x14] = param_2[0x14];

  param_1[0x15] = param_2[0x15];

  param_1[0x16] = param_2[0x16];

  param_1[0x17] = param_2[0x17];

  param_1[0x18] = param_2[0x18];

  param_1[0x19] = param_2[0x19];

  param_1[0x1a] = param_2[0x1a];

  param_1[0x1b] = param_2[0x1b];

  param_1[0x1c] = param_2[0x1c];

  param_1[0x1d] = param_2[0x1d];

  puVar2 = param_2 + 0x1e;

  puVar3 = param_1 + 0x1e;

  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  *(uint16_t *)(param_1 + 0x2e) = *(uint16_t *)(param_2 + 0x2e);

  param_1[0x2f] = param_2[0x2f];

  param_1[0x30] = param_2[0x30];

  param_1[0x31] = param_2[0x31];

  param_1[0x32] = param_2[0x32];

  param_1[0x33] = param_2[0x33];

  param_1[0x34] = param_2[0x34];

  param_1[0x35] = param_2[0x35];

  param_1[0x36] = param_2[0x36];

  return param_1;

}
