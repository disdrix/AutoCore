# Review B (skeptical / adversarial): `aa_00575870` Object_PickFollowTargetFromSlots_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00575870` |
| **VA** | `0x00575870` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00575870_Object_PickFollowTargetFromSlots_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Always returns anchor TFID | Only when flag `+0x190==0` or range-fail-empty | **Falsified always** |
| 2 | 3D distance (includes Y) | Formula uses **x and z only** | **Falsified 3D** |
| 3 | Range is 100 / 50 / skill radius | **`DAT_00aaa8a8 = 300.0f`** | **Falsified** |
| 4 | Deterministic first-slot pick | **Fisher–Yates shuffle** then pop | **Falsified deterministic** |
| 5 | Allocates new objects | Lookup only + vector shuffle | **Falsified alloc** |
| 6 | OnDeath XP math lives here | Alias is chain-only; body is follow pick | **Falsified XP** |
| 7 | Infinite loop with no exit | Multiple **-1** / TFID returns; size drains | **Falsified pure infinite** (decomp form is loop but gated) |
| 8 | `FUN_00419170` is unrelated | Vector size of 8-byte elems | **Falsified unrelated** |
| 9 | Product name string-sealed | No string on VA | **Not sealed** — `_Inferred` |
| 10 | Caller never falls back | `00521510` maps -1 → self TFID | **Falsified no-fallback** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| -1 vs TFID return | **Confirmed** | Wrong follow target / stuck |
| 300 XZ gate | **Confirmed** | Wrong leash radius |
| Slot rebuild + shuffle | **Confirmed** | Sticky unfair pick |
| Flag `+0x190` bypass | **Confirmed** | Always-follow vs self |
| Vfunc `+0x198` semantics | **Medium** | Accept wrong entity class |
| Host class English | **Low–Med** | Doc only |
| Runtime | **Open** | — |

---

## 3. Surviving contract for AutoCore

```
PickFollowTarget(host, anchor, pos):
  if !anchor: return -1
  if host.flag_190 == 0: return anchor.tfid
  if anchor.field_a8 == 0: return -1
  ensure host.vector_1f8 populated from host.slots_198[0..count_1d8)
  shuffle vector; while candidates:
    tfid = pop_front
    obj = LookupByTfid(tfid)
    if obj && xz_dist(pos, obj.pos) <= 300:
      if last candidate: return tfid
      slotObj = resolve_slot(tfid)
      if slotObj && !slotObj.vfunc_198(): return slotObj.tfid
    else if out_of_range && no candidates left: return anchor.tfid
  // drains / retries until -1 or return
// Caller 00521510: if host+0xcb0==0 or result==-1 → self.tfid
```

Port rule: **do not** use full 3D distance; **do** shuffle; respect 300f XZ leash.

---

## 4. Open questions

1. Host type name (convoy leader vs pet owner vs party).
2. Vfunc `+0x198` boolean meaning.
3. Whether `+0xcb0` on caller is “follow enabled” product flag.

**Verdict:** **accept-with-gaps** — adversarial pass keeps shuffle + 300 XZ + slot TFID contract; naming residual only.
