# Review B (skeptical / adversarial): `aa_0058e930` FxNode_SetFlagBit2_Notify_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058e930` |
| **VA** | `0x0058e930` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0058e930_FxNode_SetFlagBit2_Notify_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Whole-byte assign `*(+0x90e)=flag` | Naïve store | **Falsified** — XOR deposit of **only bit 2** (mask 4) |
| 2 | Same signature as `FUN_005bbb90` (3 args) | Sibling habit | **Falsified** — 2-arg; `ret 4`; no `param_3` |
| 3 | Always notifies nested object | Ignore gates | **Falsified** — requires `+0x90f&2` **and** `+0x91c!=0` |
| 4 | Decrements counter | Direction flip | **Falsified** — `add dword [inner+0xdc], 1` |
| 5 | Called on deactivate-only / activate-only exclusively | Parent branch habit | **Falsified as exclusive** — parent walks list **before** activate/deactivate split; both flags reach here |
| 6 | Mission-audio table helper (parent-seed name) | Alias inflation | **Falsified as role** — field bit set + optional counter; no audio table call |
| 7 | Product name sealed | Symbol inflation | **Not sealed** — `_Inferred` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Bit-2 deposit formula | **High** | Sticky other bits on `+0x90e` |
| Notify gates / offsets | **High** | Miss counter updates |
| Sole caller host cascade | **High** | Over-generalize domain |
| Nested type English | **Low** | Doc only |
| Counter meaning | **Low** | Port side-effect semantics |

---

## 3. Cross-check against raw

```text
// raw ≡ live ≡ bytes
*(byte*)(this+0x90e) ^= (flag*4 ^ *(byte*)(this+0x90e)) & 4;

if ((*(byte*)(this+0x90f) & 2) && *(this+0x91c)) {
  inner = *(*(this+0x91c) + 0x8c);
  *(inner + 0xdc) += 1;
  *(char*)(inner + 0xd0) = flag;
}
// ret 4; leaf
```

Parent `FUN_004b8dc0`: list `+0x204` → this; `param_3` **not** forwarded (only to `005bbb90`).

---

## 4. Surviving contract for AutoCore

```
FxNode_SetFlagBit2_Notify_Inferred(this, flag):
  // __thiscall
  set/clear bit2 of this->flags_byte_90e from flag (0/1)
  if (this->flags_byte_90f & 2) and this->ptr_91c:
    inner = this->ptr_91c->field_8c
    inner->counter_dc++
    inner->flag_d0 = flag

// Caller: only FUN_004b8dc0 list walk +0x204
// Sibling: FUN_005bbb90 on list +0x1E0 (different body)
```

**Port tests that matter:**

* Must preserve **other bits** of `+0x90e`.
* Must **not** require third arg.
* Notify path must honor **both** gates.
* Counter is **increment**, not clear/decrement.
* Do not invent audio/play calls in this body.

---

## 5. Open questions

1. Product names for node and nested `+0x91c` object.
2. Who sets `+0x90f` bit1.
3. Runtime observation of counter on host activate/deactivate.
4. Clean plate rename polish.

**Verdict:** **accept-with-gaps** — attacks on whole-byte store, 3-arg ABI, unconditional notify, decrement, audio-table role **fail**; English/product semantics remain open.
