// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: Client_RecvLoginCallback_8, FUN_007290e0, FUN_009332b0, OutputDebugStringA.
//  - Strings: "RecvPlayOk\n".
//  - Return sites: 1.

// =============================================================================
// Client_RecvLoginCallback_8
// -----------------------------------------------------------------------------
// Stable ID: aa_00821c30
// Address:   0x00821c30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Client_RecvLoginCallback_8(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  OutputDebugStringA("RecvPlayOk\n");

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c) = param_2;

  *(uint8_t *)(param_1 + 0x4b) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x70) = param_3;

  FUN_009332b0();

  if (DAT_00d1a90c != 0) {

    FUN_007290e0(DAT_00d1a90c);

  }

  return;

}
