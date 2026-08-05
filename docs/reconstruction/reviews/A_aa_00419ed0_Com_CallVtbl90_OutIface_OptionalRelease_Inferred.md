# Review A (reconstruction fidelity): `aa_00419ed0` Com_CallVtbl90_OutIface_OptionalRelease_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00419ed0` |
| **VA** | `0x00419ed0` |
| **Canonical name** | `Com_CallVtbl90_OutIface_OptionalRelease_Inferred` |
| **Ghidra name** | `FUN_00419ed0` |
| **Prior alias** | `Named_CalleeOf_Mission_bActiveObjectiveOverride_00419ed0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path A — fidelity (OWN-ONLY dual; Skill_DbLoadSkillsCharacters nested) |
| **Counterpart** | `reviews/B_aa_00419ed0_Com_CallVtbl90_OutIface_OptionalRelease_Inferred.md` |
| **System** | `crt-com` / XML-or-ADO method bridge |
| **Live tools** | Ghidra `batch_decompile`, `read_memory`, callees of `0x007e34b0` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

COM bridge helper:

1. **This** in **EDI** (object whose vtable is at `*[EDI]`).
2. Stack `param_1` = out location for resulting interface pointer.
3. Stack `param_2` = optional arg object (often BSTR holder from `0x00419ca0`); if non-null, first field `*param_2` is pushed as the method’s second arg.
4. Calls **`vtbl[+0x90]`** as `hr = method(this=EDI, arg2, &out)`.
5. On `hr < 0`: `_com_issue_errorex(hr, EDI, &IID_DAT_00a86128)`.
6. Stores `out` into `*param_1`.
7. If `param_2 != 0`: `FUN_00419e20()` release (holder refcount).
8. Returns `param_1`.

Ghidra decompiler mislabels the call as `QueryInterface` / `IID` — **bytes prove `call [ecx+0x90]`**, not vtbl+0.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_00419ed0_*`, `reconstructed-exact/FUN_00419ed0.cpp` |
| Function record | `functions/aa_00419ed0_FUN_00419ed0.md` |
| Live bytes | `read_memory` @ `0x00419ed0` + epilog @ `0x00419f40` |
| Error IID blob | `read_memory` @ `0x00a86128` → `{2933BF80-7B36-11D2-B20E-00C04F983E60}` |
| Release | `FUN_00419e20` (holder Release) |
| Parent skill | `0x007e34b0` after xpath holder create |

---

## 3. Assembly seal (core call)

```text
; esi = param_2; edi = this
test esi, esi
jz   arg_null
mov  eax, [esi]          ; *param_2 (e.g. BSTR inside holder)
jmp  have_arg
arg_null:
xor  eax, eax
have_arg:
mov  ecx, [edi]          ; vtbl
lea  edx, [esp+local_out]
push edx                 ; &out
push eax                 ; method arg2
push edi                 ; this
call dword ptr [ecx+0x90]
test eax, eax
jge  ok
push 0x00a86128          ; IID for errorex
push edi
push eax                 ; hr
call _com_issue_errorex
ok:
mov  [ebp], out          ; *param_1 = out
test esi, esi
jz   skip_rel
call FUN_00419e20        ; release param_2 holder
skip_rel:
… SEH restore …
ret  8                   ; __stdcall 2 stack args
```

Epilog (`read_memory` @ `0x00419f40`): `add esp,0xC` / `ret 8`.

| Claim | Conf |
|---|---|
| Method slot **`+0x90`** | **High** |
| Optional `*param_2` as arg2 | **High** |
| Fail → `_com_issue_errorex` + fixed IID | **High** |
| Optional release of param_2 via `00419e20` | **High** |
| `ret 8` | **High** |
| Product interface name for IID | **Medium** (MS family GUID pattern; not library-named in Ghidra) |
| Decompiler “QueryInterface” label | **Rejected** |

---

## 4. Nesting provenance

```
Skill_DbLoadSkillsCharacters 0x007e34b0  (WAD branch)
  SysAllocString(L"//vSkillsCharacters/row")
  FUN_00419ca0  → BSTR holder
  FUN_00419ed0  → vtbl+0x90 on document/root → row collection iface
  … column SysAllocString + FUN_007b8a60 field gets …
```

Same pair appears in many `007c*` table loaders (shared COM/XML open pattern).

---

## 5. Gaps

1. Exact COM interface + method name at vtbl+0x90 (selectNodes / get_item / custom).
2. Confirmed IID product name for `DAT_00a86128`.
3. Whether EDI is always the same interface across skill vs mission loaders.

**Verdict:** **accept-with-gaps**
