// =============================================================================
// Object_009d33c4_FactoryRegisterListed_Inferred  (FUN_0094bed0)
// -----------------------------------------------------------------------------
// Stable ID: aa_0094bed0
// Address:   0x0094bed0–0x0094bf8d  (190 B / 0xBE; pad CC after)
// System:    object factory / host listing registration
// Generated: 2026-07-29 W30-K dual seal
// Exactness: Behavior-preserving rewrite from read_memory bytes + sealed callees.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   Allocate 0x210-byte Object_009d33c4, complete-construct, run two virtual
//   inits against host field +0xe04 / global DAT_00af30f4, stamp COID identity,
//   register into host listing manager at +0xd34. On register HRESULT < 0,
//   scalar-delete the object and return NULL.
//
// ABI (image-sealed):
//   EDI = host context (live register)
//   stack: (coid_lo, coid_hi)
//   ret 8
//   returns object* or NULL

#include <stdint.h>

// External (sealed elsewhere):
// void *operator_new(uint32_t size);
// void *__thiscall Object_009d33c4_Ctor(void *self);           // 0x00575440 W29-H
// void __thiscall Object_SetCoidIdentity(void *self, uint32_t lo, uint32_t hi, uint8_t flag); // 0x00512160
// int32_t __thiscall Object_RegisterListed(void *listing, void *obj); // 0x004bc180 W19-E
// extern void *DAT_00af30f4;

typedef void *(__thiscall *vtbl_method_t)(void *self, ...);

void *Object_009d33c4_FactoryRegisterListed_Inferred(
    void *host /*EDI*/,
    uint32_t coid_lo,
    uint32_t coid_hi)
{
  void *obj = operator_new(0x210);
  if (obj != 0) {
    obj = Object_009d33c4_Ctor(obj);
  }

  // Image does not short-circuit on null new before the following virtuals.
  void **vtbl = *(void ***)obj;
  void *field_e04 = *(void **)((char *)host + 0xe04);

  // vtbl + 0x08
  ((void (__thiscall *)(void *, void *, void *, int))vtbl[2])(
      obj, DAT_00af30f4, field_e04, 1);

  Object_SetCoidIdentity(obj, coid_lo, coid_hi, 1);

  field_e04 = *(void **)((char *)host + 0xe04);
  // vtbl + 0x218
  ((void (__thiscall *)(void *, void *))vtbl[0x218 / 4])(obj, field_e04);

  int32_t hr = Object_RegisterListed(*(void **)((char *)host + 0xd34), obj);
  if (hr < 0) {
    // vtbl[0] scalar deleting dtor (flags=1)
    ((void (__thiscall *)(void *, int))vtbl[0])(obj, 1);
    return 0;
  }
  return obj;
}
