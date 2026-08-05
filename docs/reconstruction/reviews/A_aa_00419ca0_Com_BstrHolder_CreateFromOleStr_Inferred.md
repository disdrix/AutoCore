# Review A (reconstruction fidelity): `aa_00419ca0` Com_BstrHolder_CreateFromOleStr_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00419ca0` |
| **VA** | `0x00419ca0` |
| **Canonical name** | `Com_BstrHolder_CreateFromOleStr_Inferred` |
| **Ghidra name** | `FUN_00419ca0` |
| **Prior alias** | `Named_CalleeOf_Mission_bActiveObjectiveOverride_00419ca0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path A — fidelity (OWN-ONLY dual; Skill_DbLoadSkillsCharacters nested) |
| **Counterpart** | `reviews/B_aa_00419ca0_Com_BstrHolder_CreateFromOleStr_Inferred.md` |
| **System** | `crt-com` / MSVC BSTR smart-holder |
| **Live tools** | Ghidra `batch_decompile`, `read_memory`, callers/callees |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Construct a **12-byte (`0xC`) BSTR holder** from wide string in **EDI**, store the holder pointer into `*param_1`, return `param_1`.

Layout of new object:

| Offset | Init | Role |
|---|---|---|
| `+0x00` | `SysAllocString(EDI)` | BSTR |
| `+0x04` | `0` | secondary / buffer slot |
| `+0x08` | `1` | refcount |

On OOM (`operator_new` null, or `SysAllocString` null while `EDI != null`): `_com_issue_error(0x8007000E)` (`E_OUTOFMEMORY`).

Release sibling is `FUN_00419e20` (`InterlockedDecrement` + `SysFreeString` + `operator_delete`) — used by `0x00419ed0` when releasing the optional second arg.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_00419ca0_*`, `reconstructed-exact/FUN_00419ca0.cpp` |
| Function record | `functions/aa_00419ca0_FUN_00419ca0.md` |
| Live decompile | ≡ raw body |
| Live bytes | `read_memory` @ `0x00419ca0` … through `ret 4` at end |
| COM error | `_com_issue_error` dual `aa_00717f00`; imm `push 0x8007000E` |
| Parent | `Skill_DbLoadSkillsCharacters` `0x007e34b0` (xpath / field-name path) |

---

## 3. Control flow (clean ≡ raw ≡ live)

```text
Com_BstrHolder_CreateFromOleStr(out_holder**, edi=OLECHAR*):
  SEH frame (LAB_009bc02b)
  p = operator_new(0xC)
  if p:
    p[1] = 0; p[2] = 1
    bstr = SysAllocString(edi)
    *p = bstr
    if bstr==0 && edi!=0: _com_issue_error(E_OUTOFMEMORY)
  else p = 0
  *out_holder = p
  if p==0: _com_issue_error(E_OUTOFMEMORY)
  return out_holder
```

### Epilog seal (`read_memory` near `0x00419d20`)

```text
… 8B4C2408  mov ecx,[esp+8]
   5E        pop esi
   8BC5      mov eax,ebp          ; return param_1
   64 890D…  restore FS:[0]
   5D        pop ebp
   83C40C    add esp,0xC          ; tear SEH / locals
   C20400    ret 4                ; __stdcall 1 stack arg
```

| Claim | Conf |
|---|---|
| Alloc size **0xC** | **High** (`push 0xC` / `operator_new`) |
| Refcount init **1** at `+8` | **High** |
| `SysAllocString` from **EDI** | **High** (decompiler `unaff_EDI`; IAT call) |
| OOM HR **`0x8007000E`** | **High** (imm push before `_com_issue_error`) |
| `ret 4` / out-param style | **High** |
| EDI formal name = product “source OLESTR” | **High** behavioral; register-pass is MSVC this/reg convention residue |

---

## 4. Nesting provenance (skill path)

```
Skill_DbLoadSkillsCharacters 0x007e34b0
  └─ (DAT_00d1793c != 0 WAD/XML branch)
       SysAllocString(L"//vSkillsCharacters/row")
       FUN_00419ca0()  ← this unit wraps wide xpath into holder
       FUN_00419ed0()  ← consumes holder / COM method
```

Also used by many other DB/WAD loaders (`007b*` / `007c*`, `DB_ReadPowerPlantSpecific`).

---

## 5. Gaps

1. Exact product type name (`_bstr_t` vs custom holder) — layout matches common MSVC COM BSTR wrapper, not sealed as CRT symbol.
2. Whether `+4` secondary slot is ever non-zero from this ctor (always 0 here).
3. Full SEH unwind map for partial construct.

**Verdict:** **accept-with-gaps**
