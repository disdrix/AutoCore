// =============================================================================
// UI_MissionJournal_ApplyStatusCompleteLabel_Inferred  (FUN_00829ac0)
// -----------------------------------------------------------------------------
// Stable ID: aa_00829ac0
// Address:   0x00829ac0  (autoassault.exe, image base 0x400000)
// Body:      0x00829ac0 – 0x00829aff exclusive (64 B / 0x40)
// System:    client UI / missions-progression / mission journal
// Generated: 2026-07-29 W25-G dual seal (raw 2026-07-23 re-verified live)
// Exactness: Behavior-preserving rewrite of decompiler control flow + byte seal.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE
//   Store complete-flag on the mission-journal panel and, if the status
//   widget is live, set its text to ""/null (flag clear) or "(complete)"
//   then refresh the widget (vtbl+0x34c tail).
//
// ABI
//   ESI = JournalPanel*; AL = complete flag (0 / non-zero)
//   Not ECX thiscall. Plain ret when status null; else tail-jmp vtbl+0x34c.
//
// STRINGS
//   "(complete)" @ 0x00a7496c
//
// CALLERS
//   UI_MissionJournal_SelectMission_Inferred (0x00829b20) after IsMissionJournalReady
//   FUN_00829ce0 (status widget construction path)
// =============================================================================

#include <cstdint>

struct NDUI_Vtbl {
  // ...
  // +0x1d8 → SetText-like
  // +0x34c → Refresh/layout-like
};

struct NDUI {
  NDUI_Vtbl *vtbl;
};

struct JournalPanel {
  // ...
  // +0x4fd  uint8_t statusCompleteFlag
  // +0x50c  NDUI*   statusWidget   (index 0x143 as dword)
  // +0x508  NDUI*   titleWidget    (peer; not touched here)
  // +0x500  int32_t selectedMissionId (peer SelectMission)
};

// ---------------------------------------------------------------------------
// Clean reconstruction — CF ≡ live decompile; args for SetText sealed from bytes
// ---------------------------------------------------------------------------

// Register ABI: ESI = panel, AL = flag. Modeled as explicit params for clarity.
void UI_MissionJournal_ApplyStatusCompleteLabel_Inferred(JournalPanel *panel,
                                                        uint8_t completeFlag) {
  NDUI *status = *reinterpret_cast<NDUI **>(
      reinterpret_cast<uint8_t *>(panel) + 0x50c);
  *reinterpret_cast<uint8_t *>(reinterpret_cast<uint8_t *>(panel) + 0x4fd) =
      completeFlag;

  if (status == nullptr)
    return;

  // Shared pushes: 1, 1 then text-or-null (stdcall reverse → SetText(text,1,1))
  using SetTextFn = void(__thiscall *)(NDUI *, const char *text, int a, int b);
  using RefreshFn = void(__thiscall *)(NDUI *);

  auto setText = *reinterpret_cast<SetTextFn *>(
      reinterpret_cast<uint8_t *>(status->vtbl) + 0x1d8);
  auto refresh = *reinterpret_cast<RefreshFn *>(
      reinterpret_cast<uint8_t *>(status->vtbl) + 0x34c);

  if (completeFlag == 0)
    setText(status, nullptr, 1, 1);
  else
    setText(status, "(complete)", 1, 1); // literal @ 0x00a7496c

  // Retail: reload [panel+0x50c] then jmp [vtbl+0x34c] (tail)
  status = *reinterpret_cast<NDUI **>(
      reinterpret_cast<uint8_t *>(panel) + 0x50c);
  refresh(status);
}

// Ghidra register-form alias (decomp shape)
void FUN_00829ac0(void) {
  // unaff_ESI = panel; in_AL = flag — recovered at call sites
  // UI_MissionJournal_ApplyStatusCompleteLabel_Inferred(ESI, AL);
}
