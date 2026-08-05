// =============================================================================
// FUN_00929c00
// -----------------------------------------------------------------------------
// Stable ID: aa_00929c00
// Address:   0x00929c00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00929c00 @ 0x00929c00
// Stable ID: aa_00929c00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00929c00.
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

uint32_t /* width from decompiler */ FUN_00929c00(void)



{

  uint32_t /* width from decompiler */ uVar1;

  int in_EAX;

  

  uVar1 = DAT_00aaa6fc;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x18) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x20) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x24) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x54) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x80) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0xac) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x28) = 0;

  *(uint8_t *)(in_EAX + 0x100) = 0;

  *(uint8_t *)(in_EAX + 0x101) = 0;

  *(uint8_t *)(in_EAX + 0x102) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x104) = uVar1;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x108) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x10c) = 0xffffffff;

  return 1;

}
