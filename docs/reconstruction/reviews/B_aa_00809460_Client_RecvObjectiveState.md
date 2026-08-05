# Review B (skeptical / adversarial): `Client_RecvObjectiveState` @ `0x00809460`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00809460` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` (residual refresh `2026-07-29`; Action map strengthen same day) |
| **Counterpart** | `reviews/A_aa_00809460_Client_RecvObjectiveState.md` |
| **Residual scratch** | `reviews/a_00809460.md` |
| **Verdict** | **accept-with-gaps** on CF; prior post-slot eval-scheduling attack **falsified**; Action-slot mislabel **corrected** |

---

## 1. Claims under attack

| # | Claim | Attack | Residual status |
|---|---|---|---|
| 1 | RecvObjectiveState completes objectives | **Falsified** — no CompleteObjective call; that is `0x2070` / `Client_RecvCompleteDynamicObjective` | Holds |
| 2 | Slot values are always ints | **Overstated** — stored as raw dwords; Eval reinterprets as **float** | **Sealed: IEEE float bits** |
| 3 | Bitmask fires all evaluators | **Falsified** — only bits set in packet+0x10 | Holds |
| 4 | Missing pending node is fatal error | **Overstated** — silent no-op if lookup fails | Holds |
| 5 | Dialog turn-in should also send 0x2071 | **Policy risk** — turn-in uses local CompleteObjective; 0x2071 is progress sync only | Holds |
| 6 | Dirty flag / `FUN_0092ce90` invoke EvaluatePending | **Falsified (residual)** — neither body calls EvaluatePending; xrefs show other callers only | **Sealed** |
| 7 | `vtable+0x20` is type-specific event Action (e.g. Collect_Action) or Eval | **Falsified** — 14 vtables share `FUN_00637de0` toast; Collect event Action is `+0x04`; Patrol ratio helper is `+0x10` | **Sealed shared toast** |
| 8 | `vtable+0x20` Action completes objective | **Falsified** — toast only; types 7/8 no-op; never CompleteObjective | **Sealed** |
| 9 | Patrol_Action `0x0060e120` is Recv's `+0x20` | **Falsified** — DATA xref places it at Patrol vtbl **+0x10** | **Sealed correction** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Progress-only vs force-complete split | High | Double-complete or stuck objectives on server |
| Packet offsets +0x10/+0x14/+0x18.. | High | Wrong ObjectiveStateBuilder layout |
| Slot float absolute (not delta) for UseItem/Kill/Patrol | High | Under-count if server sends deltas |
| UI dirty alone triggers EvaluatePending | **High (false)** | Residual: does not; local complete needs other path or 0x2070 |
| `FUN_0092ce90` identity | **High** (role) | Cosmetic/journal only if mis-wired — sealed as UI refresh |
| Mask bit → shared toast (not Eval/complete) | **High** | Server over-relies on mask for client-side complete |

---

## 3. Surviving contract for AutoCore

```
On S2C 0x2071 ObjectiveState:
  if local character and pending-objective(id@+0x14) exist:
    state[1..4] = packet slots +0x18..+0x24   // IEEE float bits
    optional mission UI refresh (client+0x107c)
    for each requirement i with bit i in mask@+0x10:
      // ALWAYS shared FUN_00637de0 (progress toast via SlotAction text)
      // NOT Collect_Action(+0x04), NOT Eval(+0x08/+0x10), NOT SlotAction(+0x18)
      requirement.vtbl[+0x20](character, state)
    Client_RefreshMissionRelatedUi (FUN_0092ce90)
    dirty *(client+0x4d0)+4 = 1
  // never CompleteObjective here
  // never EvaluatePendingObjectives here
Do not confuse with 0x2070 force-complete.
Send absolute float counts for UseItem/Kill/Patrol mid-progress (not deltas).
Mask bits only gate progress toasts — not completion authority.
```

---

## 4. Open questions (post-residual)

1. ~~Does dirty flag or `FUN_0092ce90` invoke EvaluatePendingObjectives?~~ **Closed — no.**
2. ~~Is `vtable+0x20` a per-type Action map?~~ **Closed — shared `FUN_00637de0` toast across sampled classes.**
3. Are all four slots always meaningful, or only low N per type? (still type-authored `FirstStateSlot`)
4. Product names for toast enqueue (`FUN_0040c5c0`) / shared Action / UI widgets.
5. Interaction with patrol tick client-side before next 0x2071 (unchanged).

**Verdict:** Safe as the progress-write kernel for objective chain. Residual closed eval-scheduling fear and Action-slot confusion; server must not rely on 0x2071 alone for client-local complete.
