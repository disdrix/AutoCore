// =============================================================================
// Perf_QpcBeginNamed_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_007a4400
// Address:   0x007a4400 – 0x007a445c  (autoassault.exe, image base 0x400000)
// System:    perf / QPC named begin
// Dual:      W26-D 2026-07-29 (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Not modernization. Not bit-exact certified.
// =============================================================================
//
// PURPOSE:
//   Begin a named performance timer slot:
//     1) Once-init: QueryPerformanceFrequency → store 1.0f/freq at DAT_00afa254
//     2) Copy label string into slot+8
//     3) QueryPerformanceCounter into slot+0 (LARGE_INTEGER)
//   Returns the slot pointer (EAX = this).
//
//   High-traffic callee from Client_InitInstance stages, sector map IO, etc.
//   Label strings often use "@@..." plate prefixes.
//
// ABI (machine):
//   thiscall; ECX = timer slot; stack char* label; ret 4; EAX = this
// =============================================================================

#include <cstdint>
#include <windows.h>

// Image globals (autoassault.exe)
extern "C" std::uint8_t DAT_00b00a74;   // once-init gate (byte)
extern "C" float        DAT_00afa254;   // 1.0f / QPF after first begin
extern "C" float        g_flOne;        // @ 0x00a0f2a0 — float 1.0

// Ghidra name: FUN_007a4400
// Timer slot: +0 LARGE_INTEGER start; +8 char label[]
LARGE_INTEGER* __thiscall Perf_QpcBeginNamed_Inferred(LARGE_INTEGER* slot /*ECX*/, char* label)
{
  if (DAT_00b00a74 != 0) {
    DAT_00b00a74 = 0;
    LARGE_INTEGER freq{};
    QueryPerformanceFrequency(&freq);
    DAT_00afa254 = g_flOne / static_cast<float>(static_cast<long long>(freq.QuadPart));
  }

  // strcpy into (char*)slot + 8  (decompiler uses 8-(int)label offset form)
  char* dst = reinterpret_cast<char*>(slot) + 8;
  char c;
  do {
    c = *label;
    *dst = c;
    ++label;
    ++dst;
  } while (c != '\0');

  QueryPerformanceCounter(slot);
  return slot;
}

// Scaffold twin entry (Ghidra name)
extern "C" LARGE_INTEGER* __thiscall FUN_007a4400(LARGE_INTEGER* slot, char* label)
{
  return Perf_QpcBeginNamed_Inferred(slot, label);
}
