// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvCreateC_008264f0
// -----------------------------------------------------------------------------
// Stable ID: aa_008264f0
// Callee of Named_CalleeOf_Named_CalleeOf_Client_RecvCreateCharacter
// Address:   0x008264f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_RecvCreateCharacter: packet/network helper. Evidence string: "Macro". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Macro"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~79 non-empty decompiler lines.
//  - Control keywords: if×12, goto×4, return×4, do×2, while×2.
//  - Notable callees: FUN_007a69d0, FUN_007a6de0, FUN_008264f0.
//  - Strings: "Macro".
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_RecvCreateCharacter
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RecvCreateC_008264f0(int param_1)



{

  byte bVar1;

  int *piVar2;

  int iVar3;

  byte *pbVar4;

  byte *pbVar5;

  int iVar6;

  bool bVar7;

  char *pcVar8;

  uint32_t /* width from decompiler */ uVar9;

  

  if ((*(int *)(param_1 + 0x548) == 5) && (*(int *)(param_1 + 0x574) != 0)) {

    iVar6 = *(int *)(param_1 + 0x550) + 3000;

    if ((-1 < iVar6) &&

       (((iVar6 < 0xf && ((char *)(&DAT_00d17788)[iVar6] != (char *)0x0)) &&

        (*(char *)(&DAT_00d17788)[iVar6] != '\0')))) {

      iVar3 = (**(code **)(**(int **)(param_1 + 0x574) + 0x1dc))();

      if (iVar3 != 0) {

        pbVar5 = (byte *)(&DAT_00d17788)[iVar6];

        pbVar4 = (byte *)(**(code **)(**(int **)(param_1 + 0x574) + 0x1dc))();

        do {

          bVar1 = *pbVar4;

          bVar7 = bVar1 < *pbVar5;

          if (bVar1 != *pbVar5) {

LAB_00826594:

            iVar3 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);

            goto LAB_00826599;

          }

          if (bVar1 == 0) break;

          bVar1 = pbVar4[1];

          bVar7 = bVar1 < pbVar5[1];

          if (bVar1 != pbVar5[1]) goto LAB_00826594;

          pbVar4 = pbVar4 + 2;

          pbVar5 = pbVar5 + 2;

        } while (bVar1 != 0);

        iVar3 = 0;

LAB_00826599:

        if (iVar3 == 0) {

          return;

        }

      }

      (**(code **)(**(int **)(param_1 + 0x574) + 0x1d8))((&DAT_00d17788)[iVar6],1,1);

      (**(code **)(**(int **)(param_1 + 0x574) + 0x34c))();

      return;

    }

    iVar6 = (**(code **)(**(int **)(param_1 + 0x574) + 0x1dc))();

    if (iVar6 != 0) {

      piVar2 = *(int **)(param_1 + 0x574);

      uVar9 = 0xffffffff;

      pcVar8 = "Macro";

      FUN_007a69d0("Macro",0xffffffff);

      pbVar5 = (byte *)FUN_007a6de0(pcVar8,uVar9);

      pbVar4 = (byte *)(**(code **)(*piVar2 + 0x1dc))();

      do {

        bVar1 = *pbVar4;

        bVar7 = bVar1 < *pbVar5;

        if (bVar1 != *pbVar5) {

LAB_0082662a:

          iVar6 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);

          goto LAB_0082662f;

        }

        if (bVar1 == 0) break;

        bVar1 = pbVar4[1];

        bVar7 = bVar1 < pbVar5[1];

        if (bVar1 != pbVar5[1]) goto LAB_0082662a;

        pbVar4 = pbVar4 + 2;

        pbVar5 = pbVar5 + 2;

      } while (bVar1 != 0);

      iVar6 = 0;

LAB_0082662f:

      if (iVar6 == 0) {

        return;

      }

    }

    (**(code **)(**(int **)(param_1 + 0x574) + 0x1d8))("Macro",1,1);

    (**(code **)(**(int **)(param_1 + 0x574) + 0x34c))();

  }

  return;

}
