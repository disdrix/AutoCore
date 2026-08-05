// =============================================================================
// BasicString_CopyBackward_Thunk_0x1c
// -----------------------------------------------------------------------------
// Stable ID: aa_00431480
// Address:   0x00431480  (autoassault.exe, image base 0x400000)
// Body:      0x00431480–0x0043149d exclusive (29 B)
// System:    MSVC basic_string<char> copy_backward trampoline
// Generated: 2026-07-29 W33-I dual seal
// Exactness: Behavior-preserving rewrite of decompiler + read_memory control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================

// PURPOSE: Thin trampoline from vector insert mid-path into free copy_backward
// (FUN_00431790): assign elements of [first, last) backward so the range ends
// at dest_end. Stride 0x1c. Overlap-safe reverse assign via string operator=.
//
// Call-site ABI (sealed): cdecl, 3 stack pointers, plain RET.
// Ghidra thiscall/4-param is body-shape only; sole caller does not set ECX.

#include <cstdint>

struct BasicString_0x1c {
  std::uint8_t raw[0x1C];
};

// Free helper @ 0x00431790 (not dual-owned this wave)
extern BasicString_0x1c* FUN_00431790(
    BasicString_0x1c* first,
    BasicString_0x1c* last,
    BasicString_0x1c* dest_end);

// cdecl call-site contract; plain RET; void (return of callee discarded)
void BasicString_CopyBackward_Thunk_0x1c(
    BasicString_0x1c* first,
    BasicString_0x1c* last,
    BasicString_0x1c* dest_end)
{
  FUN_00431790(first, last, dest_end);
}
