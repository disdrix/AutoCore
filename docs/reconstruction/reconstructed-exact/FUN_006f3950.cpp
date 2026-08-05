// =============================================================================
// FUN_006f3950
// -----------------------------------------------------------------------------
// Stable ID: aa_006f3950
// Address:   0x006f3950  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f3950 @ 0x006f3950
// Stable ID: aa_006f3950
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006380a0, FUN_006f3950.
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

uint32_t /* width from decompiler */ __fastcall FUN_006f3950(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  uVar1 = *(uint32_t /* width from decompiler */ *)(param_1 + 0xc);

  uVar2 = (**(code **)*DAT_00b05060)(uVar1,0x23);

  FUN_006380a0(uVar2,(*(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc)) + *(int *)(param_1 + 8),

               uVar1);

  (**(code **)(*DAT_00b05060 + 4))(*(uint32_t /* width from decompiler */ *)(param_1 + 0x10));

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  return uVar2;

}
