// =============================================================================
// Palantir_StartPreloadThread_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00754280
// Address:   0x00754280–0x007542e8  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_00754280
// System:    Palantir / thrThread preload
// Dual:      W31-F 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI: EDI = Palantir host; 0 stack formals; plain RET; AL = 0/1.
// If host+0xd4 already non-null: log "Preload thread already runnning." → AL=0.
// Else new thrThread(0x10), store at +0xd4, CreateThread via thrThread helper
// with stack size 0x40000, not suspended → AL=1.
// Name Inferred from Palantir.cpp plate + preload strings + thrThread create.
// =============================================================================

#include <cstdint>

struct ThrThread {
  void*    vftable;   // +0x00  PTR_FUN_00a9e9bc
  uint32_t threadId;  // +0x04  out from CreateThread
  void*    handle;    // +0x08  HANDLE
  void*    context;   // +0x0c  from DAT_00d1f050+0x6c
};

// External symbols (image)
extern void* DAT_00d1f050;
extern void* PTR_FUN_00a9e9bc;
extern void* operator_new(uint32_t size);
extern void  vog_LogMessage(const char* file, int line, int level, const char* msg);
// thrThread_Create: retail FUN_0071aef0 — ESI=this, EDX=stackSize, AL=createSuspended
extern uint32_t thrThread_Create(ThrThread* self /*ESI*/, uint32_t stackSize /*EDX*/,
                                 uint8_t createSuspended /*AL*/);

// Clean signature: host explicit (retail keeps it in EDI).
uint8_t Palantir_StartPreloadThread_Inferred(void* host /*EDI*/)
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
    // +0x0c ← *(DAT_00d1f050 + 0x6c)
    raw->context = *reinterpret_cast<void**>(static_cast<uint8_t*>(DAT_00d1f050) + 0x6c);
    thread = raw;
  }

  *reinterpret_cast<ThrThread**>(static_cast<uint8_t*>(host) + 0xd4) = thread;

  // EDX=0x40000, AL=0 (not CREATE_SUSPENDED); flags include 0x10000 reservation bit inside helper
  thrThread_Create(thread, 0x40000, 0);

  return 1;
}
