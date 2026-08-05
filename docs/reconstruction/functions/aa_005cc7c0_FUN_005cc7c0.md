# Function record: `aa_005cc7c0` EntityHost_ApplyNestedLocalPosition_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005cc7c0` |
| **Canonical name (Ghidra)** | `FUN_005cc7c0` |
| **Proposed name** | `EntityHost_ApplyNestedLocalPosition_Inferred` (**Probable**) |
| **Address** | `0x005cc7c0` |
| **Body span** | `0x005cc7c0` – `0x005cc7e7` (40 bytes; `ret 8`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `input-drive-control` / object pose (host → nested) |
| **Completion status** | **Partial** — dual A/B sealed 2026-07-29 W23-J; product name / arg2 / runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual reviews** | `reviews/A_aa_005cc7c0_EntityHost_ApplyNestedLocalPosition_Inferred.md`, `reviews/B_aa_005cc7c0_EntityHost_ApplyNestedLocalPosition_Inferred.md` |

## Purpose

Virtual host method that applies a **local float4 position** to the nested object at **`host+0x64`**:

1. `FUN_0053d970(nested, 0)` — physics/body prep (stack formal **0**).
2. `*(u8*)(nested + 0x304) = 1` — dirty / recompute flag (byte).
3. `FUN_004c3a40(nested, vec)` — gated local-position store (`+0x240..+0x24c`).

## Signature (sealed)

```c
void __thiscall FUN_005cc7c0(void *host, float *localPos4 /*, unread stack arg */);
// ABI: ECX=host, stack 8 bytes cleaned (ret 8); body uses only first stack dword as vec
```

## Control flow (sealed)

```
object = *(host + 0x64)
FUN_0053d970(object, 0)          // thiscall + stack 0; callee ret 4
*(u8*)(object + 0x304) = 1
FUN_004c3a40(object, localPos4)  // thiscall; ret 4
ret 8
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005cc7c0_FUN_005cc7c0.md` (authoritative + W23-J append)
- Annotated: `docs/reconstruction/raw/aa_005cc7c0_FUN_005cc7c0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_005cc7c0.cpp`
- Named clean: `docs/reconstruction/reconstructed-exact/EntityHost_ApplyNestedLocalPosition_Inferred.cpp`
- Dual A/B: `docs/reconstruction/reviews/A_aa_005cc7c0_*.md`, `B_aa_005cc7c0_*.md`

## Dispatch / xrefs (2026-07-29)

| Kind | Sites |
|------|-------|
| DATA vtable | `0x009da9d0`, `0x009daf58`, `0x009db0d8`, `0x009db138`, `0x009db198` |
| CALL | none recovered |

## Callees

| Callee | Role |
|--------|------|
| `FUN_0053d970` @ `0x0053d970` | Nested phys/body prep; `ret 4`; stack formal from this unit always `0` |
| `FUN_004c3a40` @ `0x004c3a40` | `CVOGObject_SetLocalPosition4_Gated_Inferred` |

## Confidence

| Claim | Level |
|---|---|
| Body span / `ret 8` / order of three steps | **High** (`read_memory` + decompile) |
| Nested object at `host+0x64` | **High** |
| Dirty byte at nested `+0x304` | **High** |
| Vtable DATA dispatch (5 slots) | **High** |
| Proposed English name | **Probable** (`_Inferred`) |
| Unread arg2 meaning | **Open** |
| Runtime / differential | **Open** |
