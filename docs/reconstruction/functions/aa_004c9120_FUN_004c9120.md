# Function record: Object_CacheAIProfileFields_TypeMask_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c9120` |
| **Canonical name** | `Object_CacheAIProfileFields_TypeMask_Inferred` |
| **Ghidra name** | `FUN_004c9120` |
| **Address** | `0x004c9120`–`0x004c92e3` (**452 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | Host AI profile / object cache |
| **Completion status** | **Reviewed** — dual A/B accept W27-H (2026-07-29) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Ghidra: `FUN_004c9120`
- Inferred structural name from sealed map helpers + profile field cache behavior (no plate on this VA).

## Purpose

Mid-object method: init related subobject, copy AI profile fields from MI-resolved `+0x3c` block into object cache slots, lookup profile key in host AI profile map, store type bitmask on hit.

## Signature (sealed)

```c
// thiscall/fastcall; ECX = this; void
void __fastcall FUN_004c9120(int param_1);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004c9120_FUN_004c9120.md` (+ W27-H append)
- Annotated: `docs/reconstruction/raw/aa_004c9120_FUN_004c9120.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Object_CacheAIProfileFields_TypeMask_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004c9120.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004c9120_Object_CacheAIProfileFields_TypeMask_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_004c9120_Object_CacheAIProfileFields_TypeMask_Inferred.md`

## Callers / callees

| Direction | Symbols |
|---|---|
| Entry thunks (2) | `0x004ccec0` (vtbl `0x009cbb80`), `0x0053baa0` (vtbl `0x009cfaa0`) — adjustor JMP |
| Callees | `FUN_005c8eb0`, `Host_AIProfileMap_GetOrReset` (`FUN_00540890`)×2, `Map_LowerBoundFindByIntKey_Isnil65` (`FUN_004cbd50`) |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ live ≡ bytes | **High** |
| thiscall ECX + 452 B + void RET | **High** |
| Field offset table | **High** |
| Map pair semantics (via W26-N/O) | **High** |
| MI thunk entry | **High** (bytes + DATA xrefs) |
| Product field English | **Tentative** |
| `FUN_005c8eb0` full semantics | **Tentative** (not OWN) |
