// =============================================================================
// PtrVecShell_InitFill_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004646e0
// Address:   0x004646e0–0x0046477e  (159 B / 0x9F; autoassault.exe base 0x400000)
// System:    shared pointer-vector shell init / fill (hash bucket tables)
// Generated: 2026-07-23 scaffold as FUN_004646e0; dual A/B seal 2026-07-29 (W33-B)
// Exactness: Behavior-preserving rewrite of decompiler + bytes (ABI corrected).
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Initialize a pointer-vector shell: zero begin/end/cap, allocate count*4 bytes,
//   fill every pointer slot with *fill_src, set end = end_cap = full.
//   AssResolver nested bag ctors call with count=9 and fill = circular sentinel*.
//
// ABI (bytes win over decompiler):
//   stdcall 3 formals; RET 12; SEH LAB_009bd530.
//   shell+0x00 is NOT written.
//
// REJECT: scaffold Named_CalleeOf_* product aliases; decompiler 2-arg void signature.
//

#include <cstdint>

extern "C" void* __cdecl operator_new(uint32_t size);
// MSVC vector max-size: builds "vector<T> too long" and throws (noreturn).
extern "C" void FUN_004540b0(void);
// Fill: ECX=count, EDX=fill_src*, EAX=begin* — *dst++ = *fill_src, count times.
extern "C" void __fastcall FUN_00436ef0(uint32_t count, uint32_t* fill_src /*edx*/,
                                        /*eax*/ uint32_t* begin);

struct PtrVecShell {
  uint32_t unwritten00; // +0x00 — not written by this init
  void**   begin;       // +0x04
  void**   end;         // +0x08
  void**   end_cap;     // +0x0c
};

// Retail: stack(shell*, count, fill_src*); RET 12
extern "C" void __stdcall PtrVecShell_InitFill_Inferred(
    PtrVecShell* shell /*stack*/,
    uint32_t count /*stack*/,
    void** fill_src /*stack — pointer to value copied into each slot*/)
{
  // SEH frame LAB_009bd530
  shell->begin = nullptr;
  shell->end = nullptr;
  shell->end_cap = nullptr;

  if (count == 0) {
    return;
  }

  if (count > 0x3fffffffu) {
    FUN_004540b0(); // noreturn — "vector<T> too long"
  }

  const uint32_t byte_len = count * 4u;
  auto* const block = static_cast<void**>(operator_new(byte_len));

  shell->end_cap = reinterpret_cast<void**>(
      reinterpret_cast<uint8_t*>(block) + byte_len);
  shell->begin = block;
  shell->end = block;

  // FUN_00436ef0(count) with EAX=block, EDX=fill_src
  FUN_00436ef0(count, reinterpret_cast<uint32_t*>(fill_src),
               reinterpret_cast<uint32_t*>(block));

  shell->end = reinterpret_cast<void**>(
      reinterpret_cast<uint8_t*>(block) + byte_len);
}

// Ghidra twin symbol (corrected ABI)
extern "C" void __stdcall FUN_004646e0(PtrVecShell* shell, uint32_t count,
                                       void** fill_src)
{
  PtrVecShell_InitFill_Inferred(shell, count, fill_src);
}
