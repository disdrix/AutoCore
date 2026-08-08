// =============================================================================
// Client_UI_Host1144_QueryAndFade_Inferred
// -----------------------------------------------------------------------------
// Purpose:  ESI-host leaf: if client UI host slot +0x1144 holds a live NDUI
//           object, and query vtbl+0xd0 is true, and state vtbl+0xe8 != -1,
//           invoke fade/transition vtbl+0xfc(0, 0.1f). Shared cancel/cleanup
//           leaf (mode-latch clear, skill-target cancel, key match, interact,
//           packet UI teardown — 15 CALL sites).
//
// Address:  0x007fb990  (autoassault.exe, image base 0x400000)
// Body:     0x007fb990–0x007fb9d3 inclusive (68 B / 0x44); pad CC after plain RET
// Stable:   aa_007fb990
// System:   input-drive-control
// Ghidra:   FUN_007fb990
//
// ABI:      host in ESI (custom convention; not ECX thiscall on host);
//           zero stack args; plain RET (C3).
//           Callers typically: MOV ESI, 0x00d1a840 ; CALL 0x007fb990.
//
// Does NOT: park drive; write latch +0x493; clear skill pending +0x30c0;
//           touch DAT_00d1b9a8 cursor host.
//
// Slot install (evidence, not owned):
//   Client_UI_CreateNDUIDialogs_InstallHost_Inferred  0x0093e7e0
//     host+0x1144 = operator_new(0x488) + FUN_007b5dd0 + vtbl+0x28 / +0xcc
//
// Parent dual (caller):
//   Client_SetModeLatch493_ParkDriveOnClear_Inferred  0x00914c60  aa_00914c60
//
// SUPERSEDES:
//   Named_CalleeOf_Client_Input_OnKeyDown_MatchAction_007fb990
//
// Exactness: CF ≡ live decompile + disassemble_function + read_memory 2026-08-05.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B R12-007: accept-with-gaps.
// =============================================================================

// ESI = client UI host at entry (decompiler: unaff_ESI).
// No C parameter — inventing one would misstate the retail ABI.
void Client_UI_Host1144_QueryAndFade_Inferred(void)
{
    char cVar1;
    int iVar2;
    int unaff_ESI; // ESI = ClientUiHost*

    // Gate 1: slot non-null
    if (*(int *)(unaff_ESI + 0x1144) != 0) {
        // Gate 2: thiscall query vtbl+0xd0 → AL
        cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x1144) + 0xd0))();
        if (cVar1 != '\0') {
            // Gate 3: thiscall state vtbl+0xe8 → EAX; -1 skips fade
            iVar2 = (**(code **)(**(int **)(unaff_ESI + 0x1144) + 0xe8))();
            if (iVar2 != -1) {
                // Fade: PUSH 0.1f (0x3dcccccd); PUSH 0; CALL vtbl+0xfc
                (**(code **)(**(int **)(unaff_ESI + 0x1144) + 0xfc))(0, 0x3dcccccd);
            }
        }
    }
    return; // plain RET (C3)
}
