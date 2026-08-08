# Review B (skeptical / adversarial): `aa_005a2de0` StdTree_Buynode_Isnil29_Val24_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a2de0` |
| **VA** | `0x005a2de0` |
| **Canonical name** | `StdTree_Buynode_Isnil29_Val24_Inferred` |
| **Review date** | `2026-08-04` (WQ9F-A dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_005a2de0_StdTree_Buynode_Isnil29_Val24_Inferred.md` |
| **Live tools** | Independent `batch_decompile` + `read_memory` + callers |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | True `void` return (decomp signature) | **Falsified** — insert uses EAX as node*; null path returns EAX=0 |
| 2 | `thiscall` / ECX map | **Falsified** — pure stack args; `ret 0x14`; no ECX use |
| 3 | Val12 buynode twin (`0x005ae220`) | **Falsified** — size **0x30** not 0x1c; isnil@**+0x29** not +0x19; 6 not 3 dwords |
| 4 | Skill-gather product leaf (old scaffold name) | **Falsified** — 3 generic insert shells; no skill string/RTTI here |
| 5 | Writes value at `+0x0c` (Val12 layout) | **Falsified** — value starts at **+0x10** (`lea edx,[eax+0x10]`) |
| 6 | Always non-null / throws on OOM | **Falsified** — `jz` skip init; returns null |
| 7 | Sets isnil=1 (nil sentinel ctor) | **Falsified** — `mov byte [eax+0x29],0` |
| 8 | Sole caller `004cbb60` | **Fails partial** — **3** callers; still same buynode role |
| 9 | Product demangle sealed | **Fails** — `_Inferred` |
| 10 | Runtime Confirmed | **Fails** — no Launcher |

---

## 2. Decisive machine dataflow

```text
push 0x30
call operator_new
add esp,4
test eax,eax
jz epilogue          // EAX already 0
// init from stack args
[eax+0]  = left
[eax+4]  = parent
[eax+8]  = right
// copy 6 dwords value → [eax+0x10 .. +0x24]
[eax+0x28] = color
[eax+0x29] = 0
epilogue:
pop esi (if pushed)
ret 0x14
```

Caller insert context (`004cbbf2` family):

```text
// after size-guard
call FUN_005a2de0(head, where, head, value, color=0)
// EAX = new node; size++; link; RB rebalance
```

A ≡ B. Scaffold “Skill_GatherTarget” name is **path noise**, not product identity.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Buy size/layout/isnil | **High** | Corrupt tree nodes on insert |
| RET 0x14 stdcall | **High** | Stack imbalance |
| Not Val12 merge | **High** | Wrong port template |
| Value English / key split | **Open** | Field naming only |
| Extra insert shells dual | **Open** | Same buynode; shells not OWN |

---

## 4. Surviving contract

- **`__stdcall`**, 5 args, **`ret 0x14`**, **EAX=node***.
- `operator_new(0x30)`; L/P/R; Val24 @+0x10; color@+0x28; isnil=0@+0x29.
- Shared by isnil29 insert family (`004cbb60` + twins).
- **Terminal false**.

**Verdict:** **accept-with-gaps**
