// =============================================================================
// FUN_009651b0
// -----------------------------------------------------------------------------
// Stable ID: aa_009651b0
// Address:   0x009651b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009651b0 @ 0x009651b0
// Stable ID: aa_009651b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, do×1, while×1.
//  - Notable callees: FUN_009651b0, FUN_00972fa0, SQRT.
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

int __thiscall

FUN_009651b0(int param_1,float *param_2,float param_3,uint32_t /* width from decompiler */ *param_4,uint32_t /* width from decompiler */ *param_5)



{

  float fVar1;

  float fVar2;

  float fVar3;

  int *piVar4;

  char cVar5;

  uint32_t /* width from decompiler */ uVar6;

  int iVar7;

  uint32_t /* width from decompiler */ *puVar8;

  int local_20;

  float fStack_c;

  float fStack_8;

  float fStack_4;

  

  puVar8 = *(uint32_t /* width from decompiler */ **)(param_1 + 8);

  local_20 = 0;

  iVar7 = 0;

  if (puVar8 != *(uint32_t /* width from decompiler */ **)(param_1 + 0xc)) {

    do {

      piVar4 = (int *)*puVar8;

      cVar5 = (**(code **)*param_5)(piVar4);

      if (cVar5 != '\0') {

        uVar6 = (**(code **)(*piVar4 + 0x48))();

        (**(code **)(*piVar4 + 0xc))(uVar6);

        FUN_00972fa0(uVar6);

        fVar1 = *param_2;

        fVar2 = param_2[1];

        fVar3 = param_2[2];

        iVar7 = (**(code **)(*piVar4 + 0x48))();

        if (SQRT((fStack_c - fVar1) * (fStack_c - fVar1) +

                 (fStack_8 - fVar2) * (fStack_8 - fVar2) + (fStack_4 - fVar3) * (fStack_4 - fVar3))

            < param_3 + *(float *)(iVar7 + 0xc)) {

          local_20 = local_20 + 1;

          iVar7 = (**(code **)*param_4)(piVar4);

          if (iVar7 == 1) {

            return local_20;

          }

        }

      }

      puVar8 = puVar8 + 1;

      iVar7 = local_20;

    } while (puVar8 != *(uint32_t /* width from decompiler */ **)(param_1 + 0xc));

  }

  return iVar7;

}
