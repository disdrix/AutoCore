# Dual A/B report — W22-I OWN `aa_004068f0` + `aa_005da0a0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W22-I  
**Scope:** VAs `0x004068f0`, `0x005da0a0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004068f0` LogicUiEventQueue_InsertOne_GrowPath | **accept** — index-save grow-insert CF + ABI + stride 0x138 sealed |
| `aa_005da0a0` Drive_CollisionListener_Contact | **accept-with-gaps** — contact CF/ABI/string/constants sealed; type English residual |

---

## VA `0x004068f0` — sealed facts

1. **Body:** `0x004068f0`–`0x00406964` (116 B; `RET 0xC`).
2. **ABI:** **ECX**=queue*; stack `out**`, `insertAt`, `payload`; void return.
3. **Semantics:** Save index → insert **one** 0x138-byte element via `FUN_004076a0` → write rebased slot to `*out`.
4. **Stride:** `0x138` (magic `0xD20D20D3` div; lea×0x138).
5. **Caller (1):** `Client_SendLogicUiPacket` @ site `0x00405a70` (capacity overflow path).
6. **Name:** `LogicUiEventQueue_InsertOne_GrowPath` (Ghidra `FUN_004068f0`).
7. **Twin pattern:** `CombatFloaterQueue_InsertOne_GrowPath` (`0x00402e20`, stride 0x38).
8. **Decompile ≡ bytes** for CF.

### Gaps

- Product English for owning queue type.  
- Full 0x138 event record layout (callee/consumer residual).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004068f0_LogicUiEventQueue_InsertOne_GrowPath.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004068f0_LogicUiEventQueue_InsertOne_GrowPath.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004068f0_FUN_004068f0.md` |
| Annotated | `docs/reconstruction/raw/aa_004068f0_FUN_004068f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/LogicUiEventQueue_InsertOne_GrowPath.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004068f0.cpp` |
| Function | `docs/reconstruction/functions/aa_004068f0_FUN_004068f0.md` |
| Function named | `docs/reconstruction/functions/aa_004068f0_LogicUiEventQueue_InsertOne_GrowPath.md` |
| Scratch | `docs/reconstruction/tmp/a_004068f0.md` |

---

## VA `0x005da0a0` — sealed facts

1. **Body:** `0x005da0a0`–`0x005dab25` (2693 B; leaf worker; `RET 0x10`).
2. **ABI:** **ECX**=`CollisionListener* this` (rate @ `+0x10`); stack `ctx`, `float* impact`, `bodyA*`, `bodyB*`; **AL** result.
3. **String:** `"CollisionListener::contact"` via profiler enter.
4. **Caller (1):** `FUN_005dab30` — `if AL==0: event+0x20=1`.
5. **CF stages:** host walk → type==1 GO resolve → material-1 debounce (500 ms) → type 0xe hooks → rate 0.5 s → `FUN_005d9ea0`×2 → energy → damage → type 0x12 gates → FX → UI opcode **0x29** if `|impact|>1` → bidirectional `FUN_005d9290`.
6. **Constants:** 1.0f, 0.5f, 3.6f, ~2.5e-7f, 350.0f, 500 ms (all `read_memory`).
7. **Name:** `Drive_CollisionListener_Contact` (Ghidra `FUN_005da0a0`).
8. **Sibling:** `Drive_CollisionListener_DoVehicleCollision` @ `0x005d9290`.
9. **Decompile ≡ bytes** for CF; this residual filled from prologue + rate use.

### Gaps

- Product English for clonebase types 0xe / 0x12 / 3.  
- Full contact-event struct beyond caller offsets.  
- Nested callee depth (`005d9ea0`, `005d9af0`, `005dab60`).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005da0a0_Drive_CollisionListener_Contact.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005da0a0_Drive_CollisionListener_Contact.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005da0a0_FUN_005da0a0.md` |
| Annotated | `docs/reconstruction/raw/aa_005da0a0_FUN_005da0a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Drive_CollisionListener_Contact.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005da0a0.cpp` |
| Function | `docs/reconstruction/functions/aa_005da0a0_FUN_005da0a0.md` |
| Function named | `docs/reconstruction/functions/aa_005da0a0_Drive_CollisionListener_Contact.md` |
| Scratch | `docs/reconstruction/tmp/a_005da0a0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004068f0` | Logic-UI queue grow path only — preserve 0x138 stride and index-rebase after realloc; fast path remains `FUN_00409cc0` when capacity remains. |
| `005da0a0` | Client collision contact hub — energy formula + UI 0x29 + type gates + debounce required for vehicle collision parity; AL=0 disables event. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers).  
- Dual A (fidelity) + B (adversarial) both filed per VA.
