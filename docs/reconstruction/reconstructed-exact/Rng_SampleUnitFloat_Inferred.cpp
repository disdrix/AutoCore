// =============================================================================
// Rng_SampleUnitFloat_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_007a4170
// Address:   0x007a4170 – 0x007a41d4 exclusive (0x64 B)
// Module:    autoassault.exe (image base 0x400000)
// System:    skills-abilities / global RNG unit table
// Generated: 2026-08-04 WQ9D-F dual (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Not modernization. Not bit-exact certified.
// =============================================================================
//
// PURPOSE:
//   Sample one unit float from the global RNG ushort table:
//     - index < 0 (signed): sequential read at cursor, wrap if cursor > 0xFFFFF,
//       cursor++, return u16 * DAT_00aaa638
//     - index >= 0: indexed read with mask 0x800FFFFF + signed power-of-two
//       wrap; no cursor advance; same scale
//
//   Sibling: Rng_CopyUnitTableWindow_Inferred (0x0051b720) bulk window copy.
//   Sibling: Rng_CloneSeededTable_Inferred (0x0058ab60) heap + force seed.
//   Getter:  CVOGReaction_RandomUnitScalar (0x007a4330) → &DAT_00d20c1c.
//
// ABI: __thiscall; ECX=RngHost*; stack uint index; RET 4; float in ST0.
//
// Dual: reviews/A|B_aa_007a4170_Rng_SampleUnitFloat_Inferred.md
// =============================================================================

#include <cstdint>

// DAT_00aaa638 @ 0x00aaa638 — bytes 80 00 80 37 → float 0x37800080 ≈ 1/65535
extern float DAT_00aaa638;

struct RngHost_Inferred {
  void* vtbl;                 // +0x00
  std::uint8_t ready;         // +0x04
  std::uint8_t pad[3];
  std::uint8_t* tableBase;    // +0x08  // 0x200000 bytes / 0x100000 ushorts
  int cursor;                 // +0x0C  // ushort index
};

// __thiscall — retail returns via x87 ST0
extern "C" float __thiscall Rng_SampleUnitFloat_Inferred(
    RngHost_Inferred* self,
    std::uint32_t index)
{
  if (static_cast<std::int32_t>(index) < 0) {
    if (0xfffff < self->cursor) {
      self->cursor = 0;
    }
    auto* table = reinterpret_cast<std::uint16_t*>(self->tableBase);
    std::uint16_t w = table[self->cursor];
    self->cursor = self->cursor + 1;
    return static_cast<float>(w) * DAT_00aaa638;
  }

  index &= 0x800fffffu;
  if (static_cast<std::int32_t>(index) < 0) {
    index = (index - 1u | 0xfff00000u) + 1u;
  }
  auto* table = reinterpret_cast<std::uint16_t*>(self->tableBase);
  std::uint16_t w = table[index];
  return static_cast<float>(w) * DAT_00aaa638;
}

// Scaffold alias
extern "C" float __thiscall FUN_007a4170(
    RngHost_Inferred* self,
    std::uint32_t index)
{
  return Rng_SampleUnitFloat_Inferred(self, index);
}
