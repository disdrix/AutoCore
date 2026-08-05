// READABILITY (auto CF):
//  - Body size: ~81 non-empty decompiler lines.
//  - Control keywords: if×8, return×4, goto×1.
//  - Notable callees: Client_CastSkillFromQuickBarSlot, Client_RequestCastSkill, FUN_00404c90, FUN_0093b7f0, FUN_0093bac0.
//  - Return sites: 4.

// =============================================================================
// Client_CastSkillFromQuickBarSlot
// -----------------------------------------------------------------------------
// Purpose:  Resolve aim / selected-target context for a skill id, then forward
//           to Client_RequestCastSkill. Early-outs on stance/gadget block and
//           missing skill. Special path when skill flags request cursor aim
//           (bit 0x800) vs default entity TFID aim.
//
// Address:  0x009418e0  (autoassault.exe, image base 0x400000)
// Stable:   aa_009418e0
// System:   skills-abilities
//
// Convention: retail client in ESI at entry (NOT EAX — contrast RequestCast).
//             Asm residual 2026-07-29: prologue never loads ESI; callers set it
//             (ActivateSlot live ESI, or MOV ESI,&DAT_00d1a840). skillId stack;
//             RET 4. Clean form takes client as explicit first arg.
//             Arg is skill id (not slot index) - slot→skill is ActivateSlot type-1.
//
// Control flow summary:
//   1) Seed TFID locals from invalid sentinel; zero aim float locals
//   2) FUN_0093b7f0() with EAX=client — multi-state cast block + feedback; nz → return
//   3) entity vtbl+0x234(skillId) → pSkill; null → return
//   4) if (skill+0x614 & 0x800) == 0:  // TEST AH,8 clear → entity TFID aim
//        if no selection (+0xa4 == 0): related/self TFID + aim from vtbl+0x1a0
//        else: selection TFID; if flags bit5 clear → goto cast (aim may stay 0)
//              else vtbl+0x1c8 + FUN_00404c90 → aim
//   5) else if (skill+0x614 & 0x20) == 0:  // target-select mode
//        Client_PromptSkillTargetSelect(client, 1); EAX=skillId → client+0x30c0; return
//   6) Client_RequestCastSkill(client, skillId, tfid0..3, &aim)
//
// Key offsets:
//   client+0xe98     local character / entity root
//   client+0x30c0    pending skill id while target-select active (prompt path)
//   entity+0xa4      selected object (null → self/related)
//   skill+0x614      flag dword (mask 0x800 / 0x20; English names OPEN)
//   object+0x160..   TFID dwords on selected / related entity
//
// Callees:
//   Client_RequestCastSkill          0x00941590  aa_00941590
//   FUN_0093b7f0                     cast-block probe (strings; product name OPEN)
//   Client_PromptSkillTargetSelect   0x0093bac0  aa_0093bac0 (FUN_0093bac0)
//   FUN_00404c90                     position from selected
// Callers: QuickBar_ActivateSlot type-1; FUN_00922270; FUN_008c4fc0; FUN_0082f510 (0xED5)
// Related: Client_QuickBarActivateSkillSlot @ 0x00921b50 (parallel on-foot 0x2030 path)
//
// Exactness: Behavior-preserving decompiler CF. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED. Runtime / differential: OPEN.
// Dual residual 2026-07-29: reviews/a_009418e0.md + A_/B_ refresh.
// Dual reviews:
//   reviews/A_aa_009418e0_Client_CastSkillFromQuickBarSlot.md
//   reviews/B_aa_009418e0_Client_CastSkillFromQuickBarSlot.md
// =============================================================================

#include <cstdint>

extern "C" char  FUN_0093b7f0();                 // cast-block + feedback (EAX=client)
extern "C" void  FUN_0093bac0(void* client, int); // Client_PromptSkillTargetSelect
extern "C" void* FUN_00404c90();                  // position from selected
extern "C" void  Client_RequestCastSkill(void*, int, int, int, int, int, void*);
extern "C" std::uint8_t g_abTfidInvalid_A15870[];

