// =============================================================================
// FUN_004023f0  (Ghidra symbol twin of StdList_DefaultCtor_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004023f0
// Address:   0x004023f0  (autoassault.exe, image base 0x400000)
// Body:      0x004023f0–0x00402405 inclusive (22 B / 0x16)
// System:    shared MSVC std::list
// Generated: 2026-08-05 MEGA-052 dual re-verify
// Canonical: StdList_DefaultCtor_Inferred.cpp
// Exactness: Behavior-preserving rewrite of decompiler + sealed bytes. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

extern "C" void* __cdecl StdList_AllocEmptySentinel_Inferred(void);

// ECX=list*; EAX=list*; RET
extern "C" void* __fastcall FUN_004023f0(void* self)
{
    void* head = StdList_AllocEmptySentinel_Inferred();
    *reinterpret_cast<void**>(reinterpret_cast<std::uint8_t*>(self) + 0x4) = head;
    *reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::uint8_t*>(self) + 0x8) = 0;
    return self;
}
