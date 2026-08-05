// =============================================================================
// CVOGObjective_MatchTargetEvaluators  (FUN_0059d9c0)
// Address: 0x0059d9c0  Stable: aa_0059d9c0
// Walk objective def evaluators [+0x158, +0x15c); vtbl+0x40 MatchTarget.
// =============================================================================

#include <cstdint>

std::uint32_t __thiscall CVOGObjective_MatchTargetEvaluators(
    int objective, unsigned argA, unsigned argB)
{
    unsigned* it = *(unsigned**)(objective + 0x158);
    unsigned* end = *(unsigned**)(objective + 0x15c);
    while (it != end) {
        int* eval = (int*)*it;
        char ok = (**(char (**)(unsigned, unsigned))(*eval + 0x40))(argA, argB);
        if (ok != '\0') {
            return 1;
        }
        it = it + 1;
    }
    return 0;
}
