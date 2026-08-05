// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_007a4480, FUN_00807490, FUN_0092f360, FUN_009332b0.
//  - Strings: "No authentication key".
//  - Return sites: 1.

// =============================================================================
// Auth_No_authentication_key
// -----------------------------------------------------------------------------
// Stable ID: aa_009332b0
// Address:   0x009332b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "No authentication key"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Auth_No_authentication_key(void)



{

  int in_EAX;

  

  FUN_0092f360();

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc0) = 2;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc4) = 3;

  if ((*(char *)(in_EAX + 0x113) == '\0') && (*(char *)(in_EAX + 0xa6) == '\0')) {

    FUN_007a4480(1,"No authentication key");

  }

  FUN_00807490(in_EAX + 0x730,0x6900);

  return;

}
