// =============================================================================
// Named_CalleeOf_Named_netTcpConnection_00681ad0
// -----------------------------------------------------------------------------
// Stable ID: aa_00681ad0
// Callee of Named_netTcpConnection
// Address:   0x00681ad0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_netTcpConnection: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00681ad0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_netTcpConnection
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

void __fastcall Named_CalleeOf_Named_netTcpConnection_00681ad0(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  

  uVar1 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c);

  uVar2 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x20);

  uVar3 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x24);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x70);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x74);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x78);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x78) = uVar3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x70) = uVar1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x74) = uVar2;

  return;

}
