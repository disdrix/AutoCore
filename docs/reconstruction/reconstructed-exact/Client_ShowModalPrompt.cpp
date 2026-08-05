// =============================================================================
// Client_ShowModalPrompt
// -----------------------------------------------------------------------------
// Stable ID: aa_007fdfb0
// Address:   0x007fdfb0  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_007fdfb0
// System:    client::ui (missions-progression consumer for abandon)
// Generated: 2026-07-29 — UF-009 seal (dual Yes/No id pairing)
// Exactness: Behavior-preserving rewrite of decompiler CF + asm dual-id store.
//            Register EAX primary-id arg is from live callers (not Ghidra proto).
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE
//   Open (or replace) the client modal message box:
//     1. Dismiss any prior modal (FUN_007fc360).
//     2. Program dual button modal-codes on the modal host object:
//          host+0x498 = primary / OK / Yes   (from EAX at call)
//          host+0x49c = secondary / Cancel   (from stack param_3 if >= 0,
//                                             else same as primary for toast)
//          host+0x514 / +0x518 = previous dual ids (backup)
//     3. Set localized title/body, show message text, bring modal to front.
//
// ABANDON PAIRING (UF-009 — High)
//   Client_MissionDialogHandleButton state 2:
//     MOV EAX, 0x4e46          ; Yes  → case sends C2S 0x20B2
//     PUSH 0x4e47              ; No   → case closes only
//     CALL Client_ShowModalPrompt
//
// WIDGET BIND (dual residual sealed 2026-07-29 — High)
//   game+0x1118 = CDlgPopup (i_d_pop.xml).
//   popup+0x550 = CNDUICtrlButton OK   (i_d_pop_2d_btn_ok.xml)
//   popup+0x554 = CNDUICtrlButton Cancel (i_d_pop_2d_btn_cancel.xml)
//   FUN_008a7150: OK.vtbl+0x74(primary)     → button+0xec
//   MOV EDI, secondary; FUN_008a7100: Cancel.vtbl+0x74(secondary)
//   Readers: FUN_008a70e0 / FUN_008a70c0 (vtbl+0x78) → vtbl+0x338(8, code)
//
// NAMING
//   Prefer Client_ShowModalPrompt over string-derived VOG_DEBUG_STOP (assert only).
// =============================================================================

#include <cstdint>

// Unresolved shared symbols
extern void  FUN_007fc360();                 // dismiss / close modal
extern void  FUN_007a4480(int, const char*); // debug stop / assert log
extern void  FUN_007a69d0(...);
extern void* FUN_007a6de0(...);
extern void  FUN_008a7090();
extern void  FUN_008a7150();
extern void  FUN_008a7100();
extern void  FUN_008a6fd0(void* messageOrString);

// Offsets on modal host object (*game+0xf40)
static constexpr int kOffPrimaryId      = 0x498; // OK / Yes modal code
static constexpr int kOffSecondaryId    = 0x49c; // Cancel / No modal code
static constexpr int kOffPrimaryBackup  = 0x514;
static constexpr int kOffSecondaryBackup = 0x518;

// Abandon codes (documented consumers; not hardcoded inside this function)
static constexpr std::uint32_t kModalAbandonYes = 0x4e46;
static constexpr std::uint32_t kModalAbandonNo  = 0x4e47;

/*
 * ABI (custom; Ghidra understates):
 *   EAX     = primaryButtonId   (OK / Yes)
 *   stack+4 = game / client root*
 *   stack+8 = message (char* or string id path)
 *   stack+C = secondaryButtonId (Cancel / No); if < 0, single-button both = primary
 *   stack+10, stack+14 = flags (commonly 1, 0) used by show helpers
 *
 * Returns: void (EAX undefined at ret for callers that ignore it).
 */
void Client_ShowModalPrompt(
    int* game,
    void* message,
    int secondaryButtonId
    /* + flags consumed by helpers; primaryButtonId arrives in EAX */)
{
    // Decompiler surfaces primary as in_EAX; callers set it immediately before CALL.
    std::uint32_t primaryButtonId; // = EAX at entry
    // asm: MOV EDI, EAX  then later store EDI -> +0x498

    FUN_007fc360();

    int** ppModalHost = reinterpret_cast<int**>(
        reinterpret_cast<char*>(game) + 0xf40);
    int* modalHost = (ppModalHost != nullptr) ? *ppModalHost : nullptr;
    if (modalHost == nullptr || *modalHost == 0) {
        return;
    }

    // vtable bring-to-front / attach message panel (offsets from decompile)
    // (**modalHost)+0x3ec, +0x3f4(1), +0xa8(game+0x1118) ...

    int* modalObj = reinterpret_cast<int*>(*modalHost);

    // Backup previous dual ids
    *reinterpret_cast<std::uint32_t*>(
        reinterpret_cast<char*>(modalObj) + kOffPrimaryBackup) =
        *reinterpret_cast<std::uint32_t*>(
            reinterpret_cast<char*>(modalObj) + kOffPrimaryId);

    *reinterpret_cast<std::uint32_t*>(
        reinterpret_cast<char*>(modalObj) + kOffPrimaryId) = primaryButtonId;

    *reinterpret_cast<std::uint32_t*>(
        reinterpret_cast<char*>(modalObj) + kOffSecondaryBackup) =
        *reinterpret_cast<std::uint32_t*>(
            reinterpret_cast<char*>(modalObj) + kOffSecondaryId);

    if (secondaryButtonId < 0) {
        // Single-button / toast: both slots share primary id
        *reinterpret_cast<std::uint32_t*>(
            reinterpret_cast<char*>(modalObj) + kOffSecondaryId) = primaryButtonId;
    } else {
        // Dual-button: secondary is explicit cancel/No id
        *reinterpret_cast<std::uint32_t*>(
            reinterpret_cast<char*>(modalObj) + kOffSecondaryId) =
            static_cast<std::uint32_t>(secondaryButtonId);
    }

    int** ppMsgPanel = reinterpret_cast<int**>(
        reinterpret_cast<char*>(game) + 0x1118);
    if (*ppMsgPanel == nullptr) {
        FUN_007a4480(0, "VOG_DEBUG_STOP");
    } else {
        // Show path: localize, set text (FUN_008a6fd0(message)), vtable +0x34c show
        FUN_008a7090();
        // ... FUN_007a69d0 / FUN_007a6de0 title path ...
        FUN_008a7150();
        FUN_008a7100();
        FUN_008a6fd0(message);
        // (**( *ppMsgPanel ) + 0x34c)();
    }

    // Optional chrome at game+0xf38 / +0x31d8 visibility flags (decompile tail)
}

// -----------------------------------------------------------------------------
// Consumer contract: abandon confirm (not part of this function body)
// -----------------------------------------------------------------------------
// HandleButton state 2:
//   Client_ShowModalPrompt(&DAT_00d1a840, abandonMsg, /*secondary*/0x4e47, 1, 0);
//   with EAX = 0x4e46;
//
// UiModalDispatch:
//   case 0x4e46 + action 8 → C2S FailMission 0x20B2 size 0x18
//   case 0x4e47 + action 8 → FUN_007fc360() only
// -----------------------------------------------------------------------------
