# Review A (reconstruction fidelity): `aa_00434dd0` NDAssetImage_DecodeUncompressedTgaRow

| Field | Value |
|---|---|
| **Stable ID** | `aa_00434dd0` |
| **VA** | `0x00434dd0` |
| **Body** | `0x00434dd0`–`0x00434f08` (312 bytes) |
| **Canonical name** | `NDAssetImage_DecodeUncompressedTgaRow` |
| **Prior scaffold** | `FUN_00434dd0` |
| **Review date** | `2026-07-29` (W22-O dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00434dd0_NDAssetImage_DecodeUncompressedTgaRow.md` |
| **System** | `gfx-asset` / `NDAssetImage` / TGA |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Uncompressed TGA **span/row decoder**: read pixels from an abstract stream into an RGB8 destination, switching on bpp at `header+0x10`. Shared by `NDAssetImage_LoadTGA` (non-RLE) and RLE helper raw packets. 32bpp additionally stores alpha via `FUN_00433280`.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x00434dd0` |
| Bytes | `read_memory` 320 B — SEH, `mov ebx,ecx`/`mov esi,edx`, jump table, `ret 0x14` |
| Jump tables | `read_memory` @ `0x00434f10` / `0x00434f24` |
| Bounds | `get_function_by_address` `00434dd0`–`00434f08` |
| Callees | `FUN_00433280` only (plus stream vtbl) |
| Callers | LoadTGA @ `0x00434a55`; RLE @ `0x00434d45` |
| Parent context | `A_aa_004347d0_NDAssetImage_LoadTGA` |
| Nested | decompile `FUN_00433280`, `FUN_00434b30` (context) |
| Raw / clean | `aa_00434dd0_*`, `NDAssetImage_DecodeUncompressedTgaRow.cpp` |

**Not performed:** Launcher, runtime, parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| ECX=stream, EDX=dest RGB | **Confirmed** | `8B D9` / `8B F2` |
| `ret 0x14` = 5 stack dwords | **Confirmed** | epilogue `C2 14 00` |
| Stack: image, header, count, y, x0 | **Confirmed** | 32bpp path uses +8/+14/+18; switch uses +0xc |
| bpp switch 8/15/16/24/32 | **Confirmed** | jump table index = bpp−8 |
| 8 / 24 bulk read via vtbl+8 | **Confirmed** | 24 multiplies count×3 first |
| 15/16 RGB555→24 expand | **Confirmed** | G=`>>2&0xf8`, B=`>>7&0xf8` |
| R = `(pix&0x1f)<<3` | **Confirmed** | bytes `83 E1 1F` + ×8; **decomp residual** |
| 32: RGB write + `FUN_00433280` alpha | **Confirmed** | |
| Product English name | **Inferred** | role-sealed |
| Channel order English (BGR vs RGB) | **Inferred** | byte order sealed; naming residual |
| Runtime / bit-exact | **Open** | |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH install | Yes |
| bpp dispatch | Yes (table sealed) |
| 8 bulk | Yes |
| 15/16 loop expand | Yes (+ R mask in clean notes) |
| 24 bulk ×3 | Yes |
| 32 loop + alpha callee | Yes |
| Default no-op return | Yes |
| No invented PNG/DDS paths | Yes |

---

## 5. Gaps / open

1. Product stream interface name / Read HRESULT policy.
2. Full `FUN_00433280` alpha-plane layout (callee residual).
3. Why LoadTGA decompile of this call site scrambles formals (known decomp artifact; ABI from bytes).
4. Runtime vs retail `map.tga`.

**Verdict:** **accept**
