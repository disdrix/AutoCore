# Function record: NDSpecialFX_DeactivateClear_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b7150` |
| **Canonical name** | `NDSpecialFX_DeactivateClear_Inferred` |
| **Ghidra name** | `FUN_004b7150` |
| **Address** | `0x004b7150` |
| **Body range** | `0x004b7150`–`0x004b7320` (464 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `client-fx` / NDSpecialFX lifecycle |
| **Completion status** | **partial** — dual A/B **accept** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `reviews/A_aa_004b7150_NDSpecialFX_DeactivateClear_Inferred.md`, `reviews/B_aa_004b7150_NDSpecialFX_DeactivateClear_Inferred.md` (2026-07-29 W23-H) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_004b7150`

## Purpose

Host-level **deactivate/clear** for NDSpecialFX: flush multi-hit stage (`+0x3c`), flag owned children destroy-pending (`list +0x204`, `+0x90e bit0`), clear lists, stop sound payloads (`list +0x1f8`).

## Signature

```c
void __thiscall NDSpecialFX_DeactivateClear_Inferred(void *fx_host);
// ECX = host; plain ret (C3)
```

## Algorithm (summary)

```
if staged_multi_hit_buf: FlushStagedMultiHits
if host_entity resolves phys:
  for child in owned_list:
    if child.flags & PHYS_DETACH: detach(phys)
for child in owned_list:
  child.flags |= DESTROY_PENDING
  notify_unlink; child.parent = null
aux_clear()
clear list +0x1ec
for sound_name in list +0x1f8: stop_by_name
clear list +0x1f8
for node in list +0x21c: aux_release
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004b7150_FUN_004b7150.md`
- Annotated: `docs/reconstruction/raw/aa_004b7150_FUN_004b7150.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/NDSpecialFX_DeactivateClear_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_004b7150.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_004b7150_FUN_004b7150.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-004b7150-00595230-w23h-report.md`

## Callers / callees

| Direction | VA | Name / role |
|---|---|---|
| Caller | `0x004b8ed0` | FX lifecycle / destroy path |
| Caller | `0x004fcc40` | FX related |
| Caller | `0x00516930` | FX related |
| Caller | `0x005a8ec0` | FX related |
| Callee | `0x004b6980` | FlushStagedMultiHits |
| Callee | `0x007203b0` | MarkStopByName |
| Callee | others | see raw |

## Confidence

| Claim | Level |
|---|---|
| ABI + CF phases | **High** |
| Layout +0x3c / +0x204 / +0x1f8 | **High** |
| Product name | **Inferred** |
| List element product types | **Medium** |
| Runtime | Open |
