// =============================================================================
// FUN_00626210  (alias → CVOGHBActivatePlayer_OnEnd_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00626210
// Address:   0x00626210–0x0062623a  (43 B / 0x2B; autoassault.exe base 0x400000)
// System:    heartbeat / timed-actions / player activate
// Generated: 2026-07-29 W29-P OWN-ONLY dual
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Named clean: reconstructed-exact/CVOGHBActivatePlayer_OnEnd_Inferred.cpp
// Ghidra surface __fastcall = thiscall ECX-only; retail has no stack args.

#include <cstdint>

extern "C" void FUN_005081f0(void);

using HostVtbl18_fn = void(__thiscall *)(void *host, int a, int b);

void __fastcall FUN_00626210(void *param_1)
{
  void *host = *reinterpret_cast<void **>(reinterpret_cast<char *>(param_1) + 0x24);
  if (host != nullptr &&
      *reinterpret_cast<uint8_t *>(reinterpret_cast<char *>(param_1) + 0x28) == 0) {
    *reinterpret_cast<uint8_t *>(reinterpret_cast<char *>(host) + 0x6c8) = 1;
    void **vtbl = *reinterpret_cast<void ***>(host);
    auto fn = reinterpret_cast<HostVtbl18_fn>(vtbl[0x18 / sizeof(void *)]);
    fn(host, 1, 1);
  }
  FUN_005081f0();
}
