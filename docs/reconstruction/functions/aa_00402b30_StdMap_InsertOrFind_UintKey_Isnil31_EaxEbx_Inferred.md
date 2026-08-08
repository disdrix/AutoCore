# Function record: StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402b30` |
| **Canonical name** | `StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx_Inferred` (**Inferred** structural) |
| **Ghidra symbol** | `FUN_00402b30` |
| **Address** | `0x00402b30` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | `0x00402b30`–`0x00402be6` inclusive (**183 B** / `0xB7`) |
| **System** | MSVC `std::map` insert-or-find (missions-progression host map) |
| **Agent** | MEGA-040 OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B **accept-with-gaps**) |
| **Terminal** | **false** |

## Rejected misname

`Named_CalleeOf_Client_NotifyActiveMissionChanged_00402b30` — xref-seed scaffold only; helper is generic STL insert-or-find shared by a thin wrapper, not mission product logic.

## Purpose

MSVC-style unique **insert-or-find** for trees with **color @ +0x30** / **isnil @ +0x31** (node size **0x38**). Unsigned **uint32** key at value dword0 / node **+0x10**. On miss, always-insert via residual `FUN_00403250` (RB rebalance; uses dualed L/R rotate isnil31). On hit, `{it, inserted=0}` without rewriting mapped payload.

## Signature

```c
// EAX = map; EBX = value*; stack = out; RET 4; returns out
InsertPair_Isnil31 *StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx_Inferred(
    MapShell_Isnil31 *map,             // EAX
    InsertPair_Isnil31 *out,           // { Node* it; bool inserted; }
    const Val_UintKey *value);         // key @ +0 (EBX)
```

## Layout / constants

| Item | Value |
|---|---|
| Key | unsigned uint32 @ node+0x10 |
| isnil / color | +0x31 / +0x30 |
| Node size | `0x38` (isnil31 family) |
| Compare | unsigned (`SETC` / `JNC`) |
| ABI | EAX map, EBX value*, stack out, RET 4 |

## Call graph

| Role | Target |
|---|---|
| **Callers (3)** | `Client_NotifyActiveMissionChanged` `0x00944770` (×2 @ `0x00944802`, `0x009448bd`; map client+`0xf14`); `FUN_00933310` @ `0x00933363` |
| Insert+RB | `FUN_00403250` (unOWN; uses Lrot `00403e90` / Rrot `00403ee0`) |
| Predecessor | `FUN_00404290` (unOWN) |

## Evidence summary

- Live decompile ≡ raw CF; RET 4 + SETC + isnil@+0x31 sealed via `disassemble_function` + `read_memory`.
- Call-site EAX/EBX sealed via `get_assembly_context` on all 3 xrefs.
- Scaffold NotifyActiveMissionChanged product alias **reject**.
- Peer family: isnil15 EaxEbx `00458510`; isnil29 IntKey thiscall `004cbe20`; erase/Lrot/Rrot isnil31 dualed.

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00402b30.cpp`
- Raw: `docs/reconstruction/raw/aa_00402b30_FUN_00402b30.md`
- Annotated: `docs/reconstruction/raw/aa_00402b30_FUN_00402b30.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_00402b30_StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_00402b30_StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx_Inferred.md`
- FUN record: `docs/reconstruction/functions/aa_00402b30_FUN_00402b30.md`

## Gaps

1. Product English for host map T at client+`0xf14`.
2. Dual seal of insert `00403250` / pred `00404290`.
3. Runtime / bit-exact / differential.
