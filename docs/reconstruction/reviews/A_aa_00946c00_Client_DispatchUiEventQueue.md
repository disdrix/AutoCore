# Review A (reconstruction fidelity): `aa_00946c00` `Client_DispatchUiEventQueue`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00946c00` |
| **VA** | `0x00946c00` |
| **Body span** | `00946c00`–`009483e6` (~0x17E6 B) |
| **Canonical name** | `Client_DispatchUiEventQueue` (structural) |
| **Ghidra name** | `FUN_00946c00` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W19-C) |
| **Counterpart** | `reviews/B_aa_00946c00_Client_DispatchUiEventQueue.md` |
| **System** | `missions-progression` / client UI tick |
| **Live tools** | Ghidra `decompile_function` + `read_memory` + callers/callees (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Drain and dispatch the client sector/session UI event queue once per frame tick.**

1. Gate on `client+0xe04` and non-empty `[+0xe8bc,+0xe8c0)` with stride `0x138`.
2. If mission/dialog focus gate open: walk every event, `switch(type@+0x1c)`, run case arms (mission chrome, vehicle park, sector packets, toasts, audio, TFID UI, respawn, …), then clear helper.
3. Else: scan for type `0x1e` only and call `FUN_009430f0`.

Sole static caller: client tick `FUN_0094b520` after `FUN_00944770`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00946c00_FUN_00946c00.md` (+ 2026-07-29 live append) |
| Annotated | `docs/reconstruction/raw/aa_00946c00_FUN_00946c00.annotated.md` |
| Clean plate | `docs/reconstruction/reconstructed-exact/Client_DispatchUiEventQueue.cpp` |
| Scaffold clean | `reconstructed-exact/FUN_00946c00.cpp` |
| Function record | `docs/reconstruction/functions/aa_00946c00_Client_DispatchUiEventQueue.md` |
| Live decompile | Ghidra @ `0x00946c00` (full body; ≡ raw) |
| Bytes | `read_memory` 64 B prologue @ `0x00946c00` |
| Caller | `FUN_0094b520` sole xref |
| Related dual | `A/B_aa_0092ce90_Client_RefreshMissionRelatedUi` (case type 4 callee) |

**Not performed:** `disassemble_bytes`, Launcher, full per-case runtime golden.

---

## 3. Prologue seal (`read_memory` @ `0x00946c00`)

```text
00946c00  55                 push ebp
00946c01  8B EC              mov  ebp, esp
00946c03  83 E4 F8           and  esp, -8
00946c06  6A FF              push -1
00946c08  68 67 BA 9B 00     push LAB_009bba67   ; SEH
... FS ExceptionList install ...
          B8 14 1A 00 00     mov  eax, 0x1A14    ; large frame / chkstk
          E8 …               call __chkstk
          53                 push ebx
          8B D9              mov  ebx, ecx       ; client* = ECX
          8B 83 04 0E 00 00  mov  eax, [ebx+0xe04]
          85 C0              test eax, eax
          … je far exit …
          8B 90 BC E8 00 00  mov  edx, [eax+0xe8bc]
```

Hex (first 64 B):

```
558bec83e4f86aff6867ba9b0064a100000000506489250000000051b8141a0000e84ad1d5ff538bd98b83040e000085c056570f846c0400008b90bce8000085
```

| Claim | Evidence | Conf |
|---|---|---|
| `__fastcall` ECX client | `mov ebx,ecx` | **Confirmed** |
| Session `@client+0xe04` | `mov eax,[ebx+0xe04]` | **Confirmed** |
| Queue begin `@session+0xe8bc` | `mov edx,[eax+0xe8bc]` | **Confirmed** |
| Large SEH/chkstk frame | prologue + decompiler warning | **Confirmed** |
| Live decompile ≡ raw CF | full side-by-side | **Confirmed** |
| Sole caller `FUN_0094b520` | xrefs | **Confirmed** |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role = UI/mission event queue dispatch | **High** | callees + strings + sole tick caller |
| Stride `0x138` / type `@+0x1c` | **Confirmed** | decompile + alternate `*(iVar14+0x1c)==0x1e` |
| Float case labels = int type ids | **Confirmed** | classic MSVC denormal switch |
| Dual branch (full switch vs type-0x1e scan) | **Confirmed** | raw CF |
| Product English function / enum names | **Open** | structural name only |
| Every case product meaning | **Partial** | strings/named callees seal some; many FUN_* open |
| Clean plate ≡ full arm body | **High for CF** | arms live in `FUN_00946c00.cpp` scaffold |

---

## 5. Call graph (this unit)

**Callers:** `FUN_0094b520` only.

**High-signal callees:** `Client_SendSectorPacket`, `Client_RefreshMissionDialogChrome`, `Client_MaybeShowFirstTimeTip`, `Client_SendRespawnInSector`, `VehicleEntity_SetHandbrake`, `VehicleEntity_SetLongitudinalInput`, `Object_ResolveFromTFID`, `TFID_EqualsObjectId`, `FUN_0092ce90`, `FUN_007fef20` (×many), `FUN_008f8200` (toast), `FUN_00406840` (drain).

---

## 6. Gaps

1. Product/PDB name for dispatcher and event type enum.
2. Identity of `client+0xe04` session class and queue field English names.
3. Per-case duals for unowned `FUN_007f*` / `FUN_0080*` arms.
4. Runtime ordering / multi-event golden.
5. Whether queue is cleared only via `FUN_00406840` (not OWN).

**Verdict:** **accept-with-gaps** — structural CF + ABI + queue layout sealed; product case map residual.
