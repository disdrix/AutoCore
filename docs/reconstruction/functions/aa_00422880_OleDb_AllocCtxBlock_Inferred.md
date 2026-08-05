# Function record: OleDb_AllocCtxBlock_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00422880` |
| **Canonical name** | `OleDb_AllocCtxBlock_Inferred` |
| **Prior / Ghidra name** | `FUN_00422880` |
| **Address** | `0x00422880`–`0x004228c7` (Ghidra body **72 B**); logical `ret 8` via `FUN_004228d1` @ `0x004228d1` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `COM` / OLE DB ctx gate alloc |
| **Completion status** | **accept** — dual A/B sealed 2026-07-29 (W24-B OWN) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- `FUN_00422880`
- SEH status tail: `FUN_004228d1` (not a separate product API)

## Purpose

Allocate a `count * 8` heap buffer into a two-field block `{ void* buf; int count; }`, with SEH frame, returning **HRESULT** `S_OK` / `E_OUTOFMEMORY`.

Sole live caller is the OLE DB binding builder gate when `*ctx == 0` (`push 1; push ctx`).

## Signature (sealed)

```c
// __stdcall; ret 8; EAX = HRESULT
int32_t OleDb_AllocCtxBlock_Inferred(void** block /* +count at +4 */, int32_t count);
// S_OK=0, E_OUTOFMEMORY=0x8007000E
```

## Layout

| Off | Role |
|---:|---|
| `+0` | `void*` allocated buffer (`count * 8` bytes) |
| `+4` | `int32` count (written before alloc) |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00422880_FUN_00422880.md` |
| Annotated | `docs/reconstruction/raw/aa_00422880_FUN_00422880.annotated.md` |
| Clean (named) | `docs/reconstruction/reconstructed-exact/OleDb_AllocCtxBlock_Inferred.cpp` |
| Clean (FUN_*) | `docs/reconstruction/reconstructed-exact/FUN_00422880.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_00422880_OleDb_AllocCtxBlock_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00422880_OleDb_AllocCtxBlock_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00422880_FUN_00422880.md` |

## Callers / callees

| Direction | Symbol | VA / notes |
|---|---|---|
| Callee | `operator_new[]` | `0x00489834` |
| Callee (SEH tail) | `FUN_004228d1` | `0x004228d1` HRESULT epilogue |
| Caller | `OleDb_BuildBindingsAllocRow_Inferred` | `0x0042139b` site `0x00421604` |

## Confidence

| Claim | Level |
|---|---|
| CF: store count, zero, `new[](count*8)`, store, HRESULT | **High** |
| `ret 8` / two stack formals | **High** |
| `S_OK` / `E_OUTOFMEMORY` idiom | **High** |
| Product English plate name | **Inferred** |
| Runtime / bit-exact | **Open** |
