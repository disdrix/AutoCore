// =============================================================================
// CVOGCreature_ctor
// -----------------------------------------------------------------------------
// Stable ID: aa_004c9aa0
// Address:   0x004c9aa0–0x004c9f7b  (autoassault.exe, image base 0x400000)
// System:    creature runtime / world object factory
// Generated: 2026-07-29 W21-F dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow + image ABI.
//            Not modernization. Field English mostly open — offsets preserved.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE
//   MSVC most-derived / base constructor for CVOGCreature (~0x690 heap when
//   most-derived). Optional dual-base cookies when mostDerivedFlag!=0; always
//   chains parent FUN_005c82a0(0); installs creature vtbls including
//   PTR_CVOGCreature_SetupGraphics; defaults large field run; allocates map head
//   (FUN_0058d9c0) and 0x60-byte subobject (FUN_005d55f0).
//
// ABI (image-sealed)
//   __thiscall CVOGCreature* Ctor(this, int mostDerivedFlag);  ret 4; EAX=this
//
// Factories (push 1 unless noted)
//   CVOGSpawnPoint_CreateCreature (new 0x690), CVOGReaction_GiveItemByCbid,
//   Skill_SpawnTemplateAndStartHB, FUN_00568670, FUN_00503780, FUN_004ca150,
//   FUN_00855810; CVOGCharacter_ctor pushes 0 (base subobject).
// =============================================================================

#include <cstdint>

extern "C" void* ExceptionList;
extern float g_flOne;
extern uint32_t DAT_009cb8c0, DAT_009cb8c4, DAT_009cb8c8, DAT_009cb8cc;
extern uint32_t DAT_00aaa7a4;   // 15.0f
extern uint32_t DAT_00a0f524;
extern uint32_t DAT_00aaaa24;
extern uint32_t DAT_009d4d14, DAT_009d4d0c;
extern void* PTR_LAB_009cbe74;
extern void* PTR_CVOGCreature_SetupGraphics_009cbe38;
extern void* PTR_LAB_009cbb74;
extern uint8_t LAB_009a1d1c[];

extern "C" void* __cdecl operator_new(uint32_t size);
extern "C" void* __thiscall FUN_00518940(void* self);
extern "C" void* __thiscall FUN_005c82a0(void* self, int mostDerivedFlag);
extern "C" void* __cdecl FUN_0058d9c0(void); // MapFloatTfid_AllocNode_Inferred family
extern "C" void FUN_0096e0e0(void);
extern "C" void* __thiscall FUN_005d55f0(void* self, int arg);

// Ghidra: FUN_004c9aa0
// Prior alias: Named_CalleeOf_CVOGReaction_GiveItemByCbid_004c9aa0

