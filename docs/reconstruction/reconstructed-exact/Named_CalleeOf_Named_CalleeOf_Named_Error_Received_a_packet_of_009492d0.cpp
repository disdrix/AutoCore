// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Error_Received_a_packet_of_009492d0
// -----------------------------------------------------------------------------
// Stable ID: aa_009492d0
// Callee of Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d
// Address:   0x009492d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: Client_GetMissionCompleteAudioTable, FUN_00442fa0, FUN_004962b0, FUN_007246d0, FUN_0079e7d0, FUN_00807710, FUN_0092f360, FUN_00943b80.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d
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

void Named_CalleeOf_Named_CalleeOf_Named_Error_Received_a_packet_of_009492d0(void)



{

  int in_EAX;

  DWORD DVar1;

  

  FUN_0092f360();

  Client_GetMissionCompleteAudioTable();

  FUN_007246d0();

  if (*(uint32_t /* width from decompiler */ **)(in_EAX + 0xc78) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(in_EAX + 0xc78))(1);

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc78) = 0;

  FUN_0079e7d0(*(uint32_t /* width from decompiler */ *)(in_EAX + 0xde8));

  FUN_00943db0();

  FUN_00943b80(0);

  FUN_00442fa0(0,0,0,0,0);

  *(uint8_t *)(*(int *)(*(int *)(in_EAX + 0xe04) + 0xe894) + 0x8c) = 0;

  if ((*(int *)(in_EAX + 0xe04) != 0) && (*(int *)(*(int *)(in_EAX + 0xe04) + 0xe898) != 0)) {

    FUN_004962b0();

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc0) = 1;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc4) = 3;

  DVar1 = GetTickCount();

  DAT_00d17930 = DVar1 + 60000;

  DAT_00d17934 = 1;

  FUN_00807710(in_EAX + 0x618,*(uint32_t /* width from decompiler */ *)(in_EAX + 0x71c));

  return;

}
