# Review A (reconstruction fidelity): `aa_004d08c0` Mission_FillRolledRewardSlots

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d08c0` |
| **VA** | `0x004d08c0` |
| **Canonical name** | `FUN_004d08c0` (proposed: `Mission_FillRolledRewardSlots`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004d08c0_Mission_FillRolledRewardSlots.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** (decompiler arity vs call-site 3-arg; body primarily uses def) |

---

## 1. Purpose

**Non-type-0** mission reward fill: gated on objective/reward def fields, then loops **4 slots**:

1. Null / field gates on def (`+0xb0`, `+0xc0`, `+0xac` patterns).
2. `FUN_0052dac0(*def, 1)` → writable COID pair buffer.
3. For i in 0..3: resolve via `FUN_004cf120(slotKey, slotVal)`; on hit set flag `obj+0x17c |= 4`, copy COID from resolved `+0x160/+0x164` into buffer, `FUN_0052b350` finalize; optional `FUN_00513de0(1)` when flag short nonzero and slot sentinel -1.

CompleteObjective: type short `obj+0xf8 != 0` → roll RNG short → `FUN_004d08c0(obj, character, roll)`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean / fn | scaffold `aa_004d08c0_*` |
| Live decompile | `batch_decompile` / `analyze_function_complete` |
| Call site | `0x005342bd` (3× PUSH before CALL) |
| Parent residual | `reviews/a_00533f90.md` mild arity open |

---

## 3. Body CF (decompile ≡ raw)

```
if def == null: return
if not (def+0xb0 != -1 || complex (+0xc0 / +0xac) gate): return
buf = FUN_0052dac0(*def, 1)
for slot in 0..3:
  key = def+0xb0 region; val = def+0xc0 region  // parallel arrays
  resolved = FUN_004cf120(key, val)
  if resolved:
    maybe FUN_00513de0(1)
    resolved.flags(+0x17c) |= 4
    *buf++ = resolved COID lo/hi (+0x160/+0x164)
    FUN_0052b350(resolved)
```

---

## 4. Arity (listing seals — closes parent mild open)

```text
004d08c0  SUB ESP,8 / PUSH ESI
004d08c4  MOV ESI, [ESP+0x10]     ; stack arg0 = def*
004d08c8  MOV [ESP+8], ECX        ; preserve inbound ECX (may be live this from some sites)
004d0908  MOV ECX, [ESP+0x14]     ; stack arg1 used as ECX for staging callees
...
004d099b  RET 0xC                 ; **3 stack formals**
```

| Source | Arity |
|---|---|
| Ghidra decompile | **1** (under-count — **falsified**) |
| CompleteObjective decompile | **3** (`obj, character, roll`) |
| Call site asm | `PUSH roll; PUSH char; PUSH def` |
| Listing | **RET 0xC** + reads `[ESP+…]` formals |

```c
void __stdcall Mission_FillRolledRewardSlots(
    void* pObjectiveDef,   // arg0 — primary body this-data
    void* pCharacter,      // arg1 — loaded to ECX for FUN_0052dac0 / slot helpers
    uint32_t rollOrSeed);  // arg2 — CompleteObjective RNG short/value
// RET 0xC
```

arg2 consumption in body is still **lighter** than arg0/arg1 (no direct use in every block); keep formal for ABI.

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| 4-slot loop + COID copy | **High** | |
| Gate fields on def | **High** CF | English open |
| Pair with type-0 wrapper | **High** | caller branch |
| **RET 0xC / 3 stack args** | **High** | listing 2026-07-29 |
| Decompiler 1-arg prototype | **Falsified** | do not port |
| Callee resolve/finalize names | **Open** | |

---

## 6. Surviving contract

```
FillRolledRewards(def, character?, roll?):
  if def has reward slots configured:
    buf = ensure staging(*def)
    for 4 slots:
      resolve → stamp flag 4 → write COID pair → finalize
// Called only when objective type short +0xf8 != 0 on local final path.
// Prefer preserving 3-arg call shape from CompleteObjective.
```
