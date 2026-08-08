# Review A (reconstruction fidelity): `aa_00636bd0` CVOGHBMoveVehicle_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00636bd0` |
| **VA** | `0x00636bd0` |
| **Body span** | `0x00636bd0`–`0x00636c49` inclusive (**122** bytes / `0x7A`; exclusive end `0x00636c4a` → `cc…`) |
| **Canonical name** | `CVOGHBMoveVehicle_ctor` |
| **Ghidra name** | `FUN_00636bd0` |
| **Review date** | `2026-08-05` (OWN-ONLY **R12-006**) |
| **Reviewer role** | Independent reconstruction review (clean ≡ machine ≡ live decompile CF) |
| **Counterpart** | `reviews/B_aa_00636bd0_CVOGHBMoveVehicle_ctor.md` |
| **System** | `input-drive-control` / CVOGHBMoveVehicle constructor |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_xrefs` / `get_function_callers` / `get_xrefs_to` + `read_memory` (body, vtbl, float globals). **No** `disassemble_bytes`. **No** Launcher.

---

## 1. Purpose

Construct **`CVOGHBMoveVehicle`** (RTTI `.?AVCVOGHBMoveVehicle@@`) as a heartbeat that drives a bound vehicle entity via MoveTo:

1. `CVOGHBBase_ctor(this)`
2. Install subclass vtbl **`PTR_FUN_009e3b70`**
3. `CVOGHBBase_SetPeriodAndCounter(this, -1000, true)` then **`this+0x08 = 0x32` (50 ms pulse)**
4. Init drive fields: acceptDist `+0x2c = 2.5f`, cruiseScale `+0x30 = 0.0f`, aim dword `+0x34 = 15.0f` bits, entity `+0x24 = pEntity`, flag `+0x29 = 0`
5. `CVOGHBBase_AttachOwnerObject` with null or MSVC MI this-adjusted owner from `pEntity`

**Machine proof (`disassemble_function` + `read_memory` len 128 @ entry):**

```text
0x00636bd0:  56                   push  esi
0x00636bd1:  8B F1                mov   esi, ecx
0x00636bd3:  E8 28 16 ED FF       call  0x00508200   ; CVOGHBBase_ctor
0x00636bd8:  6A 01                push  1
0x00636bda:  68 18 FC FF FF       push  0xfffffc18   ; -1000
0x00636bdf:  8B CE                mov   ecx, esi
0x00636be1:  C7 06 70 3B 9E 00    mov   dword [esi], 0x009e3b70
0x00636be7:  E8 B4 15 ED FF       call  0x005081a0   ; SetPeriodAndCounter
0x00636bec:  F3 0F 10 05 C4 A6 AA 00  movss xmm0, [0x00aaa6c4] ; 2.5f
0x00636bf4:  8B 44 24 08          mov   eax, [esp+0x8]         ; pEntity
0x00636bf8:  85 C0                test  eax, eax
0x00636bfa:  F3 0F 11 46 2C       movss [esi+0x2c], xmm0
0x00636bff:  0F 57 C0             xorps xmm0, xmm0
0x00636c02:  F3 0F 11 46 30       movss [esi+0x30], xmm0       ; 0.0f
0x00636c07:  F3 0F 10 05 A4 A7 AA 00  movss xmm0, [0x00aaa7a4] ; 15.0f
0x00636c0f:  C7 46 08 32 00 00 00 mov   dword [esi+0x8], 0x32  ; pulse 50
0x00636c16:  F3 0F 11 46 34       movss [esi+0x34], xmm0
0x00636c1b:  89 46 24             mov   [esi+0x24], eax        ; entity*
0x00636c1e:  C6 46 29 00          mov   byte [esi+0x29], 0
0x00636c22:  75 0E                jnz   0x00636c32
0x00636c24:  50                   push  eax                    ; null
0x00636c25:  8B CE                mov   ecx, esi
0x00636c27:  E8 84 17 ED FF       call  0x005083b0   ; AttachOwnerObject
0x00636c2c:  8B C6                mov   eax, esi
0x00636c2e:  5E                   pop   esi
0x00636c2f:  C2 04 00             ret   4
0x00636c32:  8B 48 04             mov   ecx, [eax+0x4]
0x00636c35:  8B 51 04             mov   edx, [ecx+0x4]
0x00636c38:  8D 44 02 04          lea   eax, [edx+eax+0x4]     ; MI adjust
0x00636c3c:  50                   push  eax
0x00636c3d:  8B CE                mov   ecx, esi
0x00636c3f:  E8 6C 17 ED FF       call  0x005083b0   ; AttachOwnerObject
0x00636c44:  8B C6                mov   eax, esi
0x00636c46:  5E                   pop   esi
0x00636c47:  C2 04 00             ret   4
```

Hex (122 B):
`568bf1e82816edff6a016818fcffff8bcec706703b9e00e8b415edfff30f1005c4a6aa008b44240885c0f30f11462c0f57c0f30f114630f30f1005a4a7aa00c7460832000000f30f114634894624c6462900750e508bcee88417edff8bc65ec204008b48048b51048d440204508bcee86c17edff8bc65ec20400`

Call targets (rel32 decode): `00508200`, `005081a0`, `005083b0`×2 (**High**).

**Calling convention:** MSVC `__thiscall` — object in **ECX**; stack **`void* pEntity`**; **`RET 4`**; **EAX = this**.

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_00636bd0_FUN_00636bd0.md` | R12-006 append (body retained) |
| Annotated | `docs/reconstruction/raw/aa_00636bd0_FUN_00636bd0.annotated.md` | Refresh |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBMoveVehicle_ctor.cpp` | New |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00636bd0.cpp` | Replaced scaffold |
| Function FUN | `docs/reconstruction/functions/aa_00636bd0_FUN_00636bd0.md` | Updated |
| Function named | `docs/reconstruction/functions/aa_00636bd0_CVOGHBMoveVehicle_ctor.md` | New |
| Live decompile | Ghidra `0x00636bd0` | CF if/call ≡ machine |
| Live bytes | `read_memory` | ≡ instruction map (122 B) |
| Live xrefs | code CALL from `FUN_00599550` @ `0x00599558` only | ToMouse subclass ctor |
| Vtbl | `read_memory` @ `0x009e3b70` | dtor/OnHB/OnEnd sealed siblings |
| Float globals | `DAT_00aaa6c4`=2.5f; `DAT_00aaa7a4`=15.0f | IEEE decode |
| Parent dual | `aa_00636cc0` OnHeartBeat | consumes +0x24/+0x2c/+0x30/+0x34 |
| Callee duals | Base ctor / SetPeriod / AttachOwner | dualed |
| Partition | `WAVE_2026-08-05_r12_residual_partition_map.md` | R12-006 |

