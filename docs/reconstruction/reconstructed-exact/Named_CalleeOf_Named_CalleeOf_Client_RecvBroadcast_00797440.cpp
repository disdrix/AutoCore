// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RecvBroadcast_00797440
// -----------------------------------------------------------------------------
// Stable ID: aa_00797440
// Callee of Named_CalleeOf_Client_RecvBroadcast
// Address:   0x00797440  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_RecvBroadcast: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_004270d0, FUN_00427210, FUN_00797440.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_RecvBroadcast
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

void Named_CalleeOf_Named_CalleeOf_Client_RecvBroadcast_00797440(void)



{

  uint32_t /* width from decompiler */ *in_EAX;

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ local_4c [19];

  

  *in_EAX = 0;

  in_EAX[2] = 0;

  in_EAX[10] = 0;

  std::basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>::clear

            ((basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

              *)(in_EAX + 3));

  in_EAX[0x2c] = 0;

  in_EAX[0x29] = 0;

  *(uint8_t *)(in_EAX + 0x2f) = 0;

  FUN_00427210(0);

  puVar2 = in_EAX + 0x18;

  puVar3 = local_4c;

  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  FUN_004270d0();

  return;

}
