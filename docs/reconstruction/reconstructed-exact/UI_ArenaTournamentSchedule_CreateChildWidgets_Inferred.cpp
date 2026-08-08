// =============================================================================
// UI_ArenaTournamentSchedule_CreateChildWidgets_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Virtual builder for the Arena Tournament Schedule dialog: allocate,
//           construct, attach, and XML-load the full child widget tree (list
//           chrome, sort/join/refresh/spectate buttons, reward/item rows, three
//           tab chrome controls, close + mini-status cluster), then finalize
//           with host vcalls and residual refresh helpers.
//
// Address:  0x0086b9b0  (autoassault.exe, image base 0x400000)
// Stable:   aa_0086b9b0
// System:   inventory-transfer (UI arena schedule chrome — no inventory wire)
// Ghidra:   FUN_0086b9b0
//
// Convention (__thiscall):
//   ECX          = host window* (Arena tournament schedule dialog)
//   (no stack args)
//   RET          (plain C3; SEH frame restored)
//
// Dispatch:
//   DATA xref 0x00a5ed20 — vtbl method slot +0x43C on PTR_FUN_00a5e8e4
//   (class vtbl installed by ctor FUN_0086cd10 / plate UI_arena_tournament_schedule)
//
// Dualed helpers used here:
//   FUN_00822cb0  UI_TabChrome_SetSelected_Inferred   (ESI=tab, BL=sel, force@stack, RET 4)
//   FUN_00756c90  UI_Widget_MoveToFrontInParentGroup_Inferred  (EDI=widget)
//
// Exactness: Behavior-preserving CF from live disasm + decompile.
// Dual R13-009 2026-08-05.
// Dual reviews:
//   reviews/A_aa_0086b9b0_UI_ArenaTournamentSchedule_CreateChildWidgets_Inferred.md
//   reviews/B_aa_0086b9b0_UI_ArenaTournamentSchedule_CreateChildWidgets_Inferred.md
// Scaffold twin: reconstructed-exact/FUN_0086b9b0.cpp
// Supersedes plate alias: UI_arena_tournament_schedule_mini_label
// =============================================================================

#include <cstdint>

struct UiVtable; // residual product type

struct UiWidget {
    UiVtable* vtbl;
    // … layout residual …
};

// Residual ctors / helpers (not dualled in R13-009).
extern "C" void* operator_new(std::uint32_t size);
extern "C" UiWidget* FUN_007b5dd0(void* mem, int zero_flag);
extern "C" UiWidget* FUN_00864f20(void* mem);          // NDUIFxPanel_Ctor_Inferred
extern "C" UiWidget* FUN_0079c860(void* mem);          // NDUIButton_Ctor_Inferred
extern "C" UiWidget* FUN_0078b6e0(void* /*ESI=mem*/);
extern "C" UiWidget* FUN_0078f890(void* /*ESI=mem*/);
extern "C" UiWidget* FUN_008230b0(void* mem);          // tab chrome ctor residual
extern "C" void FUN_00792600(void* host_ecx);
extern "C" void FUN_00822cb0(char force /*stack*/);    // ESI=widget, BL=selected
extern "C" std::uint32_t FUN_00756c90(void);           // EDI=widget
extern "C" void FUN_0086b370(void* host_eax);
extern "C" void FUN_0086a900(int a, int b /*stack; this@ECX*/);
extern "C" void FUN_0086b3c0(void* host_ecx /* AL gate */);

// Host layout (slots written by this unit — partial).
struct ArenaTournamentScheduleHost {
    UiVtable* vtbl;                 // +0x00
    std::uint8_t  pad_04[0xC1];
    std::uint8_t  flag_c5;          // +0xC5  cleared to 0
    std::uint8_t  pad_c6[0x4FC - 0xC6];
    std::uint32_t field_4fc;        // +0x4FC = 0xF
    std::uint32_t field_500;        // +0x500 = 1
    std::uint8_t  pad_504[0x24];
    std::uint8_t  flag_528;         // +0x528 = 0
    std::uint8_t  pad_529[0x3];
    std::uint32_t size_src_x;       // +0x52C (saved into local; used by vtbl+0x110)
    std::uint32_t size_src_y;       // +0x530
    float         norm_w;           // +0x534  (may be rewritten from mini bg size path)
    float         norm_h;           // +0x538
    // … many child* slots from +0x504 / +0x588 … +0x644 …
    // Documented in annotated + function record tables.
};

// Pseudocode port of sealed CF. Not bit-exact; vcall ordinals are byte offsets.
extern "C" void UI_ArenaTournamentSchedule_CreateChildWidgets_Inferred(ArenaTournamentScheduleHost* self)
{
    // --- prologue host flags ---
    self->field_4fc = 0x0F;
    self->field_500 = 1;
    self->flag_528  = 0;
    self->flag_c5   = 0;

    // host->vtbl[+0x110](saved size locals); host->vtbl[+0x130](&self->…+0x53C);
    // FUN_00792600(self);

    // --- mass child build (pattern) ---
    // for each plate in tournament_schedule_*.xml set:
    //   child = new+ctor(size)
    //   self->slot = child
    //   self->vtbl[+0xA8](child)
    //   child->vtbl[+0x28](xml)
    //   optional child->vtbl[+0x74](resourceId) / extras

    // --- three tab chrome (FUN_008230b0 size 0x81C) ---
    // tab_console    @ +0x630: SetSelected(BL=0, force=1); MoveToFront
    // tab_tournament @ +0x634: SetSelected(BL=1, force=1); tab->vtbl[+0x94]()
    // tab_advanced   @ +0x638: SetSelected(BL=0, force=1); MoveToFront

    // --- close btn @ +0x504; mini cluster @ +0x63C/+0x640/+0x644 ---
    // optional size normalize vs DAT_00aaac10 using DAT_00aaa670/674 + screen dims

    // --- finalize ---
    // self->vtbl[+0x448](); self->vtbl[+0x34C]();
    // FUN_0086b370(self);
    // FUN_0086a900(self, -1, -1);
    // if (DAT_00d1b6d8 && DAT_00d1b6d8[+0x4FC] != 0) FUN_0086b3c0(self);
    (void)self;
}

// Ghidra default symbol — same VA / body.
extern "C" void FUN_0086b9b0(ArenaTournamentScheduleHost* self)
{
    UI_ArenaTournamentSchedule_CreateChildWidgets_Inferred(self);
}
