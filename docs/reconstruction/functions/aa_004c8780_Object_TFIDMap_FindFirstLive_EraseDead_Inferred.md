# Function record: Object_TFIDMap_FindFirstLive_EraseDead_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c8780` |
| **Canonical name** | `Object_TFIDMap_FindFirstLive_EraseDead_Inferred` |
| **Ghidra name** | `FUN_004c8780` |
| **Address** | `0x004c8780`–`0x004c8963` exclusive (**483 B** / `0x1E3`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | creature/object TFID map / resolve scrub |
| **Classification** | worker (host method; map walk + domain gates) |
| **Completion status** | **accept-with-gaps** — dual A/B sealed 2026-08-04 (WQ9F-C OWN) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual verdict** | **accept-with-gaps** |
| **Terminal** | **false** |

## Purpose

Walk the host's embedded TFID map (`shell +0x154`, `head +0x158`):

1. Resolve each node's TFID (`Object_ResolveFromTFID`).
2. **Dead:** if TFID matches selected target (MI `+0x44/+0x48/+0x4c`), clear via host `vtbl+0x258` with null TFID `DAT_009cb8c0`; erase via `StdTree_EraseAndRebalance_Isnil29` with **`lea ecx,[this+0x154]`**.
3. **Live:** return object if `vtbl+0x210(0)` non-null, or if related (`vtbl+0x214`) resolves via `Object_ResolveTfIdVtbl1dc` on blob `@+0x228`.
4. Else successor; exhaust → **null**.

## Signature (byte-sealed)

```c
void * __thiscall Object_TFIDMap_FindFirstLive_EraseDead_Inferred(void *self);
// bare ret; frame sub/add esp,0x24
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004c8780_FUN_004c8780.md`
- Annotated: `docs/reconstruction/raw/aa_004c8780_FUN_004c8780.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/Object_TFIDMap_FindFirstLive_EraseDead_Inferred.cpp`
- Clean FUN_*: `docs/reconstruction/reconstructed-exact/FUN_004c8780.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004c8780_Object_TFIDMap_FindFirstLive_EraseDead_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_004c8780_Object_TFIDMap_FindFirstLive_EraseDead_Inferred.md`
- Alias record: `docs/reconstruction/functions/aa_004c8780_FUN_004c8780.md`
- Report: `docs/agents/task-dual-ab-004c8780-004cbaa0-wq9fc-report.md`

## Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Callers | *(none recovered)* | Ghidra xrefs empty this pass |
| Callee | `Object_ResolveFromTFID` | TFID → object |
| Callee | `StdTree_EraseAndRebalance_Isnil29_Inferred` `0x004cb740` | dead erase; ECX=`this+0x154` |
| Callee | `Object_ResolveTfIdVtbl1dc_Inferred` `0x004bb0d0` | related blob gate |
| Callee | indirect | `vtbl+0x210(0)`, `vtbl+0x214()`, host `vtbl+0x258` |

**Sibling (not OWN):** `FUN_004c8610` (map decay scrub; called from `FUN_00638ac0`).

## Confidence

| Claim | Level |
|---|---|
| CF + ABI | **High** |
| Map +0x154 / erase thiscall | **High** |
| First-live + dead-erase role | **High** |
| Product English / callers | Open / Low–Med |
| Runtime | Open |
