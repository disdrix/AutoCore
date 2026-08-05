// =============================================================================
// Skill_FormatFailureMessage
// -----------------------------------------------------------------------------
// Purpose:  Map eSkillResponses → user-facing toast/chat C string in pOutBuf.
//           Pure formatter (no cast state mutation).
//
// Address:  0x0054fa20  (autoassault.exe, image base 0x400000)
// Span:     0x0054fa20 – 0x0054fdf9
// Stable:   aa_0054fa20
// System:   skills-abilities
//
// Convention: MSVC __cdecl
// Signature:
//   char* Skill_FormatFailureMessage(int eSkillResponse, char* pOutBuf, void* pCharacterCtx);
// Returns: pOutBuf on success path; "" if pOutBuf is null.
//
// Callers (Ghidra 2026-07-29):
//   Client_RecvSkillStatusEffect      0x00811170
//   Client_RequestCastSkill           0x00941590
//   Client_Skill_ResolveCastTarget    0x0093b3a0
//   Client_StanceOrGadgetActivatePath 0x0093a3d0
//   FUN_0091f6b0                      0x0091f6b0
//
// Sealed eSkillResponses → English key (switch cases; VERIFIED decompile):
//   1  Server checks failed!
//   2  Skill failed.
//   3  Cannot do that while wrecked!
//   4  You don't have enough power!
//   5  You can't do that with your current status.
//   6  You're already actively using a skill!
//   7  This skill is not ready to use again yet!
//   8  You have too many of that summon.
//   9  You can't do that while in the air.
//  10  You have an active skill that prevents you from doing that.
//  11  You must be hidden to use this.
//  12  You can't do this while hidden.
//  13  Target out of range.
//  14  Wrong target type.
//  15  (default) Unhandled reason for skill failure.  // LocalRange accuracy miss
//  16  summon-cap sprintf path (needs pCharacterCtx)
//  17  (default) Unhandled...  // cancel on wire; format rare
//  18  Target has just been stunted
//   0  (default) if ever formatted — callers should not format success
//
// Locale helpers (shared, not renamed here):
//   FUN_007a69d0 — ensure locale string-table singleton
//   FUN_007a6de0 — lookup English key → localized C string (-1 = default lane)
//
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime / differential: OPEN.
// Generated: 2026-07-29 refine
// =============================================================================

#include <cstdint>
#include <cstdio>

// Shared locale helpers (leave FUN_* until product names sealed elsewhere).
extern "C" void* FUN_007a69d0();
extern "C" char* FUN_007a6de0(const char* englishKey, int lane /* -1 */);

// Summon-cap helpers used only by case 0x10 (product names open).
extern "C" unsigned FUN_004c3f10(void* opaque);
extern "C" unsigned FUN_004c2e60();
extern "C" int FUN_004c2eb0(void* opaque);

static char* CopyLocaleToOut(char* pOutBuf, const char* englishKey)
{
    char* src = FUN_007a6de0(englishKey, -1);
    char* dst = pOutBuf;
    char c;
    do {
        c = *src;
        *dst = c;
        src++;
        dst++;
    } while (c != '\0');
    return pOutBuf;
}

