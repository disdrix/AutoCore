// =============================================================================
// FUN_00512af0
// -----------------------------------------------------------------------------
// Stable ID: aa_00512af0
// Address:   0x00512af0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00512af0 @ 0x00512af0
// Stable ID: aa_00512af0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00512af0.
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

void __fastcall FUN_00512af0(int param_1)



{

  int iVar1;

  

  if (DAT_00b03e64 == '\0') {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xc4) =

         *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0xa8) + 0x3c) + 0x3ac);

  }

  iVar1 = *(int *)(param_1 + 0xa8);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc0) = *(uint32_t /* width from decompiler */ *)(*(int *)(iVar1 + 0x3c) + 0x3e4);

  *(uint *)(param_1 + 0x17c) =

       *(uint *)(param_1 + 0x17c) ^

       (((uint)(int)*(short *)(*(int *)(iVar1 + 0x3c) + 0x3f2) >> 0xc & 0xff) << 10 ^

       *(uint *)(param_1 + 0x17c)) & 0x400;

  *(uint16_t *)(param_1 + 0xea) = *(uint16_t *)(*(int *)(iVar1 + 0x3c) + 0x3f0);

  *(uint16_t *)(param_1 + 0xec) = *(uint16_t *)(*(int *)(iVar1 + 0x3c) + 0x3fe);

  *(uint16_t *)(param_1 + 0xee) = *(uint16_t *)(*(int *)(iVar1 + 0x3c) + 0x400);

  *(uint16_t *)(param_1 + 0xf0) = *(uint16_t *)(*(int *)(iVar1 + 0x3c) + 0x402);

  *(uint16_t *)(param_1 + 0xf2) = *(uint16_t *)(*(int *)(iVar1 + 0x3c) + 0x404);

  *(uint16_t *)(param_1 + 0x180) = *(uint16_t *)(*(int *)(iVar1 + 0x3c) + 0x4bc);

  return;

}
