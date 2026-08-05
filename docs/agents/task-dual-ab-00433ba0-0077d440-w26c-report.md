# Dual A/B report — W26-C OWN `aa_00433ba0` + `aa_0077d440`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W26-C  
**Scope:** VAs `0x00433ba0`, `0x0077d440` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers/callees). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00433ba0` BitStream_HuffmanTree_EnsureCapacity | **accept** — this-in-EAX + RET 4 + 8 B tree grow + exclusive parent sealed |
| `aa_0077d440` BitStream_HuffmanAssignCodes | **accept** — recursive leaf/internal CF + bitlen/code writes + exclusive parent sealed |

---

## VA `0x00433ba0` — sealed facts

1. **Body:** `0x00433ba0`–`0x00433bfe` (**94 B**; pad `CC` after `RET 4`).
2. **ABI:** container **this in EAX**; stack `needCount`; epilogue **`RET 4`** (not ECX-thiscall, not plain cdecl).
3. **Semantics:** If `capacity(+4) < need`, allocate `newCap * 8` where `newCap = need + (0x10 - (need & 0xf))`, copy via `FUN_00433c60`, free old, store buffer(+8) and capacity.
4. **Container (parent):** base `0x00d1eaa8` → count / capacity / buf = `DAT_00d1eaa8` / `DAT_00d1eaac` / `DAT_00d1eab0` (Huffman **tree**, stride **8**).
5. **Classification:** worker; callees `malloc`, `FUN_00433c60`, `free`.
6. **Callers (1 / 2 xrefs):** only `FUN_0077d520` (`BitStream_HuffmanBuildTables`) at `0x0077d559` (need 0x100) and `0x0077d56d` (need count+1).
7. **Name:** `BitStream_HuffmanTree_EnsureCapacity` (Ghidra `FUN_00433ba0`; inferred from exclusive parent + strides).
8. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).
9. **Sister:** alphabet ensure is `FUN_00433c00` (stride 0xC) — owned by W26-B, not this unit.

### Gaps

- Product English / TNL original container type name.  
- Full `FUN_00433c60` register contract (not OWN).  
- Runtime realloc bit-exact — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00433ba0_BitStream_HuffmanTree_EnsureCapacity.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00433ba0_BitStream_HuffmanTree_EnsureCapacity.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00433ba0_FUN_00433ba0.md` |
| Annotated | `docs/reconstruction/raw/aa_00433ba0_FUN_00433ba0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/BitStream_HuffmanTree_EnsureCapacity.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00433ba0.cpp` |
| Function | `docs/reconstruction/functions/aa_00433ba0_FUN_00433ba0.md` |
| Function named | `docs/reconstruction/functions/aa_00433ba0_BitStream_HuffmanTree_EnsureCapacity.md` |
| Scratch | `docs/reconstruction/tmp/a_00433ba0.md` |

---

## VA `0x0077d440` — sealed facts

1. **Body:** `0x0077d440`–`0x0077d514` (**212 B**; pad `CC` to next fn `0x0077d520`).
2. **ABI:** **cdecl**; stack `ctx, nodeOrLeaf, depth`; **void**; plain **`RET`**.
3. **Leaf (`nodeOrLeaf < 0`):** alphabet row `DAT_00d1eabc + (n*3+3)*-4` ≡ leafIdx `(-1-n) * 0xC`; write **code** at +8 from `**(ctx+0xC)`, **bitlen** at +4 from depth.
4. **Internal:** node at `DAT_00d1eab0 + index*8`; snapshot bitPos at `ctx+0x18`; write **bit 0** then recurse left short@+4; restore; write **bit 1** then recurse right short@+6; restore. Expand via `FUN_0042b450` when `ctx+0x30 < bitPos+1`.
5. **Callers:** external only `FUN_0077d520` (`0x0077d8f8`); self ×2 (`0x0077d4c3`, `0x0077d505`).
6. **Callees:** `FUN_0042b450`, self.
7. **Name:** `BitStream_HuffmanAssignCodes` (Ghidra `FUN_0077d440`; required by W25-T parent / W21-C string codec).
8. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product English inside TNL.  
- Runtime post-walk alphabet dump bit-exact — open.  
- Expand-fail path (skip bit write) residual Medium-High; parent scratch cap 0x20 bits.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0077d440_BitStream_HuffmanAssignCodes.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0077d440_BitStream_HuffmanAssignCodes.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0077d440_FUN_0077d440.md` |
| Annotated | `docs/reconstruction/raw/aa_0077d440_FUN_0077d440.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/BitStream_HuffmanAssignCodes.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0077d440.cpp` |
| Function | `docs/reconstruction/functions/aa_0077d440_FUN_0077d440.md` |
| Function named | `docs/reconstruction/functions/aa_0077d440_BitStream_HuffmanAssignCodes.md` |
| Scratch | `docs/reconstruction/tmp/a_0077d440.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00433ba0` | Tree container grow must use this-in-EAX / RET 4 contract, 8-byte elements, and `newCap = need + (16 - (need & 15))`. Do not share with alphabet ensure (0xC / `FUN_00433c00`). |
| `0077d440` | String Huffman tables require this walk: left=0 / right=1, negative leaf encoding, bitlen@+4 code@+8. Required step after tree merge in `BitStream_HuffmanBuildTables`. Closes nested residual left open by W25-T. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/callees).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Pattern: `docs/agents/task-dual-ab-0040d450-0077d520-w25t-report.md`.
