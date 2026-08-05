# Review A (reconstruction fidelity): `aa_00457c60` StdList_AllocSentinel_0x18_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00457c60` |
| **VA** | `0x00457c60`–`0x00457c7a` exclusive (**26 B** / `0x1A`) |
| **Canonical name** | `StdList_AllocSentinel_0x18_Inferred` |
| **Ghidra name** | `FUN_00457c60` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W30-E) |
| **Counterpart** | `reviews/B_aa_00457c60_StdList_AllocSentinel_0x18_Inferred.md` |
| **System** | shared `std::list`-style sentinel factory |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory`. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

Allocate **0x18**-byte node; self-link as empty circular sentinel:

```
node = operator_new(0x18)
if (node)  *node = node           // next = self @ +0
if (node+4) *(node+4) = node      // prev = self @ +4
// EAX = node* (callers assign)
```

Does **not** write size or embed a full list object — callers pair head with a separate size dword.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W30-E) | `docs/reconstruction/raw/aa_00457c60_FUN_00457c60.md` |
| Annotated | `docs/reconstruction/raw/aa_00457c60_FUN_00457c60.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/StdList_AllocSentinel_0x18_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00457c60.cpp` |
| Function records | `functions/aa_00457c60_FUN_00457c60.md`, `…_StdList_AllocSentinel_0x18_Inferred.md` |
| Sibling | `StdList_AllocEmptySentinel_Inferred` `0x0040fb90` (node 0x0C) |
| Live | decompile; body bounds; full 26 B hex; 3 callers |

---

## 3. Signature (sealed)

```c
// no formals; EAX out = node*; bare C3 RET
void* StdList_AllocSentinel_0x18_Inferred(void);
```

| Formal | Source | Conf |
|---|---|---|
| (none) | — | **High** |
| return | EAX = `operator_new` result (not clobbered) | **High** (caller stores) |

Decompiler `void` display is a known falsehood (same class as `0040fb90`).

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
push 0x18
call operator_new / add esp,4
test eax / jz skip_next
mov [eax], eax
lea ecx, [eax+4]
test ecx / jz skip_prev
mov [ecx], eax
ret
```

| Stage | Match | Conf |
|---|---|---|
| Size 0x18 | **Yes** (`6A 18`) | **High** |
| next/prev self-link | **Yes** | **High** |
| EAX return used by 3 callers | **Yes** | **High** |
| Trailing 0x10 of block unwritten | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

| Region | Note |
|---|---|
| Full body | `6a18e82b1c030083c40485c0740289008d480485c974028901c3` |
| Size | **26 B** exclusive end `0x00457c7a`; pad `CC` |

**No `disassemble_bytes` used.**

---

## 6. Gaps

- Product element type for 0x18 node (payload after 8-byte links).
- Whether callers assume zeroed trailing 0x10 (not written here).
- Runtime / bit-exact under OOM (throwing `operator_new` makes null path dead).

---

## 7. Verdict

CF, ABI, size, self-link, EAX return, 3 call sites sealed → **accept** (product payload type residual only; does not block factory contract).
