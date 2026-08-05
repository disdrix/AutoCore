# Function record: Object_ResolveCoidVtbl1e8_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bb1c0` |
| **Canonical name** | `Object_ResolveCoidVtbl1e8_Inferred` |
| **Ghidra name** | `FUN_004bb1c0` |
| **Address** | `0x004bb1c0`–`0x004bb1e9` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object-resolve / TFID (cross-cutting client) |
| **Classification** | thin wrapper (resolve + virtual get) |
| **Completion status** | **Sealed** — dual A/B 2026-07-29 W18-T; ABI + CF + vtbl slot sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual verdict** | **accept-with-gaps** |

## Purpose

Resolve a free `(bGlobal, coidLo, coidHi)` triple through `CVOGReaction_ResolveObjectTarget`, then return the result of **`obj->vtbl[+0x1e8]()`**. On resolve failure return **0**. Used by sector player/creator load triggers, NPC interact icons, and character-remove paths.

## Signature (sealed)

```c
// ECX = resolve context (caller-supplied; body does not load it)
// stack bGlobal, coidLo, coidHi; cleaned by RET 0xC
void * __thiscall Object_ResolveCoidVtbl1e8_Inferred(
    void *ctx,
    std::uint32_t bGlobal,
    std::uint32_t coidLo,
    std::uint32_t coidHi);
```

| Param | Location | Meaning |
|---|---|---|
| `ctx` | `ECX` | resolve / reaction host tables (often `host+0xe4e8`) |
| `bGlobal` | `[esp+4]` | global/table select (load triggers pass `0`) |
| `coidLo` | `[esp+8]` | object id low |
| `coidHi` | `[esp+0xC]` | object id high |
| return | `EAX` | `vtbl+0x1e8()` result, or `0` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004bb1c0_FUN_004bb1c0.md`
- Annotated: `docs/reconstruction/raw/aa_004bb1c0_FUN_004bb1c0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Object_ResolveCoidVtbl1e8_Inferred.cpp`
- Scaffold alias: `docs/reconstruction/reconstructed-exact/FUN_004bb1c0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004bb1c0_Object_ResolveCoidVtbl1e8_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_004bb1c0_Object_ResolveCoidVtbl1e8_Inferred.md`
- Report: `docs/agents/task-dual-ab-004bb1c0-004cf120-w18t-report.md`

## Callers / callees

**Callees:** `CVOGReaction_ResolveObjectTarget` (`0x004bae70`); indirect `vtbl+0x1e8`.

**Callers (9):**

- `CVOGSectorMap_DoPlayerOnLoadTrigger` `0x004cdcc0`
- `CVOGSectorMap_DoCreatorLoadTrigger` `0x004cdd20`
- `Client_UpdateNpcInteractIcons` `0x0091b8d0`
- `FUN_004cdc80`
- `FUN_004d9b50` (`CVOGSectorMap_RemoveCharacter_Inferred`)
- `FUN_004dbef0`
- `FUN_004dd940`
- `FUN_005aca60`
- `FUN_005accf0`

**Xrefs:** 12.

**Siblings:** `Object_ResolveFromTFID` `0x004bb950` (no vtbl); `Object_ResolveTfIdVtbl1d4_Inferred` `0x004bb010` (`+0x1d4`, blob); GetIdentity / Lookup at `+0x1d8` / `+0x1dc`.

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + bytes | **High** |
| `RET 0xC` + ECX passthrough ABI | **High** |
| Free triple args (not blob*) | **High** |
| Virtual slot `+0x1e8` | **High** |
| Product name of `+0x1e8` | **Tentative** (`_Inferred`) |
| Return type semantics | **Probable** (pointer-like; callers null-check then use) |
