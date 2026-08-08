# Function record: CWndVehicle_DerivedTeardown_EDI

| Field | Value |
|---|---|
| **Stable ID** | `aa_00833d50` |
| **Canonical name** | `CWndVehicle_DerivedTeardown_EDI` |
| **Ghidra name** | `FUN_00833d50` |
| **Address** | `0x00833d50` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body** | `0x00833d50`–`0x00833df7` exclusive (**167 B** / `0xA7`) |
| **System** | CWndVehicle / UI derived member teardown |
| **Agent** | WQ9K-E OWN-ONLY dual 2026-08-05 |
| **Completion status** | Dual sealed (A/B accept-with-gaps) |
| **Terminal** | **false** |

## Purpose

Derived member teardown for **CWndVehicle** (host sealed via complete dtor RTTI `.?AVCWndVehicle@@` / vtbl `PTR_FUN_00a6fbcc`). Clears selection dword `+0x50C`; re-notifies nested host `@+0x2A8`; scalar-deletes vehicle object `@+0x508` (optional child `@+0x258` + `Vehicle_SetWheelset(0)`); nulls `+0x508`. Does **not** free the window or run base `CNDUIWndBuffered` dtor.

## Signature

```c
// Machine: EDI = CWndVehicle* this; no stack formals; bare RET; void
void CWndVehicle_DerivedTeardown_EDI(void);
// Port form (explicit this):
void CWndVehicle_DerivedTeardown(CWndVehicle *self);
```

## Layout (CWndVehicle fields touched)

| Offset | Field (inferred) |
|---|---|
| +0x2A8 | nested host* (notify plate) |
| +0x508 | vehicle object host* (scalar-deleted) |
| +0x50C | selection / state dword (cleared) |

## Call graph

| Role | Target |
|---|---|
| **Primary caller** | `CWndVehicle_CompleteDtor` @ `0x00834520` site `0x0083458d` |
| Other callers | `FUN_00833e30`, `FUN_0083ac90`, `FUN_0084b210`, `FUN_0088d980` |
| Nested stamp | `FUN_0076c4d0` |
| Wheelset | `Vehicle_SetWheelset` @ `0x004fea90` |

## Evidence summary

- Live decompile ≡ raw; entry `MOV ESI,[EDI+0x2A8]` seals EDI=this.
- Complete dtor dual (WQ9J-B) documents this helper as derived teardown with EDI ABI.
- Double-notify of nested `@+0x2A8` when both complete and this helper run — preserve.
- Do not merge with complete dtor or scalar-deleting dtor.

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/CWndVehicle_DerivedTeardown_EDI.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00833d50.cpp`
- Raw: `docs/reconstruction/raw/aa_00833d50_FUN_00833d50.md`
- Annotated: `docs/reconstruction/raw/aa_00833d50_FUN_00833d50.annotated.md`
- Review A: `docs/reconstruction/reviews/A_aa_00833d50_CWndVehicle_DerivedTeardown_EDI.md`
- Review B: `docs/reconstruction/reviews/B_aa_00833d50_CWndVehicle_DerivedTeardown_EDI.md`
- Report: `docs/agents/task-dual-ab-00408ed0-00833d50-wq9ke-report.md`
