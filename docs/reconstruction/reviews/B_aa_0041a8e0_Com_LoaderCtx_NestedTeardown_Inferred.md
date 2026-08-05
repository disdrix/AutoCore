# Review B (skeptical / adversarial): `aa_0041a8e0` Com_LoaderCtx_NestedTeardown_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0041a8e0` |
| **VA** | `0x0041a8e0` |
| **Canonical name** | `Com_LoaderCtx_NestedTeardown_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W22-M) |
| **Counterpart** | `reviews/A_aa_0041a8e0_Com_LoaderCtx_NestedTeardown_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only. No `disassemble_bytes`. No Launcher.

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Full C++ destructor of entire loader ctx | Parent `0041a3e0` already released `+0x24`; this only tears `+0x10/+0x14/+0x0C` | **Weak** as whole-object dtor — **nested** teardown only |
| 2 | Live decompile is complete | First `operator_delete` noreturn aborts CF; bytes continue with free/zero/second delete | **Falsified** decompile completeness — bytes required |
| 3 | Outer Releases double-free after holder teardown | Teardown nulls slots; outer checks non-null before Release | **Survives** as defensive pattern |
| 4 | `operator_delete` never returns (Ghidra) | Second delete + epilogue execute in bytes | **Falsified** noreturn on this thunk for analysis purposes |
| 5 | Mission-only helper | Shared COM loader path under skill DbLoad (and SEH) | **No exclusive mission claim** |
| 6 | Frees `ctx` itself | Only frees nested `*(ctx+0x0C)` and its buffer | **Falsified** whole-ctx free |
| 7 | IAT `0x009c6524` is something other than free | Peer duals seal same IAT as `free` | **Survives** as free |

---

## 2. Surviving contract

```
NestedTeardown(ctx):
  if *(ctx+0x10):
    ReleaseAccessorHandleArray(…)
    AdoRowsetHolder_Teardown(&ctx+0x10)
  AdoRowsetHolder_Teardown(&ctx+0x10)   # always
  Release(*(ctx+0x14)) if non-null
  Release(*(ctx+0x10)) if non-null
  if p = *(ctx+0x0C):
    delete p->+0x0C
    if *p: free(*p)
    zero p[0],p[1],p[2]
    delete p
  ret 4
```

Ports must use RAII/finally equivalent on all DbLoad exit paths that built this ctx; must not skip the nested `+0x0C` destroy arm when present.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Nested-only (not full ctx free) | **High** | Double-free or leak of outer ctx |
| Decompile tail incomplete | **High** | Missing free/zero → leak or use-after-free |
| COM Release shape | **High** | COM refcount imbalance |
| Nested product type | Medium | Wrong managed mapping of `+0x0C` |

---

## 4. Cross-check against raw + bytes

- Raw decompile body **must not** be ported as complete without the re-verify tail.
- Named clean includes free/zero/second delete; scaffold clean updated similarly.
- Parent dual already called this unit “deeper field teardown” — naming consistent.

---

## 5. Open questions

1. Exact product type of nested `*(ctx+0x0C)` (string-like vs custom).
2. Full ESI/EAX contract into `00422de0` when invoked from this path (callee-owned).
3. Runtime confirmation of refcount order.

**Verdict:** **accept-with-gaps**
