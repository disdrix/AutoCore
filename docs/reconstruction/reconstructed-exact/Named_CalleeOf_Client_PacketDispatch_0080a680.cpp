// =============================================================================
// Named_CalleeOf_Client_PacketDispatch_0080a680
// -----------------------------------------------------------------------------
// Stable ID: aa_0080a680
// Callee of Client_PacketDispatch
// Address:   0x0080a680  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_PacketDispatch: packet/network helper. Evidence string: "Your convoy leader has politely requested your presence in an arena. Do you want to partic". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Your convoy leader has politely requested your presence in an arena. Do you want to partic"
//   - "Your convoy leader has politely requested your presence in an arena. Do you want to partic"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_007a69d0, FUN_007a6de0, FUN_007fdfb0, FUN_0080a680.
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

void Named_CalleeOf_Client_PacketDispatch_0080a680(uint32_t /* width from decompiler */ param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  

  FUN_007a69d0();

  uVar4 = 0;

  uVar3 = 1;

  uVar2 = 0x4e51;

  uVar1 = FUN_007a6de0("Your convoy leader has politely requested your presence in an arena. Do you want to participate?"

                       ,0xffffffff);

  FUN_007fdfb0(param_1,uVar1,uVar2,uVar3,uVar4);

  return;

}
