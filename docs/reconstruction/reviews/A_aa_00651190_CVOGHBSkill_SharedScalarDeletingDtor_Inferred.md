# Review A (reconstruction fidelity): `aa_00651190` CVOGHBSkill_SharedScalarDeletingDtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00651190` |
| **VA** | `0x00651190`–`0x006511ae` exclusive (**30** B / `0x1E`) |
| **Canonical name** | `CVOGHBSkill_SharedScalarDeletingDtor_Inferred` |
| **Ghidra symbol** | `FUN_00651190` |
| **Prior scaffold** | `FUN_00651190` |
| **Review date** | `2026-08-05` (R12-001 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00651190_CVOGHBSkill_SharedScalarDeletingDtor_Inferred.md` |
| **System** | `skills-abilities` / CVOGHBSkill* lifecycle |
| **Partition** | R12 residual map → **R12-001**; parent dual `0x00614c80` (context) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs/callees. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC **scalar deleting destructor** shared as **vtbl slot 0** across many `CVOGHBSkill_*` subclass vtables (Master, XPAdder, SpawnEntities family, etc.). Not the base-class scalar dtor (`CVOGHBSkillBase_ScalarDeletingDtor` @ `0x00578de0`).

```text
CVOGHBSkill_SharedScalarDeletingDtor_Inferred(this, flags)
  thunk_FUN_00578a60(this)     // JMP → FUN_00578a60 complete body
  if (flags & 1): operator_delete(this)
  return this                  // EAX; ret 4
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ R12-001 re-verify) | `docs/reconstruction/raw/aa_00651190_FUN_00651190.md` |
| Annotated | `docs/reconstruction/raw/aa_00651190_FUN_00651190.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBSkill_SharedScalarDeletingDtor_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00651190.cpp` |
| Function record | `docs/reconstruction/functions/aa_00651190_FUN_00651190.md` |
| Named record | `docs/reconstruction/functions/aa_00651190_CVOGHBSkill_SharedScalarDeletingDtor_Inferred.md` |
| Live body | `disassemble_function` + `read_memory` @ `0x00651190` / epilogue `C2 04 00` |
| Complete path | thunk `0x00548f90` (`E9` → `0x00578a60`); decompile of `FUN_00578a60` |
| Base twin (not this VA) | dualed `CVOGHBSkillBase_ScalarDeletingDtor` @ `0x00578de0` |
| Parent dual (context) | `CVOGHBSkill_Master_Execute` @ `0x00614c80` — owner-null path `vtbl[0](1)` |

---

## 3. Byte seal (`read_memory` + `disassemble_function`)

```
00651190  56                 push esi
00651191  8B F1              mov  esi, ecx                 ; this
00651193  E8 F8 7D EF FF     call 0x00548f90               ; thunk → FUN_00578a60
00651198  F6 44 24 08 01     test byte [esp+8], 1          ; flags bit0
0065119d  74 09              jz   no_free
0065119f  56                 push esi
006511a0  E8 7D 86 E3 FF     call 0x00489822               ; operator_delete (IAT)
006511a5  83 C4 04           add  esp, 4
no_free:
006511a8  8B C6              mov  eax, esi
006511aa  5E                 pop  esi
006511ab  C2 04 00           ret  4
```

Hex (30 B): `568bf1e8f87deffff644240801740956e87d86e3ff83c4048bc65ec20400`  
Pad: `CC CC` at `0x006511ae`.

Thunk @ `0x00548f90`: `E9 CB FA 02 00` → JMP `0x00578a60`.

