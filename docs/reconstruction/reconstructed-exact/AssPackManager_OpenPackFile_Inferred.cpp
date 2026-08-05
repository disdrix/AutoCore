// =============================================================================
// AssPackManager_OpenPackFile_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00984ee0
// Address:   0x00984ee0–0x00985006  (autoassault.exe, image base 0x400000)
// System:    palantir assets / assPackManager
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W31-H)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - Plate: assPackManager.cpp:0x75/0x7b/0x80 — Opening / FAILED / SUCCESS pack file.
 * - Retail ABI: EBX=AssPackManager*, ECX=const char* path, stack char flag, RET 4.
 * - Optional CS at this+0x38 gated by char this+0x50.
 * - Allocates 0x44 pack object (FUN_00719970), opens via FUN_0071a9d0, pushes into
 *   vector at this+0x28 (FUN_004406e0). Does not free pack on fail (caller residual).
 * - Callers: AssManager_InitPrecompileAndResolvers batch (W30-D), compact path 00985010.
 * - Reject inventing product demangle; _Inferred from plate path + CF only.
 */

#include <cstdint>
#include <windows.h>

struct AssPackManager {
  // ...
  // +0x28: vector of pack* (push-back helper FUN_004406e0, EAX=vector)
  uint8_t pad_00[0x28];
  void* vec_begin;   // +0x28 family (exact subfields owned by FUN_004406e0)
  void* vec_end;     // +0x2c
  void* vec_cap;     // +0x30
  // ...
  CRITICAL_SECTION cs; // +0x38
  // ...
  char lockEnable;     // +0x50
};

// Unowned nested
extern "C" void* operator_new(uint32_t);
extern "C" void* FUN_00719970(void* mem, char flag); // 0x44 pack ctor
extern "C" int FUN_0071a9d0(/*EAX path, EDI pack*/); // open; returns <0 fail
extern "C" void FUN_004406e0(/*EAX vec@+0x28, ESI &pack**/);
extern "C" uint32_t FUN_0076cec0(void* buf, const char* fmt, ...);
extern "C" void vog_LogMessage(const char* file, int line, int level, uint32_t msg);

// Retail: EBX=this, ECX=path, stack flag, RET 4
extern "C" int AssPackManager_OpenPackFile_Inferred(
    const char* path /*ECX*/,
    char flag /*stack*/,
    AssPackManager* self /*EBX*/)
{
  CRITICAL_SECTION* cs = reinterpret_cast<CRITICAL_SECTION*>(
      reinterpret_cast<uint8_t*>(self) + 0x38);
  char* lockEn = reinterpret_cast<char*>(reinterpret_cast<uint8_t*>(self) + 0x50);

  if (*lockEn != 0) {
    EnterCriticalSection(cs);
  }

  // log Opening pack file %s
  void* pack = operator_new(0x44);
  void* packObj = nullptr;
  if (pack != nullptr) {
    packObj = FUN_00719970(pack, flag);
  }

  // open (bytes: EAX=path from ESI=ECX; EDI=packObj)
  int rc = FUN_0071a9d0(); // nested; path/pack in regs
  if (rc < 0) {
    // log FAILED
    if (*lockEn != 0) {
      LeaveCriticalSection(cs);
    }
    return -1;
  }

  // log SUCCESS; push packObj* into vector at self+0x28
  void* vec = reinterpret_cast<uint8_t*>(self) + 0x28;
  FUN_004406e0(); // EAX=vec, ESI=&packObj (bytes)

  if (*lockEn != 0) {
    LeaveCriticalSection(cs);
  }
  return 0;
}
