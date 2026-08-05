// =============================================================================
// FUN_004cd8f0  (twin of Host_ReplaceOwnedGridObj_E4FC_CtorPopulate_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004cd8f0
// Address:   0x004cd8f0  (autoassault.exe, image base 0x400000)
// Body:      0x004cd8f0–0x004cd991 exclusive (161 B); pad CC
// Wave:      W38-S (2026-08-04)
// Exactness: Behavior-preserving rewrite. Bit-for-bit: DEFERRED.
// =============================================================================

#include <cstdint>

extern "C" void *__cdecl operator_new(uint32_t size);
extern "C" void *__thiscall FUN_005b3f60(void *self);
extern "C" uint32_t __thiscall FUN_005b3fa0(
    void *self, uint32_t a, uint32_t b, uint32_t c, uint32_t scale, uint32_t ctx);

typedef void (__thiscall *ScalarDeletingDtor)(void *self, int flags);

// __thiscall; ECX = host; stack 4 args; void; ret 0x10
extern "C" void __thiscall FUN_004cd8f0(
    void *param_1,
    uint32_t param_2,
    uint32_t param_3,
    uint32_t param_4,
    uint32_t param_5)
{
  void **const slot = reinterpret_cast<void **>(static_cast<char *>(param_1) + 0xe4fc);

  if (*slot != nullptr) {
    auto **vtbl = *reinterpret_cast<void ***>(*slot);
    reinterpret_cast<ScalarDeletingDtor>(vtbl[0])(*slot, 1);
    *slot = nullptr;
  }

  void *pvVar1 = operator_new(0x30);
  void *uVar2 = nullptr;
  if (pvVar1 != nullptr) {
    uVar2 = FUN_005b3f60(pvVar1);
  }
  *slot = uVar2;

  void *nested = *reinterpret_cast<void **>(static_cast<char *>(param_1) + 0xe4f8);
  uint32_t scale = *reinterpret_cast<uint32_t *>(static_cast<char *>(nested) + 0x18);

  // Bytes: mov ecx, eax (new obj) before call — decompiler omits this=
  FUN_005b3fa0(uVar2, param_2, param_3, param_4, scale, param_5);
}
