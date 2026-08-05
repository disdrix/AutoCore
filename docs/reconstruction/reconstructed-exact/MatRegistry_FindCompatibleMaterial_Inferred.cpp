// =============================================================================
// MatRegistry_FindCompatibleMaterial_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0073d940
// Address:   0x0073d940–0x0073d9ab  (108 B / 0x6C; autoassault.exe, base 0x400000)
// System:    gfx material registry
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-08-04 (W37-X)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - ECX = MatRegistry* (callers: MOV ECX, [DAT_00d1f61c]); stack = Material* probe; RET 4.
 * - Walk 0x14-stride buckets [host+4, host+8); match entry[0] == probe->key_at_8.
 * - Scan material* range [entry+8, entry+0xC); skip probe itself; keep first where
 *   FUN_00752590(candidate, probe) != 0; else 0.
 * - Does NOT AddRef/Release — callers (Pal* FX inits, mesh channel inits) do the swap.
 * - Reject naming this body "refcount swap"; that is post-return caller glue.
 * - _Inferred: no product demangle; structural from bytes + call-site registry global.
 */

#include <cstdint>

struct MatRegistry {
  void* unused0;
  uint32_t* bucket_begin; // +4  (0x14-stride records as uint32_t[5])
  uint32_t* bucket_end;   // +8
};

// Unowned: EAX=candidate, EDX=probe → non-zero if compatible
extern "C" char FUN_00752590(void* candidate /*EAX*/, void* probe /*EDX*/);

// Retail: thiscall ECX=host, stack probe, RET 4
extern "C" void* __thiscall MatRegistry_FindCompatibleMaterial_Inferred(
    MatRegistry* host /*ECX*/,
    void* probe /*stack*/)
{
  if (probe == nullptr) {
    return nullptr;
  }
  uint32_t key = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(probe) + 8);
  if (key == 0) {
    return nullptr;
  }

  uint32_t* bucket = host->bucket_begin;
  uint32_t* bend = host->bucket_end;
  while (bucket != bend) {
    if (bucket[0] == key) {
      void** it = reinterpret_cast<void**>(bucket[2]);
      void** end = reinterpret_cast<void**>(bucket[3]);
      if (it == end) {
        return nullptr;
      }
      for (;;) {
        void* candidate = *it;
        if (candidate != probe) {
          char ok = FUN_00752590(candidate, probe);
          if (ok != 0) {
            return candidate;
          }
        }
        ++it;
        if (it == end) {
          return nullptr;
        }
      }
    }
    bucket += 5; // stride 0x14
  }
  return nullptr;
}
