// =============================================================================
// UiWidget_TeardownIfActive
// -----------------------------------------------------------------------------
// Stable ID: aa_00792490
// Address:   0x00792490  (autoassault.exe, image base 0x400000)
// System:    ui
// Generated: 2026-07-23 scaffold; dual seal refine 2026-07-29 W22-F
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Runtime / differential: OPEN.
//
// Purpose:  If widget active (vtbl+0x3d8), run close teardown: clear flags,
//           release owned resource (+0x2ac / +0x2a8), invoke vtbl helpers,
//           hash-walk children (vtbl+0xb0), then free residual pointers.
//
// Convention (asm-sealed):
//   ECX = UiWidget* this
//   no stack args; void; RET (no cleanup)
//
// Body: 0x00792490–0x007925ff (368 B). Worker.
// Callees: FUN_0074e260, FUN_007a4480 (+ many vtbl slots).
//
// Related:
//   Client_MissionDialog_FlushPreparedResponse  0x008ab8f0
//   100+ thin close wrappers: vtbl+0x3ac(); then this
//   reviews/A|B_aa_00792490_UiWidget_TeardownIfActive.md
// =============================================================================

/*
 * Behavioral notes:
 * - Gate false → full early return (no flag clear, no child walk).
 * - Hash lock byte at hash+0x1d; misuse logs HashError:* + VOG_DEBUG_STOP.
 * - Product English for vtbl slots 0x330/0x3ac/0xb0/0x1c0: Tentative.
 * - Xref count ~100+ (inventory lists many UI close paths).
 */

#include <stdint.h>

// Forward decls (Ghidra symbols)
extern void FUN_0074e260(void* resourceId);
extern void FUN_007a4480(int level, const char* msg);

typedef int  (*VtblFn0)(void* self);
typedef int  (*VtblFn1)(void* self, int a);
typedef void (*VtblFnV)(void* self);
typedef void (*VtblFnV1)(void* self, void* a);
typedef void (*DtorFn)(void* self, int freeMem);

void __fastcall UiWidget_TeardownIfActive(int* self /*ECX*/)
{
  int** vtbl = (int**)*self;

  char active = ((char (*)(void*))vtbl[0x3D8 / 4])(self);
  if (active == 0) {
    return;
  }

  ((void (*)(void*, int))vtbl[0x330 / 4])(self, 8);

  *(uint8_t*)((uint8_t*)self + 0x8C)  = 0;  // self[0x23]
  *(uint8_t*)((uint8_t*)self + 0xC8)  = 0;  // self[0x32]
  *(uint8_t*)((uint8_t*)self + 0x492) = 0;

  if (self[0xAB] != 0) { /* +0x2AC owned */
    if (self[0xAA] != 0) { /* +0x2A8 shell */
      int shell = *(int*)(self[0xAA] + 4);
      int* refObj = *(int**)(shell + 0x3C);
      if (refObj != 0) {
        int* refCount = refObj + 1;
        *refCount = *refCount - 1;
        if (*refCount == 0) {
          ((void (*)(void*))(*(int**)refObj)[2])(refObj); /* vtbl+8 */
        }
      }
      *(uint32_t*)(shell + 0x3C) = 0;
      FUN_0074e260(*(void**)(self[0xAB] + 0x8C));
    }
    if (self[0xAB] != 0) {
      ((DtorFn)(*(void**)self[0xAB]))((void*)self[0xAB], 1);
    }
    self[0xAB] = 0;
  }

  ((void (*)(void*))vtbl[0x58 / 4])(self);

  int hash = self[0x136]; /* +0x4D8 */
  int node = 0;
  if (*(char*)(hash + 0x1D) != 0) {
    FUN_007a4480(0, "HashError:TraversalLock, already locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }
  *(uint8_t*)(hash + 0x1D) = 1;

  for (;;) {
    hash = self[0x136];
    if (*(char*)(hash + 0x1D) == 0) {
      FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
      FUN_007a4480(0, "VOG_DEBUG_STOP");
    }
    if (node == 0) {
      node = *(int*)(hash + 0x14);
    } else {
      node = *(int*)(node + 0x14);
    }
    int child = (node == 0) ? 0 : *(int*)(node + 8);
    if (child == 0) {
      break;
    }
    ((void (*)(void*, int))vtbl[0xB0 / 4])(self, child);
  }

  *(uint8_t*)(self[0x136] + 0x1D) = 0;
  ((void (*)(void*))vtbl[0x3B4 / 4])(self);

  active = ((char (*)(void*))vtbl[0x1C0 / 4])(self);
  if (active != 0) {
    if (self[0xAA] != 0) {
      ((DtorFn)(*(void**)self[0xAA]))((void*)self[0xAA], 1);
    }
    self[0xAA] = 0;
  }

  if (self[0x130] != 0) { /* +0x4C0 */
    ((DtorFn)(*(void**)self[0x130]))((void*)self[0x130], 1);
  }
  self[0x130] = 0;
  self[0x12E] = 0; /* +0x4B8 */
  self[0x12F] = 0; /* +0x4BC */
  self[0x12D] = 0; /* +0x4B4 */
}
