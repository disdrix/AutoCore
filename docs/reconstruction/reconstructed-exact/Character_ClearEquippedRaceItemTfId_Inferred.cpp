// =============================================================================
// Character_ClearEquippedRaceItemTfId_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Teardown character equipped race-item binding:
//           if TFID cache at this+0x518 looks live and host component exists,
//           resolve world object, enqueue deferred once, then write the null
//           TFID template into this+0x518..+0x524.
//
// Address:  0x005210b0  (autoassault.exe, image base 0x400000)
// Body:     0x005210b0–0x0052112b (124 bytes)
// Stable:   aa_005210b0
// System:   character race-item equip / inventory / ghost
// Ghidra:   FUN_005210b0
//
// ABI:      __thiscall / __fastcall ECX = character*; no stack formals; ret
// Fields:   this+0x518 TFID_16 cache; CBID at +0x514 is NOT cleared here
// Template: DAT_009cee98 = {0xffffffff, 0xffffffff, 0, 0}
// Callees:  Object_ResolveFromTFID (via host+0xe4e8), Object_EnqueueDeferredOnce
// Callers:  Character_SyncEquippedRaceItemFromCbid_Inferred (0x00522f70),
//           FUN_0052f260
//
// Exactness: CF mirrors raw + read_memory bytes; decompiler simplify corrected.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 W21-E seal). Role name INFERRED.
// =============================================================================

#include <stdint.h>

struct TFID_16 {
  uint32_t dwCoidLo;
  uint32_t dwCoidHi;
  uint32_t field_08;
  uint32_t field_0C;
};

/* Sealed elsewhere: Object_ResolveFromTFID @ 0x004bb950.
   Bytes: thiscall on *(host+0xe4e8) with TFID* on stack. Surface decompile
   often collapses to a free function — keep both names honest. */
extern void *Object_ResolveFromTFID(TFID_16 *tfid);

/* Sealed aa_004d0e90: Object_EnqueueDeferredOnce(host, obj) — ret 4. */
extern void __thiscall Object_EnqueueDeferredOnce(void *host, void *obj);

/* Null TFID template @ 0x009cee98 (read_memory sealed). */
static const uint32_t kNullTfidTemplate[4] = {
    0xffffffffu, 0xffffffffu, 0x00000000u, 0x00000000u
};

void __thiscall Character_ClearEquippedRaceItemTfId_Inferred(void *self /*ECX*/)
{
  uint32_t *tfid_dwords = (uint32_t *)((uint8_t *)self + 0x518);
  TFID_16 *tfid = (TFID_16 *)tfid_dwords;

  /* Present if (lo & hi) != 0xffffffff OR byte at +0x520 != 0. */
  int present = ((tfid_dwords[0] & tfid_dwords[1]) != 0xffffffffu) ||
                (*(int8_t *)((uint8_t *)self + 0x520) != 0);
  if (!present) {
    return;
  }

  /* host = *(*(self+4) + 4 + self + 0xa8) — multi-base component load. */
  int *vt_adj = *(int **)((uint8_t *)self + 4);
  void *host = *(void **)((uint8_t *)vt_adj[1] + (uintptr_t)self + 0xa8);
  if (host == 0) {
    return;
  }

  /* Bytes: ecx = *(host+0xe4e8); push tfid; call Object_ResolveFromTFID.
     Clean keeps sealed free-function surface for the resolve symbol. */
  (void)/* resolve_ctx = */ *(void **)((uint8_t *)host + 0xe4e8);
  void *obj = Object_ResolveFromTFID(tfid);
  if (obj != 0) {
    Object_EnqueueDeferredOnce(host, obj);
  }

  /* Always clear TFID cache when gates passed. */
  tfid_dwords[0] = kNullTfidTemplate[0]; /* DAT_009cee98 */
  tfid_dwords[1] = kNullTfidTemplate[1]; /* DAT_009cee9c */
  tfid_dwords[2] = kNullTfidTemplate[2]; /* DAT_009ceea0 */
  tfid_dwords[3] = kNullTfidTemplate[3]; /* DAT_009ceea4 */
}
