# Review A (reconstruction fidelity): `aa_00571db0` InventoryGrid_RemoveItemAtXY

| Field | Value |
|---|---|
| **Stable ID** | `aa_00571db0` |
| **VA** | `0x00571db0` |
| **Body** | `0x00571db0`–`0x00571e0e` (94 bytes) |
| **Canonical name** | `InventoryGrid_RemoveItemAtXY` (Ghidra `FUN_00571db0`; **Inferred**) |
| **Review date** | `2026-08-04` (WQ8R-G dual seal) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ sealed bytes) |
| **Counterpart** | `reviews/B_aa_00571db0_InventoryGrid_RemoveItemAtXY.md` |
| **System** | `inventory-transfer` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (+ bulk xrefs). **No** `disassemble_bytes`.

---

## 1. Purpose

Bounds-check inventory grid cell `(x,y)`, load the cell’s 8-byte COID stamp, resolve the live item with sealed `InventoryGrid_FindItemByCoid` (`0x00571010`), then peel-or-remove via sealed `InventoryGrid_RemoveItem` (`0x00571b80`) with **qty=1** and **forceFull=0**.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00571db0_FUN_00571db0.md` |
| Annotated | `docs/reconstruction/raw/aa_00571db0_FUN_00571db0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/InventoryGrid_RemoveItemAtXY.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00571db0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00571db0_InventoryGrid_RemoveItemAtXY.md` |
| Live decompile | `decompile_function` @ `0x00571db0` ≡ raw 2026-07-23 |
| Machine | `read_memory` 96 B @ entry |
| Sibling duals | `A_aa_00571010_*`, `A_aa_00571b80_*` |
| Layout map | `systems/inventory-transfer.md` grid `+0x08/+0x0c/+0x28` |

**Not performed:** `disassemble_bytes`, Launcher, live CE cell remove, bit-exact.

---

## 3. Byte seal (`read_memory` @ `0x00571db0`)

| Claim | Confidence | Evidence |
|---|---|---|
| `__thiscall` grid in ECX | **Confirmed** | `MOV ESI, ECX` |
| Two stack args; `RET 8` | **Confirmed** | dual `C2 08 00` epilogues |
| Width `@+0x08`, height `@+0x0c` | **Confirmed** | loads + signed compare on movzx bytes |
| `index = height*x + y` | **Confirmed** | `IMUL` + add before `*8` index |
| Cells `@+0x28`, stride 8 | **Confirmed** | `[ecx+edx*8]`, `[ecx+edx*8+4]` |
| Find then Remove | **Confirmed** | rel32 → `00571010`, `00571b80` |
| qty=1, forceFull=0 | **Confirmed** | `PUSH 0; PUSH 1` before Find (left for Remove after Find `RET 8`) |
| OOB → EAX=0 | **Confirmed** | `XOR EAX,EAX` fail path |
| Leaf of only two sealed callees | **Confirmed** | no other calls |

Full body hex (94 B + `CC`):
```
83ec08568bf18b4e0c8b4608894c24080fb64c24103bc87d3d8bd00fb6442414895424048b560c3bc27d2b0fafd18b4e2803d08b04d18b4cd1046a006a0151508bcee819f2ffff508bcee881fdffff5e83c408c2080033c05e83c408c20800cc
```

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| Bound x against width | **Yes** |
| Bound y against height | **Yes** |
| Index `height*x+y` | **Yes** |
| Load COID lo/hi | **Yes** |
| FindItemByCoid | **Yes** |
| RemoveItem(item,1,0) | **Yes** |
| Fail → 0 | **Yes** |
| Decompile live ≡ raw 2026-07-23 | **Yes** |

---

## 5. Gaps (do not block accept-with-gaps)

1. **0 static CALL xrefs** in Ghidra — caller unknown / possibly dead.
2. Product/PDB name unknown (Inferred name only).
3. Runtime / bit-exact open.
4. Behavior when cell is empty (`-1,-1`) depends entirely on Find→null→Remove gate (not re-proven here).

---

## 6. Verdict

**accept-with-gaps** — CF, ABI, index formula, and sealed callee linkage are high confidence; missing callers and runtime keep the dual from full **accept**.
