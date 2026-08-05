// =============================================================================
// FUN_0076ba10  (Ghidra twin of Fs_DeleteDirTreeRecursive_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0076ba10
// Address:   0x0076ba10–0x0076bbff  (autoassault.exe, image base 0x400000)
// System:    filesystem / recursive directory delete
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W34-A)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Recursive directory tree delete (see Fs_DeleteDirTreeRecursive_Inferred.cpp).
//   Plates: "Delete file failed for: %s %d\n" / "Delete directory failed for: %s %d\n".
//
// ABI: cdecl (const char* path, char recursive_force) → bool
// Body: 495 B; SEH LAB_009adcab; ADD ESP,0x70; RET
//

#include <cstdint>
#include <cstdio>
#include <string>

extern "C" void FUN_0076b3f0(const char* path, void* out_string_vec);
extern "C" char FUN_0076adc0(const char* path);
extern "C" bool FUN_0076b080(char force_flag /* ESI = path */);
extern "C" void FUN_00431ae0();
extern "C" int _rmdir(const char* path);
extern "C" int* _errno(void);

// Avoid bare undefined4 — fixed-width integers only.
extern "C" bool FUN_0076ba10(char* param_1, uint32_t param_2)
{
  const char recursive_force = static_cast<char>(param_2);

  if (recursive_force == '\0') {
    return _rmdir(param_1) == 0;
  }

  // vector begin/end/cap — decompiler local_6c / local_68 / local_64
  std::string* begin = nullptr;
  std::string* end = nullptr;
  std::string* cap = nullptr;
  (void)cap;

  // out vector object region fed to list helper
  void* listing = &begin;  // layout: begin @ +0 relative to local_70 region in retail
  FUN_0076b3f0(param_1, listing);

  // Retail iterates string objects of stride 0x1c
  for (std::string* it = begin; it != end; ++it) {
    std::string full(param_1);
    full += "/";  // DAT_00a2eb5c
    full += it->c_str();

    if (FUN_0076adc0(full.c_str()) == '\0') {
      if (!FUN_0076b080(recursive_force)) {
        std::printf("Delete file failed for: %s %d\n", it->c_str(), *_errno());
      }
    } else {
      if (!FUN_0076ba10(const_cast<char*>(full.c_str()), param_2)) {
        std::printf("Delete directory failed for: %s %d\n", full.c_str(), *_errno());
      }
    }
  }

  const int rc = _rmdir(param_1);
  FUN_00431ae0();
  return rc == 0;
}
