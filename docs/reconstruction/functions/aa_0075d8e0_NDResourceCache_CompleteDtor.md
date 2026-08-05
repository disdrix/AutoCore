# Function record: NDResourceCache_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075d8e0` |
| **Canonical name** | `NDResourceCache_CompleteDtor` |
| **Ghidra name** | `FUN_0075d8e0` |
| **Address** | `0x0075d8e0`–`0x0075d9BF` exclusive (**223 B** / `0xDF`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | assets / NDResourceCache + AssManager host complete destructor |
| **Classification** | worker |
| **Completion status** | **Dual A/B filed** (W35-I 2026-07-29) — teardown order/ABI/global sealed; nested callees residual; Ghidra body end wrong |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Preferred: `NDResourceCache_CompleteDtor` (**Inferred**; `DAT_00d1f050` host + AssPreloader product path)
- Also structural: AssManager-shaped host complete dtor (same object as `FUN_0075d470` / EnsureAssPreloader host)
- Ghidra: `FUN_0075d8e0`
- Pair ctor: `FUN_0075d470` (unowned)
- Embedded at: `Palantir+0x30` (W34-K complete dtor stage)

## Purpose

Complete destructor for the resource-cache host published as `DAT_00d1f050`. Destroys NestedHash entries, AssPreloader, std tree, critical section, OwnedPtrTable, list shell; clears global. Does not free `self`.

## Signature (sealed)

```c
// stack self*; RET 4; void; no operator_delete(self)
void NDResourceCache_CompleteDtor(NDResourceCache* self /*stack*/);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0075d8e0_FUN_0075d8e0.md` (+ W35-I append)
- Annotated: `docs/reconstruction/raw/aa_0075d8e0_FUN_0075d8e0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/NDResourceCache_CompleteDtor.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0075d8e0.cpp`
- Function (Ghidra id): `docs/reconstruction/functions/aa_0075d8e0_FUN_0075d8e0.md`
- Review A/B: `reviews/A_aa_0075d8e0_NDResourceCache_CompleteDtor.md`, `reviews/B_aa_0075d8e0_NDResourceCache_CompleteDtor.md`

## Callers / callees

| Callers | Callees |
|---|---|
| `Palantir_CompleteDtor`; Unwind `@009afd03`/`@009afd3f` | `FUN_0075d6f0`, `FUN_00971050`, `FUN_00971180`, `operator_delete`, `FUN_0043c220`, `DeleteCriticalSection`, `OwnedPtrTable_Clear` `0x0040d9c0`, `FUN_00415e90` |

## Confidence

| Claim | Level |
|---|---|
| Stack-self ABI + RET 4 + no free self | **High** |
| Teardown stage order (bytes) | **High** |
| `DAT_00d1f050` clear | **High** |
| Host = cache/AssManager at Palantir+0x30 | **High** |
| Exact MSVC demangle / product type name | **Low** |
| Nested callee full plates | **Low** |
