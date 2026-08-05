// =============================================================================
// FUN_00509940 — scaffold alias → GetModifierSkillID
// -----------------------------------------------------------------------------
// Stable ID: aa_00509940
// Address:   0x00509940  (autoassault.exe, image base 0x400000)
// Body:      0x00509940–0x00509a78 exclusive (312 B)
// System:    skills / modifier ID resolution
// Generated: 2026-07-29 W23-P OWN-ONLY (supersedes 2026-07-23 scaffold)
// Exactness: Behavior-preserving; fallthrough on table miss preserved.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
// Prefer: reconstructed-exact/GetModifierSkillID.cpp
// Named twin: Skill_GetModifierSkillID_passed_an_invalid_IDPrefix_i_00509940.cpp

#include <cstdint>

extern "C" void* Map_LowerBoundFindByIntKey(void* map, void* outIt, int32_t* key /*, ...*/);
extern "C" void FUN_007a4480(int level, const char* fmt, ...);
extern "C" void* __thiscall FUN_00508ac0(void* registry, int32_t id);
extern "C" void* __thiscall FUN_00508b10(void* registry, int32_t id);
extern "C" void* __thiscall FUN_00508b60(void* registry, int32_t id);
extern "C" void* __thiscall FUN_00508bb0(void* registry, int32_t id);
extern "C" void* __thiscall FUN_00508c00(void* registry, int32_t id);
extern "C" void* __thiscall FUN_00508c50(void* registry, int32_t id);
extern "C" uint8_t DAT_00b041dc[];
extern "C" void* DAT_00b041e0;

int32_t __thiscall FUN_00509940(void* registry /* ECX */, int32_t idPrefix /* [esp+4] */)
{
  uint8_t local_it[4];
  int32_t key = idPrefix;
  int32_t type;
  void* entry;

  void* it = Map_LowerBoundFindByIntKey(&DAT_00b041dc, local_it, &key);
  void* node = *reinterpret_cast<void**>(it);

  if (node == DAT_00b041e0) {
    if (idPrefix != 0) {
      FUN_007a4480(
          0,
          "CVOGLootGenerator::GetTypeFromIDPrefix() passed an invalid prefix (%d), "
          "couldn't find type in map",
          idPrefix);
    }
    type = 0;
  } else {
    type = *reinterpret_cast<int32_t*>(reinterpret_cast<char*>(node) + 0x10);
  }

  switch (type) {
  case 0x0C:
    entry = FUN_00508ac0(registry, idPrefix);
    if (entry != nullptr)
      return *reinterpret_cast<int32_t*>(reinterpret_cast<char*>(entry) + 0x9c);
    // fallthrough
  case 0x1C:
    entry = FUN_00508b10(registry, idPrefix);
    if (entry != nullptr)
      return *reinterpret_cast<int32_t*>(reinterpret_cast<char*>(entry) + 0x9c);
    // fallthrough
  case 0x0A:
    entry = FUN_00508b60(registry, idPrefix);
    if (entry != nullptr)
      return *reinterpret_cast<int32_t*>(reinterpret_cast<char*>(entry) + 0x9c);
    // fallthrough
  case 0x0E:
    entry = FUN_00508bb0(registry, idPrefix);
    if (entry != nullptr)
      return *reinterpret_cast<int32_t*>(reinterpret_cast<char*>(entry) + 0x9c);
    // fallthrough
  case 0x46:
    entry = FUN_00508c00(registry, idPrefix);
    if (entry != nullptr)
      return *reinterpret_cast<int32_t*>(reinterpret_cast<char*>(entry) + 0x9c);
    // fallthrough
  case 0x44:
    entry = FUN_00508c50(registry, idPrefix);
    if (entry != nullptr)
      return *reinterpret_cast<int32_t*>(reinterpret_cast<char*>(entry) + 0x9c);
    // fallthrough
  default:
    FUN_007a4480(1, "GetModifierSkillID() passed an invalid IDPrefix: %i\n", idPrefix);
    return -1;
  }
}
