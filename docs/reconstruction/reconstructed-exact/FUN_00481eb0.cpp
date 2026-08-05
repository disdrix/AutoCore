// =============================================================================
// FUN_00481eb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00481eb0
// Address:   0x00481eb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00481eb0 @ 0x00481eb0
// Stable ID: aa_00481eb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_00481eb0.
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

void __fastcall FUN_00481eb0(uint32_t /* width from decompiler */ param_1,int param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x44) = 0;

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x4c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x50) = 0;

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x260) = 0xffffffff;

  puVar2 = (uint32_t /* width from decompiler */ *)(param_2 + 0x58);

  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = 0;

    puVar2 = puVar2 + 1;

  }

  *(int *)(param_2 + 0x26c) = *(int *)(param_2 + 0x26c) + 1;

  return;

}
