// =============================================================================
// AssPreloader_PreloadWorkerLoop_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00972140
// Address:   0x00972140–0x00972421  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_00972140
// System:    assPreloader / asset preload pipeline
// Dual:      W32-K 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI:
//   stack = AssPreloader* host; RET 4; void.
//   Sole caller FUN_00972460 thread trampoline: loops this then
//   WaitForSingleObject(*(HANDLE*)(host+4), INFINITE) while refcount > 0.
//
// While pending GuardedVector at host+0x1c is non-empty (FUN_0043e510):
//   FUN_00970fc0 drain/process;
//   if ticket *(host+0xe0) == *FUN_0044a860(host+0xdc):
//     snapshot *(host+0x110)+0x28 factory list (GuardedVector_AssignTo);
//     for each elem: vtbl[+0xc] → path; ext geo→type0 / xml→type3;
//       FUN_00971b80 + FUN_00971280 submit;
//       CS host+0x60 (gate +0x78): GuardedVector_PushBack_Stride2_U32x2;
//         flag via FUN_0043d700 *slot=1;
//     else: log PRELOAD unable @ assPreloader.cpp:0x212;
//       CS host+0x90 (gate +0xa8): pending fail update (FUN_0043d670 path);
//     Sleep(0); FUN_0040d9c0 clear local snapshot.
//
// Name is structural (_Inferred). Product file string seals family.
// Nested request build/submit not dual-owned here.
// Reject treating operator_delete as noreturn (Ghidra false positive).
// =============================================================================

#include <cstdint>
#include <cstring>
#include <windows.h>

struct GuardedVectorHeader {
  uint32_t _unk00;
  uint32_t** pages;  // +0x04
  uint32_t capacity; // +0x08
  uint32_t begin;    // +0x0c
  int32_t  size;     // +0x10
};

struct PodU32x2 {
  uint32_t a;
  uint32_t b;
};

extern "C" uint8_t FUN_0043e510(void /*ESI=pending*/);
extern "C" void FUN_00970fc0(void);
extern "C" int* FUN_0044a860(void* ticket_slot /*ECX=host+0xdc*/);
extern "C" void GuardedVector_AssignTo(void* source /*ECX*/, void* dest /*stack*/);
extern "C" void FUN_00971b80(void* out_req, void* path_obj, uint32_t type, uint32_t key_field);
extern "C" void FUN_00971280(void* host /*stack*/, void* request /*stack*/);
extern "C" void GuardedVector_PushBack_Stride2_U32x2(GuardedVectorHeader* c /*EAX*/,
                                                      const PodU32x2* v /*stack*/);
extern "C" uint32_t* FUN_0043d700(void);
extern "C" void* FUN_0096a630(void* basic_string_out /*stack*/);
extern "C" void* FUN_0076cec0(void* /*...*/, const char* fmt, ...);
extern "C" void vog_LogMessage(const char* file, int line, int level, void* msg);
extern "C" void __thiscall GuardedVector_PushBack_Thiscall(
    GuardedVectorHeader* container /*ECX*/, const uint32_t* value /*stack*/);
extern "C" void FUN_0040d9c0(void /*ESI=local snapshot*/);
extern "C" void operator_delete(void* p);

