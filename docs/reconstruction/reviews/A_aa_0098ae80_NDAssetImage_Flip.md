# Review A (reconstruction fidelity): `aa_0098ae80` NDAssetImage_Flip

| Field | Value |
|---|---|
| **Stable ID** | `aa_0098ae80` |
| **VA** | `0x0098ae80`–`0x0098af4c` |
| **Canonical name** | `NDAssetImage_Flip` |
| **Prior scaffold** | `FUN_0098ae80` |
| **Review date** | `2026-07-29` (W20-K OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction fidelity — Path A |
| **Counterpart** | `reviews/B_aa_0098ae80_NDAssetImage_Flip.md` |
| **System** | client assets / `NDAssetImage` (CxImage Flip) |
| **Verdict** | **accept-with-gaps** — ABI, CF, layout, caller role sealed; product English open |

**Tools:** Ghidra `decompile_function` + `read_memory` (body + vtbl). No `disassemble_bytes`. Own VA only. No ledgers. No Launcher.

---

## 1. Purpose

**In-place vertical flip** of full `NDAssetImage` (DIB bits + info buffer):

1. Fail if no DIB (`+4`) or OOM on temp `0x1b8`.
2. Temp clone: vtbl `PTR_FUN_00a9bcac`, ctor, copy with `+0x1b0` flag.
3. Reverse-copy rows using pitch `@+0x30`, pBits `@+0x34`, height `@+0x10`.
4. `NDAssetImage_FlipVertical` on temp; transfer ownership back; destroy temp.

BMP top-down (`biHeight < 0`) path in `FUN_00433dc0` is the sole xref caller.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0098ae80_FUN_0098ae80.md` (+ 2026-07-29 live) |
| Annotated | `docs/reconstruction/raw/aa_0098ae80_FUN_0098ae80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDAssetImage_Flip.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_0098ae80.cpp` |
| Function record | `docs/reconstruction/functions/aa_0098ae80_NDAssetImage_Flip.md` |
| Sibling | `NDAssetImage_FlipVertical` `0x004332e0` |
| Live decompile | `decompile_function` `0x0098ae80` — **≡** raw |
| Live bytes | `read_memory` body + success epilogue `ret 4` |
| Caller context | `FUN_00433dc0` CxImage BMP (`"Not a BMP"`, `CxImage::Create`) |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| Stack image* | `8B 6C 24 0C` |
| Epilogue | **`C2 04 00` ret 4** all paths |
| Return | AL 0/1 |
| Alloc | imm **`0x1b8`** |
| Body | `0098ae80`–`0098af4c` |

```c
uint8_t NDAssetImage_Flip(NDAssetImage* image); // ret 4
```

### 3.2 Layout used — **SEALED**

| Rel | Role | Conf |
|---:|---|---|
| `+0x04` | DIB base (null gate / temp gate) | **High** |
| `+0x10` | height | **High** |
| `+0x30` | pitch | **High** |
| `+0x34` | pBits | **High** |
| `+0x1b0` | info/pixel buffer (via FlipVertical) | **High** |
| vtbl | `PTR_FUN_00a9bcac` | **High** |

### 3.3 Key CF arms — **SEALED**

| Arm | Behavior |
|---|---|
| null DIB | return 0 |
| OOM | return 0 |
| temp DIB null after copy | return 0 |
| success | row reverse + FlipVertical + transfer + dtor → 1 |

### 3.4 Three-rep CF fidelity

| Pass | Match |
|---|---|
| Raw 2026-07-23 | baseline |
| Live 2026-07-29 | **≡** raw |
| Bytes | ret4, 0x1b8, vtbl, REP MOVS* |

---

## 4. Naming

| Name | Status |
|---|---|
| `NDAssetImage_Flip` | **Structural sealed** |
| CxImage::Flip product | **Probable** (string family on Create helpers) |
| `NDAssetImage_FlipVertical` | sibling only — **not** this VA |

---

## 5. Gaps

1. Product/PDB symbol exact spelling.
2. Whether FlipVertical failure is ignored (return still 1 after transfer).
3. Full Copy/Transfer helper duals not owned.
4. Runtime / bit-exact / differential — open.

---

## 6. AutoCore port notes

- Only needed if server/tooling loads top-down BMPs into NDAssetImage-compatible buffers.
- Client-only path for area/map assets; low server priority unless asset pipeline ports CxImage.
