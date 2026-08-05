// =============================================================================
// GlyphCache_GetOrCreate_ByFontKey_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0073bc50
// Address:   0x0073bc50  (autoassault.exe, image base 0x400000)
// System:    GlyphCache / gfxFont font-key map get-or-create
// Wave:      W37-AE dual seal 2026-08-04
// Exactness: Behavior-preserving rewrite from decompile + read_memory.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE: Look up a font-key in a NestedHash-style map; on miss allocate
// GlyphCache (0xB8) via GlyphCache_PlacementCtor (W35-H), rasterize glyphs
// with FUN_00754a10 (requested name, then "Arial" fallback), insert node,
// return GlyphCache*. On hit return node[+0x2c]. Fail → null (scalar dtor).
// Product: sole CODE caller FUN_0099ed40 in gfxFont.cpp
//          ("Failed to create font: %s").
// ABI: ECX + 3 stack formals; RET 12; returns GlyphCache* in EAX.
//

#include <cstdint>
#include <string>

struct GlyphCache; // W35-H aa_00754ee0 — size 0xB8, refcount at +0x04

// Residual / unowned helpers (image)
// map lower_bound into out_it; miss when *out_it == map.sentinel(+8)
void FUN_00463c40(void* map, void** out_it /* + ESI key side-channel */);
// map insert of key node (string + two dwords + GlyphCache*)
void FUN_004638c0(void** it_slot, void* key_node);
// GlyphCache placement ctor (stack this*, RET 4) — W35-H sealed
GlyphCache* GlyphCache_PlacementCtor(GlyphCache* self /*stack*/);
// Font glyph rasterize into cache; <0 on failure. thiscall GlyphCache*
int __thiscall FUN_00754a10(GlyphCache* self, const char* face_name, int size_param);
void* operator_new(uint32_t size);
// scalar deleting dtor via vtbl[0](1)

// Formals (Ghidra thiscall shape; bytes: RET 12):
//   ECX  = size/style formal (stored into key; also passed to FUN_00754a10)
//   stack0 = map*          (sole site: DAT_00d1f628)
//   stack1 = face_name*
//   stack2 = second key dword (style/weight residual)
GlyphCache* __thiscall GlyphCache_GetOrCreate_ByFontKey_Inferred(
    int size_or_style /*ECX*/,
    void* map /*stack*/,
    const char* face_name /*stack*/,
    int key_dword_b /*stack*/)
{
  // SEH LAB_009b11c0 omitted
  std::string key_name(face_name ? face_name : "");
  // Build lookup key: { name, size_or_style, key_dword_b } — decompiler
  // packs these beside local_80 / local_64 / local_60 before FUN_00463c40.

  void* it = nullptr;
  FUN_00463c40(map, &it);

  GlyphCache* cache = nullptr;
  void* sentinel = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(map) + 8);

  if (it == sentinel) {
    // Miss: allocate + placement-construct GlyphCache
    void* mem = operator_new(0xB8);
    cache = mem ? GlyphCache_PlacementCtor(static_cast<GlyphCache*>(mem)) : nullptr;

    int rc = FUN_00754a10(cache, face_name, size_or_style);
    if (rc < 0) {
      rc = FUN_00754a10(cache, "Arial", size_or_style);
    }
    if (rc < 0) {
      if (cache != nullptr) {
        // vtbl[0] scalar deleting dtor(1)
        auto** vtbl = *reinterpret_cast<void***>(cache);
        reinterpret_cast<void(__thiscall*)(GlyphCache*, int)>(vtbl[0])(cache, 1);
      }
      return nullptr;
    }

    // AddRef: refcount at +4; on 0→1 call vtbl[+4]
    int32_t* pref = reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(cache) + 4);
    *pref += 1;
    if (*pref == 1) {
      auto** vtbl = *reinterpret_cast<void***>(cache);
      reinterpret_cast<void(__thiscall*)(GlyphCache*)>(vtbl[1])(cache);
    }

    // Insert key node: name + size_or_style + key_dword_b + cache* @ value
    // FUN_004638c0(&it, key_node) — node layout residual; value at node+0x2c
    // (hit path reads +0x2c).
    // FUN_004638c0(...);  // residual full node layout
  } else {
    // Hit: GlyphCache* lives at node + 0x2c
    cache = *reinterpret_cast<GlyphCache**>(reinterpret_cast<uint8_t*>(it) + 0x2c);
  }

  return cache;
}