// Clean surface: stack host made explicit; CS/ext CF preserved.
void AssPreloader_PreloadWorkerLoop_Inferred(void* host /*stack; retail*/)
{
  char* path_slot = nullptr;
  // Retail SEH: LAB_009b264e

  // ESI = host+0x1c for empty check.
  auto* pending = reinterpret_cast<GuardedVectorHeader*>(
      reinterpret_cast<uint8_t*>(host) + 0x1c);
  (void)pending;

  uint8_t nonempty = FUN_0043e510();
  while (nonempty != 0) {
    FUN_00970fc0();

    const int ticket = *reinterpret_cast<int*>(
        reinterpret_cast<uint8_t*>(host) + 0xe0);
    int* cur = FUN_0044a860(reinterpret_cast<uint8_t*>(host) + 0xdc);
    if (*cur == ticket) {
      GuardedVectorHeader local{};
      void* cache = *reinterpret_cast<void**>(
          reinterpret_cast<uint8_t*>(host) + 0x110);
      // Assign from cache+0x28 into local.
      GuardedVector_AssignTo(reinterpret_cast<uint8_t*>(cache) + 0x28, &local);

      bool handled = false;
      uint32_t idx = local.begin;
      const uint32_t end = static_cast<uint32_t>(local.size) + local.begin;
      for (; idx != end; ++idx) {
        uint32_t page = idx >> 2;
        const uint32_t sub = idx + page * static_cast<uint32_t>(-4);
        if (local.capacity <= page) {
          page -= local.capacity;
        }
        // Element is pointer-to-object with vtbl.
        void** elem = *reinterpret_cast<void***>(
            reinterpret_cast<uint8_t*>(local.pages[page]) + sub * 4);
        // vtbl[+0x0c](out path*)
        using PathFn = int(__thiscall*)(void* self, char** out_path);
        PathFn get_path = *reinterpret_cast<PathFn*>(
            *reinterpret_cast<uint8_t**>(elem) + 0x0c);
        int path_obj = get_path(elem, &path_slot);
        if (path_obj == 0) {
          continue;
        }

        const char* path = path_slot;
        if (path == nullptr) {
          path = ""; // retail PTR_DAT_00afa2bc empty fallback
        }
        const char* dot = std::strrchr(path, '.');
        if (dot == nullptr) {
          // fall through to success-record path with path_obj still set
        } else {
          uint32_t type = 0;
          if (_stricmp(dot + 1, "geo") == 0) {
            type = 0;
          } else if (_stricmp(dot + 1, "xml") == 0) {
            type = 3;
          } else {
            // non-geo/xml: still push success record below (LAB_009722f3)
            goto success_record;
          }

          uint8_t req_buf[0x10] = {};
          uint32_t key_field = *reinterpret_cast<uint32_t*>(
              reinterpret_cast<uint8_t*>(elem) + 4);
          FUN_00971b80(req_buf, reinterpret_cast<void*>(path_obj), type, key_field);
          FUN_00971280(host, req_buf);
          // optional operator_delete on owned req block if non-null
        }

      success_record:
        {
          auto* cs = reinterpret_cast<CRITICAL_SECTION*>(
              reinterpret_cast<uint8_t*>(host) + 0x60);
          const uint8_t gate =
              *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(host) + 0x78);
          PodU32x2 rec{};
          rec.a = reinterpret_cast<uint32_t>(path_slot);
          rec.b = static_cast<uint32_t>(path_obj);
          if (gate != 0) {
            EnterCriticalSection(cs);
          }
          // EAX = container at host+0x4c region (retail lea edi,[ebx+0x4c])
          auto* success_vec = reinterpret_cast<GuardedVectorHeader*>(
              reinterpret_cast<uint8_t*>(host) + 0x4c);
          GuardedVector_PushBack_Stride2_U32x2(success_vec, &rec);
          if (gate != 0) {
            LeaveCriticalSection(cs);
          }
          uint32_t* flag = FUN_0043d700();
          *flag = 1;
          handled = true;
          break;
        }
      }

      if (!handled) {
        // Build name string FUN_0096a630; log PRELOAD unable.
        char name_storage[28] = {};
        void* name_str = FUN_0096a630(name_storage);
        const char* cstr = nullptr;
        // MSVC basic_string SSO: if size < 0x10 use +4 else *(+4)
        if (*reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(name_str) + 0x18) < 0x10) {
          cstr = reinterpret_cast<const char*>(
              reinterpret_cast<uint8_t*>(name_str) + 4);
        } else {
          cstr = *reinterpret_cast<const char**>(
              reinterpret_cast<uint8_t*>(name_str) + 4);
        }
        void* msg = FUN_0076cec0(&host, "PRELOAD: unable to preload asset %s", cstr);
        vog_LogMessage(
            "C:\\vog\\1_code\\palantir\\palantir\\assets\\assPreloader.cpp",
            0x212, 2, msg);

        auto* cs_fail = reinterpret_cast<CRITICAL_SECTION*>(
            reinterpret_cast<uint8_t*>(host) + 0x90);
        const uint8_t gate_fail =
            *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(host) + 0xa8);
        if (gate_fail != 0) {
          EnterCriticalSection(cs_fail);
        }
        // Fail-path pending update (FUN_0043d670 on path slot under CS).
        GuardedVector_PushBack_Thiscall(
            reinterpret_cast<GuardedVectorHeader*>(
                reinterpret_cast<uint8_t*>(host) + 0x7c),
            reinterpret_cast<const uint32_t*>(&path_slot));
        if (gate_fail != 0) {
          LeaveCriticalSection(cs_fail);
        }
      }

      Sleep(0);
      FUN_0040d9c0();
    }

    nonempty = FUN_0043e510();
  }
}
