// =============================================================================
// FUN_00702040
// -----------------------------------------------------------------------------
// Stable ID: aa_00702040
// Address:   0x00702040  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00702040 @ 0x00702040
// Stable ID: aa_00702040
// Embedded strings (evidence for future rename):
//   - "TtPenetration"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: rdtsc×2, FUN_007006a0, FUN_007011d0, FUN_00702040.
//  - Strings: "TtPenetration".
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

uint32_t /* width from decompiler */

FUN_00702040(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

            uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ param_6)



{

  uint64_t uVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "TtPenetration";

    uVar1 = rdtsc();

    DAT_00bc5644[1] = (int)uVar1;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  FUN_007006a0(param_1,param_2,param_3,param_4,param_5);

  uVar2 = FUN_007011d0(param_6);

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d2878;

    uVar1 = rdtsc();

    DAT_00bc5644[1] = (int)uVar1;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  return uVar2;

}
