// =============================================================================
// FUN_00408880  — scaffold twin of PodCopyConstruct_Elem0x138_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00408880
// Address:   0x00408880  (autoassault.exe, image base 0x400000)
// System:    util / POD construct (elem 0x138)
// Generated: 2026-08-04 WQ9H-I (updates scaffold 2026-07-23)
// Exactness: Behavior-preserving; prefer named clean for port.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>
#include <cstring>

// Named implementation
extern "C" void __thiscall PodCopyConstruct_Elem0x138_Inferred(void* dest, const void* src);

extern "C" void __thiscall FUN_00408880(
    std::uint32_t* param_1 /* dest ECX */,
    const std::uint32_t* param_2 /* src stack */)
{
  // Decompiler-shaped body (unroll + 0x40 dword loop) ≡ memcpy 0x138
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  param_1[4] = param_2[4];
  param_1[5] = param_2[5];
  param_1[6] = param_2[6];
  param_1[7] = param_2[7];
  param_1[8] = param_2[8];
  param_1[9] = param_2[9];
  param_1[10] = param_2[10];
  param_1[0xb] = param_2[0xb];
  param_1[0xc] = param_2[0xc];
  param_1[0xd] = param_2[0xd];
  const std::uint32_t* puVar2 = param_2 + 0xe;
  std::uint32_t* puVar3 = param_1 + 0xe;
  for (int iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
}
