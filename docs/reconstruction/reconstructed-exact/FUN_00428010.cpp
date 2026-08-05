// =============================================================================
// FUN_00428010
// -----------------------------------------------------------------------------
// Stable ID: aa_00428010
// Address:   0x00428010  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00428010 @ 0x00428010
// Stable ID: aa_00428010
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00428010.
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

void __fastcall FUN_00428010(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  int in_EAX;

  

  if (*(int *)(in_EAX + 8) == 0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc);

  }

  else {

    *(uint32_t /* width from decompiler */ *)(*(int *)(in_EAX + 8) + 0xc) = *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc);

  }

  if (*(int *)(in_EAX + 0xc) != 0) {

    *(uint32_t /* width from decompiler */ *)(*(int *)(in_EAX + 0xc) + 8) = *(uint32_t /* width from decompiler */ *)(in_EAX + 8);

    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + -1;

    return;

  }

  uVar1 = *(uint32_t /* width from decompiler */ *)(in_EAX + 8);

  *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + -1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = uVar1;

  return;

}
