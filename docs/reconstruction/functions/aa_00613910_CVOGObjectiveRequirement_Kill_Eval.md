# Function record: CVOGObjectiveRequirement_Kill_Eval

| Field | Value |
|---|---|
| **Stable ID** | `aa_00613910` |
| **Canonical name** | `CVOGObjectiveRequirement_Kill_Eval` |
| **Address** | `0x00613910` |
| **Size** | `0x20` (`00613910`–`0061392f`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Completion status** | **Dual residual sealed 2026-07-29** — formula/provenance High; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Kill requirement **eval** (vtable **+0x8**): return complete when progress slot float ≥ required kills (int@+0x18 cast to float). Pure compare — no progress mutation, no kill filters.

## Contract

```
Kill_Eval(req, /*unused*/, state) → 1|0
  (float)*(int*)(req+0x18)  <=  *(float*)(state + 4 + (*(u8*)(req+8))*4)
```

Asm polarity: `COMISS progress, required` then complete unless progress < required.

## Layout

| Offset | Role |
|---|---|
| req+0x08 | slot index (byte) |
| req+0x18 | required kill count (int32 → float) |
| state+0x04 + slot×4 | progress float |

## Vtable

| Slot | VA | Symbol |
|---|---|---|
| vtbl base | `0x009e19e4` | Kill requirement class |
| +0x4 | `0x00613b50` | `CVOGObjectiveRequirement_Kill_Precheck` |
| +0x8 | `0x00613910` | this unit |

Sole DATA xref: `0x009e19ec`. No static callers (virtual).

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_00613910_CVOGObjectiveRequirement_Kill_Eval.md` |
| Annotated | `raw/aa_00613910_CVOGObjectiveRequirement_Kill_Eval.annotated.md` |
| Clean | `reconstructed-exact/CVOGObjectiveRequirement_Kill_Eval.cpp` |
| Dual A | `reviews/A_aa_00613910_CVOGObjectiveRequirement_Kill_Eval.md` |
| Dual B | `reviews/B_aa_00613910_CVOGObjectiveRequirement_Kill_Eval.md` |
| Scratch | `tmp/a_00613910.md` |

## Confidence

| Claim | Level |
|---|---|
| Control flow / offsets / polarity | **High / Confirmed** (live asm 2026-07-29) |
| param_2 unused | **High / Confirmed** |
| Progress provenance (dual writers, pure read) | **High** |
| Parameter product names | Probable |
| Runtime / bit-exact | Open |

## Progress writers (external — not this function)

| Writer | Role |
|---|---|
| `Client_RecvObjectiveState` `0x00809460` | S2C `0x2071` absolute dwords → `state[1..4]` |
| `Kill_Precheck` `0x00613b50` | client credit `+=` into same slot; early-outs if Eval already true |

## Open questions

- Runtime observation / differential equivalence (policy)
- Precheck credit-addend residual owned by `aa_00613b50`
