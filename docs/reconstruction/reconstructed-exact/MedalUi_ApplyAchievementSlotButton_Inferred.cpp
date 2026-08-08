// =============================================================================
// MedalUi_ApplyAchievementSlotButton_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0090c9a0
// Address:   0x0090c9a0 – 0x0090cbbb  (autoassault.exe, image base 0x400000)
// Size:      540 bytes (0x21C)
// System:    missions-progression / Medal UI
// Generated: 2026-08-05 MEGA-095 dual (live Ghidra re-verify)
// Exactness: Behavior-preserving rewrite of decompiler CF + listing ABI.
//            Not modernization. Not bit-for-bit.
// Bit-for-bit vs retail EXE: DEFERRED
// Runtime Confirmed: OPEN (no Launcher)
// =============================================================================
//
// PURPOSE:
//   Create/bind one achievement/medal slot button on the medal UI host:
//     - allocate 0x488 UI widget via FUN_007b5dd0
//     - store at host slot array +0x540[slotIndex]
//     - load layout "i_d_a_2d_btn_achievement.xml"
//     - place in 3-column grid from slotIndex
//     - bind medal texture name (medalDef+0x10 + ".dds")
//     - assign control id (slotIndex + 0x9c43)
//     - if earnedFlag==0, apply unowned/dim visual (vtbl +0x164/+0x154)
//
// ABI (sealed via disassemble_function + parent FUN_0090cbc0 call sites):
//   ESI        = host (achievements/medal UI panel)
//   EBX        = slotIndex (0..0x17)
//   stack+0    = MedalDef* (from MedalDef_LookupById / FUN_0051a0e0)
//   stack+4    = earnedFlag (1=owned list path, 0=unowned hash path)
//   return     = void
//   cleanup    = RET 8  (stdcall two dwords)
//
// CALLERS:
//   FUN_0090cbc0 @ 0x0090ccea (PUSH 1; PUSH medalDef)  — owned medals
//   FUN_0090cbc0 @ 0x0090cdb4 (PUSH 0; PUSH medalDef)  — unowned remainder
//
// CALLEES:
//   operator_new @ 0x00489892
//   FUN_007b5dd0 @ 0x007b5dd0  (UI widget ctor; size 0x488)
//   + host/widget virtuals (offsets below)
//
// PRIOR NAMES (retired scaffolds):
//   FUN_0090c9a0
//   Named_CalleeOf_Named_VOG_DEBUG_STOP_0090c9a0
//   UI_a_btn_achievement  (plate alias; still valid evidence string)
//
// STRINGS / CONSTANTS:
//   "i_d_a_2d_btn_achievement.xml" @ 0x00a31024
//   ".dds" @ DAT_00a2c53c
//   DAT_00aaa678 ≈ 0.0008333334f  (Y scale)
//   DAT_00aaa67c ≈ 0.000625f      (X scale)
//   DAT_00d1e818 / DAT_00d1e81c    (runtime UI scale; 0 in static image)
// =============================================================================

#include <cstdint>

// Forward decls — retail types not fully recovered.
struct UiHost;       // achievements/medal panel (product English open)
struct UiWidget;     // FUN_007b5dd0 instance (0x488)
struct MedalDef;     // from MedalDef_LookupById (FUN_0051a0e0)

extern "C" void* __cdecl operator_new(unsigned size);
extern "C" UiWidget* __stdcall FUN_007b5dd0(void* mem, int zero_flag);

// Runtime globals
extern float DAT_00d1e818;
extern float DAT_00d1e81c;
extern float DAT_00aaa678;   // ≈ 0.0008333334f
extern float DAT_00aaa67c;   // ≈ 0.000625f
extern char  DAT_00a2c53c[]; // ".dds"
extern char  DAT_00a2c540;   // trailing 0

// MSVC FS ExceptionList (SEH) — preserved as control artifact only.
extern void* ExceptionList;
extern void* LAB_009b3aab;

