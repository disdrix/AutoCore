// =============================================================================
// UI_MissionDialog_SetResponseCountAndRebuild_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_008ac890
// Address:   0x008ac890–0x008ac8af exclusive (31 B)  (autoassault.exe, base 0x400000)
// Ghidra:    FUN_008ac890
// System:    missions-progression / client UI mission dialog
// Dual:      MEGA-109 2026-08-05 accept-with-gaps
// Exactness: Behavior-preserving rewrite of decompiler + byte-sealed ABI.
// Bit-for-bit vs retail EXE: DEFERRED. Runtime Confirmed: not claimed.
// =============================================================================
//
// PURPOSE
//   Apply a new NPC mission-dialog response count (EAX), clamp to max 8 at
//   dialog+0x510, then rebuild the response-button chrome strip via dualed
//   peer UI_MissionDialog_BuildResponseButtons_Inferred (FUN_008ac110).
//
// ABI (byte-sealed)
//   ECX = MissionDialogUi* this
//   EAX = requested response count
//   void return; bare RET (C3) — no stack parameters
//
// CALLERS (xrefs)
//   FUN_008ac8b0 @ 0x008acb02  — NUM_RESPONSES XML property path
//   0x008ad224                 — ASCII "NUM_RESPONSES" key path
//   FUN_0093e450 @ 0x0093e6e9  — after vector-size helper FUN_005795b0
//
// CALLEES
//   FUN_008ac110 UI_MissionDialog_BuildResponseButtons_Inferred (EDI-this)
//
// =============================================================================

#include <cstdint>

struct MissionDialogUi {
  // ...
  // int chrome_gate;        // +0x4C0  (peer gate; not touched here)
  std::int32_t response_count; // +0x510
  // int columns;            // +0x640  (peer; NUM_RESPONSE_COLUMNS path)
  // void* response_slots[]; // +0x708  (peer)
};

// Dualed peer — EDI = this on entry (callers present EDI; this unit loads EDI from ECX).
extern void UI_MissionDialog_BuildResponseButtons_Inferred();

// Register contract expressed as parameters for readability.
// Retail: count in EAX, this in ECX; not a stack thiscall.
void UI_MissionDialog_SetResponseCountAndRebuild_Inferred(
    MissionDialogUi* dialog /* ECX */,
    std::int32_t requested_count /* EAX */)
{
  dialog->response_count = requested_count;
  if (requested_count > 8) {
    dialog->response_count = 8;
  }
  // Peer expects EDI = dialog (this unit: MOV EDI, ECX before CALL).
  UI_MissionDialog_BuildResponseButtons_Inferred();
}
