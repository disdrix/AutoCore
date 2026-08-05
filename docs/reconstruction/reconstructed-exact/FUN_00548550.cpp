// =============================================================================
// FUN_00548550
// -----------------------------------------------------------------------------
// Stable ID: aa_00548550
// Address:   0x00548550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00548550 @ 0x00548550
// Stable ID: aa_00548550
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_004c2bb0, FUN_00548550.
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

void __thiscall FUN_00548550(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  iVar1 = *(int *)(param_1 + 0x158);

  if ((iVar1 != 0) &&

     ((uint)(*(int *)(param_1 + 0x15c) - iVar1 >> 2) <

      (uint)(*(int *)(param_1 + 0x160) - iVar1 >> 2))) {

    puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x15c);

    *puVar2 = param_2;

    *(uint32_t /* width from decompiler */ **)(param_1 + 0x15c) = puVar2 + 1;

    return;

  }

  FUN_004c2bb0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x15c),1,&param_2);

  return;

}
