// =============================================================================
// Combat_ComputeCritChance_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004cef70
// Address:   0x004cef70 – 0x004cf07c  (autoassault.exe, image base 0x400000)
// System:    combat-crit
// Ghidra:    FUN_004cef70
// Dual seal: W22-A 2026-07-29 (decompile_function + read_memory)
// Exactness: Behavior-preserving; not modernization.
// =============================================================================

// PURPOSE: Crit chance fraction for attacker/target. Consumer 004cf080 multiplies
// by 100 and compares to roll%100. Fallback when no skill bind:
//   chance = level * 0.001 * 0.25 + 0.05
// Floor negative results to 0.05 (g_flKillSpreeBonusPerStack reuse).

extern float g_flMsToSeconds_Inferred;     // 0x00a0f72c = 0.001f
extern float DAT_00a0f704;                 // 0x00a0f704 = 0.25f
extern float g_flKillSpreeBonusPerStack;   // 0x009cbf80 = 0.05f

// Skill-table base chance when attacker bind (vtbl+0x214) non-null.
extern float __fastcall FUN_004c4dd0(void *bind);

// Bind field readers (char selects hi/lo slot).
extern float __thiscall FUN_004c3140(void *bind, char useHi); // +0x1dc / +0x1d8
extern float __thiscall FUN_004c3120(void *bind, char useHi); // +0x1e4 / +0x1e0

// cdecl; ST0 return
float Combat_ComputeCritChance_Inferred(void *attacker, void *target)
{
    int *vtA = *(int **)attacker;
    int level = ((int (__thiscall *)(void *))vtA[0x27c / 4])(attacker);

    unsigned char useAltResist = 0;
    if (target != 0) {
        int *vtT = *(int **)target;
        int tProbe = ((int (__thiscall *)(void *))vtT[0x1d4 / 4])(target);
        if (tProbe != 0)
            useAltResist = 1;
    }

    // Result unused in decompile; preserve call.
    ((void (__thiscall *)(void *))vtA[0x1d4 / 4])(attacker);

    float chance;
    void *bindA = ((void *(__thiscall *)(void *))vtA[0x214 / 4])(attacker);
    if (bindA == 0) {
        chance = (float)level * g_flMsToSeconds_Inferred * DAT_00a0f704
                 + g_flKillSpreeBonusPerStack;
    } else {
        void *bind2 = ((void *(__thiscall *)(void *))vtA[0x214 / 4])(attacker);
        chance = FUN_004c4dd0(bind2);
    }

    if (((void *(__thiscall *)(void *))vtA[0x214 / 4])(attacker) != 0) {
        void *b = ((void *(__thiscall *)(void *, int))vtA[0x214 / 4])(attacker, 1);
        chance = chance + FUN_004c3140(b, 1);
    }

    if (target != 0) {
        int *vtT = *(int **)target;
        if (((void *(__thiscall *)(void *))vtT[0x214 / 4])(target) != 0) {
            void *b = ((void *(__thiscall *)(void *, unsigned char))vtT[0x214 / 4])(
                target, useAltResist);
            chance = chance - FUN_004c3120(b, (char)useAltResist);
        }
    }

    if (chance < 0.0f)
        chance = g_flKillSpreeBonusPerStack;

    return chance;
}

// Ghidra twin symbol
float FUN_004cef70(void *param_1, void *param_2)
{
    return Combat_ComputeCritChance_Inferred(param_1, param_2);
}
