# Function record: UI_Mail2dPanel_BuildChrome_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008b84a0` |
| **Canonical name** | `UI_Mail2dPanel_BuildChrome_Inferred` |
| **Ghidra name** | `FUN_008b84a0` |
| **Address** | `0x008b84a0`–`0x008b8b76` (1751 B / `0x6D7`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | inventory-transfer (mail 2d UI chrome builder; client-only) |
| **Partition** | R13-013 (dual start 2686; parent residual `0x00756c90`) |
| **Completion status** | **Dual sealed** — A/B accept-with-gaps; trio refreshed; Runtime Confirmed **not** claimed |
| **Bit-for-bit / runtime / diff** | Open (no Launcher) |

## Alias

- Ghidra: `FUN_008b84a0`
- Rejected scaffold: `UI_mail_bg_frame_deposit` (single send-arm plate; not method role)

## Purpose

Build / initialize **mail 2d panel chrome**: shared window chrome + close, dual receive/send tabs, then mode-gated (`this+0x510`) receive-list vs send-compose surfaces. Uses dualed tab select / move-to-front helpers. Optional 10 s receive refresh via residual `FUN_00980250` payload `3`.

## Signature

```c
void __thiscall UI_Mail2dPanel_BuildChrome_Inferred(Mail2dPanel* this);
// ECX = this; no stack args; plain RET
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_008b84a0_FUN_008b84a0.md` |
| Annotated | `docs/reconstruction/raw/aa_008b84a0_FUN_008b84a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_Mail2dPanel_BuildChrome_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_008b84a0.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_008b84a0_UI_Mail2dPanel_BuildChrome_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_008b84a0_UI_Mail2dPanel_BuildChrome_Inferred.md` |
| Report | `docs/agents/task-dual-ab-008b84a0-r13-report.md` |
| FUN record | `docs/reconstruction/functions/aa_008b84a0_FUN_008b84a0.md` |

## Callers / callees

**Callers:** none direct — DATA vtable `@0x00a475b0`.

**Callees (selected):** `FUN_00792600`, `operator_new`, `FUN_008230b0`, `FUN_008b7240`, `FUN_008b6d50`, dualed `FUN_00822cb0`, dualed `FUN_00756c90`, `GetTickCount`, `FUN_00980250`, `FUN_007a69d0`, `FUN_007a6de0`, `FUN_00977a30`, plus many vcalls.

## Confidence

| Claim | Level |
|---|---|
| Control flow / ABI / offsets / control ids | Confirmed (static Ghidra) |
| Product class English | Inferred → `_Inferred` |
| Refresh wire opcode map | Open |
| Runtime Confirmed | **Not claimed** |
