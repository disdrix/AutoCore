// =============================================================================
// FUN_0096c8e0 — twin of EffTextureImpl_ReleaseGpu_Unaccount_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0096c8e0
// Address:   0x0096c8e0–0x0096ca5a exclusive (378 B / 0x17A)
// Wave:      W38-AB 2026-08-04
// See:       EffTextureImpl_ReleaseGpu_Unaccount_Inferred.cpp
// =============================================================================

#include <cstdint>

struct IUnknownVtbl {
  void* QueryInterface;
  void* AddRef;
  int (__stdcall *Release)(void* self);
};

struct IUnknownLike {
  IUnknownVtbl* vtbl;
};

struct EffTextureImpl {
  uint8_t pad00[0x10];
  IUnknownLike* d3dTex;       // +0x10
  IUnknownLike* rtSurface;    // +0x14
  IUnknownLike* depthSurface; // +0x18
  uint8_t pad1c[0x10];
  uint32_t flags;             // +0x2c
};

extern uint8_t* DAT_00d1f614;
extern "C" int FUN_0096c730(void);
extern "C" int FUN_0096c810(EffTextureImpl* self);
extern "C" int FUN_0096bb20(void);

static void ReleaseAndNull(IUnknownLike** slot) {
  IUnknownLike* p = *slot;
  if (p != nullptr) {
    p->vtbl->Release(p);
  }
  *slot = nullptr;
}

// __thiscall ECX=self; plain RET; void
extern "C" void __fastcall FUN_0096c8e0(EffTextureImpl* self) {
  if (self->d3dTex != nullptr) {
    const uint32_t flags = self->flags;
    if ((flags & 0x1000u) == 0) {
      if (self->rtSurface == nullptr) {
        if ((flags & 0xfu) == 2) {
          const int bytes = FUN_0096c730();
          if (DAT_00d1f614 != nullptr) {
            *reinterpret_cast<int*>(DAT_00d1f614 + 0x3a0) -= bytes;
            *reinterpret_cast<int*>(DAT_00d1f614 + 0x358) -= 1;
          }
        } else if ((flags & 0xfu) == 4) {
          const int bytes = FUN_0096c730();
          if (DAT_00d1f614 != nullptr) {
            *reinterpret_cast<int*>(DAT_00d1f614 + 0x3a8) -= bytes;
            *reinterpret_cast<int*>(DAT_00d1f614 + 0x360) -= 1;
          }
        } else {
          const int bytes = FUN_0096c730();
          if (DAT_00d1f614 != nullptr) {
            *reinterpret_cast<int*>(DAT_00d1f614 + 0x398) -= bytes;
            *reinterpret_cast<int*>(DAT_00d1f614 + 0x350) -= 1;
          }
        }
      } else {
        if (DAT_00d1f614 != nullptr) {
          *reinterpret_cast<int*>(DAT_00d1f614 + 0x364) -= 1;
        }
        const int bytes = FUN_0096c730();
        uint8_t* stats = DAT_00d1f614;
        if (DAT_00d1f614 != nullptr) {
          *reinterpret_cast<int*>(DAT_00d1f614 + 0x3ac) -= bytes;
        }
        if (self->depthSurface != nullptr && stats != nullptr) {
          *reinterpret_cast<int*>(stats + 0x368) -= 1;
          const int dbytes = FUN_0096bb20();
          *reinterpret_cast<int*>(stats + 0x3b0) -= dbytes;
        }
      }
    } else if ((flags & 0xfu) == 2) {
      const int bytes = FUN_0096c810(self);
      if (DAT_00d1f614 != nullptr) {
        *reinterpret_cast<int*>(DAT_00d1f614 + 0x39c) -= bytes;
        *reinterpret_cast<int*>(DAT_00d1f614 + 0x354) -= 1;
      }
    } else if ((flags & 0xfu) == 4) {
      const int bytes = FUN_0096c810(self);
      if (DAT_00d1f614 != nullptr) {
        *reinterpret_cast<int*>(DAT_00d1f614 + 0x3a4) -= bytes;
        *reinterpret_cast<int*>(DAT_00d1f614 + 0x35c) -= 1;
      }
    } else {
      const int bytes = FUN_0096c810(self);
      if (DAT_00d1f614 != nullptr) {
        *reinterpret_cast<int*>(DAT_00d1f614 + 0x394) -= bytes;
        *reinterpret_cast<int*>(DAT_00d1f614 + 0x34c) -= 1;
      }
    }
  }

  ReleaseAndNull(&self->d3dTex);
  ReleaseAndNull(&self->rtSurface);
  ReleaseAndNull(&self->depthSurface);
}
