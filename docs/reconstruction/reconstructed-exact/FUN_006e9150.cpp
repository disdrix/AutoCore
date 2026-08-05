// =============================================================================
// FUN_006e9150
// -----------------------------------------------------------------------------
// Stable ID: aa_006e9150
// Address:   0x006e9150  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006e9150 @ 0x006e9150
// Stable ID: aa_006e9150
// Embedded strings (evidence for future rename):
//   - "TtShapeCollection"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: rdtsc×2, FUN_006e9150.
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

FUN_006e9150(int param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

            uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ param_6)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  uint64_t uVar4;

  uint8_t local_110 [268];

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "TtShapeCollection";

    uVar4 = rdtsc();

    DAT_00bc5644[1] = (int)uVar4;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  piVar1 = (int *)*param_2;

  piVar2 = *(int **)(param_1 + 0xc);

  if (-1 < *(int *)(param_1 + 0x10) + -1) {

    do {

      iVar3 = *piVar2;

      (**(code **)(*piVar1 + 0x34))(iVar3,local_110);

      (**(code **)(*(int *)piVar2[1] + 0xc))(&stack0xfffffed8,param_3,param_4,param_5,param_6);

    } while (iVar3 != 1);

  }

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d2878;

    uVar4 = rdtsc();

    DAT_00bc5644[1] = (int)uVar4;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  return;

}
