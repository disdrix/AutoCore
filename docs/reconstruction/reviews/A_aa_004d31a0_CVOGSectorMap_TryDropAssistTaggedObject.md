# Review A (reconstruction fidelity): `aa_004d31a0` CVOGSectorMap_TryDropAssistTaggedObject

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d31a0` |
| **VA** | `0x004d31a0` |
| **Canonical name** | `CVOGSectorMap_TryDropAssistTaggedObject` *(inferred; parent kill dual: “Assist tags”)* |
| **Ghidra name** | `FUN_004d31a0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_004d31a0_CVOGSectorMap_TryDropAssistTaggedObject.md` |
| **System** | `missions-progression` / kill side-effects |
| **Verdict** | **accept-with-gaps** — control flow sealed; product type `0x21a3` residual |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

Chance-gated **spawn + place** of a special object during kill processing, requiring two live participants.

Parent `CVOGCombat_OnDeathAwardKillXp` dual labels call sites as **“Assist tags”** (`A_aa_004da630_review.md` §4). Body shape:

1. Gate: `param_2->vtbl[+0x210](0) != 0` **and** `param_3 != null`.
2. Gate: `param_3->vtbl[+0x210](0) != 0`.
3. `threshold = *(float*)(this + 0x30)`.
4. Draw unit RNG via `CVOGReaction_RandomUnitScalar` table (`u16 * DAT_00aaa638` = u16/65536).
5. If `unit < threshold`:
   - `obj = FUN_004cf120(0x21a3, 0xffffffff)` — create typed object/reaction host.
   - `*(obj+0x170) = FUN_00521510(&stack_pos)` — copy 8-byte pose/identity blob.
   - `CVOGSectorMap_PlaceWorldObject(obj, &stack_pos, 1.0f, 1)` (`FUN_004d2820`).

Xrefs: only `0x004da846`, `0x004da88e` (both inside OnDeathAwardKillXp).

---

## 2. ABI (decompiler-derived)

```c
// __thiscall this = map or reaction host with float chance @ +0x30
void CVOGSectorMap_TryDropAssistTaggedObject(
    Host* this,
    Object* participantA,   // must pass vtbl+0x210(0)
    Object* participantB);  // non-null + vtbl+0x210(0)
```

---

## 3. RNG gate (SEALED)

Same unit-random pattern as loot:

```
u16 = next from RandomUnitScalar table
if ((float)u16 * (1/65536) < *(float*)(this+0x30)) → spawn path
```

`DAT_00aaa638 = 1/65536` confirmed.

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| Dual vtbl+0x210 gates | **Confirmed** |
| Chance at `this+0x30` | **Confirmed** |
| Creates type **0x21a3** then places radius 1 | **Confirmed** |
| Only kill-XP callers | **Confirmed** |
| Product name “assist tag” | **Medium** (parent label; not plate string) |
| `FUN_004cf120` factory semantics | **Tentative** |

---

## 5. Gaps

1. Seal what clonebase/type **0x21a3** is (assist marker vs salvage vs other).
2. `FUN_00521510` / pose source stack layout.
3. Whether `this+0x30` is per-template drop % or map global.

**Verdict:** **accept-with-gaps**.
