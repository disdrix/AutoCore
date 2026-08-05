# Review B (skeptical / adversarial): `aa_0052a1b0` CVOGReaction_RelockContinentObject

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052a1b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0052a1b0_CVOGReaction_RelockContinentObject.md` |
| **Verdict** | **accept-with-gaps** on shell; **needs-more-evidence** on erase helper |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Open-codes hash walk like Unlock | **Falsified** — erase delegated to FUN_00538c80 |
| 2 | Always deletes | **Overstated** — only if helper returns non-null |
| 3 | operator_delete never returns | **Falsified** — decompiler WARNING unreliable |
| 4 | Same as server reaction Relock ContObj | **Attacked** — exploration hash helper; type 70 separate |
| 5 | UI always refreshes | **Falsified** — local map identity gate only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Shell CF (helper → maybe delete → maybe UI) | High | Stuck unlocks |
| Hash erase correctness | Tentative | Leaks / wrong key |
| Type-70 equivalence | Low | Wrong system |

---

## 3. Cross-check against raw

```
node = FUN_00538c80(continentId, &out)
if node: delete node
if local map context: UI type 0x2a
```

Unlock inserts into `+0x534` with open walk; Relock does **not** show that walk — trust helper or re-decompile it.

---

## 4. Surviving contract for AutoCore

```
RelockContinentObject(character, continentId):
  erase exploration entry for continentId (via helper)
  maybe refresh map UI (type 0x2a) if local map
NOT full map-object relock reaction type 70.
```

---

## 5. Open questions

1. FUN_00538c80 algorithm + hash root.
2. Double-relock behavior.
3. UnlockRegion UnlockFlag==0 live path.
4. Symmetry guarantees with Unlock node layout.

**Verdict:** Accept shell; dual-review FUN_00538c80 before bit-exact erase claims.
