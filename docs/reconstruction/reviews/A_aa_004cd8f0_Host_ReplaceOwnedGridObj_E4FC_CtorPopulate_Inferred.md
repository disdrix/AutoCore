# Review A (reconstruction fidelity): `aa_004cd8f0` Host_ReplaceOwnedGridObj_E4FC_CtorPopulate_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cd8f0` |
| **VA** | `0x004cd8f0`–`0x004cd991` exclusive (**161 B** / `0xA1`) |
| **Canonical name** | `Host_ReplaceOwnedGridObj_E4FC_CtorPopulate_Inferred` (**Inferred**); Ghidra `FUN_004cd8f0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_004cd8f0_Host_ReplaceOwnedGridObj_E4FC_CtorPopulate_Inferred.md` |
| **System** | host owned 0x30 grid-list object replace + populate |
| **Live tools** | Ghidra `batch_decompile`, `analyze_function_complete`, `read_memory`, xrefs/callers, `get_function_by_address`; context W30-O / W37-L. **No** `disassemble_bytes` |
| **Verdict** | **accept-with-gaps** — CF/ABI/`ret 0x10`/slot replace+ctor+populate sealed; product host English + zero xrefs open |
| **Dual status** | **Present (W38-S)** |

---

## 1. Purpose

**Replace** the owned **0x30** grid-list object hanging off a large host at **`+0xe4fc`**, then **populate** its list with a scaled grid:

```
// __thiscall host; stack (dim_a, dim_b, dim_c, ctx); ret 0x10
if (host.e4fc) host.e4fc->vtbl[0](1); host.e4fc = 0;
obj = new(0x30) ? FUN_005b3f60() : 0;   // W30-O default ctor
host.e4fc = obj;
// ECX = obj
FUN_005b3fa0(dim_a, dim_b, dim_c, *(host.e4f8 + 0x18), ctx);  // W37-L
```

This is the **live** ctor+populate pairing documented in W30-O / W37-L (vs dead convenience `005b4260`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | Ghidra `batch_decompile` `0x004cd8f0` (2026-08-04) |
| Complete analysis | 0 xrefs; callees `FUN_005b3fa0`, `FUN_005b3f60`, `operator_new` |
| Machine | `read_memory` @ `0x004cd8f0` length 161 → body ends `c2 10 00` then `CC` |
| Prior duals | W30-O `005b3f60`; W37-L `005b3fa0` |
| Sibling | `FUN_004cd9a0` (also writes `+0xe4fc`, different path) |

**Not performed:** Launcher, runtime golden, parent ledger edits, dual of sibling `004cd9a0`.

---

## 3. Machine seal (`read_memory`)

| Claim | Evidence | Conf |
|---|---|---|
| SEH prolog `push -1; push LAB_009a1eb7; FS:[0]` | head of body | **Confirmed** |
| Load `host+0xe4fc` via `mov esi,ecx; mov ecx,[esi+0xe4fc]` | `8b f1; 8b 8e fc e4 00 00` | **Confirmed** |
| Scalar dtor `push 1; call [eax]` then zero slot | `6a 01; ff 10; c7 86 fc e4 … 0` | **Confirmed** |
| `push 0x30; call operator_new; add esp,4` | alloc | **Confirmed** |
| Non-null → `mov ecx,eax; call FUN_005b3f60` | ctor thiscall | **Confirmed** |
| Store to `+0xe4fc` | `89 86 fc e4 00 00` | **Confirmed** |
| Scale from `*( [esi+0xe4f8] + 0x18 )` | `8b 8e f8 e4 …; 8b 51 18` | **Confirmed** |
| Populate: push args; **`mov ecx,eax`**; `call FUN_005b3fa0` | decompiler drops this | **Confirmed** |
| Epilog `add esp,0x10; ret 0x10` | `83 c4 10; c2 10 00` | **Confirmed** |
| Body 161 B exclusive end `004cd991` | hex + pad | **Confirmed** |

Full hex (161 B):

```
6aff68b71e9a0064a100000000506489250000000051568bf18b8efce4000085c974108b016a01ff10c786fce40000000000006a30e868bffbff83c4048944240485c0c74424100000000074098bc8e81c660e00eb0233c08b8ef8e400008986fce400008b51188b4c2424518b4c242452518b4c2424895424108b54242852518bc8c7442424ffffffffe821660e008b4c24085e64890d0000000083c410c21000
```

---

## 4. Layout contract

| Offset | Role |
|---|---|
| host `+0xe4f8` | nested object* → scale dword/float at `+0x18` |
| host `+0xe4fc` | owned 0x30 grid-list object* |

Populate arg map (W37-L):

| Arg | Source |
|---|---|
| this | new 0x30 object |
| dim_a/b/c | stack params 0..2 |
| scale | `*(host+0xe4f8)+0x18` |
| ctx | stack param 3 |

---

## 5. Callers / callees

| Direction | Detail |
|---|---|
| Callees | `operator_new`, `FUN_005b3f60`, `FUN_005b3fa0`, owned `vtbl[0](1)` |
| Callers | **none** static (Ghidra) |

---

## 6. Confidence table

| Claim | Level |
|---|---|
| Replace + ctor + populate CF | **Confirmed** |
| `__thiscall` + `ret 0x10` | **Confirmed** |
| Populate ECX = new object | **Confirmed** (bytes over decompile) |
| Live structural host path (vs `005b4260`) | **High** (prior duals) |
| Product host class / live callers | **Open** |

---

## 7. Gaps

1. Product English for host and nested `+0xe4f8`.  
2. Zero static xrefs — discovery of who calls this.  
3. OOM: populate with ECX=0.  
4. Runtime / differential.

**Verdict:** **accept-with-gaps**
