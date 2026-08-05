// =============================================================================
// Host_ReplaceOwnedGridObj_E4FC_CtorPopulate_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004cd8f0
// Address:   0x004cd8f0  (autoassault.exe, image base 0x400000)
// Body:      0x004cd8f0–0x004cd991 exclusive (161 B / 0xA1); pad CC
// System:    host owned 0x30 grid-list object replace + populate
// Wave:      W38-S dual A/B (2026-08-04)
// Exactness: Behavior-preserving rewrite of decompile + read_memory CF/ABI.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Replace the owned 0x30 list object at host+0xe4fc:
//     1) scalar-delete existing (vtbl[0](1)) if non-null
//     2) operator_new(0x30) + Obj_DefaultCtor (FUN_005b3f60 / W30-O)
//     3) store at host+0xe4fc
//     4) Obj_PopulateListAt10_ScaledGridFill (FUN_005b3fa0 / W37-L) with
//        three stack dims, scale from *(host+0xe4f8)+0x18, and stack context
//
// ABI: __thiscall; ECX = host; stack (dim_a, dim_b, dim_c, ctx); void; ret 0x10.
// SEH: LAB_009a1eb7.
// =============================================================================

#include <cstdint>

extern "C" void *__cdecl operator_new(uint32_t size);
extern "C" void *__thiscall Obj_DefaultCtor_SetVtbl_EmptyListAt10_ZeroF4At20(void *self);
extern "C" uint32_t __thiscall Obj_PopulateListAt10_ScaledGridFill_Inferred(
    void *self, float dim_a, float dim_b, float dim_c, float scale, void *ctx);

// Ghidra twin names used at call sites in this binary family
extern "C" void *__thiscall FUN_005b3f60(void *self);
extern "C" uint32_t __thiscall FUN_005b3fa0(
    void *self, uint32_t a, uint32_t b, uint32_t c, uint32_t scale, uint32_t ctx);

typedef void (__thiscall *ScalarDeletingDtor)(void *self, int flags);

extern "C" void __thiscall Host_ReplaceOwnedGridObj_E4FC_CtorPopulate_Inferred(
    void *host,
    uint32_t dim_a,
    uint32_t dim_b,
    uint32_t dim_c,
    uint32_t ctx)
{
  void **const slot = reinterpret_cast<void **>(static_cast<char *>(host) + 0xe4fc);

  if (*slot != nullptr) {
    auto **vtbl = *reinterpret_cast<void ***>(*slot);
    reinterpret_cast<ScalarDeletingDtor>(vtbl[0])(*slot, 1);
    *slot = nullptr;
  }

  void *p = operator_new(0x30);
  void *obj = nullptr;
  if (p != nullptr) {
    obj = FUN_005b3f60(p); // returns this
  }
  *slot = obj;

  void *nested = *reinterpret_cast<void **>(static_cast<char *>(host) + 0xe4f8);
  uint32_t scale = *reinterpret_cast<uint32_t *>(static_cast<char *>(nested) + 0x18);

  // ECX = obj (bytes before call); may be null on OOM — matches machine order
  FUN_005b3fa0(obj, dim_a, dim_b, dim_c, scale, ctx);
}

extern "C" void __thiscall FUN_004cd8f0(
    void *host, uint32_t a, uint32_t b, uint32_t c, uint32_t ctx)
{
  Host_ReplaceOwnedGridObj_E4FC_CtorPopulate_Inferred(host, a, b, c, ctx);
}
