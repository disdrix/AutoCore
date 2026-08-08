// =============================================================================
// FUN_00409a30 — scaffold twin of GfxParam_LookupAndWrite_Inferred
// See: GfxParam_LookupAndWrite_Inferred.cpp (authoritative named clean)
// Dual: WQ9J-J 2026-08-05
//
// Image ABI: EAX=host, EDX=name, stack=data*, RET 4.
// Below mirrors decompiler CF with host threaded as explicit first arg for readability.
// =============================================================================

#include <cstdint>

// Readable stand-in: host is EAX on the real image entry.
void GfxParam_LookupAndWrite_Body(void *host,
                                  const char *name,
                                  void *data)
{
  void *mid = *reinterpret_cast<void **>(reinterpret_cast<char *>(host) + 4);
  void **service = *reinterpret_cast<void ***>(reinterpret_cast<char *>(mid) + 0xc);
  std::uint32_t handle = 0;
  if (service != nullptr) {
    void **vtbl = *service;
    using LookupFn = std::uint32_t(__stdcall *)(void *, int, const char *);
    handle = reinterpret_cast<LookupFn>(vtbl[0x24 / 4])(service, 0, name);
  }
  mid = *reinterpret_cast<void **>(reinterpret_cast<char *>(host) + 4);
  service = *reinterpret_cast<void ***>(reinterpret_cast<char *>(mid) + 0xc);
  void **vtbl2 = *service;
  using WriteFn = void(__stdcall *)(void *, std::uint32_t, void *, std::uint32_t);
  reinterpret_cast<WriteFn>(vtbl2[0x50 / 4])(service, handle, data, 0xFFFFFFFFu);
}

// Ghidra symbol surface — param_2=EDX name, param_3=stack data; host arrives in EAX.
extern "C" void __fastcall FUN_00409a30(std::uint32_t /*param_1 unused*/,
                                        std::uint32_t param_2,
                                        std::uint32_t param_3)
{
  // Cannot recover EAX host in portable C from this signature alone.
  // Callers: MOV EAX,[DAT_00d1f05c]; MOV EDX,name; PUSH data; CALL FUN_00409a30.
  (void)param_2;
  (void)param_3;
}
