# Dual A/B report — W19-G OWN (`aa_006061e0`, `aa_00512070`)

**Date:** 2026-07-29  
**Agent:** W19-G OWN-ONLY  
**Scope:** OWN ONLY VAs `0x006061e0`, `0x00512070`. Dual A/B + three-rep refine.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledgers.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory`. No `disassemble_bytes`.  
**Programs open:** `autoassault.exe` only (dual A/B = fidelity vs adversarial reviews).  
**Image base:** `0x400000`.

---

## Verdicts

| Unit | Canonical name | Verdict |
|------|----------------|---------|
| `aa_006061e0` / `0x006061e0` | `CVOGHBWakeupSkill_ctor` | **accept-with-gaps** |
| `aa_00512070` / `0x00512070` | `CVOGHB_TargetingLink_scalar_dtor_Inferred` | **accept-with-gaps** |

---

## Sealed facts — `0x006061e0` CVOGHBWakeupSkill_ctor

1. **ABI:** HB in **ECX** (`__thiscall`); **8** stack args; **`ret 0x20`**. Body `0x006061e0`–`0x00606353`.
2. **Class:** RTTI **Confirmed** `CVOGHBWakeupSkill` (`".?AVCVOGHBWakeupSkill@@"` @ `0x00af48f0`); vtbl install `PTR_FUN_009de7b4`.
3. **Size:** callers `operator_new(0x674)`.
4. **CF:** `CVOGHBBase_ctor` → vtbl → copy skill blob **`0x18c` dwords → `+0x24`** → seed `+0x654` world / `+0x658` flag byte / TFID vector zero @ `+0x660..+0x668` / `+0x66c` pos / `+0x0C=+0x10=1` / `+0x670` seed / `+0x08=param_2` → `CVOGHBBase_AttachOwnerObject(host)` → walk TFID list until invalid → always append `DAT_009de7a0` `{-1,-1,0,0}`.
5. **Vector:** container base `+0x65c`; element size 16; grow via `FUN_004cbfc0`, in-place via `FUN_00608720`.
6. **Callers:** `Skill_ApplyStatusEffectLocal` @ `0x0051ae04`; `FUN_00514e70` @ `0x00514f7d`.
7. **Cross-unit:** Fire dual `aa_00606180` consumes skill@`+0x24`, world@`+0x654`, flag@`+0x658`, tfid@`+0x660`, pos@`+0x66c`, seed@`+0x670` — field seed map matches.
8. **Three-rep:** raw 2026-07-23 CF ≡ live decompile ≡ entry/epilogue/vtbl/RTTI bytes.

### Gaps

- Product English for `param_2` / full `param_9` beyond Fire skipBusy.
- Named duals of vector helpers `FUN_004cbfc0` / `FUN_00608720`.
- Runtime / bit-exact image diff.

---

## Sealed facts — `0x00512070` CVOGHB_TargetingLink_scalar_dtor_Inferred

1. **ABI:** this in **ECX**; stack `flags` byte; **`ret 4`**. Body `0x00512070`–`0x0051208d`.
2. **Role:** MSVC **scalar-deleting destructor** — `FUN_00512060()` then optional `operator_delete` if `flags & 1`; return this.
3. **Vtbl:** sole DATA xref **`0x009cdfb0` slot 0** (base targeting-link family; ctor dual `CVOGHB_TargetingLink_ctor_Inferred` @ `0x00604d40`).
4. **Complete dtor:** `FUN_00512060` restores vtbl `009cdfb0` + `FUN_00508390` detach.
5. **Twin:** derived `CVOGHBPlayerTargetingLink_scalar_dtor` @ `0x0051b870` (same CF; different vtbl).
6. **CODE callers:** none (virtual only).
7. **Three-rep:** raw ≡ live decompile ≡ body bytes.

### Gaps

- Product RTTI / mangled name for base family.
- Array-deleting dtor presence.
- Runtime / bit-exact image diff.

---

## Dual A/B

| VA | Review A | Review B | Verdict |
|---|---|---|---|
| `0x006061e0` | `reviews/A_aa_006061e0_CVOGHBWakeupSkill_ctor.md` | `reviews/B_aa_006061e0_CVOGHBWakeupSkill_ctor.md` | **accept-with-gaps** |
| `0x00512070` | `reviews/A_aa_00512070_CVOGHB_TargetingLink_scalar_dtor_Inferred.md` | `reviews/B_aa_00512070_CVOGHB_TargetingLink_scalar_dtor_Inferred.md` | **accept-with-gaps** |

---

## Files

### `aa_006061e0` / `CVOGHBWakeupSkill_ctor`

| Kind | Path |
|------|------|
| Review A | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\A_aa_006061e0_CVOGHBWakeupSkill_ctor.md` |
| Review B | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\B_aa_006061e0_CVOGHBWakeupSkill_ctor.md` |
| Function record | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_006061e0_CVOGHBWakeupSkill_ctor.md` |
| Function alias | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_006061e0_FUN_006061e0.md` |
| Clean named | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\CVOGHBWakeupSkill_ctor.cpp` |
| Clean FUN_* | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\FUN_006061e0.cpp` |
| Raw | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_006061e0_FUN_006061e0.md` |
| Annotated | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_006061e0_FUN_006061e0.annotated.md` |

### `aa_00512070` / `CVOGHB_TargetingLink_scalar_dtor_Inferred`

| Kind | Path |
|------|------|
| Review A | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\A_aa_00512070_CVOGHB_TargetingLink_scalar_dtor_Inferred.md` |
| Review B | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reviews\B_aa_00512070_CVOGHB_TargetingLink_scalar_dtor_Inferred.md` |
| Function record | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_00512070_CVOGHB_TargetingLink_scalar_dtor_Inferred.md` |
| Function alias | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\functions\aa_00512070_FUN_00512070.md` |
| Clean named | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\CVOGHB_TargetingLink_scalar_dtor_Inferred.cpp` |
| Clean FUN_* | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\reconstructed-exact\FUN_00512070.cpp` |
| Raw | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_00512070_FUN_00512070.md` |
| Annotated | `C:\Users\josh\Documents\GitHub\AutoCore\docs\reconstruction\raw\aa_00512070_FUN_00512070.annotated.md` |

### This report

`C:\Users\josh\Documents\GitHub\AutoCore\docs\agents\task-dual-ab-own-w19g-006061e0-00512070-report.md`

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x00606180` | `CVOGHBWakeupSkill_Fire_Inferred` (vtbl+0x14; field consumer) |
| `0x0051aa00` | `Skill_ApplyStatusEffectLocal` (ctor caller delay≥1) |
| `0x00514e70` | `Skill_ApplyLocalById_Inferred` (ctor caller) |
| `0x00508200` | `CVOGHBBase_ctor` |
| `0x005083b0` | `CVOGHBBase_AttachOwnerObject` |
| `0x004cbfc0` | TFID vector grow/insert helper |
| `0x00608720` | 16-byte TFID fill helper |
| `0x00604d40` | `CVOGHB_TargetingLink_ctor_Inferred` (installs vtbl of 00512070) |
| `0x00512060` | targeting-link complete dtor body |
| `0x0051b870` | `CVOGHBPlayerTargetingLink_scalar_dtor` (derived twin) |
| `0x00508390` | detach path from complete dtor |
