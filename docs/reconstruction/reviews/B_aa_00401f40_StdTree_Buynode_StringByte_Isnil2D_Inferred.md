# Review B (skeptical / adversarial): `aa_00401f40` StdTree_Buynode_StringByte_Isnil2D_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00401f40` |
| **VA** | `0x00401f40` |
| **Canonical name** | `StdTree_Buynode_StringByte_Isnil2D_Inferred` |
| **Review date** | `2026-08-05` (MEGA-079) |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_00401f40_StdTree_Buynode_StringByte_Isnil2D_Inferred.md` |
| **System** | STL / map-set buynode |
| **Verdict** | **accept-with-gaps** — agree with A |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + parent/callee disasm (no `disassemble_bytes`). No Launcher.

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_00401f40` only | Scaffold OK; under-describes sealed role |
| `Named_CalleeOf_*Mis_00401f40` | **Reject** — chain-of-caller plate; shared STL helper |
| Mission null-dialog / product mutator | **Reject** — pure alloc+construct; no dialog IDs/strings in body |
| `StdTree_Buynode_Val24_Isnil29` merge (`00404180`/`00407e30`) | **Reject** — value is string+byte @+0x0c not Val24@+0x10; isnil@+0x2d≠+0x29 |
| `StdTree_Buynode_Val32_Isnil31` merge (`00403f30`) | **Reject** — size 0x30≠0x38; isnil@+0x2d≠+0x31 |
| `StdTree_BuyHeadNode_Isnil2D` merge (`00409780`) | **Reject** — head zeros links / no value copy / different ABI |
| Placement-new freelist buy | **Reject** — CRT `operator_new(0x30)` |
| thiscall ECX=map | **Reject** — pure stack; RET 0x14 |
| `set<string>` only (no mapped byte) | **Reject** — value helper copies byte @+0x1c of value |
| `StdTree_Buynode_StringByte_Isnil2D_Inferred` | **Accept** — family-aligned; `_Inferred` honest |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| Decompiler 1-arg form is full truth | **Fails** — asm loads 5 stack slots; `RET 0x14` |
| void return / no pointer | **Fails** — `MOV EAX,ESI` before `RET 0x14`; caller stores EAX |
| Value is raw 8-dword blob | **Fails** — value helper is string copy ctor + 1 byte |
| isnil set from color arg | **Fails** — hard `MOV byte [ESI+0x2d],0` after `XOR EAX,EAX` |
| Same body as insert parent | **Fails** — tiny alloc helper only; insert does rebalance + size++ |
| Product English proven | **Fails** — open; keep `_Inferred` |
| Multiple callers (mission fan-out) | **Fails** — sole xref `00401e16` |
| OOM returns garbage | **Fails** — ESI null → EAX null; ctor skipped |

---

## 3. Cross-check against raw + bytes

```text
SEH (9bc811); push 0x30; operator_new
test esi; jz skip
  push color; push left; push node
  edi=value; edx=right; ecx=parent
  call FUN_00401fe0
skip:
mov eax,esi; restore FS; pop*; ret 0x14
```

Caller `FUN_00401db0` @ `0x00401e16`:
```text
push 0                 ; color = red
push value             ; EDX from [ESP+0x60] pre-push
push head              ; [EDI+4]
push where             ; ESI
push head
call 00401f40
mov ecx,eax            ; node*
add [EDI+8],1          ; size++
; rebalance uses color @ node+0x2c; rotates 0044e010 / 0042a840
```

Insert-or-find parent `FUN_00401c50` walks isnil@**+0x2d** and compares `basic_string` at node+0xc — seals family + value shape independently of buynode body.

Clean must **not** invent freelist, mission semantics, isnil29/31 merge, or claim product demangle.

---

## 4. Agreement with Review A

- Alloc/construct CF + ABI + layout: **agree Confirmed/High**
- Name with `_Inferred`: **agree**
- Gaps (PDB, ctor/value/insert residual duals, runtime): **agree open**

---

## 5. Surviving contract for AutoCore

```csharp
// Allocate isnil@+0x2d / 0x30 tree node with string + mapped byte value
Node BuyNode_StringByte_Isnil2D(Node left, Node parent, Node right,
                                in StringByteVal value, byte color)
{
    var n = Alloc(0x30);
    if (n == null) return null;
    n.Left = left; n.Parent = parent; n.Right = right;
    CopyString(value.Str, n.Str);   // +0x0c, 0x1c
    n.MappedByte = value.Byte;      // +0x28
    n.Color = color;                // +0x2c
    n.IsNil = false;                // +0x2d
    return n;
}
// ABI: stdcall, 5 stack args, RET 0x14, EAX = node*|null
```

Port must keep **isnil@+0x2d**, **size 0x30**, **string+byte @+0x0c** — do not fold into isnil29 Val24 or isnil31 Val32 buynodes.

---

## 6. Residual risks

- Do not merge with Val24 isnil29 (`00404180` / `00407e30`), Val32 isnil31 (`00403f30`), or BuyHead (`00409780`) without layout/ABI check.
- Ctor `FUN_00401fe0`, value `FUN_00402040`, insert `FUN_00401db0` undualed residuals (not OWN).
- Mapped-type English (bool vs char vs flag) unproven beyond **1 byte** width.

**Verdict:** **accept-with-gaps**
