# Function record: Obj_BodyDtor_SetVtbl_DestroyStdListAt10

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b3b20` |
| **Canonical name** | `Obj_BodyDtor_SetVtbl_DestroyStdListAt10` (Inferred) |
| **Ghidra name** | `FUN_005b3b20` |
| **Address** | `0x005b3b20` |
| **Body range** | `0x005b3b20`–`0x005b3b2e` exclusive (**14** B / `0x0E`); pad `CC` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | host object / MSVC std::list member dtor |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + bytes + ABI sealed; product class open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_005b3b20_Obj_BodyDtor_SetVtbl_DestroyStdListAt10.md`, `reviews/B_aa_005b3b20_Obj_BodyDtor_SetVtbl_DestroyStdListAt10.md` (2026-07-29 W28-N) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_005b3b20`
- Role: MSVC **body destructor** — install final vtbl `PTR_FUN_009d95b4`, destroy embedded list at `this+0x10`

## Purpose

Body dtor for a host object with final vtbl at `0x009d95b4`. Sets `*this = vtbl`, advances `this` by `0x10`, tail-jumps `StdList_Destroy_FreeHead` to free the embedded circular list (nodes + sentinel, null head).

## Signature

```c
void __fastcall Obj_BodyDtor_SetVtbl_DestroyStdListAt10(void* self);
// ECX = this; bare RET via tail into StdList_Destroy_FreeHead
```

## Algorithm

1. `*self = PTR_FUN_009d95b4` (final vtbl; slot[0] = scalar dtor `0x005b44d0`).
2. `ECX = self + 0x10` (embedded list object: head @ +4, size @ +8 relative to list).
3. Tail `jmp StdList_Destroy_FreeHead` (`0x00497360`).

## Artifacts

- Raw: `docs/reconstruction/raw/aa_005b3b20_FUN_005b3b20.md`
- Annotated: `docs/reconstruction/raw/aa_005b3b20_FUN_005b3b20.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Obj_BodyDtor_SetVtbl_DestroyStdListAt10.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_005b3b20.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-005b3b20-005ae0b0-w28n-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | tail → `StdList_Destroy_FreeHead` / `FUN_00497360` (W27-K accept) |
| **Callers** | `FUN_005b44d0` only (scalar-deleting dtor; vtbl[0]) |

## Confidence

| Claim | Level |
|---|---|
| Bytes: vtbl + add 0x10 + jmp list destroy | **High** |
| Decompile missing add/tail | **High** (documented) |
| List at +0x10 (ctor LEA) | **High** |
| Sole scalar-dtor caller | **High** |
| Product class English | **Open** (inferred structural name) |
| Runtime / differential | Open |

## Related

- List destroy: `aa_00497360` `StdList_Destroy_FreeHead`
- Scalar dtor shell: `FUN_005b44d0` (not owned this wave)
- Ctors installing same vtbl: `FUN_005b3f60`, `FUN_005b4260`
