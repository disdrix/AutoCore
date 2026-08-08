// =============================================================================
// Client_Input_DismissUiWindowTable5_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0090dab0
// Address:   0x0090dab0  (autoassault.exe, image base 0x400000)
// System:    input-drive-control
// Generated: 2026-07-23 scaffold; MEGA-097 2026-08-05 dual seal
// Exactness: Behavior-preserving rewrite of decompiler CF + disasm ABI restore.
//            Not modernization. Not bit-exact claim.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime / differential: OPEN (terminal false).
//
// Purpose:  ESC UI-cancel helper for Client_Input_OnKeyDown_MatchAction.
//           Walks the 5-slot global UI window pointer table DAT_00d09a38
//           (exclusive end 0xd09a4c) and, for each slot, calls FUN_0090d400
//           which dismisses the window when vtbl+0x3d8 reports active and
//           notifies the client host (EAX).
//
// ABI:      custom EAX = client host* (NOT ECX thiscall). Bare RET (C3).
//           Call sites: MOV EAX,EBX before CALL (host held in EBX).
//
// Related:  FUN_0090d390  find-first-active in same table (gate)
//           FUN_0090d400  per-slot dismiss-if-active (ESI=window, EDI=host)
//           Client_Input_OnKeyDown_MatchAction  0x00911030  (caller)
//           Scaffold Named_CalleeOf_*_0090dab0 RETIRED
// =============================================================================

/*
 * Behavioral notes:
 * - Body 0x0090dab0–0x0090dad5 inclusive (38 B). Pad CC before 0x0090dae0.
 * - Decompiler omits MOV EDI,EAX and MOV ESI,[EBX]; port uses disasm authority.
 * - Table init (FUN_0093e7e0): five UI objects sizes 0x554/0x5d8/0x604/0x54c/0x588.
 * - Product window-type English and vtbl method names remain open → _Inferred.
 */

// Host arrives in EAX (custom register convention). Represented as first arg
// for readability; retail call sites do not push it.
void Client_Input_DismissUiWindowTable5_Inferred(void* /*eax*/ host)
{
  // Prologue saves EBX/ESI/EDI; EDI = host (from EAX).
  (void)host;

  uint32_t* slot = (uint32_t*)&DAT_00d09a38;

  do {
    // ESI = *slot; EDI = host; CALL FUN_0090d400
    FUN_0090d400();
    slot = slot + 1;
  } while ((int)slot < 0xd09a4c);

  return;
}
