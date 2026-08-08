# Review B (skeptical / adversarial): `aa_00402b30` StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402b30` |
| **VA** | `0x00402b30` |
| **Canonical name** | `StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx_Inferred` |
| **Review date** | `2026-08-05` (MEGA-040 dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00402b30_StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx_Inferred.md` |
| **Live tools** | Independent `decompile_function` + `read_memory` + analyze/xrefs + `disassemble_function` + assembly context |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is mission-specific `NotifyActiveMissionChanged` logic | **Falsified** — pure STL insert-or-find; only host is mission UI; 3 map-helper xrefs |
| 2 | thiscall ECX=map | **Falsified** — `MOV EDI,EAX`; call sites load map into **EAX**; ECX used only as insert where-node |
| 3 | Signed int key (`SETL`) | **Falsified** — **`SETC`** / **`JNC`** (unsigned) |
| 4 | isnil @ +0x29 / +0x15 / +0x21 | **Falsified** — nil guard **`+0x31`** only (`80 78 31 00`) |
| 5 | Same as isnil29 InsertOrFind `004cbe20` | **Falsified** — different VA, isnil offset, ABI (that peer is thiscall RET 8) |
| 6 | Same as isnil15 EaxEbx `00458510` | **Falsified** — same ABI shape, different isnil/key offsets (15/0x0C vs 31/0x10) |
| 7 | Equal key rewrites mapped value | **Falsified** — hit path only stores `it` + `inserted=0` |
| 8 | RET 0 / RET 8 | **Falsified** — three **`RET 4`** exits (`C2 04 00`) |
| 9 | Lower_bound only (no insert) | **Falsified** — two `CALL 00403250` insert paths |
| 10 | Runtime Confirmed | **Fails** — open |

---

## 2. Decisive machine dataflow

```text
MOV EDI, EAX              // map from EAX
MOV ESI, [EDI+4]          // head
MOV EAX, [ESI+4]          // root
CMP BYTE PTR [EAX+0x31],0 // isnil31
...
MOV EDX, [EBX]            // key = *value
CMP EDX, [EAX+0x10]       // vs node.key
SETC CL                   // unsigned less
// left = [EAX], right = [EAX+8]
...
// insert paths:
PUSH EBX                  // value*
PUSH addLeft
LEA  ..., [local hint]
PUSH ...
MOV  ECX, ESI             // where node
CALL 00403250
// equal:
MOV [EBP], EAX            // out.it
MOV BYTE PTR [EBP+4], 0   // inserted=0
MOV EAX, EBP
RET 4
```

Call-site (NotifyActiveMissionChanged @ `0x00944802`):

```text
LEA  EAX, [EDI+0xf14]     // map = client+0xf14
LEA  EBX, [ESP+…]         // value* (key dword0 = mission*)
PUSH out_pair
CALL 0x00402b30
```

A ≡ B on live decompile + body hex + xrefs + assembly context.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Insert-or-find CF | **High** | wrong map semantics |
| isnil@+0x31 / key@+0x10 | **High** | wrong family merge |
| EAX map + EBX value* + RET 4 | **High** | stack smash / wrong port |
| Unsigned key | **High** | sort-order bugs |
| Caller set (3) | **High** | missing specialization |
| Product English | Medium | naming only |

---

## 4. Surviving contract for AutoCore

```csharp
// Insert-or-find by uint32 key in isnil@+0x31 map (node size 0x38)
// ABI: map in EAX, value* in EBX, out pair on stack, RET 4
InsertPair InsertOrFind(MapShell map, Val value)
{
    // walk root..nil by unsigned key @ node+0x10
    // miss → InsertAndRebalance(00403250)
    // hit  → { existing, inserted=false }  // no mapped rewrite
}
// Keep distinct from isnil15/21/29 InsertOrFind peers and from mission UI parent.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/caller roles/unsigned key. Residual product map English + unOWN insert/pred duals → **accept-with-gaps**.
