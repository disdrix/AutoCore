# Function record: Client_SetModeLatch493_ParkDriveOnClear_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00914c60` |
| **Canonical name** | `Client_SetModeLatch493_ParkDriveOnClear_Inferred` |
| **Ghidra name** | `FUN_00914c60` |
| **Address** | `0x00914c60` |
| **Body** | `0x00914c60`–`0x00914ce5` inclusive (**134 B** / `0x86`); pad `CC` after |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `input-drive-control` |
| **Completion status** | **Dual A/B sealed 2026-08-05 (R11-037)** — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred; Terminal **false**) |

## Alias

- Prior scaffold: `FUN_00914c60`
- Scaffold record: `aa_00914c60_FUN_00914c60.md`

## Purpose

Virtual client method: **set/clear mode latch `+0x493`** with drive park on clear.

1. **Clear** (`enable==0`) when latch set: `FUN_007fb990` (ESI=`&DAT_00d1a840`), then dualed `Client_Vehicle_StopHbAndZeroLongitudinal_Inferred` (EAX=this), then optional `DAT_00d1b9a8` notify(0) if query true.
2. **Enable** (`enable!=0`) when latch clear: optional host notify(1) if query false.
3. **Always**: zero f32 `this+0x538`; `FUN_007902a0(this, enable)` applies latch.

Does **not** write steer/long axes itself; park is delegated to `0x00914c20` on clear only.

## Signature

```c
// thiscall ECX = client host; stack enable (char); RET 4
void __thiscall Client_SetModeLatch493_ParkDriveOnClear_Inferred(
    void* client /* ECX */,
    std::uint32_t enable /* stack */);
```

## Artifacts

| Kind | Path |
|------|------|
| Raw (+ R11-037 re-verify) | `docs/reconstruction/raw/aa_00914c60_FUN_00914c60.md` |
| Annotated | `docs/reconstruction/raw/aa_00914c60_FUN_00914c60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_SetModeLatch493_ParkDriveOnClear_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00914c60.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_00914c60_Client_SetModeLatch493_ParkDriveOnClear_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00914c60_Client_SetModeLatch493_ParkDriveOnClear_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00914c60_FUN_00914c60.md` |
| Report | `docs/agents/task-dual-ab-00914c60-r11-report.md` |

## Callers / callees

**Callers:** none direct.

| Kind | Site | Notes |
|------|------|-------|
| DATA xref | `0x00a2f468` | vtable slot → `0x00914c60` |

**Callees:**

| Callee | VA | Role |
|--------|-----|------|
| `FUN_007fb990` | `0x007fb990` | clear-path UI/camera helper (ESI global client) |
| `Client_Vehicle_StopHbAndZeroLongitudinal_Inferred` | `0x00914c20` | clear-path drive park |
| `FUN_007902a0` | `0x007902a0` | apply `+0x493` latch |
| `DAT_00d1b9a8` vtbl `+0xd0` / `+4` | indirect | query / notify |

## Related (not owned)

| Unit | VA | Note |
|------|-----|------|
| `Client_Vehicle_StopHbAndZeroLongitudinal_Inferred` | `0x00914c20` | dualed MEGA-098 parent leaf |
| `FUN_007fb990` / `FUN_007902a0` | residual scaffolds | OWN-ONLY excluded |

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / RET / vtable xref | **High** (live dual) |
| Product English name | **Probable** structural → `_Inferred` |
| Runtime Confirmed | **Open** |
