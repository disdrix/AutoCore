// =============================================================================
// FUN_0043fe60  (alias plate → StdList_Incsize)
// -----------------------------------------------------------------------------
// Stable ID: aa_0043fe60
// Address:   0x0043fe60–0x0043fece  (autoassault.exe, image base 0x400000)
// System:    shared MSVC std::list
// Generated: 2026-07-23 scaffold; **redirected 2026-07-29** W23-E to named clean
// Exactness: Behavior-preserving. Prefer StdList_Incsize.cpp as canonical plate.
// Dual:      accept (A+B 2026-07-29)
// =============================================================================

// Canonical implementation:
//   docs/reconstruction/reconstructed-exact/StdList_Incsize.cpp
//
// This twin keeps the Ghidra symbol for tooling that keys on FUN_*.

#include <cstdint>

struct StdListHeader {
  void *_Myhead_or_pad;
  void *_Myhead;
  std::uint32_t _Mysize;
};

extern "C" void __fastcall StdList_Incsize(std::uint32_t count, StdListHeader *list);

extern "C" void __fastcall FUN_0043fe60(std::uint32_t param_1, int param_2)
{
  StdList_Incsize(param_1, reinterpret_cast<StdListHeader *>(param_2));
}

/*
 * Authoritative control flow (live ≡ raw 2026-07-29):
 *
 * void __fastcall FUN_0043fe60(uint param_1, int param_2)
 * {
 *   // SEH ...
 *   if (0x3fffffffU - *(int *)(param_2 + 8) < param_1) {
 *     basic_string(..., "list<T> too long");
 *     FUN_00401a40(...);
 *     _CxxThrowException(..., &DAT_00acc388); // noreturn
 *   }
 *   *(uint *)(param_2 + 8) = *(int *)(param_2 + 8) + param_1;
 * }
 */