// Entity from client+0xe98
static void* ClientEntity(void* client)
{
    int root = *(int*)((int)client + 0xe98);
    return (void*)(*(int*)(*(int*)(root + 4) + 4) + 4 + root);
}

/// @param client  Client object (retail: ESI at entry — Confirmed 2026-07-29).
/// @param skillId Skill id (not slot index).
void Client_CastSkillFromQuickBarSlot(void* client, int skillId)
{
    int* selectedObj;
    char blocked;
    int pSkill;
    std::uint32_t* aimPtr;
    int tfid0;
    int tfid1;
    int tfid2;
    int tfid3;
    std::uint32_t aim0;
    std::uint32_t aim1;
    std::uint32_t aim2;
    std::uint32_t aim3;
    std::uint8_t tfidScratch[16];

    // Seed TFID locals from invalid sentinel
    tfid1 = ((int*)g_abTfidInvalid_A15870)[1];
    tfid0 = ((int*)g_abTfidInvalid_A15870)[0];
    tfid3 = ((int*)g_abTfidInvalid_A15870)[2];
    *(int*)tfidScratch = ((int*)g_abTfidInvalid_A15870)[3];
    tfid2 = 0;

    aim0 = 0;
    aim1 = 0;
    aim2 = 0;
    aim3 = 0;

    blocked = FUN_0093b7f0();
    if (blocked != '\0') {
        return;
    }

    pSkill = (**(int(***)(int))(*(int*)ClientEntity(client) + 0x234))(skillId);
    if (pSkill == 0) {
        return;
    }

    // skill+0x614 bit 0x800 clear → resolve aim from selection / self
    if ((*(std::uint32_t*)(pSkill + 0x614) & 0x800) == 0) {
        int root = *(int*)((int)client + 0xe98);
        int link = *(int*)(*(int*)(root + 4) + 4);

        if (*(int*)(*(int*)(*(int*)(root + 4) + 4) + 0xa4 + root) == 0) {
            // No selected object - related or self TFID
            int related = (**(int(***)())(*(int*)(link + 4 + root) + 0x19c))();
            if ((related == 0)
                || (related = *(int*)(*(int*)(related + 4) + 4) + 4 + related,
                    related == 0))
            {
                if (*(int*)((int)client + 0xe98) == 0) {
                    related = 0;
                } else {
                    related = (int)ClientEntity(client);
                }
            }

            tfid0 = *(int*)(related + 0x160);
            tfid1 = *(int*)(related + 0x164);
            tfid2 = *(int*)(related + 0x168);
            tfid3 = *(int*)(related + 0x16c);

            aimPtr = (std::uint32_t*)(**(int(***)())(
                *(int*)ClientEntity(client) + 0x1a0))();
        } else {
            int sel = *(int*)(link + 0xa4 + root);
            tfid0 = *(int*)(sel + 0x160);
            tfid1 = *(int*)(sel + 0x164);
            tfid2 = *(int*)(sel + 0x168);
            tfid3 = *(int*)(sel + 0x16c);

            selectedObj = *(int**)(*(int*)(*(int*)(*(int*)((int)client + 0xe98) + 4) + 4)
                                   + 0xa4 + *(int*)((int)client + 0xe98));

            // selected flags bit5 clear → skip aim fill
            if (((std::uint32_t)selectedObj[0x5f] >> 5 & 1) == 0) {
                goto do_cast;
            }

            (**(void(***)())(*selectedObj + 0x1c8))();
            aimPtr = (std::uint32_t*)FUN_00404c90();
        }

        aim0 = aimPtr[0];
        aim1 = aimPtr[1];
        aim2 = aimPtr[2];
        aim3 = aimPtr[3];
        (void)aim3;
    } else if ((*(std::uint32_t*)(pSkill + 0x614) & 0x20) == 0) {
        // Flag 0x800 set, 0x20 clear → cursor aim mode; do not cast yet
        FUN_0093bac0(client, 1);
        return;
    }

do_cast:
    Client_RequestCastSkill(client, skillId, tfid0, tfid1, tfid2, tfid3, &aim0);
}
