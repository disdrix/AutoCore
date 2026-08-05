// =============================================================================
// GfxDevice_Ctor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0075f7f0
// Address:   0x0075f7f0  (autoassault.exe, image base 0x400000)
// System:    client / Palantir graphics (gfxAdapter CreateDevice host)
// Generated: 2026-07-29 W35-R dual A/B (OWN-ONLY)
// Exactness: Behavior-preserving rewrite of decompiler + read_memory + sole caller.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Placement-construct the 0x7b0 gfx device host after D3D CreateDevice:
//   *self = device9; self+4 = d3d9 (ECX) + AddRef; zero banks; seed 14 subsystem slots.
// ABI: ECX = IDirect3D9* (NOT the constructed object); stack self* + device9*; RET 8.
// Sole caller: FUN_00735c90 (gfxAdapter.cpp) after operator_new(0x7b0).
// Post-ctor: caller copies D3DCAPS into +0x14/+0x144 and present params into +0x2B8.

#include <cstdint>

// IUnknown::AddRef at vtbl+4
using AddRefFn = uint32_t(__stdcall *)(void *self);

extern "C" void FUN_00966690();
extern "C" void *operator_new(uint32_t size);
extern "C" void *FUN_0073bfd0();
extern "C" void *FUN_00986d40(void *self);
extern "C" void *FUN_00985df0(void *self);
extern "C" void *FUN_0096eec0(void *self);
extern "C" void *NestedHash_Ctor_Sentinel0x30_Inferred(void *self); // FUN_00463bd0
extern "C" void *FUN_00966f70(void *self);
extern "C" void *FUN_00969df0();
extern "C" void *FUN_0073e3a0(void *self);
extern "C" void *FUN_0073c150(void *self);
extern "C" void *FUN_00987260(void *self);

// Globals dual-published by this ctor (image symbols)
extern "C" void *DAT_00d1f044;
extern "C" void *DAT_00d1f624;
extern "C" void *DAT_00d1f630;
extern "C" void *DAT_00d1f654;
extern "C" void *DAT_00d1f628;
extern "C" void *DAT_00d1f620;

static void zero_dwords(uint32_t *p, int count)
{
  for (int i = 0; i < count; ++i)
    p[i] = 0;
}

static void *new_or_null(uint32_t size)
{
  return operator_new(size);
}

