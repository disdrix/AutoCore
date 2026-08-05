# Annotated low-level: Skill_FormatFailureMessage

| Field | Value |
|---|---|
| Stable ID | `aa_0054fa20` |
| VA | `0x0054fa20` |
| Span | `0054fa20`–`0054fdf9` |
| System | skills-abilities |
| Date | 2026-07-29 (dual residual; prior refine same day; scaffold 2026-07-23) |

---

## Machine-level notes

- Source: raw capture + Ghidra decompile 2026-07-29 (refine + residual; body unchanged).
- `__cdecl`; returns `pOutBuf` (or `""` if null).
- Pure UX formatter: **no cast state mutation**.
- `FUN_007a69d0` = locale string-table singleton ensure (`&DAT_00d1f660`).
- `FUN_007a6de0(englishKey, -1)` = locale lookup (`this` = locale object; decomp may elide ECX). Returns C string used for strcpy-style copy into `pOutBuf`.
- `pCharacterCtx` used **only** for case `0x10` summon-cap path (vtbl `+0x210` plant-like query + `FUN_004c3f10` / `FUN_004c2e60` / `FUN_004c2eb0`).
- Enum **names** from `Documentation/PACKET STRUCTURES.md`; English keys from this switch (name≠string is residual, not a bug).

---

## Sealed eSkillResponses string table (VERIFIED)

| Code | Hex | Enum name (docs) | Message / behavior |
|---:|---|---|---|
| 0 | 0x00 | OK | no dedicated case → **default** if ever formatted |
| 1 | 0x01 | SERVER_CHECKS_FAILED | `Server checks failed!` |
| 2 | 0x02 | GENERIC_FAILED | `Skill failed.` |
| 3 | 0x03 | CORPSE | `Cannot do that while wrecked!` (LocalCastValidate also returns 3 for missing/empty power plant) |
| 4 | 0x04 | POWER | `You don't have enough power!` |
| 5 | 0x05 | STATUS | `You can't do that with your current status.` |
| 6 | 0x06 | BUSY | `You're already actively using a skill!` |
| 7 | 0x07 | RECHARGE | `This skill is not ready to use again yet!` |
| 8 | 0x08 | SUMMONCOUNT | `You have too many of that summon.` |
| 9 | 0x09 | NOAIR | `You can't do that while in the air.` |
| 10 | 0x0A | EXCLUSIVE | `You have an active skill that prevents you from doing that.` |
| 11 | 0x0B | NEEDSTEALTH | `You must be hidden to use this.` |
| 12 | 0x0C | NOSTEALTH | `You can't do this while hidden.` |
| 13 | 0x0D | RANGE | `Target out of range.` |
| 14 | 0x0E | FACTION | `Wrong target type.` (name≠UX residual) |
| 15 | 0x0F | AI_DIDNT_CAST | **default** `Unhandled reason for skill failure.` (LocalRange accuracy miss also returns 0x0F) |
| 16 | 0x10 | SUMMONCOUNT_TOTAL | summon level-cap **sprintf** (see below) |
| 17 | 0x11 | CANCELLED_ACTIVE | **default** unhandled (wire cancel; Recv treats specially) |
| 18 | 0x12 | TOO_SOON | `Target has just been stunted` (name≠UX residual) |
| 99 | 0x63 | DEATHCAST | **default** unhandled |
| other | — | — | **default** `Unhandled reason for skill failure.` |

### Case 0x10 (summon cap) CF

```
if pCharacterCtx && vtbl+0x210(ctx, 0) != 0:
  // plant / pool queries via vtbl+0x210 + FUN_004c3f10 / FUN_004c2e60
  // raw: uVar3 = FUN_004c3f10(...); uVar4 = FUN_004c2e60(); if (uVar4 <= uVar3)
  // operand meaning (count vs cap) OPEN — leave FUN_*
  if (uVar4 <= uVar3):
    maxCount = FUN_004c2e60(...)   // first post-gate sample used in sprintf %d
    nextTier = FUN_004c2e60(...)
    requiredLevel = FUN_004c2eb0( vtbl+0x210(ctx, 0, nextTier+1) )
    if requiredLevel > 0x50:
      sprintf(out, "%s %d %s.", "You can only have", maxCount, "summons at a time")
    else:
      sprintf(out, "%s %d %s %s %d.",
              "You can only have", maxCount, "summons at a time", "until Level", requiredLevel)
    return out
// fallback:
copy "You have too many of that summon."  // same as case 8
```

Callee internals of `FUN_004c3f10` / `FUN_004c2e60` / `FUN_004c2eb0` are **out of unit** (owned elsewhere); this unit only needs the message templates and that `pCharacterCtx` is optional.

---

## Cross-check: producers of codes (not this unit)

| Code | Known producer (Probable/High) |
|---:|---|
| 3,4,5,6,7,10,11,12 | `Skill_LocalCastValidate` `0x0051a790` |
| 13,14 | range/target helpers (via LocalRangeTargetCheck chain / server) |
| 0x0F | `Skill_LocalRangeTargetCheck` accuracy miss |
| 0x11 | cancel / Recv path |
| 1,2 | server-ish / generic fail UX |

---

## Pseudocode (annotated)

```c
/* Skill_FormatFailureMessage — eSkillResponses → toast string
   __cdecl; pure out-buf fill. */

char * __cdecl Skill_FormatFailureMessage(
    int eSkillResponse,
    char *pOutBuf,
    void *pCharacterCtx)
{
  if (pOutBuf == NULL) {
    return "";
  }

  LocaleStringTable_EnsureInit(); /* FUN_007a69d0 */

  switch (eSkillResponse) {
  case 1:  return CopyLocale(pOutBuf, "Server checks failed!");
  case 2:  return CopyLocale(pOutBuf, "Skill failed.");
  case 3:  return CopyLocale(pOutBuf, "Cannot do that while wrecked!");
  case 4:  return CopyLocale(pOutBuf, "You don't have enough power!");
  case 5:  return CopyLocale(pOutBuf, "You can't do that with your current status.");
  case 6:  return CopyLocale(pOutBuf, "You're already actively using a skill!");
  case 7:  return CopyLocale(pOutBuf, "This skill is not ready to use again yet!");
  case 8:  return CopyLocale(pOutBuf, "You have too many of that summon.");
  case 9:  return CopyLocale(pOutBuf, "You can't do that while in the air.");
  case 10: return CopyLocale(pOutBuf, "You have an active skill that prevents you from doing that.");
  case 11: return CopyLocale(pOutBuf, "You must be hidden to use this.");
  case 12: return CopyLocale(pOutBuf, "You can't do this while hidden.");
  case 13: return CopyLocale(pOutBuf, "Target out of range.");
  case 14: return CopyLocale(pOutBuf, "Wrong target type.");
  case 16: /* 0x10 */ goto summon_cap_path;
  case 18: /* 0x12 */ return CopyLocale(pOutBuf, "Target has just been stunted");
  default:
    /* 0, 15, 17, and any other */
    return CopyLocale(pOutBuf, "Unhandled reason for skill failure.");
  }

summon_cap_path:
  /* pCharacterCtx-dependent sprintf or case-8 fallback — see CF above */
  ...
  return pOutBuf;
}
```

`CopyLocale` = `FUN_007a6de0(key, -1)` then null-terminated byte copy into `pOutBuf`.
