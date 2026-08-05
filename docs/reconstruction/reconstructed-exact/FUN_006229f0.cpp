// =============================================================================
// FUN_006229f0
// -----------------------------------------------------------------------------
// Stable ID: aa_006229f0
// Address:   0x006229f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006229f0 @ 0x006229f0
// Stable ID: aa_006229f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00622440, FUN_006228f0, FUN_006229f0.
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

void __thiscall FUN_006229f0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  *(int *)(param_1 + 0x6c8) = *(int *)(param_1 + 0x6c8) + 1;

  if ((float)((uint)*(ushort *)(*(int *)(param_1 + 0x6a0) + (*(uint *)(param_1 + 0x6c8) % 600) * 2)

             % 100) <= *(float *)(param_1 + 0x108) * DAT_00aaa7ac) {

    *(int *)(param_1 + 0x6c0) = *(int *)(param_1 + 0x6c0) + 1;

    if ((int)(uint)*(byte *)(param_1 + 0x102) < *(int *)(param_1 + 0x6c0)) {

      *(uint *)(param_1 + 0x6c0) = (uint)*(byte *)(param_1 + 0x102);

    }

    FUN_006228f0();

  }

  FUN_00622440(param_2);

  return;

}
