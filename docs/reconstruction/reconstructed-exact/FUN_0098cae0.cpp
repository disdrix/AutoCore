// =============================================================================
// FUN_0098cae0
// -----------------------------------------------------------------------------
// Stable ID: aa_0098cae0
// Address:   0x0098cae0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0098cae0 @ 0x0098cae0
// Stable ID: aa_0098cae0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~75 non-empty decompiler lines.
//  - Control keywords: if×8, for×2, return×2, do×1, while×1.
//  - Notable callees: CONCAT31, FUN_00796d40, FUN_0098cae0.
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

uint32_t /* width from decompiler */ FUN_0098cae0(void)



{

  short sVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  int unaff_EBX;

  byte *pbVar5;

  uint32_t /* width from decompiler */ *puVar6;

  byte *pbVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ local_108 [65];

  

  *(uint16_t *)(unaff_EBX + 0x77e) = 0;

  iVar2 = FUN_00796d40();

  puVar6 = local_108;

  for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar6 = 0;

    puVar6 = puVar6 + 1;

  }

  if (*(int *)(iVar2 + 0x70) == 0) {

    local_108[0] = 0;

    local_108[1] = 0;

    local_108[2] = 0;

    local_108[3] = 0;

    local_108[4] = 0;

    if (*(int *)(iVar2 + 0x74) == 0) {

      puVar6 = local_108;

      for (iVar3 = 0x44; iVar3 != 0; iVar3 = iVar3 + -1) {

        *puVar6 = 0;

        puVar6 = puVar6 + 1;

      }

      if (*(int *)(iVar2 + 0x78) == 0) {

        return 0;

      }

      piVar4 = *(int **)(iVar2 + 0x78);

      iVar2 = *piVar4;

      uVar8 = 0x110;

    }

    else {

      piVar4 = *(int **)(iVar2 + 0x74);

      iVar2 = *piVar4;

      uVar8 = 0x14;

    }

    (**(code **)(iVar2 + 0x24))(piVar4,uVar8,local_108);

  }

  else {

    (**(code **)(**(int **)(iVar2 + 0x70) + 0x24))(*(int **)(iVar2 + 0x70),0x100,local_108);

  }

  iVar2 = 0;

  pbVar7 = &stack0xfffffeec;

  pbVar5 = (byte *)(unaff_EBX + 0x558);

  do {

    sVar1 = (short)iVar2;

    if ((sVar1 == 0x2a) || (sVar1 == 0x36)) {

      if ((*pbVar7 & 0x80) != 0) {

        *(short *)(unaff_EBX + 0x77e) = sVar1;

      }

    }

    else if (*pbVar7 == *pbVar5) {

      if ((byte *)(uint)*(ushort *)(unaff_EBX + 0x77c) == pbVar5 + (-0x558 - unaff_EBX)) {

        *(uint8_t *)(unaff_EBX + 0x780) = 1;

      }

    }

    else if ((char)*pbVar5 < '\0') {

      *pbVar5 = *pbVar7;

    }

    else {

      *(short *)(unaff_EBX + 0x77c) = sVar1;

    }

    iVar2 = iVar2 + 1;

    pbVar5 = pbVar5 + 1;

    pbVar7 = pbVar7 + 1;

  } while ((ushort)iVar2 < 0xf0);

  return CONCAT31((int3)((uint)iVar2 >> 8),*(char *)(unaff_EBX + 0x780) != '\0');

}
