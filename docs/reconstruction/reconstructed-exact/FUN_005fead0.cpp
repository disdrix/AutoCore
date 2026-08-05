// =============================================================================
// FUN_005fead0
// -----------------------------------------------------------------------------
// Stable ID: aa_005fead0
// Address:   0x005fead0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005fead0 @ 0x005fead0
// Stable ID: aa_005fead0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005c88b0, FUN_005fead0.
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

void __fastcall FUN_005fead0(int param_1)



{

  int iVar1;

  

  FUN_005c88b0();

  iVar1 = *(int *)(*(int *)(param_1 + -0xdc) + 4);

  *(uint32_t /* width from decompiler */ *)(iVar1 + param_1 + -0x1c) =

       *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar1 + -0x34 + param_1) + 0x3c) + 0x3e4);

  iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0x34 + param_1) + 0x3c);

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x30) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x4c0);

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x2c) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x4c4);

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x28) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x4c8);

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x24) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x4cc);

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x20) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x4d0);

  *(uint16_t *)(param_1 + -0x14) =

       *(uint16_t *)

        (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0x34 + param_1) + 0x3c) +

        0x4d2);

  return;

}
