// =============================================================================
// Object_ResolveStoredTFID_Vtbl1dc_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004c4440
// Address:   0x004c4440–0x004c44bc  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_004c4440
// System:    object / TFID resolve / vtbl query
// Sealed:    2026-07-29 W27-G (live decompile + read_memory + analyze_function_complete)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   If the TFID_16 stored at object+0x108 is not the shared "invalid" pattern,
//   resolve it via Object_ResolveFromTFID (manager ctx in ECX) and, on hit,
//   invoke the resolved object's virtual at vtbl+0x1dc. Return that result when
//   nonzero; otherwise return 0.
//
// EVIDENCE:
//   - Ghidra types: TFID_16 with dwCoidLo/dwCoidHi at +0x108/+0x10c.
//   - Callee dual-sealed as Object_ResolveFromTFID (0x004bb950).
//   - Shared invalid predicate with FUN_004c4620 (mode leaf) and FUN_004c4880
//     (mode write + rebind).
//   - Bytes rebuild resolve ctx via +0xA8 / +0xE4E8 (surface omits ECX).
//
// ABI: thiscall; RET 0; ECX=this; EAX = 0 | vtbl+0x1dc result
// Body: 0x004c4440–0x004c44bc (125 B)

#include <stdint.h>

struct TFID_16 {
  uint32_t dwCoidLo;
  uint32_t dwCoidHi;
  uint32_t word2;
  uint32_t word3;
};

// Dual-sealed: void* __thiscall Object_ResolveFromTFID(void* ctx, TFID_16* pTfid);
extern "C" void *__thiscall Object_ResolveFromTFID(void *ctx, TFID_16 *pTfid);

extern "C" int __thiscall Object_ResolveStoredTFID_Vtbl1dc_Inferred(int self)
{
  uint32_t lo = *(uint32_t *)(self + 0x108);
  uint32_t hi = *(uint32_t *)(self + 0x10c);
  uint32_t w2 = *(uint32_t *)(self + 0x110);
  uint32_t w3 = *(uint32_t *)(self + 0x114);

  if (((lo & hi) != 0xFFFFFFFFu) || ((char)w2 != 0)) {
    TFID_16 local;
    local.dwCoidLo = lo;
    local.dwCoidHi = hi;
    local.word2 = w2;
    local.word3 = w3;

    // Bytes rebuild ctx: *( *( *(self+4) + 4 ) + self + 0xA8 ) then +0xE4E8.
    // Decompiler surface omits ECX; pass nullptr placeholder for host-built ctx.
    void *ctx = nullptr;  // filled by caller-side chain in image before CALL
    // Reconstruct chain exactly as image:
    {
      int a = *(int *)(self + 4);
      int b = *(int *)(a + 4);
      int c = *(int *)(b + self + 0xA8);
      ctx = *(void **)(c + 0xE4E8);
    }

    void *obj = Object_ResolveFromTFID(ctx, &local);
    if (obj != nullptr) {
      typedef int (__thiscall *Vtbl1dc_t)(void *thisptr);
      Vtbl1dc_t fn = *(Vtbl1dc_t *)(*(uint8_t **)obj + 0x1dc);
      int r = fn(obj);
      if (r != 0) {
        return r;
      }
    }
  }
  return 0;
}

// Ghidra twin
extern "C" int __thiscall FUN_004c4440(int param_1)
{
  return Object_ResolveStoredTFID_Vtbl1dc_Inferred(param_1);
}
