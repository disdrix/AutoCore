# Function record: OwningSList_ClearDestroy_ScalarDtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bf740` |
| **Canonical name** | `OwningSList_ClearDestroy_ScalarDtor_Inferred` |
| **Ghidra name** | `FUN_004bf740` |
| **Address** | `0x004bf740`–`0x004bf76f` exclusive (**47** B / `0x2F`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | owning singly-linked list clear / ListTrackedObj list region |
| **Completion status** | **Sealed** — dual A/B W31-B 2026-07-29; **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Dual verdict** | **accept-with-gaps** |

## Naming evidence

| Source | Value |
|---|---|
| Sole CALL xref | `ListTrackedObj_CompleteDtor` (`FUN_004be2a0`) @ `0x004be321` — `this+0x10` list region |
| Body | while head@`+4`: unlink next@`node+4`; `vtbl[0](1)`; count@`+0xc`-- |
| Product mangled on this VA | **No** |
| Scaffold rejected | `Named_CalleeOf_*_VOG_DEBUG_ST_004bf740` |

**Decision:** promote **`OwningSList_ClearDestroy_ScalarDtor_Inferred`** (structural role sealed; product English residual → `_Inferred`).

## Signature

```c
// thiscall ECX = list host; bare ret; void
// host+0x04 = head Node*; host+0x0c = count
// Node: vtbl* @+0, next @+4; vtbl[0](1) = scalar deleting dtor
void __fastcall OwningSList_ClearDestroy_ScalarDtor_Inferred(void* host);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004bf740_FUN_004bf740.md`
- Annotated: `docs/reconstruction/raw/aa_004bf740_FUN_004bf740.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/OwningSList_ClearDestroy_ScalarDtor_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004bf740.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004bf740_OwningSList_ClearDestroy_ScalarDtor_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_004bf740_OwningSList_ClearDestroy_ScalarDtor_Inferred.md`
- Scaffold record: `docs/reconstruction/functions/aa_004bf740_FUN_004bf740.md`

## Confidence

| Claim | Level |
|---|---|
| Body 47 B; ECX thiscall; bare ret | **Confirmed** (`read_memory` + decompile) |
| head@+4, next@node+4, count@+0xc | **Confirmed** |
| `vtbl[0](1)` scalar-deleting dtor | **Confirmed** (push 1; call [edx]) |
| Sole caller ListTrackedObj complete dtor | **Confirmed** (xrefs) |
| Product English / node T | **Inferred** / open |
| Runtime | **Open** |
