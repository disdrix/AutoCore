# Function record: StdTree_Buynode_Isnil29_Val24_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a2de0` |
| **Canonical name** | `StdTree_Buynode_Isnil29_Val24_Inferred` |
| **Ghidra name** | `FUN_005a2de0` |
| **Address** | `0x005a2de0`–`0x005a2e3a` (**91 B** / `0x5B`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | std tree / map containers |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `A_aa_005a2de0_StdTree_Buynode_Isnil29_Val24_Inferred.md`, `B_aa_005a2de0_StdTree_Buynode_Isnil29_Val24_Inferred.md` |
| **Last reviewed** | `2026-08-04` (WQ9F-A OWN-ONLY) |

## Alias

- `FUN_005a2de0`
- Scaffold skill-gather path name (**narrow / reject as product**)

## Purpose

Shared **buynode** for the isnil@+0x29 / node-0x30 / Val24 tree family. Insert helpers allocate via this then link + RB rebalance. Contrast Val12 buynode `0x005ae220` (do not merge).

## Signature (sealed)

```c
void * __stdcall StdTree_Buynode_Isnil29_Val24_Inferred(
    void *left, void *parent, void *right,
    const uint32_t *value6, uint8_t color);
// ret 0x14
```

## Algorithm

1. `node = operator_new(0x30)`; if null return 0.
2. `left/parent/right`; copy 6 dwords to `+0x10`.
3. `color@+0x28`; `isnil@+0x29 = 0`.
4. `ret 0x14` with EAX=node.

## Related

- `aa_004cbb60` primary insert dual (WQ9E-E)
- `aa_005ae220` Val12 buynode peer (layout contrast)
- Erase peer family: `aa_004cb740` isnil29 erase

## Artifacts

- Raw / annotated / clean / dual A/B — see FUN twin record + agent report WQ9F-A
