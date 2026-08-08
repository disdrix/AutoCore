// =============================================================================
// Item_TryConcatStackWithPeer
// -----------------------------------------------------------------------------
// Stable ID: aa_00513eb0
// Address:   0x00513eb0  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-08-05 MEGA-012 dual A/B seal (live decompile + disasm + callers)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Try to concatenate peer item into this when CBIDs match.
//   - Optional: combine u16 field @ +0x180 under def limit @ +0x4BC
//     (full absorb if sum fits; else remainder-wrap before qty merge).
//   - Non-early path: this.qty = peer.qty + this.qty via vtbl +0x25C / +0x260.
//   - Dirty mark: FUN_00512670 (OR 0x20000 @ +0x17C, walk +0xAC chain).
//
// ABI: MSVC __thiscall — this = destination Item*; stack = peer Item*; RET 4; AL bool.
//
// CALLERS (2 UNCONDITIONAL_CALL):
//   FUN_008134d0 TradeRemoveItem_Response     @ 0x00813673
//   Client_RecvInventoryDropResponse          @ 0x00813995  (concat branch; string "concatinate")
//
// DISTINCT FROM:
//   Item_CanAcceptStackQty  0x0040abf0  — capacity predicate; max @ def+0x4BA; no mutation
//   Item_IsStackEligible    0x00513e70  — eligibility flags only
//
// SEALED: CBID gate, +0x180 / +0x4BC math, early fit exit, vfunc qty sum, RET 4.
// GAPS: product English for +0x180 and def+0x4BC; fit-path no-qty-merge rationale.
// =============================================================================

#include <cstdint>

// FUN_00512670 — mark item (+ linked +0xAC chain) dirty with flag 0x20000 @ +0x17C
extern "C" void __fastcall Item_MarkDirty_Flag20000_Inferred(int* item);

// Destination stack/item is `this`. Peer is the item being absorbed.
// Returns true if peer non-null and same CBID (merge applied); false otherwise.
bool __thiscall Item_TryConcatStackWithPeer(int* this_item, int* peer)
{
  if (peer == nullptr) {
    return false;
  }

  int* thisClone = reinterpret_cast<int*>(this_item[0x2a]); // +0xA8
  int* peerClone = reinterpret_cast<int*>(peer[0x2a]);

  // CBID equality at clonebase+0x34
  if (*(int*)(reinterpret_cast<char*>(peerClone) + 0x34) !=
      *(int*)(reinterpret_cast<char*>(thisClone) + 0x34)) {
    return false;
  }

  int* thisDef = *reinterpret_cast<int**>(reinterpret_cast<char*>(thisClone) + 0x3C);
  uint16_t limit = *reinterpret_cast<uint16_t*>(reinterpret_cast<char*>(thisDef) + 0x4BC);

  if (limit != 0 && limit != 0xFFFF) {
    // u16 field at item+0x180 (param_N + 0x60 as int*)
    uint16_t* thisField180 = reinterpret_cast<uint16_t*>(
        reinterpret_cast<char*>(this_item) + 0x180);
    uint16_t* peerField180 = reinterpret_cast<uint16_t*>(
        reinterpret_cast<char*>(peer) + 0x180);

    uint32_t sum = static_cast<uint32_t>(*peerField180) + static_cast<uint32_t>(*thisField180);

    if (sum <= static_cast<uint32_t>(limit)) {
      *thisField180 = static_cast<uint16_t>(sum);
      Item_MarkDirty_Flag20000_Inferred(this_item);
      return true; // early: no vfunc quantity merge
    }

    // overflow: remainder; exact multiple → store full limit (not 0)
    uint32_t rem = sum % static_cast<uint32_t>(limit);
    if (rem == 0) {
      rem = limit;
    }
    *thisField180 = static_cast<uint16_t>(rem);
  }

  // this.qty = peer.qty + this.qty  (vtbl +0x25C get / +0x260 set)
  int* thisVtbl = reinterpret_cast<int*>(*this_item);
  int* peerVtbl = reinterpret_cast<int*>(*peer);

  using GetQty_t = int(__thiscall*)(int*);
  using SetQty_t = void(__thiscall*)(int*, int);

  int peerQty = reinterpret_cast<GetQty_t>(peerVtbl[0x25C / 4])(peer);
  int thisQty = reinterpret_cast<GetQty_t>(thisVtbl[0x25C / 4])(this_item);
  reinterpret_cast<SetQty_t>(thisVtbl[0x260 / 4])(this_item, peerQty + thisQty);

  Item_MarkDirty_Flag20000_Inferred(this_item);
  return true;
}
