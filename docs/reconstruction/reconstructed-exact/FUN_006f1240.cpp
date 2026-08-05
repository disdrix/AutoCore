// =============================================================================
// FUN_006f1240
// -----------------------------------------------------------------------------
// Stable ID: aa_006f1240
// Address:   0x006f1240  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f1240 @ 0x006f1240
// Stable ID: aa_006f1240
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~174 non-empty decompiler lines.
//  - Control keywords: if×26, do×1, while×1, return×1.
//  - Notable callees: FUN_005b3300×12, FUN_006cde50, FUN_006f1240.
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

void __thiscall FUN_006f1240(int param_1,int param_2)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  int *piVar4;

  int *piVar5;

  int *piVar6;

  int *piVar7;

  int *piVar8;

  int *piVar9;

  int *piVar10;

  int *piVar11;

  int iVar12;

  uint uVar13;

  uint32_t /* width from decompiler */ *puVar14;

  int iVar15;

  int *piVar16;

  

  FUN_006cde50(param_2);

  *(uint32_t /* width from decompiler */ *)(param_2 + 4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x20);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x10) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x10);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x14) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x14);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x18) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x18);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x1c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c);

  piVar1 = (int *)(param_2 + 0x24);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x20) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x24);

  iVar12 = *(int *)(param_1 + 0x2c);

  uVar13 = *(uint *)(param_2 + 0x2c) & 0x7fffffff;

  if ((int)uVar13 < iVar12) {

    iVar15 = uVar13 * 2;

    if (iVar15 <= iVar12) {

      iVar15 = iVar12;

    }

    FUN_005b3300(piVar1,iVar15,4);

  }

  *(int *)(param_2 + 0x28) = iVar12;

  piVar2 = (int *)(param_2 + 0x30);

  uVar13 = *(uint *)(param_2 + 0x38) & 0x7fffffff;

  if ((int)uVar13 < iVar12) {

    iVar15 = uVar13 * 2;

    if (iVar15 <= iVar12) {

      iVar15 = iVar12;

    }

    FUN_005b3300(piVar2,iVar15,4);

  }

  *(int *)(param_2 + 0x34) = iVar12;

  piVar3 = (int *)(param_2 + 0x3c);

  uVar13 = *(uint *)(param_2 + 0x44) & 0x7fffffff;

  if ((int)uVar13 < iVar12) {

    iVar15 = uVar13 * 2;

    if (iVar15 <= iVar12) {

      iVar15 = iVar12;

    }

    FUN_005b3300(piVar3,iVar15,4);

  }

  *(int *)(param_2 + 0x40) = iVar12;

  piVar4 = (int *)(param_2 + 0x48);

  uVar13 = *(uint *)(param_2 + 0x50) & 0x7fffffff;

  if ((int)uVar13 < iVar12) {

    iVar15 = uVar13 * 2;

    if (iVar15 <= iVar12) {

      iVar15 = iVar12;

    }

    FUN_005b3300(piVar4,iVar15,4);

  }

  *(int *)(param_2 + 0x4c) = iVar12;

  piVar5 = (int *)(param_2 + 0x54);

  uVar13 = *(uint *)(param_2 + 0x5c) & 0x7fffffff;

  if ((int)uVar13 < iVar12) {

    iVar15 = uVar13 * 2;

    if (iVar15 <= iVar12) {

      iVar15 = iVar12;

    }

    FUN_005b3300(piVar5,iVar15,1);

  }

  *(int *)(param_2 + 0x58) = iVar12;

  piVar6 = (int *)(param_2 + 0x60);

  uVar13 = *(uint *)(param_2 + 0x68) & 0x7fffffff;

  if ((int)uVar13 < iVar12) {

    iVar15 = uVar13 * 2;

    if (iVar15 <= iVar12) {

      iVar15 = iVar12;

    }

    FUN_005b3300(piVar6,iVar15,4);

  }

  *(int *)(param_2 + 100) = iVar12;

  piVar7 = (int *)(param_2 + 0x6c);

  uVar13 = *(uint *)(param_2 + 0x74) & 0x7fffffff;

  if ((int)uVar13 < iVar12) {

    iVar15 = uVar13 * 2;

    if (iVar15 <= iVar12) {

      iVar15 = iVar12;

    }

    FUN_005b3300(piVar7,iVar15,4);

  }

  piVar8 = (int *)(param_2 + 0x78);

  *(int *)(param_2 + 0x70) = iVar12;

  uVar13 = *(uint *)(param_2 + 0x80) & 0x7fffffff;

  if ((int)uVar13 < iVar12) {

    iVar15 = uVar13 * 2;

    if (iVar15 <= iVar12) {

      iVar15 = iVar12;

    }

    FUN_005b3300(piVar8,iVar15,4);

  }

  piVar9 = (int *)(param_2 + 0x84);

  *(int *)(param_2 + 0x7c) = iVar12;

  uVar13 = *(uint *)(param_2 + 0x8c) & 0x7fffffff;

  if ((int)uVar13 < iVar12) {

    iVar15 = uVar13 * 2;

    if (iVar15 <= iVar12) {

      iVar15 = iVar12;

    }

    FUN_005b3300(piVar9,iVar15,4);

  }

  *(int *)(param_2 + 0x88) = iVar12;

  piVar10 = (int *)(param_2 + 0x90);

  uVar13 = *(uint *)(param_2 + 0x98) & 0x7fffffff;

  if ((int)uVar13 < iVar12) {

    iVar15 = uVar13 * 2;

    if (iVar15 <= iVar12) {

      iVar15 = iVar12;

    }

    FUN_005b3300(piVar10,iVar15,4);

  }

  *(int *)(param_2 + 0x94) = iVar12;

  piVar11 = (int *)(param_2 + 0x9c);

  uVar13 = *(uint *)(param_2 + 0xa4) & 0x7fffffff;

  if ((int)uVar13 < iVar12) {

    iVar15 = uVar13 * 2;

    if (iVar15 <= iVar12) {

      iVar15 = iVar12;

    }

    FUN_005b3300(piVar11,iVar15,4);

  }

  piVar16 = (int *)(param_2 + 0xa8);

  *(int *)(param_2 + 0xa0) = iVar12;

  uVar13 = *(uint *)(param_2 + 0xb0) & 0x7fffffff;

  if ((int)uVar13 < iVar12) {

    iVar15 = uVar13 * 2;

    if (iVar15 <= iVar12) {

      iVar15 = iVar12;

    }

    FUN_005b3300(piVar16,iVar15,4);

  }

  iVar15 = 0;

  *(int *)(param_2 + 0xac) = iVar12;

  if (0 < iVar12) {

    param_2 = 0;

    do {

      puVar14 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x28) + param_2);

      *(uint32_t /* width from decompiler */ *)(*piVar1 + iVar15 * 4) = *puVar14;

      *(uint32_t /* width from decompiler */ *)(*piVar2 + iVar15 * 4) = puVar14[1];

      *(uint32_t /* width from decompiler */ *)(*piVar3 + iVar15 * 4) = puVar14[2];

      *(uint32_t /* width from decompiler */ *)(*piVar4 + iVar15 * 4) = puVar14[3];

      *(uint8_t *)(iVar15 + *piVar5) = *(uint8_t *)(puVar14 + 4);

      *(uint32_t /* width from decompiler */ *)(*piVar6 + iVar15 * 4) = puVar14[5];

      *(uint32_t /* width from decompiler */ *)(*piVar7 + iVar15 * 4) = puVar14[6];

      *(uint32_t /* width from decompiler */ *)(*piVar8 + iVar15 * 4) = puVar14[7];

      *(uint32_t /* width from decompiler */ *)(*piVar9 + iVar15 * 4) = puVar14[8];

      *(uint32_t /* width from decompiler */ *)(*piVar10 + iVar15 * 4) = puVar14[9];

      *(uint32_t /* width from decompiler */ *)(*piVar11 + iVar15 * 4) = puVar14[10];

      *(uint32_t /* width from decompiler */ *)(*piVar16 + iVar15 * 4) = puVar14[0xb];

      puVar14 = (uint32_t /* width from decompiler */ *)(*piVar8 + iVar15 * 4);

      if ((uint32_t /* width from decompiler */ *)*puVar14 == &DAT_00bc5630) {

        *puVar14 = 0;

        *(uint32_t /* width from decompiler */ *)(*piVar10 + iVar15 * 4) = 0;

      }

      iVar15 = iVar15 + 1;

      param_2 = param_2 + 0x30;

    } while (iVar15 < iVar12);

  }

  return;

}
