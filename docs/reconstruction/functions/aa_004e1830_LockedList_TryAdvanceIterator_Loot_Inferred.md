# Function record: LockedList_TryAdvanceIterator_Loot_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e1830` |
| **Canonical name** | `LockedList_TryAdvanceIterator_Loot_Inferred` |
| **Ghidra name** | `FUN_004e1830` |
| **Address** | `0x004e1830` |
| **Body** | `0x004e1830`–`0x004e18dc` (**172 bytes**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | combat-loot / locked list walk |
| **Completion status** | **Dual A/B sealed** — W23-T 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Ghidra: `FUN_004e1830`
- Scaffold: `Named_CalleeOf_Named_CalleeOf_CVOGCombat_OnDeathAwardKillXp_004e1830`
- Twin: `List_IterateNext` / `LockedList_TryAdvanceIterator_Inferred` @ `0x004022a0` (SEH variant)

## Purpose

**TryEnter** CS-guarded singly-linked list cursor advance for loot/weapon table walks. Returns `0` (element), `1` (end), or `0x80070005` (not locked / TryEnter fail). No SEH frame.

## Signature (machine-derived)

```c
uint32_t __thiscall LockedList_TryAdvanceIterator_Loot_Inferred(
    int list /* ECX */,
    int *pCursor /* [esp+4] */,
    uint32_t *pOutPayload /* [esp+8] */);
// callee cleanup: ret 8
```

## Layout

| Off | Role |
|----:|------|
| `list+4` | `CRITICAL_SECTION` |
| `list+0x1C` | head node |
| `list+0x28` | traversal enable flag (byte) |
| `node+4` | payload out |
| `node+8` | next |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004e1830_FUN_004e1830.md`
- Annotated: `docs/reconstruction/raw/aa_004e1830_FUN_004e1830.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/LockedList_TryAdvanceIterator_Loot_Inferred.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_004e1830.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004e1830_LockedList_TryAdvanceIterator_Loot_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_004e1830_LockedList_TryAdvanceIterator_Loot_Inferred.md`

## Callers / callees

| Direction | Symbol | VA |
|---|---|---|
| Caller | `KillLoot_RollTableItems_Inferred` | `0x0050aa80` |
| Caller | `FUN_0050a7d0` | `0x0050a7d0` |
| Caller | `FUN_004d5c10` | `0x004d5c10` |
| Callee | `TryEnterCriticalSection` | IAT `[0x009c61a0]` |
| Callee | `LeaveCriticalSection` | IAT `[0x009c61b8]` |

## Confidence

| Claim | Level |
|---|---|
| Control flow live ≡ raw | **High** |
| Return codes 0 / 1 / `0x80070005` | **High** |
| Node `+4` payload / `+8` next | **High** |
| Twin of `0x004022a0` (no SEH) | **High** |
| Product container type name | **Tentative** |
| Domain “loot” from callers | **Probable** (role-sealed structural) |

## Dual status

| Review | Verdict |
|---|---|
| A (fidelity) | **accept-with-gaps** |
| B (adversarial) | **accept-with-gaps** |
