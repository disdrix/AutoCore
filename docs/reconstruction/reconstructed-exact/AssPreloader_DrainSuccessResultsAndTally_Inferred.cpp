// =============================================================================
// AssPreloader_DrainSuccessResultsAndTally_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00971480
// Address:   0x00971480–0x00971637  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_00971480
// System:    assPreloader / asset preload pipeline
// Dual:      W37-B 2026-08-04
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI: host* on stack; RET 0x4; void. Not thiscall.
// Drain success GuardedVector at host+0x4c (stride-8 pop via FUN_0043e750):
//   - if asset absent/null in resource cache (host+0x110):
//       stamp tree@+0x10 with {obj,time}; tally size@+0xe8[bucket] and count@+0xfc[bucket]
//   - else: log PRELOAD already-loaded + scalar-delete obj
// Optional dump of tree@+0x14 when DAT_00d1f618 set (then clear).
// Name Inferred from assPreloader.cpp strings + AssPreloader host offsets (family duals).
// Reject scaffold Named_assPreloader plate as method English.
// =============================================================================

#include <cstdint>

// Nested / external (not re-owned here):
// 0043e750: ESI=vec*, EDI=out pair{u32,u32}; AL=popped (stride 8 / 2 dwords)
// 0044e8c0: HashMap_FindIterator_Inferred (W21-N) EDI=map* EBX=key*
// 0076c330: time source → float80/float
// 0043d570: tree slot ensure/find; EDI=tree host (host+0x10)
// 00970910: extension bucket 0..4 (.geo/.dds/.ogg/.xml/OTHER)
// 0096a630: name → basic_string out
// 0076cec0: sprintf-style into scratch
// 00996dc0: vog_LogMessage
// 00457cc0: tree iterator advance

extern "C" uint8_t FUN_0043e750(void /*ESI vec, EDI out*/);
extern "C" void*   FUN_0044e8c0(void* out_it /*stack*/);
extern "C" long double FUN_0076c330(void);
extern "C" uint32_t* FUN_0043d570(void /*EDI tree, key*/);
extern "C" int     FUN_00970910(void* name_holder);
extern "C" void*   FUN_0096a630(void* out_string);
extern "C" void*   FUN_0076cec0(void* scratch, const char* fmt, ...);
extern "C" void    vog_LogMessage(const char* file, int line, int level, void* msg);
extern "C" void    FUN_00457cc0(void);
extern char        DAT_00d1f618;
extern char*       PTR_DAT_00afa2bc;
extern void*       ExceptionList;
extern uint8_t     LAB_009afdf1;

struct AssPreloaderHost_Partial {
  // ...
  // +0x10 tree root linkage for timed entries
  // +0x14 tree end / dump cursor base
  // +0x4c success GuardedVector (pop ESI)
  // +0xe8 int size_tally[5+]
  // +0xfc int count_tally[5+]
  // +0x110 void* resource_cache
};

extern "C" void AssPreloader_DrainSuccessResultsAndTally_Inferred(void* host /*stack*/)
{
  void* pvStack_14;
  uint8_t* puStack_10;
  uint32_t local_c = 0xffffffff;
  int local_4c;
  void* local_48 = reinterpret_cast<uint8_t*>(host) + 0x4c;
  uint32_t local_44 = 0;
  int* local_40;
  float local_38;
  uint8_t local_34[32];  // basic_string shell (name temp)

  puStack_10 = &LAB_009afdf1;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;

  // ESI=host+0x4c, EDI=&pair_out (local_44/local_40 region)
  uint8_t cVar2 = FUN_0043e750();
  while (cVar2 != 0) {
    int* cache = *reinterpret_cast<int**>(reinterpret_cast<uint8_t*>(host) + 0x110);
    FUN_0044e8c0(&local_4c);
    int* pair_obj = local_40;

    if (local_4c == cache[2] /* map+8 end sentinel */
        || *reinterpret_cast<int*>(local_4c + 0xc) == 0) {
      long double t80 = FUN_0076c330();
      local_38 = static_cast<float>(t80);
      // EDI = host+0x10 for tree
      uint32_t* slot = FUN_0043d570();
      slot[0] = reinterpret_cast<uint32_t>(pair_obj);
      slot[1] = *reinterpret_cast<uint32_t*>(&local_38);
      int bucket = FUN_00970910(&local_44);
      int (*size_fn)() = *reinterpret_cast<int (**)()>(*pair_obj + 0x1c);
      int sz = size_fn();
      *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(host) + 0xe8 + bucket * 4) += sz;
      *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(host) + 0xfc + bucket * 4) += 1;
    } else {
      void* name_str = FUN_0096a630(local_34);
      local_c = 0;
      int name_base = reinterpret_cast<int>(name_str);
      const char* cstr;
      if (*reinterpret_cast<uint32_t*>(name_base + 0x18) < 0x10) {
        cstr = reinterpret_cast<const char*>(name_base + 4);
      } else {
        cstr = *reinterpret_cast<const char**>(name_base + 4);
      }
      void* msg = FUN_0076cec0(&local_48,
          "PRELOAD: preloaded already loaded asset %s", cstr);
      vog_LogMessage(
          "C:\\vog\\1_code\\palantir\\palantir\\assets\\assPreloader.cpp",
          0xd3, 1, msg);
      local_c = 0xffffffff;
      // ~basic_string(local_34)
      if (local_40 != nullptr) {
        void (**vt)(int) = *reinterpret_cast<void (***)(int)>(local_40);
        (*vt)(1);  // scalar-deleting dtor
      }
    }
    cVar2 = FUN_0043e750();
  }

  if (DAT_00d1f618 != 0) {
    local_4c = **reinterpret_cast<int**>(reinterpret_cast<uint8_t*>(host) + 0x14);
    if (reinterpret_cast<int*>(local_4c)
        != *reinterpret_cast<int**>(reinterpret_cast<uint8_t*>(host) + 0x14)) {
      do {
        const char* nm = *reinterpret_cast<const char**>(local_4c + 0xc);
        if (nm == nullptr) {
          nm = PTR_DAT_00afa2bc;
        }
        int* obj = *reinterpret_cast<int**>(local_4c + 0x10);
        int (*size_fn)(const char*) =
            *reinterpret_cast<int (**)(const char*)>(*obj + 0x1c);
        int sz = size_fn(nm);
        void* msg = FUN_0076cec0(&local_48, "%d\t\t%s\n", sz);
        vog_LogMessage(
            "C:\\vog\\1_code\\palantir\\palantir\\assets\\assPreloader.cpp",
            0xe8, 1, msg);
        FUN_00457cc0();
      } while (local_4c
               != *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(host) + 0x14));
    }
    DAT_00d1f618 = 0;
  }

  ExceptionList = pvStack_14;
  // ret 4
}

extern "C" void FUN_00971480(void* host /*stack*/)
{
  AssPreloader_DrainSuccessResultsAndTally_Inferred(host);
}
