// =============================================================================
// Fs_ListDirBasenames_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0076b3f0
// Address:   0x0076b3f0–0x0076b54e  (autoassault.exe, image base 0x400000)
// System:    filesystem / directory enumeration
// Generated: 2026-07-23 scaffold as FUN_0076b3f0; dual A/B seal 2026-07-29 (W33-C)
// Exactness: Behavior-preserving rewrite of decompiler + body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Enumerate directory (or single path/pattern) entries via FindFirstFileA /
//   FindNextFileA and push each basename (except "." / "..") onto a caller
//   std::string vector via thiscall FUN_004301f0. If path is a directory
//   (FUN_0076adc0), append "/*" before FindFirst.
//
// ABI (bytes):
//   cdecl 2 formals: const char* path, void* out_string_vec.
//   Bare RET after SEH unlink + ADD ESP,0x184.
//   Body 351 B (0x15F); SEH LAB_009acd96.
//
// BYTES WIN:
//   Decompiler shows only path; second formal (out vector) is real — used as
//   ECX for FUN_004301f0. Callers: FUN_0076ba10(path, local_vec),
//   Fs_DirRecurseCollectLeafPaths (W32-D).
//
// CALLERS:
//   FUN_0076ba10, FUN_009698a0, FUN_009839b0, FUN_00984340
//
// NOTE:
//   Pushes basenames only. Full-path join is the caller's job (e.g. 009839b0
//   joins with "/"). String element stride at consumers: 0x1c.
//

#include <cstdint>
#include <string>
#include <windows.h>

extern "C" uint32_t FUN_0076adc0(const char* path);  // Fs_PathIsDirectory_Stat_Inferred
extern "C" void __thiscall FUN_004301f0(void* this_vec, void* string_elem);

// MSVC8-ish std::string object size used by listing consumers
static constexpr uint32_t kStringStride = 0x1c;

// Retail: cdecl (path, out_vec*) → void
extern "C" void Fs_ListDirBasenames_Inferred(const char* path, void* out_string_vec)
{
  // SEH frame LAB_009acd96; SUB ESP,0x178 (+ SEH pushes)
  std::string pattern(path);

  if (FUN_0076adc0(path) != 0) {
    pattern += "/*";  // retail DAT_00a9d210
  }

  WIN32_FIND_DATAA fd{};
  HANDLE h = FindFirstFileA(pattern.c_str(), &fd);
  if (h == INVALID_HANDLE_VALUE) {
    return;
  }

  do {
    // retail: REPE CMPSB exact match including NUL (len 2 = "."; len 3 = "..")
    const char* name = fd.cFileName;
    bool is_dot =
        name[0] == '.' && name[1] == '\0';
    bool is_dotdot =
        name[0] == '.' && name[1] == '.' && name[2] == '\0';
    if (!is_dot && !is_dotdot) {
      std::string entry(name);
      // bytes: MOV ECX, out_string_vec; push &entry; CALL FUN_004301f0
      FUN_004301f0(out_string_vec, &entry);
    }
  } while (FindNextFileA(h, &fd) != 0);

  FindClose(h);
  (void)kStringStride;  // documented for consumers; not used in this body
}

// Ghidra twin symbol
extern "C" void FUN_0076b3f0(const char* path, void* out_string_vec)
{
  Fs_ListDirBasenames_Inferred(path, out_string_vec);
}
