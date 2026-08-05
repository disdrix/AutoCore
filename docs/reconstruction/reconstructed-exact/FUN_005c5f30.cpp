// =============================================================================
// FUN_005c5f30
// -----------------------------------------------------------------------------
// Stable ID: aa_005c5f30
// Address:   0x005c5f30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005c5f30 @ 0x005c5f30
// Stable ID: aa_005c5f30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, while×1, goto×1.
//  - Notable callees: NAN×2, FUN_005a2850, FUN_005c5d40, FUN_005c5f30.
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

void __thiscall FUN_005c5f30(int param_1,uint32_t /* width from decompiler */ *param_2,float *param_3)



{

  float fVar1;

  char cVar2;

  uint32_t /* width from decompiler */ uVar3;

  bool bVar4;

  uint32_t /* width from decompiler */ *puVar5;

  float *pfVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ *puVar8;

  bool bVar9;

  bool bVar10;

  

  pfVar6 = param_3;

  puVar8 = (uint32_t /* width from decompiler */ *)(*(uint32_t /* width from decompiler */ **)(param_1 + 4))[1];

  bVar9 = true;

  bVar10 = true;

  cVar2 = *(char *)((int)puVar8 + 0x15);

  puVar5 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

  while (cVar2 == '\0') {

    fVar1 = (float)puVar8[3];

    bVar9 = fVar1 == *param_3;

    bVar4 = fVar1 < *param_3;

    if (bVar4 || bVar9) {

      puVar7 = (uint32_t /* width from decompiler */ *)puVar8[2];

    }

    else {

      puVar7 = (uint32_t /* width from decompiler */ *)*puVar8;

    }

    bVar10 = !bVar4 && !bVar9;

    bVar9 = (!NAN(fVar1) && !NAN(*param_3)) && (!bVar4 && !bVar9);

    puVar5 = puVar8;

    puVar8 = puVar7;

    cVar2 = *(char *)((int)puVar7 + 0x15);

  }

  param_3 = (float *)puVar5;

  if (bVar9) {

    if (puVar5 == (uint32_t /* width from decompiler */ *)**(int **)(param_1 + 4)) {

      bVar10 = true;

      goto LAB_005c5fb0;

    }

    FUN_005a2850();

  }

  fVar1 = *pfVar6;

  if (fVar1 < param_3[3] || fVar1 == param_3[3]) {

    *(uint8_t *)(param_2 + 1) = 0;

    *param_2 = param_3;

    return;

  }

LAB_005c5fb0:

  puVar8 = (uint32_t /* width from decompiler */ *)FUN_005c5d40(&param_3,bVar10,puVar5,pfVar6);

  uVar3 = *puVar8;

  *(uint8_t *)(param_2 + 1) = 1;

  *param_2 = uVar3;

  return;

}
