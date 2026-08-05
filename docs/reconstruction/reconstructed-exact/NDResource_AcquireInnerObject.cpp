// =============================================================================
// NDResource_AcquireInnerObject
// -----------------------------------------------------------------------------
// Stable ID: aa_00745ee0
// Address:   0x00745ee0  (autoassault.exe, image base 0x400000)
// System:    client NDResource shell
// Generated: 2026-07-23 scaffold; refined 2026-07-29 dual A/B
// Exactness: Behavior-preserving rewrite of decompiler + verified bytes.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// Dual A/B:  reviews/A_aa_00745ee0_* + reviews/B_aa_00745ee0_*
// =============================================================================

/*
 * Behavioral notes (sealed 2026-07-29):
 * - __thiscall: ECX = NDResource* shell; no stack args; plain ret; EAX = inner*.
 * - Bumps refcount at +0x10; stamps float last-touch at +0x1c via FUN_0076c330.
 * - Optional CRITICAL_SECTION at +0x20 when flag byte +0x38 != 0.
 * - When locked: Enter, mutate, Enter again (nested/recursive), Leave, maybe
 *   shell Release (vtbl+8) if inner was null, re-sample inner, Leave.
 * - Sibling decref: FUN_00745ea0 (same +0x10/+0x20/+0x38 layout).
 *
 * Decompiler noise:
 * - Ghidra may label __fastcall; ABI is thiscall ECX.
 * - float10/(int)(float) is fstp dword [this+0x1c] (float32), not int store.
 */

#include <windows.h>

// FUN_0076c330 @ 0x0076c330 — rdtsc-scaled float "now" (product name open).
extern "C" long double FUN_0076c330(void);

struct NDResource_Vtbl;

struct NDResource {
  NDResource_Vtbl *vtbl;       // +0x00
  void *pad04;                 // +0x04
  void *inner;                 // +0x08  — returned payload
  void *pad0c;                 // +0x0c
  int refcount;                // +0x10
  int pad14;                   // +0x14
  int pad18;                   // +0x18
  float lastTouch;             // +0x1c
  CRITICAL_SECTION cs;         // +0x20  (Windows CS; flag lives after)
  // ... CS body ...
  // uint8_t lockFlag at +0x38
};

struct NDResource_Vtbl {
  void *slot0;                 // +0x00
  void *slot1;                 // +0x04
  void (__thiscall *Release)(NDResource *self); // +0x08
};

/* NDResource_AcquireInnerObject  (thiscall)

   Bump refcount at this+0x10, optionally take critical section (this+0x20).
   If this+0x8 is null, Release this via vtable+8.
   Returns pointer at this+8 (inner resource).

   Caller NDXml_LoadDocumentFromPath then does:
     inner = AcquireInnerObject()
     iface = *(inner+4)
     iface->Release()   // crash PC 0x007B6DB0 when iface/vtable stale */

void *__fastcall NDResource_AcquireInnerObject(NDResource *self)
{
  CRITICAL_SECTION *cs;
  void *inner;
  int had_inner;
  uint8_t lockFlag;

  cs = &self->cs; /* byte +0x20 */
  lockFlag = *(uint8_t *)((char *)self + 0x38);

  if (lockFlag != 0) {
    EnterCriticalSection(cs);
  }

  self->refcount = self->refcount + 1;
  self->lastTouch = (float)FUN_0076c330();

  if (lockFlag != 0) {
    EnterCriticalSection(cs); /* nested — recursive CS required */
  }

  inner = self->inner; /* +0x08 */
  had_inner = (inner != 0) ? 1 : 0;

  if (lockFlag != 0) {
    LeaveCriticalSection(cs);
  }

  if (had_inner == 0) {
    self->vtbl->Release(self);
  }

  inner = self->inner; /* re-sample after optional Release */

  if (lockFlag != 0) {
    LeaveCriticalSection(cs);
  }

  return inner;
}
