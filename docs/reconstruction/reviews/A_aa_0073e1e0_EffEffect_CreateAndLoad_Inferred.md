# Review A (reconstruction fidelity): `aa_0073e1e0` EffEffect_CreateAndLoad_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0073e1e0` |
| **VA** | `0x0073e1e0` |
| **Body** | `0x0073e1e0`–`0x0073e257` exclusive (**119** B) |
| **Canonical name** | `EffEffect_CreateAndLoad_Inferred` |
| **Ghidra name** | `FUN_0073e1e0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0073e1e0_EffEffect_CreateAndLoad_Inferred.md` |
| **System** | graphics effect create + path load + manager register |
| **Live tools** | Ghidra `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + xrefs/callers + callee decompile context (**no** `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

Allocate effect shell, load by path/token, register with manager, return object* (null + destroy on load fail).

```c
void* __stdcall EffEffect_CreateAndLoad_Inferred(void* manager, void* pathOrToken, int32_t* outStatus);
// RET 0x0C; *outStatus = load status; return effect* or null
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `aa_0073e1e0_*` / `EffEffect_CreateAndLoad_Inferred.cpp` |
| Live decompile | ≡ CF; bytes win on callee ECX routing |
| Body | `read_memory 0x0073e1e0` length 119; **`ret 0xc`** both paths |
| Callees | `FUN_00457040`, `FUN_007533e0`, `FUN_0073d830`, `vtbl[0]` |
| Callers | `FUN_009701d0` @ `009701e7`; `FUN_0072a660` @ `0072a92a` |
| Vtbl | `PTR_FUN_00a9f9c4` → `[0]=FUN_00445020` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| stdcall 3 stack args + `ret 0xc` | **Confirmed** | epilogue both paths |
| Freelist via `DAT_00d21970` / `FUN_00457040` | **Confirmed** | `mov edi,0x00d21970` pre-call |
| Vtbl + zero init + 0xFFFF shorts | **Confirmed** | init block in bytes |
| Load status → `*outStatus`; fail → dtor(1) + null | **Confirmed** | `jl` fail path |
| Path ECX into `FUN_007533e0`; manager ECX into `FUN_0073d830` | **Confirmed** | bytes; decompiler incomplete |
| Product plate English | Inferred | `_Inferred` from BindByPath / Phase.fx callers |
| Full load/status domain | Open | unowned `FUN_007533e0` |

---

## 4. Gaps (non-blocking)

- Unowned load/register callee duals.
- Product class name for effect / manager.
- Null freelist + successful load theoretical edge.
- Runtime / bit-exact / differential.

---

## 5. Verdict rationale

Alloc/init/load/fail-destroy/success-register CF is sealed; ABI and callee thiscall ECX wiring sealed by body bytes. Name role-inferred from manager+path callers (slot bind, Phase.fx). Gaps are unowned callees and product English → **accept**.
