# Review A (reconstruction fidelity): `aa_004068f0` LogicUiEventQueue_InsertOne_GrowPath

| Field | Value |
|---|---|
| **Stable ID** | `aa_004068f0` |
| **VA** | `0x004068f0`–`0x00406964` |
| **Canonical name** | `LogicUiEventQueue_InsertOne_GrowPath` |
| **Ghidra name** | `FUN_004068f0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W22-I) |
| **Counterpart** | `reviews/B_aa_004068f0_LogicUiEventQueue_InsertOne_GrowPath.md` |
| **System** | client-logic-ui / event queue |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete`; caller `Client_SendLogicUiPacket` |
| **Verdict** | **accept** |

---

## 1. Purpose

Index-preserving **grow-insert one** path for the Logic-UI event queue (element size **0x138**):

1. If begin non-null and size ≠ 0: `index = (insertAt − begin) / 0x138`.
2. Else: `index = 0`.
3. `FUN_004076a0(this, insertAt, 1, payload)` — insert/grow.
4. `*outSlot = begin' + index * 0x138` (rebased after possible realloc).

Sole caller: capacity-miss branch of `Client_SendLogicUiPacket`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004068f0_FUN_004068f0.md` (+ 2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_004068f0_FUN_004068f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/LogicUiEventQueue_InsertOne_GrowPath.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004068f0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004068f0_FUN_004068f0.md` |
| Insert-N callee | `FUN_004076a0` `0x004076a0` (local 0x138 construct buffer) |
| Twin pattern | `CombatFloaterQueue_InsertOne_GrowPath` `0x00402e20` (stride 0x38) |
| Live | decompile ≡ raw; `read_memory` 116 B body; `C2 0C 00` |

---

## 3. Signature (sealed)

```c
// stack formals ×3; ECX = queue*; return void; RET 0xC
void LogicUiEventQueue_InsertOne_GrowPath(void* q, void** out, void* at, uint32_t value);
```

| Formal | Source | Conf |
|---|---|---|
| queue | ECX → EDI; fields +4/+8/+0xC | **High** |
| out | Stack[0x4] | **High** |
| at | Stack[0x8] → EBX | **High** |
| value | Stack[0xC] | **High** |
| cleanup | `RET 0xC` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
begin = *(q+4)
if begin && (end-begin)/0x138 != 0:
  index = (at - begin) / 0x138
else:
  index = 0
InsertN(at, 1, value)          // FUN_004076a0
*out = *(q+4) + index * 0x138
```

| Stage | Match | Conf |
|---|---|---|
| Empty / zero-size → index 0 | **Yes** | **High** |
| Non-empty → index from at | **Yes** | **High** |
| count literal 1 | **Yes** | **High** |
| Rebase after insert | **Yes** | **High** |
| Stride 0x138 magic + lea×0x138 | **Yes** | **High** |
| Sole caller SendLogicUiPacket | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Hex body (116 B):
```
538b5c240c56578bf98b770485f6741e8b4f082bceb8d3200dd2f7e903d1c1fa088bc2c1e81f03c289442414750433f6eb178bcb2bceb8d3200dd2f7e903d1c1fa088bf2c1ee1f03f28b4c2418516a01538bcfe8580d00008b47048d14b603d203d203d22bd65f8d0cd08b44240c5e89085bc20c00
```

Callee: `FUN_004076a0` @ `0x004076a0`.

---

## 6. Gaps

- Product English for the owning queue type (session field vs standalone).
- Full 0x138 event record layout (not this unit — callee/consumer).
- Runtime / bit-exact.

**Residual gaps are non-blocking for CF/ABI.** Verdict **accept**.
