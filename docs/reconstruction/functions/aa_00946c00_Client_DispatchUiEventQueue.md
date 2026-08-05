# Function record: Client_DispatchUiEventQueue

| Field | Value |
|---|---|
| **Stable ID** | `aa_00946c00` |
| **Canonical name** | `Client_DispatchUiEventQueue` (structural; product/PDB open) |
| **Ghidra name** | `FUN_00946c00` |
| **Address** | `0x00946c00` |
| **Body span** | `00946c00`–`009483e6` (~0x17E6 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` / client UI tick |
| **Completion status** | **Dual A/B sealed** (W19-C 2026-07-29) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Client-frame **UI/mission/dialog event queue dispatcher**. When `client+0xe04` holds a session with a non-empty `0x138`-byte event vector (`+0xe8bc`/`+0xe8c0`), walk entries and `switch` on type at `entry+0x1c`. Arms drive mission chrome, tips, vehicle park inputs, sector packets, toasts, vendor sounds, respawn, etc. Alternate gate scans only for type `0x1e`.

## Signature

```c
void __fastcall Client_DispatchUiEventQueue(void *client);  // ECX = client*
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00946c00_FUN_00946c00.md`
- Annotated: `docs/reconstruction/raw/aa_00946c00_FUN_00946c00.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_DispatchUiEventQueue.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_00946c00.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00946c00_Client_DispatchUiEventQueue.md`
- Review B: `docs/reconstruction/reviews/B_aa_00946c00_Client_DispatchUiEventQueue.md`
- Prior scaffold record: `docs/reconstruction/functions/aa_00946c00_FUN_00946c00.md` (superseded by this)

## Callers / callees

**Callers (sole):** `FUN_0094b520` @ `0x0094b520` (after `FUN_00944770` in client tick).

**Named callees (high-signal sample):**

| Symbol | VA |
|---|---|
| `Client_SendSectorPacket` | `0x00807460` |
| `Client_RefreshMissionDialogChrome` | `0x009306a0` |
| `Client_MaybeShowFirstTimeTip` | `0x00801760` |
| `Client_SendRespawnInSector` | `0x00935300` |
| `Client_GetMissionCompleteAudioTable` | `0x00723820` |
| `Client_PlayNamedInterfaceSound` | `0x00726d00` |
| `VehicleEntity_SetHandbrake` | `0x004f3620` |
| `VehicleEntity_SetLongitudinalInput` | `0x004f5650` |
| `Object_ResolveFromTFID` | `0x004bb950` |
| `TFID_EqualsObjectId` | `0x00404aa0` |
| `FUN_0092ce90` (`Client_RefreshMissionRelatedUi`) | `0x0092ce90` |
| `StdMap_LowerBoundByIntKey_INFERRED` | `0x004054f0` |

Plus many `FUN_007f*` / `FUN_0080*` / `FUN_0093*` UI helpers (not OWN).

## Confidence

| Claim | Level |
|---|---|
| CF: queue gate + dual branch + switch walk | **Confirmed** (live decompile ≡ raw) |
| ABI fastcall client ECX | **Confirmed** (prologue `mov ebx,ecx`) |
| Record stride `0x138` / type `@+0x1c` | **Confirmed** |
| Denormal case labels = int type ids | **Confirmed** (MSVC switch pattern) |
| Product type enum / function English name | **Open** |
| Per-case product meaning | **Partial** (some strings/callees High; many Open) |

## Dual verdict

**accept-with-gaps**
