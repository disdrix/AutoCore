// =============================================================================
// FUN_005d4fd0  (twin of Object_UnloadGraphics_Entry_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_005d4fd0
// Address:   0x005d4fd0  (autoassault.exe, image base 0x400000)
// Wave:      W37-AB (2026-08-04)
// See:       Object_UnloadGraphics_Entry_Inferred.cpp
// String:    "UnloadGraphics on %s (%d)"
// =============================================================================

#include <cstdint>

extern "C" void __fastcall FUN_005825d0(void* mi_this);
extern "C" void FUN_007a4480(int level, const char* fmt, ...);

// __thiscall via ECX; void; tail-chain (decompiler call form kept for CF parity)
extern "C" void __fastcall FUN_005d4fd0(int self)
{
    int name_rec = *reinterpret_cast<int*>(
        *reinterpret_cast<int*>(*reinterpret_cast<int*>(self - 0x3C) + 4) + self + 0x6C);

    uint32_t name_id;
    if (name_rec == 0) {
        name_id = 0xFFFFFFFFu;
    } else {
        name_id = *reinterpret_cast<uint32_t*>(name_rec + 0x34);
    }

    void** root_vtbl = *reinterpret_cast<void***>(
        *reinterpret_cast<int*>(*reinterpret_cast<int*>(self - 0x3C) + 4) + self - 0x3C);
    using Fn160 = uint32_t (__thiscall*)(void* root, uint32_t id);
    void* root = reinterpret_cast<void*>(
        *reinterpret_cast<int*>(*reinterpret_cast<int*>(self - 0x3C) + 4) + self - 0x3C);
    uint32_t log_arg = reinterpret_cast<Fn160>(root_vtbl[0x160 / 4])(root, name_id);

    FUN_007a4480(-1, "UnloadGraphics on %s (%d)", log_arg);
    FUN_005825d0(reinterpret_cast<void*>(self));

    // Bytes: tail JMP [*(self-0x40)+4] with this=self-0x40
    void** base_vtbl = *reinterpret_cast<void***>(self - 0x40);
    using Fn04 = void (__thiscall*)(void*);
    reinterpret_cast<Fn04>(base_vtbl[1])(reinterpret_cast<void*>(self - 0x40));
}
