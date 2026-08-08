# Review B (skeptical / adversarial): `aa_00404360` StdTree_NodeCtor_Val32_Isnil31_EaxThis_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404360` |
| **VA** | `0x00404360` |
| **Canonical name** | `StdTree_NodeCtor_Val32_Isnil31_EaxThis_Inferred` |
| **Review date** | `2026-08-05` (R10-021) |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_00404360_StdTree_NodeCtor_Val32_Isnil31_EaxThis_Inferred.md` |
| **System** | STL / map-set node construct |
| **Verdict** | **accept-with-gaps** — agree with A |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + callers/xrefs + `read_memory` (no `disassemble_bytes`). No Launcher.

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_00404360` only | Scaffold OK; under-describes sealed role |
| `Named_CalleeOf_*NotifyActiveMission*` multi-hop plate | **Reject** — chain-of-caller plate; shared STL helper |
| Mission product / active-mission mutator | **Reject** — pure in-place construct; no mission IDs/strings |
| `StdTree_Buynode_Val32_Isnil31` (same as parent) | **Reject** — no `operator_new`; parent owns alloc |
| Merge Val24 isnil29 NodeCtor (`00409880`/`004098d0`) | **Reject** — Val32≠Val24; isnil@+0x31≠+0x29; color@+0x30≠+0x28; ABI ECX=left not value* |
| Merge Val16 isnil21 (`004099b0`) | **Reject** — different size/offsets |
| thiscall ECX=node | **Reject** — EAX=node; ECX=left; parent wire loads EAX=ESI |
| Freelist / placement-new buy | **Reject** — pure stores; no free-list head |
| `StdTree_NodeCtor_Val32_Isnil31_EaxThis_Inferred` | **Accept** — family-aligned; `_Inferred` honest |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| Decompiler void/__fastcall is full ABI | **Fails** — phantom `in_EAX` + caller sets EAX; epilogue `RET 0xC` |
| Value is 1 dword key only | **Fails** — `MOV ECX,8` + `REP MOVSD` |
| isnil set from color arg | **Fails** — hard `MOV byte [EAX+0x31],0` after color store |
| Same body as buynode parent | **Fails** — parent is SEH + new(0x38) + call this; this unit is leaf stores only |
| Product English proven | **Fails** — open; keep `_Inferred` |
| Multiple callers (mission fan-out) | **Fails** — sole xref `00403f86` |
| +0x0C holds a link/field written here | **Fails** — no store to [EAX+0xC] |

---

## 3. Cross-check against raw + bytes

```text
push esi
mov  esi, [esp+0xC]       ; value*
mov  [eax], ecx           ; left
mov  ecx, [esp+8]         ; right
push edi
mov  [eax+8], ecx         ; right
mov  [eax+4], edx         ; parent
mov  dl, [esp+0x14]       ; color
lea  edi, [eax+0x10]
mov  ecx, 8
rep  movsd                ; Val32
pop  edi
mov  [eax+0x30], dl       ; color
mov  byte [eax+0x31], 0   ; isnil
pop  esi
ret  0xC
```

Caller (parent buynode, sealed MEGA-048):
```text
push color; push value*; push right
mov edx, parent; mov ecx, left; mov eax, node
call 00404360
```

Clean must **not** invent freelist, mission semantics, isnil29 merge, buynode naming, or claim product demangle.

---

## 4. Agreement with Review A

- Store map + ABI + leaf + sole caller: **agree Confirmed/High**
- Name with `_Inferred` + `EaxThis` + `NodeCtor` (not Buynode): **agree**
- Gaps (PDB, runtime, insert residual): **agree open**

---

## 5. Surviving contract for AutoCore

```csharp
// In-place construct isnil@+0x31 / Val32 tree node (no alloc)
void NodeCtor_Val32_Isnil31(
    Node n, Node left, Node parent, Node right,
    ReadOnlySpan<uint> val8, byte color)
{
    n.Left = left; n.Parent = parent; n.Right = right;
    Copy(val8, n.Val32);           // +0x10, 8 dwords
    n.Color = color;               // +0x30
    n.IsNil = false;               // +0x31
}
// ABI: usercall node@eax, left@ecx, parent@edx, 3 stack args, RET 0xC
```

Port must keep **isnil@+0x31**, **Val32**, **EAX-this** — do not fold into isnil29 Val24 NodeCtor or into parent buynode.

---

## 6. Residual risks

- Do not merge with Val24 isnil29 ctors (`00409880` / `004098d0`) without layout/ABI check.
- Do not rename as buynode; parent `00403f30` owns `operator_new(0x38)`.
- Insert parent `FUN_00403250` residual (not OWN).

**Verdict:** **accept-with-gaps**
