// =============================================================================
// FUN_008aec40 / Client_MissionDialog_ControlDispatch_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_008aec40
// Address:   0x008aec40  (autoassault.exe, image base 0x400000)
// Body:      0x008aec40 – 0x008aefbb
// System:    missions-progression / client mission dialog UI
// Generated: 2026-07-23 scaffold; dual A/B plate 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Dual A/B:  reviews/A_aa_008aec40_Client_MissionDialog_ControlDispatch_Inferred.md
//            reviews/B_aa_008aec40_Client_MissionDialog_ControlDispatch_Inferred.md
// Vtable:    DATA 0x00a4a854 → this VA
// =============================================================================

// PURPOSE:
//   Mission dialog UI control-message dispatcher (thiscall; msg + controlId).
//   Routes 0x9c40-band widgets: close, scale, reward slots 0..3, accept/abandon
//   buttons 0x9c46..0x9c4d, NPC multi-select ≥0x9c4f.
//   Close / button-success → FUN_007fca10 (FlushPreparedResponse chain; UF-010).
//
//   Globals (role here):
//     DAT_00aaa664 @ 0x00aaa664 ≈ 1e-4f   ROUND bias
//     DAT_00aaa6f8 @ 0x00aaa6f8 = 255.0f  UI +0xf8 scale
//
//   Decompiler artifact: unaff_EDI on HandleButton path — image uses EAX=this
//   + single stack button index only.

// READABILITY:
//  - Body size: ~110 non-empty decompiler lines.
//  - Control keywords: if×19, return×7, goto×1, switch×1.
//  - Notable callees: Client_MissionDialogHandleButton, Client_ShowNpcMissionDialogUI,
//    FUN_007fca10, FUN_007fef20, CVOGReaction_ResolveObjectTarget, FUN_007fd420,
//    FUN_008aa3f0, FUN_0087b500, widget vtbls.
//  - Return sites: multiple (often 1 = handled).

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; dual A/B sealed CF + constants 2026-07-29.
 * - Remaining FUN_* / DAT_* identifiers are unresolved product names.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

