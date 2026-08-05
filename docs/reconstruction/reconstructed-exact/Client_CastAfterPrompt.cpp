// =============================================================================
// Client_CastAfterPrompt
// -----------------------------------------------------------------------------
// Purpose:  Complete skill target-select: read pending skill id from
//           client+0x30c0, seed TFID from ESI (pick object +0x160), optional
//           Client_RequestCastSkill (C2S 0x2030), then always clear prompt
//           (EAX=-1, show=0).
//
// Address:  0x00941ac0  (autoassault.exe, image base 0x400000)
// Stable:   aa_00941ac0
// System:   skills-abilities
//
// Convention (retail — Confirmed 2026-07-29 dual):
//   EDI = client*          (callers: MOV EDI, &DAT_00d1a840)
//   ESI = TFID*            (callers: LEA ESI, [selectedObj + 0x160])
//   stack arg0 = aim float3*
//   RET 4  (stdcall 1 stack formal)
//   skillId is NOT a formal — loaded from *(client+0x30c0)
//
// Control flow:
//   1) Client_CastBlockFeedback() with EAX=client
//      nonzero → skip send (toast already emitted inside block helper)
//   2) if allow:
//        skillId = *(client+0x30c0)
//        Client_RequestCastSkill(skillId, tfid[0..3], pAim) with EAX=client
//        (callee RET 0x18; packs WI-SKL-001 0x2030)
//   3) always: Client_PromptSkillTargetSelect(client, show=0) with EAX=-1
//
// Callers (xrefs):
//   Client_InteractClickPickTarget  0x00924e29  aim=&DAT_00d1a640
//   FUN_00861680                    0x00861a52  aim=&DAT_00d1a660
//   Both gated by DAT_00d1d900 != -1  (== client+0x30c0 absolute)
//
// Enter path (not this unit):
//   Client_CastSkillFromQuickBarSlot when skill+0x614 has 0x800 and not 0x20
//   → PromptSkillTargetSelect(show=1) stores skillId at +0x30c0
//
// Exactness: Behavior-preserving decompiler CF + asm register seals.
// Bit-for-bit vs retail EXE: DEFERRED. Runtime / differential: OPEN.
// Dual residual: reviews/a_00941ac0.md
// Dual reviews:
//   reviews/A_aa_00941ac0_Client_CastAfterPrompt.md
//   reviews/B_aa_00941ac0_Client_CastAfterPrompt.md
// =============================================================================

#include <cstdint>

extern "C" char Client_CastBlockFeedback(); // FUN_0093b7f0; EAX=client; 0=allow, 1=block
extern "C" void Client_RequestCastSkill(int nSkillId, int t0, int t1, int t2, int t3, void* pAim);
// RequestCast: client in EAX; stdcall cleans 0x18
extern "C" void Client_PromptSkillTargetSelect(void* client, char showPrompt);
// Prompt: modeOrSkillId in EAX; 2 stack args cdecl

/// @param pAim  Aim float3 (retail stack formal). Client=EDI, TFID*=ESI at entry.
void Client_CastAfterPrompt(void* pAim)
{
    // retail: client lives in EDI; TFID pointer in ESI
    void* client;      // EDI
    int* pTfid;        // ESI — 4 dwords
    char blocked;

    // MOV EAX, EDI; CALL CastBlockFeedback
    blocked = Client_CastBlockFeedback();
    if (blocked == 0) {
        int skillId = *(int*)((std::uint8_t*)client + 0x30c0);
        // PUSH pAim; copy *pTfid as 4 dwords; PUSH skillId; MOV EAX,client; CALL
        Client_RequestCastSkill(
            skillId,
            pTfid[0], pTfid[1], pTfid[2], pTfid[3],
            pAim);
    }

    // OR EAX, -1; PUSH 0; PUSH EDI; CALL Prompt; ADD ESP, 8
    // Client_PromptSkillTargetSelect with EAX = -1 clears +0x30c0
    Client_PromptSkillTargetSelect(client, 0);
}
