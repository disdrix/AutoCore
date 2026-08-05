# Review A (reconstruction fidelity): `aa_00508200` CVOGHBBase_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00508200` |
| **VA** | `0x00508200` |
| **Body** | `0x00508200`–`0x0050822c` (**45** bytes incl. `ret`; pad `CC` after) |
| **Canonical name** | `CVOGHBBase_ctor` |
| **Review date** | `2026-07-29` (residual seal; prior accept 2026-07-23) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00508200_CVOGHBBase_ctor.md` |
| **System** | `heartbeat` / timed-actions |
| **Live tools** | Ghidra `force_decompile` + `read_memory` + `get_struct_layout` + `get_function_xrefs` (no `disassemble_bytes`) |
| **Verdict** | **accept** (layout + init sealed **High**) |

---

## 1. Purpose

Construct generic timed-action / heartbeat base (`sizeof(CVOGHBBase)==0x28`): install base vtbl `PTR_FUN_009cdab0` (`0x009cdab0`), zero common fields, set **`fDormant=1`** so TryFire stays **Inactive** until `CVOGHBBase_Start`, seed **`dwLastFireTickMs = g_dwClientTickMs`** (`0x00b041cc`). Subclasses replace vtbl and set period / type / owner after return.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00508200_CVOGHBBase_ctor.md` |
| Annotated | `docs/reconstruction/raw/aa_00508200_CVOGHBBase_ctor.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBBase_ctor.cpp` |
| Function record | `docs/reconstruction/functions/aa_00508200_CVOGHBBase_ctor.md` |
| Residual dual | `docs/reconstruction/reviews/a_00508200.md` |

---

## 3. Machine body (`read_memory` @ `0x00508200`, 48B)

```
00508200  8B C1              mov  eax, ecx                 ; this
00508202  33 C9              xor  ecx, ecx                 ; zero scratch
00508204  C7 00 B0 DA 9C 00  mov  dword [eax], 0x009cdab0  ; pVTable
0050820A  89 48 1C           mov  [eax+0x1C], ecx          ; nTypeTag = 0
0050820D  C6 40 21 01        mov  byte [eax+0x21], 1       ; fDormant = true
00508211  89 48 08           mov  [eax+0x08], ecx          ; nPeriodMs = 0
00508214  89 48 0C           mov  [eax+0x0C], ecx          ; nPeriodSentinel = 0
00508217  89 48 10           mov  [eax+0x10], ecx          ; nPeriodCounter = 0
0050821A  8B 15 CC 41 B0 00  mov  edx, [0x00B041CC]        ; g_dwClientTickMs
00508220  89 50 14           mov  [eax+0x14], edx          ; dwLastFireTickMs
00508223  88 48 20           mov  [eax+0x20], cl           ; cStopped = 0
00508226  89 48 18           mov  [eax+0x18], ecx          ; pOwnerObject = null
00508229  89 48 04           mov  [eax+0x04], ecx          ; nRefOrFlags = 0
0050822C  C3                 ret
```

Hex: `8bc133c9c700b0da9c0089481cc640210189480889480c8948108b15cc41b000895014884820894818894804c3`

| Claim | Evidence | Conf |
|---|---|---|
| `__thiscall`: **ECX = this**; void; bare `ret` | ECX→EAX; no stack args | **High** |
| Base vtbl **`0x009cdab0`** | imm32 store | **High** |
| **Dual period fields both zeroed** (+0x08 / +0x0C / +0x10) | three dwords | **High** |
| **lastFire = g_dwClientTickMs @ 0x00b041cc** | same global as StampLastFireTime | **High** |
| **fDormant=1 @ +0x21**, **cStopped=0 @ +0x20** | byte stores | **High** |
| **pOwner=0 @ +0x18**, **typeTag=0 @ +0x1C**, **ref=0 @ +0x04** | dword zeros | **High** |
| **Does not touch +0x22..+0x27** | no stores | **High** |
| Decompiler CF ≡ machine | store set identical | **High** |
| No callees | empty CALL set | **High** |

---

## 4. Sealed `CVOGHBBase` layout (`get_struct_layout` size **40**)

| Off | Size | Ghidra name | Sealed role | Ctor |
|----:|-----:|---|---|---|
| +0x00 | 4 | `pVTable` | base `PTR_FUN_009cdab0` | write |
| +0x04 | 4 | `nRefOrFlags` | ref/flags (zero) | write 0 |
| +0x08 | 4 | `nPeriodMs` | **real pulse period ms** (TryFire gate / GetRemaining) | write 0 |
| +0x0C | 4 | `nPeriodSentinel` | SetPeriodAndCounter / Reschedule (−1000 combat-pool) | write 0 |
| +0x10 | 4 | `nPeriodCounter` | multi-period residual | write 0 |
| +0x14 | 4 | `dwLastFireTickMs` | last fire / stamp | **g_dwClientTickMs** |
| +0x18 | 4 | `pOwnerObject` | AttachOwnerObject | write 0 |
| +0x1C | 4 | `nUnusedOrFlags` | **type tag** (see B / residual) | write 0 |
| +0x20 | 1 | `cStopped` | TryFire → Remove | write 0 |
| +0x21 | 1 | `fDormant` | Start clears; TryFire Inactive while true | write **1** |
| +0x22 | 1 | `cPad22` | pad | **uninit by ctor** |
| +0x23 | 1 | `cPad23` | pad | **uninit by ctor** |
| +0x24 | 1..4 | debounce / subclass | Regen zeros 3B; OKToCastAgain stores skill* | **uninit by ctor** |
| +0x25..+0x27 | | | subclass | **uninit by ctor** |

Plate synonym `g_ActionSchedulerTickMs` ≡ **`g_dwClientTickMs`** at `0x00b041cc` (machine).

---

## 5. Base vtbl slots (`read_memory` @ `0x009cdab0`)

| Slot | +off | Target | Role (family) |
|-----:|-----:|---|---|
| 0 | +0x00 | `0x00508630` | scalar deleting dtor (unlink owner if list) |
| 1 | +0x04 | `0x00508270` | **`CVOGHBBase_StampLastFireTime`** — default **OnStart** (`Start` calls vtbl+4) |
| 2 | +0x08 | `0x005082c0` | `CVOGHBBase_TryFire` |
| 3 | +0x0C | `0x00508350` | `CVOGHBBase_RescheduleAfterFire` (base OnHeartBeat surface) |
| 4 | +0x10 | `0x005081e0` | side helper (owner combat-pool counters) |
| 5 | +0x14 | `0x005081f0` | empty `ret` |
| 6 | +0x18 | `0x005083f0` | stop / clear-owner path |

---

## 6. Control flow: clean ≡ raw ≡ machine

| Stage | Match |
|---|---|
| Vtbl install | **Yes** |
| Dual period zeros + counter | **Yes** |
| Dormant true / stopped false | **Yes** |
| lastFire = client tick | **Yes** |
| owner / type / ref zero | **Yes** |
| No invented clamps or callees | **Yes** |

---

## 7. Gaps / open (after residual)

1. Product enum names for **type tags** at +0x1C (values 1/4/8 sealed by sibling ctors; full enum incomplete).
2. Semantic of **`nRefOrFlags` (+0x04)** beyond “zeroed here”.
3. Whether allocators always zero **+0x22..+0x27** before ctor (ctor itself does not).

**Verdict:** **accept** (residual layout sealed)
