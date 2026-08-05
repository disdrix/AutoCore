# Review B residual refresh (skeptical): `UseItem_Eval` @ `0x0060cfe0` (2026-07-29)

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060cfe0` |
| **Review type** | Skeptical residual — **not** full re-dual |
| **Counterpart** | `A_aa_0060cfe0_CVOGObjectiveRequirement_UseItem_Eval_residual.md` |
| **Prior dual** | `B_aa_0060cfe0_CVOGObjectiveRequirement_UseItem_Eval.md` (2026-07-23) |
| **Scratch** | `tmp/a_0060cfe0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Attacks on residual claims

| # | Challenge | Outcome |
|---:|---|---|
| 1 | Slot floats are **deltas** (client accumulates) | **Falsified.** RecvObjectiveState does pure assignment of four packet dwords. Eval never adds. If server sent deltas, each packet would **replace** progress, not accumulate — and UI SlotAction would show the delta as the full count. |
| 2 | Eval and SlotAction might index different slots | **Falsified.** Byte-identical addressing: `param_3+4+(uint)*(byte*)(param_1+8)*4`. |
| 3 | RecvObjectiveState slots are only ratios 0..1 | **Overstated for UseItem.** Family absolute-count types (UseItem/Kill/Collect) compare integer thresholds to slot floats; ratio-only types are a different builder path. This Eval would complete only at ratio ≥ RepeatCount (e.g. need 3 uses → ratio 3.0 impossible) if mis-fed a 0..1 ratio — operational proof slots must be absolute counts. |
| 4 | Eval consumes / destroys items | **Still falsified** (prior B) — pure compare. |
| 5 | Required count lives at `+0x18` like Kill | **Still falsified** — UseItem is `+0x50`. |
| 6 | SlotAction is what Recv calls at `vtbl+0x20` | **Not claimed.** Residual only seals **shared slot index**; action virtual identity is separate. |

---

## 2. Surviving contract (AutoCore)

```
// Server (absolute):
progress = usesCompleted   // 0..RepeatCount, not delta, not ratio
slot[FirstStateSlot] = (float)progress
// Client Eval:
complete iff (float)RepeatCount <= slot[FirstStateSlot]
// Journal SlotAction:
sprintf("%s: %i / %i", name, (int)slot[FirstStateSlot], RepeatCount)
```

Risk if wrong: UseItem objectives never complete, or complete on first packet with wrong ratio semantics.

---

## 3. Confidence (adversarial residual)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Absolute slot semantics for UseItem | **High** | Never-complete or false-complete |
| Shared slot index Eval/SlotAction/Recv | **High** | UI count ≠ completion gate |
| `+0x50` RepeatCount threshold | **High** (prior) | Wrong threshold field |
| Runtime wire values | **Open** | Content-specific edge cases only |

---

## 4. Open (do not invent)

1. Live capture of multi-use RepeatCount>1 mid-progress packets.
2. Interaction if multiple UseItem requirements share one objective with distinct slots.
3. Eval scheduling after Recv (does dirty/`FUN_0092ce90` call EvaluatePending?) — **Recv residual**, not this body.

**Verdict:** residual challenges on absolute/shared-slot **defeated**. **accept-with-gaps.**
