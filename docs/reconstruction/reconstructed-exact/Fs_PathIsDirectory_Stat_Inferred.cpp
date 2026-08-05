// =============================================================================
// Fs_PathIsDirectory_Stat_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0076adc0
// Address:   0x0076adc0–0x0076ae35  (autoassault.exe, image base 0x400000)
// System:    filesystem / path probe
// Generated: 2026-07-23 scaffold as FUN_0076adc0; dual A/B seal 2026-07-29 (W33-C)
// Exactness: Behavior-preserving rewrite of decompiler + body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Return whether `path` names an existing directory. Copies path to a 260-byte
//   stack buffer, strips one trailing '\\' or '/', calls CRT stat, and tests the
//   S_IFDIR bit (mode >> 14) & 1. Stat failure → false (XOR AL,AL).
//
// ABI (bytes):
//   cdecl 1 formal; bare RET; frame SUB ESP,0x128.
//   Body 118 B (0x76); pad CC after final RET.
//
// CALLERS (high-mention nested):
//   FUN_0076b3f0 (W33-C peer list-dir), FUN_009839b0 (W32-D recurse),
//   FUN_0076ba10, FUN_0076bc00, FUN_0076bc80, FUN_007a13e0, FUN_007b75b0,
//   FUN_00984340
//
// BYTES WIN:
//   Fail path is XOR AL,AL (not "uVar4 & 0xffffff00").
//   st_mode load is [stat_buf+6] (MSVC _stat layout).
//

#include <cstdint>
#include <cstring>

// Retail CRT import via IAT 0x009c6504 (Ghidra names it `stat`)
extern "C" int stat(const char* path, void* stat_buf);

// MSVC x86 _stat: st_mode is unsigned short at offset +6
struct RetailStatBuf {
  uint8_t  raw[0x24];  // sized to cover retail CRT layout used by this unit
};

// Retail: cdecl (path) → 0 / 1 in EAX (bool in AL)
extern "C" uint32_t Fs_PathIsDirectory_Stat_Inferred(const char* path)
{
  char path_copy[260];
  // retail: byte-copy loop until NUL (includes terminator)
  {
    const char* src = path;
    char* dst = path_copy;
    char c;
    do {
      c = *src++;
      *dst++ = c;
    } while (c != '\0');
  }

  // strip one trailing path separator
  {
    char* p = path_copy;
    while (*p != '\0') {
      ++p;
    }
    if (p != path_copy) {
      char* last = p - 1;
      if (*last == '\\' || *last == '/') {
        *last = '\0';
      }
    }
  }

  RetailStatBuf st{};
  int rc = stat(path_copy, &st);
  if (rc != 0) {
    // bytes: XOR AL,AL then ADD ESP,0x128; RET
    return 0;
  }

  // bytes: MOV EAX, dword [stat_buf+6]; SHR 14; AND 1
  uint32_t mode_dword = *reinterpret_cast<uint32_t*>(
      reinterpret_cast<uint8_t*>(&st) + 6);
  return (mode_dword >> 14) & 1u;
}

// Ghidra twin symbol
extern "C" uint32_t FUN_0076adc0(const char* path)
{
  return Fs_PathIsDirectory_Stat_Inferred(path);
}
