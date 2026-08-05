// =============================================================================
// FUN_006eb9c0
// -----------------------------------------------------------------------------
// Stable ID: aa_006eb9c0
// Address:   0x006eb9c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006eb9c0 @ 0x006eb9c0
// Stable ID: aa_006eb9c0
// Embedded strings (evidence for future rename):
//   - "LtBvTree"
//   - "StNarrowPhase"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×3, for×1, return×1.
//  - Notable callees: rdtsc×3, FUN_006ea6f0, FUN_006eb9c0.
//  - Strings: "LtBvTree"; "StNarrowPhase".
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

FUN_006eb9c0(int param_1,uint32_t /* width from decompiler */ param_2,int *param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5)



{

  uint32_t /* width from decompiler */ *puVar1;

  int *piVar2;

  uint64_t uVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint8_t local_110 [268];

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "LtBvTree";

    uVar3 = rdtsc();

    DAT_00bc5644[1] = (int)uVar3;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  FUN_006ea6f0(param_2,param_3,param_4,&LAB_006ea160);

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "StNarrowPhase";

    uVar3 = rdtsc();

    DAT_00bc5644[1] = (int)uVar3;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  puVar4 = *(uint32_t /* width from decompiler */ **)(param_1 + 0xc);

  puVar1 = puVar4 + *(int *)(param_1 + 0x10) * 3;

  piVar2 = *(int **)(*param_3 + 0xc);

  for (; puVar4 != puVar1; puVar4 = puVar4 + 3) {

    (**(code **)(*piVar2 + 0x34))(*puVar4,local_110);

    (**(code **)(*(int *)puVar4[2] + 8))(param_2,&stack0xfffffed8,param_4,param_5);

  }

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d282c;

    uVar3 = rdtsc();

    DAT_00bc5644[1] = (int)uVar3;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  return;

}
