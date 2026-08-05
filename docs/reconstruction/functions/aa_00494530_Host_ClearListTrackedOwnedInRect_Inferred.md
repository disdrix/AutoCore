# Function record: Host_ClearListTrackedOwnedInRect_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00494530` |
| **Canonical name** | `Host_ClearListTrackedOwnedInRect_Inferred` |
| **Ghidra name** | `FUN_00494530` |
| **Address** | `0x00494530`–`0x0049459d` inclusive (**110 B** / `0x6E`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Wave** | W31-D OWN-ONLY |
| **Verdict** | **accept-with-gaps** |

## Role

Host **rect clearer** for owned pointers at grid `elem+0x24` (element stride **0x28**, arr @ `host+0x28`). Pairs with single-cell scaled clearer `Ctx_ClearListTrackedOwnedAtScaledXY_Inferred` (`0x00497a30`) and owned complete dtor `ListTrackedObj_CompleteDtor` (`0x004be2a0`, W30-P).

## Signature

```c
void __fastcall Host_ClearListTrackedOwnedInRect_Inferred(void* host);
```

## Port notes

- Rect half-open: `+0x64/+0x6C` (x), `+0x68/+0x70` (y); index = `dimX(+4)*y + x`.
- Always null `+0x24` even if already null.
- Ignore Ghidra noreturn on `operator_delete`.
- Do **not** free the element array here (that is `Host_ClearElem0x28Array_Inferred` / complete dtor).

## Artifacts

See `aa_00494530_FUN_00494530.md` for full artifact table.
