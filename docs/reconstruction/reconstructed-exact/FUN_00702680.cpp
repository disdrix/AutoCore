// =============================================================================
// FUN_00702680
// -----------------------------------------------------------------------------
// Stable ID: aa_00702680
// Address:   0x00702680  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00702680 @ 0x00702680
// Stable ID: aa_00702680
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×3, do×3, while×3, return×1.
//  - Notable callees: FUN_007023a0×2, FUN_00702680.
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

void __fastcall FUN_00702680(int param_1)



{

  float *pfVar1;

  float *pfVar2;

  uint32_t /* width from decompiler */ uVar3;

  int *piVar4;

  int iVar5;

  int *piVar6;

  

  iVar5 = *(int *)(param_1 + 0x1b0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1b4) = 4;

  piVar6 = &DAT_00a0f050;

  if (iVar5 != *(int *)(param_1 + 0x1b4) * 0x50 + iVar5) {

    do {

      *(int *)(iVar5 + 0x18) = iVar5 + 0x24;

      *(int *)(iVar5 + 0x28) = iVar5 + 0x34;

      piVar4 = (int *)(iVar5 + 0x14);

      *(uint8_t *)(iVar5 + 0x44) = 0;

      *(int **)(iVar5 + 0x38) = piVar4;

      if (piVar4 < (int *)(iVar5 + 0x44)) {

        do {

          piVar4[3] = iVar5;

          *piVar4 = *piVar6 + *(int *)(param_1 + 0x2100);

          piVar4[2] = piVar6[2] + piVar6[1] + 0x14 + *(int *)(param_1 + 0x1b0);

          piVar4 = piVar4 + 4;

          piVar6 = piVar6 + 3;

        } while (piVar4 < (int *)(iVar5 + 0x44));

      }

      iVar5 = iVar5 + 0x50;

    } while (iVar5 != *(int *)(param_1 + 0x1b4) * 0x50 + *(int *)(param_1 + 0x1b0));

  }

  FUN_007023a0();

  pfVar2 = *(float **)(param_1 + 0x2100);

  iVar5 = *(int *)(param_1 + 0x1b0);

  pfVar1 = pfVar2 + 8;

  if (g_flZero <

      (*pfVar2 - pfVar2[8]) * *(float *)(iVar5 + 0xf0) +

      (pfVar2[1] - pfVar2[9]) * *(float *)(iVar5 + 0xf4) +

      (pfVar2[2] - pfVar2[10]) * *(float *)(iVar5 + 0xf8)) {

    *(float **)(iVar5 + 0xb4) = pfVar1;

    *(float **)(iVar5 + 100) = pfVar1;

    *(float **)(iVar5 + 0x14) = pfVar1;

    uVar3 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x2100);

    *(uint32_t /* width from decompiler */ *)(iVar5 + 0x104) = uVar3;

    *(uint32_t /* width from decompiler */ *)(iVar5 + 0x74) = uVar3;

    *(uint32_t /* width from decompiler */ *)(iVar5 + 0x34) = uVar3;

  }

  iVar5 = 4;

  do {

    FUN_007023a0();

    iVar5 = iVar5 + -1;

  } while (iVar5 != 0);

  return;

}
