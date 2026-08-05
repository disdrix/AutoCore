# Review B (skeptical / adversarial): `aa_00530610` CVOGCharacter_AddMissionCounter

| Field | Value |
|---|---|
| **Stable ID** | `aa_00530610` |
| **VA** | `0x00530610` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00530610_CVOGCharacter_AddMissionCounter.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** — CF sealed; insert-seed vs delta formal split needs careful port |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Map lives only at `+0x588` | Listing: object `+0x584`, head compare `+0x588` | **Residual oversimplified** — two offsets |
| 2 | Two stack arguments | **RET 0xC** | **Falsified** — three |
| 3 | Decompiler `param_3` used for both insert and hit | Listing uses different stack slots for insert value vs hit addend | **Decompiler merge risk** |
| 4 | Always inserts | Hit path only adds | **Falsified** |
| 5 | Free function | ECX character | **Falsified** |
| 6 | Return meaningful status | void / no AL set | **Survives void** |
| 7 | CompleteObjective third push is dead | Callee **RET 0xC** consumes it | **Falsified as dead** — formal exists |
| 8 | Name "mission counter" is product-sealed | No string in unit | **Tentative English only** |

---

## 2. Decisive dataflow

```
this (character)
  mapObj = this+0x584
  head   = *(this+0x588)
  find(mapObj, key)
  if found == head:
    node = insert(mapObj, key)
    node dwords seeded (0 + third formal per listing path)
  else:
    *(found+0x14) += second formal (delta)
  RET 0xC
```

Callers (Ghidra): CompleteObjective, `FUN_00809e90`, `FUN_0080c040`.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Hit `+=` at +0x14 | **High** | Wrong progress math |
| Miss vs hit gate via head | **High** | Double-insert / missed add |
| RET 0xC arity | **High** | Stack smash port |
| Which formal is insert seed vs delta | **Probable** | First-grant wrong value |
| Product counter semantics | **Low** | Wrong system port |
| Clean arity comments | **Fail until fixed** | scaffold says 2 args |

---

## 4. Surviving contract for AutoCore

```
// Always pass 3 stack formals from mission reward path: (key, delta, 0).
// Treat +0x584 as map object, +0x588 as end/head sentinel — not interchangeable.
// Do not trust decompiler 2-arg prototype.
// Return void; CompleteObjective ignores status.
```

## 5. What would overturn

1. Proof `FUN_00418b80` is not map lower_bound for this layout.
2. Runtime dump of node at first insert with non-zero third formal from other callers.
3. Image change.
