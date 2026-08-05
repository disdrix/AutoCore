// =============================================================================
// FUN_0063fd60
// -----------------------------------------------------------------------------
// Stable ID: aa_0063fd60
// Address:   0x0063fd60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0063fd60 @ 0x0063fd60
// Stable ID: aa_0063fd60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~96 non-empty decompiler lines.
//  - Control keywords: if×14, do×4, while×4, return×1.
//  - Notable callees: FUN_0063fd60, FUN_00652af0.
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

void __fastcall FUN_0063fd60(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int *piVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int iStack_1c;

  int iStack_10;

  int local_c;

  int local_8;

  uint32_t /* width from decompiler */ local_4;

  

  puVar6 = (uint32_t /* width from decompiler */ *)param_1[6];

  *param_1 = &PTR_FUN_009e3fc4;

  if ((puVar6 != (uint32_t /* width from decompiler */ *)0x0) &&

     (*(short *)((int)puVar6 + 6) = *(short *)((int)puVar6 + 6) + -1,

     *(short *)((int)puVar6 + 6) == 0)) {

    (**(code **)*puVar6)(1);

  }

  local_c = 0;

  local_8 = 0;

  local_4 = 0x80000000;

  (**(code **)(param_1[7] + 0x10))(&local_c);

  iVar1 = local_c;

  iStack_1c = 0;

  if (0 < local_c) {

    do {

      piVar4 = *(int **)(iStack_10 + iStack_1c * 4);

      iVar2 = (**(code **)(*piVar4 + 0x24))();

      iVar5 = 0;

      puVar6 = (uint32_t /* width from decompiler */ *)0x0;

      if (0 < iVar2) {

        do {

          puVar3 = (uint32_t /* width from decompiler */ *)(**(code **)(*piVar4 + 0x20))(iVar5);

          (**(code **)(*DAT_00b05060 + 4))(*puVar3);

          if (iVar5 == 0) {

            puVar6 = puVar3;

          }

          iVar5 = iVar5 + 1;

        } while (iVar5 < iVar2);

      }

      (**(code **)(*DAT_00b05060 + 4))(puVar6);

      *(short *)((int)piVar4 + 6) = *(short *)((int)piVar4 + 6) + -1;

      if (*(short *)((int)piVar4 + 6) == 0) {

        (**(code **)*piVar4)(1);

      }

      iStack_1c = iStack_1c + 1;

    } while (iStack_1c < iVar1);

  }

  iVar1 = param_1[0xe];

  do {

    if (iVar1 == 0) {

      puVar6 = (uint32_t /* width from decompiler */ *)param_1[2];

      if ((puVar6 != (uint32_t /* width from decompiler */ *)0x0) &&

         (*(short *)((int)puVar6 + 6) = *(short *)((int)puVar6 + 6) + -1,

         *(short *)((int)puVar6 + 6) == 0)) {

        (**(code **)*puVar6)(1);

      }

      if (-1 < local_8) {

        (**(code **)(*DAT_00b05060 + 0x14))(iStack_10,local_8 * 4,0x12);

      }

      if (-1 < (int)param_1[0xf]) {

        (**(code **)(*DAT_00b05060 + 0x14))(param_1[0xd],param_1[0xf] * 4,0x12);

      }

      if (-1 < (int)param_1[0xc]) {

        (**(code **)(*DAT_00b05060 + 0x14))(param_1[10],param_1[0xc] << 4,0x12);

      }

      FUN_00652af0();

      if (-1 < (int)param_1[5]) {

        (**(code **)(*DAT_00b05060 + 0x14))(param_1[3],param_1[5] & 0x7fffffff,0x12);

      }

      *param_1 = &PTR_LAB_009cc290;

      return;

    }

    iVar1 = param_1[0xe];

    piVar4 = (int *)param_1[0xd];

    puVar6 = (uint32_t /* width from decompiler */ *)piVar4[iVar1 + -1];

    if (puVar6 != (uint32_t /* width from decompiler */ *)0x0) {

      if ((puVar6[2] == 2) && (iVar2 = 0, 0 < iVar1)) {

        do {

          if ((uint32_t /* width from decompiler */ *)*piVar4 == puVar6) {

            param_1[0xe] = param_1[0xe] + -1;

            *(uint32_t /* width from decompiler */ *)(param_1[0xd] + iVar2 * 4) =

                 *(uint32_t /* width from decompiler */ *)(param_1[0xd] + param_1[0xe] * 4);

            break;

          }

          iVar2 = iVar2 + 1;

          piVar4 = piVar4 + 1;

        } while (iVar2 < iVar1);

      }

      (**(code **)*puVar6)(1);

    }

    iVar1 = param_1[0xe];

  } while( true );

}
