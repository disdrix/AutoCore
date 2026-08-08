# Review B (skeptical / adversarial): `aa_00403f30` StdTree_Buynode_Val32_Isnil31_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00403f30` |
| **VA** | `0x00403f30` |
| **Canonical name** | `StdTree_Buynode_Val32_Isnil31_Inferred` |
| **Review date** | `2026-08-05` (MEGA-048) |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_00403f30_StdTree_Buynode_Val32_Isnil31_Inferred.md` |
| **System** | STL / map-set buynode |
| **Verdict** | **accept-with-gaps** — agree with A |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs (no `disassemble_bytes`). No Launcher.

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_00403f30` only | Scaffold OK; under-describes sealed role |
| `Named_CalleeOf_*NotifyActiveMission*` | **Reject** — chain-of-caller plate; shared STL helper |
| Mission product / active-mission mutator | **Reject** — pure alloc+construct; no mission IDs/strings |
| `StdTree_Buynode_Val24_Isnil29` merge (`00407e30`) | **Reject** — size 0x38≠0x30; isnil@+0x31≠+0x29; Val32≠Val24 |
| `StdTree_BuyHeadNode_Isnil31` merge (`00409180`) | **Reject** — head zeros links / no value copy / no stack args |
| Placement-new freelist buy | **Reject** — CRT `operator_new(0x38)` |
| thiscall ECX=map | **Reject** — pure stack; RET 0x14 |
| `StdTree_Buynode_Val32_Isnil31_Inferred` | **Accept** — family-aligned; `_Inferred` honest |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| Decompiler 3-arg ctor is full truth | **Fails** — asm loads all 5 params + EAX-in-EAX |
| void return / no pointer | **Fails** — `MOV EAX,ESI` before `RET 0x14`; caller stores EAX |
| Value is 1 dword key only | **Fails** — ctor `REP MOVSD` ECX=**8** |
| isnil set from color arg | **Fails** — hard `MOV byte [EAX+0x31],0` |
| Same body as insert parent | **Fails** — tiny alloc helper only; insert does rebalance |
| Product English proven | **Fails** — open; keep `_Inferred` |
| Multiple callers (mission fan-out) | **Fails** — sole xref `004032b6` |

---

## 3. Cross-check against raw + bytes

```text
SEH (9bc781); push 0x38; operator_new
test esi; jz skip
  push color/value/right; ecx=left; edx=parent; eax=esi
  call FUN_00404360
skip:
mov eax,esi; restore FS; pop*; ret 0x14
```

Caller:
```text
push 0; push value; push head; push where; push head
call 00403f30
mov ecx,eax          ; node*
add [tree+8],1       ; size++
```

Clean must **not** invent freelist, mission semantics, isnil29 merge, or claim product demangle.

---

## 4. Agreement with Review A

- Alloc/construct CF + ABI + layout: **agree Confirmed/High**
- Name with `_Inferred`: **agree**
- Gaps (PDB, ctor/insert residual duals, runtime): **agree open**

---

## 5. Surviving contract for AutoCore

```csharp
// Allocate isnil@+0x31 / 0x38 tree node with Val32 payload
Node BuyNode_Val32_Isnil31(Node left, Node parent, Node right, ReadOnlySpan<uint> val8, byte color)
{
    var n = Alloc(0x38);
    if (n == null) return null;
    n.Left = left; n.Parent = parent; n.Right = right;
    Copy(val8, n.Val32);           // +0x10, 8 dwords
    n.Color = color;               // +0x30
    n.IsNil = false;               // +0x31
    return n;
}
// ABI: stdcall, 5 stack args, RET 0x14, EAX = node*|null
```

Port must keep **isnil@+0x31**, **size 0x38**, **Val32** — do not fold into isnil29 0x30 Val24 buynode.

---

## 6. Residual risks

- Do not merge with Val24 isnil29 (`00407e30` / `005a2de0`) or BuyHead (`00409180`) without layout/ABI check.
- Ctor `FUN_00404360` and insert parent `FUN_00403250` undualed residuals (not OWN).

**Verdict:** **accept-with-gaps**
