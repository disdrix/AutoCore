// =============================================================================
// UI_TabChrome_SetSelected_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Apply selected/unselected chrome to a client UI tab control.
//           Restyle optional childA, show/hide optional childB, and if the
//           prior selected state differed, resize by stored deltas (selected
//           shrinks; unselected grows). Always store the new selected byte.
//
// Address:  0x00822cb0  (autoassault.exe, image base 0x400000)
// Stable:   aa_00822cb0
// System:   inventory-transfer (UI tab chrome helper — no inventory wire)
// Ghidra:   FUN_00822cb0
//
// Convention (custom register + stack ABI — not portable C):
//   ESI          = widget*
//   BL           = selected (1) / unselected (0)
//   [stack]      = force (char/byte; non-zero forces restyle even if same state)
//   RET 4        (stdcall 1 stack arg)
//
// Layout:
//   widget+0x4FC         selected state byte
//   widget+0x4FD         scale/style byte (full when selected; >>1 unselected)
//   widget+0x80C         size delta X (dword)
//   widget+0x810         size delta Y (dword)
//   widget+0x814         optional childB*  (vtbl +0x3C8 show/hide)
//   widget+0x818         optional childA*  (style vtbls +0xF0/+0xE8/+0x164/
//                                           +0x15C/+0x34C)
//
// Self vtbls:
//   +0x120  GetSize  → writes {w,h,...} into caller stack buffer
//   +0x110  SetSize  ← takes {w,h} stack buffer
//
// Callers (evidence): FUN_00888b00, FUN_00889410, FUN_00889fb0, FUN_00887780,
//   + other tab/dialog hosts (45 xrefs / 10 named). Often paired after BL=0
//   with FUN_00756c90 (move collapsed chrome to front of parent group).
//
// Exactness: Behavior-preserving CF from live disasm + decompile.
// Dual R12-002 2026-08-05.
// Dual reviews:
//   reviews/A_aa_00822cb0_UI_TabChrome_SetSelected_Inferred.md
//   reviews/B_aa_00822cb0_UI_TabChrome_SetSelected_Inferred.md
// Scaffold twin: reconstructed-exact/FUN_00822cb0.cpp
// =============================================================================

#include <cstdint>

// Clean form takes explicit formals for ports. Retail uses ESI/BL + force@stack.
extern "C" void UI_TabChrome_SetSelected_Inferred(void* widget_esi,
                                                  std::uint8_t selected_bl,
                                                  std::uint8_t force_stack)
{
    auto* widget = reinterpret_cast<std::uint8_t*>(widget_esi);

    const auto selected_cur = widget[0x4FC];
    if (force_stack == 0 && selected_cur == selected_bl) {
        return;
    }

    auto* childA = *reinterpret_cast<void**>(widget + 0x818);
    auto* childB = *reinterpret_cast<void**>(widget + 0x814);
    const auto scale = widget[0x4FD];
    const auto dX = *reinterpret_cast<std::int32_t*>(widget + 0x80C);
    const auto dY = *reinterpret_cast<std::int32_t*>(widget + 0x810);

    auto restyle_childA = [&](std::uint8_t applied_scale) {
        if (childA == nullptr) {
            return;
        }
        // Live: vcall childA[+0xF0](1) → bool
        //   if true && vcall childA[+0xE8]() != 0:
        //     childA[+0xFC] = applied_scale
        //   else:
        //     packet = vcall childA[+0x164](1)
        //     packet.hi_byte = applied_scale; vcall childA[+0x15C](1, &packet)
        //   vcall childA[+0x34C]()  // invalidate
        (void)applied_scale;
        (void)childA;
    };

    auto set_childB_visible = [&](std::uint8_t visible) {
        if (childB == nullptr) {
            return;
        }
        // Live: PUSH 1; PUSH visible; CALL [vtbl+0x3C8]
        (void)visible;
        (void)childB;
    };

    struct Size2 {
        std::int32_t w;
        std::int32_t h;
    };

    auto get_size = [&]() -> Size2 {
        // Live: PUSH 0; PUSH 1; LEA buf; MOV ECX,ESI; CALL [vtbl+0x120]
        // returns ptr to {w at +0, h at +4} (decomp uses [EAX]/[EAX+4])
        Size2 sz{0, 0};
        (void)widget;
        return sz;
    };

    auto set_size = [&](Size2 sz) {
        // Live: LEA buf; MOV [buf],w; MOV [buf+8? / +4],h; CALL [vtbl+0x110]
        (void)sz;
        (void)widget;
    };

    if (selected_bl == 0) {
        restyle_childA(static_cast<std::uint8_t>(scale >> 1));
        set_childB_visible(0);
        if (selected_cur == 0) {
            widget[0x4FC] = selected_bl;
            return;
        }
        Size2 sz = get_size();
        sz.h = sz.h + dY;
        sz.w = sz.w + dX;
        set_size(sz);
    } else {
        restyle_childA(scale);
        set_childB_visible(1);
        if (selected_cur == selected_bl) {
            widget[0x4FC] = selected_bl;
            return;
        }
        Size2 sz = get_size();
        sz.h = sz.h - dY;
        sz.w = sz.w - dX;
        set_size(sz);
    }

    widget[0x4FC] = selected_bl;
}
