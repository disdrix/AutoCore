// =============================================================================
// FUN_007b66c0 — path basename token lookup in flagged map
// -----------------------------------------------------------------------------
// Stable ID: aa_007b66c0
// Address:   0x007b66c0–0x007b6728  (autoassault.exe, image base 0x400000)
// System:    ND path / interface resource map
// Generated: 2026-07-29 W17-M dual seal (decompile_function + force_decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================
//
// PURPOSE
//   If context flags at +4 have bit 1 (mask 2) set: take basename of path in EAX
//   (last of '\' or '/'), intern via FUN_00989e00 on string pool 0x00d1eac8, then
//   virtual-lookup *(ctx+0xc)->vtbl+0x14. Return 1 on non-zero hit, else 0.
//
// ABI (sealed)
//   EAX     = const char *path
//   stack+4 = PathMapContext *ctx   (cleaned by RET 4)
//   return  = AL bool 0/1
//
// CALLERS (sample)
//   NDUIWindow_LoadInterfaceFile, NDXml_LoadDocumentFromPath, + interface/path loaders
//

#include <cstdint>
#include <cstring>

// External / unresolved (keep Ghidra names)
extern "C" char *strrchr(const char *s, int c);
extern "C" void __thiscall FUN_00989e00(void *string_pool, void *out_token, const char *cstr);

// Ghidra display: undefined4 FUN_007b66c0(int param_1) with in_EAX path
// Actual ABI: path in EAX, ctx on stack, RET 4, bool in AL.
std::uint8_t FUN_007b66c0(int ctx /* stdcall stack arg */)
{
  // path arrives in EAX — model as compiler-provided register param:
  char *path; // = EAX at entry
  char *bslash;
  char *slash;
  char *basename;
  void *token; // decompiler reuses stack slot of ctx after save
  int ctx_saved = ctx;
  int hit;

  if ((*(std::uint8_t *)(ctx + 4) & 2) == 0) {
    return 0;
  }

  bslash = strrchr(path, 0x5c); // '\\'
  slash  = strrchr(path, 0x2f); // '/'

  if (bslash == nullptr) {
    if (slash == nullptr) {
      basename = path;
      goto intern;
    }
  } else if (slash < bslash) {
    slash = bslash;
  }
  basename = slash + 1;

intern:
  // thiscall ECX = 0x00d1eac8 (global string pool)
  FUN_00989e00(reinterpret_cast<void *>(0x00d1eac8), &token, basename);

  // obj = *(ctx+0xc); call obj->vtbl+0x14(&token)
  {
    int *obj = *reinterpret_cast<int **>(ctx_saved + 0xc);
    auto **vtbl = reinterpret_cast<void **>(*reinterpret_cast<void **>(obj));
    auto *fn = reinterpret_cast<int (*)(void *, void *)>(vtbl[0x14 / 4]);
    hit = fn(obj, &token);
  }

  if (hit == 0) {
    return 0;
  }
  return 1;
}
