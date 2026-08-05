// =============================================================================
// PalantirEnv_Ctor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00492dd0
// Address:   0x00492dd0-0x004930ab exclusive (731 B / 0x2DB)
// System:    client / Palantir env host (0x198)
// Generated: 2026-07-29 W31-P dual seal
// Exactness: Behavior-preserving rewrite of decompiler CF + read_memory seals.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
// Complete MSVC ctor for the 0x198 env host allocated by
// Client_InitPalantirViewBundle_Inferred (W30-F) at parent+0xE894.
// Factory call: FUN_00492dd0(raw, 0, parent). Returns this (RET 8).
// Does NOT init water/distort/NDRiver phases — that is PalantirEnv_InitPhases_Inferred.
//
// NOTE: Six FUN_0096ef70 calls are subobject inits with decompiler-omitted ECX
// this-adjusts; exact subobject bases left as FUN_0096ef70() to avoid invention.

#include <cstdint>

extern "C" void  FUN_007560d0(void);
extern "C" void  FUN_0096ef70(void);
extern "C" void *FUN_004933f0(void);
extern "C" void *FUN_0044e100(void); // RbTree_AllocEmptyNode_0x30
extern "C" void *__cdecl operator_new(uint32_t size);
extern "C" void *__thiscall FUN_00497920(void *self, void *parent);
extern "C" void  FUN_0048f2d0(void);

extern "C" void *PTR_FUN_009c7928;
extern "C" void *PTR_LAB_009c7744;

// __thiscall; ECX=self; stack arg0 + parent; RET 8; returns self
void *__thiscall PalantirEnv_Ctor_Inferred(void *self, uint32_t arg0, void *parent)
{
  auto *s = reinterpret_cast<uint8_t *>(self);
  auto *p = reinterpret_cast<uint8_t *>(parent);
  void *node;
  void *raw;
  void *child;

  // SEH LAB_009a0b3b

  FUN_007560d0();
  *reinterpret_cast<void **>(s + 0x00) = &PTR_FUN_009c7928;

  s[0x80] = 1;
  s[0x81] = 1;
  s[0x82] = 1;
  s[0x83] = 1;
  s[0x84] = 1;
  s[0x85] = 1;
  s[0x86] = 1;
  s[0x87] = static_cast<uint8_t>(p[0x7D] == 0);
  s[0x88] = 1;
  s[0x89] = 0;
  s[0x8A] = 0;
  s[0x8B] = 1;
  s[0x8C] = 1;
  s[0x8E] = 1;
  s[0x8F] = 1;
  s[0x90] = 0;
  *reinterpret_cast<uint32_t *>(s + 0x94) = 0;
  *reinterpret_cast<uint16_t *>(s + 0x98) = 0xFFFF;
  FUN_0096ef70();
  *reinterpret_cast<uint16_t *>(s + 0xA0) = 0xFFFF;
  FUN_0096ef70();
  FUN_0096ef70();
  FUN_0096ef70();

  *reinterpret_cast<uint32_t *>(s + 0xBC) = arg0;   // param_1[0x2f]
  *reinterpret_cast<void **>(s + 0xB8) = parent;    // param_1[0x2e]
  *reinterpret_cast<uint32_t *>(s + 0xC4) = 0;
  *reinterpret_cast<uint32_t *>(s + 0xC8) = 0;
  *reinterpret_cast<uint32_t *>(s + 0xCC) = 0;
  *reinterpret_cast<uint32_t *>(s + 0xD0) = 0;

  *reinterpret_cast<void **>(s + 0xD4) = &PTR_LAB_009c7744; // [0x35]
  *reinterpret_cast<void **>(s + 0xD8) = self;              // [0x36]
  FUN_0096ef70();
  FUN_0096ef70();

  *reinterpret_cast<void **>(s + 0xE8) = FUN_004933f0(); // [0x3a]
  *reinterpret_cast<uint32_t *>(s + 0xEC) = 0;
  *reinterpret_cast<void **>(s + 0xF4) = FUN_004933f0(); // [0x3d]
  *reinterpret_cast<uint32_t *>(s + 0xF8) = 0;
  s[0xFC] = 0;

  // sparse zero stores (decompiler indices → byte offs)
  *reinterpret_cast<uint32_t *>(s + 0x104) = 0; // [0x41]
  *reinterpret_cast<uint32_t *>(s + 0x108) = 0; // [0x42]
  *reinterpret_cast<uint32_t *>(s + 0x11C) = 0; // [0x47]
  *reinterpret_cast<uint32_t *>(s + 0x120) = 0;
  *reinterpret_cast<uint32_t *>(s + 0x124) = 0;
  *reinterpret_cast<uint32_t *>(s + 0x128) = 0;
  *reinterpret_cast<uint32_t *>(s + 0x12C) = 0;
  *reinterpret_cast<uint32_t *>(s + 0x130) = 0; // [0x4c]
  *reinterpret_cast<uint32_t *>(s + 0x144) = 0; // [0x51]
  *reinterpret_cast<uint32_t *>(s + 0x148) = 0;
  *reinterpret_cast<uint32_t *>(s + 0x14C) = 0;
  *reinterpret_cast<uint32_t *>(s + 0x154) = 0; // [0x55]
  *reinterpret_cast<uint32_t *>(s + 0x158) = 0;
  *reinterpret_cast<uint32_t *>(s + 0x15C) = 0;
  *reinterpret_cast<uint32_t *>(s + 0x164) = 0; // [0x59]
  *reinterpret_cast<uint32_t *>(s + 0x168) = 0;
  *reinterpret_cast<uint32_t *>(s + 0x16C) = 0;

  s[0x171] = 1;
  *reinterpret_cast<uint32_t *>(s + 0x174) = 0; // [0x5d]
  *reinterpret_cast<uint32_t *>(s + 0x178) = 0;
  *reinterpret_cast<uint32_t *>(s + 0x17C) = 0;

  node = FUN_0044e100();
  *reinterpret_cast<void **>(s + 0x190) = node; // [0x64]
  reinterpret_cast<uint8_t *>(node)[0x2D] = 1;
  *reinterpret_cast<void **>(reinterpret_cast<uint8_t *>(node) + 0x04) = node;
  *reinterpret_cast<void **>(reinterpret_cast<uint8_t *>(node) + 0x00) = node;
  *reinterpret_cast<void **>(reinterpret_cast<uint8_t *>(node) + 0x08) = node;
  *reinterpret_cast<uint32_t *>(s + 0x194) = 0; // [0x65]

  // +0x172 from parent desktop chain
  {
    int desktop = *reinterpret_cast<int *>(p + 0xE89C);
    int mid = *reinterpret_cast<int *>(reinterpret_cast<uint8_t *>(desktop) + 0x28);
    uint8_t b = *reinterpret_cast<uint8_t *>(reinterpret_cast<uint8_t *>(mid) + 0x799);
    s[0x172] = static_cast<uint8_t>(1 < b);
  }

  *reinterpret_cast<uint32_t *>(s + 0x180) = 0; // [0x60]
  *reinterpret_cast<uint32_t *>(s + 0x184) = 0;
  *reinterpret_cast<uint32_t *>(s + 0x188) = 0;

  *reinterpret_cast<uint32_t *>(s + 0x70) =
      static_cast<uint32_t>(p[0x7D] == 0); // [0x1c]

  raw = operator_new(0xC8); // 200
  child = (raw == nullptr) ? nullptr : FUN_00497920(raw, parent);
  *reinterpret_cast<void **>(s + 0x100) = child; // [0x40]

  FUN_0048f2d0();
  return self;
}
