# Function record: CsSList_AppendPayload_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004024d0` |
| **Canonical name** | `CsSList_AppendPayload_Inferred` |
| **Address** | `0x004024d0`–`0x0040258a` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client containers / deferred-queue append |
| **Completion status** | **Human-refined** + dual A/B seal 2026-07-29 (W18-B); runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Ghidra: `FUN_004024d0`
- Prior scaffold: `Named_CalleeOf_CVOGSpawnPoint_CreateCreature_004024d0`
- Parent duals call this **ListAppend** (`Object_EnqueueDeferredOnce`, queue-delete, spawn)

## Purpose

Thread-safe **singly-linked tail append** of a payload pointer:

1. Null payload → return **0** (`ret 4`).
2. `operator_new(0xC)` node; vtbl **`PTR_FUN_009cb340`**; fields `{vtbl, payload, next=0}`.
3. If `count ≤ 3`: `EnterCriticalSection(list+0x28)` (outer).
4. Always `EnterCriticalSection(list+0x10)`.
5. Empty tail → head=tail=node; else `old_tail->next=node`, `tail=node`.
6. `FUN_00402598`: Leave CS(s); **`InterlockedIncrement(list+0xC)`**; return **1**.

## Signature (sealed)

```c
// __thiscall ECX=list*, stack void* payload, ret 4
uint32_t __thiscall CsSList_AppendPayload_Inferred(void *list, void *payload);
```

## Layout (sealed)

| Off | Field |
|----:|-------|
| list+0x04 | head* |
| list+0x08 | tail* |
| list+0x0C | count (InterlockedIncrement post-unlock) |
| list+0x10 | CRITICAL_SECTION (always) |
| list+0x28 | CRITICAL_SECTION (when count ≤ 3) |
| node+0x00 | vtbl `0x009cb340` |
| node+0x04 | payload* |
| node+0x08 | next* |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004024d0_FUN_004024d0.md` (+ versioned residual 2026-07-29)
- Annotated: `docs/reconstruction/raw/aa_004024d0_FUN_004024d0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CsSList_AppendPayload_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_004024d0.cpp`
- Reviews: `A_aa_004024d0_CsSList_AppendPayload_Inferred.md`, `B_aa_004024d0_CsSList_AppendPayload_Inferred.md`

## Callers / callees

| Direction | Address / name | Notes |
|-----------|----------------|-------|
| Callee | `operator_new` | size `0xC` |
| Callee | `EnterCriticalSection` | `+0x10` always; `+0x28` gated |
| Callee | `FUN_00402598` | shared Leave + InterlockedIncrement |
| Caller | `Object_EnqueueDeferredOnce` `0x004d0e90` | deferred bit0 queue |
| Caller | `Object_QueueDelete` `0x004d4790` | |
| Caller | spawn/create + mission paths | multi-system list host |

## Confidence

| Claim | Level |
|---|---|
| ABI thiscall + ret 4 | **High / Sealed** |
| Tail-append CF + CS layout | **High / Sealed** |
| Node 0xC + vtbl | **High / Sealed** |
| Product class / vtbl English | **Tentative** (`_Inferred`) |
| Runtime / bit-exact | **Open** |
