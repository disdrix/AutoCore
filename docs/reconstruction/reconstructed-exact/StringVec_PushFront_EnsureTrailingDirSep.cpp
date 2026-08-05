// =============================================================================
// StringVec_PushFront_EnsureTrailingDirSep
// -----------------------------------------------------------------------------
// Stable ID: aa_00969830
// Address:   0x00969830–0x00969897 exclusive (103 B / 0x67, autoassault.exe base 0x400000)
// System:    assManager / StringVecShell path list (*DAT_00d1f1fc)
// Generated: 2026-07-29 W31-E dual A/B (decompile + read_memory + call-site bytes)
// Exactness: Behavior-preserving rewrite of CF + ABI. Nested helpers unowned.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_00969830
// =============================================================================
//
// PURPOSE:
//   Normalize a path string so it ends with a directory separator if needed
//   (FUN_009694e0: append '/' unless last is ':', '/', or '\\'), then insert
//   that string at the **front** of the global StringVecShell (*DAT_00d1f1fc).
//   Used by AssManager_InitPrecompileAndResolvers for precompile path + bag walk.
//
// ABI (bytes):
//   ESI = StringVecShell* (callers: mov esi, [DAT_00d1f1fc])
//   stack formal = const basic_string* (or string bag elem)
//   ret 4; void
//   SEH LAB_009acaf6; local basic_string 0x1c
//
// TWINS / CALLEES (not owned here):
//   FUN_009694e0  — ensure trailing dir sep / copy
//   FUN_00430310  — vector insert-at + return iterator (elem 0x1c)
//   FUN_004306b0  — vector insert N strings (grow path)
// =============================================================================

#include <cstdint>

struct StringVecShell {
  void* pad0;       // +0x00
  uint8_t* begin;   // +0x04  basic_string* as bytes
  uint8_t* end;     // +0x08
  // cap @ +0x0c used by insert grow (FUN_004306b0)
};

// Unowned callees
extern "C" void* FUN_009694e0(void* out_string, const void* in_string);
extern "C" void __thiscall FUN_00430310(StringVecShell* self,
                                        void* out_iterator,
                                        uint8_t* pos,
                                        void* value_string);
extern "C" void basic_string_dtor(void* self); // IAT ~basic_string

// Retail: ESI=this, stack path*; ret 4
extern "C" void StringVec_PushFront_EnsureTrailingDirSep(
    StringVecShell* self /*ESI*/,
    const void* path /*stack basic_string* */)
{
  alignas(4) uint8_t local[0x1c];
  // SEH + ExceptionList omitted (structure only)

  FUN_009694e0(local, path);

  void* out_it = nullptr;
  // Insert at begin (pos = self->begin)
  FUN_00430310(self, &out_it, self->begin, local);
  (void)out_it;

  basic_string_dtor(local);
}

// Scaffold alias
extern "C" void FUN_00969830(const void* path /*stack; ESI=self*/)
{
  // Port note: retail requires ESI preset to *DAT_00d1f1fc.
  (void)path;
}
