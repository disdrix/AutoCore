// =============================================================================
// FUN_0090c9a0  (machine twin of MedalUi_ApplyAchievementSlotButton_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0090c9a0
// Address:   0x0090c9a0 – 0x0090cbbb  (autoassault.exe, image base 0x400000)
// System:    missions-progression / Medal UI
// Generated: 2026-08-05 MEGA-095 dual
// Exactness: Behavior-preserving; ABI corrected from listing (not void).
// Named twin: MedalUi_ApplyAchievementSlotButton_Inferred.cpp
// =============================================================================

// See MedalUi_ApplyAchievementSlotButton_Inferred.cpp for full annotated port.
// This twin retains the Ghidra symbol as the machine entry symbol.

#include <cstdint>

struct UiHost;
struct UiWidget;
struct MedalDef;

extern "C" void* __cdecl operator_new(unsigned size);
extern "C" UiWidget* __stdcall FUN_007b5dd0(void* mem, int zero_flag);

extern float DAT_00d1e818;
extern float DAT_00d1e81c;
extern float DAT_00aaa678;
extern float DAT_00aaa67c;
extern char  DAT_00a2c53c[];
extern char  DAT_00a2c540;

// Retail: ESI=host, EBX=slotIndex, stack medalDef + earnedFlag, RET 8
void FUN_0090c9a0(
    UiHost* host,
    int slotIndex,
    MedalDef* medalDef,
    std::uint32_t earnedFlag)
{
    void* raw = operator_new(0x488);
    UiWidget* widget = raw ? FUN_007b5dd0(raw, 0) : nullptr;

    *reinterpret_cast<UiWidget**>(
        reinterpret_cast<std::uint8_t*>(host) + 0x540 + slotIndex * 4) = widget;

    auto hostVtbl = *reinterpret_cast<std::uintptr_t**>(host);
    using FnHost = void(__thiscall*)(UiHost*, UiWidget*);
    (*reinterpret_cast<FnHost*>(reinterpret_cast<std::uint8_t*>(hostVtbl) + 0xa8))
        (host, widget);

    auto wVtbl = *reinterpret_cast<std::uintptr_t**>(widget);
    using FnLoad = void(__thiscall*)(UiWidget*, const char*);
    (*reinterpret_cast<FnLoad*>(reinterpret_cast<std::uint8_t*>(wVtbl) + 0x28))
        (widget, "i_d_a_2d_btn_achievement.xml");

    using FnSize = float*(__thiscall*)(UiWidget*, void*);
    auto getSize = *reinterpret_cast<FnSize*>(
        reinterpret_cast<std::uint8_t*>(wVtbl) + 0x134);
    float scratch[8];
    const int row = slotIndex / 3;
    const int col = slotIndex % 3;
    float* sy = getSize(widget, scratch);
    int dy = (int)((float)DAT_00d1e81c *
                   (float)(((int)sy[1] + 0x1f) * row) * DAT_00aaa678);
    float* sx = getSize(widget, scratch);
    int dx = (int)((float)DAT_00d1e818 *
                   (float)(((int)sx[0] + 0x28) * col) * DAT_00aaa67c);

    using FnOrigin = int*(__thiscall*)(UiWidget*, void*, int, int);
    auto getOrigin = *reinterpret_cast<FnOrigin*>(
        reinterpret_cast<std::uint8_t*>(wVtbl) + 0x120);
    int* oy = getOrigin(widget, scratch, 1, 0);
    int posY = oy[1] + dy;
    int* ox = getOrigin(widget, scratch, 1, 0);
    int posX = ox[0] + dx;
    int pos[2] = { posX, posY };

    *(reinterpret_cast<std::uint8_t*>(host) + 0x510 + slotIndex) =
        *reinterpret_cast<std::uint8_t*>(medalDef);

    char nameBuf[0x100];
    const char* src = *reinterpret_cast<const char**>(
        reinterpret_cast<std::uint8_t*>(medalDef) + 0x10);
    char* dst = nameBuf;
    char c;
    do {
        c = *src++;
        *dst++ = c;
    } while (c != '\0');
    dst = nameBuf;
    while (*dst) ++dst;
    *reinterpret_cast<std::uint32_t*>(dst) =
        *reinterpret_cast<std::uint32_t*>(DAT_00a2c53c);
    dst[4] = DAT_00a2c540;

    using FnName = void(__thiscall*)(UiWidget*, char*, int, int);
    (*reinterpret_cast<FnName*>(reinterpret_cast<std::uint8_t*>(wVtbl) + 0x50))
        (widget, nameBuf, 0, 0);
    using FnPos = void(__thiscall*)(UiWidget*, int*);
    (*reinterpret_cast<FnPos*>(reinterpret_cast<std::uint8_t*>(wVtbl) + 0x118))
        (widget, pos);
    using FnRef = void(__thiscall*)(UiWidget*);
    (*reinterpret_cast<FnRef*>(reinterpret_cast<std::uint8_t*>(wVtbl) + 0x34c))
        (widget);
    using FnId = void(__thiscall*)(UiWidget*, int);
    (*reinterpret_cast<FnId*>(reinterpret_cast<std::uint8_t*>(wVtbl) + 0x74))
        (widget, slotIndex + 0x9c43);

    if ((std::uint8_t)earnedFlag == 0) {
        using FnMode = void*(__thiscall*)(UiWidget*, int);
        using FnApply = void(__thiscall*)(UiWidget*, int, void*);
        void* mode = (*reinterpret_cast<FnMode*>(
            reinterpret_cast<std::uint8_t*>(wVtbl) + 0x164))(widget, 2);
        (*reinterpret_cast<FnApply*>(
            reinterpret_cast<std::uint8_t*>(wVtbl) + 0x154))(widget, 0, mode);
    }
}
