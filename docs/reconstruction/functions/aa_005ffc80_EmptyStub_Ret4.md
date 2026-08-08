# Function record: EmptyStub_Ret4

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ffc80` |
| **Canonical name** | `EmptyStub_Ret4` |
| **Ghidra name** | `FUN_005ffc80` |
| **Address** | `0x005ffc80` |
| **Body range** | `0x005ffc80`–`0x005ffc82` (3 B `c2 04 00`; exclusive end `0x005ffc83`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | shared / multi-domain nop leaf |
| **Completion status** | **partial** — dual A/B **accept**; CF + bytes + ABI sealed; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_005ffc80_EmptyStub_Ret4.md`, `reviews/B_aa_005ffc80_EmptyStub_Ret4.md` |
| **Last reviewed** | `2026-08-05` (R11-009) |
| **Terminal** | **false** |

## Alias

- `FUN_005ffc80` (Ghidra)

## Purpose

Shared **empty leaf**: three-byte `RET 0x4`. Body performs no work. Observed roles via xrefs only:

1. Default empty **vtable** methods (100+ DATA slots with LE `80 fc 5f 00`).
2. Direct CALL nop from `FUN_0064d9f0` before field copy.

## Signature

```c
void EmptyStub_Ret4(void *ignored_stack_arg);  // ret 4; ignores this / stack arg
```

## Algorithm

1. `return;` (machine: `ret 4`)

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005ffc80_FUN_005ffc80.md`
- Annotated: `docs/reconstruction/raw/aa_005ffc80_FUN_005ffc80.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/EmptyStub_Ret4.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_005ffc80.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-005ffc80-r11-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | none |
| **Code callers** | `FUN_0064d9f0` @ `0x0064d9f9` (push dest; call; copy 8 dwords) |
| **DATA sample** | Class vtbl `0x00a9bbe8+8` (`0x00a9bbf0`); VehicleAction primary +0x10; secondary +0x04/+0x0c |

## Confidence

| Claim | Level |
|---|---|
| Body is pure `ret 4` (`c2 04 00`) | **High** |
| No side effects | **High** |
| Shared multi-role nop (not domain-specific) | **High** |
| Distinct from bare-`c3` EmptyRet | **High** |
| Product/PDB symbol | Open |
| Exhaustive DATA-slot census | Open (not needed for CF) |

## Related

- `aa_0056f570` EmptyRet — bare `c3` shared nop (different VA / ABI)
- `aa_005081f0` CVOGHBBase_EmptyVFunc — bare `c3` HB default
- `aa_00416110` Class_00a9bbe8_CompleteDtor_Inferred — residual parent; vtbl +8 points here
- Physics VehicleAction / component builders — DATA slots only
