# Function record: Palantir_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00754320` |
| **Canonical name** | `Palantir_CompleteDtor` |
| **Ghidra name** | `FUN_00754320` |
| **Address** | `0x00754320`–`0x007543A9` exclusive (**137 B** / `0x89`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / Palantir host complete destructor |
| **Classification** | worker |
| **Completion status** | **Dual A/B filed** (W34-K 2026-07-29) — stage order/ABI/globals sealed; nested subobject duals open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Preferred: `Palantir_CompleteDtor` (**Inferred** structural + product class evidence)
- Ghidra: `FUN_00754320`
- Vtbl family: `PTR_FUN_00a9f76c` — `[0]=FUN_004447e0` scalar dtor, `[1]=FUN_00754480` ResetDevice
- Product path: `C:\vog\1_code\palantir\palantir\framework\Palantir.cpp` (via peer)
- Path-list unwind: `StringVecShell_TidyAndClearGlobal` (`aa_00444810`)

## Purpose

MSVC complete destructor body for the Palantir singleton host. Tears down tail members and nested subobjects, then clears `DAT_00d1f1fc` and `DAT_00d1f058`. Scalar delete is separate (`FUN_004447e0`).

## Signature (sealed)

```c
// ECX=this; bare RET; void
void Palantir_CompleteDtor(Palantir* self);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00754320_FUN_00754320.md` (+ W34-K append)
- Annotated: `docs/reconstruction/raw/aa_00754320_FUN_00754320.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Palantir_CompleteDtor.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00754320.cpp`
- Function (Ghidra id): `docs/reconstruction/functions/aa_00754320_FUN_00754320.md`
- Review A/B: `reviews/A_aa_00754320_Palantir_CompleteDtor.md`, `reviews/B_aa_00754320_Palantir_CompleteDtor.md`

## Callers / callees

| Callers | Callees |
|---|---|
| Scalar dtor `FUN_004447e0`; ctor/other Unwind | `~basic_string`, `StringVec_Tidy`, `FUN_0075d8e0`, `FUN_00964d00` |

## Confidence

| Claim | Level |
|---|---|
| Complete-dtor ABI (no free this) | **High** |
| Stage order / offsets | **High** |
| Class identity Palantir | **High** |
| Nested subobject full plates | **Low** |
