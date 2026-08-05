// =============================================================================
// CVOGCharacter_TickUseObjectPending_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Advance the character's pending use-object countdown timer by
//           frame dt. When the timer expires (<= 0), commit-resolve via
//           CVOGCharacter_ResolveUseObjectPending_Inferred(commit=1).
//
// Address:  0x005360f0  (autoassault.exe, image base 0x400000)
// End:      0x00536144 exclusive (84 / 0x54 bytes)
// Stable:   aa_005360f0
// Ghidra:   FUN_005360f0
// Machine:  8B 41 04 ... B0 01 C2 04 00 / 32 C0 C2 04 00
//
// Convention: MSVC __thiscall; 1 stack formal (float dt); RET 4
//   ECX = Character* (pending slots +0xc7c / +0xc80; vbase via +0xa8)
//   [esp+4] = float dt (caller: DAT_00d09874+0x30 frame delta)
// Returns:  AL bool — 1 if gate passed and timer advanced; 0 if inactive
//
// Caller:   FUN_00930040 @ 0x009300c3 (client per-frame path)
// Callee:   CVOGCharacter_ResolveUseObjectPending_Inferred (0x00535ed0) commit=1
//
// Exactness: CF from live decompile 2026-07-29 ≡ raw 2026-07-23.
// Bit-for-bit / runtime / differential: OPEN.
// Dual A/B (static): SEALED accept 2026-07-29 (W26-S).
// =============================================================================

#include <cstdint>

struct Character;

// Nested (dual-sealed W25-A; declared only)
bool __thiscall CVOGCharacter_ResolveUseObjectPending_Inferred(Character *self, char commit);

/// Tick pending use-object countdown; commit-resolve when timer expires.
/// @return true if countdown was active and advanced; false if gated off.
std::uint8_t /*bool AL*/ __thiscall CVOGCharacter_TickUseObjectPending_Inferred(
    Character *self,
    float dt)
{
    auto *self_b = reinterpret_cast<std::uint8_t *>(self);

    // VBase presence (MSVC this-adjust chain +0xa8 → object flag +0x7e)
    auto *vptr_chain = *reinterpret_cast<std::uint8_t **>(self_b + 4);
    auto *vbase = *reinterpret_cast<std::uint8_t **>(
        reinterpret_cast<std::uint8_t *>(vptr_chain) + 4);
    // *( *( *(this+4)+4 ) + this + 0xa8 )
    auto *adj = *reinterpret_cast<std::uint8_t **>(
        vbase + reinterpret_cast<std::uintptr_t>(self) + 0xa8);
    if (adj[0x7e] == 0) {
        return 0;
    }

    // Pending-active flag
    if (self_b[0xc7c] == 0) {
        return 0;
    }

    float *timer = reinterpret_cast<float *>(self_b + 0xc80);
    if (!(*timer > 0.0f)) {
        return 0;
    }

    float remaining = *timer - dt;
    *timer = remaining;
    if (remaining <= 0.0f) {
        CVOGCharacter_ResolveUseObjectPending_Inferred(self, 1);
    }
    return 1;
}

// Ghidra twin entry (same body)
std::uint8_t /*bool AL*/ __thiscall FUN_005360f0(Character *self, float dt)
{
    return CVOGCharacter_TickUseObjectPending_Inferred(self, dt);
}
