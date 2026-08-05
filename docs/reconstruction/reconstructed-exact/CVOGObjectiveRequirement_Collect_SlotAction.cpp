// =============================================================================
// CVOGObjectiveRequirement_Collect_SlotAction  (was FUN_006124b0)
// -----------------------------------------------------------------------------
// Address:  0x006124b0  (autoassault.exe, image base 0x400000)
// Stable:   aa_006124b0
// System:   missions-progression (+ inventory-transfer collect bridge)
//
// Purpose: Collect objective UI/journal progress text.
//          Live cargo count via InventoryGrid_CountItemsByCbid — unlike
//          UseItem_SlotAction, which formats from 0x2071 slot floats.
//
// Vtable:   CVOGObjectiveRequirement_Collect PTR_FUN_009e12c4 +0x18 → this
// RTTI str: ".?AVCVOGObjectiveRequirement_Collect@@" @ 0x00afe9ac
// XML type: "collect" (sibling serialize @ 0x00611a00)
//
// Layout:
//   req+0x10  item CBID
//   req+0x14  NumToCollect
//   req+0x58  has level-range text
//   req+0x5c / +0x60  RequireLevelMin / Max
//   stack0 character:
//     +0x250 vehicle → +0x2b0 cargo InventoryGrid (type-1 DropResponse grid)
//   stack1 objState: unread (UseItem SlotAction uses it for slot floats)
//
// Formula:
//   have = CountItemsByCbid(cargo, CBID, includeBroken=0)
//   display = (have < NumToCollect) ? have : NumToCollect
//   sprintf("%s: %d / %d", itemName, display, NumToCollect)  // fmt @ 0x009df764
//
// ABI: __thiscall + RET 0x10 (four stack dwords). Dual residual seal 2026-07-29.
// Exactness: Behavior-preserving rewrite of Ghidra decompile + asm residual.
//            Not modernization. Bit-for-bit deferred.
// =============================================================================

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>

extern int  __thiscall InventoryGrid_CountItemsByCbid(void* /*ecx grid flattened*/, int cbid, char includeFlagged);
extern int  FUN_00404d70(int cbid);
extern void FUN_007a69d0(void);
extern int  FUN_007a6de0(int nameId, int sentinel);
extern int* FUN_00402d50(int nameBlobOffset);
extern void FUN_004f1e20(int a, int b);
extern void FUN_004eb010(void);

// Asm-sealed ABI (dual residual 2026-07-29): RET 0x10, four stack formals.
// Decompiler mislabeled character as unaff_retaddr; body loads stack0 → EBP.
// stack1 is the shared SlotAction objState formal (unread here; UseItem uses it).
// See reviews/a_006124b0.md.

int __thiscall CVOGObjectiveRequirement_Collect_SlotAction(
    int thisReq,
    int character,                 // stack0 — cargo host
    void* /*objState unread*/,     // stack1 — family formal
    char* outBuf,                  // stack2
    std::size_t outCap)            // stack3
{
    char cVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    std::uint32_t* puVar5;
    std::uint32_t uVar6;
    std::uint32_t uVar7;
    char* pcVar8;
    std::uint32_t uVar9;
    std::uint32_t uVar10;
    char* pcVar11;
    bool bVar12;
    std::uint32_t uVar13;
    char acStack_314[128];
    std::uint8_t* puStack_294;
    std::uint8_t auStack_290[127];
    char cStack_211;
    char acStack_210[512];
    void* cargoGrid;

    iVar2 = FUN_00404d70(*(int*)(thisReq + 0x10));
    FUN_007a69d0();
    if (iVar2 == 0) {
        return 0;
    }

    bVar12 = (*(int*)(iVar2 + 0x3c) == 0);
    if (bVar12) {
        FUN_004f1e20(0, 1);
    }

    // Cargo gate (asm): character / vehicle+0x250 / cargo+0x2b0 non-null
    if (character == 0 ||
        *(int*)(character + 0x250) == 0 ||
        *(int*)(*(int*)(character + 0x250) + 0x2b0) == 0) {
        return 0;
    }
    cargoGrid = (void*)*(int*)(*(int*)(character + 0x250) + 0x2b0);

    // display = min(count, NumToCollect); 2nd Count only when under target
    iVar4 = *(int*)(thisReq + 0x14); // NumToCollect default display
    iVar3 = InventoryGrid_CountItemsByCbid(cargoGrid, *(int*)(thisReq + 0x10), 0);
    if (iVar3 < iVar4) {
        iVar4 = InventoryGrid_CountItemsByCbid(cargoGrid, *(int*)(thisReq + 0x10), 0);
    }

    puVar5 = (std::uint32_t*)FUN_00402d50(*(int*)(iVar2 + 0x3c) + 0x92);
    uVar13 = *(std::uint32_t*)(thisReq + 0x14);
    uVar6 = (std::uint32_t)FUN_007a6de0((int)*puVar5, (int)0xffffffff);
    std::sprintf(acStack_210, "%s: %d / %d", (char*)uVar6, iVar4, (int)uVar13);

    if (*(char*)(thisReq + 0x58) != '\0') {
        uVar13 = *(std::uint32_t*)(thisReq + 0x60);
        uVar6 = *(std::uint32_t*)(thisReq + 0x5c);
        uVar7 = (std::uint32_t)FUN_007a6de0((int)"Level", (int)0xffffffff);
        std::sprintf(acStack_314, " %s: %d-%d", (char*)uVar7, (int)uVar6, (int)uVar13);
        // raw dword/byte append of acStack_314 onto acStack_210 tail
        pcVar8 = acStack_314;
        do {
            cVar1 = *pcVar8;
            pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        uVar9 = (std::uint32_t)((int)pcVar8 - (int)acStack_314);
        pcVar8 = &cStack_211;
        do {
            pcVar11 = pcVar8 + 1;
            pcVar8 = pcVar8 + 1;
        } while (*pcVar11 != '\0');
        pcVar11 = acStack_314;
        for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
            *(std::uint32_t*)pcVar8 = *(std::uint32_t*)pcVar11;
            pcVar11 = pcVar11 + 4;
            pcVar8 = pcVar8 + 4;
        }
        for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
            *pcVar8 = *pcVar11;
            pcVar11 = pcVar11 + 1;
            pcVar8 = pcVar8 + 1;
        }
    }

    if (bVar12) {
        FUN_004eb010();
    }

    std::strncat(outBuf, acStack_210, outCap);
    pcVar8 = acStack_210;
    do {
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    return (int)pcVar8 - (int)(acStack_210 + 1);
}
