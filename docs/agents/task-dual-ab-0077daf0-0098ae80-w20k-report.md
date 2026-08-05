# Dual A/B report — W20-K OWN-ONLY (`0x0077daf0`, `0x0098ae80`)

**Date:** 2026-07-29  
**Agent:** W20-K OWN-ONLY  
**Scope:** OWN ONLY VAs `0x0077daf0`, `0x0098ae80`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_0077daf0` BitStream_readString | **accept-with-gaps** — **ESI BitStream + stack out + RET; flag Huffman/raw; tables/globals sealed; product English open** |
| `aa_0098ae80` NDAssetImage_Flip | **accept-with-gaps** — **ret4, temp 0x1b8, DIB row reverse + FlipVertical + transfer sealed; product English open** |

---

## `aa_0077daf0` — BitStream_readString

### Sealed facts

1. **ABI:** `uint32_t BitStream_readString(char* out)` with **ESI = BitStream\***, stack out, epilogue plain **`RET`** (caller cleans 4). Body `0x0077daf0`–`0x0077dc13`. Always returns **`1`**.

2. **Once-init:** `DAT_00d17a28 == 0` → `FUN_0077d520()` builds Huffman tree (`DAT_00d1eab0`, 8 B nodes) + alphabet (`DAT_00d1eabc`, 0xc stride, char@+5) from freq seed `DAT_00a1ea68`.

3. **Flag bit:** consume 1 stream bit. **1 = Huffman** (u8 len, tree walk bit0→+4 / bit1→+6, leaf → char); **0 or bitPos overflow** → **raw** (u8 len + `readBits(len*8)`). Overflow sets error `@+0x1c`.

4. **Callers:** only `BitStream_readStringCached` (`0x0042ba90`) at `0x0042baa6` / `0x0042bb12` (cache layer separate).

5. **Name:** structural **`BitStream_readString`**. Legacy mission-chain alias incomplete.

6. **Live decompile ≡ 2026-07-23 raw** (append-only live section recorded).

### Gaps

1. Product/PDB symbol.  
2. Runtime tree/alphabet contents.  
3. Max string / out buffer contract.  
4. Write twin `FUN_0077d960` not owned.  
5. Runtime / bit-exact / differential — open.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0077daf0_BitStream_readString.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0077daf0_BitStream_readString.md` |
| Function record | `docs/reconstruction/functions/aa_0077daf0_BitStream_readString.md` |
| Clean | `docs/reconstruction/reconstructed-exact/BitStream_readString.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_0077daf0.cpp` |
| Raw | `docs/reconstruction/raw/aa_0077daf0_FUN_0077daf0.md` |
| Annotated | `docs/reconstruction/raw/aa_0077daf0_FUN_0077daf0.annotated.md` |

---

## `aa_0098ae80` — NDAssetImage_Flip

### Sealed facts

1. **ABI:** `uint8_t NDAssetImage_Flip(NDAssetImage* image)` — stack image*, epilogue **`ret 4`**. Body `0x0098ae80`–`0x0098af4c`. Returns **0** fail / **1** success.

2. **Fail gates:** `image+4 == 0` (no DIB); `new(0x1b8)` null; temp `+4 == 0` after copy.

3. **Pipeline:** vtbl `PTR_FUN_00a9bcac` → `FUN_004320d0` ctor → `FUN_00432260(src,0,0,1)` → reverse-copy DIB rows (`height@+0x10`, `pitch@+0x30`, `pBits@+0x34`) → `NDAssetImage_FlipVertical` → `FUN_00432580` transfer → vtbl dtor(1).

4. **Caller:** sole xref `FUN_00433dc0` @ `0x004345f0` — CxImage BMP decode when **top-down** (`biHeight < 0`).

5. **Distinct from** `NDAssetImage_FlipVertical` (`0x004332e0`) which only flips `+0x1b0`.

6. **Name:** structural **`NDAssetImage_Flip`** (CxImage::Flip family probable).

7. **Live CF ≡ raw**.

### Gaps

1. Product/PDB English.  
2. FlipVertical failure ignored (still returns 1 after transfer).  
3. Full Copy/Transfer helper contracts.  
4. Runtime / bit-exact / differential — open.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0098ae80_NDAssetImage_Flip.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0098ae80_NDAssetImage_Flip.md` |
| Function record | `docs/reconstruction/functions/aa_0098ae80_NDAssetImage_Flip.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDAssetImage_Flip.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_0098ae80.cpp` |
| Raw | `docs/reconstruction/raw/aa_0098ae80_FUN_0098ae80.md` |
| Annotated | `docs/reconstruction/raw/aa_0098ae80_FUN_0098ae80.annotated.md` |

---

## Absolute roots

`C:\Users\josh\Documents\GitHub\AutoCore\` + paths above.

This report: `docs/agents/task-dual-ab-0077daf0-0098ae80-w20k-report.md`

---

## AutoCore impact

- **BitStream string (`0x0077daf0`):** implement under net unpack as base Huffman/raw string decode; keep separate from `readStringCached` prefix layer. ESI convention or explicit BitStream* in ports.
- **Image flip (`0x0098ae80`):** client asset path for top-down BMP normalize; only port if asset tooling needs CxImage-compatible flip (DIB + info buffer), not FlipVertical-only.
