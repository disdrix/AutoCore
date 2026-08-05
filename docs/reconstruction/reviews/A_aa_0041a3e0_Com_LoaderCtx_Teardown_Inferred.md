# Review A (reconstruction fidelity): `aa_0041a3e0` Com_LoaderCtx_Teardown_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0041a3e0` |
| **VA** | `0x0041a3e0` |
| **Canonical name** | `Com_LoaderCtx_Teardown_Inferred` |
| **Ghidra name** | `FUN_0041a3e0` |
| **Prior alias** | `Named_CalleeOf_Mission_bActiveObjectiveOverride_0041a3e0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path A — fidelity (OWN-ONLY dual; Skill_DbLoadSkillsCharacters nested) |
| **Counterpart** | `reviews/B_aa_0041a3e0_Com_LoaderCtx_Teardown_Inferred.md` |
| **System** | `crt-com` / DB-WAD loader context dtor path |
| **Live tools** | Ghidra `batch_decompile`, `read_memory`, callees |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Teardown** for a COM/DB loader context object (`param_1`):

1. SEH frame (`LAB_009bd84a`).
2. Slot = `param_1 ? param_1+0x24 : null`.
3. `FUN_00423170()` — release / unbind associated COM state (uses register context; not fully typed here).
4. `iface = *slot`; if non-null → `iface->Release()` via **vtbl+8**.
5. `FUN_0041a8e0(param_1)` — deeper field teardown (COM at `+0x10`/`+0x14`, optional delete under `+0xC`).
6. `ret 4` — `__stdcall` one stack arg.

Called on both **success and failure** exits of `Skill_DbLoadSkillsCharacters` after row/cursor work.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_0041a3e0_*`, `reconstructed-exact/FUN_0041a3e0.cpp` |
| Function record | `functions/aa_0041a3e0_FUN_0041a3e0.md` |
| Live bytes | `read_memory` @ `0x0041a3e0` length 96 — full body through `ret 4` |
| Callees | `FUN_00423170`, `FUN_0041a8e0` (vtbl Release inline) |
| Parent | `0x007e34b0` success path + fail path `LAB_007e4db5` |

---

## 3. Assembly-sealed body (`read_memory`)

```text
0041a3e0  SEH prolog (push -1, LAB_009bd84a, FS link)
0041a3f5  push esi / edi
0041a3f7  mov  edi, [esp+0x18]          ; param_1 (after pushes)
0041a3fb  test edi, edi
0041a3fd  mov  [esp+0x10], 0            ; SEH state
0041a404  jz   null_ctx
0041a406  lea  esi, [edi+0x24]          ; &ctx+0x24
0041a409  jmp  have_slot
null_ctx:
0041a40b  xor  esi, esi
have_slot:
0041a40d  call FUN_00423170
0041a412  mov  esi, [esi]               ; *slot
0041a414  test esi, esi
0041a416  jz   no_rel
0041a418  mov  eax, [esi]
0041a41a  push esi
0041a41b  call [eax+8]                  ; Release
no_rel:
0041a41e  push edi
0041a41f  mov  [esp+0x14], -1
0041a427  call FUN_0041a8e0
0041a42c  … restore FS / pop …
0041a43a  ret  4
```

| Claim | Conf |
|---|---|
| Offset **`+0x24`** interface slot | **High** |
| Release via **vtbl+8** | **High** |
| Always calls `0041a8e0(param_1)` after | **High** |
| `ret 4` stdcall | **High** |
| Null param_1 safe (slot=0) | **High** (xor path) |
| Full type of ctx object | **Medium** |

---

## 4. Nested callees (role)

| VA | Role (from decompile, not dualled here) |
|---|---|
| `0x00423170` | Release/unbind path on related COM pair |
| `0x0041a8e0` | Tear `+0x10`/`+0x14` COM, optional `operator_delete` under `+0xC` |

---

## 5. Gaps

1. Product name of loader context struct (ADO command vs XML document wrapper).
2. Exact ESI/EDI register contract into `FUN_00423170` (decompiler `unaff_*` residual).
3. Dual of `0041a8e0` / `00423170` still open (nested residual beyond this batch’s 6).

**Verdict:** **accept-with-gaps**
