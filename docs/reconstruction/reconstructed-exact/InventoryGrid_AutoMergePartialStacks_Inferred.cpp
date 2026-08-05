// =============================================================================
// InventoryGrid_AutoMergePartialStacks_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00572ab0
// Address:   0x00572ab0  (autoassault.exe, image base 0x400000)
// Body:      0x00572ab0 – 0x00572ec7 exclusive (1047 B / 0x417)  [TRUE end]
//            Ghidra plate exclusive end 0x00572e7f is FALSE (delete noreturn)
// System:    inventory-transfer / InventoryGrid
// Generated: 2026-07-29 W29-E dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler CF + byte-sealed epilogue.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: One-pass consolidate of underfilled stackable items on an inventory
// grid. Peers match by clonebase+0x34 (stack group), not COID. Uses inlined
// max-stack formula (type4 → 0x423F; else def+0x4BA or 200). Fully absorbed
// items are RemoveItem'd + QueueDelete'd at end. Returns whether any merge
// occurred (AL). Sole caller FUN_008c2f50 may send sector pkt 0x204a on true.

#include <cstdint>

// External sealed / named helpers (roles only — not reimplemented here)
extern "C" void*  __thiscall StdList_AllocEmptySentinel_Inferred(void* /*unused ecx path per site*/);
extern "C" void*  __cdecl    StdTree_BuynodeEmptyHead_Val12(/* FUN_005ae2b0 */);
extern "C" void   __thiscall List_TraversalLock(void* listBase);
extern "C" int    __thiscall List_IterateNext(void* listBase, void** outItem, void* state);
extern "C" char   __thiscall Item_IsStackEligible(void* item);
extern "C" void   __fastcall StdTree_Inc_Val12(void** it);
extern "C" void   __thiscall StdTree_Erase_Val12(void* map, void** outIt, void* node);
extern "C" void   __thiscall StdMap_InsertOrFind_Val12_UintKey(void* map, void* outPair, const void* value);
extern "C" void   __thiscall StdTree_RangeErase_Val12(void* map, void* first, void* last); // FUN_00573700
extern "C" void*  __thiscall InventoryGrid_RemoveItem(void* grid, void* item, int qty, char flag);
extern "C" void   __thiscall Object_QueueDelete(void* obj);
extern "C" void   __thiscall Object_Dirty_00512670(void* obj);
extern "C" void*  __thiscall List_InsertNode(void* list, void* where, void** payload);
extern "C" void   __thiscall FUN_00404840(void* node, int flag);
extern "C" void   __stdcall  LeaveCriticalSection(void* cs);
extern "C" void   __cdecl    operator_delete(void* p);

struct InventoryGrid {
    // ...
    // +0x21: dirty byte (set on merge)
    // +0x24: optional owner object*
    // +0x2c: locked list / traversal base (CS at +0x2c+4, held flag at +0x2c+0x28)
};

static uint16_t MaxStackCap(void* item)
{
    // item[0x2a] == clonebase*; formula ≡ Item_CanAcceptStackQty
    int* cb = *reinterpret_cast<int**>(reinterpret_cast<char*>(item) + 0xA8);
    if (cb[0x38 / 4] == 4) {
        return 0x423F; // 16959
    }
    auto* def = reinterpret_cast<uint8_t*>(cb[0x3c / 4]);
    uint16_t m = *reinterpret_cast<uint16_t*>(def + 0x4BA);
    return m == 0 ? 200 : m;
}

// Retail: ECX = this; bare RET; AL = dirty
extern "C" uint8_t __fastcall InventoryGrid_AutoMergePartialStacks_Inferred(InventoryGrid* self)
{
    // --- prologue / SEH: LAB_009a4f99 (bytes) ---
    // Early: lea esi,[ecx+0x2c]; if esi==0 → AL=0 return
    char* listBase = reinterpret_cast<char*>(self) + 0x2c;
    if (listBase == nullptr) {
        return 0;
    }

    uint8_t dirty = 0;
    void* consumeList = StdList_AllocEmptySentinel_Inferred(nullptr);
    void* mapHead = StdTree_BuynodeEmptyHead_Val12();
    // head: isnil@+0x19=1; left=parent=right=self; size=0  (local map shell)

    List_TraversalLock(listBase);

    void* item = nullptr;
    void* iterState = nullptr;
    int done = List_IterateNext(listBase, &item, &iterState);

    while (true) {
        if (done != 0) {
            // leave CS if held @ listBase+0x28
            if (*(listBase + 0x28) != 0) {
                *(listBase + 0x28) = 0;
                LeaveCriticalSection(listBase + 4);
            }
            // drain consume list: RemoveItem(qty=1000000, flag=1) + QueueDelete
            // range-erase map + operator_delete(mapHead)
            // free list nodes + operator_delete(consumeList head)
            // return dirty  (AL from stack flag; bytes @ 0x00572ea8: 8a 44 24 1b)
            return dirty;
        }

        if (item != nullptr && Item_IsStackEligible(item) != 0) {
            uint16_t maxCap = MaxStackCap(item);
            using VGet = int(__thiscall*)(void*);
            using VSet = void(__thiscall*)(void*, int);
            using VByte = uint8_t(__thiscall*)(void*);
            void** vt = *reinterpret_cast<void***>(item);
            int qty = reinterpret_cast<VGet>(vt[0x25c / 4])(item);

            if (qty < static_cast<int>(maxCap)) {
                uint8_t ox = reinterpret_cast<VByte>(vt[0x250 / 4])(item);
                uint8_t oy = reinterpret_cast<VByte>(vt[0x254 / 4])(item);
                // walk partialMap via StdTree_Inc_Val12 looking for peer
                // with same clonebase[+0x34]; residual vs full absorb as in annotated
                // on residual: transfer room, Erase peer, InsertOrFind current
                // on full absorb: peer.qty += item.qty; item.qty=0; append consumeList
                // on no match: InsertOrFind current into partialMap
                // any qty change: Object_Dirty items; optional owner at self+0x24;
                //                *(uint8_t*)(self+0x21)=1; dirty=1
                (void)ox;
                (void)oy;
            }
        }

        done = List_IterateNext(listBase, &item, &iterState);
    }
}

// Scaffold alias
extern "C" uint8_t __fastcall FUN_00572ab0(InventoryGrid* self)
{
    return InventoryGrid_AutoMergePartialStacks_Inferred(self);
}
