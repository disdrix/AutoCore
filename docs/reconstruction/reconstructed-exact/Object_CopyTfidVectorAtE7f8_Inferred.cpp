// =============================================================================
// Object_CopyTfidVectorAtE7f8_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004e5810
// Address:   0x004e5810–0x004e5833 exclusive (35 B / 0x23, autoassault.exe base 0x400000)
// System:    inventory-transfer — object TFID vector @ +0xe7f8 materialize
// Wave:      R13-026 OWN-ONLY dual 2026-08-05
// Generated: 2026-08-05 R13-026 dual A/B (decompile + disasm + read_memory + callers)
// Exactness: Behavior-preserving rewrite of decompiler CF + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_004e5810
// Terminal:  false (no Runtime Confirmed)
// =============================================================================
//
// PURPOSE:
//   Thin thiscall wrapper: copy-construct the caller's local std::vector shell
//   from the host object's member vector at +0xe7f8 (8-byte TFID pair elements).
//   Returns the out shell pointer. Used by craft station proximity and station
//   subtype walkers to materialize a temporary TFID list.
//
// ABI:
//   __thiscall; ECX=Object*; stack VectorU64Shell* out; ret 4; returns out* in EAX.
//   Entry: 51 56 8B 74 24 0C 81 C1 F8 E7 00 00 …
//   Exit:  8B C6 5E 59 C2 04 00
//
// RELATED (not dualed here):
//   FUN_004e53e0  — vector copy-construct worker (elem 8 B)
//   FUN_0052eb90  — Character_Craft_HasMatchingStationInRange_Inferred (parent dual)
//   FUN_004dd940  — station subtype TFID walk sibling consumer
// =============================================================================

#include <cstdint>

// MSVC-style vector shell for 8-byte elements (TFID hi/lo pairs).
// Layout used by callers: +0 unused/cookie, +4 begin, +8 end, +0xc capacity_end.
struct VectorU64Shell {
  std::uint32_t _unused0;
  std::uint8_t *begin;       // +0x4
  std::uint8_t *end;         // +0x8
  std::uint8_t *capacity;    // +0xc
};

// Copy-construct dest (this) from src vector of 8-byte elements.
// Body dual open (R13 residual); sealed by decompile of 0x004e53e0.
extern "C" VectorU64Shell *__thiscall FUN_004e53e0(VectorU64Shell *dest,
                                                   const void *src_vector);

// Machine: VectorU64Shell* __thiscall FUN_004e5810(Object* this, VectorU64Shell* out)
extern "C" VectorU64Shell *__thiscall Object_CopyTfidVectorAtE7f8_Inferred(
    void *self, VectorU64Shell *out)
{
  // ADD ECX, 0xe7f8 → source = self + 0xe7f8
  const void *src = reinterpret_cast<const std::uint8_t *>(self) + 0xe7f8;

  // thiscall: ECX = out; stack = src
  FUN_004e53e0(out, src);

  return out;
}

// Ghidra symbol alias
extern "C" VectorU64Shell *__thiscall FUN_004e5810(void *self, VectorU64Shell *out)
{
  return Object_CopyTfidVectorAtE7f8_Inferred(self, out);
}
