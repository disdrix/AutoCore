# Function record: GameData_LookupCloneBaseByCbid

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404d70` |
| **Canonical name** | `GameData_LookupCloneBaseByCbid` |
| **Address** | `0x00404d70`–`0x00404d7a` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | clonebase / game data |
| **Classification** | leaf thunk (tail → `CNDHash_LookupByKey`) |
| **Completion status** | **Sealed** — dual A/B 2026-07-29; ABI + offset + tail JMP sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual verdict** | **accept** |

## Alias

- Ghidra: `FUN_00404d70`
- Scaffold: `Named_CalleeOf_CVOGReaction_GiveItemByCbid_00404d70`

## Purpose

Host-method **CBID → clonebase definition\*** lookup. Replaces `this` with `*(this+0xf10)` (`CNDHash*`) and **tail-jumps** to `CNDHash_LookupByKey`. Returns definition pointer or **NULL**.

Used by item factory (`CVOGReaction_GiveItemByCbid`), creature spawn (`CVOGSpawnPoint_CreateCreature`), mission collect UI (`FUN_006124b0`), and many other clonebase consumers.

## Signature (sealed)

```c
void * __thiscall GameData_LookupCloneBaseByCbid(void *this, uint32_t cbid);
/* ECX = host (DAT_00b041fc); stack cbid; RET 4 via Lookup; EAX = def* or NULL */
```

## Layout

| Offset | Role | Confidence |
|---:|---|---|
| host `+0xf10` | `CNDHash*` CBID→clonebase table | **High** |
| `DAT_00b041fc` | global host pointer (call-site ECX) | **High** (usage) / Probable English |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00404d70_FUN_00404d70.md`
- Annotated: `docs/reconstruction/raw/aa_00404d70_FUN_00404d70.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/GameData_LookupCloneBaseByCbid.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00404d70.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00404d70_GameData_LookupCloneBaseByCbid.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00404d70_GameData_LookupCloneBaseByCbid.md`
- Report: `docs/agents/task-dual-ab-00404d70-gamedata-lookupclonebasebycbid-report.md`

## Callers / callees

**Callee (1):** `CNDHash_LookupByKey` (`0x005b0920` / `aa_005b0920`) via **JMP**.

**Named / listed callers (sample):**  
`CVOGReaction_GiveItemByCbid`, `CVOGSpawnPoint_CreateCreature`, `FUN_004be440`, `FUN_004d7230`, `FUN_004f1ff0`, `FUN_004fdcb0`, `FUN_004fed40`, `FUN_0050a7d0`, `FUN_00517680`, `FUN_00517ab0`, `FUN_00517df0`, `FUN_0052e1d0`, `FUN_0052e640`, `FUN_0056df80`, `FUN_005b2490`, `FUN_005ca680`, `FUN_005cae70`, `FUN_005cbb20`, `FUN_005cc2a0`, `FUN_005ff140`, `FUN_00611f20`, `FUN_006124b0`, `FUN_00614380`, `FUN_00616d10`, `FUN_00620ff0`, + more xrefs.

## Confidence

| Claim | Level |
|---|---|
| Tail JMP + `[ECX+0xF10]` | **High** |
| Returns Lookup value (not void) | **High** |
| Key is CBID (call-site usage) | **High** |
| Value is clonebase/item def* | **High** (role) |
| Host product class name | **Probable** / Tentative |
| Runtime / differential | Open |
