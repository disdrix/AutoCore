// =============================================================================
// SpeedTreeRT_ComputeTree_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005b7250
// Address:   0x005b7250–0x005b76e5  (autoassault.exe, image base 0x400000)
// System:    graphics / SpeedTreeRT tree compute
// Generated: 2026-07-23 scaffold as FUN_005b7250; dual A/B seal 2026-07-29 (W34-A)
// Exactness: Behavior-preserving rewrite of decompiler + prologue/epilogue bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Bind asset config (this+0x174), ensure SpeedTreeRT instance (this+0x30, 0x9c),
//   and either (a) first-time load+compute from resource (param_2) when
//   *(asset_cfg+0x128) < 1, or (b) refresh path FUN_005b71a0(1). Success builds
//   bounds, LOD scalars (span * 5.0f), material block, optional .dds textures.
//
// ABI (bytes):
//   thiscall ECX=this; 5 stack formals; RET 0x14; returns uint8_t AL.
//   Body 1173 B (0x495). SEH LAB_009a6a98.
//
// PLATES:
//   "SpeedTreeRT Error: %s\n"
//   "\nFatal Error, cannot compute tree [%s]\n\n"
//
// CONSTANTS:
//   DAT_00a2c53c = ".dds"
//   DAT_00aaa688 = 5.0f
//   0x3f800000 / 0xbf800000 = 1.0f / -1.0f
//
// CALLERS:
//   FUN_00582090 @ 0x00582222 and 0x00582265 (sprintf "%s.spt")
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
extern "C" void* FUN_005b4600(void* /* out string path stage */);
extern "C" void* FUN_00416490(void* out, void* lhs, const char* cstr);
extern "C" void* FUN_00404ba0(const char*);
extern "C" void  FUN_0096f3e0(void*, uint32_t);
extern "C" void  FUN_005b71a0(int);
extern "C" void  FUN_007a4480(int, const char*, void*);
extern "C" void* operator_new(uint32_t);

static constexpr float kLodSpanScale = 5.0f;   // DAT_00aaa688 @ 0x00aaa688
static constexpr const char* kDdsExt = ".dds";  // DAT_00a2c53c

extern "C" uint8_t __thiscall SpeedTreeRT_ComputeTree_Inferred(
    void* self,
    void* resource_key,
    int* asset_cfg,
    void* compute_arg,
    float size_a,
    float size_b)
{
  // SEH LAB_009a6a98; SUB ESP,0xB8; ESI=this
  *reinterpret_cast<int**>(static_cast<char*>(self) + 0x174) = asset_cfg;
  if (asset_cfg == nullptr) {
    return 0;
  }

  if (*reinterpret_cast<void**>(static_cast<char*>(self) + 0x30) == nullptr) {
    void* mem = operator_new(0x9c);
    *reinterpret_cast<void**>(static_cast<char*>(self) + 0x30) =
        mem ? FUN_0068a690() : nullptr;
  }

  FUN_00685ed0(1);

  // Refresh path when asset already computed / refcount >= 1
  if (*reinterpret_cast<int*>(reinterpret_cast<char*>(asset_cfg) + 0x128) >= 1) {
    FUN_005b71a0(1);
    return 1;
  }

  // First compute: open resource, load into ST, configure, compute tree
  FUN_007b6a20(resource_key);
  int* res = static_cast<int*>(FUN_007b7420(resource_key));
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

  FUN_00686d30(0x3f800000u, 0xbf800000u, 0xbf800000u);  // 1, -1, -1
  FUN_00686ec0(0, 4);
  FUN_00686530(0);
  FUN_00686640(0);
  FUN_00686760(0);
  FUN_00686ad0(0);
  FUN_006869c0(0);
  FUN_00686c00(0);
  FUN_006868b0(1);
  if (size_a >= 0.0f && size_b >= 0.0f) {
    FUN_006863a0(size_a, size_b);
  }

  if (FUN_00688680(0, compute_arg, 1) == '\0') {
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
  FUN_00685c80(dx, dx * kLodSpanScale);

  void* mat_mem = operator_new(0x1c);
  *reinterpret_cast<void**>(static_cast<char*>(self) + 0x34) =
      mat_mem ? FUN_00685ac0() : nullptr;
  FUN_00689d90(*reinterpret_cast<void**>(static_cast<char*>(self) + 0x34));

  // Optional texture holder @ +0x170 from material primary name + ".dds"
  if (*reinterpret_cast<void**>(static_cast<char*>(self) + 0x170) == nullptr) {
    void* h = operator_new(4);
    *reinterpret_cast<void**>(static_cast<char*>(self) + 0x170) =
        h ? FUN_0096ef70() : nullptr;

    void* mat = *reinterpret_cast<void**>(static_cast<char*>(self) + 0x34);
    // decompiler: (char*)**(undefined4**)(this+0x34)
    char* base_name = *reinterpret_cast<char**>(mat);
    std::string src(base_name);
    std::string staged;
    void* mid = FUN_005b4600(&staged);
    std::string with_ext;  // FUN_00416490(out, mid, ".dds")
    (void)FUN_00416490(&with_ext, mid, kDdsExt);
    void* tok = FUN_00404ba0(with_ext.c_str());
    FUN_0096f3e0(tok, 0);
    (void)src;
  }

  // Optional texture holder @ +0x24 from material +0x14 name + ".dds"
  if (*reinterpret_cast<void**>(static_cast<char*>(self) + 0x24) == nullptr) {
    void* h = operator_new(4);
    *reinterpret_cast<void**>(static_cast<char*>(self) + 0x24) =
        h ? FUN_0096ef70() : nullptr;

    void* mat = *reinterpret_cast<void**>(static_cast<char*>(self) + 0x34);
    char* name2 = *reinterpret_cast<char**>(static_cast<char*>(mat) + 0x14);
    std::string src(name2);
    std::string staged;
    void* mid = FUN_005b4600(&staged);
    std::string with_ext;
    (void)FUN_00416490(&with_ext, mid, kDdsExt);
    void* tok = FUN_00404ba0(with_ext.c_str());
    FUN_0096f3e0(tok, 0);
    (void)src;
  }

  FUN_005b71a0(0);
  return 1;
}

extern "C" uint8_t __thiscall FUN_005b7250(
    void* self, void* p2, int* p3, void* p4, float p5, float p6)
{
  return SpeedTreeRT_ComputeTree_Inferred(self, p2, p3, p4, p5, p6);
}
