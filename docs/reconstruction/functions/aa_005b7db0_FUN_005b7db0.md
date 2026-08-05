# Function record: FUN_005b7db0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b7db0` |
| **Canonical name** | `Elem0x28_DefaultCtor` |
| **Ghidra name** | `FUN_005b7db0` |
| **Address** | `0x005b7db0`–`0x005b7dee` exclusive (**62 B** / `0x3E`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | class / cookie-vector element default ctor (stride 0x28) |
| **Completion status** | Dual sealed W31-L (**accept-with-gaps**) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

| Name | Status |
|---|---|
| `Elem0x28_DefaultCtor` | **canonical** |
| `FUN_005b7db0` | Ghidra / scaffold twin |
| `Named_CalleeOf_Named_VOG_DEBUG_STOP_005b7db0` | **reject** |

## Purpose

Element **default constructor** for **0x28-byte** cookie-vector elements. Zero-initializes buffer triple, list-ptr vector triple, and owned pointer fields that `Elem0x28_CompleteDtor` later frees. Registered solely as the ctor half of `_eh_vector_constructor_iterator_` in `Host_RebuildElem0x28ArrayFromMap_Inferred` (`FUN_004941b0`).

## Signature

```c
// __thiscall; ECX=elem; bare RET; void
// SEH: LAB_009a6ad8 (frame only)
void __thiscall Elem0x28_DefaultCtor(void* elem);
```

| Formal | Source | Conf |
|---|---|---|
| elem | ECX | **High** |
| return | void | **High** |
| stride | **0x28** at registration site | **High** |

## Field writes (sealed)

| Offset | Written | Peer dtor role |
|---|---|---|
| +0x04 / +0x08 / +0x0c | 0 | buffer begin/end/cap |
| +0x14 / +0x18 / +0x1c | 0 | list-ptr vector begin/end/cap |
| +0x24 | 0 | owned pointer |
| +0 / +0x10 / +0x20 | **not written** | not freed by dtor path |

## Call surface

| Direction | Detail |
|---|---|
| Xrefs (1 DATA) | `0x004942db` in `FUN_004941b0` |
| Callers (static code) | none (DATA registration only) |
| Callees | none (leaf) |
| Classification | leaf |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005b7db0_FUN_005b7db0.md`
- Annotated: `docs/reconstruction/raw/aa_005b7db0_FUN_005b7db0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/Elem0x28_DefaultCtor.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_005b7db0.cpp`
- Named record: `docs/reconstruction/functions/aa_005b7db0_Elem0x28_DefaultCtor.md`
- Reviews: `A_aa_005b7db0_Elem0x28_DefaultCtor.md`, `B_aa_005b7db0_Elem0x28_DefaultCtor.md`

## Confidence

| Claim | Level |
|---|---|
| Element default ctor / stride 0x28 | **High** |
| Zero-offsets + ABI/SEH/body size | **High** |
| Pair with `Elem0x28_CompleteDtor` | **High** |
| Product demangle | **Low** (open) |
| Runtime / bit-exact | **Open** |