extern "C" uint32_t* __thiscall CVOGCreature_ctor(uint32_t* self, int mostDerivedFlag)
{
  void* local_c;
  uint8_t* puStack_8;
  uint32_t local_4;

  local_4 = 0xffffffffu;
  puStack_8 = &LAB_009a1d1c[0];
  local_c = ExceptionList;
  ExceptionList = &local_c;

  if (mostDerivedFlag != 0) {
    ExceptionList = &local_c;
    self[1] = reinterpret_cast<uint32_t>(&DAT_009d4d14);
    self[0x11] = reinterpret_cast<uint32_t>(&DAT_009d4d0c);
    // image: lea ecx, [this+0x500]; call FUN_00518940
    FUN_00518940(reinterpret_cast<uint8_t*>(self) + 0x500);
    local_4 = 0;
  }

  FUN_005c82a0(self, 0);

  const uint32_t uAaa7a4 = DAT_00aaa7a4;
  *self = reinterpret_cast<uint32_t>(&PTR_LAB_009cbe74);
  self[0x10] = reinterpret_cast<uint32_t>(&PTR_CVOGCreature_SetupGraphics_009cbe38);

  {
    const int vbOff = *reinterpret_cast<int*>(self[1] + 4);
    *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(self) + vbOff + 4) =
        &PTR_LAB_009cbb74;
    *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(self) + vbOff) = vbOff + -0x4fc;
  }

  *reinterpret_cast<uint8_t*>(self + 0x40) = 1;
  self[0x42] = DAT_009cb8c0;
  self[0x43] = DAT_009cb8c4;
  self[0x44] = DAT_009cb8c8;
  uint32_t uCb8cc = DAT_009cb8cc;
  local_4 = 1;
  *reinterpret_cast<uint16_t*>(self + 0x4f) = 1;
  *reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(self) + 0x13e) = 1;
  *reinterpret_cast<uint16_t*>(self + 0x50) = 1;
  *reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(self) + 0x142) = 1;
  self[0x45] = uCb8cc;
  self[0x49] = uAaa7a4;

  float fOne = g_flOne;
  self[0x46] = 0;
  self[0x48] = 0;
  self[0x4a] = 0xffffffffu;
  *reinterpret_cast<uint16_t*>(self + 0x4b) = 0;
  *reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(self) + 0x12e) = 10;
  self[0x4c] = *reinterpret_cast<uint32_t*>(&fOne);
  self[0x4d] = 0;
  self[0x4e] = 0;
  *reinterpret_cast<uint16_t*>(self + 0x51) = 0;
  *reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(self) + 0x146) = 0;
  *reinterpret_cast<uint16_t*>(self + 0x52) = 0;
  *reinterpret_cast<uint16_t*>(reinterpret_cast<uint8_t*>(self) + 0x14a) = 0;
  *reinterpret_cast<uint8_t*>(self + 0x53) = 0;
  self[0x54] = 0;

  int* mapHead = reinterpret_cast<int*>(FUN_0058d9c0());
  self[0x56] = reinterpret_cast<uint32_t>(mapHead);
  *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(mapHead) + 0x29) = 1;
  *reinterpret_cast<uint32_t*>(self[0x56] + 4) = self[0x56];
  *reinterpret_cast<uint32_t*>(self[0x56]) = self[0x56];
  *reinterpret_cast<uint32_t*>(self[0x56] + 8) = self[0x56];

  self[0x57] = 0;
  self[0x58] = 0;
  self[0x6f] = 0;
  self[0x70] = 0;
  self[0x71] = 0;
  self[0x73] = 0;
  self[0x74] = 0;
  self[0x75] = 0;
  fOne = g_flOne;
  self[0x76] = 0;
  self[0x77] = 0;
  self[0x78] = 0;
  self[0x79] = 0;
  self[0x7a] = *reinterpret_cast<uint32_t*>(&fOne);
  self[0x7b] = 0;
  self[0x7d] = 0;
  self[0x7f] = 0;
  self[0x80] = 0;
  *reinterpret_cast<uint8_t*>(self + 0x81) = 0;
  *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(self) + 0x205) = 0;
  *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(self) + 0x206) = 0;
  *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(self) + 0x207) = 0;
  self[0x82] = 0;
  self[0x84] = 0xffffffffu;
  self[0x85] = 0xffffffffu;
  self[0x86] = 0xffffffffu;
  self[0x87] = 0xffffffffu;
  self[0x88] = 0xffffffffu;
  self[0x89] = 0xffffffffu;
  self[0x8a] = DAT_009cb8c0;
  self[0x8b] = DAT_009cb8c4;
  self[0x8c] = DAT_009cb8c8;
  uCb8cc = DAT_009cb8cc;
  self[0x97] = 0;
  self[0x98] = 0;
  self[0x99] = 0;
  self[0x9a] = 0;
  const uint32_t uA0f524 = DAT_00a0f524;
  self[0x8d] = uCb8cc;
  self[0x94] = 0;
  self[0x95] = 0;
  self[0x96] = 0;
  *reinterpret_cast<uint8_t*>(self + 0x9b) = 0;
  self[0x9c] = uA0f524;
  self[0x9d] = uA0f524;
  *reinterpret_cast<uint8_t*>(self + 0x9e) = 0;
  *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(self) + 0x279) = 0;
  self[0xb9] = 0;
  self[0xba] = 0;
  self[0xbb] = 0;
  self[0xbe] = 0;
  self[0xbf] = 0;
  self[0xc0] = 0;
  const uint32_t uAaaa24 = DAT_00aaaa24;
  local_4 = (local_4 & 0xffffff00u) | 6u;
  *reinterpret_cast<uint8_t*>(self + 0xc1) = 0;
  *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(self) + 0x305) = 0;
  *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(self) + 0x306) = 0;
  *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(self) + 0x307) = 0;
  *reinterpret_cast<uint8_t*>(self + 0xc2) = 0;
  *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(self) + 0x309) = 1;
  *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(self) + 0x30a) = 0;
  *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(self) + 0x30b) = 0;
  *reinterpret_cast<uint8_t*>(self + 0xc3) = 0;
  self[0xc4] = uAaaa24;
  *reinterpret_cast<uint8_t*>(self + 0xc5) = 0;
  *reinterpret_cast<uint8_t*>(reinterpret_cast<uint8_t*>(self) + 0x315) = 0;
  self[0xc6] = 0;

  FUN_0096e0e0();

  self[0x90] = 0;
  self[0x91] = 0;
  self[0x92] = 0;
  self[0x93] = 0;
  self[0x59] = 0;
  self[0x5a] = 0;
  self[0x5b] = 0;
  self[0x5c] = 0;
  self[0x5d] = 0;
  self[0x5e] = 0;
  self[0x5f] = 0;
  self[0x60] = 0;
  self[0x61] = 0;
  local_4 = (local_4 & 0xffffff00u) | 7u;
  self[0x62] = 0;
  self[0x63] = 0; // param_1[99]
  self[0x64] = 0; // param_1[100]
  self[0x65] = 0;
  self[0x66] = 0;
  self[0x67] = 0;
  self[0x68] = 0;
  self[0x69] = 0;
  self[0x6a] = 0;
  self[0x6b] = 0;
  self[0x6c] = 0;
  self[0x6d] = 0;
  self[0xc7] = 0; // param_1[199]
  self[0xc8] = 0; // param_1[200]
  self[0xc9] = 0;
  self[0xca] = 0;
  self[0xcb] = 0;
  self[0xcc] = 0;
  self[0xcd] = 0;
  self[0xce] = 0;
  self[0xcf] = 0;
  self[0xd0] = 0;
  self[0xd1] = 0;
  self[0xd2] = 0;
  self[0xd3] = 0;
  self[0xd4] = 0;
  self[0xd5] = 0;
  self[0xd6] = 0;
  self[0xd7] = 0;
  self[0xd8] = 0;
  self[0xd9] = 0;
  self[0xda] = 0;
  self[0xdb] = 0;
  self[0xdc] = 0;
  self[0xdd] = 0;
  self[0xde] = 0;

  void* pv = operator_new(0x60);
  local_4 = (local_4 & 0xffffff00u) | 8u;
  uint32_t subObj = 0;
  if (pv != nullptr) {
    subObj = reinterpret_cast<uint32_t>(FUN_005d55f0(self, 0));
  }
  self[0x3e] = subObj;

  self[0xb7] = 0xffffffffu;
  self[0xa0] = 0;
  self[0xa1] = 0;
  self[0xa2] = 0;
  self[0xa3] = 0;
  self[0x9f] = 0;
  self[0x47] = 0;
  *reinterpret_cast<uint8_t*>(self + 0x13) = 0;
  self[0x2e] = 0;

  // Twin zero loop: 0x13 iterations writing *pu and *(pu-0x89)
  uint32_t* pu = self + 0xa4;
  int n = 0x13;
  do {
    pu[-0x89] = 0;
    *pu = 0;
    ++pu;
    --n;
  } while (n != 0);

  *reinterpret_cast<uint8_t*>(self + 0xbc) = 0;

  ExceptionList = local_c;
  return self;
}
