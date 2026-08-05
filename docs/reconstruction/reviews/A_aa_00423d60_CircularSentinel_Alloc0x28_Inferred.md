# Review A (reconstruction fidelity): `aa_00423d60` CircularSentinel_Alloc0x28_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00423d60` |
| **VA** | `0x00423d60`–`0x00423d79` inclusive (**26 B** / `0x1A`) |
| **Canonical name** | `CircularSentinel_Alloc0x28_Inferred` |
| **Ghidra name** | `FUN_00423d60` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W33-B) |
| **Counterpart** | `reviews/B_aa_00423d60_CircularSentinel_Alloc0x28_Inferred.md` |
| **System** | shared circular-list / hash-bucket sentinel factory |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full body) + xrefs/callers. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Allocate a **0x28-byte** empty circular list/hash sentinel (`next=prev=self`) and return it in **EAX**. Non-SEH size-0x28 twin of the 0xC factory family (`0x004933f0` / `0x0040fb90`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W33-B append) | `docs/reconstruction/raw/aa_00423d60_FUN_00423d60.md` |
| Annotated | `docs/reconstruction/raw/aa_00423d60_FUN_00423d60.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CircularSentinel_Alloc0x28_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00423d60.cpp` |
| Function records | `functions/aa_00423d60_FUN_00423d60.md`, `functions/aa_00423d60_CircularSentinel_Alloc0x28_Inferred.md` |
| Family | `0x004933f0` (0xC non-SEH), `0x0040fb90` (0xC SEH) |
| Live | decompile ≡ raw CF; body 26 B; bare `C3`; hex seals EAX return path |
| Callers | 3 Ass-resolver nested bag ctors (00423cf0 / 00469db0 / 0044a0d0) |

---

## 3. Signature (sealed)

```c
// no formals; bare RET; EAX = node*
void* CircularSentinel_Alloc0x28_Inferred(void);
```

| Formal | Source | Conf |
|---|---|---|
| (none) | — | **High** |
| return | EAX = `operator_new` result (stores use `[eax]` / `ecx=eax+4`, EAX preserved) | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
push 0x28
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
| `operator_new(0x28)` | **Yes** | **High** |
| next/prev self-link | **Yes** | **High** |
| Body 26 B / bare `C3` | **Yes** (`read_memory`) | **High** |
| EAX return (not void) | **Yes** (callers assign; hex) | **High** |
| No SEH | **Yes** | **High** |
| Sole product role = Ass hash only | **No claim** — 3 callers all bag-ctor shape; still structural name | **Med** |

---

## 5. Gaps

- Product payload meaning of remaining **0x20** bytes of the 0x28 node.
- Full product English of callers beyond nested bag ctors (already dual-reviewed elsewhere).
- Runtime / bit-exact / differential.

---

## 6. Verdict

Fidelity pass seals factory role, ABI, self-link, size **0x28**, and EAX return. Residual product payload English → **accept-with-gaps**.
