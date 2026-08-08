// =============================================================================
// GfxParam_LookupAndWrite_Inferred  (Ghidra: FUN_00409a30)
// -----------------------------------------------------------------------------
// Stable ID: aa_00409a30
// Address:   0x00409a30 – 0x00409a64 exclusive  (autoassault.exe, base 0x400000)
// Size:      52 bytes (0x34); epilogue RET 4; pad CC
// System:    graphics parameter service (name → handle → write)
// Dual:      WQ9J-J 2026-08-05 (decompile + read_memory + call-site seal)
// Exactness: Behavior-preserving ABI correction (EAX host / EDX name / RET4).
//            Not modernization. Not bit-exact certified. Terminal false.
// =============================================================================
//
// PURPOSE:
//   Against host context (typically DAT_00d1f05c): resolve service at
//   host[+4]+0xc, look up a named parameter handle via service vtbl+0x24
//   (arg1 fixed 0), then write through vtbl+0x50(handle, data, 0xFFFFFFFF).
//   Callers pass "gWorldFogCenter" + float3*; function itself is type-agnostic.
//
// ABI (machine / call sites — NOT decompiler __fastcall on ECX):
//   EAX = host*; EDX = const char* name; stack = void* data; ret 4; void
// =============================================================================

#include <cstdint>

// Ghidra name: FUN_00409a30
// Note: MSVC will not emit this exact register ABI; presented as the image contract.
void GfxParam_LookupAndWrite_Inferred(void *host /*EAX*/,
                                      const char *name /*EDX*/,
                                      void *data /*[esp+4]*/)
{
  void *mid = *reinterpret_cast<void **>(reinterpret_cast<char *>(host) + 4);
  void **service = *reinterpret_cast<void ***>(reinterpret_cast<char *>(mid) + 0xc);
  std::uint32_t handle = 0;

  if (service != nullptr) {
    void **vtbl = *service;
    using LookupFn = std::uint32_t(__stdcall *)(void *, int, const char *);
    handle = reinterpret_cast<LookupFn>(vtbl[0x24 / 4])(service, 0, name);
  }

  // Odd (preserved): second load has no null check — null service faults here.
  mid = *reinterpret_cast<void **>(reinterpret_cast<char *>(host) + 4);
  service = *reinterpret_cast<void ***>(reinterpret_cast<char *>(mid) + 0xc);
  void **vtbl2 = *service;
  using WriteFn = void(__stdcall *)(void *, std::uint32_t, void *, std::uint32_t);
  reinterpret_cast<WriteFn>(vtbl2[0x50 / 4])(service, handle, data, 0xFFFFFFFFu);
}

// Scaffold twin — matches decompiler surface (in_EAX phantom + param_2/param_3).
// Prefer GfxParam_LookupAndWrite_Inferred for ports.
extern "C" void __fastcall FUN_00409a30(std::uint32_t /*unused_param_1*/,
                                        std::uint32_t param_2 /*EDX name*/,
                                        std::uint32_t param_3 /*stack data*/)
{
  // Host must be in EAX at entry (image contract). Cannot express in portable C.
  (void)param_2;
  (void)param_3;
  // See named clean above for full body.
}
