# Review B (skeptical / adversarial): `aa_00401fe0` StdTree_NodeCtor_StringByte_Isnil2D_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00401fe0` |
| **VA** | `0x00401fe0` |
| **Canonical name** | `StdTree_NodeCtor_StringByte_Isnil2D_Inferred` |
| **Review date** | `2026-08-05` (R10-004) |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_00401fe0_StdTree_NodeCtor_StringByte_Isnil2D_Inferred.md` |
| **System** | STL / map-set node construct |
| **Verdict** | **accept-with-gaps** — agree with A |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + caller/callee disasm (no `disassemble_bytes`). No Launcher.

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_00401fe0` only | Scaffold OK; under-describes sealed role |
| `Named_CalleeOf_*Nam_00401fe0` | **Reject** — chain-of-caller plate; shared STL helper |
| Mission null-dialog / product mutator | **Reject** — pure construct; no dialog IDs/strings in body |
| `StdTree_NodeCtor_Val24_Isnil29_*` merge (`00409880`/`004098d0`) | **Reject** — value is string+byte @+0x0c not Val24@+0x10; isnil@+0x2d≠+0x29 |
| `StdTree_BuyHeadNode_Isnil2D` merge (`00409780`) | **Reject** — head zeros / no value copy |
| thiscall ECX=node | **Reject** — ECX stores parent @+4; node is stack→ESI |
| pure `__fastcall` (decompiler label) | **Reject as complete ABI** — EDI value + RET 0xC stack cleanup |
| `set<string>` only (no mapped byte) | **Reject** — value helper copies byte @+0x1c of value |
| Allocates the node | **Reject** — no `operator_new`; buynode parent allocates |
| `StdTree_NodeCtor_StringByte_Isnil2D_Inferred` | **Accept** — family-aligned; `_Inferred` honest |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| Decompiler `__fastcall` 5-param form is full truth | **Fails** — EDI value implicit; stack node/left/color; `RET 0xC` |
| void return / no pointer | **Fails** — `MOV EAX,ESI` before cleanup; buynode uses return |
| Value is raw 8-dword blob | **Fails** — value helper is string copy ctor + 1 byte |
| isnil set from color arg | **Fails** — hard `MOV byte [ESI+0x2d],0` after `XOR EAX,EAX` |
| color store is at +0x2b / +0x28 | **Fails** — `MOV [ESI+0x2c],CL`; decompiler `param_3+0xb` = +0x2c |
| Multiple callers (mission fan-out) | **Fails** — sole xref `00401f94` |
| Same body as buynode | **Fails** — no alloc; construct-only |
| Product English proven | **Fails** — open; keep `_Inferred` |
| Partition parent `00401d30` is sole structural parent | **Fails as caller claim** — live caller is `00401f40`; `00401d30` is wave score parent / StringFlag twin context only |

---

## 3. Cross-check against raw + bytes

```text
SEH (9bc7ed); esi=node; eax=left
[esi]=left; [esi+4]=ecx parent; [esi+8]=edx right
lea eax,[esi+0xc]; push; call 00402040   ; EDI=value
xor eax,eax; cl=[esp+0x1c] color
[esi+0x2c]=cl; [esi+0x2d]=0
eax=esi; restore FS; pop esi; add esp,0xc; ret 0xc
```

Caller `FUN_00401f40` @ `0x00401f94`:
```text
push color; push left; push node
edi=value; edx=right; ecx=parent
call 00401fe0
```

Value `FUN_00402040`: string copy-ctor IAT + `MOV AL,[EDI+0x1c]; MOV [ESI+0x1c],AL` — seals mapped byte independently of this body's color/isnil stores.

Clean must **not** invent allocation, mission semantics, isnil29 merge, thiscall-ECX-node, or claim product demangle.

---

## 4. Agreement with Review A

- Construct CF + hybrid ABI + layout: **agree Confirmed/High**
- Name with `_Inferred`: **agree**
- Gaps (PDB, insert residual duals, runtime): **agree open**

---

## 5. Surviving contract for AutoCore

```csharp
// In-place construct isnil@+0x2d / 0x30 tree node with string + mapped byte value
void NodeCtor_StringByte_Isnil2D(Node n, Node parent, Node right, Node left,
                                 in StringByteVal value, byte color)
{
    n.Left = left; n.Parent = parent; n.Right = right;
    CopyString(value.Str, n.Str);   // +0x0c, 0x1c
    n.MappedByte = value.Byte;      // +0x28
    n.Color = color;                // +0x2c
    n.IsNil = 0;                    // +0x2d
}
// Native sites: ECX=parent, EDX=right, EDI=&value, stack n/left/color, RET 0xC
```

**Port note:** managed code may use an ordinary ctor; preserve hybrid register contract only at native call sites. Pair with dualed buynode `00401f40` and dualed value copy `00402040`. Do **not** implement as mission-dialog open.
