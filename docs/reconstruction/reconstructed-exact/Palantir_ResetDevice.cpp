// =============================================================================
// Palantir_ResetDevice
// -----------------------------------------------------------------------------
// Stable ID: aa_00754480
// Address:   0x00754480–0x007544E0 exclusive (96 B / 0x60, autoassault.exe base 0x400000)
// System:    client / Palantir host — device reset (product name from log string)
// Generated: 2026-07-29 W35-K dual A/B (decompile + read_memory)
// Exactness: Behavior-preserving CF + ABI. Bytes win over decompiler on EAX=this+8.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_00754480
// =============================================================================
//
// PURPOSE:
//   Palantir::ResetDevice — attempt gfx device reset via FUN_0075eff0; on failure
//   log Palantir.cpp:0x184, set retry flag at +6, Sleep(1000), return -1; on success
//   clear flag and invoke vtbl[+8] on *(this+0x2C) with (this+8), return 0.
//
// ABI (bytes):
//   ECX = Palantir*
//   no stack formals; bare RET (C3)
//   EAX out: 0 success / 0xFFFFFFFF failure
//
// Product evidence:
//   "Palantir::ResetDevice failed. Will try again in 1000 msec. "
//   path C:\vog\1_code\palantir\palantir\framework\Palantir.cpp line 0x184
//   vtbl PTR_FUN_00a9f76c[1]
// =============================================================================

#include <cstdint>

struct Palantir {
  void*    vtbl;           // +0x00
  uint8_t  pad_04;         // +0x04
  uint8_t  device_flag;    // +0x05  → stack arg3 of device reset
  uint8_t  reset_retry;    // +0x06  1=failed/retry, 0=ok
  uint8_t  pad_07;
  uint8_t  sub_08[0x20];   // +0x08  block passed as EAX / vcall arg (size unknown)
  // ... layout residual through +0x28 / +0x2C / +0xB0 — see notes
};

// Unowned nested: gfx device reset (gfxDevice.cpp). Register+stack ABI sealed at call site only.
// Live-in EAX = palantir+8; stack: device*, dword@+0xB0, byte@+5.
extern "C" int FUN_0075eff0(void* device, uint32_t arg_b0, uint8_t flag5 /* + more */);

extern "C" void vog_LogMessage(const char* file, int line, int level, const char* msg);
extern "C" void __stdcall Sleep(uint32_t ms); // IAT

// Retail: ECX=this; bare ret; EAX = 0 | -1
extern "C" int __fastcall Palantir_ResetDevice(Palantir* self)
{
  // Bytes: load [self+0x28], [self+0xB0], byte[self+5]; EAX = self+8
  void* device = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(self) + 0x28);
  uint32_t arg_b0 = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0xB0);
  uint8_t flag5 = *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(self) + 5);
  void* sub8 = reinterpret_cast<uint8_t*>(self) + 8;

  // FUN_0075eff0 uses EAX=sub8 in addition to stack args (bytes authority)
  int hr = FUN_0075eff0(device, arg_b0, flag5);

  if (hr < 0) {
    vog_LogMessage(
        "C:\\vog\\1_code\\palantir\\palantir\\framework\\Palantir.cpp",
        0x184,
        0,
        "Palantir::ResetDevice failed. Will try again in 1000 msec. ");
    *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(self) + 6) = 1;
    Sleep(1000);
    return -1;
  }

  *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(self) + 6) = 0;

  // ECX = *(self+0x2C); PUSH self+8; CALL [vtbl+8]
  void** obj = *reinterpret_cast<void***>(reinterpret_cast<uint8_t*>(self) + 0x2C);
  void** vtbl = *reinterpret_cast<void***>(obj);
  using VFn = void(__fastcall*)(void* ecx_this, void* arg_sub8);
  // Retail is thiscall: ECX=obj, stack arg = self+8, CALL [vtbl+8]
  reinterpret_cast<void(__thiscall*)(void*, void*)>(vtbl[2])(obj, sub8);

  return 0;
}

// Scaffold / Ghidra alias
extern "C" int __fastcall FUN_00754480(Palantir* self)
{
  return Palantir_ResetDevice(self);
}
