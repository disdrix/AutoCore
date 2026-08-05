// =============================================================================
// FUN_00680dd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00680dd0
// Address:   0x00680dd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00680dd0 @ 0x00680dd0
// Stable ID: aa_00680dd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00680dd0.
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

void __thiscall FUN_00680dd0(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  

  uVar1 = *(uint32_t /* width from decompiler */ *)(param_1 + 4);

  uVar2 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x10);

  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = *(uint32_t /* width from decompiler */ *)(param_2 + 4);

  uVar3 = *(uint32_t /* width from decompiler */ *)(param_1 + 8);

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = *(uint32_t /* width from decompiler */ *)(param_2 + 8);

  uVar4 = *(uint32_t /* width from decompiler */ *)(param_1 + 0xc);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xc);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x10);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0xc) = uVar4;

  *(uint32_t /* width from decompiler */ *)(param_2 + 8) = uVar3;

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x10) = uVar2;

  *(uint32_t /* width from decompiler */ *)(param_2 + 4) = uVar1;

  return;

}
