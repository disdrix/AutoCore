// READABILITY (auto CF):
//  - Body size: ~103 non-empty decompiler lines.
//  - Control keywords: if×11, return×3, for×2.
//  - Notable callees: FUN_008ab9b0×2, Client_NpcDialog_PrepareResponseOpcode, FUN_00547920, FUN_007a69d0, FUN_007a6de0, FUN_0092d580, sprintf.
//  - Strings: "[%d] %s".
//  - Return sites: 3.

// =============================================================================
// Client_NpcDialog_PrepareResponseOpcode
// -----------------------------------------------------------------------------
// Stable ID: aa_008abd70
// Address:   0x008abd70  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
//
// C2S 0x206E chain (static seal 2026-07-29; dual residual strengthen same day):
//   ShowNpcMissionDialogUI @ 0x00943a60 sole caller:
//     ESI = dialog (EBX), ECX = mission def* (EDI) → THIS
//   THIS: *(dialog+0x650)=0x206E (imm @ 0x008abd8c); *(dialog+0x670)=def
//   → MissionDialogHandleButton fills payload
//   → Client_MissionDialog_FlushPreparedResponse @ 0x008ab8f0 sends size 0x20
//   (this unit does NOT send; Flush is teardown peer, not a direct callee)
//   Sole caller always passes nonzero def (Show gate); param==0 chrome retained but not reached from Show.
//   Chain: reviews/CHAIN_2026-07-29_c2s_206e_seal.md
//   Dual residual: tmp/a_008abd70.md
// =============================================================================

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

/* Client_NpcDialog_PrepareResponseOpcode: sets dialog+0x650 = 0x206E for C2S MissionDialogResponse.
   ECX = mission def* (param_1); ESI = dialog UI (caller-framed dual-register).
   Payload body filled later (HandleButton): missionId i32 + accepted bool + pad7 + npc TFID16. */



