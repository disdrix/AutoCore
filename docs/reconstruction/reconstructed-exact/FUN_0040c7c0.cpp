// =============================================================================
// FUN_0040c7c0  (scaffold alias → Mem_MoveDwordRange_ReturnEnd_EcxEax)
// -----------------------------------------------------------------------------
// Stable ID: aa_0040c7c0
// Address:   0x0040c7c0  (autoassault.exe, image base 0x400000)
// Canonical: Mem_MoveDwordRange_ReturnEnd_EcxEax
// System:    stl-helpers / POD relocate
// Generated: 2026-07-29 W22-T dual seal (supersedes 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   Custom-ABI dword-range memmove returning write end.
//   See Mem_MoveDwordRange_ReturnEnd_EcxEax.cpp for named clean source.
//
// Decompiler surface (misleading __thiscall label retained for Ghidra parity):

#include <cstring>
#include <cstddef>

void * /*__thiscall-shaped*/ FUN_0040c7c0(void *param_1 /* ecx srcBegin */,
                                          void *param_2 /* stack dest */)
{
  // in_EAX = srcEnd on entry (not a formal in Ghidra signature)
  int in_EAX = 0; // placeholder: caller-supplied exclusive end in EAX
  size_t _Size =
      (static_cast<size_t>(in_EAX - reinterpret_cast<int>(param_1)) >> 2) * 4;
  void *pvVar1 = memmove(param_2, param_1, _Size);
  return reinterpret_cast<void *>(reinterpret_cast<int>(pvVar1) +
                                  static_cast<int>(_Size));
}

// NOTE: The in_EAX placeholder above is documentation-only for the scaffold
// surface. Prefer Mem_MoveDwordRange_ReturnEnd_EcxEax for real ports.
