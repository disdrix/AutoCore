# Review A (reconstruction fidelity): `aa_00530670` CVOGCharacter_TryClearMissionCounterIfPositive

| Field | Value |
|---|---|
| **Stable ID** | `aa_00530670` |
| **VA** | `0x00530670`–`0x00530708` exclusive (**152 B** / `0x98`) |
| **Canonical name** | `CVOGCharacter_TryClearMissionCounterIfPositive` |
| **Ghidra name** | `FUN_00530670` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W31-S) |
| **Counterpart** | `reviews/B_aa_00530670_CVOGCharacter_TryClearMissionCounterIfPositive.md` |
| **System** | missions-progression |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + callers/callees/xrefs + `analyze_function_complete`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

On character Val12 counter map (`char+0x584`):

1. Find `key` via `FUN_00418b80`.
2. If miss (`node == head@+0x588`) **or** `*(node+0x14) <= 0` → return **0**.
3. Re-find; if hit: set `node+0x10 = 0` (Get-field); defensive `if +0x14 < 0` copy into `+0x10`; `char+0x634 |= 0x40`.
4. `CVOGCharacter_SetMissionCounter(key, 0)` (zeros `+0x14`).
5. `char+0x634 |= 0x40` again; return **1**.

Sole caller packet path `FUN_00809dd0`: success flag → clear key; else `"FAILED: Server reports failure."`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W31-S append) | `docs/reconstruction/raw/aa_00530670_FUN_00530670.md` |
| Annotated | `docs/reconstruction/raw/aa_00530670_FUN_00530670.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGCharacter_TryClearMissionCounterIfPositive.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00530670.cpp` |
| Function records | `functions/aa_00530670_FUN_00530670.md`, `functions/aa_00530670_CVOGCharacter_TryClearMissionCounterIfPositive.md` |
| Nested | `CVOGCharacter_SetMissionCounter` W30-I; find `00418b80` |
| Live | decompile ≡ raw; body hex; dual `C2 04 00`; `LEA EDI,[ESI+0x584]` map this |

---

## 3. Signature (sealed)

```c
// __thiscall; ECX=Character*; stack (key); bool AL; ret 4
bool __thiscall CVOGCharacter_TryClearMissionCounterIfPositive(void *character, uint32_t key);
```

| Formal | Source | Conf |
|---|---|---|
| character | ECX (`8B F1`) | **High** |
| key | stack; epilogue `C2 04 00` | **High** |
| return | AL `B0 01` / `32 C0` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ live)

```
find(map=char+0x584, &node, &key)
if node==head OR node+0x14<=0: return 0
re-find
if node!=head:
  node+0x10 = 0
  if node+0x14 < 0: node+0x10 = node+0x14
  char+0x634 |= 0x40
SetMissionCounter(key, 0)
char+0x634 |= 0x40
return 1
```

| Stage | Match | Conf |
|---|---|---|
| Map @ +0x584 / head +0x588 | **Yes** (machine LEA/compare) | **High** |
| Positive gate on +0x14 | **Yes** (`TEST`/`JLE`) | **High** |
| Clear +0x10 then Set 0 | **Yes** | **High** |
| Dirty 0x40 | **Yes** (`OR [ESI+0x634], 0x40`) | **High** |
| ret 4 / bool | **Yes** | **High** |

---

## 5. Call graph

| Role | Address / name |
|---|---|
| Caller (1) | `FUN_00809dd0` @ `00809e0a` ← `Client_PacketDispatch` |
| Callee | `FUN_00418b80` ×2 |
| Callee | `FUN_005305b0` SetMissionCounter |

---

## 6. Gaps

- Product English for key domain / counter type.
- Dirty bit `0x40` consumer map (vs `0x10` mission objective dirty).
- Negative `+0x14` branch after positive outer gate (defensive only).
- Runtime / bit-exact open.

---

## 7. Verdict

CF, ABI, map offsets, dual-field clear, dirty bit, and sole caller sealed → **accept-with-gaps**.
