# Function record: CVOGHBBase_dtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00508390` |
| **Canonical name** | `CVOGHBBase_dtor` |
| **Ghidra name** | `FUN_00508390` |
| **Address** | `0x00508390` |
| **Body range** | `0x00508390`–`0x005083af` (32 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `heartbeat` / timed-action infrastructure |
| **Completion status** | **partial** — dual A/B **accept**; CF + bytes sealed; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00508390_CVOGHBBase_dtor.md`, `reviews/B_aa_00508390_CVOGHBBase_dtor.md` (2026-07-29 W21-A) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_00508390`
- Base complete-dtor body (non-scalar)

## Purpose

MSVC-style **complete object destructor body** for `CVOGHBBase`:

1. Restore base vtbl `PTR_FUN_009cdab0` at `this+0`.
2. If `this+0x18` (owner) and `*(owner+0xB0)` (list manager) are both non-null, detach this HB via `FUN_005085b0(listMgr, this)`.

Does **not** call `operator_delete` (scalar deleting sibling is `FUN_00508630` @ `0x00508630`).

## Signature

```c
void __fastcall CVOGHBBase_dtor(void *thisHb /* ECX */);
// bare RET; no stack args
```

## Algorithm

1. `eax = this`.
2. Load owner from `this+0x18` into `ecx`; test non-null.
3. Store `0x009cdab0` to `*this` (always, even if owner null).
4. If owner live: load listMgr from `owner+0xB0`; if non-null `push this; call FUN_005085b0` with `ECX=listMgr`.
5. Return.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00508390_FUN_00508390.md`
- Annotated: `docs/reconstruction/raw/aa_00508390_FUN_00508390.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBBase_dtor.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_00508390.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00508390-00512d10-w21a-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_005085b0` @ `0x005085b0` (list remove-by-key) |
| **Callers (sample)** | TargetingLink complete dtor `0x00512060` (tail), `FUN_00642b00`, `FUN_00606380`, `FUN_005078c0`, `FUN_00578a60`, multiple HB derived complete dtors + Unwind sites |

## Confidence

| Claim | Level |
|---|---|
| Control flow + bytes | **High** |
| Base vtbl restore `0x009cdab0` | **High** |
| `HB+0x18` / `owner+0xB0` gates | **High** |
| Callee this = listMgr (not HB) | **High** (machine) |
| Role = complete dtor body (non-scalar) | **High** |
| Product English / mangled | Open (class RTTI known elsewhere) |
| Runtime / differential | Open |

## Related

- `aa_00508200` — `CVOGHBBase_ctor`
- `aa_005083b0` — `CVOGHBBase_AttachOwnerObject`
- `aa_005085b0` — list remove-by-key
- `aa_00512060` — TargetingLink complete dtor (tails here)
- `FUN_00508630` — scalar deleting dtor sibling
