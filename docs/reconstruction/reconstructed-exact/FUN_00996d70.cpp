// =============================================================================
// FUN_00996d70  (twin of ResourceCache_Subobj14_Configure_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00996d70
// Address:   0x00996d70  (autoassault.exe, image base 0x400000)
// System:    ResourceCache / embedded configure subobject
// Generated: 2026-08-04 W37-V dual seal
// Exactness: Decompiler CF + byte register formals (EAX subobj, EBX size).
// Bit-for-bit vs retail EXE: DEFERRED (no Launcher).
// =============================================================================

#include <cstdint>

extern "C" void FUN_00415e90(void);
extern "C" void __thiscall FUN_00449a90(void *param_1, uint32_t param_2);
extern "C" void FUN_009899a0(void);
extern "C" bool __thiscall FUN_00989b00(void *param_1, uint8_t param_2);

// Register formals (not in Ghidra signature):
//   EAX = subobject base (in_EAX in decompiler)
//   EBX = buffer size for FUN_00989b00 (omitted by decompiler)
// Stack: flag byte; cleanup RET 4
extern "C" void FUN_00996d70(uint8_t param_1)
{
  int in_EAX; // sealed: entry EAX

  // ESI = in_EAX+0x2C before this call (bytes)
  FUN_00415e90();
  // ECX = in_EAX+0x38; push 9 (bytes)
  FUN_00449a90(reinterpret_cast<void *>(static_cast<uintptr_t>(0)), 9);
  *(uint32_t *)(in_EAX + 0x48) = 1;
  *(uint32_t *)(in_EAX + 0x4c) = 1;
  // EDI = in_EAX before this call (bytes)
  FUN_009899a0();
  *(uint8_t *)(in_EAX + 0x50) = param_1;
  // ECX = in_EAX; EAX = 4; EBX = size; push 1 (bytes)
  (void)FUN_00989b00(reinterpret_cast<void *>(static_cast<uintptr_t>(in_EAX)), 1);
}
