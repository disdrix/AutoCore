// =============================================================================
// FUN_007a5f00
// -----------------------------------------------------------------------------
// Stable ID: aa_007a5f00
// Address:   0x007a5f00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a5f00 @ 0x007a5f00
// Stable ID: aa_007a5f00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~95 non-empty decompiler lines.
//  - Control keywords: if×8, do×3, while×3, return×2.
//  - Notable callees: FUN_00456960, FUN_007a4e70, FUN_007a5f00, time.
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

void __fastcall FUN_007a5f00(int *param_1)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  char *pcVar5;

  int *piVar6;

  uint32_t /* width from decompiler */ unaff_EBX;

  int *piVar7;

  int iVar8;

  time_t tVar9;

  int *local_3c;

  int *local_2c;

  int *local_28;

  int local_24;

  char local_20 [20];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ac3a2;

  pvStack_c = ExceptionList;

  piVar7 = (int *)0x0;

  ExceptionList = &pvStack_c;

  tVar9 = time((time_t *)0x0);

  local_3c = (int *)0x0;

  local_2c = (int *)0x0;

  local_28 = (int *)0x0;

  local_24 = 0;

  local_4 = 0;

  piVar6 = (int *)param_1[6];

  if (piVar6 != (int *)param_1[7]) {

    do {

      iVar2 = *piVar6;

      if (((*(uint *)(iVar2 + 0x1f0) & *(uint *)(iVar2 + 500)) != 0xffffffff) &&

         (*(int *)(iVar2 + 0x21c) <= (int)tVar9)) {

        if ((local_3c == (int *)0x0) ||

           ((uint)(local_24 - (int)local_2c >> 2) <= (uint)((int)piVar7 - (int)local_3c >> 2))) {

          FUN_00456960(piVar7);

          local_3c = local_2c;

          piVar7 = local_28;

        }

        else {

          *piVar7 = iVar2;

          local_28 = piVar7 + 1;

          local_3c = local_2c;

          piVar7 = local_28;

        }

      }

      piVar6 = piVar6 + 1;

    } while (piVar6 != (int *)param_1[7]);

  }

  piVar6 = local_3c;

  if (local_3c != piVar7) {

    do {

      iVar2 = *local_3c;

      iVar8 = 0;

      if ((*(uint *)(iVar2 + 0x240) & *(uint *)(iVar2 + 0x244)) != 0xffffffff) {

        iVar8 = FUN_007a4e70(*(uint *)(iVar2 + 0x240),*(uint *)(iVar2 + 0x244));

      }

      uVar3 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x208);

      pcVar5 = (char *)(iVar2 + 0x1c2);

      iVar4 = -(int)pcVar5;

      do {

        cVar1 = *pcVar5;

        pcVar5[(int)(local_20 + iVar4)] = cVar1;

        pcVar5 = pcVar5 + 1;

      } while (cVar1 != '\0');

      if (iVar8 == 0) {

        (**(code **)(*param_1 + 0x4c))(iVar2,0,0);

      }

      else {

        (**(code **)(*param_1 + 0x4c))(iVar2,1,iVar8);

        (**(code **)(*param_1 + 0x50))

                  (iVar8,*(uint32_t /* width from decompiler */ *)(iVar2 + 0x228),*(uint32_t /* width from decompiler */ *)(iVar2 + 0x22c),&local_2c,

                   uVar3,unaff_EBX,*(uint32_t /* width from decompiler */ *)(iVar2 + 0x1f0),*(uint32_t /* width from decompiler */ *)(iVar2 + 500),

                   *(uint32_t /* width from decompiler */ *)(iVar2 + 0x1f8));

      }

      (**(code **)(*param_1 + 0x48))(iVar2,iVar8,0);

      if (iVar8 != 0) {

        (**(code **)(*param_1 + 8))(*(uint32_t /* width from decompiler */ *)(iVar8 + 0x200),*(uint32_t /* width from decompiler */ *)(iVar8 + 0x204));

      }

      (**(code **)(*param_1 + 8))(*(uint32_t /* width from decompiler */ *)(iVar2 + 0x200),*(uint32_t /* width from decompiler */ *)(iVar2 + 0x204));

      local_3c = local_3c + 1;

      piVar6 = local_2c;

    } while (local_3c != local_28);

  }

  if (piVar6 == (int *)0x0) {

    ExceptionList = pvStack_c;

    return;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(piVar6);

}
