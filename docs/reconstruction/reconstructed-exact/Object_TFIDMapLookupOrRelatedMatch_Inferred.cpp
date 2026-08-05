// =============================================================================
// Object_TFIDMapLookupOrRelatedMatch_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Lower-bound TFID in creature map at self+0x154. On hit return map
//           value @node+0x20. On miss, gate against MI+0xA4 related object TFID
//           (direct field match or vtbl+0x214 related id via TFID_EqualsObjectId).
//
// Address:  0x004c8970  (autoassault.exe, image base 0x400000)
// Body:     0x004c8970–0x004c8a58 (0xE9 / 233 B; RET 0x10)
// Stable:   aa_004c8970
// System:   creature / TFID map / engage gate
//
// Sole caller: CVOGHBAI_EngageSelectTargetFromOwnerTFID_Inferred (0x005ccff0)
//              @ 0x005cd103 — non-zero early-outs before LinkedDeath walk.
//
// Exactness: CF mirrors raw; map this + RET 0x10 sealed by read_memory.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Human-refined plate: 2026-07-29 W30-T
// =============================================================================

// Ghidra: FUN_004c8970
// ABI: __thiscall; stack TFID 16 B (4 dwords); RET 0x10

#include <cstdint>

extern "C" void *__thiscall FUN_004cb4b0(void *map, uint32_t *pTfidKey);
extern "C" int __cdecl TFID_EqualsObjectId(void *pA, void *pB);

uint32_t __thiscall Object_TFIDMapLookupOrRelatedMatch_Inferred(
    void *self,
    uint32_t tfidLo,
    uint32_t tfidHi,
    uint32_t tfidW2,
    uint32_t /*tfidW3 — stack slot present; body unused beyond Equals ptr base*/)
{
  void *map = (char *)self + 0x154;
  void *end = *(void **)((char *)self + 0x158);
  void *node = FUN_004cb4b0(map, &tfidLo);

  void *sel;
  if (node == end
      || (int)tfidHi < *(int *)((char *)node + 0x14)
      || ((int)tfidHi <= *(int *)((char *)node + 0x14)
          && tfidLo < *(uint32_t *)((char *)node + 0x10))) {
    sel = end;
  } else {
    sel = node;
  }

  if (sel == end) {
    int mi = *(int *)(*(int *)((char *)self + 4) + 4);
    int *related = *(int **)((char *)self + mi + 0xA4);
    if (related != nullptr) {
      if (related[0x58] == (int)tfidLo
          && related[0x59] == (int)tfidHi
          && (char)related[0x5a] == (char)tfidW2) {
        return 1;
      }
      int r = (**(int(__thiscall ***)(void *))(*related + 0x214))(related);
      if (r != 0) {
        related = *(int **)((char *)self + mi + 0xA4);
        r = (**(int(__thiscall ***)(void *))(*related + 0x214))(related);
        int rmi = *(int *)(*(int *)((char *)r + 4) + 4);
        if ((char)TFID_EqualsObjectId((char *)r + rmi + 0x164, &tfidLo) != 0) {
          return 1;
        }
      }
    }
    return 0;
  }
  return *(uint32_t *)((char *)sel + 0x20);
}
