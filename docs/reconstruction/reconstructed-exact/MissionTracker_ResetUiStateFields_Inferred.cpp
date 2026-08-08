// =============================================================================
// MissionTracker_ResetUiStateFields_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00929c00
// Address:   0x00929c00–0x00929c50 inclusive (81 B / 0x51)
// Module:    autoassault.exe (image base 0x400000)
// Ghidra:    FUN_00929c00
// System:    missions-progression / mission-tracker UI state
// Sealed:    2026-08-05 MEGA-087 OWN dual (decompile + analyze + disasm + read_memory)
// Exactness: Behavior-preserving rewrite of image control flow. Not modernization.
// Bit-for-bit / runtime / diff: DEFERRED.
// =============================================================================
//
// PURPOSE
//   Reset mission-tracker derived UI/state fields to defaults: clear id/waypoint
//   slots to -1, zero flag dwords/bytes, restore default range float 25.0f from
//   DAT_00aaa6fc. Always returns success (1). Leaf; no callees.
//
// ABI (image-sealed — custom EAX object, not thiscall)
//   EAX = MissionTracker* (client+0x4d0 family; call sites MOV EAX,EDI/ESI)
//   Stack: none
//   AL  = 1
//   RET bare (C3)
//
// CALLERS
//   FUN_0092a590 @ 0x0092a5a8 / 0x0092a5ef  (set-active clear/miss paths)
//   FUN_0092c080 @ 0x0092c47f               (region/sector id change)
//   Upstream: Client_TryBindActiveMissionTracker 0x0092fd00 → FUN_0092a590
//
// SUPERSEDES scaffold name:
//   Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_MissionDial_00929c00
// =============================================================================

#include <cstdint>

// DAT_00aaa6fc @ 0x00aaa6fc — IEEE 0x41c80000 = 25.0f
extern "C" float DAT_00aaa6fc;

// Layout notes are offset-only; product field names open (_Inferred).
struct MissionTracker {
    // ... earlier fields owned by other units ...
    // +0x18 and below written here only when called.
};

// Image: object in EAX (decompiler "in_EAX"), not ECX.
// Model as fastcall-style first-arg-in-EAX for readability of call sites.
std::uint8_t MissionTracker_ResetUiStateFields_Inferred(MissionTracker* tracker /*EAX*/)
{
    float default_range = DAT_00aaa6fc; // MOVSS XMM0,[DAT_00aaa6fc]

    auto* base = reinterpret_cast<std::uint8_t*>(tracker);

    *reinterpret_cast<std::uint32_t*>(base + 0x18)  = 0xFFFFFFFFu;
    *reinterpret_cast<std::uint32_t*>(base + 0x20)  = 0xFFFFFFFFu;
    *reinterpret_cast<std::uint32_t*>(base + 0x24)  = 0xFFFFFFFFu;
    *reinterpret_cast<std::uint32_t*>(base + 0x54)  = 0;
    *reinterpret_cast<std::uint32_t*>(base + 0x80)  = 0;
    *reinterpret_cast<std::uint32_t*>(base + 0xac)  = 0;
    *reinterpret_cast<std::uint32_t*>(base + 0x28)  = 0;
    *(base + 0x100) = 0;
    *(base + 0x101) = 0;
    *(base + 0x102) = 0;
    *reinterpret_cast<float*>(base + 0x104)         = default_range; // MOVSS store
    *reinterpret_cast<std::uint32_t*>(base + 0x108) = 0xFFFFFFFFu;
    *reinterpret_cast<std::uint32_t*>(base + 0x10c) = 0xFFFFFFFFu;

    return 1; // MOV AL,1 ; RET
}

// Ghidra symbol alias for call sites still naming FUN_00929c00.
std::uint8_t FUN_00929c00(MissionTracker* tracker /*EAX*/)
{
    return MissionTracker_ResetUiStateFields_Inferred(tracker);
}
