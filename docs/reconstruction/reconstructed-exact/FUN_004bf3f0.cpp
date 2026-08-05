// =============================================================================
// FUN_004bf3f0
// -----------------------------------------------------------------------------
// Stable ID: aa_004bf3f0
// Address:   0x004bf3f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004bf3f0 @ 0x004bf3f0
// Stable ID: aa_004bf3f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004bf3f0, FUN_004bf830, memmove.
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

void __fastcall FUN_004bf3f0(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  void *pvVar3;

  

  uVar1 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x590);

  uVar2 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x58c);

  if (*(void **)(param_1 + 0x57c) != *(void **)(param_1 + 0x580)) {

    pvVar3 = memmove(*(void **)(param_1 + 0x57c),*(void **)(param_1 + 0x580),0);

    *(void **)(param_1 + 0x580) = pvVar3;

  }

  FUN_004bf830(*(uint32_t /* width from decompiler */ *)(param_1 + 0x57c),uVar2,uVar1,param_1);

  return;

}
