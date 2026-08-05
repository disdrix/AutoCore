// =============================================================================
// FUN_0076cd60
// -----------------------------------------------------------------------------
// Stable ID: aa_0076cd60
// Address:   0x0076cd60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0076cd60 @ 0x0076cd60
// Stable ID: aa_0076cd60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0076c500, FUN_0076cd60.
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

void FUN_0076cd60(uint32_t /* width from decompiler */ param_1)



{

  uint32_t /* width from decompiler */ in_EAX;

  uint8_t *unaff_ESI;

  

  *unaff_ESI = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 4) = in_EAX;

  FUN_0076c500(1000000);

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x38) = param_1;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x40) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x44) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x48) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x4c) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x50) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x54) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x58) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x5c) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x60) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 100) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x68) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x6c) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x70) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x74) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x78) = 0;

  return;

}
