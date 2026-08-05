// =============================================================================
// FUN_00465990
// -----------------------------------------------------------------------------
// Stable ID: aa_00465990
// Address:   0x00465990  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00465990 @ 0x00465990
// Stable ID: aa_00465990
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_00465800, FUN_00465990, FUN_00752370, FUN_00752800.
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

void __thiscall FUN_00465990(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  int iVar1;

  undefined *puVar2;

  int *piVar3;

  int *piVar4;

  uint8_t local_54 [4];

  uint8_t local_50 [76];

  

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = *param_2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = param_2[1];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = param_2[2];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = param_2[3];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = param_2[4];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = param_2[5];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = param_2[6];

  FUN_00465800(local_50,param_1 + 0x14,param_1 + 0x1c);

  piVar4 = *(int **)(param_1 + 8);

  if (piVar4 != *(int **)(param_1 + 0xc)) {

    do {

      iVar1 = *(int *)(*piVar4 + 0x20);

      if ((iVar1 != piVar4[1]) && (piVar4[1] = iVar1, iVar1 != 0)) {

        puVar2 = (undefined *)piVar4[2];

        if ((undefined *)piVar4[2] == (undefined *)0x0) {

          puVar2 = PTR_DAT_00afa2bc;

        }

        piVar3 = (int *)FUN_00752370(local_54,puVar2);

        piVar4[3] = *piVar3;

      }

      if (-1 < piVar4[3]) {

        FUN_00752800(piVar4[3]);

      }

      piVar4 = piVar4 + 4;

    } while (piVar4 != *(int **)(param_1 + 0xc));

  }

  return;

}
