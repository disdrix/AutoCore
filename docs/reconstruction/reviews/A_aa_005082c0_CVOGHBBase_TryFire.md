# Review A (reconstruction fidelity): `aa_005082c0` CVOGHBBase_TryFire

| Field | Value |
|---|---|
| **Stable ID** | `aa_005082c0` |
| **VA** | `0x005082c0` |
| **Canonical name** | `CVOGHBBase_TryFire` |
| **Review date** | `2026-07-29` (machine seal; prior accept-with-gaps 2026-07-23) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005082c0_CVOGHBBase_TryFire.md` |
| **System** | `heartbeat` / timed-actions |
| **Live tools** | Ghidra `decompile_function` + `read_memory` + pcode offsets + sibling duals (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** (CF/offsets High; OnHeartBeat return ABI residual; −1000@+0x08 vs combat-pool myth corrected) |

---

## 1. Purpose

Per-tick heartbeat decision for one `CVOGHBBase` action: whether to invoke virtual **OnHeartBeat** (`vtable+0x0C`) and which **EHBStatus** to write through the stack out-param.

**List contract (sibling `CVOGHBList_Tick`):** active slots call **vtable+0x08** (`TryFire`); status **`& 0x10`** → remove/destroy. Value **16** is that Remove bit / shared dword, **not** combat-pool regen period.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005082c0_CVOGHBBase_TryFire.md` |
| Annotated | `docs/reconstruction/raw/aa_005082c0_CVOGHBBase_TryFire.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBBase_TryFire.cpp` |
| Function record | `docs/reconstruction/functions/aa_005082c0_CVOGHBBase_TryFire.md` |
| Siblings (context, not owned) | StampLastFireTime, SetPeriodAndCounter, GetRemainingSeconds, RescheduleAfterFire, Regeneration_ctor, List_Tick |

---

## 3. Seal: body (`read_memory` @ `0x005082c0`)

Body range **`0x005082c0`–`0x00508347`** (`ret 4`); padding `CC` after. Hex:

```
51 8b 15 cc 41 b0 00 56 8b f1 80 7e 20 00 74 17
8b 0d e8 19 af 00 8b 44 24 0c 89 08 5e 59 c2 04 00
8b 4e 08 81 f9 18 fc ff ff 74 4c 8b 46 14 57 8b fa
2b f8 3b f9 5f 77 04 3b c2 76 3b 80 7e 21 00 74 17
8b 44 24 0c 8b 15 e4 19 af 00 89 10 5e 59 c2 04 00
8b 06 8d 4c 24 04 51 8b ce ff 50 0c 8b 00 8b 15 cc 41 b0 00
8b 4c 24 0c 89 56 14 89 01 8b c1 5e 59 c2 04 00
8b 0d d0 41 b0 00 8b 44 24 0c 89 08 5e 59 c2 04 00
```

### Control flow (machine)

```
push ecx                         ; save this
mov  edx, [0x00b041cc]           ; g_dwClientTickMs (snapshot)
push esi
mov  esi, ecx                    ; this
cmp  byte [esi+0x20], 0          ; cStopped
jz   period_gate
  *pOut = [0x00af19e8]           ; g_dwTimedActionDefaultPeriodMs → Remove(16)
  ret 4

period_gate:
mov  ecx, [esi+0x08]             ; nPeriodMs @ +0x08
cmp  ecx, 0xFFFFFC18             ; -1000
jz   write_continue              ; NO fire when +0x08 == -1000
mov  eax, [esi+0x14]             ; dwLastFireTickMs
elapsed = tick - lastFire
if (elapsed > nPeriodMs) OR (lastFire > tick)  ; unsigned; wrap
  cmp  byte [esi+0x21], 0        ; fDormant
  jnz  write_inactive            ; *out = [0x00af19e4] (2); ret 4
  call [vtable+0x0C] OnHeartBeat
  *out = *returned_status_ptr
  [esi+0x14] = g_dwClientTickMs  ; stamp (inline; not StampLastFireTime call)
  ret 4
else
  write_continue: *out = [0x00b041d0] (0); ret 4
```

### ABI

