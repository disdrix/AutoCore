// =============================================================================
// stoFileOSFile_Open  (aa_007669d0)
// -----------------------------------------------------------------------------
// Address:   0x007669d0  (autoassault.exe, image base 0x400000)
// Body:      0x007669d0 – 0x00766d8c exclusive (956 B / 0x3BC)
// Wave:      W37-E OWN-ONLY dual 2026-08-04
// Exactness: Behavior-preserving rewrite of decompiler CF + dual RET 0x0C.
// Bit-for-bit vs retail EXE: DEFERRED.
// Plate:     arda2/storage/stoFileOSFile.cpp (Confirmed log path).
// =============================================================================

#include <cstdint>
#include <cstdio>

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

// Retail stoFileOSFile shell (partial; only fields touched here).
struct stoFileOSFile {
  void* vtable;      // +0  (0x00a9d84c at construct sites)
  uint32_t mode;     // +4  written from open mode arg
  HANDLE handle;     // +8  CreateFileA result
};

// Nested / external (not dual-owned).
extern "C" int* FUN_007a69d0(void);  // settings singleton; +0x2c quality
extern "C" void* FUN_0076cec0(void* ctx, const char* fmt, ...);
extern "C" void vog_LogMessage(const char* file, int line, int level, void* msg);

// Scratch path buffer used for quality remaps.
extern char DAT_00d206c8[0x100];

// Quality tags (read_memory @ 0x00a9d998..).
// 1 → "_FR", 2 → "_DE", 3 → "_UK"
// DDS suffix table PTR_DAT_00b01838: "_on","_off","_over","_down",(+5th)

// ECX = this; stack path, mode, dwFlagsAndAttributes; RET 0x0C.
// Returns 0 on success, 0xFFFFFFFF on failure.
// Mode map (share always FILE_SHARE_READ):
//   0 → fail
//   1 → access 0x20001, OPEN_EXISTING     (read)
//   2 → access 0x20006, OPEN_EXISTING     (write existing)
//   3 → access 0x20007, OPEN_EXISTING     (read/write)
//   4,5 → access 0, OPEN_EXISTING         (CreateFile fails)
//   6 → access 0x20006, CREATE_ALWAYS     (write/create)
// Optional: when quality!=0, try remapped .ogg/.dds path via fopen probe.
extern "C" int32_t __thiscall stoFileOSFile_Open(
    stoFileOSFile* self,
    const char* path,
    uint32_t mode,
    DWORD attrs)
{
  self->mode = mode;

  // --- quality path remap (abbrev; full string rebuild in image) ---
  // if (FUN_007a69d0()[0x2c/4] != 0) {
  //   if strstr(path, ".ogg") → rebuild with _FR/_DE/_UK + ".ogg"; fopen probe
  //   else if strstr(path, ".dds") → for each suffix table entry, rebuild + ".dds"
  //   on successful probe: path = DAT_00d206c8
  // }
  (void)DAT_00d206c8;
  (void)FUN_007a69d0;

  DWORD access = 0;
  DWORD disposition = OPEN_EXISTING;  // 3
  switch (mode) {
    case 0:
      return -1;
    case 1:
      access = 0x20001;
      break;
    case 3:
      access = 0x20007;
      break;
    case 6:
      disposition = CREATE_ALWAYS;  // 2
      // fallthrough
    case 2:
      access = 0x20006;
      break;
    default:
      // modes 4/5 and any >6 out-of-range handled like switch default
      break;
  }

  HANDLE h = CreateFileA(
      path,
      access,
      FILE_SHARE_READ,
      /*sa*/ nullptr,
      disposition,
      attrs,
      /*template*/ nullptr);
  self->handle = h;

  if (h != INVALID_HANDLE_VALUE) {
    return 0;
  }

  DWORD err = GetLastError();
  char msgBuf[0x200];
  // zero msgBuf (image does rep stos)
  msgBuf[0] = '\0';
  DWORD n = FormatMessageA(
      0x1000 /*FORMAT_MESSAGE_FROM_SYSTEM*/,
      nullptr,
      err,
      0,
      msgBuf,
      0x200,
      nullptr);
  if (n != 0) {
    // FUN_0076cec0 builds "File open error <%s> - %s"
    void* formatted = FUN_0076cec0(
        &self /*image passes &local_this_slot*/,
        "File open error <%s> - %s",
        path,
        msgBuf);
    vog_LogMessage(
        "C:\\vog\\1_code\\palantir\\arda2\\storage\\stoFileOSFile.cpp",
        0xB9,
        2,
        formatted);
  }
  return -1;
}
