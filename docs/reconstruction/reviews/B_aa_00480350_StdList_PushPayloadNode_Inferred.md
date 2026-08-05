# Review B (skeptical / adversarial): `aa_00480350` StdList_PushPayloadNode_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00480350` |
| **VA** | `0x00480350` |
| **Canonical name** | `StdList_PushPayloadNode_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00480350_StdList_PushPayloadNode_Inferred.md` |
| **System** | client audio / `CSoundManager` queue list |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Vector / array push (`push_back` grow buffer) | Allocates **0xC node** + link pointers; size via list helper | **Falsified** as vector |
| 2 | Inserts the freelist slot by value copy of 0x160 | Node stores **one dword** payload (`node[2]=*param_3`) | **Falsified** bulk-copy claim |
| 3 | Payload is stack formal | Decompiler `in_EAX` into node ctor | **Falsified** stack-payload |
| 4 | Leaf | Calls `006759b0`, `0043fe60` | **Falsified** leaf |
| 5 | Mission / FailMission helper | Only audio queue parents in xrefs | **Falsified** mission role |
| 6 | Can OOM silently | `006759b0` returns null on failed new; body still links | **Risk open** — null link not guarded here |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| List head at `list+4` | **Confirmed** | Wrong container offset |
| 0xC node + dword payload | **Confirmed** | Port as full slot embed |
| Size++ path | **Confirmed** | Miss throw-on-overflow |
| Audio `+0x310` usage | **High** | Wrong manager field |
| Front vs back naming | **Medium** | Iterator order wrong |
| Null-new safety | **Open** | Crash if `new` fails |

---

## 3. Cross-check

```
raw ≡ live (2026-07-29).
FUN_006759b0: new(0xC); node={p1,p2,*p3}
FUN_0043fe60: if size would exceed 0x3fffffff → throw "list<T> too long"; else size += n
Parents: FUN_00480350(param_1 + 0x310) after slot fill
```

### Vector trap

Do **not** model as `vector<Slot>` contiguous growth. This is **pointer list of slots**.

### Payload trap

Freelist slot lives on aligned heap; list only holds the **pointer**.

---

## 4. Surviving contract for AutoCore

```
StdList_PushPayloadNode(list, payload_ptr_in_EAX):
  head = list->_Myhead            // *(list+4)
  node = new ListNode{ head, head->next, payload }
  list->_Mysize++                 // via 0043fe60 (may throw)
  splice node after head

CSoundManager queue: list @ manager+0x310

AutoCore must NOT:
  - memcpy entire 0x160 slot into the list node
  - treat as vector reallocation
  - invent mission semantics from historical name noise on siblings
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| MSVC list insert of EAX payload | **Agree Confirmed** |
| Callees node-new + size++ | **Agree Confirmed** |
| Audio queue at +0x310 | **Agree High** |
| Front naming Medium | **Agree** |
| accept-with-gaps | **Agree** |
