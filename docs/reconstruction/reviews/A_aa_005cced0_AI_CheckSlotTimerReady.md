# Review A (reconstruction fidelity): `aa_005cced0` AI_CheckSlotTimerReady

| Field | Value |
|---|---|
| **Stable ID** | `aa_005cced0` |
| **VA** | `0x005cced0` |
| **Canonical name** | `AI_CheckSlotTimerReady` |
| **Prior names** | `aa_005cced0`, decomp 3-arg thiscall |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (fidelity / clean ≡ raw / dual residual) |
| **Counterpart** | `reviews/B_aa_005cced0_AI_CheckSlotTimerReady.md` |
| **System** | `npc-ai` / HBAI slot cooldown gate |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Tiny **__thiscall** gate on an HBAI object: for slot index `i`, if elapsed client ms since last stamp exceeds the per-slot period, set the slot ready flag byte to `1` and return AL=`1`; else return AL=`0` (do not clear the flag).

Does **not** restamp last-fire or reseed period (those live in reschedule/fire paths).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005cced0_AI_CheckSlotTimerReady.md` |
| Annotated | `docs/reconstruction/raw/aa_005cced0_AI_CheckSlotTimerReady.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AI_CheckSlotTimerReady.cpp` |
| Function record | `docs/reconstruction/functions/aa_005cced0_AI_CheckSlotTimerReady.md` |
| Live decompile | Ghidra `decompile_function` `0x005cced0` (2026-07-29) |
| Live memory | Ghidra `read_memory` body `0x005cced0` length 48 (2026-07-29) |
| Global | `g_dwClientTickMs` @ `0x00b041cc` (`audit_global`) |
| Callers / xrefs | `get_function_callers` / `get_function_xrefs` — **6** call sites / **4** functions |
| Caller body reads | `read_memory` around all 6 xrefs for push/ECX/TEST AL |

---

## 3. Control flow (authoritative body)

```
AI_CheckSlotTimerReady(this /*ECX*/, nSlotIndex /*stack*/):
  elapsed = g_dwClientTickMs - *(int*)(this + nSlotIndex*0xC + 0x70)
  period  = *(uint*)(this + nSlotIndex*0xC + 0x74)
  if period < elapsed:                    // equiv: elapsed > period
    *(uint8_t*)(this + nSlotIndex*0xC + 0x78) = 1
    return 1                              // AL=1; callers TEST AL
  return 0                                // AL=0
