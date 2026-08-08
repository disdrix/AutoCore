// =============================================================================
// Object_Store16At90_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00404c30
// Address:   0x00404c30  (autoassault.exe, image base 0x400000)
// System:    skills-abilities (partition owner); generic object field store
// Ghidra:    FUN_00404c30
// Dual:      2026-08-05 R10-022 OWN-ONLY
//
// Purpose: Store a caller-provided 16-byte (4× dword) blob into this+0x90..0x9c.
//          Leaf setter. Twin Object_Store16At80_Inferred (00404c60) stores the
//          previous 16 bytes at +0x80..0x8c. Product field English residual.
//
// ABI:     __thiscall
//          ECX = object* (destination; multi-inh bases at some call sites)
//          stack: const uint32_t src[4]*  (16-byte source)
//          ret 4
//          void (EAX not semantic)
//
// Exactness: Behavior-preserving rewrite of decompiler CF + live disassembly /
//            read_memory. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime / differential: OPEN.
// =============================================================================

#include <cstdint>

// Stores 16 bytes at this+0x90. Keep distinct from twin store @ +0x80 (00404c60)
// and from TFID *out-copy* helpers (0040aff0 / 0061b960) which read from this.
void __thiscall Object_Store16At90_Inferred(void *thisObj, const std::uint32_t *src16)
{
  auto *dst = reinterpret_cast<std::uint32_t *>(
      reinterpret_cast<char *>(thisObj) + 0x90);
  dst[0] = src16[0];
  dst[1] = src16[1];
  dst[2] = src16[2];
  dst[3] = src16[3];
}
