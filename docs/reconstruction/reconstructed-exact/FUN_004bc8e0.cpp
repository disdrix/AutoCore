// =============================================================================
// FUN_004bc8e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004bc8e0
// Address:   0x004bc8e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004bc8e0 @ 0x004bc8e0
// Stable ID: aa_004bc8e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_004bc8e0.
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

void __thiscall FUN_004bc8e0(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  

  if (*(int *)(param_2 + 8) == 0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xc);

  }

  else {

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 8) + 0xc) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xc);

  }

  if (*(int *)(param_2 + 0xc) != 0) {

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 0xc) + 8) = *(uint32_t /* width from decompiler */ *)(param_2 + 8);

    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + -1;

    return;

  }

  uVar1 = *(uint32_t /* width from decompiler */ *)(param_2 + 8);

  *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + -1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = uVar1;

  return;

}
