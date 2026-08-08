# Review B (skeptical / adversarial): `aa_004040f0` StdList_InsertOne_BeforeNode_Dword_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004040f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY **R10-005**) |
| **Counterpart** | `reviews/A_aa_004040f0_StdList_InsertOne_BeforeNode_Dword_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Mission/debug-specific helper (`Named_CalleeOf_*DebugListMissions*`) | **Falsified** — pure buy+inc+splice; no mission strings; callers are InsertN + insert-range STL wrappers; BuyNode has **61** multi-domain xrefs |
| 2 | Standard **cdecl** / no stack cleanup | **Falsified** — epilogue **`RET 0x8`**; ECX thiscall list |
| 3 | Entry ECX is **where** or **val** (not list) | **Falsified** — `MOV EDI,ECX` then Incsize `MOV ECX,EDI`; callers load list into ECX before CALL |
| 4 | Insert **after** node / push_front only | **Falsified** — rewires `where->_Prev` and `node->_Prev->_Next` (insert **before** where). Push_front would use where=head->next pattern; push_back twin hardcodes where=head |
| 5 | Vector / tree / map insert | **Falsified** — BuyNode `0xC` circular links + `"list<T> too long"` Incsize family |
| 6 | Element size ≠ dword | **Falsified for this chain** — `operator_new(0xC)` copies one dword from `*val` |
| 7 | Decompiler signature complete as printed | **Clarify** — missing list this; Incsize this elided; stack args are (where, val*) not (list, val) |
| 8 | Sole caller / single-use debug path | **Falsified** — **3** CALL xrefs; 2 named parents + orphan site |
| 9 | Identical to push_back `00402d10` (no free where) | **Falsified as same symbol** — same *splice*, but `where` is a stack formal here; push_back loads head from `list+4` |
| 10 | Runtime Confirmed | **Fails** — open (no Launcher) |
| 11 | Safe under null BuyNode | **Open residual** — no null check before rewire (same as push_back dual gap) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Insert-one before node CF | **Confirmed** | Wrong container op in ports |
| ECX=list / stack where,val / RET 0x8 | **Confirmed** | Stack imbalance / bad this |
| List family via Incsize string + 0xC node | **High** | Mis-tag as vector |
| Dword payload | **High** | Wrong element width |
| Not mission product English | **Confirmed** | Misleading system maps |
| Exact CRT demangle spelling | **Low** | Name residual only (`_Inferred`) |
| Null-new link safety | **Open** | Crash path on OOM |
| Runtime / bit-exact | **Open** | no Launcher |

---

## 3. Cross-check against raw / bytes

```text
raw 2026-07-23 ≡ live decompile 2026-08-05 CF
asm 2026-08-05 seals ABI (overrides decompiler list-this elision)

8B 44 24 08          MOV EAX,[ESP+8]     ; val*
53                   PUSH EBX
8B 5C 24 08          MOV EBX,[ESP+8]     ; where*
56 57                PUSH ESI / EDI
8B F9                MOV EDI,ECX         ; list*
8B 4B 04             MOV ECX,[EBX+4]     ; where->prev
50 51 53             PUSH val / prev / where
8B CF E8 …           CALL BuyNode 00418700
6A 01 8B CF 8B F0    PUSH 1; ECX=list; ESI=node
E8 …                 CALL Incsize 00404840
89 73 04             where->prev = node
8B 56 04 5F 89 32    node->prev->next = node
5E 5B C2 08 00       RET 0x8

Caller 004034fc:
  PUSH EBX (val*) / PUSH EDI (where) / MOV ECX,[EBP+8] (list) / CALL 004040f0

Caller 004045a0:
  LEA EAX,[ESI+8] / PUSH EAX / PUSH EDI / MOV ECX,EBX / CALL 004040f0
```

Reject ports that:

- Keep `Named_CalleeOf_*DebugListMissions*` as the primary name.
- Treat entry ECX as where/val instead of list.
- Use cdecl without popping 8 stack bytes.
- Model this as vector `insert` or tree rebalance.
- Assume multi-word element copy inside this VA (copy is in BuyNode).
- Collapse this symbol into push_back without a free `where` formal.

---

## 4. Surviving contract for AutoCore

```csharp
// Retail: std::list<uint32_t>-family insert before node (one element)
// Port: insert *val immediately before `where` (where==sentinel ⇒ push_back).

void StdListInsertOneBeforeNodeDword(
    StdListDword list,      // this
    ListNodeDword where,
    uint val)               // by value or const ref — BuyNode derefs pointer
{
    // node = new Node { Next=where, Prev=where.Prev, Myval=val }
    // size++; guard size <= 0x3fffffff else throw "list<T> too long"
    // where.Prev = node; node.Prev.Next = node;
}
```

Pair with: BuyNode `00418700`, Incsize `00404840`, InsertN `004034c0`, PushBack `00402d10`, insert-range `00404560`.

---

## 5. Verdict

Path B attacks on mission-only naming, wrong ABI, after-insert, vector/tree, and sole-caller claims are **falsified**. Core CF/ABI/list-family sealed. Remaining gaps (demangle English, null-new, runtime, Incsize dual formalization) do **not** block accept-with-gaps.

**Verdict:** **accept-with-gaps**
