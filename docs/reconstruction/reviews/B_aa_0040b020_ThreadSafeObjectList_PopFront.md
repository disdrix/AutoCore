# Review B (skeptical / adversarial): `aa_0040b020` ThreadSafeObjectList_PopFront

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040b020` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W24-S) |
| **Counterpart** | `reviews/A_aa_0040b020_ThreadSafeObjectList_PopFront.md` |
| **Scratch** | `tmp/a_0040b020.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is a refcount release on a COM object (not a list pop) | **Falsified** — head/tail/next linked list; push twin allocates 0xC nodes; dtor drains via loop on this function |
| 2 | Single critical section only | **Falsified** — outer always `+0x28`; inner `+0x10` when `count < 2` |
| 3 | Returns the node pointer | **Falsified** — returns `node[+4]` payload; node destroyed before return |
| 4 | Count is not atomic | **Falsified** — `InterlockedDecrement` on `+0xC` after CS leave |
| 5 | Empty list still locks | **Falsified** — early `return 0` before any `EnterCriticalSection` |
| 6 | Name is retail | **Overstated** — **Inferred**; Ghidra `FUN_0040b020`; list vtbl `PTR_FUN_009cb368` is sealed marker not product English |
| 7 | Prior alias “mission notify callee” is full identity | **Overstated** — one of many callers; skill multi-target + dtor are equal peers |
| 8 | SEH changes return domain | **Decomp artifact** — filter/cleanup leaves CS; normal returns payload or 0 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Pop-front CF | **High** | Use-after-free / lost objects |
| Dual CS offsets | **High** | Deadlock / races |
| Node 0xC layout | **High** | Wrong payload |
| ABI ECX-only | **High** | Stack corruption |
| Callers include skill + dtor | **High** | Missed coupling |
| Product type English | **Medium** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
if *(list+4)==0 return 0
EnterCS(list+0x28)
node=head; if count<2 EnterCS(list+0x10)
payload=node[1]; head=node[2]; if !head tail=0
node[1]=0; (*node.vtbl)(1)
Leave CS(s); InterlockedDec(count); return payload
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Push twin seals node size/fields; dtor twin seals CS pair teardown.

---

## 4. Surviving contract for AutoCore

```
// Thread-safe object list pop (payload ownership transfers to caller)
obj = ThreadSafeObjectList_PopFront(list)
// obj may be null (empty)
// node memory is released inside pop — do not free node
// concurrent push uses dual CS; do not reimplement without both CS + Interlocked count
// dtor path: while (PopFront()) { obj->Release/dtor(1); } then DeleteCriticalSection both
```

---

## 5. Verdict

Adversarial pass **confirms** A on full CF/ABI/layout; residual is product English only → **accept**.
