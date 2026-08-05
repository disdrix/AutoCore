# Function record: Anm_KestChunk_ReadF32Array_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0045dd60` |
| **Canonical name** | `Anm_KestChunk_ReadF32Array_Inferred` |
| **Ghidra symbol** | `FUN_0045dd60` |
| **Address** | `0x0045dd60`–`0x0045de07` (**168 B**) |
| **Module** | `autoassault.exe` base `0x400000` |
| **System** | `sto-chunk` / animation |
| **Completion status** | **Dual complete (accept-with-gaps)** W37-P |
| **Prior alias (reject as canonical)** | `Named_CalleeOf_Named_anmTrackMaster_inl_0045dd60` |

## Purpose

Read a **KEST**-tagged nested chunk as a dense f32 blob sized **`elem_count * 7`** (Pod28 track elements) into a pre-resized buffer. Worker under `AnmTrackMaster_Unserialize_Inferred` after `StdVector_Resize_Pod28`.

## Signature

```c
uint32_t /* status or -1 */ Anm_KestChunk_ReadF32Array_Inferred(
    int elem_count /*ECX*/,
    /* EDI */ void *reader,
    float *dest /*stack*/);
/* bare RET; caller ADD ESP,4 */
```

## Artifacts

- Raw / annotated / clean / twin / dual A/B — see `aa_0045dd60_FUN_0045dd60.md`
- Agent report: `docs/agents/task-dual-ab-0045dd60-0052ade0-w37p-report.md`
