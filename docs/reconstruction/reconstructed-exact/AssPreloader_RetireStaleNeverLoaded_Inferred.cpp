// =============================================================================
// AssPreloader_RetireStaleNeverLoaded_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00970e50
// Address:   0x00970e50–0x00970fb8  (360 B / 0x168)
// Ghidra:    FUN_00970e50
// System:    assPreloader / asset preload pipeline
// Dual:      W33-O 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI:
//   stack = (AssPreloader* self, float maxAge); RET 8; void.
//
// Walk map at self+0x10 (end sentinel self+0x14). For each node:
//   if (now - node+0x14 stamp) <= maxAge → iterator++ only
//   else:
//     optional release *(node+0x10) via vtbl[0](1)
//     format assId from key@node+0xC (FUN_0096a630)
//     log assPreloader.cpp:0x2A8
//       "Preloaded asset <%s> never loaded. Retiring and removing."
//     push PodU32U8 into self+0xAC (locked stride-2)
//     iterator++; erase node via FUN_00447350(self+0x10)
//     retired++
// Tail log assPreloader.cpp:0x2B7 "Retired %d preload blocks from pool."
//
// Sole caller FUN_007b7000: self=*(DAT_00d1f050+0x6c), maxAge=300.0f.
// Name structural (_Inferred); product file+strings seal family.
// =============================================================================

#include <cstdint>

extern "C" float FUN_0076c330(void);
extern "C" void FUN_00457cc0(void* it /*site regs*/); // map iterator++
extern "C" void* FUN_0096a630(void* key /*this*/, void* string_out);
extern "C" void* FUN_0076cec0(void* /*...*/, const char* fmt, ...);
extern "C" void vog_LogMessage(const char* file, int line, int level, void* msg);
extern "C" void FUN_0043e8f0(void);
extern "C" void FUN_0043e7f0(void); // EDI=container
extern "C" void FUN_00447350(void* map /*self+0x10*/, void* node /*site*/);

static const char kPreloaderCpp[] =
    "C:\\vog\\1_code\\palantir\\palantir\\assets\\assPreloader.cpp";
static const char kNeverLoaded[] =
    "Preloaded asset <%s> never loaded. Retiring and removing.";
static const char kRetiredCount[] =
    "Retired %d preload blocks from pool.";

void AssPreloader_RetireStaleNeverLoaded_Inferred(void* self /*stack*/,
                                                   float maxAge /*stack*/)
{
  float now = FUN_0076c330();
  int retired = 0;

  auto* base = reinterpret_cast<uint8_t*>(self);
  // map end sentinel pointer lives at self+0x14
  int* end = *reinterpret_cast<int**>(base + 0x14);
  int* node = reinterpret_cast<int*>(*end);

  while (node != end) {
    float stamp = *reinterpret_cast<float*>(reinterpret_cast<uint8_t*>(node) + 0x14);
    if ((now - stamp) <= maxAge) {
      FUN_00457cc0(&node);
    } else {
      void** obj = *reinterpret_cast<void***>(reinterpret_cast<uint8_t*>(node) + 0x10);
      if (obj != nullptr) {
        auto** vtbl = reinterpret_cast<void***>(obj);
        using DtorFn = void (*)(void*, int);
        reinterpret_cast<DtorFn>((*vtbl)[0])(obj, 1);
      }

      // key @ node+0xC → assId string via FUN_0096a630; format via FUN_0076cec0
      void* msg = FUN_0076cec0(nullptr, kNeverLoaded /* + assId */);
      vog_LogMessage(kPreloaderCpp, 0x2A8, 2, msg);

      // EDI = self+0xAC
      FUN_0043e8f0();
      FUN_0043e7f0();

      FUN_00457cc0(&node);
      FUN_00447350(base + 0x10, node);
      ++retired;
    }
  }

  void* summary = FUN_0076cec0(nullptr, kRetiredCount, retired);
  vog_LogMessage(kPreloaderCpp, 0x2B7, 2, summary);
}