void __fastcall Client_NpcDialog_PrepareResponseOpcode(int param_1 /* mission def* ; dialog in ESI */)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  int *piVar3;

  int *piVar4;

  int *piVar5;

  int iVar6;

  int unaff_ESI;

  uint32_t /* width from decompiler */ *puVar7;

  float fVar8;

  char local_208 [2];

  uint32_t /* width from decompiler */ local_206 [128];

  

  *(int *)(unaff_ESI + 0x670) = param_1;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x650) = 0x206e;

  if (param_1 == 0) {

    if (*(int **)(unaff_ESI + 0x6dc) != (int *)0x0) {

      (**(code **)(**(int **)(unaff_ESI + 0x6dc) + 0x1b0))();

      iVar6 = *(int *)(unaff_ESI + 0x6dc);

      fVar8 = (float)*(int *)(iVar6 + 0x1bc) * (float)DAT_00d1e81c * DAT_00aaa678;

      *(int *)(iVar6 + 0x170) =

           (int)((float)*(int *)(iVar6 + 0x1b8) * (float)DAT_00d1e818 * DAT_00aaa67c);

      *(int *)(iVar6 + 0x174) = (int)fVar8;

      (**(code **)(**(int **)(unaff_ESI + 0x6dc) + 0x15c))();

      (**(code **)(**(int **)(unaff_ESI + 0x6dc) + 0x1d8))(&DAT_00a1419b,1);

      (**(code **)(**(int **)(unaff_ESI + 0x6dc) + 0x34c))();

    }

  }

  else {

    if (*(char *)(param_1 + 0x168) == '\0') {

      FUN_00547920();

    }

    if (*(int *)(unaff_ESI + 0x6dc) != 0) {

      local_208[0] = '\0';

      local_208[1] = '\0';

      puVar7 = local_206;

      for (iVar6 = 0x7f; iVar6 != 0; iVar6 = iVar6 + -1) {

        *puVar7 = 0;

        puVar7 = puVar7 + 1;

      }

      *(uint16_t *)puVar7 = 0;

      FUN_007a69d0();

      FUN_007a6de0();

      sprintf(local_208,"[%d] %s");

      (**(code **)(**(int **)(unaff_ESI + 0x6dc) + 0x1b0))();

      iVar6 = *(int *)(unaff_ESI + 0x6dc);

      fVar8 = (float)*(int *)(iVar6 + 0x1bc) * (float)DAT_00d1e81c * DAT_00aaa678;

      *(int *)(iVar6 + 0x170) =

           (int)((float)*(int *)(iVar6 + 0x1b8) * (float)DAT_00d1e818 * DAT_00aaa67c);

      *(int *)(iVar6 + 0x174) = (int)fVar8;

      (**(code **)(**(int **)(unaff_ESI + 0x6dc) + 0x1d8))();

      if (DAT_00d1b6d8 != 0) {

        (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) + 0x27c))

                  ();

      }

      iVar6 = **(int **)(unaff_ESI + 0x6dc);

      uVar2 = FUN_0092d580();

      (**(code **)(iVar6 + 0x158))(1,uVar2);

      (**(code **)(**(int **)(unaff_ESI + 0x6dc) + 0x34c))();

      piVar3 = (int *)(**(code **)(**(int **)(unaff_ESI + 0x6dc) + 0x140))(&stack0xfffffdc8,1);

      piVar5 = *(int **)(unaff_ESI + 0x6dc);

      piVar4 = (int *)(**(code **)(*piVar5 + 0x204))(&stack0xfffffdc8);

      if (*piVar3 - piVar5[0x5c] < *piVar4) {

        (**(code **)(**(int **)(unaff_ESI + 0x6dc) + 0x1b0))();

        piVar5 = (int *)(*(int *)(unaff_ESI + 0x6dc) + 0x174);

        *piVar5 = *piVar5 + (*(int *)(DAT_00d1e808 + 0x7c) - *(int *)(DAT_00d1e7e8 + 0x7c));

      }

    }

    if (*(int **)(unaff_ESI + 0x6e4) != (int *)0x0) {

      (**(code **)(**(int **)(unaff_ESI + 0x6e4) + 0x268))();

      (**(code **)(**(int **)(unaff_ESI + 0x6e4) + 0x1b0))();

      cVar1 = FUN_008ab9b0();

      if (cVar1 == '\0') {

        (**(code **)(**(int **)(unaff_ESI + 0x6e4) + 4))();

        if (*(int **)(unaff_ESI + 0x68c) != (int *)0x0) {

          (**(code **)(**(int **)(unaff_ESI + 0x68c) + 4))();

          (**(code **)(**(int **)(unaff_ESI + 0x6e4) + 0x34c))();

          return;

        }

      }

      else {

        (**(code **)(**(int **)(unaff_ESI + 0x6e4) + 0x204))();

        piVar5 = (int *)(**(code **)(**(int **)(unaff_ESI + 0x6e4) + 0x140))();

        if ((*piVar5 < (int)&stack0xfffffddc) ||

           (iVar6 = (**(code **)(**(int **)(unaff_ESI + 0x6e4) + 0x140))(&stack0xfffffdd8,1),

           *(int *)(iVar6 + 4) < 2)) {

          (**(code **)(**(int **)(unaff_ESI + 0x6e4) + 0x268))();

          (**(code **)(**(int **)(unaff_ESI + 0x6e4) + 0x1b0))(8);

          FUN_008ab9b0(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x670));

        }

        (**(code **)(**(int **)(unaff_ESI + 0x6e4) + 4))(1);

        if (*(int **)(unaff_ESI + 0x68c) != (int *)0x0) {

          (**(code **)(**(int **)(unaff_ESI + 0x68c) + 4))();

        }

      }

      (**(code **)(**(int **)(unaff_ESI + 0x6e4) + 0x34c))();

      return;

    }

  }

  return;

}
