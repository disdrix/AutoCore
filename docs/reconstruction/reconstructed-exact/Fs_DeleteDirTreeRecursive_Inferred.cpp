// =============================================================================
// Fs_DeleteDirTreeRecursive_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0076ba10
// Address:   0x0076ba10–0x0076bbff  (autoassault.exe, image base 0x400000)
// System:    filesystem / recursive directory delete
// Generated: 2026-07-23 scaffold as FUN_0076ba10; dual A/B seal 2026-07-29 (W34-A)
// Exactness: Behavior-preserving rewrite of decompiler + prologue/epilogue bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Recursively delete a directory tree when recursive_force != 0: list basenames
//   (FUN_0076b3f0), join path+"/"+name, recurse into directories, force-unlink
//   files via FUN_0076b080 (ESI=path), then _rmdir root. When recursive_force==0,
//   only _rmdir(path) (no content walk). Delete failures printf+continue.
//
// ABI (bytes):
//   cdecl 2 formals: const char* path, char recursive_force.
//   SEH LAB_009adcab; ADD ESP,0x70; bare RET.
//   Body 495 B (0x1EF). Returns bool (AL) from final _rmdir == 0.
//
// PLATES:
//   "Delete file failed for: %s %d\n"      — uses basename on file fail
//   "Delete directory failed for: %s %d\n" — uses full joined path on dir fail
//
// CONSTANTS:
//   DAT_00a2eb5c = "/"
//   string stride 0x1c; SSO cap threshold 0x10
//
// CALLERS:
//   self; FUN_0076bc00; FUN_007b75b0; FUN_00985010 (CompactPackFile)
//

#include <cstdint>
#include <cstdio>
#include <string>

// Peers (owned other waves / CRT)
extern "C" void FUN_0076b3f0(const char* path, void* out_string_vec);  // Fs_ListDirBasenames_Inferred
extern "C" char FUN_0076adc0(const char* path);                       // Fs_PathIsDirectory_Stat_Inferred
// force flag + ESI=path (Ghidra shows only flag formal)
extern "C" bool FUN_0076b080(char force_writable_unlink /* ESI path */);
extern "C" void* FUN_00416490(void* out_string, void* lhs_string, const char* cstr);
extern "C" void FUN_00431ae0(/* ECX = vector* */);
extern "C" int _rmdir(const char* path);
extern "C" int* _errno(void);

// Retail: cdecl (path, recursive_force) → bool
extern "C" bool Fs_DeleteDirTreeRecursive_Inferred(const char* path, char recursive_force)
{
  // SEH frame LAB_009adcab; SUB ESP,0x64 (+ SEH)

  if (recursive_force == 0) {
    return _rmdir(path) == 0;
  }

  // MSVC vector<string>: begin/end/cap (decompiler locals local_6c/local_68/local_64)
  // Represented here as std::vector for clarity; retail uses raw 3-pointer vector.
  struct StringVec {
    std::string* begin;
    std::string* end;
    std::string* cap;
  } listing{};
  listing.begin = listing.end = listing.cap = nullptr;

  FUN_0076b3f0(path, &listing);

  // Iterate [begin, end) stride sizeof(std::string) == 0x1c on MSVC8 retail
  for (std::string* it = listing.begin; it != listing.end; ++it) {
    // full = path + "/" + *it
    std::string full = std::string(path);
    full += "/";           // DAT_00a2eb5c
    full += it->c_str();

    if (FUN_0076adc0(full.c_str()) != 0) {
      if (!Fs_DeleteDirTreeRecursive_Inferred(full.c_str(), recursive_force)) {
        std::printf("Delete directory failed for: %s %d\n", full.c_str(), *_errno());
      }
    } else {
      // retail: ESI = full.c_str(); CALL FUN_0076b080(recursive_force)
      // Optional chmod(S_IREAD|S_IWRITE) when force!=0 then _unlink
      bool ok = FUN_0076b080(recursive_force);
      if (!ok) {
        // plate uses basename (vector element), not full path
        std::printf("Delete file failed for: %s %d\n", it->c_str(), *_errno());
      }
    }
  }

  int rc = _rmdir(path);
  // FUN_00431ae0: destroy [begin,end) strings + operator_delete(begin)
  FUN_00431ae0();
  (void)listing;
  return rc == 0;
}

// Ghidra twin symbol
extern "C" bool FUN_0076ba10(const char* path, char recursive_force)
{
  return Fs_DeleteDirTreeRecursive_Inferred(path, recursive_force);
}
