// =============================================================================
// FUN_004e48b0 — scaffold twin of StdMap_InsertOrFind_PairKey_Isnil21_Via4e37e0_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004e48b0
// Address:   0x004e48b0  (autoassault.exe, image base 0x400000)
// Body:      0x004e48b0–0x004e4983 exclusive (211 B / 0xD3)
// System:    skills-abilities
// Agent:     R13-005 OWN-ONLY dual 2026-08-05
// Exactness: Thin alias; prefer named clean for semantics.
// Terminal:  false
// =============================================================================

#include <cstdint>

// Forward to named reconstruction (same CU / link as peer twins).
struct MapShell_Isnil21_Pair;
struct InsertPair_Isnil21;
struct Val_PairKey_Isnil21;

void __thiscall StdMap_InsertOrFind_PairKey_Isnil21_Via4e37e0_Inferred(
    MapShell_Isnil21_Pair *map,
    InsertPair_Isnil21 *out,
    const Val_PairKey_Isnil21 *value);

extern "C" void __thiscall FUN_004e48b0(
    MapShell_Isnil21_Pair *map,
    InsertPair_Isnil21 *out,
    const Val_PairKey_Isnil21 *value)
{
  StdMap_InsertOrFind_PairKey_Isnil21_Via4e37e0_Inferred(map, out, value);
}
