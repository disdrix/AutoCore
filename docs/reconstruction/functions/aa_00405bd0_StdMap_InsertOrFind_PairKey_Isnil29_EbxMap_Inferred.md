# Function record: StdMap_InsertOrFind_PairKey_Isnil29_EbxMap_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00405bd0` |
| **Canonical name** | `StdMap_InsertOrFind_PairKey_Isnil29_EbxMap_Inferred` (**Inferred** structural) |
| **Ghidra symbol** | `FUN_00405bd0` |
| **Address** | `0x00405bd0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | `0x00405bd0`–`0x00405c7e` inclusive (**175 B** / `0xAF`) |
| **System** | MSVC std::map unique insert-or-find |
| **Agent** | WQ9K-D OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B accept-with-gaps) |
| **Terminal** | **false** |

## Purpose

Unique **insert-or-find** for **isnil@+0x29** maps keyed by a **two-dword pair** (signed hi @ node+0x14 primary, unsigned lo @ node+0x10 secondary). Register ABI distinguishes this unit from thiscall twin `0x004cbee0`.

## Signature

```c
// EBX = map*, EAX = value*, ESI = out {it*, inserted}*; bare RET; EAX = out*
InsertPair_Isnil29* StdMap_InsertOrFind_PairKey_Isnil29_EbxMap_Inferred(
    MapShell_Isnil29_Pair* map /*EBX*/,
    InsertPair_Isnil29* out /*ESI*/,
    const Val_PairKey_Isnil29* value /*EAX*/);
```

## Call graph

| Role | Target |
|---|---|
| **Caller** | `FUN_0092ff00` @ `0x0092ffbc`, `0x00930001` (TFID resolve host) |
| Predecessor | `StdTree_Predecessor_Isnil29_Edx_Inferred` (`0x00409820`) dualed WQ9J-G |
| Insert worker | `FUN_004069f0` (**undualed**) |
| Twin (do not merge) | `StdMap_InsertOrFind_PairKey_Isnil29_Inferred` (`0x004cbee0`) thiscall RET8 |

## Evidence summary

- Live decompile ≡ raw CF; body 175 B; bare RET sealed.
- Pair compare opcodes (JG/JL/JNC) match signed-hi / unsigned-lo order.
- isnil@+0x29 on all walk guards.
- Pred dual EDX sealed; insert worker residual.
- Reject packet-error chain-of-caller scaffold; TFID caller is host evidence only.
- Product demangle open → `_Inferred`.

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/StdMap_InsertOrFind_PairKey_Isnil29_EbxMap_Inferred.cpp`
- Scaffold twin: `docs/reconstruction/reconstructed-exact/FUN_00405bd0.cpp`
- Raw: `docs/reconstruction/raw/aa_00405bd0_FUN_00405bd0.md`
- Annotated: `docs/reconstruction/raw/aa_00405bd0_FUN_00405bd0.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_00405bd0_StdMap_InsertOrFind_PairKey_Isnil29_EbxMap_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00405bd0_StdMap_InsertOrFind_PairKey_Isnil29_EbxMap_Inferred.md`
- Report: `docs/agents/task-dual-ab-00406190-00405bd0-wq9kd-report.md`
