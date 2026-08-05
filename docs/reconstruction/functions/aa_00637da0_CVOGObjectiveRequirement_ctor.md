# Function record: CVOGObjectiveRequirement_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00637da0` |
| **Canonical name** | `CVOGObjectiveRequirement_ctor` |
| **Prior / Ghidra** | `FUN_00637da0` |
| **Address** | `0x00637da0` |
| **Body** | `0x00637da0`–`0x00637db1` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` |
| **Completion status** | **Dual sealed 2026-07-29 (W17-Q)** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

MSVC **`__thiscall` base constructor** for RTTI class `CVOGObjectiveRequirement`:

1. Install base vtable `PTR_LAB_009e3bac` (`0x009e3bac`).
2. Store `parent` at `this+0x04`.
3. Return `this` in EAX.

No RequirementType, no inventory, no virtual dispatch beyond vfptr install. All production requirement subclass ctors call this then overwrite `*this` with their own vtable.

## Signature (sealed)

```c
// RET 4 — one stack arg; this in ECX; returns this in EAX
void* __thiscall CVOGObjectiveRequirement_ctor(void* this, void* parent);
```

## Layout written

| Off | Value | Role |
|----:|-------|------|
| `+0x00` | `0x009e3bac` | base vfptr |
| `+0x04` | `parent` | owner / parent objective |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00637da0_FUN_00637da0.md` (+ 2026-07-29 residual)
- Annotated: `docs/reconstruction/raw/aa_00637da0_FUN_00637da0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGObjectiveRequirement_ctor.cpp`
- Legacy scaffold: `reconstructed-exact/FUN_00637da0.cpp`, `functions/aa_00637da0_FUN_00637da0.md`
- Dual A: `docs/reconstruction/reviews/A_aa_00637da0_CVOGObjectiveRequirement_ctor.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00637da0_CVOGObjectiveRequirement_ctor.md`

## Callers / callees

| Direction | Symbol | VA | Role |
|---|---|---|---|
| Caller | `CVOGObjectiveRequirement_Collect_ctor` | `0x00611690` | type=2 Collect |
| Caller | `CVOGObjectiveRequirement_Deliver_ctor` | `0x00610bc0` | type=3 Deliver |
| Caller | 12 other requirement subclass ctors | see residual | overwrite vfptr after base |
| Callee | *(none)* | — | leaf |

## Confidence

| Claim | Level |
|---|---|
| ABI `__thiscall` / `RET 4` / return this | **Confirmed** (bytes) |
| vfptr `0x009e3bac` | **Confirmed** |
| `this+0x04 = parent` | **Confirmed** |
| Class = `CVOGObjectiveRequirement` base | **High** (RTTI string + shared callers) |
| Base vfptr slot product names | **Open** |
| Runtime / bit-exact | **Open** |
