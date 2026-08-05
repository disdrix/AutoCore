# Review A (reconstruction fidelity): `aa_005b43b0` StdList_AllocSentinel_0x30_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b43b0` |
| **VA** | `0x005b43b0`–`0x005b43c9` inclusive (**26 B** / `0x1A`) |
| **Canonical name** | `StdList_AllocSentinel_0x30_Inferred` |
| **Ghidra name** | `FUN_005b43b0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W35-G) |
| **Counterpart** | `reviews/B_aa_005b43b0_StdList_AllocSentinel_0x30_Inferred.md` |
| **System** | shared `std::list`-style sentinel factory |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full body) + xrefs/callers. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Allocate a 0x30-byte empty circular list sentinel (`next=prev=self`) and return it in EAX. Non-SEH sibling of 0xC / 0x18 factories.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W35-G append) | `docs/reconstruction/raw/aa_005b43b0_FUN_005b43b0.md` |
| Annotated | `docs/reconstruction/raw/aa_005b43b0_FUN_005b43b0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/StdList_AllocSentinel_0x30_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005b43b0.cpp` |
| Function records | `functions/aa_005b43b0_FUN_005b43b0.md`, `…_StdList_AllocSentinel_0x30_Inferred.md` |
| Family | `0x004933f0` (0xC), `0x00457c60` (0x18), `0x0040fb90` (SEH 0xC), `0x00423d60` (0x28) |
| Live | decompile ≡ raw CF; body 26 B; bare `C3`; hex seals EAX return path |

---

## 3. Signature (sealed)

```c
// no formals; bare RET; EAX = node*
void* StdList_AllocSentinel_0x30_Inferred(void);
```

| Formal | Source | Conf |
|---|---|---|
| (none) | — | **High** |
| return | EAX = `operator_new` result (stores use `[eax]` / `ecx=eax+4`, EAX preserved) | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
push 0x30
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
| `operator_new(0x30)` | **Yes** | **High** |
| next/prev self-link | **Yes** | **High** |
| Body 26 B / bare `C3` | **Yes** (`read_memory`) | **High** |
| EAX return (not void) | **Yes** (callers assign; hex) | **High** |
| Family skeleton ≡ 0xC/0x18 | **Yes** | **High** |

---

## 5. Gaps

- Product payload meaning of +0x08..+0x2F when elements inserted.
- Why 0x30 vs 0x28 Ass NestedHash sentinel for similar bag shapes.
- Runtime / bit-exact / differential.

---

## 6. Verdict

Fidelity pass seals factory role, ABI, self-link, size 0x30, and return. Residual product English → **accept-with-gaps**.
