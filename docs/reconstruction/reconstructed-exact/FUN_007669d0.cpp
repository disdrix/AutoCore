// =============================================================================
// FUN_007669d0  — twin of stoFileOSFile_Open
// -----------------------------------------------------------------------------
// Address:   0x007669d0  (autoassault.exe, image base 0x400000)
// Body:      0x007669d0 – 0x00766d8c exclusive (956 B / 0x3BC)
// Wave:      W37-E OWN-ONLY dual 2026-08-04
// Canonical: stoFileOSFile_Open
// =============================================================================

#include <cstdint>
#include <windows.h>

struct stoFileOSFile {
  void* vtable;
  uint32_t mode;
  HANDLE handle;
};

extern "C" int* FUN_007a69d0(void);
extern "C" void* FUN_0076cec0(void* ctx, const char* fmt, ...);
extern "C" void vog_LogMessage(const char* file, int line, int level, void* msg);

// Full quality-remap body lives in stoFileOSFile_Open.cpp / image.
// This twin seals ABI + CreateFile mode matrix + fail log plate.
extern "C" int32_t __thiscall FUN_007669d0(
    stoFileOSFile* self,
    const char* path,
    uint32_t mode,
    DWORD attrs)
{
  self->mode = mode;
  (void)FUN_007a69d0;  // quality gate + .ogg/.dds remap when non-zero

  DWORD access = 0;
  DWORD disposition = OPEN_EXISTING;
  switch (mode) {
    case 0: return -1;
    case 1: access = 0x20001; break;
    case 3: access = 0x20007; break;
    case 6: disposition = CREATE_ALWAYS; // fallthrough
    case 2: access = 0x20006; break;
    default: break;
  }

  HANDLE h = CreateFileA(path, access, FILE_SHARE_READ, nullptr,
                         disposition, attrs, nullptr);
  self->handle = h;
  if (h != INVALID_HANDLE_VALUE) {
    return 0;
  }

  DWORD err = GetLastError();
  char msgBuf[0x200] = {};
  if (FormatMessageA(0x1000, nullptr, err, 0, msgBuf, 0x200, nullptr)) {
    void* formatted = FUN_0076cec0(self, "File open error <%s> - %s", path, msgBuf);
    vog_LogMessage(
        "C:\\vog\\1_code\\palantir\\arda2\\storage\\stoFileOSFile.cpp",
        0xB9, 2, formatted);
  }
  return -1;
}
