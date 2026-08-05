// =============================================================================
// Mem_FillDwordN_FromSrc_EaxEcxEdx
// -----------------------------------------------------------------------------
// Stable ID: aa_00436ef0
// Address:   0x00436ef0–0x00436f06  (autoassault.exe, image base 0x400000)
// Body:      23 B / 0x17; bare RET; pad CC @ 0x00436f07
// System:    stl-helpers / POD fill
// Generated: 2026-07-23 scaffold as FUN_00436ef0; dual A/B seal 2026-07-29 (W34-D)
// Exactness: Behavior-preserving rewrite of decompiler + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Fill N consecutive dwords at dest with *src (re-read each iteration).
//   Null-safe: if dest is NULL, still advance cursor without store (guards
//   operator_new failure). Used by PtrVecShell_InitFill (FUN_004646e0) and
//   many other fill paths.
//
// ABI (register — not standard thiscall/stdcall):
//   EAX = dest (uint32_t *)
//   ECX = count (element count)
//   EDX = src pointer (uint32_t const *)
//   bare ret (no stack formals)
//
// Related: Mem_FillDwordN_ReturnEnd (0x004651d0) — different register map +
// returns end pointer; no null gate.
//
// Ghidra: FUN_00436ef0  (__fastcall decompile omits EAX dest as formal)
// Reject: Named_CalleeOf_Named_assManager_00436ef0
//

#include <cstdint>

// Register ABI cannot be expressed portably; document contract in comment.
// Portable semantic equivalent:
void Mem_FillDwordN_FromSrc_EaxEcxEdx(uint32_t* dest, int count,
                                      uint32_t const* src)
{
  for (; count != 0; count = count - 1) {
    if (dest != nullptr) {
      *dest = *src;
    }
    dest = dest + 1;
  }
}

// Scaffold / Ghidra alias
extern "C" void FUN_00436ef0(int count /*ECX*/, uint32_t const* src /*EDX*/,
                             uint32_t* dest /*EAX*/)
{
  Mem_FillDwordN_FromSrc_EaxEcxEdx(dest, count, src);
}
