# Review A (reconstruction fidelity): `aa_00508280` CVOGHBBase_GetRemainingSeconds

| Field | Value |
|---|---|
| **Stable ID** | `aa_00508280` |
| **VA** | `0x00508280` |
| **Canonical name** | `CVOGHBBase_GetRemainingSeconds` |
| **Review date** | `2026-07-29` (residual seal; prior accept-with-gaps 2026-07-23) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00508280_CVOGHBBase_GetRemainingSeconds.md` |
| **System** | `heartbeat` / timed-actions |
| **Live tools** | Ghidra `decompile_function` + `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **accept** (sealed High for body + field binds + constants) |

---

## 1. Purpose

UI helper: remaining time until next HB fire as **float seconds**.  
Formula (integer ms, then × 0.001):

```
base = max(0, dwLastFireTickMs - g_dwClientTickMs + nPeriodMs)   // nPeriodMs @ +0x08
remMs = (nPeriodCounter - 1) * nPeriodMs + base                  // counter @ +0x10
return signed_int_to_float(remMs) * g_flMsToSeconds_Inferred     // 0.001f @ 0x00a0f72c
```

Used for **"Remaining"** tooltips / CD overlays / readiness gates — **not** list schedule authority (`TryFire` / `RescheduleAfterFire` own that).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00508280_CVOGHBBase_GetRemainingSeconds.md` |
| Annotated | `docs/reconstruction/raw/aa_00508280_CVOGHBBase_GetRemainingSeconds.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBBase_GetRemainingSeconds.cpp` |
| Function record | `docs/reconstruction/functions/aa_00508280_CVOGHBBase_GetRemainingSeconds.md` |

---

## 3. Seal: body bytes (High)

`read_memory` @ `0x00508280` (body `00508280`–`005082b5`, 54 bytes; CC pad after):

```
00508280  51                 push ecx
00508281  8B 41 14           mov  eax, [ecx+0x14]          ; dwLastFireTickMs
00508284  2B 05 CC41B000     sub  eax, [0x00b041cc]        ; g_dwClientTickMs
0050828A  8B 51 08           mov  edx, [ecx+0x08]          ; nPeriodMs (REAL period)
0050828D  03 C2              add  eax, edx
0050828F  79 02              jns  short +2
00508291  33 C0              xor  eax, eax                 ; clamp base ≥ 0
00508293  8B 49 10           mov  ecx, [ecx+0x10]          ; nPeriodCounter
00508296  83 E9 01           sub  ecx, 1
00508299  0F AF CA           imul ecx, edx                 ; (counter-1)*period
0050829C  03 C8              add  ecx, eax
0050829E  85 C9              test ecx, ecx
005082A0  89 0C 24           mov  [esp], ecx
005082A3  DB 04 24           fild dword ptr [esp]
005082A6  7D 06              jge  short +6
005082A8  D8 05 DCA5AA00     fadd dword ptr [0x00aaa5dc]   ; 2^32 bias if remMs < 0
005082AE  D8 0D 2CF7A000     fmul dword ptr [0x00a0f72c]   ; g_flMsToSeconds = 0.001f
005082B4  59                 pop  ecx
005082B5  C3                 ret
```

Hex: `51 8b 41 14 2b 05 cc 41 b0 00 8b 51 08 03 c2 79 02 33 c0 8b 49 10 83 e9 01 0f af ca 03 c8 85 c9 89 0c 24 db 04 24 7d 06 d8 05 dc a5 aa 00 d8 0d 2c f7 a0 00 59 c3`

| Claim | Evidence | Conf |
|---|---|---|
| Body size **54 bytes**; ends `pop ecx; ret` | `read_memory` + function range `00508280–005082b5` | **High** |
| `__fastcall` / `__thiscall`: **ECX = this**; **no stack args**; **float in ST0** | ECX loads; bare `ret` (not `ret n`) | **High** |
| **`this+0x14` = dwLastFireTickMs** | `8B 41 14` | **High** |
| **`this+0x08` = nPeriodMs** (real pulse period) | `8B 51 08` + imul uses same EDX | **High** |
| **Does not read `this+0x0C`** (nPeriodSentinel) | no `+0x0C` load | **High** |
| **`this+0x10` = nPeriodCounter** | `8B 49 10` | **High** |
| Base term clamp ≥ 0 before multi-period | `jns` / `xor eax,eax` | **High** |
| Multi-period: `(counter-1)*period + base` | `sub 1; imul; add` | **High** |
| Signed-neg rem → +`2^32` then float | `fild` + conditional `fadd [0x00aaa5dc]` | **High** |
| Scale `× 0.001f` | `fmul [0x00a0f72c]` | **High** |
| **No callees** | empty callee set; no CALL | **High** |
| Decompiler CF ≡ machine | clamp + multi + bias + scale | **High** |

### Constants sealed (`read_memory`)

| VA | Bytes LE | Value | Role |
|---|---|---|---|
| `0x00b041cc` | (named) | `g_dwClientTickMs` | client tick ms |
| `0x00aaa5dc` | `00 00 80 4f` | **4294967296.0f** (`2^32`) | signed-neg int→float bias |
| `0x00a0f72c` | `6f 12 83 3a` | **0.001f** (`0x3a83126f`) | `g_flMsToSeconds_Inferred` |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Formula + field offsets as above | **High** | Body sealed |
| Period bind is **+0x08**, not +0x0C | **High** | Prior gap closed by machine |
| UI / tooltip consumer (not TryFire schedule) | **High** | `FUN_00578550` “Remaining”; no list Tick path |
| Sibling TryFire also gates on **+0x08** | **High** | TryFire body `8B 4E 08` / cmp `-1000` (sibling own) |
| SetPeriodAndCounter writes **+0x0C** only | **High** | sibling sealed; dual-field model |
| Combat-pool UI when period=-1000 unused path | **Probable** | tooltip skips if **counter**==-1000 (`FUN_00578550`); period==-1000 not special-cased here |
| Field name `nPeriodMs` for +0x08 | **High** | Ghidra type + family plates |

---

## 5. Control flow: clean ≡ raw ≡ machine

| Stage | Match |
|---|---|
| base = lastFire − tick + period | **Yes** |
| clamp base ≥ 0 | **Yes** |
| rem = (counter−1)×period + base | **Yes** |
| signed-neg fild bias | **Yes** |
| × 0.001f return | **Yes** |
| No invented UI side effects | **Yes** |
| No stack cleanup beyond push/pop scratch | **Yes** |

---

## 6. Call / xref inventory (this unit)

### Code CALL → `0x00508280` (15 xrefs)

| Site | Owner (Ghidra) | Notes |
|---|---|---|
| `0x0057857f` | `FUN_00578550` | “Remaining” tooltip sprintf path |
| `0x00578751` | (same region / sibling path) | unconditional CALL |
| `0x005b28a9` | `FUN_005b2830` | — |
| `0x0061820a` | `FUN_00618180` | — |
| `0x00618c3e` | `FUN_00618bf0` | — |
| `0x00625b4d` | `FUN_00625b00` | readiness: rem vs skill window |
| `0x006266a7` | — | unconditional CALL |
| `0x0083ba4e` | `FUN_0083b920` | — |
| `0x0088bfaf`, `0x0088c130`, `0x0088c2ce` | — | three sites |
| `0x00956c89`, `0x00956cd3`, `0x00956e14`, `0x00956e4d` | `FUN_00955eb0` / `Client_DebugDumpEntityCombatStats` | debug combat dump ×4 |

`get_function_callers` named: `FUN_00578550`, `FUN_005b2830`, `FUN_00618180`, `FUN_00618bf0`, `FUN_00625b00`, `FUN_0083b920`, `FUN_00955eb0` (7 owners; extra xrefs share owners or lack named containing functions).

**No DATA/vtable xrefs observed** for this address (direct CALL helper, not virtual slot).

---

## 7. Gaps / open

1. Full semantic names for all non-debug callers (`FUN_005b2830`, `FUN_00618180`, `FUN_00618bf0`, `FUN_0083b920`, orphan CALL sites).
2. Live UI: tooltip string vs field values (runtime deferred).
3. Edge case: `nPeriodCounter == 0` → `(−1)×period` can push rem negative → 2^32 bias → huge display if ever reached.
4. Bit-for-bit / differential: **deferred**.

**Verdict:** **accept** (sealed High for body, offsets, constants; caller naming open)
