# Review B (skeptical / adversarial): `aa_00507290` Host_ActionList_Push

| Field | Value |
|---|---|
| **Stable ID** | `aa_00507290` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W19-O) |
| **Counterpart** | `reviews/A_aa_00507290_Host_ActionList_Push.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` (+ xrefs / call-site bytes).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | ECX is the **action** being registered | **Falsified** — vector is at ECX+0x94; actions are ~0x48 and lack that vector; all call sites load **host** into ECX |
| 2 | Decompiler `FUN_00507290(param_1)` with action this is complete | **Falsified** — missing host ECX; stack is the pointer stored |
| 3 | Function addrefs host or action | **Falsified** — body only stores pointer + count++; addref is in **callers** |
| 4 | `ret` without stack cleanup | **Falsified** — `C2 04 00` |
| 5 | Grow uses `new[]` directly | **Falsified** — `FUN_005b3370` via `DAT_00b05060` allocator vtbl |
| 6 | Element size is 8 (TFID) or object | **Falsified** — `push 4`; `mov [edx+ecx*4],eax` |
| 7 | Capacity compare uses full dword | **Falsified** — `and eax,0x7fffffff` before cmp |
| 8 | This is world/island action register | **Falsified as identity** — separate path `FUN_0055fe50` exists for world register (peer plate); this is **host-local** vector |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Host vector push semantics | **High** | heap corruption if ECX wrong in ports |
| ret 4 / one pointer arg | **High** | stack imbalance |
| Not refcount helper | **High** | leaks / double-free if folded |
| Product type name | **Low** | naming only |

---

## 3. Cross-check against raw + bytes

```
if count == (cap & 0x7fffffff): grow(vec@+0x94, elemSize=4)
data[count] = item
count++
ret 4
```

Any clean that:

- calls with action as `this`, or
- uses element size ≠ 4, or
- folds host addref into this helper,

is **wrong**.

---

## 4. Surviving contract for AutoCore

```c
// Port of Host_ActionList_Push
struct HostActionVector {
  void **data;   // host+0x94
  int count;     // +0x98
  uint capacity; // +0x9c, low 31 bits
};

void Host_ActionList_Push(void *host, void *item) {
  auto *v = (HostActionVector *)((char *)host + 0x94);
  if (v->count == (int)(v->capacity & 0x7fffffff))
    GrowPointerVector(v, /*elemSize*/ 4); // FUN_005b3370
  v->data[v->count++] = item;
}
// Callers: when linking action→host, also host->refcount++
```

---

## 5. Open questions

1. Exact host C++ class across `Phys_ActionBase_ctor` / flipper / dual-host ctor.
2. High bit on capacity: "memory owned by custom heap" flag?
3. Symmetric remove helper address (dtor path).

**Verdict:** **accept**
