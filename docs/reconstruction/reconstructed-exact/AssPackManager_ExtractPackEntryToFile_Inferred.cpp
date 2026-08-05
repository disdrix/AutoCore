// =============================================================================
// AssPackManager_ExtractPackEntryToFile_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00984d30
// Address:   0x00984d30–0x00984ed4  (autoassault.exe, image base 0x400000)
// System:    palantir assets / assPackManager
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W33-Q)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - Plate: assPackManager.cpp:0x20f — "<%s> couldnt be found!"
 * - Retail ABI: ECX=outPath (nullable), stack host + entryName + spill, RET 0x0C.
 * - Optional CS at host+0x38 gated by char host+0x50.
 * - Lookup entry by name; stream-read packed bytes; write to out path (mode 6).
 * - Path fallback: outPath → entry+0x10 → empty string (PTR_DAT_00afa2bc → DAT_00a1419b).
 * - Sole static caller: AssPackManager_CompactPackFile_Inferred (W32-E).
 * - Reject inventing product demangle; _Inferred from plate path + CF only.
 */

#include <cstdint>
#include <windows.h>

struct AssPackHost {
  // ...
  CRITICAL_SECTION cs; // +0x38
  // ...
  char lockEnable;     // +0x50
};

struct PackEntryNode {
  // ...
  int32_t size;        // +0x08
  // uint32_t mtime;   // +0x0c (used by add path, not this unit)
  const char* defPath; // +0x10
  // ...
};

// Unowned nested
extern "C" PackEntryNode* FUN_009835f0(/*EAX host, ECX name*/);
extern "C" void* FUN_00983d40(AssPackHost* host); // stream factory
extern "C" void* operator_new[](uint32_t);
extern "C" void operator_delete[](void*);
extern "C" void FUN_0076bd90(int);
extern "C" int FUN_007669d0(const char* path, int mode, int z); // mode 6 = write
extern "C" void FUN_00766750();
extern "C" uint32_t FUN_0076cec0(void* buf, const char* fmt, ...);
extern "C" void vog_LogMessage(const char* file, int line, int level, uint32_t msg);
extern "C" char (*PTR_FUN_00a9d86c)(); // close-gate predicate
extern "C" const char* PTR_DAT_00afa2bc; // → empty ""

// Retail: ECX=outPath, stack host/name/spill, RET 0x0C
extern "C" int AssPackManager_ExtractPackEntryToFile_Inferred(
    const char* outPath /*ECX*/,
    AssPackHost* host /*stack0*/,
    const char* entryName /*stack1*/,
    uint32_t /*stack2 spill — sole caller pushes empty; fail reuses slot as fmt buf*/)
{
  CRITICAL_SECTION* cs = reinterpret_cast<CRITICAL_SECTION*>(
      reinterpret_cast<uint8_t*>(host) + 0x38);
  char* lockEn = reinterpret_cast<char*>(reinterpret_cast<uint8_t*>(host) + 0x50);

  if (*lockEn != 0) {
    EnterCriticalSection(cs);
  }

  PackEntryNode* entry = FUN_009835f0(); // EAX=host, ECX=entryName (bytes)
  if (entry == nullptr) {
    // log :0x20f "<%s> couldnt be found!" level 3
    if (*lockEn != 0) {
      LeaveCriticalSection(cs);
    }
    return -1;
  }

  void* stream = FUN_00983d40(host);
  int32_t size = *reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(entry) + 0x08);
  void* buf = operator_new[](static_cast<uint32_t>(size) + 1);
  // stream->vtbl[0x14/4](buf, size)
  (**reinterpret_cast<void (***)(void*, int32_t)>(
      *reinterpret_cast<void***>(stream) + (0x14 / 4)))(buf, size);

  const char* path = outPath;
  if (path == nullptr) {
    path = *reinterpret_cast<const char**>(reinterpret_cast<uint8_t*>(entry) + 0x10);
    if (path == nullptr) {
      path = PTR_DAT_00afa2bc; // empty
    }
  }

  FUN_0076bd90(1);
  FUN_007669d0(path, 6, 0);
  // WriteFile via open handle held in file object (decompiler shows -1 placeholder)
  WriteFile(INVALID_HANDLE_VALUE, buf, static_cast<DWORD>(size), nullptr, nullptr);

  if (PTR_FUN_00a9d86c != nullptr && PTR_FUN_00a9d86c() != 0) {
    CloseHandle(INVALID_HANDLE_VALUE);
  }

  operator_delete[](buf);
  // stream scalar-deleting dtor vtbl[0](1)
  (**reinterpret_cast<void (***)(int)>(*reinterpret_cast<void***>(stream)))(1);
  FUN_00766750();

  if (*lockEn != 0) {
    LeaveCriticalSection(cs);
  }
  return 0;
}

// Scaffold twin symbol
extern "C" int FUN_00984d30(
    const char* outPath,
    AssPackHost* host,
    const char* entryName,
    uint32_t spill)
{
  return AssPackManager_ExtractPackEntryToFile_Inferred(outPath, host, entryName, spill);
}
