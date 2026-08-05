// =============================================================================
// GfxView_Ctor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0075ceb0
// Address:   0x0075ceb0  (autoassault.exe, image base 0x400000)
// System:    graphics / client camera (GfxView)
// Generated: 2026-07-29 W31-O (OWN-ONLY dual A/B)
// Exactness: Behavior-preserving rewrite of decompiler CF + read_memory constants.
// Bit-for-bit vs retail EXE: DEFERRED (not run). Nested D3D helpers unresolved.
// =============================================================================
//
// PURPOSE: Construct GfxView (product path gfxView.cpp) on pre-allocated 0x150.
//
// ABI: ECX = this; no stack formals; returns this; SEH LAB_009b25d7;
//      epilogue ADD ESP,0x2C; RET. Body 0x0075ceb0–0x0075d1fc (0x54D B).
//
// Evidence strings:
//   C:\vog\1_code\palantir\palantir\graphics\gfxView.cpp
//   "Failed to Create Background Vertex Buffer" (line 0x45)
//   "Failed to create view background effect" (line 0x48)
//   "PalViewBackground.fx"
//   c:\VOGCRASH.txt / ExitProcess(3) on hard fail
//
// Defaults (read_memory):
//   g_flOne      @ 0x00a0f2a0 = 1.0     → +0x0C zoom
//   DAT_00a0f298 @ 0x00a0f298 = 0.5     → +0xF0 near
//   DAT_00aaa880 @ 0x00aaa880 = 10000.0 → +0xF4 far
//   DAT_00a0f520 @ 0x00a0f520 = 1000.0  → +0x104
//   DAT_00aaa628 @ 0x00aaa628 = π/3     → +0x10C FOV
//   DAT_00afdf70              identity 4×4 seed for two matrix allocs
//
// Callers: FUN_004cda90 (new 0x150), FUN_00968a50 (new 0x198 path also uses sibling).
// Pair: GfxView_SetNear_Inferred (0x0075b3b0), GfxView_EnsureProjection (0x0075b7f0).
//

#include <cstdint>
#include <cstdio>
#include <cstdlib>

extern float g_flOne;           // 1.0
extern float DAT_00a0f298;      // 0.5 near default
extern float DAT_00aaa880;      // 10000 far default
extern float DAT_00a0f520;      // 1000 → +0x104
extern float DAT_00aaa628;      // π/3 FOV
extern uint32_t DAT_00afdf0c;   // -1
extern uint32_t DAT_00afdf70[]; // identity 4×4 (16 dwords)
extern uint32_t DAT_00d1f01c, DAT_00d1f020, DAT_00d1f024, DAT_00d1f028;
extern void *PTR_FUN_00a9edc8;
extern void *PTR_FUN_00a9db18;
extern void *ExceptionList;
extern void *LAB_009b25d7;

extern "C" void *_aligned_malloc(size_t size, size_t alignment);
extern "C" void  FUN_00972cc0(void); // transform ctor on aligned block (return pairing open)
extern "C" void  FUN_0073f590(void *sub); // embedded subobject @ +0x10
extern "C" void *FUN_0043f780(void); // alloc 0x40 (16 floats)
extern "C" uint32_t FUN_00414bc0(uint32_t bytes);
extern "C" int  FUN_00414c20(uint32_t a, uint32_t b, uint32_t c, uint32_t d);
extern "C" void FUN_00414b60(void);
extern "C" void FUN_00989e00(void *out, const char *name);
extern "C" int  FUN_009701d0(void *effectName);
extern "C" int  FUN_0076d1b0(const char *file, int line, const char *msg);
extern "C" void raise(int sig);
extern "C" void ExitProcess(uint32_t code);

