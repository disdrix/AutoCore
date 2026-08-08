# Review B (skeptical / adversarial): `aa_00416010` StdList_Incsize_Max1fffffff

| Field | Value |
|---|---|
| **Stable ID** | `aa_00416010` |
| **VA** | `0x00416010` |
| **Canonical name** | `StdList_Incsize_Max1fffffff` |
| **Review date** | `2026-08-04` (WQ9I-E dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00416010_StdList_Incsize_Max1fffffff.md` |
| **Live tools** | Independent `batch_decompile` + `read_memory` + caller `get_assembly_context` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | `__thiscall` / `this` in ECX | **Falsified** — ECX is count; list in **EDX** (`[edx+8]`) |
| 2 | Same function as `StdList_Incsize` @ `0x0043fe60` | **Falsified** — max imm is **`0x1fffffff`**, not `0x3fffffff` |
| 3 | Allocates / links list nodes | **Falsified** — size math + throw only; buy-node is `FUN_00415ed0` |
| 4 | Max is unlimited / `0xffffffff` | **Falsified** — immediate `0x1fffffff` |
| 5 | Returns bool success / soft-fail | **Falsified** — void bare ret; overflow is **noreturn throw** |
| 6 | Stack args / `RET N` | **Falsified** — plain `C3` |
| 7 | UI-only / domain-specific helper | **Falsified** — shared STL leaf; multiple parents |
| 8 | Merge with vector `"vector<T> too long"` | **Falsified** — string is list-specific at `00a1581c` |
| 9 | Product exception type sealed | **Fails** — ThrowInfo only |
| 10 | Runtime Confirmed / bit-exact | **Fails** — open; no Launcher |

---

## 2. Decisive machine dataflow

```text
// entry SEH frame
EAX = [EDX+8]                 // size
ESI = 0x1fffffff
ESI = ESI - EAX
if ESI < ECX:                 // (max - size) < count
  throw "list<T> too long" via FUN_00401a40 + _CxxThrowException(DAT_00acc388)
EAX = EAX + ECX
[EDX+8] = EAX
ret
```

Caller sample (`00415deb`):

```text
MOV ECX, 1
MOV EDX, list*
CALL 0x00416010
// then link node into list head
```

A ≡ B on live decompile + max/size/string bytes.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX count, EDX list*, plain RET | **High** | Wrong insert ABI → corrupt size |
| `+8` is `_Mysize` | **High** | Wrong field |
| `0x1fffffff` gate | **High** | Missed / false throw |
| Distinct from max-`0x3fffffff` twin | **High** | Cross-merge COMDAT clones |
| Product throw type | **Open** | Naming only |
| Runtime | **Open** | Shipping growth edge |

---

## 4. Surviving contract

```text
StdList_Incsize_Max1fffffff:
  ECX = count, EDX = list*
  if 0x1fffffff - list[8] < count: throw "list<T> too long"
  list[8] += count
  bare ret
```

**Verdict:** **accept-with-gaps**
