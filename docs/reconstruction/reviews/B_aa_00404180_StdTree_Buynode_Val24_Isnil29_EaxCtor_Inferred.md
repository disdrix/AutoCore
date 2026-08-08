# Review B (skeptical / adversarial): `aa_00404180` StdTree_Buynode_Val24_Isnil29_EaxCtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404180` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (WQ9K-C) |
| **Counterpart** | `reviews/A_aa_00404180_StdTree_Buynode_Val24_Isnil29_EaxCtor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `disassemble_function` + `read_memory` + callers/xrefs (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Decompiler call `FUN_00409880(param_2,param_3,param_5)` is complete ABI | **Falsified** — disasm passes EAX=node, ECX=value*, EDX=left + 3 stack; decomp incomplete |
| 2 | Same symbol as thiscall buynode `0x00407e30` | **Falsified** — different VA and different ctor ABI; do not merge |
| 3 | Thiscall on tree/map object (ECX=this) | **Falsified** — no ECX this on entry; stdcall RET 0x14 |
| 4 | Scaffold `Named_CalleeOf_*Client_RecvSpecial*` is product role | **Falsified** — chain-of-caller plate; CF is StdTree buynode |
| 5 | CNDHash freelist / recycle pool | **Falsified** — pure `operator_new(0x30)` + construct |
| 6 | Val12 / isnil21 family | **Falsified** — ctor stores Val24 @+0x10 and isnil@+0x29 |
| 7 | Insert does the rebalance | **Falsified** — only alloc+construct; rebalance lives in caller `004069f0` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Alloc size 0x30 | **High** | OOB / wrong node type |
| color@+0x28 / isnil@+0x29 | **High** | tree corruption |
| RET 0x14 / 5 stack args | **High** | stack imbalance |
| EAX-ctor pairing | **High** | wrong construct twin |
| Product English | Medium | naming only |
| Val24 type English | Low–Med | layout docs only |

---

## 3. Cross-check against raw + bytes

```
push ebp; mov ebp,esp; SEH
push 0x30; call operator_new
test esi,esi; jz null
  push color; push right; push parent
  mov ecx, value*; mov edx, left; mov eax, esi
  call 00409880
mov eax, esi; restore FS; ret 0x14
```

Caller `004069f0`:
```
call 00404180(head, where, head, value, 0)
size++
link + rebalance (color @ parent+0x28)
```

Clean must **not** invent freelist, thiscall-on-map, or fold into `00407e30` / `005a2de0`.

---

## 4. Surviving contract for AutoCore

```csharp
// Val24/isnil29 buynode via EAX-this ctor
Node BuyNode_Val24_Isnil29_EaxCtor(Node left, Node parent, Node right, Val24* v, byte color)
{
    var n = Alloc(0x30);
    if (n == null) return null;
    NodeCtor_EaxThis(n, v, left, parent, right, color); // isnil=0, color store
    return n;
}
```

Port must keep **stdcall RET 0x14** and pair with **EAX-this** ctor — not the thiscall buynode twin.

---

## 5. Open questions

1. Exact demangled map value_type for insert `004069f0`.  
2. Dual of insert parent.  
3. Runtime / bit-exact.

**Verdict:** **accept-with-gaps**
