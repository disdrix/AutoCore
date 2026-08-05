# Function record: Host_RegisterObjectAndAccumulateBounds

| Field | Value |
|---|---|
| **Stable ID** | `aa_007647c0` |
| **Canonical name** | `Host_RegisterObjectAndAccumulateBounds` (**Inferred** structural) |
| **Ghidra name** | `FUN_007647c0` |
| **Address** | `0x007647c0`–`0x0076482d` exclusive (**109 B** / `0x6D`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | host registration + graphics bounds |
| **Completion status** | **Dual sealed** W36-L — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

- `FUN_007647c0` (Ghidra)
- ~~`Named_CalleeOf_CVOGTacArc_InitializeMesh_007647c0`~~ — **rejected** scaffold (multi-caller; not TacArc-only)

## Purpose

Register an `object*` with a `host` (append to host+0xbc pointer vector), run object virtual prep hooks, resolve an xform via host virt+0x0c, and accumulate the object's local `BoundsVolume` at object+0x28 into the host dest bounds at host+4 via sealed `Bounds_AccumulateTransformedLocal`.

## Signature

```c
// ECX=host*, stack0=object*, RET 4
void Host_RegisterObjectAndAccumulateBounds(HostLike* host, ObjectLike* obj);
```

## Layout (used offsets)

| Side | Off | Field |
|---|---|---|
| host | `+0x00` | vtable (`+0x0c`) |
| host | `+0x04` | dest BoundsVolume |
| host | `+0xbc` | vector\<object*\> |
| object | `+0x00` | vtable (`+0x20`, `+0x5c`, `+0x80`) |
| object | `+0x28` | local BoundsVolume |
| object | `+0x58/+0x5c/+0x60` | linkage gate |
| object | `+0x64` | scaleSrc-like |
| object | `+0xbc` | flag bit0 |

## Related

| VA | Role |
|---|---|
| `0x004406e0` | ptr-vector push (EAX=vec, ESI=&value) — unowned |
| `0x0074c9c0` | `Bounds_AccumulateTransformedLocal` (W21-O) |
| many | mesh / host / TacArc / HostPtrTable12 callers |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007647c0_FUN_007647c0.md` |
| Annotated | `docs/reconstruction/raw/aa_007647c0_FUN_007647c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Host_RegisterObjectAndAccumulateBounds.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_007647c0.cpp` |
| A/B | `docs/reconstruction/reviews/A_aa_007647c0_Host_RegisterObjectAndAccumulateBounds.md`, `B_…` |
| Dual report | `docs/agents/task-dual-ab-007647c0-0045cce0-w36l-report.md` |
