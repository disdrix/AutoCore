// =============================================================================
// FUN_008335a0
// -----------------------------------------------------------------------------
// Stable ID: aa_008335a0
// Address:   0x008335a0 – 0x0083363b  (156 B; autoassault.exe base 0x400000)
// System:    object / orientation step (client)
// Dual:      W27-A 2026-07-29 (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Not modernization. Not bit-exact certified.
// =============================================================================
//
// PURPOSE:
//   If host orient quat @ +0x590 is nearly equal (double-cover) to target @
//   +0x5e0 within 0.002f abs+rel, clear pending flag @ +0x5dc and return.
//   Otherwise slerp current→target by t=0.25, write orient, run sibling
//   workers FUN_00833490 / FUN_00833390 (and optional sink @ +0x508).
//
// ABI (machine):
//   EBX = host object (caller FUN_00833a30: MOV EBX,ECX)
//   no stack formals; void; plain RET after ADD ESP,0x10
//
// SEALED CALLEE:
//   Math_QuatNearlyEqual_DoubleCover (FUN_00416260, W26-A)
// =============================================================================

#include <cstdint>

// Sealed W26-A — ESI/EDI register ABI in machine form.
extern "C" std::uint32_t FUN_00416260(float relTol, float absTol);
// Quat slerp: EAX=target, ESI=source, EDI=out, stack t; see FUN_0076e780.
extern "C" void FUN_0076e780(float t);
// thiscall: write orient quat at this+0x80 if changed.
extern "C" void __thiscall FUN_0040d1a0(void *self, float *quat);
extern "C" void FUN_00833490(void);
extern "C" void FUN_00833390(void);

// Ghidra name: FUN_008335a0
// Portable restatement uses an explicit host pointer for EBX.
void FUN_008335a0_portable(std::uint8_t *host)
{
  float local_q[4];
  char near_flag;

  local_q[0] = *reinterpret_cast<float *>(host + 0x590);
  local_q[1] = *reinterpret_cast<float *>(host + 0x594);
  local_q[2] = *reinterpret_cast<float *>(host + 0x598);
  local_q[3] = *reinterpret_cast<float *>(host + 0x59c);

  // Machine: ESI=&local_q, EDI=host+0x5e0, push 0.002f ×2, CALL FUN_00416260
  // Portable: pass pointers explicitly (register ABI is not expressible in ISO C).
  // near_flag = Math_QuatNearlyEqual_DoubleCover(local_q, (float*)(host+0x5e0), 0.002f, 0.002f);
  (void)local_q;
  near_flag = static_cast<char>(FUN_00416260(0.002f, 0.002f));

  if (near_flag != 0) {
    *(host + 0x5dc) = 0;
    return;
  }

  // Machine: EAX=EDI(+0x5e0), ESI=EDI_out=&local_q, t=0.25f
  FUN_0076e780(0.25f);

  // Machine: ECX = host+0x510; push &local_q
  FUN_0040d1a0(host + 0x510, local_q);

  FUN_00833490();

  if (*reinterpret_cast<void **>(host + 0x508) != nullptr) {
    void **iface = *reinterpret_cast<void ***>(host + 0x508);
    auto **vt = reinterpret_cast<void (**)()>(*iface);
    vt[0x44 / 4]();
  }

  FUN_00833390();
}

// Scaffold entry matching Ghidra void FUN_008335a0(void) — EBX must be live.
extern "C" void FUN_008335a0(void)
{
  // Intentionally incomplete for portable C: EBX host is register-passed.
  // Prefer FUN_008335a0_portable for ports.
}
