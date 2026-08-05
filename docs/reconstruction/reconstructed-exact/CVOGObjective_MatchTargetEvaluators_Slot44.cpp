// =============================================================================
// CVOGObjective_MatchTargetEvaluators_Slot44  (FUN_0059da10)
// Address: 0x0059da10  Stable: aa_0059da10
// Walk objective evaluators [+0x158, +0x15c); vtbl+0x44 match (sibling of
// CVOGObjective_MatchTargetEvaluators @ 0x0059d9c0 which uses vtbl+0x40).
// Sole production caller: FUN_005245d0 (pick/hover active-obj id walker).
// =============================================================================

#include <cstdint>

std::uint32_t __thiscall CVOGObjective_MatchTargetEvaluators_Slot44(
    int objective, unsigned argA, unsigned argB)
{
    unsigned* it = *(unsigned**)(objective + 0x158);
    unsigned* end = *(unsigned**)(objective + 0x15c);
    while (it != end) {
        int* eval = (int*)*it;
        char ok = (**(char (**)(unsigned, unsigned))(*eval + 0x44))(argA, argB);
        if (ok != '\0') {
            return 1;
        }
        it = it + 1;
    }
    return 0;
}
