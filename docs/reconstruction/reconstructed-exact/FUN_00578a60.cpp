// =============================================================================
// FUN_00578a60  (scaffold twin — prefer CVOGHBSkillBase_dtor.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_00578a60
// Address:   0x00578a60–0x00578ab2 inclusive  (autoassault.exe, image base 0x400000)
// Body:      83 bytes / 0x53
// System:    skills-abilities
// Named:     CVOGHBSkillBase_dtor
// Generated: 2026-07-23 scaffold; R12-026 2026-08-05 assembly-corrected twin
// Exactness: Behavior-preserving rewrite of assembly CF. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (Terminal false).
// =============================================================================

// PURPOSE: Complete destructor body for CVOGHBSkillBase (non-scalar).
// See CVOGHBSkillBase_dtor.cpp for named plate and dual seal notes.

#include <cstdint>

extern "C" void *PTR_FUN_009d3fdc[];
extern "C" void __fastcall FUN_00508390(void *thisHb /* ECX */);
extern "C" void __cdecl operator_delete(void *p);
extern "C" void __cdecl operator_delete[](void *p);

/*
 * Behavioral notes (R12-026):
 * - Scaffold raw decompile used dword indices (0x1a8 = +0x6a0, 0x1ac = +0x6b0).
 * - Decompiler: false noreturn on operator_delete; CALL+return for base (machine JMP).
 * - ABI: thiscall ECX; no free of this object.
 */

void __fastcall FUN_00578a60(void *param_1 /* ECX */)
{
    auto *base = reinterpret_cast<std::uint8_t *>(param_1);
    void *pArr = *reinterpret_cast<void **>(base + 0x6a0);
    void *pBuf;

    *reinterpret_cast<void **>(param_1) = PTR_FUN_009d3fdc;

    if (pArr != nullptr) {
        operator_delete[](pArr);
    }
    *reinterpret_cast<void **>(base + 0x6a0) = nullptr;

    pBuf = *reinterpret_cast<void **>(base + 0x6b0);
    if (pBuf != nullptr) {
        operator_delete(pBuf);
    }
    *reinterpret_cast<void **>(base + 0x6b0) = nullptr;
    *reinterpret_cast<void **>(base + 0x6b4) = nullptr;
    *reinterpret_cast<void **>(base + 0x6b8) = nullptr;

    FUN_00508390(param_1); // tail JMP on machine
}
