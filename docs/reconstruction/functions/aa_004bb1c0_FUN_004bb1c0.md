# Function record: FUN_004bb1c0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bb1c0` |
| **Canonical name** | `FUN_004bb1c0` (scaffold) |
| **Sealed name** | `Object_ResolveCoidVtbl1e8_Inferred` |
| **Address** | `0x004bb1c0`–`0x004bb1e9` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object-resolve / TFID (cross-cutting client) |
| **Completion status** | **Sealed** — dual A/B 2026-07-29 W18-T; see named record |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual verdict** | **accept-with-gaps** |

## Alias

Human name: `Object_ResolveCoidVtbl1e8_Inferred` (free-arg resolve + `vtbl+0x1e8`)

## Alias_prev

Human name: `Named_CalleeOf_Client_UpdateNpcInteractIcons_004bb1c0`

## Purpose

Resolve `(bGlobal, coidLo, coidHi)` via `CVOGReaction_ResolveObjectTarget`, then return `obj->vtbl[+0x1e8]()` (or 0). See named record for full seal.

## Signature (sealed)

```c
// ECX = resolve ctx; stack bGlobal, coidLo, coidHi; RET 0xC
void * __thiscall FUN_004bb1c0(void *ctx, uint32_t bGlobal, uint32_t coidLo, uint32_t coidHi);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004bb1c0_FUN_004bb1c0.md`
- Annotated: `docs/reconstruction/raw/aa_004bb1c0_FUN_004bb1c0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Object_ResolveCoidVtbl1e8_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_004bb1c0.cpp`
- Named record: `docs/reconstruction/functions/aa_004bb1c0_Object_ResolveCoidVtbl1e8_Inferred.md`
- Review A/B: `docs/reconstruction/reviews/A_aa_004bb1c0_Object_ResolveCoidVtbl1e8_Inferred.md` / `B_…`

## Callers / callees

See named record (9 callers; sole direct callee `CVOGReaction_ResolveObjectTarget`).

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + bytes | **High** |
| ECX passthrough + RET 0xC | **High** |
| Slot `+0x1e8` | **High** |
| Product name of virtual | **Tentative** |
