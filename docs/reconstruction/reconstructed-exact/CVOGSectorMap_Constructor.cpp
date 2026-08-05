// =============================================================================
// CVOGSectorMap_Constructor
// -----------------------------------------------------------------------------
// Stable ID: aa_004d8a10
// Address:   0x004d8a10–0x004d938f  (autoassault.exe, image base 0x400000)
// System:    client / CVOGSectorMap
// Generated: 2026-07-29 W24-F dual seal (decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler CF + byte ABI seals.
//            Not modernization. Full per-store listing remains in raw capture.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   CVOGSectorMap C++ constructor. Caller Client_InitInstance does
//   operator_new(0xE920) after string "@@new CVOGSectorMap", then this.
//   Installs vtbl PTR_FUN_009cc770, inits embedded trees/locks/flags,
//   heap-allocates subsystem objects, publishes global _DAT_00b03600=this.
//
// ABI:
//   __thiscall; ECX=this; bare ret; EAX=this.
//   Ghidra surface: undefined4 * __fastcall FUN_004d8a10(undefined4 *param_1)
//
// CALLEES: FUN_004e7450×4, FUN_004e7420×2, InitializeCriticalSection×N,
//   operator_new, GetTickCount, many subsystem factories (see raw).
// CALLERS: Client_InitInstance (FUN_0094a6a0) only
// =============================================================================

#include <cstdint>
#include <windows.h>

// External callees (Ghidra names until product duals exist).
extern "C" void FUN_004e7450(void);           // RbTree_InitEmptyHeader (thiscall on ECX)
extern "C" void FUN_004e7420(void);           // RbTree_InitEmptyHeader_Node1c
extern "C" uint32_t FUN_004e28c0(void);
extern "C" uint32_t FUN_004e2920(void);
extern "C" void FUN_004e5840(int);
extern "C" uint32_t FUN_00671610(void);
extern "C" void FUN_00589b00(void);
extern "C" uint32_t FUN_005b43b0(void);
extern "C" uint32_t FUN_004e59b0(int);
extern "C" uint32_t FUN_004e5a30(int);
extern "C" uint32_t FUN_004e5b50(int);
extern "C" uint32_t FUN_004e5c90(int);
extern "C" uint32_t FUN_004e5d10(int);
extern "C" uint32_t FUN_004e5e10(int);
extern "C" uint32_t FUN_004e5f10(int);
extern "C" uint32_t FUN_004e6010(int);
extern "C" uint32_t FUN_004e6190(int);
extern "C" uint32_t FUN_004e62d0(int);
extern "C" uint32_t FUN_004e6410(int);
extern "C" uint32_t FUN_005abfa0(void* self);
extern "C" uint32_t FUN_005b0650(void* self);
extern "C" uint32_t FUN_004bff60(void);
extern "C" void FUN_004e4620(int);
extern "C" void FUN_00418e60(uint32_t a, int b, void* c);
extern "C" void* operator_new(unsigned size);
extern float g_flOne;
extern uint32_t DAT_00aaaca8;
extern uint32_t DAT_00aaa7ac;
extern void* _DAT_00b03600;
extern uint32_t _DAT_00b037e4;
extern void* PTR_FUN_009cc770;
extern void* PTR_FUN_009cb368;
extern void* PTR_FUN_009cc3e4;
extern void* PTR_FUN_009cc3ec;
extern void* PTR_FUN_009cc3f4;

// Opaque 0xE920 object; dword-index addressing matches decompiler param_1[i].
struct CVOGSectorMap {
  void* vtbl;           // +0x00 → PTR_FUN_009cc770
  uint32_t raw[0x3A48]; // remainder; see raw for per-index stores
};

static uint32_t* new_lock44(void* vtbl) {
  uint32_t* p = (uint32_t*)operator_new(0x44);
  if (!p) return nullptr;
  p[0] = (uint32_t)vtbl;
  p[1] = 0;
  p[2] = 0;
  p[3] = 0;
  p[0x10] = 0xFFFFFFFFu;
  InitializeCriticalSection((LPCRITICAL_SECTION)(p + 4));
  InitializeCriticalSection((LPCRITICAL_SECTION)(p + 10));
  return p;
}

static uint32_t new_node34(uint32_t (*init)(int), int arg) {
  void* pv = operator_new(0x34);
  if (!pv) return 0;
  return init(arg);
}

