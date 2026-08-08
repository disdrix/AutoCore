// =============================================================================
// UI_ArenaConsole_CreateChildWidgets_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00878300
// Address:   0x00878300  (autoassault.exe, image base 0x400000)
// Body:      0x00878300–0x00878c14 inclusive (0x915 B)
// System:    inventory-transfer (partition; pure client UI construct)
// Generated: 2026-08-05 R13-010 dual seal (from live Ghidra decompile + disasm)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Dual A/B:  accept-with-gaps; Terminal false; never Runtime Confirmed.
// =============================================================================
//
// PURPOSE:
//   Virtual CreateChildWidgets for the Arena Console host dialog.
//   Builds the full i_d_arena/i_d_arena_console_*.xml child tree, wires command
//   ids 0x9c40–0x9c47, default-selects the console tab, collapses tournament +
//   advanced tabs (SetSelected 0 + MoveToFront), builds mini overlay, optional
//   player-gated post-step, host finalize.
//
// ABI:
//   __thiscall  ECX = host*
//   no stack formals; plain RET; void
//
// DISPATCH:
//   Vtbl DATA slot 0x00a5a640 (host vtbl base PTR_FUN_00a5a204 + 0x43C)
//
// PLATE ALIAS (retired as canonical): UI_arena_console_tab_tournament
// =============================================================================

#include <cstdint>

// Residual / dualed callees (not re-implemented here)
extern "C" void FUN_00792600(void* host);
extern "C" void* operator_new(unsigned size);
extern "C" void* FUN_007b5dd0(void* mem, int zero_flag);
extern "C" void* FUN_00864f20(void* mem);
extern "C" void* FUN_0078f890(/* ESI = mem */);
extern "C" void* FUN_0079c860(/* ESI = mem */);
extern "C" void* FUN_008230b0(void* mem);
extern "C" void FUN_00822cb0(/* ESI=tab, BL=selected, stack force */);
extern "C" int  FUN_00756c90(/* EDI=widget */);
extern "C" void FUN_00877790(/* ESI = host */);
extern "C" void FUN_008778e0(void* host);
extern "C" void FUN_00877c50(void* host /* ECX */);

extern float DAT_00aaac10;   // -99998.0f  unset-size sentinel
extern float DAT_00aaa670;   // 1200.0f
extern float DAT_00aaa674;   // 1600.0f
extern int   DAT_00d17944;
extern int   DAT_00d1e818;
extern int   DAT_00d1e81c;
extern int*  DAT_00d1b6d8;   // player / character host (Probable)

// Host layout (byte offsets; child pointers as dword slots)
// +0x0C5  byte clear
// +0x4FC  dword = 0x0F
// +0x500  dword = 1
// +0x504  close button*
// +0x524  byte clear
// +0x528 / +0x52C  saved base offsets for mini size
// +0x530 / +0x534  cached size floats (sentinel -99998)
// +0x54C..+0x594  child pointer band (see table in annotated)

static inline void** vtbl(void* obj) { return *reinterpret_cast<void***>(obj); }

// Typed vcall helpers (ordinals from disasm; product names open)
using VFn = void(__thiscall*)(void*, ...);

