// =============================================================================
// Fs_CreateDirectoryForce_Inferred  (Ghidra: FUN_0076bc00)
// -----------------------------------------------------------------------------
// Stable ID: aa_0076bc00
// Address:   0x0076bc00  (autoassault.exe, image base 0x400000)
// System:    filesystem / directory create with optional force clear
// Generated: 2026-08-04 W37-Z dual A/B
// Exactness: Behavior-preserving rewrite of decompiler CF + byte ABI.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   CreateDirectoryA wrapper. When force_clear != 0:
//     - if path is a directory: recursive force wipe (FUN_0076ba10), recreate
//     - else if path is a regular file (_S_IFREG): force unlink (FUN_0076b080)
//   Always ends with CreateDirectoryA(path, NULL); returns BOOL success as bool.
//
// PEERS (sealed elsewhere):
//   FUN_0076adc0 Fs_PathIsDirectory_Stat (W33-C)
//   FUN_0076ba10 Fs_DeleteDirTreeRecursive (W34-A)
//   FUN_0076b080 force file unlink (ESI=path) — not dual-owned here
//
// CALLERS:
//   FUN_004b52e0, FUN_0076bc80, FUN_007a13e0, FUN_00985010 (CompactPackFile)
//
// BODY: 0x0076bc00–0x0076bc79 exclusive (121 B). Dual: accept.
// =============================================================================

#include <cstdint>
#include <windows.h>

// CRT _stat mode bit: regular file
#ifndef _S_IFREG
#define _S_IFREG 0x8000
#endif

extern "C" char __cdecl FUN_0076adc0(const char* path);          // is directory
extern "C" void __cdecl FUN_0076ba10(const char* path, char force); // wipe tree
// Force unlink: stack force flag; path in ESI (peer convention).
extern "C" void FUN_0076b080(char force);
extern "C" int __cdecl stat(const char* path, void* buf);

extern "C" bool __cdecl Fs_CreateDirectoryForce_Inferred(const char* path,
                                                         char force_clear)
{
  // local_24[0x24] frame; st_mode at +6 within CRT _stat buffer
  uint8_t stbuf[0x24];

  if (force_clear != 0) {
    if (FUN_0076adc0(path) != 0) {
      FUN_0076ba10(path, 1);
      return CreateDirectoryA(path, nullptr) != 0;
    }
    if (stat(path, stbuf) == 0) {
      // Bytes: MOV ECX, [esp+0x0A]; SHR ECX, 0xF; AND CL, 1
      uint16_t st_mode = *reinterpret_cast<uint16_t*>(stbuf + 6);
      if ((st_mode & _S_IFREG) != 0) {
        // ESI must hold path when calling FUN_0076b080 (not a formal).
        FUN_0076b080(1);
      }
    }
  }

  return CreateDirectoryA(path, nullptr) != 0;
}

extern "C" bool __cdecl FUN_0076bc00(const char* path, char force_clear)
{
  return Fs_CreateDirectoryForce_Inferred(path, force_clear);
}
