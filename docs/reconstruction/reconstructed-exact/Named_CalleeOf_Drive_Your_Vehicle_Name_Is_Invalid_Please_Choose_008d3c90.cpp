// =============================================================================
// Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_008d3c90
// -----------------------------------------------------------------------------
// Stable ID: aa_008d3c90
// Callee of Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_Anoth
// Address:   0x008d3c90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_008cf740, FUN_008cf7f0, FUN_008d3090, FUN_008d3c90, FUN_0096ae20.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_Anoth
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose_008d3c90(void)



{

  float fVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ uVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  int in_EAX;

  int iVar7;

  uint32_t /* width from decompiler */ *puVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  

  if ((DAT_00d1b77c != 0) && (*(int *)(*(int *)(in_EAX + 0x544) + 0x48) != 0)) {

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x568) = 1;

    *(uint8_t *)(in_EAX + 0x5bc) = 1;

    iVar7 = FUN_0096ae20(*(int *)(*(int *)(in_EAX + 0x544) + 0x48) + 0x98);

    piVar2 = *(int **)(*(int *)(in_EAX + 0x544) + 0x48);

    iVar7 = *(int *)(piVar2[0x29] + iVar7 * 4);

    if (iVar7 != 0) {

      uVar3 = *(uint32_t /* width from decompiler */ *)(iVar7 + 0xc0);

      fVar4 = *(float *)(iVar7 + 0xc4);

      fVar5 = *(float *)(iVar7 + 200);

      iVar7 = (**(code **)(*piVar2 + 0x48))();

      fVar9 = *(float *)(in_EAX + 0x5b0) + DAT_00aaaa1c;

      fVar1 = *(float *)(iVar7 + 0x24);

      puVar8 = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(*(int *)(in_EAX + 0x544) + 0x48) + 0x48))();

      iVar7 = DAT_00d1b77c;

      fVar6 = DAT_00aaaa1c;

      fVar10 = (fVar9 * fVar1 - _DAT_00afe830) * _DAT_00afe834;

      fVar11 = fVar10 * DAT_00aaaa1c;

      fVar1 = *(float *)(in_EAX + 0x5b0);

      fVar12 = DAT_00afe82c * DAT_00aaaa1c;

      fVar9 = *(float *)(in_EAX + 0x5b0);

      *(uint32_t /* width from decompiler */ *)(DAT_00d1b77c + 0x600) = *puVar8;

      *(float *)(iVar7 + 0x604) = fVar11 + fVar1 + fVar4;

      *(float *)(iVar7 + 0x608) = fVar12 + fVar9 + fVar5;

      iVar7 = DAT_00d1b77c;

      *(uint32_t /* width from decompiler */ *)(DAT_00d1b77c + 0x5d0) = uVar3;

      *(float *)(iVar7 + 0x5d4) = fVar4;

      *(float *)(iVar7 + 0x5d8) = fVar5;

      *(float *)(DAT_00d1b77c + 0x5d4) =

           fVar10 * fVar6 + *(float *)(DAT_00d1b77c + 0x5d4) + *(float *)(in_EAX + 0x5b0);

      FUN_008cf7f0(0);

      FUN_008cf740();

      *(uint8_t *)(in_EAX + 0x5c0 + *(int *)(in_EAX + 0x568)) = 1;

      FUN_008d3090();

      *(uint8_t *)(in_EAX + 0x5c1) = 1;

    }

  }

  return;

}
