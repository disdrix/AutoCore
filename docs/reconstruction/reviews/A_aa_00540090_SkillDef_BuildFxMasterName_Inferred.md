# Review A (reconstruction fidelity): `aa_00540090` SkillDef_BuildFxMasterName_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00540090` |
| **VA** | `0x00540090`–`0x00540282` |
| **Canonical name** | `SkillDef_BuildFxMasterName_Inferred` |
| **Ghidra name** | `FUN_00540090` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — W24-N) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00540090_SkillDef_BuildFxMasterName_Inferred.md` |
| **System** | skills-abilities / client-fx |
| **Dual status** | **Present** |
| **Verdict** | **accept** |

---

## 1. Purpose

Materialize skill FX master basename into caller buffer:

```
skill_ + {h_|m_|c_|n_} + {c_|e_|o_|r_|fixme_} + name[@+0x5a6]
```

from SkillDef payload (typically RB node + 0x10).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ W24-N append) | `raw/aa_00540090_FUN_00540090.md` |
| Annotated | `raw/aa_00540090_FUN_00540090.annotated.md` |
| Clean | `reconstructed-exact/SkillDef_BuildFxMasterName_Inferred.cpp` |
| Alias clean | `reconstructed-exact/FUN_00540090.cpp` |
| Function record | `functions/aa_00540090_FUN_00540090.md` |
| Live decompile | Ghidra @ `0x00540090` |
| Bytes | entry `sub esp,0x400`; exit plain `ret`; caller `add esp,0xC` |
| Strings | `read_memory` @ `0x009d01bc`, `0x009cf9e0` family |
| Related duals | `FxCache_EnsureMasterAndResolve`, `Client_LoadSkillsFX` |

**This pass:** live decompile + `read_memory` + `analyze_function_complete` + xrefs. **Not:** Launcher, `disassemble_bytes`, runtime.

---

## 3. Calling convention (assembly-sealed)

| Slot | Role | Evidence |
|---|---|---|
| stack arg0 | skill payload* | `mov esi,[esp+...]` after `sub esp,0x400` |
| stack arg1 | out buffer | decompile + caller site |
| stack arg2 | capacity | typically `0x400` |
| Return | void | plain `C3` |
| Cleanup | caller | `add esp,0xC` at `0x00540970` |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Seed `"skill_"` | **High** | `read_memory` 0x009d01bc |
| Class tags h/m/c/n from +0x180 | **High** | literals + if ladder |
| Category tags c/e/o/r/fixme from +0x17c | **High** | switch + default |
| Name append from +0x5a6 | **High** | dword bulk + tail |
| cdecl 3-arg | **High** | ret + caller cleanup |
| FX master basename role | **High** | callers → LoadMasterFromXML |
| Product enum English | **Open** | tags only |
| Runtime / bit-exact | **Open** | deferred |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Seed skill_ | Yes |
| Class append ladder | Yes |
| Category switch | Yes |
| Name strcat bulk | Yes |
| strncpy out | Yes |

---

## 6. Callers / callees

**Callees:** `strncpy`

**Callers (3):** `FUN_005408f0` @ `0x00540979`; `FUN_00542790` @ `0x005428f2`; `FUN_005c74e0` @ `0x005c761a`.

Payload base: callers pass **node+0x10**, so name absolute = node+0x5B6 (matches LoadSkillsFX gate field).

---

## 7. Gaps

1. Product English names for class/category enums.
2. Whether strncpy always leaves NUL when name fills cap (retail strncpy semantics).
3. Runtime golden strings for sample skill ids.

**Verdict:** **accept** — CF/ABI/string table/role sealed High; residual is product enum labels only (does not block AutoCore port of the format).
