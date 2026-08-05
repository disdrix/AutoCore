// =============================================================================
// FUN_00628f70
// -----------------------------------------------------------------------------
// Stable ID: aa_00628f70
// Address:   0x00628f70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00628f70 @ 0x00628f70
// Stable ID: aa_00628f70
// Embedded strings (evidence for future rename):
//   - "TtIntegrate"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×5, do×2, while×2, return×2.
//  - Notable callees: rdtsc×2, FUN_00628f70, FUN_006511b0.
//  - Strings: "TtIntegrate".
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

void __thiscall FUN_00628f70(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  int *piVar2;

  uint64_t uVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  

  puVar5 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x4c);

  puVar1 = puVar5 + *(int *)(param_1 + 0x50);

  if (puVar5 != puVar1) {

    do {

      (**(code **)(*(int *)*puVar5 + 0x14))(param_2 + 0x10);

      puVar5 = puVar5 + 1;

    } while (puVar5 != puVar1);

  }

  if (*(int *)(param_1 + 0x5c) == 0) {

    if (DAT_00bc5644 < DAT_00bc5648) {

      *DAT_00bc5644 = "TtIntegrate";

      uVar3 = rdtsc();

      DAT_00bc5644[1] = (int)uVar3;

      DAT_00bc5644 = DAT_00bc5644 + 3;

    }

    iVar4 = *(int *)(param_1 + 0x40) + -1;

    if (-1 < iVar4) {

      do {

        piVar2 = *(int **)(*(int *)(*(int *)(param_1 + 0x3c) + iVar4 * 4) + 0x3c);

        (**(code **)(*piVar2 + 8))(param_2 + 0x10,*(int *)(param_1 + 0x20) + 0xe0);

        (**(code **)(*piVar2 + 4))(param_2 + 0x10);

        iVar4 = iVar4 + -1;

      } while (-1 < iVar4);

    }

    if (DAT_00bc5644 < DAT_00bc5648) {

      *DAT_00bc5644 = &DAT_009d2878;

      uVar3 = rdtsc();

      DAT_00bc5644[1] = (int)uVar3;

      DAT_00bc5644 = DAT_00bc5644 + 3;

      return;

    }

  }

  else {

    FUN_006511b0(param_2 + 0x10,param_2 + 0x20,param_2 + 0x50,*(int *)(param_1 + 0x20) + 0xe0,

                 param_1,*(uint32_t /* width from decompiler */ *)(param_1 + 0x3c),*(uint32_t /* width from decompiler */ *)(param_1 + 0x40),

                 *(uint32_t /* width from decompiler */ *)(param_1 + 0x58),*(int *)(param_1 + 0x5c));

  }

  return;

}
