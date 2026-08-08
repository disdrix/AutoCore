# Review A (reconstruction fidelity): `aa_00570f50` InventoryGrid_RemoveAllAndReEmptyCells_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00570f50` |
| **VA** | `0x00570f50` |
| **Canonical name** | `InventoryGrid_RemoveAllAndReEmptyCells_Inferred` |
| **Ghidra name** | `FUN_00570f50` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_00570f50_InventoryGrid_RemoveAllAndReEmptyCells_Inferred.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** (R10-013 OWN-ONLY; supersedes 2026-07-23 scaffold) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Inventory grid **thin re-empty**: drain the embedded list, then re-allocate a fully empty cell buffer. Does **not** walk items for detach / special void-delete (that is twin `0x00570f70`).

```text
InventoryGrid_RemoveAllAndReEmptyCells_Inferred(grid)
  list = grid+0x2c
  List_RemoveAll(list)                              // 0x004bc580
  InventoryGrid_AllocateCellArray_Inferred(grid)    // 0x00570720  (tail-JMP)
```

**Calling convention:** MSVC `__fastcall` with sole arg in `ECX` (thiscall-equivalent). Void. Retail ends with **tail-JMP**, not `RET`.

| Slot | Role | Evidence |
|------|------|----------|
| `this` / `grid` (ECX) | `InventoryGrid*` | `MOV ESI,ECX`; restored before Allocate |
| list ECX for RemoveAll | `grid+0x2c` | `LEA ECX,[ESI+0x2c]` |

**Returns:** void (via tail into Allocate).

**Side effects:** list drain (CS + possible throw + node dtors); cell free/realloc/empty-fill via Allocate. No locks inside this 19-byte body itself (locks are inside RemoveAll).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw (+ R10 re-verify) | `docs/reconstruction/raw/aa_00570f50_FUN_00570f50.md` |
| Annotated | `docs/reconstruction/raw/aa_00570f50_FUN_00570f50.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/InventoryGrid_RemoveAllAndReEmptyCells_Inferred.cpp` |
| Clean FUN | `docs/reconstruction/reconstructed-exact/FUN_00570f50.cpp` |
| Function records | `functions/aa_00570f50_FUN_00570f50.md` + named |
| Live re-decompile | Ghidra MCP `decompile_function` @ `0x00570f50` (2026-08-05) — **matches raw body CF** |
| Complete analyze | `analyze_function_complete` — worker; 13 xrefs; callees RemoveAll + Allocate |
| Memory | `read_memory` 48 B — body hex + pad + twin entry |
| Dualed callees | `List_RemoveAll` A/B; `InventoryGrid_AllocateCellArray_Inferred` A/B |
| Twin dual | MEGA-090 `InventoryGrid_ClearItemsAndReEmptyCells_Inferred` |

**Not performed:** `disassemble_bytes`, Launcher, live heap dump, bit-exact diff. Parent ledgers not edited.

---

## 3. Control flow: clean ≡ raw ≡ live decompile

| Stage | Match |
|---|---|
| `List_RemoveAll` first | **Yes** |
| ECX for RemoveAll = `grid+0x2c` | **Yes** (assembly; decompiler elides) |
| `AllocateCellArray` second | **Yes** |
| ECX for Allocate = original grid | **Yes** (`MOV ECX,ESI`) |
| Tail-JMP (not CALL+RET) | **Yes** (assembly; clean may use call form — CF equivalent) |
| No item walk / TraversalLock / detach | **Yes** |
| Body size 19 B before CC pad | **Yes** |

### 3.1 Decompiler vs assembly

Live decompile:

```c
void __fastcall FUN_00570f50(void *param_1)
{
  FUN_004bc580();
  InventoryGrid_AllocateCellArray_Inferred(param_1);
  return;
}
```

Decompiler drops list `this` on `FUN_004bc580` and shows `return` instead of tail-JMP. **Annotated + clean named** restore list ECX and document tail. Fidelity of **call order and sole grid argument to Allocate** is intact.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Two-step RemoveAll → Allocate | **High / Confirmed** | Raw + live + hex |
| `list = grid+0x2c` | **High** | `LEA ECX,[ESI+0x2c]` |
| ECX in = InventoryGrid* | **High** | Callers pass grid; twin same ABI |
| Thin twin of `00570f70` | **High** | MEGA-090 chain + body contrast |
| Name retail-accurate | **Inferred only** | `_Inferred` honest |
| When thin vs full clear is chosen | **Probable** | multi-caller; product English open |
| Runtime / bit-exact | **Open** | Deferred |

---

## 5. Callers (sample)

| VA / name | Notes |
|-----------|-------|
| `CVOGCharacter_ApplyCreateFromPacket` | Character create |
| `Vehicle_applyCreatePacket` | Vehicle create |
| `FUN_00884720` | After full clear twin on host cargo; thin on `DAT_00d1b6d8+0xce0` |
| `FUN_0051f1f0` | Conditional up to 3 grids |
| `FUN_0052f260` | Three call sites |

**Contract:** produces empty occupancy via Allocate; list residual nodes destroyed only if still linked (RemoveAll). Callers that still own live items needing detach must use twin `00570f70` first (or equivalent).

---

## 6. Gaps / open (do not block accept-with-gaps)

1. **Runtime / differential** — no live create/clear heap golden.
2. **Retail symbol** — name remains `_Inferred`.
3. **Product English** — why create paths use thin vs full clear.
4. **Clean tail form** — reconstruction uses call+return; retail tail-JMPs (behavior-equivalent).
5. **List node type** — owned by `List_RemoveAll` dual, not re-proven here.

**No clean-vs-raw fidelity rewrite required beyond documenting list ECX.**

---

## 7. Verdict

### **accept-with-gaps**

Among the shortest inventory units: live decompile ≡ raw CF; assembly seals list offset and tail-JMP. Gaps are naming, product policy for thin vs full clear, and runtime goldens — not CF drift.

---

## Checklist (reviewer)

| Check | Result |
|---|---|
| Live decompile matches raw CF | **Pass** |
| Clean CF matches raw order | **Pass** |
| list @ `+0x2c` sealed | **Pass** |
| Tail to dualed Allocate | **Pass** |
| No false item-walk claim | **Pass** |
| Runtime / bit-exact | **Open** |
| Verdict | **accept-with-gaps** |
