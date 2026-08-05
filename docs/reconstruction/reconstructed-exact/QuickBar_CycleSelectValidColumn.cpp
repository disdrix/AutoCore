// =============================================================================
// QuickBar_CycleSelectValidColumn  (was FUN_008a0210)
// -----------------------------------------------------------------------------
// Stable ID: aa_008a0210
// Address:   0x008a0210  (autoassault.exe, image base 0x400000)
// System:    client UI / quickbar
// Body:      0x008a0210–0x008a0368 exclusive (344 B)
//
// Purpose: From CDlgQuickBar host in EBX, find the currently selected column
// (widget+0x4fc), then walk adjacent columns (direction: 0=prev, !=0=next) for
// the next filled slot (widget+0x548 != 0 && != 6). On hit: deselect current and
// select target via UI_QuickBarSlotButton_SetSelected (0x00826780). If no column
// is selected, bootstrap-select the first filled column (inline SetSelected(1)).
//
// ABI (custom register + stdcall arg):
//   EBX  = CDlgQuickBar* host
//   stack: char direction
//   ret 4; AL always 0
//
// Exactness: control flow mirrors Ghidra decompile 2026-07-29 W21-T; ECX rewrite
// on the SetSelected pair restored from live body bytes (decompiler gap).
// Dual: reviews/A_aa_008a0210_* and B_aa_008a0210_*
// =============================================================================

#include <cstdint>

// Sealed sibling: UI_QuickBarSlotButton_SetSelected @ 0x00826780
extern void __fastcall UI_QuickBarSlotButton_SetSelected(int* columnWidget, int /*unused edx*/, char fSelected);

// Peer exclusive-clear helper (uses EAX = CDlgQuickBar* from prior cast)
extern void FUN_0089fef0(void);

extern "C" void* __cdecl __RTDynamicCast(void* obj, long vfDelta, void* srcType, void* targetType, int isRef);
extern void* gfxUIWindow_RTTI_Type_Descriptor;   // 0x00afe190
extern void* CDlgQuickBar_RTTI_Type_Descriptor;  // 0x00afe3b4
extern std::uint32_t DAT_00d1da38[];             // page → last selected column id

// Retail entry: EBX=host, stack char direction, ret 4.
// Written as an explicit-args form for readability; register binding is ABI.
std::uint32_t QuickBar_CycleSelectValidColumn(int* host /*EBX*/, char direction /*stack*/)
{
    int* cols = reinterpret_cast<int*>(reinterpret_cast<char*>(host) + 0x63c);
    int cur = 0;
    int* p = cols;

    // Find currently selected column
    do {
        if ((*p != 0) && (*reinterpret_cast<char*>(*p + 0x4fc) != 0)) {
            int i = cur;
            if (direction == 0)
                goto scan_prev;
            goto scan_next;
        }
        cur++;
        p++;
    } while (cur < 10);
    goto no_current;

    // ---- next (wrap 0..9) ----
    while (true) {
        if (i > 9)
            i = 0;
        {
            int w = *reinterpret_cast<int*>(reinterpret_cast<char*>(host) + 0x63c + i * 4);
            int* kind = nullptr;
            if ((w != 0) &&
                (kind = *reinterpret_cast<int**>(w + 0x548), kind != nullptr) &&
                (kind != reinterpret_cast<int*>(6)))
                break;
        }
    scan_next:
        i++;
        if (i == cur)
            goto no_current;
    }
    goto apply_pair;

    // ---- prev (wrap 0..9) ----
    while (true) {
        if (i < 0)
            i = 9;
        {
            int w = *reinterpret_cast<int*>(reinterpret_cast<char*>(host) + 0x63c + i * 4);
            int* kind = nullptr;
            if ((w != 0) &&
                (kind = *reinterpret_cast<int**>(w + 0x548), kind != nullptr) &&
                (kind != reinterpret_cast<int*>(6)))
                break;
        }
    scan_prev:
        i--;
        if (i == cur)
            goto no_current;
    }

apply_pair:
    {
        int* currentCol =
            *reinterpret_cast<int**>(reinterpret_cast<char*>(host) + 0x63c + cur * 4);
        int* targetCol =
            *reinterpret_cast<int**>(reinterpret_cast<char*>(host) + 0x63c + i * 4);
        // LIVE: ECX=currentCol; push 0; call SetSelected
        //       ECX=targetCol;  push 1; call SetSelected
        UI_QuickBarSlotButton_SetSelected(currentCol, 0, 0);
        UI_QuickBarSlotButton_SetSelected(targetCol, 0, 1);
    }

no_current:
    if (cur == 10) {
        unsigned idx = 0;
        int* scan = cols;
        while ((*scan == 0) ||
               (*reinterpret_cast<int*>(*scan + 0x548) == 0) ||
               (*reinterpret_cast<int*>(*scan + 0x548) == 6)) {
            idx++;
            scan++;
            if (static_cast<int>(idx) > 9)
                return 0;
        }
        int w = *reinterpret_cast<int*>(reinterpret_cast<char*>(host) + 0x63c + idx * 4);
        int* kind = *reinterpret_cast<int**>(w + 0x548);
        if ((kind != nullptr) && (kind != reinterpret_cast<int*>(6))) {
            __RTDynamicCast(*reinterpret_cast<void**>(w + 0x88), 0,
                            &gfxUIWindow_RTTI_Type_Descriptor,
                            &CDlgQuickBar_RTTI_Type_Descriptor, 0);
            FUN_0089fef0();
            if (*reinterpret_cast<int**>(w + 0x56c) != nullptr) {
                int* hl = *reinterpret_cast<int**>(w + 0x56c);
                (**(void (**)(int))(*hl + 4))(1);
            }
            DAT_00d1da38[*reinterpret_cast<int*>(w + 0x504)] =
                *reinterpret_cast<std::uint32_t*>(w + 0x500);
            *reinterpret_cast<char*>(w + 0x4fc) = 1;
        }
    }
    return 0;
}
