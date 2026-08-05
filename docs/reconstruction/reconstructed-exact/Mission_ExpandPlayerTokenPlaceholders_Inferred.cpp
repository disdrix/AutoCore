// =============================================================================
// Mission_ExpandPlayerTokenPlaceholders_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005465c0
// Address:   0x005465c0  (autoassault.exe, image base 0x400000)
// System:    missions-progression / mission dialog string prep
// Dual:      WQ7R-D 2026-08-04
// Exactness: Behavior-preserving rewrite of decompiler + image bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   Expand fixed player-token placeholders inside a mutable std::string used by
//   mission dialog/UI text:
//     [$name] [$class] [$race] [$credits] [$level]
//   Each token is find/replace-all until npos. Sources: character vtbl getters,
//   race/class helpers, and 64-bit credits delta at char+0x720 − char+0x728.
//
// ABI: cdecl (Character*, std::string*) — caller ADD ESP,8.

#include <cstdint>
#include <cstdio>
#include <string>

// Race / class string getters — dual-owned WQ7R-F.
extern "C" const char* FUN_00521800(void* character /*ECX*/);
extern "C" const char* FUN_00521900(void* character /*ECX*/);

// Minimal stand-in for the character host used by this unit only.
struct CharacterHost {
  uint8_t _unk0[4];
  // +0x04: pointer into MSVC MI adjustor chain for vcalls
  uint8_t* mi_base; // +0x04
  uint8_t _unk8[0x720 - 0x8];
  uint32_t credits_lo;      // +0x720
  uint32_t credits_hi;      // +0x724
  uint32_t credits_sub_lo;  // +0x728
  uint32_t credits_sub_hi;  // +0x72c
};

static const char* VcallName(CharacterHost* ch)
{
  // Image: this2 = ch + *(*(ch+4)+4) + 4; (*vtbl[0x160/4])(this2)
  auto* base_info = *reinterpret_cast<uint8_t**>(reinterpret_cast<uint8_t*>(ch) + 4);
  auto adj = *reinterpret_cast<int32_t*>(base_info + 4);
  auto* this2 = reinterpret_cast<uint8_t*>(ch) + adj + 4;
  auto** vtbl = *reinterpret_cast<void***>(this2);
  using Fn = const char*(__thiscall*)(void*);
  return reinterpret_cast<Fn>(vtbl[0x160 / 4])(this2);
}

static int VcallLevel(CharacterHost* ch)
{
  auto* base_info = *reinterpret_cast<uint8_t**>(reinterpret_cast<uint8_t*>(ch) + 4);
  auto adj = *reinterpret_cast<int32_t*>(base_info + 4);
  auto* this2 = reinterpret_cast<uint8_t*>(ch) + adj + 4;
  auto** vtbl = *reinterpret_cast<void***>(this2);
  using Fn = int(__thiscall*)(void*);
  return reinterpret_cast<Fn>(vtbl[0x27c / 4])(this2);
}

static void ReplaceAll(std::string* text, const char* needle, size_t needle_len,
                       const char* replacement)
{
  for (;;) {
    const auto pos = text->find(needle, 0);
    if (pos == std::string::npos)
      break;
    text->replace(pos, needle_len, replacement);
  }
}

// cdecl — two stack arguments.
extern "C" void Mission_ExpandPlayerTokenPlaceholders_Inferred(
    CharacterHost* character,
    std::string* text)
{
  char buf[64];

  ReplaceAll(text, "[$name]", 7, VcallName(character));
  ReplaceAll(text, "[$class]", 8, FUN_00521900(character));
  ReplaceAll(text, "[$race]", 7, FUN_00521800(character));

  // 64-bit subtract with borrow (image SBB path).
  const uint32_t lo = character->credits_lo - character->credits_sub_lo;
  const uint32_t hi =
      character->credits_hi - character->credits_sub_hi -
      (character->credits_lo < character->credits_sub_lo ? 1u : 0u);
  const int64_t credits =
      (static_cast<int64_t>(static_cast<int32_t>(hi)) << 32) |
      static_cast<uint32_t>(lo);
  std::sprintf(buf, "%I64d", credits);
  ReplaceAll(text, "[$credits]", 10, buf);

  std::sprintf(buf, "%i", VcallLevel(character));
  ReplaceAll(text, "[$level]", 8, buf);
}
