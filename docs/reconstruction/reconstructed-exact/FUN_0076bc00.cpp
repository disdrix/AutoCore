// =============================================================================
// FUN_0076bc00  — clean twin of Fs_CreateDirectoryForce_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0076bc00
// Address:   0x0076bc00  (autoassault.exe, image base 0x400000)
// W37-Z:     2026-08-04 — see Fs_CreateDirectoryForce_Inferred.cpp
// =============================================================================

#include <cstdint>
#include <windows.h>

#ifndef _S_IFREG
#define _S_IFREG 0x8000
#endif

extern "C" char __cdecl FUN_0076adc0(const char* path);
extern "C" void __cdecl FUN_0076ba10(const char* path, char force);
extern "C" void FUN_0076b080(char force); // ESI=path
extern "C" int __cdecl stat(const char* path, void* buf);

// cdecl; path + force_clear; bool AL; ADD ESP,0x24; RET
extern "C" bool __cdecl FUN_0076bc00(const char* path, char force_clear)
{
  uint8_t stbuf[0x24];

  if (force_clear != 0) {
    if (FUN_0076adc0(path) != 0) {
      FUN_0076ba10(path, 1);
      return CreateDirectoryA(path, nullptr) != 0;
    }
    if (stat(path, stbuf) == 0) {
      uint16_t st_mode = *reinterpret_cast<uint16_t*>(stbuf + 6);
      if ((st_mode & static_cast<uint16_t>(_S_IFREG)) != 0) {
        FUN_0076b080(1);
      }
    }
  }

  return CreateDirectoryA(path, nullptr) != 0;
}
