// READABILITY (auto CF):
//  - Body size: ~71 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, do×1, for×1, goto×1, while×1.
//  - Notable callees: FUN_004022a0×2, CVOGReaction_RemoveInventoryItem, FUN_00403430, FUN_00404840, FUN_0040fb90, FUN_00418700, FUN_004294f0, FUN_004d4790.
//  - Return sites: 2.

// =============================================================================
// CVOGReaction_RemoveInventoryItem
// -----------------------------------------------------------------------------
// Purpose:  Walk a locked inventory (this) and remove up to `qty` of items whose
//           clonebase CBID equals `cbid`. Partial stack reduce via vfunc+0x260
//           when stack qty > remaining need; else full-remove stacks into a temp
//           list, then FUN_00571b80 + FUN_004d4790 each removed node.
//
// Address:  0x005721c0  (autoassault.exe, image base 0x400000)
// Stable:   aa_005721c0
// System:   inventory-transfer
//
// Convention: MSVC __thiscall
//   this / pInventory   inventory object (+0x30 CRITICAL_SECTION, +0x54 held flag)
//   cbid                target clonebase id (param_2); -1 → return 0
//   qty                 count to remove (param_3); <1 → return 0
//
// Returns: total quantity actually removed (accumulated in param_3 reuse).
//
// Algorithm:
//   1) SEH frame; early-out if cbid==-1 or qty<1
//   2) Build temp list (FUN_0040fb90); take inventory lock (FUN_004294f0)
//   3) Iterate items FUN_004022a0; match clonebase+0x34 == cbid
//   4) qty_stack = vfunc+0x25c; if stack > need → reduce (vfunc+0x260) and stop
//   5) else subtract stack from need, queue node for destroy, continue
//   6) Leave CS if held; destroy queued items; free list; return removed total
//
// Exactness: CF mirrors raw (including infinite-loop decompile shape of scan).
//            Bit-for-bit / runtime / diff: DEFERRED.
// =============================================================================

#include <cstdint>
#include <windows.h>

extern void* ExceptionList;
extern std::uint8_t LAB_009a4f22; // SEH handler label from image

void* FUN_0040fb90();
void  FUN_004294f0();
int   FUN_004022a0(void* iterState, int** outItem);
int   FUN_00418700(void* list, std::uint32_t a, int** item);
void  FUN_00404840(int a);
void  FUN_00571b80(std::uint32_t item, int qty, int flag);
void  FUN_004d4790(std::uint32_t item);
void  FUN_00403430();

/// @return quantity removed (0 on bad args or empty match)
int __thiscall CVOGReaction_RemoveInventoryItem(
    int pInventory,
    int cbid,
    int qty)
{
    std::uint32_t* puNode;
    int* piItem;
    std::uint32_t* puList;
    int iVar4;
    int iNeed;
    int* local_24;
    std::uint32_t local_20;
    int local_1c;
    std::uint32_t* local_14;
    std::uint32_t local_10;
    void* local_c;
    std::uint8_t* puStack_8;
    std::uint32_t local_4;

    iNeed = qty;
    local_4 = 0xFFFFFFFFu;
    puStack_8 = &LAB_009a4f22;
    local_c = ExceptionList;

    if ((cbid == -1) || (qty < 1)) {
        return 0;
    }

    ExceptionList = &local_c;
    local_1c = pInventory;
    puList = reinterpret_cast<std::uint32_t*>(FUN_0040fb90());
    local_10 = 0;
    local_4 = 0;
    local_20 = 0;
    qty = 0; // reused as removed-total accumulator
    local_14 = puList;
    FUN_004294f0();
    iVar4 = FUN_004022a0(&local_20, &local_24);
    piItem = local_24;

    do {
        if (iVar4 != 0) {
        LAB_005722df:
            // Release inventory CS if held
            if (*reinterpret_cast<char*>(pInventory + 0x54) != '\0') {
                *reinterpret_cast<std::uint8_t*>(pInventory + 0x54) = 0;
                LeaveCriticalSection(
                    reinterpret_cast<LPCRITICAL_SECTION>(pInventory + 0x30));
            }
            // Destroy every queued full-remove item
            for (puNode = reinterpret_cast<std::uint32_t*>(*puList);
                 puNode != puList;
                 puNode = reinterpret_cast<std::uint32_t*>(*puNode)) {
                FUN_00571b80(puNode[2], 1000000, 1);
                FUN_004d4790(puNode[2]);
            }
            FUN_00403430();
            ExceptionList = local_c;
            return qty;
        }

        local_24 = piItem;
        // Match CBID at item's clonebase+0x34 (item dword [0x2a] = +0xa8)
        if ((piItem != nullptr)
            && (*reinterpret_cast<int*>(piItem[0x2a] + 0x34) == cbid)) {
            iVar4 = (**(int(**)())(*piItem + 0x25c))(); // stack quantity
            if (0 < iVar4 - iNeed) {
                // Partial reduce: set remaining stack = old - need
                (**(void(**)(int))(*piItem + 0x260))(iVar4 - iNeed);
                qty = qty + iNeed;
                goto LAB_005722df;
            }
            // Full remove this stack
            iVar4 = (**(int(**)())(*piItem + 0x25c))();
            iNeed = iNeed - iVar4;
            iVar4 = FUN_00418700(puList, puList[1], &local_24);
            FUN_00404840(1);
            puList[1] = iVar4;
            **reinterpret_cast<int**>(iVar4 + 4) = iVar4;
            iVar4 = (**(int(**)())(*piItem + 0x25c))();
            qty = qty + iVar4;
            puList = local_14;
        }

        pInventory = local_1c;
        iVar4 = FUN_004022a0(&local_20, &local_24);
        piItem = local_24;
    } while (true);
}
