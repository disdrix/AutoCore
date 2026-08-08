// =============================================================================
// Client_Input_FindFirstActiveUiWindowTable5_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0090d390
// Address:   0x0090d390–0x0090d3c4 inclusive  (53 B / 0x35)
// Module:    autoassault.exe (image base 0x400000)
// System:    input-drive-control
// Generated: 2026-08-05 MEGA-096 dual seal (from raw + live re-verify)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// Runtime / differential: OPEN
//
// PURPOSE: Scan the fixed 5-slot UI window* table DAT_00d09a38[0..4]
//   (exclusive end 0x00d09a4c). Return the first non-null slot whose
//   virtual method at vtbl+0x3d8 returns true (active/visible gate).
//   Return NULL if none.
//
//   Primary consumer: Client_Input_OnKeyDown_MatchAction ESC cancel path —
//   if this returns non-null, sibling Client_Input_DismissUiWindowTable5_Inferred
//   (0x0090dab0 / MEGA-097) dismisses every slot via FUN_0090d400.
//
// ABI: no stack args; plain RET (C3). ESI = index. EAX = window* or 0.
//      ECX used only as this for the vtbl+0x3d8 thiscall.
//
// Related:
//   Client_Input_DismissUiWindowTable5_Inferred  0x0090dab0  (MEGA-097)
//   FUN_0090d400                                 per-slot dismiss (residual)
//   Client_Input_OnKeyDown_MatchAction           0x00911030  (parent ESC)
//   FUN_0093e7e0                                 table init WRITE (evidence)
//   FUN_00935a30                                 table teardown null (evidence)
//
// Retired scaffold: Named_CalleeOf_Client_Input_OnKeyDown_MatchAction_0090d390
// =============================================================================

/*
 * Behavioral notes:
 * - CF ≡ raw decompile ≡ live disassembly (MEGA-096).
 * - Product English for the five window types and vtbl+0x3d8 method open → _Inferred.
 * - Do not confuse with keybind scan table DAT_00d1bc18 (ActionMap slots).
 */

// Returns first active UI window* in DAT_00d09a38[5], or 0.
uint32_t /* window* or 0 */ Client_Input_FindFirstActiveUiWindowTable5_Inferred(void)
{
  char cVar1;
  int iVar2;

  iVar2 = 0;
  do {
    if ((&DAT_00d09a38)[iVar2] != 0) {
      cVar1 = (**(code **)(*(int *)(&DAT_00d09a38)[iVar2] + 0x3d8))();
      if (cVar1 != '\0') {
        return (&DAT_00d09a38)[iVar2];
      }
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 5);
  return 0;
}
