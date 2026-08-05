# Function record: CVOGObject_GetActivePositionPtr_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c3ac0` |
| **Canonical name** | `CVOGObject_GetActivePositionPtr_Inferred` (Inferred) |
| **Ghidra name** | `FUN_004c3ac0` |
| **Address** | `0x004c3ac0` |
| **Body range** | `0x004c3ac0`–`0x004c3aef` (48 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object pose |
| **Completion status** | **partial** — dual A/B **accept**; CF + bytes sealed; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_004c3ac0_CVOGObject_GetActivePositionPtr_Inferred.md`, `reviews/B_aa_004c3ac0_CVOGObject_GetActivePositionPtr_Inferred.md` (2026-07-29 W20-O) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_004c3ac0`
- `Named_CalleeOf_Named_VOG_DEBUG_STOP_004c3ac0` (legacy misleading scaffold — **not** the setter; sibling writer has VOG_DEBUG_STOP)

## Purpose

Return a pointer to the object's currently active position float block: local override (`+0x240`), phys-linked (`*(phys+0x3c)+0xb0`), or embedded (`typeOff+0x84`), selected by component flags bits 0–2.

## Signature

```c
uint8_t *__fastcall CVOGObject_GetActivePositionPtr_Inferred(void *self);
// ECX=self; bare RET; returns pointer in EAX
```

## Algorithm

1. `typeOff = *(*(self+4)+4)`.
2. If `(*(u8*)(self+typeOff+0xb8) & 7) == 0` → return `self+0x240`.
3. Else if `*(self+8) != 0` → return `*( *(self+8)+0x3c ) + 0xb0`.
4. Else return `self+typeOff+0x84`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004c3ac0_FUN_004c3ac0.md`
- Annotated: `docs/reconstruction/raw/aa_004c3ac0_FUN_004c3ac0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGObject_GetActivePositionPtr_Inferred.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_004c3ac0.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-004c3ac0-00514390-w20o-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | none (leaf) |
| **Callers** | `FUN_005cd3b0` (×2), `FUN_005cedf0` (×2), `FUN_005d2800`, `FUN_0060a230`, `FUN_009190d0` |

## Confidence

| Claim | Level |
|---|---|
| Control flow + bytes | **High** |
| Three-way position pointer select | **High** |
| Mask imm `7`; offsets `0x240` / `0xb0` / `0x84` | **High** |
| Phys form `*(phys+0x3c)+0xb0` | **High** |
| Product English name | **Inferred** |
| Runtime / differential | Open |

## Related

- `aa_004c3a40` CVOGObject_SetLocalPosition4_Gated_Inferred — sibling writer of `+0x240`
- `FUN_004cb3e0` — 4-float store leaf into `+0x240..+0x24c`
