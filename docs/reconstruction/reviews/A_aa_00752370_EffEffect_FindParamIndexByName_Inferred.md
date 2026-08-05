# Review A (reconstruction fidelity): `aa_00752370` EffEffect_FindParamIndexByName_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00752370` |
| **VA** | `0x00752370` |
| **Body** | `0x00752370`–`0x007523cb` exclusive (**91** B) |
| **Canonical name** | `EffEffect_FindParamIndexByName_Inferred` |
| **Ghidra name** | `FUN_00752370` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00752370_EffEffect_FindParamIndexByName_Inferred.md` |
| **System** | graphics effect parameter index lookup |
| **Live tools** | Ghidra `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + xrefs/callers (**no** `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

Resolve parameter **table index** by name on a loaded effect shell for subsequent set-param calls.

```c
void __thiscall EffEffect_FindParamIndexByName_Inferred(void* effect, int32_t* outIndex, const void* nameOrToken);
// RET 8; *outIndex = index or -1
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `aa_00752370_*` / `EffEffect_FindParamIndexByName_Inferred.cpp` |
| Live decompile | ≡ raw CF |
| Body | `read_memory 0x00752370` length 91; **`ret 8`** both paths |
| Callers | 35 fn / 86 xrefs — MatDiffuse / DiffuseTexture / WireColor paths |
| String evidence | `"DiffuseTexture"` @ `0x00a9ede4` (caller `FUN_0075bf40`) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| thiscall ECX=effect + 2 stack args + `ret 8` | **Confirmed** | prologue `mov esi,ecx`; epilogue `c2 08 00` |
| Default / miss → `*out = -1` | **Confirmed** | `or edi,-1`; early store |
| `vtbl+0x24(iface,0,name)` handle resolve | **Confirmed** | push name; push 0; call `[ecx+0x24]` |
| Table base `+0x10`, count `+0x18`, stride 8 | **Confirmed** | `cmp [esi+ecx*8], eax` |
| Product plate English | Inferred | `_Inferred` from role + callers |
| iface method product name | Open | unowned |

---

## 4. Gaps (non-blocking)

- Product/PDB demangle for effect/param iface.
- Second dword of table entries unused here.
- Runtime / bit-exact / differential.

---

## 5. Verdict rationale

Control flow, ABI (`ret 8`), null gates, handle→index linear scan, and miss−1 are sealed from decompile ≡ body hex. Name is role-inferred from high-volume material/FX callers — not a retail demangle. Residual gaps are product English only → **accept**.
