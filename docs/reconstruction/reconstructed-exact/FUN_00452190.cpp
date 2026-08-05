// =============================================================================
// FUN_00452190
// -----------------------------------------------------------------------------
// Stable ID: aa_00452190
// Address:   0x00452190  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00452190 @ 0x00452190
// Stable ID: aa_00452190
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~80 non-empty decompiler lines.
//  - Control keywords: if×9, do×3, while×3, return×3.
//  - Notable callees: FUN_00438140×2, FUN_004129f0, FUN_00452190.
//  - Return sites: 3.

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

void FUN_00452190(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *unaff_EBX;

  byte *pbVar5;

  byte *pbVar6;

  bool bVar7;

  bool bVar8;

  bool bVar9;

  

  puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

  bVar7 = true;

  if (*(char *)((int)puVar2[1] + 0x15) == '\0') {

    puVar1 = (uint32_t /* width from decompiler */ *)puVar2[1];

    do {

      puVar2 = puVar1;

      iVar3 = 0xc;

      bVar7 = false;

      iVar4 = 0;

      bVar8 = true;

      pbVar5 = (byte *)*param_2;

      pbVar6 = (byte *)puVar2[3];

      do {

        if (iVar3 == 0) break;

        iVar3 = iVar3 + -1;

        bVar7 = *pbVar5 < *pbVar6;

        bVar8 = *pbVar5 == *pbVar6;

        pbVar5 = pbVar5 + 1;

        pbVar6 = pbVar6 + 1;

      } while (bVar8);

      if (!bVar8) {

        iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);

      }

      bVar7 = iVar4 < 0;

      if (bVar7) {

        puVar1 = (uint32_t /* width from decompiler */ *)*puVar2;

      }

      else {

        puVar1 = (uint32_t /* width from decompiler */ *)puVar2[2];

      }

    } while (*(char *)((int)puVar1 + 0x15) == '\0');

  }

  if (bVar7) {

    if (puVar2 == (uint32_t /* width from decompiler */ *)**(int **)(param_1 + 4)) {

      puVar2 = (uint32_t /* width from decompiler */ *)FUN_00438140(&param_2,1,puVar2,param_2);

      *unaff_EBX = *puVar2;

      *(uint8_t *)(unaff_EBX + 1) = 1;

      return;

    }

    FUN_004129f0();

  }

  iVar4 = 0xc;

  bVar8 = false;

  iVar3 = 0;

  bVar9 = true;

  pbVar5 = (byte *)puVar2[3];

  pbVar6 = (byte *)*param_2;

  do {

    if (iVar4 == 0) break;

    iVar4 = iVar4 + -1;

    bVar8 = *pbVar5 < *pbVar6;

    bVar9 = *pbVar5 == *pbVar6;

    pbVar5 = pbVar5 + 1;

    pbVar6 = pbVar6 + 1;

  } while (bVar9);

  if (!bVar9) {

    iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);

  }

  if (-1 < iVar3) {

    *unaff_EBX = puVar2;

    *(uint8_t *)(unaff_EBX + 1) = 0;

    return;

  }

  puVar2 = (uint32_t /* width from decompiler */ *)FUN_00438140(&param_2,bVar7,puVar2,param_2);

  *unaff_EBX = *puVar2;

  *(uint8_t *)(unaff_EBX + 1) = 1;

  return;

}
