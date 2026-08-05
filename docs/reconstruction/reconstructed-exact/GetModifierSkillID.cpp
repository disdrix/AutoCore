// =============================================================================
// GetModifierSkillID
// -----------------------------------------------------------------------------
// Stable ID: aa_00509940
// Address:   0x00509940  (autoassault.exe, image base 0x400000)
// Body:      0x00509940–0x00509a78 exclusive (312 / 0x138 bytes)
// System:    skills / modifier ID resolution
// Generated: 2026-07-29 W23-P OWN-ONLY dual seal
// Exactness: Behavior-preserving rewrite of decompiler + read_memory bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Resolve an IDPrefix to a modifier skill ID:
//     1) map prefix → type via global map DAT_00b041dc (node+0x10 = type)
//     2) switch(type) → linear handler-table find on registry this
//     3) return *(entry + 0x9c), or -1 on total failure
//
// PRODUCT NAME: sealed by format string
//   "GetModifierSkillID() passed an invalid IDPrefix: %i\n" @ 0x009cdc88
//
// ABI (sealed):
//   ECX     = registry*  (handler-table owner)
//   stack   = int32 idPrefix
//   ret 4
//   return  = skill id, or 0xFFFFFFFF on failure
//
// DECOMPILER RESIDUALS CORRECTED:
//   - thiscall ECX saved to EDI (not unaff_EDI noise on map call)
//   - map object is &DAT_00b041dc (mov ecx, imm32), not EDI
//   - miss path FALLS THROUGH cases (no break) — preserve in clean
//
// NOTE: map-miss log reuses CVOGLootGenerator::GetTypeFromIDPrefix string;
//       that does not rename this unit.
// =============================================================================

#include <cstdint>

extern "C" void* Map_LowerBoundFindByIntKey(void* map, void* outIt, int32_t* key /*, ...*/);
extern "C" void FUN_007a4480(int level, const char* fmt, ...);

// Family of linear find-by-id helpers (thiscall registry, stack id):
extern "C" void* __thiscall FUN_00508ac0(void* registry, int32_t id);
extern "C" void* __thiscall FUN_00508b10(void* registry, int32_t id);
extern "C" void* __thiscall FUN_00508b60(void* registry, int32_t id);
extern "C" void* __thiscall FUN_00508bb0(void* registry, int32_t id);
extern "C" void* __thiscall FUN_00508c00(void* registry, int32_t id); // HandlerTable54
extern "C" void* __thiscall FUN_00508c50(void* registry, int32_t id); // HandlerTable58

// Globals (Ghidra names)
extern "C" uint8_t DAT_00b041dc[];
extern "C" void* DAT_00b041e0;

int32_t __thiscall GetModifierSkillID(void* registry, int32_t idPrefix)
{
  uint8_t local_it[4];
  int32_t key = idPrefix;
  int32_t type;
  void* entry;

  // Map_LowerBoundFindByIntKey this = &DAT_00b041dc
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

  // MSVC jump-table switch; failed lookup intentionally falls through.
  switch (type) {
  case 0x0C:
    entry = FUN_00508ac0(registry, idPrefix);
    if (entry != nullptr) {
      return *reinterpret_cast<int32_t*>(reinterpret_cast<char*>(entry) + 0x9c);
    }
    // fallthrough
  case 0x1C:
    entry = FUN_00508b10(registry, idPrefix);
    if (entry != nullptr) {
      return *reinterpret_cast<int32_t*>(reinterpret_cast<char*>(entry) + 0x9c);
    }
    // fallthrough
  case 0x0A:
    entry = FUN_00508b60(registry, idPrefix);
    if (entry != nullptr) {
      return *reinterpret_cast<int32_t*>(reinterpret_cast<char*>(entry) + 0x9c);
    }
    // fallthrough
  case 0x0E:
    entry = FUN_00508bb0(registry, idPrefix);
    if (entry != nullptr) {
      return *reinterpret_cast<int32_t*>(reinterpret_cast<char*>(entry) + 0x9c);
    }
    // fallthrough
  case 0x46:
    entry = FUN_00508c00(registry, idPrefix);
    if (entry != nullptr) {
      return *reinterpret_cast<int32_t*>(reinterpret_cast<char*>(entry) + 0x9c);
    }
    // fallthrough
  case 0x44:
    entry = FUN_00508c50(registry, idPrefix);
    if (entry != nullptr) {
      return *reinterpret_cast<int32_t*>(reinterpret_cast<char*>(entry) + 0x9c);
    }
    // fallthrough
  default:
    FUN_007a4480(1, "GetModifierSkillID() passed an invalid IDPrefix: %i\n", idPrefix);
    return -1;
  }
}

// Ghidra symbol alias
int32_t __thiscall FUN_00509940(void* registry, int32_t idPrefix)
{
  return GetModifierSkillID(registry, idPrefix);
}
