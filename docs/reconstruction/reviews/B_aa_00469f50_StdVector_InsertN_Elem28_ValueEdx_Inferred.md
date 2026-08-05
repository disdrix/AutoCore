# Review B (skeptical / adversarial): `aa_00469f50` StdVector_InsertN_Elem28_ValueEdx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00469f50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W34-Q) |
| **Counterpart** | `reviews/A_aa_00469f50_StdVector_InsertN_Elem28_ValueEdx_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + xrefs only. **No** `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | ECX is a real formal (count or this) | **Falsified** — entry `mov ecx,7` for `rep movsd` only |
| 2 | Same ABI as `00466ea0` | **Falsified** — value in EDX; three stack args; `RET 0x0C` vs `RET 8` |
| 3 | Element stride 4 | **Falsified** — `/0x1c` throughout |
| 4 | basic_string insert with refcount | **Falsified** — POD 7-dword helpers; no string IAT |
| 5 | Growth 2× | **Falsified** — `cap+(cap>>1)` |
| 6 | Silent overflow | **Falsified** — `FUN_004540b0` |
| 7 | Multi-caller domain logic | **Falsified** — single insert-one parent |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Value-EDX + stack vec/where/count | **High** | Wrong formals at call site |
| RET 0x0C | **High** | Stack imbalance |
| Stride/max/growth | **High** | Memory smash |
| POD role | **High** | Wrong lifetime |
| Product English | Medium | Naming only |

---

## 3. Cross-check against raw + bytes

```
mov esi, edx          ; value*
lea edi, [ebp-0x30]
mov ecx, 7
rep movsd             ; snapshot 0x1c
vec   = [ebp+8]
where = [ebp+0xC]
count = [ebp+0x10]
; same insert-n CF as 00466ea0 with 0046a350/0046a260 helpers
ret 0x0C
```

Do **not** unify call sites with `00466ea0` without adapting formals.

---

## 4. Surviving contract for AutoCore

Same port shape as `00466ea0` — one server insert-range for 28-byte POD. Preserve insert-one parent semantics (count=`1`, rebind iterator) when wiring `FUN_00469e20`.

---

## 5. Open questions

1. Concrete T.  
2. Why ValueEdx vs CountEcx flavors coexist.  
3. EH state on fill arms.

**Verdict:** **accept-with-gaps**
