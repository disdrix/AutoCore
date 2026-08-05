// =============================================================================
// FUN_00919ae0
// -----------------------------------------------------------------------------
// Stable ID: aa_00919ae0
// Address:   0x00919ae0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00919ae0 @ 0x00919ae0
// Stable ID: aa_00919ae0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×3, do×2, while×2, return×1.
//  - Notable callees: Client_EvalAutoPatrolWaypoint, FUN_00919ae0.
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

void FUN_00919ae0(int param_1)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  float fVar6;

  float local_1c;

  float local_18;

  uint32_t /* width from decompiler */ local_14;

  uint local_10;

  uint local_c;

  char local_8;

  

  iVar5 = 0;

  if ((((*(char *)(param_1 + 0xce1) != '\0') && (*(int *)((int)DAT_00d1ad10 + 0x11c) != 0)) &&

      (iVar2 = *(int *)((int)DAT_00d1ad10 + 0x120) - *(int *)((int)DAT_00d1ad10 + 0x11c) >> 2,

      iVar2 != 0)) && (0 < iVar2)) {

    piVar3 = (int *)(param_1 + 0xc7c);

    do {

      Client_EvalAutoPatrolWaypoint(DAT_00d1ad10,&local_10,&local_1c);

      if (((local_10 & local_c) == 0xffffffff) && (local_8 == '\0')) {

        (**(code **)(*(int *)*piVar3 + 4))(0);

      }

      else {

        iVar1 = *piVar3;

        *(float *)(iVar1 + 0x508) = local_1c;

        fVar6 = local_18 + g_flLevelUpUiBase_Inferred;

        *(float *)(iVar1 + 0x50c) = local_18;

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x510) = local_14;

        iVar1 = *piVar3;

        *(float *)(iVar1 + 0x514) = local_1c;

        *(float *)(iVar1 + 0x518) = fVar6;

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x51c) = local_14;

        local_18 = fVar6;

        (**(code **)(*(int *)*piVar3 + 0xcc))(1);

        (**(code **)(*(int *)*piVar3 + 0x34c))();

      }

      iVar5 = iVar5 + 1;

      piVar3 = piVar3 + 1;

    } while (iVar5 < iVar2);

  }

  if (iVar5 < 4) {

    puVar4 = (uint32_t /* width from decompiler */ *)(param_1 + 0xc7c + iVar5 * 4);

    iVar5 = 4 - iVar5;

    do {

      (**(code **)(*(int *)*puVar4 + 4))(0);

      puVar4 = puVar4 + 1;

      iVar5 = iVar5 + -1;

    } while (iVar5 != 0);

  }

  return;

}
