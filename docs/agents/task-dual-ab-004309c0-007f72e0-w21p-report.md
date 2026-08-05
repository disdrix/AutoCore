# Dual A/B report — W21-P OWN `aa_004309c0` + `aa_007f72e0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W21-P  
**Scope:** VAs `0x004309c0`, `0x007f72e0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004309c0` StdMap_StringKey_InsertOrFind | **accept-with-gaps** — insert-or-find CF + ABI sealed; product map-owner names / mapped-value typedef residual |
| `aa_007f72e0` ActionMap_TrySetSlotBind | **accept** — leaf mode tables, flag gate, dual-lane write, register ABI sealed |

---

## VA `0x004309c0` — sealed facts

1. **Body:** `0x004309c0`–`0x00430a96` (215 B; 3× `RET 4`).
2. **ABI:** stack map shell*; **EAX** = `basic_string*` key; **EBX** = `{node* it, u8 inserted}` out; return EAX=EBX.
3. **Semantics:** MSVC `std::map<std::string,T>` **insert-or-find** (not assign).
4. **Node:** key string `@+0x0C`; color `@+0x2C`; isnil `@+0x2D`; L/P/R `@0/4/8`.
5. **Equal key:** `inserted=0`, no value write.
6. **Callees:** IAT `operator<` (`0x009c62e8`); `FUN_00430b60` insert+rebalance; `FUN_004313d0` predecessor.
7. **Callers (2):** `FUN_004303c0` @ `0x00430521`, `FUN_00786470` @ `0x007865b1`.
8. **Name:** `StdMap_StringKey_InsertOrFind` (Ghidra `FUN_004309c0`).
9. **Decompile ≡ bytes** for CF; phantoms filled from bytes + callers.

### Gaps

- Product English for map owners at callers.  
- Mapped-value layout after string (consumer `node+0x28`).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004309c0_StdMap_StringKey_InsertOrFind.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004309c0_StdMap_StringKey_InsertOrFind.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004309c0_FUN_004309c0.md` |
| Annotated | `docs/reconstruction/raw/aa_004309c0_FUN_004309c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_StringKey_InsertOrFind.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004309c0.cpp` |
| Function | `docs/reconstruction/functions/aa_004309c0_FUN_004309c0.md` |
| Function named | `docs/reconstruction/functions/aa_004309c0_StdMap_StringKey_InsertOrFind.md` |
| Scratch | `docs/reconstruction/tmp/a_004309c0.md` |

---

## VA `0x007f72e0` — sealed facts

1. **Body:** `0x007f72e0`–`0x007f748f` (432 B; leaf; 9× `RET 8`).
2. **ABI:** **AL**=slot index; **BL**=bind lane; **SI**=key u16; **DX**=mod u16; stack base + mode; AL success.
3. **Switch:** mode 0..3 via jump table `@0x007f7490` → `{0x7f72f9, 0x7f734b, 0x7f73b8, 0x7f7425}`.
4. **Stride:** `0x34` per slot; bounds 5 / 6 / `0x78` / `0x14`.
5. **Gate:** write only if mode-relative customized flag == 0.
6. **Lanes:** BL==0 primary key/mod pair; BL!=0 alt pair; clear two status bytes.
7. **Callers:** `Client_InitDefaultKeybinds` (74 sites); `FUN_0092f710` keymap.ini (BL=0 then BL=1).
8. **Name:** `ActionMap_TrySetSlotBind` (Ghidra `FUN_007f72e0`).
9. **Decompile ≡ bytes** for CF; phantoms filled from callers.

### Gaps

- Product English for four mode groups.  
- Exact meaning of cleared status bytes.  
- Live keymap differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_007f72e0_ActionMap_TrySetSlotBind.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_007f72e0_ActionMap_TrySetSlotBind.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_007f72e0_FUN_007f72e0.md` |
| Annotated | `docs/reconstruction/raw/aa_007f72e0_FUN_007f72e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ActionMap_TrySetSlotBind.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_007f72e0.cpp` |
| Function | `docs/reconstruction/functions/aa_007f72e0_FUN_007f72e0.md` |
| Function named | `docs/reconstruction/functions/aa_007f72e0_ActionMap_TrySetSlotBind.md` |
| Scratch | `docs/reconstruction/tmp/a_007f72e0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004309c0` | Client STL map helper — string-key insert-or-find only; do not model as upsert; isnil/color at `+0x2D/+0x2C` (not int-map `+0x19/+0x18`). |
| `007f72e0` | ActionMap bind writer — preserve flag gate or re-init wipes user binds; dual-lane primary/alt; four mode offset tables required for full keybind parity. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers).  
- Dual A (fidelity) + B (adversarial) both filed per VA.
