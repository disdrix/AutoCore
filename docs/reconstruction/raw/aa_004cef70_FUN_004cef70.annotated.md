# Annotated low-level: Combat_ComputeCritChance_Inferred (`FUN_004cef70`)

| Field | Value |
|---|---|
| Stable ID | `aa_004cef70` |
| VA | `0x004cef70`–`0x004cf07c` |
| System | combat-crit |
| Date | 2026-07-29 (W22-A dual seal) |
| Ghidra name | `FUN_004cef70` |
| Canonical (structural) | `Combat_ComputeCritChance_Inferred` |

## Purpose

Compute a **crit chance fraction** (0..1-ish float, ST0) for an attacker/target pair. Sole high-value combat consumer is `Combat_RollCritMultiplier_Inferred` (`FUN_004cf080`), which gates `roll % 100` against `chance * 100`. Second xref is UI path `FUN_00838e20`.

## Signature (sealed)

```c
// cdecl; float return in ST0
float Combat_ComputeCritChance_Inferred(void *attacker /*stack+4*/, void *target /*stack+8, nullable*/);
```

| Formal | Source | Conf |
|---|---|---|
| attacker | Stack[0x4] → ESI; required | **High** |
| target | Stack[0x8] → EDI; null-safe | **High** |
| Return | ST0 float chance | **High** |
| ABI | cdecl (`RET`, cleanup `add esp,8` local frame only) | **High** |

## Annotated control flow

```c
float Combat_ComputeCritChance_Inferred(void *attacker, void *target)
{
    // vtbl+0x27c — same "level" int used by crit mult (004cf080)
    int level = ((int (__thiscall *)(void *))(*(int **)attacker)[0x27c / 4])(attacker);

    // target "is creature/vehicle?" style flag for resist slot select
    char useAltResist = 0;
    if (target != NULL) {
        int tFlag = ((int (__thiscall *)(void *))(*(int **)target)[0x1d4 / 4])(target);
        if (tFlag != 0)
            useAltResist = 1;
    }

    // attacker +0x1d4 — called; return unused in decompile (side-effect / legacy)
    ((void (__thiscall *)(void *))(*(int **)attacker)[0x1d4 / 4])(attacker);

    void *bindA = ((void *(__thiscall *)(void *))(*(int **)attacker)[0x214 / 4])(attacker);
    float chance;
    if (bindA == NULL) {
        // level * 0.001 * 0.25 + 0.05
        chance = (float)level * g_flMsToSeconds_Inferred /*0.001*/
                             * DAT_00a0f704              /*0.25*/
                             + g_flKillSpreeBonusPerStack /*0.05*/;
    } else {
        // skill binding present → table-derived base chance
        void *bindAgain = ((void *(__thiscall *)(void *))(*(int **)attacker)[0x214 / 4])(attacker);
        chance = (float)FUN_004c4dd0(bindAgain); // __fastcall ECX=bind
    }

    // attacker crit bonus from binding (+0x1d8 / +0x1dc)
    if (((void *(__thiscall *)(void *))(*(int **)attacker)[0x214 / 4])(attacker) != NULL) {
        void *b = ((void *(__thiscall *)(void *, int))(*(int **)attacker)[0x214 / 4])(attacker, 1);
        chance += (float)FUN_004c3140(b, 1); // reads +0x1dc when flag!=0
    }

    // target crit resist from binding (+0x1e0 / +0x1e4)
    if (target != NULL) {
        void *bindT = ((void *(__thiscall *)(void *))(*(int **)target)[0x214 / 4])(target);
        if (bindT != NULL) {
            void *b = ((void *(__thiscall *)(void *, int))(*(int **)target)[0x214 / 4])(target, useAltResist);
            chance -= (float)FUN_004c3120(b, useAltResist); // +0x1e4 if flag else +0x1e0
        }
    }

    if (chance < 0.0f)
        chance = g_flKillSpreeBonusPerStack; // floor 0.05
    return chance;
}
```

## Offsets / globals

| Item | Meaning | Conf |
|---|---|---|
| `vtbl+0x27c` | attacker level int (FILD path in sibling mult) | **High** (cross-sealed w/ 004cf080) |
| `vtbl+0x214` | skill/status binding object getter | **High** |
| `vtbl+0x1d4` | entity class/state probe (target → resist slot; attacker result unused) | **Medium** |
| `FUN_004c3140` | attacker bonus float at bind+0x1d8/0x1dc | **High** (live decomp) |
| `FUN_004c3120` | target resist float at bind+0x1e0/0x1e4 | **High** |
| `FUN_004c4dd0` | skill-table base chance when bind non-null | **High** (call site) |
| fallback `level*0.00025+0.05` | sealed mulss/addss | **High** |
| floor `0.05` | same global as min clamp elsewhere | **High** |
| Product English "crit chance" | inferred from sole combat consumer | **Probable** |

## Callers

| Site | Function | Role |
|---|---|---|
| `0x004cf0bf` | `Combat_RollCritMultiplier_Inferred` | `chance * 100` vs `roll%100` |
| `0x00839a01` | `FUN_00838e20` | large UI refresh (display path) |

## Open / residual

1. Exact product name of `vtbl+0x214` / `+0x1d4` methods (no RTTI/string in this unit).
2. Full dual of `FUN_004c4dd0` skill-table formula (out of ownership).
3. Whether floor-to-0.05 is intentional crit floor vs reused XP constant (value sealed either way).
4. UI consumer semantics beyond "also calls this helper".
