# Function record: FUN_008aa3f0 (Dialog_SelectRewardSlot)

| Field | Value |
|---|---|
| **Stable ID** | `aa_008aa3f0` |
| **Canonical name** | `FUN_008aa3f0` |
| **Product alias** | `Dialog_SelectRewardSlot` (Tentative — role name) |
| **Address** | `0x008aa3f0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` |
| **Completion status** | **Dual A/B sealed** — `accept-with-gaps` (2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (static dual only) |

## Purpose

Select a mission-dialog reward slot: copy per-slot TFID into the dialog’s selected TFID pair (`+0x578/+0x57c`), restyle all four reward chrome widgets (unselected then selected), and clear the “must choose a reward” hint widget (`+0x708`) with empty string `DAT_00a1419b`.

Used for:

1. **Auto-select** sole resolved reward on turn-in chrome fill (`FUN_008aa760` → slot 0).
2. **Click-select** among multi-reward turn-in choices (`FUN_008aec40` control ids `0x9c42..0x9c45`).

## Signature (sealed)

```c
// EAX = dialog UI host
// stack param_1 = slot index (0..3 expected; no clamp)
void FUN_008aa3f0(int slotIndex);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008aa3f0_FUN_008aa3f0.md`
- Annotated: `docs/reconstruction/raw/aa_008aa3f0_FUN_008aa3f0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_008aa3f0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_008aa3f0_Dialog_SelectRewardSlot.md`
- Dual B: `docs/reconstruction/reviews/B_aa_008aa3f0_Dialog_SelectRewardSlot.md`

## Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Caller | `FUN_008aa760` @ call `0x008aa968` | `PUSH 0`; `MOV EAX,EDI`; only if `+0x514==1 && +0x64c≠0` |
| Caller | `FUN_008aec40` @ call `0x008aed23` | `slot = controlId-0x9c42`; msg==8; `+0x64c≠0` |
| Callees | Indirect only | widget `vtbl+0x158`, `+0x34c`; hint `vtbl+0x308` |

## Offsets

| Off | Role |
|---|---|
| `+0x558` | Reward slot TFID array (8 B × 4) |
| `+0x578/+0x57c` | Selected reward TFID |
| `+0x594` | Unselected style param block |
| `+0x5a4` | Selected style param block |
| `+0x698` | Four reward widget pointers (4 B stride) |
| `+0x708` | Choose-reward hint widget (optional) |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + prologue bytes | **High** |
| EAX this + stack slot ABI | **High** |
| TFID selection writer | **High** |
| Dual callers (auto + click) | **High** |
| Vtbl / style product names | **Tentative** |
| Runtime null/OOB | **Open** |
