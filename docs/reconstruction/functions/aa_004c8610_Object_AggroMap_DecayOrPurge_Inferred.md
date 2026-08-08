# Function record: Object_AggroMap_DecayOrPurge_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c8610` |
| **Canonical name** | `Object_AggroMap_DecayOrPurge_Inferred` (**Inferred** product English) |
| **Ghidra symbol** | `FUN_004c8610` |
| **Address** | `0x004c8610` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | `0x004c8610`–`0x004c8779` exclusive (**361 B** / `0x169`) |
| **System** | Object aggro / threat map maintenance |
| **Agent** | WQ9F-B OWN-ONLY dual 2026-08-04 |
| **Completion status** | Dual sealed (A/B accept-with-gaps) |
| **Terminal** | **false** |

## Purpose

Host-side **aggro/threat map** walker: apply **0.85** float decay to each entry score (`node+0x20`), keep non-zero residuals in decay mode, erase zero residual or force-purge via dualed `StdTree_EraseAndRebalance_Isnil29_Inferred`, and clear selected target (vtbl **+0x258**) when the purged TFID equals the host primary identity.

## Signature

```c
void __thiscall Object_AggroMap_DecayOrPurge_Inferred(
    void* self,           // ECX — object host
    char forcePurge);     // 0 = decay-and-drop-zeros; nonzero = purge all
// RET 4
```

## Layout

| Site | Meaning |
|---|---|
| `self+0x154` | `MapShellIsnil29` (proxy/head/size) |
| `self+0x158` | head sentinel |
| node `+0x10..+0x18` | TFID-like key (peer: `Object_ResolveFromTFID`) |
| node `+0x20` | int score (decay target) |
| node `+0x29` | isnil |
| `DAT_00aaa680` | **0.85f** |

## Call graph

| Role | Target |
|---|---|
| **Caller (1)** | `FUN_00638ac0` (AI cadence; arg 0) |
| Erase | `StdTree_EraseAndRebalance_Isnil29_Inferred` (`0x004cb740`) |
| Clear target | host vtbl **+0x258** + `DAT_009cb8c0` payload |
| Peer (not OWN) | `FUN_004c8780` same map; resolve-or-erase |

## Evidence summary

- Live decompile ≡ disasm CF; epilogue `RET 4` sealed.
- Float constant bytes `9A 99 59 3F` = 0.85f.
- Erase ECX = `this+0x154`; dualed isnil29 erase.
- Peer `004c8780` names key as TFID via `Object_ResolveFromTFID`.
- Product method name open → `_Inferred`.

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/Object_AggroMap_DecayOrPurge_Inferred.cpp`
- Raw: `docs/reconstruction/raw/aa_004c8610_FUN_004c8610.md`
- Annotated: `docs/reconstruction/raw/aa_004c8610_FUN_004c8610.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_004c8610_Object_AggroMap_DecayOrPurge_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_004c8610_Object_AggroMap_DecayOrPurge_Inferred.md`
- Report: `docs/agents/task-dual-ab-00407e30-004c8610-wq9fb-report.md`
