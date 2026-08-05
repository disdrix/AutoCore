// =============================================================================
// FUN_00573810 / StdMap_InsertOrFind_Val12_UintKey
// -----------------------------------------------------------------------------
// Stable ID: aa_00573810
// Address:   0x00573810  (autoassault.exe, image base 0x400000)
// Body:      0x00573810 – 0x005738c8 exclusive (184 B / 0xB8)
// System:    std map unique insert-or-find (Val12 / uint key)
// Generated: 2026-07-29 W28-T dual seal (refined from 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow + byte ABI.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Val12 insert-or-find by uint key; out pair {it, inserted}; ret 8.
// Full named plate: StdMap_InsertOrFind_Val12_UintKey.cpp

#include <cstdint>

// Forward to named reconstruction (behavior ≡ raw).
struct MapShell_Val12;
struct InsertPair;

extern "C" void __thiscall StdMap_InsertOrFind_Val12_UintKey(
    MapShell_Val12* map,
    InsertPair* out,
    const uint32_t* value);

extern "C" void __thiscall FUN_00573810(
    MapShell_Val12* map,
    InsertPair* out,
    const uint32_t* value)
{
    StdMap_InsertOrFind_Val12_UintKey(map, out, value);
}

/*
 * Raw-faithful control flow (decompiler form):
 *
 *   head = *(this+4); addLeft = true;
 *   if root not nil: walk by (*value < node[3]); left/right; isnil@+0x19
 *   if addLeft:
 *     if parent == leftmost: InsertAndRebalance(...,1,...) → out{it,1}; ret
 *     else Predecessor(&parent)
 *   if parent.key < *value: InsertAndRebalance(...,addLeft,...) → out{it,1}; ret
 *   else: out{parent,0}; ret
 *   RET 8 all exits
 *
 * Callees: FUN_00573510, FUN_005ae050
 */