**Not performed:** Launcher, runtime golden, bit-exact package diff, dual of ToMouse ctor `00599550` (other VA).

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 122 B / end `0x00636c49` | **High** | bytes + next `cc` pad |
| `this` in ECX; stack pEntity; `RET 4`; EAX=this | **High** | prologue/epilogue |
| Base ctor then vtbl `009e3b70` | **High** | call + store |
| SetPeriod(-1000,true) then pulse `+0x08=50` | **High** | dual-period pattern |
| acceptDist `+0x2c=2.5f` | **High** | MOVSS + `read_memory` float |
| cruiseScale `+0x30=0.0f` | **High** | XORPS + store |
| aim dword `+0x34=15.0f` bits | **High** | MOVSS from `DAT_00aaa7a4` |
| entity raw store `+0x24=pEntity` | **High** | before attach branch |
| flag `+0x29=0` | **High** | imm0 |
| Null → Attach(null); non-null → MI adjust | **High** | two RET arms |
| Class = CVOGHBMoveVehicle | **High** | RTTI + vtbl siblings dualed |
| Sole code caller ToMouse `00599550` | **High** | xrefs |
| Product English for `+0x29` flag | **Open** | written 0 only |
| MI-adjust owner type | **Tentative** | expression sealed; product type open |
| Runtime / bit-exact | **Open** | deferred |

---

## 4. Control flow: clean ≡ machine ≡ decompile

| Stage | Match |
|---|---|
| Base ctor → vtbl install | **Yes** |
| SetPeriod(-1000,true) then +0x08=0x32 | **Yes** |
| Field inits 2.5 / 0 / 15 / entity / flag0 | **Yes** |
| Dual Attach arms + RET 4 | **Yes** |
| Return this in EAX | **Yes** |

### 4.1 Dual-period note

`SetPeriodAndCounter(-1000, true)` writes sentinel/counter at **`+0x0C`/`+0x10` = -1000** (always-ready reschedule mode). Real pulse period is then set at **`+0x08 = 50`**. Matches combat-pool dual-period convention (do not treat -1000 as the fire interval).

### 4.2 Entity vs owner split

| Slot | Source | Consumer |
|---|---|---|
| `+0x24` | raw stack `pEntity` | OnHeartBeat MoveTo ECX; OnEnd entity gate |
| `+0x18` | AttachOwner (null or MI-adjusted) | HB list manager via owner+0xB0 |

Do not assume `+0x24 == +0x18`.

### 4.3 Vtbl installed (`PTR_FUN_009e3b70`)

| Slot | VA | Role (sibling duals) |
|---|---|---|
| +0x00 | `0x00636d10` | ScalarDeletingDtor (R11-024) |
| +0x04 | `0x00508270` | StampLastFireTime / default OnStart |
| +0x08 | `0x005082c0` | TryFire |
| +0x0c | `0x00636cc0` | OnHeartBeat (R11-023 parent) |
| +0x10 | `0x00636ba0` | OnEnd (MEGA-017) |
| +0x14 | `0x005081f0` | EmptyVFunc |
| +0x18 | `0x005083f0` | EndOrDestroy |
| +0x1c | `0x00599680` | (residual) |

---

## 5. Gaps (honest)

1. Runtime / CE under live alloc → ctor → Enqueue → TryFire.
2. Product English for byte `+0x29`.
3. Exact product type of MI-adjusted Attach owner (expression sealed).
4. ToMouse subclass ctor `00599550` residual (overrides vtbl + writes `+0x40`).
5. Whether `+0x34` 15.0f default is ever overwritten before MoveTo.
6. PDB method symbol beyond RTTI class + ctor role.
7. Bit-exact / differential.

---

## 6. Verdict

**accept-with-gaps** — CF/ABI/RET4/vtbl/RTTI class/field defaults/dual-period/Attach arms sealed from machine; flag English + MI owner type + runtime open. **No Runtime Confirmed.**