| Item | Machine | Conf |
|---|---|---|
| Convention | MSVC **thiscall**: ECX = this; **one** stack formal `uint* pOutStatus`; **`ret 4`** | **High** |
| Return | EAX = `pOutStatus` (pointer identity) | **High** |
| Out location after prolog | `[esp+0xC]` (after `push ecx; push esi`) | **High** |
| Decompiler `__fastcall` + `unaff_retaddr` | **Residual** — stack formal is real; phantom aliasing | **High** (artifact only) |

### Field offsets (this unit)

| Offset | Field | Access |
|---|---|---|
| `+0x00` | `pVTable` | load for OnHeartBeat |
| `+0x08` | `nPeriodMs` | period gate vs elapsed **and** vs `-1000` |
| `+0x14` | `dwLastFireTickMs` | elapsed base; stamp on fire |
| `+0x20` | `cStopped` (byte) | → Remove |
| `+0x21` | `fDormant` (byte) | → Inactive without OnHeartBeat |

**Does not read `+0x0C` (`nPeriodSentinel`) or `+0x10` (`nPeriodCounter`).** Those are SetPeriodAndCounter / RescheduleAfterFire / GetRemaining domain.

### Globals (`read_memory`)

| VA | Symbol | LE bytes | Value | Role here |
|---|---|---|---|---|
| `0x00af19e8` | `g_dwTimedActionDefaultPeriodMs` | `10 00 00 00` | **16** | written as **Remove** when stopped |
| `0x00af19e4` | `g_dwHBStatusInactive` | `02 00 00 00` | **2** | dormant path |
| `0x00b041d0` | `g_dwHBStatusContinue` | `00 00 00 00` | **0** | not due / `+0x08==-1000` |
| `0x00b041cc` | `g_dwClientTickMs` | BSS `00…` static | tick ms | elapsed + stamp |

### Virtual call

| Slot | Offset | Role |
|---|---|---|
| vtbl[3] | `+0x0C` | **OnHeartBeat** — only callee; returns **pointer** to status dword (`mov eax,[eax]`) |

List_Tick binds **TryFire** at vtbl **`+0x08`** (slot 2). No **code** CALL xrefs to `0x005082c0` — only **DATA** vtable slots (76 xrefs).

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `cStopped (+0x20) → *out = 16 (Remove)` via `g_dwTimedActionDefaultPeriodMs` | **High** | machine + constant |
| **16 ≠ combat regen period** (regen 3000/5000 @ `+0x08` from Regeneration_ctor) | **High** | dual-field model |
| Period / −1000 gate is **`this+0x08`**, not `+0x0C` | **High** | `8B 4E 08` / `81 F9 18 FC FF FF` |
| **`+0x08 == -1000` → Continue, no OnHeartBeat** | **High** | `jz write_continue` |
| Elapsed due: **`elapsed > nPeriodMs` (strict)** OR lastFire > tick | **High** | `ja` / wrap `cmp` |
| `fDormant (+0x21) → Inactive(2)`, no fire | **High** | body |
| OnHeartBeat then stamp `+0x14` then `*out = status` | **High** | body |
| Continue(0) when not due | **High** | body |
| Clean struct had wrong period bind (`+0x0C`) / “always ready” myth | **Corrected this seal** | prior 2026-07-23 dual overstated |
| OnHeartBeat full formal ABI (extra `push &saved_this`) | **Probable / residual** | sibling OnHeartBeat bodies own return shape |
| EHBStatus enum completeness beyond 0/2/0x10 | **Open** | other bits unused here |

---

## 5. Control flow: clean ≡ raw ≡ machine

| Stage | Match after seal |
|---|---|
| Stopped → Remove(16) | **Yes** |
| Period gate @ **+0x08** / −1000 → Continue | **Yes** (clean updated) |
| Elapsed / wrap → dormant vs OnHeartBeat | **Yes** |
| Stamp `+0x14` on fire | **Yes** |
| Status out-param + `ret 4` | **Yes** |
| Prior plate “combat-pool always ready via −1000 in TryFire” | **No** — combat pool keeps real ms @ `+0x08`; −1000 is **`+0x0C` Reschedule** |

---

## 6. Gaps / open

1. Exact OnHeartBeat return-object lifetime (pointer into callee stack / static / out-object).
2. Which HB types ever set **`+0x08 = -1000`** (suppress period fire) — not Regeneration (writes 3000/5000).
3. Full EHBStatus bit set beyond Continue/Inactive/Remove.
4. Runtime / bit-exact harness not run.

**Verdict:** **accept-with-gaps**