extern "C" char* __cdecl Skill_FormatFailureMessage(
    int eSkillResponse,
    char* pOutBuf,
    void* pCharacterCtx)
{
    if (pOutBuf == nullptr) {
        return const_cast<char*>("");
    }

    FUN_007a69d0(); // locale singleton ensure

    switch (eSkillResponse) {
    case 1:
        return CopyLocaleToOut(pOutBuf, "Server checks failed!");
    case 2:
        return CopyLocaleToOut(pOutBuf, "Skill failed.");
    case 3:
        return CopyLocaleToOut(pOutBuf, "Cannot do that while wrecked!");
    case 4:
        return CopyLocaleToOut(pOutBuf, "You don't have enough power!");
    case 5:
        return CopyLocaleToOut(pOutBuf, "You can't do that with your current status.");
    case 6:
        return CopyLocaleToOut(pOutBuf, "You're already actively using a skill!");
    case 7:
        return CopyLocaleToOut(pOutBuf, "This skill is not ready to use again yet!");
    case 8:
        return CopyLocaleToOut(pOutBuf, "You have too many of that summon.");
    case 9:
        return CopyLocaleToOut(pOutBuf, "You can't do that while in the air.");
    case 10:
        return CopyLocaleToOut(
            pOutBuf,
            "You have an active skill that prevents you from doing that.");
    case 11: // 0x0B
        return CopyLocaleToOut(pOutBuf, "You must be hidden to use this.");
    case 12: // 0x0C
        return CopyLocaleToOut(pOutBuf, "You can't do this while hidden.");
    case 13: // 0x0D
        return CopyLocaleToOut(pOutBuf, "Target out of range.");
    case 14: // 0x0E
        return CopyLocaleToOut(pOutBuf, "Wrong target type.");
    case 16: // 0x10 — summon cap (goto label in raw)
        goto summon_cap_path;
    case 18: // 0x12
        return CopyLocaleToOut(pOutBuf, "Target has just been stunted");
    default:
        // 0, 15 (0x0F), 17 (0x11), and any other residual code
        return CopyLocaleToOut(pOutBuf, "Unhandled reason for skill failure.");
    }

summon_cap_path:
    // Raw label: switchD_0054fa4a_caseD_10
    // Decompiler register tracking on vtbl+0x210 / FUN_004c* is imperfect;
    // preserve call *order* and sprintf templates. Helper product names open.
    if (pCharacterCtx != nullptr) {
        void** vtbl = *reinterpret_cast<void***>(pCharacterCtx);
        using V210_1 = int(__thiscall*)(void* self, int a);
        using V210_2 = int(__thiscall*)(void* self, int a, int b);
        // Raw: (**(code **)(*pCharacterCtx + 0x210))(0) — this in ECX
        int plantish = reinterpret_cast<V210_1>(vtbl[0x210 / sizeof(void*)])(pCharacterCtx, 0);
        if (plantish != 0) {
            void* uVar10 = nullptr;
            reinterpret_cast<V210_2>(vtbl[0x210 / sizeof(void*)])(pCharacterCtx, 0, 0);
            unsigned uVar3 = FUN_004c3f10(uVar10);
            reinterpret_cast<V210_1>(vtbl[0x210 / sizeof(void*)])(pCharacterCtx, 0);
            unsigned uVar4 = FUN_004c2e60();
            if (uVar4 <= uVar3) {
                reinterpret_cast<V210_1>(vtbl[0x210 / sizeof(void*)])(pCharacterCtx, 0);
                unsigned maxCount = FUN_004c2e60();
                reinterpret_cast<V210_1>(vtbl[0x210 / sizeof(void*)])(pCharacterCtx, 0);
                int nextTier = static_cast<int>(FUN_004c2e60());
                void* uVar9 = nullptr;
                reinterpret_cast<V210_2>(vtbl[0x210 / sizeof(void*)])(
                    pCharacterCtx, 0, nextTier + 1);
                int requiredLevel = FUN_004c2eb0(uVar9);
                if (requiredLevel > 0x50) {
                    const char* sMax = FUN_007a6de0("summons at a time", -1);
                    const char* sHave = FUN_007a6de0("You can only have", -1);
                    std::sprintf(pOutBuf, "%s %d %s.", sHave, maxCount, sMax);
                    return pOutBuf;
                }
                const char* sUntil = FUN_007a6de0("until Level", -1);
                const char* sMax = FUN_007a6de0("summons at a time", -1);
                const char* sHave = FUN_007a6de0("You can only have", -1);
                std::sprintf(
                    pOutBuf, "%s %d %s %s %d.", sHave, maxCount, sMax, sUntil, requiredLevel);
                return pOutBuf;
            }
        }
    }
    // Fallback: same message as case 8
    return CopyLocaleToOut(pOutBuf, "You have too many of that summon.");
}
