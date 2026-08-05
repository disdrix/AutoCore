// =============================================================================
// FUN_0067af90
// -----------------------------------------------------------------------------
// Stable ID: aa_0067af90
// Address:   0x0067af90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0067af90 @ 0x0067af90
// Stable ID: aa_0067af90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×7, do×1, while×1, return×1.
//  - Notable callees: FUN_00680c80×5, FUN_00446860, FUN_0067af90.
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

void FUN_0067af90(int param_1,int param_2,byte *param_3,int param_4,int param_5,int param_6)



{

  int iVar1;

  uint8_t *puVar2;

  byte *pbVar3;

  int iVar4;

  uint uVar5;

  

  if ((param_2 != 0) && (*(int *)(param_1 + 0xc) != 0)) {

    FUN_00680c80(param_2,1);

  }

  pbVar3 = param_3;

  if ((param_3 != (byte *)0x0) && (*(int *)(param_1 + 0xc) != 0)) {

    FUN_00680c80(param_3,1);

  }

  if ((param_4 != 0) && (1 < *(uint *)(param_1 + 0xc))) {

    FUN_00680c80(param_4,2);

  }

  iVar4 = param_6;

  uVar5 = 0;

  if (*pbVar3 != 0) {

    do {

      if (*(int *)(param_1 + 0xc) != 0) {

        FUN_00680c80(&param_2,1);

      }

      iVar1 = *(int *)(iVar4 + 4);

      if ((iVar1 == 0) ||

         ((uint)(*(int *)(iVar4 + 0xc) - iVar1) <= (uint)(*(int *)(iVar4 + 8) - iVar1))) {

        FUN_00446860(*(uint32_t /* width from decompiler */ *)(iVar4 + 8),1,&param_2);

      }

      else {

        puVar2 = *(uint8_t **)(iVar4 + 8);

        *puVar2 = (uint8_t)param_2;

        *(uint8_t **)(iVar4 + 8) = puVar2 + 1;

      }

      uVar5 = uVar5 + 1;

    } while (uVar5 != *pbVar3);

  }

  if ((param_5 != 0) && (1 < *(uint *)(param_1 + 0xc))) {

    FUN_00680c80(param_5,2);

  }

  return;

}
