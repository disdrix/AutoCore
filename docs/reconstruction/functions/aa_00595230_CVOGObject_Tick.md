# Function record: CVOGObject_Tick

| Field | Value |
|---|---|
| **Stable ID** | `aa_00595230` |
| **Canonical name** | `CVOGObject_Tick` |
| **Ghidra name** | `FUN_00595230` |
| **Address** | `0x00595230` |
| **Body range** | `0x00595230`–`0x005960fc` (3788 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client object / per-frame tick |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `reviews/A_aa_00595230_CVOGObject_Tick.md`, `reviews/B_aa_00595230_CVOGObject_Tick.md` (2026-07-29 W23-H) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_00595230`

## Purpose

Client object **per-frame tick**: reaction/phase timer, lifetime timer, parent/gfx pose sync, deferred `CVOGObject_JustCreatedInit(mode=0)`, velocity cache and gfx writeback. Sole caller is SpecialFX object walk `FUN_004b8ed0`.

## Signature

```c
void __thiscall CVOGObject_Tick(void *self, float dt, uint32_t ctx);
// ret 8
```

## Algorithm (summary)

```
inc stats by created flag
optional multi FUN_00634c50
profile "Time etc.."
countdown +0x788; on expire: pulse, maybe flush multi-hit, advance reaction node
lifetime +0x790 if flag; maybe destroy return
if not-created or just-created-pending:
  profile "Update Parent Pos"
  pose from gfx or parent physics
  zero-geo warn
  velocity cache
  if just-created-pending: delay or JustCreatedInit(0); abort if 0
  gfx update / velocity or integrate; clear just-created bit
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00595230_FUN_00595230.md`
- Annotated: `docs/reconstruction/raw/aa_00595230_FUN_00595230.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGObject_Tick.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00595230.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_00595230_FUN_00595230.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-004b7150-00595230-w23h-report.md`

## Callers / callees

| Direction | VA | Name / role |
|---|---|---|
| Caller | `0x004b8ed0` | SpecialFX owned-object walk |
| Callee | `0x005911b0` | CVOGObject_JustCreatedInit mode 0 |
| Callee | `0x004b6980` | FlushStagedMultiHits (timer path) |
| Callee | many | pose/quat/gfx helpers — see raw |

## Confidence

| Claim | Level |
|---|---|
| Phase structure + ABI | **High** |
| Timer / JustCreated gate | **High** |
| Nested pose math detail | **Medium** |
| Product name | **Inferred** |
| Runtime | Open |
