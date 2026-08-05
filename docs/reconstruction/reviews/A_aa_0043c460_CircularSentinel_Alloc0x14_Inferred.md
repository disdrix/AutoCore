# Review A (reconstruction fidelity): `aa_0043c460` CircularSentinel_Alloc0x14_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043c460` |
| **VA** | `0x0043c460`–`0x0043c479` inclusive (**26 B** / `0x1A`) |
| **Canonical name** | `CircularSentinel_Alloc0x14_Inferred` |
| **Ghidra name** | `FUN_0043c460` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W35-B) |
| **Counterpart** | `reviews/B_aa_0043c460_CircularSentinel_Alloc0x14_Inferred.md` |
| **System** | shared circular-list / hash-bucket sentinel factory |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` (full body) + xrefs/callers. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Allocate a **0x14-byte** empty circular list/hash sentinel (`next=prev=self`) and return it in **EAX**. Non-SEH size-0x14 twin of the 0xC / 0x28 factory family.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W35-B append) | `docs/reconstruction/raw/aa_0043c460_FUN_0043c460.md` |
| Annotated | `docs/reconstruction/raw/aa_0043c460_FUN_0043c460.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CircularSentinel_Alloc0x14_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043c460.cpp` |
| Function records | `functions/aa_0043c460_FUN_0043c460.md`, named twin |
| Family | `0x00423d60` (0x28), `0x004933f0` (0xC non-SEH), `0x0040fb90` (0xC SEH) |
| Live | decompile ≡ raw CF; body 26 B; bare `C3`; hex seals EAX return path |
| Callers | NestedHash/HeadBag bag ctors + two ad-hoc list heads |

---

## 3. Signature (sealed)

```c
// no formals; bare RET; EAX = node*
void* CircularSentinel_Alloc0x14_Inferred(void);
```

| Formal | Source | Conf |
|---|---|---|
| (none) | — | **High** |
| return | EAX = `operator_new` result (stores use `[eax]` / `ecx=eax+4`, EAX preserved) | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
push 0x14
call operator_new
add esp, 4
test eax, eax
jz skip_next
  mov [eax], eax          // next = self
skip_next:
lea ecx, [eax+4]
test ecx, ecx
jz skip_prev
  mov [ecx], eax          // prev = self
skip_prev:
ret                       // EAX = node*
```

| Stage | Match | Conf |
|---|---|---|
| `operator_new(0x14)` | **Yes** | **High** |
| next/prev self-link | **Yes** | **High** |
| Body 26 B / bare `C3` | **Yes** (`read_memory`) | **High** |
| EAX return (not void) | **Yes** (callers assign; hex) | **High** |
| No SEH | **Yes** | **High** |
| Family CF vs 0xC/0x28 | **Yes** (size immediate only) | **High** |

---

## 5. Gaps

- Product payload meaning of remaining **0x0C** bytes of the 0x14 node.
- Full product English of non-bag callers (`FUN_005e2670`, `FUN_007c77b0`) beyond list-head use.
- Runtime / bit-exact / differential.

---

## 6. Verdict

Fidelity pass seals factory role, ABI, self-link, size **0x14**, and EAX return. Residual product payload English → **accept-with-gaps**.
