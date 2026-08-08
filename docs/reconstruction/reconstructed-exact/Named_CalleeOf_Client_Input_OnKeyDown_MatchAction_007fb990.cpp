// =============================================================================
// Named_CalleeOf_Client_Input_OnKeyDown_MatchAction_007fb990  [SUPERSEDED]
// -----------------------------------------------------------------------------
// Stable ID: aa_007fb990
// Address:   0x007fb990
// Status:    SUPERSEDED 2026-08-05 by Client_UI_Host1144_QueryAndFade_Inferred
// Reason:    Scaffold tied name to a single OnKeyDown caller; live xrefs show
//            15 UNCONDITIONAL_CALL sites (mode latch, skill cancel, interact,
//            packet UI, etc.). Prefer the named plate:
//              Client_UI_Host1144_QueryAndFade_Inferred.cpp
//            and twin FUN_007fb990.cpp.
// =============================================================================

// Forward to sealed CF (kept for path stability only).

void Named_CalleeOf_Client_Input_OnKeyDown_MatchAction_007fb990(void)
{
  char cVar1;
  int iVar2;
  int unaff_ESI;

  if (*(int *)(unaff_ESI + 0x1144) != 0) {
    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x1144) + 0xd0))();
    if (cVar1 != '\0') {
      iVar2 = (**(code **)(**(int **)(unaff_ESI + 0x1144) + 0xe8))();
      if (iVar2 != -1) {
        (**(code **)(**(int **)(unaff_ESI + 0x1144) + 0xfc))(0, 0x3dcccccd);
      }
    }
  }
  return;
}
