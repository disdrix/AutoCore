# Function record: RefCountedPtr_DefaultCtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096ef70` |
| **Canonical name** | `RefCountedPtr_DefaultCtor_Inferred` |
| **Prior / Ghidra name** | `FUN_0096ef70` |
| **Address** | `0x0096ef70`–`0x0096ef78` (**9 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared util — refcounted handle default ctor |
| **Completion status** | **accept** — dual A/B sealed 2026-07-29 (W25-N OWN) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- `FUN_0096ef70`
- Prior auto: `Named_CalleeOf_CVOGTacArc_ctor_0096ef70` (one of many callers; not product role)

## Purpose

**Default-construct** a 4-byte refcounted handle by writing `*this = 0`.

Peer dtor `FUN_0096efd0` (out of OWN) decrements payload refcount and may invoke release — confirming this is null-init of that handle type, not a full object zero.

## Signature (sealed)

```c
// ECX = handle*; no stack args; ret; return this* in EAX
void* RefCountedPtr_DefaultCtor_Inferred(void** self /*ECX*/);
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0096ef70_FUN_0096ef70.md` |
| Annotated | `docs/reconstruction/raw/aa_0096ef70_FUN_0096ef70.annotated.md` |
| Clean (named) | `docs/reconstruction/reconstructed-exact/RefCountedPtr_DefaultCtor_Inferred.cpp` |
| Clean (FUN_*) | `docs/reconstruction/reconstructed-exact/FUN_0096ef70.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_0096ef70_RefCountedPtr_DefaultCtor_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0096ef70_RefCountedPtr_DefaultCtor_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_0096ef70_FUN_0096ef70.md` |

## Callers / callees

| Direction | Symbol | VA / notes |
|---|---|---|
| Callee | *(none)* | pure store |
| Peer dtor | `FUN_0096efd0` | `0x0096efd0` (not owned) |
| Callers | ~62 sites | TacArc, paint, graphics, assets, UI |

## Confidence

| Claim | Level |
|---|---|
| CF: `*this = 0` | **High** |
| ECX this / return this | **High** |
| Refcounted-handle role | **High** (peer dtor) |
| Product type English | **Inferred** |
| Runtime / bit-exact | **Open** |
