// =============================================================================
// FUN_00629c40
// -----------------------------------------------------------------------------
// Stable ID: aa_00629c40
// Address:   0x00629c40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00629c40 @ 0x00629c40
// Stable ID: aa_00629c40
// Embedded strings (evidence for future rename):
//   - "TtNarrowPhase"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: if×7, do×1, while×1, return×1.
//  - Notable callees: rdtsc×2, FUN_00629580, FUN_00629c40.
//  - Strings: "TtNarrowPhase".
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

void __thiscall FUN_00629c40(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  uint64_t uVar2;

  int iVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ *local_40 [6];

  int local_28;

  uint32_t /* width from decompiler */ local_24 [2];

  uint uStack_1c;

  int local_18;

  int local_14;

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "TtNarrowPhase";

    uVar2 = rdtsc();

    local_28 = (int)uVar2;

    DAT_00bc5644[1] = local_28;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  FUN_00629580(0x40);

  piVar4 = *(int **)(param_1 + 0x68);

  local_40[0] = local_24;

  iVar3 = *(int *)(param_1 + 0x6c);

  if (-1 < *(int *)(param_1 + 0x6c) + -1) {

    do {

      local_28 = iVar3;

      if (piVar4[2] != 0) {

        local_40[0][1] = 0;

        iVar3 = piVar4[1];

        iVar1 = *piVar4;

        (**(code **)(*(int *)piVar4[2] + 0x10))(iVar1 + -0x10,iVar3 + -0x10,param_2,local_40);

        if (local_40[0][1] != 0) {

          (**(code **)(**(int **)(piVar4[2] + 8) + 0xc))

                    (iVar1 + -0x10,iVar3 + -0x10,param_2,local_40);

        }

      }

      piVar4 = piVar4 + 4;

      local_28 = local_28 + -1;

      iVar3 = local_28;

    } while (local_28 != 0);

  }

  piVar4 = DAT_00b05060;

  iVar3 = local_14 * 0x30;

  if ((iVar3 == 0) || ((local_18 != DAT_00b05060[5] && (DAT_00b05060[5] != 0)))) {

    DAT_00b05060[2] = DAT_00b05060[2] + local_14 * -0x30;

    piVar4[3] = piVar4[3] + iVar3;

  }

  else {

    (**(code **)(*DAT_00b05060 + 0x28))(local_18,iVar3);

  }

  if (-1 < (int)uStack_1c) {

    (**(code **)(*DAT_00b05060 + 0x14))(local_24[0],(uStack_1c & 0x7fffffff) * 0x30,0x12);

  }

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d2878;

    uVar2 = rdtsc();

    DAT_00bc5644[1] = (int)uVar2;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  return;

}
