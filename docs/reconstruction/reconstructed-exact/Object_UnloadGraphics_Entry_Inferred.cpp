// =============================================================================
// Object_UnloadGraphics_Entry_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005d4fd0
// Address:   0x005d4fd0  (autoassault.exe, image base 0x400000)
// System:    client / object graphics lifecycle
// Wave:      W37-AB (2026-08-04)
// Exactness: Behavior-preserving rewrite of decompiler + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED (no Launcher).
// Ghidra:    FUN_005d4fd0
// String:    "UnloadGraphics on %s (%d)" @ 0x009dac54
// =============================================================================
//
// PURPOSE:
//   Vtable-installed logged entry for unload-graphics:
//   1) Resolve name id from optional record at root+0x6C (+0x34), else -1.
//   2) Root vtbl+0x160(nameId) → log argument.
//   3) FUN_007a4480(-1, "UnloadGraphics on %s (%d)", arg).
//   4) Object_UnloadGraphics_Inferred (FUN_005825d0, W31-T) with same ECX.
//   5) Tail JMP to base vtbl+4 with this = self-0x40 (not call+ret).
//
// DATA: 8 vtable installs (no direct CODE callers).
// NOTE: Format has %s and %d but only one intentional vararg after format (bytes).
// =============================================================================

#include <cstdint>

extern "C" void __fastcall Object_UnloadGraphics_Inferred(void* mi_this); // 0x005825d0
extern "C" void FUN_007a4480(int level, const char* fmt, ...);

// __thiscall: ECX = MI object pointer; void; ends in tail JMP
extern "C" void __fastcall Object_UnloadGraphics_Entry_Inferred(uint8_t* self)
{
    // vbtable path: *( *(self-0x3C) + 4 ) adjusted with self
    int* vb = *reinterpret_cast<int**>(self - 0x3C);
    int adj = vb[1]; // +4
    uint8_t* root_base = self + adj - 0x3C;

    int* name_rec = *reinterpret_cast<int**>(root_base + 0xA8); // ≡ decompiler root+0x6C path
    uint32_t name_id = (name_rec == nullptr)
        ? 0xFFFFFFFFu
        : *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(name_rec) + 0x34);

    // thiscall root vtbl+0x160(name_id)
    void** root_vtbl = *reinterpret_cast<void***>(root_base);
    using Fn160 = void* (__thiscall*)(void* root, uint32_t id);
    void* name_arg = reinterpret_cast<Fn160>(root_vtbl[0x160 / 4])(root_base, name_id);

    FUN_007a4480(-1, "UnloadGraphics on %s (%d)", name_arg);

    Object_UnloadGraphics_Inferred(self);

    // Tail (bytes): LEA ECX,[ESI-0x40]; JMP [EAX+4] — decompiler shows call+return incorrectly
    uint8_t* base = self - 0x40;
    void** base_vtbl = *reinterpret_cast<void***>(base);
    using Fn04 = void (__thiscall*)(void*);
    reinterpret_cast<Fn04>(base_vtbl[1])(base);
}

// Twin Ghidra name
extern "C" void __fastcall FUN_005d4fd0(uint8_t* self)
{
    Object_UnloadGraphics_Entry_Inferred(self);
}