```

### 3.1 Body bytes (live `read_memory`, through both epilogues)

```text
8b 44 24 04          ; mov eax, [esp+4]          nSlotIndex
56                   ; push esi
8b 35 cc 41 b0 00    ; mov esi, [g_dwClientTickMs]
8d 14 40             ; lea edx, [eax+eax*2]      index*3
2b 74 91 70          ; sub esi, [ecx+edx*4+0x70] elapsed = tick - last
8d 14 91             ; lea edx, [ecx+edx*4]      base = this+index*0xC
3b 72 74             ; cmp esi, [edx+0x74]       cmp elapsed, period
5e                   ; pop esi
76 0d                ; jbe not_ready             ready iff elapsed > period
8d 44 40 1e          ; lea eax, [eax+eax*2+0x1e] index*3+0x1e
c6 04 81 01          ; mov byte [ecx+eax*4], 1   this+index*0xC+0x78 = 1
b0 01                ; mov al, 1
c2 04 00             ; ret 4
32 c0                ; xor al, al
c2 04 00             ; ret 4
```

Body range Ghidra: `005cced0`–`005ccefc`. Next function starts after `cc` pad.

### 3.2 Calling convention (sealed)

| Claim | Evidence | Conf |
|---|---|---|
| **`__thiscall`**, ECX = object | All 6 sites `MOV ECX, ESI` (or equiv) before CALL | **High** |
| **One** stack dword (`nSlotIndex`) | Body `RET 4` (`c2 04 00`) both exits; sites single `PUSH` | **High** |
| Second decomp formal `nSlotIndex` / third arg | **Artifact** — no second stack load; not in signature | **High** (withdrawn) |
| Return consumed as **bool in AL** | All sites `TEST AL,AL` / `JZ`/`JE`/`MOV [stack],AL` | **High** |
| Upper EAX bits on success | `LEA EAX,…` then `MOV AL,1` leaves high bytes of `index*3+0x1e` | **High** (unused by callers) |
| Upper EAX bits on fail | `XOR AL,AL` after index still in EAX → `index & ~0xFF` | **High** (unused) |

Corrected signature:

```c
uint8_t /*bool AL*/ __thiscall AI_CheckSlotTimerReady(void *this, uint nSlotIndex);
// RET 4
```

---

## 4. Slot table layout (body-backed)

Per-slot stride **`0x0C`** starting at **`this+0x70`**:

| Slot-relative | Object offset | Type | Role | Conf |
|---|---|---|---|---|
| `+0x00` | `this + i*0xC + 0x70` | `int`/`uint` dword | Last stamp (ms); subtracted from `g_dwClientTickMs` | **High** |
| `+0x04` | `this + i*0xC + 0x74` | `uint` | Period threshold (ms); RHS of ready compare | **High** |
| `+0x08` | `this + i*0xC + 0x78` | `uint8_t` | Ready flag; **set to 1 only** when ready | **High** |

Ready write identity:

- Decomp: `*(this + (i*3 + 0x1e)*4) = 1`
- Algebra: `(i*3 + 0x1e)*4 = i*0xC + 0x78` → same slot record `+0x08`

Compare polarity (sealed):

- Ready when **`period < (tick − last)`** ≡ **`elapsed > period`**
- Equal elapsed/period → **not ready** (`JBE`)

Global:

| Symbol | VA | Role | Conf |
|---|---|---|---|
| `g_dwClientTickMs` | `0x00b041cc` | Client ms tick (HB list / stamp family) | **High** name+use |

---

## 5. Callers (xrefs sealed)

| Site | Function | Stack arg (slot) | ECX | AL use |
|---|---|---|---|---|
| `0x005d079d` | `CVOGHBAICreatureBase_OnHeartBeat` | `PUSH EDI` (runtime) | ESI | `TEST AL` skip combat fire path |
| `0x005d7845` | `CVOGHBAIDriver_DoLogic` | **`PUSH 0`** | ESI | `TEST AL` |
| `0x005d7ac1` | `CVOGHBAIDriver_DoLogic` | **`PUSH 0`** | ESI | `TEST AL` |
| `0x005d13ee` | `NPC_TryCastSkillFromSet` | **`PUSH 2`** | ESI | store AL → skill gate byte |
| `0x005d7ffe` | `FUN_005d7f70` | `PUSH EBX` | ESI | `TEST AL` |
| `0x005d8264` | `FUN_005d7f70` | `PUSH EBX` | ESI | `TEST AL` |

Observed fixed indices: **0** (driver pulses), **2** (skill-set cast path). Heartbeat / `FUN_005d7f70` pass a register (EDI/EBX) — value domain not sealed in this unit.

Callees: **none** (leaf).

---

## 6. Clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Load index from `[esp+4]` | **Yes** |
| `g_dwClientTickMs` @ `0x00b041cc` | **Yes** |
| Stride `0xC` / bases `+0x70/+0x74` | **Yes** |
| Ready iff `period < elapsed` | **Yes** |
| Flag write `+0x78` / decomp `(i*3+0x1e)*4` | **Yes** |
| AL 1 / 0 + `RET 4` | **Yes** |
| No invented clamps / restamp | **Yes** |

Prior scaffold issues corrected this pass:

- System tag **inventory-transfer** → **npc-ai / HBAI**
- Fake second stack formal removed
- Ready flag algebra tied to same 0xC slot record

---

## 7. Gaps (owned residual)

1. Product type name of `this` (which HBAI subclass owns `+0x70` timer bank) — used as HBAI object from multiple AI owners.
2. Semantic names of slots beyond observed constants **0** / **2** (weapon vs skill vs other).
3. Who **writes** `+0x70` last stamp and `+0x74` period (reschedule / fire) — not this function.
4. Whether ready flag at `+0x78` is ever cleared here (no) or only elsewhere.
5. Heartbeat `EDI` / `FUN_005d7f70` `EBX` concrete values need those owners’ duals.

**Verdict:** CF, signature (`thiscall` + 1 stack arg), compare polarity, and slot layout **sealed High**. Semantic slot taxonomy and stamp writers remain open. **accept-with-gaps.**
