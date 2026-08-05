# Review A (reconstruction fidelity): `aa_004397f0` CircularSentinel_Alloc0x10_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004397f0` |
| **VA** | `0x004397f0`–`0x00439809` inclusive (**26 B** / `0x1A`) |
| **Canonical name** | `CircularSentinel_Alloc0x10_Inferred` |
| **Ghidra name** | `FUN_004397f0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W35-C) |
| **Counterpart** | `reviews/B_aa_004397f0_CircularSentinel_Alloc0x10_Inferred.md` |
| **System** | shared circular-list / hash-bucket sentinel factory |
| **Evidence pass** | Live Ghidra `batch_decompile` / `decompile_function` + `analyze_function_complete` + `read_memory` (full body) + xrefs/callers. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Allocate a **0x10-byte** empty circular list/hash sentinel (`next=prev=self`) and return it in **EAX**. Non-SEH size-0x10 twin of the CircularSentinel / StdList sentinel factory family (`0x00423d60` 0x28 / `0x004933f0` 0xC).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W35-C append) | `docs/reconstruction/raw/aa_004397f0_FUN_004397f0.md` |
| Annotated | `docs/reconstruction/raw/aa_004397f0_FUN_004397f0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CircularSentinel_Alloc0x10_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004397f0.cpp` |
| Function records | `functions/aa_004397f0_FUN_004397f0.md`, `functions/aa_004397f0_CircularSentinel_Alloc0x10_Inferred.md` |
| Family | `0x00423d60` (0x28), `0x004933f0` (0xC non-SEH), `0x0040fb90` (0xC SEH) |
| Live | decompile ≡ raw CF; body 26 B; bare `C3`; hex seals EAX return path |
| Callers | 4 — NestedHash 0x10 bag + FX/list hosts |

---

## 3. Signature (sealed)

```c
// no formals; bare RET; EAX = node*
void* CircularSentinel_Alloc0x10_Inferred(void);
```

| Formal | Source | Conf |
|---|---|---|
| (none) | — | **High** |
| return | EAX = `operator_new` result (stores use `[eax]` / `ecx=eax+4`, EAX preserved) | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
push 0x10
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
| `operator_new(0x10)` | **Yes** | **High** |
| next/prev self-link | **Yes** | **High** |
| Body 26 B / bare `C3` | **Yes** (`read_memory`) | **High** |
| EAX return (not void) | **Yes** (callers assign; hex) | **High** |
| No SEH | **Yes** | **High** |
| Sole product role = NestedHash only | **No claim** — 4 callers; structural name | **Med** |

---

## 5. Gaps

- Product/PDB English for 0x10 node payload after +8.
- Runtime / bit-exact / differential.

---

## 6. Verdict

Fidelity pass seals size/links/ABI/return against full-body bytes and family twins. Residual product payload English + runtime → **accept-with-gaps**.
