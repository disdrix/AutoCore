# Review A (reconstruction fidelity): `aa_008c2f50` Client_TryInventoryAutoMergePartialStacks_Notify

| Field | Value |
|---|---|
| **Stable ID** | `aa_008c2f50` |
| **VA** | `0x008c2f50`–`0x008c2fdf` exclusive (**143 B** / `0x8F`) |
| **Canonical name** | `Client_TryInventoryAutoMergePartialStacks_Notify` |
| **Ghidra name** | `FUN_008c2f50` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W30-N) |
| **Counterpart** | `reviews/B_aa_008c2f50_Client_TryInventoryAutoMergePartialStacks_Notify.md` |
| **System** | client / inventory-transfer notify |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full 143 B) + `get_bulk_xrefs` + caller context @ `0x008c3da5`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Client **try-auto-merge** wrapper for underfilled inventory stacks:

1. Gate busy flag `DAT_00d1a8f6` and host/grid pointers.
2. Call `InventoryGrid_AutoMergePartialStacks_Inferred` (`0x00572ab0`).
3. On dirty: stamp `host+0x564`, refresh via `FUN_00860700`, send sector packet **`0x204a`** (8 bytes), return 1.
4. Else return 0.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W30-N) | `docs/reconstruction/raw/aa_008c2f50_FUN_008c2f50.md` |
| Annotated | `docs/reconstruction/raw/aa_008c2f50_FUN_008c2f50.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Client_TryInventoryAutoMergePartialStacks_Notify.cpp` |
| Clean scaffold | `docs/reconstruction/reconstructed-exact/FUN_008c2f50.cpp` |
| Function records | `functions/aa_008c2f50_FUN_008c2f50.md`, `functions/aa_008c2f50_Client_TryInventoryAutoMergePartialStacks_Notify.md` |
| Merge twin | `InventoryGrid_AutoMergePartialStacks_Inferred` `aa_00572ab0` (W29-E accept-with-gaps) |
| Live | decompile ≡ raw CF; full-body hex; sole caller UI case 4 |

---

## 3. Signature (sealed)

```c
// EDI = host*; bare RET; bool in AL
// Not __thiscall (ECX unused for this unit).
uint8_t Client_TryInventoryAutoMergePartialStacks_Notify(/* EDI host */);
```

| Formal | Source | Conf |
|---|---|---|
| host | EDI (`unaff_EDI` + sole caller keeps EDI) | **High** |
| return | AL = 0/1 | **High** |
| cleanup | bare `C3` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if DAT_00d1a8f6 != 0: return 0
host = *(EDI+0x580); if !host: return 0
grid = *(host+0x56c); if !grid: return 0
if !InventoryGrid_AutoMergePartialStacks_Inferred(grid): return 0
*(host+0x564) = DAT_00d17768[*(EDI+0x50c)]   // *4 scale
FUN_00860700()  // ESI=host
packet = {0x204a, u8(EDI+0x50c), 0xFF, 0}
Client_SendSectorPacket(&DAT_00d1a840, 8, &packet)
return 1
```

| Stage | Match | Conf |
|---|---|---|
| Busy + null gates | **Yes** | **High** |
| Merge callee | **Yes** → `0x00572ab0` | **High** |
| Table stamp + refresh | **Yes** | **High** |
| Packet 0x204a size 8 | **Yes** | **High** |
| Return bool | **Yes** (`B0 01` / `32 C0`) | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body 143 B captured in raw (W30-N section). Highlights:

| Feature | Encoding |
|---|---|
| Busy gate | `80 3D F6 A8 D1 00 00` |
| Host/grid | `[edi+0x580]`, `[eax+0x56c]` |
| Merge call | `E8` @ `0x008c2f72` → `0x00572ab0` |
| Opcode imm | `C7 … 4A 20 00 00` → `0x204a` |
| Success/fail | `B0 01 … C3` / `32 C0 … C3` |

**No `disassemble_bytes` used.**

---

## 6. Call surface

| Direction | Detail |
|---|---|
| Xrefs | 1 UNCONDITIONAL_CALL from `FUN_008c3ca0` @ `0x008c3da5` |
| Callees | `FUN_00572ab0`, `FUN_00860700`, `Client_SendSectorPacket` |
| Caller context | UI switch `(param_3-40000)==4` and `param_2==8`; return discarded |

---

## 7. Confidence

| Claim | Level |
|---|---|
| ABI EDI / AL / bare RET | **High** |
| Gates + dirty notify CF | **High** |
| Merge callee identity | **High** |
| Packet layout bytes | **High** |
| Product English / 0x204a meaning / table role | **Open** |
| Runtime / bit-exact | **Open** |

---

## 8. Gaps

1. Product English for host / inventory host classes.
2. Server meaning of sector opcode `0x204a`.
3. Semantics of `DAT_00d17768` and field `host+0x564`.
4. Full contract of refresh helper `FUN_00860700` (out of ownership).
5. Runtime differential.

---

## Verdict

**accept-with-gaps** — client wrapper CF/ABI/packet/callee sealed; product naming + opcode/table semantics residual.
