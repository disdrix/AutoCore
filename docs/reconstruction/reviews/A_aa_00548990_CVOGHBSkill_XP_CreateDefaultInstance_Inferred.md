# Review A (reconstruction fidelity): `aa_00548990` CVOGHBSkill_XP_CreateDefaultInstance_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00548990` |
| **VA** | `0x00548990`–`0x005489e2` |
| **Body** | **83 bytes** (`0x53`) |
| **Canonical name** | `CVOGHBSkill_XP_CreateDefaultInstance_Inferred` |
| **Prior scaffold** | `FUN_00548990` |
| **Review date** | `2026-08-05` (R12-022 dual seal; dual start 2646) |
| **Reviewer role** | Independent reconstruction review (fidelity) |
| **Counterpart** | `reviews/B_aa_00548990_CVOGHBSkill_XP_CreateDefaultInstance_Inferred.md` |
| **System** | skills-abilities / CVOGHBSkill_XP default factory |
| **Parent dual (context)** | `0x0061c590` `CVOGHBSkill_XP_ApplyToTargetList_Inferred` |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_by_address` + `get_function_xrefs` + `get_function_callers` + `get_function_callees` + `get_xrefs_to` + `read_memory`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

**Default-instance factory** for class **`CVOGHBSkill_XP`**:

| Step | Action | Role |
|---|---|---|
| 1 | SEH frame `LAB_009a43fb` | MSVC EH |
| 2 | `operator_new(0x6c0)` | retail XP HB size |
| 3 | null → return **null** | OOM path |
| 4 | `CVOGHBSkillBase_DefaultCtor` (ECX=new) | empty skill-HB shell |
| 5 | `*obj = &PTR_FUN_009d119c` | XP subclass vtbl |
| 6 | return object* | EAX |

Not OnHeartBeat, not ApplyToTargetList, not full cast ctor.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x00548990` |
| Complete analysis | `analyze_function_complete` (xrefs/callees/callers/disasm/vars/completeness) |
| Disasm | `disassemble_function` full body through `RET` |
| Bytes | `read_memory` 96 B @ entry — through `c3` + `cc` pad |
| RTTI | COL `0x00aade00` → type_info `0x00af29ec` → **`.?AVCVOGHBSkill_XP@@`** |
| Vtbl slot | `0x009d11e4` = vtbl+0x48 holds `0x00548990` |
| Parent dual | `A_aa_0061c590_CVOGHBSkill_XP_ApplyToTargetList_Inferred` (same vtbl; slot +0x2C) |
| Base DefaultCtor | `A_aa_00578830_CVOGHBSkillBase_DefaultCtor` (dual sealed; not re-owned) |
| Raw / annotated / clean | `aa_00548990_*`, named + scaffold cpp |

**Not performed:** Launcher, runtime construct, parent ledgers, dual of sibling vtbl slots.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body `00548990`–`005489e2`, 83 B | **Confirmed** | `get_function_by_address` + disasm end `RET` |
| No stack formals / plain `RET` | **Confirmed** | `C3`; no `C2 xx` |
| `operator_new(0x6c0)` | **Confirmed** | `68 c0 06 00 00` + call `00489892` |
| Base = DefaultCtor `00578830` | **Confirmed** | rel32 + `MOV ECX,ESI` |
| Vtbl imm `009d119c` | **Confirmed** | `C7 06 9C 11 9D 00` |
| Class = `CVOGHBSkill_XP` | **Confirmed** | RTTI string on same vtbl as parent dual |
| Sole inbound = DATA vtbl+0x48 | **Confirmed** | callers empty; xref DATA only |
| Method English CreateDefaultInstance | **Inferred** | role; no PDB |
| Decompile ≡ raw CF | **Confirmed** | live re-decompile match |

---

## 4. Control flow: clean ≡ raw ≡ live ≡ bytes

```
SEH setup (LAB_009a43fb)
obj = operator_new(0x6c0)
result = null
if obj != null:
    CVOGHBSkillBase_DefaultCtor(obj)   // thiscall
    *obj = CVOGHBSkill_XP_vtbl         // 009d119c
    result = obj
restore ExceptionList
return result
```

| Stage | Match |
|---|---|
| SEH prolog/epilog | Yes |
| Alloc 0x6c0 | Yes |
| Null short-circuit | Yes (`JZ` skip ctor/vtbl) |
| DefaultCtor + vtbl stamp | Yes |
| Plain `RET` | Yes |
| Decompiler ECX omit | Documented; bytes seal thiscall |

---

## 5. Gaps / open

1. Product/PDB method name for vtbl+0x48.
2. Whether virtual dispatchers pass unused ECX `this`.
3. Dynamic/indirect CALL sites (none as UNCONDITIONAL_CALL).
4. Runtime / bit-exact / differential.

**Verdict:** **accept**
