// =============================================================================
// Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d_00808910
// -----------------------------------------------------------------------------
// Stable ID: aa_00808910
// Callee of Named_Error_Received_a_packet_of_unknown_type_d_d
// Address:   0x00808910  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Error_Received_a_packet_of_unknown_type_d: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CVOGReaction_TeleportTarget, FUN_00808910.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_Error_Received_a_packet_of_unknown_type_d_d
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

void Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d_00808910(int param_1)



{

  int in_EAX;

  uint32_t /* width from decompiler */ *pTeleportData;

  void *this;

  float fVar1;

  

  pTeleportData = (uint32_t /* width from decompiler */ *)(in_EAX + 0x10);

  *(float *)(in_EAX + 0x14) = *(float *)(in_EAX + 0x14) + g_flLevelUpUiBase_Inferred;

  fVar1 = *(float *)(in_EAX + 0x18) - g_flOne;

  *pTeleportData = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x10);

  *(float *)(in_EAX + 0x18) = fVar1;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x1c) = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x1c);

  this = (void *)(**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xe98) + 4) + 4) + 4 +

                                      *(int *)(param_1 + 0xe98)) + 0x19c))();

  CVOGReaction_TeleportTarget(this,pTeleportData);

  return;

}
