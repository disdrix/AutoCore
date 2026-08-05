# Review A (reconstruction fidelity): `aa_00432cb0` NDAssetImage_DecodeByFormat_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00432cb0` |
| **VA** | `0x00432cb0` |
| **Body** | `0x00432cb0`–`0x004330bf` (1039 / `0x40F` bytes) |
| **Canonical name** | `NDAssetImage_DecodeByFormat_Inferred` |
| **Ghidra name** | `FUN_00432cb0` |
| **Review date** | `2026-07-29` (W22-P dual seal) |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_00432cb0_NDAssetImage_DecodeByFormat_Inferred.md` |
| **System** | `gfx-asset` / `NDAssetImage` / multi-format decode |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). Supporting: `analyze_function_complete`, callers, callees, `get_assembly_context`.

---

## 1. Purpose

**Format-dispatch image decoder.** EAX selects auto-detect (TGA→PNG→BMP→residual) or a forced loader; ECX is the abstract stream; stack holds the destination/context object. Success commits via `FUN_00432580` and returns 1; failure writes an error string at `context+0x44` and returns 0.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00432cb0_FUN_00432cb0.md` (+ W22-P re-verify) |
| Annotated | `docs/reconstruction/raw/aa_00432cb0_FUN_00432cb0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDAssetImage_DecodeByFormat_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00432cb0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00432cb0_FUN_00432cb0.md` |
| Live decompile | `0x00432cb0` |
| Bytes | `read_memory` entry + mid + epilogue |
| Call sites | `0x00432c16`, `0x00432c72` |

---

## 3. Byte / ABI seal

| Claim | Confidence | Evidence |
|---|---|---|
| Body 1039 B | **Confirmed** | Ghidra body `00432cb0`–`004330bf` |
| Prologue tests **EAX** | **Confirmed** | `85 C0` immediately after stack setup |
| `EBX = ECX` stream | **Confirmed** | `8B D9`; `call [ebx] vtbl` |
| **`RET 4`** | **Confirmed** | epilogue `C2 04 00` |
| Return 1 / 0 in AL | **Confirmed** | `B0 01` / `32 C0` paths |
| Mode 0..4 switch | **Confirmed** | decompile + `83 F8 01/02/03/04` mid-body |
| Auto TGA first | **Confirmed** | `NDAssetImage_LoadTGA` call sites in mode 0 and 3 |
| PNG via `FUN_00435410` | **Confirmed** | call + sibling plate PNG string |
| BMP via `FUN_00433dc0` | **Confirmed** | call + sibling BMP notes |
| Unknown string | **Confirmed** | `"Decode: Unknown or wrong format"`; 8× dword copy to `+0x44` |
| Stream rewind auto tries | **Confirmed** | `vtbl+0x14` save; `vtbl+0x10(pos,0)` on fail |
| Callers ×2 wrappers | **Confirmed** | xrefs `FUN_00432be0`, `FUN_00432c50` |
| Live ≡ raw CF | **Confirmed** | 2026-07-29 re-verify |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| Mode 0 cascade + rewinds | **Yes** |
| Mode 1 BMP only | **Yes** |
| Mode 2 PNG only | **Yes** |
| Mode 3 TGA only | **Yes** |
| Mode 4 residual | **Yes** |
| Mode else / total fail → string + 0 | **Yes** |
| Success → `FUN_00432580` + return 1 | **Yes** |
| Invented formats outside 0..4 | **None** |

---

## 5. Gaps

1. Product dispatcher symbol — open (`_Inferred`).
2. Mode-4 / `FUN_0098b5b0` format English.
3. Full `param_2` layout; ctor/dtor/move helper duals.
4. BMP path stream formal (decomp shows image-only; stream likely via side channel).
5. Runtime / bit-exact / image diff — open.

**Verdict:** **accept-with-gaps**

---

## Checklist

| Check | Result |
|---|---|
| Clean CF matches raw / live decompile | **Pass** |
| EAX mode + RET 4 | **Pass** |
| String sealed | **Pass** |
| Cascade order sealed | **Pass** |
| Product name | **Open** |
| Verdict | **accept-with-gaps** |
