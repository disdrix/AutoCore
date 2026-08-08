// =============================================================================
// CVOGObjective_ProbeEligibilityCode_Inferred  (FUN_0059db80)
// -----------------------------------------------------------------------------
// Stable ID: aa_0059db80
// Address:   0x0059db80  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-08-05 MEGA-091 dual seal (live decompile ≡ raw)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED (no Launcher / runtime this wave).
// Prior scaffold: Named_CalleeOf_Named_VOG_DEBUG_STOP_0059db80 (retired)
// =============================================================================
//
// PURPOSE:
//   Nested eligibility / tracker-category probe on an objective instance.
//   Returns default code from objective+0x120 (fallback def+0xfc), or an
//   evaluator vtbl+0x58 override when pending state exists and that evaluator's
//   progress eval (vtbl+0x8) is false with a non-zero / non--1 code.
//
//   Parent gate FUN_0059dc50 treats return == -1 as ineligible.
//   Tracker UI callers match return against widget+0x110 as category id.
//
// ABI: thiscall ECX=objective*; stack character*; RET 4; int in EAX.
// Direct callees: none (indirect evaluator vcalls only).
// =============================================================================

#include <cstdint>

// Pending CNDHash shape (character+0x55c): mask@+0x8, buckets@+0x10,
// chain node key@+0x10, next@+0xc, value@+0x8 — same family as CNDHash_LookupByKey.

int __thiscall CVOGObjective_ProbeEligibilityCode_Inferred(
    int objective /* ECX */,
    int character /* stack */)
{
    int *eval;
    char ready;
    int overrideCode;
    int defaultCode;
    int pendingValue;
    std::uint32_t *it;

    defaultCode = *reinterpret_cast<int *>(objective + 0x120);
    if (defaultCode == -1) {
        defaultCode = *reinterpret_cast<int *>(
            *reinterpret_cast<int *>(objective + 0x14c) + 0xfc);
    }

    // Inline pending-hash lookup by objective id (objective+0x10).
    pendingValue = *reinterpret_cast<int *>(
        *reinterpret_cast<int *>(
            *reinterpret_cast<int *>(
                *reinterpret_cast<int *>(character + 0x55c) + 0x10) +
            ((*reinterpret_cast<std::uint32_t *>(
                  *reinterpret_cast<int *>(character + 0x55c) + 8) &
              *reinterpret_cast<std::uint32_t *>(objective + 0x10)) *
             4) +
        4);

    if (pendingValue == 0) {
        // no chain head
    } else {
        do {
            if (*reinterpret_cast<std::uint32_t *>(objective + 0x10) ==
                *reinterpret_cast<std::uint32_t *>(pendingValue + 0x10)) {
                if (pendingValue == 0) {
                    pendingValue = 0;
                    goto after_lookup;
                }
                pendingValue = *reinterpret_cast<int *>(pendingValue + 8);
                goto after_lookup;
            }
            pendingValue = *reinterpret_cast<int *>(pendingValue + 0xc);
        } while (pendingValue != 0);
        pendingValue = 0;
    }
after_lookup:
    if (pendingValue == 0) {
        return defaultCode;
    }

    it = *reinterpret_cast<std::uint32_t **>(objective + 0x158);
    if (it != *reinterpret_cast<std::uint32_t **>(objective + 0x15c)) {
        while (true) {
            eval = reinterpret_cast<int *>(*it);
            // vtbl+0x8(character, pendingValue) — progress-aware eval
            ready = (**(char (**)(int, int))(*eval + 8))(character, pendingValue);
            if (((ready == '\0') &&
                 (overrideCode = (**(int (**)())(*eval + 0x58))(),
                  overrideCode != -1)) &&
                (overrideCode != 0)) {
                break;
            }
            it = it + 1;
            if (it == *reinterpret_cast<std::uint32_t **>(objective + 0x15c)) {
                return defaultCode;
            }
        }
        return overrideCode;
    }
    return defaultCode;
}
