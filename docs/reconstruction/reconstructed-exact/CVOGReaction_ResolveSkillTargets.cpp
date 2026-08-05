// =============================================================================
// CVOGReaction_ResolveSkillTargets
// -----------------------------------------------------------------------------
// Purpose:  Look up skill definition by skillId in map DAT_00b04734. On hit,
//           allocate a 0x630-byte runtime buffer, construct via FUN_0054f3c0,
//           copy 0x18c dwords from node+0x10, apply rank via
//           Skill_SetRankAndReevaluate (stores short at skill+0x5f6), return
//           buffer. Returns null on map MISS (node == DAT_00b04738 end sentinel).
//
// Address:  0x0054c570  (autoassault.exe, image base 0x400000)
// Stable:   aa_0054c570
// System:   skills-abilities
//
// Convention: __cdecl — two stack args; caller cleans 8 (ADD ESP,8).
//   arg0 = skillId (int key)
//   arg1 = rankPacked (word used at SetRank; dword pushed)
//
// Algorithm (asm-sealed 2026-07-29):
//   1. If DAT_00b04724 == 0, init via FUN_0054b2c0
//   2. FUN_00418890 with this=DAT_00b04734, key=skillId
//   3. If *it == DAT_00b04738 → return null (miss — NOT "already cached")
//   4. operator_new(0x630); FUN_0054f3c0(ECX=alloc)
//   5. REP MOVSD 0x18c dwords from node+0x10
//   6. Skill_SetRankAndReevaluate(buf /*ECX*/, rankPacked /*stack*/)  // RET 4
//   7. return buf
//
// Note: Despite the symbol name, this body clones skill *runtime/template*
//       data (0x630) and reevaluates rank — not a TFID target list. Target
//       list resolution is Skill_ResolveTargetList / GatherTargetsInArea.
//       Decompiler unaff_DI "rank" is FALSE (EDI only REP MOVSD dest).
//
// Exactness: Behavior-preserving decompiler CF + asm ABI seal.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime / differential: OPEN.
// =============================================================================

#include <cstdint>

extern "C" void  FUN_0054b2c0();
// Map find: asm loads ECX=DAT_00b04734 (thiscall). Scaffold shows out/key only.
extern "C" void* FUN_00418890(void* outIt, void* skillIdKey);
// Ctor: asm MOV ECX,alloc; CALL. Returns constructed buffer.
extern "C" void* FUN_0054f3c0(void* rawBuf /* ECX */);
// thiscall: ECX=skill; one stack arg = rank word; stores skill+0x5f6; RET 4.
// Scaffold: (buf, rankPacked) — no phantom DI third arg.
extern "C" void  Skill_SetRankAndReevaluate(void* skillBuf /* ECX */, int rankPacked);
extern "C" void* operator_new(std::uint32_t size);
extern "C" char  DAT_00b04724;
// Map object (FUN_00418890 this); end sentinel node pointer:
extern "C" int   DAT_00b04738;
extern "C" void* ExceptionList;

std::uint32_t* __cdecl CVOGReaction_ResolveSkillTargets(int skillId, int rankPacked)
{
    int templateNode;
    int* lookupResult;
    int i;
    std::uint32_t* runtimeBuf = nullptr;
    std::uint32_t* src;
    std::uint32_t* dst;
    std::uint8_t itScratch[4];
    void* keyPtr = &skillId;
    void* savedExceptionList;
    // SEH frame locals omitted beyond ExceptionList swap (decomp)

    savedExceptionList = ExceptionList;
    runtimeBuf = nullptr;
    ExceptionList = &savedExceptionList; // decomp installs frame; simplified

    // Check DAT_00b04724 flag, init if needed
    if (DAT_00b04724 == '\0') {
        ExceptionList = &savedExceptionList;
        FUN_0054b2c0();
    }

    // Lookup skill def (asm: ECX = 0xb04734 map object)
    lookupResult = (int*)FUN_00418890(itScratch, keyPtr);
    templateNode = *lookupResult;

    if (templateNode != DAT_00b04738) {
        // Hit — allocate 0x630 and populate
        void* raw = operator_new(0x630);

        if (raw != nullptr) {
            // FUN_0054f3c0 constructs with ECX = allocation
            runtimeBuf = (std::uint32_t*)FUN_0054f3c0(raw);
        }

        // Copy 0x18c dwords from node+0x10 (REP MOVSD)
        src = (std::uint32_t*)(templateNode + 0x10);
        dst = runtimeBuf;
        for (i = 0x18c; i != 0; i = i + -1) {
            *dst = *src;
            src = src + 1;
            dst = dst + 1;
        }

        // Rank only via stack arg1 — NOT DI (SetRank RET 4)
        Skill_SetRankAndReevaluate(runtimeBuf, rankPacked);

        ExceptionList = savedExceptionList;
        return runtimeBuf;
    }

    // Map miss (end sentinel)
    ExceptionList = savedExceptionList;
    return nullptr;
}
