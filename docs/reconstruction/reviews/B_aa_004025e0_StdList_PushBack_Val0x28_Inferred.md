# Review B (skeptical / adversarial): `aa_004025e0` StdList_PushBack_Val0x28_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004025e0` |
| **VA** | `0x004025e0` |
| **Canonical name** | `StdList_PushBack_Val0x28_Inferred` |
| **Review date** | `2026-08-05` (MEGA-059 dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_004025e0_StdList_PushBack_Val0x28_Inferred.md` |
| **Live tools** | Independent `decompile_function` + `read_memory` + analyze/xrefs + `disassemble_function` + parent call-site disassembly |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Security cookie / epilogue helper (prior TransferMap gap) | **Falsified** — real list splice; 2 CALL callees; `RET 4`; sole xref from TransferMap mid-body |
| 2 | `std::map` / tree insert / rebalance | **Falsified** — no rotate/color/isnil; list string `"list<T> too long"` in Incsize; circular prev/next only |
| 3 | CsSList / critical-section queue (`004024d0` family) | **Falsified** — no CS, no vtbl node `009cb340`, node size 0x30 not 0xC |
| 4 | Push-front (insert after head Next) | **Falsified** — loads `head[+4]` as prev, stores `head[+4]=node`, `*(node[+4])[+0]=node` → insert **before** sentinel = **push_back** (MSVC `_Insert(_Myhead)`) |
| 5 | Fastcall / no stack cleanup / void no-arg | **Falsified** — `MOV EAX,[ESP+4]`; **`RET 4`**; thiscall ECX=list |
| 6 | ECX unused / static free function | **Falsified** — `MOV ESI,ECX`; Incsize `MOV ECX,ESI`; call site `LEA ECX,[EDI+0xe778]` |
| 7 | Element size dword / 0xC node | **Falsified** — buynode `PUSH 0x30` / `operator_new(0x30)`; ctor `MOV ECX,0xA` REP MOVSD; max **`0x6666666` = 0xFFFFFFFF/0x28** |
| 8 | Product name `CVOGReaction_*` for this VA | **Falsified** as unit name — shared STL helper; reaction is sole **caller**, not the function identity |
| 9 | Runtime Confirmed | **Fails** — open (no Launcher) |

---

## 2. Decisive machine dataflow

```text
MOV EAX, [ESP+4]        // value*
MOV ESI, ECX            // list*
MOV EDI, [ESI+4]        // head
MOV ECX, [EDI+4]        // head->_Prev
PUSH EAX / PUSH ECX / PUSH EDI
CALL FUN_00403560       // Buynode0x30; RET 0xC
PUSH 1 / MOV ECX,ESI
CALL FUN_00403600       // Incsize; max 0x6666666; RET 4
MOV [EDI+4], EBX        // head->_Prev = node
MOV EDX, [EBX+4]
MOV [EDX], EBX          // old_prev->_Next = node
RET 4
```

Call-site (`CVOGReaction_TransferMap` @ `0x004d3893`):

```text
// build 0x28-byte local at [ESP+0x10..]
LEA ECX, [ESP+0x10]
PUSH ECX                // value*
LEA ECX, [EDI+0xe778]   // list embed
CALL 0x004025e0
```

A ≡ B on live decompile + body hex + xrefs + parent assembly.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| List push_back CF | **High** | wrong container port |
| T size 0x28 / node 0x30 | **High** | allocator/size mismatch |
| thiscall + RET 4; ECX=list | **High** | stack smash |
| Sole caller + list @ +0xe778 | **High** | missing specialization |
| Product T English | Medium | naming only |

---

## 4. Surviving contract for AutoCore

```csharp
// MSVC std::list push_back for T size 0x28 (node 0x30)
void PushBack(ListShell list, in Val0x28 value)
{
    var head = list.Myhead;
    var node = BuyNode(head, head.Prev, value); // new 0x30; copy 10 dwords
    Incsize(list, 1); // throw if size would exceed 0x6666666
    head.Prev = node;
    node.Prev.Next = node;
}
// RET 4 at call boundary. List at CVOGReaction+0xe778 for sole known parent.
// Keep distinct from dword PushPayloadNode and CsSList append.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/caller roles. Residual product T English → **accept-with-gaps**.
