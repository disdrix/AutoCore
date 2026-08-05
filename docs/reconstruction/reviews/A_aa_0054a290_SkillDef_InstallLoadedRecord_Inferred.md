# Review A (reconstruction fidelity): `aa_0054a290` SkillDef_InstallLoadedRecord

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054a290` |
| **VA** | `0x0054a290`–`0x0054a631` |
| **Canonical name** | `SkillDef_InstallLoadedRecord` (INFERRED; Ghidra `FUN_0054a290`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (skill-def install worker) |
| **Counterpart** | `reviews/B_aa_0054a290_SkillDef_InstallLoadedRecord_Inferred.md` |
| **System** | `skills-abilities` |
| **Parent chain** | `ResolveSkillTargets` → `SkillDefMap_EnsureInitialized` (stride-`0x934` loop) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Install one loaded skill-definition blob** (`param_1`, stride **`0x934`** from parent loop) into client skill maps / runtime templates.

Early-out if element count short at **`param_1 + 0x24b*4`** (short at dword index `0x24b`) is **0** → logs  
`"Skill %d had no skill elements - it won't work."` via `FUN_007a4480` and returns (no install).

Otherwise:

1. SEH frame; `FUN_0054cc10()` prep.
2. Zero a large staging block (`0x14e` dwords).
3. Map skill-class / flags from blob fields (`param_1+0x242` class byte → flag bits; optional bits from `+0x240/+0x241`).
4. Copy numeric fields (`0x246..0x24a`) into staging; set `local_11a3 = 1`.
5. `FUN_005495f0` + `FUN_0054d9a0` map probe; insert or overwrite (`FUN_0054e9a0` / in-place copy `0x14e` dwords to `node+0x10`).
6. Locale/string materialize via `PTR_FUN_00af8c9c` + `FUN_00403450` on three string slots.
7. **`Skill_InitializeRuntimeObject`** with packed skill-id / rank / flag args from blob.
8. Free any heap-expanded string buffers; **`SkillDefMap_ExactFindByIntKey` (`00418890`)**; on hit copy `0x18c` dwords from `node+0x10` and **`Skill_CopyRuntimeFieldsFromTemplate`**; on miss insert via `FUN_0054ea60`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw / annotated / clean | `raw/aa_0054a290_*`, `reconstructed-exact/FUN_0054a290.cpp` |
| Function record | `functions/aa_0054a290_FUN_0054a290.md` |
| Live Ghidra | `batch_decompile` / `get_function_by_address` / callers |
| String | `"Skill %d had no skill elements - it won't work."` |
| Parent dual | `A_aa_0054b2c0_SkillDefMap_EnsureInitialized` (install loop) |
| Map find dual | `A_aa_00418890_SkillDefMap_ExactFindByIntKey` |

---

## 3. Signature (sealed shape)

```c
// __cdecl-ish large frame; skill blob pointer on stack
void SkillDef_InstallLoadedRecord(SkillDefBlob *param_1);
// *param_1 = skill id (used in log + key)
// short at param_1+0x92C area (index 0x24b dwords) = skill-element count gate
```

| Gate | Behavior |
|---|---|
| element-count short == 0 | log + return (no maps mutated by install path) |
| else | full flag pack + dual map update + runtime init |

---

## 4. Control flow: sealed skeleton

```
if (*(short*)(param_1 + 0x24b) == 0):
    NDError_Log("Skill %d had no skill elements...", *param_1)
    return
FUN_0054cc10()
zero staging[0x14e]
pack flags from class byte + optional bits
FUN_005495f0(param_1, staging)
FUN_0054d9a0(outIt, param_1)
if outIt == end(DAT_00b0472c): insert new row
else: memcpy node+0x10 <- staging (0x14e dwords)
materialize 3 strings; Skill_InitializeRuntimeObject(...)
ExactFind(00418890) on skill id
if hit: copy 0x18c dwords; Skill_CopyRuntimeFieldsFromTemplate
else: insert via FUN_0054ea60
```

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Empty-elements early-out + string | **Confirmed** | decompile + string xref |
| Called from EnsureInitialized load loop | **Confirmed** | callers + parent dual |
| Also called from `FUN_00517400` | **Confirmed** | second caller |
| Uses ExactFind `00418890` | **Confirmed** | end of body |
| Staging sizes `0x14e` / runtime `0x18c` dwords | **Confirmed** | copy loops |
| Full field→flag product enum | **Open** | class 1..5 bits sealed as CF only |
| Product name | **Open** | structural |

---

## 6. Gaps

1. Exact meaning of class values 1–5 and bits `0x10/8/0x40` / `local_11b4|1`.
2. Roles of `FUN_0054cc10`, `FUN_005495f0`, `FUN_0054d9a0`, `FUN_0054e9a0`, `FUN_0054ea60` (nested residual).
3. Full `Skill_InitializeRuntimeObject` arg product names.
4. Runtime / bit-exact open.

**Verdict:** **accept-with-gaps**
