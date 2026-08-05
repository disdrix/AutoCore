// =============================================================================
// Combat_RollCritMultiplier_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004cf080
// Address:   0x004cf080 – 0x004cf0f4  (autoassault.exe, image base 0x400000)
// System:    combat-crit
// Twin:      reconstructed-exact/FUN_004cf080.cpp
// Callers:   Weapon_ApplyDamageToTargets_Inferred @ 0x0056e000
//            Skill_ApplyMultiTargetHits_Inferred @ 0x0058c850
// Callee:    FUN_004cef70 @ 0x004cef70 (crit chance)
// Generated: 2026-07-29 W21-I dual seal
// Exactness: Behavior-preserving rewrite of decompiler CF + stack ABI from bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   Roll crit damage multiplier from attacker level + chance helper + roll%100.
//   Crit: level * 0.01 + ~1.2; miss/null attacker: 1.0.

#include <cstdint>

// FPU return (float10 / ST0) modeled as float for readability.
extern float FUN_004cef70(void *attacker, void *target);

// Globals (image VAs)
// DAT_00aaa7ac @ 0x00aaa7ac = 100.0f
// _DAT_009cc1c8 @ 0x009cc1c8 = 0.01 (double)
// _DAT_009cc1c0 @ 0x009cc1c0 ≈ 1.2000000476837158 (double)
// g_flOne @ 0x00a0f2a0 = 1.0f

static const float kPercentScale = 100.0f;
static const double kCritLevelScale = 0.01;
static const double kCritBaseMult = 1.2000000476837158;
static const float kNoCrit = 1.0f;

float Combat_RollCritMultiplier_Inferred(void *attacker,
                                         void *target,
                                         uint16_t roll)
{
    if (attacker == nullptr) {
        return kNoCrit;
    }

    // vtbl+0x27c — int level (GetLevel-like; FILD in body)
    int *vtbl = *reinterpret_cast<int **>(attacker);
    using GetLevelFn = int(__thiscall *)(void *);
    int level = reinterpret_cast<GetLevelFn>(vtbl[0x27c / 4])(attacker);

    float chance = FUN_004cef70(attacker, target);

    // (roll % 100) <= chance * 100.0  →  crit hit
    if (static_cast<float>(static_cast<unsigned>(roll) % 100)
        <= chance * kPercentScale) {
        return static_cast<float>(static_cast<double>(level) * kCritLevelScale
                                  + kCritBaseMult);
    }
    return kNoCrit;
}
