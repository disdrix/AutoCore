// =============================================================================
// FUN_004c4c10
// -----------------------------------------------------------------------------
// Stable ID: aa_004c4c10
// Address:   0x004c4c10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c4c10 @ 0x004c4c10
// Stable ID: aa_004c4c10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004c41c0, FUN_004c4c10.
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

float10 __fastcall FUN_004c4c10(int param_1)



{

  short sVar1;

  int iVar2;

  

  sVar1 = FUN_004c41c0();

  iVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x4fc + param_1) + 0x27c

                      ))();

  return (float10)iVar2 * (float10)DAT_00a0f708 + (float10)((float)(int)sVar1 * 0.6931472);

}
