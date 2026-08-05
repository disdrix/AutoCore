# Review B (skeptical / adversarial): `aa_005bbb90` FxNode_SetEnabledCascade_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005bbb90` |
| **VA** | `0x005bbb90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005bbb90_FxNode_SetEnabledCascade_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Same 2-arg ABI as `FUN_0058e930` | Sibling habit | **Falsified** — 3 args; `ret 8`; `param_3` gates deactivate list |
| 2 | Deactivate always clears list | Ignore multi-gate | **Falsified** — needs float≥999999, type≠4, `param_3==0`, non-empty list |
| 3 | Threshold is 1e6 exactly / 0 / 1 | Guess | **Falsified** — `DAT_00aaa66c` = **999999.0f** (`f0237449`) |
| 4 | Activate path walks the list | Symmetry assumption | **Falsified** — list walk only on deactivate branch |
| 5 | Zeros three floats always on activate | Over-generalize | **Falsified** — always `+0x804=0` and `+0x810←+0x8fc`; `+0x808` only if `+0x989&0x10` |
| 6 | Mission-audio table body | Parent-seed alias | **Falsified as role** — field cascade only; no audio calls |
| 7 | Comparison is strict `<` only (skip equals) | Float edge | **Falsified** — decompile uses `<` **or** `==` (i.e. `>=` gate to enter) |
| 8 | Product name sealed | Symbol inflation | **Not sealed** — `_Inferred` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Enable store `+0x7f8` | **High** | Miss primary flag |
| Activate field writes | **High** | Wrong init on fire-start |
| Deactivate multi-gate + list zero | **High** | Clear too often / never |
| Constant 999999 | **High** | Wrong threshold |
| Field product English | **Low** | Doc only |
| Type-4 meaning | **Low** | Wrong suppress rule interpretation |

---

## 3. Cross-check against raw

```text
// raw ≡ live ≡ bytes
*(char*)(this+0x7f8) = enabled;

if (enabled == 0) {
  if ( *(float*)(this+0x900) >= 999999.0f
    && *(int*)(*(this+4)+0x28) != 4
    && param_3 == 0
    && list(+0xa24) non-empty ) {
      for node in list: zero payload+0x16c, +0x170
  }
} else {
  *(float*)(this+0x804) = 0;
  *(this+0x810) = *(this+0x8fc);
  if (*(byte*)(this+0x989) & 0x10)
    *(this+0x808) = *(this+0x900);
}
// ret 8

// Parent FUN_004b8dc0 is sole caller; only this sibling receives param_3
```

---

## 4. Surviving contract for AutoCore

```
FxNode_SetEnabledCascade_Inferred(this, enabled, param_3):
  this->enabled_7f8 = enabled
  if enabled:
    this->f804 = 0
    this->d810 = this->d8fc
    if (this->flags_989 & 0x10): this->d808 = this->f900
  else:
    if f900 >= 999999.0 and type(this+4)+0x28 != 4
       and param_3==0 and list_a24 non-empty:
      for payload in list_a24: payload.u16c = payload.u170 = 0

// DAT_00aaa66c @ 0x00aaa66c = 999999.0f
// Caller: FUN_004b8dc0 list +0x1E0 only
// Sibling: FUN_0058e930 (bit deposit; no list clear)
```

**Port tests that matter:**

* **3-arg** thiscall; preserve `param_3` gate.
* Deactivate clear **not** unconditional.
* Threshold **999999**, not 1e6 / 0.
* Activate must not walk `+0xa24`.
* Do not invent audio/play in this body.

---

## 5. Open questions

1. Product names for node, type-4 class, list payloads.
2. Semantic of `+0x900` float (why 999999 is special).
3. What `param_3 != 0` means at host call sites beyond weapon `(0,0)/(1,0)`.
4. Runtime CE on activate/deactivate field snapshots.

**Verdict:** **accept-with-gaps** — attacks on 2-arg ABI, unconditional clear, wrong threshold, activate list walk, audio-table role **fail**; product English remains open.
