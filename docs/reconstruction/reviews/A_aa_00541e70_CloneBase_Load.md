# Review A (reconstruction fidelity): `aa_00541e70` CloneBase_Load

| Field | Value |
|---|---|
| **Stable ID** | `aa_00541e70` |
| **VA** | `0x00541e70`–`0x00542757` |
| **Canonical name** | `CloneBase_Load` |
| **Ghidra name** | `FUN_00541e70` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — W24-N) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00541e70_CloneBase_Load.md` |
| **System** | client-content / clonebase / gamedata |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Client **CloneBase load** for content host:

1. Create four host CNDHash tables (`+0xF10`, `+0xF14`, `+0xF0C`, `+0xEF0`).
2. First-process-time global config/name/removed-objects init.
3. `CloneBase_LoadWadFile` (throw on fail).
4. Materialize clone-object array (stride `0x114`) and map modules (stride `0x154`).
5. Optional RegionMissions (`+0xF18`), TypeDef hash (`+0xF1C`) + reload, LoadSkillsFX + SpecialFXMaster.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ W24-N append) | `raw/aa_00541e70_FUN_00541e70.md` |
| Annotated | `raw/aa_00541e70_FUN_00541e70.annotated.md` |
| Clean | `reconstructed-exact/CloneBase_Load.cpp` |
| Alias clean | `reconstructed-exact/FUN_00541e70.cpp` |
| Function record | `functions/aa_00541e70_FUN_00541e70.md` |
| Live decompile | Ghidra @ `0x00541e70` |
| Bytes | entry `push ebp; mov ebp,ecx path`; exit `ret 0x0C` |
| Caller | `FUN_00542aa0` decompile + call site bytes |
| Nested duals | `CloneBase_LoadWadFile`, `Client_LoadSkillsFX`, `CVOGRegionMissions_Ctor`, `Client_ReloadTypeDefTable` |

**This pass:** live decompile + `read_memory` + `analyze_function_complete` + xrefs. **Not:** Launcher, `disassemble_bytes`, runtime.

---

## 3. Calling convention (assembly-sealed)

| Slot | Role | Evidence |
|---|---|---|
| **ECX** | content host | entry `mov esi,ecx`; field stores |
| stack ×3 | char flags A/B/C | decompile + caller pushes |
| Return | void | `C2 0C 00` ret 0xC |
| SEH | `LAB_009a40ca` | FS frame |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Name CloneBase_Load | **High** | start/end logs |
| thiscall + ret 0xC | **High** | exit bytes |
| Hash offsets F10/F14/F0C/EF0 | **High** | stores after ctors |
| Phase order | **High** | log sequence |
| Strides 0x114 / 0x154 | **High** | div in decompile |
| LoadSkillsFX call | **High** | dual aa_00541aa0 |
| Flag product English | **Open** | gates only |
| Full nested dual coverage | **Open** | many callees not OWN |
| Runtime / bit-exact | **Open** | deferred |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| CreateInstance + throw | Yes |
| Four hashes | Yes |
| First-time global block | Yes |
| LoadWadFile throw | Yes |
| Name list vs hash traverse | Yes |
| Array + type switch + loot | Yes |
| Map module buckets | Yes |
| RegionMissions / TypeDef | Yes |
| LoadSkillsFX + SFX master | Yes |
| CloneBase: end + ret 0xC | Yes |

---

## 6. Callers / callees

**Caller (1):** `FUN_00542aa0` @ `0x00542bf9` — only when `param_5==0`.

**Callees:** see function record (40+ including sealed `CloneBase_LoadWadFile`, `Client_LoadSkillsFX`, `FUN_0060b870`, `FUN_00541950`).

---

## 7. Gaps

1. Product English for three bool flags (roles inferred from gates).
2. Full layout of 0x114 clone records / 0x154 map records.
3. Dual seals for nested COM/hash helpers (not OWN this wave).
4. Exception unwind paths that `operator_delete` vectors (decompiler non-return edges).
5. Runtime golden for flag matrix.

**Verdict:** **accept-with-gaps** — CF/ABI/role/phase order High; residual is flag naming + nested duals + runtime.
