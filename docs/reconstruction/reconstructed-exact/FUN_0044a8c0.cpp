// =============================================================================
// FUN_0044a8c0  (scaffold twin of Map_TreeInsertAndRebalance_Val12_EsiBuy_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0044a8c0
// Address:   0x0044a8c0  (autoassault.exe, image base 0x400000)
// System:    std map/set tree insert + RB rebalance (Val12, ESI buy)
// Generated: 2026-07-29 W27-P (updates 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
// Named clean: Map_TreeInsertAndRebalance_Val12_EsiBuy_Inferred.cpp
// ABI: map in EDI; stack (outIt*, addLeft, where*, value*); ret 0x10
// Body: 0x0044a8c0–0x0044aa46 exclusive (390 B)
// String: "map/set<T> too long" @ 0x00a1530c; max size 0x15555553
// Buynode: FUN_0046c6c0 (ESI=value*, new 0x1c); rotates: 00573170 / 00418c10

#include <cstdint>

extern "C" int* FUN_0046c6c0(uint32_t head_a, uint32_t* where, uint32_t head_b, uint8_t color);
extern "C" void __thiscall FUN_00573170(void* map, void* node);
extern "C" void __thiscall FUN_00418c10(void* map, void* node);
extern "C" void FUN_00401a40(void* basic_string);
extern "C" void __stdcall _CxxThrowException(void* obj, void* throwInfo);

// Decompiler shape with sealed annotations. Map = EDI (not a C parameter).
// value* is the 4th stack argument (omitted by Ghidra named params).
extern "C" void FUN_0044a8c0(uint32_t* param_1 /*outIt*/, char param_2 /*addLeft*/, uint32_t* param_3 /*where*/)
{
  // Live CF matches raw 2026-07-23 + W27-P append.
  // Portable reconstruction with explicit map*: see
  // Map_TreeInsertAndRebalance_Val12_EsiBuy_Inferred.cpp
  (void)param_1;
  (void)param_2;
  (void)param_3;
  // Structural contract:
  // if (map->size > 0x15555553) throw length_error("map/set<T> too long");
  // n = FUN_0046c6c0(head, where, head, 0) with ESI=value*; map->size++;
  // link empty|left|right + leftmost/rightmost; RB fixup; root black; *outIt=n; ret 0x10
}
