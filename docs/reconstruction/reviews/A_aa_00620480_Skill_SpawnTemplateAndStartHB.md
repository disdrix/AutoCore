# Review A (reconstruction fidelity): `aa_00620480` Skill_SpawnTemplateAndStartHB

| Field | Value |
|---|---|
| **Stable ID** | `aa_00620480` |
| **VA** | `0x00620480`–`0x00620a20` |
| **Canonical name** | `Skill_SpawnTemplateAndStartHB` |
| **Prior scaffold** | `FUN_00620480` / string-seed invalid-template names |
| **Review date** | `2026-07-29` (W19-E OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction fidelity — Path A |
| **Counterpart** | `reviews/B_aa_00620480_Skill_SpawnTemplateAndStartHB.md` |
| **System** | skills / HB action spawn |
| **Verdict** | **accept-with-gaps** — ABI ret0x18, dual spawn arms, HB enqueue/start, floats, DATA install sealed; product English / arg3 open |

**Tools:** Ghidra `decompile_function` + `read_memory` (body + floats + DATA dword + string) + function meta / xrefs / callees. No `disassemble_bytes`. Own VA only. No ledgers. No Launcher.

---

## 1. Purpose

Table-installed skill handler that, when world gate and related object resolve:

1. Samples pose from related object.
2. Spawns a template entity (**direct** `0x690` path if `skillDef+0x22==0`, else **template lookup** `FUN_0058bf50`).
3. Terrain-snaps with **Z + 100.0f**.
4. Ensures up to three skill-tree ids; builds **0x6c0** HB action; Enqueue+Start (or destroy if no owner).
5. Optionally applies effects when `skillDef+0x150` set.

Invalid template → log `"Skill %d had invalid template %d."` + return **0**. Normal completion → return **1**. Gate miss → return **1** (no-op success).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00620480_FUN_00620480.md` (+ 2026-07-29 live) |
| Annotated | `docs/reconstruction/raw/aa_00620480_FUN_00620480.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_SpawnTemplateAndStartHB.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00620480.cpp` |
| Function record | `docs/reconstruction/functions/aa_00620480_Skill_SpawnTemplateAndStartHB.md` |
| Live decompile | `decompile_function` `0x00620480` — **CF ≡** raw |
| Live bytes | body + epilogue `C2 18 00`; floats; DATA `@0x009d1598`; string `@0x009e1c6c` |
| Callees | terrain cast, HB start/enqueue, EnsureLoaded, ApplyEffects, template lookup |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| Six stack args | `C2 18 00` = `ret 0x18` |
| arg0 source | `[ebp+8]` gate + vcall `+0x214` |
| arg1 skillDef | `[ebp+C]` `+0x22`, `+0x14c`, skills, effects |
| arg2 ctx | `[ebp+10]` `+0x7e`, `+0xe4ec` |
| arg4/arg5 | forwarded to `FUN_006202f0` / ApplyEffects |
| Returns | `0` invalid template; `1` success / gate no-op |
| Install | DATA `@0x009d1598` = `80 04 62 00` |

```c
uint32_t Skill_SpawnTemplateAndStartHB(Object*, SkillDef*, WorldCtx*, u32, u32, u32);
```

### 3.2 Dual spawn arms — **SEALED**

| Arm | Gate | Action |
|---|---|---|
| **Direct** | `skillDef+0x22 == 0` | `new(0x690)` + `FUN_004c9aa0(1)` + vcall init(template, ctx, 1) |
| **Template** | else | `FUN_0058bf50`; null → log+`return 0`; else pose apply + spawn `+0x1d8` |

### 3.3 Post-spawn pipeline — **SEALED**

| Step | Evidence |
|---|---|
| clear `entity+0x309` | decomp store 0 |
| terrain Z bias | `fStack_78 + DAT_00aaa7ac` with float **100.0f** |
| `DAT_00aaa688` | **5.0f** loaded into stack block |
| EnsureLoaded ×3 | `+0x154/+0x158/+0x15c` nonzero gates |
| HB `new(0x6c0)` + `FUN_006202f0` | sizes + callee |
| owner null → dtor(1); else Enqueue(`ctx+0xe4ec`)+Start | decomp |
| optional ApplyEffects | `skillDef+0x150` |

### 3.4 Three-rep fidelity

| Pass | Match |
|---|---|
| Raw 2026-07-23 | baseline |
| Live 2026-07-29 | **CF ≡**; cosmetic void*/named ApplyEffects |
| Bytes | ret0x18, sizes 0x690/0x6c0, string, floats, DATA install |

---

## 4. Naming

| Name | Status |
|---|---|
| `Skill_SpawnTemplateAndStartHB` | **Structural sealed** |
| `Skill_Skill_d_had_invalid_template_d*` | **Incomplete** error-string seed |
| PDB product symbol | **Open** |

---

## 5. Gaps

1. Product English for handler table slot / skill class name.
2. Role of unused surface `param_4` / exact `arg5` bitfield.
3. Why both `+0x250` arms call same `FUN_00404c90` in decomp (selector residual).
4. `operator_delete` noreturn warning — decompiler SEH artifact until runtime.
5. Runtime / bit-exact / differential — open.

---

## 6. AutoCore port notes

- Implement as **skill spawn + HB start**, not as a pure logger.
- Preserve **return 1** on gate miss (no-op), **return 0** only on invalid template.
- Keep Z bias **100.0f** on terrain cast unless proven otherwise by live tuning data.
- Dispatch via table pointer, not a hard-coded direct call graph.
