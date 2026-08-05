// =============================================================================
// FUN_006e9330
// -----------------------------------------------------------------------------
// Stable ID: aa_006e9330
// Address:   0x006e9330  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006e9330 @ 0x006e9330
// Stable ID: aa_006e9330
// Embedded strings (evidence for future rename):
//   - "TtShapeCollection"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×3, while×1, return×1.
//  - Notable callees: rdtsc×2, FUN_006e9330.
//  - Strings: "TtShapeCollection".
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

FUN_006e9330(int param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,int param_5)



{

  int *piVar1;

  int iVar2;

  uint64_t uVar3;

  int *piVar4;

  uint8_t local_110 [268];

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "TtShapeCollection";

    uVar3 = rdtsc();

    DAT_00bc5644[1] = (int)uVar3;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  piVar1 = (int *)*param_2;

  piVar4 = *(int **)(param_1 + 0xc);

  iVar2 = *(int *)(param_1 + 0x10);

  while (-1 < iVar2 + -1) {

    iVar2 = *piVar4;

    (**(code **)(*piVar1 + 0x34))(iVar2,local_110);

    (**(code **)(*(int *)piVar4[1] + 4))(&stack0xfffffed8,param_3,param_4,param_5);

    if (*(char *)(param_5 + 4) != '\0') break;

    piVar4 = piVar4 + 2;

  }

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d2878;

    uVar3 = rdtsc();

    DAT_00bc5644[1] = (int)uVar3;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  return;

}
