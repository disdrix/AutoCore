// =============================================================================
// AssPackManager_AddOrReplaceFileInPack_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00984910
// Address:   0x00984910–0x00984c65  (autoassault.exe, image base 0x400000)
// System:    palantir assets / assPackManager
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W33-Q)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - Plate: assPackManager.cpp:0x128/0x163/0x166 —
 *   "Not replacing %s." / "Error: Unable to open file <%s>" / "Added file %s"
 * - Retail ABI: ECX=srcPath, five stack formals, RET 0x14.
 * - Optional CS at host+0x38 gated by char host+0x50.
 * - Skip-if-same when forceReplace==0 and mtime/size/typeId match existing entry.
 * - Else replace-prep (FUN_009847c0), open-read file, compress/hash into pack node, insert.
 * - Callers: FUN_00984c70 (dir bulk add), AssPackManager_CompactPackFile_Inferred.
 * - Reject inventing product demangle; _Inferred from plate path + CF only.
 */

#include <cstdint>
#include <sys/stat.h>
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
  uint32_t mtimeMask;  // +0x0c
  // ...
  int16_t typeId;      // +0x14
};

// Unowned nested
extern "C" void FUN_00719630();
extern "C" PackEntryNode* FUN_009835f0(/* lookup */);
extern "C" void FUN_009847c0(uint32_t cookie); // replace/remove prep
extern "C" int FUN_007669d0(const char* path, int mode, int z); // mode 1 = read
extern "C" int FUN_00766840(void* buf, DWORD size);
extern "C" void* FUN_009834f0(); // alloc entry node
extern "C" int FUN_0071aaf0(DWORD rawSize); // compressed size estimate
extern "C" int FUN_0071ad70(int typeId, int* inoutSize);
extern "C" int FUN_007199e0(void* nameOut, void* compBuf, int compSize, void* meta);
extern "C" uint32_t FUN_0076ad70(); // stamp
extern "C" int FUN_0076ad40(const char* path); // file size helper
extern "C" void FUN_00989e00(void* a, void* name);
extern "C" void FUN_00469910(void* a, void* entryBlob); // insert into host table
extern "C" void FUN_00766750();
extern "C" void* operator_new[](uint32_t);
extern "C" void operator_delete[](void*);
extern "C" uint32_t FUN_0076cec0(void* buf, const char* fmt, ...);
extern "C" void vog_LogMessage(const char* file, int line, int level, uint32_t msg);

// Retail: ECX=srcPath, stack host/typeId/force/arg4/cookie, RET 0x14
extern "C" int AssPackManager_AddOrReplaceFileInPack_Inferred(
    const char* srcPath /*ECX*/,
    AssPackHost* host /*stack0*/,
    int typeId /*stack1*/,
    char forceReplace /*stack2*/,
    uint32_t arg4 /*stack3*/,
    uint32_t replaceCookie /*stack4*/)
{
  CRITICAL_SECTION* cs = reinterpret_cast<CRITICAL_SECTION*>(
      reinterpret_cast<uint8_t*>(host) + 0x38);
  char* lockEn = reinterpret_cast<char*>(reinterpret_cast<uint8_t*>(host) + 0x50);

  if (*lockEn != 0) {
    EnterCriticalSection(cs);
  }

  FUN_00719630();
  PackEntryNode* existing = FUN_009835f0();
  int rc = 0;

  if (existing != nullptr) {
    if (forceReplace == 0) {
      struct stat st{};
      int stRc = stat(srcPath, &st);
      // decompiler: (~-(stRc!=0) & st_mtime_field) == existing->mtimeMask
      uint32_t mtimeField = 0;
      // exact stat field offset sealed as local_118 in decompiler (MSVC stat layout)
      if (stRc == 0) {
        mtimeField = static_cast<uint32_t>(st.st_mtime);
      }
      int fileSize = FUN_0076ad40(srcPath);
      int16_t entryType =
          *reinterpret_cast<int16_t*>(reinterpret_cast<uint8_t*>(existing) + 0x14);
      int32_t entrySize =
          *reinterpret_cast<int32_t*>(reinterpret_cast<uint8_t*>(existing) + 0x08);
      uint32_t entryMtime =
          *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(existing) + 0x0c);

      if (mtimeField == entryMtime && fileSize == entrySize && typeId == entryType) {
        // log :0x128 "Not replacing %s." level 1
        if (*lockEn != 0) {
          LeaveCriticalSection(cs);
        }
        return 1;
      }
    }
    FUN_009847c0(replaceCookie);
  }

  // Local file object (vtbl PTR_FUN_00a9d84c); open-read path mode 1
  rc = FUN_007669d0(srcPath, 1, 0);
  if (rc < 0) {
    // log :0x163 "Error: Unable to open file <%s>" level 3
    rc = -1;
  } else {
    DWORD fileSize = 0;
    // GetFileSize from open handle held in file object
    void* raw = operator_new[](fileSize);
    if (raw == nullptr || FUN_00766840(raw, fileSize) < 0 || FUN_009834f0() == nullptr) {
      rc = -1;
      operator_delete[](raw);
    } else {
      int compCap = FUN_0071aaf0(fileSize);
      void* comp = operator_new[](static_cast<uint32_t>(compCap) + 1);
      rc = FUN_0071ad70(typeId, &compCap);
      if (rc >= 0) {
        uint8_t nameBuf[260]{};
        uint32_t meta[4]{};
        rc = FUN_007199e0(nameBuf, comp, compCap, meta);
        // meta: type i16, raw size, stamp FUN_0076ad70
        meta[2] = fileSize;
        meta[3] = FUN_0076ad70();
        // FUN_00989e00 + 7-dword pod copy + FUN_00469910 insert (bytes)
        FUN_00989e00(nullptr, nameBuf);
        FUN_00469910(nullptr, nullptr);
      }
      operator_delete[](comp);
      operator_delete[](raw);
    }
  }

  // log :0x166 "Added file %s" (name from compress path)
  // close file object if open; FUN_00766750
  FUN_00766750();

  if (*lockEn != 0) {
    LeaveCriticalSection(cs);
  }
  return rc;
}

// Scaffold twin symbol
extern "C" int FUN_00984910(
    const char* srcPath,
    AssPackHost* host,
    int typeId,
    char forceReplace,
    uint32_t arg4,
    uint32_t replaceCookie)
{
  return AssPackManager_AddOrReplaceFileInPack_Inferred(
      srcPath, host, typeId, forceReplace, arg4, replaceCookie);
}
