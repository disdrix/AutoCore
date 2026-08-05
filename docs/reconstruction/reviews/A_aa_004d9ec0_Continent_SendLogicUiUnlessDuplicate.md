# Review A (reconstruction fidelity): `aa_004d9ec0` Continent_SendLogicUiUnlessDuplicate

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d9ec0` |
| **VA** | `0x004d9ec0` |
| **Canonical name** | `Continent_SendLogicUiUnlessDuplicate` (role-sealed; product English open) |
| **Ghidra name** | `FUN_004d9ec0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004d9ec0_Continent_SendLogicUiUnlessDuplicate.md` |
| **System** | `missions-progression` (+ LogicUI) |
| **Parent chain** | Nested from GiveMission → `CVOGReaction_UnlockContinentObject` @ `0x00531d37` (also Relock) |
| **Dual status** | **Present** (first full A+B dual) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Thin **LogicUI send gate** on continent object:

1. `this` (ECX) = continent / client-world host.
2. Stack0 = packet/context object (`param_2`).
3. Stack1 = enable-dedupe flag (`param_3`).
4. If flag ≠ 0: scan array `[this+0xe8bc, this+0xe8c0)` with **stride `0x138`**; if any element has `*(elem+0x1c) == *(param_2+0x1c)`, **return without send**.
5. Else: `Client_SendLogicUiPacket(param_2)` with `this` adjusted (`ADD ECX, 0xe8b8` at call — LogicUI queue base).

Used after unlock/relock continent work so UI refresh is not double-posted for the same logical id.

**ABI (asm-sealed):**

```c
void __thiscall Continent_SendLogicUiUnlessDuplicate(
    Continent* this, void* logicUiMsg, char checkDuplicates);
/* ret 8 */
```

| Evidence | Detail |
|---|---|
| Entry | `CMP byte [ESP+8],0` (flag); `MOV EDI,[ESP+0xC]` after pushes → original stack0 |
| Dedupe range | loads `+0xe8bc` / `+0xe8c0`; step `ADD EAX,0x138` |
| Match field | `CMP [EDI+0x1c],[EAX+0x1c]` |
| Send | `ADD ECX,0xe8b8`; `CALL Client_SendLogicUiPacket` |
| Epilogue | **`RET 8`** (`C2 08 00`) |

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004d9ec0_FUN_004d9ec0.md` |
| Annotated | `docs/reconstruction/raw/aa_004d9ec0_FUN_004d9ec0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004d9ec0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004d9ec0_FUN_004d9ec0.md` |
| Live decompile | ≡ raw |
| Live bytes | `read_memory` 80 B — full body |
| Callers | UnlockContinentObject, RelockContinentObject |
| Unlock site | `PUSH 1` then CALL — **dedupe enabled** on unlock path |

**Not performed:** full LogicUI packet layout dual, Launcher.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Signature thiscall + 2 stack args + RET 8 | **High** | bytes |
| Dedupe only when flag ≠ 0 | **High** | early skip scan |
| Stride `0x138` | **High** | imm `0x138` |
| Compare key at `+0x1c` | **High** | both sides |
| Send via `Client_SendLogicUiPacket` | **High** | named callee |
| Queue base `this+0xe8b8` at call | **High** | `ADD ECX,0xe8b8` |
| Product English for list | **Open** | |

---

## 4. Gaps

1. What `+0x1c` product field is (quest id vs UI type vs object id).
2. Full element layout of `0x138` records.
3. Relock path flag polarity vs unlock (unlock sealed as push 1).

**Verdict:** Compact gate High. **accept-with-gaps.**
