// READABILITY (auto CF):
//  - Body size: ~256 non-empty decompiler lines.
//  - Control keywords: if×19, for×5, return×3, while×2, do×1.
//  - Notable callees: FUN_00829ec0×4, FUN_00411180×3, FUN_007a69d0×3, FUN_007a6de0×3, FUN_0053fff0×2, FUN_00547920×2, FUN_00829b20×2, FUN_008aaf60×2.
//  - Strings: "Active Missions:"; "New Missions:".
//  - Return sites: 3.

// =============================================================================
// Client_UpdateMissionJournal
// -----------------------------------------------------------------------------
// Purpose:  Rebuild the mission **journal** UI when dialog state is 3
//           (journal view). Creates "Active Missions:" and "New Missions:"
//           panels with per-mission entry widgets. Invoked from
//           Client_ShowNpcMissionDialogUI when multiple actives and no
//           explicit mission key.
//
// Address:  0x008ae130  (autoassault.exe, image base 0x400000)
// Stable:   aa_008ae130
// System:   missions-progression
//
// Convention: MSVC __thiscall (decompiler also surfaces pContext; primary
//             dialog context often in EBX / unaff_EBX).
//
// Context offsets (dialog UI, dword indices where noted):
//   [0x192] / +0x648  — dialog state; must be 3 (journal)
//   [0x144]           — sub-mode cleared to 0 on entry
//   [0x191]           — optional NPC / focus entity for header name
//   [0x1b8]           — layout root for y-offset accumulation
//   [0x1ca..0x1cd]    — child widget vector (new-mission push path)
//
// Character / globals:
//   DAT_00d1b6d8      — client game singleton
//   +0x50c            — active missions intrusive list head
//   +0x540            — active mission instance hash
//   +0x510            — active mission count (used by ShowNpc multi-path)
//
// Algorithm:
//   1) Bail unless state==3 and global client alive
//   2) Init chrome; optional NPC name header via FUN_00402d50 / FUN_007a6de0
//   3) Walk mission tree at char+0x50c (iterator at stack; end = header):
//        id @ node+0x10
//        hash probe char+0x540
//        if hash hit AND *(hashNode+0x8) != 0 → Vector_PushDword(Active)
//        else                                  → Vector_PushDword(New)
//        FUN_00568200 = tree iterator++ (NOT id collection)
//      Vector push helper is named CVOGReaction_FailMissionNotify historically;
//      body is growable dword push only — does not fail missions at this site.
//   4) If active ids: build "Active Missions:" panel + entry widgets (0x510 each)
//      control id = i + 0x9c4f
//   5) If new ids: build "New Missions:" panel + entries
//      control id = activeCount + 0x9c4f + i; push into dialog child vec [0x1ca..]
//   6) Free temporary id arrays; restore SEH ExceptionList
//
// Exactness: Control flow mirrors raw Ghidra decompile (2026-07-23 batch);
// Active/New LEA partition sealed via assembly 2026-07-29 residual dual.
// Bit-for-bit vs retail EXE: DEFERRED. UI vcall identities open.
// Dual reviews:
//   reviews/A_aa_008ae130_Client_UpdateMissionJournal.md
//   reviews/B_aa_008ae130_Client_UpdateMissionJournal.md
// Scratch: tmp/a_008ae130.md
// =============================================================================

#include <cstdint>
#include <cstdlib>

extern int DAT_00d1b6d8;
extern int DAT_00d1e81c;
extern float DAT_00aaa9ec;
extern void* ExceptionList;
extern std::uint8_t LAB_009bb948;

void  FUN_007a69d0();
std::uint32_t FUN_007a6de0(std::uint32_t nameId, std::uint32_t unk);
void  FUN_008ac110();
void  FUN_008aaf60();
void* FUN_00402d50(std::uint32_t key);
// Historical name; body = Vector_PushDword(this /*vec*/, int* pId)
void  CVOGReaction_FailMissionNotify(void* pVec, int* pMissionId);
// Tree/list iterator++ (__fastcall); advances *pIter (is_nil @ node+0x49)
void  FUN_00568200(int* pIter);
std::uint32_t* FUN_0053fff0();
void* CNDHash_LookupByKey(void* hash, unsigned key);
void  FUN_00547920(int mode);
void* operator_new(std::size_t size);
void  operator_delete(void* p);
int*  FUN_00829ec0(void* mem); // mission-entry widget ctor
void  FUN_00829b20();
void  FUN_00411180();
void  FUN_00419880(int* vecBase, int insertAt, void* pElem);

