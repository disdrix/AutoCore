// =============================================================================
// Client_InitPalantirViewBundle_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004cda90
// Address:   0x004cda90-0x004cdc34 exclusive (420 B / 0x1A4)
// System:    client / Palantir graphics + env bootstrap
// Generated: 2026-07-29 W30-F dual seal
// Exactness: Behavior-preserving rewrite of decompiler CF + read_memory seals.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
// Factory on large client/core parent (sole caller FUN_00948530 window init):
//   +0xE890 = new(0x150) GfxView FUN_0075ceb0 (gfxView.cpp / PalViewBackground.fx)
//   +0xE894 = new(0x198) FUN_00492dd0(0, parent)
//   +0xE898 = new(0xC8)  Class_009c7a1c_Ctor (FUN_00496f70, W29-G)
// Cross-wires view↔env; optional Palantir desktop at +0xE89C; env phases
// FUN_0048fc90(1); publishes *(env+4) into DAT_00d1a54c via FUN_0074e200.
// Returns 1. Bare RET (no stack formals).

#include <cstdint>

extern "C" void *__cdecl operator_new(uint32_t size);
extern "C" void *__fastcall FUN_0075ceb0(void *self);
extern "C" void  __thiscall FUN_0075b3b0(void *self, uint32_t near_bits);
extern "C" void  __thiscall FUN_0075b390(void *self, uint32_t far_bits);
extern "C" void *__thiscall FUN_00492dd0(void *self, uint32_t arg0, void *parent);
extern "C" void *__thiscall FUN_00496f70(void *self, void *parent); // Class_009c7a1c_Ctor
extern "C" void  __thiscall FUN_0048fc90(void *self, uint32_t flag);
extern "C" void  FUN_0074e200(uint32_t enable);

extern "C" uint32_t DAT_00a0f520; // 1000.0f bits
extern "C" uint32_t DAT_00aaaa90; // 500.0f bits
extern "C" uint32_t DAT_00afdef0; // 0xFF000000
extern "C" uint32_t DAT_00d1a54c;

// __thiscall/__fastcall; ECX=parent; returns 1; bare C3
uint32_t __fastcall Client_InitPalantirViewBundle_Inferred(void *parent)
{
  auto *p = reinterpret_cast<uint8_t *>(parent);
  void *raw;
  void *obj;
  uint32_t far_bits;
  int slot;

  // SEH LAB_009a1ef7 — levels 0/1/2 around the three new+ctor pairs

  raw = operator_new(0x150);
  obj = (raw == nullptr) ? nullptr : FUN_0075ceb0(raw);
  *reinterpret_cast<void **>(p + 0xE890) = obj;

  FUN_0075b3b0(obj, 0x3F000000u); // 0.5f → view+0xF0
  far_bits = DAT_00a0f520;        // 1000.0f
  if (p[0x7D] == 0) {
    far_bits = DAT_00aaaa90;      // 500.0f
  }
  FUN_0075b390(obj, far_bits);    // → view+0xF4

  int desktop = *reinterpret_cast<int *>(p + 0xE89C);
  if (desktop != 0) {
    void *view = *reinterpret_cast<void **>(p + 0xE890);
    *reinterpret_cast<void **>(reinterpret_cast<uint8_t *>(desktop) + 0x2E4) = view;
    int *child = *reinterpret_cast<int **>(reinterpret_cast<uint8_t *>(desktop) + 0x2C);
    auto **vt = reinterpret_cast<void **>(*child);
    using Vcall = void(__thiscall *)(void *, void *);
    reinterpret_cast<Vcall>(vt[3])(child, view); // vtbl+0xC
    *reinterpret_cast<uint32_t *>(reinterpret_cast<uint8_t *>(child) + 0xC4) = DAT_00afdef0;
  }

  raw = operator_new(0x198);
  obj = (raw == nullptr) ? nullptr : FUN_00492dd0(raw, 0, parent);
  *reinterpret_cast<void **>(p + 0xE894) = obj;

  raw = operator_new(0xC8);
  obj = (raw == nullptr) ? nullptr : FUN_00496f70(raw, parent);
  *reinterpret_cast<void **>(p + 0xE898) = obj;

  void *view = *reinterpret_cast<void **>(p + 0xE890);
  void *env  = *reinterpret_cast<void **>(p + 0xE894);
  *reinterpret_cast<void **>(reinterpret_cast<uint8_t *>(view) + 0x04) = env;
  *reinterpret_cast<void **>(reinterpret_cast<uint8_t *>(env)  + 0xC0) = view;

  FUN_0048fc90(env, 1);

  slot = *reinterpret_cast<int *>(reinterpret_cast<uint8_t *>(env) + 4);
  if (DAT_00d1a54c != 0) {
    FUN_0074e200(0);
  }
  if (slot != 0) {
    FUN_0074e200(1);
  }
  DAT_00d1a54c = static_cast<uint32_t>(slot);

  return 1;
}