undefined4 __thiscall FUN_008aec40(int param_1, int param_2, int param_3)
{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int unaff_EDI; /* decompiler artifact — not a real image arg on HandleButton */
  float10 fVar7;
  undefined1 auStack_8 [8];

  /* Outside button band 0x9c46..0x9c4d */
  if ((param_3 < 0x9c46) || (0x9c4d < param_3)) {
    /* NPC multi-select table ids ≥ 0x9c4f, msg click(8) */
    if ((0x9c4e < param_3) && (param_2 == 8)) {
      if ((*(int *)(param_1 + 0x72c) != 0) &&
         (param_3 - 0x9c4fU < (uint)(*(int *)(param_1 + 0x730) - *(int *)(param_1 + 0x72c) >> 2))) {
        Client_ShowNpcMissionDialogUI(&DAT_00d1a840,*(undefined4 *)(param_1 + 0x644),0);
      }
      return 1;
    }
  }
  else if (param_2 == 8) {
    /* Accept/abandon/etc buttons: index = controlId - 0x9c46; EAX=this in image */
    cVar1 = Client_MissionDialogHandleButton((int *)(param_3 + -0x9c46),unaff_EDI);
    if (cVar1 == '\0') {
      return 1;
    }
    goto LAB_008aef8f;
  }
  switch(param_3) {
  case 40000: /* 0x9c40 close */
    if (param_2 == 8) {
LAB_008aef8f:
      FUN_007fca10(); /* close + flush chain */
      if (*(int *)(param_1 + 0x648) == 2) {
        FUN_007fef20(0x13,1,0); /* abandon-state chrome */
      }
      return 1;
    }
    break;
  case 0x9c41: /* scale / slider */
    if (param_2 == 0x1a) {
      if ((*(int *)(param_1 + 0x700) != 0) && (*(int *)(param_1 + 0x6e0) != 0)) {
        fVar7 = (float10)(**(code **)(**(int **)(param_1 + 0x700) + 0x458))();
        iVar2 = (int)ROUND((float)((float10)*(int *)(param_1 + 0x704) * fVar7 +
                                  (float10)DAT_00aaa664)); /* ~1e-4 bias */
        iVar6 = (**(code **)(**(int **)(param_1 + 0x6e0) + 0x218))();
        if (iVar6 != iVar2) {
          (**(code **)(**(int **)(param_1 + 0x6e0) + 0x214))(iVar2);
          (**(code **)(**(int **)(param_1 + 0x6e0) + 0x34c))();
        }
      }
      return 1;
    }
    break;
  case 0x9c42:
  case 0x9c43:
  case 0x9c44:
  case 0x9c45: /* reward slots 0..3 */
    if (param_2 == 5) {
      iVar2 = CVOGReaction_ResolveObjectTarget
                        (1,*(undefined4 *)(param_1 + -0x4dcb8 + param_3 * 8),
                         *(undefined4 *)(param_1 + -0x4dcb4 + param_3 * 8));
      if (iVar2 != 0) {
        puVar3 = (undefined4 *)
                 (**(code **)(**(int **)(param_1 + -0x26a70 + param_3 * 4) + 0x140))(auStack_8,1);
        puVar4 = (undefined4 *)
                 (**(code **)(**(int **)(param_1 + -0x26a70 + param_3 * 4) + 0x120))
                           (&stack0xffffffe8,1,1);
        FUN_007fd420(*puVar4,puVar4[1],*puVar3,puVar3[1]);
        if (((*(int *)(param_1 + -0x4dcb8 + param_3 * 8) != *(int *)(param_1 + 0x578)) ||
            (*(int *)(param_1 + -0x4dcb4 + param_3 * 8) != *(int *)(param_1 + 0x57c))) &&
           (*(char *)(param_1 + 0x64c) != '\0')) {
          (**(code **)(**(int **)(param_1 + -0x26a70 + param_3 * 4) + 0x158))(0,param_1 + 0x584);
          cVar1 = (**(code **)(**(int **)(param_1 + -0x26a70 + param_3 * 4) + 0xf8))();
          if (cVar1 != '\0') {
            *(int *)(*(int *)(param_1 + -0x26a70 + param_3 * 4) + 0xf8) =
                 (int)(*(float *)(param_1 + 0x590) * DAT_00aaa6f8); /* *255 */
          }
          (**(code **)(**(int **)(param_1 + -0x26a70 + param_3 * 4) + 0x34c))();
        }
      }
    }
    else if (param_2 == 6) {
      DAT_00d1d8f4 = 1;
      DAT_00d1d8f5 = 0;
      if (DAT_00d1d8dc != (int *)0x0) {
        (**(code **)(*DAT_00d1d8dc + 4))(0);
      }
      if (((*(int *)(param_1 + -0x4dcb8 + param_3 * 8) != *(int *)(param_1 + 0x578)) ||
          (*(int *)(param_1 + -0x4dcb4 + param_3 * 8) != *(int *)(param_1 + 0x57c))) &&
         (*(char *)(param_1 + 0x64c) != '\0')) {
        (**(code **)(**(int **)(param_1 + -0x26a70 + param_3 * 4) + 0x158))(0,param_1 + 0x594);
        cVar1 = (**(code **)(**(int **)(param_1 + -0x26a70 + param_3 * 4) + 0xf8))();
        if (cVar1 != '\0') {
          *(int *)(*(int *)(param_1 + -0x26a70 + param_3 * 4) + 0xf8) =
               (int)(*(float *)(param_1 + 0x5a0) * DAT_00aaa6f8);
        }
        (**(code **)(**(int **)(param_1 + -0x26a70 + param_3 * 4) + 0x34c))();
        uVar5 = FUN_0087b500(6,param_3);
        return uVar5;
      }
    }
    else if ((param_2 == 8) && (*(char *)(param_1 + 0x64c) != '\0')) {
      FUN_008aa3f0(param_3 + -0x9c42);
      uVar5 = FUN_0087b500(8,param_3);
      return uVar5;
    }
  }
  uVar5 = FUN_0087b500(param_2,param_3);
  return uVar5;
}
