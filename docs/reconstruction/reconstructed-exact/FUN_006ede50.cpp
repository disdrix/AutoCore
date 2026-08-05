// =============================================================================
// FUN_006ede50
// -----------------------------------------------------------------------------
// Stable ID: aa_006ede50
// Address:   0x006ede50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006ede50 @ 0x006ede50
// Stable ID: aa_006ede50
// Embedded strings (evidence for future rename):
//   - "TthkBvAgent"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: rdtsc×2, FUN_006ede50.
//  - Strings: "TthkBvAgent".
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

void __thiscall

FUN_006ede50(int param_1,int *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5)



{

  uint64_t uVar1;

  uint32_t /* width from decompiler */ local_10;

  int local_c;

  int local_8;

  int *local_4;

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "TthkBvAgent";

    uVar1 = rdtsc();

    DAT_00bc5644[1] = (int)uVar1;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  local_8 = param_2[2];

  local_4 = param_2;

  local_c = param_2[1];

  local_10 = *(uint32_t /* width from decompiler */ *)(*param_2 + 0xc);

  (**(code **)(**(int **)(param_1 + 0xc) + 4))(&local_10,param_3,param_4,param_5);

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d2878;

    uVar1 = rdtsc();

    DAT_00bc5644[1] = (int)uVar1;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  return;

}
