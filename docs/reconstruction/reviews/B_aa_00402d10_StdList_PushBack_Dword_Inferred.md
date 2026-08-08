# Review B (skeptical / adversarial): `aa_00402d10` StdList_PushBack_Dword_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402d10` |
| **VA** | `0x00402d10`–`0x00402d41` |
| **Canonical name** | `StdList_PushBack_Dword_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Reviewer role** | OWN-ONLY dual **MEGA-126** Path B |
| **Counterpart** | `reviews/A_aa_00402d10_StdList_PushBack_Dword_Inferred.md` |
| **System** | shared MSVC `std::list` |
| **Live tools** | same live set as A (decompile / disasm / `read_memory` / xrefs); **no** `disassemble_bytes` |
| **Verdict** | **accept-with-gaps** |
| **Terminal** | **false** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Mission-debug exclusive helper | 7 xrefs include `FUN_00509010` + 5× `FUN_0057ade0` | **Falsified** — shared list utility; parent-seed name retired |
| 2 | `std::vector` grow / contiguous push | Allocates **0xC node** + circular Next/Prev links; size via list Incsize | **Falsified** as vector |
| 3 | Push-**front** (insert after head Next) | Bytes write **`[head+4]`** (Prev) and `old_prev->Next`; BuyNode sets `Next=head` | **Falsified** front — sealed as **push_back** |
| 4 | Payload by value in register only (EAX) like `00480350` | Stack formal `[ESP+4]` pushed as BuyNode arg3; sites `LEA`/`PUSH` address | **Falsified** EAX-only ABI |
| 5 | cdecl / no this | `MOV ESI,ECX`; Incsize reloads `MOV ECX,ESI`; **`RET 4`** | **Falsified** — thiscall list* |
| 6 | `RET 0` / plain RET | Epilogue `C2 04 00` | **Falsified** |
| 7 | Leaf | Calls `00418700` + `00404840` | **Falsified** leaf |
| 8 | Incsize never throws | Callee path builds `"list<T> too long"` + `_CxxThrowException` / `DAT_00acc388` | **Falsified** no-throw claim |
| 9 | Node embeds full mission/object blob | BuyNode copies **one dword** `*pValue` to `node+8` | **Falsified** bulk embed |
| 10 | Merge with `StdList_PushPayloadNode` `00480350` as identical ABI | Peer uses **EAX** payload + different BuyNode/Incsize VAs | **Falsified** merge — same splice, different ABI/callees |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| List head `+4` / size `+8` | **High / Sealed** | Wrong container port |
| 0xC node dword payload | **High / Sealed** | Over-size node / wrong value width |
| Push-back splice | **High / Sealed** | Iterator order / front-vs-back bugs |
| thiscall + RET 4 | **High / Sealed** | Stack corruption on port |
| Shared multi-caller | **High / Sealed** | Wrong domain ownership |
| Product `T` name | **Tentative** | Misnamed mission-only API |
| Null-new path | **Open** | Crash if `new` fails |
| Runtime | **Open** | — |

---

## 3. Cross-check

```
raw 2026-07-23 ≡ live decompile 2026-08-05
disasm ≡ read_memory hex seal (50 B) ≡ RET 4
FUN_00418700: new(0xC); node={head, head->Prev, *pValue}; RET 0xC
FUN_00404840: if 0x3fffffff - size < n → throw "list<T> too long"; else size += n; RET 4
Parents: DebugListMissionsStatus, FUN_00509010 (&item), FUN_0057ade0 ×5
```

### Mission-name trap

Do **not** keep `Named_CalleeOf_Client_DebugListMissionsStatus_*` as canonical. Partition hint is consumer context only.

### Vector trap

Do **not** model as `vector<T>` reallocation. This is circular sentinel list of **pointer-sized** values.

### Front/back trap

Sibling `StdList_PushPayloadNode` review noted Medium front-vs-back. This unit’s bytes seal **Prev-at-head** update → **push_back**. Do not rename to PushFront without new evidence.

### Null-new trap

`FUN_00418700` returns 0 on failed `operator_new`; this unit still stores through `node`. Port may crash on OOM — matches retail risk, not a reconstruction gap in CF.

---

## 4. Surviving contract for AutoCore

```
StdList_PushBack_Dword_Inferred(list /*ECX*/, const uint32_t* pValue /*stack*/):
  head = list->_Myhead                 // *(list+4)
  node = BuyNode(head, head->_Prev, pValue)  // FUN_00418700
  list->_Incsize(1)                    // FUN_00404840 — may throw
  head->_Prev = node
  node->_Prev->_Next = node
  // RET 4

AutoCore must NOT:
  - treat as vector growth
  - invent mission-only ownership
  - pass payload by value in EAX (that is 00480350 peer)
  - skip Incsize overflow throw path
  - embed full object into the 0xC node (only dword/pointer)
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| MSVC list push_back of dword via pValue* | **Agree High/Sealed** |
| ABI thiscall RET 4 | **Agree High/Sealed** |
| Callees BuyNode + Incsize | **Agree High/Sealed** |
| Shared multi-caller (not Debug-only) | **Agree High/Sealed** |
| Product T open → `_Inferred` | **Agree** |
| accept-with-gaps | **Agree** |

**Verdict:** Adversarial path falsifies mission-only / vector / push-front / EAX-payload / wrong-RET claims. Structural contract stands. **accept-with-gaps.**
