// =============================================================================
// FUN_007871c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007871c0
// Address:   0x007871c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007871c0 @ 0x007871c0
// Stable ID: aa_007871c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_007871c0.
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

void FUN_007871c0(void)



{

  uint8_t *in_EAX;

  

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x1e8) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x1ec) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x1f0) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 500) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x200) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x204) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x208) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x20c) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x210) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x214) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x218) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x21c) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x228) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x22c) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x230) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x234) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x238) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x23c) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x240) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x244) = 0xffffffff;

  in_EAX[0x248] = 0;

  *in_EAX = 0;

  in_EAX[0x32] = 0;

  in_EAX[0x1c2] = 0;

  in_EAX[0x1d3] = 0;

  return;

}
