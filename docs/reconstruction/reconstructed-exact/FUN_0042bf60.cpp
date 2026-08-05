// =============================================================================
// FUN_0042bf60
// -----------------------------------------------------------------------------
// Stable ID: aa_0042bf60
// Address:   0x0042bf60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0042bf60 @ 0x0042bf60
// Stable ID: aa_0042bf60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0042b810, FUN_0042bf60, FUN_0099ee90, malloc.
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

void FUN_0042bf60(uint32_t /* width from decompiler */ param_1)



{

  uint32_t /* width from decompiler */ *in_EAX;

  void *pvVar1;

  

  in_EAX[1] = 0;

  in_EAX[2] = 0;

  *in_EAX = &PTR_LAB_009d7b00;

  in_EAX[4] = 0x5dc;

  pvVar1 = malloc(0x5dc);

  in_EAX[3] = pvVar1;

  *(uint8_t *)(in_EAX + 5) = 1;

  *in_EAX = &PTR_LAB_00a9b340;

  in_EAX[6] = 0;

  in_EAX[7] = 0;

  in_EAX[8] = 0;

  in_EAX[10] = 0;

  *(uint8_t *)(in_EAX + 9) = 0;

  FUN_0042b810(param_1);

  FUN_0099ee90();

  return;

}
