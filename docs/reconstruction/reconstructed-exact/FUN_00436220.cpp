// =============================================================================
// FUN_00436220
// -----------------------------------------------------------------------------
// Stable ID: aa_00436220
// Address:   0x00436220  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00436220 @ 0x00436220
// Stable ID: aa_00436220
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~10 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00436220.
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ FUN_00436220(void)



{

  int in_EAX;

  uint uVar1;

  

  uVar1 = (*(int *)(in_EAX + 0x4040) + *(int *)(in_EAX + 0x403c)) - 1;

  if (*(uint *)(in_EAX + 0x4038) <= uVar1) {

    return *(uint32_t /* width from decompiler */ *)(*(int *)(in_EAX + 0x4034) + (uVar1 - *(uint *)(in_EAX + 0x4038)) * 4);

  }

  return *(uint32_t /* width from decompiler */ *)(*(int *)(in_EAX + 0x4034) + uVar1 * 4);

}
