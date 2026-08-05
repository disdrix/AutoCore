// =============================================================================
// FUN_004364b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004364b0
// Address:   0x004364b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004364b0 @ 0x004364b0
// Stable ID: aa_004364b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004364b0, FUN_00436510, FUN_00436920.
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

void __thiscall FUN_004364b0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int in_EAX;

  uint uVar1;

  

  uVar1 = FUN_00436510(param_2,param_3,in_EAX);

  FUN_00436920(uVar1 & 0x1f,*(int *)(param_1 + 8) + (uVar1 >> 5) * 4,in_EAX + uVar1 & 0x1f,

               *(int *)(param_1 + 8) + (in_EAX + uVar1 >> 5) * 4,&stack0x0000000c);

  return;

}
