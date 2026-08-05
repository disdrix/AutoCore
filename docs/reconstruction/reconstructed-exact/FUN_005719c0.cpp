// =============================================================================
// FUN_005719c0
// -----------------------------------------------------------------------------
// Stable ID: aa_005719c0
// Address:   0x005719c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005719c0 @ 0x005719c0
// Stable ID: aa_005719c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00571010, FUN_005719c0.
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

uint32_t /* width from decompiler */ __thiscall FUN_005719c0(int param_1,byte param_2,byte param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  if ((int)(uint)param_2 < *(int *)(param_1 + 8)) {

    if ((int)(uint)param_3 < *(int *)(param_1 + 0xc)) {

      iVar1 = *(int *)(param_1 + 0xc) * (uint)param_2 + (uint)param_3;

      if ((*(uint *)(*(int *)(param_1 + 0x28) + iVar1 * 8) &

          *(uint *)(*(int *)(param_1 + 0x28) + 4 + iVar1 * 8)) != 0xffffffff) {

        uVar2 = FUN_00571010();

        return uVar2;

      }

    }

  }

  return 0;

}
