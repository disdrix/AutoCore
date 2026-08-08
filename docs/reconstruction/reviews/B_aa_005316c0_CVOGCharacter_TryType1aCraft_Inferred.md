# Review B (skeptical / adversarial): `aa_005316c0` CVOGCharacter_TryType1aCraft_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005316c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (WQ8R-B) |
| **Counterpart** | `reviews/A_aa_005316c0_CVOGCharacter_TryType1aCraft_Inferred.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** on CF; **reject** overclaims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Soft `return 1` when count helper fails is a decompiler bug | **Not falsified as bug** — present in raw + live re-decompile; treat as intentional CF |
| 2 | Same product field as simple twin (`object+0x34`) | **Falsified** — this unit gives `*(blob+4)` |
| 3 | Always uses ingredient `+0x4c0` like simple twin | **Falsified** — multi path uses `+0x4d0/+0x4d4` and `+0x498` list; `+0x4c0` is simple-exchange / count helper `param_5!=0` path |
| 4 | Mode args are inventoryType 1/3/5 | **Falsified** — compared to **1** and **2** as bank enable flags, not DropResponse inventoryType |
| 5 | FindFree uses locker | **Falsified** — ECX = cargo (`esi`) |
| 6 | Secondary loop always walks 5 slots | **Nuanced** — loop bound is `FUN_00599dd0` non-`-1` **prefix count**, not fixed 5; empty `-1` entries skipped when present |
| 7 | Places crafted item into found (ox,oy) | **Falsified** — FindFree outs discarded for placement; give helper creates/adds items |
| 8 | Scaffold dual already sealed | **Falsified** — 2026-07-23 FUN record only |
| 9 | Runtime Confirmed | **Fail** — no Launcher |

---

## 2. Decisive evidence

### Soft no-op (SEALED CF)

```c
cVar3 = FUN_00522060(pObj, &available, mode, 0);
if (cVar3 == '\0') {
    return 1;   // NOT 0
}
```

Do not "fix" this to failure without product proof.

### Mode matrix (SEALED)

| mode | Primary `+0x4d0/+0x4d4` | Secondary `+0x498` |
|------|-------------------------|---------------------|
| 0 (typical) | on if cost>0 | on if slots>0 |
| 1 | **off** | on |
| 2 | on if cost>0 | **off** |

### Primary shortfall split (SEALED math)

If `have < cost * qty`:  
`qtyPrimary = have / cost`, `secondaryNeed = qty - qtyPrimary`; else `secondaryNeed = 0`.  
Remove `cost * qtyPrimary` of primary CBID across cargo→locker.

### Product CBID (SEALED)

Give site: `FUN_005310a0(*(blob+4), totalOut)` — distinct from simple twin `object+0x34`.

---

## 3. Residual gaps

1. Why soft-success exists (UI vs mission reaction).
2. Exact semantics when secondary list empty but `secondaryNeed > 0` after primary shortfall (still adds to totalOut).
3. `FUN_00522060` dual not owned (behavior summarized from decompile only).
4. No static callers.

---

## 4. Verdict

Adversarial review **accepts** multi-bank craft CF, mode flags, soft no-op, and cargo FindFree. **Rejects** conflation with simple exchange fields and inventoryType misread of mode.

**accept-with-gaps.**
