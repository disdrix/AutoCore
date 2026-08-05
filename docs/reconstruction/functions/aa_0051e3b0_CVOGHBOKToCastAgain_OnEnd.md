# Function record: CVOGHBOKToCastAgain_OnEnd

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051e3b0` |
| **Canonical name** | `CVOGHBOKToCastAgain_OnEnd` |
| **Address** | `0x0051e3b0` |
| **Body** | `0x0051e3b0`–`0x0051e3ca` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Completion status** | **Human-refined + dual residual 2026-07-29** — CF/ABI sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual residual** | `reviews/a_0051e3b0.md` |
| **Dual A/B** | `reviews/A_aa_0051e3b0_*`, `reviews/B_aa_0051e3b0_*` |

## Purpose

Type-8 cast-again heartbeat **OnEnd** (vtable slot **+0x14**). Clears skill casting flag when the cast-again window ends; does **not** erase category cooldown map (inserted in ctor). Trailing call is an empty shared stub.

## Signature (machine-sealed)

```c
// __thiscall — ECX = CVOGHBOKToCastAgain* / CVOGHBBase*; 0 stack args
void __thiscall CVOGHBOKToCastAgain_OnEnd(void* thisHb);
```

## Control flow (sealed)

1. If `*(thisHb+0x18) != 0` (owner object from `AttachOwnerObject`):
   - `Skill_SetIsCastingFlag(*(thisHb+0x24), 0)` — `skill+0x628 = 0`; false path does not touch `+0x170`/`+0x178`.
2. Tail-jump `FUN_005081f0` with `ECX=thisHb` — single-byte `ret` (no-op).

## Layout used

| Offset | Field | Source |
|---|---|---|
| `HB+0x18` | owner object | `CVOGHBBase_AttachOwnerObject`; ctor attaches owner |
| `HB+0x1c` | type **8** | ctor (not written here) |
| `HB+0x24` | skill runtime | ctor |
| `skill+0x628` | is-casting flag | `Skill_SetIsCastingFlag` |

## Vtbl

| Item | Value |
|---|---|
| `g_pVtbl_CVOGHBOKToCastAgain` | `0x009ce1c4` |
| OnEnd slot | **+0x14** → DATA at `0x009ce1d8` |
| OnStart sibling | +0x04 → `0x0051e390` |

## Callers / callees

| Dir | Target | Notes |
|---|---|---|
| Xref in | `0x009ce1d8` DATA only | virtual dispatch |
| Callee | `Skill_SetIsCastingFlag` `0x005502d0` | `push 0`; RET 4 |
| Callee | `FUN_005081f0` `0x005081f0` | empty `C3`; tail-jmp |

## Artifacts

- Residual: `docs/reconstruction/reviews/a_0051e3b0.md`
- Raw: `docs/reconstruction/raw/aa_0051e3b0_CVOGHBOKToCastAgain_OnEnd.md`
- Annotated: `docs/reconstruction/raw/aa_0051e3b0_CVOGHBOKToCastAgain_OnEnd.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBOKToCastAgain_OnEnd.cpp`

## Confidence

| Claim | Level |
|---|---|
| Control flow + offsets from machine | **High** |
| Empty stub identity (behavior) | **High** |
| Product English for `FUN_005081f0` | Open |
| Parameter semantic names | **High** (owner / skill from ctor + AttachOwner) |
| Runtime / bit-exact | Open |
