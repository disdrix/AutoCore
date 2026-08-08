# Review A (reconstruction fidelity): `aa_006226a0` CVOGHBSkill_OnKill_SpawnPerTargetHB_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006226a0` |
| **VA** | `0x006226a0`–`0x006227a7` |
| **Canonical name** | `FUN_006226a0` |
| **Inferred name** | `CVOGHBSkill_OnKill_SpawnPerTargetHB_Inferred` |
| **Review date** | `2026-08-05` (R11-020 OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction fidelity — Path A |
| **Counterpart** | `reviews/B_aa_006226a0_CVOGHBSkill_OnKill_SpawnPerTargetHB_Inferred.md` |
| **System** | skills-abilities |
| **Verdict** | **accept-with-gaps** — RTTI class, vtbl+0x2c, ABI RET0x18, target table, Resolve thiscall, HB construct/enqueue/start sealed; method English open |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` (body, vtbl, COL, type_info string) + xrefs/callers. **No** `disassemble_bytes`. Own VA only. No ledgers. No Launcher.

---

## 1. Purpose

`CVOGHBSkill_OnKill` virtual method at **vtbl+0x2c**: iterate a **0x10-stride** target table, resolve each TFID via the world reaction object, allocate a **0x6c0** skill HB, run **`CVOGHBSkillBase_ctor`** with the resolved target, install the OnKill vtbl, then **Enqueue+Start** (or scalar-delete if ValidateTarget left no owner). Sentinel `(-1,-1,type0)` → **return 1**.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ R11 append) | `docs/reconstruction/raw/aa_006226a0_FUN_006226a0.md` |
| Annotated | `docs/reconstruction/raw/aa_006226a0_FUN_006226a0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBSkill_OnKill_SpawnPerTargetHB_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_006226a0.cpp` |
| Function records | `functions/aa_006226a0_FUN_006226a0.md` + named |
| Live decompile | `decompile_function` `0x006226a0` — **CF ≡** 2026-07-23 raw |
| Live asm | `disassemble_function` — body end `RET 0x18` @ `0x006227a5` |
| RTTI | COL `0x00aae288` → type_info `0x00af1dc8` → `.?AVCVOGHBSkill_OnKill@@` |
| Vtbl slot | `read_memory` `0x009d1710` = `a0 26 62 00` → `0x006226a0` |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| Six stack args | `C2 18 00` @ `0x006227a5` |
| `__thiscall` surface | Virtual slot; ECX set by caller, **unused** in body |
| Return | Always **1** at sentinel (no 0 path) |
| Body span | `0x006226a0`–`0x006227a7` (**0x108** B) |

### 3.2 Target table — **SEALED**

| Field | Off | Sentinel |
|---|----:|---|
| idLo | +0 | -1 |
| idHi | +4 | -1 |
| type (char) | +8 | 0 |
| stride | 0x10 | — |

### 3.3 Resolve + HB pipeline — **SEALED**

| Step | Evidence |
|---|---|
| `ECX = *(world+0xe4e8)` before Resolve | asm `MOV ECX,[EBP+0xe4e8]` |
| `ResolveObjectTarget(type, idLo, idHi)` thiscall | callee `0x004bae70` decompile |
| `operator_new(0x6c0)` | `PUSH 0x6c0` |
| `CVOGHBSkillBase_ctor` this=new | `MOV ECX,ESI` / `CALL 0x005788d0` |
| OnKill vtbl install | `MOV [ESI],0x009d16e4` |
| Owner gate `+0x18` | `CMP [ESI+0x18],0` |
| Enqueue `*(world+0xe4ec)` + Start | `CALL 0x005078f0` / `0x005081c0` |
| Else vtbl[0](1) | `PUSH 1` / `CALL [EDX]` |

### 3.4 Class identity — **SEALED**

| Fact | Evidence |
|---|---|
| Vtbl `PTR_FUN_009d16e4` | COL @ -4 → OnKill type_info string |
| Sibling ctor `FUN_006223c0` | installs same vtbl (not owned) |
| Not a subclass ctor itself | loop + Enqueue; partition parent is base ctor score only |

### 3.5 Three-rep fidelity

| Pass | Match |
|---|---|
| Raw 2026-07-23 | baseline CF |
| Live 2026-08-05 | **CF ≡**; renames + asm fixes |
| Bytes / asm | ret0x18, sizes, offsets, DATA install |

---

## 4. Naming

| Name | Status |
|---|---|
| `CVOGHBSkill_OnKill` (class) | **RTTI Confirmed** |
| `CVOGHBSkill_OnKill_SpawnPerTargetHB_Inferred` | **Structural sealed** + `_Inferred` method English |
| PDB product method symbol | **Open** |

---

## 5. Gaps

1. Product English for the virtual method (OnKill class known).
2. Producer of the 0x10 target table / dispatch site of vtbl+0x2c (virtual only).
3. Why ECX this is unused (stack-complete args).
4. Null-`new` crash path — theoretical only.
5. Runtime / bit-exact / differential — open.

---

## 6. AutoCore port notes

- Port as **OnKill multi-target HB fanout**, not as a free standalone factory without vtbl context.
- Preserve **return 1** only at sentinel; no failure return in this unit.
- Keep Resolve **thiscall** on `world+0xe4e8`; Enqueue list `world+0xe4ec`.
- HB size **0x6c0**; install **OnKill** vtbl after base ctor (same as inlined `FUN_006223c0`).
- Pair with dualed `CVOGHBSkillBase_ctor` (`0x005788d0`) and peer `Skill_HB_SpawnEntities_Execute_Inferred` (different class, same vtbl+0x2c pattern).
