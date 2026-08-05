// =============================================================================
// FUN_009841d0  (twin of Fs_ReadPathListFileToStringVec_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_009841d0
// Address:   0x009841d0 – 0x00984335 exclusive (357 B / 0x165)
// Module:    autoassault.exe (image base 0x400000)
// Wave:      W34-I OWN-ONLY dual 2026-07-29
// =============================================================================

// PURPOSE: Read a text path-list file (one path per line) into a string vector.
// Preferred name: Fs_ReadPathListFileToStringVec_Inferred
//
// ABI: cdecl (out_string_vec*, const char* path) → out_string_vec* (EAX); bare RET.
// Open via stoFileOSFile mode 1; fail returns empty assign; success line-loops
// (Tell < Size) with FUN_00766ee0 + StringVec_PushBack, then FUN_00469d10 assign.
// Sole caller: FUN_00984340 @ 0x00984395 (@-list expand).

#include <cstdint>

extern "C" void* FUN_009841d0(void* out_string_vec, const char* path);

// See Fs_ReadPathListFileToStringVec_Inferred.cpp for sealed contract notes.
// Authoritative CF: docs/reconstruction/raw/aa_009841d0_FUN_009841d0.md (W34-I append).
