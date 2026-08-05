# Function record: WorldMgr_RebindAllObjects_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00561370` |
| **Canonical name** | `WorldMgr_RebindAllObjects_Inferred` |
| **Ghidra name** | `FUN_00561370` |
| **Address** | `0x00561370` |
| **Body range** | `0x00561370`–`0x0056144a` exclusive (**218** B / `0xDA`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | world / phys manager rebind |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `reviews/A_aa_00561370_WorldMgr_RebindAllObjects_Inferred.md`, `reviews/B_aa_00561370_WorldMgr_RebindAllObjects_Inferred.md` |
| **Last reviewed** | `2026-07-29` W27-P OWN-ONLY |

## Alias

- `FUN_00561370`
- Prior scaffold only (no misleading product plate)

## Purpose

Rebind **all** registered world objects after a manager profile swap:

1. For every island/group in manager vectors **A** (`+8`/`+0xc`) and **B** (`+0x14`/`+0x18`), for every body in island `+0x3c`/`+0x40`: **unbind** (`FUN_0055fbf0`) → **bind** (`FUN_0055fa40`) → set `*(body+0x44)+0x28 = 1`.
2. For every object in extras vector **C** (`+0x120`/`+0x124`): `FUN_0055f7a0(obj, 1)`.

Sole caller `FUN_00562530` replaces manager `+0xd0` profile and related links, then optionally invokes this when its flag ≠ 0.

## Signature

```c
void __thiscall WorldMgr_RebindAllObjects_Inferred(Manager* this);
// ECX = this; 0 stack args; bare ret (c3)
```

## Layout

| This ofs | Role |
|---|---|
| `+0x08` / `+0x0c` | island*[] / count (pass A) |
| `+0x14` / `+0x18` | island*[] / count (pass B) |
| `+0x120` / `+0x124` | object*[] / count (pass C → `0055f7a0`) |

| Island ofs | Role |
|---|---|
| `+0x3c` / `+0x40` | body*[] / count |

| Body ofs | Role |
|---|---|
| `+0x44` | host* |

| Host ofs | Role |
|---|---|
| `+0x28` | `uint8_t` flag ← 1 |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00561370_FUN_00561370.md`
- Annotated: `docs/reconstruction/raw/aa_00561370_FUN_00561370.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/WorldMgr_RebindAllObjects_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00561370.cpp`
- Report: `docs/agents/task-dual-ab-00561370-0044a8c0-w27p-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `WorldObj_UnbindLinks_Inferred` `0x0055fbf0` (W26-D accept); `WorldObj_BindLinks_Inferred` `0x0055fa40` (W26-E accept); `FUN_0055f7a0` |
| **Callers** | `FUN_00562530` only |

## Confidence

| Claim | Level |
|---|---|
| CF + ABI | **High** |
| Unbind→bind order | **High** |
| Host flag write | **High** |
| Three list partitions | **High** |
| Name / product English | **Inferred** |
| `0055f7a0` semantics | **Tentative** (not OWN) |
| Runtime / differential | Open |

## Related

- Unbind dual: `aa_0055fbf0` (W26-D)
- Bind dual: `aa_0055fa40` (W26-E)
- Rebind single-object path: `FUN_00560e90` (RebindActivate) — different unit
- Sibling flush pairs: `aa_00561320` PhysSim_FlushPendingBodyPairs_Inferred (W19-M)
