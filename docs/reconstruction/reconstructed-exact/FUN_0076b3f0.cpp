// =============================================================================
// FUN_0076b3f0  (Ghidra twin of Fs_ListDirBasenames_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0076b3f0
// Address:   0x0076b3f0–0x0076b54e  (autoassault.exe, image base 0x400000)
// System:    filesystem / directory enumeration
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W33-C)
// Exactness: Behavior-preserving rewrite of decompiler + body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
// See Fs_ListDirBasenames_Inferred.cpp for named clean + full plate.
// ABI: cdecl (path, out_string_vec*) — second formal recovered from bytes/callers.
// =============================================================================

extern "C" void Fs_ListDirBasenames_Inferred(const char* path, void* out_string_vec);

extern "C" void FUN_0076b3f0(const char* path, void* out_string_vec)
{
  Fs_ListDirBasenames_Inferred(path, out_string_vec);
}
