// =============================================================================
// operator_delete_array  (MSVC CRT: operator delete[])
// -----------------------------------------------------------------------------
// Stable ID: aa_0048981c
// Address:   0x0048981c–0x00489821 inclusive (6 B)  autoassault.exe base 0x400000
// System:    CRT universal (partition seed: inventory-transfer / parent 0x005725a0)
// Wave:      R10-010 OWN-ONLY dual (2026-08-05)
// Exactness: Behavior-preserving reconstruction of the IAT thunk only.
//            CRT implementation is external (import target); not dualed here.
// Bit-for-bit vs retail EXE thunk: sealed via read_memory (FF 25 98 66 9C 00).
// Runtime Confirmed: OPEN (terminal false).
// =============================================================================

/*
 * Role:
 *   Import thunk for MSVC `operator delete[](void*)`.
 *   Body is a single indirect jump through IAT slot 0x009c6698.
 *
 * Sibling (do not merge):
 *   operator_delete @ 0x00489822  → IAT [0x009c6694]  (scalar operator delete)
 *
 * Decompiler hazards:
 *   - "Could not recover jumptable" is false (single FF25).
 *   - Recursive self-call model is false (IAT tail-JMP).
 *   - Not noreturn: callers use cdecl CALL + ADD ESP,4 and continue.
 *
 * Ghidra symbols:
 *   function name: operator_delete[]
 *   decomp symbol: operator_delete__
 */

#include <cstddef>

// IAT slot for operator delete[] (image VA).
static void *const *const kIat_operator_delete_array =
    reinterpret_cast<void *const *>(0x009c6698);

extern "C" void __cdecl operator_delete_array(void *block)
{
  // Equivalent machine: JMP dword ptr [0x009c6698]
  using DeleteArrayFn = void(__cdecl *)(void *);
  DeleteArrayFn fn = reinterpret_cast<DeleteArrayFn>(*kIat_operator_delete_array);
  fn(block);
}

// Alias matching Ghidra decompiler encoding of operator delete[].
extern "C" void __cdecl operator_delete__(void *block)
{
  operator_delete_array(block);
}

// C++ spelling used by reconstructed callers (e.g. InventoryGrid_CompleteDtor).
void operator delete[](void *block) noexcept
{
  operator_delete_array(block);
}
