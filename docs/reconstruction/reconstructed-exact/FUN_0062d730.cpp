// =============================================================================
// FUN_0062d730
// -----------------------------------------------------------------------------
// Stable ID: aa_0062d730
// Address:   0x0062d730  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0062d730 @ 0x0062d730
// Stable ID: aa_0062d730
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~71 non-empty decompiler lines.
//  - Control keywords: if×6, do×3, while×3, goto×1, return×1.
//  - Notable callees: FUN_005b3370, FUN_0062d730, ROUND.
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

void __thiscall FUN_0062d730(int param_1,float *param_2,float *param_3,int *param_4)



{

  uint *puVar1;

  float fVar2;

  uint uVar3;

  int iVar4;

  uint uVar5;

  int *piVar6;

  float *pfVar7;

  uint uVar8;

  int local_3c;

  int local_38;

  uint auStack_2c [3];

  float local_20 [7];

  

  local_20[0] = *param_2;

  local_20[1] = param_2[1];

  local_20[2] = param_2[2];

  local_20[3] = param_2[3];

  pfVar7 = (float *)(param_1 + 0x30);

  iVar4 = 0;

  do {

    uVar5 = (int)ROUND(*pfVar7 * *(float *)((int)local_20 + iVar4)) & 0xfffffffe;

    fVar2 = *pfVar7;

    *(uint *)((int)auStack_2c + iVar4) = uVar5;

    *(float *)((int)local_20 + iVar4) = (float)(int)uVar5 / fVar2;

    iVar4 = iVar4 + 4;

    pfVar7 = pfVar7 + 1;

  } while (iVar4 < 0xc);

  *param_3 = local_20[0];

  param_3[1] = local_20[1];

  param_3[2] = local_20[2];

  param_3[3] = local_20[3];

  piVar6 = (int *)(param_1 + 0x50);

  local_38 = 0;

  do {

    uVar5 = auStack_2c[local_38];

    local_3c = 1;

    if (1 < *piVar6 + -1) {

      do {

        puVar1 = (uint *)(piVar6[-1] + local_3c * 8);

        uVar3 = *puVar1;

        if ((1 < (int)uVar3) && ((int)uVar3 < 0x7ffffffc)) {

          uVar8 = uVar5 + uVar3;

          if ((int)uVar8 < 0) {

            uVar8 = uVar3 & 1;

LAB_0062d851:

            uVar3 = puVar1[1];

            iVar4 = *(int *)(param_1 + 0x40);

            if (param_4[1] == (param_4[2] & 0x7fffffffU)) {

              FUN_005b3370(param_4,4);

            }

            *(uint32_t /* width from decompiler */ *)(*param_4 + param_4[1] * 4) =

                 *(uint32_t /* width from decompiler */ *)(iVar4 + 0x18 + uVar3 * 0x1c);

            param_4[1] = param_4[1] + 1;

          }

          else if (0x7ffffffb < (int)uVar8) {

            uVar8 = uVar3 & 1 | 0x7ffffffc;

            goto LAB_0062d851;

          }

          *puVar1 = uVar8;

        }

        local_3c = local_3c + 1;

      } while (local_3c < *piVar6 + -1);

    }

    local_38 = local_38 + 1;

    piVar6 = piVar6 + 3;

    if (2 < local_38) {

      return;

    }

  } while( true );

}
