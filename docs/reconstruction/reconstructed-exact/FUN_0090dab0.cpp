// =============================================================================
// FUN_0090dab0  (twin of Client_Input_DismissUiWindowTable5_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0090dab0
// Address:   0x0090dab0  (autoassault.exe, image base 0x400000)
// System:    input-drive-control
// Generated: 2026-07-23 scaffold; MEGA-097 2026-08-05 dual seal
// Exactness: Behavior-preserving rewrite of decompiler CF + disasm ABI restore.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime / differential: OPEN (terminal false).
// Canonical named unit: Client_Input_DismissUiWindowTable5_Inferred.cpp
// =============================================================================

/*
 * Behavioral notes:
 * - Nested OnKeyDown ESC helper: walk DAT_00d09a38[5], CALL FUN_0090d400 each.
 * - ABI: EAX = client host (custom); bare RET. Sites: MOV EAX,EBX; CALL.
 * - See named twin for full plate.
 */

void FUN_0090dab0(void)
{
  uint32_t* puVar1;

  // Disasm: MOV EDI,EAX (host) — decompiler omits
  puVar1 = &DAT_00d09a38;
  do {
    // Disasm: MOV ESI,[EBX]; CALL FUN_0090d400
    FUN_0090d400();
    puVar1 = puVar1 + 1;
  } while ((int)puVar1 < 0xd09a4c);
  return;
}
