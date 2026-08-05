// =============================================================================
// FUN_005b7250  (Ghidra twin of SpeedTreeRT_ComputeTree_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_005b7250
// Address:   0x005b7250–0x005b76e5  (autoassault.exe, image base 0x400000)
// System:    graphics / SpeedTreeRT tree compute
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W34-A)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   SpeedTreeRT load/compute or refresh (see SpeedTreeRT_ComputeTree_Inferred.cpp).
//   Plates: "SpeedTreeRT Error: %s\n" / "\nFatal Error, cannot compute tree [%s]\n\n".
//
// ABI: thiscall ECX=this; 5 stack formals; RET 0x14; returns uint8_t
// Body: 1173 B; SEH LAB_009a6a98
//

#include <cstdint>
#include <string>

extern "C" void* FUN_0068a690();
extern "C" void  FUN_00685ed0(int);
extern "C" void  FUN_007b6a20(void*);
extern "C" void* FUN_007b7420(void*);
extern "C" char  FUN_0068b360(void*, void*);
extern "C" void* FUN_00685ca0();
extern "C" void  FUN_00686d30(uint32_t, uint32_t, uint32_t);
extern "C" void  FUN_00686ec0(int, int);
extern "C" void  FUN_00686530(int);
extern "C" void  FUN_00686640(int);
extern "C" void  FUN_00686760(int);
extern "C" void  FUN_00686ad0(int);
extern "C" void  FUN_006869c0(int);
extern "C" void  FUN_00686c00(int);
extern "C" void  FUN_006868b0(int);
extern "C" void  FUN_006863a0(float, float);
extern "C" char  FUN_00688680(int, void*, int);
extern "C" void  FUN_00687320(void*);
extern "C" void  FUN_006868a0(int);
extern "C" void  FUN_00685c70(int);
extern "C" void* FUN_00686870();
extern "C" void* FUN_00686890();
extern "C" void* FUN_00686880();
extern "C" void  FUN_005b7770(void*);
extern "C" void  FUN_00685c80(float, float);
extern "C" void* FUN_00685ac0();
extern "C" void  FUN_00689d90(void*);
extern "C" void* FUN_0096ef70();
extern "C" void* FUN_005b4600(void*);
extern "C" void* FUN_00416490(void*, void*, const char*);
extern "C" void* FUN_00404ba0(const char*);
extern "C" void  FUN_0096f3e0(void*, uint32_t);
extern "C" void  FUN_005b71a0(int);
extern "C" void  FUN_007a4480(int, const char*, void*);
extern "C" void* operator_new(uint32_t);

// Avoid bare undefined4 — fixed-width only.
extern "C" uint8_t __thiscall FUN_005b7250(
    int param_1,
    uint32_t param_2,
    int param_3,
    uint32_t param_4,
    float param_5,
    float param_6)
{
  void* self = reinterpret_cast<void*>(param_1);
  *reinterpret_cast<int*>(static_cast<char*>(self) + 0x174) = param_3;
  if (param_3 == 0) {
    return 0;
  }

  if (*reinterpret_cast<int*>(static_cast<char*>(self) + 0x30) == 0) {
    void* mem = operator_new(0x9c);
    uint32_t st = mem ? reinterpret_cast<uint32_t>(FUN_0068a690()) : 0;
    *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x30) = st;
  }

  FUN_00685ed0(1);

  if (*reinterpret_cast<int*>(*reinterpret_cast<int*>(static_cast<char*>(self) + 0x174) + 0x128) >= 1) {
    FUN_005b71a0(1);
    return 1;
  }

  FUN_007b6a20(reinterpret_cast<void*>(param_2));
  int* res = static_cast<int*>(FUN_007b7420(reinterpret_cast<void*>(param_2)));
  if (res == nullptr) {
    return 0;
  }

  uint32_t blob_slot = 0;
  using Vfn = void* (__thiscall*)(void*, void*);
  void** vtbl = *reinterpret_cast<void***>(res);
  void* blob = reinterpret_cast<Vfn>(vtbl[0x34 / 4])(res, &blob_slot);
  void* st = *reinterpret_cast<void**>(static_cast<char*>(self) + 0x30);
  char loaded = FUN_0068b360(blob, st);
  using ReleaseFn = void (__thiscall*)(void*, int);
  reinterpret_cast<ReleaseFn>(vtbl[0])(res, 1);

  if (loaded == '\0') {
    void* err = FUN_00685ca0();
    FUN_007a4480(1, "SpeedTreeRT Error: %s\n", err);
    return 0;
  }

  FUN_00686d30(0x3f800000u, 0xbf800000u, 0xbf800000u);
  FUN_00686ec0(0, 4);
  FUN_00686530(0);
  FUN_00686640(0);
  FUN_00686760(0);
  FUN_00686ad0(0);
  FUN_006869c0(0);
  FUN_00686c00(0);
  FUN_006868b0(1);
  if (param_5 >= 0.0f && param_6 >= 0.0f) {
    FUN_006863a0(param_5, param_6);
  }

  if (FUN_00688680(0, reinterpret_cast<void*>(param_4), 1) == '\0') {
    void* err = FUN_00685ca0();
    FUN_007a4480(1, "\nFatal Error, cannot compute tree [%s]\n\n", err);
    return 0;
  }

  FUN_00687320(static_cast<char*>(self) + 0x8c);
  FUN_006868a0(1);
  FUN_00685c70(1);
  FUN_005b7770(FUN_00686870());
  FUN_005b7770(FUN_00686890());
  FUN_005b7770(FUN_00686880());

  float dx = *reinterpret_cast<float*>(static_cast<char*>(self) + 0xa0)
           - *reinterpret_cast<float*>(static_cast<char*>(self) + 0x94);
  FUN_00685c80(dx, dx * 5.0f);  // DAT_00aaa688

  void* mat_mem = operator_new(0x1c);
  *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x34) =
      mat_mem ? reinterpret_cast<uint32_t>(FUN_00685ac0()) : 0;
  FUN_00689d90(*reinterpret_cast<void**>(static_cast<char*>(self) + 0x34));

  if (*reinterpret_cast<int*>(static_cast<char*>(self) + 0x170) == 0) {
    void* h = operator_new(4);
    *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x170) =
        h ? reinterpret_cast<uint32_t>(FUN_0096ef70()) : 0;
    void* mat = *reinterpret_cast<void**>(static_cast<char*>(self) + 0x34);
    std::string src(*reinterpret_cast<char**>(mat));
    std::string staged;
    void* mid = FUN_005b4600(&staged);
    std::string with_ext;
    (void)FUN_00416490(&with_ext, mid, ".dds");
    FUN_0096f3e0(FUN_00404ba0(with_ext.c_str()), 0);
    (void)src;
  }

  if (*reinterpret_cast<int*>(static_cast<char*>(self) + 0x24) == 0) {
    void* h = operator_new(4);
    *reinterpret_cast<uint32_t*>(static_cast<char*>(self) + 0x24) =
        h ? reinterpret_cast<uint32_t>(FUN_0096ef70()) : 0;
    void* mat = *reinterpret_cast<void**>(static_cast<char*>(self) + 0x34);
    std::string src(*reinterpret_cast<char**>(static_cast<char*>(mat) + 0x14));
    std::string staged;
    void* mid = FUN_005b4600(&staged);
    std::string with_ext;
    (void)FUN_00416490(&with_ext, mid, ".dds");
    FUN_0096f3e0(FUN_00404ba0(with_ext.c_str()), 0);
    (void)src;
  }

  FUN_005b71a0(0);
  return 1;
}
