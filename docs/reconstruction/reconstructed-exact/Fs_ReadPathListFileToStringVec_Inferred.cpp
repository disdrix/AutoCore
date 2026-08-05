// =============================================================================
// Fs_ReadPathListFileToStringVec_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_009841d0
// Address:   0x009841d0 – 0x00984335 exclusive (357 B / 0x165)
// Module:    autoassault.exe (image base 0x400000)
// System:    filesystem / path-list text reader (stoFileOSFile)
// Wave:      W34-I OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================

// Ghidra: FUN_009841d0
// Preferred: Fs_ReadPathListFileToStringVec_Inferred
//
// cdecl; bare RET; returns out_string_vec* in EAX.
// Sole caller: Fs_ExpandPathSpecToStringVec_Inferred @-list branch (path+1).

#include <cstdint>

struct StringVecShell;   // begin/end/cap; elem basic_string stride 0x1c
struct StoFileOSFile;    // vtable 0x00a9d84c
struct BasicString;      // MSVC basic_string<char> size 0x1c

extern "C" int     FUN_007669d0(StoFileOSFile* self, const char* path, int mode, unsigned flags);
extern "C" int     FUN_00766ee0(/* ESI=file, EDI=line via regs */);
extern "C" unsigned FUN_007667f0(StoFileOSFile* self); // Tell
extern "C" void    FUN_00766750(StoFileOSFile* self);  // dtor/close
extern "C" void    FUN_004301f0(StringVecShell* self, const BasicString* value); // StringVec_PushBack
extern "C" void*   FUN_00469d10(StringVecShell* src, StringVecShell* dst);       // assign
extern "C" void    FUN_00431ae0(StringVecShell* self); // StringVec_Tidy

// Clean contract (control flow sealed; nested stoFile plates residual):
//
// void* Fs_ReadPathListFileToStringVec_Inferred(void* out_string_vec, const char* path)
// {
//   StoFileOSFile file; StringVecShell collector; // stack
//   if (stoFile_Open(&file, path, mode=1, flags=0) < 0) {
//     assign empty collector -> out; dtor file; tidy collector; return out;
//   }
//   BasicString line;
//   while (Tell(&file) < Size(&file)) {
//     ReadLine(&file, &line);          // CRLF-aware
//     StringVec_PushBack(&collector, &line);
//   }
//   assign collector -> out; ~line; dtor file; tidy collector; return out;
// }

extern "C" void* Fs_ReadPathListFileToStringVec_Inferred(void* out_string_vec, const char* path);
// Twin symbol kept for inventory: FUN_009841d0
