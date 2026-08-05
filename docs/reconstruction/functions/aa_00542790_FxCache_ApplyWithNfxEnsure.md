# Function record: FxCache_ApplyWithNfxEnsure

| Field | Value |
|---|---|
| **Stable ID** | `aa_00542790` |
| **Canonical name** | `FxCache_ApplyWithNfxEnsure` (**INFERRED** structural) |
| **Ghidra name** | `FUN_00542790` |
| **Address** | `0x00542790` |
| **Body span** | `00542790`–`00542a8c` (**764 bytes**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `client-fx` / skills-abilities |
| **Completion status** | **Dual A/B sealed** (W20-I 2026-07-29) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

| Name | Notes |
|---|---|
| `FUN_00542790` | Ghidra / scaffold |
| `Named_nfx` | prior plate from `_nfx.xml` string |
| `Named_CalleeOf_Named_VOG_DEBUG_STOP_00542790` | prior auto alias |
| `FxCache_ApplyWithNfxEnsure` | structural dual name |

## Purpose

Full **apply / attach** path for a skill/FX cache key when the resource subsystem is enabled:

1. Gate `*(DAT_00d1f050+0x6c) != 0`.
2. Snapshot transforms from `source+0x160` / `target+0x160` or `DAT_009d00a8`.
3. `CNDHash_LookupByKey(*(this+0xf0c), key)`.
4. If master flag clear: SkillDef name → append `_nfx.xml` → path open → strip suffix → `FxMaster_LoadMasterFromXML`.
5. Resource open → `FUN_004a16d0` → entity `vtbl[+0x238]` apply, else transform fallback `FUN_00545d70`.
6. Return **1** / **0**.

## Signature (sealed)

```c
uint32_t __thiscall FxCache_ApplyWithNfxEnsure(
    void *host,           // ECX; hash @ +0xf0c
    uint32_t key,         // +0x04
    uint32_t eventId,     // +0x08
    uint32_t argA,        // +0x0c
    uint32_t argB,        // +0x10
    void *sourceObj,      // +0x14  optional +0x160 xform
    int *targetEntity,    // +0x18  optional vtbl+0x238
    uint32_t argC);       // +0x1c
// ret 0x1c
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00542790_FUN_00542790.md`
- Annotated: `docs/reconstruction/raw/aa_00542790_FUN_00542790.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FxCache_ApplyWithNfxEnsure.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00542790.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00542790_FxCache_ApplyWithNfxEnsure.md`
- Review B: `docs/reconstruction/reviews/B_aa_00542790_FxCache_ApplyWithNfxEnsure.md`

## Callers / callees

**Callers:** `FUN_00512d10` (`0x00512d10`), `FUN_005c74e0` (`CLoadNode::_initSpecialFX` plate) (`0x005c74e0`).

**Callees:** `CNDHash_LookupByKey`, `SkillDefMap_GetGlobal`, `SkillDefMap_ExactFindByIntKey`, `FUN_00540090`, `FUN_00989e00`, `FUN_0043d670`, `FUN_004ed310`, `strstr`, `FxMaster_LoadMasterFromXML`, `FUN_00971820`, `FUN_0043d650`, `FUN_004a04f0`, `FUN_004a16d0`, `FUN_00545d70`, `FUN_005b2ba0`.

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ live | **Confirmed** |
| SEH + `ret 0x1c` / 7 stack args | **Confirmed** (bytes) |
| Gate + `_nfx.xml` string + default pose | **Confirmed** |
| vtbl `+0x238` apply | **Confirmed** (decompile) |
| Product English / method names | **Open** |
| Runtime / bit-exact | **Open** |
