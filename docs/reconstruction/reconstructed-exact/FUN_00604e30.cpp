// =============================================================================
// FUN_00604e30  (twin of CNDHash_ValueClearOwnedPtrs)
// -----------------------------------------------------------------------------
// Stable ID: aa_00604e30
// Address:   0x00604e30–0x00604e84  (autoassault.exe @ 0x400000)
// Dual A/B:  2026-07-29 W26-P
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// =============================================================================

#include <cstdint>

extern void operator_delete(void *p);

// Ghidra signature; MSVC thiscall on ECX
void __fastcall FUN_00604e30(int param_1)
{
  void *p;

  p = *reinterpret_cast<void **>(param_1 + 4);
  if (p != nullptr) {
    operator_delete(p); // decompiler noreturn is FALSE
  }
  *reinterpret_cast<std::uint32_t *>(param_1 + 4) = 0;

  p = *reinterpret_cast<void **>(param_1 + 8);
  if (p != nullptr) {
    operator_delete(p);
  }
  *reinterpret_cast<std::uint32_t *>(param_1 + 8) = 0;

  p = *reinterpret_cast<void **>(param_1 + 0xc);
  if (p != nullptr) {
    operator_delete(p);
  }
  *reinterpret_cast<std::uint32_t *>(param_1 + 0xc) = 0;

  p = *reinterpret_cast<void **>(param_1 + 0x10);
  if (p != nullptr) {
    operator_delete(p);
  }
  *reinterpret_cast<std::uint32_t *>(param_1 + 0x10) = 0;
}
