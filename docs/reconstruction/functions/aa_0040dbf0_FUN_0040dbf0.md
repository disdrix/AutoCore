# Function record: FUN_0040dbf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040dbf0` |
| **Canonical name** | `FUN_0040dbf0` |
| **Structural name** | `StdVector_InsertOne_RebindIt_Thiscall_Inferred` |
| **Address** | `0x0040dbf0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | util / container (std::vector&lt;dword&gt;) |
| **Completion status** | **Dual sealed** (A+B W16-G, 2026-07-29) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Human / structural: `StdVector_InsertOne_RebindIt_Thiscall_Inferred`
- Prior scaffold alias: `Named_CalleeOf_CVOGReaction_FailMissionNotify_0040dbf0`
- Twin customcc: `aa_00466da0` `StdVector_InsertOne_RebindIt_Inferred`

## Purpose

Insert **one** 4-byte element at a vector iterator position via `FUN_004073a0` (count=1), then write a **rebased** iterator (`begin' + saved_index`) to an out-parameter so callers survive realloc. Used as the capacity-full slow path of dword push_back (e.g. `CVOGReaction_FailMissionNotify`).

## Signature (byte-sealed)

```c
// __thiscall, callee cleans 0x0C stack bytes
void __thiscall FUN_0040dbf0(
    void *vec,          // ECX: begin@+4 end@+8 capEnd@+0xC
    void **outIt,       // stack0: written with ptr to inserted element
    void *insertPos,    // stack1: T* into buffer
    const void *value); // stack2: const T* fill source
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0040dbf0_FUN_0040dbf0.md`
- Annotated: `docs/reconstruction/raw/aa_0040dbf0_FUN_0040dbf0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_0040dbf0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0040dbf0_StdVector_InsertOne_RebindIt_Thiscall_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_0040dbf0_StdVector_InsertOne_RebindIt_Thiscall_Inferred.md`

## Callers / callees

| Direction | Symbol | VA / notes |
|---|---|---|
| Caller | `CVOGReaction_FailMissionNotify` | `0x004149d0` — push_back slow path |
| Callee | `FUN_004073a0` / `StdVector_InsertN_Dword_Inferred` | insert-N engine, count=1 |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ raw ≡ live | **High** |
| Element stride 4; index-before-realloc rebind | **Confirmed** (bytes) |
| `ret 0x0C` / three stack formals + thiscall ECX | **Confirmed** |
| Callee role insert-N | **High** (dual `aa_004073a0`) |
| Product STL mangled name | **Open** (`_Inferred`) |
| Types beyond dword bag | **Tentative** (multi-domain) |
