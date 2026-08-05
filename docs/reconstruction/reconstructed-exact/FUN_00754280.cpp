// =============================================================================
// FUN_00754280  (clean twin of Palantir_StartPreloadThread_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00754280
// Address:   0x00754280–0x007542e8  (autoassault.exe, image base 0x400000)
// Dual:      W31-F 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// =============================================================================

#include <cstdint>

struct ThrThread {
  void*    vftable;
  uint32_t threadId;
  void*    handle;
  void*    context;
};

extern void* DAT_00d1f050;
extern void* PTR_FUN_00a9e9bc;
extern void* operator_new(uint32_t size);
extern void  vog_LogMessage(const char* file, int line, int level, const char* msg);
extern uint32_t FUN_0071aef0(ThrThread* self /*ESI*/, uint32_t stackSize /*EDX*/,
                             uint8_t createSuspended /*AL*/);

// Retail: EDI=host; plain RET; AL return
uint8_t FUN_00754280(void* host /*EDI*/)
{
  ThrThread* thread = nullptr;

  if (*reinterpret_cast<ThrThread**>(static_cast<uint8_t*>(host) + 0xd4) != nullptr) {
    vog_LogMessage(
        "C:\\vog\\1_code\\palantir\\palantir\\framework\\Palantir.cpp",
        0x1fd,
        2,
        "Preload thread already runnning.");
    return 0;
  }

  auto* raw = static_cast<ThrThread*>(operator_new(0x10));
  if (raw != nullptr) {
    raw->vftable = &PTR_FUN_00a9e9bc;
    raw->threadId = 0;
    raw->handle = nullptr;
    raw->context = *reinterpret_cast<void**>(static_cast<uint8_t*>(DAT_00d1f050) + 0x6c);
    thread = raw;
  }

  *reinterpret_cast<ThrThread**>(static_cast<uint8_t*>(host) + 0xd4) = thread;
  FUN_0071aef0(thread, 0x40000, 0);
  return 1;
}
