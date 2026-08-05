// =============================================================================
// TFID_EqualsObjectId
// -----------------------------------------------------------------------------
// Stable ID: aa_00404aa0
// Address:   0x00404aa0–0x00404ac6  (autoassault.exe, image base 0x400000)
// System:    identity / TFID (cross-cutting)
// Generated: 2026-07-29 dual A/B seal (from raw + read_memory bytes)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Dual:      accept (A+B 2026-07-29)
// =============================================================================

/*
 * Behavioral notes:
 * - Leaf equality of ObjectId / TFID head fields only.
 * - Compares int32@+0, int32@+4, int8@+8. Does NOT compare +9..+15.
 * - __cdecl; return 1 equal, 0 unequal.
 * - No null checks (retail faults on null).
 * - Inverse: TFID_NotEquals @ 0x0040b150 (same fields, flipped return).
 * - Common invalid sentinel: g_abTfidInvalid_A15870 @ 0x00a15870 = {-1,-1,0,...}.
 *
 * Field names below are repo-inferred (TFID_16); widths match sealed body.
 */

#include <cstdint>

// Layout used by many callers (obj+0x160 class / packet TFID_16). Equality
// only needs the first 9 bytes of addressable fields.
struct TFID_ObjectIdHead {
    std::int32_t  dwCoidLo;  // +0
    std::int32_t  dwCoidHi;  // +4
    std::uint8_t  bGlobal;   // +8  (compared as 8-bit)
    // +9..+15 pad — not compared by this function
};

extern "C" int __cdecl TFID_EqualsObjectId(void *pA, void *pB)
{
    // Match Ghidra raw: successive short-circuit compares.
    if (*(int *)pA == *(int *)pB &&
        *(int *)((int)pA + 4) == *(int *)((int)pB + 4) &&
        *(char *)((int)pA + 8) == *(char *)((int)pB + 8)) {
        return 1;
    }
    return 0;
}
