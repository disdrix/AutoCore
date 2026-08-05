// =============================================================================
// FUN_005c4f00
// -----------------------------------------------------------------------------
// Stable ID: aa_005c4f00
// Address:   0x005c4f00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005c4f00 @ 0x005c4f00
// Stable ID: aa_005c4f00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~97 non-empty decompiler lines.
//  - Control keywords: if×12, while×3, do×1, return×1.
//  - Notable callees: FUN_00453110, FUN_005c4f00, FUN_005c53b0, FUN_007464e0, FUN_00746520.
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

void __thiscall FUN_005c4f00(int param_1,int *param_2)



{

  float fVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  float *pfVar6;

  int iVar7;

  uint32_t /* width from decompiler */ *puVar8;

  int iVar9;

  int iVar10;

  int iStack_28;

  int iStack_24;

  int iStack_20;

  

  FUN_005c53b0(0);

  iVar2 = (**(code **)(*param_2 + 0xc))();

  fVar1 = *(float *)(iVar2 + 0x9c);

  if (param_2[0x30] == 0) {

    iStack_24 = 0;

  }

  else {

    iStack_24 = param_2[0x31] - param_2[0x30] >> 2;

  }

  iStack_28 = 0;

  if (0 < iStack_24) {

    do {

      puVar3 = (uint32_t /* width from decompiler */ *)0x0;

      iVar2 = *(int *)(param_2[0x30] + iStack_28 * 4);

      if (*(int *)(param_1 + 4) == 0) {

        iVar9 = 0;

      }

      else {

        iVar9 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc;

      }

      FUN_00453110();

      if (*(int *)(iVar2 + 0x14) == 0) {

        iStack_20 = 0;

      }

      else {

        iVar7 = *(int *)(*(int *)(iVar2 + 0x14) + 0x10);

        if (iVar7 == 0) {

          iStack_20 = 0;

        }

        else {

          iStack_20 = *(int *)(iVar7 + 8);

        }

      }

      if ((*(int *)(*(int *)(iVar2 + 0x14) + 0x10) != 0) &&

         (puVar3 = (uint32_t /* width from decompiler */ *)FUN_00746520(), puVar3 != (uint32_t /* width from decompiler */ *)0x0)) {

        iVar10 = 0;

        iVar7 = iVar9 * 0xc;

        puVar8 = puVar3;

        while( true ) {

          if (*(int *)(iVar2 + 0x14) == 0) {

            iVar4 = 0;

          }

          else {

            iVar4 = *(int *)(*(int *)(iVar2 + 0x14) + 0x18);

          }

          if (iVar4 <= iVar10) break;

          puVar5 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 4) + iVar7);

          *puVar5 = *puVar8;

          puVar5[1] = puVar8[1];

          puVar5[2] = puVar8[2];

          iVar10 = iVar10 + 1;

          iVar7 = iVar7 + 0xc;

          puVar8 = (uint32_t /* width from decompiler */ *)((int)puVar8 + iStack_20);

        }

      }

      if (*(int *)(*(int *)(iVar2 + 0x14) + 0x10) != 0) {

        FUN_007464e0();

      }

      if (puVar3 != (uint32_t /* width from decompiler */ *)0x0) {

        iVar7 = 0;

        iVar9 = iVar9 * 0xc;

        while( true ) {

          if (*(int *)(iVar2 + 0x14) == 0) {

            iVar10 = 0;

          }

          else {

            iVar10 = *(int *)(*(int *)(iVar2 + 0x14) + 0x18);

          }

          if (iVar10 <= iVar7) break;

          pfVar6 = (float *)(*(int *)(param_1 + 4) + iVar9);

          *pfVar6 = *(float *)(*(int *)(param_1 + 4) + iVar9) * fVar1;

          pfVar6[1] = pfVar6[1] * fVar1;

          iVar7 = iVar7 + 1;

          pfVar6[2] = pfVar6[2] * fVar1;

          iVar9 = iVar9 + 0xc;

        }

      }

      iStack_28 = iStack_28 + 1;

    } while (iStack_28 < iStack_24);

  }

  return;

}
