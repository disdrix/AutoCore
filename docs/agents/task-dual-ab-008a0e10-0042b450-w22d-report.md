# Dual A/B report — W22-D OWN `aa_008a0e10` + `aa_0042b450`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W22-D  
**Scope:** VAs `0x008a0e10`, `0x0042b450` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0042b450` BitStream_GrowForBits | **accept** — EDI this / ECX extraBits / AL bool; NewSize formula + owns-realloc sealed from bytes; decompiler shift parens corrected |
| `aa_008a0e10` QuickBar_RebindPageColumns_Inferred | **accept-with-gaps** — 10-col rebind CF High; type 1/2/5/else sealed; callee product ABI residual |

---

## VA `0x0042b450` — sealed facts

1. **Body:** `0x0042b450`–`0x0042b49b` (76 B to final `RET`).
2. **ABI:** EDI = BitStream* this; ECX = extra bits needed; AL = success (1/0). Not MSVC thiscall.
3. **Formula (bytes):** `NewSize = ((extraBits + bitCap(+0x30) + 7) >> 3) + 0x5DC`.
4. **Decompiler hazard:** C text `(param_1 + 7 + cap >> 3) + 0x5dc` mis-groups `>>` vs `+`.
5. **Success:** if `+0x10 < NewSize` and owns `+0x14`: `realloc(+0x0c)`, set `+0x10`, `+0x2c/+0x30 = NewSize*8`, return 1. No NULL check.
6. **Fail:** stamp `+0x10 = NewSize`, set error `+0x1c = 1`, return 0 (also when alloc already ≥ NewSize or !owns).
7. **Callee:** `realloc` via IAT `[0x009C650C]`.
8. **Callers (7+):** `BitStream_writeBits`, `BitStream_writeFlag`, writeString family, others (11 xrefs).
9. **Name:** `BitStream_GrowForBits` (Ghidra `FUN_0042b450`).

### Gaps

- Product/TNL symbol.  
- Live OOM / fixed-buffer.  
- Soft reason alloc≥NewSize fails (defensive edge).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0042b450_BitStream_GrowForBits.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0042b450_BitStream_GrowForBits.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0042b450_FUN_0042b450.md` |
| Annotated | `docs/reconstruction/raw/aa_0042b450_FUN_0042b450.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/BitStream_GrowForBits.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0042b450.cpp` |
| Function | `docs/reconstruction/functions/aa_0042b450_FUN_0042b450.md` |
| Function named | `docs/reconstruction/functions/aa_0042b450_BitStream_GrowForBits.md` |
| Scratch | `tmp/a_0042b450.md` |

---

## VA `0x008a0e10` — sealed facts

1. **Body:** `0x008a0e10`–`0x008a0eca` (~186 B); **`RET 4`** stdcall.
2. **ABI:** one stack formal = QB host*; void return.
3. **Gates:** host `vtbl+0x3d8()` non-zero **and** `DAT_00d1b6d8 != 0`.
4. **Prelude:** `FUN_007fce10(&DAT_00d1a840)`.
5. **Loop:** 10 columns; widgets `host+0x63c` (`host[399]`); page `host+0x50c` (`host[0x143]`).
6. **Table:** `DAT_00d1da60[page*10+col]` stride **0x18** — type@+0, id@+8 (`da68`), skillId@+0x10 (`da70`).
7. **Dispatch:** type **1** → `FUN_00826860` (skill); **2** → `FUN_008283a0` (item); **5** → `FUN_00827670` (macro, EAX=5); else → `QuickBar_ClearActiveSlot_INFERRED`.
8. **Decompiler residual:** collapses type-1/2 register/stack args; bytes carry full setup.
9. **Callers (4):** SelectPage `0x008a0ed0`, CreateChildWidgets `0x008a16b0`, `FUN_008a1280`, `Client_RecvCreateCharacter`.
10. **Name:** `QuickBar_RebindPageColumns_Inferred` (Ghidra `FUN_008a0e10`).

### Gaps

- Product names (unit + binders + `FUN_007fce10` / globals).  
- Full callee prototypes beyond image ABI.  
- Runtime page-switch rebind.  
- 0x18 row full typedef.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_008a0e10_QuickBar_RebindPageColumns_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_008a0e10_QuickBar_RebindPageColumns_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_008a0e10_FUN_008a0e10.md` |
| Annotated | `docs/reconstruction/raw/aa_008a0e10_FUN_008a0e10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/QuickBar_RebindPageColumns_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_008a0e10.cpp` |
| Function | `docs/reconstruction/functions/aa_008a0e10_FUN_008a0e10.md` |
| Function named | `docs/reconstruction/functions/aa_008a0e10_QuickBar_RebindPageColumns_Inferred.md` |
| Scratch | `tmp/a_008a0e10.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0042b450` | Network BitStream grow — use **byte-sealed** formula with +1500 slack; stream in explicit arg (EDI), not ECX thiscall; treat return as bool; do not trust decompiler parens; note retail skips realloc NULL check. |
| `008a0e10` | Client QB UI rebind only — **do not** put in sector sim; if mocking QB chrome, rebind from page×10 type table; never confuse with SelectPage (`0x008a0ed0`) or Activate. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Prior scaffolds (2026-07-23) refreshed in place; raw bodies preserved with W22-D append.
