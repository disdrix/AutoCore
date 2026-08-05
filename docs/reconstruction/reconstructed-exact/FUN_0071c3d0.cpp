// =============================================================================
// FUN_0071c3d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0071c3d0
// Address:   0x0071c3d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0071c3d0 @ 0x0071c3d0
// Stable ID: aa_0071c3d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~64 non-empty decompiler lines.
//  - Control keywords: if×4, for×4, return×2.
//  - Notable callees: CONCAT31, FUN_0071b060, FUN_0071c3d0.
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

uint FUN_0071c3d0(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  uint in_EAX;

  uint uVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint uVar5;

  uint uVar6;

  uint uVar7;

  int *unaff_EBX;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ *puVar9;

  

  if ((*unaff_EBX != -1) && ((short)in_EAX != 0)) {

    uVar2 = in_EAX & 0xffff;

    uVar7 = uVar2 + 2;

    if (unaff_EBX[6] == 0) {

      pvVar3 = operator_new__(0x400);

      unaff_EBX[6] = (int)pvVar3;

      unaff_EBX[7] = 0x400;

      unaff_EBX[8] = 0;

    }

    if ((uint)(unaff_EBX[7] - unaff_EBX[8]) < uVar7) {

      puVar4 = operator_new__(unaff_EBX[7] + uVar7);

      uVar6 = unaff_EBX[8];

      puVar8 = (uint32_t /* width from decompiler */ *)unaff_EBX[6];

      puVar9 = puVar4;

      for (uVar5 = uVar6 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

        *puVar9 = *puVar8;

        puVar8 = puVar8 + 1;

        puVar9 = puVar9 + 1;

      }

      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

        *(uint8_t *)puVar9 = *(uint8_t *)puVar8;

        puVar8 = (uint32_t /* width from decompiler */ *)((int)puVar8 + 1);

        puVar9 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

      }

      operator_delete__((void *)unaff_EBX[6]);

      unaff_EBX[7] = unaff_EBX[7] + uVar7;

      unaff_EBX[6] = (int)puVar4;

    }

    iVar1 = unaff_EBX[8];

    unaff_EBX[8] = iVar1 + 2;

    puVar8 = (uint32_t /* width from decompiler */ *)(unaff_EBX[6] + iVar1 + 2);

    for (uVar7 = uVar2 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {

      *puVar8 = *param_1;

      param_1 = param_1 + 1;

      puVar8 = puVar8 + 1;

    }

    for (uVar7 = in_EAX & 3; uVar7 != 0; uVar7 = uVar7 - 1) {

      *(uint8_t *)puVar8 = *(uint8_t *)param_1;

      param_1 = (uint32_t /* width from decompiler */ *)((int)param_1 + 1);

      puVar8 = (uint32_t /* width from decompiler */ *)((int)puVar8 + 1);

    }

    if (unaff_EBX[1] != 0) {

      FUN_0071b060();

    }

    *(char *)(unaff_EBX[6] + iVar1) = (char)uVar2 + '\x02';

    *(char *)(unaff_EBX[6] + 1 + iVar1) = (char)(uVar2 + 2 >> 8);

    unaff_EBX[8] = unaff_EBX[8] + uVar2;

    return CONCAT31((int3)(uVar2 >> 8),1);

  }

  return in_EAX & 0xffffff00;

}
