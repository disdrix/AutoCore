// =============================================================================
// FUN_005360f0 — Ghidra-name twin of CVOGCharacter_TickUseObjectPending_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005360f0
// Address:   0x005360f0–0x00536143 (84 B)
// Prefer:    CVOGCharacter_TickUseObjectPending_Inferred.cpp for named clean
// Dual A/B:  SEALED accept W26-S 2026-07-29
// =============================================================================

#include <cstdint>

struct Character;

bool __thiscall CVOGCharacter_ResolveUseObjectPending_Inferred(Character *self, char commit);

std::uint8_t /*bool AL*/ __thiscall FUN_005360f0(Character *self /*ECX*/, float dt)
{
    auto *self_b = reinterpret_cast<std::uint8_t *>(self);

    auto *p4 = *reinterpret_cast<std::uint8_t **>(self_b + 4);
    auto *p44 = *reinterpret_cast<std::uint8_t **>(p4 + 4);
    auto *vbase_obj = *reinterpret_cast<std::uint8_t **>(
        p44 + reinterpret_cast<std::uintptr_t>(self) + 0xa8);

    if (vbase_obj[0x7e] == 0) {
        return 0;
    }
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
        CVOGCharacter_ResolveUseObjectPending_Inferred(self, /*commit=*/1);
    }
    return 1;
}
