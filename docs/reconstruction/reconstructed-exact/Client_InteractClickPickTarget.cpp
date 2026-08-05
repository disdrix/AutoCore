// =============================================================================
// Client_InteractClickPickTarget
// -----------------------------------------------------------------------------
// Purpose:  Click/pick hub for world-object interact. Resolves a target from
//           screen coords (ray + Skill_GatherTargetsInArea / helpers), stores
//           selection on the client controller, then may:
//             (1) Client_SendUseObject_IfInteractable  — if FUN_005245d0 or
//                 CVOGCharacter_FindActiveObjectiveIdForInteract (FUN_00524520)
//                 returns non-zero for the pick
//             (2) Client_SendUseObject                 — if selected object has
//                 interact flag at +0x11c AND Euclidean distance to player body
//                 <= DAT_00aaa6fc (25.0f)
//           Secondary type-switch (clone type @ clonebase+0x38) may send
//           QuestItemPickup 0x205D (type 4), clear select, or other packets.
//
// Address:  0x009247b0  (autoassault.exe, image base 0x400000)
// Stable:   aa_009247b0
// System:   interaction-activation
// Generated: 2026-07-29 human refine + dual residual strengthen (25f/0.015f)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Not modernization. Bit-for-bit vs retail: DEFERRED.
//
// Caller:   FUN_009251d0 (only xref) — click/input path:
//             Client_InteractClickPickTarget(EBX?, mousePacked, 0|1, DAT_00d1b205)
//             param_3 = 0 when DAT_00d1a860 (soft path); else 1 (commit path)
//
// Convention (decompiler residuals):
//   unaff_EBX  = client / input controller* (this residual; SendUseObject ECX)
//   param_1    = forwarded to vtbl+0x380 alternate path
//   param_2    = packed screen coords (lo16 x, hi16 y)
//   param_3    = soft(0) vs commit(1) mode bit (caller-supplied)
//   param_4    = filter flag (low char): 0 → ignore pick == self / vehicle
//
// Constants (Ghidra read_memory + asm 2026-07-29 residual):
//   DAT_00aaa6fc = 25.0f   (0x41c80000)  // UseObject gate + gather cap A + scale B
//   _DAT_00aaacbc = 0.015f (0x3c75c28f)  // post-FUN_0040d020 gather scale
//   DAT_00a110d8 = 10.0f   (0x41200000)  // soft A radius mult
//   DAT_00aaa688 =  5.0f   (0x40a00000)  // soft A2 radius mult
//   DAT_00a1109c = 40.0f   (0x42200000)  // soft B radius cap
//
// Soft gather (Skill_GatherTargetsInArea ABI):
//   Soft A:  maxTargets=1, gatherMode=3 (living interact), radius=scale*10 cap 25
//   Soft A2: FUN_0058cd60 (...1,5...) empty-fallback, radius=scale*5 cap 25
//   Soft B:  maxTargets=1, gatherMode=2 (hostile), radius=scale*25 cap 40
//
// Matchers (asm Confirmed): ECX=DAT_00d1b6d8 character; stack=world object
//   FUN_005245d0 @ 0x00924d8c; FUN_00524520 @ 0x00924da2
//
// UseObject chain:
//   this → Client_SendUseObject_IfInteractable (0x00930d70)  // stage 5 gated
//   this → Client_SendUseObject               (0x00916740)  // stage 7 +0x11c && dist<=25
//   CF allows both same click; wire open
//   CHAIN: reviews/CHAIN_2026-07-29_interaction_useobject.md
//
// Dual + residual:
//   reviews/A_aa_009247b0_Client_InteractClickPickTarget.md
//   reviews/B_aa_009247b0_Client_InteractClickPickTarget.md
//   reviews/a_009247b0.md
// =============================================================================

#include <cstdint>
#include <cmath>

