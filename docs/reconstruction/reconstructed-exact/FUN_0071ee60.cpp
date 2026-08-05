// =============================================================================
// FUN_0071ee60
// -----------------------------------------------------------------------------
// Stable ID: aa_0071ee60
// Address:   0x0071ee60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0071ee60 @ 0x0071ee60
// Stable ID: aa_0071ee60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0071ee60.
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

void FUN_0071ee60(void)



{

  uint8_t *in_EAX;

  

  *in_EAX = 0;

  in_EAX[1] = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 4) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x1c) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x20) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x40) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x10) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x14) = 0;

  *(uint16_t *)(in_EAX + 0x18) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x28) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x2c) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x30) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x34) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x38) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x3c) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x44) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x48) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x4c) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x50) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x28) = 0;

  return;

}
