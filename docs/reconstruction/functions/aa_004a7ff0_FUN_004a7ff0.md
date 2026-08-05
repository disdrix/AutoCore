# Function record: FUN_004a7ff0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a7ff0` |
| **Canonical name** | `FUN_004a7ff0` |
| **Structural name** | `StdVector_InsertOne_RebindIt_BasicStringW` (**Inferred**) |
| **Address** | `0x004a7ff0`–`0x004a8063` exclusive (**115 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | MSVC vector insert-one + rebind (`basic_string<wchar_t>`) |
| **Completion status** | **Dual sealed** W37-W — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Preferred: `StdVector_InsertOne_RebindIt_BasicStringW`
- Historical scaffold: `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_attachmentRe_004a7ff0` (**reject** as final plate)

## Purpose

Insert one wstring element and rebind an out-iterator to `begin' + saved_index * 0x1c` after possible realloc. Thin wrapper over `StdVector_InsertN_BasicStringW` with `count=1`.

## Signature (sealed)

```c
void __thiscall FUN_004a7ff0(
    void *vec /*ECX*/,
    void **outIt,
    void *where,
    const void *value);  // RET 0x0C
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004a7ff0_FUN_004a7ff0.md`
- Annotated: `docs/reconstruction/raw/aa_004a7ff0_FUN_004a7ff0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/StdVector_InsertOne_RebindIt_BasicStringW.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004a7ff0.cpp`
- Named record: `docs/reconstruction/functions/aa_004a7ff0_StdVector_InsertOne_RebindIt_BasicStringW.md`
- A/B: `docs/reconstruction/reviews/A_aa_004a7ff0_StdVector_InsertOne_RebindIt_BasicStringW.md`, `B_…`

## Callers / callees

| Dir | VA | Name |
|---|---|---|
| Caller | `0x004a8100` | push_back parent (`FUN_004a8100`) @ `0x004a817d` |
| Callee | `0x004a7ad0` | `StdVector_InsertN_BasicStringW` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + bytes | **Confirmed** |
| Parameter semantic names | **High** (parent + insert-n dual) |
| Types | **High** for layout/stride; product demangle open |
