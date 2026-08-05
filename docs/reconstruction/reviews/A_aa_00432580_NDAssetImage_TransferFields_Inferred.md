# Review A (reconstruction fidelity): `aa_00432580` NDAssetImage_TransferFields_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00432580` |
| **VA** | `0x00432580`–`0x00432625` (**165 B**) |
| **Canonical name** | `NDAssetImage_TransferFields_Inferred` |
| **Ghidra name** | `FUN_00432580` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W23-C) |
| **Counterpart** | `reviews/B_aa_00432580_NDAssetImage_TransferFields_Inferred.md` |
| **System** | NDAssetImage buffer ownership move |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` full body; callers decode/flip; callee `FUN_004321b0` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Move owned image payload from **src (EBX)** into **dest (stack)**: pre-clear dest, copy field blocks + ownership pointers, zero src so temp destruction is safe. Success returns **1**; pre-clear failure returns **0**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00432580_FUN_00432580.md` (+ W23-C append) |
| Annotated | `docs/reconstruction/raw/aa_00432580_FUN_00432580.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/NDAssetImage_TransferFields_Inferred.cpp` |
| Clean scaffold | `docs/reconstruction/reconstructed-exact/FUN_00432580.cpp` |
| Function record | `docs/reconstruction/functions/aa_00432580_NDAssetImage_TransferFields_Inferred.md` |
| Sibling context | `aa_0098ae80` NDAssetImage_Flip (annotates this as TransferFields) |
| Live | `decompile_function` `0x00432580`; `read_memory` 256 B; `get_function_by_address`; callee `0x004321b0` |

---

## 3. Signature

```c
// Ghidra: undefined4 FUN_00432580(int param_1)  // dest*
//         unaff_EBX = src*
// Bytes:  mov ebp,[esp+8]; mov esi,ebp; call FUN_004321b0
//         ...; mov al,1; pop ebp; ret 4
```

| Item | Evidence | Conf |
|---|---|---|
| Stack dest* | `8B 6C 24 08` | **High** |
| EBX = src | `8D 43 08` / loads `[ebx+…]` | **High** |
| ESI = dest for pre-clear | `8B F5` before call | **High** |
| `ret 4` | `C2 04 00` fail + success | **High** |
| Return 0/1 in AL | `test al` fail; `B0 01` success | **High** |

---

## 4. Control flow (sealed from bytes + decompile)

```
dest = arg0; src = EBX
if FUN_004321b0(ESI=dest) == 0: return 0
rep movsd 10 dwords:  dest+8  ← src+8
rep movsd 0x5F dwords: dest+0x30 ← src+0x30
dest+4 / +0x1ac / +0x1b0 / +0x1b4 ← src
zero src +8 (10 dwords)
zero src +0x30 (0x5F dwords)
zero src +0x1b0 / +0x1ac / +4 / +0x1b4
return 1
```

| Stage | Match | Conf |
|---|---|---|
| Pre-clear call `FUN_004321b0` | **Yes** (rel32 → `0x004321b0`) | **High** |
| 10-dword +8 copy | **Yes** (`B9 0A; F3 A5`) | **High** |
| 0x5F-dword +0x30 copy | **Yes** (`B9 5F; F3 A5`) | **High** |
| Scalar copies +4/+0x1ac/+0x1b0/+0x1b4 | **Yes** | **High** |
| Zero src blocks | **Yes** (stores + `F3 AB`) | **High** |
| ret 4 / AL=1 | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Full 165 B body hex in raw W23-C append. Spot checks:

| Offset | Bytes | Decode |
|---|---|---|
| +0 | `55 8B 6C 24 08 56 8B F5` | frame; dest→ebp/esi |
| +8 | `E8 23 FC FF FF` | call pre-clear |
| +0xD | `84 C0 75 05 5E 5D C2 04 00` | fail ret 4 |
| +0x1A | `B9 0A 00 00 00 F3 A5` | 10× movsd |
| +0x28 | `B9 5F 00 00 00 … F3 A5` | 0x5F× movsd |
| end | `B0 01 5D C2 04 00` | success; ret 4 |

**No `disassemble_bytes` used.**

---

## 6. Call surface

| Caller | VA / note |
|---|---|
| `FUN_00432cb0` | decode-by-format success commit |
| `FUN_0098acc0` | load path sibling |
| `FUN_0098ae80` | Flip: transfer temp→image |

Xrefs: **4**.

| Callee | VA / note |
|---|---|
| `FUN_004321b0` | free existing dest owned buffers; gate on +0x38 |

---

## 7. Confidence

| Claim | Level |
|---|---|
| CF / block sizes / ret 4 / EBX=src | **High** |
| Role as ownership steal / transfer | **High** |
| Product field English names | **Probable** |
| Full NDAssetImage typedef | **Tentative** |
| Runtime / bit-exact | **Open** |

---

## 8. Gaps

1. Product English for the 40 B and 380 B blocks.
2. Full semantics of `FUN_004321b0` when `dest+0x38 != 0` (returns 0).
3. Object size / fields beyond +0x1b4.
4. Live capture of transfer during flip/decode — open.

**Verdict:** **accept-with-gaps** — image CF and ABI sealed; field English remains inferred.
