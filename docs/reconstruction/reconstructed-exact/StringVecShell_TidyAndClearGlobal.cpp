// =============================================================================
// StringVecShell_TidyAndClearGlobal
// -----------------------------------------------------------------------------
// Stable ID: aa_00444810
// Address:   0x00444810–0x0044484A exclusive (58 B / 0x3A, autoassault.exe base 0x400000)
// System:    Palantir path-list StringVecShell tidy + clear DAT_00d1f1fc
// Generated: 2026-07-29 W34-K dual A/B (decompile + read_memory)
// Exactness: Behavior-preserving CF + ABI. Bytes + SEH sites win over decompiler void.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_00444810
// =============================================================================
//
// PURPOSE:
//   SEH / shared helper used by Palantir_CompleteDtor unwind states:
//   fully tidy a StringVecShell (destroy strings, free buffer, null triad)
//   then null the published global alias DAT_00d1f1fc.
//
// ABI (bytes):
//   ECX = StringVecShell*
//   no stack formals; bare RET (C3); void
//   SEH frame LAB_009bd525; ECX preserved through prolog into StringVec_Tidy
//
// Callers:
//   Unwind@009afd09 / Unwind@009afd4a — ECX = Palantir* + 0xA0, then JMP here
// =============================================================================

#include <cstdint>

struct StringVecShell {
  void*    pad0;   // +0x00
  uint8_t* begin;  // +0x04
  uint8_t* end;    // +0x08
  uint8_t* capEnd; // +0x0c
};

// Sealed W33-D: ECX=self; bare ret
extern "C" void __fastcall StringVec_Tidy(StringVecShell* self); // 0x00431ae0

// Published path-list shell pointer (nulled after tidy)
extern "C" StringVecShell* DAT_00d1f1fc;

// Retail: ECX=shell; bare ret
extern "C" void __fastcall StringVecShell_TidyAndClearGlobal(StringVecShell* shell)
{
  StringVec_Tidy(shell);
  DAT_00d1f1fc = nullptr;
}

// Scaffold alias (Ghidra name)
extern "C" void __fastcall FUN_00444810(StringVecShell* shell)
{
  StringVecShell_TidyAndClearGlobal(shell);
}