// MSVC thiscall: first arg in ECX.
CVOGSectorMap* __fastcall CVOGSectorMap_Constructor(CVOGSectorMap* self)
{
  uint32_t* p = (uint32_t*)self;
  float fOne;
  uint32_t uVar2, uVar3;
  DWORD tick;
  uint32_t* pu;
  void* pv;
  int i;

  // --- Phase 1: vtbl + early trees / flags ---
  p[0] = (uint32_t)&PTR_FUN_009cc770;
  p[0xc] = 0;
  // ECX = &self[+0x34]; FUN_004e7450 thiscall
  FUN_004e7450();
  *(uint8_t*)(p + 0x10) = 0;
  FUN_004e7450();
  p[0x15] = 0;
  p[0x16] = 0;
  p[0x17] = 0;
  uVar3 = FUN_004e28c0();
  p[0x19] = uVar3;
  p[0x1a] = 0;
  p[0x1c] = 0;
  *(uint8_t*)(p + 0x1d) = 0;
  p[0x1e] = 0;
  *(uint8_t*)(p + 0x1f) = 0;
  *(uint8_t*)((uint8_t*)p + 0x7d) = 0;
  *(uint8_t*)((uint8_t*)p + 0x7e) = 1;
  *(uint8_t*)((uint8_t*)p + 0x7f) = 0;
  *(uint8_t*)(p + 0x20) = 0;
  *(uint8_t*)((uint8_t*)p + 0x81) = 0;
  *(uint8_t*)((uint8_t*)p + 0x82) = 0;
  *(uint8_t*)((uint8_t*)p + 0x83) = 0;
  p[0x21] = 0;
  p[0x22] = 0;
  p[0x24] = 0;
  p[0x48] = 0;
  p[0x47] = 0;
  p[0x46] = 0;

  // --- Phase 2: mid-object zeros + third tree ---
  p[0x3929] = 0;
  p[0x392a] = 0;
  p[0x3938] = 0;
  p[0x3939] = 0;
  p[0x393b] = 0;
  p[0x393c] = 0;
  p[0x393d] = 0;
  p[0x393e] = 0;
  p[0x393f] = 0;
  p[0x3940] = 0;
  p[0x3941] = 0;
  FUN_004e7450();
  p[0x394b] = 0;
  p[0x394c] = 0;
  p[0x394d] = 0;
  p[0x394f] = 0;
  p[0x3950] = 0;
  p[0x3951] = 0;
  p[0x3953] = 0;
  p[0x3954] = 0;
  p[0x3955] = 0;
  FUN_004e5840(2);
  FUN_004e5840(2);
  p[0x3978] = 0;
  p[0x3979] = 0;
  p[0x397a] = 0;
  uVar3 = FUN_00671610();
  p[0x397c] = uVar3;
  p[0x397d] = 0;

  // --- Phase 3: embedded lock objects + critical sections ---
  p[0x3980] = (uint32_t)&PTR_FUN_009cb368;
  p[0x3981] = 0;
  p[0x3982] = 0;
  p[0x3983] = 0;
  p[0x3990] = 0xFFFFFFFFu;
  InitializeCriticalSection((LPCRITICAL_SECTION)(p + 0x3984));
  InitializeCriticalSection((LPCRITICAL_SECTION)(p + 0x398a));
  p[0x3994] = (uint32_t)&PTR_FUN_009cc3e4;
  p[0x3995] = 0;
  p[0x3996] = 0;
  p[0x3997] = 0;
  p[0x39a4] = 0xFFFFFFFFu;
  InitializeCriticalSection((LPCRITICAL_SECTION)(p + 0x3998));
  InitializeCriticalSection((LPCRITICAL_SECTION)(p + 0x399e));
  p[0x39a5] = (uint32_t)&PTR_FUN_009cc3ec;
  p[0x39a6] = 0;
  p[0x39a7] = 0;
  p[0x39a8] = 0;
  p[0x39b5] = 0xFFFFFFFFu;
  InitializeCriticalSection((LPCRITICAL_SECTION)(p + 0x39a9));
  InitializeCriticalSection((LPCRITICAL_SECTION)(p + 0x39af));
  p[0x39b6] = 1;
  p[0x39b7] = 0;
  p[0x39b8] = 0xFFFFFFFFu;
  p[0x39b9] = 0;
  p[0x39ba] = 0xFFFFFFFFu;
  p[0x39bb] = 0x7FFFFFFF;
  p[0x39bd] = 0;
  p[0x39be] = 0;
  p[0x39bf] = 0;
  p[0x39c1] = 0;
  p[0x39c2] = 0;
  p[0x39c3] = 0;
  uVar3 = FUN_004e2920();
  p[0x39c5] = uVar3;
  p[0x39c6] = 0;
  p[0x39c8] = 0;
  p[0x39c9] = 0;
  p[0x39ca] = 0;
  p[0x39cc] = 0;
  p[0x39cd] = 0;
  p[0x39ce] = 0;
  FUN_00589b00();
  p[0x39d3] = 0;
  p[0x39d4] = 0;
  p[0x39d5] = 0;
  p[0x39d7] = 0;
  p[0x39d8] = 0;
  p[0x39d9] = 0;
  p[0x39db] = 0;
  p[0x39dc] = 0;
  p[0x39dd] = 0;
  uVar3 = FUN_005b43b0();
  p[0x39df] = uVar3;
  p[0x39e0] = 0;
  p[0x39e2] = 0;
  p[0x39e3] = 0;
  p[0x39e4] = 0;
  p[0x39e6] = 0;
  p[0x39e7] = 0;
  p[0x39e8] = 0;
  p[0x39ea] = 0;
  p[0x39eb] = 0;
  p[0x39ec] = 0;
  p[0x39f6] = 0xFFFFFFFFu;
  p[0x39f7] = 0xFFFFFFFFu;
  p[0x39f8] = 0xFFFFFFFFu;
  p[0x39f9] = 0xFFFFFFFFu;
  p[0x39fa] = 0xFFFFFFFFu;
  p[0x39fb] = 0xFFFFFFFFu;
  p[0x39fc] = 0xFFFFFFFFu;
  p[0x39fd] = 0xFFFFFFFFu;
  p[0x39ff] = 0;
  p[0x3a00] = 0;
  p[0x3a01] = 0;
  p[0x3a03] = 0;
  p[0x3a04] = 0;
  p[0x3a05] = 0x80000000;
  FUN_004e7420();
  FUN_004e7420();
  p[0x3a19] = 0;
  p[0x3a1a] = 0;
  p[0x3a1b] = 0;
  p[0x3a1d] = 0;
  p[0x3a1e] = 0;
  p[0x3a1f] = 0;
  p[0x3a21] = 0;
  p[0x3a22] = 0;
  p[0x3a23] = 0;
  p[0x3a28] = 0;
  p[0x3a2a] = 0;
  p[0x3a2b] = 0;
  p[0x3a2c] = 0;
  p[0x3a2f] = 0;
  p[0x3a30] = 0;
  p[0x3a31] = 0;
  p[0x3a33] = 0;
  p[0x3a34] = 0;
  p[0x3a35] = 0;
  uVar3 = FUN_00671610();
  p[0x3a37] = uVar3;
  p[0x3a38] = 0;
  uVar3 = FUN_00671610();
  p[0x3a3a] = uVar3;
  p[0x3a3b] = 0;
  FUN_004e7450();
  fOne = g_flOne;
  p[0x3a42] = 0;
  p[0x3a43] = 0;
  p[0x3a44] = 0;
  p[0x3a45] = 0;
  p[4] = 0;
  p[5] = 0;
  p[6] = 0;
  p[7] = 0;
  p[8] = 0;
  p[9] = 0;
  p[10] = 0;
  p[0xb] = 0;
  p[0x3a0e] = *(uint32_t*)&fOne;
  p[0x3a0f] = *(uint32_t*)&fOne;
  p[0x3a10] = *(uint32_t*)&fOne;
  p[0x3a11] = *(uint32_t*)&fOne;
  p[0x3a02] = 0xFFFFFFFFu;
  tick = GetTickCount();
  uVar2 = DAT_00aaaca8;
  uVar3 = DAT_00aaa7ac;
  p[0x1b] = tick;
  p[0x392c] = 0;
  p[0x392d] = 0;
  p[0x392e] = 0;
  p[0x392f] = 0;
  p[0x3930] = uVar2;
  p[0x3932] = uVar2;
  fOne = g_flOne;
  p[0x3931] = uVar3;
  p[0x3933] = 0;
  p[0x3937] = 0;
  p[0x3936] = 0;
  p[0x3935] = 0;
  p[0x3934] = 0;
  p[0x3937] = *(uint32_t*)&fOne;
  p[0x39f4] = 0x20;
  p[0x39f5] = 0;
  p[0x25] = 0;

  // --- Phase 4: heap lock wrappers + bulk zero ---
  p[0x397f] = (uint32_t)new_lock44(&PTR_FUN_009cb368);
  p[0x3991] = (uint32_t)new_lock44(&PTR_FUN_009cb368);
  pu = p + 0x3254;
  for (i = 0x612; i != 0; --i) {
    *pu++ = 0;
  }
  p[0x26] = 0x2005;
  *(uint16_t*)(p + 0x250) = 0;
  p[0x49] = 0;
  *(uint8_t*)((uint8_t*)p + 0xf6) = 0;
  *(uint8_t*)((uint8_t*)p + 0xf5) = 0;
  p[0x29] = 1;
  p[0x3e] = 0xFFFFFFFFu;
  p[0x2c] = 0xFFFFFFFFu;
  p[0x2b] = 0;
  p[0x28] = 0xFFFFFFFFu;
  *(uint8_t*)(p + 0x2d) = 0;
  *(uint8_t*)(p + 0x2a) = 1;
  p[0x3f] = 0xFFFFFFFFu;
  p[0x42] = 0xFFFFFFFFu;
  *(uint8_t*)(p + 0x3866) = 0;
  *(uint8_t*)(p + 0x38a7) = 0;
  *(uint8_t*)(p + 0x38e8) = 0;

  // --- Phase 5: typed 0x34 nodes + large subsystems ---
  p[0x3970] = new_node34(FUN_004e59b0, 8);
  p[0x3948] = new_node34(FUN_004e5a30, 8);
  p[0x3949] = new_node34(FUN_004e5b50, 3);
  p[0x3947] = new_node34(FUN_004e5c90, 4);
  p[0x3971] = new_node34(FUN_004e5d10, 5);
  p[0x3972] = new_node34(FUN_004e5e10, 5);
  p[0x3973] = new_node34(FUN_004e5f10, 3);
  p[0x3974] = new_node34(FUN_004e6010, 3);
  p[0x3975] = new_node34(FUN_004e6190, 3);
  p[0x3976] = new_node34(FUN_004e62d0, 3);

  pv = operator_new(0x5118);
  p[0x3943] = pv ? FUN_005abfa0(self) : 0;
  pv = operator_new(0x40);
  p[0x3942] = pv ? FUN_005b0650(self) : 0;

  p[0x39ed] = 0;
  p[0x39ee] = 0;
  p[0x39ef] = 0;
  p[0x39f0] = 0;
  p[0x39f1] = 0;
  *(uint8_t*)(p + 0x39f2) = 0;
  *(uint8_t*)((uint8_t*)p + 0xe7c9) = 0;
  p[0x39f3] = 0;
  p[0x3a25] = 0;
  p[0x3a26] = 0;
  p[0x3a3c] = 0;
  p[0x3a3d] = new_node34(FUN_004e6410, 3);
  pv = operator_new(0x70);
  p[0x3a45] = pv ? FUN_004bff60() : 0;

  _DAT_00b03600 = self;

  p[0x3992] = (uint32_t)new_lock44(&PTR_FUN_009cb368);
  p[0x3993] = (uint32_t)new_lock44(&PTR_FUN_009cb368);
  p[0x397e] = (uint32_t)new_lock44(&PTR_FUN_009cc3f4);
  p[0x3a06] = 0;
  p[0x3a0a] = 0;
  p[0x393a] = 0;
  p[0x3a27] = 0;

  // --- Phase 6: tail bring-up ---
  FUN_004e4620(0x20);
  {
    uint32_t local_8 = 0, local_4 = 0;
    FUN_00418e60(p[0x15], 0x20, &local_8);
    (void)local_4;
  }
  _DAT_00b037e4 = _DAT_00b037e4 + 1;
  p[0x3a07] = 0;
  p[0x3a0b] = 0;
  p[0x3a08] = 0;
  p[0x3a0c] = 0;
  p[0x3a09] = 0;
  p[0x3a0d] = 0;
  return self;
}

// Scaffold alias
extern "C" uint32_t* __fastcall FUN_004d8a10(uint32_t* param_1) {
  return (uint32_t*)CVOGSectorMap_Constructor((CVOGSectorMap*)param_1);
}
