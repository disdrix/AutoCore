// =============================================================================
// FUN_00756840
// -----------------------------------------------------------------------------
// Stable ID: aa_00756840
// Address:   0x00756840  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00756840 @ 0x00756840
// Stable ID: aa_00756840
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00756840.
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

void FUN_00756840(void)



{

  int in_EAX;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  float local_4;

  

  local_10 = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x80);

  local_c = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x84);

  local_8 = 0;

  local_18 = 0;

  local_14 = 0;

  local_4 = g_flOne;

  (**(code **)(*(int *)*DAT_00d1f044 + 0xbc))((int *)*DAT_00d1f044,&local_18);

  return;

}
