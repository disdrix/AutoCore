// =============================================================================
// FUN_006edef0
// -----------------------------------------------------------------------------
// Stable ID: aa_006edef0
// Address:   0x006edef0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006edef0 @ 0x006edef0
// Stable ID: aa_006edef0
// Embedded strings (evidence for future rename):
//   - "TthkBvAgent"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: rdtsc×2, FUN_006edef0.
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

void FUN_006edef0(int *param_1,uint32_t /* width from decompiler */ *param_2,int *param_3,uint32_t /* width from decompiler */ param_4)



{

  uint64_t uVar1;

  int iVar2;

  int iVar3;

  int *local_10;

  int local_c;

  int local_8;

  int *local_4;

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "TthkBvAgent";

    uVar1 = rdtsc();

    DAT_00bc5644[1] = (int)uVar1;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  local_8 = param_1[2];

  local_4 = param_1;

  local_10 = *(int **)(*param_1 + 0xc);

  local_c = param_1[1];

  iVar2 = (**(code **)(*local_10 + 0x14))();

  iVar3 = (**(code **)(*(int *)*param_2 + 0x14))();

  (**(code **)(*param_3 + 0x118c + (iVar2 * 0x20 + iVar3) * 4))(&local_10,param_2,param_3,param_4);

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d2878;

    uVar1 = rdtsc();

    DAT_00bc5644[1] = (int)uVar1;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  return;

}
