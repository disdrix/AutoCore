# Review B (skeptical / adversarial): `aa_0053c760` CNDHash_Insert

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053c760` |
| **VA** | `0x0053c760` |
| **Canonical name** | `CNDHash_Insert` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0053c760_CNDHash_Insert.md` |
| **System** | container / missions-progression |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is a unique algorithm vs `0053c460` | Side-by-side decompile: only vtbl imm differs | **Falsified** unique CF — **vtbl twin only** |
| 2 | Can alias / redirect to `0053c460` | Different node vtbl → different methods / ownership | **Falsified** redirect-safe |
| 3 | Inserts objective **def** like +0x548 path | Residual: payload is state node (EBX); def uses `0053c460` | **Falsified** def payload |
| 4 | Targets same hash as active-objective def | AddActiveObjective ECX = `char+0x55c`, not +0x548 | **Falsified** same-hash |
| 5 | Same vtbl as mission state-blob insert `0053c660` | This body writes `009cefec`; twin uses `009cefe4` | **Falsified** shared vtbl |
| 6 | `allowDuplicate` multi-insert | Soft return 1 without link | **Falsified** |
| 7 | Lock aborts | Log only | **Falsified** |
| 8 | Only AddActiveObjective uses this VA | Also `FUN_00531bd0` xref | **Falsified** exclusivity; **agree** rare (2 xrefs) |
| 9 | Freelist is operator_new | Slab freelist | **Falsified** |
| 10 | AddActiveObjective deletes node **instead of** continuing | Residual: delete then fall-through evaluator loop | **Falsified** as exclusive abort |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Twin-of-insert CF | **Confirmed** | Invented special logic |
| Vtbl 009cefec distinct | **Confirmed** | Cross-wire node methods |
| +0x55c state-node role | **High** | Bind def pointer into state hash |
| HRESULTs / soft policy | **Confirmed** | |
| Hash/node layout | **High** | |
| State-node field meanings | **Open** | Wrong runtime object layout on port |
| Runtime | **Open** | |

---

## 3. Cross-check

```
raw/clean ≡ live (2026-07-29).

CF delta vs 0053c460:
  *puVar3 = &PTR_FUN_009cefec;   // ONLY structural difference

Xrefs (2):
  00531b77  CVOGMission_AddActiveObjective  — char+0x55c, stateNode
  00531c72  FUN_00531bd0

Vtbl 009cefec first methods:
  0x00537550, 0x00aad148, 0x00537630, 0x00aad190, ...
≠ 009cf02c method0:
  0x00537d10
≠ 009cefe4 method0 (mission state-blob twin):
  0x00537510
```

### Critical traps

1. **Do not** implement one shared `CNDHash_Insert` that stamps a single hard-coded vtbl for all call sites — objective def vs state need different node types.
2. **Do not** store objective def pointer into `+0x55c` using this path’s callers — def goes through `0053c460` / `+0x548`.
3. Soft-flag is still soft-skip, not multi-map.
4. Do **not** merge with mission state-blob insert `0053c660` (`009cefe4` / `char+0x530`) despite similar “state” English.

---

## 4. Surviving contract for AutoCore

```
CNDHash_Insert_0053c760(hash, key, value, softIfExists) -> int
  // identical policy to 0053c460 / 0053c360 / 0053c560 / 0053c660
  // node vtbl MUST be 009cefec

AddActiveObjective:
  hash  = char+0x55c
  key   = objId
  value = allocated objective state node
  soft  = 0
  // nonzero insert result → operator_delete(value); continue (caller)

AutoCore must NOT:
  - redirect this VA to 0053c460 / 0053c360 / 0053c660
  - put objective def into +0x55c via this insert family
  - treat CF differences beyond vtbl as real
  - confuse 009cefec (objective state) with 009cefe4 (mission grant state blob)
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Identical CF except vtbl | **Agree Confirmed** |
| Signature + HRESULTs + soft | **Agree** |
| +0x55c / state-node | **Agree High** |
| Layout shared with twin | **Agree** |
| accept-with-gaps | **Agree** |

Disputes: none.

---

## 6. Open questions

1. Semantics of each `009cefec` method (dtor / serialize / evaluator bind).
2. Exact state-node field map beyond residual setup at AddActiveObjective.
3. `FUN_00531bd0` hash root offset (likely +0x55c or sibling).
4. Runtime / bit-exact.

**Verdict:** **accept-with-gaps** — agree with A; **block twin merge and def-vs-state / mission-blob confusion**.
