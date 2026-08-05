// =============================================================================
// AssPreloader_TryPreloadChildAssetsForAbsentKeys_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00971280
// Address:   0x00971280–0x00971472  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_00971280
// System:    assPreloader / asset preload pipeline
// Dual:      W32-J 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI:
//   stack = (AssPreloader* host, KeyVec* keys); RET 8; void.
//   KeyVec: +0x04 begin dword*, +0x08 end dword* (flat pointer range).
//
// For each key* in [begin,end):
//   drain/process via FUN_00970fc0 (EAX=host).
//   If key is ABSENT from membership tree at host+0xDC
//     (lower_bound FUN_0044a860 returns end header at host+0xE0):
//     snapshot child objects from *(host+0x110)+0x28 into local ring
//       (FUN_0043c5f0);
//     for each child: result = child->vtbl[+0x0C](key*);
//       on first success:
//         push {key_value, result} to host+0x4C (stride-2, FUN_0043e970)
//           under optional CS host+0x60 if *(host+0x78);
//         find-or-insert key in tree host+0xDC (FUN_0043d700); set value=1;
//       if all fail:
//         log assPreloader.cpp:0x241 "PRELOAD: unable to preload child asset %s"
//           (name via FUN_0096a630 / assId format);
//         push key* to host+0x7C (FUN_0043d670) under optional CS host+0x90
//           if *(host+0xA8);
//     Sleep(0); destroy local ring (FUN_0040d9c0).
//
// Name is structural (_Inferred). Nested helpers not dual-owned here.
// =============================================================================

#include <cstdint>
#include <windows.h>

struct KeyVec {
  uint32_t _unk00;
  int** begin;  // +0x04
  int** end;    // +0x08
};

struct GuardedVectorHeader {
  uint32_t _unk00;
  uint32_t** pages;  // +0x04
  uint32_t capacity; // +0x08
  uint32_t begin;    // +0x0c
  int32_t  size;     // +0x10
};

// Nested helpers (owned elsewhere; ABI as used at this site).
extern "C" void FUN_00970fc0(void /*EAX=host*/);
extern "C" void __fastcall FUN_0044a860(void* tree /*ECX*/, void* out_it /*EAX*/ /*EBX=key**/);
extern "C" void __fastcall FUN_0043c5f0(void* child_src /*ECX*/, GuardedVectorHeader* out /*stack*/);
extern "C" void GuardedVector_PushBack_Stride2_U32x2(void* container /*EAX*/, const void* pair /*stack*/);
extern "C" uint32_t* __fastcall FUN_0043d700(const int* key /*ECX*/ /*EDI=tree*/);
extern "C" void* __thiscall FUN_0096a630(const int* key /*ECX*/, void* out_string /*stack*/);
extern "C" void* FUN_0076cec0(void* scratch, const char* fmt, const char* name);
extern "C" void vog_LogMessage(const char* file, int line, int level, void* msg);
extern "C" void GuardedVector_PushBack_Thiscall(GuardedVectorHeader* container /*ECX*/,
                                                const int* key /*stack*/);
extern "C" void FUN_0040d9c0(void /*ESI=ring*/);

void AssPreloader_TryPreloadChildAssetsForAbsentKeys_Inferred(
    void* host /*stack; retail*/,
    KeyVec* keys /*stack; retail*/)
{
  int** cur = keys->begin;
  int** const vend = keys->end;

  for (; cur != vend; ++cur) {
    FUN_00970fc0();

    void* it = nullptr;
    void* tree = reinterpret_cast<uint8_t*>(host) + 0xDC;
    // EBX = *cur (key*) set by call-site convention inside lower_bound.
    FUN_0044a860(tree, &it);

    void* end_hdr = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(host) + 0xE0);
    if (it != end_hdr) {
      continue; // key already present in membership tree
    }

    GuardedVectorHeader local{};
    void* cache = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(host) + 0x110);
    void* child_src = reinterpret_cast<uint8_t*>(cache) + 0x28;
    FUN_0043c5f0(child_src, &local);

    uint8_t success = 0;
    uint32_t idx = local.begin;
    const uint32_t end = static_cast<uint32_t>(local.size) + local.begin;
    for (; idx != end; ++idx) {
      uint32_t page = idx >> 2;
      const uint32_t sub = idx + page * static_cast<uint32_t>(-4); // idx & 3
      if (local.capacity <= page) {
        page -= local.capacity;
      }
      // Slot holds child object*.
      void** child_pp = reinterpret_cast<void**>(
          reinterpret_cast<uint8_t*>(local.pages[page]) + sub * 4);
      void* child = *child_pp;
      // vtbl[3] at +0x0C: try preload this parent key against child.
      using ChildPreloadFn = int(__thiscall*)(void* child, int* key);
      auto** vtbl = *reinterpret_cast<ChildPreloadFn***>(child);
      int result = vtbl[0x0C / 4](child, *cur);
      if (result != 0) {
        struct {
          uint32_t key_val;
          int child_result;
        } pair{};
        pair.key_val = static_cast<uint32_t>(**cur);
        pair.child_result = result;

        char* flag78 = reinterpret_cast<char*>(reinterpret_cast<uint8_t*>(host) + 0x78);
        auto* cs60 = reinterpret_cast<CRITICAL_SECTION*>(
            reinterpret_cast<uint8_t*>(host) + 0x60);
        if (*flag78 != 0) {
          EnterCriticalSection(cs60);
        }
        void* ring4c = reinterpret_cast<uint8_t*>(host) + 0x4C;
        GuardedVector_PushBack_Stride2_U32x2(ring4c, &pair);
        if (*flag78 != 0) {
          LeaveCriticalSection(cs60);
        }

        uint32_t* slot = FUN_0043d700(*cur); // EDI=tree host+0xDC
        *slot = 1;
        success = 1;
        break;
      }
    }

    if (!success) {
      // Name string + log path sealed by product strings in body.
      alignas(4) uint8_t name_storage[28]{};
      void* name_str = FUN_0096a630(*cur, name_storage);
      const char* cstr = nullptr;
      // MSVC basic_string SSO: if size < 0x10, chars at +4; else heap at +4.
      if (*reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(name_str) + 0x18) < 0x10) {
        cstr = reinterpret_cast<const char*>(reinterpret_cast<uint8_t*>(name_str) + 4);
      } else {
        cstr = *reinterpret_cast<const char**>(reinterpret_cast<uint8_t*>(name_str) + 4);
      }
      void* msg = FUN_0076cec0(&keys, "PRELOAD: unable to preload child asset %s", cstr);
      vog_LogMessage(
          "C:\\vog\\1_code\\palantir\\palantir\\assets\\assPreloader.cpp",
          0x241, 2, msg);
      // ~basic_string(name_storage) — IAT dtor omitted in clean outline.

      char* flag_a8 = reinterpret_cast<char*>(reinterpret_cast<uint8_t*>(host) + 0xA8);
      auto* cs90 = reinterpret_cast<CRITICAL_SECTION*>(
          reinterpret_cast<uint8_t*>(host) + 0x90);
      if (*flag_a8 != 0) {
        EnterCriticalSection(cs90);
      }
      auto* fail_ring = reinterpret_cast<GuardedVectorHeader*>(
          reinterpret_cast<uint8_t*>(host) + 0x7C);
      GuardedVector_PushBack_Thiscall(fail_ring, *cur);
      if (*flag_a8 != 0) {
        LeaveCriticalSection(cs90);
      }
    }

    Sleep(0);
    FUN_0040d9c0(); // ESI=&local
  }
}
