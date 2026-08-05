# Function record: FxCache_EnsureMasterAndResolve

| Field | Value |
|---|---|
| **Stable ID** | `aa_005408f0` |
| **Canonical name** | `FxCache_EnsureMasterAndResolve` (**INFERRED** structural) |
| **Ghidra name** | `FUN_005408f0` |
| **Address** | `0x005408f0` |
| **Body span** | `005408f0`–`005409b1` (**193 bytes**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `client-fx` / skills-abilities |
| **Completion status** | **Dual A/B sealed** (W20-I 2026-07-29) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

| Name | Notes |
|---|---|
| `FUN_005408f0` | Ghidra / scaffold |
| `Named_CalleeOf_Skill_Skill_d_has_invalid_frequency_d_005408f0` | prior auto alias (caller string) |
| `FxCache_EnsureMasterAndResolve` | structural dual name |

## Purpose

Ensure the FX master catalog for a skill/fx **cache key** is loaded, then resolve an FX handle via `FUN_004a16d0`:

1. Inline **CNDHash** walk on `*(this+0xf0c)` for `key`.
2. Miss → **0**.
3. If `value[+0x0a]==0`: `SkillDefMap_GetGlobal` + `ExactFindByIntKey` → `FUN_00540090` name → `FxMaster_LoadMasterFromXML`.
4. `FUN_004a16d0` with **this = value+4** (bytes); return EAX.

## Signature (sealed)

```c
uint32_t __thiscall FxCache_EnsureMasterAndResolve(
    void *host,       // ECX; CNDHash* @ +0xf0c
    uint32_t key,     // stack+4
    uint32_t eventA,  // stack+8
    uint32_t eventB); // stack+0xc
// ret 0x0c
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005408f0_FUN_005408f0.md`
- Annotated: `docs/reconstruction/raw/aa_005408f0_FUN_005408f0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FxCache_EnsureMasterAndResolve.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_005408f0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_005408f0_FxCache_EnsureMasterAndResolve.md`
- Review B: `docs/reconstruction/reviews/B_aa_005408f0_FxCache_EnsureMasterAndResolve.md`

## Callers / callees

**Callers:** `FUN_00512d10` (`0x00512d10`), `FUN_00578b30` (`0x00578b30`).

**Callees:** `FUN_0054b480` (`SkillDefMap_GetGlobal`), `FUN_00418890` (`SkillDefMap_ExactFindByIntKey`), `FUN_00540090`, `FUN_004a6390` (`FxMaster_LoadMasterFromXML`), `FUN_004a16d0`.

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ live | **Confirmed** |
| `ret 0x0c` / 3 stack args | **Confirmed** (bytes) |
| Hash layout + master flag `+0x0a` | **Confirmed** |
| FUN_004a16d0 this = value+4 | **Confirmed** (exit bytes) |
| Parameter English / product symbol | **Tentative / Open** |
| Types beyond uint32_t widths | **Tentative** |
