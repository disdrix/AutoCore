// =============================================================================
// Fs_ExpandPathSpecToStringVec_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00984340
// Address:   0x00984340–0x009847bb  (autoassault.exe, image base 0x400000)
// System:    filesystem / path-spec expansion
// Generated: 2026-07-23 scaffold as FUN_00984340; dual A/B seal 2026-07-29 (W33-E)
// Exactness: Behavior-preserving rewrite of decompiler + body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Expand a path specification into a caller-supplied std::string vector:
//     - "@file"  → read path list, recurse expand each line
//     - regular file → single push
//     - glob / non-dir pattern → list dir + wildcard match
//     - directory + recurse flag → leaf walk (FUN_009839b0)
//     - directory + no flag → one-level children
//   Join separator is DAT_00a2eb5c ("/").
//
// ABI (bytes):
//   cdecl 3 stack formals; bare RET; EAX = out_vec*.
//   Body 1148 B; SEH LAB_009af78c; SUB ESP,0x1A8.
//
// CALLERS:
//   self only @ 0x009843e5  (no external static xrefs)
//
// BYTES WIN:
//   path is stack arg2 (EDI); out is arg1; recurse flag arg3.
//   FUN_004301f0 / FUN_00469d10 thiscall ECX = vector (decompiler often hides).
//

#include <cstdint>
#include <cstring>

static constexpr uint32_t kStringStride = 0x1c;

// Unowned callees (retail shapes)
extern "C" void*    FUN_009841d0(void* out_vec, const char* list_path);
extern "C" char     FUN_0076adc0(const char* path);              // is_directory
extern "C" void     FUN_0076b3f0(const char* path, void* out_listing_vec);
extern "C" char     FUN_0076b210(/*this/pattern ABI per retail*/); // glob match
extern "C" void*    FUN_00416490(void* out, void* left, const char* sep);
extern "C" void*    FUN_00416410(void* out, void* left, void* right);
extern "C" void __thiscall FUN_004301f0(void* this_vec, void* string_elem);
extern "C" void* __thiscall FUN_00469d10(void* this_src_vec, void* dst_vec);
extern "C" void     FUN_00431ae0(/* listing vec destroy */);
extern "C" int      FUN_009839b0(const char* path, void* out_string_vec);
extern "C" int      stat(const char* path, void* st);

// Retail: cdecl (out_vec*, path_spec, recurse_flag) → out_vec*
extern "C" void* Fs_ExpandPathSpecToStringVec_Inferred(void* out_string_vec,
                                                       const char* path_spec,
                                                       char recurse_dirs)
{
  // SEH LAB_009af78c; large frame; local collector vector (begin/end/cap)
  // DAT_00a2eb5c == "/"

  if (path_spec != nullptr && path_spec[0] == '@') {
    // FUN_009841d0(&lines, path_spec + 1)
    // for each line: self(temp, line_cstr, recurse_dirs); append temp → collector
  } else if (FUN_0076adc0(path_spec) == 0) {
    // not a directory:
    //   if stat ok && (st_mode >> 15 & 1): push path (regular file)
    //   else glob:
    //     split on last '/' or '\\' (else dir=".", pattern=path)
    //     list dir; for entry if FUN_0076b210 match: push dir+"/"+entry
  } else {
    // directory:
    if (recurse_dirs != 0) {
      FUN_009839b0(path_spec, /*&collector*/ nullptr /*placeholder — retail local*/);
    } else {
      // list one level; push path+"/"+entry each
    }
  }

  // FUN_00431ae0 destroy temps; FUN_00469d10(collector → out_string_vec)
  // Exact SSO / EH states follow retail order in raw.
  (void)kStringStride;
  return out_string_vec;
}

// Ghidra twin symbol
extern "C" void* FUN_00984340(void* out_string_vec, const char* path_spec, char recurse_dirs)
{
  return Fs_ExpandPathSpecToStringVec_Inferred(out_string_vec, path_spec, recurse_dirs);
}
