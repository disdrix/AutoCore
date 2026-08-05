// =============================================================================
// Object_SharedBase_Dtor
// -----------------------------------------------------------------------------
// Stable ID: aa_00518ec0
// Address:   0x00518ec0-0x005190b1 exclusive (497 B / 0x1F1)
// System:    object core / dual-base shared field destructor
// Generated: 2026-07-29 W29-G dual seal
// Exactness: Behavior-preserving rewrite of decompiler CF + read_memory seals.
//            Ghidra false-noreturn on operator_delete ignored; fall-through kept.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
// Shared dual-base / virtual-base field destructor for the client object core.
// Twin of Object_SharedBase_Ctor (aa_00518940, W22-B). Outer complete-object
// dtors call or tail-jmp here with ECX = core this.
// Not a scalar-deleting destructor (no flags, no operator_delete(this)).

#include <cstdint>
#include <windows.h>

struct TFID_16 {
  uint32_t dwCoidLo;
};

extern "C" void *Object_ResolveFromTFID(TFID_16 *tfid);
extern "C" void FUN_007a4480(int level, const char *fmt, ...);
extern "C" void FUN_004bb970(uint8_t a, uint32_t coidLo, uint32_t b);
extern "C" void CNDDoubleList_InvokePredicateAndRemove_Inferred(void *pred, void *ctx, int flag);
extern "C" void *LAB_005120e0;
extern "C" void FUN_0051b8a0(void);
extern "C" void __fastcall Object_TeardownOwnedFxLists_Inferred(void *self); // FUN_005179e0
extern "C" void FUN_0040ec70(void);
extern "C" void FUN_0051da00(void);
extern "C" void FUN_0051da30(void);
extern "C" void FUN_005b2ba0(void);
extern "C" void FUN_004eb010(void);
extern "C" void *__cdecl operator_delete(void *p);
extern "C" void *__cdecl operator_delete__(void *p);
extern "C" char DAT_00b03e64;

static void free_triple(uint8_t *base, unsigned begin_off)
{
  void *begin = *reinterpret_cast<void **>(base + begin_off);
  if (begin != nullptr) {
    operator_delete(begin);
  }
  *reinterpret_cast<void **>(base + begin_off) = nullptr;
  *reinterpret_cast<void **>(base + begin_off + 4) = nullptr;
  *reinterpret_cast<void **>(base + begin_off + 8) = nullptr;
}

// __thiscall/__fastcall; ECX=this; void; bare RET
void __fastcall Object_SharedBase_Dtor(void *self)
{
  auto *base = reinterpret_cast<uint8_t *>(self);
  void *local = self;

  int *world = *reinterpret_cast<int **>(base + 0xA4);
  if (world != nullptr && *reinterpret_cast<int *>(reinterpret_cast<uint8_t *>(world) + 0xE4E8) != 0) {
    auto *tfid = reinterpret_cast<TFID_16 *>(base + 0x160);
    void *resolved = Object_ResolveFromTFID(tfid);
    if (resolved == self) {
      uint32_t coid_hi = *reinterpret_cast<uint32_t *>(base + 0x164);
      uint8_t cbid = base[0x168];
      int *cb = *reinterpret_cast<int **>(base + 0xA8);
      uint32_t extra = cb ? *reinterpret_cast<uint32_t *>(reinterpret_cast<uint8_t *>(cb) + 0x34) : 0;
      FUN_007a4480(
          1,
          "##$$##$$##$$##$$## About to crash, destructor but still in co list: "
          "Object COID(%I64d, %d), CBID(%d)\n",
          tfid->dwCoidLo, coid_hi, cbid, extra);
      FUN_004bb970(cbid, tfid->dwCoidLo, coid_hi);
    }
  }

  int **iface = *reinterpret_cast<int ***>(base + 0x14);
  if (iface != nullptr) {
    auto **vt = reinterpret_cast<void **>(*iface);
    using Fn = void(__thiscall *)(void *, int);
    reinterpret_cast<Fn>(vt[0x2C / 4])(iface, 0);
    *reinterpret_cast<void **>(base + 0x14) = nullptr;
  }

  *reinterpret_cast<DWORD *>(base + 0x18) = GetTickCount();

  local = reinterpret_cast<void *>(reinterpret_cast<uintptr_t>(local) & ~uintptr_t(0xFF));
  CNDDoubleList_InvokePredicateAndRemove_Inferred(&LAB_005120e0, &local, 0);
  FUN_0051b8a0();

  void **cs = *reinterpret_cast<void ***>(base + 0xB0);
  if (cs != nullptr) {
    auto **vt = reinterpret_cast<void **>(*cs);
    using Dtor = void(__thiscall *)(void *, int);
    reinterpret_cast<Dtor>(vt[0])(cs, 1);
  }
  *reinterpret_cast<void **>(base + 0xB0) = nullptr;

  Object_TeardownOwnedFxLists_Inferred(self);

  void *p = *reinterpret_cast<void **>(base + 0x15C);
  if (p != nullptr) {
    FUN_0040ec70();
    operator_delete(p);
  }
  *reinterpret_cast<void **>(base + 0x15C) = nullptr;

  p = *reinterpret_cast<void **>(base + 0x6C);
  if (p != nullptr) {
    FUN_0051da00();
    operator_delete(p);
  }
  *reinterpret_cast<void **>(base + 0x6C) = nullptr;

  p = *reinterpret_cast<void **>(base + 0x68);
  if (p != nullptr) {
    FUN_0051da30();
    operator_delete(p);
  }
  *reinterpret_cast<void **>(base + 0x68) = nullptr;

  p = *reinterpret_cast<void **>(base + 0x64);
  if (p != nullptr) {
    FUN_005b2ba0();
    operator_delete(p);
  }
  *reinterpret_cast<void **>(base + 0x64) = nullptr;

  void **owned70 = *reinterpret_cast<void ***>(base + 0x70);
  if (owned70 != nullptr) {
    auto **vt = reinterpret_cast<void **>(*owned70);
    using Dtor = void(__thiscall *)(void *, int);
    reinterpret_cast<Dtor>(vt[0])(owned70, 1);
  }
  *reinterpret_cast<void **>(base + 0x70) = nullptr;

  if (*reinterpret_cast<void **>(base + 0x158) != nullptr) {
    operator_delete__(*reinterpret_cast<void **>(base + 0x158));
  }
  *reinterpret_cast<void **>(base + 0x158) = nullptr;

  if (*reinterpret_cast<int *>(base + 0xA8) != 0 && DAT_00b03e64 != '\0') {
    FUN_004eb010();
  }

  free_triple(base, 0x148);
  free_triple(base, 0x138);
  free_triple(base, 0x124);
}
