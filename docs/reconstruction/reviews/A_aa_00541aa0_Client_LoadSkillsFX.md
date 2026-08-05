# Review A (reconstruction fidelity): `aa_00541aa0` Client_LoadSkillsFX

| Field | Value |
|---|---|
| **Stable ID** | `aa_00541aa0` |
| **VA** | `0x00541aa0`–`0x00541baf` |
| **Canonical name** | `Client_LoadSkillsFX` |
| **Ghidra name** | `FUN_00541aa0` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — W23-F) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00541aa0_Client_LoadSkillsFX.md` |
| **System** | skills-abilities / client-fx |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**LoadSkillsFX** during CloneBase content load:

1. Get global SkillDefMap (`SkillDefMap_GetGlobal` / `FUN_0054b480`).
2. In-order walk all skill-definition RB nodes (isnil `@+0x641`).
3. If C-string at `node+0x5B6` is **non-empty**:
   - `operator_new(0xC)` SkillFxEntry
   - `FxMasterCatalog_Ctor` at `entry+4` (`FUN_004a1620`)
   - store skill id (`node[3]` / `+0x0C`) at `entry+0`
   - `FUN_00545890(*(host+0xF0C), skillId, entry, 0)` — CNDHash insert

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ W23-F append) | `raw/aa_00541aa0_FUN_00541aa0.md` |
| Annotated | `raw/aa_00541aa0_FUN_00541aa0.annotated.md` |
| Clean | `reconstructed-exact/Client_LoadSkillsFX.cpp` |
| Alias clean | `reconstructed-exact/FUN_00541aa0.cpp` |
| Function record | `functions/aa_00541aa0_FUN_00541aa0.md` |
| Parent | live decompile `FUN_00541e70` (LoadSkillsFX log) |
| Callee duals | `SkillDefMap_GetGlobal`, `FxMasterCatalog_Ctor_Inferred` |

**This pass:** live decompile + `read_memory` + `analyze_function_complete` + parent decompile. **Not:** Launcher, `disassemble_bytes`, runtime.

---

## 3. Calling convention (assembly-sealed)

| Slot | Role | Evidence |
|---|---|---|
| **ECX** | content host `this` | `mov ebp, ecx` |
| host `+0xF0C` | skills FX `CNDHash*` | `mov ecx, [ebp+0xF0C]` before insert |
| Return | void | plain `C3` |
| SEH | `LAB_009a3ff9` | push handler + FS:[0] |

Decompiler `void FUN_00541aa0(void)` **under-states** ABI; bytes restore thiscall.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Name = LoadSkillsFX | **High** | parent log literal |
| SkillDefMap full walk | **High** | GetGlobal + begin/end |
| Non-empty string gate `@+0x5B6` | **High** | strlen-style scan |
| Entry `0xC` = id + catalog@+4 | **High** | new + lea ecx,[edi+4] |
| Hash insert host+0xF0C | **High** | bytes |
| Product English for string field | **Open** | path vs name vs fx key |
| Full SkillDef node layout | **Open** | only used offsets sealed |
| Runtime / bit-exact | **Open** | deferred |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| GetGlobal → begin iterator | Yes |
| String non-empty test | Yes |
| new(0xC) + ctor@+4 + store id | Yes (bytes fix ctor ECX) |
| CNDHash insert flag 0 | Yes |
| Successor isnil+0x641 | Yes |
| Empty map early exit | Yes |

---

## 6. Callers / callees

**Callees:** `FUN_0054b480`, `operator_new`, `FUN_004a1620`, `FUN_00545890`

**Caller (1):** `FUN_00541e70` @ `0x005426d0` — gated by `DAT_00b03e64==0` and `DAT_00b035fc!=0`, sequenced before SpecialFXMaster (`FUN_004a6790`).

---

## 7. Gaps

1. Product meaning of skill-def string at `+0x5B6`.
2. Complete SkillDef node schema beyond used offsets.
3. Dual of `FUN_00545890` CNDHash insert (not OWN).
4. Runtime golden for empty vs non-empty skill strings.

**Verdict:** **accept-with-gaps** — CF/ABI/role sealed High; residual is product field naming + nested hash dual.
