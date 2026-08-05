# Function record: CVOGHBBase_SetPeriodAndCounter

| Field | Value |
|---|---|
| **Stable ID** | `aa_005081a0` |
| **Canonical name** | `CVOGHBBase_SetPeriodAndCounter` |
| **Address** | `0x005081a0` |
| **Body range** | `0x005081a0`–`0x005081b3` (19 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `heartbeat` / timed-actions |
| **Completion status** | **Sealed** (body High; dual A/B accept 2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Write **`HB+0x0C`** (period/sentinel) from arg1, and optionally mirror the same int to **`HB+0x10`** (counter) when arg2 bool is non-zero. Seeds TryFire/Reschedule fields. Does **not** set pulse period at `+0x08`.

## Signature (machine + decompiler)

```c
void __thiscall CVOGHBBase_SetPeriodAndCounter(
    void *this /* ECX */,
    int nPeriodSentinel /* [esp+4] */,
    bool bAlsoSetCounter /* byte [esp+8] */);
```

- Convention: MSVC `__thiscall` — **ECX = this**, two stack formals, callee cleanup **`ret 8`**, void.
- Callees: **none**.

## Body (authoritative)

```
80 7C 24 08 00    cmp  byte ptr [esp+0x8], 0
8B 44 24 04       mov  eax, [esp+0x4]
89 41 0C          mov  [ecx+0x0C], eax
74 03             jz   skip
89 41 10          mov  [ecx+0x10], eax
C2 08 00          ret  8
```

Hex: `807c2408008b44240489410c7403894110c20800`

Decompile:

```c
void __thiscall CVOGHBBase_SetPeriodAndCounter(void *this, int nPeriodSentinel, bool bAlsoSetCounter)
{
  *(int *)((int)this + 0xc) = nPeriodSentinel;
  if (bAlsoSetCounter) {
    *(int *)((int)this + 0x10) = nPeriodSentinel;
  }
  return;
}
```

## Layout (this unit)

| Offset | Field (working names) | Role |
|---|---|---|
| `+0x0C` | `nPeriodSentinel` / TryFire `nPeriodMs` alias | **Always written**; `-1000` = always-ready sentinel |
| `+0x10` | `nPeriodCounter` | **Optionally** set equal to arg1 when flag true |

Not written here (siblings):

| Offset | Field | Owner examples |
|---|---|---|
| `+0x08` | pulse period ms | Regeneration_ctor after this call; GetRemaining reads for UI |
| `+0x14` | `dwLastFireTickMs` | StampLastFireTime / TryFire success path |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005081a0_CVOGHBBase_SetPeriodAndCounter.md`
- Annotated: `docs/reconstruction/raw/aa_005081a0_CVOGHBBase_SetPeriodAndCounter.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBBase_SetPeriodAndCounter.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_005081a0_CVOGHBBase_SetPeriodAndCounter.md`
- Dual B: `docs/reconstruction/reviews/B_aa_005081a0_CVOGHBBase_SetPeriodAndCounter.md`

## Callers / xrefs (Ghidra 2026-07-29)

24 UNCONDITIONAL_CALL sites:

| Address | Owner |
|---|---|
| `0x00507674` | `FUN_005075f0` |
| `0x0051e27a` | `CVOGHBOKToCastAgain_ctor` |
| `0x00558c4d` | `FUN_00558b20` |
| `0x00578a40` | `CVOGHBSkillBase_ctor` |
| `0x005a4f99` | `Vehicle_CreateWeaponTrackAction` |
| `0x005b3224` | `FUN_005b3210` |
| `0x005d1a2e` | `FUN_005d1990` |
| `0x005d6bc0` | `FUN_005d6b80` |
| `0x005d8374` | `FUN_005d8360` |
| `0x005dabd7` | `FUN_005dabc0` |
| `0x005fbe37` | `CVOGHBRegeneration_ctor` |
| `0x005ffbe4` | `TimedAction_CreateTokenFlagAction` |
| `0x005fc204` | `FUN_005fc1f0` |
| `0x00618232` | `FUN_00618180` |
| `0x0061c650` | `FUN_0061c590` |
| `0x0061f98e` | `FUN_0061f940` |
| `0x0061fb2c` | `FUN_0061fa40` |
| `0x00626519` | `FUN_006264e0` |
| `0x00626557` | `FUN_00626530` |
| `0x00632864` | `FUN_00632850` |
| `0x00636be7` | `FUN_00636bd0` |
| `0x00650527` | `FUN_00650510` |
| `0x0065088c` | `FUN_006507c0` |
| `0x00650d9a` | `FUN_00650d30` |

### Arg patterns (from clean/caller decompiles)

| Pattern | Examples |
|---|---|
| `(-1000, true)` | Regeneration, WeaponTrack, `FUN_00558b20`, `FUN_005d6b80`, mission patrol-ish ctors |
| `(1, true)` | OKToCastAgain, TokenFlag, many short HB ctors |
| `(computedPeriod, true)` | SkillBase, SkillCast, `FUN_0061f940` / `FUN_0061fa40` / `FUN_006264e0` |

## Confidence

| Claim | Level |
|---|---|
| Control flow / body bytes | **High** (sealed) |
| `+0x0C` / optional `+0x10` only | **High** |
| `ret 8` / thiscall stack args | **High** |
| Named code callers list | **High** |
| Family field naming (`nPeriodMs` dual use) | **Open residual** |
| `bAlsoSetCounter=false` live use | **Open** |
| Runtime / bit-exact | **Deferred** |
