// =============================================================================
// FUN_00771de0
// -----------------------------------------------------------------------------
// Stable ID: aa_00771de0
// Address:   0x00771de0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00771de0 @ 0x00771de0
// Stable ID: aa_00771de0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: if×7, do×4, while×4, return×2.
//  - Notable callees: CARRY4×2, FUN_00770490, FUN_00770710, FUN_00770ea0, FUN_00771de0, __allmul.
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

int FUN_00771de0(int *param_1,int *param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  int iVar2;

  uint uVar3;

  uint uVar4;

  uint uVar5;

  uint *puVar6;

  uint *puVar7;

  uint64_t uVar8;

  int local_4;

  

  iVar1 = *param_2;

  if ((param_1[1] < iVar1 * 2) && (iVar2 = FUN_00770490(), iVar2 != 0)) {

    return iVar2;

  }

  do {

    puVar7 = (uint *)param_1[3];

    puVar6 = puVar7 + iVar1;

    uVar5 = 0;

    local_4 = iVar1;

    if (0 < iVar1) {

      do {

        uVar8 = __allmul(*puVar6,0,param_3,0);

        uVar3 = (uint)uVar8 + *puVar7;

        uVar4 = uVar3 + uVar5;

        uVar5 = uVar4 >> 0x1c |

                ((int)((ulonglong)uVar8 >> 0x20) + (uint)CARRY4((uint)uVar8,*puVar7) +

                (uint)CARRY4(uVar3,uVar5)) * 0x10;

        *puVar7 = uVar4 & 0xfffffff;

        puVar6 = puVar6 + 1;

        puVar7 = puVar7 + 1;

        local_4 = local_4 + -1;

      } while (local_4 != 0);

    }

    *puVar7 = uVar5;

    iVar2 = iVar1 + 1;

    if (iVar2 < *param_1) {

      do {

        puVar7 = puVar7 + 1;

        *puVar7 = 0;

        iVar2 = iVar2 + 1;

      } while (iVar2 < *param_1);

    }

    iVar2 = *param_1;

    if (0 < iVar2) {

      do {

        if (*(int *)(param_1[3] + -4 + *param_1 * 4) != 0) break;

        iVar2 = *param_1 + -1;

        *param_1 = iVar2;

      } while (0 < iVar2);

      iVar2 = *param_1;

    }

    if (iVar2 == 0) {

      param_1[2] = 0;

    }

    iVar2 = FUN_00770710();

    if (iVar2 == -1) {

      return 0;

    }

    FUN_00770ea0();

  } while( true );

}
