// =============================================================================
// AssPreloader_Ctor_Inferred  (aa_00970cf0)
// -----------------------------------------------------------------------------
// Address:   0x00970cf0–0x00970e4c exclusive (348 B / 0x15C)
// Module:    autoassault.exe @ image base 0x400000
// Ghidra:    FUN_00970cf0
// System:    assets / AssPreloader construction
// Wave:      W37-W OWN-ONLY 2026-08-04
// Exactness: Behavior-preserving from decompile + read_memory. Not modernization.
// Bit-for-bit / runtime: DEFERRED.
// =============================================================================
//
// Retail ABI:
//   stack: self* (placement storage from operator_new(0x114)), host*
//   RET 0x08; returns self* in EAX
//
// Sole caller: AssManager_EnsureAssPreloader_Inferred (0x0075d3c0, W33-O)
//   push host; push mem; call this — after operator_new(0x114).
//
// Sealed init:
//   vtbl PTR_FUN_00aa9a94; CreateEventA; map head via StdTree_AllocNode_0x1c;
//   four GuardedVector+CS banks; second tree via RbTree_AllocEmptyNode;
//   host back-pointer at +0x110; object size 0x114.
//
// Name is structural (_Inferred). Reject scaffold Named_CalleeOf_*Client_InitI*.
// SEH frame (LAB_009accf1) omitted from clean surface.
// =============================================================================

#include <cstdint>
#include <windows.h>

// External vtbl plate (first slot = scalar-deleting dtor FUN_00481270)
extern "C" void* PTR_FUN_00aa9a94[];

// Sealed helpers
extern "C" void* StdTree_AllocNode_0x1c(void);       // FUN_005ae2b0
extern "C" void* RbTree_AllocEmptyNode_Inferred(void); // FUN_00439770

struct AssPreloader {
  void** vtbl;                 // +0x00
  HANDLE event;                // +0x04  CreateEventA
  uint8_t flag08;              // +0x08
  // +0x0C.. map host; head at +0x14; size at +0x18
  // GuardedVector banks (see raw W37-W layout notes)
  // +0xAC: seed ring header used by ensure (CS@+0xC0, lockEnable@+0xD8)
  // +0xE0: second tree head (0x18 nodes)
  // +0x110: host* (ctor param_2 / NDResourceCache path)
  uint8_t body[0x114 - sizeof(void*) - sizeof(HANDLE) - 1];
};

// Retail: stack (self*, host*); RET 8; returns self*
extern "C" AssPreloader* AssPreloader_Ctor_Inferred(
    AssPreloader* self,
    void* host)
{
  self->vtbl = PTR_FUN_00aa9a94;
  self->event = nullptr;
  self->flag08 = 0;

  self->event = CreateEventA(nullptr, FALSE, FALSE, nullptr);

  // Map head (0x1c tree node family) — retail writes self+0x14
  auto* mapHead = static_cast<uint8_t*>(StdTree_AllocNode_0x1c());
  *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(self) + 0x14) = mapHead;
  mapHead[0x19] = 1; // isnil head
  *reinterpret_cast<void**>(mapHead + 4) = mapHead;
  *reinterpret_cast<void**>(mapHead + 0) = mapHead;
  *reinterpret_cast<void**>(mapHead + 8) = mapHead;
  *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 0x18) = 0;

  // Four GuardedVector banks: zero pages/cap/begin/size then CS + lockEnable=1
  auto init_gv_bank = [](uint8_t* base, uint32_t pagesOff, uint32_t csOff) {
    *reinterpret_cast<uint32_t*>(base + pagesOff + 0x00) = 0;
    *reinterpret_cast<uint32_t*>(base + pagesOff + 0x04) = 0;
    *reinterpret_cast<uint32_t*>(base + pagesOff + 0x08) = 0;
    *reinterpret_cast<uint32_t*>(base + pagesOff + 0x0C) = 0;
    InitializeCriticalSection(
        reinterpret_cast<LPCRITICAL_SECTION>(base + csOff));
    *(base + csOff + 0x18) = 1; // lockEnable relative to CS start in bank A–C
  };
  auto* b = reinterpret_cast<uint8_t*>(self);
  // Bank A: pages@+0x20 CS@+0x30 flag@+0x48
  init_gv_bank(b, 0x20, 0x30);
  // Bank B: pages@+0x50 CS@+0x60 flag@+0x78
  init_gv_bank(b, 0x50, 0x60);
  // Bank C: pages@+0x80 CS@+0x90 flag@+0xA8
  init_gv_bank(b, 0x80, 0x90);
  // Bank D (GuardedVector this = self+0xAC): pages@+0xB0 CS@+0xC0 lockEnable@+0xD8
  *reinterpret_cast<uint32_t*>(b + 0xB0) = 0;
  *reinterpret_cast<uint32_t*>(b + 0xB4) = 0;
  *reinterpret_cast<uint32_t*>(b + 0xB8) = 0;
  *reinterpret_cast<uint32_t*>(b + 0xBC) = 0;
  InitializeCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(b + 0xC0));
  *(b + 0xD8) = 1;

  // Second tree head (0x18-node family) @ +0xE0
  auto* t2 = static_cast<uint8_t*>(RbTree_AllocEmptyNode_Inferred());
  *reinterpret_cast<void**>(b + 0xE0) = t2;
  t2[0x15] = 1;
  *reinterpret_cast<void**>(t2 + 4) = t2;
  *reinterpret_cast<void**>(t2 + 0) = t2;
  *reinterpret_cast<void**>(t2 + 8) = t2;
  *reinterpret_cast<uint32_t*>(b + 0xE4) = 0;

  // Host back-pointer + zero pad run used by family methods
  *reinterpret_cast<void**>(b + 0x110) = host;
  for (uint32_t off = 0xE8; off < 0x110; off += 4) {
    *reinterpret_cast<uint32_t*>(b + off) = 0;
  }

  return self;
}
