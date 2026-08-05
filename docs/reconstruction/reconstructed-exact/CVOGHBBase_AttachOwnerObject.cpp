// READABILITY (machine CF seal 2026-07-29):
//  - Body size: 60 bytes (005083b0–005083ec).
//  - Control: detach gate → unconditional store → attach gate.
//  - Callees: FUN_005085b0 (remove), FUN_00508490 (insert) — this = *(owner+0xB0).
//  - Return: void; ret 4.

// =============================================================================
// CVOGHBBase_AttachOwnerObject
// -----------------------------------------------------------------------------
// Purpose:  Rebind a heartbeat/action (CVOGHBBase) to an owner object and
//           keep the owner's HB list manager consistent when owner+0xB0 is set.
//
// Address:  0x005083b0  (autoassault.exe, image base 0x400000)
// Stable:   aa_005083b0
// System:   heartbeat / timed-action infrastructure
//
// Convention: MSVC __thiscall  (this = CVOGHBBase* in ECX;
//             pOwnerObject on stack; ret 4)
// Returns:    void
//
// Layout:
//   HB +0x18     pOwnerObject (void*)
//   Owner +0xB0  pListManager (void*) — pointer to list manager object;
//                NOT an embedded list head. Null ⇒ skip list ops.
//
// Algorithm (machine-authoritative):
//   old = *(HB+0x18)
//   if old && *(old+0xB0):
//       FUN_005085b0(this=*(old+0xB0), hb=this)   // detach
//   *(HB+0x18) = pOwnerObject                     // always (null clears)
//   if pOwnerObject && *(pOwnerObject+0xB0):
//       FUN_00508490(this=*(pOwnerObject+0xB0), hb=this)  // attach
//
// Note: Ghidra pseudocode shows FUN_*(this) with this=HB — WRONG.
//       ECX for helpers is the list manager at owner+0xB0; HB is stack arg.
//
// Callers: HB ctors / rebinds (regen, skill, mission, weapon track, token flag, …)
// Exactness: Behavior-preserving; call shape from read_memory.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime / differential: OPEN.
// Human-refined: 2026-07-23 (priority_014)
// Machine seal: 2026-07-29 (dual A/B + read_memory; callee this corrected)
// =============================================================================

#include <cstdint>

// Remove hb from list manager (ECX = list manager, stack = HB*).
extern "C" void __thiscall FUN_005085b0(void* pListManager, void* pHb);

// Insert hb into list manager (ECX = list manager, stack = HB*).
extern "C" void __thiscall FUN_00508490(void* pListManager, void* pHb);

/// @param thisHb         CVOGHBBase* (this / ECX).
/// @param pOwnerObject   Owner object (vehicle/character/skill/…), or null.
void __thiscall CVOGHBBase_AttachOwnerObject(void* thisHb, void* pOwnerObject)
{
    void* pOldOwner = *reinterpret_cast<void**>(static_cast<char*>(thisHb) + 0x18);
    if (pOldOwner != nullptr) {
        void* pOldListMgr =
            *reinterpret_cast<void**>(static_cast<char*>(pOldOwner) + 0xb0);
        if (pOldListMgr != nullptr) {
            FUN_005085b0(pOldListMgr, thisHb);
        }
    }

    *reinterpret_cast<void**>(static_cast<char*>(thisHb) + 0x18) = pOwnerObject;

    if (pOwnerObject != nullptr) {
        void* pNewListMgr =
            *reinterpret_cast<void**>(static_cast<char*>(pOwnerObject) + 0xb0);
        if (pNewListMgr != nullptr) {
            FUN_00508490(pNewListMgr, thisHb);
        }
    }
}
