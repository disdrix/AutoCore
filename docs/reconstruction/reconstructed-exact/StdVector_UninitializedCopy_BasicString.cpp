// =============================================================================
// StdVector_UninitializedCopy_BasicString  (aa_00431430)
// -----------------------------------------------------------------------------
// Address:   0x00431430  (autoassault.exe, image base 0x400000)
// Body:      0x00431430 – 0x00431450 exclusive (32 B / 0x20)
// Wave:      W33-H OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite from decompile + full-body read_memory.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

struct BasicString_0x1c {
  uint8_t bytes[0x1c];
};

// Opaque vector host (this forwarded as 4th arg to core Ucopy).
struct VectorBasicString {
  void* _unused0;
  BasicString_0x1c* begin;   // +4
  BasicString_0x1c* end;     // +8
  BasicString_0x1c* cap_end; // +0xC
};

// Core range Ucopy (not owned): placement copy-ctor [first,last) → dest; returns dest end.
// Call site / this wrapper push 5 dwords; triad first/last/dest drives the loop.
extern "C" BasicString_0x1c* FUN_0046a2c0(
    BasicString_0x1c* first,
    BasicString_0x1c* last,
    BasicString_0x1c* dest,
    VectorBasicString* vec,
    BasicString_0x1c* dest_again);

// ECX = vector*; stack first, last, dest; RET 0x0C.
// Returns EAX = end of constructed dest range.
extern "C" BasicString_0x1c* __fastcall StdVector_UninitializedCopy_BasicString(
    VectorBasicString* vec,
    BasicString_0x1c* first,
    BasicString_0x1c* last,
    BasicString_0x1c* dest)
{
  // Retail: thiscall ECX=vec; three stack args cleaned by RET 0x0C.
  return FUN_0046a2c0(first, last, dest, vec, dest);
}

// Scaffold / Ghidra alias
extern "C" BasicString_0x1c* __fastcall FUN_00431430(
    VectorBasicString* vec,
    BasicString_0x1c* first,
    BasicString_0x1c* last,
    BasicString_0x1c* dest)
{
  return StdVector_UninitializedCopy_BasicString(vec, first, last, dest);
}