| Claim | Confidence | Evidence |
|---|---|---|
| Body **30 B** / end exclusive `0x006511ae` | **Confirmed** | `get_function_by_address`; hex length |
| `__thiscall`, ECX=this, **`ret 4`** | **Confirmed** | `MOV ESI,ECX`; `C2 04 00` |
| Always call complete dtor path | **Confirmed** | `CALL 0x00548f90` → `FUN_00578a60` |
| Complete body = `FUN_00578a60` (SkillBase) | **Confirmed** | thunk JMP; decompile restores `PTR_FUN_009d3fdc` |
| `(flags & 1)` → `operator_delete` | **Confirmed** | `TEST [ESP+8],1` + free path |
| Free target = this | **Confirmed** | `PUSH ESI` before delete |
| EAX = this | **Confirmed** | `MOV EAX,ESI` |
| No array-delete (`flags&2`) | **Confirmed** | only bit0 tested |
| Live decompile ≡ raw CF | **Confirmed** | side-by-side 2026-08-05 |
| Decompiler "delete does not return" | **Noise** | machine continues to `MOV EAX,ESI` / `RET 4` |
| Shared vtbl[0] across skill subclasses | **Confirmed** | DATA xrefs: `0x009d0e14`, `0x009d0e6c` (Master), `0x009d0ec4`, …, `0x009e5304` (XPAdder), `0x009e1f2c` |
| Master vtbl[0] = this VA | **Confirmed** | `read_memory` `0x009d0e6c` LE `90116500`; RTTI `.?AVCVOGHBSkill_Master@@` |
| XPAdder vtbl[0] = this VA | **Confirmed** | `read_memory` `0x009e5304` LE `90116500` |
| Distinct from base scalar `0x00578de0` | **Confirmed** | base vtbl `0x009d3fdc[0]` = `0x00578de0`; different VA, same pattern |
| CODE use = virtual delete with flags=1 | **High** | e.g. `00614d5a`: `PUSH 1; MOV EDX,[ESI]; MOV ECX,ESI; CALL [EDX]` |
| Product mangled on this VA | **Open** | multi-class share; no single `??_G…` sealed |
| Runtime / bit-exact / differential | **Open** | Terminal false |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| save this → call complete dtor (via thunk) | **Yes** |
| test flags bit0 → optional free | **Yes** |
| return this; ret 4 | **Yes** |
| No invented subclass field teardown in this VA | **Yes** (teardown lives in `FUN_00578a60`) |

---

## 5. Callers / xrefs (summary)

| Kind | Count / notes |
|---|---|
| **DATA** (vtbl[0]) | **~39** skill subclass vtables in `0x009d0e14`…`0x009e5304` range |
| **COMPUTED_CALL** | Owner-null destroy paths in skill factories/executes (`FUN_00614c80`, `FUN_00621700`, `FUN_006226a0`, …) — always `push 1` then `call [vtbl+0]` |
| Direct UNCONDITIONAL_CALL | **0** |

Callees: `thunk_FUN_00578a60` (`0x00548f90` → `0x00578a60`); `operator_delete` (`0x00489822` IAT).

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Role = scalar deleting dtor | **Yes** — flags&1 free + complete body + ret 4 |
| Single product class RTTI on *this* VA | **No** — shared by many `CVOGHBSkill_*` vtbls |
| Complete body class = `CVOGHBSkillBase` | **Yes** — `FUN_00578a60` / vtbl restore `PTR_FUN_009d3fdc` |
| Distinct from base scalar `0x00578de0` | **Yes** |
| Product mangled on this VA | **No** |

**Decision:** promote **`CVOGHBSkill_SharedScalarDeletingDtor_Inferred`**.  
- `_Inferred` required: multi-class share, no product demangle.  
- “Shared” encodes evidence (many DATA vtbl[0] xrefs, one body).  
- Do **not** name as `CVOGHBSkillBase_ScalarDeletingDtor` (that name is sealed on `0x00578de0`).  
- Do **not** name as Master/XPAdder-only dtor.

---

## 7. Gaps (non-blocking)

1. Product/PDB mangled symbol(s) for the merged scalar dtor.  
2. Complete dtor `FUN_00578a60` dual residual (not OWN).  
3. Exhaustive class list for every DATA vtbl (partial sealed: Master, XPAdder + peer reports).  
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — CF/ABI/shared-vtbl role/complete-body path sealed; product mangled + full class inventory + runtime open.
