# Review A (reconstruction fidelity): `aa_0041a8e0` Com_LoaderCtx_NestedTeardown_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0041a8e0` |
| **VA** | `0x0041a8e0` |
| **Body** | `0x0041a8e0`–`0x0041a988` (169 bytes) |
| **Canonical name** | `Com_LoaderCtx_NestedTeardown_Inferred` |
| **Ghidra name** | `FUN_0041a8e0` |
| **Prior alias** | `Named_CalleeOf_Named_CalleeOf_Mission_bActiveObjectiveOverride_0041a8e0` |
| **Review date** | `2026-07-29` (W22-M dual seal) |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_0041a8e0_Com_LoaderCtx_NestedTeardown_Inferred.md` |
| **System** | `crt-com` / DB-WAD loader context nested teardown |
| **Live tools** | Ghidra `decompile_function` / `batch_decompile` + `read_memory` + callers/callees/xrefs (`autoassault.exe`) |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |
| **Parent ensure** | `Com_LoaderCtx_Teardown_Inferred` `aa_0041a3e0` |

---

## 1. Purpose

**Nested teardown** under a COM/DB loader context (`ctx`), invoked after parent releases `*(ctx+0x24)`:

1. SEH (`LAB_009bd810`).
2. If `*(ctx+0x10)≠0`: `OleDb_ReleaseAccessorHandleArray` (`0x00422de0`) then `AdoRowsetHolder_Teardown` (`0x0041bf70`) with EDI=`&ctx+0x10`.
3. SEH state=1; always `AdoRowsetHolder_Teardown` again.
4. Defensive `IUnknown::Release` (`vtbl+8`) on `*(ctx+0x14)` then `*(ctx+0x10)`.
5. If `*(ctx+0x0C)≠0`: `operator_delete(*(p+0x0C))`; optional `free(*p)` via IAT `0x009c6524`; zero `p[0..2]`; `operator_delete(p)`.
6. **`ret 4`** — `__stdcall` one stack arg.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | `batch_decompile` @ `0x0041a8e0` (2026-07-29) — **truncated tail** |
| Bytes | `read_memory` 169 B @ entry — full body through `ret 4` |
| Raw / annotated / clean | `raw/aa_0041a8e0_*`, `reconstructed-exact/Com_LoaderCtx_NestedTeardown_Inferred.cpp` |
| Function record | `functions/aa_0041a8e0_Com_LoaderCtx_NestedTeardown_Inferred.md` |
| Parent dual | `reviews/A_aa_0041a3e0_Com_LoaderCtx_Teardown_Inferred.md` |
| Nested duals | `AdoRowsetHolder_Teardown` `aa_0041bf70`; `OleDb_ReleaseAccessorHandleArray` `aa_00422de0` |

**Not performed:** Launcher, runtime, parent ledgers, `disassemble_bytes`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body length 169 B / `ret 4` | **Confirmed** | `read_memory` + `get_function_by_address` |
| Offsets `+0x10` / `+0x14` / `+0x0C` | **High** | `lea edi,[esi+0x10]`; `[edi+4]`; `[esi+0xc]` |
| Release via vtbl+8 | **Confirmed** | `call [reg+8]` |
| Two `operator_delete` + one `free` | **Confirmed** | call targets `0x00489822`, IAT `0x009c6524` |
| Decompile misses tail after first delete | **Confirmed** | noreturn false positive on delete thunk |
| Parent is `Com_LoaderCtx_Teardown` only (+SEH) | **High** | callers analysis |
| Product name of `*(ctx+0x0C)` object | Open | 3-dword + buffer pattern |
| Full register ABI into `00422de0` | Residual | callee dual owns details |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH + optional accessor release + holder teardown | **Yes** (decompile + bytes) |
| Always second holder teardown | **Yes** |
| Defensive Releases | **Yes** |
| Nested destroy (`delete`/`free`/zero/`delete`) | **Yes in bytes + named clean**; **No in raw decompile body** (documented gap) |
| No modernization | **Yes** |

---

## 5. Gaps

1. Product English / layout of nested object at `ctx+0x0C`.
2. Whether `ctx+0x0C` should be nulled by caller after (this unit does not write it).
3. Runtime / bit-exact / differential.
4. Scaffold decompile raw head remains truncated — annotated + named clean + re-verify section are authoritative for the tail.

**Verdict:** Structural nested-teardown contract sealed from live bytes + parent/callee duals. Product nested type open. **accept-with-gaps.**
