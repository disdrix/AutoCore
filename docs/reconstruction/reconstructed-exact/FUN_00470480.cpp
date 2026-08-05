// =============================================================================
// FUN_00470480
// -----------------------------------------------------------------------------
// Stable ID: aa_00470480
// Address:   0x00470480  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00470480 @ 0x00470480
// Stable ID: aa_00470480
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00470480.
//  - Return sites: 1.

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

void __fastcall FUN_00470480(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,int param_3,uint8_t param_4)



{

  int in_EAX;

  

  if ((param_3 != 0) && (in_EAX != 0)) {

    *(byte *)(in_EAX + 8) = *(byte *)(in_EAX + 8) | 0x80;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x70) = param_1;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x74) = param_2;

    *(uint8_t *)(in_EAX + 0x78) = param_4;

  }

  return;

}
