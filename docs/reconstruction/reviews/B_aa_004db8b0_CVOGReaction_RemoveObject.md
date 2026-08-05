# Review B (skeptical / adversarial): `aa_004db8b0` CVOGReaction_RemoveObject

| Field | Value |
|---|---|
| **Stable ID** | `aa_004db8b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004db8b0_CVOGReaction_RemoveObject.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on type semantics & free timing |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Immediately frees the object | **Overstated** — hash insert + vcalls; free deferred |
| 2 | Types 1/3 are only weapons/armor | **Probable only** — plate labels |
| 3 | Return 1 means removed | **Overstated** — alive short path also returns 1 without full teardown |
| 4 | Symmetric exact inverse of SpawnObject | **Attacked** — shared flags/params but different type arms |
| 5 | Server Delete is this function | **Falsified** — client apply |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Resolve + type split | High | Wrong destroy path |
| Hash insert bookkeeping | High | Leaks / double free |
| When memory frees | Tentative | Ghost objects |
| bRemoveType product meaning | Probable | Wrong destroy FX |

---

## 3. Cross-check against raw

Long body; clean scaffold preserves order. Spot-check: ResolveObjectTarget first; type 1|3 vs 0x36; hash lock log strings present (`HashError:insert…`, `Duplicate hash insert`).

---

## 4. Surviving contract for AutoCore

```
RemoveObject(ctx, objectId, instanceId, removeType) -> 0|1
  resolve target; miss → soft clear + return 0
  if already-live short path: maybe FUN_004d0e90; return 1
  type-specific destroy; unspawn vcall; clear spawn bit
  record in removal hash (+0xe5c0)
Client-side; free timing open.
```

---

## 5. Open questions

1. Drain of removal hash.
2. Reaction type 3 vs 8 `bRemoveType` mapping.
3. Type 0x36 product identity.
4. Live Delete reaction wire path.

**Verdict:** Accept remove apply structure; do not assume immediate free.
