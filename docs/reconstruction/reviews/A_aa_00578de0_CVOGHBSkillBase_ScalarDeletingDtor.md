# Review A (reconstruction fidelity): `aa_00578de0` CVOGHBSkillBase_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00578de0` |
| **VA** | `0x00578de0`–`0x00578dfe` exclusive (**30** B / `0x1E`) |
| **Canonical name** | `CVOGHBSkillBase_ScalarDeletingDtor` |
| **Ghidra symbol** | `FUN_00578de0` |
| **Prior scaffold** | `FUN_00578de0` |
| **Review date** | `2026-08-05` (R11-006 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00578de0_CVOGHBSkillBase_ScalarDeletingDtor.md` |
| **System** | `skills-abilities` / CVOGHBSkillBase lifecycle |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs/callees. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC **scalar deleting destructor** for **`CVOGHBSkillBase`** (vtbl slot **0** of `PTR_FUN_009d3fdc`):

```text
CVOGHBSkillBase_ScalarDeletingDtor(this, flags)
  FUN_00578a60(this)           // complete body
  if (flags & 1): operator_delete(this)
  return this                  // EAX; ret 4
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ R11-006 re-verify) | `docs/reconstruction/raw/aa_00578de0_FUN_00578de0.md` |
| Annotated | `docs/reconstruction/raw/aa_00578de0_FUN_00578de0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBSkillBase_ScalarDeletingDtor.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00578de0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00578de0_CVOGHBSkillBase_ScalarDeletingDtor.md` |
| Live body | `disassemble_function` + `read_memory` @ `0x00578de0` / epilogue `C2 04 00` |
| Vtbl[0] | `read_memory` @ `0x009d3fdc` → LE `E08D5700` = this VA |
| Complete dtor (context) | `FUN_00578a60` decompile (not dualed OWN) |
| Ctor family | dualed `CVOGHBSkillBase_ctor` @ `0x005788d0` |
| Base twin | dualed `CVOGHBBase_ScalarDeletingDtor` @ `0x00508630` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 30 B + `ret 4` | **Confirmed** | hex ends `C2 04 00`; pad `CC` |
| `__thiscall` ECX=this, stack flags | **Confirmed** | `MOV ESI,ECX`; `TEST [ESP+8],1` after push |
| Always call complete `FUN_00578a60` | **Confirmed** | rel32 → `0x00578a60` |
| `(flags & 1)` → `operator_delete` | **Confirmed** | free path + `ADD ESP,4` |
| EAX = this | **Confirmed** | `MOV EAX,ESI` |
| vtbl[0] @ `0x009d3fdc` = this VA | **Confirmed** | `read_memory` |
| Class `CVOGHBSkillBase` | **Confirmed** | RTTI on same vtbl; ctor dual |
| 0 CODE callers | **Confirmed** | analyze + xrefs (DATA only) |
| Live decompile ≡ raw CF | **Confirmed** | side-by-side 2026-08-05 |
| Decompiler "delete does not return" | **Noise** | machine continues to return this |
| Product mangled `??_GCVOGHBSkillBase@@…` | **Open** | |
| Runtime / bit-exact / differential | **Open** | Terminal false |

---

## 4. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| save this → call complete dtor | **Yes** |
| test flags bit0 → optional free | **Yes** |
| return this; ret 4 | **Yes** |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| Role = scalar deleting dtor | **Yes** (flags&1 free + complete body shared) |
| Class = `CVOGHBSkillBase` | **Yes** — RTTI Confirmed on `PTR_FUN_009d3fdc` |
| Vtbl[0] placement | **Yes** — `0x009d3fdc` |
| Product mangled on this VA | **No** |
| Distinct from complete `FUN_00578a60` | **Yes** |

**Decision:** promote **`CVOGHBSkillBase_ScalarDeletingDtor`** (no `_Inferred` — class + role sealed by RTTI family + MSVC pattern).

---

## 6. Gaps (non-blocking)

1. Product/PDB mangled symbol.  
2. Complete dtor `FUN_00578a60` dual residual (not OWN).  
3. Runtime / bit-exact / differential.

**Verdict:** **accept**.
