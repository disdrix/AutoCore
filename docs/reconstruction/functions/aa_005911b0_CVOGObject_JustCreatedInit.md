# Function record: CVOGObject_JustCreatedInit

| Field | Value |
|---|---|
| **Stable ID** | `aa_005911b0` |
| **Canonical name** | `CVOGObject_JustCreatedInit` |
| **Ghidra name** | `FUN_005911b0` |
| **Address** | `0x005911b0` |
| **Body range** | `0x005911b0`–`0x00593233` (8324 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client object / physics-gfx spawn finalize |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `reviews/A_aa_005911b0_CVOGObject_JustCreatedInit.md`, `reviews/B_aa_005911b0_CVOGObject_JustCreatedInit.md` (2026-07-29 W22-H) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_005911b0`
- Scaffold string-seeds (`SkyBoxParticles`) — phase-local only

## Purpose

Client object **Just-created** initialization: pose/gfx apply, skybox particles, ragdoll, rigidbody, entity registration. Mode `1` used by batch pass; mode `0` by deferred tick.

## Signature

```c
uint32_t __thiscall CVOGObject_JustCreatedInit(void *self, char mode);
// ret 4; returns 1 success/already-done, 0 deferred abort
```

## Algorithm (summary)

```
profile "Just created"
if done_latch: return 1
if mode==0 && soft_skip: enqueue/abort helper; return 0
copy pending position
if gfx: build rot/pos (optional random); apply; skybox; optional FX
optional scale from template
if ragdoll once: load or log error
if rigidbody path: build RB(s); impulses; addEntity
return 1
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005911b0_FUN_005911b0.md`
- Annotated: `docs/reconstruction/raw/aa_005911b0_FUN_005911b0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGObject_JustCreatedInit.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_005911b0.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_005911b0_FUN_005911b0.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-004047a0-005911b0-w22h-report.md`

## Callers / callees

| Direction | VA | Name / role |
|---|---|---|
| Caller | `0x00594290` | batch just-created (mode=1) |
| Caller | `0x00595230` | object tick (mode=0) |
| Callee | many | see raw W22-H seal (51 callees) |

## Confidence

| Claim | Level |
|---|---|
| Phase structure + ABI | **High** |
| Latch / return contract | **High** |
| Nested phase strings | **High** |
| Full physics formula detail | **Medium** (decomp present; not line-audited) |
| Product name | **Inferred** |
| Runtime | Open |
