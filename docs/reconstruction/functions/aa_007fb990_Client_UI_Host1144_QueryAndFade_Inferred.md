# Function record: Client_UI_Host1144_QueryAndFade_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fb990` |
| **Canonical name** | `Client_UI_Host1144_QueryAndFade_Inferred` |
| **Ghidra name** | `FUN_007fb990` |
| **Address** | `0x007fb990` |
| **Body** | `0x007fb990`–`0x007fb9d3` inclusive (**68 B** / `0x44`); pad `CC` after |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `input-drive-control` |
| **Completion status** | **Dual A/B sealed 2026-08-05 (R12-007)** — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred; Terminal **false**) |

## Alias

- Ghidra / scaffold: `FUN_007fb990`
- Superseded: `Named_CalleeOf_Client_Input_OnKeyDown_MatchAction_007fb990`
- Scaffold record: `aa_007fb990_FUN_007fb990.md`

## Purpose

Shared **ESI-host** UI cleanup leaf for NDUI object at **`host+0x1144`**:

1. Null-check slot.
2. Query `obj->vtbl[+0xd0]()` (AL non-zero).
3. State `obj->vtbl[+0xe8]()` must **not** be `-1`.
4. Fade/transition `obj->vtbl[+0xfc](0, 0.1f)` (`0x3dcccccd`).

Does **not** park drive, write mode latch `+0x493`, or clear skill pending `+0x30c0` — those remain in callers (e.g. parent `Client_SetModeLatch493_ParkDriveOnClear_Inferred`).

## Signature

```c
// ESI = client UI host (often &DAT_00d1a840); plain RET; no stack args
void Client_UI_Host1144_QueryAndFade_Inferred(void /* ESI host */);
```

## Artifacts

| Kind | Path |
|------|------|
| Raw (+ R12-007 re-verify) | `docs/reconstruction/raw/aa_007fb990_FUN_007fb990.md` |
| Annotated | `docs/reconstruction/raw/aa_007fb990_FUN_007fb990.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_UI_Host1144_QueryAndFade_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_007fb990.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_007fb990_Client_UI_Host1144_QueryAndFade_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_007fb990_Client_UI_Host1144_QueryAndFade_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_007fb990_FUN_007fb990.md` |
| Report | `docs/agents/task-dual-ab-007fb990-r12-report.md` |

## Callers / callees

**Callers (15 UNCONDITIONAL_CALL):**

| Site | Function / note |
|------|-----------------|
| `00914c9e` | `FUN_00914c60` parent dual — mode latch clear (`MOV ESI,&DAT_00d1a840`) |
| `00911199` | `Client_Input_OnKeyDown_MatchAction` — after PromptSkillTargetSelect(-1) |
| `00925279` | `FUN_009251d0` interact/pick cancel path |
| `007fc896` | `FUN_007fc840` |
| `007fc9f2` | `FUN_007fc9b0` |
| `007fd1a7` | `FUN_007fd090` |
| `00935504` | `FUN_00935430` |
| `0090e419` | `FUN_0090e3c0` |
| `0090e18b` | site with `MOV ESI,&DAT_00d1a840` |
| `008a1f21` | `FUN_008a1e60` |
| `0082914c` | site with `MOV ESI,&DAT_00d1a840` |
| `008c4c37` | site with `MOV ESI,&DAT_00d1a840` |
| `0087b942` | site with `MOV ESI,&DAT_00d1a840` |
| `0088ca71` | site with `MOV ESI,&DAT_00d1a840` |
| `00942427` | `FUN_009423b0` (`MOV ESI,EBX` client this) |

**Callees:** none by name.

| Kind | Target | Role |
|------|--------|------|
| Indirect | `*(host+0x1144)->vtbl+0xd0` | query bool |
| Indirect | `*(host+0x1144)->vtbl+0xe8` | state/index (`-1` skip) |
| Indirect | `*(host+0x1144)->vtbl+0xfc` | fade `(0, 0.1f)` |

## Related (not owned)

| Unit | VA | Note |
|------|-----|------|
| `Client_SetModeLatch493_ParkDriveOnClear_Inferred` | `0x00914c60` | dualed R11-037 parent; clear path calls this |
| `Client_UI_CreateNDUIDialogs_InstallHost_Inferred` | `0x0093e7e0` | installs `+0x1144` |
| `FUN_007b5dd0` | ctor for slot object | residual |

## Confidence

| Claim | Level |
|---|---|
| CF / ABI (ESI) / RET / xrefs / bytes | **High** (live dual) |
| Product English name | **Probable** structural → `_Inferred` |
| Runtime Confirmed | **Open** |
