// =============================================================================
// FUN_00929c00  (machine twin of MissionTracker_ResetUiStateFields_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00929c00
// Address:   0x00929c00–0x00929c50 inclusive (81 B / 0x51)
// Module:    autoassault.exe (image base 0x400000)
// System:    missions-progression / mission-tracker UI state
// Sealed:    2026-08-05 MEGA-087 OWN dual
// Exactness: Behavior-preserving rewrite of decompiler + assembly control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: Reset tracker UI/state fields to defaults (ids -1, flags 0, range 25.0f).
// ABI: EAX = tracker*; bare RET; AL = 1. Leaf.
// Named clean: MissionTracker_ResetUiStateFields_Inferred.cpp
// =============================================================================

#include <cstdint>

extern "C" float DAT_00aaa6fc; // 0x00aaa6fc = 25.0f

// Image object pointer arrives in EAX (decompiler: in_EAX).
std::uint32_t FUN_00929c00(void /* EAX = tracker base */)
{
    // Recover EAX object for portability in this twin.
    // Call sites: MOV EAX,EDI/ESI ; CALL FUN_00929c00
    int in_EAX;
#if defined(_MSC_VER) && defined(_M_IX86)
    __asm { mov in_EAX, eax }
#else
    // Non-x86 host: signature is illustrative only.
    in_EAX = 0;
#endif

    std::uint32_t uVar1 = *reinterpret_cast<std::uint32_t*>(&DAT_00aaa6fc);

    *reinterpret_cast<std::uint32_t*>(in_EAX + 0x18)  = 0xFFFFFFFFu;
    *reinterpret_cast<std::uint32_t*>(in_EAX + 0x20)  = 0xFFFFFFFFu;
    *reinterpret_cast<std::uint32_t*>(in_EAX + 0x24)  = 0xFFFFFFFFu;
    *reinterpret_cast<std::uint32_t*>(in_EAX + 0x54)  = 0;
    *reinterpret_cast<std::uint32_t*>(in_EAX + 0x80)  = 0;
    *reinterpret_cast<std::uint32_t*>(in_EAX + 0xac)  = 0;
    *reinterpret_cast<std::uint32_t*>(in_EAX + 0x28)  = 0;
    *reinterpret_cast<std::uint8_t*>(in_EAX + 0x100)  = 0;
    *reinterpret_cast<std::uint8_t*>(in_EAX + 0x101)  = 0;
    *reinterpret_cast<std::uint8_t*>(in_EAX + 0x102)  = 0;
    *reinterpret_cast<std::uint32_t*>(in_EAX + 0x104) = uVar1; // float bits of 25.0f
    *reinterpret_cast<std::uint32_t*>(in_EAX + 0x108) = 0xFFFFFFFFu;
    *reinterpret_cast<std::uint32_t*>(in_EAX + 0x10c) = 0xFFFFFFFFu;
    return 1;
}
