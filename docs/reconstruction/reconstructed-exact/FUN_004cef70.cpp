// =============================================================================
// FUN_004cef70 / Combat_ComputeCritChance_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004cef70
// Address:   0x004cef70 – 0x004cf07c  (autoassault.exe, image base 0x400000)
// System:    combat-crit
// Dual seal: W22-A 2026-07-29 (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Prefer:    Combat_ComputeCritChance_Inferred.cpp
// =============================================================================

extern float g_flMsToSeconds_Inferred;   // 0.001f @ 0x00a0f72c
extern float DAT_00a0f704;               // 0.25f  @ 0x00a0f704
extern float g_flKillSpreeBonusPerStack; // 0.05f  @ 0x009cbf80

extern float __fastcall FUN_004c4dd0(void *bind);
extern float __thiscall FUN_004c3140(void *bind, char useHi);
extern float __thiscall FUN_004c3120(void *bind, char useHi);

// cdecl; float return in ST0
float FUN_004cef70(int *param_1, int *param_2)
{
    int *attacker = param_1;
    int level;
    int probe;
    unsigned int resistFlag;
    float chance;
    void *bind;

    level = (**(int (**)())(*attacker + 0x27c))();

    resistFlag = 0;
    if (param_2 != 0) {
        probe = (**(int (**)())(*param_2 + 0x1d4))();
        if (probe != 0) {
            resistFlag = 1;
        }
    }

    // attacker +0x1d4 — call preserved; return unused
    (**(int (**)())(*attacker + 0x1d4))();

    bind = (void *)(**(int (**)())(*attacker + 0x214))();
    if (bind == 0) {
        // level * 0.001 * 0.25 + 0.05
        chance = (float)level * g_flMsToSeconds_Inferred * DAT_00a0f704
                 + g_flKillSpreeBonusPerStack;
    } else {
        bind = (void *)(**(int (**)())(*attacker + 0x214))();
        chance = FUN_004c4dd0(bind);
    }

    if ((**(int (**)())(*attacker + 0x214))() != 0) {
        bind = (void *)(**(int (**)())(*attacker + 0x214))(1);
        chance = chance + FUN_004c3140(bind, 1);
    }

    if (param_2 != 0) {
        if ((**(int (**)())(*param_2 + 0x214))() != 0) {
            bind = (void *)(**(int (**)())(*param_2 + 0x214))(resistFlag);
            chance = chance - FUN_004c3120(bind, (char)resistFlag);
        }
    }

    if (chance < 0.0f) {
        chance = g_flKillSpreeBonusPerStack;
    }

    return chance;
}
