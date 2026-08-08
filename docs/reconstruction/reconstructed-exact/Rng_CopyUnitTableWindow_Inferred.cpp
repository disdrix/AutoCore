// =============================================================================
// Rng_CopyUnitTableWindow_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0051b720
// Address:   0x0051b720  (autoassault.exe, image base 0x400000)
// System:    skills-abilities (global RNG unit-table window copy)
// Generated: 2026-08-04 WQ9R-A dual (live Ghidra decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (no Launcher / not run).
// =============================================================================
//
// PURPOSE:
//   Copy nWords ushorts from the global MT-backed RNG word table
//   (host+0x08 base, host+0x0C cursor) into a caller buffer, then advance
//   cursor by 1. Wrap cursor to 0 when cursor+nWords > 0xFFFFF.
//   Returns the pre-increment cursor (used as lDiceSeed / packet+0x3C under
//   world sim flag +0x7e in Skill_ApplyStatusEffectLocal).
//
//   Sibling: Rng_CloneSeededTable_Inferred (0x0058ab60) — alloc 0x4B0 + force
//   seed + fixed-600 inline copy of the same window algorithm.
//   Single-word unit float: FUN_007a4170 (u16 * DAT_00aaa638 = 1/65536).
//
// ABI: __thiscall; ECX=RngHost*; stack nWords, dst*; RET 8; EAX=old cursor.
// Body: 0x0051b720–0x0051b768 exclusive (72 B); leaf (rep movs only).
//
// Dual: reviews/A|B_aa_0051b720_Rng_CopyUnitTableWindow_Inferred.md

#include <cstdint>
#include <cstring>

// RNG host layout (static sealed — shared with Rng_CloneSeededTable / FUN_007a4170):
//   +0x00 vtbl
//   +0x04 ready flag (byte)
//   +0x08 table base (uint8_t*, size 0x200000 after init)
//   +0x0C cursor (int, ushort index)
//   +0x10 rebuild seed
//   +0x14 MT state object*
struct RngHost_Inferred {
  void* vtbl;
  std::uint8_t ready;
  std::uint8_t pad[3];
  std::uint8_t* tableBase;  // +0x08
  int cursor;               // +0x0C
};

// __thiscall
extern "C" std::uint32_t __thiscall Rng_CopyUnitTableWindow_Inferred(
    RngHost_Inferred* self,
    int nWords,
    void* dst)
{
  if (0xfffff < self->cursor + nWords) {
    self->cursor = 0;
  }

  // Source: ushort-index → byte offset (*2). Copy nWords*2 bytes.
  // Retail uses rep movsd for (nWords*2)>>2 dwords then rep movsb for remainder.
  auto* src = reinterpret_cast<std::uint32_t*>(self->tableBase + self->cursor * 2);
  auto* out = static_cast<std::uint32_t*>(dst);

  for (std::uint32_t n = static_cast<std::uint32_t>(nWords * 2) >> 2; n != 0; n = n - 1) {
    *out = *src;
    src = src + 1;
    out = out + 1;
  }
  for (std::uint32_t n = static_cast<std::uint32_t>(nWords * 2) & 3u; n != 0; n = n - 1) {
    *reinterpret_cast<std::uint8_t*>(out) = *reinterpret_cast<std::uint8_t*>(src);
    src = reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::uint8_t*>(src) + 1);
    out = reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::uint8_t*>(out) + 1);
  }

  std::uint32_t oldCursor = static_cast<std::uint32_t>(self->cursor);
  self->cursor = self->cursor + 1;
  return oldCursor;
}

// Legacy symbol alias for existing reconstructed-exact call sites.
extern "C" std::uint32_t __thiscall FUN_0051b720(
    RngHost_Inferred* self,
    int nWords,
    void* dst)
{
  return Rng_CopyUnitTableWindow_Inferred(self, nWords, dst);
}
