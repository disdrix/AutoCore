// =============================================================================
// CNDDoubleList_InvokePredicateAndRemove_Inferred  (was FUN_004e2600)
// Address:  0x004e2600  Stable: aa_004e2600
// System:   skills-abilities (generic list utility)
//
// RTTI family: .?AV?$CNDDoubleList@PAVCVOGHBBase@@$00@@ (class; method Inferred)
// ValidateTarget consumer: Skill_ValidateTargetForSkill walks target+0xB0
// Dual: reviews/A|B_aa_004e2600_CNDDoubleList_InvokePredicateAndRemove_Inferred.md
// =============================================================================

#include <cstdint>
#include <windows.h>

// Predicate: non-zero = match (remove this node). May set *stopFlag to end walk.
using ListPredicate = char (*)(void* payload, void* ctx, char* stopFlag);

void __thiscall CNDDoubleList_InvokePredicateAndRemove_Inferred(
    int thisList,
    ListPredicate predicate,
    void* ctx,
    char nullPayloadBeforeDestroy)
{
    LPCRITICAL_SECTION cs = reinterpret_cast<LPCRITICAL_SECTION>(thisList + 4);
    EnterCriticalSection(cs);

    if (*reinterpret_cast<char*>(thisList + 0x28) != '\0') {
        LeaveCriticalSection(cs);
        return;
    }

    char stopFlag = '\0';
    std::uint32_t* node = *reinterpret_cast<std::uint32_t**>(thisList + 0x1c);

    while (true) {
        while (true) {
            if (node == nullptr) {
                LeaveCriticalSection(cs);
                return;
            }
            // node[1] = payload; node[2] = next; node[3] = prev
            char match = predicate(
                reinterpret_cast<void*>(node[1]), ctx, &stopFlag);
            std::uint32_t* next = reinterpret_cast<std::uint32_t*>(node[2]);
            if (match == '\0') {
                node = next;
                continue;
            }

            // Unlink matched node
            if (next == nullptr) {
                *reinterpret_cast<std::uint32_t*>(thisList + 0x20) = node[3];
            } else {
                next[3] = node[3];
            }
            if (node[3] == 0) {
                *reinterpret_cast<std::uint32_t*>(thisList + 0x1c) =
                    reinterpret_cast<std::uint32_t>(next);
            } else {
                *reinterpret_cast<std::uint32_t*>(node[3] + 8) =
                    reinterpret_cast<std::uint32_t>(next);
            }
            (*reinterpret_cast<int*>(thisList + 0x24))--;

            if (nullPayloadBeforeDestroy == '\0') {
                node[1] = 0;
            }
            // node vtbl[0](1) — destroy/free
            (**(void(**)(int))node)(1);

            node = next;
            break; // re-check stopFlag
        }

        if (stopFlag != '\0') {
            LeaveCriticalSection(cs);
            return;
        }
    }
}
