# Function record: StdMap_InsertOrFind_Val12_UintKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_00573810` |
| **Canonical name** | `StdMap_InsertOrFind_Val12_UintKey` (Inferred) |
| **Ghidra name** | `FUN_00573810` |
| **Address** | `0x00573810` |
| **Body range** | `0x00573810`–`0x005738c8` exclusive (**184** B / `0xB8`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | std red-black tree / map insert-or-find |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + ABI + out-pair + equal-no-write sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00573810_StdMap_InsertOrFind_Val12_UintKey.md`, `reviews/B_aa_00573810_StdMap_InsertOrFind_Val12_UintKey.md` (2026-07-29 W28-T) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_00573810`
- `Named_CalleeOf_…_Client_ShowInvento_00573810` (legacy xref scaffold — **narrow**; inventory callers exist but unit is generic map)
- Peer pattern: `Skill_CategoryCooldownMap_Insert` (`aa_0051d2f0`) — different always-insert helper

## Purpose

MSVC-style unique map **insert-or-find** for Val12 nodes with **uint key** at value dword0 / node `+0x0c`. On miss, always-insert via `StdTree_InsertAndRebalance_Val12` (`FUN_00573510`); on hit, return existing iterator with `inserted=0` and **do not** rewrite value fields.

## Signature

```c
struct InsertPair {
    MapNode_Val12* it;  // +0
    uint8_t inserted;   // +4
};

void __thiscall StdMap_InsertOrFind_Val12_UintKey(
    MapShell_Val12* map,       // ECX; head@+4, size@+8
    InsertPair* out,           // stack0
    const uint32_t* value);    // stack1 — 3 dwords; key = value[0]
// RET 8
```

## Algorithm

1. Start at head; if root non-nil, walk left/right by `key < node.key` (unsigned).
2. If final step was left and parent is leftmost → insert left (`addLeft=1`) → out `{n,1}`.
3. Else if left → tree predecessor on parent.
4. If `parent.key < key` → insert with `addLeft` → out `{n,1}`.
5. Else equal → out `{parent,0}` (no mutate).

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00573810_FUN_00573810.md`
- Annotated: `docs/reconstruction/raw/aa_00573810_FUN_00573810.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdMap_InsertOrFind_Val12_UintKey.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00573810.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-0046c6c0-00573810-w28t-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_00573510` (W27-S insert+rebalance Val12, uses stack buy `005ae220`); `FUN_005ae050` (predecessor) |
| **Callers** | `FUN_00572360` @ `0x005724d5`; `FUN_00572730` @ `0x005729b8`; `FUN_00572ab0` @ `0x00572d41`, `0x00572deb` |

## Confidence

| Claim | Level |
|---|---|
| Control flow + live ≡ raw | **High** |
| `ret 8` + thiscall ECX=map | **High** |
| Out pair `{it@+0, inserted@+4}` | **High** |
| Uint key @ value+0 / node+0xc | **High** |
| Equal key no value rewrite | **High** |
| Val12 isnil@+0x19 | **High** |
| Product English / demangle | **Inferred** |
| Runtime / differential | Open |

## Related

- Always-insert: `aa_00573510` `StdTree_InsertAndRebalance_Val12` (W27-S)
- Node buy (via insert): `aa_005ae220` `StdTree_Buynode_Val12` (W24-I) — **not** ESI twin `0046c6c0`
- Predecessor: `FUN_005ae050`
- Inventory consumer: `aa_00572360` InventoryGrid_RePlaceItems_Inferred
