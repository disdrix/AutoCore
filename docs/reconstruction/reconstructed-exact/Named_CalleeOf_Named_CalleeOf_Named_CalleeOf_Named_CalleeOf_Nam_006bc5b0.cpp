// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006bc5b0
// -----------------------------------------------------------------------------
// Stable ID: aa_006bc5b0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x006bc5b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~98 non-empty decompiler lines.
//  - Control keywords: if×9, do×2, while×2, return×1.
//  - Notable callees: FUN_005b3300, FUN_006bc5b0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006bc5b0(int *param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint uVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ *puVar8;

  int iVar9;

  

  uVar4 = param_1[1];

  puVar6 = (uint32_t /* width from decompiler */ *)*param_1;

  iVar9 = uVar4 - 1;

  puVar8 = puVar6;

  if (3 < (int)uVar4) {

    uVar4 = uVar4 >> 2;

    iVar9 = iVar9 + uVar4 * -4;

    do {

      puVar7 = puVar8;

      if ((float)puVar6[3] == g_flZero) {

        uVar1 = puVar6[1];

        uVar2 = puVar6[2];

        uVar3 = puVar6[3];

        puVar7 = puVar8 + 4;

        *puVar8 = *puVar6;

        puVar8[1] = uVar1;

        puVar8[2] = uVar2;

        puVar8[3] = uVar3;

      }

      puVar8 = puVar7;

      if ((float)puVar6[7] == g_flZero) {

        uVar1 = puVar6[5];

        uVar2 = puVar6[6];

        uVar3 = puVar6[7];

        puVar8 = puVar7 + 4;

        *puVar7 = puVar6[4];

        puVar7[1] = uVar1;

        puVar7[2] = uVar2;

        puVar7[3] = uVar3;

      }

      puVar7 = puVar8;

      if ((float)puVar6[0xb] == g_flZero) {

        uVar1 = puVar6[9];

        uVar2 = puVar6[10];

        uVar3 = puVar6[0xb];

        puVar7 = puVar8 + 4;

        *puVar8 = puVar6[8];

        puVar8[1] = uVar1;

        puVar8[2] = uVar2;

        puVar8[3] = uVar3;

      }

      puVar8 = puVar7;

      if ((float)puVar6[0xf] == g_flZero) {

        uVar1 = puVar6[0xd];

        uVar2 = puVar6[0xe];

        uVar3 = puVar6[0xf];

        puVar8 = puVar7 + 4;

        *puVar7 = puVar6[0xc];

        puVar7[1] = uVar1;

        puVar7[2] = uVar2;

        puVar7[3] = uVar3;

      }

      puVar6 = puVar6 + 0x10;

      uVar4 = uVar4 - 1;

    } while (uVar4 != 0);

  }

  if (-1 < iVar9) {

    iVar9 = iVar9 + 1;

    puVar7 = puVar8;

    do {

      puVar8 = puVar7;

      if ((float)puVar6[3] == g_flZero) {

        uVar1 = puVar6[1];

        uVar2 = puVar6[2];

        uVar3 = puVar6[3];

        puVar8 = puVar7 + 4;

        *puVar7 = *puVar6;

        puVar7[1] = uVar1;

        puVar7[2] = uVar2;

        puVar7[3] = uVar3;

      }

      puVar6 = puVar6 + 4;

      iVar9 = iVar9 + -1;

      puVar7 = puVar8;

    } while (iVar9 != 0);

  }

  iVar9 = (int)puVar8 - *param_1 >> 4;

  if ((int)(param_1[2] & 0x7fffffffU) < iVar9) {

    iVar5 = (param_1[2] & 0x7fffffffU) * 2;

    if (iVar5 <= iVar9) {

      iVar5 = iVar9;

    }

    FUN_005b3300(param_1,iVar5,0x10);

  }

  param_1[1] = iVar9;

  return;

}
