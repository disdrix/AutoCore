# Function record: Palantir_BaseCtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_007543b0` |
| **Canonical name** | `Palantir_BaseCtor` |
| **Ghidra name** | `FUN_007543b0` |
| **Address** | `0x007543b0`–`0x0075447C` exclusive (**204 B** / `0xCC`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / Palantir host base constructor |
| **Classification** | worker |
| **Completion status** | **Dual A/B filed** (W35-I 2026-07-29) — ABI/globals/layout sealed; nested `FUN_0075d470` dual open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Preferred: `Palantir_BaseCtor` (**Inferred** structural + product class evidence)
- Ghidra: `FUN_007543b0`
- Reject scaffold: `Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance_007543b0`
- Vtbl: `PTR_FUN_00a9f76c` (same family as `Palantir_CompleteDtor` W34-K)
- Pair dtor: `Palantir_CompleteDtor` @ `0x00754320`

## Purpose

Base/placement constructor for the Palantir host: publish singleton `DAT_00d1f058`, install Palantir vtbl, `CoInitializeEx(0,2)`, construct nested NDResourceCache at `+0x30`, publish path shell `+0xA0` as `DAT_00d1f1fc`, construct `basic_string(".")` at `+0xB4`.

## Signature (sealed)

```c
// stack self*; RET 4; EAX=self
Palantir* Palantir_BaseCtor(Palantir* self /*stack*/);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_007543b0_FUN_007543b0.md` (+ W35-I append)
- Annotated: `docs/reconstruction/raw/aa_007543b0_FUN_007543b0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Palantir_BaseCtor.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_007543b0.cpp`
- Function (Ghidra id): `docs/reconstruction/functions/aa_007543b0_FUN_007543b0.md`
- Review A/B: `reviews/A_aa_007543b0_Palantir_BaseCtor.md`, `reviews/B_aa_007543b0_Palantir_BaseCtor.md`

## Callers / callees

| Callers | Callees |
|---|---|
| `FUN_007a26c0` (sole) | `CoInitializeEx`, `FUN_0075d470`, `basic_string` ctor |

## Confidence

| Claim | Level |
|---|---|
| Stack-self ABI + RET 4 + EAX=self | **High** |
| Globals `DAT_00d1f058` / `DAT_00d1f1fc` | **High** |
| Offsets `+0x30` / `+0xA0` / `+0xB4` | **High** |
| Product class Palantir | **High** (vtbl peer W34-K) |
| Nested cache ctor full plate | **Low** (unowned `FUN_0075d470`) |