// -----------------------------------------------------------------------------
// Retail calling convention (not portable C++):
//   ESI = host, EBX = slotIndex, stack medalDef + earnedFlag, RET 8
// Portable reconstruction documents the same contract explicitly.
// -----------------------------------------------------------------------------
void MedalUi_ApplyAchievementSlotButton_Inferred(
    UiHost* host,            // ESI
    int slotIndex,           // EBX
    MedalDef* medalDef,      // stack arg0
    std::uint32_t earnedFlag // stack arg1
)
{
    // --- SEH frame (LAB_009b3aab) omitted in portable form ---

    // 1) Allocate + construct widget (0x488)
    void* raw = operator_new(0x488);
    UiWidget* widget = nullptr;
    if (raw != nullptr) {
        widget = FUN_007b5dd0(raw, 0);
    }

    // 2) Store into host slot pointer array at +0x540
    //    listing: MOV [ESI + EBX*4 + 0x540], EAX
    *reinterpret_cast<UiWidget**>(
        reinterpret_cast<std::uint8_t*>(host) + 0x540 + slotIndex * 4) = widget;

    // 3) Host attach/register child — vtbl +0xa8 (ECX=host)
    //    (**(code**)(*host + 0xa8))(widget);
    using Host_Attach = void(__thiscall*)(UiHost*, UiWidget*);
    Host_Attach attach = *reinterpret_cast<Host_Attach*>(
        *reinterpret_cast<std::uintptr_t*>(host) + 0xa8);
    attach(host, widget);

    // 4) Load layout XML — widget vtbl +0x28
    using Widget_LoadXml = void(__thiscall*)(UiWidget*, const char*);
    Widget_LoadXml loadXml = *reinterpret_cast<Widget_LoadXml*>(
        *reinterpret_cast<std::uintptr_t*>(widget) + 0x28);
    loadXml(widget, "i_d_a_2d_btn_achievement.xml");

    // 5) Size query helper — vtbl +0x134 returns float* (x,y)
    using Widget_GetSize = float*(__thiscall*)(UiWidget*, void* out);
    auto* vtbl = *reinterpret_cast<std::uintptr_t**>(widget);
    Widget_GetSize getSize = *reinterpret_cast<Widget_GetSize*>(
        reinterpret_cast<std::uint8_t*>(vtbl) + 0x134);

    // row = slot/3, col = slot%3
    const int row = slotIndex / 3;
    const int col = slotIndex % 3;

    float sizeScratch[8];
    float* sizeY = getSize(widget, sizeScratch);
    const int dy = static_cast<int>(
        static_cast<float>(DAT_00d1e81c) *
        static_cast<float>((static_cast<int>(sizeY[1]) + 0x1f) * row) *
        DAT_00aaa678);

    float* sizeX = getSize(widget, sizeScratch);
    const int dx = static_cast<int>(
        static_cast<float>(DAT_00d1e818) *
        static_cast<float>((static_cast<int>(sizeX[0]) + 0x28) * col) *
        DAT_00aaa67c);

    // 6) Origin via vtbl +0x120; compose pos
    using Widget_GetOrigin = int*(__thiscall*)(UiWidget*, void* out, int a, int b);
    Widget_GetOrigin getOrigin = *reinterpret_cast<Widget_GetOrigin*>(
        reinterpret_cast<std::uint8_t*>(vtbl) + 0x120);
    int* oy = getOrigin(widget, sizeScratch, 1, 0);
    int posY = oy[1] + dy;
    int* ox = getOrigin(widget, sizeScratch, 1, 0);
    int posX = ox[0] + dx;
    int pos[2] = { posX, posY };

    // 7) Per-slot status byte from medalDef[0] → host+0x510+slot
    *reinterpret_cast<std::uint8_t*>(
        reinterpret_cast<std::uint8_t*>(host) + 0x510 + slotIndex) =
        *reinterpret_cast<std::uint8_t*>(medalDef);

    // 8) Build texture name: strcpy(medalDef+0x10) + ".dds"
    char nameBuf[0x100];
    const char* src = *reinterpret_cast<const char**>(
        reinterpret_cast<std::uint8_t*>(medalDef) + 0x10);
    // byte-copy until NUL (retail do-while)
    char* dst = nameBuf;
    char c;
    do {
        c = *src++;
        *dst++ = c;
    } while (c != '\0');
    // append ".dds" (DAT_00a2c53c dword + DAT_00a2c540 byte)
    dst = nameBuf;
    while (*dst) ++dst;
    *reinterpret_cast<std::uint32_t*>(dst) =
        *reinterpret_cast<std::uint32_t*>(DAT_00a2c53c); // '.','d','d','s'
    dst[4] = DAT_00a2c540; // 0

    // 9) Set texture/name — vtbl +0x50
    using Widget_SetName = void(__thiscall*)(UiWidget*, char*, int, int);
    Widget_SetName setName = *reinterpret_cast<Widget_SetName*>(
        reinterpret_cast<std::uint8_t*>(vtbl) + 0x50);
    setName(widget, nameBuf, 0, 0);

    // 10) Set position — vtbl +0x118
    using Widget_SetPos = void(__thiscall*)(UiWidget*, int*);
    Widget_SetPos setPos = *reinterpret_cast<Widget_SetPos*>(
        reinterpret_cast<std::uint8_t*>(vtbl) + 0x118);
    setPos(widget, pos);

    // 11) Refresh — vtbl +0x34c
    using Widget_Refresh = void(__thiscall*)(UiWidget*);
    Widget_Refresh refresh = *reinterpret_cast<Widget_Refresh*>(
        reinterpret_cast<std::uint8_t*>(vtbl) + 0x34c);
    refresh(widget);

    // 12) Control id = slotIndex + 0x9c43 — vtbl +0x74
    using Widget_SetId = void(__thiscall*)(UiWidget*, int);
    Widget_SetId setId = *reinterpret_cast<Widget_SetId*>(
        reinterpret_cast<std::uint8_t*>(vtbl) + 0x74);
    setId(widget, slotIndex + 0x9c43);

    // 13) Unowned path: earnedFlag == 0 → dim/lock visual
    if (static_cast<std::uint8_t>(earnedFlag) == 0) {
        using Widget_GetMode = void*(__thiscall*)(UiWidget*, int);
        using Widget_ApplyMode = void(__thiscall*)(UiWidget*, int, void*);
        Widget_GetMode getMode = *reinterpret_cast<Widget_GetMode*>(
            reinterpret_cast<std::uint8_t*>(vtbl) + 0x164);
        Widget_ApplyMode applyMode = *reinterpret_cast<Widget_ApplyMode*>(
            reinterpret_cast<std::uint8_t*>(vtbl) + 0x154);
        void* mode = getMode(widget, 2);
        applyMode(widget, 0, mode);
    }

    // RET 8
}
