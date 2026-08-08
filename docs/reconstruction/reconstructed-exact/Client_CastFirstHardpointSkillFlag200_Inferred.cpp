// =============================================================================
// Client_CastFirstHardpointSkillFlag200_Inferred
// -----------------------------------------------------------------------------
// Purpose:  When local character has host-mode flag (+0x6b8), lock-walk the
//           hardpoint/HB list on player or active vehicle, select the first
//           enabled CVOGHBSkillBase, and if skill flags (+0x614) include bit
//           0x200, cast skillId (+0x5fc) through Client_CastSkillFromQuickBarSlot.
//
// Address:  0x008c4fc0  (autoassault.exe, image base 0x400000)
// Stable:   aa_008c4fc0
// System:   skills-abilities (host hardpoint cast leaf)
// Ghidra:   FUN_008c4fc0
//
// Convention: no stack formals; SUB ESP,8 / ADD ESP,8 / RET.
//             Cast site: PUSH skillId; MOV ESI,&DAT_00d1a840; CALL
//             Client_CastSkillFromQuickBarSlot (callee ESI=client, RET 4).
//
// Control flow:
//   1) Gate DAT_00d1b6d8 && *(char*)(player+0x6b8)
//   2) listHost = MI(player)+0xb4  if +0x30c==0 || vehicle@+0x250==0
//               else MI(vehicle)+0xb4
//   3) List_TraversalLock(listHost); iterate List_IterateNext until first
//      node with +0x1c==1, RTTI→CVOGHBSkillBase, +0x140≠0 → skill = base+0x24
//   4) Unlock list CS if held (+0x28)
//   5) if skill && (skill+0x614 & 0x200): CastSkillFromQuickBarSlot(skill+0x5fc)
//
// Caller (sole): FUN_008c50f4 @ 0x008c510f when player+0x6b8 && !player+0x6b9
//                (else parent may call Client_Input_TryUseModChip).
//
// Callees:
//   List_TraversalLock                 0x004294f0  aa_004294f0
//   List_IterateNext                   0x004022a0  aa_004022a0
//   __RTDynamicCast                    CVOGHBBase → CVOGHBSkillBase
//   LeaveCriticalSection               Win32
//   Client_CastSkillFromQuickBarSlot   0x009418e0  aa_009418e0
//
// Exactness: Behavior-preserving CF. Not modernization.
// Bit-for-bit / runtime: DEFERRED. Dual WQ8R-F 2026-08-04.
// Dual reviews:
//   reviews/A_aa_008c4fc0_Client_CastFirstHardpointSkillFlag200_Inferred.md
//   reviews/B_aa_008c4fc0_Client_CastFirstHardpointSkillFlag200_Inferred.md
// Scaffold: reconstructed-exact/FUN_008c4fc0.cpp
// =============================================================================

#include <cstdint>
#include <windows.h>

extern "C" int  DAT_00d1b6d8;
extern "C" void List_TraversalLock(void* list); // FUN_004294f0
// FUN_004022a0 — thiscall list; outs via two stack ptrs (payload/node order per decomp)
extern "C" unsigned __thiscall List_IterateNext(void* list, void** a, void** b);
extern "C" void* __RTDynamicCast(void*, long, void*, void*, int);
extern "C" void Client_CastSkillFromQuickBarSlot(void* client, int skillId);
extern "C" char CVOGHBBase_RTTI_Type_Descriptor[];
extern "C" char CVOGHBSkillBase_RTTI_Type_Descriptor[];

// Retail multi-inherit field fetch used by body:
//   *(T*)( *(int*)(*(int*)(obj+4)+4) + off + obj )
static void* MiFieldPtr(void* obj, int off)
{
    int base = (int)obj;
    int mid = *(int*)(*(int*)(base + 4) + 4);
    return (void*)(mid + off + base);
}

/// Host-mode first hardpoint skill cast when flag bit 0x200 is set.
void Client_CastFirstHardpointSkillFlag200_Inferred(void)
{
    int player = DAT_00d1b6d8;
    if (player == 0 || *(char*)(player + 0x6b8) == '\0') {
        return;
    }

    void* listHost;
    if (*(char*)(player + 0x30c) == '\0' || *(int*)(player + 0x250) == 0) {
        listHost = *(void**)MiFieldPtr((void*)player, 0xb4);
    } else {
        listHost = *(void**)MiFieldPtr(*(void**)(player + 0x250), 0xb4);
    }

    if (listHost == nullptr) {
        return;
    }

    int skillRuntime = 0;
    void* node = nullptr;     // decomp local_8
    void* payload = nullptr;  // decomp local_4

    List_TraversalLock(listHost);
    unsigned walkRc = List_IterateNext(listHost, &payload, &node);
    while (walkRc == 0) {
        if (node != nullptr && *(int*)((int)node + 0x1c) == 1) {
            void* skillHb = __RTDynamicCast(
                node, 0,
                CVOGHBBase_RTTI_Type_Descriptor,
                CVOGHBSkillBase_RTTI_Type_Descriptor,
                0);
            if (skillHb != nullptr && *(char*)((int)skillHb + 0x140) != '\0') {
                skillRuntime = (int)skillHb + 0x24;
                break;
            }
        }
        walkRc = List_IterateNext(listHost, &payload, &node);
    }

    if (*(char*)((int)listHost + 0x28) != '\0') {
        *(char*)((int)listHost + 0x28) = 0;
        LeaveCriticalSection((LPCRITICAL_SECTION)((int)listHost + 4));
    }

    if (skillRuntime != 0 &&
        (*(unsigned*)(skillRuntime + 0x614) & 0x200u) != 0) {
        // Retail: PUSH [skill+0x5fc]; MOV ESI, &DAT_00d1a840; CALL
        Client_CastSkillFromQuickBarSlot(
            (void*)0x00d1a840,
            *(int*)(skillRuntime + 0x5fc));
    }
}