// Named / plate callees (out of unit ownership)
extern std::uint32_t Client_SendUseObject_IfInteractable(void);
extern void Client_SendUseObject(void);
extern void Client_SendSectorPacket(void* conn, int size, void* packet);
extern int* Object_ResolveFromTFID(void* tfid);
extern void Skill_GatherTargetsInArea(
    void* outTfid, int a, void* b, int c, void* pos, float radius,
    int d, int e, int f, int g, int h, int i, int j, int k, int l);
extern int FUN_00524520(int worldObject); // CVOGCharacter_FindActiveObjectiveIdForInteract
extern int FUN_005245d0(int* worldObject); // sibling matcher (vtable+0x44 path)
extern int* FUN_00490070(void* screenOrCam, void* scratch, std::uint32_t flag);
extern char FUN_004cff70(void* a, void* b, void* outHit, int maxRange);
extern float FUN_0040d020(float dx, float dy, float dz);
extern char FUN_0040b1b0(void);
extern void FUN_0093e120(int objectOrZero);
extern void FUN_00941ac0(void* p);
extern void FUN_00938670(std::uint32_t a, std::uint32_t b, float c, int d);
extern void FUN_004f3640(int a, int b);
extern void FUN_0058cd60(void* outTfid, int a, void* b, int c, void* pos,
                         float radius, int d, int e, int f, int g, int h);
extern void FUN_0075c340(void* screen, void* outA, void* outB);

// Globals referenced (names from decompiler / plate)
extern char DAT_00d1a8da;
extern int DAT_00d1b6d8;
extern int DAT_00d1b644;
extern int DAT_00d17944;
extern int DAT_00d1d870;
extern float DAT_00d1d86c;
extern int DAT_00d1d900;
extern int DAT_00d1d904;
extern char DAT_00d1bdfa;
extern char DAT_00d1d867;
extern float DAT_00aaa6fc;   // 25.0f
extern float DAT_00a110d8;   // 10.0f
extern float DAT_00aaa688;   // 5.0f
extern float DAT_00a1109c;   // 40.0f
extern float _DAT_00aaacbc;  // ~0.015f
extern std::uint32_t DAT_00a158b8;
extern std::uint32_t DAT_00a158bc;
extern std::uint32_t DAT_00a158c0;
extern std::uint32_t DAT_00a158c4;
extern char DAT_00d1a840[1];
extern char DAT_00d1a640[1];

struct TFID_16 {
    std::uint32_t dwCoidLo;
    std::uint32_t dwCoidHi;
    std::uint8_t bGlobal;
    std::uint8_t bPad0;
    std::uint8_t bPad1;
    std::uint8_t bPad2;
    std::uint8_t bPad3;
    std::uint8_t bPad4;
    std::uint8_t bPad5;
    std::uint8_t bPad6;
};

