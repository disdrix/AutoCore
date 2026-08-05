// =============================================================================
// FUN_00470290
// -----------------------------------------------------------------------------
// Stable ID: aa_00470290
// Address:   0x00470290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00470290 @ 0x00470290
// Stable ID: aa_00470290
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00470290.
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

void __fastcall FUN_00470290(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,int param_3,uint8_t param_4)



{

  int in_EAX;

  

  if ((param_3 != 0) && (in_EAX != 0)) {

    *(byte *)(in_EAX + 9) = *(byte *)(in_EAX + 9) | 1;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 100) = param_1;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x68) = param_2;

    *(uint8_t *)(in_EAX + 0x6c) = param_4;

  }

  return;

}