// Retail returns this pointer
extern "C" void *__fastcall GfxView_Ctor_Inferred(void *selfRaw)
{
  uint32_t *self = static_cast<uint32_t *>(selfRaw);
  float one = g_flOne;

  // SEH frame (ExceptionList / LAB_009b25d7) — structure preserved abstractly
  void *savedExc = ExceptionList;
  ExceptionList = &savedExc; // schematic; retail uses full FS frame

  self[0] = reinterpret_cast<uint32_t>(&PTR_FUN_00a9edc8); // vtbl
  self[1] = 0;
  self[2] = 0;
  *reinterpret_cast<float *>(&self[3]) = one; // +0x0C zoom

  void *xf = _aligned_malloc(0xC0, 0x10);
  uint32_t xfPtr = 0;
  if (xf != nullptr) {
    FUN_00972cc0();
    // retail: transform pointer recovered (decompiler extraout_EDX)
    xfPtr = reinterpret_cast<uint32_t>(xf); // port note: verify EAX/EDX pairing live
  }
  self[2] = xfPtr; // +0x08

  FUN_0073f590(self + 4); // +0x10 subobject

  self[0x11] = 0;                                   // +0x44
  *reinterpret_cast<uint8_t *>(self + 0x12) = 1;    // +0x48 dirty
  *reinterpret_cast<uint8_t *>(reinterpret_cast<uint8_t *>(self) + 0x49) = 1;
  self[0x13] = 0xFFFFFFFFu;                         // +0x4C

  // Two identity matrix allocations → +0x50 / +0x54
  for (int slot = 0x14; slot <= 0x15; ++slot) {
    uint32_t *mat = static_cast<uint32_t *>(FUN_0043f780());
    if (mat != nullptr) {
      const uint32_t *src = DAT_00afdf70;
      uint32_t *dst = mat;
      for (int i = 0; i < 0x10; ++i) {
        *dst++ = *src++;
      }
    }
    self[slot] = reinterpret_cast<uint32_t>(mat);
  }

  self[0x16] = 0;
  self[0x30] = 0;
  self[0x31] = 0;
  self[0x32] = 0;
  *reinterpret_cast<uint8_t *>(self + 0x33) = 1;    // +0xCC dirty
  self[0x34] = 0xFFFFFFFFu;
  self[0x36] = 0;
  self[0x35] = reinterpret_cast<uint32_t>(&PTR_FUN_00a9db18);

  *reinterpret_cast<float *>(&self[0x3c]) = DAT_00a0f298; // +0xF0 near 0.5
  *reinterpret_cast<float *>(&self[0x3d]) = DAT_00aaa880; // +0xF4 far 10000
  self[0x37] = DAT_00d1f01c; // +0xDC
  self[0x38] = DAT_00d1f020;
  self[0x39] = DAT_00d1f024;
  self[0x3a] = DAT_00d1f028;
  self[0x3b] = 0; // +0xEC mode persp
  self[0x3e] = 0;
  self[0x3f] = 0;
  self[0x40] = 0;
  *reinterpret_cast<float *>(&self[0x41]) = DAT_00a0f520; // +0x104 = 1000
  self[0x42] = 0;
  *reinterpret_cast<float *>(&self[0x43]) = DAT_00aaa628; // +0x10C FOV π/3
  self[0x44] = 0;
  self[0x45] = 0;
  self[0x46] = 0;
  self[0x47] = 0;
  self[0x48] = 0;
  self[0x49] = 0;
  *reinterpret_cast<uint8_t *>(self + 0x4a) = 0;
  *reinterpret_cast<uint8_t *>(reinterpret_cast<uint8_t *>(self) + 0x129) = 0;
  self[0x4c] = 0;
  self[0x4b] = reinterpret_cast<uint32_t>(&PTR_FUN_00a9db18);
  self[0x4d] = 0;
  *reinterpret_cast<uint8_t *>(self + 0x4e) = 0;
  *reinterpret_cast<uint8_t *>(reinterpret_cast<uint8_t *>(self) + 0x139) = 0;
  *reinterpret_cast<uint8_t *>(reinterpret_cast<uint8_t *>(self) + 0x13a) = 0;
  self[0x4f] = 0;
  self[0x50] = 0;
  self[0x51] = 0;
  self[0x52] = DAT_00afdf0c; // +0x148 = -1
  *reinterpret_cast<uint8_t *>(self + 0x53) = 0;
  *reinterpret_cast<uint8_t *>(reinterpret_cast<uint8_t *>(self) + 0x14d) = 0;

  uint32_t vb = FUN_00414bc0(0x144);
  int hr = FUN_00414c20(4, vb, 3, 0);
  FUN_00414b60();

  const char *failMsg = nullptr;
  uint32_t failLine = 0;

  if (hr < 0) {
    int r = FUN_0076d1b0(
        "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxView.cpp",
        0x45,
        "Failed to Create Background Vertex Buffer");
    if (r == 3) {
      failMsg = "Failed to Create Background Vertex Buffer";
      failLine = 0x45;
    }
  }

  if (failMsg == nullptr) {
    uint8_t effectName[4];
    FUN_00989e00(effectName, "PalViewBackground.fx");
    hr = FUN_009701d0(effectName);
    if (hr < 0) {
      int r = FUN_0076d1b0(
          "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxView.cpp",
          0x48,
          "Failed to create view background effect");
      if (r == 3) {
        failMsg = "Failed to create view background effect";
        failLine = 0x48;
      }
    }
  }

  if (failMsg == nullptr) {
    self[0x10] = reinterpret_cast<uint32_t>(self); // +0x40 self back-ptr
    uint32_t *p = self + 0x17; // +0x5C
    for (int i = 0; i < 0x18; ++i) {
      *p++ = 0;
    }
    ExceptionList = savedExc;
    return self;
  }

  FILE *f = fopen("c:\\VOGCRASH.txt", "w");
  if (f != nullptr) {
    fprintf(f,
            "errReport::Massive failure EH_Abort: F:%s l:%d s:%d d:%s\n",
            "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxView.cpp",
            static_cast<int>(failLine),
            3,
            failMsg);
    fclose(f);
  }
  raise(0x16);
  ExitProcess(3);
  return nullptr; // unreachable
}

// Ghidra twin symbol
extern "C" void *__fastcall FUN_0075ceb0(void *self)
{
  return GfxView_Ctor_Inferred(self);
}