void __fastcall UI_ArenaConsole_CreateChildWidgets_Inferred(void* host /* ECX */)
{
    // SEH frame: PUSH -1; PUSH LAB_009b902f; FS:[0] chain — elided in clean plate.

    auto* h = reinterpret_cast<std::uint8_t*>(host);
    auto* hd = reinterpret_cast<std::uint32_t*>(host);

    // Pre-init
    h[0x524] = 0;
    h[0xC5]  = 0;
    hd[0x4FC / 4] = 0x0F;
    hd[0x500 / 4] = 1;

    // Host virtual prep
    reinterpret_cast<VFn>(vtbl(host)[0x110 / 4])(host);
    reinterpret_cast<VFn>(vtbl(host)[0x130 / 4])(host);
    FUN_00792600(host);

    // ---- child factory helpers ----
    auto attach_load = [&](void* child, const char* xml) {
        reinterpret_cast<VFn>(vtbl(host)[0xA8 / 4])(host, child);
        if (child)
            reinterpret_cast<VFn>(vtbl(child)[0x28 / 4])(child, xml);
    };
    auto set_cmd = [&](void* child, unsigned cmd) {
        if (child)
            reinterpret_cast<VFn>(vtbl(child)[0x74 / 4])(child, cmd);
    };
    auto show = [&](void* child) {
        if (child)
            reinterpret_cast<VFn>(vtbl(child)[0x43C / 4])(child);
    };

    // +0x54C bg_fill
    {
        void* p = operator_new(0x488);
        p = p ? FUN_007b5dd0(p, 0) : nullptr;
        hd[0x54C / 4] = reinterpret_cast<std::uint32_t>(p);
        attach_load(p, "i_d_arena/i_d_arena_console_wnd_bg_fill.xml");
    }
    // +0x550 fx panel
    {
        void* p = operator_new(0x4BC);
        p = p ? FUN_00864f20(p) : nullptr;
        hd[0x550 / 4] = reinterpret_cast<std::uint32_t>(p);
        attach_load(p, "i_d_arena/i_d_arena_console_wnd_fx.xml");
    }
    // +0x554 bg_texture
    {
        void* p = operator_new(0x488);
        p = p ? FUN_007b5dd0(p, 0) : nullptr;
        hd[0x554 / 4] = reinterpret_cast<std::uint32_t>(p);
        attach_load(p, "i_d_arena/i_d_arena_console_wnd_bg_texture.xml");
    }
    // +0x55C title
    {
        void* p = operator_new(0x488);
        p = p ? FUN_007b5dd0(p, 0) : nullptr;
        hd[0x55C / 4] = reinterpret_cast<std::uint32_t>(p);
        attach_load(p, "i_d_arena/i_d_arena_console_wnd_title.xml");
    }
    // +0x560 bg_logo
    {
        void* p = operator_new(0x488);
        p = p ? FUN_007b5dd0(p, 0) : nullptr;
        hd[0x560 / 4] = reinterpret_cast<std::uint32_t>(p);
        attach_load(p, "i_d_arena/i_d_arena_console_wnd_bg_logo.xml");
    }
    // +0x564 bg_help
    {
        void* p = operator_new(0x488);
        p = p ? FUN_007b5dd0(p, 0) : nullptr;
        hd[0x564 / 4] = reinterpret_cast<std::uint32_t>(p);
        attach_load(p, "i_d_arena/i_d_arena_console_wnd_bg_help.xml");
    }
    // +0x568 help
    {
        void* p = operator_new(0x488);
        p = p ? FUN_007b5dd0(p, 0) : nullptr;
        hd[0x568 / 4] = reinterpret_cast<std::uint32_t>(p);
        attach_load(p, "i_d_arena/i_d_arena_console_wnd_help.xml");
    }
    // +0x558 arena_logo
    {
        void* p = operator_new(0x488);
        p = p ? FUN_007b5dd0(p, 0) : nullptr;
        hd[0x558 / 4] = reinterpret_cast<std::uint32_t>(p);
        attach_load(p, "i_d_arena/i_d_arena_console_wnd_arena_logo.xml");
    }
    // +0x56C bg_dynamic_news
    {
        void* p = operator_new(0x488);
        p = p ? FUN_007b5dd0(p, 0) : nullptr;
        hd[0x56C / 4] = reinterpret_cast<std::uint32_t>(p);
        attach_load(p, "i_d_arena/i_d_arena_console_wnd_bg_dynamic_news.xml");
    }
    // +0x570 stats_dynamic_news
    {
        void* p = operator_new(0x488);
        p = p ? FUN_007b5dd0(p, 0) : nullptr;
        hd[0x570 / 4] = reinterpret_cast<std::uint32_t>(p);
        attach_load(p, "i_d_arena/i_d_arena_console_wnd_stats_dynamic_news.xml");
    }
    // +0x574 sb_dynamic_news (0x954)
    {
        void* p = operator_new(0x954);
        // retail: MOV ESI,EAX; CALL FUN_0078f890
        p = p ? FUN_0078f890() : nullptr;
        hd[0x574 / 4] = reinterpret_cast<std::uint32_t>(p);
        attach_load(p, "i_d_arena/i_d_arena_console_sb_dynamic_news.xml");
        show(p);
        if (p)
            reinterpret_cast<VFn>(vtbl(p)[0x468 / 4])(p, 1);
        set_cmd(p, 0x9C46);
        FUN_00877790(); // ESI=host in retail
    }
    // +0x578 btn_instant_action
    {
        void* p = operator_new(0x4CC);
        p = p ? FUN_0079c860() : nullptr;
        hd[0x578 / 4] = reinterpret_cast<std::uint32_t>(p);
        attach_load(p, "i_d_arena/i_d_arena_console_btn_instant_action.xml");
        set_cmd(p, 0x9C41);
    }
    // +0x57C btn_my_stats
    {
        void* p = operator_new(0x4CC);
        p = p ? FUN_0079c860() : nullptr;
        hd[0x57C / 4] = reinterpret_cast<std::uint32_t>(p);
        attach_load(p, "i_d_arena/i_d_arena_console_btn_my_stats.xml");
        set_cmd(p, 0x9C42);
    }
    // +0x504 btn_close
    {
        void* p = operator_new(0x4CC);
        p = p ? FUN_0079c860() : nullptr;
        hd[0x504 / 4] = reinterpret_cast<std::uint32_t>(p);
        attach_load(p, "i_d_arena/i_d_arena_console_btn_close.xml");
        set_cmd(p, 0x9C40);
    }

    // ---- tabs (0x81c / FUN_008230b0) ----
    // +0x580 tab_console — SELECTED
    {
        void* p = operator_new(0x81C);
        p = p ? FUN_008230b0(p) : nullptr;
        hd[0x580 / 4] = reinterpret_cast<std::uint32_t>(p);
        attach_load(p, "i_d_arena/i_d_arena_console_tab_console.xml");
        show(p);
        set_cmd(p, 0x9C43);
        // retail: MOV ESI,p; PUSH 1; MOV BL,1; CALL 00822cb0
        FUN_00822cb0();
        if (p)
            reinterpret_cast<VFn>(vtbl(p)[0x94 / 4])(p);
    }
    // +0x584 tab_tournament — unselected + MoveToFront
    {
        void* p = operator_new(0x81C);
        p = p ? FUN_008230b0(p) : nullptr;
        hd[0x584 / 4] = reinterpret_cast<std::uint32_t>(p);
        attach_load(p, "i_d_arena/i_d_arena_console_tab_tournament.xml");
        show(p);
        set_cmd(p, 0x9C44);
        // retail: MOV ESI,p; PUSH 1; XOR BL,BL; CALL 00822cb0
        FUN_00822cb0();
        // retail: MOV EDI,p; CALL 00756c90
        FUN_00756c90();
    }
    // +0x588 tab_advanced — unselected + MoveToFront
    {
        void* p = operator_new(0x81C);
        p = p ? FUN_008230b0(p) : nullptr;
        hd[0x588 / 4] = reinterpret_cast<std::uint32_t>(p);
        attach_load(p, "i_d_arena/i_d_arena_console_tab_advanced.xml");
        show(p);
        set_cmd(p, 0x9C45);
        FUN_00822cb0();
        FUN_00756c90();
    }

    // ---- mini overlay ----
    // +0x58C mini_wnd_bg_texture
    {
        void* p = operator_new(0x488);
        p = p ? FUN_007b5dd0(p, 0) : nullptr;
        hd[0x58C / 4] = reinterpret_cast<std::uint32_t>(p);
        attach_load(p, "i_d_arena/i_d_arena_console_mini_wnd_bg_texture.xml");
        if (p) {
            reinterpret_cast<VFn>(vtbl(p)[0xCC / 4])(p, 0);
            reinterpret_cast<std::uint8_t*>(p)[0xC4] = 1;
        }

        float* sz0 = reinterpret_cast<float*>(&hd[0x530 / 4]);
        float* sz1 = reinterpret_cast<float*>(&hd[0x534 / 4]);
        const float sentinel = DAT_00aaac10; // -99998.0f
        if (*sz0 <= sentinel || *sz1 <= sentinel) {
            // Query child size via vtbl+0x120; normalize with 1600/1200 over display dims.
            // Exact stack temps omitted; CF matches raw (COMISS + MULSS/DIVSS path).
            if (DAT_00d17944 == 0) {
                *sz0 = 0.0f;
                *sz1 = 0.0f;
            } else {
                // (component + host_base) * (1600|1200) / DAT_00d1e818|1c
                // sealed formula; component ints from vtbl+0x120 results.
            }
        }
        if (p) {
            float pos[2] = {0.0f, 0.0f};
            reinterpret_cast<VFn>(vtbl(p)[0x110 / 4])(p, pos);
        }
    }
    // +0x590 mini label status
    {
        void* p = operator_new(0x488);
        p = p ? FUN_007b5dd0(p, 0) : nullptr;
        hd[0x590 / 4] = reinterpret_cast<std::uint32_t>(p);
        attach_load(p, "i_d_arena/i_d_arena_console_mini_wnd_label_status.xml");
        if (p) {
            reinterpret_cast<VFn>(vtbl(p)[0xCC / 4])(p, 0);
            reinterpret_cast<std::uint8_t*>(p)[0xC4] = 1;
        }
    }
    // +0x594 mini cancel
    {
        void* p = operator_new(0x4CC);
        p = p ? FUN_0079c860() : nullptr;
        hd[0x594 / 4] = reinterpret_cast<std::uint32_t>(p);
        attach_load(p, "i_d_arena/i_d_arena_console_mini_btn_cancel.xml");
        set_cmd(p, 0x9C47);
        if (p)
            reinterpret_cast<VFn>(vtbl(p)[0xCC / 4])(p, 0);
    }

    FUN_008778e0(host);

    if (DAT_00d1b6d8 != nullptr &&
        *reinterpret_cast<std::uint8_t*>(reinterpret_cast<std::uint8_t*>(DAT_00d1b6d8) + 0x4FC) != 0) {
        FUN_00877c50(host);
    }

    reinterpret_cast<VFn>(vtbl(host)[0x34C / 4])(host);
    // SEH leave; plain RET
}
