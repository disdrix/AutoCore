# Function record: CNDHash_TraverseToNext_RegEdiEsi

| Field | Value |
|---|---|
| **Stable ID** | `aa_00411e40` |
| **Canonical name** | `CNDHash_TraverseToNext_RegEdiEsi` |
| **Ghidra name** | `FUN_00411e40` |
| **Address** | `0x00411e40`–`0x00411e80` inclusive (**65 B** / `0x41`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | interaction-activation / CNDHash container |
| **Partition** | MEGA-114 (parent `Client_UpdateNpcInteractIcons` `0x0091b8d0`) |
| **Completion status** | **Dual sealed MEGA-114** |
| **Dual verdict** | **accept-with-gaps** (A + B) |
| **Bit-for-bit / runtime / diff** | Open — Terminal **false** |

## Naming

| Name | Status |
|---|---|
| `CNDHash_TraverseToNext_RegEdiEsi` | **Canonical** — HashError string seals TraverseToNext; `RegEdiEsi` marks register ABI vs thiscall twin |
| `FUN_00411e40` | Ghidra default (kept as twin clean) |
| `Named_VOG_DEBUG_STOP_00411e40` | **Retired** scaffold |

## Twin

| VA | Name | ABI |
|---|---|---|
| `0x00411900` | `CNDHash_TraverseToNext` (dualed) | thiscall ECX=hash, stack cursor*, **RET 4** |
| `0x00411e40` | **this unit** | **EDI**=hash, **ESI**=cursor*, bare **RET** |

CF/offsets/strings identical; calling convention differs.

## Purpose

Ordered-list iterator step for CNDHash under TraversalLock:

1. Soft-assert lock @ **hash+0x1d** (log + continue if clear).
2. Seed cursor from **hash+0x14** or advance via **node+0x14**.
3. Return **payload** @ **node+8**, or **0**.

No membership / lock / freelist mutation.

## Signature

```c
// Register convention (MSVC freestanding helper):
//   IN  EDI = CNDHash* hash
//   I/O ESI = node** cursor
//   OUT EAX = void* payload @ node+8, or NULL
//   bare RET
uint32_t CNDHash_TraverseToNext_RegEdiEsi(void);
```

## Offsets (0x1c-class node family)

| Offset | Field |
|---|---|
| hash+0x1d | TraversalLock byte |
| hash+0x14 | list head node* |
| node+0x14 | list-next node* |
| node+0x08 | value / payload (returned) |

## Call graph

```text
Client_UpdateNpcInteractIcons  0x0091b8d0  [partition parent; not dualled here]
  ├─ FUN_00411e10   TraversalLock reg (ESI=hash)   [not dualled]
  ├─ FUN_00411e40   CNDHash_TraverseToNext_RegEdiEsi  [OWN MEGA-114]
  │     └─ FUN_007a4480  log
  └─ clear lock @ hash+0x1d

Other callers: FUN_0078dac0, FUN_007ff3d0, FUN_00812de0, FUN_008153b0, FUN_0083c110
(+ unlabeled CALL sites 0078a39e, 0078a422)
```

## Artifacts

| Kind | Path |
|---|---|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00411e40_FUN_00411e40.md` |
| Annotated | `docs/reconstruction/raw/aa_00411e40_FUN_00411e40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDHash_TraverseToNext_RegEdiEsi.cpp` |
| Clean FUN twin | `docs/reconstruction/reconstructed-exact/FUN_00411e40.cpp` |
| FUN record | `docs/reconstruction/functions/aa_00411e40_FUN_00411e40.md` |
| Review A | `docs/reconstruction/reviews/A_aa_00411e40_CNDHash_TraverseToNext_RegEdiEsi.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00411e40_CNDHash_TraverseToNext_RegEdiEsi.md` |
| Report | `docs/agents/task-dual-ab-00411e40-mega-114-report.md` |

## Gaps

- Payload product English / struct layout per host hash (interact path uses +4 type, +8/+0xc TFID).
- Owning function for unlabeled CALL sites.
- Runtime / bit-exact / differential.

## Confidence

| Claim | Level |
|---|---|
| CF / offsets / strings | Confirmed / High |
| Register ABI | High |
| Product TraverseToNext role | Confirmed |
| Port as drop-in thiscall | **False** — must preserve EDI/ESI convention or thunk |
