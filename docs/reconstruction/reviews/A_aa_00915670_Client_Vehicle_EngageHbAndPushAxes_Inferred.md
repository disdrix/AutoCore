# Review A (reconstruction fidelity): `aa_00915670` Client_Vehicle_EngageHbAndPushAxes_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00915670` |
| **VA** | `0x00915670`–`0x009156e0` |
| **Canonical name** | `Client_Vehicle_EngageHbAndPushAxes_Inferred` (Ghidra `FUN_00915670`) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B **create** — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile ≡ entry bytes) |
| **Counterpart** | `reviews/B_aa_00915670_Client_Vehicle_EngageHbAndPushAxes_Inferred.md` |
| **System** | `input-drive-control` |
| **Dual status** | **Present (create)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` / `analyze_function_complete` / `get_bulk_xrefs` / `get_assembly_context` / `read_memory` @ entry. Prefer decompile/`read_memory`. Own VA only. No ledgers.

---

## 1. Purpose

Short **client vehicle hard-stop pack**: when the local player vehicle is present and drive is not suppressed (`vehicle+0x101 == 0`), engage handbrake, fire the empty drive-path hook, optionally stop a heartbeat, clear a client latch, and push axes to the controller.

**Live decompile (`0x00915670`, 2026-07-29):**

```c
void FUN_00915670(void)
{
  int unaff_EDI;   // client / game host (register EDI at entry)

  if ((DAT_00d1b6d8 != 0) &&
      (*(int *)(DAT_00d1b6d8 + 0x250) != 0) &&
      (*(char *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x101) == '\0')) {
    *(undefined1 *)(unaff_EDI + 0xa31) = 1;
    VehicleEntity_SetHandbrake(1);           // ECX = vehicle (ESI)
    if ((DAT_00d1a860 == '\0') &&
        (*(char *)(*(int *)(unaff_EDI + 0xc70) + 0x21) == '\0')) {
      FUN_005081d0();                        // CVOGHBBase_Stop (known plate)
    }
    FUN_004f3700();                          // DrivePathNoOp (empty ret)
    if ((DAT_00d1a860 == '\0') && (DAT_00d1d866 == '\0')) {
      *(undefined1 *)(unaff_EDI + 0xa32) = 0;
    }
    VehicleEntity_PushDriveAxesToController();
    return;
  }
  return;
}
```

≡ frozen raw / annotated / clean scaffold CF.

**Entry bytes (`read_memory`):**

```text
0x00915670: a1 d8 b6 d1 00    mov eax, [DAT_00d1b6d8]
0x00915675: 85 c0             test eax, eax
0x00915677: 74 67             jz  short exit
0x00915679: 56                push esi
0x0091567a: 8b b0 50 02 00 00 mov esi, [eax+0x250]   ; vehicle
…
0x0091568c: 6a 01             push 1
0x0091568e: 8b ce             mov ecx, esi
0x00915690: c6 87 31 0a 00 00 01  mov byte ptr [edi+0xa31], 1
0x00915697: e8 …              call VehicleEntity_SetHandbrake
```

---

## 2. Inspected artifacts

| Artifact | Path / tool | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_00915670_FUN_00915670.md` | ≡ live CF |
| Annotated | `docs/reconstruction/raw/aa_00915670_FUN_00915670.annotated.md` | ≡ live CF |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00915670.cpp` | Scaffold CF match |
| Function record | `docs/reconstruction/functions/aa_00915670_FUN_00915670.md` | Scaffold only |
| Live decompile | Ghidra MCP `0x00915670` | **≡ raw** |
| Live bytes | `read_memory` len 96 @ entry | gate + HB(1) + EDI flags |
| Live xrefs | `get_bulk_xrefs` | **1** site `0x00927e48` |
| Call-site asm | `get_assembly_context` | After vfunc `+0x3d8` true; near DriveControlTick |

**Not performed:** Launcher, runtime golden, package bit-exact, Ghidra product rename.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Gate: `DAT_00d1b6d8` + vehicle `+0x250` + `vehicle+0x101==0` | **High** | decompile ≡ asm |
| `SetHandbrake(1)` thiscall ECX=vehicle | **High** | `push 1; mov ecx,esi; call` |
| `FUN_004f3700` empty drive-path hook | **High** | dual-sealed sibling |
| `PushDriveAxesToController` after pack | **High** | last call on allow path |
| Client flags `EDI+0xa31=1`, optional `EDI+0xa32=0` | **High** | decompile ≡ `c6 87 31 0a…` |
| Optional `FUN_005081d0` under `DAT_00d1a860==0` + host `+0xc70→+0x21==0` | **High CF** | product role of `+0x21` open |
| `unaff_EDI` = client/game host | **High** (register) / **Probable** (type English) | used as `+0xa31/+0xa32/+0xc70` |
| Sole xref `0x00927e48` | **High** | bulk xrefs |
| Product English name | **Open** | `_Inferred` |
| Runtime / bit-exact | **Open** | deferred |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Triple gate then pack | **Yes** |
| Order: flag → HB1 → optional Stop → NoOp → optional clear → Push | **Yes** |
| No thr/steer stores in body | **Yes** |
| Early no-op return if gate fails | **Yes** |

### 4.1 Contract

```
require DAT_00d1b6d8 && vehicle=*(+0x250) && *(u8*)(vehicle+0x101)==0
*(u8*)(client+0xa31) = 1
SetHandbrake(vehicle, 1)
if !DAT_00d1a860 && !*(u8*)(*(client+0xc70)+0x21): CVOGHBBase_Stop()
DrivePathNoOp(vehicle)                 // FUN_004f3700 empty ret
if !DAT_00d1a860 && !DAT_00d1d866: *(u8*)(client+0xa32) = 0
PushDriveAxesToController(vehicle)
```

---

## 5. Callers

| Site | Context |
|---|---|
| `0x00927e48` | `CALL 0x00915670` after `[EDX+0x3d8]` true; fallthrough region near `CALL Client_Input_DriveControlTick` (`0x009223b0`). Ghidra did not attach an enclosing function name at the site (orphan / split range after `PollBoundActions` end `0x00927d70`). |

---

## 6. Gaps / open

1. Product English for body / `client+0xa31/+0xa32` latches.
2. Exact enclosing parent symbol at `0x00927e48`.
3. Runtime capture of stop-pack under focus/UI gates.
4. Package-level bit-exact beyond CF seal.

**Verdict:** **accept-with-gaps** — gate order, HB engage, NoOp, Push, client latches, sole xref sealed; product names / runtime open.
