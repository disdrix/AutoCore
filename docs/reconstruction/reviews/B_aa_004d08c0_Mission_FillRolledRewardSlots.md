# Review B (skeptical / adversarial): `aa_004d08c0` Mission_FillRolledRewardSlots

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d08c0` |
| **VA** | `0x004d08c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004d08c0_Mission_FillRolledRewardSlots.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** — loop CF High; arity map **not fully sealed** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Single-arg free function only | Listing **RET 0xC** + 3 call-site pushes | **Falsified** — three stack formals |
| 2 | Uses RNG roll inside body | arg2 formal present; sparse direct body reads | **Partial** — ABI sealed, deep use open |
| 3 | Always fills 4 COIDs | Resolve can fail → skip slot | **Falsified always** |
| 4 | Type-0 safe | Type gate is caller | **Survives caller discipline** |
| 5 | Clean invents 4-slot | Raw has local_8=4 loop | **Survives** |
| 6 | Product "loot table roll" sealed | No strings | **Tentative English** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 4-iter slot loop | **High** | Wrong reward count |
| Flag `\|4` + COID copy | **High** | Broken grant filter later |
| 3-arg RET 0xC | **High** | Stack smash if ported as 1-arg |
| Character as arg1/ECX feed | **High** listing load | Wrong staging owner |

---

## 3. Surviving contract for AutoCore

```
// MUST use 3-arg RET 0xC shape (listing sealed 2026-07-29).
// Decompiler 1-arg view is wrong.
// Keep paired with FUN_004cf100 type-0 path.
// Parent residual mild arity open → closed for stack count; roll depth still light.
```
