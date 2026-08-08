# Review A (reconstruction fidelity): `aa_0054cbb0` CVOGHBSkill_PossessCreature_DefaultFactory_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054cbb0` |
| **VA** | `0x0054cbb0`–`0x0054cc02` (83 B / `0x53`; pad `CC` → `0x0054cc10`) |
| **Canonical name** | `CVOGHBSkill_PossessCreature_DefaultFactory_Inferred` (Ghidra `FUN_0054cbb0`) |
| **Review date** | `2026-08-05` (OWN-ONLY dual A — R12-023) |
| **Reviewer role** | Independent reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_0054cbb0_CVOGHBSkill_PossessCreature_DefaultFactory_Inferred.md` |
| **System** | skills-abilities |
| **Dual status** | **Present (create / residual seal)** |
| **Dual start** | 2646 |
| **Parent dual** | `0x00626240` `CVOGHBSkill_PossessCreature_ctor` (R11-021) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_xrefs_to` + `get_function_callers` + `read_memory` (body + factory dword + vtbl head). **No** `disassemble_bytes`. Parent dual of full ctor + dualed `CVOGHBSkillBase_DefaultCtor` used for class/size/vtbl only.

---

## 1. Purpose

**Default heap factory** for `CVOGHBSkill_PossessCreature` skill HB objects:

1. SEH frame (`LAB_009a43fb`)
2. `operator_new(0x6f0)`
3. Null → return null
4. `CVOGHBSkillBase_DefaultCtor` (`0x00578830`, thiscall ECX = alloc)
5. Install subclass vtbl **`0x009d1ba4`** (overwrites base vtbl `0x009d3fdc`)
6. Return object*

Does **not** invoke full-arg `CVOGHBSkill_PossessCreature_ctor` (`0x00626240`), does **not** dyn-cast a creature target, does **not** clear subclass tail fields `+0x6c0/6c4/6c8/6c9`.

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_0054cbb0_FUN_0054cbb0.md` | Append R12-023 re-verify |
| Annotated | `docs/reconstruction/raw/aa_0054cbb0_FUN_0054cbb0.annotated.md` | Refined |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBSkill_PossessCreature_DefaultFactory_Inferred.cpp` | New/replace |
| Clean alias | `docs/reconstruction/reconstructed-exact/FUN_0054cbb0.cpp` | Refined |
| Function record | `docs/reconstruction/functions/aa_0054cbb0_CVOGHBSkill_PossessCreature_DefaultFactory_Inferred.md` | New |
| Scaffold record | `docs/reconstruction/functions/aa_0054cbb0_FUN_0054cbb0.md` | Updated |
| Live decompile | Ghidra @ `0x0054cbb0` | ≡ raw CF |
| Live bytes | `read_memory` 96 B body + pad | size/vtbl/ret sealed |
| Xrefs | complete + get_xrefs_to | 0 CALL; 1 DATA @ `0x009d1bec` |
| Parent dual | R11-021 PossessCreature ctor | class RTTI + size + vtbl |
| Base ctor dual | W23-S `CVOGHBSkillBase_DefaultCtor` | callee semantics |

**Not performed:** Launcher, runtime golden, dual of non-OWN vtbl methods / registry, parent ledger edits.

---

## 3. Signature (image-sealed)

```c
// cdecl; no stack args; bare RET; returns object* or null
void *CVOGHBSkill_PossessCreature_DefaultFactory_Inferred(void);
```

| Item | Evidence | Conf |
|---|---|---|
| No this at entry / cdecl | no ECX use before alloc; bare `C3` | **High** |
| 0 stack args | no `RET n`; no stack arg loads | **High** |
| Returns EAX = p or 0 | `mov eax,esi` / zero path | **High** |
| Size `0x6f0` | `push 0x6f0` | **High** |
| Base default ctor | rel → `0x00578830` | **High** |
| Vtbl `0x009d1ba4` | `C7 06 A4 1B 9D 00` | **High** |
| Class name | parent RTTI Confirmed + same vtbl/size | **High** (inherited) |
| Role DefaultFactory | structural (new+default+vtbl; DATA slot) | **Inferred** |
| Not full ctor | no call to `0x00626240`; no cast/fields | **High** |

---

## 4. Byte seal (relative calls / immediates)

| next-IP / site | Target / imm | Meaning |
|---|---|---|
| `0x0054cbc7` | `push 0x6f0` | alloc size |
| `0x0054cbd1` | `operator_new` | heap |
| `0x0054cbeb` | `0x00578830` | `CVOGHBSkillBase_DefaultCtor` |
| `0x0054cbeb` store | `0x009d1ba4` | subclass vtbl |
| `0x0054cc02` | `C3` | bare ret |
| DATA `0x009d1bec` | dword `0x0054cbb0` | factory pointer slot |

---

## 5. Control flow: clean ≡ raw ≡ live decompile ≡ bytes

| Stage | Match |
|---|---|
| SEH install | **Yes** |
| `operator_new(0x6f0)` | **Yes** |
| null → return 0 | **Yes** |
| base default ctor then vtbl overwrite | **Yes** |
| return object*; bare RET | **Yes** |
| no full-arg ctor / no creature bind | **Yes** |

---

## 6. Gaps / open

1. Product English for the type-registry / who loads `0x009d1bec` (non-OWN).
2. Indirect call-site catalog beyond single DATA pointer (reachability open).
3. Whether default-factory objects later receive full field init elsewhere.
4. Runtime / bit-exact / differential — open (Terminal false).

**Verdict:** **accept-with-gaps** — CF/ABI/size/vtbl/base-ctor sealed; factory-role English Inferred; runtime open.
