# Review B (skeptical / adversarial): `aa_0040b890` StdTree_Insert_IntKey_Isnil19_EaxEbx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040b890` |
| **VA** | `0x0040b890` |
| **Canonical name** | `StdTree_Insert_IntKey_Isnil19_EaxEbx_Inferred` |
| **Review date** | `2026-08-05` (R13-019 dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_0040b890_StdTree_Insert_IntKey_Isnil19_EaxEbx_Inferred.md` |
| **Live tools** | Independent `decompile_function` + `read_memory` + analyze/xrefs + `disassemble_function` + assembly context |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is inventory item-transfer / grab-drop product logic | **Falsified** — pure tree always-insert; only host is MissionTracker ranking temp map; partition label ≠ product role |
| 2 | thiscall ECX=map | **Falsified** — `MOV EDI,EAX`; call site loads map into **EAX**; ECX = where-parent for insert callee |
| 3 | InsertOrFind (equal key → inserted=0) | **Falsified** — no equality arm; `MOV BYTE PTR [EBP+4],1` unconditional |
| 4 | Unsigned key (`SETC`/`JNC`) | **Falsified** — **`SETL`** (signed) vs node+0x0C |
| 5 | isnil @ +0x29 / +0x15 / +0x21 / +0x31 | **Falsified** — nil guard **`+0x19`** only (`80 78 19 00`) |
| 6 | Same as isnil31 InsertOrFind `00402b30` | **Falsified** — different VA, isnil, key offset, always-insert vs unique find |
| 7 | RET 0 / RET 8 / multi-exit | **Falsified** — single **`RET 4`** (`C2 04 00`) |
| 8 | Multi-caller / data xref | **Falsified** — 1 UNCONDITIONAL_CALL from `0092b2a0` only |
| 9 | Mutates inventory grids / packets | **Falsified** — only tree insert helper + pair write |
| 10 | Runtime Confirmed | **Fails** — open; dual must stay `_Inferred` / non-terminal |

---

## 2. Decisive machine dataflow

```text
PUSH EBP
MOV  EBP, [ESP+8]         // out
PUSH EDI
MOV  EDI, EAX              // map from EAX
MOV  ECX, [EDI+4]         // head
MOV  EAX, [ECX+4]         // root
CMP  BYTE PTR [EAX+0x19],0
MOV  BYTE PTR [ESP+0xC],1 // goLeft=1
JNZ  skip_walk
PUSH ESI
MOV  ESI, [EBX]           // key = *value
loop:
  CMP  ESI, [EAX+0xC]     // signed vs key@+0x0C
  MOV  ECX, EAX            // where = cur
  SETL DL
  MOV  [ESP+0x10], DL     // goLeft
  JZ   go_right
  MOV  EAX, [EAX]         // left
  JMP  cont
go_right:
  MOV  EAX, [EAX+8]
cont:
  CMP  BYTE PTR [EAX+0x19],0
  JZ   loop
POP  ESI
skip_walk:
MOV  EAX, [ESP+0xC]
PUSH EBX                  // value*
PUSH EAX                  // goLeft
LEA  EDX, [ESP+0x14]
PUSH EDX                  // tmp out
CALL 0040bcd0             // EDI=map, ECX=where
MOV  EAX, [EAX]
MOV  [EBP], EAX           // out.it
POP  EDI
MOV  BYTE PTR [EBP+4], 1  // ALWAYS inserted
MOV  EAX, EBP
POP  EBP
RET  4
```

Call-site (MissionTracker fill @ `0x0092b4fc`):

```text
PUSH out                  // LEA [ESP+0x28]
LEA  EBX, value*          // key + val0 + val1 stack block
LEA  EAX, map_shell       // stack temp map
CALL 0x0040b890
```

A ≡ B on live decompile + body hex + xrefs + assembly context.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Always-insert CF | **High** | wrong map semantics / false unique-map port |
| isnil@+0x19 / key@+0x0C | **High** | wrong family merge |
| EAX map + EBX value* + RET 4 | **High** | stack smash / wrong port |
| Signed key | **High** | sort-order bugs |
| Caller set (1) | **High** | missing specialization |
| Product English | Medium | naming only |
| Runtime / bit-exact | **Open** | unverified live |

---

## 4. Surviving contract for AutoCore

```csharp
// Always-insert by signed int32 key in isnil@+0x19 tree (node size 0x1C)
// ABI: map in EAX, value* in EBX, out pair on stack, RET 4
InsertPair AlwaysInsert(MapShell map, Val value)
{
    // walk root..nil by signed key @ node+0x0C; track where-parent + goLeft
    // always InsertAndRebalance(0040bcd0)
    // return { newIt, inserted=true }  // never equal-key early-out
}
// Keep distinct from InsertOrFind peers (isnil15/21/29/31) and from inventory
// product handlers. Partition system inventory-transfer is queue assignment only.
```

**Runtime Confirmed: not claimed.**
