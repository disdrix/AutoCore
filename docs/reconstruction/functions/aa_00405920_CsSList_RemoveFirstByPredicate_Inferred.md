# Function record: CsSList_RemoveFirstByPredicate_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00405920` |
| **Canonical name** | `CsSList_RemoveFirstByPredicate_Inferred` |
| **Address** | `0x00405920`–`0x004059b9` inclusive (**154 B** / `0x9A`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client containers / deferred-queue & object-list remove |
| **Completion status** | **Human-refined** + dual A/B seal 2026-08-05 (MEGA-042); runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Ghidra: `FUN_00405920`
- Prior scaffold: `Named_CalleeOf_Named_CalleeOf_Client_SendInventoryAddItem_00405920` (**retired**)
- MEGA hint plate: inventory-transfer / SendInventoryAddItem nested (parent seed only)

## Purpose

Thread-safe **singly-linked remove-first** driven by a predicate:

1. `EnterCriticalSection(list+0x28)` then `EnterCriticalSection(list+0x10)`.
2. Walk `head = list+4`; for each node call `pred(node->payload, cookie)`.
3. On first true: unlink (head/prev/tail), clear payload, `vtbl[0](1)` delete-this, `InterlockedDecrement(list+0xC)`.
4. Leave both CS (inner then outer). At most one removal per call.

Live call-site predicates (`0x4cd580`, `0x92d8e0`) are pointer-equality stubs (`SETE` / `RET 8`).

## Signature (sealed)

```c
// __thiscall ECX=list*, stack pred*, cookie; void; RET 8
typedef char (__cdecl *CsSList_Pred_Inferred)(void *payload, void *cookie);

void __thiscall CsSList_RemoveFirstByPredicate_Inferred(
    void *list,
    CsSList_Pred_Inferred pred,
    void *cookie);
```

## Layout (sealed)

| Off | Field |
|----:|-------|
| list+0x04 | head* |
| list+0x08 | tail* |
| list+0x0C | count (InterlockedDecrement on remove) |
| list+0x10 | CRITICAL_SECTION (always) |
| list+0x28 | CRITICAL_SECTION (always) |
| node+0x00 | vtbl* |
| node+0x04 | payload* |
| node+0x08 | next* |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00405920_FUN_00405920.md` (+ MEGA-042 re-verify append)
- Annotated: `docs/reconstruction/raw/aa_00405920_FUN_00405920.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CsSList_RemoveFirstByPredicate_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00405920.cpp`
- Retired: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Client_SendInventoryAddItem_00405920.cpp`
- Reviews: `A_aa_00405920_…`, `B_aa_00405920_…`

## Callers / callees

| Direction | Address / name | Notes |
|-----------|----------------|-------|
| Callee | EnterCriticalSection / LeaveCriticalSection | dual CS always |
| Callee | InterlockedDecrement | count @ +0xC |
| Callee | node vtbl[0] | scalar deleting dtor |
| Caller | `FUN_004d4790` Object_QueueDelete | list @ `objMgr+0xe648`; after Contains |
| Caller | `FUN_00944d50` | list @ `+0xe5fc`; two sites |

## Confidence

| Claim | Level |
|---|---|
| ABI thiscall + RET 8 | **High / Sealed** |
| Remove-first-by-pred CF + CS layout | **High / Sealed** |
| Family with Append/Contains | **High / Sealed** |
| Product class / inventory-specific English | **Tentative** (`_Inferred`) |
| Runtime / bit-exact | **Open** |