extern "C" void *__thiscall GfxDevice_Ctor_Inferred(void *d3d9, void *self, void *device9)
{
  auto *obj = static_cast<uint32_t *>(self);

  DAT_00d1f044 = self;
  obj[0] = reinterpret_cast<uint32_t>(device9); // +0x00
  obj[1] = reinterpret_cast<uint32_t>(d3d9);    // +0x04
  obj[2] = 0;                                   // +0x08
  obj[3] = 0;                                   // +0x0c
  obj[4] = 0;                                   // +0x10

  FUN_00966690();

  // High subsystem ptr cluster pre-zero (@ dword 0x1cf..)
  for (int i = 0x1cf; i <= 0x1db; ++i)
    obj[i] = 0;
  obj[0x1e7] = 0;
  obj[0x1e8] = 0;
  obj[0x1e9] = 0;
  *reinterpret_cast<uint8_t *>(obj + 0x1ea) = 0; // +0x7A8
  obj[0x1eb] = 0;

  // AddRef IDirect3D9*
  if (d3d9) {
    auto **vtbl = *reinterpret_cast<void ***>(d3d9);
    auto addref = reinterpret_cast<AddRefFn>(vtbl[1]); // offset +4
    addref(d3d9);
  }

  // Zero D3DCAPS9-sized blocks (0x4c dwords = 0x130) and present params (0xe = 0x38)
  zero_dwords(obj + 5, 0x4c);      // +0x14
  zero_dwords(obj + 0x51, 0x4c);   // +0x144
  zero_dwords(obj + 0xae, 0xe);    // +0x2B8
  zero_dwords(obj + 0x1dd, 10);    // mid cluster @ +0x774
  zero_dwords(obj + 0xbc, 0x113);  // +0x2F0 large bank

  // --- subsystem slots ---
  // 0x1cf / +0x73C: PoolHost shell 0x20 → DAT_00d1f624
  {
    void *p = new_or_null(0x20);
    if (p) {
      DAT_00d1f624 = p;
      auto *u = static_cast<uint32_t *>(p);
      u[1] = u[2] = u[3] = u[5] = u[6] = u[7] = 0;
    }
    obj[0x1cf] = reinterpret_cast<uint32_t>(p);
  }

  // 0x1d0 / +0x740: 0xC4 + FUN_0073bfd0
  {
    void *p = new_or_null(0xc4);
    obj[0x1d0] = p ? reinterpret_cast<uint32_t>(FUN_0073bfd0()) : 0;
  }

  // 0x1d1 / +0x744: 0x5C shell → DAT_00d1f630
  {
    void *p = new_or_null(0x5c);
    if (p) {
      DAT_00d1f630 = p;
      auto *u = static_cast<uint32_t *>(p);
      u[1] = u[2] = u[3] = u[4] = u[5] = 0;
      u[0xe] = 0; // +0x38
    }
    obj[0x1d1] = reinterpret_cast<uint32_t>(p);
  }

  // 0x1d2 / +0x748: bare new(1) → DAT_00d1f654
  // On OOM: slot=0; global rewritten with prior value (no-op). On success: both = p.
  {
    void *p = new_or_null(1);
    void *global_val = p ? p : DAT_00d1f654;
    if (!p)
      p = nullptr;
    DAT_00d1f654 = global_val;
    obj[0x1d2] = reinterpret_cast<uint32_t>(p);
  }

  // 0x1d3 / +0x74C: 0x20 + FUN_00986d40
  {
    void *p = new_or_null(0x20);
    obj[0x1d3] = p ? reinterpret_cast<uint32_t>(FUN_00986d40(p)) : 0;
  }

  // 0x1d4 / +0x750: 0x20 + FUN_00985df0
  {
    void *p = new_or_null(0x20);
    obj[0x1d4] = p ? reinterpret_cast<uint32_t>(FUN_00985df0(p)) : 0;
  }

  // 0x1d5 / +0x754: 0x34 + FUN_0096eec0
  {
    void *p = new_or_null(0x34);
    obj[0x1d5] = p ? reinterpret_cast<uint32_t>(FUN_0096eec0(p)) : 0;
  }

  // 0x1d6 / +0x758: 0x28 NestedHash sentinel 0x30 → DAT_00d1f628
  {
    void *p = new_or_null(0x28);
    if (p) {
      DAT_00d1f628 = p;
      NestedHash_Ctor_Sentinel0x30_Inferred(p);
    }
    obj[0x1d6] = reinterpret_cast<uint32_t>(p);
  }

  // 0x1d7 / +0x75C: 0x20 + FUN_00966f70
  {
    void *p = new_or_null(0x20);
    obj[0x1d7] = p ? reinterpret_cast<uint32_t>(FUN_00966f70(p)) : 0;
  }

  // 0x1d8 / +0x760: 0x150 + FUN_00969df0
  {
    void *p = new_or_null(0x150);
    obj[0x1d8] = p ? reinterpret_cast<uint32_t>(FUN_00969df0()) : 0;
  }

  // 0x1d9 / +0x764: 0x48 + FUN_0073e3a0
  {
    void *p = new_or_null(0x48);
    obj[0x1d9] = p ? reinterpret_cast<uint32_t>(FUN_0073e3a0(p)) : 0;
  }

  // 0x1da / +0x768: 0x5C + FUN_0073c150
  {
    void *p = new_or_null(0x5c);
    obj[0x1da] = p ? reinterpret_cast<uint32_t>(FUN_0073c150(p)) : 0;
  }

  // 0x1db / +0x76C: 0x10 shell → DAT_00d1f620
  {
    void *p = new_or_null(0x10);
    if (p) {
      DAT_00d1f620 = p;
      auto *u = static_cast<uint32_t *>(p);
      u[1] = u[2] = u[3] = 0;
    }
    obj[0x1db] = reinterpret_cast<uint32_t>(p);
  }

  // 0x1dc / +0x770: 0x1C + FUN_00987260
  {
    void *p = new_or_null(0x1c);
    obj[0x1dc] = p ? reinterpret_cast<uint32_t>(FUN_00987260(p)) : 0;
  }

  return self;
}

// Twin export for FUN_* symbol stability
extern "C" void *__thiscall FUN_0075f7f0(void *d3d9, void *self, void *device9)
{
  return GfxDevice_Ctor_Inferred(d3d9, self, device9);
}
