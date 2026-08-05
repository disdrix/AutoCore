// =============================================================================
// Named_CalleeOf_Client_PacketDispatch_008091e0
// -----------------------------------------------------------------------------
// Stable ID: aa_008091e0
// Callee of Client_PacketDispatch
// Address:   0x008091e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_PacketDispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_007fca10, FUN_008091e0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_PacketDispatch
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

void Named_CalleeOf_Client_PacketDispatch_008091e0(void)



{

  int iVar1;

  int in_EAX;

  

  iVar1 = *(int *)(in_EAX + 0xe98);

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0xcd8) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0xcdc) = 0xffffffff;

  (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(in_EAX + 0xf40) + 0x1c8))(0);

  (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(in_EAX + 0xf40) + 0x3c0))(0);

  FUN_007fca10();

  return;

}
