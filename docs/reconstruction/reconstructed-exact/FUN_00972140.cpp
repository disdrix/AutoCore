// =============================================================================
// FUN_00972140
// -----------------------------------------------------------------------------
// Stable ID: aa_00972140
// Address:   0x00972140–0x00972421  (autoassault.exe, image base 0x400000)
// Structural: AssPreloader_PreloadWorkerLoop_Inferred
// Dual:      W32-K 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed ABI.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI: stack = AssPreloader* host; RET 4; void.
// Product strings: "PRELOAD: unable to preload asset %s",
//   "C:\\vog\\1_code\\palantir\\palantir\\assets\\assPreloader.cpp" line 0x212.
// =============================================================================

#include <cstdint>
#include <cstring>
#include <windows.h>

struct GuardedVectorHeader {
  uint32_t _unk00;
  uint32_t** pages;
  uint32_t capacity;
  uint32_t begin;
  int32_t  size;
};

extern "C" uint8_t FUN_0043e510(void);
extern "C" void FUN_00970fc0(void);
extern "C" int* FUN_0044a860(void* /*ECX=host+0xdc*/);
extern "C" void FUN_0043c5f0(void* dest /*stack; ECX=source*/);
extern "C" void FUN_00971b80(void* out, void* path_obj, uint32_t type, uint32_t key_field);
extern "C" void FUN_00971280(void* host, void* request);
extern "C" void FUN_0043e970(void* value /*stack; EAX=container*/);
extern "C" uint32_t* FUN_0043d700(void);
extern "C" void* FUN_0096a630(void* basic_string_out);
extern "C" void* FUN_0076cec0(void*, const char* fmt, ...);
extern "C" void vog_LogMessage(const char* file, int line, int level, void* msg);
extern "C" void __thiscall FUN_0043d670(GuardedVectorHeader* c, const uint32_t* v);
extern "C" void FUN_0040d9c0(void);
extern "C" void operator_delete(void* p);

void FUN_00972140(void* host /*stack*/)
{
  char* path_slot = nullptr;
  uint8_t nonempty = FUN_0043e510(); // retail ESI=host+0x1c

  while (nonempty != 0) {
    FUN_00970fc0();

    int ticket = *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(host) + 0xe0);
    int* cur = FUN_0044a860(reinterpret_cast<uint8_t*>(host) + 0xdc);
    if (*cur == ticket) {
      GuardedVectorHeader local{};
      void* cache = *reinterpret_cast<void**>(
          reinterpret_cast<uint8_t*>(host) + 0x110);
      FUN_0043c5f0(&local); // ECX=cache+0x28 at call site

      bool handled = false;
      uint32_t idx = local.begin;
      const uint32_t end = static_cast<uint32_t>(local.size) + local.begin;

      for (; idx != end; ++idx) {
        uint32_t page = idx >> 2;
        const uint32_t sub = idx + page * static_cast<uint32_t>(-4);
        if (local.capacity <= page) {
          page -= local.capacity;
        }
        void** elem = *reinterpret_cast<void***>(
            reinterpret_cast<uint8_t*>(local.pages[page]) + sub * 4);
        using PathFn = int(__thiscall*)(void*, char**);
        PathFn get_path = *reinterpret_cast<PathFn*>(
            *reinterpret_cast<uint8_t**>(elem) + 0x0c);
        int path_obj = get_path(elem, &path_slot);
        if (path_obj == 0) {
          continue;
        }

        const char* path = path_slot ? path_slot : "";
        const char* dot = std::strrchr(path, '.');
        if (dot != nullptr) {
          uint32_t type = 0;
          if (_stricmp(dot + 1, "geo") == 0) {
            type = 0;
          } else if (_stricmp(dot + 1, "xml") == 0) {
            type = 3;
          } else {
            goto success_record;
          }
          uint8_t req[16] = {};
          uint32_t key_field =
              *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(elem) + 4);
          FUN_00971b80(req, reinterpret_cast<void*>(path_obj), type, key_field);
          FUN_00971280(host, req);
          // operator_delete if req owned block non-null — continues after
        }

      success_record: {
        CRITICAL_SECTION* cs = reinterpret_cast<CRITICAL_SECTION*>(
            reinterpret_cast<uint8_t*>(host) + 0x60);
        if (*reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(host) + 0x78)) {
          EnterCriticalSection(cs);
        }
        // EAX = host+0x4c success stride-2 vec
        FUN_0043e970(&path_slot);
        if (*reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(host) + 0x78)) {
          LeaveCriticalSection(cs);
        }
        *FUN_0043d700() = 1;
        handled = true;
        break;
      }
      }

      if (!handled) {
        char name_storage[28] = {};
        void* name_str = FUN_0096a630(name_storage);
        const char* cstr =
            (*reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(name_str) + 0x18) < 0x10)
                ? reinterpret_cast<const char*>(reinterpret_cast<uint8_t*>(name_str) + 4)
                : *reinterpret_cast<const char**>(reinterpret_cast<uint8_t*>(name_str) + 4);
        void* msg = FUN_0076cec0(&host, "PRELOAD: unable to preload asset %s", cstr);
        vog_LogMessage(
            "C:\\vog\\1_code\\palantir\\palantir\\assets\\assPreloader.cpp",
            0x212, 2, msg);

        CRITICAL_SECTION* cs = reinterpret_cast<CRITICAL_SECTION*>(
            reinterpret_cast<uint8_t*>(host) + 0x90);
        if (*reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(host) + 0xa8)) {
          EnterCriticalSection(cs);
        }
        // ECX = host+0x7c tracked; push path_slot
        FUN_0043d670(
            reinterpret_cast<GuardedVectorHeader*>(
                reinterpret_cast<uint8_t*>(host) + 0x7c),
            reinterpret_cast<const uint32_t*>(&path_slot));
        if (*reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(host) + 0xa8)) {
          LeaveCriticalSection(cs);
        }
      }

      Sleep(0);
      FUN_0040d9c0();
    }

    nonempty = FUN_0043e510();
  }
}
