// =============================================================================
// FillPreloadList
// -----------------------------------------------------------------------------
// Stable ID: aa_004f2540
// Address:   0x004f2540–0x004f26d5  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_004f2540
// System:    client-load / preload pipeline
// Dual:      W32-L 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI:
//   ECX  = load host (name@+0x188, clonebase*@+0x3c,
//          GuardedVectors @+0x110 deps, +0x124 primary, +0x138 anim,
//          +0x14c phy, +0x160 snd)
//   bare RET (C3); returns 0|1 in AL
//
// Plate: FUN_0076cf00("FillPreloadList") — product profiler name sealed.
// Sole caller: CLoadNode__initPreload when clonebase +0x134 == 0.
// =============================================================================

#include <cstdint>

struct GuardedVectorHeader {
  uint32_t _unk00;
  uint32_t** pages;   // +0x04
  uint32_t capacity;  // +0x08
  uint32_t begin;     // +0x0c
  int32_t  size;      // +0x10
};

extern "C" void* DAT_00d1f040;
extern "C" void* DAT_00d1f050;  // global resource / preload manager root
extern "C" uint32_t DAT_009cd088;  // ".spt\0" (first 4)
extern "C" uint8_t  DAT_009cd08c;  // remaining byte of ".spt"

extern "C" void FUN_0076cf00(const char* name /*stack*/);
extern "C" void FUN_0076cef0(void);
// ECX = GuardedVector at self+0x124; stack arg 0
extern "C" void __fastcall FUN_0043d650(GuardedVectorHeader* ring /*ECX*/,
                                        uint32_t clear_mode /*stack*/);
// ECX = self; builds hash key from name@+0x188 into *out
extern "C" uint32_t* __fastcall FUN_004eb1c0(void* self /*ECX*/,
                                             uint32_t* out_key /*stack*/);
// ECX = dep host *(DAT_00d1f050+0x64); stack (key*, ring*); RET 8
extern "C" void __fastcall PreloadDep_CollectTransitiveKeys_Inferred(
    void* dep_host /*ECX*/,
    const int* key /*stack*/,
    GuardedVectorHeader* ring /*stack*/);
// CollectAllGraphicsPreloads — FUN_004f1ff0
extern "C" void __fastcall FUN_004f1ff0(void* self /*ECX*/,
                                        GuardedVectorHeader* gfx_ring /*stack*/);
extern "C" void FUN_00989e00(uint32_t* out_key /*stack*/, const char* path /*stack*/);
extern "C" void __fastcall GuardedVector_PushFront_Thiscall(
    GuardedVectorHeader* container /*ECX*/,
    const uint32_t* value /*stack*/);
extern "C" void __fastcall Anim_CollectAllAnimationPreloads(
    void* self /*ECX*/, GuardedVectorHeader* ring /*stack*/);
extern "C" void __fastcall Phy_CollectAllPhysicsPreloads(
    void* self /*ECX*/, GuardedVectorHeader* ring /*stack*/);
extern "C" void __fastcall Snd_CollectAllSoundPreloads(
    void* self /*ECX*/, GuardedVectorHeader* ring /*stack*/);

uint8_t __fastcall FillPreloadList(void* self /*ECX*/)
{
  // SEH frame LAB_009a2bbe omitted; DAT_00d1f040 copied into frame cookie slot.
  FUN_0076cf00("FillPreloadList");

  auto* primary = reinterpret_cast<GuardedVectorHeader*>(
      reinterpret_cast<uint8_t*>(self) + 0x124);
  FUN_0043d650(primary, 0);

  char* name = reinterpret_cast<char*>(reinterpret_cast<uint8_t*>(self) + 0x188);
  if (name == nullptr || *name == '\0' || *name == ' ') {
    FUN_0076cef0();
    return 0;
  }

  uint32_t key_primary = 0;
  FUN_004eb1c0(self, &key_primary);

  void* dep_host = *reinterpret_cast<void**>(
      reinterpret_cast<uint8_t*>(DAT_00d1f050) + 0x64);
  auto* dep_ring = reinterpret_cast<GuardedVectorHeader*>(
      reinterpret_cast<uint8_t*>(self) + 0x110);
  PreloadDep_CollectTransitiveKeys_Inferred(
      dep_host,
      reinterpret_cast<const int*>(&key_primary),
      dep_ring);

  const int gate = *reinterpret_cast<int*>(
      reinterpret_cast<uint8_t*>(DAT_00d1f050) + 0x6c);
  if (gate != 0) {
    FUN_004f1ff0(self, primary);
  }

  const uint32_t* push_key = &key_primary;
  uint32_t key_spt = 0;
  void* clonebase = *reinterpret_cast<void**>(
      reinterpret_cast<uint8_t*>(self) + 0x3c);
  const int16_t kind = *reinterpret_cast<int16_t*>(
      reinterpret_cast<uint8_t*>(clonebase) + 0x3f4);
  if (kind == 3) {
    char buf[260];
    // strcpy name → buf; strcat ".spt"; hash
    char* d = buf;
    const char* s = name;
    do {
      *d++ = *s;
    } while (*s++ != '\0');
    // append DAT_009cd088 / DAT_009cd08c (".spt")
    char* end = buf;
    while (*end != '\0') {
      ++end;
    }
    *reinterpret_cast<uint32_t*>(end) = DAT_009cd088;
    *(end + 4) = static_cast<char>(DAT_009cd08c);
    FUN_00989e00(&key_spt, buf);
    push_key = &key_spt;
  }

  GuardedVector_PushFront_Thiscall(primary, push_key);

  if (gate != 0) {
    auto* anim = reinterpret_cast<GuardedVectorHeader*>(
        reinterpret_cast<uint8_t*>(self) + 0x138);
    auto* phy = reinterpret_cast<GuardedVectorHeader*>(
        reinterpret_cast<uint8_t*>(self) + 0x14c);
    auto* snd = reinterpret_cast<GuardedVectorHeader*>(
        reinterpret_cast<uint8_t*>(self) + 0x160);
    Anim_CollectAllAnimationPreloads(self, anim);
    Phy_CollectAllPhysicsPreloads(self, phy);
    Snd_CollectAllSoundPreloads(self, snd);
  }

  FUN_0076cef0();
  return 1;
}
