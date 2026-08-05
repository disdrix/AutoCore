# Review A (reconstruction fidelity): `aa_009701d0` EffEffectSlot_BindByPath_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_009701d0` |
| **VA** | `0x009701d0` |
| **Body** | `0x009701d0`–`0x00970250` exclusive (**128** B) |
| **Canonical name** | `EffEffectSlot_BindByPath_Inferred` |
| **Ghidra name** | `FUN_009701d0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_009701d0_EffEffectSlot_BindByPath_Inferred.md` |
| **System** | graphics effect/material slot bind |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `analyze_function_complete`, xrefs/callers (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Bind a loaded effect object into a `void**` slot: load via process manager `DAT_00d1f61c`, AddRef, release previous occupant, store, optional debug notify, return status.

```c
int32_t __thiscall EffEffectSlot_BindByPath_Inferred(void** slot, void* pathOrToken);
// RET 4; fail → 0xFFFFFFFF
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `aa_009701d0_*` |
| Live decompile | ≡ raw CF |
| Body | `read_memory 0x009701d0` length 128; **`ret 4`** both paths |
| Callees | `FUN_0073e1e0`, `FUN_00965600`, `FUN_00744ea0` |
| Callers | 100+ (FX preload, material setup, bootstrap, Z-fill, unserialize) |
| Peer refcount | W23-A `RefCountedSlot_ReleaseAndClear` — same +4 / vtbl+8 |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| thiscall ECX=slot + stack path + `ret 4` | **Confirmed** | bytes prologue/epilogue |
| Load null → `-1` | **Confirmed** | `or eax,-1` fail path |
| Refcount @+4; vtbl+4 first; vtbl+8 release | **Confirmed** | matches peer slot helpers |
| Success return = status formal (not effect*) | **Confirmed** | `mov eax,[esp+0x14]` after loader writes `&stack_arg` |
| Optional `DAT_00d1f050+0x68` debug | **Confirmed** | gated block present |
| Product plate English | Inferred | `_Inferred`; `.fx` caller evidence |
| Loader internals | Open | unowned `FUN_0073e1e0` |

---

## 4. Gaps (non-blocking)

- Full product type of effect object / vtbl identity beyond refcount contract.
- Exact status code domain from `FUN_007533e0` inside loader.
- Runtime / bit-exact / differential.

---

## 5. Verdict rationale

Control flow, ABI, refcount swap, fail code, and return discipline are sealed from decompile ≡ body hex. Name is role-inferred from manager + `.fx` callers + refcount pattern — not a retail demangle. Residual gaps are unowned callees and product English only → **accept-with-gaps**.
