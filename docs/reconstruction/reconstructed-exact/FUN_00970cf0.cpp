// =============================================================================
// FUN_00970cf0 — scaffold twin of AssPreloader_Ctor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00970cf0
// Address:   0x00970cf0  (autoassault.exe, image base 0x400000)
// Wave:      W37-W 2026-08-04 (scaffold twin kept; prefer named clean)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>
#include <windows.h>

extern "C" void* PTR_FUN_00aa9a94[];
extern "C" void* FUN_005ae2b0(void);
extern "C" void* FUN_00439770(void);

// stack self*, host*; RET 8; returns self*
extern "C" uint32_t* FUN_00970cf0(uint32_t* param_1, uint32_t param_2)
{
  param_1[1] = 0;
  *param_1 = reinterpret_cast<uint32_t>(&PTR_FUN_00aa9a94);
  *reinterpret_cast<uint8_t*>(param_1 + 2) = 0;

  HANDLE ev = CreateEventA(nullptr, 0, 0, nullptr);
  param_1[1] = reinterpret_cast<uint32_t>(ev);
  param_1[3] = 0;

  int head = reinterpret_cast<int>(FUN_005ae2b0());
  param_1[5] = head;
  *reinterpret_cast<uint8_t*>(head + 0x19) = 1;
  *reinterpret_cast<uint32_t*>(param_1[5] + 4) = param_1[5];
  *reinterpret_cast<uint32_t*>(param_1[5]) = param_1[5];
  *reinterpret_cast<uint32_t*>(param_1[5] + 8) = param_1[5];
  param_1[6] = 0;

  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  InitializeCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(param_1 + 0xc));
  *reinterpret_cast<uint8_t*>(param_1 + 0x12) = 1;

  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  InitializeCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(param_1 + 0x18));
  *reinterpret_cast<uint8_t*>(param_1 + 0x1e) = 1;

  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  InitializeCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(param_1 + 0x24));
  *reinterpret_cast<uint8_t*>(param_1 + 0x2a) = 1;

  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0;
  InitializeCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(param_1 + 0x30));
  *reinterpret_cast<uint8_t*>(param_1 + 0x36) = 1;

  int head2 = reinterpret_cast<int>(FUN_00439770());
  param_1[0x38] = head2;
  *reinterpret_cast<uint8_t*>(head2 + 0x15) = 1;
  *reinterpret_cast<uint32_t*>(param_1[0x38] + 4) = param_1[0x38];
  *reinterpret_cast<uint32_t*>(param_1[0x38]) = param_1[0x38];
  *reinterpret_cast<uint32_t*>(param_1[0x38] + 8) = param_1[0x38];
  param_1[0x39] = 0;
  param_1[0x44] = param_2;

  param_1[0x3a] = 0;
  param_1[0x3b] = 0;
  param_1[0x3c] = 0;
  param_1[0x3d] = 0;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  param_1[0x40] = 0;
  param_1[0x41] = 0;
  param_1[0x42] = 0;
  param_1[0x43] = 0;

  return param_1;
}