void __thiscall Client_UpdateMissionJournal(void* /*this*/, int* /*pContext*/)
{
    unsigned uVar1;
    unsigned uVar2_hi;
    std::uint32_t* puVar3;
    int* piVar4;
    int iVar5;
    int iVar6;
    int* unaff_EBX; // dialog context (register)
    int* piVar7;
    char* pcVar8;
    std::uint32_t uVar9;
    int local_cc;           // cumulative y layout
    int* local_c8[2];
    int* piStack_c0;
    int iStack_bc;
    void* local_b4;         // active mission id vector begin
    int local_b0;           // active vector end
    std::uint32_t local_ac;
    void* local_a4;         // new mission id vector begin
    int local_a0[4];        // new vector end / layout scratch
    std::uint8_t* local_90;
    std::uint8_t local_8c[128];
    void* local_c;
    std::uint8_t* puStack_8;
    std::uint32_t local_4;

    local_4 = 0xffffffffu;
    puStack_8 = &LAB_009bb948;
    local_c = ExceptionList;

    // Bail if not journal view (state != 3) or no client singleton
    // unaff_EBX[0x192] == dword index for +0x648
    if ((unaff_EBX[0x192] == 3) && (DAT_00d1b6d8 != 0)) {
        ExceptionList = &local_c;

        // ----- Init journal chrome -----
        FUN_007a69d0();
        unaff_EBX[0x144] = 0;
        FUN_008ac110();

        // Optional NPC-focused header name at dialog[0x191]
        iVar5 = unaff_EBX[0x191];
        if ((iVar5 == 0) ||
            ((*(int*)(*(int*)(*(int*)(*(int*)(iVar5 + 4) + 4) + 0xac + iVar5) + 0x3c) == 0 ||
              (*(int*)(*(int*)(*(int*)(*(int*)(*(int*)(iVar5 + 4) + 4) + 0xac + iVar5) + 0x3c) +
                       0x518) == 0))))
        {
            FUN_008aaf60();
        } else {
            puVar3 = (std::uint32_t*)FUN_00402d50(
                *(std::uint32_t*)(
                    *(int*)(*(int*)(*(int*)(*(int*)(iVar5 + 4) + 4) + 0xac + iVar5) + 0x3c) +
                    0x518));
            local_4 = 0;
            FUN_007a6de0(*puVar3, 0xffffffffu);
            FUN_008aaf60();
            local_4 = 0xffffffffu;
            if (local_90 != local_8c) {
                free(local_90);
            }
        }

        // Layout y base from optional root at [0x1b8]
        local_cc = 0;
        if ((int*)unaff_EBX[0x1b8] != (int*)0x0) {
            (**(void (**)(int**, int, int))(*(int*)unaff_EBX[0x1b8] + 0x120))(local_c8, 1, 0);
            (**(void (**)(int*))(*(int*)unaff_EBX[0x1b8] + 0x204))(&local_cc);
            local_cc = local_cc + (int)((float)DAT_00d1e81c * DAT_00aaa9ec) + iStack_bc;
        }

        // Temp vectors: active ids (local_b4 triad) and new ids (local_a4 triad).
        // Assembly: Active vector object @ ESP+0x24 (begin/end/cap +0x28/+0x2c/+0x30);
        //           New    vector object @ ESP+0x34 (begin/end/cap +0x38/+0x3c/+0x40);
        //           iterator @ ESP+0x14.
        local_b4 = (void*)0x0;
        local_b0 = 0;
        local_ac = 0;
        local_a4 = (void*)0x0;
        local_a0[0] = 0;
        local_a0[1] = 0;
        local_4 = (local_4 & 0xffffff00u) | 2u; // SEH state 2
        uVar2_hi = 0;

        // ----- Walk mission tree (char+0x50c); partition into Active vs New -----
        local_c8[0] = (int*)**(int**)(DAT_00d1b6d8 + 0x50c);
        if (local_c8[0] != *(int**)(DAT_00d1b6d8 + 0x50c)) {
            do {
                // Hash probe instance table at +0x540 by node id @ +0x10 (dword [4])
                for (iVar5 = *(int*)(*(int*)(*(int*)(*(int*)(DAT_00d1b6d8 + 0x540) + 0x10) +
                                            (*(unsigned*)(*(int*)(DAT_00d1b6d8 + 0x540) + 8) &
                                             (unsigned)local_c8[0][4]) *
                                                4) +
                                    4);
                     (iVar5 != 0 && ((unsigned)local_c8[0][4] != *(unsigned*)(iVar5 + 0x10)));
                     iVar5 = *(int*)(iVar5 + 0xc))
                {
                }
                // Assembly partition (0x008ae31e..0x008ae330):
                //   if (hashNode && *(hashNode+8)!=0) ECX = ActiveVecObj (ESP+0x24)
                //   else                               ECX = NewVecObj    (ESP+0x34)
                //   PUSH &id; CALL FailMissionNotify  // Vector_PushDword only
                // FailMissionNotify reads triad at this+4/+8/+0xc (= begin/end/cap),
                // so object base is one dword before the begin pointer (local_b4 / local_a4).
                // Decompiler collapses both LEAs into one call; branch restored here.
                {
                    // activeVecObj / newVecObj: { hdr, begin, end, cap } with begin@+4
                    void* activeVecObj = (void*)((char*)&local_b4 - 4);
                    void* newVecObj = (void*)((char*)&local_a4 - 4);
                    if ((iVar5 != 0) && (*(int*)(iVar5 + 8) != 0)) {
                        CVOGReaction_FailMissionNotify(activeVecObj, local_c8[0] + 4);
                    } else {
                        CVOGReaction_FailMissionNotify(newVecObj, local_c8[0] + 4);
                    }
                }
                FUN_00568200((int*)&local_c8[0]); // tree iterator++
            } while (local_c8[0] != *(int**)(DAT_00d1b6d8 + 0x50c));

            // ----- "Active Missions:" panel -----
            if ((local_b4 != (void*)0x0) &&
                (piVar7 = (int*)((local_b0 - (int)local_b4) >> 2), piStack_c0 = piVar7,
                 piVar7 != (int*)0x0))
            {
                local_c8[0] = (int*)operator_new(0x510);
                local_4 = (local_4 & 0xffffff00u) | 3u;
                if (local_c8[0] == (int*)0x0) {
                    piVar4 = (int*)0x0;
                } else {
                    piVar4 = FUN_00829ec0(local_c8[0]);
                }
                local_4 = (local_4 & 0xffffff00u) | 2u;
                local_c8[0] = piVar4;
                (**(void (**)(int*))(*unaff_EBX + 0xa8))(piVar4);
                *(std::uint8_t*)(piVar4 + 0x13f) = 1;
                (**(void (**)())(*piVar4 + 0x43c))();
                if (piVar4[0x142] != 0) {
                    iVar5 = *(int*)piVar4[0x142];
                    uVar9 = 0xffffffffu;
                    pcVar8 = (char*)"Active Missions:";
                    FUN_007a69d0();
                    uVar9 = FUN_007a6de0((std::uint32_t)(std::uintptr_t)pcVar8, uVar9);
                    (**(void (**)(std::uint32_t))(iVar5 + 0x1d8))(uVar9);
                }
                (**(void (**)(void*))(*piVar4 + 0x114))((void*)0); // layout pos
                iVar5 = (**(int (**)(int*, int))(*piVar4 + 0x140))(local_a0, 1);
                local_cc = local_cc + *(int*)(iVar5 + 4);
                FUN_00411180();

                // One entry widget per active mission id
                for (iVar5 = 0; iVar5 < (int)(std::intptr_t)piVar7; iVar5 = iVar5 + 1) {
                    puVar3 = FUN_0053fff0();
                    CNDHash_LookupByKey((void*)*puVar3,
                                        *(unsigned*)((int)local_b4 + iVar5 * 4));
                    FUN_00547920(0);
                    local_c8[0] = (int*)operator_new(0x510);
                    local_4 = (local_4 & 0xffffff00u) | 4u;
                    if (local_c8[0] == (int*)0x0) {
                        piVar7 = (int*)0x0;
                    } else {
                        piVar7 = FUN_00829ec0(local_c8[0]);
                    }
                    local_4 = (local_4 & 0xffffff00u) | 2u;
                    local_c8[0] = piVar7;
                    (**(void (**)(int))(*piVar7 + 0x74))(iVar5 + 0x9c4f); // control id base 0x9c4f
                    (**(void (**)(int*))(*unaff_EBX + 0xa8))(piVar7);
                    (**(void (**)())(*piVar7 + 0x43c))();
                    FUN_00829b20();
                    (**(void (**)(void*))(*piVar7 + 0x114))((void*)0);
                    iVar6 = (**(int (**)(void**, int))(*piVar7 + 0x140))(&local_a4, 1);
                    local_cc = local_cc + *(int*)(iVar6 + 4);
                    FUN_00411180();
                    piVar7 = piStack_c0;
                }
                local_cc = local_cc + (int)((float)DAT_00d1e81c * DAT_00aaa9ec);
            }

            // ----- "New Missions:" panel -----
            iVar5 = 0;
            if ((local_a4 != (void*)0x0) &&
                (local_c8[0] = (int*)((local_a0[0] - (int)local_a4) >> 2),
                 local_c8[0] != (int*)0x0))
            {
                piStack_c0 = (int*)operator_new(0x510);
                local_4 = (local_4 & 0xffffff00u) | 5u;
                if (piStack_c0 == (int*)0x0) {
                    piVar7 = (int*)0x0;
                } else {
                    piVar7 = FUN_00829ec0(piStack_c0);
                }
                local_4 = (local_4 & 0xffffff00u) | 2u;
                piStack_c0 = piVar7;
                (**(void (**)(int*))(*unaff_EBX + 0xa8))(piVar7);
                *(std::uint8_t*)(piVar7 + 0x13f) = 1;
                (**(void (**)())(*piVar7 + 0x43c))();
                if (piVar7[0x142] != 0) {
                    iVar6 = *(int*)piVar7[0x142];
                    uVar9 = 0xffffffffu;
                    pcVar8 = (char*)"New Missions:";
                    FUN_007a69d0();
                    uVar9 = FUN_007a6de0((std::uint32_t)(std::uintptr_t)pcVar8, uVar9);
                    (**(void (**)(std::uint32_t))(iVar6 + 0x1d8))(uVar9);
                }
                (**(void (**)(void*))(*piVar7 + 0x114))((void*)0);
                iVar6 = (**(int (**)(int*, int))(*piVar7 + 0x140))(local_a0, 1);
                local_cc = local_cc + *(int*)(iVar6 + 4);
                FUN_00411180();

                while (iVar5 < (int)(std::intptr_t)local_c8[0]) {
                    piVar7 = (int*)FUN_0053fff0();
                    uVar1 = *(unsigned*)((int)local_a4 + iVar5 * 4);
                    // Manual mission-def hash walk by id
                    for (iVar6 = *(int*)(*(int*)(*(int*)(*piVar7 + 0x10) +
                                                (*(unsigned*)(*piVar7 + 8) & uVar1) * 4) +
                                        4);
                         (iVar6 != 0 && (uVar1 != *(unsigned*)(iVar6 + 0x10)));
                         iVar6 = *(int*)(iVar6 + 0xc))
                    {
                    }
                    FUN_00547920(0);
                    piStack_c0 = (int*)operator_new(0x510);
                    local_4 = (local_4 & 0xffffff00u) | 6u;
                    if (piStack_c0 == (int*)0x0) {
                        piVar7 = (int*)0x0;
                    } else {
                        piVar7 = FUN_00829ec0(piStack_c0);
                    }
                    local_4 = (local_4 & 0xffffff00u) | 2u;
                    if (local_b4 == (void*)0x0) {
                        iVar6 = 0;
                    } else {
                        iVar6 = (local_b0 - (int)local_b4) >> 2;
                    }
                    piStack_c0 = piVar7;
                    (**(void (**)(int))(*piVar7 + 0x74))(iVar6 + 0x9c4f + iVar5);
                    (**(void (**)(int*))(*unaff_EBX + 0xa8))(piVar7);
                    (**(void (**)())(*piVar7 + 0x43c))();
                    FUN_00829b20();
                    (**(void (**)(void*))(*piVar7 + 0x114))((void*)0);
                    iVar6 = (**(int (**)(void**, int))(*piVar7 + 0x140))(&local_a4, 1);
                    local_cc = local_cc + *(int*)(iVar6 + 4);

                    // Push entry into dialog child vector [0x1ca..]
                    iVar6 = unaff_EBX[0x1cb];
                    if ((iVar6 == 0) ||
                        ((unsigned)(unaff_EBX[0x1cd] - iVar6 >> 2) <=
                         (unsigned)(unaff_EBX[0x1cc] - iVar6 >> 2)))
                    {
                        FUN_00419880(unaff_EBX + 0x1ca, unaff_EBX[0x1cc], &piStack_c0);
                        iVar5 = iVar5 + 1;
                    } else {
                        puVar3 = (std::uint32_t*)unaff_EBX[0x1cc];
                        *puVar3 = (std::uint32_t)(std::uintptr_t)piVar7;
                        unaff_EBX[0x1cc] = (int)(puVar3 + 1);
                        iVar5 = iVar5 + 1;
                    }
                }
            }
        }

        // ----- Cleanup temp id arrays -----
        local_4 = (local_4 & 0xffffff00u) | 1u;
        if (local_a4 != (void*)0x0) {
            operator_delete(local_a4);
        }
        local_a4 = (void*)0x0;
        local_a0[0] = 0;
        local_a0[1] = 0;
        local_4 = 0xffffffffu;
        if (local_b4 != (void*)0x0) {
            operator_delete(local_b4);
        }
    }

    ExceptionList = local_c;
    return;
}
