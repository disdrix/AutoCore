// Twin of Mission_ExpandPlayerTokenPlaceholders_Inferred.cpp
// Stable ID: aa_005465c0  VA: 0x005465c0
// See named clean for full plate + token table.

#include <cstdint>
#include <cstdio>
#include <string>

extern "C" const char* FUN_00521800(void* character /*ECX*/);
extern "C" const char* FUN_00521900(void* character /*ECX*/);

struct CharacterHost {
  uint8_t _unk0[4];
  uint8_t* mi_base;
  uint8_t _unk8[0x720 - 0x8];
  uint32_t credits_lo;
  uint32_t credits_hi;
  uint32_t credits_sub_lo;
  uint32_t credits_sub_hi;
};

static const char* VcallName(CharacterHost* ch)
{
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

extern "C" void FUN_005465c0(CharacterHost* character, std::string* text)
{
  char buf[64];

  ReplaceAll(text, "[$name]", 7, VcallName(character));
  ReplaceAll(text, "[$class]", 8, FUN_00521900(character));
  ReplaceAll(text, "[$race]", 7, FUN_00521800(character));

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
