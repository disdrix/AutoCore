// =============================================================================
// FxCache_EnsureMasterAndResolve
// -----------------------------------------------------------------------------
// Stable ID: aa_005408f0
// Address:   0x005408f0  (autoassault.exe, image base 0x400000)
// System:    client-fx / skills-abilities
// Generated: 2026-07-29 W20-I dual A/B seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Look up a skill/FX cache entry by integer key in the host hash at this+0xf0c.
//   If the entry's master-loaded flag (value+0x0a) is clear, resolve the skill
//   definition name via SkillDefMap and call FxMaster_LoadMasterFromXML.
//   Then resolve an FX instance/template via FUN_004a16d0 (this = value+4).
//
// ABI: __thiscall — ECX = host*; stack (key, eventA, eventB); ret 0x0c.
// Body: 005408f0–005409b1 (193 bytes).
//
// DISTINCT FROM:
//   FxCache_ApplyWithNfxEnsure (0x00542790) — full apply/attach + nfx path open.
//
// SEALED: inline hash walk; master gate; SkillDef→LoadMaster; ret 0x0c; live≡raw.
// =============================================================================

#include <cstdint>

// External symbols (autoassault.exe) — names structural where dualed.
struct SkillDefMapHeader;
struct FxMasterHost;

extern "C" SkillDefMapHeader* FUN_0054b480(void); // SkillDefMap_GetGlobal
extern "C" void FUN_00418890(void* outIt, uint32_t* pKey); // SkillDefMap_ExactFindByIntKey
extern "C" void FUN_00540090(void* skillNameSrc, char* dst, size_t cap);
extern "C" uint32_t FUN_004a6390(char* scriptBaseName); // FxMaster_LoadMasterFromXML
extern "C" uint32_t FUN_004a16d0(uint32_t eventA, uint32_t eventB, int slotOrFlags);

// Host layout (partial)
//   +0xf0c  CNDHash*  skill/fx cache (bucket mask @ hash+8, table @ hash+0x10)
// Hash node: key@+0x10, next@+0x0c, value@+0x08
// Value:     masterLoaded@+0x0a (char); FxMaster host at value+4 (bytes)

uint32_t __thiscall FxCache_EnsureMasterAndResolve(
    void* host,
    uint32_t key,
    uint32_t eventA,
    uint32_t eventB)
{
  // --- inline CNDHash_Lookup (matches decompiler / entry bytes) ---
  uint8_t* hash = *reinterpret_cast<uint8_t**>(reinterpret_cast<uint8_t*>(host) + 0xf0c);
  uint32_t mask = *reinterpret_cast<uint32_t*>(hash + 8);
  uint32_t* table = *reinterpret_cast<uint32_t**>(hash + 0x10);
  int node = *reinterpret_cast<int*>(table[(mask & key)] + 4);

  void* value = nullptr;
  if (node != 0) {
    for (;;) {
      if (key == *reinterpret_cast<uint32_t*>(node + 0x10)) {
        value = *reinterpret_cast<void**>(node + 8);
        break;
      }
      node = *reinterpret_cast<int*>(node + 0xc);
      if (node == 0) {
        value = nullptr;
        break;
      }
    }
  }

  if (value == nullptr) {
    return 0;
  }

  if (*reinterpret_cast<char*>(reinterpret_cast<uint8_t*>(value) + 10) == '\0') {
    // SkillDefMap_GetGlobal is a leaf (no args). Decompiler may show dummy args.
    int it = 0;
    uint32_t keyCopy = key;
    (void)FUN_0054b480();
    FUN_00418890(&it, &keyCopy);
    SkillDefMapHeader* map = FUN_0054b480();
    int endSentinel = *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(map) + 4);
    if (it != endSentinel) {
      char pathBuf[1024];
      FUN_00540090(reinterpret_cast<void*>(it + 0x10), pathBuf, 0x400);
      FUN_004a6390(pathBuf);
    }
  }

  // Bytes at exit: lea ecx, [value+4]; push -1; push eventB; push eventA; call FUN_004a16d0
  // Decompiler surfaces (eventA, eventB, -1) as stack args with this in ECX.
  (void)reinterpret_cast<FxMasterHost*>(reinterpret_cast<uint8_t*>(value) + 4);
  return FUN_004a16d0(eventA, eventB, -1);
}
