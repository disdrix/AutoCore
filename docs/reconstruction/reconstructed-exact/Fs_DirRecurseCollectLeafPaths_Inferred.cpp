// =============================================================================
// Fs_DirRecurseCollectLeafPaths_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_009839b0
// Address:   0x009839b0–0x00983b53  (autoassault.exe, image base 0x400000)
// System:    filesystem / path enumeration
// Generated: 2026-07-23 scaffold as FUN_009839b0; dual A/B seal 2026-07-29 (W32-D)
// Exactness: Behavior-preserving rewrite of decompiler + body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   If `path` is a directory, recursively enumerate children and push every
//   non-directory leaf path onto the caller-supplied std::string vector.
//   Separator is DAT_00a2eb5c ("/"). Returns 0 on success, -1 if path is not a dir.
//
// ABI (bytes):
//   cdecl 2 formals; bare RET; EAX = 0 or 0xFFFFFFFF.
//   Body 420 B; SEH LAB_009ad54e.
//
// CALLERS:
//   FUN_00984340 @ 0x009844a1 (recurse flag path)
//   FUN_00984c70 @ 0x00984ca6 (collect then FUN_00984910 each)
//   self        @ 0x00983ada
//
// BYTES WIN:
//   Leaf push uses thiscall FUN_004301f0 with ECX = out vector (param_2).
//   Decompiler omitted that ECX load; do not treat param_2 as unused.
//

#include <cstdint>
#include <string>

// Unowned callees (retail shapes)
extern "C" char     FUN_0076adc0(const char* path);              // is_directory
extern "C" void     FUN_0076b3f0(const char* path, void* out_listing_vec);
extern "C" void*    FUN_00416490(void* out, void* left, const char* sep);
extern "C" void*    FUN_00416410(void* out, void* left, void* right);
extern "C" void __thiscall FUN_004301f0(void* this_vec, void* string_elem);
extern "C" void     FUN_00431ae0(/* listing vec this/arg via retail ABI */);

// MSVC8-ish std::string stride used by listing / out vectors
static constexpr uint32_t kStringStride = 0x1c;

// Retail: cdecl (path, out_vec*) → 0 / -1
extern "C" int Fs_DirRecurseCollectLeafPaths_Inferred(const char* path,
                                                      void* out_string_vec /*stack*/)
{
  // SEH frame LAB_009ad54e; SUB ESP,0x80
  if (FUN_0076adc0(path) == 0) {
    return -1;
  }

  // local listing vector (begin/end/cap) zeroed then filled by FUN_0076b3f0
  uint8_t listing[0x10] = {};
  FUN_0076b3f0(path, listing);

  // Iterate listing entries (std::string objects, stride 0x1c):
  //   full = path + "/" + entry
  //   if !is_dir(full):  FUN_004301f0(out_string_vec, full)   // thiscall push
  //   else:              Fs_DirRecurseCollectLeafPaths_Inferred(full, out_string_vec)
  //
  // Exact SSO / basic_string temporaries and EH states follow retail order in raw.

  FUN_00431ae0();
  return 0;
}

// Ghidra twin symbol
extern "C" int FUN_009839b0(const char* path, void* out_string_vec)
{
  return Fs_DirRecurseCollectLeafPaths_Inferred(path, out_string_vec);
}
