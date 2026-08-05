// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: Client_RecvLoginOk, FUN_00728840, OutputDebugStringA.
//  - Strings: "RecvLoginOk\n".
//  - Return sites: 1.

// =============================================================================
// Client_RecvLoginOk
// -----------------------------------------------------------------------------
// Stable ID: aa_00821df0
// Address:   0x00821df0  (autoassault.exe, image base 0x400000)
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

void __thiscall Client_RecvLoginOk(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  OutputDebugStringA("RecvLoginOk\n");

  *(uint8_t *)(param_1 + 0x4a) = 2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x50) = param_2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x54) = param_3;

  if (*(int *)(param_1 + 4) != 0) {

    FUN_00728840(*(int *)(param_1 + 4),param_2,param_3);

  }

  return;

}
