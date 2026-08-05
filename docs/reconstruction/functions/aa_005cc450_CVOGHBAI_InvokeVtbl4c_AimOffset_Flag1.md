# Function record: CVOGHBAI_InvokeVtbl4c_AimOffset_Flag1

| Field | Value |
|---|---|
| **Stable ID** | `aa_005cc450` |
| **Canonical name** | `CVOGHBAI_InvokeVtbl4c_AimOffset_Flag1` |
| **Ghidra name** | `FUN_005cc450` |
| **Address** | `0x005cc450`–`0x005cc45b` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | npc-ai / HBAI / aim-offset dispatch |
| **Wave** | W28-L OWN dual |
| **Verdict** | **accept** |

## Signature

```c
void __thiscall CVOGHBAI_InvokeVtbl4c_AimOffset_Flag1(void *self);
```

## Sealed contract

1. Load `this` vtbl.
2. Call slot `+0x4c` with stack args `(this+0x40, 1)`.
3. Return; no other stores.

## Artifacts

See `aa_005cc450_FUN_005cc450.md` for full paths.
