# Function record: AssManager_ReleaseOwnedResolvers_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b65d0` |
| **Canonical name** | `AssManager_ReleaseOwnedResolvers_Inferred` |
| **Ghidra name** | `FUN_007b65d0` |
| **Address** | `0x007b65d0` |
| **Body range** | `0x007b65d0`–`0x007b66a3` exclusive (**211** B / `0xD3`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | assManager / asset resolver teardown |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `reviews/A_aa_007b65d0_AssManager_ReleaseOwnedResolvers_Inferred.md`, `reviews/B_aa_007b65d0_AssManager_ReleaseOwnedResolvers_Inferred.md` |
| **Last reviewed** | `2026-07-29` W29-D OWN-ONLY |

## Alias

- `FUN_007b65d0`
- Dtor body behind `FUN_004239a0` (scalar deleting) and `FUN_007b66b0` (complete)
- Prior bulk alias context: NDXml loader vtbl `PTR_FUN_00a95b88` slot0 → `FUN_004239a0` → this body

## Purpose

Release two optional resolver interfaces on an assManager-related object (`+0x08`, `+0x0c`): remove from global resolver GuardedVector / side string vector, scalar-delete, null slots. Logs `"Removing resolver not found"` from `assManager.cpp:0x27b` when the `+0x0c` key is absent from the vector.

## Signature

```c
// Retail: this in EBX; plain ret; void
void AssManager_ReleaseOwnedResolvers_Inferred(/*EBX*/ AssManagerResolverEntry* self);
```

## Algorithm

1. If `resolverA (+8)` non-null: call `FUN_00423e00` (manager list remove), scalar-delete A, null A; up to **20** first-element erases on `*DAT_00d1f1fc` string vector (elem **0x1c**) via `FUN_0044d4e0`.
2. If `resolverB (+0xc)` non-null: `key=B`; container = `*DAT_00d1f058 + 0x58`; `FUN_0043e5b0(&key)` find; miss → `vog_LogMessage`; hit → `FUN_0043c550` EraseFirstEqual; scalar-delete B; null B.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_007b65d0_FUN_007b65d0.md`
- Annotated: `docs/reconstruction/raw/aa_007b65d0_FUN_007b65d0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/AssManager_ReleaseOwnedResolvers_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_007b65d0.cpp`
- Report: `docs/agents/task-dual-ab-007b65d0-0043c2e0-w29d-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_00423e00`, `FUN_0044d4e0`, `FUN_0043e5b0`, `FUN_0043c550` (W28-C), `vog_LogMessage`, interface vtbl[0](1) |
| **Callers** | `FUN_004239a0`, `FUN_007b66b0`, `FUN_00939fd0` |

## Confidence

| Claim | Level |
|---|---|
| CF + body size + plain ret | **High** |
| EBX this; slots +8/+0xc | **High** |
| assManager.cpp string + line 0x27b | **High** |
| GuardedVector at manager+0x58 | **High** |
| EraseFirstEqual = `FUN_0043c550` | **High** |
| Product class English / resolver iface type | **Inferred** |
| `FUN_00423e00` key from EAX | **Medium** (call-site bytes; unowned body residual) |
| Runtime / differential | Open |