// Decompiler signature (returns 0 early-out, 1 handled / no-op success).
std::uint32_t Client_InteractClickPickTarget(
    std::uint32_t param_1,
    std::uint32_t param_2,
    char param_3,
    std::uint32_t param_4)
{
    char* pcVar1;
    bool bVar2;
    char cVar3;
    int* piVar4;
    int* piVar5;
    int iVar6;
    std::uint32_t uVar7;
    float* pfVar8;
    int* unaff_EBX; // client controller residual
    long double fVar9;

    float fStack_10c;
    int iStack_108;
    float fStack_104;
    float fStack_100;
    float fStack_fc;
    float fStack_f8;
    float fStack_f0;
    float fStack_ec;
    float fStack_e8;
    int iStack_e4;
    float fStack_d8;
    int iStack_d4;
    float fStack_d0;
    float fStack_cc;
    float fStack_c8;
    float fStack_bc;
    float fStack_b8;
    float fStack_b4;
    float fStack_b0;
    float fStack_ac;
    float fStack_a8;
    std::uint32_t uStack_a4;
    TFID_16 aTStack_98[3];
    std::uint8_t auStack_68[84];
    std::uint8_t uStack_14;
    std::uint8_t uStack_13;
    std::uint8_t uStack_12;
    std::uint8_t uStack_11;

    // ----- Stage 0: clear primary select slot; modal / mode early-outs -----
    unaff_EBX[0x349] = 0; // client+0xd24 select slot
    if ((*(char*)(DAT_00d1b6d8 + 0x4f1) != '\0') ||
        (cVar3 = (**(char(**)())(*unaff_EBX + 0x3d8))(), cVar3 == '\0')) {
        return 0;
    }

    iStack_d4 = (int)(short)((unsigned)param_2 >> 0x10); // screen Y
    unaff_EBX[0x156] = 0;
    uStack_12 = 0xff;
    uStack_13 = 0xff;
    uStack_14 = 0xff;
    uStack_11 = 0xff;

    // ----- Stage 1: special mode DAT_00d1a8da → camera pick + select only -----
    if (DAT_00d1a8da != '\0') {
        iStack_d4 = DAT_00d1d870;
        fStack_d8 = DAT_00d1d86c;
        iVar6 = (**(int(**)(float*, int, void*, int))(
            **(int**)(*(int*)(DAT_00d1b644 + 0xe894) + 0xc0) + 0x10))(
            &fStack_d8, 5, auStack_68, 0);
        if (iVar6 == 0) {
            return 0;
        }
        pcVar1 = *(char**)(iVar6 + 0x78);
        if (pcVar1 == nullptr) {
            return 0;
        }
        if (*pcVar1 != '\x01') {
            return 0;
        }
        if (*(int*)(pcVar1 + 4) == 0) {
            return 0;
        }
        FUN_0093e120(*(int*)(pcVar1 + 4)); // select object (no UseObject here)
        return 1;
    }

    // ----- Stage 2: primary pick via FUN_00490070; seed empty TFID -----
    iStack_108 = DAT_00d1d870;
    fStack_10c = DAT_00d1d86c;
    piVar4 = FUN_00490070(&fStack_10c, auStack_68, param_4);
    aTStack_98[0].dwCoidLo = DAT_00a158b8;
    aTStack_98[0].dwCoidHi = DAT_00a158bc;
    aTStack_98[0].bGlobal = (std::uint8_t)DAT_00a158c0;
    aTStack_98[0].bPad0 = (std::uint8_t)(DAT_00a158c0 >> 8);
    aTStack_98[0].bPad1 = (std::uint8_t)(DAT_00a158c0 >> 16);
    aTStack_98[0].bPad2 = (std::uint8_t)(DAT_00a158c0 >> 24);
    aTStack_98[0].bPad3 = (std::uint8_t)DAT_00a158c4;
    aTStack_98[0].bPad4 = (std::uint8_t)(DAT_00a158c4 >> 8);
    aTStack_98[0].bPad5 = (std::uint8_t)(DAT_00a158c4 >> 16);
    aTStack_98[0].bPad6 = (std::uint8_t)(DAT_00a158c4 >> 24);

    // ----- Stage 3: if no hit and not blocked, soft-path ray + gather -----
    if ((piVar4 == nullptr) && (*(char*)(DAT_00d1b644 + 0xf5) == '\0')) {
        bVar2 = false;
        fStack_104 = 0.0f;

        // Soft path only when param_3 == 0 (caller soft-click / DAT_00d1a860 path)
        if (param_3 == '\0') {
            iStack_108 = iStack_d4;
            fStack_10c = (float)(int)(short)param_2; // screen X
            FUN_0075c340(&fStack_10c, &fStack_100, &fStack_bc);
            fStack_b0 = fStack_bc;
            fStack_ac = fStack_b8;
            fStack_f0 = fStack_100;
            fStack_a8 = fStack_b4;
            fStack_ec = fStack_fc;
            uStack_a4 = 0;
            fStack_e8 = fStack_f8;
            iStack_e4 = 0;
            // Ray cast max range 400
            cVar3 = FUN_004cff70(&fStack_f0, &fStack_b0, &fStack_d0, 400);
            if (cVar3 == '\0') {
                return 1; // ray miss → handled no-op
            }
            bVar2 = true;
            // Distance from camera/player origin DAT_00d17944+0x228.. → scale
            fVar9 = (long double)FUN_0040d020(
                fStack_d0 - *(float*)(DAT_00d17944 + 0x228),
                fStack_cc - *(float*)(DAT_00d17944 + 0x22c),
                fStack_c8 - *(float*)(DAT_00d17944 + 0x230));
            fStack_104 = (float)(fVar9 * (long double)_DAT_00aaacbc); // * ~0.015
            // Gather radius = scaled * 10.0f, capped at 25.0f
            fStack_10c = fStack_104 * DAT_00a110d8;
            if (DAT_00aaa6fc <= fStack_10c) {
                fStack_10c = DAT_00aaa6fc;
            }
            iVar6 = DAT_00d1b6d8;
            if (DAT_00d1b6d8 != 0) {
                // Resolve character body from player/vehicle wrapper
                iVar6 = *(int*)(*(int*)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8;
            }
            // maxTargets=1, gatherMode=3 (living interact: Veh/Cre/Char)
            Skill_GatherTargetsInArea(
                aTStack_98, 0, (void*)DAT_00d1b644, iVar6, &fStack_d0, fStack_10c,
                1, 3, 0, 0, 1, 1, 0, 0, (int)0xbf800000);
            if ((aTStack_98[0].dwCoidLo & aTStack_98[0].dwCoidHi) == 0xffffffffu) {
                // Empty gather → alternate mask/scale ( * 5.0f, cap 25.0f )
                fStack_10c = fStack_104 * DAT_00aaa688;
                if (DAT_00aaa6fc <= fStack_10c) {
                    fStack_10c = DAT_00aaa6fc;
                }
                iVar6 = DAT_00d1b6d8;
                if (DAT_00d1b6d8 != 0) {
                    iVar6 = *(int*)(*(int*)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8;
                }
                FUN_0058cd60(aTStack_98, 0, (void*)DAT_00d1b644, iVar6, &fStack_d0,
                             fStack_10c, 1, 5, 0, 0, 1);
                if ((aTStack_98[0].dwCoidLo & aTStack_98[0].dwCoidHi) != 0xffffffffu) {
                    piVar4 = Object_ResolveFromTFID(aTStack_98);
                }
            } else {
                piVar5 = Object_ResolveFromTFID(aTStack_98);
                // Prefer type 0x12 only if vtbl+0x1d8 and FUN_0040b1b0 allow
                if ((piVar5 != nullptr) && (*(int*)(piVar5[0x2a] + 0x38) == 0x12)) {
                    (**(int(**)())(*piVar5 + 0x1d8))();
                    cVar3 = FUN_0040b1b0();
                    if (cVar3 != '\0') {
                        piVar4 = piVar5;
                    }
                }
            }
        }

        // Path B: still no object → gather mode 2 (hostile); radius * 25, cap 40
        if (piVar4 == nullptr) {
            aTStack_98[0].dwCoidLo = DAT_00a158b8;
            aTStack_98[0].dwCoidHi = DAT_00a158bc;
            aTStack_98[0].bGlobal = (std::uint8_t)DAT_00a158c0;
            aTStack_98[0].bPad0 = (std::uint8_t)(DAT_00a158c0 >> 8);
            aTStack_98[0].bPad1 = (std::uint8_t)(DAT_00a158c0 >> 16);
            aTStack_98[0].bPad2 = (std::uint8_t)(DAT_00a158c0 >> 24);
            aTStack_98[0].bPad3 = (std::uint8_t)DAT_00a158c4;
            aTStack_98[0].bPad4 = (std::uint8_t)(DAT_00a158c4 >> 8);
            aTStack_98[0].bPad5 = (std::uint8_t)(DAT_00a158c4 >> 16);
            aTStack_98[0].bPad6 = (std::uint8_t)(DAT_00a158c4 >> 24);
            if (!bVar2) {
                fStack_10c = (float)(int)(short)param_2;
                iStack_108 = iStack_d4;
                FUN_0075c340(&fStack_10c, &fStack_100, &fStack_bc);
                fStack_f0 = fStack_bc;
                fStack_ec = fStack_b8;
                fStack_b0 = fStack_100;
                fStack_e8 = fStack_b4;
                fStack_ac = fStack_fc;
                iStack_e4 = 0;
                fStack_a8 = fStack_f8;
                uStack_a4 = 0;
                cVar3 = FUN_004cff70(&fStack_b0, &fStack_f0, &fStack_d0, 400);
                if (cVar3 == '\0') {
                    goto LAB_00924d29;
                }
                fVar9 = (long double)FUN_0040d020(
                    fStack_d0 - *(float*)(DAT_00d17944 + 0x228),
                    fStack_cc - *(float*)(DAT_00d17944 + 0x22c),
                    fStack_c8 - *(float*)(DAT_00d17944 + 0x230));
                fStack_104 = (float)(fVar9 * (long double)_DAT_00aaacbc);
            }
            fStack_10c = fStack_104 * DAT_00aaa6fc; // * 25.0f
            if (DAT_00a1109c <= fStack_10c) {
                fStack_10c = DAT_00a1109c; // cap 40.0f
            }
            iVar6 = DAT_00d1b6d8;
            if (DAT_00d1b6d8 != 0) {
                iVar6 = *(int*)(*(int*)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8;
            }
            // maxTargets=1, gatherMode=2 (hostile / enemy filter)
            Skill_GatherTargetsInArea(
                aTStack_98, 0, (void*)DAT_00d1b644, iVar6, &fStack_d0, fStack_10c,
                1, 2, 0, 0, 1, 0, 1, 0, (int)0xbf800000);
            if ((aTStack_98[0].dwCoidLo & aTStack_98[0].dwCoidHi) != 0xffffffffu) {
                piVar4 = Object_ResolveFromTFID(aTStack_98);
            }
        }
    }

LAB_00924d29:
    // ----- Stage 4: optional filter — drop pick if self or vehicle body -----
    if ((char)param_4 == '\0') {
        if (DAT_00d1b6d8 == 0) {
            piVar5 = nullptr;
        } else {
            piVar5 = (int*)(*(int*)(*(int*)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8);
        }
        if (piVar4 == piVar5) {
            return 1; // clicked self
        }
        piVar5 = *(int**)(DAT_00d1b6d8 + 0x250);
        if (piVar5 != nullptr) {
            piVar5 = (int*)(*(int*)(piVar5[1] + 4) + 4 + (int)piVar5);
        }
        if (piVar4 == piVar5) {
            return 1; // clicked own vehicle
        }
    }

    // ----- Stage 5: store selection; maybe IfInteractable -----
    unaff_EBX[0x349] = (int)piVar4; // +0xd24
    unaff_EBX[0x1d6] = (int)piVar4; // +0x758
    unaff_EBX[0x15a] = 0;
    if (piVar4 != nullptr) {
        // Asm: ECX = DAT_00d1b6d8 (character); PUSH world object.
        // Decompiler omits thiscall ECX — both matchers are character thiscall.
        // 005245d0 = FindActiveObjectiveIdForPick (+0x44 eval)
        // 00524520 = FindActiveObjectiveIdForInteract (+0x40 eval)
        iVar6 = FUN_005245d0(piVar4);
        if ((iVar6 != 0) || (iVar6 = FUN_00524520(unaff_EBX[0x1d6]), iVar6 != 0)) {
            Client_SendUseObject_IfInteractable();
        }
        FUN_0093e120(unaff_EBX[0x1d6]); // push selection UI / focus
    }

    // ----- Stage 6: alternate mode DAT_00d1bdfa → vtbl+0x380 and exit -----
    if (DAT_00d1bdfa != '\0') {
        DAT_00d1d867 = 1;
        uVar7 = (**(std::uint32_t(**)(std::uint32_t, std::uint32_t))(
            *unaff_EBX + 0x380))(param_1, param_2);
        return uVar7;
    }

    iVar6 = unaff_EBX[0x1d6];
    if (iVar6 == 0) {
        goto switchD_00924f0c_caseD_5;
    }
    iStack_d4 = DAT_00d1d904;
    if (DAT_00d1d900 != -1) {
        FUN_00941ac0(&DAT_00d1a640);
        goto switchD_00924f0c_caseD_3;
    }

    // ----- Stage 7: USEOBJECT GATE — flag +0x11c && dist <= 25.0f -----
    // This is the unconditional C2S 0x2072 producer on the click path.
    // Server must re-validate range (~30f product); client gate is 25.0f only.
    if (*(int*)(iVar6 + 0x11c) != 0) {
        fStack_100 = *(float*)(iVar6 + 0x80); // obj pos X
        fStack_fc = *(float*)(iVar6 + 0x84);  // Y
        fStack_f8 = *(float*)(iVar6 + 0x88);  // Z
        // Player body position via vtbl+0x1a0 on resolved character
        pfVar8 = (float*)(**(float*(**)())(
            *(int*)(*(int*)(*(int*)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) + 0x1a0))();
        fStack_100 = fStack_100 - *pfVar8;
        fStack_fc = fStack_fc - pfVar8[1];
        fStack_f8 = fStack_f8 - pfVar8[2];
        if (std::sqrt(fStack_100 * fStack_100 + fStack_fc * fStack_fc +
                      fStack_f8 * fStack_f8) <= DAT_00aaa6fc) {
            Client_SendUseObject(); // C2S 0x2072 size 0x20; objective −1 or match
        }
    }

    // ----- Stage 8: clone-type secondary actions (not UseObject) -----
    // Type lives at *( *(obj+0xa8) + 0x38 ) — same clone type field as IfInteractable type-4.
    piVar4 = (int*)unaff_EBX[0x1d6];
    switch (*(std::uint32_t*)(piVar4[0x2a] + 0x38)) {
    case 3:
        break;
    case 4:
        // QuestItemPickup C2S 0x205D size 0x10.
        // Decompiler showed fStack_f0 = 1.16098e-41 == bits 0x0000205d.
        *(std::uint32_t*)&fStack_f0 = 0x205d;
        fStack_e8 = (float)piVar4[0x58]; // TFID lo @ obj+0x160
        iStack_e4 = piVar4[0x59];        // TFID mid
        Client_SendSectorPacket(&DAT_00d1a840, 0x10, &fStack_f0);
        break;
    case 0xe:
    case 0x12:
    case 0x14:
        if (((piVar4 != nullptr) &&
             (iVar6 = (**(int(**)())(*piVar4 + 0x1d8))(), iVar6 != 0)) &&
            (cVar3 = FUN_0040b1b0(), cVar3 != '\0')) {
            FUN_0093e120(0); // clear selection
            if (param_3 != '\0') {
                *(std::uint8_t*)((int)unaff_EBX + 0xa32) = 0;
            }
            break;
        }
        // fall through to default
    default:
    switchD_00924f0c_caseD_5:
        if (param_3 != '\0') {
            *(std::uint8_t*)((int)unaff_EBX + 0xa32) = 1;
        }
        break;
    case 0x16:
        fStack_e8 = (float)((*(std::uint32_t*)&fStack_e8 & 0xffffff00u) |
                            (std::uint8_t)(char)piVar4[0x5a]);
        FUN_00938670(piVar4[0x58], piVar4[0x59], fStack_e8, iStack_e4);
        break;
    }

switchD_00924f0c_caseD_3:
    // ----- Stage 9: vehicle flag + optional drive helper; commit flag -----
    if (((DAT_00d1b6d8 != 0) && (*(int*)(DAT_00d1b6d8 + 0x250) != 0)) &&
        (*(std::uint8_t*)(*(int*)(DAT_00d1b6d8 + 0x250) + 0x107) = 1,
         *(char*)(*(int*)(DAT_00d1b6d8 + 0x250) + 0x108) == '\0')) {
        FUN_004f3640(0, 1);
    }
    if (param_3 != '\0') {
        *(std::uint8_t*)((int)unaff_EBX + 0xa32) = 1;
    }
    return 1;
}
