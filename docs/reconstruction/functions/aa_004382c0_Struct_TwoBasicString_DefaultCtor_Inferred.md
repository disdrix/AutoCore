# Function record: Struct_TwoBasicString_DefaultCtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004382c0` |
| **Canonical name** | `Struct_TwoBasicString_DefaultCtor_Inferred` (structural; product/PDB open) |
| **Ghidra name** | `FUN_004382c0` |
| **Address** | `0x004382c0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC basic_string composite default ctor |
| **Completion status** | **Dual sealed (A+B)** — W38-G 2026-08-04 |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Scaffold seed: `Named_CalleeOf_Named_gfxBody_004382c0` (**reject** as product).
- Ghidra: `FUN_004382c0`.

## Purpose

Default-construct `{ basic_string str0; basic_string str1; }` (offsets 0 / 0x1c, total 0x38). Returns `this`.

## Signature (machine-sealed)

```c
Struct_TwoBasicString *Struct_TwoBasicString_DefaultCtor_Inferred(Struct_TwoBasicString *self);
// stack arg; ret 4; body 70 B @ 0x004382c0-0x00438305
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004382c0_FUN_004382c0.md`
- Annotated: `docs/reconstruction/raw/aa_004382c0_FUN_004382c0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Struct_TwoBasicString_DefaultCtor_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004382c0.cpp`
- Function (FUN_*): `docs/reconstruction/functions/aa_004382c0_FUN_004382c0.md`
- Review A/B under `docs/reconstruction/reviews/`
- Report: `docs/agents/task-dual-ab-00438040-004382c0-w38g-report.md`

## Callers / callees

| Direction | VA | Role |
|---|---|---|
| Callee | IAT `basic_string` ctor | Both members |
| Callers | `00437ad0`, `00765740`, `009895c0`, `0095e3e0` | Default fill / temps |

## Confidence

| Claim | Level |
|---|---|
| Dual string layout / ABI | **Confirmed** |
| Product field names | **Open** |
