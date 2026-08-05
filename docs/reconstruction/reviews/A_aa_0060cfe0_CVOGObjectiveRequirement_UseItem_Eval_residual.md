# Review A residual refresh: `CVOGObjectiveRequirement_UseItem_Eval` (2026-07-29)

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060cfe0` |
| **VA** | `0x0060cfe0` |
| **Canonical name** | `CVOGObjectiveRequirement_UseItem_Eval` |
| **Scope** | Dual residual only — **not** a full-function re-dual |
| **Counterpart** | `B_aa_0060cfe0_CVOGObjectiveRequirement_UseItem_Eval_residual.md` |
| **Prior dual** | `A_aa_0060cfe0_CVOGObjectiveRequirement_UseItem_Eval.md` (2026-07-23 accept-with-gaps) |
| **Scratch** | `tmp/a_0060cfe0.md` |
| **Verdict** | **accept-with-gaps** — prior open static gaps **sealed**; runtime/diff still open |

---

## 1. Residuals closed

| Prior gap | Resolution | Confidence |
|---|---|---|
| Absolute vs delta use counts on `0x2071` | **Absolute.** `Client_RecvObjectiveState` assigns packet slots; Eval/SlotAction only read. Server absolute use count (0,1,2…) required. | **High** |
| Same progress slot as SlotAction / Recv write | **Same formula.** `state+4+slot*4` with `slot=(byte)req+0x08`; Recv fills `state[1..4]` from packet `+0x18..+0x24`. | **High** |
| Threshold offset | Unchanged: `(float)(int)req+0x50` (RepeatCount) — not Kill's `+0x18` | **High** |
| Compare polarity | Unchanged: `required <= progress` → complete (1) | **High** |
| Pure eval (no consume) | Unchanged: no stores in body | **High** |

---

## 2. Control flow (unchanged; clean ≡ raw)

```
entry
  if (float)*(int*)(req+0x50) <= *(float*)(state + 4 + (uint)*(byte*)(req+8)*4)
    return 1
  return 0
```

| Stage | Match |
|---|---|
| Threshold load `+0x50` int→float | **Yes** |
| Slot index byte `+0x08` ×4 | **Yes** |
| Float `<=` complete | **Yes** |
| No mutation / no callees | **Yes** |

---

## 3. Cross-artifact evidence (this residual)

| Artifact | Role |
|---|---|
| `raw/aa_0060cfe0_…` | Authoritative body |
| `raw/aa_0060d060_…` SlotAction | Same slot formula; display-only |
| `raw/aa_00809460_…` RecvObjectiveState | Absolute dword stores → `state[1..4]` |
| `ObjectiveStateBuilder` (AutoCore) | Documents absolute UseItem slots vs this Eval |
| Prior dual A/B 2026-07-23 | Threshold / slot / `<=` already High |

---

## 4. Remaining gaps (accept)

1. Runtime packet capture correlating live UseObject → absolute `0x2071` → journal/`Eval` complete.
2. Differential / bit-exact vs retail EXE (deferred project-wide).
3. Which virtual Recv fires at `vtable+0x20` after slot write (not SlotAction; separate residual if needed).

**Verdict:** static dual residual for absolute-slot + shared index **sealed**. **accept-with-gaps.**
