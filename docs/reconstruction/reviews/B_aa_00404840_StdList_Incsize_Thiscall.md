# Review B (skeptical / adversarial): `aa_00404840` StdList_Incsize_Thiscall

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404840` |
| **VA** | `0x00404840` |
| **Canonical name** | `StdList_Incsize_Thiscall` |
| **Review date** | `2026-08-05` (R10-006 dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00404840_StdList_Incsize_Thiscall.md` |
| **Live tools** | Independent `decompile_function` + `read_memory` + caller `get_assembly_context` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Fastcall ECX=count / EDX=list* like `StdList_Incsize` `0043fe60` | **Falsified** — ECX is list (`[ecx+8]`); count from **stack** (`[esp+4]`→EDX); **`RET 4`** not bare `C3` |
| 2 | Same function as `StdList_Incsize` @ `0x0043fe60` | **Falsified** — ABI differs (thiscall vs fastcall); body at different VA |
| 3 | Max is `0x1fffffff` (merge with `00416010`) | **Falsified** — immediate `0x3fffffff` (`BE FF FF FF 3F`) |
| 4 | Allocates / links list nodes | **Falsified** — size math + throw only; BuyNode is `FUN_00418700` |
| 5 | Mission-only / DebugListMissionsStatus helper | **Falsified** — 32 xrefs across inventory, character, insert wrappers; shared STL leaf |
| 6 | Returns bool success / soft-fail | **Falsified** — void; overflow is **noreturn throw** |
| 7 | cdecl / plain `RET` / no stack cleanup | **Falsified** — `C2 04 00` |
| 8 | Vector `"vector<T> too long"` | **Falsified** — string at `00a1581c` is list-specific (vector string is adjacent after NUL pad) |
| 9 | Product exception type sealed | **Fails** — ThrowInfo only (`DAT_00acc388`) |
| 10 | Runtime Confirmed / bit-exact | **Fails** — open; no Launcher |

---

## 2. Decisive machine dataflow

```text
// entry SEH frame
EDX = [ESP+4]                 // count (stack)
EAX = [ECX+8]                 // size (thiscall list*)
ESI = 0x3fffffff
ESI = ESI - EAX
if ESI < EDX:                 // (max - size) < count
  throw "list<T> too long" via FUN_00401a40 + _CxxThrowException(DAT_00acc388)
EAX = EAX + EDX
[ECX+8] = EAX
ret 4
```

Caller sample (`00402d2f` in PushBack):

```text
PUSH 1
MOV  ECX, ESI                 // list*
CALL 0x00404840
// then link BuyNode result into list head
```

A ≡ B on live decompile + max/size/string/ret bytes.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX list*, stack count, `RET 4` | **High** | Wrong insert ABI → corrupt size / stack |
| `+8` is `_Mysize` | **High** | Wrong field |
| `0x3fffffff` gate | **High** | Missed / false throw |
| Distinct from fastcall twin `0043fe60` | **High** | Cross-merge COMDAT clones |
| Distinct from Max1fffffff `00416010` | **High** | Wrong overflow bound |
| Product throw type | **Open** | Naming only |
| Runtime | **Open** | Shipping growth edge |

---

## 4. Surviving contract

```text
StdList_Incsize_Thiscall:
  ECX = list*, stack = count
  if 0x3fffffff - list[8] < count: throw "list<T> too long"
  list[8] += count
  ret 4
```

**Verdict:** **accept**
