# Review B (skeptical / adversarial): `aa_00802170` Client_LocalDeathUiSequence_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00802170` |
| **VA** | `0x00802170` |
| **Canonical name** | `Client_LocalDeathUiSequence_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00802170_Client_LocalDeathUiSequence_Inferred.md` |
| **System** | client combat / death / respawn UI |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Server kill-loot generator | No loot/credit calls; client UI only | **Falsified** loot merge |
| 2 | Always runs on any destroy | Multi-flag outer gate; may no-op | **Falsified** always-run |
| 3 | Opens dialogs | Closes exclusive (`007fca10`) then shows death widgets | **Falsified** open-dialog |
| 4 | Unconditional death FX | Needs `+0x3c10` non-null | **Falsified** |
| 5 | Unconditional death widget block | Needs both `+0x1158` and `+0x114c` | **Falsified** |
| 6 | HB always enqueued | Needs `+0xd38` list | **Falsified** |
| 7 | Same as respawn button logic | Different VA; this is pre-respawn death presentation | **High** separate |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Outer gate + dialog sweep | **Confirmed** | Death UI in wrong modes |
| LED_FX_death path | **Confirmed** | Missing death VFX |
| Widget fade 1.5f | **Confirmed** | Wrong fade |
| Flag English (+0xaa, DATs) | **Tentative** | Wrong eligibility |
| HB payload meaning | **Open** | Wrong timer behavior |

---

## 3. Cross-check against raw / live / bytes

```
batch_decompile ≡ raw.
Callees include Client_MaybeShowFirstTimeTip, LED_FX_death, CVOGHB* — death family.
Caller Client_RecvDestroyObject matches "local object gone / death" presentation.
```

### Merge trap

Do **not** merge with:

- kill-loot / XP duals (`0050ac80` family)
- `Client_OpenDialogByIndex` (`007fef20`) — death **closes** exclusives
- server-side death

### Partial-run trap

Ports that always show widgets/FX without `1158/114c/3c10` checks diverge from retail.

---

## 4. Surviving contract for AutoCore

```
Client_LocalDeathUiSequence(client):
  if !eligible(flags + local char + not blocked drive/mode): return
  teardown partial UI; close exclusive dialogs
  tip(7); optional death LED FX
  optional death widget fade block
  optional HB enqueue(300000ms)

AutoCore must NOT:
  - place loot generation here
  - skip outer gate
  - force widgets without 1158/114c
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Death UI sequence | **Agree Confirmed** |
| Outer gate + dialog close | **Agree Confirmed** |
| Optional FX/widgets/HB | **Agree Confirmed** |
| Flag English Tentative/Open | **Agree** |
| accept-with-gaps | **Agree** |

---

## 6. Open questions

1. Dual `FUN_005b3210` / death HB.
2. When `RecvDestroyObject` sets eligibility `+0xaa`.
3. Link to respawn UI (`ClientSpecialEvent_Respawn_Update`).

**Verdict:** **accept-with-gaps** — agree with A; block loot/always-run mistakes.
