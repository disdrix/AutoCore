// =============================================================================
// FUN_00447c10
// -----------------------------------------------------------------------------
// Stable ID: aa_00447c10
// Address:   0x00447c10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00447c10 @ 0x00447c10
// Stable ID: aa_00447c10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: FUN_00435f30, FUN_00447c10, FUN_007693e0.
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

uint32_t /* width from decompiler */ __thiscall FUN_00447c10(int param_1,int param_2,int param_3)



{

  uint32_t /* width from decompiler */ uVar1;

  

  if (*(int *)(param_1 + 0x4044) != 0) {

    if (-1 < param_3 + -1) {

      do {

        FUN_007693e0(param_2);

        param_2 = param_2 + 1;

        param_3 = param_3 + -1;

      } while (param_3 != 0);

    }

    return 0;

  }

  uVar1 = FUN_00435f30(param_2,param_3);

  return uVar1;

}
