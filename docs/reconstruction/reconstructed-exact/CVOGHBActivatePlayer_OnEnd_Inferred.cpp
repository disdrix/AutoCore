// =============================================================================
// CVOGHBActivatePlayer_OnEnd_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00626210
// Address:   0x00626210–0x0062623a  (43 B / 0x2B; autoassault.exe base 0x400000)
// System:    heartbeat / timed-actions / player activate
// Generated: 2026-07-29 W29-P OWN-ONLY dual (from raw + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: Activate-player HB virtual OnEnd (vtbl 0x009e3168 +0x14).
// If host backref (this+0x24) is set and skip flag (this+0x28)==0:
//   host+0x6c8 = 1; host->vtbl+0x18(1,1). Always tail-jmps empty FUN_005081f0.
//
// ABI: __thiscall ECX=this; no stack args; void (exit via jmp to empty RET).

#include <cstdint>

// FUN_005081f0 — empty RET (shared nop tail)
extern "C" void FUN_005081f0(void);

using HostVtbl18_fn = void(__thiscall *)(void *host, int a, int b);

void __fastcall CVOGHBActivatePlayer_OnEnd_Inferred(void *self)
{
  void *host = *reinterpret_cast<void **>(reinterpret_cast<char *>(self) + 0x24);
  if (host != nullptr &&
      *reinterpret_cast<uint8_t *>(reinterpret_cast<char *>(self) + 0x28) == 0) {
    *reinterpret_cast<uint8_t *>(reinterpret_cast<char *>(host) + 0x6c8) = 1;
    void **vtbl = *reinterpret_cast<void ***>(host);
    auto fn = reinterpret_cast<HostVtbl18_fn>(vtbl[0x18 / sizeof(void *)]);
    fn(host, 1, 1);
  }
  FUN_005081f0();
}
