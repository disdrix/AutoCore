# Function record: CVOGObject_FxPhysStartStop_IfSlotNeg_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058e300` |
| **Canonical name** | `CVOGObject_FxPhysStartStop_IfSlotNeg_Inferred` |
| **Ghidra name** | `FUN_0058e300` |
| **Address** | `0x0058e300`–`0x0058e370` (112 B exclusive) |
| **Module** | `autoassault.exe` base `0x400000` |
| **System** | client object / FX phys link |
| **Dual** | W26-L 2026-07-29 **accept** |
| **Name confidence** | **Inferred** — role from CF + NDSpecialFX callers; no product string |

## Contract

```
// thiscall RET 8
void CVOGObject_FxPhysStartStop_IfSlotNeg_Inferred(
    Object* self,
    void* want_start,   // 0 = skip start
    void* want_stop)    // 0 = skip stop
{
  if (self->slot_0x25c >= 0) return;
  if (want_stop)  FUN_0096d550(want_stop, self->key_0x914);
  if (want_start) {
    if (FUN_0096d460(want_start, self->key_0x258) == 0) {
      FUN_0096dc80(want_start, key_0x258, key_0x914, param_0x254);
      self->flags_0x90f |= 1;
      return;
    }
  }
  self->flags_0x90f &= ~1;
}
```

## Why this name

- Callers are dualed as `NDSpecialFX_*` apply/clear over owned children.
- Body is pure start/stop phys-link helpers (`0096d*`), not spawn/teardown.
- Gate is **slot negative** (unslotted), distinct from `0058e270` slot-filter.
- `_Inferred` required: no retail string in body.

## Gaps

- Product method name / class spelling.
- English for `+0x90f` bit0.
- Nested `0096d*` product duals (not OWN).
- Runtime differential.

## Artifacts

See `aa_0058e300_FUN_0058e300.md`.
