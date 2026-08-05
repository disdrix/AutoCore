# Review A (reconstruction fidelity): `aa_00744ea0` NDResDepHost_RemoveResourceId_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00744ea0` |
| **VA** | `0x00744ea0` |
| **Body** | `0x00744ea0`–`0x007450ae` exclusive (**526** B) |
| **Canonical name** | `NDResDepHost_RemoveResourceId_Inferred` |
| **Ghidra name** | `FUN_00744ea0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00744ea0_NDResDepHost_RemoveResourceId_Inferred.md` |
| **System** | ND resource dependency host |
| **Live tools** | Ghidra `decompile_function`, `batch_decompile`, `read_memory`, `analyze_function_complete`, xrefs/callers, `get_assembly_context`, callee decompile (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Remove resource id `*pId` from dependency host maps and tracked-id vector; optional cascade when `recurse != 0`.

```c
bool __thiscall NDResDepHost_RemoveResourceId_Inferred(void* self, int* pId, char recurse);
// RET 8; AL bool
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `aa_00744ea0_*` + named clean |
| Live decompile | ≡ raw CF |
| Body | `read_memory 0x00744ea0` length 526; **`RET 8`** both exits |
| Call sites | NDXml / FUN_007b7420 / EffEffectSlot_BindByPath / self |
| Callees | map distance/find/erase, vector remove, key box copy |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| thiscall ECX + `int* pId` + `char recurse` + `RET 8` | **Confirmed** | prologue/epilogue + call-site pushes |
| bool AL (init 1 / fail 0) | **Confirmed** | `MOV byte [esp+0x13],1` / `XOR AL,AL` |
| equal_range count==1 owned erase on map@+0x1c | **Confirmed** | decompile ≡ bytes |
| fail if count remains ≠0 | **Confirmed** | early `return 0` |
| vector scan +0x50/+0x54 + FUN_00744cc0 | **Confirmed** | |
| map walks +0x14 / head@+0x20; erase helper +0x1c | **Confirmed** | MSVC map object @+0x1c head@+0x20 |
| DAT_00d1f050 host wiring at callers | **Confirmed** | assembly context |
| Product host type English | Inferred | `_Inferred` |
| Full map key/value C++ types | Open | unowned STL helpers |

---

## 4. Gaps (non-blocking)

- Product/PDB name of host class (dependency graph vs cache subobject).
- Whether map@+0x14 and map@+0x1c are distinct typed maps vs multi-index.
- Exact semantics of recurse=0 vs 1 at product layer (cascade depth policy).
- Runtime / bit-exact / differential.

---

## 5. Verdict rationale

ABI, bool return, erase-only CF (no insert), vector drop, and recurse gate are sealed. Name is structural from `DAT_00d1f050` callers + erase CF — not a retail demangle. Residual gaps are product English and unowned map helpers → **accept-with-gaps**.
